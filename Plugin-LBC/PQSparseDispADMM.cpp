/*
 * PQSparseDispADMM.cpp
 *
 *  Created on: Jul 9, 2012
 *      Author: Bailin Deng
 */

#include "PQSparseDispADMM.h"
#include "ConstrainedMeshPluginAux.h"
#include <Dolphin/Core/Scenegraph/Geometry/OpenMeshNode.h>
#include <Utilities/Qt/Visualization/MeshHistogram.h>
#include <Utilities/Qt/Widgets/HistogramWidget/HistogramWidget.h>
#include <ctime>
#include <algorithm>
#include <CGAL/Cartesian.h>
#include <CGAL/linear_least_squares_fitting_3.h>
#include <omp.h>


namespace Dolphin {

namespace plugins {

typedef CGAL::Cartesian<double>	Data_Kernel;
/* Some CGAL specific typedefs. Copied literally from the examples in the	*
 * CGAL manual of the geometry processing package.							*/
typedef Data_Kernel::Point_3    DPoint;
typedef Data_Kernel::Plane_3    Plane3;

inline DPoint cgal_point_from_vec3d(const MeshPointType &point)
{
	return DPoint(point[0], point[1], point[2]);
}

inline MeshPointType vec3d_from_cgal_point(const DPoint& point){
	return MeshPointType(point.x(), point.y(), point.z());
}

// Debug routine to check least squares fitting plane using CGAL
void check_fitting_plane(const MeshPointType &v1, const MeshPointType &v2, const MeshPointType &v3,
		const MeshPointType &v4, const MeshPointType &N)
{
	std::vector<DPoint> pts;
	pts.push_back(cgal_point_from_vec3d(v1));
	pts.push_back(cgal_point_from_vec3d(v2));
	pts.push_back(cgal_point_from_vec3d(v3));
	pts.push_back(cgal_point_from_vec3d(v4));
	Plane3 plane;
	DPoint centroid_pt;

	CGAL::linear_least_squares_fitting_3(pts.begin(),pts.end(), plane, centroid_pt, CGAL::Dimension_tag<0>());
	MeshPointType plane_N(plane.a(), plane.b(), plane.c());
	plane_N.normalize();
	MeshPointType N_normalized = N;
	N_normalized.normalize();
	double diff = std::abs(std::abs(plane_N.dot(N_normalized)) - 1.0);
	if( diff > 1e-5 ){
		std::cout << "Normal diff:" << diff << std::endl;
	}

	double center_norm = vec3d_from_cgal_point(centroid_pt).norm();
	if( center_norm > 1e-5){
		std::cout << "center_norm:" << center_norm << std::endl;
	}
}

void PQSparseDispSDMM::set_histogram(MeshHistogram *histogram_)
{
	update_histogram = true;
	histogram = histogram_;
}

void PQSparseDispSDMM::initialize_variables(PolyMeshType *pmesh_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double lambda_, double tau_incr_, double tau_decr_, bool use_mat_var_)
{
	// Initialize variable indices
	pmesh = pmesh_;
	fixed_vtx_displacement = fixed_vtx_disp;
	use_mat_var = use_mat_var_;
	var_vtx_n = pmesh->n_vertices() - fixed_vtx_displacement.size();

	update_mesh = false;
	update_histogram = false;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;

	Z_weight_rel = Y_weight_rel = W_weight_rel = 1;
	Z_weight_rel_square = Y_weight_rel_square = W_weight_rel_square = 1;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = lambda_;
	tau_incr = tau_incr_;
	tau_decr = tau_decr_;
	//diagonal_dist_bound = 0.01;

	diagonal_dist_bound = 0.00001;

	initialize_var_index();

	initialize_centered_matrix();

	initialize_disp_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_stopping_criteria_var();

	initialize_solver();
}

void PQSparseDispSDMM::initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double lambda_, double tau_incr_, double tau_decr_, bool use_mat_var_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	use_mat_var = use_mat_var_;
	var_vtx_n = pmesh->n_vertices() - fixed_vtx_displacement.size();

	update_mesh = true;
	update_histogram = false;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;

	Z_weight_rel = Y_weight_rel = W_weight_rel = 1;
	Z_weight_rel_square = Y_weight_rel_square = W_weight_rel_square = 1;


	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = lambda_;
	tau_incr = tau_incr_;
	tau_decr = tau_decr_;
	diagonal_dist_bound = 0.01;

	initialize_var_index();

	store_orig_vertex_positions();

	initialize_centered_matrix();

	initialize_disp_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_stopping_criteria_var();

	initialize_solver();
}


void PQSparseDispSDMM::initialize_penalty_method_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double penalty_incr_ratio)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	use_mat_var = true;
	var_vtx_n = pmesh->n_vertices() - fixed_vtx_displacement.size();

	update_mesh = true;
	update_histogram = false;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;

	Z_weight_rel = Y_weight_rel = W_weight_rel = 1;
	Z_weight_rel_square = Y_weight_rel_square = W_weight_rel_square = 1;


	ep_abs = 1e-3;
	ep_rel = 1e-3;
	lambda = 10;
	tau_incr = 2;
	tau_decr = 2;
	diagonal_dist_bound = 0.01;
	penalty_incr = penalty_incr_ratio;

	initialize_var_index();

	store_orig_vertex_positions();

	initialize_centered_matrix();

	initialize_disp_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	update_Z_mat();

	get_initial_value_and_primal_residual();

	initialize_solver();
}

void PQSparseDispSDMM::initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp, double sparsity_weight_,
		double smoothness_weight_, double init_penalty_weight_, double Z_weight, double Y_weight, double W_weight,
		double min_change_bound, double lambda_, double tau_incr_, double tau_decr_, bool use_mat_var_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	use_mat_var = use_mat_var_;
	var_vtx_n = pmesh->n_vertices() - fixed_vtx_displacement.size();

	update_mesh = true;
	update_histogram = false;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;

	Z_weight_rel = Z_weight;
	Y_weight_rel = Y_weight;
	W_weight_rel = W_weight;
	Z_weight_rel_square = Z_weight * Z_weight;
	Y_weight_rel_square = Y_weight * Y_weight;
	W_weight_rel_square = W_weight * W_weight;

	min_vec_change_threshold = min_change_bound;

	ep_abs = 1e-3;
	ep_rel = 1e-3;
	lambda = lambda_;
	tau_incr = tau_incr_;
	tau_decr = tau_decr_;
	diagonal_dist_bound = 0.01;

	initialize_var_index();

	store_orig_vertex_positions();

	initialize_centered_matrix();

	initialize_disp_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_stopping_criteria_var();

	initialize_solver_weighted();
}

void PQSparseDispSDMM::initialize_stopping_criteria_var()
{
	if(use_mat_var){
		J_sqr_norm = F_mat.squaredNorm() + K_mat.squaredNorm();
		primal_ep_abs = dual_ep_abs = std::sqrt(double(Z_mat.rows() + Y_mat.rows() + W_mat.rows()) * 3) * ep_abs;
	}
	else{
		double sqrnorm_col[] = {0.0, 0.0, 0.0};
		for(int i = 0; i < 3; i++){
			sqrnorm_col[i] = F[i].squaredNorm() + K[i].squaredNorm();
		}

		J_sqr_norm = sqrnorm_col[0] + sqrnorm_col[1] + sqrnorm_col[2];
		primal_ep_abs = dual_ep_abs = std::sqrt(double(Z[0].rows() + Y[0].rows() + W[0].rows()) * 3) * ep_abs;
	}


}


void PQSparseDispSDMM::initialize_var_index()
{
	int n_vtx = pmesh->n_vertices();
	vtx_sol_index.assign(n_vtx, -2);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter){
		vtx_sol_index[iter->first] = -1;
	}

	int cur_idx = 0;
	for(int i = 0; i < n_vtx; i++){
		if(vtx_sol_index[i] == -2){
			vtx_sol_index[i] = cur_idx++;
		}
	}
}


void PQSparseDispSDMM::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_pos.resize(n_vtx);

	for(int i = 0; i < n_vtx; i++){
		PolyMeshType::VertexHandle vh(i);
		if(vtx_sol_index[i] >= 0){
			orig_vtx_pos[i] = pmesh->point(vh);
		}
		else{
			orig_vtx_pos[i] = pmesh->point(vh) + fixed_vtx_displacement[i];
		}
	}
}


void PQSparseDispSDMM::initialize_solver_weighted()
{
	SparseMatrixXd I(var_vtx_n, var_vtx_n);

	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_I;
	for(int i = 0; i < var_vtx_n; i++){
		triplets_I.push_back(T(i, i, Y_weight_rel));
	}

	I.setFromTriplets(triplets_I.begin(), triplets_I.end());
	solver.compute(Ct * C * Z_weight_rel + Et * E * W_weight_rel + I);
}

void PQSparseDispSDMM::initialize_solver()
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

void PQSparseDispSDMM::initialize_centered_matrix()
{
	// Pre-compute fixed values
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_C;
	std::vector<MeshPointType> K_vec;
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		MeshPointType current_center(0.0);
		std::vector<MeshPointType> cur_pos;
		std::vector<int> vtx_var_idx;
		bool has_var_vtx = false;

		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			cur_pos.push_back(pmesh->point(fv_it));
			current_center += pmesh->point(fv_it);

			int vtx_idx = fv_it.handle().idx();
			vtx_var_idx.push_back(vtx_sol_index[vtx_idx]);

			if(vtx_sol_index[vtx_idx] == -1){
				// For fixed vertex, new position is fixed
				current_center += fixed_vtx_displacement[vtx_idx];
				cur_pos.back() += fixed_vtx_displacement[vtx_idx];
			}
			else{
				has_var_vtx = true;
			}
		}

		if(has_var_vtx){
			current_center *= 0.25;
			for(int i = 0; i < 4; i++){
				int cur_row = K_vec.size();
				K_vec.push_back( cur_pos[i] - current_center );   // Constant term for mean-centered values
				for(int k = 0; k < 4; k++){
					if(vtx_var_idx[k] >= 0){
						triplets_C.push_back(T(cur_row, vtx_var_idx[k], (k==i) ? 0.75:(-0.25) ));
					}
				}
			}
		}
	}

	int num_row_C = K_vec.size();
	C.resize(num_row_C, var_vtx_n);
	C.setFromTriplets(triplets_C.begin(), triplets_C.end());
	Ct = C.transpose();

	if(use_mat_var){
		K_mat.resize(num_row_C, 3);
		for(int i = 0; i < num_row_C; i++){
			K_mat(i, 0) = K_vec[i][0];
			K_mat(i, 1) = K_vec[i][1];
			K_mat(i, 2) = K_vec[i][2];
		}
	}
	else{
		K[0].resize(num_row_C);
		K[1].resize(num_row_C);
		K[2].resize(num_row_C);
		for(int i = 0; i < num_row_C; i++){
			K[0](i) = K_vec[i][0];
			K[1](i) = K_vec[i][1];
			K[2](i) = K_vec[i][2];
		}
	}
}

void PQSparseDispSDMM::initialize_disp_energy_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_E;
	std::vector<MeshPointType> F_vec;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	std::vector< std::pair<int, MeshPointType> > nonzero_F;
	std::vector< MeshPointType > init_W;	// Initialize W as 3rd difference of displacement vectors
	int row_n = 0;

	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		MeshPointType f_vec(0.0);
		MeshPointType w_vec(0.0);
		bool has_var_vtx = false, has_fixed_vtx = false;

		for(int k = 0; k < 4; k++){
			if(vtx_sol_index[polyline_idx[i][k]] < 0){
				has_fixed_vtx = true;
				f_vec += fixed_vtx_displacement[polyline_idx[i][k]] * coef[k];
				w_vec += fixed_vtx_displacement[polyline_idx[i][k]] * coef[k];
			}
			else{
				has_var_vtx = true;
				triplets_E.push_back(T(row_n, vtx_sol_index[polyline_idx[i][k]], coef[k]));
			}
		}

		if(has_var_vtx){

			// Only store nonzero entries in F
			if(has_fixed_vtx){
				nonzero_F.push_back(std::make_pair(row_n, f_vec));
			}

			init_W.push_back(w_vec);
			row_n ++;
		}
	}

	E.resize(row_n, var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();


	if(use_mat_var){
		F_mat.setZero(row_n, 3);
		for(unsigned int i = 0; i < nonzero_F.size(); i++){
			int row = nonzero_F[i].first;
			MeshPointType F_val = nonzero_F[i].second;
			F_mat(row, 0) = F_val[0];
			F_mat(row, 1) = F_val[1];
			F_mat(row, 2) = F_val[2];
		}

		W_mat.resize(row_n, 3);
		for(int i = 0; i < row_n; i++){
			W_mat(i, 0) = init_W[i][0];
			W_mat(i, 1) = init_W[i][1];
			W_mat(i, 2) = init_W[i][2];
		}

		prev_W_mat = W_mat;
	}
	else{
		F[0].setZero(row_n);
		F[1].setZero(row_n);
		F[2].setZero(row_n);
		for(unsigned int i = 0; i < nonzero_F.size(); i++){
			int row = nonzero_F[i].first;
			MeshPointType F_val = nonzero_F[i].second;
			F[0][row] = F_val[0];
			F[1][row] = F_val[1];
			F[2][row] = F_val[2];
		}

		W[0].resize(row_n);
		W[1].resize(row_n);
		W[2].resize(row_n);
		for(int i = 0; i < row_n; i++){
			W[0](i) = init_W[i][0];
			W[1](i) = init_W[i][1];
			W[2](i) = init_W[i][2];
		}
	}
}


void PQSparseDispSDMM::initialize_primal_vars()
{
	int h_size = var_vtx_n;
	int y_size = var_vtx_n;
	int z_size = C.rows();
	Z_update_tmp_pts.resize(z_size, 3);
	Y_update_tmp_mat.resize(y_size, 3);

	if(use_mat_var){
		H_mat.setZero(h_size, 3);
		prev_H_mat.setZero(h_size, 3);
		Y_mat.setZero(y_size, 3);
		prev_Y_mat.setZero(y_size, 3);
		Z_mat.setZero(z_size, 3);
		prev_Z_mat.setZero(z_size, 3);
	}
	else{
		for(int i = 0; i < 3; i++){
			H[i].setZero(h_size);
			prev_H[i].setZero(h_size);
			Y[i].setZero(y_size);
			Z[i].setZero(z_size);
		}
	}
}

void PQSparseDispSDMM::zero_initialize_dual_vars()
{
	int d1_size = C.rows();
	int d2_size = var_vtx_n;
	int d3_size = E.rows();

	if(use_mat_var){
		D1_mat.setZero(d1_size, 3);
		D2_mat.setZero(d2_size, 3);
		D3_mat.setZero(d3_size, 3);
		primal_residual_mat_1.setZero(d1_size, 3);
		primal_residual_mat_2.setZero(d2_size, 3);
		primal_residual_mat_3.setZero(d3_size, 3);
	}
	else{
		for(int i = 0; i < 3; i++){
			D1[i].setZero(d1_size);
			D2[i].setZero(d2_size);
			D3[i].setZero(d3_size);
			primal_residual_1[i].setZero(d1_size);
			primal_residual_2[i].setZero(d2_size);
			primal_residual_3[i].setZero(d3_size);
		}
	}
}


void PQSparseDispSDMM::update_Z_mat()
{
	prev_Z_mat = Z_mat;
	Z_update_tmp_pts = K_mat - D1_mat;
	Z_update_tmp_pts.noalias() += C * H_mat;
	int row_n = Z_update_tmp_pts.rows();

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

	for(int i = 0; i < row_n; i += 4){

		Matrix43d M = Z_update_tmp_pts.block<4,3>(i, 0);
		Eigen::Vector3d mean_vec = M.colwise().mean();

		for(int k = 0; k < 4; k++){
			M.row(k) -= mean_vec;
		}

		Eigen::JacobiSVD<Matrix43d> jSVD(M, Eigen::ComputeFullV);
		Eigen::Vector3d N = jSVD.matrixV().col(2);

		for(int k = 0; k < 4; k++){
			Eigen::Vector3d row_pt = M.row(k);
			Z_mat.row( i + k ).noalias() = row_pt - N * N.dot(row_pt);
		}
	}


}

void PQSparseDispSDMM::update_Z()
{
	for(int i = 0; i < 3; i++){
		Z_update_tmp_pts.col(i).noalias() = C * H[i] +  K[i] - D1[i];
	}

	int row_n = Z_update_tmp_pts.rows();

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

	for(int i = 0; i < row_n; i += 4){

		Matrix43d M = Z_update_tmp_pts.block<4,3>(i, 0);
		Eigen::Vector3d mean_vec = M.colwise().mean();

		for(int k = 0; k < 4; k++){
			M.row(k) -= mean_vec;
		}

		Eigen::JacobiSVD<Matrix43d> jSVD(M, Eigen::ComputeFullV);
		Eigen::Matrix<double, 3, 2> Pl = jSVD.matrixV().block<3,2>(0, 0);
		Matrix43d Proj_pt = M * Pl * Pl.transpose();

		Z[0].segment<4>(i) = Proj_pt.col(0);
		Z[1].segment<4>(i) = Proj_pt.col(1);
		Z[2].segment<4>(i) = Proj_pt.col(2);
	}
}

void PQSparseDispSDMM::update_W_mat()
{
	W_mat = F_mat - D3_mat;
	W_mat.noalias() += E * H_mat;
	W_mat *= ( penalty_weight / (penalty_weight + smoothness_weight) );
}

void PQSparseDispSDMM::update_H_mat()
{
	prev_H_mat = H_mat;
	H_mat = solver.solve(Ct * (Z_mat - K_mat + D1_mat) +  Et * (W_mat - F_mat + D3_mat) + Y_mat + D2_mat);
}

void PQSparseDispSDMM::weighted_update_W_mat()
{
	W_mat = F_mat - D3_mat;
	W_mat.noalias() += E * H_mat;
	W_mat *= ( (penalty_weight * W_weight_rel) / (penalty_weight * W_weight_rel + smoothness_weight) );
}

void PQSparseDispSDMM::weighted_update_H_mat()
{
	prev_H_mat = H_mat;
	H_mat = solver.solve( Z_weight_rel * (Ct * (Z_mat - K_mat + D1_mat)) +  W_weight_rel * (Et * (W_mat - F_mat + D3_mat)) + Y_weight_rel * (Y_mat + D2_mat));
}

void PQSparseDispSDMM::update_mesh_vertices_mat()
{
	int n_vtx = pmesh->n_vertices();

	for(int i = 0; i < n_vtx; i++){
		PolyMeshType::VertexHandle vh(i);

		if(vtx_sol_index[i] >= 0){
			int row_num = vtx_sol_index[i];
			pmesh->set_point(vh, orig_vtx_pos[i] + MeshPointType( H_mat(row_num,0), H_mat(row_num,1), H_mat(row_num,2) ));
		}
		else{
			pmesh->set_point(vh, orig_vtx_pos[i]);
		}
	}

	pmesh->update_normals();

	if(update_mesh){
		mesh->setGeometryChanged();
	}
}

void PQSparseDispSDMM::update_mesh_vertices_mat(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){
		update_mesh_vertices_mat();
	}
}


void PQSparseDispSDMM::L0_update_Y_mat()
{
	Y_update_tmp_mat = H_mat - D2_mat;

	int row_n = Y_update_tmp_mat.rows();
	for(int i = 0; i < row_n; ++ i){
		if( Y_update_tmp_mat.row(i).squaredNorm() * penalty_weight <= sparsity_weight ){
			Y_mat.row(i).setZero();
		}
		else{
			Y_mat.row(i) = Y_update_tmp_mat.row(i);
		}
	}
}

void PQSparseDispSDMM::L1_update_Y_mat()
{
	Y_update_tmp_mat = H_mat - D2_mat;

	int row_n = Y_update_tmp_mat.rows();
	for(int i = 0; i < row_n; ++ i){
		Eigen::Vector3d cur_row_vec = Y_update_tmp_mat.row(i);
		double row_vec_norm = cur_row_vec.norm();
		if( 2 * row_vec_norm * penalty_weight <= sparsity_weight ){
			Y_mat.row(i).setZero();
		}
		else{
			Y_mat.row(i) = cur_row_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * row_vec_norm));
		}
	}
}

void PQSparseDispSDMM::weighted_L0_update_Y_mat()
{
	double real_penalty_weight = penalty_weight * Y_weight_rel;

	Y_update_tmp_mat = H_mat - D2_mat;

	int row_n = Y_update_tmp_mat.rows();
	for(int i = 0; i < row_n; ++ i){
		if( Y_update_tmp_mat.row(i).squaredNorm() * real_penalty_weight <= sparsity_weight ){
			Y_mat.row(i).setZero();
		}
		else{
			Y_mat.row(i) = Y_update_tmp_mat.row(i);
		}
	}
}

void PQSparseDispSDMM::weighted_L1_update_Y_mat()
{
	double real_penalty_weight = penalty_weight * Y_weight_rel;

	Y_update_tmp_mat = H_mat - D2_mat;

	int row_n = Y_update_tmp_mat.rows();
	for(int i = 0; i < row_n; ++ i){
		Eigen::Vector3d cur_row_vec = Y_update_tmp_mat.row(i);
		double row_vec_norm = cur_row_vec.norm();
		if( 2 * row_vec_norm * real_penalty_weight <= sparsity_weight ){
			Y_mat.row(i).setZero();
		}
		else{
			Y_mat.row(i) = cur_row_vec * (1.0 - 0.5 * sparsity_weight / (real_penalty_weight * row_vec_norm));
		}
	}
}


bool PQSparseDispSDMM::weighted_dual_var_update_with_stop_check_and_penalty_update_mat()
{
	Eigen::MatrixXd H_diff_mat = H_mat - prev_H_mat;

	bool small_change = H_diff_mat.rowwise().norm().maxCoeff() <= min_vec_change_threshold
			&& ( Y_mat - prev_Y_mat ).rowwise().norm().maxCoeff() <= min_vec_change_threshold
			&& ( W_mat - prev_W_mat ).rowwise().norm().maxCoeff() <= min_vec_change_threshold
			&& ( Z_mat - prev_Z_mat ).rowwise().norm().maxCoeff() <= min_vec_change_threshold;

	if(small_change && (*std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end())) <= diagonal_dist_bound){
		update_mesh_vertices_mat();
		return true;
	}

	// Compute primal resiuduals
	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;

	// Update dual variables
	D1_mat += primal_residual_mat_1;
	D2_mat += primal_residual_mat_2;
	D3_mat += primal_residual_mat_3;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() * Z_weight_rel +
			primal_residual_mat_2.squaredNorm() * Y_weight_rel + primal_residual_mat_3.squaredNorm() * W_weight_rel);

	double dual_residual_norm = penalty_weight * std::sqrt(H_diff_mat.squaredNorm() * Y_weight_rel_square
			+ (C * H_diff_mat).squaredNorm() * Z_weight_rel_square + (E * H_diff_mat).squaredNorm() * W_weight_rel_square);

	std::cout << "Primal Residual Norm: " << primal_residual_norm << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm  << std::endl;

	// Update penalty weight
//	if(primal_residual_norm > lambda * dual_residual_norm){
//		penalty_weight *= tau_incr;
//		D1_mat /= tau_incr;
//		D2_mat /= tau_incr;
//		D3_mat /= tau_incr;
//	}
//	else if(dual_residual_norm > lambda * primal_residual_norm){
//		penalty_weight /= tau_decr;
//		D1_mat *= tau_decr;
//		D2_mat *= tau_decr;
//		D3_mat *= tau_decr;
//	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}

bool PQSparseDispSDMM::dual_var_update_with_stop_check_and_penalty_weight_update_mat()
{
	// Compute primal resiuduals
	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;

	// Update dual variables
	D1_mat += primal_residual_mat_1;
	D2_mat += primal_residual_mat_2;
	D3_mat += primal_residual_mat_3;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());

	double primal_rel_eps_sqr_scale = std::max(J_sqr_norm,
			std::max(
					Z_mat.squaredNorm() + Y_mat.squaredNorm() + W_mat.squaredNorm(),
					H_mat.squaredNorm() + (C * H_mat).squaredNorm() + (E * H_mat).squaredNorm()
			));

	double primal_eps = primal_ep_abs + ep_rel *  std::sqrt(primal_rel_eps_sqr_scale);

	double dual_var_norm = std::sqrt(D1_mat.squaredNorm() + D2_mat.squaredNorm() + D3_mat.squaredNorm());
	double dual_eps = dual_ep_abs + ep_rel * dual_var_norm;
	Eigen::MatrixXd H_diff_mat = H_mat - prev_H_mat;
	double dual_residual_norm = penalty_weight * std::sqrt(H_diff_mat.squaredNorm()
			+ (C * H_diff_mat).squaredNorm() + (E * H_diff_mat).squaredNorm());

	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_eps << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_eps << std::endl;

	double max_diagonal_dist = *std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end());

	if(primal_residual_norm <= primal_eps && dual_residual_norm <= dual_eps && max_diagonal_dist <= diagonal_dist_bound){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Update penalty weight
	if(primal_residual_norm > lambda * dual_residual_norm){
		penalty_weight *= tau_incr;
		D1_mat /= tau_incr;
		D2_mat /= tau_incr;
		D3_mat /= tau_incr;
	}
//	else if(dual_residual_norm > lambda * primal_residual_norm){
//		penalty_weight /= tau_decr;
//		D1_mat *= tau_decr;
//		D2_mat *= tau_decr;
//		D3_mat *= tau_decr;
//	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}

bool PQSparseDispSDMM::dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat()
{
	// Compute primal resiuduals
	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;

	// Update dual variables
	D1_mat -= primal_residual_mat_1;
	D2_mat -= primal_residual_mat_2;
	D3_mat -= primal_residual_mat_3;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());

	double primal_rel_eps_sqr_scale = std::max(J_sqr_norm,
			std::max(
					Z_mat.squaredNorm() + Y_mat.squaredNorm() + W_mat.squaredNorm(),
					H_mat.squaredNorm() + (C * H_mat).squaredNorm() + (E * H_mat).squaredNorm()
			));

	double primal_eps = primal_ep_abs + ep_rel *  std::sqrt(primal_rel_eps_sqr_scale);

	double dual_var_norm = std::sqrt(D1_mat.squaredNorm() + D2_mat.squaredNorm() + D3_mat.squaredNorm());
	double dual_eps = dual_ep_abs + ep_rel * dual_var_norm;
	Eigen::MatrixXd H_diff_mat = H_mat - prev_H_mat;
	double dual_residual_norm = penalty_weight * std::sqrt(H_diff_mat.squaredNorm()
			+ (C * H_diff_mat).squaredNorm() + (E * H_diff_mat).squaredNorm());

	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_eps << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_eps << std::endl;

	if(primal_residual_norm <= primal_eps && dual_residual_norm <= dual_eps){
		update_mesh_vertices_mat();
		return true;
	}

	// Update penalty weight
	if(primal_residual_norm > lambda * dual_residual_norm){
		penalty_weight *= tau_incr;
		D1_mat /= tau_incr;
		D2_mat /= tau_incr;
		D3_mat /= tau_incr;
	}
	else if(dual_residual_norm > lambda * primal_residual_norm){
		penalty_weight /= tau_decr;
		D1_mat *= tau_decr;
		D2_mat *= tau_decr;
		D3_mat *= tau_decr;
	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}


void PQSparseDispSDMM::dual_var_half_update_mat()
{
	// Compute primal resiuduals
	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;

	// Update dual variables
	D1_mat.noalias() += primal_residual_mat_1 * 0.5;
	D2_mat.noalias() += primal_residual_mat_2 * 0.5;
	D3_mat.noalias() += primal_residual_mat_3 * 0.5;

}

void PQSparseDispSDMM::update_diagonal_dist_histogram(int iter_num)
{
	if(update_histogram && (iter_num % update_period == 0)){
		histogram->setMeasures(face_diagonal_dist);
	}
}


void PQSparseDispSDMM::get_initial_value_and_primal_residual()
{
	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;

	this->initial_primal_residual_squared_norm = primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm();

	this->initial_func_value =  Y_mat.rowwise().norm().sum() * this->sparsity_weight
			+ W_mat.squaredNorm() * this->smoothness_weight;
}


bool PQSparseDispSDMM::check_stopping_and_update_penalty(int iter)
{
	if(iter >= 500){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;

	// Check stopping criteria
	double primal_residual_squared_norm = primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm();

	double max_diagonal_dist = *std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end());

	if(primal_residual_squared_norm < 1e-6 && max_diagonal_dist <= diagonal_dist_bound){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	std::cout << "Primal residual norm:" << std::sqrt(primal_residual_squared_norm) << std::endl;

	//double cur_func_val =  Y_mat.rowwise().norm().sum() * this->sparsity_weight
	//		+ W_mat.squaredNorm() * this->smoothness_weight;

	//double weight_bound = 0;


	penalty_weight *= this->penalty_incr;


//	if(initial_primal_residual_squared_norm > primal_residual_squared_norm){
//		std::cout << "Lower weight bound" << std::endl;
//		weight_bound = (cur_func_val - initial_func_value) / (initial_primal_residual_squared_norm - primal_residual_squared_norm);
//		this->penalty_weight = std::max(this->penalty_weight, weight_bound );
//	}
//	else if(initial_primal_residual_squared_norm < primal_residual_squared_norm){
//		std::cout << "Upper weight bound" << std::endl;
//		weight_bound = (initial_func_value - cur_func_val) / (primal_residual_squared_norm - initial_primal_residual_squared_norm );
//		this->penalty_weight = std::max(this->penalty_weight, weight_bound );
//	}
//
//	std::cout << "Weight bound" << weight_bound << std::endl;
//
//	penalty_weight = std::min(penalty_weight, 1000.0);



	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}


void PQSparseDispSDMM::L0_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_Z_mat();
		L0_update_Y_mat();
		update_W_mat();

		//dual_var_half_update_mat();

		update_H_mat();

		evaluate_diagonal_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(iter >= 500){
			return;
		}

		if(dual_var_update_with_stop_check_and_penalty_weight_update_mat()){
			return;
		}
	}
}

void PQSparseDispSDMM::L1_penalty_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_H_mat();
		update_Z_mat();
		L1_update_Y_mat();
		update_W_mat();
		evaluate_diagonal_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(check_stopping_and_update_penalty(iter)){
			return;
		}
	}
}

void PQSparseDispSDMM::L1_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_Z_mat();
		L1_update_Y_mat();
		update_W_mat();

		//dual_var_half_update_mat();

		update_H_mat();

		evaluate_diagonal_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(iter >= 1000){
			return;
		}

		if(dual_var_update_with_stop_check_and_penalty_weight_update_mat()){
			return;
		}
	}
}

void PQSparseDispSDMM::weighted_L0_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_Z_mat();
		weighted_L0_update_Y_mat();
		weighted_update_W_mat();

		//dual_var_half_update_mat();

		weighted_update_H_mat();

		evaluate_diagonal_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(iter >= 500){
			return;
		}

		if(weighted_dual_var_update_with_stop_check_and_penalty_update_mat()){
			return;
		}
	}
}

void PQSparseDispSDMM::weighted_L1_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_Z_mat();
		weighted_L1_update_Y_mat();
		weighted_update_W_mat();

		//dual_var_half_update_mat();

		weighted_update_H_mat();

		evaluate_diagonal_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(iter >= 500){
			return;
		}

		if(weighted_dual_var_update_with_stop_check_and_penalty_update_mat()){
			return;
		}
	}
}

void PQSparseDispSDMM::L0_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		L0_optimize_mat();
		opt_disp.clear();

		for(unsigned int i = 0; i < vtx_sol_index.size(); i++){
			int row_idx = vtx_sol_index[i];
			if( row_idx >=0 ){
				opt_disp.push_back(MeshPointType(H_mat(row_idx, 0), H_mat(row_idx, 1), H_mat(row_idx, 2)));
			}
			else{
				opt_disp.push_back(fixed_vtx_displacement[i]);
			}
		}
	}
}

void PQSparseDispSDMM::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		L1_optimize_mat();
		opt_disp.clear();

		for(unsigned int i = 0; i < vtx_sol_index.size(); i++){
			int row_idx = vtx_sol_index[i];
			if( row_idx >=0 ){
				opt_disp.push_back(MeshPointType(H_mat(row_idx, 0), H_mat(row_idx, 1), H_mat(row_idx, 2)));
			}
			else{
				opt_disp.push_back(fixed_vtx_displacement[i]);
			}
		}
	}
}


void PQSparseDispSDMM::L1_penalty_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		L1_penalty_optimize_mat();
		opt_disp.clear();

		for(unsigned int i = 0; i < vtx_sol_index.size(); i++){
			int row_idx = vtx_sol_index[i];
			if( row_idx >=0 ){
				opt_disp.push_back(MeshPointType(H_mat(row_idx, 0), H_mat(row_idx, 1), H_mat(row_idx, 2)));
			}
			else{
				opt_disp.push_back(fixed_vtx_displacement[i]);
			}
		}
	}
}


void PQSparseDispSDMM::weighted_L0_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		weighted_L0_optimize_mat();
		opt_disp.clear();

		for(unsigned int i = 0; i < vtx_sol_index.size(); i++){
			int row_idx = vtx_sol_index[i];
			if( row_idx >=0 ){
				opt_disp.push_back(MeshPointType(H_mat(row_idx, 0), H_mat(row_idx, 1), H_mat(row_idx, 2)));
			}
			else{
				opt_disp.push_back(fixed_vtx_displacement[i]);
			}
		}
	}
}

void PQSparseDispSDMM::weighted_L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		weighted_L1_optimize_mat();
		opt_disp.clear();

		for(unsigned int i = 0; i < vtx_sol_index.size(); i++){
			int row_idx = vtx_sol_index[i];
			if( row_idx >=0 ){
				opt_disp.push_back(MeshPointType(H_mat(row_idx, 0), H_mat(row_idx, 1), H_mat(row_idx, 2)));
			}
			else{
				opt_disp.push_back(fixed_vtx_displacement[i]);
			}
		}
	}
}


const std::vector<double>& PQSparseDispSDMM::face_diagonal_dist_measure()
{
	evaluate_diagonal_dist_mat();
	return face_diagonal_dist;
}

void PQSparseDispSDMM::evaluate_diagonal_dist_mat()
{
	std::vector<MeshPointType> vtx_new_pos = orig_vtx_pos;
	PolyMeshType::VertexIter v_it, v_end = pmesh->vertices_end();
	for(v_it = pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		int idx = v_it.handle().idx();
		if(vtx_sol_index[idx] >= 0){
			int row_num = vtx_sol_index[idx];
			vtx_new_pos[idx] += MeshPointType( H_mat(row_num,0), H_mat(row_num,1), H_mat(row_num,2) );
		}
	}

	face_diagonal_dist.clear();
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		std::vector<MeshPointType> vtx;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			vtx.push_back(vtx_new_pos[ fv_it.handle().idx() ]);
		}

		MeshPointType N = Dolphin::defines::cross((vtx[2] - vtx[0]).normalize(), (vtx[3] - vtx[1]).normalize()).normalize();
		double dist = std::abs( Dolphin::defines::dot( N, (vtx[3] + vtx[1]) * 0.5 - (vtx[2] + vtx[0]) * 0.5  ));
		face_diagonal_dist.push_back(dist);
	}
}


void PQSparseDispADMM2ndDiffEnergy::initialize_variables(OpenMeshNode *mesh_, int update_period_,
		const std::map<int, MeshPointType> &fixed_vtx_disp, double sparsity_weight_, double smoothness_weight_,
		double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool use_mat_var_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	use_mat_var = use_mat_var_;
	var_vtx_n = pmesh->n_vertices() - fixed_vtx_displacement.size();

	update_mesh = true;
	update_histogram = false;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	tau_incr = tau_incr_;
	tau_decr = 2;
	diagonal_dist_bound = 0.01;

	max_penalty = 1e4;
	check_penalty_period = 20;
	residual_change_ratio = 0.5;

	initialize_var_index();

	store_orig_vertex_positions();

	initialize_centered_matrix();

	initialize_disp_3rddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	update_Z_mat();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();
}


void PQSparseDispADMM2ndDiffEnergy::set_histogram(MeshHistogram *histogram_)
{
	update_histogram = true;
	histogram = histogram_;
}


void PQSparseDispADMM2ndDiffEnergy::initialize_var_index()
{
	int n_vtx = pmesh->n_vertices();
	vtx_sol_index.assign(n_vtx, -2);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter){
		vtx_sol_index[iter->first] = -1;
	}

	int cur_idx = 0;
	for(int i = 0; i < n_vtx; i++){
		if(vtx_sol_index[i] == -2){
			vtx_sol_index[i] = cur_idx++;
		}
	}
}


void PQSparseDispADMM2ndDiffEnergy::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_pos.resize(n_vtx);

	for(int i = 0; i < n_vtx; i++){
		PolyMeshType::VertexHandle vh(i);
		if(vtx_sol_index[i] >= 0){
			orig_vtx_pos[i] = pmesh->point(vh);
		}
		else{
			orig_vtx_pos[i] = pmesh->point(vh) + fixed_vtx_displacement[i];
		}
	}
}

void PQSparseDispADMM2ndDiffEnergy::initialize_solver()
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

void PQSparseDispADMM2ndDiffEnergy::initialize_centered_matrix()
{
	// Pre-compute fixed values
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_C;
	std::vector<MeshPointType> K_vec;
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		MeshPointType current_center(0.0);
		std::vector<MeshPointType> cur_pos;
		std::vector<int> vtx_var_idx;
		bool has_var_vtx = false;

		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			cur_pos.push_back(pmesh->point(fv_it));
			current_center += pmesh->point(fv_it);

			int vtx_idx = fv_it.handle().idx();
			vtx_var_idx.push_back(vtx_sol_index[vtx_idx]);

			if(vtx_sol_index[vtx_idx] == -1){
				// For fixed vertex, new position is fixed
				current_center += fixed_vtx_displacement[vtx_idx];
				cur_pos.back() += fixed_vtx_displacement[vtx_idx];
			}
			else{
				has_var_vtx = true;
			}
		}

		if(has_var_vtx){
			current_center *= 0.25;
			for(int i = 0; i < 4; i++){
				int cur_row = K_vec.size();
				K_vec.push_back( cur_pos[i] - current_center );   // Constant term for mean-centered values
				for(int k = 0; k < 4; k++){
					if(vtx_var_idx[k] >= 0){
						triplets_C.push_back(T(cur_row, vtx_var_idx[k], (k==i) ? 0.75:(-0.25) ));
					}
				}
			}
		}
	}

	int num_row_C = K_vec.size();
	C.resize(num_row_C, var_vtx_n);
	C.setFromTriplets(triplets_C.begin(), triplets_C.end());
	Ct = C.transpose();

	if(use_mat_var){
		K_mat.resize(num_row_C, 3);
		for(int i = 0; i < num_row_C; i++){
			K_mat(i, 0) = K_vec[i][0];
			K_mat(i, 1) = K_vec[i][1];
			K_mat(i, 2) = K_vec[i][2];
		}
	}
	else{
		K[0].resize(num_row_C);
		K[1].resize(num_row_C);
		K[2].resize(num_row_C);
		for(int i = 0; i < num_row_C; i++){
			K[0](i) = K_vec[i][0];
			K[1](i) = K_vec[i][1];
			K[2](i) = K_vec[i][2];
		}
	}

	check_centered_matrix();
}


void PQSparseDispADMM2ndDiffEnergy::check_centered_matrix()
{
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;

	Eigen::MatrixXd orig_pos_mat(pmesh->n_vertices(), 3);
	for(unsigned int i = 0; i < pmesh->n_vertices(); i++){
		MeshPointType pt = pmesh->point(PolyMeshType::VertexHandle(i));
		orig_pos_mat(i, 0) = pt[0];
		orig_pos_mat(i, 1) = pt[1];
		orig_pos_mat(i, 2) = pt[2];
	}

	for(int k = 0; k < 10; k++){

		Eigen::MatrixXd vtx_disp;
		vtx_disp.setRandom(pmesh->n_vertices(), 3);
		Eigen::MatrixXd var_disp(var_vtx_n, 3);

		for(int j = 0; j < static_cast<int>(vtx_sol_index.size()); j++){
			if(vtx_sol_index[j] >= 0){
				var_disp.row(vtx_sol_index[j]) = vtx_disp.row(j);
			}
		}

		for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
				iter != fixed_vtx_displacement.end(); ++ iter){
			vtx_disp(iter->first, 0) = iter->second[0];
			vtx_disp(iter->first, 1) = iter->second[1];
			vtx_disp(iter->first, 2) = iter->second[2];
		}

		Eigen::MatrixXd new_pos = orig_pos_mat + vtx_disp;

		Eigen::MatrixXd num_val_mat = C * var_disp + K_mat;
		int cur_row = 0;

		for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
			Eigen::Matrix<double, 4, 3> new_vtx_pos;
			bool has_var = false;
			int n = 0;
			for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
				new_vtx_pos.row(n) = new_pos.row(fv_it.handle().idx());
				if(vtx_sol_index[ fv_it.handle().idx() ] >= 0){
					has_var = true;
				}
				n++;
			}

			if(!has_var){
				continue;
			}

			Eigen::Vector3d mean_vec = new_vtx_pos.colwise().mean();
			for(int i = 0; i < 4; i++){
				Eigen::Vector3d num_row_val = num_val_mat.block(cur_row, 0, 1, 3).transpose();
				Eigen::Vector3d new_row = new_vtx_pos.row(i);
				cur_row++;
				Eigen::Vector3d diff_vec = new_row - mean_vec - num_row_val;
				double diff_vec_norm = diff_vec.norm();
				if(diff_vec_norm > 1e-4){
					std::cout << "Inconsistent row: diff vec norm " << diff_vec_norm << std::endl;
				}
			}
		}
	}
}


void PQSparseDispADMM2ndDiffEnergy::evaluate_least_squares_dist_mat()
{
	std::vector<MeshPointType> vtx_new_pos = orig_vtx_pos;
	PolyMeshType::VertexIter v_it, v_end = pmesh->vertices_end();
	for(v_it = pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		int idx = v_it.handle().idx();
		if(vtx_sol_index[idx] >= 0){
			int row_num = vtx_sol_index[idx];
			vtx_new_pos[idx] += MeshPointType( H_mat(row_num,0), H_mat(row_num,1), H_mat(row_num,2) );
		}
	}

	face_diagonal_dist.clear();
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){

		Matrix43d M;
		int cur_row = 0;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			MeshPointType cur_pt = vtx_new_pos[ fv_it.handle().idx() ];
			M(cur_row, 0) = cur_pt[0];
			M(cur_row, 1) = cur_pt[1];
			M(cur_row, 2) = cur_pt[2];
			cur_row ++;
		}

		Eigen::Vector3d mean_vec = M.colwise().mean();
		for(int k = 0; k < 4; k++){
			M.row(k) -= mean_vec;
		}

		Eigen::JacobiSVD<Matrix43d> jSVD(M, Eigen::ComputeFullV);
		double smallest_val = jSVD.singularValues()(2);
		face_diagonal_dist.push_back(smallest_val*smallest_val);
	}
}

void PQSparseDispADMM2ndDiffEnergy::initialize_disp_2nddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_2nddiff_polyline_idx(pmesh, polyline_idx);

	std::vector< MeshPointType > init_F;
	std::vector< MeshPointType > init_W;	// Initialize W as 2nd order difference of displacement vectors
	int row_n = 0;

	double coef[] = {1.0, -2.0, 1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		MeshPointType f_vec(0.0);
		MeshPointType w_vec(0.0);
		bool has_var_vtx = false;

		for(int k = 0; k < 3; k++){
			if(vtx_sol_index[polyline_idx[i][k]] < 0){
				f_vec += fixed_vtx_displacement[polyline_idx[i][k]] * coef[k];
				w_vec += fixed_vtx_displacement[polyline_idx[i][k]] * coef[k];
			}
			else{
				has_var_vtx = true;
				triplets_E.push_back(T(row_n, vtx_sol_index[polyline_idx[i][k]], coef[k]));
			}
		}

		if(has_var_vtx){
			init_F.push_back(f_vec);
			init_W.push_back(w_vec);
			row_n ++;
		}
	}

	E.resize(row_n, var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();


	if(use_mat_var){
		F_mat.resize(row_n, 3);
		for(int i = 0; i < row_n; i++){
			F_mat(i, 0) = init_F[i][0];
			F_mat(i, 1) = init_F[i][1];
			F_mat(i, 2) = init_F[i][2];
		}

		W_mat.resize(row_n, 3);
		for(int i = 0; i < row_n; i++){
			W_mat(i, 0) = init_W[i][0];
			W_mat(i, 1) = init_W[i][1];
			W_mat(i, 2) = init_W[i][2];
		}
		prev_W_mat.setZero(row_n, 3);
		W_mat_diff.setZero(row_n, 3);
	}
	else{
		F[0].resize(row_n);
		F[1].resize(row_n);
		F[2].resize(row_n);
		for(int i = 0; i < row_n; i++){
			F[0](i) = init_F[i][0];
			F[1](i) = init_F[i][1];
			F[2](i) = init_F[i][2];
		}

		W[0].resize(row_n);
		W[1].resize(row_n);
		W[2].resize(row_n);
		for(int i = 0; i < row_n; i++){
			W[0](i) = init_W[i][0];
			W[1](i) = init_W[i][1];
			W[2](i) = init_W[i][2];
		}
	}

	check_2nddiff_disp_energy_matrix(polyline_idx);
}


void PQSparseDispADMM2ndDiffEnergy::initialize_disp_3rddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	std::vector< MeshPointType > init_F;
	std::vector< MeshPointType > init_W;	// Initialize W as 2nd order difference of displacement vectors
	int row_n = 0;

	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		MeshPointType f_vec(0.0);
		MeshPointType w_vec(0.0);
		bool has_var_vtx = false;

		for(int k = 0; k < 4; k++){
			if(vtx_sol_index[polyline_idx[i][k]] < 0){
				f_vec += fixed_vtx_displacement[polyline_idx[i][k]] * coef[k];
				w_vec += fixed_vtx_displacement[polyline_idx[i][k]] * coef[k];
			}
			else{
				has_var_vtx = true;
				triplets_E.push_back(T(row_n, vtx_sol_index[polyline_idx[i][k]], coef[k]));
			}
		}

		if(has_var_vtx){
			init_F.push_back(f_vec);
			init_W.push_back(w_vec);
			row_n ++;
		}
	}

	E.resize(row_n, var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();


	if(use_mat_var){
		F_mat.resize(row_n, 3);
		for(int i = 0; i < row_n; i++){
			F_mat(i, 0) = init_F[i][0];
			F_mat(i, 1) = init_F[i][1];
			F_mat(i, 2) = init_F[i][2];
		}

		W_mat.resize(row_n, 3);
		for(int i = 0; i < row_n; i++){
			W_mat(i, 0) = init_W[i][0];
			W_mat(i, 1) = init_W[i][1];
			W_mat(i, 2) = init_W[i][2];
		}
		prev_W_mat.setZero(row_n, 3);
		W_mat_diff.setZero(row_n, 3);
	}
	else{
		F[0].resize(row_n);
		F[1].resize(row_n);
		F[2].resize(row_n);
		for(int i = 0; i < row_n; i++){
			F[0](i) = init_F[i][0];
			F[1](i) = init_F[i][1];
			F[2](i) = init_F[i][2];
		}

		W[0].resize(row_n);
		W[1].resize(row_n);
		W[2].resize(row_n);
		for(int i = 0; i < row_n; i++){
			W[0](i) = init_W[i][0];
			W[1](i) = init_W[i][1];
			W[2](i) = init_W[i][2];
		}
	}

	check_3rddiff_disp_energy_matrix(polyline_idx);
}

void PQSparseDispADMM2ndDiffEnergy::check_2nddiff_disp_energy_matrix(const std::vector< std::vector<int> > &idx)
{
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;

//	Eigen::MatrixXd orig_pos_mat(pmesh->n_vertices(), 3);
//	for(unsigned int i = 0; i < pmesh->n_vertices(); i++){
//		MeshPointType pt = pmesh->point(PolyMeshType::VertexHandle(i));
//		orig_pos_mat(i, 0) = pt[0];
//		orig_pos_mat(i, 1) = pt[1];
//		orig_pos_mat(i, 2) = pt[2];
//	}

	double coef[] = {1.0, -2.0, 1.0};

	for(int k = 0; k < 10; k++){

		Eigen::MatrixXd vtx_disp;
		vtx_disp.setRandom(pmesh->n_vertices(), 3);
		Eigen::MatrixXd var_disp(var_vtx_n, 3);

		for(int j = 0; j < static_cast<int>(vtx_sol_index.size()); j++){
			if(vtx_sol_index[j] >= 0){
				var_disp.row(vtx_sol_index[j]) = vtx_disp.row(j);
			}
		}

		for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
				iter != fixed_vtx_displacement.end(); ++ iter){
			vtx_disp(iter->first, 0) = iter->second[0];
			vtx_disp(iter->first, 1) = iter->second[1];
			vtx_disp(iter->first, 2) = iter->second[2];
		}

		//Eigen::MatrixXd new_pos = orig_pos_mat + vtx_disp;

		Eigen::MatrixXd num_val_mat = E * var_disp + F_mat;


		for(int i = 0; i < static_cast<int>(idx.size()); i++){
			Eigen::Vector3d diff2_vec;
			diff2_vec.setZero();
			for(int j = 0; j < 3; j++){
				diff2_vec += vtx_disp.row(idx[i][j]) * coef[j];
			}

			Eigen::Vector3d num_val_vec = num_val_mat.block(i, 0, 1, 3).transpose();

			Eigen::Vector3d diff = diff2_vec - num_val_vec;
			double diff_norm = diff.norm();
			if(diff_norm > 1e-5){
				std::cout << "Inconsistent vector: diff norm " << diff_norm << std::endl;
			}
		}
	}
}


void PQSparseDispADMM2ndDiffEnergy::check_3rddiff_disp_energy_matrix(const std::vector< std::vector<int> > &idx)
{
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;

//	Eigen::MatrixXd orig_pos_mat(pmesh->n_vertices(), 3);
//	for(unsigned int i = 0; i < pmesh->n_vertices(); i++){
//		MeshPointType pt = pmesh->point(PolyMeshType::VertexHandle(i));
//		orig_pos_mat(i, 0) = pt[0];
//		orig_pos_mat(i, 1) = pt[1];
//		orig_pos_mat(i, 2) = pt[2];
//	}

	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(int k = 0; k < 10; k++){

		Eigen::MatrixXd vtx_disp;
		vtx_disp.setRandom(pmesh->n_vertices(), 3);
		Eigen::MatrixXd var_disp(var_vtx_n, 3);

		for(int j = 0; j < static_cast<int>(vtx_sol_index.size()); j++){
			if(vtx_sol_index[j] >= 0){
				var_disp.row(vtx_sol_index[j]) = vtx_disp.row(j);
			}
		}

		for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
				iter != fixed_vtx_displacement.end(); ++ iter){
			vtx_disp(iter->first, 0) = iter->second[0];
			vtx_disp(iter->first, 1) = iter->second[1];
			vtx_disp(iter->first, 2) = iter->second[2];
		}

		//Eigen::MatrixXd new_pos = orig_pos_mat + vtx_disp;

		Eigen::MatrixXd num_val_mat = E * var_disp + F_mat;


		for(int i = 0; i < static_cast<int>(idx.size()); i++){
			Eigen::Vector3d diff3_vec;
			diff3_vec.setZero();
			for(int j = 0; j < 4; j++){
				diff3_vec += vtx_disp.row(idx[i][j]) * coef[j];
			}

			Eigen::Vector3d num_val_vec = num_val_mat.block(i, 0, 1, 3).transpose();

			Eigen::Vector3d diff = diff3_vec - num_val_vec;
			double diff_norm = diff.norm();
			if(diff_norm > 1e-5){
				std::cout << "Inconsistent vector: diff norm " << diff_norm << std::endl;
			}
		}
	}
}

void PQSparseDispADMM2ndDiffEnergy::initialize_primal_vars()
{
	int h_size = var_vtx_n;
	int y_size = var_vtx_n;
	int z_size = C.rows();
	Z_update_tmp_pts.resize(z_size, 3);
	Y_update_tmp_mat.resize(y_size, 3);

	if(use_mat_var){
		H_mat.setZero(h_size, 3);
		prev_H_mat.setZero(h_size, 3);
		Y_mat.setZero(y_size, 3);
		prev_Y_mat.setZero(y_size, 3);
		Y_mat_diff.setZero(y_size, 3);
		Z_mat.setZero(z_size, 3);
		prev_Z_mat.setZero(z_size, 3);
		Z_mat_diff.setZero(z_size, 3);
	}
}

void PQSparseDispADMM2ndDiffEnergy::zero_initialize_dual_vars()
{
	int d1_size = C.rows();
	int d2_size = var_vtx_n;
	int d3_size = E.rows();

	if(use_mat_var){
		D1_mat.setZero(d1_size, 3);
		D2_mat.setZero(d2_size, 3);
		D3_mat.setZero(d3_size, 3);
		primal_residual_mat_1.setZero(d1_size, 3);
		primal_residual_mat_2.setZero(d2_size, 3);
		primal_residual_mat_3.setZero(d3_size, 3);
	}
	else{
		for(int i = 0; i < 3; i++){
			D1[i].setZero(d1_size);
			D2[i].setZero(d2_size);
			D3[i].setZero(d3_size);
			primal_residual_1[i].setZero(d1_size);
			primal_residual_2[i].setZero(d2_size);
			primal_residual_3[i].setZero(d3_size);
		}
	}
}


void PQSparseDispADMM2ndDiffEnergy::update_Z_mat()
{
	prev_Z_mat = Z_mat;
	Z_update_tmp_pts = K_mat + D1_mat;
	Z_update_tmp_pts.noalias() += C * H_mat;
	int row_n = Z_update_tmp_pts.rows();

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;

	for(int i = 0; i < row_n; i += 4){

		Matrix43d M = Z_update_tmp_pts.block<4,3>(i, 0);
		Eigen::Vector3d mean_vec = M.colwise().mean();

		for(int k = 0; k < 4; k++){
			M.row(k) -= mean_vec;
		}

		Eigen::JacobiSVD<Matrix43d> jSVD(M, Eigen::ComputeFullV);
		Eigen::Vector3d N = jSVD.matrixV().col(2);

		//check_fitting_plane(MeshPointType(M(0,0), M(0,1), M(0,2)), MeshPointType(M(1,0), M(1,1), M(1,2)),
		//		MeshPointType(M(2,0), M(2,1), M(2,2)), MeshPointType(M(3,0), M(3,1), M(3,2)),
		//		MeshPointType(N(0), N(1), N(2)));

		for(int k = 0; k < 4; k++){
			Eigen::Vector3d row_pt = M.row(k);
			Z_mat.row( i + k ).noalias() = row_pt - N * N.dot(row_pt);
		}
	}

	Z_mat_diff = Z_mat - prev_Z_mat;
}

void PQSparseDispADMM2ndDiffEnergy::update_W_mat()
{
	prev_W_mat = W_mat;
	W_mat = F_mat + D3_mat;
	W_mat.noalias() += E * H_mat;
	W_mat *= ( penalty_weight / (penalty_weight + smoothness_weight) );
	W_mat_diff = W_mat - prev_W_mat;
}

void PQSparseDispADMM2ndDiffEnergy::update_H_mat()
{
	prev_H_mat = H_mat;
	H_mat = solver.solve(Ct * (Z_mat - K_mat - D1_mat) +  Et * (W_mat - F_mat - D3_mat) + Y_mat - D2_mat);
}

void PQSparseDispADMM2ndDiffEnergy::update_mesh_vertices_mat()
{
	int n_vtx = pmesh->n_vertices();

	for(int i = 0; i < n_vtx; i++){
		PolyMeshType::VertexHandle vh(i);

		if(vtx_sol_index[i] >= 0){
			int row_num = vtx_sol_index[i];
			pmesh->set_point(vh, orig_vtx_pos[i] + MeshPointType( H_mat(row_num,0), H_mat(row_num,1), H_mat(row_num,2) ));
		}
		else{
			pmesh->set_point(vh, orig_vtx_pos[i]);
		}
	}

	pmesh->update_normals();

	if(update_mesh){
		mesh->setGeometryChanged();
	}
}

void PQSparseDispADMM2ndDiffEnergy::update_mesh_vertices_mat(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){
		update_mesh_vertices_mat();
	}
}


void PQSparseDispADMM2ndDiffEnergy::L0_update_Y_mat()
{
	prev_Y_mat = Y_mat;
	Y_update_tmp_mat = H_mat + D2_mat;

	int row_n = Y_update_tmp_mat.rows();
	for(int i = 0; i < row_n; ++ i){
		if( Y_update_tmp_mat.row(i).squaredNorm() * penalty_weight <= sparsity_weight ){
			Y_mat.row(i).setZero();
		}
		else{
			Y_mat.row(i) = Y_update_tmp_mat.row(i);
		}
	}

	Y_mat_diff = Y_mat - prev_Y_mat;
}

void PQSparseDispADMM2ndDiffEnergy::L1_update_Y_mat()
{
	prev_Y_mat = Y_mat;
	Y_update_tmp_mat = H_mat + D2_mat;

	int row_n = Y_update_tmp_mat.rows();
	for(int i = 0; i < row_n; ++ i){
		Eigen::Vector3d cur_row_vec = Y_update_tmp_mat.row(i);
		double row_vec_norm = cur_row_vec.norm();
		if( 2 * row_vec_norm * penalty_weight <= sparsity_weight ){
			Y_mat.row(i).setZero();
		}
		else{
			Y_mat.row(i) = cur_row_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * row_vec_norm));
		}
	}

	Y_mat_diff = Y_mat - prev_Y_mat;
}


void PQSparseDispADMM2ndDiffEnergy::initialize_stopping_criteria_var()
{
	if(use_mat_var){
		primal_ep_abs = dual_ep_abs = std::sqrt(double(Z_mat.rows() + Y_mat.rows() + W_mat.rows()) * 3) * ep_abs;
	}
	else{
		primal_ep_abs = dual_ep_abs = std::sqrt(double(Z[0].rows() + Y[0].rows() + W[0].rows()) * 3) * ep_abs;
	}
}


void PQSparseDispADMM2ndDiffEnergy::initialize_primal_residual_norm()
{
	compute_primal_residual_mat();
	prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
}

void PQSparseDispADMM2ndDiffEnergy::compute_primal_residual_mat()
{
	primal_residual_mat_1 = K_mat - Z_mat;
	primal_residual_mat_1.noalias() += C * H_mat;

	primal_residual_mat_2 = H_mat - Y_mat;

	primal_residual_mat_3 = F_mat - W_mat;
	primal_residual_mat_3.noalias() += E * H_mat;
}


bool PQSparseDispADMM2ndDiffEnergy::dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(int iter_num)
{
	if(iter_num >= 1000){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Compute primal resiuduals
	compute_primal_residual_mat();

	// Update dual variables
	D1_mat += primal_residual_mat_1;
	D2_mat += primal_residual_mat_2;
	D3_mat += primal_residual_mat_3;

	dual_residual_mat = Ct * Z_mat_diff + Y_mat_diff + Et * W_mat_diff;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());

	double dual_residual_norm = penalty_weight * dual_residual_mat.norm();

	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

	double max_diagonal_dist = *std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end());

	if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs && max_diagonal_dist <= diagonal_dist_bound){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Update penalty weight
	bool need_incr = false;

	if(penalty_weight * tau_incr <= max_penalty){
		if(primal_residual_norm > lambda * dual_residual_norm){
			need_incr = true;
		}
		//else if(iter_num != 0 && iter_num % check_penalty_period == 0){
		//	need_incr = primal_residual_norm > residual_change_ratio * prev_primal_residual_norm
		//			&& dual_residual_norm < lambda * primal_residual_norm ;
		//	prev_primal_residual_norm = primal_residual_norm;
		//}
	}

	if(need_incr){
		penalty_weight *= tau_incr;
		D1_mat /= tau_incr;
		D2_mat /= tau_incr;
		D3_mat /= tau_incr;
	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}

bool PQSparseDispADMM2ndDiffEnergy::dual_var_update_with_stop_check_and_penalty_weight_update_mat(int iter_num)
{
	if(iter_num >= 1000){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Compute primal resiuduals
	compute_primal_residual_mat();

	// Update dual variables
	D1_mat += primal_residual_mat_1;
	D2_mat += primal_residual_mat_2;
	D3_mat += primal_residual_mat_3;

	dual_residual_mat = Ct * Z_mat_diff + Y_mat_diff + Et * W_mat_diff;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());

	double dual_residual_norm = penalty_weight * dual_residual_mat.norm();

	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

	double max_diagonal_dist = *std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end());

	if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs && max_diagonal_dist <= diagonal_dist_bound){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Update penalty weight
	bool need_incr = false;

	if(penalty_weight * tau_incr <= max_penalty){
		if(primal_residual_norm > lambda * dual_residual_norm){
			need_incr = true;
		}
		//else if(iter_num != 0 && iter_num % check_penalty_period == 0){
		//	need_incr = primal_residual_norm > residual_change_ratio * prev_primal_residual_norm
		//			&& dual_residual_norm < lambda * primal_residual_norm ;
		//	prev_primal_residual_norm = primal_residual_norm;
		//}
	}

	if(need_incr){
		penalty_weight *= tau_incr;
		D1_mat /= tau_incr;
		D2_mat /= tau_incr;
		D3_mat /= tau_incr;
	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}


void PQSparseDispADMM2ndDiffEnergy::update_diagonal_dist_histogram(int iter_num)
{
	if(update_histogram && (iter_num % update_period == 0)){
		histogram->setMeasures(face_diagonal_dist);
	}
}

void PQSparseDispADMM2ndDiffEnergy::L1_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_H_mat();
		update_Z_mat();
		L1_update_Y_mat();
		update_W_mat();

		//evaluate_diagonal_dist_mat();
		this->evaluate_least_squares_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(dual_var_update_with_stop_check_and_penalty_weight_update_mat(iter)){
			return;
		}
	}
}

void PQSparseDispADMM2ndDiffEnergy::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		L1_optimize_mat();
		opt_disp.clear();

		for(unsigned int i = 0; i < vtx_sol_index.size(); i++){
			int row_idx = vtx_sol_index[i];
			if( row_idx >=0 ){
				opt_disp.push_back(MeshPointType(H_mat(row_idx, 0), H_mat(row_idx, 1), H_mat(row_idx, 2)));
			}
			else{
				opt_disp.push_back(fixed_vtx_displacement[i]);
			}
		}
	}
}

const std::vector<double>& PQSparseDispADMM2ndDiffEnergy::face_diagonal_dist_measure()
{
	evaluate_diagonal_dist_mat();
	return face_diagonal_dist;
}

void PQSparseDispADMM2ndDiffEnergy::evaluate_diagonal_dist_mat()
{
	std::vector<MeshPointType> vtx_new_pos = orig_vtx_pos;
	PolyMeshType::VertexIter v_it, v_end = pmesh->vertices_end();
	for(v_it = pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		int idx = v_it.handle().idx();
		if(vtx_sol_index[idx] >= 0){
			int row_num = vtx_sol_index[idx];
			vtx_new_pos[idx] += MeshPointType( H_mat(row_num,0), H_mat(row_num,1), H_mat(row_num,2) );
		}
	}

	face_diagonal_dist.clear();
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		std::vector<MeshPointType> vtx;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			vtx.push_back(vtx_new_pos[ fv_it.handle().idx() ]);
		}

		MeshPointType N = Dolphin::defines::cross((vtx[2] - vtx[0]).normalize(), (vtx[3] - vtx[1]).normalize()).normalize();
		double dist = std::abs( Dolphin::defines::dot( N, (vtx[3] + vtx[1]) * 0.5 - (vtx[2] + vtx[0]) * 0.5  ));
		face_diagonal_dist.push_back(dist);
	}
}


void PQSparseDispSoftCon::initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double tau_incr_, bool threshold_smoothness_, double vtx_disp_weight_, bool soft_vtx_disp_constraint_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	fixed_vtx_disp_array.clear();
	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter){
		fixed_vtx_disp_array.push_back(std::make_pair(iter->first, iter->second));
	}

	use_mat_var = true;
	var_vtx_n = pmesh->n_vertices();

	update_mesh = true;
	update_histogram = false;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	threshold_smoothness = threshold_smoothness_;
	soft_vtx_disp_constraint = soft_vtx_disp_constraint_;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	tau_incr = tau_incr_;
	tau_decr = 2;
	diagonal_dist_bound = 0.01;

	min_residual_change_ratio = 0.6;
	check_penalty_period = 10;

	max_penalty = 1e5;

	initialize_var_index();

	store_orig_vertex_positions();

	initialize_centered_matrix();

	initialize_disp_3rddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	//update_Z_mat();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();
}


void PQSparseDispSoftCon::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness){
		smoothness_energy_bound = F_mat.squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}


void PQSparseDispSoftCon::set_histogram(MeshHistogram *histogram_)
{
	update_histogram = true;
	histogram = histogram_;
}


void PQSparseDispSoftCon::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
			iter != fixed_vtx_displacement.end(); ++ iter){
		free_vtx[iter->first] = 0;
	}
}


void PQSparseDispSoftCon::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_pos.resize(n_vtx);
	orig_vtx_mat.resize(n_vtx, 3);

	for(int i = 0; i < n_vtx; i++){
		PolyMeshType::VertexHandle vh(i);
		orig_vtx_pos[i] = pmesh->point(vh);
		orig_vtx_mat(i, 0) = orig_vtx_pos[i][0];
		orig_vtx_mat(i, 1) = orig_vtx_pos[i][1];
		orig_vtx_mat(i, 2) = orig_vtx_pos[i][2];
	}
}

void PQSparseDispSoftCon::initialize_solver()
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

void PQSparseDispSoftCon::initialize_centered_matrix()
{
	// Pre-compute fixed values
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_C;
	std::vector<MeshPointType> K_vec;
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		MeshPointType current_center(0.0);
		std::vector<MeshPointType> cur_pos;
		std::vector<int> vtx_var_idx;

		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			int vtx_idx = fv_it.handle().idx();
			cur_pos.push_back(orig_vtx_pos[vtx_idx]);
			current_center += orig_vtx_pos[vtx_idx];
			vtx_var_idx.push_back(vtx_idx);
		}

		current_center *= 0.25;
		for(int i = 0; i < 4; i++){
			int cur_row = K_vec.size();
			K_vec.push_back( cur_pos[i] - current_center );   // Constant term for mean-centered values
			for(int k = 0; k < 4; k++){
				triplets_C.push_back(T(cur_row, vtx_var_idx[k], (k==i) ? 0.75:(-0.25) ));
			}
		}
	}

	int num_row_C = K_vec.size();
	C.resize(num_row_C, var_vtx_n);
	C.setFromTriplets(triplets_C.begin(), triplets_C.end());
	Ct = C.transpose();

	if(use_mat_var){
		K_mat.resize(num_row_C, 3);
		for(int i = 0; i < num_row_C; i++){
			K_mat(i, 0) = K_vec[i][0];
			K_mat(i, 1) = K_vec[i][1];
			K_mat(i, 2) = K_vec[i][2];
		}
	}
}


void PQSparseDispSoftCon::evaluate_least_squares_dist_mat()
{
	Eigen::MatrixXd new_vtx_mat = orig_vtx_mat + H_mat;
	face_diagonal_dist.clear();
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;
	int face_i = 0;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		Matrix43d M;
		int cur_row = 0;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			M.row(cur_row) = new_vtx_mat.row(fv_it.handle().idx());
			cur_row ++;
		}

		Eigen::Vector3d mean_vec = M.colwise().mean();
		double sqr_dist = 0.0;
		for(int k = 0; k < 4; k++){
			Eigen::Vector3d temp_vec = M.row(k) - Z_mat.row(face_i + k);
			sqr_dist += ( temp_vec - mean_vec).squaredNorm();
		}

		face_i += 4;
		face_diagonal_dist.push_back(sqr_dist);
	}
}


void PQSparseDispSoftCon::initialize_disp_3rddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	std::vector< MeshPointType > init_F;
	int row_n = 0;

	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		MeshPointType f_vec(0.0);

		for(int k = 0; k < 4; k++){
			f_vec += orig_vtx_pos[polyline_idx[i][k]] * coef[k];
			triplets_E.push_back(T(row_n, polyline_idx[i][k], coef[k]));
		}

		init_F.push_back(f_vec);
		row_n ++;
	}

	E.resize(row_n, var_vtx_n);
	E.setFromTriplets(triplets_E.begin(), triplets_E.end());
	Et = E.transpose();


	if(use_mat_var){
		F_mat.resize(row_n, 3);
		for(int i = 0; i < row_n; i++){
			F_mat(i, 0) = init_F[i][0];
			F_mat(i, 1) = init_F[i][1];
			F_mat(i, 2) = init_F[i][2];
		}

		W_mat = F_mat;
		prev_W_mat.setZero(row_n, 3);
		W_mat_diff.setZero(row_n, 3);
	}
}


void PQSparseDispSoftCon::initialize_primal_vars()
{
	int h_size = var_vtx_n;
	int y_size = var_vtx_n;
	int z_size = C.rows();
	Z_update_tmp_pts.resize(z_size, 3);
	Y_update_tmp_mat.resize(y_size, 3);

	if(use_mat_var){
		H_mat.setZero(h_size, 3);
		prev_H_mat.setZero(h_size, 3);
		H_mat_diff.setZero(h_size, 3);
		Y_mat.setZero(y_size, 3);
		if(!soft_vtx_disp_constraint){
			for(unsigned int i = 0; i < fixed_vtx_disp_array.size(); ++ i){
				Y_mat(fixed_vtx_disp_array[i].first, 0) = fixed_vtx_disp_array[i].second[0];
				Y_mat(fixed_vtx_disp_array[i].first, 1) = fixed_vtx_disp_array[i].second[1];
				Y_mat(fixed_vtx_disp_array[i].first, 2) = fixed_vtx_disp_array[i].second[2];
			}
		}

		prev_Y_mat = Y_mat;
		Y_mat_diff.setZero(y_size, 3);
		Z_mat.setZero(z_size, 3);
		prev_Z_mat.setZero(z_size, 3);
		Z_mat_diff.setZero(z_size, 3);
	}
}

void PQSparseDispSoftCon::zero_initialize_dual_vars()
{
	int d1_size = C.rows();
	int d2_size = var_vtx_n;
	int d3_size = E.rows();

	if(use_mat_var){
		D1_mat.setZero(d1_size, 3);
		D2_mat.setZero(d2_size, 3);
		D3_mat.setZero(d3_size, 3);
		primal_residual_mat_1.setZero(d1_size, 3);
		primal_residual_mat_2.setZero(d2_size, 3);
		primal_residual_mat_3.setZero(d3_size, 3);
	}
}


void PQSparseDispSoftCon::update_Z_mat()
{
	prev_Z_mat = Z_mat;
	Z_update_tmp_pts = K_mat - D1_mat;
	Z_update_tmp_pts.noalias() += C * H_mat;

	typedef Eigen::Matrix<double, 4, 3> Matrix43d;
	int row_n = Z_update_tmp_pts.rows();

	for(int i = 0; i < row_n; i += 4){

		Matrix43d M = Z_update_tmp_pts.block<4,3>(i, 0);
		Eigen::Vector3d mean_vec = M.colwise().mean();

		for(int k = 0; k < 4; k++){
			M.row(k) -= mean_vec;
		}

		Eigen::JacobiSVD<Matrix43d> jSVD(M, Eigen::ComputeFullV);
		Eigen::Vector3d N = jSVD.matrixV().col(2);

		for(int k = 0; k < 4; k++){
			Eigen::Vector3d row_pt = M.row(k);
			Z_mat.row( i + k ).noalias() = row_pt - N * N.dot(row_pt);
		}
	}

	Z_mat_diff = Z_mat - prev_Z_mat;

}

void PQSparseDispSoftCon::update_W_mat()
{
	prev_W_mat = W_mat;
	W_mat = F_mat - D3_mat;
	W_mat.noalias() += E * H_mat;
	W_mat *= ( penalty_weight / (penalty_weight + smoothness_weight) );
	W_mat_diff = W_mat - prev_W_mat;
}

void PQSparseDispSoftCon::update_W_mat_with_thresholding()
{
	prev_W_mat = W_mat;
	W_mat = F_mat - D3_mat;
	W_mat.noalias() += E * H_mat;
	double new_W_sqr_norm = W_mat.squaredNorm();
	if( new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 ) ){
		W_mat *= ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
	else if(new_W_sqr_norm > smoothness_energy_bound){
		W_mat *= (smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm));
	}

	W_mat_diff = W_mat - prev_W_mat;
}

void PQSparseDispSoftCon::update_H_mat()
{
	prev_H_mat = H_mat;
	H_mat = solver.solve(Ct * (Z_mat - K_mat + D1_mat) +  Et * (W_mat - F_mat + D3_mat) + Y_mat + D2_mat);
	H_mat_diff = H_mat - prev_H_mat;
}

void PQSparseDispSoftCon::update_mesh_vertices_mat()
{
	for(int i = 0; i < var_vtx_n; i++){
		pmesh->set_point(PolyMeshType::VertexHandle(i), orig_vtx_pos[i] + MeshPointType( H_mat(i,0), H_mat(i,1), H_mat(i,2) ));
	}

	pmesh->update_normals();

	if(update_mesh){
		mesh->setGeometryChanged();
	}
}

void PQSparseDispSoftCon::update_mesh_vertices_mat(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){
		update_mesh_vertices_mat();
	}
}


void PQSparseDispSoftCon::update_Y_soft_constrained_component(int idx)
{
	// This method assumes that Y_update_tmp_mat stores the current value of H + D2;
	MeshPointType cur_disp = fixed_vtx_displacement[idx];
	Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
	Eigen::Vector3d tmp_vec = Y_update_tmp_mat.row(idx);
	double t = penalty_weight / (penalty_weight + vtx_disp_weight);
	Y_mat.row(idx) = disp_vec * (1-t) + tmp_vec * t;
}

void PQSparseDispSoftCon::L0_update_Y_mat()
{
	prev_Y_mat = Y_mat;
	Y_update_tmp_mat = H_mat - D2_mat;

	for(int i = 0; i < var_vtx_n; ++ i){
		if(free_vtx[i]){
			if( Y_update_tmp_mat.row(i).squaredNorm() * penalty_weight <= sparsity_weight ){
				Y_mat.row(i).setZero();
			}
			else{
				Y_mat.row(i) = Y_update_tmp_mat.row(i);
			}
		}
		else if(soft_vtx_disp_constraint){
			update_Y_soft_constrained_component(i);
		}
	}

	Y_mat_diff = Y_mat - prev_Y_mat;
}

void PQSparseDispSoftCon::L1_update_Y_mat()
{
	prev_Y_mat = Y_mat;
	Y_update_tmp_mat = H_mat - D2_mat;

	for(int i = 0; i < var_vtx_n; ++ i){
		if(free_vtx[i]){
			Eigen::Vector3d cur_row_vec = Y_update_tmp_mat.row(i);
			double row_vec_norm = cur_row_vec.norm();
			if( 2 * row_vec_norm * penalty_weight <= sparsity_weight ){
				Y_mat.row(i).setZero();
			}
			else{
				Y_mat.row(i) = cur_row_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * row_vec_norm));
			}
		}
		else if(soft_vtx_disp_constraint){
			update_Y_soft_constrained_component(i);
		}
	}

	Y_mat_diff = Y_mat - prev_Y_mat;
}


void PQSparseDispSoftCon::initialize_stopping_criteria_var()
{
	if(use_mat_var){
		primal_ep_abs = dual_ep_abs = std::sqrt(double(Z_mat.rows() + Y_mat.rows() + W_mat.rows()) * 3) * ep_abs;
	}
}


void PQSparseDispSoftCon::initialize_primal_residual_norm()
{
	//compute_primal_residual_mat();
	//prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
	//		primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
	prev_primal_residual_norm = 1e10;
}

void PQSparseDispSoftCon::compute_primal_residual_mat()
{
	primal_residual_mat_1 = Z_mat - K_mat;
	primal_residual_mat_1.noalias() -= C * H_mat;

	primal_residual_mat_2 = Y_mat - H_mat;

	primal_residual_mat_3 = W_mat - F_mat;
	primal_residual_mat_3.noalias() -= E * H_mat;
}


bool PQSparseDispSoftCon::dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(int iter_num)
{
	if(iter_num >= 1000){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Compute primal resiuduals
	compute_primal_residual_mat();

	// Update dual variables
	D1_mat += primal_residual_mat_1;
	D2_mat += primal_residual_mat_2;
	D3_mat += primal_residual_mat_3;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());

	double dual_residual_norm = penalty_weight * std::sqrt((C * H_mat_diff).squaredNorm() + (E * H_mat_diff).squaredNorm() + H_mat_diff.squaredNorm());

	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

	//double max_diagonal_dist = *std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end());

	if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs){
		update_mesh_vertices_mat();
		update_diagonal_dist_histogram(0);
		return true;
	}

	// Update penalty weight
	if(iter_num > 0 && iter_num % check_penalty_period == 0){
		bool need_incr = false;

		// Make sure current penalty does not exceed max value
		if(penalty_weight <= max_penalty){
			if(dual_residual_norm <= primal_residual_norm * lambda){
				// If we cannot update because dual residual is too large, we do not update the previous primal residual value

				// Increase penalty parameter if primal residual is too large w.r.t. dual residual,
				// or if the primal residual does not decrease enough
				need_incr = (primal_residual_norm > min_residual_change_ratio * prev_primal_residual_norm)
						|| (primal_residual_norm > dual_residual_norm * lambda);
				prev_primal_residual_norm = primal_residual_norm;
			}
		}

		if(need_incr){
			penalty_weight *= tau_incr;
			D1_mat /= tau_incr;
			D2_mat /= tau_incr;
			D3_mat /= tau_incr;
		}
	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}

//bool PQSparseDispSoftCon::dual_var_update_with_stop_check_and_penalty_weight_update_mat(int iter_num)
//{
//	if(iter_num >= 1000){
//		update_mesh_vertices_mat();
//		update_diagonal_dist_histogram(0);
//		return true;
//	}
//
//	// Compute primal resiuduals
//	compute_primal_residual_mat();
//
//	// Update dual variables
//	D1_mat += primal_residual_mat_1;
//	D2_mat += primal_residual_mat_2;
//	D3_mat += primal_residual_mat_3;
//
//	dual_residual_mat = Ct * Z_mat_diff + Y_mat_diff + Et * W_mat_diff;
//
//	// Check stopping criteria
//	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
//			primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
//
//	double dual_residual_norm = penalty_weight * dual_residual_mat.norm();
//
//	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
//	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;
//
//	double max_diagonal_dist = *std::max_element(face_diagonal_dist.begin(), face_diagonal_dist.end());
//
//	if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs && max_diagonal_dist <= diagonal_dist_bound){
//		update_mesh_vertices_mat();
//		update_diagonal_dist_histogram(0);
//		return true;
//	}
//
//	// Update penalty weight
//	bool need_incr = false;
//
//	if(penalty_weight * tau_incr <= max_penalty){
//		if(primal_residual_norm > lambda * dual_residual_norm){
//			need_incr = true;
//		}
//		//else if(iter_num != 0 && iter_num % check_penalty_period == 0){
//		//	need_incr = primal_residual_norm > residual_change_ratio * prev_primal_residual_norm
//		//			&& dual_residual_norm < lambda * primal_residual_norm ;
//		//	prev_primal_residual_norm = primal_residual_norm;
//		//}
//	}
//
//	if(need_incr){
//		penalty_weight *= tau_incr;
//		D1_mat /= tau_incr;
//		D2_mat /= tau_incr;
//		D3_mat /= tau_incr;
//	}
//
//	std::cout << "Penalty Weight:" << penalty_weight << std::endl;
//
//	return false;
//}


void PQSparseDispSoftCon::update_diagonal_dist_histogram(int iter_num)
{
	if(update_histogram && (iter_num % update_period == 0)){
		histogram->setMeasures(face_diagonal_dist);
	}
}

void PQSparseDispSoftCon::L1_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;
		update_Z_mat();
		L1_update_Y_mat();

		if(threshold_smoothness){
			update_W_mat_with_thresholding();
		}
		else{
			update_W_mat();
		}

		update_H_mat();

		//evaluate_diagonal_dist_mat();
		this->evaluate_least_squares_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(iter)){
			return;
		}

	}
}

void PQSparseDispSoftCon::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		L1_optimize_mat();
		opt_disp.clear();

		for(int i = 0; i < var_vtx_n; i++){
			opt_disp.push_back(MeshPointType(H_mat(i, 0), H_mat(i, 1), H_mat(i, 2)));
		}
	}
}


void PQSparseDispSoftCon::L0_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;

		update_Z_mat();
		L0_update_Y_mat();

		if(threshold_smoothness){
			update_W_mat_with_thresholding();
		}
		else{
			update_W_mat();
		}

		update_H_mat();

		//evaluate_diagonal_dist_mat();
		this->evaluate_least_squares_dist_mat();
		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(iter)){
			return;
		}
	}
}

void PQSparseDispSoftCon::L0_optimize(std::vector<MeshPointType> &opt_disp)
{
	if(use_mat_var){
		L0_optimize_mat();
		opt_disp.clear();

		for(int i = 0; i < var_vtx_n; i++){
			opt_disp.push_back(MeshPointType(H_mat(i, 0), H_mat(i, 1), H_mat(i, 2)));
		}
	}
}


const std::vector<double>& PQSparseDispSoftCon::face_least_squres_dist_measure()
{
	evaluate_least_squares_dist_mat();
	return face_diagonal_dist;
}

const std::vector<double>& PQSparseDispSoftCon::face_rel_diagonal_dist_measure()
{
	evaluate_diagonal_dist_mat();
	return face_diagonal_dist;
}

void PQSparseDispSoftCon::evaluate_diagonal_dist_mat()
{
	Eigen::MatrixXd new_vtx_mat = orig_vtx_mat + H_mat;
	face_diagonal_dist.clear();
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		std::vector<MeshPointType> vtx;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			int i = fv_it.handle().idx();
			vtx.push_back(MeshPointType(new_vtx_mat(i, 0), new_vtx_mat(i, 1), new_vtx_mat(i, 2)));
		}

		MeshPointType N = Dolphin::defines::cross((vtx[2] - vtx[0]).normalize(), (vtx[3] - vtx[1]).normalize()).normalize();
		double dist = std::abs( Dolphin::defines::dot( N, (vtx[3] + vtx[1]) * 0.5 - (vtx[2] + vtx[0]) * 0.5  ));
		double dimension = ((vtx[0] -vtx[2]).norm() + (vtx[1] -vtx[3]).norm()) * 0.5;
		face_diagonal_dist.push_back(dist / dimension);
	}
}

void PQTangentSparseDisp::initialize_variables(OpenMeshNode *mesh_, const std::vector< std::vector<double> > &tangent_basis_,
		int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double tau_incr_, bool threshold_smoothness_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	fixed_vtx_disp_array.clear();
	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter){
		fixed_vtx_disp_array.push_back(std::make_pair(iter->first, iter->second));
	}

	var_vtx_n = pmesh->n_vertices();
	tangent_basis = tangent_basis_;

	update_mesh = true;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	threshold_smoothness = threshold_smoothness_;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	tau_incr = tau_incr_;

	min_residual_change_ratio = 0.6;
	check_penalty_period = 10;

	max_penalty = 1e5;
	min_penalty = std::min(10.0, init_penalty_weight_);

	initialize_var_index();

	initialize_tangent_basis_matrix();

	store_orig_vertex_positions();

	initialize_disp_3rddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();
}


void PQTangentSparseDisp::initialize_tangent_basis_matrix()
{
	int n = tangent_basis.size();
	int n_coord = 3 * var_vtx_n;

	T.resize(n_coord, n);
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n_coord; i++){
			T(i, k) = tangent_basis[k][i];
		}
	}

	Tt = T.transpose();
}


void PQTangentSparseDisp::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness){
		smoothness_energy_bound = F_mat.squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}



void PQTangentSparseDisp::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
			iter != fixed_vtx_displacement.end(); ++ iter){
		free_vtx[iter->first] = 0;
	}
}


void PQTangentSparseDisp::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_mat.resize(3 * n_vtx);

	for(int i = 0; i < n_vtx; i++){
		MeshPointType pt = pmesh->point(PolyMeshType::VertexHandle(i));
		orig_vtx_mat(3 * i) = pt[0];
		orig_vtx_mat(3 * i + 1) = pt[1];
		orig_vtx_mat(3 * i + 2) = pt[2];
	}
}

void PQTangentSparseDisp::initialize_solver()
{
	solver.compute(Tt * T + ETt * ET);
}


void PQTangentSparseDisp::initialize_disp_3rddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> Triplet_type;
	std::vector<Triplet_type> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	int row_n = 0;
	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		for(int k = 0; k < 4; k++){
			triplets_E.push_back(Triplet_type(row_n, 3 * polyline_idx[i][k], coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 1, 3 * polyline_idx[i][k] + 1, coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 2, 3 * polyline_idx[i][k] + 2, coef[k]));
		}
		row_n += 3;
	}

	SparseMatrixXd E_mat(row_n, var_vtx_n * 3);
	E_mat.setFromTriplets(triplets_E.begin(), triplets_E.end());

	F_mat = E_mat * orig_vtx_mat;
	ET = E_mat * T;
	ETt = ET.transpose();
	W_mat = F_mat;
}


void PQTangentSparseDisp::initialize_primal_vars()
{
	int h_size = var_vtx_n * 3;
	int y_size = var_vtx_n * 3;
	Y_update_tmp_mat.setZero(y_size);
	H_mat.setZero(h_size);
	prev_H_mat.setZero(h_size);
	Y_mat.setZero(y_size);
	G_mat.setZero(tangent_basis.size());
	ETG_mat.setZero(ET.rows());
	prev_ETG_mat.setZero(ET.rows());
}

void PQTangentSparseDisp::zero_initialize_dual_vars()
{
	int d1_size = var_vtx_n * 3;
	int d2_size = ET.rows();
	D1_mat.setZero(d1_size);
	D2_mat.setZero(d2_size);
	primal_residual_mat_1.setZero(d1_size);
	primal_residual_mat_2.setZero(d2_size);
}

void PQTangentSparseDisp::update_W_mat()
{
	W_mat = ETG_mat + F_mat - D2_mat;
	W_mat *= ( penalty_weight / (penalty_weight + smoothness_weight) );
}

void PQTangentSparseDisp::update_W_mat_with_thresholding()
{
	W_mat = ETG_mat + F_mat - D2_mat;
	double new_W_sqr_norm = W_mat.squaredNorm();
	if( new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 ) ){
		W_mat *= ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
	else if(new_W_sqr_norm > smoothness_energy_bound){
		W_mat *= (smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm));
	}
}

void PQTangentSparseDisp::update_G_mat()
{
	G_mat = solver.solve(Tt * (Y_mat + D1_mat) +  ETt * (W_mat - F_mat + D2_mat));

	prev_H_mat = H_mat;
	H_mat.noalias() = T * G_mat;

	prev_ETG_mat = ETG_mat;
	ETG_mat.noalias() = ET * G_mat;
}

void PQTangentSparseDisp::update_mesh_vertices_mat()
{
	Eigen::VectorXd new_vtx_pos = orig_vtx_mat + H_mat;
	for(int i = 0; i < var_vtx_n; i++){
		pmesh->set_point(PolyMeshType::VertexHandle(i), MeshPointType(new_vtx_pos(3 * i), new_vtx_pos(3 * i + 1), new_vtx_pos(3 * i + 2) ));
	}

	pmesh->update_normals();

	if(update_mesh){
		mesh->setGeometryChanged();
	}
}

void PQTangentSparseDisp::update_mesh_vertices_mat(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){
		update_mesh_vertices_mat();
	}
}

void PQTangentSparseDisp::L1_update_Y_mat()
{
	Y_update_tmp_mat = H_mat - D1_mat;

	for(int i = 0; i < var_vtx_n; ++ i){
		if(free_vtx[i]){
			Eigen::Vector3d cur_vec = Y_update_tmp_mat.segment<3>(3 * i);
			double vec_norm = cur_vec.norm();
			if( 2 * vec_norm * penalty_weight <= sparsity_weight ){
				Y_mat.segment<3>(3 * i).setZero();
			}
			else{
				Y_mat.segment<3>(3 * i) = cur_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * vec_norm));
			}
		}
		else{
			MeshPointType cur_disp = fixed_vtx_displacement[i];
			Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
			Eigen::Vector3d tmp_vec = Y_update_tmp_mat.segment<3>(3 * i);
			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
			Y_mat.segment<3>(3 * i) = disp_vec * (1-t) + tmp_vec * t;
		}
	}
}


void PQTangentSparseDisp::initialize_stopping_criteria_var()
{
	primal_ep_abs = dual_ep_abs = std::sqrt(double(Y_mat.rows() + W_mat.rows())) * ep_abs;
}


void PQTangentSparseDisp::initialize_primal_residual_norm()
{
	//compute_primal_residual_mat();
	//prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
	//		primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
	prev_primal_residual_norm = 1e10;
}

void PQTangentSparseDisp::compute_primal_residual_mat()
{
	primal_residual_mat_1 = Y_mat - H_mat;
	primal_residual_mat_2 = W_mat - ETG_mat - F_mat;
}


bool PQTangentSparseDisp::dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(int iter_num)
{
	if(iter_num >= 1000){
		update_mesh_vertices_mat();
		return true;
	}

	// Compute primal resiuduals
	compute_primal_residual_mat();

	// Update dual variables
	D1_mat += primal_residual_mat_1;
	D2_mat += primal_residual_mat_2;

	// Check stopping criteria
	double primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() + primal_residual_mat_2.squaredNorm());
	double dual_residual_norm = penalty_weight * std::sqrt((H_mat - prev_H_mat).squaredNorm() + (ETG_mat - prev_ETG_mat).squaredNorm());

	std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
	std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

	if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs){
		update_mesh_vertices_mat();
		return true;
	}

	// Update penalty weight
//	if(iter_num > 0 && iter_num % check_penalty_period == 0){
//		bool need_incr = false;
//
//		// Make sure current penalty does not exceed max value
//		if(penalty_weight <= max_penalty){
//			if(dual_residual_norm <= primal_residual_norm * lambda){
//				// If we cannot update because dual residual is too large, we do not update the previous primal residual value
//
//				// Increase penalty parameter if primal residual is too large w.r.t. dual residual,
//				// or if the primal residual does not decrease enough
//				need_incr = (primal_residual_norm > min_residual_change_ratio * prev_primal_residual_norm)
//						|| (primal_residual_norm > dual_residual_norm * lambda);
//				prev_primal_residual_norm = primal_residual_norm;
//			}
//		}
//
//		if(need_incr){
//			penalty_weight *= tau_incr;
//			D1_mat /= tau_incr;
//			D2_mat /= tau_incr;
//		}
//	}

	if(dual_residual_norm >= primal_residual_norm * lambda && penalty_weight / tau_incr >= min_penalty){
		penalty_weight /= tau_incr;
		D1_mat *= tau_incr;
		D2_mat *= tau_incr;
	}
	else if(primal_residual_norm >= dual_residual_norm * lambda && penalty_weight * tau_incr <= max_penalty){
		penalty_weight *= tau_incr;
		D1_mat /= tau_incr;
		D2_mat /= tau_incr;
	}

	std::cout << "Penalty Weight:" << penalty_weight << std::endl;

	return false;
}

void PQTangentSparseDisp::L1_optimize_mat()
{
	int iter = 0;
	while(true){
		std::cout << "Iteration " << iter++ << std::endl;

		L1_update_Y_mat();

		if(threshold_smoothness){
			update_W_mat_with_thresholding();
		}
		else{
			update_W_mat();
		}

		update_G_mat();

		//evaluate_diagonal_dist_mat();
//		this->evaluate_least_squares_dist_mat();
//		update_diagonal_dist_histogram(iter);
		update_mesh_vertices_mat(iter);

		if(dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(iter)){
			return;
		}
	}
}

void PQTangentSparseDisp::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	double start_time = omp_get_wtime();

	L1_optimize_mat();

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;

	opt_disp.clear();

	for(int i = 0; i < var_vtx_n; i++){
		opt_disp.push_back(MeshPointType(H_mat(3*i), H_mat(3*i+1), H_mat(3*i+2)));
	}
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


//void PQSparseDispSoftConstraint::set_histogram(MeshHistogram *histogram_)
//{
//	update_histogram = true;
//	histogram = histogram_;
//}


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

void PQSparseDispSoftConstraint::update_W()
{
	#pragma omp for
	for(int i = 0; i < 3; i++){
		W[i].noalias() = W_update_tmp[i] * ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
}




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

void PQSparseDispSoftConstraint::reset_data(const std::vector<MeshPointType> &init_disp)
{
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < this->var_vtx_n; j++){
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


void PQSparseDispSoftConRowMajor::initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double tau_incr_, bool threshold_smoothness_, bool diff_vec_planarity)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;
	fixed_vtx_disp_array.clear();
	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin(); iter != fixed_vtx_displacement.end(); ++ iter){
		fixed_vtx_disp_array.push_back(std::make_pair(iter->first, iter->second));
	}

	var_vtx_n = pmesh->n_vertices();
	face_n = pmesh->n_faces();

	update_mesh = true;
	update_period = update_period_;

	penalty_weight = init_penalty_weight_;
	min_penalty = init_penalty_weight_;
	sparsity_weight = sparsity_weight_;
	smoothness_weight = smoothness_weight_;
	vtx_disp_weight = vtx_disp_weight_;
	threshold_smoothness = threshold_smoothness_;
	difference_vec_planarity = diff_vec_planarity;

	ep_abs = ep_abs_;
	ep_rel = ep_rel_;
	lambda = 10;
	tau_incr = tau_incr_;
	tau_decr = 2;
	diagonal_dist_bound = 0.01;

	min_residual_change_ratio = 0.6;
	check_penalty_period = 10;

	max_penalty = 1e5;

	initialize_var_index();

	store_orig_vertex_positions();

	if(this->difference_vec_planarity){
		initialize_diffvec_matrix();
	}
	else{
		initialize_centered_matrix();
	}

	initialize_disp_3rddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();
}


void PQSparseDispSoftConRowMajor::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness){
		smoothness_energy_bound = F.squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}


//void PQSparseDispSoftConRowMajor::set_histogram(MeshHistogram *histogram_)
//{
//	update_histogram = true;
//	histogram = histogram_;
//}


void PQSparseDispSoftConRowMajor::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
			iter != fixed_vtx_displacement.end(); ++ iter){
		free_vtx[iter->first] = 0;
	}
}


void PQSparseDispSoftConRowMajor::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_pos.resize(3, n_vtx);
	for(int i = 0; i < n_vtx; i++){
		MeshPointType &pt = pmesh->point(PolyMeshType::VertexHandle(i));
		orig_vtx_pos(0,i) = pt[0];
		orig_vtx_pos(1,i) = pt[1];
		orig_vtx_pos(2,i) = pt[2];
	}

	new_vtx_pos = orig_vtx_pos;
}

void PQSparseDispSoftConRowMajor::initialize_solver()
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

void PQSparseDispSoftConRowMajor::initialize_centered_matrix()
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

	K = orig_vtx_pos * Ct;

	C43.fill(-0.25);
	for(int i = 0; i < 4; i++){
		C43(i, i) = 0.75;
	}
}

void PQSparseDispSoftConRowMajor::initialize_diffvec_matrix()
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

	K = orig_vtx_pos * Ct;
}


void PQSparseDispSoftConRowMajor::initialize_disp_3rddiff_energy_matrix()
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

	F = orig_vtx_pos * Et;
}


void PQSparseDispSoftConRowMajor::initialize_primal_vars()
{
	int h_size = var_vtx_n;
	int y_size = var_vtx_n;
	int z_size = C.rows();

	H.setZero(3, h_size);
	prev_H = H;
	Y.setZero(3, y_size);
	Z.setZero(3, z_size);
	W = F;
	Z_update_tmp = K;
	Y_update_tmp.setZero(3, y_size);
	W_update_tmp = F;
}

void PQSparseDispSoftConRowMajor::zero_initialize_dual_vars()
{
	int d1_size = C.rows();
	int d2_size = var_vtx_n;
	int d3_size = E.rows();

	D1.setZero(3, d1_size);
	D2.setZero(3, d2_size);
	D3.setZero(3, d3_size);
	primal_residual_1.setZero(3, d1_size);
	primal_residual_2.setZero(3, d2_size);
	primal_residual_3.setZero(3, d3_size);
}


void PQSparseDispSoftConRowMajor::update_Z()
{
	typedef Eigen::Matrix<double, 3, 4> Matrix34d;

	#pragma omp for
	for(int i = 0; i < face_n; i ++){
		int base_idx = i * 4;

		Matrix34d M = Z_update_tmp.block<3,4>(0,base_idx) * C43;

		Eigen::JacobiSVD<Matrix34d> jSVD(M, Eigen::ComputeFullU);
		Eigen::Matrix<double,3,1> N = jSVD.matrixU().col(2);

		Z.block<3,4>(0, base_idx) = M - N * ( N.transpose() * M );
	}
}

void PQSparseDispSoftConRowMajor::update_Z_diffvec()
{
	typedef Eigen::Matrix<double, 3, 3> Matrix33d;

	#pragma omp for
	for(int i = 0; i < face_n; i ++){
		int base_idx = i * 3;

		Matrix33d M = Z_update_tmp.block<3,3>(0, base_idx);
		Eigen::JacobiSVD<Matrix33d> jSVD(M, Eigen::ComputeFullU);
		Eigen::Matrix<double,3,1> N = jSVD.matrixU().col(2);

		Z.block<3,3>(0, base_idx) = M - N * (N.transpose() * M);
	}
}

void PQSparseDispSoftConRowMajor::update_W()
{
	#pragma omp single
	{
		W.noalias() = W_update_tmp * ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
}

void PQSparseDispSoftConRowMajor::update_W_with_thresholding()
{
	#pragma omp single
	{
		W_update_factor = 1.0;
		double new_W_sqr_norm = W_update_tmp.squaredNorm();

		if(new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 )){
			W_update_factor =  penalty_weight / (penalty_weight + smoothness_weight) ;
		}
		else if(new_W_sqr_norm > smoothness_energy_bound){
			W_update_factor = smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm);
		}

		W.noalias() = W_update_tmp * W_update_factor;
	}
}

void PQSparseDispSoftConRowMajor::update_H()
{
#pragma omp for
	for(int i = 0; i < 3; i++){
		//prev_H.row(i) = H.row(i);
		H.row(i) = solver.solve(((Z.row(i) - K.row(i) + D1.row(i)) * C + (W.row(i) - F.row(i) + D3.row(i)) * E + Y.row(i) + D2.row(i)).transpose()).transpose();
		//H_diff.row(i) = H.row(i) - prev_H.row(i);

//		new_vtx_pos.row(i) = orig_vtx_pos.row(i) + H.row(i);
//
//		// Update primal residual
//		primal_residual_1.row(i) = Z.row(i) - K.row(i) - H.row(i) * Ct;
//
//		primal_residual_2.row(i) = Y.row(i) - H.row(i);
//
//		primal_residual_3.row(i) = W.row(i) - F.row(i) - H.row(i) * Et;
//
//		// Store temporary squared norm
//		primal_residual_squared_norm[i] = primal_residual_1.row(i).squaredNorm() + primal_residual_2.row(i).squaredNorm()
//				+ primal_residual_3.row(i).squaredNorm();
//
//		dual_residual_squared_norm[i] = (H_diff.row(i) * Ct).squaredNorm() + (H_diff.row(i) * Et).squaredNorm() + H_diff.row(i).squaredNorm();
	}


	// Dispatch works to different threads
#pragma omp sections
{
	#pragma omp section
	{
		new_vtx_pos = orig_vtx_pos + H;
	}

	#pragma omp section
	{
		primal_residual_1 = Z - K;
		primal_residual_1.noalias() -= H * Ct;
		primal_residual_squared_norm[0] = primal_residual_1.squaredNorm();
	}

	#pragma omp section
	{
		primal_residual_2 = Y - H;
		primal_residual_squared_norm[1] = primal_residual_2.squaredNorm();
	}

	#pragma omp section
	{
		primal_residual_3 = W - F;
		primal_residual_3.noalias() -= H * Et;
		primal_residual_squared_norm[2] = primal_residual_3.squaredNorm();
	}

	#pragma omp section
	{
		H_diff = H - prev_H;
		prev_H = H;
		single_dual_residual_norm = std::sqrt((H_diff * Ct).squaredNorm() + (H_diff * Et).squaredNorm() + H_diff.squaredNorm());
	}
}
}

void PQSparseDispSoftConRowMajor::update_mesh_vertices()
{
	update_mesh_vertices(0);
}

void PQSparseDispSoftConRowMajor::update_mesh_vertices(int iter_num)
{
	if(update_mesh && (iter_num % update_period == 0) ){
		for(int i = 0; i < var_vtx_n; i++){
			pmesh->set_point(PolyMeshType::VertexHandle(i), MeshPointType( new_vtx_pos(0, i), new_vtx_pos(1, i), new_vtx_pos(2,i)));
		}

		pmesh->update_normals();
		mesh->setGeometryChanged();
	}
}


//void PQSparseDispSoftConRowMajor::update_Y_soft_constrained_component(int idx)
//{
//	// This method assumes that Y_update_tmp_mat stores the current value of H + D2;
//	MeshPointType cur_disp = fixed_vtx_displacement[idx];
//	Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
//	Eigen::Vector3d tmp_vec = Y_update_tmp_mat.row(idx);
//	double t = penalty_weight / (penalty_weight + vtx_disp_weight);
//	Y_mat.row(idx) = disp_vec * (1-t) + tmp_vec * t;
//}


void PQSparseDispSoftConRowMajor::L1_update_Y()
{
#pragma omp for
	for(int i = 0; i < var_vtx_n; i++){
		if(free_vtx[i]){
			double update_vec_norm = Y_update_tmp.col(i).norm();
			if( 2 * update_vec_norm * penalty_weight <= sparsity_weight ){
				Y.col(i).setZero();
			}
			else{
				double t = 1.0 - 0.5 * sparsity_weight / (penalty_weight * update_vec_norm);
				Y.col(i) = Y_update_tmp.col(i) * t;
			}
		}
		else{
			MeshPointType &cur_disp = fixed_vtx_displacement[i];
			Eigen::Vector3d cur_disp_vec( cur_disp[0], cur_disp[1], cur_disp[2] );
			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
			Y.col(i) = cur_disp_vec * (1-t) + Y_update_tmp.col(i) * t;
		}
	}
}


void PQSparseDispSoftConRowMajor::initialize_stopping_criteria_var()
{
	primal_ep_abs = dual_ep_abs = std::sqrt(double(Z.cols() + Y.cols() + W.cols()) * 3) * ep_abs;
}


void PQSparseDispSoftConRowMajor::initialize_primal_residual_norm()
{
	//compute_primal_residual_mat();
	//prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
	//		primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
	prev_primal_residual_norm = 1e10;
}


void PQSparseDispSoftConRowMajor::dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num)
{
#pragma omp single
{
	optimization_end = false;
	need_change_penalty = false;

	if(iter_num >= 10000){
		std::cout << "Max iteration reached" << std::endl;
		optimization_end = true;
	}

	if(!optimization_end){
		// Check stopping criteria
		double primal_residual_norm = std::sqrt( primal_residual_squared_norm[0] + primal_residual_squared_norm[1] + primal_residual_squared_norm[2] );
		//double dual_residual_norm = penalty_weight * std::sqrt(dual_residual_squared_norm[0] + dual_residual_squared_norm[1] + dual_residual_squared_norm[2]);
		double dual_residual_norm = penalty_weight * single_dual_residual_norm;

		std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
		std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

		if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs){
			std::cout << "Residual norm within tolerance" << std::endl;
			optimization_end = true;
		}
		else{
			// Update penalty weight
			if(iter_num > 0 && iter_num % check_penalty_period == 0){
				// Make sure current penalty does not exceed max value or min value
				if(dual_residual_norm > primal_residual_norm * lambda && primal_residual_norm < primal_ep_abs * min_residual_change_ratio){
					need_change_penalty = true;
					penalty_change_ratio = 1.0 / tau_incr;
					prev_primal_residual_norm = primal_ep_abs / min_residual_change_ratio;
				}
				else if(dual_residual_norm <= primal_residual_norm * lambda && penalty_weight * tau_incr <= max_penalty){
					// If we cannot update because dual residual is too large, we do not update the previous primal residual value

					// Increase penalty parameter if primal residual is too large w.r.t. dual residual,
					// or if the primal residual does not decrease enough
					need_change_penalty = (primal_residual_norm > primal_ep_abs && primal_residual_norm > min_residual_change_ratio * prev_primal_residual_norm)
							|| (primal_residual_norm > dual_residual_norm * lambda);
					penalty_change_ratio = tau_incr;
					prev_primal_residual_norm = primal_residual_norm > primal_ep_abs ?  (primal_ep_abs / min_residual_change_ratio)  :  primal_residual_norm;
				}
			}

			if(need_change_penalty){
				//std::cout << "Penalty change with ratio " << penalty_change_ratio << std::endl;
				penalty_weight *= penalty_change_ratio;

			}

			std::cout << "Penalty:" << penalty_weight << std::endl;
		}
	}

	//std::cout << "Penalty Weight:" << penalty_weight << std::endl;
}
	#pragma omp sections
	{
		#pragma omp section
		{
			if(!optimization_end){
				D1 += primal_residual_1;

				if(need_change_penalty){
					D1 /= penalty_change_ratio;
				}

				Z_update_tmp = K - D1;
				Z_update_tmp.noalias() += H * Ct;
			}
		}

		#pragma omp section
		{
			if(!optimization_end){
				D2 += primal_residual_2;

				if(need_change_penalty){
					D2 /= penalty_change_ratio;
				}

				Y_update_tmp = H - D2;
			}
		}

		#pragma omp section
		{
			if(!optimization_end){
				D3 += primal_residual_3;

				if(need_change_penalty){
					D3 /= penalty_change_ratio;
				}

				W_update_tmp = F - D3;
				W_update_tmp.noalias() += H * Et;
			}
		}
	}
}


void PQSparseDispSoftConRowMajor::L1_optimize_unbounded_smoothness()
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


void PQSparseDispSoftConRowMajor::L1_optimize_bounded_smoothness()
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




void PQSparseDispSoftConRowMajor::L1_optimize_unbounded_smoothness_diffvec()
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


void PQSparseDispSoftConRowMajor::L1_optimize_bounded_smoothness_diffvec()
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

void PQSparseDispSoftConRowMajor::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
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
		opt_disp.push_back(MeshPointType(H(0,i), H(1,i), H(2,i)));
	}
}


void PQTangentSparseDispOpenMP::initialize_variables(OpenMeshNode *mesh_, const std::vector< std::vector<double> > &tangent_basis_,
		int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double tau_incr_, bool threshold_smoothness_)
{
	// Initialize variable indices
	mesh = mesh_;
	pmesh = mesh->getMesh().get();
	fixed_vtx_displacement = fixed_vtx_disp;

	var_vtx_n = pmesh->n_vertices();
	tangent_basis = tangent_basis_;

	update_mesh = true;
	update_period = update_period_;

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

	initialize_tangent_basis_matrix();

	store_orig_vertex_positions();

	initialize_disp_3rddiff_energy_matrix();

	zero_initialize_dual_vars();

	initialize_primal_vars();

	initialize_smoothness_energy_lowerbound();

	initialize_stopping_criteria_var();

	initialize_primal_residual_norm();

	initialize_solver();

	update_W();
}


void PQTangentSparseDispOpenMP::initialize_tangent_basis_matrix()
{
	int n = tangent_basis.size();
	int n_coord = 3 * var_vtx_n;

	T.resize(n_coord, n);
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n_coord; i++){
			T(i, k) = tangent_basis[k][i];
		}
	}

	Tt = T.transpose();
}


void PQTangentSparseDispOpenMP::initialize_smoothness_energy_lowerbound()
{
	if(threshold_smoothness){
		smoothness_energy_bound = F.squaredNorm();
		smoothness_energy_bound_sqrt = std::sqrt(smoothness_energy_bound);
	}
	else{
		smoothness_energy_bound = smoothness_energy_bound_sqrt = 0;
	}
}



void PQTangentSparseDispOpenMP::initialize_var_index()
{
	free_vtx.assign(var_vtx_n, 1);

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
			iter != fixed_vtx_displacement.end(); ++ iter){
		free_vtx[iter->first] = 0;
	}
}


void PQTangentSparseDispOpenMP::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_mat.resize(3 * n_vtx);

	for(int i = 0; i < n_vtx; i++){
		MeshPointType pt = pmesh->point(PolyMeshType::VertexHandle(i));
		orig_vtx_mat(3 * i) = pt[0];
		orig_vtx_mat(3 * i + 1) = pt[1];
		orig_vtx_mat(3 * i + 2) = pt[2];
	}
}

void PQTangentSparseDispOpenMP::initialize_solver()
{
	solver.compute(Tt * T + ETt * ET);
}


void PQTangentSparseDispOpenMP::initialize_disp_3rddiff_energy_matrix()
{
	typedef Eigen::Triplet<double> Triplet_type;
	std::vector<Triplet_type> triplets_E;

	std::vector< std::vector<int> > polyline_idx;
	get_3rddiff_polyline_idx(pmesh, polyline_idx);

	int row_n = 0;
	double coef[] = {1.0, -3.0, 3.0, -1.0};

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		for(int k = 0; k < 4; k++){
			triplets_E.push_back(Triplet_type(row_n, 3 * polyline_idx[i][k], coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 1, 3 * polyline_idx[i][k] + 1, coef[k]));
			triplets_E.push_back(Triplet_type(row_n + 2, 3 * polyline_idx[i][k] + 2, coef[k]));
		}
		row_n += 3;
	}

	SparseMatrixXd E_mat(row_n, var_vtx_n * 3);
	E_mat.setFromTriplets(triplets_E.begin(), triplets_E.end());

	F = E_mat * orig_vtx_mat;
	ET = E_mat * T;
	ETt = ET.transpose();
	W = F;
}


void PQTangentSparseDispOpenMP::initialize_primal_vars()
{
	int h_size = var_vtx_n * 3;
	int y_size = var_vtx_n * 3;
	Y_update_tmp.setZero(y_size);
	H.setZero(h_size);
	prev_H.setZero(h_size);
	Y.setZero(y_size);
	G.setZero(tangent_basis.size());
	ETG.setZero(ET.rows());
	prev_ETG.setZero(ET.rows());
	ETG2 = ETG;
}

void PQTangentSparseDispOpenMP::zero_initialize_dual_vars()
{
	int d1_size = var_vtx_n * 3;
	int d2_size = ET.rows();
	D1.setZero(d1_size);
	D2.setZero(d2_size);
	D1_t = D1;
	D2_t = D2;
	primal_residual_1.setZero(d1_size);
	primal_residual_2.setZero(d2_size);
}

void PQTangentSparseDispOpenMP::update_W()
{
//#ifdef USE_FASTADMM
	W = ETG2 + F - D2_t;
//#else
//	W = ETG + F - D2;
//#endif

	if(this->threshold_smoothness){
		double new_W_sqr_norm = W.squaredNorm();
		if( new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 ) ){
			W *=  (penalty_weight / (penalty_weight + smoothness_weight));
		}
		else if(new_W_sqr_norm > smoothness_energy_bound){
			W *= (smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm));
		}
	}
	else{
		W *= ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
}

void PQTangentSparseDispOpenMP::update_G()
{
#pragma omp single
{
	//#ifdef USE_FASTADMM
		G = solver.solve(Tt * (Y + D1_t) + ETt * (W - F + D2_t));
	//#else
	//	G = solver.solve(Tt * (Y + D1) + ETt * (W - F + D2));
	//#endif
}

#pragma omp sections
{
	#pragma omp section
	{
		prev_H = H;
		H.noalias() = T * G;
		primal_residual_1 = Y - H;
		primal_residual_squared_norm[0] = primal_residual_1.squaredNorm();
		single_dual_residual_squared_norm[0] = ( H - prev_H ).squaredNorm();
	}

	#pragma omp section
	{
		prev_ETG = ETG;
		ETG.noalias() = ET * G;
		primal_residual_2 = W - ETG - F;
		primal_residual_squared_norm[1] = primal_residual_2.squaredNorm();
		single_dual_residual_squared_norm[1] = ( ETG - prev_ETG ).squaredNorm();
	}
}
}

void PQTangentSparseDispOpenMP::L1_update_Y()
{
	#pragma omp for
	for(int i = 0; i < var_vtx_n; ++ i){
		int base_idx = 3 * i;
		if(free_vtx[i]){
			Eigen::Vector3d cur_vec = Y_update_tmp.segment<3>(base_idx);
			double vec_norm = cur_vec.norm();
			if( 2 * vec_norm * penalty_weight <= sparsity_weight ){
				Y.segment<3>(base_idx).setZero();
			}
			else{
				Y.segment<3>(base_idx) = cur_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * vec_norm));
			}
		}
		else{
			MeshPointType &cur_disp = fixed_vtx_displacement[i];
			Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
			Eigen::Vector3d tmp_vec = Y_update_tmp.segment<3>(3 * i);
			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
			Y.segment<3>(base_idx) = disp_vec * (1-t) + tmp_vec * t;
		}
	}
}


void PQTangentSparseDispOpenMP::initialize_stopping_criteria_var()
{
	primal_ep_abs = dual_ep_abs = std::sqrt(double(Y.rows() + W.rows())) * ep_abs;
}


void PQTangentSparseDispOpenMP::initialize_primal_residual_norm()
{
	//compute_primal_residual_mat();
	//prev_primal_residual_norm = std::sqrt( primal_residual_mat_1.squaredNorm() +
	//		primal_residual_mat_2.squaredNorm() + primal_residual_mat_3.squaredNorm());
	prev_primal_residual_norm = 1e10;
	last_primal_residual_norm = last_dual_residual_norm = 1e10;
}

void PQTangentSparseDispOpenMP::dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num)
{
#pragma omp single
{
	optimization_end = false;
	need_incr_penalty = false;

	if(iter_num >= 10000){
		std::cout << "Max iteration reached" << std::endl;
		optimization_end = true;
	}

	if(!optimization_end){
		// Check stopping criteria
		double primal_residual_norm = std::sqrt( primal_residual_squared_norm[0] + primal_residual_squared_norm[1] );
		double dual_residual_norm = penalty_weight * std::sqrt(single_dual_residual_squared_norm[0] + single_dual_residual_squared_norm[1]);

		std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
		std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

		if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs){
			std::cout << "Residual norm within tolerance" << std::endl;
			optimization_end = true;
		}
		else{
			// Update penalty weight
//			if(iter_num > 0 && iter_num % check_penalty_period == 0){
//				// Make sure current penalty does not exceed max value
//				if(penalty_weight * tau_incr <= max_penalty){
//					if(dual_residual_norm <= primal_residual_norm * penalty_incr_dual_residual_max_ratio){
//						// If we cannot update because dual residual is too large, we do not update the previous primal residual value
//
//						// Increase penalty parameter if primal residual is too large w.r.t. dual residual,
//						// or if the primal residual does not decrease enough
//						need_incr_penalty = (primal_residual_norm > min_residual_change_ratio * prev_primal_residual_norm && primal_residual_norm > primal_ep_abs)
//								|| (primal_residual_norm > dual_residual_norm * lambda);
//						prev_primal_residual_norm = primal_residual_norm;
//					}
//				}
//
//
//			}

			if(need_incr_penalty){
				penalty_weight *= tau_incr;
				dual_residual_norm *= tau_incr;	// Due to the penalty parameter factor in front of the dual residual, we need to increase the dual residual too

				//#ifdef USE_FASTADMM
				restart_fastadmm = true;
				std::cout << "fast admm restarted due to penalty change" << std::endl;
				//#endif
			}
			//#ifdef USE_FASTADMM
			else{
				restart_fastadmm = std::max( last_primal_residual_norm, last_dual_residual_norm ) < std::max( primal_residual_norm, dual_residual_norm );
				//restart_fastadmm = false;
			}

			if(restart_fastadmm){
				alpha = last_alpha = 1;
			}
			else{
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
					//Y_update_tmp.noalias() += (H - prev_H) * accel_factor;
				}

				Y_update_tmp -= D1_t;

//				#else
//
//				D1 += primal_residual_1;
//
//				if(need_incr_penalty){
//					D1 /= tau_incr;
//				}
//
//				Y_update_tmp = H - D1;
//
//				#endif
			}


		}

		#pragma omp section
		{
			if(!optimization_end){

//				#ifdef USE_FASTADMM

				last_D2 = D2;
				D2 = D2_t + primal_residual_2;
				if(need_incr_penalty){
					D2 /= tau_incr;
				}

				D2_t = D2;
				ETG2 = ETG;
				if(!restart_fastadmm){
					double accel_factor = (last_alpha - 1) / alpha;
					D2_t.noalias() += (D2 - last_D2) * accel_factor;
					//ETG2.noalias() += (ETG - prev_ETG) * accel_factor;
				}

//				#else
//
//				D2 += primal_residual_2;
//
//				if(need_incr_penalty){
//					D2 /= tau_incr;
//				}
//
//				#endif

				update_W();
			}
		}
	}
}

void PQTangentSparseDispOpenMP::update_mesh_vertices(int iter)
{
	if(update_mesh && (iter % update_period == 0) ){
		Eigen::VectorXd new_vtx_pos = orig_vtx_mat + H;
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

void PQTangentSparseDispOpenMP::L1_optimize()
{
	int iter = 0;

	omp_set_num_threads(8);

	while(true){
		std::cout << "Iteration " << iter++ << std::endl;

#pragma omp parallel
{
		L1_update_Y();
		update_G();
		dual_var_update_with_stop_check_and_penalty_weight_update(iter);
}

		if(optimization_end){
			update_mesh_vertices(0);
			return;
		}

		update_mesh_vertices(iter);
	}
}

void PQTangentSparseDispOpenMP::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	double start_time = omp_get_wtime();
	L1_optimize();
	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
	opt_disp.clear();

	for(int i = 0; i < var_vtx_n; i++){
		opt_disp.push_back(MeshPointType(H(3*i), H(3*i+1), H(3*i+2)));
	}
}


void PQTangentDispNormalConstraint::initialize_variables(OpenMeshNode *mesh_, const SparseMatrixXd &normal_basis,
		int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
		double ep_rel_, double tau_incr_, bool threshold_smoothness_)
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
	if(threshold_smoothness){
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

	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_displacement.begin();
			iter != fixed_vtx_displacement.end(); ++ iter){
		free_vtx[iter->first] = 0;
	}
}


void PQTangentDispNormalConstraint::store_orig_vertex_positions()
{
	int n_vtx = pmesh->n_vertices();
	orig_vtx_pos.resize(3 * n_vtx);


	for(int i = 0; i < n_vtx; i++){
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
	for(int i = 0; i < n_var; i++){
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

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		for(int k = 0; k < 3; k++){
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

	if(threshold_smoothness){
		F = E * orig_vtx_pos;
		W_update_tmp = F;
	}
	else{
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

	for(unsigned int i = 0; i < polyline_idx.size(); i++){
		for(int k = 0; k < 4; k++){
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

	if(threshold_smoothness){
		F = E * orig_vtx_pos;
		W_update_tmp = F;
	}
	else{
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

void PQTangentDispNormalConstraint::update_W()
{
	if(threshold_smoothness){
		double W_update_factor = 1.0;
		double new_W_sqr_norm = W_update_tmp.squaredNorm();

		if(new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 )){
			W_update_factor =  penalty_weight / (penalty_weight + smoothness_weight) ;
		}
		else if(new_W_sqr_norm > smoothness_energy_bound){
			W_update_factor = smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm);
		}

		W = W_update_tmp * W_update_factor;
	}
	else{
		W = W_update_tmp * ( penalty_weight / (penalty_weight + smoothness_weight) );
	}
}

//void PQTangentDispNormalConstraint::update_Wv()
//{
//	#pragma omp for
//	for(int i = 0; i < 3; i++){
//		Wv[i].noalias() = Wv_update_tmp[i] * ( penalty_weight / (penalty_weight + smoothness_weight) );
//	}
//}
//
//void PQTangentDispNormalConstraint::update_Wv_with_thresholding()
//{
//	#pragma omp single
//	{
//		double W_update_factor = 1.0;
//		double new_W_sqr_norm = Wv_update_tmp[0].squaredNorm() + Wv_update_tmp[1].squaredNorm() + Wv_update_tmp[2].squaredNorm();
//
//		if(new_W_sqr_norm > smoothness_energy_bound * std::pow( (smoothness_weight + penalty_weight)/penalty_weight, 2 )){
//			W_update_factor =  penalty_weight / (penalty_weight + smoothness_weight) ;
//		}
//		else if(new_W_sqr_norm > smoothness_energy_bound){
//			W_update_factor = smoothness_energy_bound_sqrt / std::sqrt(new_W_sqr_norm);
//		}
//	}
//
//	#pragma omp for
//	for(int i = 0; i < 3; i++){
//		Wv[i].noalias() = Wv_update_tmp[i] * W_update_factor;
//	}
//
//}
//
//
//void PQTangentDispNormalConstraint::initialize_centered_matrix()
//{
//	// Compute nean-centering matrix
//	typedef Eigen::Triplet<double> T;
//	std::vector<T> triplets_C;
//	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
//	PolyMeshType::FaceVertexIter fv_it;
//	int row_n = 0;
//	face_vtx_idx.clear();
//
//	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
//		std::vector<int> vtx_var_idx;
//		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
//			vtx_var_idx.push_back(fv_it.handle().idx());
//		}
//
//		for(int i = 0; i < 4; i++){
//
//			for(int k = 0; k < 4; k++){
//				triplets_C.push_back(T(row_n, vtx_var_idx[k], (k==i) ? 0.75:(-0.25) ));
//			}
//
//			row_n ++;
//		}
//
//		face_vtx_idx.push_back(vtx_var_idx);
//	}
//
//	C.resize(row_n, var_vtx_n);
//	C.setFromTriplets(triplets_C.begin(), triplets_C.end());
//	Ct = C.transpose();
//
//	for(int i = 0; i < 3; i++){
//		K[i] = C * orig_vtx_pos[i];
//	}
//
//	C43.fill(-0.25);
//	for(int i = 0; i < 4; i++){
//		C43(i, i) = 0.75;
//	}
//}
//
//
//void PQTangentDispNormalConstraint::update_Zv()
//{
//	typedef Eigen::Matrix<double, 4, 3> Matrix43d;
//
//	#pragma omp for
//	for(int i = 0; i < face_n; i ++){
//		int base_idx = i * 4;
//
//		Matrix43d M, Mc;
//		M.col(0) = Zv_update_tmp[0].segment<4>(base_idx);
//		M.col(1) = Zv_update_tmp[1].segment<4>(base_idx);
//		M.col(2) = Zv_update_tmp[2].segment<4>(base_idx);
//
//		Mc.noalias() = C43 * M;
//		Eigen::JacobiSVD<Matrix43d> jSVD(Mc, Eigen::ComputeFullV);
//
//		Eigen::Matrix<double,3,1> N = jSVD.matrixV().col(2);
//		Eigen::Matrix<double,1,3> Nt = N.transpose();
//
//		M.noalias() = Mc - (Mc * N) * Nt;
//
//		for(int k = 0; k < 3; k++){
//			Zv[k].segment<4>(base_idx) = M.col(k);
//		}
//	}
//}
//
//void PQTangentDispNormalConstraint::update_Hv()
//{
//#pragma omp for
//	for(int i = 0; i < 3; i++){
//		prev_Hv[i] = Hv[i];
//		Hv[i] = solver2.solve(Ct * (Zv[i] - Kv[i] + D1v[i]) +  Evt * (Wv[i] - Fv[i] + D3v[i]) + Yv[i] + D2v[i]);
//		Hv_diff[i] = Hv[i] - prev_Hv[i];
//
//		new_vtx_pos[i] = orig_vtx_pos_v[i] + Hv[i];
//
//		// Update primal residual
//		primal_residualv_1[i] = Zv[i] - Kv[i];
//		primal_residualv_1[i].noalias() -= C * Hv[i];
//
//		primal_residualv_2[i] = Yv[i] - Hv[i];
//
//		primal_residualv_3[i] = Wv[i] - Fv[i];
//		primal_residualv_3[i].noalias() -= E * Hv[i];
//
//		// Store temporary squared norm
//		primal_residual_squared_norm_v[i] = primal_residualv_1[i].squaredNorm() + primal_residualv_2[i].squaredNorm()
//				+ primal_residualv_3[i].squaredNorm();
//
//		dual_residual_squared_norm[i] = (C * H_diff[i]).squaredNorm() + (E * H_diff[i]).squaredNorm() + H_diff[i].squaredNorm();
//	}
//}

void PQTangentDispNormalConstraint::update_H()
{
#pragma omp single
{
	//#ifdef USE_FASTADMM
	if(this->threshold_smoothness){
		H = solver.solve(Y + D1_t + Et * (W - F + D2_t) - Nbt * D3_t);
	}
	else{
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
		if(this->threshold_smoothness){
			primal_residual_2 = W - EH - F;
		}
		else{
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

void PQTangentDispNormalConstraint::L1_update_Y()
{
	#pragma omp for
	for(int i = 0; i < var_vtx_n; ++ i){
		int base_idx = 3 * i;
		if(free_vtx[i]){
			Eigen::Vector3d cur_vec = Y_update_tmp.segment<3>(base_idx);
			double vec_norm = cur_vec.norm();
			if( 2 * vec_norm * penalty_weight <= sparsity_weight ){
				Y.segment<3>(base_idx).setZero();
			}
			else{
				Y.segment<3>(base_idx) = cur_vec * (1.0 - 0.5 * sparsity_weight / (penalty_weight * vec_norm));
			}
		}
		else{
			MeshPointType &cur_disp = fixed_vtx_displacement[i];
			Eigen::Vector3d disp_vec(cur_disp[0], cur_disp[1], cur_disp[2]);
			Eigen::Vector3d tmp_vec = Y_update_tmp.segment<3>(3 * i);
			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
			Y.segment<3>(base_idx) = disp_vec * (1-t) + tmp_vec * t;
		}
	}
}

//void PQTangentDispNormalConstraint::L1_update_Yv()
//{
//#pragma omp for
//	for(int i = 0; i < var_vtx_n; ++ i){
//		if(free_vtx[i]){
//			double row_vec_norm = std::sqrt( std::pow(Yv_update_tmp[0](i), 2) + std::pow(Yv_update_tmp[1](i), 2) + std::pow(Yv_update_tmp[2](i), 2) );
//			if( 2 * row_vec_norm * penalty_weight <= sparsity_weight ){
//				Yv[0](i) = Yv[1](i) = Yv[2](i) = 0.0;
//			}
//			else{
//				double t = 1.0 - 0.5 * sparsity_weight / (penalty_weight * row_vec_norm);
//				Yv[0](i) = Yv_update_tmp[0](i) * t;
//				Yv[1](i) = Yv_update_tmp[1](i) * t;
//				Yv[2](i) = Yv_update_tmp[2](i) * t;
//			}
//		}
//		else{
//			MeshPointType &cur_disp = fixed_vtx_displacement[i];
//			double t = penalty_weight / (penalty_weight + vtx_disp_weight);
//			Yv[0](i) = cur_disp[0] * (1-t) + Yv_update_tmp[0](i) * t;
//			Yv[1](i) = cur_disp[1] * (1-t) + Yv_update_tmp[1](i) * t;
//			Yv[2](i) = cur_disp[2] * (1-t) + Yv_update_tmp[2](i) * t;
//		}
//	}
//}


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

void PQTangentDispNormalConstraint::dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num)
{
#pragma omp single
{
	optimization_end = false;
	need_incr_penalty = false;

	if(iter_num >= 10000){
		std::cout << "Max iteration reached" << std::endl;
		optimization_end = true;
	}

	if(!optimization_end){
		// Check stopping criteria
		double primal_residual_norm = std::sqrt( primal_residual_squared_norm[0] + primal_residual_squared_norm[1] + primal_residual_squared_norm[2]);
		double dual_residual_norm = penalty_weight * std::sqrt(single_dual_residual_squared_norm[0] + single_dual_residual_squared_norm[1]);

		std::cout << "Primal Residual Norm: " << primal_residual_norm << ",  Primal_Eps:" << primal_ep_abs << std::endl;
		std::cout << "Dual Residual Norm: " << dual_residual_norm << ",  Dual_Eps:" << dual_ep_abs << std::endl;

		if(primal_residual_norm <= primal_ep_abs && dual_residual_norm <= dual_ep_abs){
			std::cout << "Residual norm within tolerance" << std::endl;
			optimization_end = true;
		}
		else{
			// Update penalty weight
//			if(iter_num > 0 && iter_num % check_penalty_period == 0){
//				// Make sure current penalty does not exceed max value
//				if(penalty_weight * tau_incr <= max_penalty){
//					if(dual_residual_norm <= primal_residual_norm * penalty_incr_dual_residual_max_ratio){
//						// If we cannot update because dual residual is too large, we do not update the previous primal residual value
//
//						// Increase penalty parameter if primal residual is too large w.r.t. dual residual,
//						// or if the primal residual does not decrease enough
//						need_incr_penalty = (primal_residual_norm > min_residual_change_ratio * prev_primal_residual_norm && primal_residual_norm > primal_ep_abs)
//								|| (primal_residual_norm > dual_residual_norm * lambda);
//						prev_primal_residual_norm = primal_residual_norm;
//					}
//				}
//
//
//			}

			if(need_incr_penalty){
				penalty_weight *= tau_incr;
				dual_residual_norm *= tau_incr;	// Due to the penalty parameter factor in front of the dual residual, we need to increase the dual residual too

				//#ifdef USE_FASTADMM
				restart_fastadmm = true;
				std::cout << "fast admm restarted due to penalty change" << std::endl;
				//#endif
			}
			//#ifdef USE_FASTADMM
			else{
				restart_fastadmm = std::max( last_primal_residual_norm, last_dual_residual_norm ) < std::max( primal_residual_norm, dual_residual_norm );
				std::cout << "fast admm restarted due to increased residual norm" << std::endl;
				//restart_fastadmm = false;
			}

			if(restart_fastadmm){
				alpha = last_alpha = 1;
			}
			else{
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

//				#else
//
//				D1 += primal_residual_1;
//
//				if(need_incr_penalty){
//					D1 /= tau_incr;
//				}
//
//				Y_update_tmp = H - D1;
//
//				#endif
			}


		}

		#pragma omp section
		{
			if(!optimization_end){

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

void PQTangentDispNormalConstraint::L1_optimize()
{
	int iter = 0;

	omp_set_num_threads(8);

	while(true){
		std::cout << "Iteration " << iter++ << std::endl;

#pragma omp parallel
{
		L1_update_Y();
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

void PQTangentDispNormalConstraint::L1_optimize(std::vector<MeshPointType> &opt_disp)
{
	double start_time = omp_get_wtime();
	L1_optimize();
	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
	opt_disp.clear();

	for(int i = 0; i < var_vtx_n; i++){
		opt_disp.push_back(MeshPointType(H(3*i), H(3*i+1), H(3*i+2)));
	}
}


void PQSparseDispViaTangentSpace::L1_optimize(std::vector<MeshPointType> &tangent_disp, std::vector<MeshPointType> &final_disp)
{
	double start_time = omp_get_wtime();
	tangent_disp_admm.L1_optimize(tangent_disp);
	sparse_disp_admm.reset_data(tangent_disp);
	sparse_disp_admm.L1_optimize(final_disp);

	double end_time = omp_get_wtime();
	std::cout << "Total time:" << end_time - start_time << " seconds" << std::endl;
}


void PQSparseDispViaTangentSpace::initialize_variables(OpenMeshNode *mesh_, const SparseMatrixXd &normal_basis, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double tau_incr_, bool threshold_smoothness_, int max_iter)
{
	tangent_disp_admm.initialize_variables(mesh_, normal_basis, update_period_, fixed_vtx_disp, sparsity_weight_, smoothness_weight_,
			vtx_disp_weight_, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness_);
	sparse_disp_admm.initialize_variables(mesh_, update_period_, fixed_vtx_disp, sparsity_weight_, smoothness_weight_, vtx_disp_weight_,
			init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness_, max_iter, false);
}

}}

