/*
 * IpoptHalfNormSBC.cpp
 *
 *  Created on: Dec 24, 2012
 *      Author: Bailin Deng
 */

#include "IpoptHalfNormSBC.h"
#include <cstring>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

bool IpoptHalfNormSBC::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
	Index& nnz_h_lag, IndexStyleEnum& index_style)
{
	n = W_size*2;
	m = num_constraints;
	nnz_jac_g = jac_g_row.size();
	nnz_h_lag = this->nnz_h;
	index_style = C_STYLE;

	return true;
}


bool IpoptHalfNormSBC::get_bounds_info(Index, Number* x_l, Number* x_u,
	Index m, Number* g_l, Number* g_u)
{
	Eigen::Map< Eigen::VectorXd > wl_vec(x_l, W_size), wu_vec(x_u, W_size),
			zl_vec(&(x_l[W_size]), W_size), zu_vec(&(x_u[W_size]), W_size);
	wl_vec.fill(param.nonnegative_sbc ? 0.0 : this->inf_lower_bound);
	wu_vec.fill(this->inf_upper_bound);
	zl_vec.fill(0.0);
	zu_vec.fill(this->inf_upper_bound);

	std::memcpy(g_l, &(g_lower_bound[0]), m * sizeof(Number));
	std::memcpy(g_u, &(g_upper_bound[0]), m * sizeof(Number));

	return true;
}

bool IpoptHalfNormSBC::get_starting_point(Index, bool, Number* x,
		bool init_bound_multiplier, Number*, Number*, Index, bool init_lambda, Number*)
{
	Eigen::Map< Eigen::VectorXd > init_W_vec(x, W_size), init_Z_vec(&(x[W_size]), W_size);
	for(int j = 0; j < W_size; j++){
		init_W_vec(j) = W_value(j);
		init_Z_vec(j) = std::sqrt(std::abs(W_value(j)));
	}

	assert(!init_bound_multiplier);
	assert(!init_lambda);

	return true;
}

void IpoptHalfNormSBC::initialize_h_info()
{
	// Since the Laplacian part and the p-norm part in Hessian are separated, we can count their positions separately
	// Besides, remember that we only need to store the lower left part of Hessian

	int num_P_elem = P.rows() * P.cols();

	h_lap_constraint_idx = param.smoothness_hard_constraint ? num_P_elem : -1;
	double lap_weight = param.smoothness_hard_constraint ? 1.0 : param.smoothness_weight;

	for(int k=0; k< LtL.outerSize(); ++k){
		for(SparseMatrixXd::InnerIterator it(LtL,k); it; ++it){
			int row_idx = it.row(), col_idx = it.col();
			if(row_idx >= col_idx){
				// Since the Laplacian part is on upper left of Hessian, the indices are the same as in the orignal matrix
				h_row.push_back(W_idx(row_idx));
				h_col.push_back(W_idx(col_idx));
				lap_hessian_base_values.push_back(it.value() * (2 * lap_weight));
			}
		}
	}

	int z_constraint_base_idx = num_P_elem + W_idx.rows() + param.smoothness_hard_constraint ? 1 : 0;

	for(int i = 0; i < W_size; i++){
		h_row.push_back(Z_idx(i));
		h_col.push_back(Z_idx(i));
		p_norm_hessian_base_values.push_back( std::make_pair( z_constraint_base_idx + 2 * i, 2.0 ) );
	}

	nnz_h = h_row.size();
}


void IpoptHalfNormSBC::init_variable_index()
{
	W_size = W_value.rows()*W_value.cols();
	W_idx.resize(W_value.rows(), W_value.cols());
	Z_idx.resize(W_value.rows(), W_value.cols());

	for(int i = 0; i < W_size; i++){
		W_idx(i) = i;
		Z_idx(i) = W_size + i;
	}
}


// Store information about constraint function Jacobian
void IpoptHalfNormSBC::initialize_g_info()
{
	int cur_row = 0;

	// Constraint C W^T - P = 0

	assert(W_value.cols() == C.cols());
	int num_control_pts = C.cols();
	for(int j = 0; j < P.cols(); j++){
		for(int i = 0; i < P.rows(); i++){
			// We need to get i-th row of C and j-th row of W
			add_row_to_jac_g_array(cur_row, W_idx.row(j), C.row(i), num_control_pts);

			add_constraint_bound(P(i,j), P(i,j));

			cur_row ++;
		}
	}

	// Constraint ||LW|| < eps

	if(param.smoothness_hard_constraint){
		smoothness_hard_constraint_jac_g_baseidx = fixed_jac_g_vec.size();

		// Constant part of the gradient for smoothness term
		Eigen::VectorXd smoothness_grad_const_term = ( Lt * const_linear_term ) * 2.0;

		add_row_to_jac_g_array(cur_row, W_idx, smoothness_grad_const_term);

		add_constraint_bound(inf_lower_bound, param.smoothness_bound * param.smoothness_bound);

		cur_row ++;
	}
	else{
		smoothness_hard_constraint_jac_g_baseidx = -1;
	}

	// Constraints W e_n = e_m
	for(int i = 0; i < W_idx.rows(); i++){
		add_single_value_row_to_jac_g_array(cur_row, W_idx.row(i), 1.0, W_idx.cols());
		add_constraint_bound(1.0, 1.0);
		cur_row ++;
	}


	// Constraint (z_i^j)^2 + w_i^j >= 0
	// (z_i^j)^2 - w_i^j >= 0

	p_norm_constraint_jac_g_idx.clear();

	for(int i = 0; i < W_size; i++){
		add_to_jac_g_array(cur_row, W_idx(i), 1.0);

		p_norm_constraint_jac_g_idx.push_back(fixed_jac_g_vec.size());
		add_to_jac_g_array(cur_row, Z_idx(i), 0.0);

		add_constraint_bound(0.0, inf_upper_bound);
		cur_row++;

		add_to_jac_g_array(cur_row, W_idx(i), -1.0);

		p_norm_constraint_jac_g_idx.push_back(fixed_jac_g_vec.size());
		add_to_jac_g_array(cur_row, Z_idx(i), 0.0);

		add_constraint_bound(0.0, inf_upper_bound);
		cur_row ++;
	}

	num_constraints = cur_row;
}

void IpoptHalfNormSBC::initialize_grad_f_info()
{
	fixed_grad_f.assign(W_size*2, 0.0);

	if(!param.smoothness_hard_constraint){
		Eigen::Map<Eigen::VectorXd>(&(fixed_grad_f[0]), W_size) = (Lt * const_linear_term) * (2 * this->param.smoothness_weight);
		//assert((w_grad - (Lt * const_linear_term) * (2 * this->param.smoothness_weight)).norm() < 1e-6);
	}

	std::fill(fixed_grad_f.begin() + W_size, fixed_grad_f.end(), 1.0);
}


bool IpoptHalfNormSBC::eval_g(Index, const Number* x, bool, Index, Number* g)
{
	int cur_row = 0;

	Eigen::Map< const Eigen::MatrixXd > w_mat(&(w_var_value(x,0)), W_value.rows(), W_value.cols());

	// Constraint C W^T - P = 0
	Eigen::Map<Eigen::MatrixXd>(&(g[cur_row]), P.rows(), P.cols()) = C * w_mat.transpose();
	cur_row += P.rows() * P.cols();

	// Constraint ||LW + A|| < eps
	if(param.smoothness_hard_constraint){
		g[cur_row ++] = (small_L * w_mat + small_const_linear_term).squaredNorm();
	}

	// Constraints W e_n = e_m
	Eigen::Map<Eigen::VectorXd>(&(g[cur_row]), W_value.rows()) = w_mat.rowwise().sum();
	cur_row += W_value.rows();


	// Constraint (z_i^j)^2 + w_i^j >= 0
	// (z_i^j)^2 - w_i^j >= 0
	for(int i = 0; i < W_size; i++){
		double z_sqr = z_var_value(x,i) * z_var_value(x,i);
		g[cur_row++] = z_sqr + w_var_value(x,i);
		g[cur_row++] = z_sqr - w_var_value(x,i);
	}

	return true;
}


bool IpoptHalfNormSBC::eval_jac_g(Index, const Number* x, bool,
						  Index, Index nele_jac, Index* iRow, Index *jCol,
						  Number* values)
{
	if(values){
		assert(Index(fixed_jac_g_vec.size()) == nele_jac);
		std::memcpy(values, &(fixed_jac_g_vec[0]), nele_jac * sizeof(Number));

		if(param.smoothness_hard_constraint){
			Eigen::Map< const Eigen::VectorXd > w(&(w_var_value(x,0)), W_size);
			Eigen::Map< Eigen::VectorXd >(&(values[smoothness_hard_constraint_jac_g_baseidx]), W_size) += (LtL*w)*2;
		}

		for(int i = 0; i < W_size; i ++){
			double cur_val = 2*z_var_value(x,i);
			values[ p_norm_constraint_jac_g_idx[i*2]] = cur_val;
			values[ p_norm_constraint_jac_g_idx[i*2+1]] = cur_val;
		}
	}
	else{
		std::memcpy(iRow, &(jac_g_row[0]), nele_jac * sizeof(Index));
		std::memcpy(jCol, &(jac_g_col[0]), nele_jac * sizeof(Index));
	}

	return true;
}


bool IpoptHalfNormSBC::eval_f(Index, const Number* x, bool, Number& obj_value)
{
	// Sum of auxiliary variables
	obj_value = Eigen::Map< const Eigen::VectorXd >(&(z_var_value(x,0)), W_size).sum();

	if(!param.smoothness_hard_constraint){
		obj_value += param.smoothness_weight *
				(small_L * Eigen::Map< const Eigen::MatrixXd >(&(w_var_value(x,0)), W_value.rows(), W_value.cols()) + small_const_linear_term ).squaredNorm();
	}

	return true;
}


bool IpoptHalfNormSBC::eval_grad_f(Index, const Number* x, bool, Number* grad_f)
{
	std::memcpy(grad_f, &(fixed_grad_f[0]), fixed_grad_f.size() * sizeof(Number));

	if(!param.smoothness_hard_constraint){
		Eigen::Map< Eigen::VectorXd >(grad_f, W_size) += ( LtL * Eigen::Map< const Eigen::VectorXd >(&(w_var_value(x,0)), W_size) ) * ( 2 * param.smoothness_weight );
	}

	return true;
}

bool IpoptHalfNormSBC::eval_h(Index, const Number*, bool,
                    Number obj_factor, Index, const Number* lambda,
                    bool, Index nele_hess, Index* iRow,
                    Index* jCol, Number* values)
{
	if(param.hessian_approx){
		return false;
	}
	else{
		if(values){
			int cur_idx = 0;

			double lap_factor = h_lap_constraint_idx >= 0 ? lambda[h_lap_constraint_idx] : obj_factor;
			for(unsigned int i = 0; i < lap_hessian_base_values.size(); i++){
				values[cur_idx++] = lap_factor * lap_hessian_base_values[i];
			}

			for(unsigned int i = 0; i < p_norm_hessian_base_values.size(); i++){
				values[cur_idx++] = (lambda[p_norm_hessian_base_values[i].first] + lambda[p_norm_hessian_base_values[i].first + 1]) * p_norm_hessian_base_values[i].second;
			}

			assert(nele_hess == cur_idx);
		}
		else{
			std::memcpy(iRow, &(h_row[0]), nele_hess * sizeof(Index));
			std::memcpy(jCol, &(h_col[0]), nele_hess * sizeof(Index));
		}

		return true;
	}
}

void IpoptHalfNormSBC::expand_L_and_const_linear_term()
{
	// For W that is column-major, the big L is simply laying the small L over the diagonal
	assert(small_L.cols() == W_value.rows());
	int n_col = W_value.cols(), n_row = W_value.rows();

    typedef Eigen::Triplet<double> Triplet_type;
    std::vector<Triplet_type> triplets_L;

    for(int k=0; k< small_L.outerSize(); ++k){
		for(SparseMatrixXd::InnerIterator it(small_L,k); it; ++it){
			int row_idx = it.row(), col_idx = it.col();
			double val = it.value();

			for(int i = 0; i < n_col; i++){
				int base_idx = i*n_row;
				triplets_L.push_back(Triplet_type(base_idx + row_idx, base_idx + col_idx, val));
			}
		}
    }

	L.resize(n_col*n_row, n_col*n_row);
	L.setFromTriplets(triplets_L.begin(), triplets_L.end());
	Lt = L.transpose();
	LtL = Lt*L;

	int linear_term_size = small_const_linear_term.rows()*small_const_linear_term.cols();
	const_linear_term.resize(linear_term_size);
	for(int i = 0; i < linear_term_size; i++){
		const_linear_term(i) = small_const_linear_term(i);
	}

//	double old_norm = (small_L * W_value + small_const_linear_term).squaredNorm();
//	Eigen::VectorXd W_vec(n_col * n_row);
//	for(int i = 0; i < n_col * n_row; i++){
//		W_vec(i) = W_value(i);
//	}
//	double new_norm = (L * W_vec + const_linear_term).squaredNorm();
//
//	if(std::abs(old_norm - new_norm) > 1e-10){
//		std::cout << "Old Norm: " << old_norm << ", New Norm:" << new_norm << std::endl;
//		assert(false);
//	}
}


void IpoptHalfNormSBC::finalize_solution(SolverReturn status,
        Index, const Number* x, const Number*, const Number*,
        Index, const Number*, const Number*, Number obj_value,
        const IpoptData*, IpoptCalculatedQuantities*)
{
    std::cout << "Return Status:";
    switch(status){
    case Ipopt::SUCCESS :
        std::cout << "SUCCESS" << std::endl;
        break;
    case Ipopt::MAXITER_EXCEEDED :
        std::cout << "MAXITER_EXCEEDED" << std::endl;
        break;
    case Ipopt::CPUTIME_EXCEEDED :
        std::cout << "CPUTIME_EXCEEDED" << std::endl;
        break;
    case Ipopt::STOP_AT_TINY_STEP :
        std::cout << "STOP_AT_TINY_STEP" << std::endl;
        break;
    case Ipopt::STOP_AT_ACCEPTABLE_POINT :
        std::cout << "STOP_AT_ACCEPTABLE_POINT" << std::endl;
        break;
    case Ipopt::LOCAL_INFEASIBILITY :
        std::cout << "LOCAL_INFEASIBILITY" << std::endl;
        break;
    case Ipopt::USER_REQUESTED_STOP :
        std::cout << "USER_REQUESTED_STOP" << std::endl;
        break;
    case Ipopt::FEASIBLE_POINT_FOUND :
        std::cout << "FEASIBLE_POINT_FOUND" << std::endl;
        break;
    case Ipopt::DIVERGING_ITERATES :
        std::cout << "DIVERGING_ITERATES" << std::endl;
        break;
    case Ipopt::RESTORATION_FAILURE :
        std::cout << "RESTORATION_FAILURE" << std::endl;
        break;
    case Ipopt::ERROR_IN_STEP_COMPUTATION :
        std::cout << "ERROR_IN_STEP_COMPUTATION" << std::endl;
        break;
    case Ipopt::INVALID_NUMBER_DETECTED :
        std::cout << "INVALID_NUMBER_DETECTED" << std::endl;
        break;
    case Ipopt::TOO_FEW_DEGREES_OF_FREEDOM :
        std::cout << "TOO_FEW_DEGREES_OF_FREEDOM" << std::endl;
        break;
    case Ipopt::INVALID_OPTION :
        std::cout << "INVALID_OPTION" << std::endl;
        break;
    case Ipopt::OUT_OF_MEMORY :
        std::cout << "OUT_OF_MEMORY" << std::endl;
        break;
    case Ipopt::INTERNAL_ERROR :
        std::cout << "INTERNAL_ERROR" << std::endl;
        break;
    case Ipopt::UNASSIGNED :
        std::cout << "UNASSIGNED" << std::endl;
        break;
    default:
        break;
    }

    std::cout << "Final Target Function Value:" << obj_value << std::endl;

    W_value = Eigen::Map<const Eigen::MatrixXd>(&(w_var_value(x,0)), W_value.rows(), W_value.cols());
}
