#ifndef REWEIGHTEDL2_H
#define REWEIGHTEDL2_H

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <OpenMesh/Core/Geometry/VectorT.hh>
#include <vector>
#include "ConstrainedMeshPluginTypedef.h"
#include <cmath>
#include <iostream>

namespace Dolphin {

namespace plugins {
typedef Eigen::SparseMatrix<double> SparseMatrixXd;

// Base class for SBC optimization
class ReWeightedL2{
public:
    explicit ReWeightedL2(){}
    virtual ~ReWeightedL2(){}

    Eigen::MatrixXd& get_w(){
        return w;
    }

    void assign_other_coordinate(Eigen::MatrixXd& otherw);

    void assign_weighted_matrix(Eigen::MatrixXd &weightedD);

    void assign_new_smooth_bound(double laplacian_bound_min_ratio);

    void solve();

    void solve_dl();

    void solve_smooth();

    void solve_bbw();

    void solve_harmonic();

    void solve_illustrate();

    void init_variables(int num_threads,
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
                        int max_iter,
                        int primal_max_iter,
                        int dim_,
                        SparseMatrixXd L_,
                        Eigen::MatrixXd a_,
                        Eigen::MatrixXd D_,
                        Eigen::MatrixXd control_points_,
                        Eigen::MatrixXd data_points_,
                        std::vector<bool> has_fixed_neighbor_,
                        bool nonnegativeConstraint_,
                        bool smoothness_hard_constraint_,
                        bool linearPrecision_,
                        bool smoothCoordinate_);

    void illustrate_init_variables(int num_threads,
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
                                   SparseMatrixXd L_,
                                   Eigen::MatrixXd a_);

    void harmonic_initialize_stopping_criteria_var();

    void initialize_v_harmonic_vars();

protected:
    double laplacian_bound_min_ratio_;
    double penalty_weight;
    double max_penalty, min_penalty;
    double lap_bound;
    double average_element_bound;
    Eigen::MatrixXd smooth_bound;

    int max_iteration;
    int nb_threads;
    bool need_incr_penalty;
    bool primal_subproblem_converge;
    bool optimization_converge, optimization_end;

    int n_control_points;
    int n_data_points;
    int n_total_coef;
    bool nonnegativeConstraint;
    bool smoothness_hard_constraint;
    bool linearPrecision;

    Eigen::SimplicialLDLT<SparseMatrixXd> solver, solver_smooth;
    Eigen::SimplicialLDLT<SparseMatrixXd> solver_u_dl, solver_harmonic;	// Cholesky factorization of the linear system for w
    SparseMatrixXd Lt, L; // The Laplacian matrix and its transpose
    std::vector<Eigen::VectorXd> matrixL;
    Eigen::VectorXd matrixLrowNorm;
    Eigen::MatrixXd IminusNNt;	// Matrix used for updaing y
    Eigen::MatrixXd basey_NNt;

    // Intermediate variables
    Eigen::MatrixXd u_update_tmp;
    Eigen::MatrixXd v_update_tmp;
    Eigen::MatrixXd v_harmonic_update_tmp;
    Eigen::MatrixXd x_update_tmp;
    Eigen::MatrixXd y_update_tmp;
    Eigen::MatrixXd z_update_tmp;

    // The ordering of the following variables is based on the control points. Quantities related to the same control point are packed together
    int dim;
    Eigen::MatrixXd D;
    Eigen::MatrixXd d1, d2, d3, d4, d5;
    Eigen::MatrixXd d1_bar, d2_bar, d3_bar, d4_bar, d5_bar;
    Eigen::MatrixXd d1_diff, d2_diff, d3_diff, d4_diff, d5_diff;
    Eigen::MatrixXd d1_harmonic;
    Eigen::MatrixXd x, y, z, u, v, w, a;
    Eigen::MatrixXd initial_w;
    Eigen::MatrixXd w_bar;
    Eigen::MatrixXd v_harmonic;
    std::vector<int> v_index;
    Eigen::MatrixXd prev_w, w_diff;
    Eigen::MatrixXd control_points;
    Eigen::MatrixXd data_points;
    std::vector<bool> has_fixed_neighbor;
    Eigen::MatrixXd pC_dl;
    Eigen::MatrixXd e_dl;
    SparseMatrixXd  C_dl_s, CTC_dl_s, dl_I, Iu;
    SparseMatrixXd M_edge, M_edge_T;

    // Primal residual vectors
    Eigen::MatrixXd primal_residual_v, primal_residual_x, primal_residual_y, primal_residual_z, primal_residual_u;
    Eigen::MatrixXd primal_residual_v_harmonic;
    double primal_residual_v_sqr_norm, primal_residual_x_sqr_norm, primal_residual_y_sqr_norm, primal_residual_z_sqr_norm, primal_residual_u_sqr_norm;

    // Temporary storage for primal residual norms
    //double primal_residual_sqr_norm_v, primal_residual_sqr_norm_x, primal_residual_sqr_norm_y, primal_residual_sqr_norm_z;
    double primal_residual_sqr_norm, dual_residual_sqr_norm;

    // Dual residual vector related to v
    Eigen::MatrixXd dual_residual_v;
    Eigen::MatrixXd dual_residual_v_harmonic;

    // Dimension of the primal and dual residual. We need this to normalized the primal and dual residual
    int primal_residual_dim, dual_residual_dim;

    // Primal and dual residual norms
    double prev_outer_primal_residual_sqr_norm;

    double primal_eps_val, dual_eps_val;	// Epsilon value for defining norm related tolerances
    double init_dual_eps_val;

    double initval_primal_eps_val, initval_dual_eps_val;

    // We use squared-norm instead of L2 norm to represent thresholds, so that we don't need to do sqrt
    double primal_sqr_norm_eps, final_dual_sqr_norm_eps, cur_dual_sqr_norm_eps;
    double initval_primal_residual_sqr_norm_eps, initval_dual_residual_sqr_norm_eps;

    // The starting iteration number count for the current primal problem
    int current_primal_run_start_iter, primal_subproblem_maxiter;

    // Intermediate variables related to changing penalty weight
    double primal_dual_sqr_norm_rel_ratio_bound; // Threshold ratio between primal and dual residual norms
    double tau_incr;	// Ratio of change for increasing penalty weight
    double smooth_Weight;      //trade off parameter
    double dl_Weight;
    double scaled_dual_change_ratio;	// Reciprocal of the penalty increase ratio
    double penalty_change_ratio;
    double min_sqr_primal_residual_change_ratio;

    void initialize_stopping_criteria_var();
    void initvalue_initialize_stopping_criteria_var();
    void dl_initialize_stopping_criteria_var();
    void smooth_initialize_stopping_criteria_var();

    void compute_vx_update_aux_vars();
    void compute_vxy_update_aux_vars();
    void compute_vyz_update_aux_vars();
    void compute_vxyz_update_aux_vars();
    void compute_vxyz_harmonic_update_aux_vars();
    void compute_uvxy_update_aux_vars();
    void update_w();
    void update_w_dl();
    void update_w_smooth();
    void update_w_harmonic();
    void update_w_illustrate();
    void update_x();
    void update_x_illustrate();
    void update_y();
    void update_y_dl();
    void update_z();
    void update_u();
    void update_v();
    void update_v_smooth();
    void update_v_harmonic();
    void update_v_illustrate();
    void initialize_primal_vars();
    void initialize_solver();
    void zero_initialize_dual_vars();
    void init_intermediate_vars();

    int sgn(double val)
    {
        return (0 < val) - (val < 0);
    }

    int point_dim()
    {
        return dim;
    }

    bool nonnegative_constraint()
    {
        return nonnegativeConstraint;
    }

    int num_control_points()
    {
        return n_control_points;
    }

    int num_data_points()
    {
        return n_data_points;
    }

    void initialize_primal_residual_norm()
    {
        this->prev_outer_primal_residual_sqr_norm = 0;
    }

    void initialize_control_matrix();

    void initialize_y_constraint_data();

    // Update dual variables
    // Then Check if stopping criteria is met. If so, return true.
    // Otherwise, update penalty weight, and return false

    void stop_check_and_dual_var_penalty_weight_update(int iter_num);

    void dl_stop_check_and_dual_var_penalty_weight_update(int iter_num);

    void smooth_stop_check_and_dual_var_penalty_weight_update(int iter_num);

    void harmonic_stop_check_and_dual_var_penalty_weight_update(int iter_num);

    void illustrate_stop_check_and_dual_var_penalty_weight_update(int iter_num);

    bool compute_penalty_change_ratio();	// Return true if penalty need to change. This method is used in initial value optimization
};
}}

#endif // REWEIGHTEDL2_H
