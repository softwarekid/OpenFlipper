/*
 * SBCOpt.cpp
 *
 *  Created on: Nov 10, 2012
 *      Author: Bailin Deng
 */

#include "SBCOpt.h"
#include <algorithm>
#include <omp.h>
#include <gsl/gsl_poly.h>
#include <Eigen/Cholesky>
#include <Eigen/LU>


namespace Dolphin {

namespace plugins {
void SBCOptBase::init_variables(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio, double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_, double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_, int max_iter, int primal_max_iter, double dlweight_, bool linearPrecision_)
{
	this->nb_threads = num_threads;
	this->penalty_weight = init_penalty_weight_;
	this->min_penalty = init_penalty_weight_ * 0.01;
	this->tau_incr = tau_incr_;
	this->dual_sqaured_norm_eps_decr_ratio = this->tau_incr;
	this->max_iteration = max_iter;
	this->primal_subproblem_maxiter = primal_max_iter;
	this->primal_eps_val = primal_eps_val_;
	this->dual_eps_val = dual_eps_val_;
	this->init_dual_eps_val = init_dual_eps_;
	this->initval_primal_eps_val = initval_primal_eps_;
	this->initval_dual_eps_val = initval_dual_eps_;
	this->current_primal_run_start_iter = 0;
	this->primal_dual_sqr_norm_rel_ratio_bound = 100;
	this->weight_dl = dlweight_;
    this->linearPrecision = linearPrecision_;
	this->min_sqr_primal_residual_change_ratio = 0.7 * 0.7;
	this->max_penalty = std::max(max_penalty_weight, penalty_weight * std::pow(init_dual_eps_val/dual_eps_val, 2) + 1.0);
	e_dl.setOnes(1, n_control_points);

    initialize_fairness_energy_matrix();
	initialize_control_matrix();
	initialize_data_matrix();
	initialize_solver();
	initialize_y_constraint_data();
	initialvalue_init_primal_vars();
	zero_initialize_dual_vars();
	init_intermediate_vars();
	initvalue_initialize_stopping_criteria_var();
	initialvalue_solve();
	init_w = w;

    lap_energy_bound.resize(n_data_points);
    for (int i = 0; i < n_data_points; ++i)
    {
        this->min_lap_energy(i) = (v.row(i).norm() > (L*w + a).row(i).norm())?v.row(i).norm():(L*w + a).row(i).norm();
        this->lap_energy_bound(i) = (laplacian_energy_bound > laplacian_bound_min_ratio*this->min_lap_energy(i))?laplacian_energy_bound:laplacian_bound_min_ratio*this->min_lap_energy(i);
    }

	this->penalty_weight = init_penalty_weight_;
	initialize_primal_vars();
	zero_initialize_dual_vars();
	initialize_stopping_criteria_var();
	dl_initialize_stopping_criteria_var();
	initialize_primal_residual_norm();
}

void SBCOptBase::compute_uvxyz_update_aux_vars()
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
			z_update_tmp = w - d4;
		}

		#pragma omp section
		{
			u_update_tmp = w - d5;
		}
	}

	#pragma omp for
	for(int i = 0; i < n_control_points; i++){
		v_update_tmp.col(i) = L*w.col(i) + a.col(i) - d1.col(i);
	}
}

void SBCOptBase::compute_vxyz_update_aux_vars()
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
			z_update_tmp = w - d4;
		}
	}

	#pragma omp for
	for(int i = 0; i < n_control_points; i++){
		v_update_tmp.col(i) = L*w.col(i) + a.col(i) - d1.col(i);
	}
}

void SBCOptBase::compute_vyz_update_aux_vars()
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
	for(int i = 0; i < n_control_points; i++){
		v_update_tmp.col(i) = L * w.col(i) + a.col(i) - d1.col(i);
	}
}

void SBCOptBase::initialvalue_update_w()
{
	#pragma omp for
	for(int i = 0; i < n_control_points; ++i ){
		prev_w.col(i) = w.col(i);
		w.col(i) = initialvalue_solver.solve( L * (v.col(i) + d1.col(i) - a.col(i)) + y.col(i) + d3.col(i) + z.col(i) + d4.col(i) );
		w_diff.col(i) = w.col(i) - prev_w.col(i);
		dual_residual_v.col(i) = L * w_diff.col(i);
	}
}

void SBCOptBase::update_w()
{
	#pragma omp for
	for(int i = 0; i < n_control_points; ++i){
		prev_w.col(i) = w.col(i);
		w.col(i) = solver.solve(L*(v.col(i) + d1.col(i) - a.col(i)) + x.col(i) + d2.col(i) + y.col(i) + d3.col(i) + z.col(i) + d4.col(i));
		w_diff.col(i) = w.col(i) - prev_w.col(i);
		dual_residual_v.col(i) = L*w_diff.col(i);
	}
}

void SBCOptBase::update_w_dl()
{
	#pragma omp for
	for(int i = 0; i < n_control_points; ++i){
		prev_w.col(i) = w.col(i);
		w.col(i) = solver_dl.solve(L*(v.col(i) + d1.col(i) - a.col(i)) + x.col(i) + d2.col(i) + y.col(i) + d3.col(i) + z.col(i) + d4.col(i) + u.col(i) + d5.col(i));
		w_diff.col(i) = w.col(i) - prev_w.col(i);
		dual_residual_v.col(i) = L*w_diff.col(i);
	}
}

void SBCOptBase::update_y()
{
	#pragma omp for nowait
    for(int i = 0; i < n_control_points; ++i)
    {
		y.col(i) = y_update_tmp*IminusNNt.col(i) + basey_NNt.col(i);
	}
}

void SBCOptBase::update_y_dl()
{
	#pragma omp for nowait
	for (int i = 0; i < n_data_points; ++i)
	{
		y.row(i) = y_update_tmp.row(i) + (1.0 - (y_update_tmp.row(i)).sum())*(e_dl.row(0))/(double(n_control_points));
	}
}

void SBCOptBase::initialize_control_matrix()
{
	int pt_dim = this->point_dim();
	C_dl.resize(pt_dim, n_control_points);

	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_C;

	for(int i = 0; i < n_control_points; ++i)
	{
		double *cp = this->control_point_coord(i);
		for(int j = 0; j < pt_dim; ++j)
		{
			C_dl(j, i) = cp[j];
			triplets_C.push_back(T(j, i, cp[j]));
		}
	}

	C_dl_s.resize(pt_dim, n_control_points);
	C_dl_s.setFromTriplets(triplets_C.begin(), triplets_C.end());
}

void SBCOptBase::assign_other_coordinate(Eigen::MatrixXd &otherw)
{
    w = otherw;
}

void SBCOptBase::initialize_data_matrix()
{
	int pt_dim = this->point_dim();
	p_dl.resize(n_data_points, pt_dim);

	for(int i = 0; i < n_data_points; i++)
	{
		double *cp = this->data_point_coord(i);
		for(int j = 0; j < pt_dim; j++)
		{
			p_dl(i, j) = cp[j];
		}
	}

	pC_dl = p_dl*C_dl;
}

void SBCOptBase::init_intermediate_vars()
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

void SBCOptBase::zero_initialize_dual_vars()
{
	d1.setZero(this->n_data_points, this->n_control_points);
	d2.setZero(this->n_data_points, this->n_control_points);
	d3.setZero(this->n_data_points, this->n_control_points);
	d4.setZero(this->n_data_points, this->n_control_points);
	d5.setZero(this->n_data_points, this->n_control_points);
}

// Here we assume we have a good value of w based on initial value optimization
void SBCOptBase::initialize_primal_vars()
{
	x = w;
	y = w;
	z = w;
	v = L*w + a;
	u = w;
}

void SBCOptBase::dl_initialize_stopping_criteria_var()
{
	primal_residual_dim_dl = w.rows()*w.cols()*4 + v.rows()*v.cols();
	dual_residual_dim_dl = v.rows()*v.cols() + w.rows()*w.cols();
	primal_sqr_norm_eps_dl = primal_residual_dim_dl*primal_eps_val*primal_eps_val;
	final_dual_sqr_norm_eps_dl = dual_residual_dim_dl*dual_eps_val*dual_eps_val;
	cur_dual_sqr_norm_eps_dl = dual_residual_dim_dl*init_dual_eps_val*init_dual_eps_val;
}

void SBCOptBase::initialize_stopping_criteria_var()
{
	primal_residual_dim = w.rows()*w.cols()*3 + v.rows()*v.cols();
	dual_residual_dim = v.rows()*v.cols() + w.rows()*w.cols();
	primal_sqr_norm_eps = primal_residual_dim * primal_eps_val * primal_eps_val;
	final_dual_sqr_norm_eps = dual_residual_dim * dual_eps_val * dual_eps_val;
	cur_dual_sqr_norm_eps = dual_residual_dim * init_dual_eps_val * init_dual_eps_val;
}

void SBCOptBase::initvalue_initialize_stopping_criteria_var()
{
	primal_residual_dim = w.rows()*w.cols()*3 + v.rows()*v.cols();
	dual_residual_dim = v.rows()*v.cols() + w.rows()*w.cols();
	initval_primal_residual_sqr_norm_eps = primal_residual_dim * initval_primal_eps_val * initval_primal_eps_val;
	initval_dual_residual_sqr_norm_eps = dual_residual_dim * initval_dual_eps_val * initval_dual_eps_val;
}

void SBCOptBase::initialvalue_init_primal_vars()
{
	w = y;
	x = w;
	z = w;
	v = L*w + a;
	u = w;
    //min_lap_energy = v.norm();
    min_lap_energy = v.rowwise().norm();
}

void SBCOptBase::update_z()
{
	#pragma omp for nowait
    for (int i = 0; i < n_total_coef; ++ i)
    {
        if (nonnegative_constraint())
        {
            z(i) = std::max(0.0, z_update_tmp(i));
        }
        else
        {
            //to test no bound on w_i
            z(i) = z_update_tmp(i);
        }
	}
}

void SBCOptBase::update_v()
{
	#pragma omp single nowait
    {/*
		double a_ = v_update_tmp.norm();
		if(a_ <= lap_energy_bound)
		{
			v = v_update_tmp;
		}
		else
		{
			v = v_update_tmp*(lap_energy_bound/a_);
        }*/

        //bound laplacian distortion for each vertex
        for (int i = 0; i < n_data_points; ++i)
        {
            double distortion = lap_energy_bound(i);
            double a_ = v_update_tmp.row(i).norm();
            if (a_ <= distortion)
            {
                v.row(i) = v_update_tmp.row(i);
            }
            else
            {
                v.row(i) = v_update_tmp.row(i)*(distortion/a_);
            }
        }
	}
}

void SBCOptBase::update_u()
{
	#pragma omp single nowait
	for (int i = 0; i < n_data_points; ++i)
	{
		u.row(i) = (solver_u.solve((weight_dl*pC_dl.row(i) + penalty_weight*(u_update_tmp.row(i))).transpose())).transpose();
	}
}

void SBCOptBase::initialvalue_update_v()
{
	#pragma omp single nowait
	{
		v = v_update_tmp*(this->penalty_weight/(1.0 + this->penalty_weight));
	}
}

void SBCOptBase::initialize_solver()
{
	SparseMatrixXd I(n_data_points, n_data_points);

	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_I;
	for(int i = 0; i < n_data_points; i++){
		triplets_I.push_back(T(i, i, 1.0));
	}
	I.setFromTriplets(triplets_I.begin(), triplets_I.end());
	Lt = L.transpose();

	Iu.resize(n_control_points, n_control_points);
	std::vector<T> triplets_Iu;
	for(int i = 0; i < n_control_points; i++){
		triplets_Iu.push_back(T(i, i, 1.0));
	}
	Iu.setFromTriplets(triplets_Iu.begin(), triplets_Iu.end());

	SparseMatrixXd LtL = Lt*L;
	SparseMatrixXd M1 = LtL + I*3.0;
	SparseMatrixXd M2 = LtL + I*2.0;
	SparseMatrixXd M3 = LtL + I*4.0;
	CTC_dl_s = C_dl_s.transpose()*C_dl_s;
	SparseMatrixXd M4 = weight_dl*CTC_dl_s + penalty_weight*Iu;

	std::cout<<"original penalty weight: "<<penalty_weight<<std::endl;

	solver.compute(M1);
	initialvalue_solver.compute(M2);
	solver_dl.compute(M3);
	solver_u.compute(M4);
}

void SBCOptBase::initialvalue_solve()
{
	double start_time = omp_get_wtime();

	int iter = 0;
	this->optimization_end = false;

	omp_set_num_threads(this->nb_threads);
	while(!this->optimization_end){
		iter++;
#ifdef OUTPUT_LOG
		std::cout << "Iteration " << iter << std::endl;
#endif

		#pragma omp parallel
		{
			this->compute_vyz_update_aux_vars();
			this->initialvalue_update_v();
			this->update_y();
			this->update_z();
			this->initialvalue_update_w();
			this->initialvalue_stop_check_and_dual_var_penalty_weight_update(iter);
		}
	}

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds for initialization" << std::endl;
}

void SBCOptBase::initialize_y_constraint_data()
{
	int pt_dim = this->point_dim();

    Eigen::MatrixXd A;
    Eigen::MatrixXd b;

    if (linearPrecision)
    {
        A.resize(pt_dim + 1, n_control_points);
        b.resize(pt_dim + 1, n_data_points);
        for(int i = 0; i < n_control_points; ++i)
        {
            double *cp = this->control_point_coord(i);
            for(int j = 0; j < pt_dim; ++j)
            {
                A(j, i) = cp[j];
            }

            A(pt_dim, i) = 1.0;
        }

        for(int i = 0; i < n_data_points; ++i)
        {
            double *dp = this->data_point_coord(i);
            for(int j = 0; j < pt_dim; ++j)
            {
                b(j, i) = dp[j];
            }

            b(pt_dim, i) = 1.0;
        }
    }
    else
    {
        A.resize(1, n_control_points);
        b.resize(1, n_data_points);
        for(int i = 0; i < n_control_points; ++i)
        {
            A(0, i) = 1.0;
        }

        for(int i = 0; i < n_data_points; ++i)
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

bool SBCOptBase::compute_penalty_change_ratio()
{
	if(this->primal_residual_sqr_norm*this->initval_dual_residual_sqr_norm_eps >
			primal_dual_sqr_norm_rel_ratio_bound*this->dual_residual_sqr_norm * this->initval_primal_residual_sqr_norm_eps
			&& this->penalty_weight * this->tau_incr <= this->max_penalty){
		penalty_change_ratio = this->tau_incr;
		scaled_dual_change_ratio = 1.0 / this->tau_incr;
		return true;
	}
	else if(this->primal_residual_sqr_norm * this->initval_dual_residual_sqr_norm_eps * primal_dual_sqr_norm_rel_ratio_bound <
				 this->dual_residual_sqr_norm * this->initval_primal_residual_sqr_norm_eps
				 && this->penalty_weight / this->tau_incr >= this->min_penalty){
		penalty_change_ratio = 1.0 / this->tau_incr;
		scaled_dual_change_ratio = this->tau_incr;
		return true;
	}
	else{
		penalty_change_ratio = 1.0 ;
		scaled_dual_change_ratio = 1.0;
		return false;
	}
}

void SBCOptBase::initialvalue_stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
	#pragma omp single
	{
		optimization_end = false;
		optimization_converge = false;

		if(iter_num >= this->max_iteration){
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
        if (iter_num%50 == 0)
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
				std::cout << "Penalty Weight:" << penalty_weight << std::endl;
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

void SBCOptBase::stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
    int print_iter = 2000;

	#pragma omp single
    {
		optimization_end = false;
		need_incr_penalty = false;
		optimization_converge = false;
		primal_subproblem_converge = false;
		dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v.squaredNorm() + w_diff.squaredNorm()*3);

		if(iter_num >= this->max_iteration)
		{
#ifdef OUTPUT_LOG
			std::cout << "Max iteration reached" << std::endl;
#endif
			optimization_end = true;
		}

		// If optimization ends because of max_iteartion, we still update the penalty weight and
		if((!optimization_end) || iter_num == max_iteration)
        {
            if (iter_num%print_iter == 0)
            {
                std::cout<<"Dual Residual Squared Norm: " << dual_residual_sqr_norm<<",  Tolerance:" << cur_dual_sqr_norm_eps << std::endl;
                std::cout << "Prev primal residual squared norm:" << prev_outer_primal_residual_sqr_norm << ", Toleraence" << primal_sqr_norm_eps << std::endl;
            }

			if((dual_residual_sqr_norm <= cur_dual_sqr_norm_eps) || (iter_num - current_primal_run_start_iter >= primal_subproblem_maxiter)){
				primal_subproblem_converge = true;
				current_primal_run_start_iter = iter_num;
			}
#ifdef OUTPUT_LOG
			else{
				std::cout << "Not converge yet" << std::endl;
			}
#endif
		}
#ifdef OUTPUT_LOG
		std::cout << "Penalty Weight:" << penalty_weight << std::endl;
#endif
	}

	#pragma omp sections
	{
		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_v = v - a - L * w;
				primal_residual_v_sqr_norm = primal_residual_v.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_x = x - w;
				primal_residual_x_sqr_norm = primal_residual_x.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_y = y - w;
				primal_residual_y_sqr_norm = primal_residual_y.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_z = z - w;
				primal_residual_z_sqr_norm = primal_residual_z.squaredNorm();
			}
		}

	}

	#pragma omp single
	{
		// Determine residual change ratio
		if(primal_subproblem_converge){
			scaled_dual_change_ratio = 1.0;
			primal_residual_sqr_norm = primal_residual_v_sqr_norm + primal_residual_x_sqr_norm + primal_residual_y_sqr_norm + primal_residual_z_sqr_norm;

            if (iter_num%print_iter == 0)
            {
                std::cout << "Primal residual squared norm:" << primal_residual_sqr_norm << ",  tolerance:" << primal_sqr_norm_eps << std::endl;
            }

			if( primal_residual_sqr_norm <= primal_sqr_norm_eps && dual_residual_sqr_norm <= final_dual_sqr_norm_eps){
				std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  Tolerance:" << final_dual_sqr_norm_eps << std::endl;
				std::cout << "Prev primal residual squared norm:" << primal_residual_sqr_norm << ", Toleraence" << primal_sqr_norm_eps << std::endl;
				optimization_end = true;
				optimization_converge = true;

#ifdef OUTPUT_LOG
				std::cout << "Optimization converges" << std::endl;
#endif
			}
			else if(penalty_weight * tau_incr <= max_penalty){

				if(dual_residual_sqr_norm <= cur_dual_sqr_norm_eps){
					need_incr_penalty = need_increment_penalty();
					if(need_incr_penalty){
						penalty_weight *= tau_incr;
                        scaled_dual_change_ratio  = 1.0/tau_incr;
					}

					// Decrease dual residual squared norm
					cur_dual_sqr_norm_eps = std::max( cur_dual_sqr_norm_eps / dual_sqaured_norm_eps_decr_ratio , final_dual_sqr_norm_eps);
					prev_outer_primal_residual_sqr_norm = primal_residual_sqr_norm;
				}
			}
		}
	}

	#pragma omp sections
	{		
		#pragma omp section
		{
			if(primal_subproblem_converge){
				d5 += primal_residual_u;
				d5 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d1 += primal_residual_v;
				d1 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d2 += primal_residual_x;
				d2 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d3 += primal_residual_y;
				d3 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d4 += primal_residual_z;
				d4 *= scaled_dual_change_ratio;
			}
		}
	}
}

void SBCOptBase::dl_stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
	#pragma omp single
	{
		if (iter_num%20 == 0)
		{
			//compute sparsity energy
			double wnorm0 = 0, whalfnorm = 0;
			double initwnorm0 = 0, initwhalfnorm = 0;
            for (int i = 0; i < x.rows(); ++i)
			{
				double wvec = 0, initwvec = 0;
                for (int j = 0; j < x.cols(); ++j)
				{
                    if (x(i, j) != 0)
						wnorm0++;
					if (init_w(i, j) != 0)
						initwnorm0++;
                    wvec += sqrt(fabs(x(i, j)));
					initwvec += sqrt(fabs(init_w(i, j)));
				}
				whalfnorm += wvec*wvec;
                initwhalfnorm += initwvec*initwvec;
			}
            std::cout<<iter_num<<"-th step iteration:"<<std::endl;
			std::cout<<"init w 0 norm: "<<initwnorm0<<"; 0.5 norm: "<<initwhalfnorm<<std::endl;
			std::cout<<"current w 0 norm: "<<wnorm0<<"; 0.5 norm: "<<whalfnorm<<std::endl;
			std::cout<<"init w smoothness: "<<(L*init_w + a).norm()<<std::endl;
			std::cout<<"current w smoothness: "<<(L*w + a).norm()<<std::endl;
			std::cout<<"position error: "<<(w*C_dl.transpose() - p_dl).norm()<<std::endl;
			//end of computing sparsity energy
		}

		optimization_end = false;
		need_incr_penalty = false;
		optimization_converge = false;
		primal_subproblem_converge = false;
		dual_residual_sqr_norm = penalty_weight*penalty_weight*(dual_residual_v.squaredNorm() + w_diff.squaredNorm()*4);

		if(iter_num >= this->max_iteration)
		{
#ifdef OUTPUT_LOG
			std::cout << "Max iteration reached" << std::endl;
#endif
			optimization_end = true;
		}

		// If optimization ends because of max_iteartion, we still update the penalty weight and
		if((!optimization_end) || iter_num == max_iteration)
		{
#ifdef OUTPUT_LOG
			std::cout<<"Dual Residual Squared Norm: " << dual_residual_sqr_norm<<",  Tolerance:" << cur_dual_sqr_norm_eps_dl << std::endl;
			std::cout << "Prev primal residual squared norm:" << prev_outer_primal_residual_sqr_norm << ", Toleraence" << primal_sqr_norm_eps_dl << std::endl;
#endif

			if((dual_residual_sqr_norm <= cur_dual_sqr_norm_eps_dl) || (iter_num - current_primal_run_start_iter >= primal_subproblem_maxiter)){
				primal_subproblem_converge = true;
				current_primal_run_start_iter = iter_num;
			}
#ifdef OUTPUT_LOG
			else{
				std::cout << "Not converge yet" << std::endl;
			}
#endif
		}
#ifdef OUTPUT_LOG
		std::cout << "Penalty Weight:" << penalty_weight << std::endl;
#endif
	}

	#pragma omp sections
	{
		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_v = v - a - L*w;
				primal_residual_v_sqr_norm = primal_residual_v.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_x = x - w;
				primal_residual_x_sqr_norm = primal_residual_x.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_y = y - w;
				primal_residual_y_sqr_norm = primal_residual_y.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_z = z - w;
				primal_residual_z_sqr_norm = primal_residual_z.squaredNorm();
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				primal_residual_u = u - w;
				primal_residual_u_sqr_norm = primal_residual_u.squaredNorm();
			}
		}
	}

	#pragma omp single
	{
		// Determine residual change ratio
		if(primal_subproblem_converge)
		{
			scaled_dual_change_ratio = 1.0;
			primal_residual_sqr_norm = primal_residual_u_sqr_norm + primal_residual_v_sqr_norm + primal_residual_x_sqr_norm + primal_residual_y_sqr_norm + primal_residual_z_sqr_norm;

#ifdef OUTPUT_LOG
			std::cout << "Primal residual squared norm:" << primal_residual_sqr_norm << ",  tolerance:" << primal_sqr_norm_eps_dl << std::endl;
#endif

			if( primal_residual_sqr_norm <= primal_sqr_norm_eps_dl && dual_residual_sqr_norm <= final_dual_sqr_norm_eps_dl){
				std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  Tolerance:" << final_dual_sqr_norm_eps_dl << std::endl;
				std::cout << "Prev primal residual squared norm:" << primal_residual_sqr_norm << ", Toleraence" << primal_sqr_norm_eps_dl << std::endl;
				optimization_end = true;
				optimization_converge = true;

#ifdef OUTPUT_LOG
				std::cout << "Optimization converges" << std::endl;
#endif
			}
			else if(penalty_weight*tau_incr <= max_penalty){

				if(dual_residual_sqr_norm <= cur_dual_sqr_norm_eps_dl){
					need_incr_penalty = need_increment_penalty_dl();

					if(need_incr_penalty){
						penalty_weight *= tau_incr;
						solver_u.compute(weight_dl*CTC_dl_s + penalty_weight*Iu);
						scaled_dual_change_ratio  = 1.0 / tau_incr;
					}

					// Decrease dual residual squared norm
					cur_dual_sqr_norm_eps_dl = std::max( cur_dual_sqr_norm_eps_dl / dual_sqaured_norm_eps_decr_ratio , final_dual_sqr_norm_eps_dl);
					prev_outer_primal_residual_sqr_norm = primal_residual_sqr_norm;
				}
			}
		}
	}

	#pragma omp sections
	{
		#pragma omp section
		{
			if(primal_subproblem_converge){
				d5 += primal_residual_u;
				d5 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d1 += primal_residual_v;
				d1 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d2 += primal_residual_x;
				d2 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d3 += primal_residual_y;
				d3 *= scaled_dual_change_ratio;
			}
		}

		#pragma omp section
		{
			if(primal_subproblem_converge){
				d4 += primal_residual_z;
				d4 *= scaled_dual_change_ratio;
			}
		}
	}
}

bool SBCOptBase::need_increment_penalty()
{
	return primal_residual_sqr_norm > std::max(primal_sqr_norm_eps, min_sqr_primal_residual_change_ratio * prev_outer_primal_residual_sqr_norm);
}

bool SBCOptBase::need_increment_penalty_dl()
{
	return primal_residual_sqr_norm > std::max(primal_sqr_norm_eps_dl, min_sqr_primal_residual_change_ratio*prev_outer_primal_residual_sqr_norm);
}

void SBCL0Update::update_x()
{
	#pragma omp for
    for(int i = 0; i < n_total_coef; i++)
    {
        //for L_0 update
        //x(i) = (this->x_update_tmp(i)*this->x_update_tmp(i)*this->penalty_weight <= 1.0)?0.0:this->x_update_tmp(i);

        //tsp paper method
        double t = this->x_update_tmp(i);
        double fabs_t = std::max(1.0e-8, std::fabs(t));
        double mu = 1.0/(2.0*this->penalty_weight);
        x(i) = (fabs_t - mu/std::sqrt(fabs_t) > 0)?(fabs_t - mu/std::sqrt(fabs_t))*sgn(t):0.0;
	}
}

void SBCHalfNormUpdate::update_x_bailin()
{
	#pragma omp for
    for(int i = 0; i < n_total_coef; i++)
    {
		double v = this->x_update_tmp(i);
        if( v == 0)
        {
			x(i) = 0;
		}
        else
        {
			double roots[3];
            int n_root = gsl_poly_solve_cubic(-2*v, v*v, (v>0 ? -1:1)/(16*this->penalty_weight*this->penalty_weight), &(roots[0]), &(roots[1]), &(roots[2]));
            if(n_root == 0)
            {
				x(i) = 0;
			}
            else
            {
				std::vector<double> candidate_roots;
                if(v > 0)
                {
                    for(int j = 0; j < n_root; j++)
                    {
                        if(roots[j] >= 2.0*v/3 && roots[j] <= v)
                        {
							candidate_roots.push_back(roots[j]);
						}
					}
				}
                else
                {
                    for(int j = 0; j < n_root; j++)
                    {
                        if(roots[j] <= 2.0*v/3 && roots[j] >= v)
                        {
							candidate_roots.push_back(roots[j]);
						}
					}
				}

                if(candidate_roots.empty())
                {
					x(i) = 0;
				}
                else
                {
                    if(candidate_roots.size() == 1)
                    {
                        x(i) = candidate_roots.front();
					}
                    else
                    {
						double best_root = candidate_roots.front();
						double min_val = func_val(candidate_roots.front(), v);
                        for(int j = 1; j < static_cast<int>(candidate_roots.size()); j++)
                        {
							double cur_val = func_val(candidate_roots[j], v);
                            if(cur_val < min_val)
                            {
								min_val = cur_val;
								best_root = candidate_roots[j];
							}
                        }

                        x(i) = best_root;
					}
				}
			}
		}
	}
}

void SBCHalfNormUpdate::update_x()
{
    #pragma omp for
    for (int i = 0; i < n_total_coef; ++i)
    {
        double v = fabs(this->x_update_tmp(i));
        double mu = 0.5*this->penalty_weight;

        double w_star = 0.25*pow(mu, -2./3.);
        double a0 = 3.0*w_star;
        if (v <= a0)
        {
            x(i) = 0;
        }
        else
        {
            double left = w_star;
            double right = v;
            double w0;
            while (true)
            {
                double middle = (left + right)/2.;
                double value = (1./sqrt(middle) - 4.0*mu*(v - middle));
                if (fabs(value) < 1.0e-6)
                {
                    w0 = middle;
                    break;
                }
                else
                {
                    if (value > 0)
                        right = middle;
                    else
                        left = middle;
                }
            }

            double value0 = mu*v*v;
            double valuew0 = sqrt(w0) + mu*(w0 - v)*(w0 - v);
            if (value0 <= valuew0)
                x(i) = 0;
            else
            {
                if (this->x_update_tmp(i) > 0)
                    x(i) = w0;
                else
                    x(i) = -w0;
            }
        }
    }
}

void SBCHalfNormUpdate::update_x_interval()
{
    #pragma omp for
    for (int i = 0; i < n_total_coef; ++i)
    {
        double v = this->x_update_tmp(i);
        double mu = 0.5*this->penalty_weight;

        double w_star = 0.25*pow(mu, -2./3.);
        double a0 = 3.0*w_star;
        if (v <= a0)
        {
            x(i) = 0;
        }
        else
        {
            if (1 <= w_star)
            {
                x(i) = 0;
            }
            else
            {
                double left = w_star;
                double right = v;
                double w0;
                while (true)
                {
                    double middle = (left + right)/2.;
                    double value = (1./sqrt(middle) - 4.0*mu*(v - middle));
                    if (fabs(value) < 1.0e-6)
                    {
                        w0 = middle;
                        break;
                    }
                    else
                    {
                        if (value > 0)
                            right = middle;
                        else
                            left = middle;
                    }
                }

                double value0 = mu*v*v;
                double value1 = 1 + mu*(1. - v)*(1. - v);
                double valuew0 = sqrt(w0) + mu*(w0 - v)*(w0 - v);
                if (w0 <= 1)
                    x(i) = (value0 <= valuew0)?0:w0;
                else
                    x(i) = (value0 <= value1)?0:1;
            }
        }
    }
}

template<typename T1, typename T2>
void SBCMeshWithBoundaryControl<T1, T2>::initialize_mesh_data()
{
	this->point_data.clear();
	this->datapt_idx_to_vtx_idx_map.clear();
	this->controlpt_idx_to_vtx_idx_map.clear();
	this->vtx_idx_to_datapt_idx_map.clear();
	this->n_boundary_pt = 0;
	this->n_data_pt = 0;

    typename T1::VertexIter v_it, v_end = this->pmesh->vertices_end();

    for(v_it = this->pmesh->vertices_begin(); v_it != v_end; ++v_it)
    {
        if (!hasCage)
        {
            if(this->pmesh->is_boundary(v_it))
            {
                this->vtx_idx_to_control_pt_idx_map.push_back(this->controlpt_idx_to_vtx_idx_map.size());
                this->vtx_idx_to_datapt_idx_map.push_back(-1);
                this->controlpt_idx_to_vtx_idx_map.push_back(this->point_data.size());
                this->n_boundary_pt++;
            }
            else
            {
                this->vtx_idx_to_datapt_idx_map.push_back(this->datapt_idx_to_vtx_idx_map.size());
                this->vtx_idx_to_control_pt_idx_map.push_back(-1);
                this->datapt_idx_to_vtx_idx_map.push_back(this->point_data.size());
                this->n_data_pt++;
            }
        }
        else
        {
            this->vtx_idx_to_datapt_idx_map.push_back(this->datapt_idx_to_vtx_idx_map.size());
            this->vtx_idx_to_control_pt_idx_map.push_back(-1);
            this->datapt_idx_to_vtx_idx_map.push_back(this->point_data.size());
            this->n_data_pt++;
        }

        typename T1::Point cur_pt = this->pmesh->point(v_it);
        this->point_data.push_back(OpenMesh::Vec3d(cur_pt[0], cur_pt[1], cur_pt[2]));
    }

    if (hasCage)
    {
        VertexIterator v_it, v_end = (this->cage)->vertexEnd();
        for(v_it = (this->cage)->vertexBegin(); v_it != v_end; ++v_it)
        {
            this->vtx_idx_to_control_pt_idx_map.push_back(this->controlpt_idx_to_vtx_idx_map.size());
            this->vtx_idx_to_datapt_idx_map.push_back(-1);
            this->controlpt_idx_to_vtx_idx_map.push_back(this->point_data.size());
            this->n_boundary_pt++;
            Point cur_pt = v_it->getPosition();
            this->point_data.push_back(OpenMesh::Vec3d(cur_pt[0], cur_pt[1], cur_pt[2]));
        }
    }

	this->n_control_points = n_boundary_pt;
	this->n_data_points = n_data_pt;
    this->n_total_coef = this->n_control_points*this->n_data_points;
}

template<typename T1, typename T2>
void SBCMeshWithBoundaryControl<T1, T2>::initialize_fairness_energy_matrix()
{
    this->L.resize(this->n_data_pt, this->n_data_pt);
    this->a.setZero(this->n_data_pt, this->n_boundary_pt);

    typedef Eigen::Triplet<double> Triplet_type;
    std::vector<Triplet_type> triplets_L;

    OMesh::VertexIter v_it, v_end = this->pmesh->vertices_end();
    OMesh::VertexOHalfedgeIter vohe_it;

    for(v_it = this->pmesh->vertices_begin(); v_it != v_end; ++v_it)
    {
        int vidx = v_it.handle().idx();
        int centerpt_idx = this->vtx_idx_to_datapt_idx_map[vidx];
        if(centerpt_idx >= 0)
        {
            OpenMesh::Vec3d center_pt = this->point_data[vidx];

            std::vector<OpenMesh::Vec3d> neighbor_pts;
            std::vector<OpenMesh::Vec3d> neighbor_vec;
            std::vector<int> neighbor_idx;
            std::vector<bool> boundary_edge;
            for (vohe_it = this->pmesh->voh_iter(v_it.handle()); vohe_it; ++vohe_it)
            {
                OMesh::VertexHandle vh = this->pmesh->to_vertex_handle(vohe_it.handle());
                neighbor_idx.push_back(vh.idx());
                neighbor_pts.push_back(this->point_data[vh.idx()]);
                neighbor_vec.push_back(neighbor_pts.back() - center_pt);
                if (this->pmesh->is_boundary(this->pmesh->edge_handle(vohe_it.handle())))
                    boundary_edge.push_back(true);
                else
                    boundary_edge.push_back(false);
            }

            int n_neighbor = neighbor_pts.size();
            double total_area = 0.0;
            for(int i = 0; i < n_neighbor; ++i)
            {
                if (i + 1 < n_neighbor || (!boundary_edge[i] || !boundary_edge[(i + 1)%n_neighbor]))
                    total_area += cross(neighbor_vec[i], neighbor_vec[(i + 1)%n_neighbor]).norm();
            }
            total_area /= 6.0;
            double sqrt_total_area = std::sqrt(total_area);
            double center_weight = 0.0;

            for(int i = 0; i < n_neighbor; i++)
            {
                OpenMesh::Vec3d vec1 = neighbor_pts[i] - neighbor_pts[(i + n_neighbor - 1)%n_neighbor],
                        vec2 = center_pt - neighbor_pts[(i + n_neighbor - 1)%n_neighbor];
                OpenMesh::Vec3d vec3 = neighbor_pts[i] - neighbor_pts[(i + 1)%n_neighbor],
                        vec4 = center_pt - neighbor_pts[(i + 1)%n_neighbor];

                double cot1 = 0, cot2 = 0;
                if (i > 0 || (!boundary_edge[i] || !boundary_edge[(i + n_neighbor - 1)%n_neighbor]))
                    cot1 = dot(vec1, vec2)/cross(vec1, vec2).norm();
                if (i + 1 < n_neighbor || (!boundary_edge[i] || !boundary_edge[(i + 1)%n_neighbor]))
                    cot2 = dot(vec3, vec4)/cross(vec3, vec4).norm();

                center_weight -= (cot1 + cot2);

                if(this->vtx_idx_to_datapt_idx_map[neighbor_idx[i]] >= 0)
                {
                    triplets_L.push_back(Triplet_type(centerpt_idx, this->vtx_idx_to_datapt_idx_map[neighbor_idx[i]], (cot1 + cot2)/sqrt_total_area));
                }
                else
                {
                    this->a(centerpt_idx, this->vtx_idx_to_control_pt_idx_map[neighbor_idx[i]]) = (cot1 + cot2)/sqrt_total_area;
                }
            }

            center_weight /= sqrt_total_area;
            triplets_L.push_back(Triplet_type(centerpt_idx, centerpt_idx, center_weight));
        }
    }

    this->L.setFromTriplets(triplets_L.begin(), triplets_L.end());
}

template<typename T1, typename T2, typename T3>
void SBCOpt<T1, T2, T3>::solve_dl()
{
	double start_time = omp_get_wtime();

	int iter = 0;
	this->optimization_end = false;

	omp_set_num_threads(this->nb_threads);
	while(!this->optimization_end)
	{
		iter++;
#ifdef OUTPUT_LOG
		std::cout<<"Iteration "<<iter<<std::endl;
#endif

		#pragma omp parallel
		{
			this->compute_uvxyz_update_aux_vars();
			this->update_v();
			this->update_y_dl();
			this->update_z();
			this->update_u();
			this->update_x();
			this->update_w_dl();
			this->dl_stop_check_and_dual_var_penalty_weight_update(iter);
		}
	}

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

template<typename T1, typename T2, typename T3>
void SBCOpt<T1, T2, T3>::solve()
{
	double start_time = omp_get_wtime();

	int iter = 0;
	this->optimization_end = false;

	omp_set_num_threads(this->nb_threads);
	while(!this->optimization_end)
	{
		iter++;
#ifdef OUTPUT_LOG
		std::cout << "Iteration " << iter << std::endl;
#endif

		#pragma omp parallel
		{
			this->compute_vxyz_update_aux_vars();
			this->update_v();
			this->update_y();
            this->update_z();
            this->update_x();
			this->update_w();
			this->stop_check_and_dual_var_penalty_weight_update(iter);
		}
	}

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds" << std::endl;
}

template<typename T1, typename T2, typename T3>
void SBCOpt<T1, T2, T3>::initialize_variables(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio, double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_, double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_, int max_iter, int primal_max_iter, double dlweight, bool linearPrecision)
{
    this->init_variables(num_threads, laplacian_energy_bound, laplacian_bound_min_ratio, init_penalty_weight_, max_penalty_weight, primal_eps_val_, dual_eps_val_, init_dual_eps_, initval_primal_eps_, initval_dual_eps_, tau_incr_, max_iter, primal_max_iter, dlweight, linearPrecision);
}

template<typename T1, typename T2, typename T3>
void SBCOpt<T1, T2, T3>::get_test_tex_coord(std::vector<double> &init_w_tex_coord, std::vector<double> &w_tex_coord)
{
	init_w_tex_coord.assign(this->pmesh->n_vertices(), 0.0);
	w_tex_coord.assign(this->pmesh->n_vertices(), 0.0);

	typename T2::HalfedgeIter h_it, hend = this->pmesh->halfedges_end();
	typename T2::HalfedgeHandle first_boundary_heh;
	for(h_it = this->pmesh->halfedges_begin(); h_it != hend; ++ h_it){
		if(this->pmesh->is_boundary(h_it.handle())){
			first_boundary_heh = h_it.handle();
			break;
		}
	}

	if(first_boundary_heh.is_valid())
	{
		double min_coord = 0.001, max_coord = 0.999;

		std::vector<typename T2::VertexHandle> vhs;
		vhs.push_back(this->pmesh->to_vertex_handle(first_boundary_heh));
		typename T2::HalfedgeHandle next_heh = this->pmesh->next_halfedge_handle(first_boundary_heh);

		while(next_heh != first_boundary_heh)
		{
			vhs.push_back(this->pmesh->to_vertex_handle(next_heh));
			next_heh = this->pmesh->next_halfedge_handle(next_heh);
		}

		int n = vhs.size();
		double total_length = 0.0;
		std::vector<double> accum_length;
		accum_length.push_back(0.0);
		for(int i = 0; i < n; i++)
		{
			double cur_length = ( this->pmesh->point(vhs[i]) - this->pmesh->point(vhs[(i+1)%n]) ).norm();
			total_length += cur_length;
			accum_length.push_back(accum_length.back() + cur_length);
		}

		double mid_length = total_length/2;

		Eigen::VectorXd boundary_value(n);

		for(int i = 0; i < n; i++)
		{
			int boundary_val_idx = this->vtx_idx_to_control_pt_idx_map[vhs[i].idx()];
			assert(boundary_val_idx >= 0);

			double cur_length = accum_length[i];
			double normalized_coord = ( cur_length <= mid_length ) ? cur_length / mid_length : (total_length - cur_length)/mid_length;
			double coord = max_coord*normalized_coord + min_coord*(1 - normalized_coord);

			boundary_value(boundary_val_idx) = coord;
			init_w_tex_coord[vhs[i].idx()] = coord;
			w_tex_coord[vhs[i].idx()] = coord;
		}

		Eigen::VectorXd init_w_coord = this->init_w*boundary_value;
		Eigen::VectorXd w_coord = this->w*boundary_value;

		int m = static_cast<int>(this->pmesh->n_vertices()) - n;
		for(int i = 0 ; i < m; i++)
		{
			int vidx = this->datapt_idx_to_vtx_idx_map[i];
			init_w_tex_coord[vidx] = init_w_coord(i);
			w_tex_coord[vidx] = w_coord(i);
		}
	}
}

template<typename T1, typename T2, typename T3>
void SBCOpt<T1, T2, T3>::get_control_point_coord(Eigen::MatrixXd &cp_coord)
{
	cp_coord = this->control_points;
}

template<typename T1, typename T2, typename T3>
void SBCOpt<T1, T2, T3>::update_control_points()
{
	//based on given data points, weights and initial cge positions
	//compute the new cage positions
	Eigen::MatrixXd A = this->w.transpose()*this->w;
	Eigen::MatrixXd b = this->w.transpose()*this->p_dl;

	this->control_points.resize(this->n_control_points, this->point_dim());

	Eigen::ConjugateGradient<Eigen::MatrixXd> cg;
	cg.compute(A);
	this->control_points = cg.solveWithGuess(b, (this->C_dl).transpose());

	std::cout<<"Current position error: "<<(this->w*this->control_points - this->p_dl).norm()<<std::endl;
	std::cout<<"Position difference: "<<(this->control_points.transpose() - this->C_dl).norm()<<std::endl;
}

template class SBCOpt<SBCL0Update, PolyMeshType, VertexGeometry* >;
template class SBCOpt<SBCHalfNormUpdate, PolyMeshType, VertexGeometry* >;
}}
