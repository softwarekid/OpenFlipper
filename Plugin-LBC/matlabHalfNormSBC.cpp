/*
 * MatlabHalfNormSBC.cpp
 *
 *  Created on: Dec 28, 2012
 *      Author: Juyong Zhang
 */

#include "MatlabHalfNormSBC.h"
#include <cstring>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>


void MatlabHalfNormSBC::initialize_h_info()
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

void MatlabHalfNormSBC::init_variable_index()
{
	W_size = W_value.rows() * W_value.cols();
	W_idx.resize(W_value.rows(), W_value.cols());
	Z_idx.resize(W_value.rows(), W_value.cols());

	for(int i = 0; i < W_size; i++){
		W_idx(i) = i;
		Z_idx(i) = W_size + i;
	}
}

// Store information about constraint function Jacobian
void MatlabHalfNormSBC::initialize_g_info()
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

			cur_row++;
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

void MatlabHalfNormSBC::initialize_grad_f_info()
{
	fixed_grad_f.assign(W_size * 2, 0.0);

	if(!param.smoothness_hard_constraint){
		Eigen::Map<Eigen::VectorXd>(&(fixed_grad_f[0]), W_size) = (Lt * const_linear_term) * (2 * this->param.smoothness_weight);
		//assert((w_grad - (Lt * const_linear_term) * (2 * this->param.smoothness_weight)).norm() < 1e-6);
	}

	std::fill(fixed_grad_f.begin() + W_size, fixed_grad_f.end(), 1.0);
}

void MatlabHalfNormSBC::expand_L_and_const_linear_term()
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
				int base_idx = i * n_row;
				triplets_L.push_back(Triplet_type(base_idx + row_idx, base_idx + col_idx, val));
			}
		}
	}

	L.resize(n_col * n_row, n_col * n_row);
	L.setFromTriplets(triplets_L.begin(), triplets_L.end());
	Lt = L.transpose();
	LtL = Lt * L;

	int linear_term_size = small_const_linear_term.rows() * small_const_linear_term.cols();
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

