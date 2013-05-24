/*
 * SBCProximalOpt.cpp
 *
 *  Created on: Dec 4, 2012
 *      Author: Bailin Deng
 */


#include "SBCProximalOpt.h"
#include <algorithm>
#include <omp.h>




namespace Dolphin {

namespace plugins {

void SBCProximalOptBase::init_variables(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio,
		double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_,
		double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_,
		int max_iter, int primal_max_iter)
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

	this->min_sqr_primal_residual_change_ratio = 0.8 * 0.8;

	this->max_penalty = std::max( max_penalty_weight,
				penalty_weight * std::pow( init_dual_eps_val / dual_eps_val, 2 ) + 1.0);

	initialize_fairness_energy_matrix();
	initialize_solver();
	initialize_y_constraint_data();
	initialvalue_init_primal_vars();
	zero_initialize_dual_vars();
	init_intermediate_vars();
	initvalue_initialize_stopping_criteria_var();
	initialvalue_solve();
	init_w = w;

	this->min_lap_energy = std::max(v.norm(), (L * w + a).norm());
	this->lap_energy_bound = std::max(laplacian_energy_bound, min_lap_energy * laplacian_bound_min_ratio);

	this->penalty_weight = init_penalty_weight_;
	initialize_primal_vars();
	zero_initialize_dual_vars();
	initialize_stopping_criteria_var();
	initialize_primal_residual_norm();


}



void SBCProximalOptBase::compute_vxyz_update_aux_vars()
{
	#pragma omp sections //nowait
	{
		#pragma omp section
		{
			prev_x = x;
			x_update_tmp = (prev_x + w - d2) * 0.5;
			x_update_quadratic_term_weight = this->penalty_weight * 2;
		}

		#pragma omp section
		{
			prev_y = y;
			y_update_tmp = (prev_y + w - d3) * 0.5;;
		}

		#pragma omp section
		{
			prev_z = z;
			z_update_tmp = (prev_z + w - d4) * 0.5;
		}

		#pragma omp section
		{
			prev_v = v;
		}
	}

	#pragma omp for
	for(int i = 0; i < n_control_points; i++){
		v_update_tmp.col(i) = (L * w.col(i) + a.col(i) - d1.col(i) + v.col(i)) * 0.5;
	}
}

void SBCProximalOptBase::compute_vyz_update_aux_vars()
{
	#pragma omp sections //nowait
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

void SBCProximalOptBase::initialvalue_update_w()
{
	#pragma omp for
	for(int i = 0; i < n_control_points; ++i ){
		prev_w.col(i) = w.col(i);
		w.col(i) = initialvalue_solver.solve( L * (v.col(i) + d1.col(i) - a.col(i)) + y.col(i) + d3.col(i) + z.col(i) + d4.col(i) );
		w_diff.col(i) = w.col(i) - prev_w.col(i);
		dual_residual_v.col(i) = L * w_diff.col(i);
	}
}

void SBCProximalOptBase::update_w()
{
	#pragma omp for
	for(int i = 0; i < n_control_points; ++i ){
		prev_w.col(i) = w.col(i);
		w.col(i) = solver.solve( L * (v.col(i) + d1.col(i) - a.col(i)) + x.col(i) + d2.col(i) + y.col(i) + d3.col(i) + z.col(i) + d4.col(i) + prev_w.col(i) );
		w_diff.col(i) = w.col(i) - prev_w.col(i);
		dual_residual_v.col(i) += L * w_diff.col(i);
		dual_residual_x.col(i) += w_diff.col(i);
		dual_residual_y.col(i) += w_diff.col(i);
		dual_residual_z.col(i) += w_diff.col(i);
	}
}


void SBCProximalOptBase::update_y()
{
	#pragma omp for //nowait
	for(int i = 0; i < n_control_points; ++ i){
		y.col(i) = y_update_tmp * NNt.col(i) + basey.col(i);
		dual_residual_y.col(i) = prev_y.col(i) - y.col(i);
	}
}

void SBCProximalOptBase::initialvalue_update_y()
{
	#pragma omp for //nowait
	for(int i = 0; i < n_control_points; ++ i){
		y.col(i) = y_update_tmp * NNt.col(i) + basey.col(i);
	}
}


void SBCProximalOptBase::init_intermediate_vars()
{
	// Initialize intermediate variables with proper dimension
	x_update_tmp.setZero(w.rows(), w.cols());
	y_update_tmp = x_update_tmp;
	z_update_tmp = x_update_tmp;
	v_update_tmp.setZero(a.rows(), a.cols());
	prev_w = x_update_tmp;
	prev_x = x_update_tmp;
	prev_y = y_update_tmp;
	prev_z = z_update_tmp;
	prev_v = v_update_tmp;
	w_diff = prev_w;

	dual_residual_v.setZero(L.rows(), w_diff.cols());
	dual_residual_x.setZero(w_diff.rows(), w_diff.cols());
	dual_residual_y = dual_residual_x;
	dual_residual_z = dual_residual_x;
	primal_residual_v.setZero(a.rows(), a.cols());
	primal_residual_x.setZero(w.rows(), w.cols());
	primal_residual_y = primal_residual_x;
	primal_residual_z = primal_residual_x;
}


void SBCProximalOptBase::zero_initialize_dual_vars()
{
	d1.setZero(this->n_data_points, this->n_control_points);
	d2.setZero(this->n_data_points, this->n_control_points);
	d3.setZero(this->n_data_points, this->n_control_points);
	d4.setZero(this->n_data_points, this->n_control_points);
}


// Here we assume we have a good value of w based on initial value optimization
void SBCProximalOptBase::initialize_primal_vars()
{
	x = w;
	y = w;
	z = w;
	v = L * w + a;
}


void SBCProximalOptBase::initialize_stopping_criteria_var()
{
	primal_residual_dim = w.rows() * w.cols() * 3 + v.rows() * v.cols();
	dual_residual_dim = v.rows() * v.cols() + w.rows() * w.cols() * 4;
	primal_sqr_norm_eps = primal_residual_dim * primal_eps_val * primal_eps_val;
	final_dual_sqr_norm_eps = dual_residual_dim * dual_eps_val * dual_eps_val;
	cur_dual_sqr_norm_eps = dual_residual_dim * init_dual_eps_val * init_dual_eps_val;
}


void SBCProximalOptBase::initvalue_initialize_stopping_criteria_var()
{
	primal_residual_dim = w.rows() * w.cols() * 3 + v.rows() * v.cols();
	dual_residual_dim = v.rows() * v.cols() + w.rows() * w.cols() * 2;
	initval_primal_residual_sqr_norm_eps = primal_residual_dim * initval_primal_eps_val * initval_primal_eps_val;
	initval_dual_residual_sqr_norm_eps = dual_residual_dim * initval_dual_eps_val * initval_dual_eps_val;
}


void SBCProximalOptBase::initialvalue_init_primal_vars()
{
	w = y;
	x = w;
	z = w;
	v = L * w + a;
}

void SBCProximalOptBase::update_z()
{
	#pragma omp for //nowait
	for(int i = 0; i < n_total_coef; ++ i){
		z(i) = std::max(0.0, z_update_tmp(i));
		dual_residual_z(i) = prev_z(i) - z(i);
	}
}

void SBCProximalOptBase::initialvalue_update_z()
{
	#pragma omp for
	for(int i = 0; i < n_total_coef; ++ i){
		z(i) = std::max(0.0, z_update_tmp(i));
	}
}

void SBCProximalOptBase::update_v()
{
	#pragma omp single //nowait
	{
		double a_ = v_update_tmp.norm();
		if(a_ <= lap_energy_bound){
			v = v_update_tmp;
		}
		else{
			v = v_update_tmp * ( lap_energy_bound / a_ );
		}

		dual_residual_v = prev_v - v;
	}
}


void SBCProximalOptBase::initialvalue_update_v()
{
	#pragma omp single //nowait
	{
		v = v_update_tmp * ( this->penalty_weight / (1.0 + this->penalty_weight) );
	}
}


void SBCProximalOptBase::initialize_solver()
{
	SparseMatrixXd I(n_data_points, n_data_points);

	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_I;
	for(int i = 0; i < n_data_points; i++){
		triplets_I.push_back(T(i, i, 1.0));
	}

	I.setFromTriplets(triplets_I.begin(), triplets_I.end());
	Lt = L.transpose();

	SparseMatrixXd LtL = Lt * L;
	SparseMatrixXd M1 = LtL + I * 4.0, M2 = LtL + I * 2.0;

	solver.compute( M1);
	initialvalue_solver.compute( M2);
}


void SBCProximalOptBase::initialvalue_solve()
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
			this->initialvalue_update_y();
			this->initialvalue_update_z();
			this->initialvalue_update_w();
			this->initialvalue_stop_check_and_dual_var_penalty_weight_update(iter);
		}

	}

	double end_time = omp_get_wtime();
	std::cout << "Used " << end_time - start_time << " seconds for initialization" << std::endl;
}

void SBCProximalOptBase::initialize_y_constraint_data()
{
	int pt_dim = this->point_dim();
	Eigen::MatrixXd A( pt_dim + 1, n_control_points);
	for(int i = 0; i < n_control_points; i++){
		double *cp = this->control_point_coord(i);
		for(int j = 0; j < pt_dim; j++){
			A(j, i) = cp[j];
		}

		A(pt_dim, i) = 1.0;
	}

	Eigen::MatrixXd b( pt_dim + 1, n_data_points );
	for(int i = 0; i < n_data_points; i++){
		double *dp = this->data_point_coord(i);
		for(int j = 0; j < pt_dim; j++){
			b(j, i) = dp[j];
		}

		b(pt_dim, i) = 1.0;
	}


	Eigen::JacobiSVD< Eigen::MatrixXd, Eigen::FullPivHouseholderQRPreconditioner > jsvd(A, Eigen::ComputeFullU | Eigen::ComputeFullV);
	int nrank = jsvd.nonzeroSingularValues();

	// Get the null space
	Eigen::MatrixXd N = jsvd.matrixV().block(0, nrank, n_control_points, n_control_points - nrank);


	NNt = N * N.transpose();

	y = (jsvd.solve(b)).transpose();	// Least squares solving

	basey = y - y * NNt;
}


bool SBCProximalOptBase::compute_penalty_change_ratio()
{
	if(this->primal_residual_sqr_norm * this->initval_dual_residual_sqr_norm_eps >
			primal_dual_sqr_norm_rel_ratio_bound * this->dual_residual_sqr_norm * this->initval_primal_residual_sqr_norm_eps
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


void SBCProximalOptBase::initialvalue_stop_check_and_dual_var_penalty_weight_update(int iter_num)
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
			dual_residual_sqr_norm = penalty_weight * penalty_weight * (dual_residual_v.squaredNorm() + w_diff.squaredNorm() * 2);
		}

		#pragma omp section
		{
			primal_residual_v = v - a - L * w;
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
		std::cout << "Primal Residual Squared Norm: " << primal_residual_sqr_norm << ",  tolerance:" << initval_primal_residual_sqr_norm_eps << std::endl;
		std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  tolerance:" << initval_dual_residual_sqr_norm_eps << std::endl;
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


void SBCProximalOptBase::stop_check_and_dual_var_penalty_weight_update(int iter_num)
{
	#pragma omp single
	{
		optimization_end = false;
		need_incr_penalty = false;
		optimization_converge = false;
		primal_subproblem_converge = false;
		dual_residual_sqr_norm = penalty_weight * penalty_weight * (dual_residual_v.squaredNorm() + dual_residual_x.squaredNorm()
				+ dual_residual_y.squaredNorm() + dual_residual_z.squaredNorm() + w_diff.squaredNorm());
		double var_norm = std::sqrt(x.squaredNorm() + y.squaredNorm() + v.squaredNorm() + z.squaredNorm() + w.squaredNorm());
		std::cout << "Var Norm : " << var_norm << std::endl;

		if(iter_num >= this->max_iteration){
#ifdef OUTPUT_LOG
			std::cout << "Max iteration reached" << std::endl;
#endif
			optimization_end = true;
		}

		// If optimization ends because of max_iteartion, we still update the penalty weight and
		if((!optimization_end) || iter_num == max_iteration){
#ifdef OUTPUT_LOG
			std::cout << "Dual Residual Squared Norm: " << dual_residual_sqr_norm << ",  Tolerance:" << cur_dual_sqr_norm_eps << std::endl;
			std::cout << "Prev primal residual squared norm:" << prev_outer_primal_residual_sqr_norm << ", Toleraence" << primal_sqr_norm_eps << std::endl;
#endif

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

#ifdef OUTPUT_LOG
			std::cout << "Primal residual squared norm:" << primal_residual_sqr_norm << ",  tolerance:" << primal_sqr_norm_eps << std::endl;
#endif

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
						scaled_dual_change_ratio  = 1.0 / tau_incr;
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

bool SBCProximalOptBase::need_increment_penalty()
{
	return primal_residual_sqr_norm > std::max(primal_sqr_norm_eps, min_sqr_primal_residual_change_ratio * prev_outer_primal_residual_sqr_norm);
}


void SBCProximalL0Update::update_x()
{
	#pragma omp for
	for(int i = 0; i < n_total_coef; i++){
		x(i) = ( this->x_update_tmp(i) * this->x_update_tmp(i) * this->x_update_quadratic_term_weight <= 1.0) ? 0.0 : this->x_update_tmp(i);
		this->dual_residual_x(i) = prev_x(i) - x(i);
	}
}


void SBCProximalHalfNormUpdate::update_x()
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

template<typename T>
void SBCProximalMeshWithBoundaryControl<T>::initialize_mesh_data()
{
	this->point_data.clear();
	this->datapt_idx_to_vtx_idx_map.clear();
	this->controlpt_idx_to_vtx_idx_map.clear();
	this->vtx_idx_to_datapt_idx_map.clear();
	this->n_boundary_pt = 0;
	this->n_data_pt = 0;

	typename T::VertexIter v_it, v_end = this->pmesh->vertices_end();

	OpenMesh::Vec3d mean_pt(0.0, 0.0, 0.0);
	for(v_it = this->pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		if(this->pmesh->is_boundary(v_it)){
			this->vtx_idx_to_control_pt_idx_map.push_back(this->controlpt_idx_to_vtx_idx_map.size());
			this->vtx_idx_to_datapt_idx_map.push_back(-1);
			this->controlpt_idx_to_vtx_idx_map.push_back(this->point_data.size());
			this->n_boundary_pt ++;
		}
		else{
			this->vtx_idx_to_datapt_idx_map.push_back(this->datapt_idx_to_vtx_idx_map.size());
			this->vtx_idx_to_control_pt_idx_map.push_back(-1);
			this->datapt_idx_to_vtx_idx_map.push_back(this->point_data.size());
			this->n_data_pt ++;
		}

		typename T::Point cur_pt = this->pmesh->point(v_it);
		this->point_data.push_back(OpenMesh::Vec3d(cur_pt[0], cur_pt[1], cur_pt[2]));
		mean_pt += this->point_data.back();
	}

	mean_pt /= this->pmesh->n_vertices();

	// Mean-centering
	for(unsigned int i = 0; i < this->point_data.size(); ++ i){
		this->point_data[i] -= mean_pt;
	}

	// Project onto plane for 2D case
	if(this->dim == 2){
		int n_pt = this->point_data.size();
		Eigen::MatrixXd A(n_pt, 3);
		for(int i = 0; i < n_pt; i++){
			for(int j = 0; j < 3; j++){
				A(i, j) = this->point_data[i][j];
			}
		}

		Eigen::JacobiSVD< Eigen::MatrixXd > jsvd(A, Eigen::ComputeFullV);
		Eigen::MatrixXd V = jsvd.matrixV();
		OpenMesh::Vec3d T1( V(0,0), V(1,0), V(2,0) ), T2( V(0,1), V(1,1), V(2,1) );
		for(int i = 0; i < n_pt; i++){
			OpenMesh::Vec3d proj_coord(
						OpenMesh::dot(T1, this->point_data[i]),
						OpenMesh::dot(T2, this->point_data[i]),
						0.0
					);
			point_data[i] = proj_coord;
		}
	}

	this->n_control_points = n_boundary_pt;
	this->n_data_points = n_data_pt;
	this->n_total_coef = this->n_control_points * this->n_data_points;
}


template<typename T>
void SBCProximalMeshWithBoundaryControl<T>::initialize_fairness_energy_matrix()
{
	this->L.resize(this->n_data_pt, this->n_data_pt);
	this->a.setZero(this->n_data_pt, this->n_boundary_pt);

	typedef Eigen::Triplet<double> Triplet_type;
	std::vector<Triplet_type> triplets_L;

	typename T::VertexIter v_it, v_end = this->pmesh->vertices_end();
	typename T::VertexVertexIter vv_it;
	for(v_it = pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		if(!this->pmesh->is_boundary(v_it)){
			int vidx = v_it.handle().idx();
			int centerpt_idx = vtx_idx_to_datapt_idx_map[ vidx ];
			assert(centerpt_idx >= 0);
			OpenMesh::Vec3d center_pt = this->point_data[ vidx ];

			std::vector< OpenMesh::Vec3d > neighbor_pts;
			std::vector< OpenMesh::Vec3d > neighbor_vec;
			std::vector< int > neighbor_idx;
			for(vv_it = this->pmesh->vv_iter(v_it); vv_it; ++ vv_it){
				neighbor_idx.push_back(vv_it.handle().idx());
				neighbor_pts.push_back(point_data[vv_it.handle().idx()]);
				neighbor_vec.push_back(neighbor_pts.back() - center_pt);
			}

			int n_neighbor = neighbor_pts.size();
			double total_area = 0.0;
			for(int i = 0; i < n_neighbor; i++){
				total_area += OpenMesh::cross( neighbor_vec[i], neighbor_vec[ (i+1) % n_neighbor ] ).norm();
			}
			total_area /= 6.0;
			double sqrt_total_area = std::sqrt(total_area);
			double center_weight = 0.0;

			for(int i = 0; i < n_neighbor; i++){
				OpenMesh::Vec3d vec1 = neighbor_pts[i] - neighbor_pts[(i+n_neighbor-1) % n_neighbor],
						vec2 = center_pt - neighbor_pts[(i+n_neighbor-1) % n_neighbor];
				OpenMesh::Vec3d vec3 = neighbor_pts[i] - neighbor_pts[(i+1) % n_neighbor],
						vec4 = center_pt - neighbor_pts[(i+1) % n_neighbor];
				double cot1 = OpenMesh::dot(vec1, vec2) / OpenMesh::cross(vec1, vec2).norm();
				double cot2 = OpenMesh::dot(vec3, vec4) / OpenMesh::cross(vec3, vec4).norm();

				center_weight -= (cot1 + cot2);

				if(vtx_idx_to_datapt_idx_map[neighbor_idx[i]] >= 0){
					triplets_L.push_back(Triplet_type(centerpt_idx, vtx_idx_to_datapt_idx_map[neighbor_idx[i]], (cot1 + cot2)/ sqrt_total_area) );
				}
				else{
					this->a(centerpt_idx, vtx_idx_to_control_pt_idx_map[neighbor_idx[i]]) = (cot1 + cot2)/ sqrt_total_area;
				}
			}

			center_weight /= sqrt_total_area;
			triplets_L.push_back(Triplet_type(centerpt_idx, centerpt_idx, center_weight));
		}
	}

	this->L.setFromTriplets(triplets_L.begin(), triplets_L.end());
}


template<typename T1, typename T2>
void SBCProximalOpt<T1, T2>::solve()
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

template<typename T1, typename T2>
void SBCProximalOpt<T1, T2>::initialize_variables(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio,
		double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_,
		double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_,
		int max_iter, int primal_max_iter)
{
	this->init_variables(num_threads, laplacian_energy_bound, laplacian_bound_min_ratio, init_penalty_weight_,
			max_penalty_weight, primal_eps_val_, dual_eps_val_, init_dual_eps_, initval_primal_eps_,
			initval_dual_eps_, tau_incr_, max_iter, primal_max_iter);
}


template<typename T1, typename T2>
void SBCProximalOpt<T1, T2>::get_test_tex_coord(std::vector<double> &init_w_tex_coord, std::vector<double> &w_tex_coord)
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

	if(first_boundary_heh.is_valid()){

		double min_coord = 0.001, max_coord = 0.999;

		std::vector<typename T2::VertexHandle> vhs;
		vhs.push_back(this->pmesh->to_vertex_handle(first_boundary_heh));
		typename T2::HalfedgeHandle next_heh = this->pmesh->next_halfedge_handle(first_boundary_heh);

		while(next_heh != first_boundary_heh){
			vhs.push_back(this->pmesh->to_vertex_handle(next_heh));
			next_heh = this->pmesh->next_halfedge_handle(next_heh);
		}

		int n = vhs.size();
		double total_length = 0.0;
		std::vector<double> accum_length;
		accum_length.push_back(0.0);
		for(int i = 0; i < n; i++){
			double cur_length = ( this->pmesh->point(vhs[i]) - this->pmesh->point(vhs[(i+1)%n]) ).norm();
			total_length += cur_length;
			accum_length.push_back(accum_length.back() + cur_length);
		}

		double mid_length = total_length / 2;

		Eigen::VectorXd boundary_value(n);

		for(int i = 0; i < n; i++){
			int boundary_val_idx = this->vtx_idx_to_control_pt_idx_map[vhs[i].idx()];
			assert(boundary_val_idx >= 0);

			double cur_length = accum_length[i];
			double normalized_coord = ( cur_length <= mid_length ) ? cur_length / mid_length : ( total_length - cur_length ) / mid_length;
			double coord = max_coord * normalized_coord + min_coord * (1 - normalized_coord);

			boundary_value( boundary_val_idx ) = coord;
			init_w_tex_coord[ vhs[i].idx() ] = coord;
			w_tex_coord[ vhs[i].idx() ] = coord;
		}

		Eigen::VectorXd init_w_coord = this->init_w * boundary_value;
		Eigen::VectorXd w_coord = this->w * boundary_value;

		int m = static_cast<int>(this->pmesh->n_vertices()) - n;
		for(int i = 0 ; i < m; i++){
			int vidx = this->datapt_idx_to_vtx_idx_map[i];
			init_w_tex_coord[vidx] = init_w_coord(i);
			w_tex_coord[vidx] = w_coord(i);
		}
	}
}

template class SBCProximalOpt<SBCProximalL0Update, PolyMeshType>;
template class SBCProximalOpt<SBCProximalHalfNormUpdate, PolyMeshType>;

}}

