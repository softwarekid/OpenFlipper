/*
 * IpoptHalfNormSBC.h
 *
 *  Created on: Dec 23, 2012
 *      Author: Bailin Deng
 */

#ifndef IPOPTHALFNORMSBC_H_
#define IPOPTHALFNORMSBC_H_

#include <coin/IpTNLP.hpp>
#include <coin/IpIpoptApplication.hpp>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <vector>


struct IpoptSBCParam{
	bool smoothness_hard_constraint;
	double smoothness_weight;	// Use this when smoothness is soft constraint
	double smoothness_bound;	// The bound of NORM (not squared!). Use this when smoothness is hard constraint
	bool hessian_approx;	// Set this to be true if we want to use Hessian approximation
	bool nonnegative_sbc;	// Indicates whether we require SBC to be non-negative
	bool control_variables;
};


using namespace Ipopt;

class IpoptHalfNormSBC : public TNLP{

public:
	typedef Eigen::SparseMatrix<double> SparseMatrixXd;

   // control_pts_ should be
   IpoptHalfNormSBC(const Eigen::MatrixXd &control_pts_,
					const Eigen::MatrixXd &data_pts,
					const Eigen::MatrixXd &init_W_val,
					const SparseMatrixXd &L_mat,
					const Eigen::MatrixXd &const_linear_term_,
					const IpoptSBCParam &param_):
   C(control_pts_), P(data_pts), W_value(init_W_val),
   small_L(L_mat), small_const_linear_term(const_linear_term_), param(param_),
   inf_lower_bound(-1.5e19), inf_upper_bound(1.5e19)
   {
	   initialize();
   }

   const Eigen::MatrixXd& get_W() const{
	   return W_value;
   }

  /** default destructor */
  virtual ~IpoptHalfNormSBC(){}

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

  virtual bool eval_h(Index n, const Number* x, bool new_x,
                      Number obj_factor, Index m, const Number* lambda,
                      bool new_lambda, Index nele_hess, Index* iRow,
                      Index* jCol, Number* values);


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
  IpoptHalfNormSBC(const IpoptHalfNormSBC&);
  IpoptHalfNormSBC& operator=(const IpoptHalfNormSBC&);

  // Each matrix has point_dim rows, and each column represents a point coordinate
  Eigen::MatrixXd C, P;


  Eigen::MatrixXd W_value;
  Eigen::MatrixXi W_idx, Z_idx;	// Store the variable indices of elements in W and Z
  int W_size;	// Number of elements in W

  SparseMatrixXd L, Lt, LtL;
  Eigen::VectorXd const_linear_term;

  // The lower-dimensional version of L, i.e., it applies to the W which is considered as a matrix instead of a vector
  SparseMatrixXd small_L;
  Eigen::MatrixXd small_const_linear_term;

  IpoptSBCParam param;

  double inf_lower_bound, inf_upper_bound;

  // The fixed part of constraint Jacobian
  SparseMatrixXd fixed_jac_g;

  // The fixed part of constraint Jacobian
  std::vector<double> fixed_jac_g_vec;
  std::vector<int> jac_g_row, jac_g_col;
  std::vector<double> g_lower_bound, g_upper_bound;

  // Store the indices of the constraint Jacobian elements about changeable p_norm constraints
  // Later we use this to fill Jacobian efficiently
  std::vector<int> p_norm_constraint_jac_g_idx;

  std::vector<double> fixed_grad_f;	// The fixed part of the gradient of f

  // Starting index of Jacobian component for hard constraint of smoothness bound
  int smoothness_hard_constraint_jac_g_baseidx;

  int num_constraints;


  std::vector<int> h_row, h_col;	// row and column index of nonzero elements in hessian

  int h_lap_constraint_idx;
  std::vector< double > lap_hessian_base_values;

  // The integers are the first constraint index for each z element within the constraint array
  std::vector< std::pair<int, double> > p_norm_hessian_base_values;

  int nnz_h;

//  int h_lap_constraint_idx; // Index of the constraint of Laplacian in the constraint array (if it is a hard constraint)
//  std::vector< std::pair<int,double> > h_lap_values;	// Stores the entry index in the hessian array for the Laplacian term
//
//  int pnorm_constraint_start_idx;	// The starting index of the p-norm constraint within the constraint array
//
//  // Stores the entry index in the hessian array for the p-norm constraint.
//  // Note that two constraints about the same z elements generate one entry
//  std::vector< int > h_pnorm_entry_idx;

  void initialize(){
	  init_variable_index();
	  expand_L_and_const_linear_term();
	  initialize_grad_f_info();
	  initialize_g_info();
	  initialize_h_info();
  }

  void initialize_g_info(); // Return the number of constraints

  void initialize_h_info();

  void initialize_grad_f_info();

  void add_to_jac_g_array(int row, int col, double val){
	  jac_g_row.push_back(row);
	  jac_g_col.push_back(col);
	  fixed_jac_g_vec.push_back(val);
  }

  template<typename ColVecType, typename ValVecType>
  void add_row_to_jac_g_array(int row, const ColVecType &input_col_idx_vec, const ValVecType &input_val_vec, int num_elem){
	  jac_g_row.insert(jac_g_row.end(), num_elem, row);

	  int col_begin_idx = jac_g_col.size();
	  jac_g_col.insert(jac_g_col.end(), num_elem, -1);
	  Eigen::Map<Eigen::VectorXi>(&(jac_g_col[col_begin_idx]), num_elem) = input_col_idx_vec;

	  int val_begin_idx = fixed_jac_g_vec.size();
	  fixed_jac_g_vec.insert(fixed_jac_g_vec.end(), num_elem, 0.0);
	  Eigen::Map<Eigen::VectorXd>(&(fixed_jac_g_vec[val_begin_idx]), num_elem) = input_val_vec;
  }

  template<typename ValVecType>
  void add_row_to_jac_g_array(int row, const Eigen::MatrixXi &input_col_idx_mat, const ValVecType &input_val_vec)
  {
	  int num_elem = input_col_idx_mat.rows() * input_col_idx_mat.cols();

	  jac_g_row.insert(jac_g_row.end(), num_elem, row);

	  int col_begin_idx = jac_g_col.size();
	  jac_g_col.insert(jac_g_col.end(), num_elem, -1);
	  Eigen::Map<Eigen::MatrixXi>(&(jac_g_col[col_begin_idx]), input_col_idx_mat.rows(), input_col_idx_mat.cols()) = input_col_idx_mat;

	  int val_begin_idx = fixed_jac_g_vec.size();
	  fixed_jac_g_vec.insert(fixed_jac_g_vec.end(), num_elem, 0.0);
	  Eigen::Map<Eigen::VectorXd>(&(fixed_jac_g_vec[val_begin_idx]), num_elem) = input_val_vec;
  }


  template<typename ColVecType>
  void add_single_value_row_to_jac_g_array(int row, const ColVecType &input_col_idx_vec, double val, int num_elem)
  {
	  jac_g_row.insert(jac_g_row.end(), num_elem, row);

	  int col_begin_idx = jac_g_col.size();
	  jac_g_col.insert(jac_g_col.end(), num_elem, -1);
	  Eigen::Map<Eigen::VectorXi>(&(jac_g_col[col_begin_idx]), num_elem) = input_col_idx_vec;

	  fixed_jac_g_vec.insert(fixed_jac_g_vec.end(), num_elem, val);
  }

  void add_constraint_bound(double lower, double upper){
	  g_lower_bound.push_back(lower);
	  g_upper_bound.push_back(upper);
  }

  // Expand L and const linear term into a form assuing W is a long vector
  void expand_L_and_const_linear_term();

  void init_variable_index();

  double& w_var_value(double *x, int i){
	  return x[W_idx(i)];
  }

  const double& w_var_value(const double *x, int i){
	  return x[W_idx(i)];
  }

  double& z_var_value(double *x, int i){
	  return x[Z_idx(i)];
  }

  const double& z_var_value(const double *x, int i){
	  return x[Z_idx(i)];
  }
};


#endif /* IPOPTHALFNORMSBC_H_ */
