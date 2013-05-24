#ifndef PQSPARSEDISPADMMGPU_H_
#define PQSPARSEDISPADMMGPU_H_

#include "ConstrainedMeshPluginTypedef.h"
#include <vector>
#include <map>
#include <boost/thread/mutex.hpp>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <vector>
#include <map>

class PQTangentDispNormalConstraint
{
	typedef std::vector<double> MeshPointType;
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		void initialize_variables(OpenMeshNode *mesh_, const SparseMatrixXd &normal_basis,
		int update_period_, const std::map<int, MeshPointType> &fixed_vtx_disp,
		double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness_);

	void copydatafromhost2device(double& cudapenalty_weight, double& cudasparsity_weight, double& cudasmoothness_weight, double& cudavtx_disp_weight, bool& cudathreshold_smoothness, double& cudasmoothness_energy_bound, double& cudasmoothness_energy_bound_sqrt, double& cudaalpha, double& cudalast_alpha, double& cudamax_penalty, double& cudamin_penalty, int& cudacheck_penalty_period, double& cudamin_residual_change_ratio,	cusp::coo_matrix<int, double, cusp::device_memory>& cudaNb, cusp::coo_matrix<int, double, cusp::device_memory>& cudaNbt,	cusp::coo_matrix<int, double, cusp::device_memory>& cudaE, cusp::coo_matrix<int, double, cusp::device_memory>& cudaEt,					cusp::array2d<double, cusp::device_memory>& cudaorig_vtx_pos,
								 cusp::array2d<double, cusp::device_memory>*& cudaorig_vtx_pos_v, cusp::array2d<double, cusp::device_memory>*& cudanew_vtx_pos, cusp::array2d<double, cusp::device_memory>& cudavertexPositions,	cusp::array1d<int, cusp::device_memory>& cudafree_vtx,	cusp::array2d<double, cusp::device_memory>& cudaY_update_tmp, cusp::array2d<double, cusp::device_memory>& cudaY, cusp::array2d<double, cusp::device_memory>& cudaW_update_tmp, cusp::array2d<double, cusp::device_memory>& cudaW, cusp::array2d<double, cusp::device_memory>& cudaF, cusp::array2d<double, cusp::device_memory>& cudaprev_H, cusp::array2d<double, cusp::device_memory>& cudaH, cusp::array2d<double, cusp::device_memory>& cudaprev_EH, cusp::array2d<double, cusp::device_memory>& cudaEH, cusp::array2d<double>& cudaD1, cusp::array2d<double>& cudaD2, cusp::array2d<double>& cudaD3, cusp::array2d<double>& cudalast_D1, cusp::array2d<double>& cudalast_D2, cusp::array2d<double>& cudalast_D3, cusp::array2d<double>& cudaD1_t, cusp::array2d<double>& cudaD2_t, cusp::array2d<double>& cudaD3_t,	cusp::array2d<double>& cudaprimal_residual_1, cusp::array2d<double>& cudaprimal_residual_2, cusp::array2d<double>& cudaprimal_residual_3, double& cudaprimal_residual_squared_norm[3], double& cudasingle_dual_residual_squared_norm[2], double& cudaprev_primal_residual_norm, double& cudapenalty_incr_dual_residual_max_ratio, bool& cudaoptimization_end, bool& cudaneed_incr_penalty, bool& cudarestart_fastadmm, double& cudalast_primal_residual_norm, bool& cudalast_dual_residual_norm, double& cudaep_abs, double& cudaep_rel, double& cudaprimal_ep_abs, double& cudadual_ep_abs, double& cudalambda, double& cudatau_incr,	std::map<int, MeshPointType>& fixed_vtx_displacement, int& cudavar_vtx_n, cusp::coo_matrix<int, double, cusp::device_memory>& cudasparseCoeffMatrix);

	void L1_optimize(std::vector<MeshPointType> &opt_disp);
	//	const std::vector<double>& face_rel_diagonal_dist_measure();
	//	const std::vector<double>& face_least_squres_dist_measure();

private:
	std::vector<MeshPointType> vertexPositions;
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

class PQSparseDispSoftConstraint
{
	typedef std::vector<double> MeshPointType;
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
