/*
 * ConstrainedMeshPlugin.h
 *
 *  Created on: Jul 13, 2012
 *      Author: Bailin Deng
 */

#ifndef CONSTRAINEDMESHPLUGIN_H_
#define CONSTRAINEDMESHPLUGIN_H_


#include <Dolphin/Plugins/PluginInterface/Plugin_interface.h>
#include <Dolphin/Core/Scenegraph/Core/NodeObserver.h>
#include "ConstrainedMeshPluginTypedef.h"
#include <Dolphin/Core/Scenegraph/Geometry/OpenMeshNode.h>
#include <Dolphin/Core/Scenegraph/Geometry/PointCloudNode.h>
#include <Utilities/OpenMeshAlgorithms/Geometry/NearestTriangleSearch/NearestTriangleSearch.h>
#include <Utilities/OpenMeshAlgorithms/Geometry/BasicMeasuring/BasicMeasuring.h>
#include <map>
#include <memory>
#include <utility>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include "SBCOpt.h"
#include "SBCProximalOpt.h"
#include "ReWeightedL2.h"
#include "GeneralizedBaryCentricCoords.h"

#include <igl/cotmatrix.h>
#include <igl/cotangent.h>
#include <igl/massmatrix.h>
#include <igl/invert_diag.h>
#include <igl/speye.h>
#include <igl/slice_into.h>
#include <igl/normalize_row_sums.h>
#include <igl/verbose.h>

//ipopt library
#include <coin/IpTNLP.hpp>
#include <coin/IpIpoptApplication.hpp>
#include <coin/IpSolveStatistics.hpp>




using namespace Ipopt;

namespace Dolphin {
  namespace utilities{
    class MeshHistogram;
    class MATLABEngine;
  }

  namespace scenegraph {
    class EdgeSetNode;
  }
}



namespace Dolphin { namespace plugins {

class ConstrainedMeshWidget;

class ConstrainedMeshPlugin : public Plugin_interface, public NodeObserver {
	Q_OBJECT
	Q_INTERFACES(Dolphin::plugins::Plugin_interface)

    typedef Dolphin::defines::Vector3 Vector3;

public:

	explicit ConstrainedMeshPlugin();
	virtual ~ConstrainedMeshPlugin();

public:
	PLUGIN("ConstrainedMesh","0.1","Mesh Processing")

	virtual void init(MainApplication* _mainApplication);

	virtual void onUnload();

	void onNodeUpdate(Node* _node, shared_ptr<NodeUpdate> _update = shared_ptr<NodeUpdate>() );


	//void l0_optimize_PQMesh_Disp_SDMM(int update_period, double rel_sparsity_weight, double smoothness_weight, double init_penalty_weight, double stop_ep_abs, double stop_ep_rel, double lambda, double tau_incr, double tau_decr, bool use_mat_var);

	//void l1_optimize_PQMesh_Disp_SDMM(int update_period, double rel_sparsity_weight, double smoothness_weight, double init_penalty_weight, double stop_ep_abs, double stop_ep_rel, double lambda, double tau_incr, double tau_decr, bool use_mat_var);

	//void l1_optimize_PQMesh_Disp_penalty(int update_period, double rel_sparsity_weight, double smoothness_weight, double init_penalty_weight, double penalty_incr_ratio, bool use_mat_var);

	//void l0_optimize_PQMesh_Disp_ADMM(int update_period, double rel_sparsity_weight, double smoothness_weight, double penalty_weight, double stop_ep_abs, double stop_ep_rel, bool use_mat_var);

	//void l1_optimize_PQMesh_Disp_ADMM(int update_period, double rel_sparsity_weight, double smoothness_weight, double penalty_weight, double stop_ep_abs, double stop_ep_rel, bool use_mat_var);

	//void L1_optimize_PQMesh_Disp_2nddiff(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool use_mat_var_);

	//void L1_optimize_PQMesh_Disp_softconstraint(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool diffvec_planarity);

	//void L1_optimize_PQMesh_Disp_softconstraint_rowmajor(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool diffvec_planarity);

	//void L1_optimize_PQMesh_Disp_softconstraint_matrix(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool soft_constraint_disp);

	//void L0_optimize_PQMesh_Disp_softconstraint(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool soft_constraint_disp);

	//void L1_PQMesh_tangent_disp_softconstraint(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness);

	//void L1_PQMesh_tangent_disp_softconstraint_openmp(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness);

	//void L1_PQMesh_sparse_disp_softconstraint_penaltymethod(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness);

	//void L1_PQMesh_sparse_disp_softconstraint_auglag(int update_period_, double rel_sparsity_weight_, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness);

	//void L1_sparse_disp_auglag_PQ(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool diffvec_planarity, bool use_2nddiff, bool reuse_multipliers, double tau_incr_, bool threshold_smoothness);

	//void L1_sparse_disp_auglag_PQ_lesssplit(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type, bool hex_mesh, int inner_regular_valence, bool check_boundary, bool weighted_diff, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio);

	//void L1_sparse_disp_auglag_polygonal_planar_mesh(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type, bool hex_mesh, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio);


	//void normal_L1_sparse_disp_auglag_polygonal_planar_mesh(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type, bool hex_mesh, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio);

	//void interactive_L1_sparse_disp_auglag_polygonal_planar_mesh(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type, bool hex_mesh, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio);

	//void PQ_planarization_auglag(int update_period_, double individual_disp_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, double primal_eps, double dual_eps, double init_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool diffvec_planarity, bool use_2nddiff, double tau_incr_, bool threshold_smoothness);

	//void output_fairness_energy_matrix(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type, bool hex_mesh, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_);

	//void L2_planarization(int update_period_, double l2_disp_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, double quad_dist_on_boundary, AugLagFairnessType fairness_type, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio);

	//void HC_L2_planarization(int update_period_, double l2_disp_weight, double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, double quad_dist_on_boundary, AugLagFairnessType fairness_type, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio);

	void set_orig_mesh();
	//void init_disp_planarization(int update_period_, double sparsity_weight, double smoothness_weight_, double vtx_disp_weight, double init_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps, double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps, int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, bool quad_dist_on_boundary, AugLagFairnessType fairness_type, bool hex_mesh, int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh, bool reuse_multipliers, double tau_incr_, double max_penalty_ratio, bool use_reweighting, double reweighted_tolerance_ratio);

	//void generate_displacement_files();
/*
	void clear_handle_disp(){
		this->fixed_vtx_disp.clear();
	}

	void output_obj_file();
*/
	//void save_mesh_disp_length_color_info(bool compare_input_disp);
	//void save_planarity_dist_color_info(bool diag_dist, bool local_dist, int level_num);

	//int save_colorbar_mtl_file();

	//void show_2nddiff_sequences();


	//void load_tangent_basis();

	//void read_vertex_displacement();

	// Get minimum change vector length for optimization on meshes
	//double get_min_vec_change(PolyMeshType *pmesh);

	//void exit_interactive_mode();
/*
	void udpate_ADMM_optimization();
	void update_handle_positions();
	void update_interactive_disp_edgeset();
	void setHandleIndices();
	void enter_interactive_mode();
	*/
//	void initialize_ADMM_solver(int update_period_,
//			double sparsity_weight_, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_,
//			double ep_abs_, double ep_rel_, double tau_incr_, int max_iteration);

	//void output_edgesets();
    //void load_edgesets();

    void computeBBW(int num_threads,
                    double laplacian_bound_min_ratio,
                    double init_penalty_weight_,
                    double max_penalty_weight,
                    double primal_eps_val_,
                    double dual_eps_val_,
                    double init_dual_eps_,
                    double initval_primal_eps_,
                    double initval_dual_eps_,
                    double tau_incr_,
                    int max_iter,
                    int primal_max_iter,
                    int dimension,
                    int laplaceType);
    void computeMeanCoordinate(int dimension);
    void computeGreenCoordinate(int dimension);
    void computeHarmonicCoordinate();
    void computeSmoothBC(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio, double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_, double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_, int max_iter, int primal_max_iter, double dlweight_, int dimension, int laplaceType, bool nonnegativeConstraint, bool linearPrecision);
    void test_SBC(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio, double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_, double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_, int max_iter, int primal_max_iter, double dlweight_, int dimension, int laplaceType, bool nonnegativeConstraint, bool linearPrecision);
    void load_data(int coordinateType);

    void initialization();

    void displayCoordinates();

    void addParametrizationtexture(OpenMeshNode* meshNode);

    void displayCoordinatesAlongPath();

    void displayAlongControls();

    void setCoordinateType(int type);

    void displayAllDataCoordinates(int coordinateType, double epsilon);

    void VisualizeMeasure(VertexBasedGeometryNode * histogramNode,
                          std::vector<double> measures,
						  std::vector<int>& indexarray,
						  bool setBoundary_ = false,
						  double leftBoundary_ = 0.0,
						  double rightBoundary_ = 1.0);

    void cagebasedDeformation(bool readData);

    void initialize_P_and_C(int dim);

    virtual void mouseMoveEvent(QMouseEvent* _event);

    virtual void keyPressEvent(QKeyEvent* _event);

    //ipopt solver
    void ipoptl0_solve(int dimension,
                       int laplaceType,
                       bool nonnegativeConstraint);
    void ipoptlhalf_solve(int smoothness_position,
                          double lambda,
                          bool supplyHessian,
                          int init_type,
                          int dimension,
                          int laplaceType,
						  bool controlVariables,
						  double controlWeight,
						  bool nonnegativeConstraint,
						  double tol,
                          double dual_inf_tol,
                          bool meshlessparameterization,
                          double sparsity);
    void ipoptsmooth_solve(int dimension,
                           int laplaceType,
                           bool nonnegativeConstraint,
                           bool meshlessparameterization,
                           double laplacian_bound_min_ratio,
                           double tol,
                           double dual_inf_tol,
                           double lambda);

    void knitro_smooth_solve(int dimension,
                             int laplaceType,
                             bool nonnegativeConstraint,
                             bool meshlessparameterization,
                             bool linearPrecision);

    void initialize_fairness_energy_matrix(int laplaceType);

	void initialize_fairness_energy_matrix_keenan();

    void initialize_3D_fairness_energy_matrix();

    void initialization_3D();

    void load_TetrahedralMesh();

    void set_SelectObject_as_Cage();

    void set_SelectObject_as_Data();

    void bcTextureImage(int coordinateType);

	void get_test_tex_coord(Eigen::VectorXd &boundary_value,
							Eigen::VectorXd &w_tex_coord,
							int coordinateType);

    void ipopt_halfnorm_sbc_opt(int smoothness_position,
                                double lambda,
                                bool supplyHessian,
                                int init_type,
                                int dimension,
								int laplaceType,
								bool controlVariables,
								bool nonnegative_sbc);
    void bc_parameterization();

    void delaunay_Triangulation();

    int knitro_lhalf_solve(int smoothness_position,
                           double lambda,
                           bool supplyHessian,
                           int init_type,
                           int dimension,
                           int laplaceType,
                           bool controlVariables,
                           double controlWeight,
                           bool nonnegativeConstraint,
                           double tol,
                           double dual_inf_tol,
                           bool meshlessparameterization,
                           double laplacianminratio);

    void reWeighted_l2_solve(int num_threads,
                             double laplacian_bound_min_ratio,
                             double init_penalty_weight_,
                             double max_penalty_weight,
                             double primal_eps_val_,
                             double dual_eps_val_,
                             double init_dual_eps_,
                             double initval_primal_eps_,
                             double initval_dual_eps_,
                             double tau_incr_,
                             double dlWeight_,
                             double smoothWeight_,
                             double sparsity,
                             double pNorm,
                             int max_iter,
                             int primal_max_iter,
                             int dimension,
                             int laplaceType,
                             bool nonnegativeConstraint,
                             int smoothPosition,
                             bool linearPrecision,
                             bool harmonicSolver);

    void reWeighted_l2_smooth(int num_threads,
                              double laplacian_bound_min_ratio,
                              double init_penalty_weight_,
                              double max_penalty_weight,
                              double primal_eps_val_,
                              double dual_eps_val_,
                              double init_dual_eps_,
                              double initval_primal_eps_,
                              double initval_dual_eps_,
                              double tau_incr_,
                              int max_iter,
                              int primal_max_iter,
                              int dimension,
                              int laplaceType,
                              bool nonnegativeConstraint,
                              bool linearPrecision);

    void oneDillustration(int num_threads,
                          double laplacian_bound_min_ratio,
                          double init_penalty_weight_,
                          double max_penalty_weight,
                          double primal_eps_val_,
                          double dual_eps_val_,
                          double init_dual_eps_,
                          double initval_primal_eps_,
                          double initval_dual_eps_,
                          double tau_incr_,
                          int max_iter,
                          int n,
                          double sparsity);

    void twoDillustration();

    void displayLocalExtrema(int coordinateType);

    void compute3D_LBC(int num_threads,
					   double laplacian_bound_min_ratio,
					   double init_penalty_weight_,
					   double max_penalty_weight,
					   double primal_eps_val_,
					   double dual_eps_val_,
					   double init_dual_eps_,
					   double initval_primal_eps_,
					   double initval_dual_eps_,
					   double tau_incr_,
					   double dlWeight_,
					   double smoothWeight_,
					   double sparsity,
					   int max_iter,
					   int primal_max_iter,
					   int dimension,
					   bool nonnegativeConstraint,
					   int smoothPosition,
                       bool linearPrecision,
					   bool harmonicSolver);

private:
	// Check if fixed_vtx_disp is valid for the given mesh
	/*
	bool is_valid_displacement(PolyMeshType *pmesh);

	bool is_valid_tangent_basis(PolyMeshType *pmesh);

	// Check if given mesh is quad mesh
	bool is_quad_mesh(PolyMeshType *pmesh);

	void setMeshMaterial( OpenMeshNode *n );

	// Use relative sparsity weight to get absolute sparsity weight
	double l0_sparsity_weight(double rel_weight);
	double l1_sparsity_weight(double rel_weight);
	void setVertexIndices( std::vector<unsigned int>& v );

	void get_PQMesh_normal_space_basis(PolyMeshType *pmesh, Eigen::SparseMatrix<double> &Nb);

	// Visualize displacemnt vectors using edgeset
	void show_displacements(OpenMeshNode *orig_mesh_node, scenegraph::Node *parent,
			const std::vector<MeshPointType> &disp, const char *name);

	OpenMeshNode* show_deformed_mesh(OpenMeshNode *orig_mesh, const std::vector< MeshPointType > &disp, const char *name);

	void get_edgeset_vertices(EdgeSetNode* node, std::vector< std::pair<MeshPointType, MeshPointType> > &vtx_pairs);

	double get_vertex_handle_radius(PolyMeshType*);
*/

protected:
    class IpoptL0Solver : public TNLP{
    public:
      /** default constructor */
      IpoptL0Solver(ConstrainedMeshPlugin*);

      /** default destructor */
      virtual ~IpoptL0Solver();

      /**@name Overloaded from TNLP */
      //@{
      /** Method to return some info about the nlp */
      virtual bool get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                                Index& nnz_h_lag, IndexStyleEnum& index_style);

      /** Method to return the bounds for my problem */
      virtual bool get_bounds_info(Index n, Number* x_l, Number* x_u,
                                   Index m, Number* g_l, Number* g_u);

      /** Method to return the starting point for the algorithm */
      virtual bool get_starting_point(Index n, bool init_x, Number* x,
                                      bool init_z, Number* z_L, Number* z_U,
                                      Index m, bool init_lambda,
                                      Number* lambda);

      /** Method to return the objective value */
      virtual bool eval_f(Index n, const Number* x, bool new_x, Number& obj_value);

      /** Method to return the gradient of the objective */
      virtual bool eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);

      /** Method to return the constraint residuals */
      virtual bool eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);

      /** Method to return:
       *   1) The structure of the jacobian (if "values" is NULL)
       *   2) The values of the jacobian (if "values" is not NULL)
       */
      virtual bool eval_jac_g(Index n, const Number* x, bool new_x,
                              Index m, Index nele_jac, Index* iRow, Index *jCol,
                              Number* values);

      /** @name Solution Methods */
      //@{
      /** This method is called when the algorithm is complete so the TNLP can store/write the solution */
      virtual void finalize_solution(SolverReturn status,
                                     Index n, const Number* x, const Number* z_L, const Number* z_U,
                                     Index m, const Number* g, const Number* lambda,
                                     Number obj_value,
                     const IpoptData* ip_data,
                     IpoptCalculatedQuantities* ip_cq);
      //@}

    private:
      /**@name Methods to block default compiler methods.
       * The compiler automatically generates the following three methods.
       *  Since the default compiler implementation is generally not what
       *  you want (for all but the most simple classes), we usually
       *  put the declarations of these methods in the private section
       *  and never implement them. This prevents the compiler from
       *  implementing an incorrect "default" behavior without us
       *  knowing. (See Scott Meyers book, "Effective C++")
       *
       */
      IpoptL0Solver(const IpoptL0Solver&);
      IpoptL0Solver& operator=(const IpoptL0Solver&);

      ConstrainedMeshPlugin *o;
    };

    class IpoptLhalfSolver : public TNLP{
    public:
      /** default constructor */
      IpoptLhalfSolver(ConstrainedMeshPlugin*);

      /** default destructor */
      virtual ~IpoptLhalfSolver();

      /**@name Overloaded from TNLP */
      //@{
      /** Method to return some info about the nlp */
      virtual bool get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                                Index& nnz_h_lag, IndexStyleEnum& index_style);

      /** Method to return the bounds for my problem */
      virtual bool get_bounds_info(Index n, Number* x_l, Number* x_u,
                                   Index m, Number* g_l, Number* g_u);

      /** Method to return the starting point for the algorithm */
      virtual bool get_starting_point(Index n, bool init_x, Number* x,
                                      bool init_z, Number* z_L, Number* z_U,
                                      Index m, bool init_lambda,
                                      Number* lambda);

      /** Method to return the objective value */
      virtual bool eval_f(Index n, const Number* x, bool new_x, Number& obj_value);

      /** Method to return the gradient of the objective */
      virtual bool eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);

      /** Method to return the constraint residuals */
      virtual bool eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);

      /** Method to return:
       *   1) The structure of the jacobian (if "values" is NULL)
       *   2) The values of the jacobian (if "values" is not NULL)
       */
      virtual bool eval_jac_g(Index n, const Number* x, bool new_x,
                              Index m, Index nele_jac, Index* iRow, Index *jCol,
                              Number* values);

      virtual bool eval_h(Index n, const Number *x, bool new_x, Number obj_factor, Index m, const Number *lambda, bool new_lambda, Index nele_hess, Index *iRow, Index *jCol, Number *values);

      /** @name Solution Methods */
      //@{
      /** This method is called when the algorithm is complete so the TNLP can store/write the solution */
      virtual void finalize_solution(SolverReturn status,
                                     Index n, const Number* x, const Number* z_L, const Number* z_U,
                                     Index m, const Number* g, const Number* lambda,
                                     Number obj_value,
                     const IpoptData* ip_data,
                     IpoptCalculatedQuantities* ip_cq);
      //@}

    private:
      /**@name Methods to block default compiler methods.
       * The compiler automatically generates the following three methods.
       *  Since the default compiler implementation is generally not what
       *  you want (for all but the most simple classes), we usually
       *  put the declarations of these methods in the private section
       *  and never implement them. This prevents the compiler from
       *  implementing an incorrect "default" behavior without us
       *  knowing. (See Scott Meyers book, "Effective C++")
       *
       */
      IpoptLhalfSolver(const IpoptLhalfSolver&);
      IpoptLhalfSolver& operator=(const IpoptLhalfSolver&);

      ConstrainedMeshPlugin *o;
    };

    class IpoptSmoothSolver : public TNLP{
    public:
      /** default constructor */
      IpoptSmoothSolver(ConstrainedMeshPlugin*);

      /** default destructor */
      virtual ~IpoptSmoothSolver();

      /**@name Overloaded from TNLP */
      //@{
      /** Method to return some info about the nlp */
      virtual bool get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                                Index& nnz_h_lag, IndexStyleEnum& index_style);

      /** Method to return the bounds for my problem */
      virtual bool get_bounds_info(Index n, Number* x_l, Number* x_u,
                                   Index m, Number* g_l, Number* g_u);

      /** Method to return the starting point for the algorithm */
      virtual bool get_starting_point(Index n, bool init_x, Number* x,
                                      bool init_z, Number* z_L, Number* z_U,
                                      Index m, bool init_lambda,
                                      Number* lambda);

      /** Method to return the objective value */
      virtual bool eval_f(Index n, const Number* x, bool new_x, Number& obj_value);

      /** Method to return the gradient of the objective */
      virtual bool eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);

      /** Method to return the constraint residuals */
      virtual bool eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);

      /** Method to return:
       *   1) The structure of the jacobian (if "values" is NULL)
       *   2) The values of the jacobian (if "values" is not NULL)
       */
      virtual bool eval_jac_g(Index n, const Number* x, bool new_x,
                              Index m, Index nele_jac, Index* iRow, Index *jCol,
                              Number* values);

      /** @name Solution Methods */
      //@{
      /** This method is called when the algorithm is complete so the TNLP can store/write the solution */
      virtual void finalize_solution(SolverReturn status,
                                     Index n, const Number* x, const Number* z_L, const Number* z_U,
                                     Index m, const Number* g, const Number* lambda,
                                     Number obj_value,
                     const IpoptData* ip_data,
                     IpoptCalculatedQuantities* ip_cq);
      //@}

    private:
      /**@name Methods to block default compiler methods.
       * The compiler automatically generates the following three methods.
       *  Since the default compiler implementation is generally not what
       *  you want (for all but the most simple classes), we usually
       *  put the declarations of these methods in the private section
       *  and never implement them. This prevents the compiler from
       *  implementing an incorrect "default" behavior without us
       *  knowing. (See Scott Meyers book, "Effective C++")
       *
       */
      IpoptSmoothSolver(const IpoptSmoothSolver&);
      IpoptSmoothSolver& operator=(const IpoptSmoothSolver&);

      ConstrainedMeshPlugin *o;
    };

    class MeanValueCooridnates{

    public:
        static std::vector<double> weights(const Point& x, PolyMeshType* mesh)
        {
            int npts = mesh->n_vertices();

            // Initializing weights
            std::vector<double> weights(npts);

            // arrays storing point-to-vertex vectors and distances
            std::vector<double> dist(npts);
            std::vector<Point> uVec(npts);
            static const double eps = 0.00000001;

            OMesh::VertexIter vit, vend = mesh->vertices_end();

            for (vit = mesh->vertices_begin(); vit != vend; ++vit)
            {
                int pid = vit.handle().idx();

                // point-to-vertex vector
                uVec[pid] = mesh->point(vit) - x;

                // distance
                dist[pid] = uVec[pid].norm();

                // handle special case when the point is really close to a vertex
                if (dist[pid] < eps)
                {
                    weights[pid] = 1.0;
                    return weights;
                }

                // project onto unit sphere (normalize)
                uVec[pid] /= dist[pid];
            }

            // Now loop over all triangle to compute weights
            for (OMesh::FaceIter fIt = mesh->faces_begin(); fIt != mesh->faces_end(); ++fIt)
            {
                // vertex id
                int fi = fIt.handle().idx();
                OMesh::FaceVertexIter fv_it = mesh->fv_iter(fIt.handle());
                int pid0 = fv_it.handle().idx();
                int pid1 = (++fv_it).handle().idx();
                int pid2 = (++fv_it).handle().idx();

                // unit vectors
                Point u0 = uVec[pid0];
                Point u1 = uVec[pid1];
                Point u2 = uVec[pid2];

                // edge lengths
                double l0 = (u1 - u2).norm();
                double l1 = (u2 - u0).norm();
                double l2 = (u0 - u1).norm();

                // angles
                double theta0 = 2.0*asin(l0/2.0);
                double theta1 = 2.0*asin(l1/2.0);
                double theta2 = 2.0*asin(l2/2.0);
                double halfSum = (theta0 + theta1 + theta2) / 2.0;

                // special case when the point lies on the triangle
                if (M_PI - halfSum < eps)
                {
                    weights.clear();
                    weights.resize(npts, 0.0); // clear all

                    weights[pid0] = sin(theta0) * dist[pid1] * dist[pid2];
                    weights[pid1] = sin(theta1) * dist[pid2] * dist[pid0];
                    weights[pid2] = sin(theta2) * dist[pid0] * dist[pid1];

                    double sumWeight = weights[pid0] + weights[pid1] + weights[pid2];

                    weights[pid0] /= sumWeight;
                    weights[pid1] /= sumWeight;
                    weights[pid2] /= sumWeight;

                    return weights;
                }

                // coefficient
                double sinHalfSum = sin(halfSum);
                double sinHalfSumSubTheta0 = sin(halfSum-theta0);
                double sinHalfSumSubTheta1 = sin(halfSum-theta1);
                double sinHalfSumSubTheta2 = sin(halfSum-theta2);
                double sinTheta0 = sin(theta0), sinTheta1 = sin(theta1), sinTheta2 = sin(theta2);

                double c0 = 2 * sinHalfSum * sinHalfSumSubTheta0 / sinTheta1 / sinTheta2 - 1;
                double c1 = 2 * sinHalfSum * sinHalfSumSubTheta1 / sinTheta2 / sinTheta0 - 1;
                double c2 = 2 * sinHalfSum * sinHalfSumSubTheta2 / sinTheta0 / sinTheta1 - 1;

                if (fabs(c0) > 1) c0 = c0 > 0 ? 1 : -1;
                if (fabs(c1) > 1) c1 = c1 > 0 ? 1 : -1;
                if (fabs(c2) > 1) c2 = c2 > 0 ? 1 : -1;

                // sign
                double det = Determinant3x3(u0, u1, u2);

                // skip when less than eps
                if (abs(det) < eps){
                    fi++; continue;
                }

                double detSign = det > 0 ? 1 : -1;
                double sign0 = detSign * sqrt(1 - c0*c0);
                double sign1 = detSign * sqrt(1 - c1*c1);
                double sign2 = detSign * sqrt(1 - c2*c2);

                // if 'x' lies on the plane of current triangle but outside it, ignore the current triangle
                if (abs(sign0) < eps || abs(sign1) < eps || abs(sign2) < eps)
                {
                    fi++; continue;
                }

                // weight
                weights[pid0] += (theta0-c1*theta2-c2*theta1) / (dist[pid0]*sinTheta1*sign2);
                weights[pid1] += (theta1-c2*theta0-c0*theta2) / (dist[pid1]*sinTheta2*sign0);
                weights[pid2] += (theta2-c0*theta1-c1*theta0) / (dist[pid2]*sinTheta0*sign1);
            }

            // normalize weight
            double sumWeight = 0.0;
            for (int pid=0; pid < npts; ++pid)	sumWeight += weights[pid];
            if(!sumWeight) printf("WARNING: zero weights.\n");
            for (int pid=0; pid < npts; ++pid)	weights[pid] /= sumWeight;

            return weights;
        }

        static Point point(std::vector<double> weight, PolyMeshType* mesh)
        {
            OMesh::VertexIter vit, vend = mesh->vertices_end();

            Point p(0,0,0);

            for (vit = mesh->vertices_begin(); vit != vend; ++vit){
                p += mesh->point(vit.handle())*weight[vit.handle().idx()];
            }

            return p;
        }

        static inline double Determinant3x3(const Point& c1, const Point& c2, const Point& c3)
        {
            return c1[0] * c2[1] * c3[2] + c2[0] * c3[1] * c1[2] + c3[0] * c1[1] * c2[2] -
                c1[0] * c3[1] * c2[2] - c2[0] * c1[1] * c3[2] - c3[0] * c2[1] * c1[2];
        }
    };

    class GreenCoordinates{

    public:
        GreenCoordinates(PolyMeshType* forShape, PolyMeshType* usingCage);

        PolyMeshType* shape;
        PolyMeshType* cage;

        std::vector<Point> orginalCagePos;
        std::vector<Normal> orginalCageNormal;
        std::vector<double> S;

        struct GreenCoordiante{
            std::vector<double> coord_v;
            std::vector<double> coord_n;
            bool insideCage;
            bool valid;
        };

        std::vector<GreenCoordiante> coords;

        GreenCoordinates::GreenCoordiante computeCoordinates(Point point);
    private:
        double GCTriInt(const Point& p, const Point& v1, const Point& v2, const Point& e);
    };

    bool ipoptl0_get_nlp_info(Index& n, Index& m, Index& nnz_jac_g, Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style);
    bool ipoptl0_get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u);
    bool ipoptl0_get_starting_point(Index n, bool init_x, Number* x,
                                  bool init_z, Number* z_L, Number* z_U,
                                  Index m, bool init_lambda,
                                  Number* lambda);
    bool ipoptl0_eval_f(Index n, const Number* x, bool new_x, Number& obj_value);
    bool ipoptl0_eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);
    bool ipoptl0_eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);
    bool ipoptl0_eval_jac_g(Index n, const Number* x, bool new_x,
                          Index m, Index nele_jac, Index* iRow, Index *jCol,
                          Number* values);

    //ipopt half norm minimization
    bool ipoptlhalf_get_nlp_info(Index& n, Index& m, Index& nnz_jac_g, Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style);
    bool ipoptlhalf_get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u);
    bool ipoptlhalf_get_starting_point(Index n, bool init_x, Number* x,
                                  bool init_z, Number* z_L, Number* z_U,
                                  Index m, bool init_lambda,
                                  Number* lambda);
    bool ipoptlhalf_eval_f(Index n, const Number* x, bool new_x, Number& obj_value);
    bool ipoptlhalf_eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);
    bool ipoptlhalf_eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);
    bool ipoptlhalf_eval_jac_g(Index n, const Number* x, bool new_x,
                          Index m, Index nele_jac, Index* iRow, Index *jCol,
                          Number* values);
    bool ipoptlhalf_eval_h(Index n, const Number *x, bool new_x, Number obj_factor, Index m, const Number *lambda, bool new_lambda, Index nele_hess, Index *iRow, Index *jCol, Number *values);

    //ipopt half norm minimization
    bool ipoptsmooth_get_nlp_info(Index& n, Index& m, Index& nnz_jac_g, Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style);
    bool ipoptsmooth_get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u);
    bool ipoptsmooth_get_starting_point(Index n, bool init_x, Number* x,
                                  bool init_z, Number* z_L, Number* z_U,
                                  Index m, bool init_lambda,
                                  Number* lambda);
    bool ipoptsmooth_eval_f(Index n, const Number* x, bool new_x, Number& obj_value);
    bool ipoptsmooth_eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);
    bool ipoptsmooth_eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);
    bool ipoptsmooth_eval_jac_g(Index n, const Number* x, bool new_x,
                          Index m, Index nele_jac, Index* iRow, Index *jCol,
                          Number* values);

protected:

    //for sbc project
    //SBCL0Mesh* sbcl0_solver;
    SBCLHalfMesh* sbcl0_solver;
    //SBCProximalL0Mesh* sbcl0_solver;
    int n_boundary_pt, n_data_pt, n_LTL_nonzeros;
    int dim;
    double dl_weight;
    double control_weight_;
    Eigen::Vector3d mean_cage_;
    double smoothness_bound;
    double epsilon;
    Eigen::VectorXd LTL_hessian_values;
    std::vector<int> diagonalIndex;
    Ipopt::Number* lhalf_jac_g;
    int smoothness_position_;
    SparseMatrixXd matrix_Lt, matrix_L, matrix_LTL; // The Laplacian matrix and its transpose
    //Eigen::SparseMatrix<double, Eigen::RowMajor> matrix_LTL;
    Eigen::MatrixXd matrix_a, matrix_LTa, fair_derivative;
    std::vector<int> control_data_correspondence_;

	// Mean-centered coordinates for vertices.
	// For 2d meshes, the first two coordinates are projection coordinates to the least squares plane of the whole mesh, and the third coordinates are zero
    std::vector<Vector3> point_data;

    std::vector<double> control_edge_length;
    std::vector<Vector3> control_edge_normal;
    std::vector<double> old_control_edge_length;

    std::vector<Point> orginalCagePos;
    std::vector<double> threeDS;

    std::vector<int> vhs;
    std::vector<int> datapt_idx_to_vtx_idx_map;	// A map from data point index to vertex index
    std::vector<int> vtx_idx_to_datapt_idx_map;
    std::vector<int> vtx_idx_to_control_pt_idx_map;
    std::vector<int> controlpt_idx_to_vtx_idx_map; // A map from control point index to vertex index
    Eigen::MatrixXd init_w, w, temp_w;
    Eigen::MatrixXd meanw, greenw, harmonicw, boundedBiharmonicW;
    std::vector<GreenCoordinates::GreenCoordiante> threeDGreen;
	Eigen::MatrixXd new_control_points;
    int coordinateType_;
    bool hasCage_;
    bool controlVariables_;
    bool nonnegativeConstraint_;
    bool meshless_parameterization_;
    bool linearPrecision_;
    bool color_map_;
    std::tr1::shared_ptr<VertexGeometry> cageObject_;
    std::tr1::shared_ptr<PolyMeshType> cageMesh_;
    std::tr1::shared_ptr<PolyMeshType> pmesh_;
    std::vector<Point> original_positions_;
    std::vector<Point> initial_data_positions_;
    std::vector<Point> initial_cage_positions_;
    OpenMeshNode *meshNode_;
    VertexBasedGeometryNode *cageNode_;
    int pickedCageVertex;
    Eigen::MatrixXd P_mat, C_mat;
	Eigen::MatrixXd optimized_C_mat;
    Eigen::MatrixXd TetrahedralMesh_node_;
    Eigen::MatrixXi TetrahedralMesh_ele_;
    Eigen::MatrixXi TetrahedralMesh_face_;
    vector<Segment> cageSegments;
    vector<Segment> modelSegments;
    Eigen::MatrixXd weighted_D;
    Eigen::MatrixXd Bound_low;
    Eigen::MatrixXd Bound_up;
    Eigen::MatrixXd wud;

private://data
	std::map< int, MeshPointType > fixed_vtx_disp;
	std::auto_ptr<ConstrainedMeshWidget> widget;
    std::tr1::shared_ptr<Dolphin::utilities::MeshHistogram> mesh_histogram;
    std::tr1::shared_ptr<PolyMeshType> original_mesh, interactive_orignal_mesh;
    OpenMeshNode* interactive_orig_meshnode;
    EdgeSetNode* interactive_disp_edgeset_node;
    std::vector< std::vector<double> > tangent_basis;
    std::vector<unsigned int> handleIndices;
    std::vector< MeshPointType > handle_orig_pos;
    PointCloudNode *handles;
	//PQSparseDispSoftConstraint admm_solver;
    bool interactive_mode;

    //set up matlab engine...
  #ifdef MATLAB_EXISTS
    utilities::MATLABEngine* matEngine_;
  #endif
};
}}//namespaces

#endif /* CONSTRAINEDMESHPLUGIN_H_ */
