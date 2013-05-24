/*
 * SparseDispADMM.h
 *
 *  Created on: Sep 1, 2012
 *      Author: Bailin Deng
 */

#ifndef SPARSEDISPADMM_H_
#define SPARSEDISPADMM_H_

#include "ConstrainedMeshPluginTypedef.h"
#include <vector>
#include <map>
#include <boost/thread/mutex.hpp>
#include <string>
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


// Augmented Lagrangian method for computing sparse displacement on PQ mesh,
// using Eigen as linear algebra library
class SparseDispAugLag_PQ_Eigen{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	void initialize_variables(OpenMeshNode *mesh_,
							  int update_period_,
							  int nb_threads,
							  const std::map<int, MeshPointType> &fixed_vtx_disp,
							  double sparsity_weight_,
							  double smoothness_weight_,
							  double vtx_disp_weight_,
							  double init_penalty_weight_,
							  double eps_val_,
							  double init_dual_eps_val,
							  double tau_incr_,
							  bool use_2nddiff,
							  bool threshold_smoothness_,
							  bool use_diffvec,
							  int max_iter, int primal_max_iter);

	void L1_optimize(std::vector<MeshPointType> &opt_disp);

	// Use this method to initialize some data members
	void reset_data(const std::vector<MeshPointType> &init_disp);

protected:

	//void threaded_L1_optimize(std::vector<MeshPointType> &opt_disp);
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	Eigen::VectorXd orig_vtx_pos[3], new_vtx_pos[3];

	double penalty_weight;
	double orig_penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;
	bool diffvec_planarity;

	// Variables used to change penalty weight
	double max_penalty;
	double W_update_factor;
	bool optimization_end;	// flags indicating end of optimization, either due to max number of iteration or due to convergence of the iteration
	bool need_incr_penalty;
	bool primal_subproblem_converge;

	bool optimization_converge;
	int max_iteration;
	int nb_threads;

	// All input displacements wait in this queue
	//std::vector< std::map<int, MeshPointType> > input_disp_queue;

	//boost::mutex mutex_optimization;
	//boost::mutex mutex_input_disp;

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
	Eigen::VectorXd primal_residual_1[3], primal_residual_2[3], primal_residual_3[3];
	Eigen::VectorXd primal_residual_1_inf_norm[3], primal_residual_2_inf_norm[3], primal_residual_3_inf_norm[3];

	// Temporary storage for primal residual squared-norm in each component
	double primal_residual_squared_norm[3], dual_residual_squared_norm[3], dual_residual_total_sqr_norm;

	// Dimension of the primal and dual residual. We need this to normalized the primal and dual residual
	int primal_residual_dim, dual_residual_dim;

	// Primal and dual residual norms
	double prev_outer_primal_residual_sqr_norm;
	//double prev_outer_iter_dual_residual_norm;
	//double prev_outer_iter_primal_residual_inf_norm;


	double eps_val;	// Epsilon value for defining norm related tolerances
	double init_dual_eps_val;

	// We use squared-norm instead of L2 norm to represent thresholds, so that we don't need to do sqrt
	double primal_squared_norm_eps, final_dual_squared_norm_eps, cur_dual_squared_norm_eps;

	// The starting iteration number count for the current primal problem
	int current_primal_run_start_iter, primal_subproblem_maxiter;

	// Intermediate variables related to changing penalty weight
	double lambda_primal2dual_sqr, lambda_dual2primal_sqr; // Threshold ratio between primal and dual residual norms
	double tau_incr;	// Ratio of change for increasing penalty weight
	double dual_sqaured_norm_eps_decr_ratio;	// Ratio of decreasing dual squared residual norm
	double scaled_dual_change_ratio;	// Reciprocal of the penalty increase ratio
	double min_sqr_primal_residual_change_ratio;


	std::map<int, MeshPointType> fixed_vtx_displacement;
	//std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	std::vector<int> free_vtx;	// Array indicating which vertices are free
	int var_vtx_n, face_n; // the number of faces, will be 1/4 of the number of rows of C
	std::vector< std::vector<int> > face_vtx_idx;
	std::vector< int > free_vtx_idx;
	std::vector< int > fixed_vtx_idx;
	std::vector< MeshPointType > fixed_vtx_target;


	#ifdef DEBUG_RESIDUAL
	// Data structure for debugging
	Eigen::VectorXd prev_Y_residual, new_Y_residual;
	Eigen::VectorXd prev_Z_residual, new_Z_residual;
	double prev_W_residual, new_W_residual;
	int Y_residual_dim, Z_residual_dim;
	void init_aux_var_debug_data(){
		Y_residual_dim = Y[0].rows();
		Z_residual_dim = face_n;
		prev_Y_residual.resize(Y_residual_dim);
		new_Y_residual.resize(Y_residual_dim);
		prev_Z_residual.resize(Z_residual_dim);
		new_Z_residual.resize(Z_residual_dim);
	}

	void compute_Y_residual(Eigen::VectorXd &residual_vec);
	void compute_Z_residual(Eigen::VectorXd &residual_vec);
	void compute_W_residual(double &residual_val);
	void check_decreasing_value(const Eigen::VectorXd &prev_val, const Eigen::VectorXd &new_val, const std::string &name);
	void check_decreasing_value(double prev_val, double new_val, const std::string &name);
	#endif



	void copydatafromhost2device();
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
	void L1_optimize_unbounded_smoothness_diffvec_planarity();
	void L1_optimize_bounded_smoothness_diffvec_planarity();
	void update_mesh_vertices(int iter_num);
	void update_mesh_vertices();

	void compute_primal_update_aux_var();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void stop_check_and_dual_var_penalty_weight_update(int iter_num);

//	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
//	void update_diagonal_dist_histogram(int iter_num);
	void initialize_primal_residual_norm(){
		//this->prev_outer_primal_residual_sqr_norm = 1e10;
		this->prev_outer_primal_residual_sqr_norm = 0;
	}

	//label
	void update_aux_primal_variables(){
		compute_primal_update_aux_var();
		update_W();
		update_Z();
		L1_update_Y();
	}

	//label
	void update_aux_primal_variables_with_faring_threshold(){
		compute_primal_update_aux_var();
		update_W_with_thresholding();
		update_Z();
		L1_update_Y();
	}

	//label
	void update_aux_primal_variables_diffvec(){
		compute_primal_update_aux_var();
		update_W();
		update_Z_diffvec();
		L1_update_Y();
	}

	//label
	void update_aux_primal_variables_with_faring_threshold_diffvec(){
		compute_primal_update_aux_var();
		update_W_with_thresholding();
		update_Z_diffvec();
		L1_update_Y();
	}
};



class Planarization_PQ_Eigen{
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	void initialize_variables(OpenMeshNode *mesh_, int update_period_, int nb_threads, const std::map<int, MeshPointType> &fixed_vtx_disp,
			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double eps_val_,
			double init_dual_eps_val, double tau_incr_, bool use_2nddiff, bool threshold_smoothness_, int max_iter, int primal_max_iter);

	void L1_optimize(std::vector<MeshPointType> &opt_disp);

	// Use this method to initialize some data members
	void reset_data(const std::vector<MeshPointType> &init_disp);

protected:

	//void threaded_L1_optimize(std::vector<MeshPointType> &opt_disp);
	OpenMeshNode *mesh;
	PolyMeshType *pmesh;

	bool update_mesh;
	int update_period;
	Eigen::VectorXd orig_vtx_pos[3], new_vtx_pos[3];

	double penalty_weight;
	double orig_penalty_weight;
	double sparsity_weight;
	double smoothness_weight;
	double vtx_disp_weight;
	bool threshold_smoothness;
	double smoothness_energy_bound;
	double smoothness_energy_bound_sqrt;

	// Variables used to change penalty weight
	double max_penalty;
	double W_update_factor;
	bool optimization_end;	// flags indicating end of optimization, either due to max number of iteration or due to convergence of the iteration
	bool need_incr_penalty;
	bool primal_subproblem_converge;

	bool optimization_converge;
	int max_iteration;
	int nb_threads;

	// All input displacements wait in this queue
	//std::vector< std::map<int, MeshPointType> > input_disp_queue;

	//boost::mutex mutex_optimization;
	//boost::mutex mutex_input_disp;

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
	Eigen::VectorXd primal_residual_1[3], primal_residual_2[3], primal_residual_3[3];
	Eigen::VectorXd primal_residual_1_inf_norm[3], primal_residual_2_inf_norm[3], primal_residual_3_inf_norm[3];

	// Temporary storage for primal residual squared-norm in each component
	double primal_residual_squared_norm[3], dual_residual_squared_norm[3], dual_residual_total_sqr_norm;

	// Dimension of the primal and dual residual. We need this to normalized the primal and dual residual
	int primal_residual_dim, dual_residual_dim;

	// Primal and dual residual norms
	double prev_outer_primal_residual_sqr_norm;
	//double prev_outer_iter_dual_residual_norm;
	//double prev_outer_iter_primal_residual_inf_norm;


	double eps_val;	// Epsilon value for defining norm related tolerances
	double init_dual_eps_val;

	// We use squared-norm instead of L2 norm to represent thresholds, so that we don't need to do sqrt
	double primal_squared_norm_eps, final_dual_squared_norm_eps, cur_dual_squared_norm_eps;

	// The starting iteration number count for the current primal problem
	int current_primal_run_start_iter, primal_subproblem_maxiter;

	// Intermediate variables related to changing penalty weight
	double lambda_primal2dual_sqr, lambda_dual2primal_sqr; // Threshold ratio between primal and dual residual norms
	double tau_incr;	// Ratio of change for increasing penalty weight
	double dual_sqaured_norm_eps_decr_ratio;	// Ratio of decreasing dual squared residual norm
	double scaled_dual_change_ratio;	// Reciprocal of the penalty increase ratio
	double min_sqr_primal_residual_change_ratio;


	std::map<int, MeshPointType> fixed_vtx_displacement;
	//std::vector< std::pair<int, MeshPointType> > fixed_vtx_disp_array;	// Use array to allow fast access to the input displacement information
	std::vector<int> free_vtx;	// Array indicating which vertices are free
	int var_vtx_n, face_n; // the number of faces, will be 1/4 of the number of rows of C
	std::vector< std::vector<int> > face_vtx_idx;
	std::vector< int > free_vtx_idx;
	std::vector< int > fixed_vtx_idx;
	std::vector< MeshPointType > fixed_vtx_target;


	#ifdef DEBUG_RESIDUAL
	// Data structure for debugging
	Eigen::VectorXd prev_Y_residual, new_Y_residual;
	Eigen::VectorXd prev_Z_residual, new_Z_residual;
	double prev_W_residual, new_W_residual;
	int Y_residual_dim, Z_residual_dim;
	void init_aux_var_debug_data(){
		Y_residual_dim = Y[0].rows();
		Z_residual_dim = face_n;
		prev_Y_residual.resize(Y_residual_dim);
		new_Y_residual.resize(Y_residual_dim);
		prev_Z_residual.resize(Z_residual_dim);
		new_Z_residual.resize(Z_residual_dim);
	}

	void compute_Y_residual(Eigen::VectorXd &residual_vec);
	void compute_Z_residual(Eigen::VectorXd &residual_vec);
	void compute_W_residual(double &residual_val);
	void check_decreasing_value(const Eigen::VectorXd &prev_val, const Eigen::VectorXd &new_val, const std::string &name);
	void check_decreasing_value(double prev_val, double new_val, const std::string &name);
	#endif



	void store_orig_vertex_positions();
	void initialize_stopping_criteria_var();

	void update_H();
	void L1_update_Y();
	void update_W();
	void update_W_with_thresholding();
	void update_Z();

	void initialize_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void initialize_centered_matrix();
	void initialize_disp_3rddiff_energy_matrix(); // Use 2nd-diff of displacement vectors as energy
	void initialize_disp_2nddiff_energy_matrix();
	void initialize_var_index();

	void initialize_smoothness_energy_lowerbound();
	void L1_optimize_unbounded_smoothness();
	void L1_optimize_bounded_smoothness();
	void update_mesh_vertices(int iter_num);
	void update_mesh_vertices();

	void compute_primal_update_aux_var();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void stop_check_and_dual_var_penalty_weight_update(int iter_num);

//	std::vector<double> face_diagonal_dist;	// Distance between diagonals for a quad
//	void update_diagonal_dist_histogram(int iter_num);
	void initialize_primal_residual_norm(){
		//this->prev_outer_primal_residual_sqr_norm = 1e10;
		this->prev_outer_primal_residual_sqr_norm = 0;
	}

	void update_aux_primal_variables(){
		compute_primal_update_aux_var();
		update_W();
		update_Z();
		L1_update_Y();
	}

	void update_aux_primal_variables_with_faring_threshold(){
		compute_primal_update_aux_var();
		update_W_with_thresholding();
		update_Z();
		L1_update_Y();
	}
};

}}

#endif /* SPARSEDISPADMM_H_ */
