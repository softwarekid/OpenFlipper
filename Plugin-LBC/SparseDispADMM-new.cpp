/*
 * SparseDispADMM.cpp
 *
 *  Created on: Sep 1, 2012
 *      Author: Bailin Deng
 */

#include "SparseDispADMM-new.h"
#include "ConstrainedMeshPluginAux.h"
#include <Dolphin/Core/Scenegraph/Geometry/OpenMeshNode.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <omp.h>

// CUDA library
#include <cusp/hyb_matrix.h>
#include <cusp/io/matrix_market.h>
#include <cusp/krylov/cg.h>
#include <cusp/csr_matrix.h>
#include <cusp/blas.h>
#include <cusp/array1d.h>
#include <cusp/array2d.h>


namespace Dolphin {

namespace plugins {


void SparseDispAugLag_PQ_Eigen::initialize_variables(OpenMeshNode *mesh_, int update_period_, int nb_threads_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double eps_val_,
		double init_dual_eps_val_, double tau_incr_, bool use_2nddiff, bool threshold_smoothness_, bool use_diffvec,
		int max_iter, int primal_max_iter)
{
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	var_vtx_n = pmesh->n_vertices();
	face_n = pmesh->n_faces();

	update_mesh = true;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	threshold_smoothness = threshold_smoothness_;
	current_primal_run_start_iter = 0;
	primal_subproblem_maxiter = primal_max_iter;
	nb_threads = nb_threads_;

	eps_val = eps_val_;
	init_dual_eps_val = init_dual_eps_val_;
	tau_incr = tau_incr_;
	dual_sqaured_norm_eps_decr_ratio = tau_incr;
	diffvec_planarity = use_diffvec;

	min_sqr_primal_residual_change_ratio = 0.7 * 0.7;
	lambda_primal2dual_sqr = 10 * 10;
	max_iteration = max_iter;
	max_penalty = std::max(1e5, init_penalty_weight_ * std::pow( init_dual_eps_val_ / eps_val_, 2 ));

	prev_outer_primal_residual_sqr_norm = 0;

	initialize_var_index();

	store_orig_vertex_positions();

	if(diffvec_planarity){
		initialize_diffvec_matrix();
	}
	else{
		initialize_centered_matrix();
	}

	if(use_2nddiff){
		initialize_disp_2nddiff_energy_matrix();
	}
	else{
		initialize_disp_3rddiff_energy_matrix();
	}

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();

	#ifdef DEBUG_RESIDUAL
	init_aux_var_debug_data();
	#endif
}


void SparseDispAugLag_PQ_Eigen::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness){
		smoothness_energy_bound = F[0].squaredNorm() + F[1].squaredNorm() + F[2].squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}

void SparseDispAugLag_PQ_Eigen::initialize_centered_matrix()
{
	// Compute nean-centering matrix
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_C;
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	int row_n = 0;
	face_vtx_idx.clear();

	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		std::vector<int> vtx_var_idx;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			vtx_var_idx.push_back(fv_it.handle().idx());
		}

		for(int i = 0; i < 4; i++){

			for(int k = 0; k < 4; k++){
				triplets_C.push_back(T(row_n, vtx_var_idx[k], (k==i) ? 0.75:(-0.25) ));
			}

			row_n ++;
		}

		face_vtx_idx.push_back(vtx_var_idx);
	}

	C.resize(row_n, var_vtx_n);
	C.setFromTriplets(triplets_C.begin(), triplets_C.end());
	Ct = C.transpose();

	for(int i = 0; i < 3; i++){
		K[i] = C * orig_vtx_pos[i];
	}

	C43.fill(-0.25);
	for(int i = 0; i < 4; i++){
		C43(i, i) = 0.75;
	}
}

void SparseDispAugLag_PQ_Eigen::zero_initialize_dual_vars()
{
	int d1_size = C.rows();
	int d2_size = var_vtx_n;
	int d3_size = E.rows();

	for(int i = 0; i < 3; i++){
		D1[i].setZero(d1_size);
		D2[i].setZero(d2_size);
		D3[i].setZero(d3_size);
		primal_residual_1[i].setZero(d1_size);
		primal_residual_2[i].setZero(d2_size);
		primal_residual_3[i].setZero(d3_size);
	}
}

//label
void SparseDispAugLag_PQ_Eigen::update_H()
{
	#pragma omp for
	for(int i = 0; i < 3; i++){
		prev_H[i] = H[i];
		H[i] = solver.solve(Ct * (Z[i] - K[i] + D1[i]) +  Et * (W[i] - F[i] + D3[i]) + Y[i] + D2[i]);
		H_diff[i] = H[i] - prev_H[i];
		dual_residual_squared_norm[i] = H_diff[i].squaredNorm() + (C * H_diff[i]).squaredNorm() + (E * H_diff[i]).squaredNorm();
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaupdate_H()
{
	#pragma omp for
	for(int i = 0; i < 3; i++)
	{
		cusp::blas::copy(cudaH[i], cudaprev_H[i]);
		cusp::array2d cusparray;
		cusp::blas::axpbypcz(cudaW[i], cudaF[i], cudaD3[i], cusparray, 1, -1, 1);
		cusp::multiply(cudaEt, cusparray, cusparray);
		cusp::blas::axpbyp(cudaY[i], cudaD2[i], cusparray, 1, 1);
		cusp::array2d cuspb;
		cusp::blas::axpbypcz(cudaZ[i], cudaK[i], cudaD1[i], cuspb, 1, -1, 1);
		cusp::multiply(cudaCt, cuspb, cuspb);
		cusp::blas::axpy(cusparray, cuspb, 1);

		//solve the linear system
		cusp::verbose_monitor<double> monitor(cuspb, 100, 1e-3);
		cusp::identity_operator<double, cusp::device_memory> M(cudasparseCoeffMatrix.num_rows, cudasparseCoeffMatrix.num_rows);
		//here, the initial value of cudaH is a good guess?
		//cudasparseCoeffMatrix is constructed at the beginning
		//we need to add the construction in copydata function
		cusp::krylov::cg(cudasparseCoeffMatrix, cudaH, cuspb, monitor, M);//conjugate method to solve linear system

		cusp::blas::axpby(cudaH[i], cudaprev_H[i], cudaH_diff[i], 1, -1);
		cusp::multiply(cudaC, cudaH_diff[i], cuspb);
		cusp::multiply(cudaE, cudaH_diff[i], cusparray);
		cudadual_residual_squared_norm[i] = cusp::blas::dot(cudaH_diff[i], cudaH_diff[i]) + cusp::blas::dot(cuspb, cuspb) + cusp::blas::dot(cusparray, cusparray);
		//dual_residual_squared_norm[i] = H_diff[i].squaredNorm() + (C * H_diff[i]).squaredNorm() + (E * H_diff[i]).squaredNorm();
	}
}

void SparseDispAugLag_PQ_Eigen::initialize_solver()
{
	SparseMatrixXd I(var_vtx_n, var_vtx_n);

	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_I;
	for(int i = 0; i < var_vtx_n; i++){
		triplets_I.push_back(T(i, i, 1.0));
	}

	I.setFromTriplets(triplets_I.begin(), triplets_I.end());
	solver.compute(Ct * C  + Et * E  + I);
}


//label
void SparseDispAugLag_PQ_Eigen::update_W()
{
	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_W_residual(prev_W_residual);
	#endif

	#pragma omp for nowait
	for(int i = 0; i < 3; i++){
		W[i].noalias() = W_update_tmp[i] * ( penalty_weight / (penalty_weight + smoothness_weight) );
	}

	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_W_residual(new_W_residual);
	check_decreasing_value(prev_W_residual, new_W_residual, "W");
	#endif
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaupdate_W()
{
	#pragma omp for nowait
	for(int i = 0; i < 3; i++)
	{
		cusp::blas::copy(cudaW_update_tmp[i], cudaW[i]);
		cusp::blas::scal(cudaW[i], cudapenalty_weight/(cudapenalty_weight + cudasmoothness_weight));
	}
}

//label
void SparseDispAugLag_PQ_Eigen::update_W_with_thresholding()
{
	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_W_residual(prev_W_residual);
	#endif

	#pragma omp single
	{
		W_update_factor = 1.0;
		double new_W_sqr_norm = W_update_tmp[0].squaredNorm() + W_update_tmp[1].squaredNorm() + W_update_tmp[2].squaredNorm();

		if(new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 )){
			W_update_factor =  penalty_weight / (penalty_weight + smoothness_weight) ;
		}
		else if(new_W_sqr_norm > smoothness_energy_bound){
			W_update_factor = smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm);
		}
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++){
		W[i].noalias() = W_update_tmp[i] * W_update_factor;
	}

	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_W_residual(new_W_residual);
	check_decreasing_value(prev_W_residual, new_W_residual, "W");
	#endif
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaupdate_W_with_thresholding()
{
	#pragma omp single
	{
		cudaW_update_factor = 1.0;
		double new_W_sqr_norm = cusp::blas::dot(cudaW_update_tmp[0], cudaW_update_tmp[0]) + cusp::blas::dot(cudaW_update_tmp[1], cudaW_update_tmp[1]) + cusp::blas::dot(cudaW_update_tmp[2], cudaW_update_tmp[2]);

		if(new_W_sqr_norm > cudasmoothness_energy_bound*std::pow((cudasmoothness_weight + cudapenalty_weight)/cudapenalty_weight, 2 ))
		{
			cudaW_update_factor =  cudapenalty_weight/(cudapenalty_weight + cudasmoothness_weight) ;
		}
		else if(new_W_sqr_norm > cudasmoothness_energy_bound)
		{
			cudaW_update_factor = cudasmoothness_energy_bound_sqrt/std::sqrt(new_W_sqr_norm);
		}
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++)
	{
		//I am not sure the meaning of noalias
		cusp::blas::copy(cudaW_update_tmp[i], cudaW[i]);
		cusp::blas::scal(cudaW[i], cudaW_update_factor);
		//W[i].noalias() = W_update_tmp[i] * W_update_factor;
	}
}

//label
void SparseDispAugLag_PQ_Eigen::L1_update_Y()
{
	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_Y_residual(prev_Y_residual);
	#endif

	#pragma omp for nowait
	for(unsigned int i = 0; i < fixed_vtx_idx.size(); i++){
		int idx = fixed_vtx_idx[i];
		MeshPointType &cur_disp = fixed_vtx_target[i];
		double t = penalty_weight / (penalty_weight + vtx_disp_weight);
		Y[0](idx) = cur_disp[0] * (1-t) + Y_update_tmp[0](idx) * t;
		Y[1](idx) = cur_disp[1] * (1-t) + Y_update_tmp[1](idx) * t;
		Y[2](idx) = cur_disp[2] * (1-t) + Y_update_tmp[2](idx) * t;
	}

	#pragma omp for
	for(unsigned int i = 0; i < free_vtx_idx.size(); i++){
		int idx = free_vtx_idx[i];
		if(sparsity_weight == 0.0){
			Y[0](idx) = Y_update_tmp[0](idx);
			Y[1](idx) = Y_update_tmp[1](idx);
			Y[2](idx) = Y_update_tmp[2](idx);
		}
		else{
			double row_vec_norm = std::sqrt( std::pow(Y_update_tmp[0](idx), 2) + std::pow(Y_update_tmp[1](idx), 2) + std::pow(Y_update_tmp[2](idx), 2) );
			if( 2 * row_vec_norm * penalty_weight <= sparsity_weight ){
				Y[0](idx) = Y[1](idx) = Y[2](idx) = 0.0;
			}
			else{
				double t = 1.0 - 0.5 * sparsity_weight / (penalty_weight * row_vec_norm);
				Y[0](idx) = Y_update_tmp[0](idx) * t;
				Y[1](idx) = Y_update_tmp[1](idx) * t;
				Y[2](idx) = Y_update_tmp[2](idx) * t;
			}
		}
	}

	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_Y_residual(new_Y_residual);
	check_decreasing_value(prev_Y_residual, new_Y_residual, "Y");
	#endif
}


__global__
void cudaL1_update_Y_fixed()
{
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if (i < cudanfixed)
	{
		int idx = cudafixed_vtx_idx[i];
		double t = cudapenalty_weight/(cudapenalty_weight + cudavtx_disp_weight);
		for (int j = 0; j < 3; ++j)
		{
			cudaY(idx, j) = (1 - t)*cudacur_disp(i, j) + t*cudaY_update_tmp(i, j);
		}
	}
}

__global__
void cudaL1_update_Y_free()
{
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if (i < cudanfree)
	{
		int idx = cudafree_vtx_idx[i];
		if (cudasparsity_weight == 0)
		{
			cudaY(idx, 0) = cudaY_update_tmp(idx, 0);
			cudaY(idx, 1) = cudaY_update_tmp(idx, 1);
			cudaY(idx, 2) = cudaY_update_tmp(idx, 2);
		}
		else
		{
			double row_vec_norm = std::sqrt(std::pow(cudaY_update_tmp(idx, 0), 2) + std::pow(cudaY_update_tmp(idx, 1), 2) + std::pow(Y_update_tmp(idx, 2), 2));
			if(2*row_vec_norm*cudapenalty_weight <= cudasparsity_weight)
			{
				cudaY(idx, 0) = cudaY(idx, 1) = cudaY(idx, 2) = 0.0;
			}
			else
			{
				double t = 1.0 - 0.5*cudasparsity_weight/(cudapenalty_weight*row_vec_norm);
				cudaY(idx, 0) = cudaY_update_tmp(idx, 0)*t;
				cudaY(idx, 1) = cudaY_update_tmp(idx, 1)*t;
				cudaY(idx, 2) = cudaY_update_tmp(idx, 2)*t;
			}
		}
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaL1_update_Y()
{
	cudaL1_update_Y_fixed<<<BLOCK_N, THREAD_N>>>();
	cudaL1_update_Y_free<<<BLOCK_N, THREAD_N>>>();
}

//label
void SparseDispAugLag_PQ_Eigen::update_Z()
{
	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_Z_residual(prev_Z_residual);
	#endif

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

	#pragma omp for nowait
	for(int i = 0; i < face_n; i ++){
		int base_idx = i * 4;

		Matrix43d M, Mc;
		M.col(0) = Z_update_tmp[0].segment<4>(base_idx);
		M.col(1) = Z_update_tmp[1].segment<4>(base_idx);
		M.col(2) = Z_update_tmp[2].segment<4>(base_idx);

		Mc.noalias() = C43 * M;
		Eigen::JacobiSVD<Matrix43d> jSVD(Mc, Eigen::ComputeFullV);

		Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
		Eigen::Matrix<double,1,3> Nt = N.transpose();

		M.noalias() = Mc - (Mc * N) * Nt;

		for(int k = 0; k < 3; k++){
			Z[k].segment<4>(base_idx) = M.col(k);
		}
	}

	#ifdef DEBUG_RESIDUAL
	#pragma omp barrier
	compute_Z_residual(new_Z_residual);
	check_decreasing_value(prev_Z_residual, new_Z_residual, "Z");
	#endif
}

//cuda
__global__
void SparseDispAugLag_PQ_Eigen::cudaupdate_Z()
{
	#pragma omp for nowait
	int idx = blockIdx.x*blockDim.x + threadIdx.x;
	//int base_idx = i * 4;

	cusp::array2d M(4, 3), Mc(4, 3);
	//Matrix43d M, Mc;
	//M.col(0) = Z_update_tmp[0].segment<4>(base_idx);
	//M.col(1) = Z_update_tmp[1].segment<4>(base_idx);
	//M.col(2) = Z_update_tmp[2].segment<4>(base_idx);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			M(i, j) = cudaZ_update_tmp[j](idx, i);
		}
	}

	//Mc.noalias() = C43 * M;
	cusp::multiply(cudaC43, M, Mc);

	//how to compute svd of a 4*3 matrix?
	Eigen::JacobiSVD<Matrix43d> jSVD(Mc, Eigen::ComputeFullV);

	//Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
	//Eigen::Matrix<double,1,3> Nt = N.transpose();
	cusp::array2d N(3, 1);
	cusp::array2d Nt(1, 3);//how to compute transpose of a matrix in cusp?

	cusp::array2d cusparray;
	cusp::multiply(Mc, N, cusparray);
	cusp::multiply(cusparray, Nt, cusparray);
	cusp::blas::axpby(Mc, cusparray, M, 1, -1);
	//M.noalias() = Mc - (Mc * N) * Nt;

	for(int k = 0; k < 3; k++)
	{
		//Z[k].segment<4>(base_idx) = M.col(k);
		for (int i = 0; i < 4; ++i)
		{
			cudaZ[k](idx, i) = M(i, k);
		}
	}
}

void SparseDispAugLag_PQ_Eigen::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();

	orig_vtx_pos[0].resize(n_vtx);
	orig_vtx_pos[1].resize(n_vtx);
	orig_vtx_pos[2].resize(n_vtx);

	for(int i = 0; i < n_vtx; i++){
		MeshPointType &pt = pmesh->point(PolyMeshType::VertexHandle(i));
		orig_vtx_pos[0](i) = pt[0];
		orig_vtx_pos[1](i) = pt[1];
		orig_vtx_pos[2](i) = pt[2];
	}

	new_vtx_pos[0] = orig_vtx_pos[0];
	new_vtx_pos[1] = orig_vtx_pos[1];
	new_vtx_pos[2] = orig_vtx_pos[2];
}

void SparseDispAugLag_PQ_Eigen::initialize_stopping_criteria_var()
{
	primal_residual_dim = (Z[0].rows() + Y[0].rows() + W[0].rows()) * 3;
	dual_residual_dim = H[0].rows() * 3;
	primal_squared_norm_eps = primal_residual_dim * eps_val * eps_val;
	final_dual_squared_norm_eps = dual_residual_dim * eps_val * eps_val;
	cur_dual_squared_norm_eps = dual_residual_dim * init_dual_eps_val * init_dual_eps_val;
}

//label
void SparseDispAugLag_PQ_Eigen::stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
	#pragma omp single
	{
		optimization_end = false;
		need_incr_penalty = false;
		primal_subproblem_converge = false;
		dual_residual_total_sqr_norm = 0.0;

		if(iter_num >= this->max_iteration){
			std::cout << "Max iteration reached" << std::endl;
			optimization_end = true;
		}

		// If optimization ends because of max_iteartion, we still update the penalty weight and
		if((!optimization_end) || iter_num == max_iteration){
			dual_residual_total_sqr_norm = penalty_weight * penalty_weight * (dual_residual_squared_norm[0] + dual_residual_squared_norm[1] + dual_residual_squared_norm[2]);
			std::cout << "Dual Residual Squared Norm: " << dual_residual_total_sqr_norm << ",  Tolerance:" << cur_dual_squared_norm_eps << std::endl;

			if(dual_residual_total_sqr_norm <= cur_dual_squared_norm_eps || iter_num - current_primal_run_start_iter >= primal_subproblem_maxiter){
				primal_subproblem_converge = true;
				current_primal_run_start_iter = iter_num;
			}
			else{
				std::cout << "Not converge yet" << std::endl;
			}
		}

		std::cout << "Penalty Weight:" << penalty_weight << std::endl;
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++){
		if(primal_subproblem_converge){
			primal_residual_1[i] = Z[i] - K[i];
			primal_residual_1[i].noalias() -= C * H[i];
		}
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++){
		if(primal_subproblem_converge){
			primal_residual_3[i] = W[i] - F[i];
			primal_residual_3[i].noalias() -= E * H[i];
		}
	}

	#pragma omp for
	for(int i = 0; i < 3; i++){
		if(primal_subproblem_converge){
			primal_residual_2[i] = Y[i] - H[i];
		}
	}

	// Compute primal residual norms
	#pragma omp for
	for(int i = 0; i < 3; i++){
		if(primal_subproblem_converge){
			primal_residual_squared_norm[i] = primal_residual_1[i].squaredNorm() + primal_residual_2[i].squaredNorm()
					+ primal_residual_3[i].squaredNorm();
		}
	}

	#pragma omp single
	{
		// Determine residual change ratio
		if(primal_subproblem_converge){
			scaled_dual_change_ratio = 1.0;
			double primal_residual_total_squared_norm = primal_residual_squared_norm[0] + primal_residual_squared_norm[1] + primal_residual_squared_norm[2];

			std::cout << "Primal residual squared norm:" << primal_residual_total_squared_norm << ",  tolerance:" << primal_squared_norm_eps << std::endl;

			if( primal_residual_total_squared_norm <= primal_squared_norm_eps && dual_residual_total_sqr_norm <= final_dual_squared_norm_eps){
				optimization_end = true;
				optimization_converge = true;
				std::cout << "Optimization converges" << std::endl;
			}
			else if(penalty_weight * tau_incr <= max_penalty){

				if(dual_residual_total_sqr_norm <= cur_dual_squared_norm_eps){
					double normalized_primal_residual = primal_residual_total_squared_norm / primal_residual_dim;
					double normalized_dual_residual = dual_residual_total_sqr_norm / dual_residual_dim;
					need_incr_penalty =  (normalized_primal_residual >= lambda_primal2dual_sqr * normalized_dual_residual) ||
							//( dual_residual_total_sqr_norm <= final_dual_squared_norm_eps && primal_residual_total_squared_norm > min_sqr_primal_residual_change_ratio * prev_outer_primal_residual_sqr_norm);
							(primal_residual_total_squared_norm > std::max(primal_squared_norm_eps,
									min_sqr_primal_residual_change_ratio * prev_outer_primal_residual_sqr_norm));

					if(need_incr_penalty){
						penalty_weight *= tau_incr;
						scaled_dual_change_ratio  = 1.0 / tau_incr;
					}

					// Decrease dual residual squared norm
					cur_dual_squared_norm_eps /= dual_sqaured_norm_eps_decr_ratio;
					cur_dual_squared_norm_eps = std::max(cur_dual_squared_norm_eps, final_dual_squared_norm_eps);
					prev_outer_primal_residual_sqr_norm = primal_residual_total_squared_norm;
				}
			}
		}
	}


	#pragma omp for
	for(int i = 0; i < 3; i++){
		if(primal_subproblem_converge){
			// Update dual variables
			D1[i] += primal_residual_1[i];
			D2[i] += primal_residual_2[i];
			D3[i] += primal_residual_3[i];

			D1[i] *= scaled_dual_change_ratio;
			D2[i] *= scaled_dual_change_ratio;
			D3[i] *= scaled_dual_change_ratio;
		}
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudastop_check_and_dual_var_penalty_weight_update(int iter_num)
{
	#pragma omp single
	{
		cudaoptimization_end = false;
		cudaneed_incr_penalty = false;
		cudaprimal_subproblem_converge = false;
		cudadual_residual_total_sqr_norm = 0.0;

		if(iter_num >= cudamax_iteration)
		{
			std::cout << "Max iteration reached" << std::endl;
			cudaoptimization_end = true;
		}

		// If optimization ends because of max_iteartion, we still update the penalty weight and
		if((!cudaoptimization_end) || iter_num == cudamax_iteration)
		{
			cudadual_residual_total_sqr_norm = cudapenalty_weight * cudapenalty_weight * (cudadual_residual_squared_norm[0] + cudadual_residual_squared_norm[1] + cudadual_residual_squared_norm[2]);
			std::cout << "Dual Residual Squared Norm: " << cudadual_residual_total_sqr_norm << ",  Tolerance:" << cudacur_dual_squared_norm_eps << std::endl;

			if(cudadual_residual_total_sqr_norm <= cudacur_dual_squared_norm_eps || iter_num - cudacurrent_primal_run_start_iter >= cudaprimal_subproblem_maxiter){
				cudaprimal_subproblem_converge = true;
				cudacurrent_primal_run_start_iter = iter_num;
			}
			else{
				std::cout << "Not converge yet" << std::endl;
			}
		}

		std::cout << "Penalty Weight:" << cudapenalty_weight << std::endl;
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++)
	{/*
		if(primal_subproblem_converge)
		{
			primal_residual_1[i] = Z[i] - K[i];
			primal_residual_1[i].noalias() -= C * H[i];
		}*/
		if(cudaprimal_subproblem_converge)
		{
			cusp::blas::axpby(cudaZ[i], cudaK[i], cudaprimal_residual_1[i], 1, -1);
			cusp::array2d cusparray;
			cusp::multiply(cudaC, cudaH[i], cusparray);
			cusp::blas::axpy(cusparray, cudaprimal_residual_1[i], -1);
		}
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++)
	{/*
		if(primal_subproblem_converge){
			primal_residual_3[i] = W[i] - F[i];
			primal_residual_3[i].noalias() -= E * H[i];
		}*/
		if(cudaprimal_subproblem_converge)
		{
			cusp::blas::axpby(cudaW[i], cudaF[i], cudaprimal_residual_3[i], 1, -1);
			cusp::array2d cusparray;
			cusp::multiply(cudaE, cudaH[i], cusparray);
			cusp::blas::axpy(cusparray, cudaprimal_residual_3[i], -1);
		}
	}

	#pragma omp for
	for(int i = 0; i < 3; i++)
	{/*
		if(primal_subproblem_converge){
			primal_residual_2[i] = Y[i] - H[i];
		}*/
		if (cudaprimal_subproblem_converge)
		{
			cusp::blas::axpby(cudaY[i], cudaH[i], cudaprimal_residual_2[i], 1, -1);
		}
	}

	// Compute primal residual norms
	#pragma omp for
	for(int i = 0; i < 3; i++)
	{/*
		if(primal_subproblem_converge){
			primal_residual_squared_norm[i] = primal_residual_1[i].squaredNorm() + primal_residual_2[i].squaredNorm()
					+ primal_residual_3[i].squaredNorm();
		}*/
		if (cudaprimal_subproblem_converge)
		{
			cudaprimal_residual_squared_norm[i] = cusp::blas::dot(cudaprimal_residual_1[i], cudaprimal_residual_1[i]) + cusp::blas::dot(cudaprimal_residual_2[i], cudaprimal_residual_2[i]) + cusp::blas::dot(cudaprimal_residual_3[i], cudaprimal_residual_3[i]);
		}
	}

	#pragma omp single
	{
		// Determine residual change ratio
		if(cudaprimal_subproblem_converge)
		{
			cudascaled_dual_change_ratio = 1.0;
			double primal_residual_total_squared_norm = cudaprimal_residual_squared_norm[0] + cudaprimal_residual_squared_norm[1] + cudaprimal_residual_squared_norm[2];

			std::cout << "Primal residual squared norm:" << primal_residual_total_squared_norm << ",  tolerance:" << cudaprimal_squared_norm_eps << std::endl;

			if( primal_residual_total_squared_norm <= cudaprimal_squared_norm_eps && cudadual_residual_total_sqr_norm <= cudafinal_dual_squared_norm_eps){
				cudaoptimization_end = true;
				cudaoptimization_converge = true;
				std::cout << "Optimization converges" << std::endl;
			}
			else if(cudapenalty_weight * cudatau_incr <= cudamax_penalty){

				if(cudadual_residual_total_sqr_norm <= cudacur_dual_squared_norm_eps){
					double normalized_primal_residual = primal_residual_total_squared_norm / cudaprimal_residual_dim;
					double normalized_dual_residual = cudadual_residual_total_sqr_norm / cudadual_residual_dim;
					cudaneed_incr_penalty =  (normalized_primal_residual >= cudalambda_primal2dual_sqr * normalized_dual_residual) ||
							//( dual_residual_total_sqr_norm <= final_dual_squared_norm_eps && primal_residual_total_squared_norm > min_sqr_primal_residual_change_ratio * prev_outer_primal_residual_sqr_norm);
							(primal_residual_total_squared_norm > std::max(cudaprimal_squared_norm_eps,
									cudamin_sqr_primal_residual_change_ratio * cudaprev_outer_primal_residual_sqr_norm));

					if(cudaneed_incr_penalty){
						cudapenalty_weight *= cudatau_incr;
						cudascaled_dual_change_ratio  = 1.0 / cudatau_incr;
					}

					// Decrease dual residual squared norm
					cudacur_dual_squared_norm_eps /= cudadual_sqaured_norm_eps_decr_ratio;
					cudacur_dual_squared_norm_eps = std::max(cudacur_dual_squared_norm_eps, cudafinal_dual_squared_norm_eps);
					cudaprev_outer_primal_residual_sqr_norm = primal_residual_total_squared_norm;
				}
			}
		}
	}

	#pragma omp for
	for(int i = 0; i < 3; i++)
	{/*
		if(primal_subproblem_converge)
		{
			// Update dual variables
			D1[i] += primal_residual_1[i];
			D2[i] += primal_residual_2[i];
			D3[i] += primal_residual_3[i];

			D1[i] *= scaled_dual_change_ratio;
			D2[i] *= scaled_dual_change_ratio;
			D3[i] *= scaled_dual_change_ratio;
		}*/
		if (cudaprimal_subproblem_converge)
		{
			cusp::blas::axpy(cudaprimal_residual_1[i], cudaD1[i], 1);
			cusp::blas::axpy(cudaprimal_residual_2[i], cudaD2[i], 1);
			cusp::blas::axpy(cudaprimal_residual_3[i], cudaD3[i], 1);
			cusp::blas::scal(cudaD1[i], cudascale_dual_change_ratio);
			cusp::blas::scal(cudaD2[i], cudascale_dual_change_ratio);
			cusp::blas::scal(cudaD3[i], cudascale_dual_change_ratio);
		}
	}
}

//label
void SparseDispAugLag_PQ_Eigen::compute_primal_update_aux_var()
{
	#pragma omp for nowait
	for(int i = 0; i < 3; i ++){
		Z_update_tmp[i] = K[i] - D1[i];
		Z_update_tmp[i].noalias() += C * H[i];
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++){
		W_update_tmp[i] = F[i] - D3[i];
		W_update_tmp[i].noalias() += E * H[i];
	}

	#pragma omp for
	for(int i = 0; i < 3; i ++){
		Y_update_tmp[i] = H[i] - D2[i];
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudacompute_primal_update_aux_var()
{/*
	#pragma omp for nowait
	for(int i = 0; i < 3; i ++){
		Z_update_tmp[i] = K[i] - D1[i];
		Z_update_tmp[i].noalias() += C * H[i];
	}

	#pragma omp for nowait
	for(int i = 0; i < 3; i++){
		W_update_tmp[i] = F[i] - D3[i];
		W_update_tmp[i].noalias() += E * H[i];
	}

	#pragma omp for
	for(int i = 0; i < 3; i ++){
		Y_update_tmp[i] = H[i] - D2[i];
	}*/
	for (int i = 0; i < 3; ++i)
	{
		cusp::blas::axpby(cudaK[i], cudaD1[i], cudaZ_update_tmp[i], 1, -1);
		cusp::array2d cusparray;
		cusp::multiply(cudaC, cudaH[i], cusparray);
		cusp::blas::axpy(cusparray, cudaZ_update_tmp[i], 1);
	}

	for (int i = 0; i < 3; ++i)
	{
		cusp::blas::axpby(cudaF[i], cudaD3[i], cudaW_update_tmp[i], 1, -1);
		cusp::array2d cusparray;
		cusp::multiply(cudaE, cudaH[i], cusparray);
		cusp::blas::axpy(cusparray, cudaW_update_tmp[i], 1);
	}

	for (int i = 0; i < 3; ++i)
	{
		cusp::blas::axpby(cudaH[i], cudaD2[i], cudaY_update_tmp[i], 1, -1);
	}
}

void SparseDispAugLag_PQ_Eigen::initialize_disp_2nddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_2nddiff_polyline_idx(pmesh, polyline_idx);

	std::vector< MeshPointType > init_F;
	int row_n = 0;

	double coef[] = {1.0, -2.0, 1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		for(int k = 0; k < 3; k++){
			triplets_E.push_back(T(row_n, polyline_idx[i][k], coef[k]));
		}
		row_n ++;
	}

	E.resize(row_n, var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();

	for(int i = 0; i < 3; i++){
		F[i] = E * orig_vtx_pos[i];
	}
}


void SparseDispAugLag_PQ_Eigen::initialize_disp_3rddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	std::vector< MeshPointType > init_F;
	int row_n = 0;

	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		for(int k = 0; k < 4; k++){
			triplets_E.push_back(T(row_n, polyline_idx[i][k], coef[k]));
		}
		row_n ++;
	}

	E.resize(row_n, var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();

	for(int i = 0; i < 3; i++){
		F[i] = E * orig_vtx_pos[i];
	}
}


void SparseDispAugLag_PQ_Eigen::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
			iter != fixed_vtx_displacement.end(); ++ iter){
		free_vtx[iter->first] = 0;
	}

	free_vtx_idx.clear();
	fixed_vtx_idx.clear();
	fixed_vtx_target.clear();

	for(int i = 0; i < var_vtx_n; i++){
		if(free_vtx[i]){
			free_vtx_idx.push_back(i);
		}
		else{
			fixed_vtx_idx.push_back(i);
			fixed_vtx_target.push_back(fixed_vtx_displacement[i]);
		}
	}
}

void SparseDispAugLag_PQ_Eigen::initialize_primal_vars()
{
	int h_size = var_vtx_n;
	int y_size = var_vtx_n;
	int z_size = C.rows();

	for(int i = 0; i < 3; i++){
		H[i].setZero(h_size);
		prev_H[i].setZero(h_size);
		Y[i].setZero(y_size);
		Z[i].setZero(z_size);
		W[i] = F[i];

		Z_update_tmp[i] = K[i];
		Y_update_tmp[i].setZero(y_size);
		W_update_tmp[i] = F[i];
	}
}

//label
void SparseDispAugLag_PQ_Eigen::update_mesh_vertices()
{
	update_mesh_vertices(0);
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaupdate_mesh_vertices()
{
	cudaupdate_mesh_vertices(0);
}

//label
void SparseDispAugLag_PQ_Eigen::update_mesh_vertices(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){

		for(int i = 0; i < 3; i++){
			new_vtx_pos[i] = orig_vtx_pos[i] + H[i];
		}

		for(int i = 0; i < var_vtx_n; i++){
			pmesh->set_point(PolyMeshType::VertexHandle(i), MeshPointType( new_vtx_pos[0](i), new_vtx_pos[1](i), new_vtx_pos[2](i)));
		}

		pmesh->update_normals();
		mesh->setGeometryChanged();
	}
}

//cuda
__global__
void SparseDispAugLag_PQ_Eigen::cudaupdate_mesh_vertices(int iter_num)
{
	if(cudaupdate_mesh && (iter_num % cudaupdate_period == 0) )
	{/*
		for(int i = 0; i < 3; i++){
			new_vtx_pos[i] = orig_vtx_pos[i] + H[i];
		}

		for(int i = 0; i < var_vtx_n; i++){
			pmesh->set_point(PolyMeshType::VertexHandle(i), MeshPointType( new_vtx_pos[0](i), new_vtx_pos[1](i), new_vtx_pos[2](i)));
		}

		pmesh->update_normals();
		mesh->setGeometryChanged();*/

		int idx = blockIdx.x*blockDim.x + threadIdx.x;
		if (idx < cudavar_vtx_n)
		{
			for (int i = 0; i < 3; ++i)
			{
				cudanew_vtx_pos(idx, i) = cudaorig_vtx_pos(idx, i) + cudaH(idx, i);
				//save mesh's vertex positions
				cudavertexPositions(idx, i) = cudanew_vtx_pos(idx, i);
			}
		}
	}
}

//label
void SparseDispAugLag_PQ_Eigen::L1_optimize_unbounded_smoothness()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(this->nb_threads);
	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		update_aux_primal_variables();
		update_H();
		stop_check_and_dual_var_penalty_weight_update(iter);
}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);

	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaL1_optimize_unbounded_smoothness()
{
	int iter = 0;
	cudaoptimization_end = false;

	omp_set_num_threads(cudanb_threads);
	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		cudaupdate_aux_primal_variables();
		cudaupdate_H();
		cudastop_check_and_dual_var_penalty_weight_update(iter);
}

		if(cudaoptimization_end){
			cudaupdate_mesh_vertices(0);
			return;
		}
		cudaupdate_mesh_vertices(iter);
	}
}

//label
void SparseDispAugLag_PQ_Eigen::L1_optimize_bounded_smoothness()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(this->nb_threads);

	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		update_aux_primal_variables_with_faring_threshold();
		update_H();
		stop_check_and_dual_var_penalty_weight_update(iter);
}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaL1_optimize_bounded_smoothness()
{
	int iter = 0;
	cudaoptimization_end = false;

	omp_set_num_threads(cudanb_threads);

	while(true)
	{
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		cudaupdate_aux_primal_variables_with_faring_threshold();
		cudaupdate_H();
		cudastop_check_and_dual_var_penalty_weight_update(iter);
}

		if(cudaoptimization_end){
			cudaupdate_mesh_vertices(0);
			return;
		}
		cudaupdate_mesh_vertices(iter);
	}
}

//label
void SparseDispAugLag_PQ_Eigen::L1_optimize_unbounded_smoothness_diffvec_planarity()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(this->nb_threads);
	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		update_aux_primal_variables_diffvec();
		update_H();
		stop_check_and_dual_var_penalty_weight_update(iter);
}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);

	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaL1_optimize_unbounded_smoothness_diffvec_planarity()
{
	int iter = 0;
	cudaoptimization_end = false;

	omp_set_num_threads(cudanb_threads);
	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		cudaupdate_aux_primal_variables_diffvec();
		cudaupdate_H();
		cudastop_check_and_dual_var_penalty_weight_update(iter);
}

		if(cudaoptimization_end){
			cudaupdate_mesh_vertices(0);
			return;
		}
		cudaupdate_mesh_vertices(iter);
	}
}

//label
void SparseDispAugLag_PQ_Eigen::L1_optimize_bounded_smoothness_diffvec_planarity()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(this->nb_threads);

	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
		update_aux_primal_variables_with_faring_threshold_diffvec();
		update_H();
		stop_check_and_dual_var_penalty_weight_update(iter);
}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaL1_optimize_bounded_smoothness_diffvec_planarity()
{
	int iter = 0;
	cudaoptimization_end = false;

	omp_set_num_threads(this->nb_threads);

	while(true)
	{
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
{
			cudaupdate_aux_primal_variables_with_faring_threshold_diffvec();
		cudaupdate_H();
		cudastop_check_and_dual_var_penalty_weight_update(iter);
}

		if(cudaoptimization_end)
		{
			cudaupdate_mesh_vertices(0);
			return;
		}
		cudaupdate_mesh_vertices(iter);
	}
}


//label
void SparseDispAugLag_PQ_Eigen::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	this->optimization_converge = false;
	double start_time = omp_get_wtime();
	if(this->diffvec_planarity){
		if(threshold_smoothness){
			L1_optimize_bounded_smoothness_diffvec_planarity();
		}
		else{
			L1_optimize_unbounded_smoothness_diffvec_planarity();
		}
	}
	else{
		if(threshold_smoothness){
			L1_optimize_bounded_smoothness();
		}
		else{
			L1_optimize_unbounded_smoothness();
		}
	}

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;

	opt_disp.clear();

	for(int i = 0; i < var_vtx_n; i++){
		opt_disp.push_back(MeshPointType(H[0](i), H[1](i), H[2](i)));
	}
}

//cuda
void SparseDispAugLag_PQ_Eigen::cudaL1_optimize(std::vector<MeshPointType> &opt_disp)
{
	cudaoptimization_converge = false;
	double start_time = omp_get_wtime();
	if(cudadiffvec_planarity){
		if(cudathreshold_smoothness){
			cudaL1_optimize_bounded_smoothness_diffvec_planarity();
		}
		else{
			cudaL1_optimize_unbounded_smoothness_diffvec_planarity();
		}
	}
	else{
		if(cudathreshold_smoothness){
			cudaL1_optimize_bounded_smoothness();
		}
		else{
			cudaL1_optimize_unbounded_smoothness();
		}
	}

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;

	opt_disp.clear();

	for(int i = 0; i < cudavar_vtx_n; i++){
		opt_disp.push_back(MeshPointType(cudaH(i, 0), cudaH(i, 1), cudaH(i, 2)));
	}
}

//label
void SparseDispAugLag_PQ_Eigen::update_Z_diffvec()
{
	typedef Eigen::Matrix<double, 3, 3> Matrix33d;

	#pragma omp for nowait
	for(int i = 0; i < face_n; i ++)
	{
		int base_idx = i * 3;

		Matrix33d M;
		M.col(0) = Z_update_tmp[0].segment<3>(base_idx);
		M.col(1) = Z_update_tmp[1].segment<3>(base_idx);
		M.col(2) = Z_update_tmp[2].segment<3>(base_idx);
		Eigen::JacobiSVD<Matrix33d> jSVD(M, Eigen::ComputeFullV);

		Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
		Eigen::Matrix<double,1,3> Nt = N.transpose();

		M = M - (M * N) * Nt;

		Z[0].segment<3>(base_idx) = M.col(0);
		Z[1].segment<3>(base_idx) = M.col(1);
		Z[2].segment<3>(base_idx) = M.col(2);
	}
}

//cuda
__global__
void SparseDispAugLag_PQ_Eigen::cudaupdate_Z_diffvec()
{
	//typedef Eigen::Matrix<double, 3, 3> Matrix33d;

	//#pragma omp for nowait

	int idx = blockIdx.x*blockDim.x + threadIdx.x;
	if (idx < cudaface_n)
	{
		//int base_idx = i * 3;

		//Matrix33d M;
		cusp::array2d M(3, 3);
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				//here, we assume that cudaZ_update_tmp is two dimension array, rwo index equal to vertex index
				M(i, j) = cudaZ_update_tmp[j](idx, i);
			}
		}
		//M.col(0) = Z_update_tmp[0].segment<3>(base_idx);
		//M.col(1) = Z_update_tmp[1].segment<3>(base_idx);
		//M.col(2) = Z_update_tmp[2].segment<3>(base_idx);

		//how to do svd decomposition to 3*3 matrix?
		Eigen::JacobiSVD<Matrix33d> jSVD(M, Eigen::ComputeFullV);

		//Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
		//Eigen::Matrix<double,1,3> Nt = N.transpose();

		cusp::array2d N(3, 1);
		cusp::array2d Nt(1, 3);
		N(0, 0) = Nt(0, 0) = jSVD(0, 1);
		N(1, 0) = Nt(0, 1) = jSVD(1, 1);
		N(2, 0) = Nt(0, 2) = jSVD(2, 1);

		cusp::array2d cusparray;
		cusp::multiply(M, N, cusparray);
		cusp::multiply(cusparray, Nt, cusparray);
		cusp::blas::axpy(cusparray, M, -1);
		//M = M - (M * N) * Nt;

		//here, we assume that cudaZ is a two dimension array, rwo index equal to vertex index, and column inde is 0, 1, and 2
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cudaZ[j](idx, i) = M(i, j);
			}
		}
		//Z[0].segment<3>(base_idx) = M.col(0);
		//Z[1].segment<3>(base_idx) = M.col(1);
		//Z[2].segment<3>(base_idx) = M.col(2);
	}
}

void SparseDispAugLag_PQ_Eigen::initialize_diffvec_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_C;
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	int row_n = 0;
	face_vtx_idx.clear();

	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		std::vector<int> vtx_var_idx;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			vtx_var_idx.push_back(fv_it.handle().idx());
		}

		for(int i = 0; i < 3; i++){
			triplets_C.push_back(T(row_n, vtx_var_idx[i], 1.0 ));
			triplets_C.push_back(T(row_n, vtx_var_idx[3], -1.0 ));
			row_n ++;
		}

		face_vtx_idx.push_back(vtx_var_idx);
	}

	C.resize(row_n, var_vtx_n);
	C.setFromTriplets(triplets_C.begin(), triplets_C.end());
	Ct = C.transpose();

	for(int i = 0; i < 3; i++){
		K[i] = C * orig_vtx_pos[i];
	}
}

void SparseDispAugLag_PQ_Eigen::copydatafromhost2device()
{
	cudaupdate_mesh = update_mesh;
	cudaupdate_period = update_period;
	for (int i = 0; i < 3; ++i)
	{
		cudaorig_vtx_pos[i] = orig_vtx_pos[i];
		cudanew_vtx_pos[i] = new_vtx_pos[i];
	}

	cudapenalty_weight = penalty_weight;
	cudaorig_penalty_weight = orig_penalty_weight;
	cudasparsity_weight = sparsity_weight;
	cudasmoothness_weight = smoothness_weight;
	cudavtx_disp_weight = vtx_disp_weight;
	cudathreshold_smoothness = threshold_smoothness;
	cudasmoothness_energy_bound = smoothness_energy_bound;
	cudasmoothness_energy_bound_sqrt = smoothness_energy_bound_sqrt;
	cudadiffvec_planarity = diffvec_planarity;

	// Variables used to change penalty weight
	cudamax_penalty = max_penalty;
	cudaW_update_factor = W_update_factor;
	cudaoptimization_end = optimization_end;	// flags indicating end of optimization, either due to max number of iteration or due to convergence of the iteration
	cudaneed_incr_penalty = need_incr_penalty;
	cudaprimal_subproblem_converge = primal_subproblem_converge;

	cudaoptimization_converge = optimization_converge;
	cudamax_iteration = max_iteration;
	cudanb_threads = nb_threads;

	// All input displacements wait in this queue
	//std::vector< std::map<int, MeshPointType> > input_disp_queue;

	//boost::mutex mutex_optimization;
	//boost::mutex mutex_input_disp;


	double* valuePtr = Ct.valuePtr();
	int* innerIndexPtr = Ct.innerIndexPtr();
	int* outerIndexPtr = Ct.outerIndexPtr();
	for (int i = 0; i < Ct.nonZeros(); ++i)
	{
		cudaCt.row_indices[i] = innerIndexPtr[i];
		cudaCt.column_indices[i] = outerIndexPtr[i];
		cudaCt.values[i] = valuePtr[i];
	}

	valuePtr = C.valuePtr();
	innerIndexPtr = C.innerIndexPtr();
	outerIndexPtr = C.outerIndexPtr();
	for (int i = 0; i < C.nonZeros(); ++i)
	{
		cudaC.row_indices[i] = innerIndexPtr[i];
		cudaC.column_indices[i] = outerIndexPtr[i];
		cudaC.values[i] = valuePtr[i];
	}

	valuePtr = Et.valuePtr();
	innerIndexPtr = Et.innerIndexPtr();
	outerIndexPtr = Et.outerIndexPtr();
	for (int i = 0; i < Et.nonZeros(); ++i)
	{
		cudaEt.row_indices[i] = innerIndexPtr[i];
		cudaEt.column_indices[i] = outerIndexPtr[i];
		cudaEt.values[i] = valuePtr[i];
	}

	valuePtr = E.valuePtr();
	innerIndexPtr = E.innerIndexPtr();
	outerIndexPtr = E.outerIndexPtr();
	for (int i = 0; i < E.nonZeros(); ++i)
	{
		cudaE.row_indices[i] = innerIndexPtr[i];
		cudaE.column_indices[i] = outerIndexPtr[i];
		cudaE.values[i] = valuePtr[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cudaC43(i, j) = C43(i, j);
		}
	}


	for (int i = 0; i < Z_update_tmp[0].rows(); ++i)
	{
		for (int j = 0; j < Z_update_tmp[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				cudaZ_update_tmp[k](i, j) = Z_update_tmp[k][i][j];
				cudaY_update_tmp[k](i, j) = Y_update_tmp[k][i][j];
				cudaW_update_tmp[k](i, j) = W_update_tmp[k][i][j];
			}
		}
	}

	for (int i = 0; i < D1[0].rows(); ++i)
	{
		for (int j = 0; j < D1[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				cudaD1[k](i, j) = D1[k][i][j];
				cudaD2[k](i, j) = D2[k][i][j];
				cudaD3[k](i, j) = D3[k][i][j];
			}
		}
	}

	for (int i = 0; i < W[0].rows(); ++i)
	{
		for (int j = 0; j < W[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				cudaW[k](i, j) = W[k](i, j);
				cudaH[k](i, j) = H[k](i, j);
				cudaK[k](i, j) = K[k](i, j);
				cudaY[k](i, j) = Y[k](i, j);
				cudaF[k](i, j) = F[k](i, j);
				cudaZ[k](i, j) = Z[k](i, j);
			}
		}
	}

	for (int i = 0; i < prev_H[0].rows(); ++i)
	{
		for (int j = 0; j < prev_H[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				cudaprev_H[k](i, j) = prev_H[k](i, j);
				cudaH_diff[k](i, j) = prevH_diff[k](i, j);
			}
		}
	}
	// Matrix version of the above variables
	//Eigen::VectorXd W[3], H[3], K[3], Y[3], F[3], Z[3];
	//Eigen::VectorXd prev_H[3], H_diff[3];  // store previous H value for computing dual residual


	for (int i = 0; i < primal_residual_1[0].rows(); ++i)
	{
		for (int j = 0; j < primal_residual_1[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				cudaprimal_residual_1[k](i, j) = primal_residual_1[k](i, j);
				cudaprimal_residual_2[k](i, j) = primal_residual_2[k](i, j);
				cudaprimal_residual_3[k](i, j) = primal_residual_3[k](i, j);
			}
		}
	}

	for (int i = 0; i < primal_residual_1_inf_norm[0].rows(); ++i)
	{
		for (int j = 0; j < primal_residual_1_inf_norm[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				cudaprimal_residual_1_inf_norm[k](i, j) = primal_residual_1_inf_norm[k](i, j);
				cudaprimal_residual_2_inf_norm[k](i, j) = primal_residual_2_inf_norm[k](i, j);
				cudaprimal_residual_3_inf_norm[k](i, j) = primal_residual_3_inf_norm[k](i, j);
			}
		}
	}

	// Temporary storage for primal residual squared-norm in each component
	for (int i = 0; i < 3; ++i)
	{
		cudaprimal_residual_squared_norm[i] = primal_residual_squared_norm[i];
		cudadual_residual_squared_norm[i] = dual_residual_squared_norm[i];
	}
	cudadual_residual_total_sqr_norm = dual_residual_total_sqr_norm;

	// Dimension of the primal and dual residual. We need this to normalized the primal and dual residual
	cudaprimal_residual_dim = primal_residual_dim;
	cudadual_residual_dim = dual_residual_dim;

	// Primal and dual residual norms
	cudaprev_outer_primal_residual_sqr_norm = prev_outer_primal_residual_sqr_norm;
	//double prev_outer_iter_dual_residual_norm;
	//double prev_outer_iter_primal_residual_inf_norm;


	cudaeps_val = eps_val;
	//double eps_val;	// Epsilon value for defining norm related tolerances
	cudainit_dual_eps_val = init_dual_eps_val;
	//double init_dual_eps_val;

	// We use squared-norm instead of L2 norm to represent thresholds, so that we don't need to do sqrt
	cudaprimal_squared_norm_eps = primal_squared_norm_eps;
	cudafinal_dual_squared_norm_eps = final_dual_squared_norm_eps;
	cudacur_dual_squared_norm_eps = cur_dual_squared_norm_eps;
	//double primal_squared_norm_eps, final_dual_squared_norm_eps, cur_dual_squared_norm_eps;

	// The starting iteration number count for the current primal problem
	cudacurrent_primal_run_start_iter = current_primal_run_start_iter;
	cudaprimal_subproblem_maxiter = primal_subproblem_maxiter;
	//int current_primal_run_start_iter, primal_subproblem_maxiter;

	// Intermediate variables related to changing penalty weight
	cudalambda_primal2dual_sqr = lambda_primal2dual_sqr;
	cudalambda_dual2primal_sqr = lambda_dual2primal_sqr;
	//double lambda_primal2dual_sqr, lambda_dual2primal_sqr; // Threshold ratio between primal and dual residual norms
	cudatau_incr = tau_incr;
	//double tau_incr;	// Ratio of change for increasing penalty weight
	dualdual_sqaured_norm_eps_decr_ratio = dual_sqaured_norm_eps_decr_ratio;
	//double dual_sqaured_norm_eps_decr_ratio;	// Ratio of decreasing dual squared residual norm
	cudascaled_dual_change_ratio = scaled_dual_change_ratio;
	//double scaled_dual_change_ratio;	// Reciprocal of the penalty increase ratio
	cudamin_sqr_primal_residual_change_ratio = min_sqr_primal_residual_change_ratio;
	//double min_sqr_primal_residual_change_ratio;


	//how to represent map in cusp?
	std::map<int, MeshPointType> fixed_vtx_displacement;
	//std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	for (int i = 0; i < free_vtx.size(); ++i)
		cudafree_vtx[i] = free_vtx[i];
	//std::vector<int> free_vtx;	// Array indicating which vertices are free
	cudavar_vtx_n = var_vtx_n;
	cudaface_n = face_n;
	//int var_vtx_n, face_n; // the number of faces, will be 1/4 of the number of rows of C
	for (int i = 0; i < face_n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cudaface_vtx_idx(i, j) = face_vtx_idx[i][j];
		}
	}
	//std::vector< std::vector<int> > face_vtx_idx;
	for (int i = 0; i < free_vtx_idx.size(); ++i)
		cudafree_vtx_idx[i] = free_vtx_idx[i];
	//std::vector< int > free_vtx_idx;
	for (int i = 0; i < fixed_vtx_idx.size(); ++i)
		cudafixed_vtx_idx[i] = fixed_vtx_idx[i];
	//std::vector< int > fixed_vtx_idx;
	for (int i = 0; i < fixed_vtx_target.size(); ++i)
	{
		for (int j = 0; j < 3; ++j)
			cudafixed_vtx_target(i, j) = fixed_vtx_target[i][j];
	}
	//std::vector< MeshPointType > fixed_vtx_target;

	//initializing the coefficient matrix in the linear system
	cusp::identity_operator<double, cusp::device_memory> cudaI(cudavar_vtx_n, cudavar_vtx_n);
	cusp::array2d cusparray;
	cusp::multiply(cudaCt, cudaC, cusparray);
	cusp::array2d cuspb;
	cusp::multiply(cudaEt, cudaE, cuspb);
	cusp::blas::axpbypcz(cusparray, cuspb, cudaI, cudasparseCoeffMatrix, 1, 1, 1);
}

}}
