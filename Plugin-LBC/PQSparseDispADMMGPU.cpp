#include "PQSparseDispADMM.h"

#include "PQSparseDispADMMGPU.h"
#include "ConstrainedMeshPluginAux.h"
#include <Dolphin/Core/Scenegraph/Geometry/OpenMeshNode.h>
#include <Utilities/Qt/Visualization/MeshHistogram.h>
#include <Utilities/Qt/Widgets/HistogramWidget/HistogramWidget.h>
#include <ctime>
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

void PQTangentDispNormalConstraint::initialize_variables(OpenMeshNode *mesh_,
	const SparseMatrixXd &normal_basis,
	int update_period_,
	const std::map<int, MeshPointType> &fixed_vtx_disp,
	double sparsity_weight_,
	double smoothness_weight_,
	double vtx_disp_weight_,
	double init_penalty_weight_,
	double ep_abs_,
	double ep_rel_,
	double tau_incr_,
	bool threshold_smoothness_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;

	var_vtx_n = pmesh->n_vertices();

	update_mesh = true;
	update_period = update_period_;

	Nb = normal_basis;
	Nbt = Nb.transpose();

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	threshold_smoothness = threshold_smoothness_;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	penalty_incr_dual_residual_max_ratio = 5;
	tau_incr = tau_incr_;
	alpha = 1;
	last_alpha = 1;

	min_residual_change_ratio = 0.6;
	check_penalty_period = 10;

	max_penalty = 1e5;
	min_penalty = std::min(10.0, init_penalty_weight_);

	initialize_var_index();

	store_orig_vertex_positions();

	//initialize_disp_3rddiff_energy_matrix();
	initialize_disp_2nddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_prev_residual_norm();

	initialize_solver();

	update_W();
}


void PQTangentDispNormalConstraint::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness)
	{
		smoothness_energy_bound = F.squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}


void PQTangentDispNormalConstraint::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter)
	{
		free_vtx[iter->first] = 0;
	}
}

void PQTangentDispNormalConstraint::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_pos.resize(3 * n_vtx);

	for(int i = 0; i < n_vtx; i++)
	{
		MeshPointType pt = pmesh->point(PolyMeshType::VertexHandle(i));
		orig_vtx_pos(3*i) = pt[0];
		orig_vtx_pos(3*i+1) = pt[1];
		orig_vtx_pos(3*i+2) = pt[2];
	}
}

void PQTangentDispNormalConstraint::initialize_solver()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_I;
	int n_var = 3 * var_vtx_n;
	for(int i = 0; i < n_var; i++)
	{
		triplets_I.push_back(T(i, i, 1.0));
	}

	SparseMatrixXd I(n_var, n_var);
	I.setFromTriplets(triplets_I.begin(), triplets_I.end());
	solver.compute(I + Nbt * Nb + Et * E);

	//	SparseMatrixXd Iv(var_vtx_n, var_vtx_n);
	//	std::vector<T> triplets_Iv;
	//	for(int i = 0; i < var_vtx_n; i++){
	//		triplets_Iv.push_back(T(i, i, 1.0));
	//	}
	//	Iv.setFromTriplets(triplets_Iv.begin(), triplets_Iv.end());
	//	solver2.compute(Iv + Ct * C + Evt * E);
}


void PQTangentDispNormalConstraint::initialize_disp_2nddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> Triplet_type;
	std::vector<Triplet_type> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_2nddiff_polyline_idx(pmesh, polyline_idx);

	int row_n = 0;
	double coef[] = {1.0, -2.0, 1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++)
	{
		for(int k = 0; k < 3; k++)
		{
			triplets_E.push_back(Triplet_type(row_n, 3 * polyline_idx[i][k], coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 1, 3 * polyline_idx[i][k] + 1, coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 2, 3 * polyline_idx[i][k] + 2, coef[k]));
		}
		row_n += 3;
	}

	E.resize(row_n, 3 * var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();
	EH.setZero(E.rows());
	prev_EH = EH;

	if(threshold_smoothness)
	{
		F = E * orig_vtx_pos;
		W_update_tmp = F;
	}
	else
	{
		F.setZero(E.rows());
		W_update_tmp.setZero(E.rows());
	}
}



void PQTangentDispNormalConstraint::initialize_disp_3rddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> Triplet_type;
	std::vector<Triplet_type> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	int row_n = 0;
	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++)
	{
		for(int k = 0; k < 4; k++)
		{
			triplets_E.push_back(Triplet_type(row_n, 3 * polyline_idx[i][k], coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 1, 3 * polyline_idx[i][k] + 1, coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 2, 3 * polyline_idx[i][k] + 2, coef[k]));
		}
		row_n += 3;
	}

	E.resize(row_n, 3 * var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();
	EH.setZero(E.rows());
	prev_EH = EH;

	if(threshold_smoothness)
	{
		F = E * orig_vtx_pos;
		W_update_tmp = F;
	}
	else
	{
		F.setZero(E.rows());
		W_update_tmp.setZero(E.rows());
	}
}


void PQTangentDispNormalConstraint::initialize_primal_vars()
{
	int h_size = var_vtx_n * 3;
	int y_size = var_vtx_n * 3;
	Y_update_tmp.setZero(y_size);
	Y.setZero(y_size);
	H.setZero(h_size);
	prev_H.setZero(h_size);
}

void PQTangentDispNormalConstraint::zero_initialize_dual_vars()
{
	int d1_size = var_vtx_n * 3;
	int d2_size = E.rows();
	int d3_size = Nb.rows();
	D1.setZero(d1_size);
	last_D1 = D1;
	D2.setZero(d2_size);
	last_D2 = D2;
	D3.setZero(d3_size);
	last_D3 = D3;
	D1_t = D1;
	D2_t = D2;
	D3_t = D3;
	primal_residual_1.setZero(d1_size);
	primal_residual_2.setZero(d2_size);
	primal_residual_3.setZero(d3_size);
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::update_W()
{
	if(threshold_smoothness)
	{
		double W_update_factor = 1.0;
		double new_W_sqr_norm = W_update_tmp.squaredNorm();

		if(new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 ))
		{
			W_update_factor =  penalty_weight / (penalty_weight + smoothness_weight) ;
		}
		else if(new_W_sqr_norm > smoothness_energy_bound)
		{
			W_update_factor = smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm);
		}

		W = W_update_tmp * W_update_factor;
	}
	else
	{
		W = W_update_tmp * ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
}

//gpu code
void PQTangentDispNormalConstraint::cudaupdate_W()
{
	if(cudathreshold_smoothness)
	{
		double W_update_factor = 1.0;
		//double new_W_sqr_norm = W_update_tmp.squaredNorm();
		double new_W_sqr_norm = cusp::blas::dot(cudaW_update_tmp, cudaW_update_tmp);

		if(new_W_sqr_norm > cudasmoothness_energy_bound*std::pow((cudasmoothness_weight + cudapenalty_weight)/cudapenalty_weight, 2))
		{
			W_update_factor =  cudapenalty_weight/(cudapenalty_weight + cudasmoothness_weight);
		}
		else if(new_W_sqr_norm > cudasmoothness_energy_bound)
		{
			W_update_factor = cudasmoothness_energy_bound_sqrt/std::sqrt(new_W_sqr_norm);
		}

		cusp::blas::copy(cudaW_update_tmp, cudaW);
		cusp::blas::scal(cudaW, W_update_factor);
		//W = W_update_tmp*W_update_factor;
	}
	else
	{
		cusp::blas::copy(cudaW_update_tmp, cudaW);
		cusp::blas::scal(cudaW, (cudapenalty_weight/(cudapenalty_weight + cudasmoothness_weight)));
		//W = W_update_tmp*(penalty_weight/(penalty_weight + smoothness_weight));
	}
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::update_H()
{
#pragma omp single
	{
		//#ifdef USE_FASTADMM
		if(this->threshold_smoothness)
		{
			H = solver.solve(Y + D1_t + Et * (W - F + D2_t) - Nbt * D3_t);
		}
		else
		{
			H = solver.solve(Y + D1_t + Et * (W + D2_t) - Nbt * D3_t);
		}
		//#else
		//	G = solver.solve(Tt * (Y + D1) + ETt * (W - F + D2));
		//#endif
	}

#pragma omp sections
	{
#pragma omp section
		{
			prev_H = H;
			primal_residual_1 = Y - H;
			primal_residual_squared_norm[0] = primal_residual_1.squaredNorm();
			single_dual_residual_squared_norm[0] = ( H - prev_H ).squaredNorm();
		}

#pragma omp section
		{
			prev_EH = EH;
			EH.noalias() = E * H;
			if(this->threshold_smoothness)
			{
				primal_residual_2 = W - EH - F;
			}
			else
			{
				primal_residual_2 = W - EH;
			}
			primal_residual_squared_norm[1] = primal_residual_2.squaredNorm();
			single_dual_residual_squared_norm[1] = ( EH - prev_EH ).squaredNorm();
		}

#pragma omp section
		{
			primal_residual_3 = Nb * H;
			primal_residual_squared_norm[2] = primal_residual_3.squaredNorm();
		}
	}
}

//gpu code
//linear solver, right now it is direct method
//change it to iterative method
void PQTangentDispNormalConstraint::cudaupdate_H()
{
#pragma omp single
	{
		//#ifdef USE_FASTADMM
		//solve the following linear system by opennl
		//H = solver.solve(Y + D1_t + Et * (W - F + D2_t) - Nbt * D3_t);
		if(cudathreshold_smoothness)
		{
			cusp::array2d cudab;
			cusp::blas::axpbypcz(cudaW, cudaF, cudaD2_t, cudab, 1, -1, 1);
			cusp::multiply(cudaEt, cudab, cudab);

			cusp::array2d cudavector;
			cusp::multiply(cudaNbt, cudaD3_t, cudavector);
			cusp::blas::axpbypcz(cudaY, cudaD1_t, cudavector, cudab, 1, 1, -1);
			cusp::verbose_monitor<double> monitor(cudab, 100, 1e-3);
			cusp::identity_operator<double, cusp::device_memory> M(cudasparseCoeffMatrix.num_rows, cudasparseCoeffMatrix.num_rows);
			//here, the initial value of cudaH is a good guess?
			cusp::krylov::cg(cudasparseCoeffMatrix, cudaH, cudab, monitor, M);
			//H = solver.solve(Y + D1_t + Et*(W - F + D2_t) - Nbt*D3_t);
		}
		else
		{
			cusp::array2d cudab;
			cusp::blas::axpby(cudaW, cudaD2_t, cudab, 1, 1);
			cusp::multiply(cudaEt, cudab, cudab);

			cusp::array2d cudavector;
			cusp::multiply(cudaNbt, cudaD3_t, cudavector);
			cusp::blas::axpbypcz(cudaY, cudaD1_t, cudavector, cudab, 1, 1, -1);
			cusp::verbose_monitor<double> monitor(cudab, 100, 1e-3);
			cusp::identity_operator<double, cusp::device_memory> M(cudasparseCoeffMatrix.num_rows, cudasparseCoeffMatrix.num_rows);
			cusp::krylov::cg(cudasparseCoeffMatrix, cudaH, monitor, M);
			//H = solver.solve(Y + D1_t + Et*(W + D2_t) - Nbt*D3_t);
		}
	}

#pragma omp sections
	{
#pragma omp section
		{
			//prev_H = H;
			cusp::blas::copy(cudaH, cudaprev_H);
			//primal_residual_1 = Y - H;
			cusp::blas::axpby(cudaY, cudaH, cudaprimal_residual_1, 1, -1);
			//primal_residual_squared_norm[0] = primal_residual_1.squaredNorm();
			cusp::array2d cuspvector;
			cusp::blas::axpby(cudaH, cudaprev_H, cuspvector, 1, -1);
			cudaprimal_residual_squared_norm[0] = cusp::blas::dot(cuspvector, cuspvector);
			//single_dual_residual_squared_norm[0] = ( H - prev_H ).squaredNorm();
		}

#pragma omp section
		{
			cusp::blas::copy(cudaEH, cudaprev_EH);
			//prev_EH = EH;
			cusp::multiply(cudaE, cudaH, cudaEH);
			//EH.noalias() = E*H;
			if (cudathreshold_smoothness)
			{
				cusp::blas::axpbypcz(cudaW, cudaEH, cudaF, cudaprimal_residual_2, 1, -1, -1);
				//primal_residual_2 = W - EH - F;
			}
			else
			{
				cusp::blas::axpby(cudaW, cudaEH, cudaprimal_residual_2, 1, -1);
				//primal_residual_2 = W - EH;
			}
			cudaprimal_residual_squared_norm[1] = cusp::blas::dot(cudaprimal_residual_2, cudaprimal_residual_2);
			//primal_residual_squared_norm[1] = primal_residual_2.squaredNorm();
			cusp::array2d cuspvector;
			cusp::blas::axpby(cudaEH, cudaprev_EH, cuspvector, 1, -1);
			cudasingle_dual_residual_squared_norm[1] = cusp::blas::dot(cuspvector, cuspvector);
			//single_dual_residual_squared_norm[1] = ( EH - prev_EH ).squaredNorm();
		}

#pragma omp section
		{
			cusp::multiply(cudaNb, cudaH, cudaprimal_residual_3);
			//primal_residual_3 = Nb*H;
			cudaprimal_residual_squared_norm[2] = cusp::blas::dot(cudaprimal_residual_3, cudaprimal_residual_3);
			//primal_residual_squared_norm[2] = primal_residual_3.squaredNorm();
		}
	}
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::L1_update_Y()
{
#pragma omp for
	for(int i = 0; i < cudavar_vtx_n; ++i)
	{
		int base_idx = 3 * i;
		if(free_vtx[i])
		{
			Eigen::Vector3d cur_vec = Y_update_tmp.segment<3>(base_idx);
			double vec_norm = cur_vec.norm();
			if( 2 * vec_norm * penalty_weight <= sparsity_weight )
			{
				Y.segment<3>(base_idx).setZero();
			}
			else
			{
				Y.segment<3>(base_idx) = cur_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * vec_norm));
			}
		}
		else
		{
			MeshPointType &cur_disp = fixed_vtx_displacement[i];
			Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
			Eigen::Vector3d tmp_vec = Y_update_tmp.segment<3>(3 * i);
			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
			Y.segment<3>(base_idx) = disp_vec * (1-t) + tmp_vec * t;
		}
	}
}

//gpu code
__global__
void PQTangentDispNormalConstraint::cudaL1_update_Y()
{
#pragma omp for
	int idx = blockIdx.x*blockDim.x + threadIdx.x;
	if (idx >= cudavar_vtx_n)
		return;

	int base_idx = 3*idx;
	if(cudafree_vtx[idx])
	{
		cusp::array1d<double, cusp::device_memory> cur_vec(3);
		cur_vec[0] = cudaY_update_tmp[0](base_idx);
		cur_vec[1] = cudaY_update_tmp[1](base_idx);
		cur_vec[2] = cudaY_update_tmp[2](base_idx);
		double vec_norm = cusp::blas::nrm2(cur_vec);
		if(2*vec_norm*cudapenalty_weight <= cudasparsity_weight)
		{
			cudaY[0](base_idx) = 0;
			cudaY[1](base_idx) = 1;
			cudaY[2](base_idx) = 2;
		}
		else
		{
			cudaY[0](base_idx) = cur_vec[0]*(1.0 - 0.5*cudasparsity_weight/(cudapenalty_weight*vec_norm));
			cudaY[1](base_idx) = cur_vec[1]*(1.0 - 0.5*cudasparsity_weight/(cudapenalty_weight*vec_norm));
			cudaY[2](base_idx) = cur_vec[2]*(1.0 - 0.5*cudasparsity_weight/(cudapenalty_weight*vec_norm));

			//Y.segment<3>(base_idx) = cur_vec*(1.0 - 0.5*sparsity_weight/(penalty_weight*vec_norm));
		}
	}
	else
	{
		//MeshPointType &cur_disp = fixed_vtx_displacement[idx];
		//Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
		//Eigen::Vector3d tmp_vec = Y_update_tmp.segment<3>(3*idx);
		//double t = penalty_weight/(penalty_weight + vtx_disp_weight);
		//Y.segment<3>(base_idx) = disp_vec*(1 - t) + tmp_vec*t;


		double t = cudapenalty_weight/(cudapenalty_weight + cudavtx_disp_weight);
		cudaY[0](base_idx) = cudafixed_vtx_displacement[0](idx)*(1 - t) + cudaY_update_tmp[0](base_idx)*t;
		cudaY[1](base_idx) = cudafixed_vtx_displacement[1](idx)*(1 - t) + cudaY_update_tmp[1](base_idx)*t;
		cudaY[2](base_idx) = cudafixed_vtx_displacement[2](idx)*(1 - t) + cudaY_update_tmp[2](base_idx)*t;
	}
}

void PQTangentDispNormalConstraint::initialize_stopping_criteria_var()
{
	primal_ep_abs = dual_ep_abs = std::sqrt(double(Y.rows() + W.rows() + Nb.rows())) * ep_abs;
}


void PQTangentDispNormalConstraint::initialize_prev_residual_norm()
{
	//compute_primal_residual_mat();
	//prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
	//		primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
	prev_primal_residual_norm = 1e10;
	last_primal_residual_norm = last_dual_residual_norm = 1e10;
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num)
{
#pragma omp single
	{
		optimization_end = false;
		need_incr_penalty = false;

		if(iter_num >= 10000)
		{
			std::cout << "Max iteration reached" << std::endl;
			optimization_end = true;
		}

		if(!optimization_end)
		{
			// Check stopping criteria
			double primal_residual_norm = std::sqrt( primal_residual_squared_norm[0] + primal_residual_squared_norm[1] + primal_residual_squared_norm[2]);
			double dual_residual_norm = penalty_weight * std::sqrt(single_dual_residual_squared_norm[0] + single_dual_residual_squared_norm[1]);

			std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
			std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

			if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs){
				std::cout << "Residual norm within tolerance" << std::endl;
				optimization_end = true;
			}
			else
			{
				if(need_incr_penalty)
				{
					penalty_weight *= tau_incr;
					dual_residual_norm *= tau_incr;	// Due to the penalty parameter factor in front of the dual residual, we need to increase the dual residual too

					//#ifdef USE_FASTADMM
					restart_fastadmm = true;
					std::cout << "fast admm restarted due to penalty change" << std::endl;
					//#endif
				}
				//#ifdef USE_FASTADMM
				else
				{
					restart_fastadmm = std::max( last_primal_residual_norm, last_dual_residual_norm ) < std::max( primal_residual_norm, dual_residual_norm );
					std::cout << "fast admm restarted due to increased residual norm" << std::endl;
					//restart_fastadmm = false;
				}

				if(restart_fastadmm)
				{
					alpha = last_alpha = 1;
				}
				else
				{
					last_alpha = alpha;
					alpha = 0.5 * (1 + std::sqrt( 1.0 + 4 * last_alpha * last_alpha ));
				}

				last_primal_residual_norm = primal_residual_norm;
				last_dual_residual_norm = dual_residual_norm;
				//#endif

				std::cout << "Penalty:" << penalty_weight << std::endl;
				std::cout << "restart:" << this->restart_fastadmm << std::endl;
			}
		}
	}
#pragma omp sections
	{
#pragma omp section
		{
			if(!optimization_end){

				//#ifdef USE_FASTADMM

				last_D1 = D1;
				D1 = D1_t + primal_residual_1;
				if(need_incr_penalty){
					D1 /= tau_incr;
				}

				D1_t = D1;
				Y_update_tmp = H;

				if(!restart_fastadmm){
					double accel_factor = (last_alpha - 1) / alpha;
					D1_t.noalias() += (D1 - last_D1) * accel_factor;
					Y_update_tmp.noalias() += (H - prev_H) * accel_factor;
				}

				Y_update_tmp -= D1_t;
			}
		}

#pragma omp section
		{
			if(!optimization_end)
			{
				//				#ifdef USE_FASTADMM

				last_D2 = D2;
				D2 = D2_t + primal_residual_2;
				if(need_incr_penalty){
					D2 /= tau_incr;
				}

				D2_t = D2;
				W_update_tmp = EH;
				if(this->threshold_smoothness){
					W_update_tmp += F;
				}
				if(!restart_fastadmm){
					double accel_factor = (last_alpha - 1) / alpha;
					D2_t.noalias() += (D2 - last_D2) * accel_factor;
					W_update_tmp.noalias() += (EH - prev_EH) * accel_factor;
				}

				W_update_tmp -= D2_t;
				update_W();
			}
		}

#pragma omp section
		{
			if(!optimization_end){

				//				#ifdef USE_FASTADMM

				last_D3 = D3;
				D3 = D3_t + primal_residual_3;
				if(need_incr_penalty){
					D3 /= tau_incr;
				}

				D3_t = D3;
				if(!restart_fastadmm){
					double accel_factor = (last_alpha - 1) / alpha;
					D3_t.noalias() += (D3 - last_D3) * accel_factor;
				}
				//				#endif
			}
		}
	}
}

//gpu code
void PQTangentDispNormalConstraint::cudadual_var_update_with_stop_check_and_penalty_weight_update(int iter_num)
{
#pragma omp single
	{
		cudaoptimization_end = false;
		cudaneed_incr_penalty = false;

		if(iter_num >= 10000)
		{
			std::cout << "Max iteration reached" << std::endl;
			cudaoptimization_end = true;
		}

		if(!cudaoptimization_end)
		{
			// Check stopping criteria
			double primal_residual_norm = std::sqrt( cudaprimal_residual_squared_norm[0] + cudaprimal_residual_squared_norm[1] + cudaprimal_residual_squared_norm[2]);
			double dual_residual_norm = cudapenalty_weight*std::sqrt(cudasingle_dual_residual_squared_norm[0] + cudasingle_dual_residual_squared_norm[1]);

			std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << cudaprimal_ep_abs << std::endl;
			std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << cudadual_ep_abs << std::endl;

			if (primal_residual_norm <= cudaprimal_ep_abs && dual_residual_norm <= cudadual_ep_abs)
			{
				std::cout << "Residual norm within tolerance" << std::endl;
				cudaoptimization_end = true;
			}
			else
			{
				if(cudaneed_incr_penalty)
				{
					cudapenalty_weight *= cudatau_incr;
					dual_residual_norm *= cudatau_incr;	// Due to the penalty parameter factor in front of the dual residual, we need to increase the dual residual too

					//#ifdef USE_FASTADMM
					cudarestart_fastadmm = true;
					std::cout << "fast admm restarted due to penalty change" << std::endl;
					//#endif
				}
				//#ifdef USE_FASTADMM
				else
				{
					cudarestart_fastadmm = std::max( cudalast_primal_residual_norm, cudalast_dual_residual_norm ) < std::max( primal_residual_norm, dual_residual_norm );
					std::cout << "fast admm restarted due to increased residual norm" << std::endl;
					//restart_fastadmm = false;
				}

				if(cudarestart_fastadmm)
				{
					cudaalpha = cudalast_alpha = 1;
				}
				else
				{
					cudalast_alpha = cudaalpha;
					cudaalpha = 0.5 * (1 + std::sqrt(1.0 + 4*cudalast_alpha*cudalast_alpha));
				}

				cudalast_primal_residual_norm = primal_residual_norm;
				cudalast_dual_residual_norm = dual_residual_norm;
				//#endif

				std::cout << "Penalty:" << cudapenalty_weight << std::endl;
				std::cout << "restart:" << cudarestart_fastadmm << std::endl;
			}
		}
	}
#pragma omp sections
	{
#pragma omp section
		{
			if(!cudaoptimization_end)
			{
				//#ifdef USE_FASTADMM
				cusp::blas::copy(cudaD1, cudalast_D1);
				//last_D1 = D1;
				cusp::blas::axpby(cudaD1_t, cudaprimal_residual_1, cudaD1, 1, 1);
				//D1 = D1_t + primal_residual_1;
				if(cudaneed_incr_penalty)
				{
					cusp::blas::scal(cudaD1, 1/cudatau_incr);
					//D1 /= tau_incr;
				}

				cusp::blas::copy(cudaD1, cudaD1_t);
				//D1_t = D1;
				cusp::blas::copy(cudaH, cudaY_update_tmp);
				//Y_update_tmp = H;

				if(!cudarestart_fastadmm)
				{
					double accel_factor = (cudalast_alpha - 1)/cudaalpha;
					//D1_t.noalias() += (D1 - last_D1)*accel_factor;
					//Y_update_tmp.noalias() += (H - prev_H)*accel_factor;
					cusp::blas::axpbypcz(cudaD1, cudalast_D1, cudaD1_t, cudaD1_t, accel_factor, -accel_factor, 1);
					cusp::blas::axpbypcz(cudaH, cudaprev_H, cudaY_update_tmp, cudaY_update_tmp, accel_factor, -accel_factor, 1);
				}

				//Y_update_tmp -= D1_t;
				cusp::blas::axpby(cudaY_update_tmp, cudaD1_t, cudaY_update_tmp, 1, -1);
			}
		}

#pragma omp section
		{
			if(!cudaoptimization_end)
			{
				//				#ifdef USE_FASTADMM
				//last_D2 = D2;
				cusp::blas::copy(cudaD2, cudalast_D2);
				//D2 = D2_t + primal_residual_2;
				cusp::blas::axpby(cudaD2_t, cudaprimal_residual_2, cudaD2, 1, 1);
				if(cudaneed_incr_penalty)
				{
					//D2 /= tau_incr;
					cusp::blas::scal(cudaD2, 1/cudatau_incr);
				}

				//D2_t = D2;
				cusp::blas::copy(cudaD2, cudaD2_t);
				//W_update_tmp = EH;
				cusp::blas::copy(cudaEH, cudaW_update_tmp);
				if(cudathreshold_smoothness)
				{
					//W_update_tmp += F;
					cusp::blas::axpby(cudaW_update, cudaF, cudaW_update_tmp, 1, 1);
				}
				if(!cudarestart_fastadmm)
				{
					double accel_factor = (cudalast_alpha - 1)/cudaalpha;
					//D2_t.noalias() += (D2 - last_D2)*accel_factor;
					//W_update_tmp.noalias() += (EH - prev_EH)*accel_factor;
					cusp::blas::axpbypcz(cudaD1, cudalast_D2, cudaD2_t, cudaD2_t, accel_factor, -accel_factor, 1);
					cusp::blas::axpbypcz(cudaEH, cudaprev_H, cudaW_update_tmp, cudaW_update_tmp, accel_factor, -accel_factor, 1);
				}

				//W_update_tmp -= D2_t;
				cusp::blas::axpby(cudaW_update_tmp, cudaD2_t, cudaW_update_tmp, 1, -1);
				cudaupdate_W();
			}
		}

#pragma omp section
		{
			if(!cudaoptimization_end)
			{
				//				#ifdef USE_FASTADMM
				//last_D3 = D3;
				cusp::blas::copy(cudaD3, cudalast_D3);
				//D3 = D3_t + primal_residual_3;
				cusp::blas::axpy(cudaD3_t, cudaprimal_residual_3, cudaD3, 1, 1);
				if(cudaneed_incr_penalty)
				{
					//D3 /= tau_incr;
					cusp::blas::scal(cudaD3, 1/tau_incr);
				}

				//D3_t = D3;
				cusp::blas::copy(cudaD3, cudaD3_t);
				if(!cudarestart_fastadmm)
				{
					double accel_factor = (cudalast_alpha - 1)/cudaalpha;
					//D3_t.noalias() += (D3 - last_D3)*accel_factor;
					cusp::blas::axpbypcz(cudaD3, cudalast_D3, cudaD3_t, cudaD3_t, accel_factor, -accel_factor, 1);
				}
				//				#endif
			}
		}
	}
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::update_mesh_vertices(int iter)
{
	if(update_mesh && (iter % update_period == 0) ){
		Eigen::VectorXd new_vtx_pos = orig_vtx_pos + H;
		for(int i = 0; i < var_vtx_n; i++){
			int base_idx = 3 * i;
			pmesh->set_point(PolyMeshType::VertexHandle(i), MeshPointType(new_vtx_pos(base_idx), new_vtx_pos(base_idx + 1), new_vtx_pos(base_idx + 2) ));
		}

		pmesh->update_normals();

		if(update_mesh){
			mesh->setGeometryChanged();
		}
	}
}

//gpu code
__global__
void PQTangentDispNormalConstraint::cudaupdate_mesh_vertices(int iter)
{
	if(cudaupdate_mesh && (iter%cudaupdate_period == 0))
	{
		//Eigen::VectorXd new_vtx_pos = orig_vtx_pos + H;

		int idx = blockIdx.x*blockDim.x + threadIdx.x;
		if ( idx >= cudavar_vtx_n)
			return;

		//here, we should use array to represent mesh
			//int base_idx = 3*idx;
			//pmesh->set_point(PolyMeshType::VertexHandle(idx), MeshPointType(new_vtx_pos(base_idx), new_vtx_pos(base_idx + 1), new_vtx_pos(base_idx + 2)));
			cudavertexPositions(idx, 0) = cudaorig_vtx_pos(idx, 0) + cudaH(idx, 0);
			cudavertexPositions(idx, 1) = cudaorig_vtx_pos(idx, 1) + cudaH(idx, 1);
			cudavertexPositions(idx, 2) = cudaorig_vtx_pos(idx, 2) + cudaH(idx, 2);
	}
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::cudaL1_optimize()
{
	int iter = 0;

	omp_set_num_threads(8);

	while(true){
		std::cout << "Iteration " << iter++ << std::endl;

#pragma omp parallel
		{
			cudaL1_update_Y();
			cudaupdate_H();
			cudadual_var_update_with_stop_check_and_penalty_weight_update(iter);
		}

		if(optimization_end)
		{
			cudaupdate_mesh_vertices(0);
			return;
		}

		cudaupdate_mesh_vertices(iter);
	}
}

//need to be converted into gpu code
void PQTangentDispNormalConstraint::cudaL1_optimize(std::vector<MeshPointType> &opt_disp)
{
	double start_time = omp_get_wtime();

	//copy data from cpu to gpu, and then do the operations on gpu
	double cudapenalty_weight;
	double cudasparsity_weight;
	double cudasmoothness_weight;
	double cudavtx_disp_weight;
	bool cudathreshold_smoothness;
	double cudasmoothness_energy_bound;
	double cudasmoothness_energy_bound_sqrt;
	double cudaalpha, cudalast_alpha; 	// Variable for fast ADMM

	// Variables used to change penalty weight
	double cudamax_penalty, cudamin_penalty;
	int cudacheck_penalty_period;
	double cudamin_residual_change_ratio; // Threshold to determine that the change is small enough

	cusp::coo_matrix<int, double, cusp::device_memory> cudaNb, cudaNbt, cudaE, cudaEt;

	cusp::array2d<double, cusp::device_memory> cudaorig_vtx_pos, cudaorig_vtx_pos_v[3], cudanew_vtx_pos[3];
	cusp::array2d<double, cusp::device_memory> cudavertexPositions;

	cusp::array1d<int, cusp::device_memory> cudafree_vtx;	// Array indicating which vertices are free

	cusp::array2d<double, cusp::device_memory> cudaY_update_tmp, cudaY;
	cusp::array2d<double, cusp::device_memory> cudaW_update_tmp, cudaW, cudaF;
	cusp::array2d<double, cusp::device_memory> cudaprev_H, cudaH, cudaprev_EH, cudaEH;


	// Matrix version of the above variables
	cusp::array2d<double> cudaD1, cudaD2, cudaD3;
	cusp::array2d<double> cudalast_D1, cudalast_D2, cudalast_D3, cudaD1_t, cudaD2_t, cudaD3_t;	// Variables used for fast ADMM
	cusp::array2d<double> cudaprimal_residual_1, cudaprimal_residual_2, cudaprimal_residual_3;
	double cudaprimal_residual_squared_norm[3];
	double cudasingle_dual_residual_squared_norm[2];	// The dual residual norm only has two parts
	double cudaprev_primal_residual_norm;
	double cudapenalty_incr_dual_residual_max_ratio;	// Max ratio between dual and primal residual norm that allows incrementing penalty weight
	bool cudaoptimization_end, cudaneed_incr_penalty;
	bool cudarestart_fastadmm;
	double cudalast_primal_residual_norm, cudalast_dual_residual_norm;	// Variables for Fast ADMM


	// Intermediate variables related to stopping criteria
	double cudaep_abs, cudaep_rel;	// Absolute and relative minimum change ratio
	double cudaprimal_ep_abs, cudadual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double cudalambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double cudatau_incr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;

	int cudavar_vtx_n;

	//copy these class variable to device
	copydatafromhost2device(cudapenalty_weight, cudasparsity_weight, cudasmoothness_weight, cudavtx_disp_weight, cudathreshold_smoothness, cudasmoothness_energy_bound, cudasmoothness_energy_bound_sqrt, cudaalpha, cudalast_alpha, cudamax_penalty, cudamin_penalty, cudacheck_penalty_period, cudamin_residual_change_ratio, cudaNb, cudaNbt, cudaE, cudaEt,  cudaorig_vtx_pos, &cudaorig_vtx_pos_v, &cudanew_vtx_pos, cudavertexPositions, cudafree_vtx, cudaY_update_tmp, cudaY, cudaW_update_tmp, cudaW, cudaF, cudaprev_H, cudaH, cudaprev_EH, cudaEH, cudaD1, cudaD2, cudaD3, cudalast_D1, cudalast_D2, cudalast_D3, cudaD1_t, cudaD2_t, cudaD3_t, cudaprimal_residual_1, cudaprimal_residual_2, cudaprimal_residual_3, &cudaprimal_residual_squared_norm, &cudasingle_dual_residual_squared_norm, cudaprev_primal_residual_norm, cudapenalty_incr_dual_residual_max_ratio, cudaoptimization_end, cudaneed_incr_penalty, cudarestart_fastadmm, cudalast_primal_residual_norm, cudalast_dual_residual_norm, cudaep_abs, cudaep_rel, cudaprimal_ep_abs, cudadual_ep_abs, cudalambda, cudatau_incr, fixed_vtx_displacement, cudavar_vtx_n, cudasparseCoeffMatrix);
	cudaL1_optimize();
	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
	opt_disp.clear();

	for(int i = 0; i < var_vtx_n; i++){
		opt_disp.push_back(MeshPointType(H(3*i), H(3*i+1), H(3*i+2)));
	}
}

void PQTangentDispNormalConstraint::copydatafromhost2device(double& cudapenalty_weight, double& cudasparsity_weight, double& cudasmoothness_weight, double& cudavtx_disp_weight, bool& cudathreshold_smoothness, double& cudasmoothness_energy_bound, double& cudasmoothness_energy_bound_sqrt, double& cudaalpha, double& cudalast_alpha, double& cudamax_penalty, double& cudamin_penalty, int& cudacheck_penalty_period, double& cudamin_residual_change_ratio,	cusp::coo_matrix<int, double, cusp::device_memory>& cudaNb, cusp::coo_matrix<int, double, cusp::device_memory>& cudaNbt,	cusp::coo_matrix<int, double, cusp::device_memory>& cudaE, cusp::coo_matrix<int, double, cusp::device_memory>& cudaEt,					cusp::array2d<double, cusp::device_memory>& cudaorig_vtx_pos,
cusp::array2d<double, cusp::device_memory>& cudaorig_vtx_pos_v[3], cusp::array2d<double, cusp::device_memory>& cudanew_vtx_pos[3], cusp::array2d<double, cusp::device_memory>& cudavertexPositions,	cusp::array1d<int, cusp::device_memory>& cudafree_vtx,	cusp::array2d<double, cusp::device_memory>& cudaY_update_tmp, cusp::array2d<double, cusp::device_memory>& cudaY, cusp::array2d<double, cusp::device_memory>& cudaW_update_tmp, cusp::array2d<double, cusp::device_memory>& cudaW, cusp::array2d<double, cusp::device_memory>& cudaF, cusp::array2d<double, cusp::device_memory>& cudaprev_H, cusp::array2d<double, cusp::device_memory>& cudaH, cusp::array2d<double, cusp::device_memory>& cudaprev_EH, cusp::array2d<double, cusp::device_memory>& cudaEH, cusp::array2d<double>& cudaD1, cusp::array2d<double>& cudaD2, cusp::array2d<double>& cudaD3, cusp::array2d<double>& cudalast_D1, cusp::array2d<double>& cudalast_D2, cusp::array2d<double>& cudalast_D3, cusp::array2d<double>& cudaD1_t, cusp::array2d<double>& cudaD2_t, cusp::array2d<double>& cudaD3_t,	cusp::array2d<double>& cudaprimal_residual_1, cusp::array2d<double>& cudaprimal_residual_2, cusp::array2d<double>& cudaprimal_residual_3, double& cudaprimal_residual_squared_norm[3], double& cudasingle_dual_residual_squared_norm[2], double& cudaprev_primal_residual_norm, double& cudapenalty_incr_dual_residual_max_ratio, bool& cudaoptimization_end, bool& cudaneed_incr_penalty, bool& cudarestart_fastadmm, double& cudalast_primal_residual_norm, bool& cudalast_dual_residual_norm, double& cudaep_abs, double& cudaep_rel, double& cudaprimal_ep_abs, double& cudadual_ep_abs, double& cudalambda, double& cudatau_incr,	std::map<int, MeshPointType>& cudafixed_vtx_displacement, int& cudavar_vtx_n)
{
	//copy data from cpu to gpu, and then do the operations on gpu
	cudapenalty_weight = penalty_weight;
	cudasparsity_weight = sparsity_weight;
	cudasmoothness_weight = smoothness_weight;
	cudavtx_disp_weight = vtx_disp_weight;
	cudathreshold_smoothness = threshold_smoothness;
	cudasmoothness_energy_bound = smoothness_energy_bound;
	cudasmoothness_energy_bound_sqrt = smoothness_energy_bound_sqrt;
	cudaalpha = alpha;
	cudalast_alpha = last_alpha; 	// Variable for fast ADMM

	// Variables used to change penalty weight
	cudamax_penalty = max_penalty;
	cudamin_penalty = min_penalty;
	cudacheck_penalty_period = check_penalty_period;
	cudamin_residual_change_ratio = min_residual_change_ratio; // Threshold to determine that the change is small enough

	//copy value from eigen::sparsematrixxd to cusp csr_matrix
	double* valuePtr = Nb.valuePtr();
	int* innerIndexPtr = Nb.innerIndexPtr();
	int* outerIndexPtr = Nb.outerIndexPtr();
	for (int i = 0; i < Nb.nonZeros(); ++i)
	{
		cudaNb.row_indices[i] = innerIndexPtr[i];
		cudaNb.column_indices[i] = outerIndexPtr[i];
		cudaNb.values[i] = valuePtr[i];
	}
	valuePtr = Nbt.valuePtr();
	innerIndexPtr = Nbt.innerIndexPtr();
	outerIndexPtr = Nbt.outerIndexPtr();
	for (int i = 0; i < Nbt.nonZeros(); ++i)
	{
		cudaNbt.row_indices[i] = innerIndexPtr[i];
		cudaNbt.column_indices[i] = outerIndexPtr[i];
		cudaNbt.values[i] = valuePtr[i];
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
	valuePtr = Et.valuePtr();
	innerIndexPtr = Et.innerIndexPtr();
	outerIndexPtr = Et.outerIndexPtr();
	for (int i = 0; i < Et.nonZeros(); ++i)
	{
		cudaEt.row_indices[i] = innerIndexPtr[i];
		cudaEt.column_indices[i] = outerIndexPtr[i];
		cudaEt.values[i] = valuePtr[i];
	}


	for (int i = 0; i < orig_vtx_pos.rows(); ++i)
	{
		for (int j = 0; j < orig_vtx_pos.cols(); ++j)
			cudaorig_vtx_pos(i, j) = orig_vtx_pos[i][j];
	}
	for (int i = 0; i < orig_vtx_pos_v[0].rows(); ++i)
	{
		for (int j = 0; j < orig_vtx_pos_v[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
				cudaorig_vtx_pos_v[k](i, j) = orig_vtx_pos_v[k][i][j];
		}
	}
	for (int i = 0; i < cudanew_vtx_pos[0].rows(); ++i)
	{
		for (int j = 0; j < cudanew_vtx_pos[0].cols(); ++j)
		{
			for (int k = 0; k < 3; ++k)
				cudanew_vtx_pos[k](i, j) = cudanew_vtx_pos[k][i][j];
		}
	}
	for (int i = 0; i < vertexPositions.rows(); ++i)
	{
		for (int j = 0; j < vertexPositions.cols(); ++j)
			cudavertexPositions(i, j) = vertexPositions[i][j];
	}

	for (int i = 0; i < free_vtx.size(); ++i)
	{
		cudafree_vtx[i] = free_vtx[i];
	}

	for (int i = 0; i < Y.rows(); ++i)
	{
		for (int j = 0; j < Y.cols(); ++j)
		{
			cudaY_update_tmp(i, j) = Y_update_tmp[i][j];
			cudaY(i, j) = Y[i][j];
		}
	}
	for (int i = 0; i < W.rows(); ++i)
	{
		for (int j = 0; j < W.cols(); ++j)
		{
			cudaW_update_tmp(i, j) = W[i][j];
			cudaW(i, j) = W[i][j];
			cudaF(i, j) = F[i][j];
		}
	}
	for (int i = 0; i < H.rows(); ++i)
	{
		for (int j = 0; j < H.cols(); ++j)
		{
			cudaprev_H(i, j) = prev_H[i][j];
			cudaH(i, j) = H[i][j];
			cudaprev_EH(i, j) = prev_EH[i][j];
			cudaEH(i, j) = EH[i][j];
		}
	}


	for (int i = 0; i < D1.rows(); ++i)
	{
		for (int j = 0; j < D1.cols(); ++j)
		{
			cudaD1(i, j) = D1[i][j];
			cudaD2(i, j) = D2[i][j];
			cudaD3(i, j) = D3[i][j];
			cudalast_D1(i, j) = last_D1[i][j];
			cudalast_D2(i, j) = last_D2[i][j];
			cudalast_D3(i, j) = last_D3[i][j];
			cudaD1_t(i, j) = D1_t[i][j];
			cudaD2_t(i, j) = D2_t[i][j];
			cudaD3_t(i, j) = D3_t[i][j];
		}
	}
	for (int i = 0; i < primal_residual_1.rows(); ++i)
	{
		for (int j = 0; j < primal_residual_1.cols(); ++j)
		{
			cudaprimal_residual_1(i, j) = primal_residual_1[i][j];
			cudaprimal_residual_2(i, j) = primal_residual_2[i][j];
			cudaprimal_residual_3(i, j) = primal_residual_3[i][j];
		}
	}

	memcpy(cudaprimal_residual_squared_norm, primal_residual_squared_norm, sizeof(double)*3);
	memcpy(cudasingle_dual_residual_squared_norm, single_dual_residual_squared_norm, sizeof(double)*2);
	cudaprev_primal_residual_norm = prev_primal_residual_norm;
	cudapenalty_incr_dual_residual_max_ratio = penalty_incr_dual_residual_max_ratio;	// Max ratio between dual and primal residual norm that allows incrementing penalty weight
	cudaoptimization_end = optimization_end;
	cudaneed_incr_penalty = need_incr_penalty;
	cudarestart_fastadmm = restart_fastadmm;
	cudalast_primal_residual_norm = last_primal_residual_norm;
	cudalast_dual_residual_norm = last_dual_residual_norm;	// Variables for Fast ADMM


	// Intermediate variables related to stopping criteria
	cudaep_abs = ep_abs;
	cudaep_rel = ep_rel;	// Absolute and relative minimum change ratio
	cudaprimal_ep_abs = primal_ep_abs;
	cudadual_ep_abs = dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	cudalambda = lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	cudatau_incr = tau_incr;	// Ratio of change for increasing and decreasing penalty weight

	cudafixed_vtx_displacement = fixed_vtx_displacement;

	cudavar_vtx_n = var_vtx_n;
}


void PQSparseDispSoftConstraint::initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::vector<int> &constrained_vtx_index,
	double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
	double ep_abs_, double ep_rel_, double tau_incr_, int max_iter, bool threshold_smoothness_)
{
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	var_vtx_n = pmesh->n_vertices();
	face_n = pmesh->n_faces();

	threshold_smoothness = threshold_smoothness_;
	update_period = update_period_;

	smoothness_weight = smoothness_weight_;
	penalty_weight = init_penalty_weight_;
	orig_penalty_weight = init_penalty_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	sparsity_weight = sparsity_weight_;

	max_iteration = max_iter;
	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	lambda2 = 5;
	tau_incr = tau_incr_;
	tau_decr = 2;
	diagonal_dist_bound = 0.01;

	min_residual_change_ratio = 0.7;
	check_penalty_period = 10;

	max_penalty = 1e5;

	optimization_converge = false;
	difference_vec_planarity = false;

	fixed_vtx_displacement.clear();
	for(unsigned int i = 0; i < constrained_vtx_index.size(); ++ i){
		fixed_vtx_displacement[i] = MeshPointType(0.0);
	}

	initialize_var_index();

	store_orig_vertex_positions();

	initialize_centered_matrix();

	//initialize_disp_3rddiff_energy_matrix();
	initialize_disp_2nddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();

	var_initialized = true;
}


void PQSparseDispSoftConstraint::initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
	double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
	double ep_rel_, double tau_incr_, bool threshold_smoothness_, int max_iter, bool diff_vec_planarity)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	//	fixed_vtx_disp_array.clear();
	//	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter){
	//		fixed_vtx_disp_array.push_back(std::make_pair(iter->first, iter->second));
	//	}

	var_vtx_n = pmesh->n_vertices();
	face_n = pmesh->n_faces();

	update_mesh = true;
	update_histogram = false;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	threshold_smoothness = threshold_smoothness_;
	difference_vec_planarity = diff_vec_planarity;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	lambda2 = 5;
	tau_incr = tau_incr_;
	tau_decr = 2;
	diagonal_dist_bound = 0.01;

	min_residual_change_ratio = 0.7;
	check_penalty_period = 10;
	max_iteration = max_iter;

	max_penalty = 1e5;

	initialize_var_index();

	store_orig_vertex_positions();

	if(this->difference_vec_planarity){
		initialize_diffvec_matrix();
	}
	else{
		initialize_centered_matrix();
	}

	//initialize_disp_3rddiff_energy_matrix();
	initialize_disp_2nddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();
}


void PQSparseDispSoftConstraint::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness){
		smoothness_energy_bound = F[0].squaredNorm() + F[1].squaredNorm() + F[2].squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}


void PQSparseDispSoftConstraint::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
		iter != fixed_vtx_displacement.end(); ++ iter){
			free_vtx[iter->first] = 0;
	}
}


void PQSparseDispSoftConstraint::store_orig_vertex_positions()
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

void PQSparseDispSoftConstraint::initialize_solver()
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

void PQSparseDispSoftConstraint::initialize_centered_matrix()
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

void PQSparseDispSoftConstraint::initialize_diffvec_matrix()
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


void PQSparseDispSoftConstraint::initialize_disp_2nddiff_energy_matrix()
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


void PQSparseDispSoftConstraint::initialize_disp_3rddiff_energy_matrix()
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


void PQSparseDispSoftConstraint::initialize_primal_vars()
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

void PQSparseDispSoftConstraint::zero_initialize_dual_vars()
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
		dual_var_squared_norm[i] = 0;
	}
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::update_Z()
{
	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

#pragma omp for
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
}
//gpu code
void PQSparseDispSoftConstraint::CUDAupdate_Z()
{
	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

#pragma omp for

	int idx = blockIdx.x*blockDim.x + threadIdx.x;
	if (idx >= face_n)
		return;

	int base_idx = idx*4;

	Matrix43d M, Mc;
	M.col(0) = Z_update_tmp[0].segment<4>(base_idx);
	M.col(1) = Z_update_tmp[1].segment<4>(base_idx);
	M.col(2) = Z_update_tmp[2].segment<4>(base_idx);

	Mc.noalias() = C43*M;
	Eigen::JacobiSVD<Matrix43d> jSVD(Mc, Eigen::ComputeFullV);

	Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
	Eigen::Matrix<double,1,3> Nt = N.transpose();

	M.noalias() = Mc - (Mc*N)*Nt;

	for(int k = 0; k < 3; k++)
	{
		Z[k].segment<4>(base_idx) = M.col(k);
	}
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::update_Z_diffvec()
{
	typedef Eigen::Matrix<double, 3, 3> Matrix33d;

#pragma omp for
	for(int i = 0; i < face_n; i ++){
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
//gpu code
void PQSparseDispSoftConstraint::CUDAupdate_Z_diffvec()
{
	typedef Eigen::Matrix<double, 3, 3> Matrix33d;

#pragma omp for

	int idx = blockIdx.x*blockDim.x + threadIdx.x;
	if (idx >= face_n)
		return;

	int base_idx = idx*3;

	Matrix33d M;
	M.col(0) = Z_update_tmp[0].segment<3>(base_idx);
	M.col(1) = Z_update_tmp[1].segment<3>(base_idx);
	M.col(2) = Z_update_tmp[2].segment<3>(base_idx);
	Eigen::JacobiSVD<Matrix33d> jSVD(M, Eigen::ComputeFullV);

	Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
	Eigen::Matrix<double,1,3> Nt = N.transpose();

	M = M - (M*N)*Nt;

	Z[0].segment<3>(base_idx) = M.col(0);
	Z[1].segment<3>(base_idx) = M.col(1);
	Z[2].segment<3>(base_idx) = M.col(2);
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::update_W()
{
#pragma omp for
	for(int i = 0; i < 3; i++){
		W[i].noalias() = W_update_tmp[i] * ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
}
//gpu code
void PQSparseDispSoftConstraint::CUDAupdate_W()
{
#pragma omp for
	for(int i = 0; i < 3; i++)
	{
		W[i].noalias() = W_update_tmp[i]*(penalty_weight/(penalty_weight + smoothness_weight));
	}
}



//need to be converted into gpu code
void PQSparseDispSoftConstraint::update_W_with_thresholding()
{
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

#pragma omp for
	for(int i = 0; i < 3; i++){
		W[i].noalias() = W_update_tmp[i] * W_update_factor;
	}

}
//gpu code
void PQSparseDispSoftConstraint::CUDAupdate_W_with_thresholding()
{
#pragma omp single
	{
		W_update_factor = 1.0;
		double new_W_sqr_norm = W_update_tmp[0].squaredNorm() + W_update_tmp[1].squaredNorm() + W_update_tmp[2].squaredNorm();

		if(new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 ))
		{
			W_update_factor =  penalty_weight / (penalty_weight + smoothness_weight) ;
		}
		else if(new_W_sqr_norm > smoothness_energy_bound)
		{
			W_update_factor = smoothness_energy_bound_sqrt/std::sqrt(new_W_sqr_norm);
		}
	}

#pragma omp for
	for(int i = 0; i < 3; i++)
	{
		W[i].noalias() = W_update_tmp[i]*W_update_factor;
	}
}


//need to be converted into gpu code
void PQSparseDispSoftConstraint::update_H()
{
#pragma omp for
	for(int i = 0; i < 3; i++){
		prev_H[i] = H[i];
		H[i] = solver.solve(Ct * (Z[i] - K[i] + D1[i]) +  Et * (W[i] - F[i] + D3[i]) + Y[i] + D2[i]);
		H_diff[i] = H[i] - prev_H[i];

		new_vtx_pos[i] = orig_vtx_pos[i] + H[i];

		// Update primal residual
		primal_residual_1[i] = Z[i] - K[i];
		primal_residual_1[i].noalias() -= C * H[i];

		primal_residual_2[i] = Y[i] - H[i];

		primal_residual_3[i] = W[i] - F[i];
		primal_residual_3[i].noalias() -= E * H[i];

		// Store temporary squared norm
		primal_residual_squared_norm[i] = primal_residual_1[i].squaredNorm() + primal_residual_2[i].squaredNorm()
			+ primal_residual_3[i].squaredNorm();

		dual_residual_squared_norm[i] = (C * H_diff[i]).squaredNorm() + (E * H_diff[i]).squaredNorm() + H_diff[i].squaredNorm();
	}
}
//gpu code
void PQSparseDispSoftConstraint::CUDAupdate_H()
{
#pragma omp for
	for(int i = 0; i < 3; i++)
	{
		prev_H[i] = H[i];
		H[i] = solver.solve(Ct * (Z[i] - K[i] + D1[i]) +  Et * (W[i] - F[i] + D3[i]) + Y[i] + D2[i]);
		H_diff[i] = H[i] - prev_H[i];

		new_vtx_pos[i] = orig_vtx_pos[i] + H[i];

		// Update primal residual
		primal_residual_1[i] = Z[i] - K[i];
		primal_residual_1[i].noalias() -= C * H[i];

		primal_residual_2[i] = Y[i] - H[i];

		primal_residual_3[i] = W[i] - F[i];
		primal_residual_3[i].noalias() -= E * H[i];

		// Store temporary squared norm
		primal_residual_squared_norm[i] = primal_residual_1[i].squaredNorm() + primal_residual_2[i].squaredNorm()
			+ primal_residual_3[i].squaredNorm();

		dual_residual_squared_norm[i] = (C * H_diff[i]).squaredNorm() + (E * H_diff[i]).squaredNorm() + H_diff[i].squaredNorm();
	}
}

void PQSparseDispSoftConstraint::update_mesh_vertices()
{
	update_mesh_vertices(0);
}

void PQSparseDispSoftConstraint::update_mesh_vertices(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){
		for(int i = 0; i < var_vtx_n; i++){
			pmesh->set_point(PolyMeshType::VertexHandle(i), MeshPointType( new_vtx_pos[0](i), new_vtx_pos[1](i), new_vtx_pos[2](i)));
		}

		pmesh->update_normals();
		mesh->setGeometryChanged();
	}
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::L1_update_Y()
{
#pragma omp for
	for(int i = 0; i < var_vtx_n; ++ i){
		if(free_vtx[i]){
			double row_vec_norm = std::sqrt( std::pow(Y_update_tmp[0](i), 2) + std::pow(Y_update_tmp[1](i), 2) + std::pow(Y_update_tmp[2](i), 2) );
			if( 2 * row_vec_norm * penalty_weight <= sparsity_weight ){
				Y[0](i) = Y[1](i) = Y[2](i) = 0.0;
			}
			else{
				double t = 1.0 - 0.5 * sparsity_weight / (penalty_weight * row_vec_norm);
				Y[0](i) = Y_update_tmp[0](i) * t;
				Y[1](i) = Y_update_tmp[1](i) * t;
				Y[2](i) = Y_update_tmp[2](i) * t;
			}
		}
		else{
			MeshPointType &cur_disp = fixed_vtx_displacement[i];
			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
			Y[0](i) = cur_disp[0] * (1-t) + Y_update_tmp[0](i) * t;
			Y[1](i) = cur_disp[1] * (1-t) + Y_update_tmp[1](i) * t;
			Y[2](i) = cur_disp[2] * (1-t) + Y_update_tmp[2](i) * t;
		}
	}
}
//gpu code
void PQSparseDispSoftConstraint::CUDAL1_update_Y()
{
#pragma omp for

	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if ( idx >= var_vtx_n )
		return;

	if(free_vtx[idx])
	{
		double row_vec_norm = std::sqrt( std::pow(Y_update_tmp[0](idx), 2) + std::pow(Y_update_tmp[1](idx), 2) + std::pow(Y_update_tmp[2](idx), 2) );
		if( 2 * row_vec_norm * penalty_weight <= sparsity_weight )
		{
			Y[0](idx) = Y[1](idx) = Y[2](idx) = 0.0;
		}
		else
		{
			double t = 1.0 - 0.5*sparsity_weight/(penalty_weight*row_vec_norm);
			Y[0](idx) = Y_update_tmp[0](idx)*t;
			Y[1](idx) = Y_update_tmp[1](idx)*t;
			Y[2](idx) = Y_update_tmp[2](idx)*t;
		}
	}
	else
	{
		MeshPointType &cur_disp = fixed_vtx_displacement[idx];
		double t = penalty_weight/(penalty_weight + vtx_disp_weight);
		Y[0](idx) = cur_disp[0]*(1 - t) + Y_update_tmp[0](idx)*t;
		Y[1](idx) = cur_disp[1]*(1 - t) + Y_update_tmp[1](idx)*t;
		Y[2](idx) = cur_disp[2]*(1 - t) + Y_update_tmp[2](idx)*t;
	}
}


void PQSparseDispSoftConstraint::initialize_stopping_criteria_var()
{
	primal_ep_abs = dual_ep_abs = std::sqrt(double(Z[0].rows() + Y[0].rows() + W[0].rows()) * 3) * ep_abs;
}


void PQSparseDispSoftConstraint::initialize_primal_residual_norm()
{
	//compute_primal_residual_mat();
	//prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
	//		primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
	prev_primal_residual_norm = 1e10;
}


void PQSparseDispSoftConstraint::dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num)
{
#pragma omp single
	{
		optimization_end = false;
		need_incr_penalty = false;

		if(iter_num >= this->max_iteration){
			std::cout << "Max iteration reached" << std::endl;
			optimization_end = true;
		}

		// If optimization ends because of max_iteartion, we still update the penalty weight and
		if((!optimization_end) || iter_num == max_iteration){
			// Check stopping criteria
			double primal_residual_norm = std::sqrt( primal_residual_squared_norm[0] + primal_residual_squared_norm[1] + primal_residual_squared_norm[2] );
			double dual_residual_norm = penalty_weight * std::sqrt(dual_residual_squared_norm[0] + dual_residual_squared_norm[1] + dual_residual_squared_norm[2]);
			double dual_residual_norm_eps = dual_ep_abs + ep_rel * penalty_weight * std::sqrt( dual_var_squared_norm[0] + dual_var_squared_norm[1] + dual_var_squared_norm[2] );

			std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
			std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_residual_norm_eps << std::endl;

			if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_residual_norm_eps){
				std::cout << "Residual norm within tolerance" << std::endl;
				optimization_end = true;
				optimization_converge = true;
			}
			else{
				// Update penalty weight
				if(iter_num > 0 && iter_num % check_penalty_period == 0){
					// Make sure current penalty does not exceed max value
					if(penalty_weight * tau_incr <= max_penalty){
						if(dual_residual_norm <= primal_residual_norm * lambda2){
							//if(dual_residual_norm <= primal_residual_norm){
							// If we cannot update because dual residual is too large, we do not update the previous primal residual value

							// Increase penalty parameter if primal residual is too large w.r.t. dual residual,
							// or if the primal residual does not decrease enough
							need_incr_penalty = (primal_residual_norm > min_residual_change_ratio * prev_primal_residual_norm && primal_residual_norm > primal_ep_abs)
								|| (primal_residual_norm > dual_residual_norm * lambda);
							prev_primal_residual_norm = primal_residual_norm;
						}
					}


				}

				if(need_incr_penalty){
					penalty_weight *= tau_incr;
				}
			}
		}

		//std::cout << "Penalty Weight:" << penalty_weight << std::endl;
	}


	if((!optimization_end) || iter_num == max_iteration){
#pragma omp for
		for(int i = 0; i < 3; i++){
			// Update dual variables
			D1[i] += primal_residual_1[i];
			D2[i] += primal_residual_2[i];
			D3[i] += primal_residual_3[i];


			if(need_incr_penalty){
				D1[i] /= tau_incr;
				D2[i] /= tau_incr;
				D3[i] /= tau_incr;
			}

			dual_var_squared_norm[i] = D1[i].squaredNorm() + D2[i].squaredNorm() + D3[i].squaredNorm();

			// Update auxiliary data for other primal variable updates
			Z_update_tmp[i] = K[i] - D1[i];
			Z_update_tmp[i].noalias() += C * H[i];

			Y_update_tmp[i] = H[i] - D2[i];

			W_update_tmp[i] = F[i] - D3[i];
			W_update_tmp[i].noalias() += E * H[i];
		}
	}
}


void PQSparseDispSoftConstraint::update_diagonal_dist_histogram(int iter_num)
{
	if(update_histogram && (iter_num % update_period == 0)){
		histogram->setMeasures(face_diagonal_dist);
	}
}


//need to be converted into gpu code
void PQSparseDispSoftConstraint::L1_optimize_unbounded_smoothness()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(8);
	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
		{
			update_Z();
			L1_update_Y();
			update_W();
			update_H();
			dual_var_update_with_stop_check_and_penalty_weight_update(iter);
		}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);

	}
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::L1_optimize_bounded_smoothness()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(8);

	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
		{
			update_Z();
			L1_update_Y();
			update_W_with_thresholding();
			update_H();
			dual_var_update_with_stop_check_and_penalty_weight_update(iter);
		}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);
	}
}


//need to be converted into gpu code
void PQSparseDispSoftConstraint::L1_optimize_unbounded_smoothness_diffvec()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(8);
	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
		{
			update_Z_diffvec();
			L1_update_Y();
			update_W();
			update_H();
			dual_var_update_with_stop_check_and_penalty_weight_update(iter);
		}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);

	}
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::L1_optimize_bounded_smoothness_diffvec()
{
	int iter = 0;
	optimization_end = false;

	omp_set_num_threads(8);

	while(true){
		iter++;
		std::cout << "Iteration " << iter << std::endl;

#pragma omp parallel
		{
			update_Z_diffvec();
			L1_update_Y();
			update_W_with_thresholding();
			update_H();
			dual_var_update_with_stop_check_and_penalty_weight_update(iter);
		}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}
		update_mesh_vertices(iter);
	}
}

void PQSparseDispSoftConstraint::threaded_L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(!mutex_optimization.try_lock()){
		return;
	}


	if(this->var_initialized){
		// Use the last element of input disp queue as input to the current optimization, then clear the queue
		mutex_input_disp.lock();
		bool empty_disp = input_disp_queue.empty();
		if(!empty_disp){
			fixed_vtx_displacement = input_disp_queue.back();
			input_disp_queue.clear();
		}
		mutex_input_disp.unlock();

		while (true){

			// If there is no new input and no remaining residual from previous optimization, we can exit
			if(empty_disp && optimization_converge){
				break;
			}
			else{
				std::cout << "empty_disp:" << empty_disp << std::endl;
				std::cout << "optimization_converge" << optimization_converge << std::endl;
			}


			// Use the original sparsity weight if there is new input
			if(!empty_disp){
				sparsity_weight = orig_penalty_weight;

#pragma omp parallel for
				for(int i = 0; i < 3; i++){
					// Update dual variables
					D1[i].fill(0.0);
					D2[i].fill(0.0);
					D3[i].fill(0.0);
					dual_var_squared_norm[i] = 0;

					// Update auxiliary data for other primal variable updates
					Z_update_tmp[i] = K[i];
					Z_update_tmp[i].noalias() += C * H[i];

					Y_update_tmp[i] = H[i];

					W_update_tmp[i] = F[i];
					W_update_tmp[i].noalias() += E * H[i];
				}
			}

			initialize_primal_residual_norm();
			L1_optimize(opt_disp);

			mutex_input_disp.lock();
			empty_disp = input_disp_queue.empty();
			if(!empty_disp){
				fixed_vtx_displacement = input_disp_queue.back();
				input_disp_queue.clear();
			}
			mutex_input_disp.unlock();
		}

	}

	mutex_optimization.unlock();
}

void PQSparseDispSoftConstraint::threaded_L1_optimize(const std::map<int, MeshPointType> &fixed_vtx_disp, std::vector<MeshPointType> &opt_disp)
{
	mutex_input_disp.lock();
	input_disp_queue.push_back(fixed_vtx_disp);
	mutex_input_disp.unlock();

	threaded_L1_optimize(opt_disp);
}

//need to be converted into gpu code
void PQSparseDispSoftConstraint::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	this->optimization_converge = false;
	double start_time = omp_get_wtime();
	if(difference_vec_planarity){
		if(threshold_smoothness){
			L1_optimize_bounded_smoothness_diffvec();
		}
		else{
			L1_optimize_unbounded_smoothness_diffvec();
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

//need to be converted into gpu code
void PQSparseDispSoftConstraint::reset_data(const std::vector<MeshPointType> &init_disp)
{
	for(int i = 0; i < 3; i ++)
	{
		for(int j = 0; j < this->var_vtx_n; j++)
		{
			H[i](j) = init_disp[j][i];
		}

		prev_H[i] = H[i];
		D1[i].fill(0.0);
		D2[i].fill(0.0);
		D3[i].fill(0.0);

		Z_update_tmp[i] = K[i] - D1[i];
		Z_update_tmp[i].noalias() += C * H[i];

		Y_update_tmp[i] = H[i] - D2[i];

		W_update_tmp[i] = F[i] - D3[i];
		W_update_tmp[i].noalias() += E * H[i];
	}
}
//gpu code
void PQSparseDispSoftConstraint::CUDAreset_data(const std::vector<MeshPointType> &init_disp)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < this->var_vtx_n; j++)
		{
			H[i](j) = init_disp[j][i];
		}

		prev_H[i] = H[i];
		D1[i].fill(0.0);
		D2[i].fill(0.0);
		D3[i].fill(0.0);

		Z_update_tmp[i] = K[i] - D1[i];
		Z_update_tmp[i].noalias() += C*H[i];

		Y_update_tmp[i] = H[i] - D2[i];

		W_update_tmp[i] = F[i] - D3[i];
		W_update_tmp[i].noalias() += E * H[i];
	}
}
