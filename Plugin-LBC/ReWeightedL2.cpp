#include "ReWeightedL2.h"
#include <algorithm>
#include <omp.h>
#include <gsl/gsl_poly.h>
#include <Eigen/Cholesky>
#include <Eigen/LU>


namespace Dolphin {

namespace plugins {
void ReWeightedL2::init_variables(int num_threads,
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
                                  bool smoothCoordinate_)
{
    this->nb_threads = num_threads;
    this->laplacian_bound_min_ratio_ = laplacian_bound_min_ratio;
    this->penalty_weight = init_penalty_weight_;
    this->min_penalty = init_penalty_weight_*0.01;
    this->tau_incr = tau_incr_;
    this->dl_Weight = dlWeight_;
    this->smooth_Weight = smoothWeight_;
    this->max_iteration = max_iter;
    this->primal_subproblem_maxiter = primal_max_iter;
    this->primal_eps_val = primal_eps_val_;
    this->dual_eps_val = dual_eps_val_;
    this->init_dual_eps_val = init_dual_eps_;
    this->initval_primal_eps_val = initval_primal_eps_;
    this->initval_dual_eps_val = initval_dual_eps_;
    this->current_primal_run_start_iter = 0;
    this->primal_dual_sqr_norm_rel_ratio_bound = 100;
    this->primal_residual_sqr_norm = 0;
    this->dual_residual_sqr_norm = 0;

    this->min_sqr_primal_residual_change_ratio = 0.7*0.7;

    this->max_penalty = std::max(max_penalty_weight, penalty_weight * std::pow(init_dual_eps_val/dual_eps_val, 2.0) + 1.0);

    nonnegativeConstraint = nonnegativeConstraint_;
    smoothness_hard_constraint = smoothness_hard_constraint_;
    linearPrecision = linearPrecision_;
    dim = dim_;
    n_control_points = control_points_.cols();
    n_data_points = data_points_.cols();
    n_total_coef = n_control_points*n_data_points;
    control_points = control_points_;
    data_points = data_points_;
    has_fixed_neighbor = has_fixed_neighbor_;
    L = L_;
    Lt = L.transpose();
    a = a_;
    D = D_;
    initialize_control_matrix();
    initialize_solver();
    initialize_y_constraint_data();
    init_intermediate_vars();
    e_dl.setOnes(1, n_control_points);

    penalty_weight = init_penalty_weight_;
    initialize_primal_vars();
    zero_initialize_dual_vars();
    initialize_primal_residual_norm();
    //initialize_stopping_criteria_var();

    if (smoothCoordinate_ || linearPrecision)
    {
        smooth_initialize_stopping_criteria_var();
    }
    else
    {
        dl_initialize_stopping_criteria_var();
    }

    //for whole mesh
    smooth_bound = (L*initial_w + a)*laplacian_bound_min_ratio;
    lap_bound = smooth_bound.norm();
    average_element_bound = smooth_bound.lpNorm<1>()/double(a.rows()*a.cols());
    std::cout<<"Average element bound: "<<average_element_bound<<std::endl;
}

void ReWeightedL2::illustrate_init_variables(int num_threads,
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
                                             Eigen::MatrixXd a_)
{
    this->nb_threads = num_threads;
    this->penalty_weight = init_penalty_weight_;
    this->min_penalty = init_penalty_weight_*0.01;
    this->tau_incr = tau_incr_;
    this->max_iteration = max_iter;
    this->primal_eps_val = primal_eps_val_;
    this->dual_eps_val = dual_eps_val_;
    this->init_dual_eps_val = init_dual_eps_;
    this->initval_primal_eps_val = initval_primal_eps_;
    this->initval_dual_eps_val = initval_dual_eps_;
    this->current_primal_run_start_iter = 0;
    this->primal_dual_sqr_norm_rel_ratio_bound = 100;
    this->primal_residual_sqr_norm = 0;
    this->dual_residual_sqr_norm = 0;

    this->min_sqr_primal_residual_change_ratio = 0.7*0.7;

    this->max_penalty = std::max(max_penalty_weight, penalty_weight * std::pow(init_dual_eps_val/dual_eps_val, 2.0) + 1.0);

    n_control_points = a_.cols();
    n_data_points = L_.rows();
    n_total_coef = n_control_points*n_data_points;
    L = L_;
    Lt = L.transpose();
    a = a_;
    init_intermediate_vars();

    penalty_weight = init_penalty_weight_;
    initialize_primal_vars();
    zero_initialize_dual_vars();
    initialize_primal_residual_norm();
    smooth_initialize_stopping_criteria_var();

    //initialize solver
    Iu.resize(n_data_points, n_data_points);
    typedef Eigen::Triplet<double> T;
    std::vector<T> triplets_I;
    for (int i = 0; i < n_data_points; i++)
    {
        triplets_I.push_back(T(i, i, 1.0));
    }
    Iu.setFromTriplets(triplets_I.begin(), triplets_I.end());
    solver_smooth.compute(Lt*L + Iu*2.0);
    //end of initializing solver

    //for each vertex
    smooth_bound = (L*w + a)*laplacian_bound_min_ratio;
}

void ReWeightedL2::compute_vyz_update_aux_vars()
{
    #pragma omp sections nowait
    {
        #pragma omp section
        {
            y_update_tmp = w - d3;
        }

        #pragma omp section
        {
            z_update_tmp = w - d4;
        }
    }

    #pragma omp for
    for (int i = 0; i < n_control_points; i++)
    {
        v_update_tmp.col(i) = L*w.col(i) + a.col(i) - d1.col(i);
    }
}

void ReWeightedL2::compute_vxyz_update_aux_vars()
{
    #pragma omp sections nowait
    {
        #pragma omp section
        {
            x_update_tmp = w_bar - d2_bar;
        }

        #pragma omp section
        {
            y_update_tmp = w_bar - d3_bar;
        }

        #pragma omp section
        {
            z_update_tmp = w_bar - d4_bar;
        }
    }

    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        v_update_tmp.col(i) = L*w_bar.col(i) + a.col(i) - d1_bar.col(i);
    }
}

void ReWeightedL2::compute_vxy_update_aux_vars()
{
    #pragma omp sections nowait
    {
        #pragma omp section
        {
            x_update_tmp = w - d2;
        }

        #pragma omp section
        {
            y_update_tmp = w - d3;
        }
    }

    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        v_update_tmp.col(i) = L*w.col(i) + a.col(i) - d1.col(i);
    }
}

void ReWeightedL2::compute_vx_update_aux_vars()
{
    #pragma omp sections nowait
    {
        #pragma omp section
        {
            x_update_tmp = w - d2;
        }
    }

    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        v_update_tmp.col(i) = L*w.col(i) + a.col(i) - d1.col(i);
    }
}

void ReWeightedL2::compute_vxyz_harmonic_update_aux_vars()
{
    #pragma omp sections nowait
    {
        #pragma omp section
        {
            x_update_tmp = w - d2;
        }

        #pragma omp section
        {
            y_update_tmp = w - d3;
        }
    }

    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        v_harmonic_update_tmp.col(i) = M_edge*w.col(i) - d1_harmonic.col(i);
    }
}

void ReWeightedL2::compute_uvxy_update_aux_vars()
{
    #pragma omp sections nowait
    {
        #pragma omp section
        {
            x_update_tmp = w - d2;
        }

        #pragma omp section
        {
            y_update_tmp = w - d3;
        }

        #pragma omp section
        {
            u_update_tmp = w - d5;
        }
    }

    #pragma omp for
    for (int i = 0; i < n_control_points; i++)
    {
        v_update_tmp.col(i) = L*w.col(i) + a.col(i) - d1.col(i);
    }
}

void ReWeightedL2::update_u()
{
    #pragma omp for
    for (int i = 0; i < n_data_points; ++i)
    {
        u.row(i) = (solver_u_dl.solve((dl_Weight*pC_dl.row(i) + penalty_weight*u_update_tmp.row(i)).transpose())).transpose();
    }
}

void ReWeightedL2::update_v()
{
    if (smoothness_hard_constraint)
    {
        #pragma omp single nowait
        {
            double a_ = v_update_tmp.norm();
            if(a_ <= lap_bound)
            {
                v = v_update_tmp;
            }
            else
            {
                v = v_update_tmp*(lap_bound/a_);
            }
        }/*

        //test for subharmonic and superharmonic
        #pragma omp for nowait
        for (int i = 0; i < v.rows()*v.cols(); ++i)
        {
            double lowbound = std::min(0.0, smooth_bound(i)/laplacian_bound_min_ratio_);
            double upbound = fabs(smooth_bound(i));
            v(i) = std::max(lowbound, v_update_tmp(i));
            v(i) = std::min(upbound, v(i));
        }*/
    }
    else
    {
        #pragma omp single nowait
        {
            v = v_update_tmp*(penalty_weight/(2.0*smooth_Weight + penalty_weight));
        }
    }
}

void ReWeightedL2::update_v_illustrate()
{/*
    #pragma omp for nowait
    for (int i = 0; i < v.rows()*v.cols(); ++i)
    {
        double value = v_update_tmp(i);
        double upBound_ = 1.0/double(a.rows());
        double lowBound = -1.0/double(a.rows());
        if (value > upBound_)
        {
            v(i) = upBound_;
        }
        else
        {
            if (value < lowBound)
            {
                v(i) = lowBound;
            }
            else
            {
                v(i) = value;
            }
        }
    }*/

    #pragma omp single nowait
    {
        lap_bound = 100.0/double(a.rows());
        double a_ = v_update_tmp.norm();
        if(a_ <= lap_bound)
        {
            v = v_update_tmp;
        }
        else
        {
            v = v_update_tmp*(lap_bound/a_);
        }
    }
}

void ReWeightedL2::update_v_smooth()
{
    #pragma omp single nowait
    {
        v = v_update_tmp*(penalty_weight/(1.0 + penalty_weight));
    }
}

void ReWeightedL2::update_v_harmonic()
{
    #pragma omp for nowait
    for (int k = 0; k < n_total_coef; ++k)
    {
        int i = k/n_control_points;
        int j = k%n_control_points;
        Eigen::VectorXd col = v_harmonic_update_tmp.block(v_index[i], j, v_index[i + 1] - v_index[i], 1).col(0);
        double epsilon = (matrixL[i]).dot(col) + a(i, j);
        double upbound = average_element_bound;
        double lowbound = -upbound;
        if (epsilon < lowbound)
        {
            v_harmonic.block(v_index[i], j, v_index[i + 1] - v_index[i], 1).col(0) = col + matrixL[i]*((lowbound - epsilon)/matrixLrowNorm[i]);
        }
        else
        {
            if (epsilon > upbound)
            {
                v_harmonic.block(v_index[i], j, v_index[i + 1] - v_index[i], 1).col(0) = col + matrixL[i]*((upbound - epsilon)/matrixLrowNorm[i]);
            }
            else
            {
                v_harmonic.block(v_index[i], j, v_index[i + 1] - v_index[i], 1).col(0) = col;
            }
        }
    }
}

void ReWeightedL2::update_w()
{
    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        prev_w.col(i) = w.col(i);
        w.col(i) = solver_smooth.solve(Lt*(v.col(i) + d1.col(i) - a.col(i)) + (x.col(i) + d2.col(i)) + (y.col(i) + d3.col(i)));
        w_diff.col(i) = w.col(i) - prev_w.col(i);
        dual_residual_v.col(i) = L*w_diff.col(i);
    }
}

void ReWeightedL2::update_w_dl()
{
    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        prev_w.col(i) = w.col(i);
        w.col(i) = solver.solve(Lt*(v.col(i) + d1.col(i) - a.col(i)) + (x.col(i) + d2.col(i)) + (y.col(i) + d3.col(i)) + (z.col(i) + d4.col(i)) + (u.col(i) + d5.col(i)));
        w_diff.col(i) = w.col(i) - prev_w.col(i);
        dual_residual_v.col(i) = L*w_diff.col(i);
    }
}

void ReWeightedL2::update_w_smooth()
{
    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        prev_w.col(i) = w.col(i);
        w.col(i) = solver_smooth.solve(Lt*(v.col(i) + d1.col(i) - a.col(i)) + (y.col(i) + d3.col(i)) + (z.col(i) + d4.col(i)));
        w_diff.col(i) = w.col(i) - prev_w.col(i);
        dual_residual_v.col(i) = L*w_diff.col(i);
    }
}

void ReWeightedL2::update_w_harmonic()
{
    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        prev_w.col(i) = w.col(i);
        w.col(i) = solver_harmonic.solve(M_edge_T*(v_harmonic.col(i) + d1_harmonic.col(i)) + (x.col(i) + d2.col(i)) + (y.col(i) + d3.col(i)));
        w_diff.col(i) = w.col(i) - prev_w.col(i);
        dual_residual_v_harmonic.col(i) = M_edge*w_diff.col(i);
    }
}

void ReWeightedL2::update_w_illustrate()
{
    #pragma omp for
    for (int i = 0; i < n_control_points; ++i)
    {
        prev_w.col(i) = w.col(i);
        w.col(i) = solver_smooth.solve(Lt*(v.col(i) + d1.col(i) - a.col(i)) + (x.col(i) + d2.col(i)));
        w_diff.col(i) = w.col(i) - prev_w.col(i);
        dual_residual_v.col(i) = L*w_diff.col(i);
    }
}

void ReWeightedL2::update_x()
{   
    #pragma omp for nowait
    for (int i = 0; i < n_total_coef; ++i)
    {
        x(i) = penalty_weight*x_update_tmp(i)/(2.0*D(i)*D(i) + penalty_weight);

        if (nonnegative_constraint())
        {
            x(i) = std::max(x(i), 0.0);
            x(i) = std::min(x(i), 1.0);
        }
    }
}

void ReWeightedL2::update_x_illustrate()
{
    #pragma omp for nowait
    for (int i = 0; i < n_total_coef; ++i)
    {
        x(i) = penalty_weight*x_update_tmp(i)/(2.0*D(i)*D(i) + penalty_weight);

        //to constraint the value between [0, 1]
//        x(i) = std::max(0.0, x(i));
//        x(i) = std::min(1.0, x(i));
    }
}

void ReWeightedL2::update_y()
{
    #pragma omp for nowait
    for (int i = 0; i < n_control_points; ++i)
    {
        y.col(i) = y_update_tmp*IminusNNt.col(i) + basey_NNt.col(i);
    }
}

void ReWeightedL2::update_y_dl()
{
    #pragma omp for nowait
    for (int i = 0; i < n_data_points; ++i)
    {
        y.row(i) = y_update_tmp.row(i) + (1.0 - (y_update_tmp.row(i)).sum())*(e_dl.row(0))/(double(n_control_points));
    }
}

void ReWeightedL2::update_z()
{
    #pragma omp for nowait
    for (int i = 0; i < n_total_coef; ++i)
    {
        z(i) = std::max(0.0, z_update_tmp(i));
        z(i) = std::min(1.0, z(i));
    }
}

void ReWeightedL2::assign_other_coordinate(Eigen::MatrixXd &otherw)
{
    initial_w = otherw;
    w = initial_w;
}

void ReWeightedL2::assign_weighted_matrix(Eigen::MatrixXd &weightedD)
{
    D = weightedD;
}

void ReWeightedL2::assign_new_smooth_bound(double laplacian_bound_min_ratio)
{
    //for whole mesh
    smooth_bound = (L*initial_w + a)*laplacian_bound_min_ratio;
    lap_bound = smooth_bound.norm();
    average_element_bound = smooth_bound.lpNorm<1>()/double(a.rows()*a.cols());
    std::cout<<"Average element bound: "<<average_element_bound<<std::endl;
}

void ReWeightedL2::init_intermediate_vars()
{
    x_update_tmp.setZero(w.rows(), w.cols());
    y_update_tmp = x_update_tmp;
    z_update_tmp = x_update_tmp;
    u_update_tmp = x_update_tmp;
    v_update_tmp.setZero(a.rows(), a.cols());
    prev_w = x_update_tmp;
    w_diff = prev_w;

    dual_residual_v.setZero(L.rows(), w_diff.cols());
    primal_residual_v.setZero(a.rows(), a.cols());
    primal_residual_x.setZero(w.rows(), w.cols());
    primal_residual_y = primal_residual_x;
    primal_residual_z = primal_residual_x;
    primal_residual_u = primal_residual_x;
}

void ReWeightedL2::zero_initialize_dual_vars()
{
    d1.setZero(a.rows(), a.cols());
    d2.setZero(n_data_points, n_control_points);
    d3.setZero(n_data_points, n_control_points);
    d4.setZero(n_data_points, n_control_points);
    d5.setZero(n_data_points, n_control_points);

    d1_bar.setZero(a.rows(), a.cols());
    d2_bar.setZero(n_data_points, n_control_points);
    d3_bar.setZero(n_data_points, n_control_points);
    d4_bar.setZero(n_data_points, n_control_points);
    d5_bar.setZero(n_data_points, n_control_points);
}

// Here we assume we have a good value of w based on initial value optimization
void ReWeightedL2::initialize_primal_vars()
{
    w_bar = w;
    x = w;
    y = w;
    z = w;
    u = w;
    v = L*w + a;
}

void ReWeightedL2::initialize_v_harmonic_vars()
{
    typedef Eigen::Triplet<double> T;
    std::vector<T> triplets_C;

    int nConstraint = 0;

    v_index.resize(n_data_points + 1);
    v_index[0] = 0;
    matrixLrowNorm.resize(n_data_points);
    matrixL.clear();
    Eigen::MatrixXd tmp_v_harmonic_val(L.nonZeros(), n_control_points);

    for (int i = 0; i < n_data_points; ++i)
    {
        int j = 0;
        int nonZeros = Lt.col(i).nonZeros();

        // Check if there are fixed-value points around the current data point
        double coef_sum = Lt.col(i).sum();
        bool fixed_neighbor = has_fixed_neighbor[i];
        int l_tmp_size = fixed_neighbor?nonZeros:(nonZeros - 1);

        Eigen::VectorXd l_tmp(l_tmp_size);

        // If there are fixed-value points, we do not have translation-invariance
        if (fixed_neighbor)
        {
            l_tmp[j++] = coef_sum;
            triplets_C.push_back(T(nConstraint, i, 1.0));
            tmp_v_harmonic_val.row(nConstraint++) = w.row(i);
        }

        for (SparseMatrixXd::InnerIterator it(Lt, i); it; ++it)
        {
            int idx = it.row();
            if (idx != i)
            {
                l_tmp[j++] = it.value();
                triplets_C.push_back(T(nConstraint, idx, 1.0));
                triplets_C.push_back(T(nConstraint, i, -1.0));
                tmp_v_harmonic_val.row(nConstraint++) = w.row(idx) - w.row(i);
            }
        }
        v_index[i + 1] = v_index[i] + l_tmp_size;
        matrixL.push_back(l_tmp);
        matrixLrowNorm[i] = l_tmp.squaredNorm();
    }

    M_edge.resize(nConstraint, n_data_points);
    M_edge.setFromTriplets(triplets_C.begin(), triplets_C.end());
    M_edge_T = M_edge.transpose();
    solver_harmonic.compute(M_edge_T*M_edge + 2.0*Iu);

    v_harmonic = tmp_v_harmonic_val.block(0,0,nConstraint, n_control_points);
    v_harmonic_update_tmp.setZero(nConstraint, n_control_points);
    d1_harmonic.setZero(nConstraint, n_control_points);
    primal_residual_v_harmonic.setZero(nConstraint, n_control_points);
    dual_residual_v_harmonic.setZero(nConstraint, n_control_points);
}

void ReWeightedL2::initialize_stopping_criteria_var()
{
    primal_residual_dim = w.rows()*w.cols()*3 + v.rows()*v.cols();
    dual_residual_dim = v.rows()*v.cols() + w.rows()*w.cols();
    primal_sqr_norm_eps = primal_residual_dim*primal_eps_val*primal_eps_val;
    final_dual_sqr_norm_eps = dual_residual_dim*dual_eps_val*dual_eps_val;
    cur_dual_sqr_norm_eps = dual_residual_dim*init_dual_eps_val*init_dual_eps_val;
}

void ReWeightedL2::initvalue_initialize_stopping_criteria_var()
{
    primal_residual_dim = w.rows()*w.cols()*3 + v.rows()*v.cols();
    dual_residual_dim = v.rows()*v.cols() + w.rows()*w.cols();
    initval_primal_residual_sqr_norm_eps = primal_residual_dim * initval_primal_eps_val * initval_primal_eps_val;
    initval_dual_residual_sqr_norm_eps = dual_residual_dim * initval_dual_eps_val * initval_dual_eps_val;
}

void ReWeightedL2::dl_initialize_stopping_criteria_var()
{
    primal_residual_dim = w.rows()*w.cols()*3 + v.rows()*v.cols();
    dual_residual_dim = v.rows()*v.cols() + w.rows()*w.cols();
    initval_primal_residual_sqr_norm_eps = primal_residual_dim * initval_primal_eps_val * initval_primal_eps_val;
    initval_dual_residual_sqr_norm_eps = dual_residual_dim * initval_dual_eps_val * initval_dual_eps_val;
}

void ReWeightedL2::smooth_initialize_stopping_criteria_var()
{
    primal_residual_dim = w.rows()*w.cols()*2 + v.rows()*v.cols();
    dual_residual_dim = v.rows()*v.cols() + w.rows()*w.cols();
    initval_primal_residual_sqr_norm_eps = primal_residual_dim * initval_primal_eps_val * initval_primal_eps_val;
    initval_dual_residual_sqr_norm_eps = dual_residual_dim * initval_dual_eps_val * initval_dual_eps_val;
}

void ReWeightedL2::harmonic_initialize_stopping_criteria_var()
{
    primal_residual_dim = w.rows()*w.cols()*2 + v_harmonic.rows()*v_harmonic.cols();
    dual_residual_dim = v_harmonic.rows()*v_harmonic.cols() + w.rows()*w.cols();
    initval_primal_residual_sqr_norm_eps = primal_residual_dim * initval_primal_eps_val * initval_primal_eps_val;
    initval_dual_residual_sqr_norm_eps = dual_residual_dim * initval_dual_eps_val * initval_dual_eps_val;
}

void ReWeightedL2::initialize_control_matrix()
{
    typedef Eigen::Triplet<double> T;
    std::vector<T> triplets_C;

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < n_control_points; ++j)
        {
            triplets_C.push_back(T(i, j, control_points(i, j)));
        }
    }

    C_dl_s.resize(dim, n_control_points);
    C_dl_s.setFromTriplets(triplets_C.begin(), triplets_C.end());
    CTC_dl_s = C_dl_s.transpose()*C_dl_s;

    pC_dl = data_points.transpose()*control_points;
}

void ReWeightedL2::initialize_solver()
{
    Iu.resize(n_data_points, n_data_points);

    typedef Eigen::Triplet<double> T;
    std::vector<T> triplets_I;
    for (int i = 0; i < n_data_points; i++)
    {
        triplets_I.push_back(T(i, i, 1.0));
    }
    Iu.setFromTriplets(triplets_I.begin(), triplets_I.end());

    dl_I.resize(n_control_points, n_control_points);
    triplets_I.clear();
    for (int i = 0; i < n_control_points; i++)
    {
        triplets_I.push_back(T(i, i, 1.0));
    }
    dl_I.setFromTriplets(triplets_I.begin(), triplets_I.end());

    solver_smooth.compute(Lt*L + Iu*2.0);
    solver.compute(Lt*L + Iu*3.0);
    solver_u_dl.compute(dl_Weight*CTC_dl_s + penalty_weight*dl_I);
}

void ReWeightedL2::solve()
{
    double start_time = omp_get_wtime();

    int iter = 0;
    this->optimization_end = false;

    omp_set_num_threads(this->nb_threads);
    while (!this->optimization_end)
    {
        iter++;
#ifdef OUTPUT_LOG
        std::cout << "Iteration " << iter << std::endl;
#endif

        #pragma omp parallel
        {
            this->compute_vxy_update_aux_vars();
            this->update_v();
            this->update_y();
            this->update_x();
            this->update_w();
            this->stop_check_and_dual_var_penalty_weight_update(iter);
        }
    }

    double end_time = omp_get_wtime();
    std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

void ReWeightedL2::solve_dl()
{
    double start_time = omp_get_wtime();

    int iter = 0;
    this->optimization_end = false;

    omp_set_num_threads(this->nb_threads);
    while (!this->optimization_end)
    {
        iter++;

        #pragma omp parallel
        {
            this->compute_uvxy_update_aux_vars();
            this->update_v();
            this->update_y_dl();
            this->update_u();
            this->update_x();
            this->update_w_dl();
            this->dl_stop_check_and_dual_var_penalty_weight_update(iter);
        }
    }

    double end_time = omp_get_wtime();
    std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

void ReWeightedL2::solve_bbw()
{
    double start_time = omp_get_wtime();

    int iter = 0;
    this->optimization_end = false;

    omp_set_num_threads(this->nb_threads);
    while (!this->optimization_end)
    {
        iter++;
#ifdef OUTPUT_LOG
        std::cout << "Iteration " << iter << std::endl;
#endif

        #pragma omp parallel
        {
            this->compute_vyz_update_aux_vars();
            this->update_v_smooth();
            this->update_y_dl();
            this->update_z();
            this->update_w_smooth();
            this->smooth_stop_check_and_dual_var_penalty_weight_update(iter);
        }
    }

    double end_time = omp_get_wtime();
    std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

void ReWeightedL2::solve_smooth()
{
    double start_time = omp_get_wtime();

    int iter = 0;
    this->optimization_end = false;

    omp_set_num_threads(this->nb_threads);
    while (!this->optimization_end)
    {
        iter++;
#ifdef OUTPUT_LOG
        std::cout << "Iteration " << iter << std::endl;
#endif

        #pragma omp parallel
        {
            this->compute_vyz_update_aux_vars();
            this->update_v_smooth();
            this->update_y();
            this->update_z();
            this->update_w_smooth();
            this->smooth_stop_check_and_dual_var_penalty_weight_update(iter);
        }
    }

    double end_time = omp_get_wtime();
    std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

void ReWeightedL2::solve_harmonic()
{
    double start_time = omp_get_wtime();

    int iter = 0;
    this->optimization_end = false;

    omp_set_num_threads(this->nb_threads);
    while (!this->optimization_end)
    {
        iter++;
#ifdef OUTPUT_LOG
        std::cout << "Iteration " << iter << std::endl;
#endif

        #pragma omp parallel
        {
            this->compute_vxyz_harmonic_update_aux_vars();
            this->update_v_harmonic();
            this->update_y();
            this->update_x();
            this->update_w_harmonic();
            this->harmonic_stop_check_and_dual_var_penalty_weight_update(iter);
        }
    }

    double end_time = omp_get_wtime();
    std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

void ReWeightedL2::solve_illustrate()
{
    double start_time = omp_get_wtime();

    int iter = 0;
    this->optimization_end = false;

    omp_set_num_threads(this->nb_threads);
    while (!this->optimization_end)
    {
        iter++;
#ifdef OUTPUT_LOG
        std::cout << "Iteration " << iter << std::endl;
#endif

        #pragma omp parallel
        {
            this->compute_vx_update_aux_vars();
            this->update_v_illustrate();
            this->update_x_illustrate();
            this->update_w_illustrate();
            this->illustrate_stop_check_and_dual_var_penalty_weight_update(iter);
        }
    }

    double end_time = omp_get_wtime();
    std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

void ReWeightedL2::initialize_y_constraint_data()
{
    Eigen::MatrixXd A;
    Eigen::MatrixXd b;

    if (linearPrecision)
    {
        A.resize(dim + 1, n_control_points);
        b.resize(dim + 1, n_data_points);
        for (int i = 0; i < n_control_points; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                A(j, i) = control_points(j, i);
            }

            A(dim, i) = 1.0;
        }
        for (int i = 0; i < n_data_points; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                b(j, i) = data_points(j, i);
            }

            b(dim, i) = 1.0;
        }
    }
    else
    {
        A.resize(1, n_control_points);
        b.resize(1, n_data_points);
        for (int i = 0; i < n_control_points; ++i)
        {
            A(0, i) = 1.0;
        }
        for (int i = 0; i < n_data_points; ++i)
        {
            b(0, i) = 1.0;
        }
    }

    Eigen::JacobiSVD< Eigen::MatrixXd, Eigen::FullPivHouseholderQRPreconditioner > jsvd(A, Eigen::ComputeFullU | Eigen::ComputeFullV);
    int nrank = jsvd.nonzeroSingularValues();
    Eigen::MatrixXd N = jsvd.matrixV().block(0, 0, n_control_points, nrank);

    Eigen::MatrixXd NNt = N*N.transpose();

    y = (jsvd.solve(b)).transpose();	// Least squares solving

    basey_NNt = y*NNt;

    IminusNNt = -NNt;
    for(int i = 0; i < n_control_points; i++)
    {
        IminusNNt(i,i) += 1.0;
    }
}

bool ReWeightedL2::compute_penalty_change_ratio()
{
    if(this->primal_residual_sqr_norm*this->initval_dual_residual_sqr_norm_eps >
            primal_dual_sqr_norm_rel_ratio_bound*this->dual_residual_sqr_norm * this->initval_primal_residual_sqr_norm_eps
            && this->penalty_weight * this->tau_incr <= this->max_penalty)
    {
        penalty_change_ratio = this->tau_incr;
        scaled_dual_change_ratio = 1.0/this->tau_incr;
        return true;
    }
    else if(this->primal_residual_sqr_norm * this->initval_dual_residual_sqr_norm_eps * primal_dual_sqr_norm_rel_ratio_bound <
                 this->dual_residual_sqr_norm * this->initval_primal_residual_sqr_norm_eps
                 && this->penalty_weight / this->tau_incr >= this->min_penalty)
    {
        penalty_change_ratio = 1.0/this->tau_incr;
        scaled_dual_change_ratio = this->tau_incr;
        return true;
    }
    else
    {
        penalty_change_ratio = 1.0 ;
        scaled_dual_change_ratio = 1.0;
        return false;
    }
}

void ReWeightedL2::stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
    int iters = 5000;
    #pragma omp single
    {
        optimization_end = false;
        optimization_converge = false;

        if (iter_num >= this->max_iteration)
        {
    #ifdef OUTPUT_LOG
            std::cout << "Max iteration reached" << std::endl;
    #endif
            optimization_end = true;
        }

    #ifdef OUTPUT_LOG
        std::cout << "Penalty Weight:" << penalty_weight << std::endl;
    #endif
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v.squaredNorm() + w_diff.squaredNorm()*2);
        }

        #pragma omp section
        {
            primal_residual_v = v - a - L*w;
            d1 += primal_residual_v;
            primal_residual_v_sqr_norm = primal_residual_v.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_x = x - w;
            d2 += primal_residual_x;
            primal_residual_x_sqr_norm = primal_residual_x.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_y = y - w;
            d3 += primal_residual_y;
            primal_residual_y_sqr_norm = primal_residual_y.squaredNorm();
        }
    }

    #pragma omp single
    {
        primal_residual_sqr_norm = primal_residual_v_sqr_norm + primal_residual_x_sqr_norm + primal_residual_y_sqr_norm;

        if (iter_num%iters == 0)
        {
            std::cout<<iter_num<<"-th step iteration:"<<std::endl;
            std::cout << "Penalty Weight: "<< penalty_weight <<std::endl;
            std::cout << "Primal Residual Squared Norm: " << primal_residual_sqr_norm << ",  tolerance:" << initval_primal_residual_sqr_norm_eps << std::endl;
            std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  tolerance:" << initval_dual_residual_sqr_norm_eps << std::endl;
        }
        need_incr_penalty = false;

        if ( primal_residual_sqr_norm <= initval_primal_residual_sqr_norm_eps && dual_residual_sqr_norm <= initval_dual_residual_sqr_norm_eps )
        {
            optimization_end = true;
            optimization_converge = true;
        }
        else
        {
            need_incr_penalty = compute_penalty_change_ratio();
            if (need_incr_penalty)
            {
                this->penalty_weight *= this->penalty_change_ratio;
            }
        }
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            if ((!optimization_end) && this->need_incr_penalty){
                d1 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if ((!optimization_end) && this->need_incr_penalty){
                d2 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if ((!optimization_end) && this->need_incr_penalty){
                d3 *= this->scaled_dual_change_ratio;
            }
        }
    }
}

void ReWeightedL2::dl_stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
    int iters = 500;
    #pragma omp single
    {
        optimization_end = false;
        optimization_converge = false;

        if(iter_num >= this->max_iteration)
        {
    #ifdef OUTPUT_LOG
            std::cout << "Max iteration reached" << std::endl;
    #endif
            optimization_end = true;
        }
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v.squaredNorm() + w_diff.squaredNorm()*3);
        }

        #pragma omp section
        {
            primal_residual_v = v - a - L*w;
            d1 += primal_residual_v;
            primal_residual_v_sqr_norm = primal_residual_v.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_x = x - w;
            d2 += primal_residual_x;
            primal_residual_x_sqr_norm = primal_residual_x.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_y = y - w;
            d3 += primal_residual_y;
            primal_residual_y_sqr_norm = primal_residual_y.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_u = u - w;
            d5 += primal_residual_u;
            primal_residual_u_sqr_norm = primal_residual_u.squaredNorm();
        }
    }

    #pragma omp single
    {
        primal_residual_sqr_norm = primal_residual_v_sqr_norm + primal_residual_x_sqr_norm + primal_residual_y_sqr_norm + primal_residual_u_sqr_norm;
        if (iter_num%iters == 0)
        {
            std::cout<<iter_num<<"-th step iteration:"<<std::endl;
            std::cout << "Primal Residual Squared Norm: " << primal_residual_sqr_norm << ",  tolerance:" << initval_primal_residual_sqr_norm_eps << std::endl;
            std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  tolerance:" << initval_dual_residual_sqr_norm_eps << std::endl;
        }
        need_incr_penalty = false;

        if (primal_residual_sqr_norm <= initval_primal_residual_sqr_norm_eps && dual_residual_sqr_norm <= initval_dual_residual_sqr_norm_eps)
        {
            optimization_end = true;
            optimization_converge = true;
        }
        else
        {
            need_incr_penalty = compute_penalty_change_ratio();
            if (need_incr_penalty)
            {
                this->penalty_weight *= this->penalty_change_ratio;
                solver_u_dl.compute(dl_Weight*CTC_dl_s + penalty_weight*dl_I);
            }
        }
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d1 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d2 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d3 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d5 *= this->scaled_dual_change_ratio;
            }
        }
    }
}

void ReWeightedL2::smooth_stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
    int iters = 100;
    #pragma omp single
    {
        optimization_end = false;
        optimization_converge = false;

        if(iter_num >= this->max_iteration)
        {
    #ifdef OUTPUT_LOG
            std::cout << "Max iteration reached" << std::endl;
    #endif
            optimization_end = true;
        }

    #ifdef OUTPUT_LOG
        std::cout << "Penalty Weight:" << penalty_weight << std::endl;
    #endif
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v.squaredNorm() + w_diff.squaredNorm()*2);
        }

        #pragma omp section
        {
            primal_residual_v = v - a - L*w;
            d1 += primal_residual_v;
            primal_residual_v_sqr_norm = primal_residual_v.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_y = y - w;
            d3 += primal_residual_y;
            primal_residual_y_sqr_norm = primal_residual_y.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_z = z - w;
            d4 += primal_residual_z;
            primal_residual_z_sqr_norm = primal_residual_z.squaredNorm();
        }
    }

    #pragma omp single
    {
        primal_residual_sqr_norm = primal_residual_v_sqr_norm + primal_residual_y_sqr_norm + primal_residual_z_sqr_norm;
        if (iter_num%iters == 0)
        {
            std::cout<<iter_num<<"-th step iteration:"<<std::endl;
            std::cout << "Primal Residual Squared Norm: " << primal_residual_sqr_norm << ",  tolerance:" << initval_primal_residual_sqr_norm_eps << std::endl;
            std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  tolerance:" << initval_dual_residual_sqr_norm_eps << std::endl;
        }
        need_incr_penalty = false;

        if( primal_residual_sqr_norm <= initval_primal_residual_sqr_norm_eps && dual_residual_sqr_norm <= initval_dual_residual_sqr_norm_eps ){
            optimization_end = true;
            optimization_converge = true;
        }
        else{
            need_incr_penalty = compute_penalty_change_ratio();
            if(need_incr_penalty){
                this->penalty_weight *= this->penalty_change_ratio;
            }
        }
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d1 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d3 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d4 *= this->scaled_dual_change_ratio;
            }
        }
    }
}

void ReWeightedL2::harmonic_stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
    int iters = 5000;
    #pragma omp single
    {
        optimization_end = false;
        optimization_converge = false;

        if (iter_num >= this->max_iteration)
        {
    #ifdef OUTPUT_LOG
            std::cout << "Max iteration reached" << std::endl;
    #endif
            optimization_end = true;
        }

    #ifdef OUTPUT_LOG
        std::cout << "Penalty Weight:" << penalty_weight << std::endl;
    #endif
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v_harmonic.squaredNorm() + w_diff.squaredNorm()*2);
        }

        #pragma omp section
        {
            primal_residual_v_harmonic = v_harmonic - M_edge*w;
            d1_harmonic += primal_residual_v_harmonic;
            primal_residual_v_sqr_norm = primal_residual_v_harmonic.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_x = x - w;
            d2 += primal_residual_x;
            primal_residual_x_sqr_norm = primal_residual_x.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_y = y - w;
            d3 += primal_residual_y;
            primal_residual_y_sqr_norm = primal_residual_y.squaredNorm();
        }
    }

    #pragma omp single
    {
        primal_residual_sqr_norm = primal_residual_v_sqr_norm + primal_residual_x_sqr_norm + primal_residual_y_sqr_norm;
        if (iter_num%iters == 0)
        {
            std::cout<<iter_num<<"-th step iteration:"<<std::endl;
            std::cout << "Penalty Weight: "<< penalty_weight <<std::endl;
            std::cout << "Primal Residual Squared Norm: " << primal_residual_sqr_norm << ",  tolerance:" << initval_primal_residual_sqr_norm_eps << std::endl;
            std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  tolerance:" << initval_dual_residual_sqr_norm_eps << std::endl;
        }
        need_incr_penalty = false;

        if( primal_residual_sqr_norm <= initval_primal_residual_sqr_norm_eps && dual_residual_sqr_norm <= initval_dual_residual_sqr_norm_eps )
        {
            optimization_end = true;
            optimization_converge = true;
        }
        else
        {
            need_incr_penalty = compute_penalty_change_ratio();
            if(need_incr_penalty)
            {
                this->penalty_weight *= this->penalty_change_ratio;
            }
        }
    }

    #pragma omp single
    {
        if((!optimization_end) && this->need_incr_penalty)
        {
            d1_harmonic *= this->scaled_dual_change_ratio;
        }

        if((!optimization_end) && this->need_incr_penalty)
        {
            d2 *= this->scaled_dual_change_ratio;
        }

        if((!optimization_end) && this->need_incr_penalty)
        {
            d3 *= this->scaled_dual_change_ratio;
        }
    }
}

void ReWeightedL2::illustrate_stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
    int iters = 100;
    #pragma omp single
    {
        optimization_end = false;
        optimization_converge = false;

        if (iter_num >= this->max_iteration)
        {
    #ifdef OUTPUT_LOG
            std::cout << "Max iteration reached" << std::endl;
    #endif
            optimization_end = true;
        }

    #ifdef OUTPUT_LOG
        std::cout << "Penalty Weight:" << penalty_weight << std::endl;
    #endif
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v.squaredNorm() + w_diff.squaredNorm()*2);
        }

        #pragma omp section
        {
            primal_residual_v = v - a - L*w;
            d1 += primal_residual_v;
            primal_residual_v_sqr_norm = primal_residual_v.squaredNorm();
        }

        #pragma omp section
        {
            primal_residual_x = x - w;
            d2 += primal_residual_x;
            primal_residual_x_sqr_norm = primal_residual_x.squaredNorm();
        }
    }

    #pragma omp single
    {
        primal_residual_sqr_norm = primal_residual_v_sqr_norm + primal_residual_x_sqr_norm;

        if (iter_num%iters == 0)
        {
            std::cout<<iter_num<<"-th step iteration:"<<std::endl;
            std::cout << "Primal Residual Squared Norm: " << primal_residual_sqr_norm << ",  tolerance:" << initval_primal_residual_sqr_norm_eps << std::endl;
            std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  tolerance:" << initval_dual_residual_sqr_norm_eps << std::endl;
        }
        need_incr_penalty = false;

        if( primal_residual_sqr_norm <= initval_primal_residual_sqr_norm_eps && dual_residual_sqr_norm <= initval_dual_residual_sqr_norm_eps )
        {
            optimization_end = true;
            optimization_converge = true;
        }
        else
        {/*
            need_incr_penalty = compute_penalty_change_ratio();
            if(need_incr_penalty)
            {
                this->penalty_weight *= this->penalty_change_ratio;
                std::cout << "Penalty Weight:" << penalty_weight << std::endl;
            }*/
        }
    }

    #pragma omp sections
    {
        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d1 *= this->scaled_dual_change_ratio;
            }
        }

        #pragma omp section
        {
            if((!optimization_end) && this->need_incr_penalty){
                d2 *= this->scaled_dual_change_ratio;
            }
        }
    }
}
}}
