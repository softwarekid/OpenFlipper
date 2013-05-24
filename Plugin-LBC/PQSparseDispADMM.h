/*
 * PQSparseDispADMM.h
 *
 *  Created on: Jul 4, 2012
 *      Author: Bailin Deng
 */

#ifndef PQSPARSEDISPADMM_H_
#define PQSPARSEDISPADMM_H_

#include "ConstrainedMeshPluginTypedef.h"
#include <vector>
#include <map>
#include <boost/thread/mutex.hpp>
#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace Dolphin {
	namespace scenegraph {
		class OpenMeshNode;
	}

	namespace utilities{
	    class MeshHistogram;
	}
}

using namespace Dolphin::scenegraph;
using namespace Dolphin::utilities;

namespace Dolphin {

namespace plugins {


class PQSparseDispSDMM{

	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(PolyMeshType *pmesh_, const std::map<int, MeshPointType> &fixed_vtx_disp, double sparsity_weight_,
			double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double lambda_, double tau_incr_, double tau_decr_, bool use_mat_var_);

	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp, double sparsity_weight_,
			double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double lambda_, double tau_incr_, double tau_decr_, bool use_mat_var_);

	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp, double sparsity_weight_,
			double smoothness_weight_, double init_penalty_weight_, double Z_weight, double Y_weight, double W_weight,
			double min_change_bound, double lambda_, double tau_incr_, double tau_decr_, bool use_mat_var_);

	void initialize_penalty_method_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp, double sparsity_weight_,
			double smoothness_weight_, double init_penalty_weight_, double penalty_incr_ratio);

	void set_histogram(MeshHistogram *histogram_);
	void set_diagonal_dist_bound(double val){
		diagonal_dist_bound = val;
	}

	void L0_optimize(std::vector<MeshPointType> &opt_disp);
	void L1_optimize(std::vector<MeshPointType> &opt_disp);
	void L1_penalty_optimize(std::vector<MeshPointType> &opt_disp);

	void weighted_L0_optimize(std::vector<MeshPointType> &opt_disp);
	void weighted_L1_optimize(std::vector<MeshPointType> &opt_disp);
	const std::vector<double>& face_diagonal_dist_measure();

private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	std::vector< MeshPointType > orig_vtx_pos;

	bool update_histogram;
	MeshHistogram *histogram;

	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;

	// The relative weight between different constraints
	double Z_weight_rel, Y_weight_rel, W_weight_rel;
	double Z_weight_rel_square, Y_weight_rel_square, W_weight_rel_square;
	//double Z_weight_rel_sqrt, Y_weight_rel_sqrt, W_weight_rel_sqrt;
	//double Z_weight_abs, Y_weight_abs, W_weight_abs;

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Ct, C;
	SparseMatrixXd Et, E;

	Eigen::VectorXd D1[3], D2[3], D3[3];
	Eigen::VectorXd W[3];
	Eigen::VectorXd H[3];
	Eigen::VectorXd prev_H[3]; // store previous H value for computing dual residual
	Eigen::VectorXd K[3], Y[3], F[3], Z[3];
	Eigen::VectorXd primal_residual_1[3], primal_residual_2[3], primal_residual_3[3];

	// Intermediate variables
	Eigen::MatrixXd Z_update_tmp_pts;
	Eigen::MatrixXd Y_update_tmp_mat;

	// Matrix version of the above variables
	Eigen::MatrixXd D1_mat, D2_mat, D3_mat;
	Eigen::MatrixXd W_mat, H_mat, K_mat, Y_mat, F_mat, Z_mat;
	Eigen::MatrixXd prev_H_mat;  // store previous H value for computing dual residual
	Eigen::MatrixXd prev_Z_mat, prev_Y_mat, prev_W_mat;
	Eigen::MatrixXd primal_residual_mat_1, primal_residual_mat_2, primal_residual_mat_3;

	// Threshold to determine that the change is small enough
	double min_vec_change_threshold;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double J_sqr_norm;	// Norm of the constant term in the primal residual
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr, tau_decr;	// Ratio of change for increasing and decreasing penalty weight

	// Index among the solution vector x[i] for each vertex
	// For fixed vertex, this is -1
	std::vector<int> vtx_sol_index;
	std::map<int, MeshPointType> fixed_vtx_displacement;
	int var_vtx_n;

	// Do we use matrix version or vector version of intermediate variables?
	bool use_mat_var;

	double diagonal_dist_bound;


	double initial_func_value, initial_primal_residual_squared_norm;
	double penalty_incr;


	void store_orig_vertex_positions();

	void initialize_stopping_criteria_var();

	void update_H();
	void update_Y();
	void update_W();
	void update_Z();
	void update_dual_var();

	void update_H_mat();
	void weighted_update_H_mat();
	void L0_update_Y_mat();
	void L1_update_Y_mat();
	void weighted_L0_update_Y_mat();
	void weighted_L1_update_Y_mat();
	void update_W_mat();
	void weighted_update_W_mat();
	void update_Z_mat();

	void update_penalty_term();

	void initialize_primal_vars();
	void initialize_solver();
	void initialize_solver_weighted();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_disp_energy_matrix(); // Use 3rd-diff of displacement vectors as energy
	void initialize_var_index();

	void L0_optimize_mat();
	void L1_optimize_mat();
	void L1_penalty_optimize_mat();
	void weighted_L0_optimize_mat();
	void weighted_L1_optimize_mat();
	void update_mesh_vertices_mat(int iter_num);
	void update_mesh_vertices_mat();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	bool dual_var_update_with_stop_check_and_penalty_weight_update_mat();

	bool dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat();

	bool weighted_dual_var_update_with_stop_check_and_penalty_update_mat();

	// Use this between the auxiliary variable update and H update
	void dual_var_half_update_mat();


	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
	void evaluate_diagonal_dist_mat();
	void update_diagonal_dist_histogram(int iter_num);

	bool check_stopping_and_update_penalty(int iter_num);
	void get_initial_value_and_primal_residual();
};


class PQTangentSparseDisp{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, const std::vector< std::vector<double> > &tangent_basis_,
			int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
			double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness_);


	void L1_optimize(std::vector<MeshPointType> &opt_disp);
//	const std::vector<double>& face_rel_diagonal_dist_measure();
//	const std::vector<double>& face_least_squres_dist_measure();

private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;

	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;

	std::vector< std::vector<double> > tangent_basis;

	// Variables used to change penalty weight
	double max_penalty, min_penalty;
	int check_penalty_period;
	double min_residual_change_ratio; // Threshold to determine that the change is small enough

	Eigen::LDLT<Eigen::MatrixXd> solver;
	Eigen::MatrixXd T, Tt;
	Eigen::MatrixXd ET, ETt;

	// Intermediate variables
	Eigen::VectorXd Y_update_tmp_mat;
	Eigen::VectorXd orig_vtx_mat;

	// Matrix version of the above variables
	Eigen::VectorXd D1_mat, D2_mat;
	Eigen::VectorXd W_mat, Y_mat, F_mat, G_mat, H_mat, ETG_mat;
	Eigen::VectorXd prev_H_mat, prev_ETG_mat;
	Eigen::VectorXd primal_residual_mat_1, primal_residual_mat_2;

	double prev_primal_residual_norm;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;
	std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	std::vector<int> free_vtx;	// Array indicating which vertices are free
	int var_vtx_n;


	void store_orig_vertex_positions();

	void initialize_stopping_criteria_var();

	void initialize_tangent_basis_matrix();

	void update_G_mat();
	void L0_update_Y_mat();
	void L1_update_Y_mat();
	void update_W_mat();
	void update_W_mat_with_thresholding();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_var_index();

	void initialize_smoothness_energy_lowerbound();

	void L1_optimize_mat();
	void update_mesh_vertices_mat(int iter_num);
	void update_mesh_vertices_mat();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	bool dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(int iter_num);

	void compute_primal_residual_mat();
	void initialize_primal_residual_norm();
};


class PQTangentSparseDispOpenMP{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, const std::vector< std::vector<double> > &tangent_basis_,
			int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
			double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness_);

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
//	const std::vector<double>& face_rel_diagonal_dist_measure();
//	const std::vector<double>& face_least_squres_dist_measure();



private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;

	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;
	double alpha, last_alpha; 	// Variable for fast ADMM

	std::vector< std::vector<double> > tangent_basis;

	// Variables used to change penalty weight
	double max_penalty, min_penalty;
	int check_penalty_period;
	double min_residual_change_ratio; // Threshold to determine that the change is small enough

	Eigen::LDLT<Eigen::MatrixXd> solver;
	Eigen::MatrixXd T, Tt;
	Eigen::MatrixXd ET, ETt;

	Eigen::VectorXd orig_vtx_mat;

	std::vector<int> free_vtx;	// Array indicating which vertices are free

	Eigen::VectorXd Y_update_tmp, Y;
	Eigen::VectorXd W, F, G;
	Eigen::VectorXd prev_H, H;
	Eigen::VectorXd prev_ETG, ETG;



	// Matrix version of the above variables
	Eigen::VectorXd D1, D2;
	Eigen::VectorXd last_D1, last_D2, D1_t, D2_t, ETG2;	// Variables used for fast ADMM
	Eigen::VectorXd primal_residual_1, primal_residual_2;
	double primal_residual_squared_norm[2];
	double single_dual_residual_squared_norm[2];
	double prev_primal_residual_norm;
	double penalty_incr_dual_residual_max_ratio;	// Max ratio between dual and primal residual norm that allows incrementing penalty weight
	bool optimization_end, need_incr_penalty;
	bool restart_fastadmm;
	double last_primal_residual_norm, last_dual_residual_norm;	// Variables for Fast ADMM

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;

	int var_vtx_n;


	void store_orig_vertex_positions();
	void initialize_stopping_criteria_var();
	void initialize_tangent_basis_matrix();
	void update_G();
	void L1_update_Y();
	void update_W();
	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_var_index();
	void initialize_smoothness_energy_lowerbound();

	void L1_optimize();
	void update_mesh_vertices(int iter_num);
	void update_mesh_vertices();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num);

	void compute_primal_residual();
	void initialize_primal_residual_norm();
};

// Optimization with input displacement as soft constraint or as a costraint in the Lagrange multiplier term
class PQSparseDispSoftCon{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double tau_incr_, bool threshold_smoothness_, double vtx_disp_weight_, bool soft_vtx_disp_constraint_);

	void set_histogram(MeshHistogram *histogram_);
	void set_diagonal_dist_bound(double val){
		diagonal_dist_bound = val;
	}

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
	void L0_optimize(std::vector<MeshPointType> &opt_disp);
	const std::vector<double>& face_rel_diagonal_dist_measure();
	const std::vector<double>& face_least_squres_dist_measure();

private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	std::vector< MeshPointType > orig_vtx_pos;

	bool update_histogram;
	MeshHistogram *histogram;

	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	bool soft_vtx_disp_constraint;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;

	// Variables used to change penalty weight
	double max_penalty;
	int check_penalty_period;
	double min_residual_change_ratio; // Threshold to determine that the change is small enough

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Ct, C;
	SparseMatrixXd Et, E;

	// Intermediate variables
	Eigen::MatrixXd Z_update_tmp_pts;
	Eigen::MatrixXd Y_update_tmp_mat;
	Eigen::MatrixXd orig_vtx_mat;

	// Matrix version of the above variables
	Eigen::MatrixXd D1_mat, D2_mat, D3_mat;
	Eigen::MatrixXd W_mat, H_mat, K_mat, Y_mat, F_mat, Z_mat;
	Eigen::MatrixXd prev_H_mat, H_mat_diff;  // store previous H value for computing dual residual
	Eigen::MatrixXd prev_Z_mat, prev_Y_mat, prev_W_mat;
	Eigen::MatrixXd Z_mat_diff, Y_mat_diff, W_mat_diff;
	Eigen::MatrixXd dual_residual_mat;
	Eigen::MatrixXd primal_residual_mat_1, primal_residual_mat_2, primal_residual_mat_3;

	double prev_primal_residual_norm;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double J_sqr_norm;	// Norm of the constant term in the primal residual
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr, tau_decr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;
	std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	std::vector<int> free_vtx;	// Array indicating which vertices are free
	int var_vtx_n;

	// Do we use matrix version or vector version of intermediate variables?
	bool use_mat_var;
	double diagonal_dist_bound;

	double initial_func_value;
	double penalty_incr;

	void store_orig_vertex_positions();
	void initialize_stopping_criteria_var();

	void update_H_mat();
	void L0_update_Y_mat();
	void L1_update_Y_mat();
	void update_W_mat();
	void update_W_mat_with_thresholding();
	void update_Z_mat();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_disp_2nddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_var_index();

	void initialize_smoothness_energy_lowerbound();

	void L0_optimize_mat();
	void L1_optimize_mat();
	void update_mesh_vertices_mat(int iter_num);
	void update_mesh_vertices_mat();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	bool dual_var_update_with_stop_check_and_penalty_weight_update_mat(int iter_num);
	bool dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(int iter_num);

	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
	void evaluate_diagonal_dist_mat();
	void evaluate_least_squares_dist_mat();
	void update_diagonal_dist_histogram(int iter_num);
	void compute_primal_residual_mat();
	void initialize_primal_residual_norm();

	void check_centered_matrix();
	void check_2nddiff_disp_energy_matrix(const std::vector< std::vector<int> > &idx);
	void check_3rddiff_disp_energy_matrix(const std::vector< std::vector<int> > &idx);
	void update_Y_soft_constrained_component(int idx);
};


class PQTangentDispNormalConstraint{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	void initialize_variables(OpenMeshNode *mesh_, const SparseMatrixXd &normal_basis,
			int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
			double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness_);

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
//	const std::vector<double>& face_rel_diagonal_dist_measure();
//	const std::vector<double>& face_least_squres_dist_measure();

private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;

	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;
	double alpha, last_alpha; 	// Variable for fast ADMM

	// Variables used to change penalty weight
	double max_penalty, min_penalty;
	int check_penalty_period;
	double min_residual_change_ratio; // Threshold to determine that the change is small enough

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Nb, Nbt;
	SparseMatrixXd E, Et;

	Eigen::VectorXd orig_vtx_pos, orig_vtx_pos_v[3], new_vtx_pos[3];

	std::vector<int> free_vtx;	// Array indicating which vertices are free

	Eigen::VectorXd Y_update_tmp, Y;
	Eigen::VectorXd W_update_tmp, W, F;
	Eigen::VectorXd prev_H, H, prev_EH, EH;


	// Matrix version of the above variables
	Eigen::VectorXd D1, D2, D3;
	Eigen::VectorXd last_D1, last_D2, last_D3, D1_t, D2_t, D3_t;	// Variables used for fast ADMM
	Eigen::VectorXd primal_residual_1, primal_residual_2, primal_residual_3;
	double primal_residual_squared_norm[3];
	double single_dual_residual_squared_norm[2];	// The dual residual norm only has two parts
	double prev_primal_residual_norm;
	double penalty_incr_dual_residual_max_ratio;	// Max ratio between dual and primal residual norm that allows incrementing penalty weight
	bool optimization_end, need_incr_penalty;
	bool restart_fastadmm;
	double last_primal_residual_norm, last_dual_residual_norm;	// Variables for Fast ADMM


	// Data for computing projection onto PQ mesh manifold using ADMM
	// We split the data into three arrays for parallelism
//	Eigen::VectorXd D1v[3], D2v[3], D3v[3];
//	Eigen::VectorXd Wv[3], Hv[3], Kv[3], Yv[3], Fv[3], Zv[3];
//	Eigen::VectorXd prev_Hv[3], Hv_diff[3];
//	SparseMatrixXd Ev, Evt;
//	SparseMatrixXd C, Ct;
//	Eigen::VectorXd primal_residualv_1[3], primal_residualv_2[3], primal_residualv_3[3];
//	Eigen::VectorXd Zv_update_tmp[3], Yv_update_tmp[3], Wv_update_tmp[3];
//	double primal_residual_squared_norm_v[3];
//	double single_dual_residual_squared_norm_v[3];
//	double prev_primal_residual_norm_v;
//	Eigen::SimplicialLDLT<SparseMatrixXd> solver2;
//	Eigen::Matrix<double, 4, 4> C43;


	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;

	int var_vtx_n;


	void store_orig_vertex_positions();
	void initialize_stopping_criteria_var();
	//void update_G();
	void update_H();
	void L1_update_Y();
	void update_W();
	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_disp_2nddiff_energy_matrix();
	void initialize_var_index();
	void initialize_smoothness_energy_lowerbound();

	void L1_optimize();
	void update_mesh_vertices(int iter_num);
	void update_mesh_vertices();
//	void initialize_centered_matrix();
//	void update_Zv();
//	void update_Wv();
//	void update_Hv();
//	void L1_update_Yv();
//	void update_Wv_with_thresholding();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num);

	void compute_primal_residual();
	void initialize_prev_residual_norm();
};

class PQSparseDispSoftConstraint{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW


	PQSparseDispSoftConstraint():var_initialized(false), optimization_converge(true){}

	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double tau_incr_, bool threshold_smoothness_, int max_iter, bool diff_vec_planarity);

	// Initialize solver and set primal/dual variables to zero, but leave input displacements unspecified
	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::vector<int> &constrained_vtx_index,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
			double ep_abs_, double ep_rel_, double tau_incr_, int max_iteartion_, bool threshold_smoothness_);

	// Use the current primal and dual variables as initial value, compute new solution according to given displacements
	void threaded_L1_optimize(const std::map<int, MeshPointType> &fixed_vtx_disp, std::vector<MeshPointType> &opt_disp);



	bool optimization_convergent(){
		return optimization_converge;
	}

//	void set_histogram(MeshHistogram *histogram_);
//	void set_diagonal_dist_bound(double val){
//		diagonal_dist_bound = val;
//	}

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
	const std::vector<double>& face_rel_diagonal_dist_measure();
	const std::vector<double>& face_least_squres_dist_measure();


	// Use this method to initialize some data members
	void reset_data(const std::vector<MeshPointType> &init_disp);

private:

	void threaded_L1_optimize(std::vector<MeshPointType> &opt_disp);

	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	Eigen::VectorXd orig_vtx_pos[3], new_vtx_pos[3];

	bool update_histogram;
	MeshHistogram *histogram;

	double penalty_weight;
	double orig_penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	bool difference_vec_planarity;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;
	double var_initialized;

	// Variables used to change penalty weight
	double max_penalty;
	int check_penalty_period;
	double min_residual_change_ratio; // Threshold to determine that the change is small enough
	double W_update_factor;
	bool optimization_end;	// flags indicating end of optimization, either due to max number of iteration or due to convergence of the iteration
	bool need_incr_penalty;

	bool optimization_converge;
	int max_iteration;

	// All input displacements wait in this queue
	std::vector< std::map<int, MeshPointType> > input_disp_queue;

	boost::mutex mutex_optimization;
	boost::mutex mutex_input_disp;

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Ct, C;
	SparseMatrixXd Et, E;

	Eigen::Matrix<double, 4, 4> C43; // The mean-centering matrix for a 4x3 matrix representing four 3d vectors

	// Intermediate variables
	Eigen::VectorXd Z_update_tmp[3];
	Eigen::VectorXd Y_update_tmp[3];
	Eigen::VectorXd W_update_tmp[3];

	// Matrix version of the above variables
	Eigen::VectorXd D1[3], D2[3], D3[3];
	Eigen::VectorXd W[3], H[3], K[3], Y[3], F[3], Z[3];
	Eigen::VectorXd prev_H[3], H_diff[3];  // store previous H value for computing dual residual
	Eigen::VectorXd dual_residual[3];
	Eigen::VectorXd primal_residual_1[3], primal_residual_2[3], primal_residual_3[3];
	double dual_var_squared_norm[3];	// temporary storage for squared norm of scaled dual variables

	// Temporary storage for primal residual squared-norm in each component
	double primal_residual_squared_norm[3], dual_residual_squared_norm[3];

	double prev_primal_residual_norm;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double J_sqr_norm;	// Norm of the constant term in the primal residual
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda, lambda2; // Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr, tau_decr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;
	//std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	std::vector<int> free_vtx;	// Array indicating which vertices are free
	int var_vtx_n;
	int face_n; // the number of faces, will be 1/4 of the number of rows of C
	std::vector< std::vector<int> > face_vtx_idx;

	double diagonal_dist_bound;

	double initial_func_value;
	double penalty_incr;



	void store_orig_vertex_positions();
	void initialize_stopping_criteria_var();

	void update_H();
	void L1_update_Y();
	void update_W();
	void update_W_with_thresholding();
	void update_Z();
	void update_Z_diffvec();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_diffvec_matrix();
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_disp_2nddiff_energy_matrix();
	void initialize_var_index();

	void initialize_smoothness_energy_lowerbound();
	void L1_optimize_unbounded_smoothness();
	void L1_optimize_bounded_smoothness();
	void L1_optimize_unbounded_smoothness_diffvec();
	void L1_optimize_bounded_smoothness_diffvec();
	void update_mesh_vertices(int iter_num);
	void update_mesh_vertices();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num);

	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
	void update_diagonal_dist_histogram(int iter_num);
	void initialize_primal_residual_norm();
};

class PQSparseDispViaTangentSpace{

	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, const SparseMatrixXd &normal_basis, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double tau_incr_, bool threshold_smoothness_, int max_iter);

	void L1_optimize(std::vector<MeshPointType> &tangent_disp, std::vector<MeshPointType> &final_disp);

private:
	PQTangentDispNormalConstraint tangent_disp_admm;
	PQSparseDispSoftConstraint sparse_disp_admm;
};


// Implementation using vertex coordinates as columns of some data matrix, possibly improving cache efficiency
class PQSparseDispSoftConRowMajor{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double tau_incr_, bool threshold_smoothness_, bool diff_vec_planarity);

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
	const std::vector<double>& face_rel_diagonal_dist_measure();
	const std::vector<double>& face_least_squres_dist_measure();

private:

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Ct, C;
	SparseMatrixXd Et, E;


	Eigen::MatrixXd Z_update_tmp, Z;
	Eigen::MatrixXd Y_update_tmp, Y;
	Eigen::MatrixXd W_update_tmp, W;

	Eigen::MatrixXd H, prev_H, H_diff, K, F;

	Eigen::MatrixXd orig_vtx_pos, new_vtx_pos;

	Eigen::MatrixXd D1, D2, D3;
	Eigen::MatrixXd primal_residual_1, primal_residual_2, primal_residual_3;
	Eigen::MatrixXd dual_residual;



	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;



	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	bool difference_vec_planarity;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;

	// Variables used to change penalty weight
	double max_penalty, min_penalty;
	int check_penalty_period;
	double min_residual_change_ratio; // Threshold to determine that the change is small enough
	double W_update_factor;
	bool optimization_end;	// flags indicating end of optimization
	bool need_change_penalty;
	double penalty_change_ratio;



	Eigen::Matrix<double, 4, 4> C43; // The mean-centering matrix for a 4x3 matrix representing four 3d vectors


	// Temporary storage for primal residual squared-norm in each component
	double primal_residual_squared_norm[3], dual_residual_squared_norm[3];


	double single_dual_residual_norm;	// Keep track of the current dual residual norm

	double prev_primal_residual_norm;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double J_sqr_norm;	// Norm of the constant term in the primal residual
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr, tau_decr;	// Ratio of change for increasing and decreasing penalty weight

	std::map<int, MeshPointType> fixed_vtx_displacement;
	std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	std::vector<int> free_vtx;	// Array indicating which vertices are free
	int var_vtx_n;
	int face_n; // the number of faces, will be 1/4 of the number of rows of C
	std::vector< std::vector<int> > face_vtx_idx;

	double diagonal_dist_bound;

	double initial_func_value;
	double penalty_incr;

	void store_orig_vertex_positions();
	void initialize_stopping_criteria_var();

	void update_H();
	void L1_update_Y();
	void update_W();
	void update_W_with_thresholding();
	void update_Z();
	void update_Z_diffvec();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_diffvec_matrix();
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_var_index();

	void initialize_smoothness_energy_lowerbound();
	void L1_optimize_unbounded_smoothness();
	void L1_optimize_bounded_smoothness();
	void L1_optimize_unbounded_smoothness_diffvec();
	void L1_optimize_bounded_smoothness_diffvec();
	void update_mesh_vertices(int iter_num);
	void update_mesh_vertices();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void dual_var_update_with_stop_check_and_penalty_weight_update(int iter_num);

	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
	void update_diagonal_dist_histogram(int iter_num);
	void initialize_primal_residual_norm();
};

class PQSparseDispADMM2ndDiffEnergy{

	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double ep_abs_,
			double ep_rel_, double tau_incr_, bool use_mat_var_ = true);

	void set_histogram(MeshHistogram *histogram_);
	void set_diagonal_dist_bound(double val){
		diagonal_dist_bound = val;
	}

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
	const std::vector<double>& face_diagonal_dist_measure();

private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	std::vector< MeshPointType > orig_vtx_pos;

	bool update_histogram;
	MeshHistogram *histogram;

	double penalty_weight;
	double sparsity_weight;
	double smoothness_weight;

	// Variables used to change penalty weight
	double max_penalty;
	int check_penalty_period;
	double residual_change_ratio;

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Ct, C;
	SparseMatrixXd Et, E;

	Eigen::VectorXd D1[3], D2[3], D3[3];
	Eigen::VectorXd W[3];
	Eigen::VectorXd H[3];
	Eigen::VectorXd prev_H[3]; // store previous H value for computing dual residual
	Eigen::VectorXd K[3], Y[3], F[3], Z[3];
	Eigen::VectorXd primal_residual_1[3], primal_residual_2[3], primal_residual_3[3];

	// Intermediate variables
	Eigen::MatrixXd Z_update_tmp_pts;
	Eigen::MatrixXd Y_update_tmp_mat;

	// Matrix version of the above variables
	Eigen::MatrixXd D1_mat, D2_mat, D3_mat;
	Eigen::MatrixXd W_mat, H_mat, K_mat, Y_mat, F_mat, Z_mat;
	Eigen::MatrixXd prev_H_mat;  // store previous H value for computing dual residual
	Eigen::MatrixXd prev_Z_mat, prev_Y_mat, prev_W_mat;
	Eigen::MatrixXd Z_mat_diff, Y_mat_diff, W_mat_diff;
	Eigen::MatrixXd dual_residual_mat;
	Eigen::MatrixXd primal_residual_mat_1, primal_residual_mat_2, primal_residual_mat_3;

	double prev_primal_residual_norm;

	// Threshold to determine that the change is small enough
	double min_change_threshold;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double J_sqr_norm;	// Norm of the constant term in the primal residual
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Intermediate variables related to changing penalty weight
	double lambda;	// Threshold ratio between primal and dual residual norm to change penalty weight
	double tau_incr, tau_decr;	// Ratio of change for increasing and decreasing penalty weight

	// Index among the solution vector x[i] for each vertex
	// For fixed vertex, this is -1
	std::vector<int> vtx_sol_index;
	std::map<int, MeshPointType> fixed_vtx_displacement;
	int var_vtx_n;

	// Do we use matrix version or vector version of intermediate variables?
	bool use_mat_var;

	double diagonal_dist_bound;


	double initial_func_value, initial_primal_residual_squared_norm;
	double penalty_incr;


	void store_orig_vertex_positions();

	void initialize_stopping_criteria_var();

	void update_H_mat();
	void L0_update_Y_mat();
	void L1_update_Y_mat();
	void update_W_mat();
	void update_Z_mat();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_disp_2nddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_var_index();

	void L0_optimize_mat();
	void L1_optimize_mat();
	void update_mesh_vertices_mat(int iter_num);
	void update_mesh_vertices_mat();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	bool dual_var_update_with_stop_check_and_penalty_weight_update_mat(int iter_num);

	bool dual_var_update_with_stop_check_and_penalty_weight_update_reverse_order_mat(int iter_num);


	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
	void evaluate_diagonal_dist_mat();
	void evaluate_least_squares_dist_mat();
	void update_diagonal_dist_histogram(int iter_num);
	void compute_primal_residual_mat();
	void initialize_primal_residual_norm();

	void check_centered_matrix();
	void check_2nddiff_disp_energy_matrix(const std::vector< std::vector<int> > &idx);
	void check_3rddiff_disp_energy_matrix(const std::vector< std::vector<int> > &idx);
};

/*
 * The ADMM class does not separate the variable for energy function.
 * As a result, there are fewer variables but we cannot change the penalty weight
 */
class PQSparseDispADMM{

	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	void initialize_variables(OpenMeshNode *mesh_, int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double penalty_weight_, double ep_abs_,
			double ep_rel_,bool use_mat_var_);

	void L0_optimize(std::vector<MeshPointType> &opt_disp);
	void L1_optimize(std::vector<MeshPointType> &opt_disp);

private:
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	std::vector< MeshPointType > orig_vtx_pos;

	double penalty_weight_Y;
	double penalty_weight_Z;
	double sparsity_weight;
	double smoothness_weight;

	Eigen::SimplicialLDLT<SparseMatrixXd> solver;
	SparseMatrixXd Ct, C;
	SparseMatrixXd Et, E;

	Eigen::VectorXd D1[3], D2[3];
	Eigen::VectorXd H[3];
	Eigen::VectorXd prev_H[3]; // store previous H value for computing change of variables
	Eigen::VectorXd K[3], Y[3], F[3], Z[3];
	Eigen::VectorXd primal_residual_1[3], primal_residual_2[3];

	// Intermediate variables
	Eigen::MatrixXd Z_update_tmp_pts;
	Eigen::MatrixXd Y_update_tmp_mat;

	// Matrix version of the above variables
	Eigen::MatrixXd D1_mat, D2_mat;
	Eigen::MatrixXd H_mat, K_mat, Y_mat, F_mat, Z_mat;
	Eigen::MatrixXd prev_H_mat;  // store previous H value for computing change of variables
	Eigen::MatrixXd primal_residual_mat_1, primal_residual_mat_2;

	// Intermediate variables related to stopping criteria
	double ep_abs, ep_rel;	// Absolute and relative minimum change ratio
	double J_sqr_norm;	// Norm of the constant term in the primal residual
	double primal_ep_abs, dual_ep_abs; 	// The portion of absolute epsilon for primal and dual residuals


	// Index among the solution vector x[i] for each vertex
	// For fixed vertex, this is -1
	std::vector<int> vtx_sol_index;
	std::map<int, MeshPointType> fixed_vtx_displacement;
	int var_vtx_n;

	// Do we use matrix version or vector version of intermediate variables?
	bool use_mat_var;


	void store_orig_vertex_positions();

	void initialize_stopping_criteria_var();

	void update_H();
	void update_Y();
	void update_Z();
	void update_dual_var();

	void update_H_mat();
	void L0_update_Y_mat();
	void L1_update_Y_mat();
	void update_Z_mat();
	void update_dual_var_mat();

	void update_penalty_term();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_disp_energy_matrix(); // Use 3rd-diff of displacement vectors as energy
	void initialize_var_index();

	void L0_optimize_mat();
	void L1_optimize_mat();
	void update_mesh_vertices_mat(int iter_num);
	void update_mesh_vertices_mat();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	bool dual_var_update_with_stop_check_and_penalty_weight_update_mat();
};

}}

#endif /* PQSPARSEDISPADMM_H_ */
