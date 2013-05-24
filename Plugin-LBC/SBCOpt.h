/*
 * SBCOpt.h
 *
 *  Created on: Nov 10, 2012
 *      Author: Bailin Deng
 */

#ifndef SBCOPT_H_
#define SBCOPT_H_

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <OpenMesh/Core/Geometry/VectorT.hh>
#include <vector>
#include "ConstrainedMeshPluginTypedef.h"
#include <Dolphin/Core/Scenegraph/Geometry/EdgeSetNode.h>
#include <Dolphin/Core/DataStructures/EdgeSet.h>
#include <cmath>
#include <iostream>

namespace Dolphin {

namespace plugins {
typedef Eigen::SparseMatrix<double> SparseMatrixXd;

// Base class for SBC optimization
class SBCOptBase{
public:
	virtual ~SBCOptBase(){}

	Eigen::MatrixXd& get_init_w(){
		return init_w;
	}

	Eigen::MatrixXd& get_w(){
		return w;
	}

    void assign_other_coordinate(Eigen::MatrixXd& otherw);

protected:
	double penalty_weight;
	double max_penalty, min_penalty;
    //double lap_energy_bound;
    Eigen::VectorXd lap_energy_bound;
	double weight_dl;
    bool linearPrecision;

	int max_iteration;
	int nb_threads;
	bool need_incr_penalty;
	bool primal_subproblem_converge;
	bool optimization_converge, optimization_end;

	int n_control_points;
	int n_data_points;
	int n_total_coef;

	Eigen::SimplicialLDLT<SparseMatrixXd> solver, initialvalue_solver, solver_dl, solver_u;	// Cholesky factorization of the linear system for w
	SparseMatrixXd Lt, L; // The Laplacian matrix and its transpose
	SparseMatrixXd Iu;
	Eigen::MatrixXd IminusNNt;	// Matrix used for updaing y
	Eigen::MatrixXd basey_NNt;

	// Intermediate variables
	Eigen::MatrixXd v_update_tmp;
	Eigen::MatrixXd x_update_tmp;
	Eigen::MatrixXd y_update_tmp;
	Eigen::MatrixXd z_update_tmp;
	Eigen::MatrixXd u_update_tmp;


	// The ordering of the following variables is based on the control points. Quantities related to the same control point are packed together
	Eigen::MatrixXd d1, d2, d3, d4, d5;
	Eigen::MatrixXd v, x, y, z, u, w, a;
	Eigen::MatrixXd init_w;
	Eigen::MatrixXd prev_w, w_diff;
	SparseMatrixXd  C_dl_s, CTC_dl_s;
	Eigen::MatrixXd C_dl, p_dl, pC_dl;
	Eigen::MatrixXd control_points;
	Eigen::MatrixXd e_dl;

	// Primal residual vectors
	Eigen::MatrixXd primal_residual_u, primal_residual_v, primal_residual_x, primal_residual_y, primal_residual_z;
	double primal_residual_u_sqr_norm, primal_residual_v_sqr_norm, primal_residual_x_sqr_norm, primal_residual_y_sqr_norm, primal_residual_z_sqr_norm;

	// Temporary storage for primal residual norms
	//double primal_residual_sqr_norm_v, primal_residual_sqr_norm_x, primal_residual_sqr_norm_y, primal_residual_sqr_norm_z;
	double primal_residual_sqr_norm, dual_residual_sqr_norm;

	// Dual residual vector related to v
	Eigen::MatrixXd dual_residual_v;

	// Dimension of the primal and dual residual. We need this to normalized the primal and dual residual
	int primal_residual_dim, dual_residual_dim;
	int primal_residual_dim_dl, dual_residual_dim_dl;

	// Primal and dual residual norms
	double prev_outer_primal_residual_sqr_norm;

	double primal_eps_val, dual_eps_val;	// Epsilon value for defining norm related tolerances
	double init_dual_eps_val;

	double initval_primal_eps_val, initval_dual_eps_val;

	// We use squared-norm instead of L2 norm to represent thresholds, so that we don't need to do sqrt
	double primal_sqr_norm_eps, final_dual_sqr_norm_eps, cur_dual_sqr_norm_eps;
	double initval_primal_residual_sqr_norm_eps, initval_dual_residual_sqr_norm_eps;
	double primal_sqr_norm_eps_dl, final_dual_sqr_norm_eps_dl, cur_dual_sqr_norm_eps_dl;

	// The starting iteration number count for the current primal problem
	int current_primal_run_start_iter, primal_subproblem_maxiter;

	// Intermediate variables related to changing penalty weight
	double primal_dual_sqr_norm_rel_ratio_bound; // Threshold ratio between primal and dual residual norms
	double tau_incr;	// Ratio of change for increasing penalty weight
	double dual_sqaured_norm_eps_decr_ratio;	// Ratio of decreasing dual squared residual norm
	double scaled_dual_change_ratio;	// Reciprocal of the penalty increase ratio
	double penalty_change_ratio;
	double min_sqr_primal_residual_change_ratio;

	// Lower bound of fairness energy obtained from optimization
    //double min_lap_energy;
    Eigen::VectorXd min_lap_energy;

	void dl_initialize_stopping_criteria_var();
	void initialize_stopping_criteria_var();
	void initvalue_initialize_stopping_criteria_var();

	void compute_uvxyz_update_aux_vars();
	void compute_vxyz_update_aux_vars();
	void compute_vyz_update_aux_vars();
	void update_w();
	void update_w_dl();
	void update_y();
	void update_y_dl();
	void update_z();
	void update_v();
	void update_u();
	virtual void initialize_primal_vars();
	virtual void initialvalue_init_primal_vars();
	void initialize_solver();
	void zero_initialize_dual_vars();
	void init_intermediate_vars();
	void initialize_control_matrix();
    void initialize_data_matrix();
	virtual void initialize_fairness_energy_matrix(){}

	virtual int point_dim(){
		return 3;
	}

    virtual bool nonnegative_constraint(){
        return true;
    }

	virtual int num_control_points(){
		return 0;
	}

	virtual int num_data_points(){
		return 0;
	}

	void initialize_primal_residual_norm(){
		this->prev_outer_primal_residual_sqr_norm = 0;
	}

	// Return pointer to coordinates of data points and control points
	virtual double* data_point_coord(int){return NULL;}
	virtual double* control_point_coord(int){return NULL;}

	void initialize_y_constraint_data();

	// Update dual variables
	// Then Check if stopping criteria is met. If so, return true.
	// Otherwise, update penalty weight, and return false
	void stop_check_and_dual_var_penalty_weight_update(int iter_num);

	void dl_stop_check_and_dual_var_penalty_weight_update(int iter_num);

	void initialvalue_stop_check_and_dual_var_penalty_weight_update(int iter_num);

	void initialvalue_solve();

    void init_variables(int num_threads,
                        double laplacian_energy_bound,
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
                        double dlweight_,
                        bool linearPrecision_);

	void initialvalue_update_v();
	void initialvalue_update_w();

	bool need_increment_penalty();
	bool need_increment_penalty_dl();
	bool compute_penalty_change_ratio();	// Return true if penalty need to change. This method is used in initial value optimization
};

// A class that updates x based on L0 norm target function
class SBCL0Update : public virtual SBCOptBase
{
public:
	virtual ~SBCL0Update(){}
protected:

    int sgn(double val)
    {
        return (0 < val) - (val < 0);
    }
    void update_x();
};


class SBCHalfNormUpdate : public virtual SBCOptBase
{
public:
	virtual ~SBCHalfNormUpdate(){}
protected:
    void update_x_bailin();
    void update_x_interval();
    void update_x();
	double func_val(double x_val, double v_val)
	{
        return std::sqrt(std::abs(x_val)) + this->penalty_weight*(v_val - x_val)*(v_val - x_val);
	}
};


// A template class with T being an openmesh type
template<typename T1, typename T2>
class SBCMeshWithBoundaryControl : public virtual SBCOptBase
{
public:
    SBCMeshWithBoundaryControl(T1 *mesh_, int dim_, bool hasCage_, T2 cage_, int laplaceType_, bool nonnegativeConstraint_)
        :pmesh(mesh_), dim(dim_), hasCage(hasCage_), cage(cage_), laplacceType(laplaceType_), nonnegativeConstraint(nonnegativeConstraint_){
		initialize_mesh_data();
	}

	virtual ~SBCMeshWithBoundaryControl(){}

protected:
	virtual int point_dim(){
		return this->dim;
	}

    virtual bool nonnegative_constraint(){
        return this->nonnegativeConstraint;
    }

	virtual int num_control_points(){
		return this->n_boundary_pt;
	}

	virtual int num_data_points(){
		return this->n_data_pt;
	}

	virtual void initialize_fairness_energy_matrix();

	virtual double* data_point_coord(int i){
        return point_data[datapt_idx_to_vtx_idx_map[i]].data();
	}
	virtual double* control_point_coord(int i){
        return point_data[controlpt_idx_to_vtx_idx_map[i]].data();
	}

protected:
	int n_boundary_pt, n_data_pt;
    T1 *pmesh;
	int dim;
    bool hasCage;
    bool nonnegativeConstraint;
    int laplacceType;
    T2 cage;


	// Mean-centered coordinates for vertices.
	// For 2d meshes, the first two coordinates are projection coordinates to the least squares plane of the whole mesh, and the third coordinates are zero
	std::vector<OpenMesh::Vec3d> point_data;

	std::vector<int> datapt_idx_to_vtx_idx_map;	// A map from data point index to vertex index
	std::vector<int> vtx_idx_to_datapt_idx_map;
	std::vector<int> vtx_idx_to_control_pt_idx_map;
	std::vector<int> controlpt_idx_to_vtx_idx_map; // A map from control point index to vertex index

	void initialize_mesh_data();
};

template<typename T1, typename T2, typename T3>
class SBCOpt : public T1, public SBCMeshWithBoundaryControl<T2, T3>
{
public:
    SBCOpt(T2 *mesh_, int dim, bool hasCage_, T3 cage_, int laplaceType_, bool nonnegativeConstraint_):
    SBCMeshWithBoundaryControl<T2, T3>(mesh_, dim, hasCage_, cage_, laplaceType_, nonnegativeConstraint_){}

	void get_test_tex_coord(std::vector<double> &init_w_tex_coord, std::vector<double> &w_tex_coord);

	void get_control_point_coord(Eigen::MatrixXd &cp_coord);

	virtual ~SBCOpt(){}

	void update_control_points();
	void solve_dl();
	void solve();
    void initialize_variables(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio, double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_, double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_, int max_iter, int primal_max_iter, double dlweight_, bool linearPrecision);
};


typedef SBCOpt<SBCL0Update, PolyMeshType, VertexGeometry*> SBCL0Mesh;
typedef SBCOpt<SBCHalfNormUpdate, PolyMeshType, VertexGeometry*> SBCLHalfMesh;
}}

#endif /* SBCOPT_H_ */
