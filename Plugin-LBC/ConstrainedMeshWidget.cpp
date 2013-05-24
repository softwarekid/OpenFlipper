/*
 * ConstrainedMeshWidget.cpp
 *
 *  Created on: Jul 14, 2012
 *      Author: Bailin Deng
 */

#include "ConstrainedMeshWidget.h"
#include "ConstrainedMeshPlugin.h"


namespace Dolphin { namespace plugins {

ConstrainedMeshWidget::ConstrainedMeshWidget(ConstrainedMeshPlugin& _plugin, QWidget* _parent)
: QWidget(_parent), plugin_(_plugin)
{
    setupUi(this);
}

ConstrainedMeshWidget::~ConstrainedMeshWidget(){}


void ConstrainedMeshWidget::on_pushButton_LoadDisp_clicked()
{
	//plugin_.read_vertex_displacement();
}

void ConstrainedMeshWidget::readSettings(DolphinSettings&) {
}

void ConstrainedMeshWidget::writeSettings(DolphinSettings&) {
}

void ConstrainedMeshWidget::on_pushButton_loadTangentBasis_clicked()
{
	//plugin_.show_2nddiff_sequences();
}

void ConstrainedMeshWidget::on_pushButton_AugLagL1Lesssplit_clicked()
{
	/*
	int update_period = this->spinBox_UpdatePeriod->value();
	double sparsity_weight = this->doubleSpinBox_RelSparsityWeight->value();
	double smoothness_weight = this->doubleSpinBox_SmoothnessWeight->value();
	double init_penalty_weight = this->doubleSpinBox_InitPenaltyWeight->value();
	double vtx_disp_weight = this->doubleSpinBox_VtxDispWeight->value();
	double primal_eps = this->doubleSpinBox_AugLagPrimalEps->value();
	double dual_eps = this->doubleSpinBox_AugLagDualEps->value();
	double init_dual_eps = this->doubleSpinBox_AugLagInitDualEps->value();
	int max_primal_iter = this->spinBox_PrimalMaxIter->value();
	int max_iter = this->spinBox_MaxIter->value();
	int nb_threads = this->spinBox_NbThreads->value();
	double tau_incr = 2;
	double inter_primal_eps = this->doubleSpinBox_InterPrimalEps->value();
	double inter_dual_eps = this->doubleSpinBox_InterDualEps->value();
	double init_inter_dual_eps = this->doubleSpinBox_InitInterDualEps->value();
	int nb_phases = this->spinBox_NbPhases->value();
	bool reuse_multipliers = this->checkBox_ReuseMultipliers->isChecked();
	//AugLagFairnessType fairness_type = AUGLAGFAIRNESS_LAPLACIAN;
	AugLagFairnessType fairness_type = get_fairness_type();
	int inner_regular_valence = 4;
	bool weighted_diff = checkBox_WeightedDiff->isChecked();
	bool check_boundary = checkBox_CheckBoundaryValence->isChecked();
	bool use_pq = checkBox_UsePQ->isChecked();
	bool normalize_weights = checkBox_NormalizeWeights->isChecked();
	double max_penalty_ratio = doubleSpinBox_MaxPenaltyRatio->value();
	bool hex_mesh = checkBox_hexmesh->isChecked();

	plugin_.L1_sparse_disp_auglag_polygonal_planar_mesh(update_period, sparsity_weight, smoothness_weight, vtx_disp_weight,
			init_penalty_weight, nb_phases, primal_eps, dual_eps, init_dual_eps, inter_primal_eps,
			inter_dual_eps, init_inter_dual_eps, max_iter, max_primal_iter, nb_threads, normalize_weights, fairness_type,
			hex_mesh, inner_regular_valence, check_boundary, weighted_diff, use_pq, reuse_multipliers, tau_incr,
			max_penalty_ratio);
			*/
}


void ConstrainedMeshWidget::on_pushButton_SetOriginalMesh_clicked()
{
	//plugin_.set_orig_mesh();
}


void ConstrainedMeshWidget::on_pushButton_clearFixedVtxDisp_clicked()
{
	//plugin_.clear_handle_disp();
}


void ConstrainedMeshWidget::on_pushButton_OutputObj_clicked()
{
	//plugin_.output_obj_file();
}

void ConstrainedMeshWidget::on_pushButton_InitDispPlanarization_clicked()
{
	/*
	int update_period = this->spinBox_UpdatePeriod->value();
	double sparsity_weight = this->doubleSpinBox_RelSparsityWeight->value();
	double smoothness_weight = this->doubleSpinBox_SmoothnessWeight->value();
	double init_penalty_weight = this->doubleSpinBox_InitPenaltyWeight->value();
	double vtx_disp_weight = this->doubleSpinBox_VtxDispWeight->value();
	double primal_eps = this->doubleSpinBox_AugLagPrimalEps->value();
	double dual_eps = this->doubleSpinBox_AugLagDualEps->value();
	double init_dual_eps = this->doubleSpinBox_AugLagInitDualEps->value();
	int max_primal_iter = this->spinBox_PrimalMaxIter->value();
	int max_iter = this->spinBox_MaxIter->value();
	int nb_threads = this->spinBox_NbThreads->value();
	double tau_incr = 2;
	double inter_primal_eps = this->doubleSpinBox_InterPrimalEps->value();
	double inter_dual_eps = this->doubleSpinBox_InterDualEps->value();
	double init_inter_dual_eps = this->doubleSpinBox_InitInterDualEps->value();
	int nb_phases = this->spinBox_NbPhases->value();
	bool reuse_multipliers = this->checkBox_ReuseMultipliers->isChecked();
	//AugLagFairnessType fairness_type = AUGLAGFAIRNESS_LAPLACIAN;
	AugLagFairnessType fairness_type = get_fairness_type();
	int inner_regular_valence = 4;
	bool weighted_diff = checkBox_WeightedDiff->isChecked();
	bool check_boundary = checkBox_CheckBoundaryValence->isChecked();
	bool use_pq = checkBox_UsePQ->isChecked();
	bool normalize_weights = checkBox_NormalizeWeights->isChecked();
	double max_penalty_ratio = doubleSpinBox_MaxPenaltyRatio->value();
	double init_disp_weight = doubleSpinBox_InitDispWeight->value();
	bool hex_mesh = checkBox_hexmesh->isChecked();
	bool reweighte_proj = checkBox_reweightedProjection->isChecked();
	double reweighted_tol = doubleSpinBox_reweightedToleranceRatio->value();
	bool dist_to_boundary = checkBox_QuadDistToBoundary->isChecked();

	plugin_.init_disp_planarization(update_period, sparsity_weight, smoothness_weight, vtx_disp_weight, init_disp_weight,
			init_penalty_weight, nb_phases, primal_eps, dual_eps, init_dual_eps, inter_primal_eps,
			inter_dual_eps, init_inter_dual_eps, max_iter, max_primal_iter, nb_threads, normalize_weights,
			dist_to_boundary, fairness_type, hex_mesh, inner_regular_valence, check_boundary, weighted_diff, use_pq, reuse_multipliers, tau_incr,
			max_penalty_ratio, reweighte_proj, reweighted_tol);
			*/
}


void ConstrainedMeshWidget::on_pushButton_HCL2Disp_clicked()
{
	/*
	int update_period = this->spinBox_UpdatePeriod->value();
	double l2_disp_weight = this->doubleSpinBox_InitDispWeight->value();
	double smoothness_weight = this->doubleSpinBox_SmoothnessWeight->value();
	double init_penalty_weight = this->doubleSpinBox_InitPenaltyWeight->value();
	double vtx_disp_weight = this->doubleSpinBox_VtxDispWeight->value();
	double primal_eps = this->doubleSpinBox_AugLagPrimalEps->value();
	double dual_eps = this->doubleSpinBox_AugLagDualEps->value();
	double init_dual_eps = this->doubleSpinBox_AugLagInitDualEps->value();
	int max_primal_iter = this->spinBox_PrimalMaxIter->value();
	int max_iter = this->spinBox_MaxIter->value();
	int nb_threads = this->spinBox_NbThreads->value();
	double tau_incr = 2;
	double inter_primal_eps = this->doubleSpinBox_InterPrimalEps->value();
	double inter_dual_eps = this->doubleSpinBox_InterDualEps->value();
	double init_inter_dual_eps = this->doubleSpinBox_InitInterDualEps->value();
	int nb_phases = this->spinBox_NbPhases->value();
	bool reuse_multipliers = this->checkBox_ReuseMultipliers->isChecked();
	//AugLagFairnessType fairness_type = AUGLAGFAIRNESS_LAPLACIAN;
	AugLagFairnessType fairness_type = get_fairness_type();
	int inner_regular_valence = 4;
	bool weighted_diff = checkBox_WeightedDiff->isChecked();
	bool check_boundary = checkBox_CheckBoundaryValence->isChecked();
	bool use_pq = checkBox_UsePQ->isChecked();
	bool normalize_weights = checkBox_NormalizeWeights->isChecked();
	double max_penalty_ratio = doubleSpinBox_MaxPenaltyRatio->value();
	bool dist_to_boundary = checkBox_QuadDistToBoundary->isChecked();

	plugin_.HC_L2_planarization(update_period, l2_disp_weight, smoothness_weight, vtx_disp_weight,
			init_penalty_weight, nb_phases, primal_eps, dual_eps, init_dual_eps, inter_primal_eps,
			inter_dual_eps, init_inter_dual_eps, max_iter, max_primal_iter, nb_threads, normalize_weights,
			dist_to_boundary, fairness_type, inner_regular_valence, check_boundary, weighted_diff, use_pq, reuse_multipliers, tau_incr, max_penalty_ratio);
			*/
}


void ConstrainedMeshWidget::on_pushButton_L2Planarization_clicked()
{
	/*
	int update_period = this->spinBox_UpdatePeriod->value();
	double l2_disp_weight = this->doubleSpinBox_InitDispWeight->value();
	double smoothness_weight = this->doubleSpinBox_SmoothnessWeight->value();
	double init_penalty_weight = this->doubleSpinBox_InitPenaltyWeight->value();
	double vtx_disp_weight = this->doubleSpinBox_VtxDispWeight->value();
	double primal_eps = this->doubleSpinBox_AugLagPrimalEps->value();
	double dual_eps = this->doubleSpinBox_AugLagDualEps->value();
	double init_dual_eps = this->doubleSpinBox_AugLagInitDualEps->value();
	int max_primal_iter = this->spinBox_PrimalMaxIter->value();
	int max_iter = this->spinBox_MaxIter->value();
	int nb_threads = this->spinBox_NbThreads->value();
	double tau_incr = 2;
	double inter_primal_eps = this->doubleSpinBox_InterPrimalEps->value();
	double inter_dual_eps = this->doubleSpinBox_InterDualEps->value();
	double init_inter_dual_eps = this->doubleSpinBox_InitInterDualEps->value();
	int nb_phases = this->spinBox_NbPhases->value();
	bool reuse_multipliers = this->checkBox_ReuseMultipliers->isChecked();
	//AugLagFairnessType fairness_type = AUGLAGFAIRNESS_LAPLACIAN;
	AugLagFairnessType fairness_type = get_fairness_type();
	int inner_regular_valence = 4;
	bool weighted_diff = checkBox_WeightedDiff->isChecked();
	bool check_boundary = checkBox_CheckBoundaryValence->isChecked();
	bool use_pq = checkBox_UsePQ->isChecked();
	bool normalize_weights = checkBox_NormalizeWeights->isChecked();
	double max_penalty_ratio = doubleSpinBox_MaxPenaltyRatio->value();
	bool dist_to_boundary = checkBox_QuadDistToBoundary->isChecked();

	plugin_.L2_planarization(update_period, l2_disp_weight, smoothness_weight, vtx_disp_weight,
			init_penalty_weight, nb_phases, primal_eps, dual_eps, init_dual_eps, inter_primal_eps,
			inter_dual_eps, init_inter_dual_eps, max_iter, max_primal_iter, nb_threads, normalize_weights,
			dist_to_boundary, fairness_type, inner_regular_valence, check_boundary, weighted_diff, use_pq, reuse_multipliers, tau_incr, max_penalty_ratio);
			*/
}

/*
AugLagFairnessType ConstrainedMeshWidget::get_fairness_type()
{
	int selected_idx = comboBox_fairness->currentIndex();
	if(selected_idx == 0){
		return AUGLAGFAIRNESS_2NDDIFF;
	}
	else if(selected_idx == 1){
		return AUGLAGFAIRNESS_UNIFORMLAPLACIAN;
	}
	else if(selected_idx == 2){
		return AUGLAGFAIRNESS_LAPLACIAN;
	}
	else{
		return AUGLAGFAIRNESS_3RDDIFF;
	}
}
*/
void ConstrainedMeshWidget::on_pushButton_SetHandles_clicked()
{
	//plugin_.setHandleIndices();
}


void ConstrainedMeshWidget::on_pushButton_ExitInteractiveMode_clicked()
{
	//plugin_.exit_interactive_mode();
}

void ConstrainedMeshWidget::on_pushButton_EnterInteractiveMode_clicked()
{
	//plugin_.enter_interactive_mode();
}

void ConstrainedMeshWidget::on_pushButton_OutputDispVec_clicked()
{
	//plugin_.output_edgesets();
}


void ConstrainedMeshWidget::on_pushButton_SBC_clicked()
{
	plugin_.test_SBC(this->get_num_threads(),
					 0.0,
                     laplacianminratio->value(),
					 this->get_init_penalty_weight(),
					 this->get_max_penalty_weight(),
					 this->get_primal_residual_eps(),
					 this->get_dual_residual_eps(),
					 this->get_init_dual_eps(),
					 this->get_intermediate_primal_eps(),
					 this->get_intermediate_dual_eps(),
					 2,
					 this->get_max_iteration(),
					 this->get_primal_max_iteration(),
                     doubleSpinBox_dlweight->value(),
                     spinBox_dim->value(),
                     comboBox_laplacianType->currentIndex(),
                     checkBox_nonnegative_sbc->isChecked(),
                     checkBox_linearPrecision->isChecked());
}

void ConstrainedMeshWidget::on_pushButton_loadData_clicked()
{
    plugin_.load_data(comboBox_weightType->currentIndex());
}

void ConstrainedMeshWidget::on_pushButton_displaySBC_clicked()
{
    plugin_.setCoordinateType(comboBox_weightType->currentIndex());
}

void ConstrainedMeshWidget::on_pushButton_meanvaluecoordinate_clicked()
{
    plugin_.computeMeanCoordinate(spinBox_dim->value());
}

void ConstrainedMeshWidget::on_pushButton_greencoordinate_clicked()
{
    plugin_.computeGreenCoordinate(spinBox_dim->value());
}

void ConstrainedMeshWidget::on_pushButton_harmoniccoordinate_clicked()
{
    plugin_.computeHarmonicCoordinate();
}

void ConstrainedMeshWidget::on_pushButton_ipoptl0solver_clicked()
{
    plugin_.ipoptl0_solve(spinBox_dim->value(),
                          comboBox_laplacianType->currentIndex(),
						  checkBox_nonnegative_sbc->isChecked());
}

void ConstrainedMeshWidget::on_pushButton_smoothBC_clicked()
{
    if (comboBox_smoothBCSolver->currentIndex() == 0)
    {
        plugin_.reWeighted_l2_smooth(this->get_num_threads(),
                                     laplacianminratio->value(),
                                     this->get_init_penalty_weight(),
                                     this->get_max_penalty_weight(),
                                     this->get_primal_residual_eps(),
                                     this->get_dual_residual_eps(),
                                     this->get_init_dual_eps(),
                                     this->get_intermediate_primal_eps(),
                                     this->get_intermediate_dual_eps(),
                                     2,
                                     this->get_max_iteration(),
                                     this->get_primal_max_iteration(),
                                     spinBox_dim->value(),
                                     comboBox_laplacianType->currentIndex(),
                                     checkBox_nonnegative_sbc->isChecked(),
                                     checkBox_linearPrecision->isChecked());
    }
    if (comboBox_smoothBCSolver->currentIndex() == 2)
    {
        // the solution by adm as initial value
        plugin_.computeSmoothBC(this->get_num_threads(),
                                0.0,
                                laplacianminratio->value(),
                                this->get_init_penalty_weight(),
                                this->get_max_penalty_weight(),
                                this->get_primal_residual_eps(),
                                this->get_dual_residual_eps(),
                                this->get_init_dual_eps(),
                                this->get_intermediate_primal_eps(),
                                this->get_intermediate_dual_eps(),
                                2,
                                this->get_max_iteration(),
                                this->get_primal_max_iteration(),
                                doubleSpinBox_dlweight->value(),
                                spinBox_dim->value(),
                                comboBox_laplacianType->currentIndex(),
                                checkBox_nonnegative_sbc->isChecked(),
                                checkBox_linearPrecision->isChecked());
    }
    if (comboBox_smoothBCSolver->currentIndex() == 3)
    {
        plugin_.ipoptsmooth_solve(spinBox_dim->value(),
                                  comboBox_laplacianType->currentIndex(),
                                  checkBox_nonnegative_sbc->isChecked(),
                                  checkBox_meshlessparameterization->isChecked(),
                                  laplacianminratio->value(),
                                  doubleSpinBox_tol->value(),
                                  doubleSpinBox_dual_inf_tol->value(),
                                  doubleSpinBox_dlweight->value());
    }
    if (comboBox_smoothBCSolver->currentIndex() == 1)
    {
        plugin_.computeSmoothBC(this->get_num_threads(),
                                0.0,
                                laplacianminratio->value(),
                                this->get_init_penalty_weight(),
                                this->get_max_penalty_weight(),
                                this->get_primal_residual_eps(),
                                this->get_dual_residual_eps(),
                                this->get_init_dual_eps(),
                                this->get_intermediate_primal_eps(),
                                this->get_intermediate_dual_eps(),
                                2,
                                this->get_max_iteration(),
                                this->get_primal_max_iteration(),
                                doubleSpinBox_dlweight->value(),
                                spinBox_dim->value(),
                                comboBox_laplacianType->currentIndex(),
                                checkBox_nonnegative_sbc->isChecked(),
                                checkBox_linearPrecision->isChecked());
        /*
        plugin_.ipoptsmooth_solve(spinBox_dim->value(),
                                  comboBox_laplacianType->currentIndex(),
                                  checkBox_nonnegative_sbc->isChecked(),
                                  checkBox_meshlessparameterization->isChecked(),
                                  laplacianminratio->value(),
                                  doubleSpinBox_tol->value(),
                                  doubleSpinBox_dual_inf_tol->value());
                                  */
        plugin_.knitro_smooth_solve(spinBox_dim->value(),
                                    comboBox_laplacianType->currentIndex(),
                                    checkBox_nonnegative_sbc->isChecked(),
                                    checkBox_meshlessparameterization->isChecked(),
                                    checkBox_linearPrecision->isChecked());
    }
}

void ConstrainedMeshWidget::on_pushButton_ipoptlhalfsolver_clicked()
{
    if (comboBox_solverType->currentIndex() == 2)
	{
		plugin_.ipopt_halfnorm_sbc_opt(comboBox_smoothPosition->currentIndex(),
									   doubleSpinBox_dlweight->value(),
									   checkBox_supplyhessian->isChecked(),
									   comboBox_weightType->currentIndex(),
									   spinBox_dim->value(),
									   comboBox_laplacianType->currentIndex(),
									   checkBox_controlVariables->isChecked(),
									   checkBox_nonnegative_sbc->isChecked());
	}

    if (comboBox_solverType->currentIndex() == 3)
    {
	}

    if (comboBox_solverType->currentIndex() == 4)
    {
        // at the last, use interior point method to make the solution in the feasible set
		plugin_.ipoptlhalf_solve(comboBox_smoothPosition->currentIndex(),
								 doubleSpinBox_dlweight->value(),
								 checkBox_supplyhessian->isChecked(),
								 comboBox_weightType->currentIndex(),
								 spinBox_dim->value(),
								 comboBox_laplacianType->currentIndex(),
								 checkBox_controlVariables->isChecked(),
								 doubleSpinBox_controlWeight->value(),
								 checkBox_nonnegative_sbc->isChecked(),
								 doubleSpinBox_tol->value(),
                                 doubleSpinBox_dual_inf_tol->value(),
                                 checkBox_meshlessparameterization->isChecked(),
                                 doubleSpinBox_sparsity->value());
	}

    if (comboBox_solverType->currentIndex() == 1)
    {
        plugin_.knitro_lhalf_solve(comboBox_smoothPosition->currentIndex(),
                                   doubleSpinBox_dlweight->value(),
                                   checkBox_supplyhessian->isChecked(),
                                   comboBox_weightType->currentIndex(),
                                   spinBox_dim->value(),
                                   comboBox_laplacianType->currentIndex(),
                                   checkBox_controlVariables->isChecked(),
                                   doubleSpinBox_controlWeight->value(),
                                   checkBox_nonnegative_sbc->isChecked(),
                                   doubleSpinBox_tol->value(),
                                   doubleSpinBox_dual_inf_tol->value(),
                                   checkBox_meshlessparameterization->isChecked(),
                                   laplacianminratio->value());
    }
    if (comboBox_solverType->currentIndex() == 0)
    {
        if (spinBox_dim->value() == 2)
        {
            plugin_.reWeighted_l2_solve(this->get_num_threads(),
                                        laplacianminratio->value(),
                                        this->get_init_penalty_weight(),
                                        this->get_max_penalty_weight(),
                                        this->get_primal_residual_eps(),
                                        this->get_dual_residual_eps(),
                                        this->get_init_dual_eps(),
                                        this->get_intermediate_primal_eps(),
                                        this->get_intermediate_dual_eps(),
                                        2,
                                        doubleSpinBox_dlweight->value(),
                                        doubleSpinBox_smoothnessWeight->value(),
                                        doubleSpinBox_sparsity->value(),
                                        doubleSpinBox_pNorm->value(),
                                        this->get_max_iteration(),
                                        this->get_primal_max_iteration(),
                                        spinBox_dim->value(),
                                        comboBox_laplacianType->currentIndex(),
                                        checkBox_nonnegative_sbc->isChecked(),
                                        comboBox_smoothPosition->currentIndex(),
                                        checkBox_linearPrecision->isChecked(),
                                        false);
        }
        else
        {
            plugin_.compute3D_LBC(this->get_num_threads(),
                                  laplacianminratio->value(),
                                  this->get_init_penalty_weight(),
                                  this->get_max_penalty_weight(),
                                  this->get_primal_residual_eps(),
                                  this->get_dual_residual_eps(),
                                  this->get_init_dual_eps(),
                                  this->get_intermediate_primal_eps(),
                                  this->get_intermediate_dual_eps(),
                                  2,
                                  doubleSpinBox_dlweight->value(),
                                  doubleSpinBox_smoothnessWeight->value(),
                                  doubleSpinBox_sparsity->value(),
                                  this->get_max_iteration(),
                                  this->get_primal_max_iteration(),
                                  spinBox_dim->value(),
                                  checkBox_nonnegative_sbc->isChecked(),
                                  comboBox_smoothPosition->currentIndex(),
                                  checkBox_linearPrecision->isChecked(),
                                  false);
        }
    }
    if (comboBox_solverType->currentIndex() == 6)
    {
        plugin_.reWeighted_l2_solve(this->get_num_threads(),
                                    laplacianminratio->value(),
                                    this->get_init_penalty_weight(),
                                    this->get_max_penalty_weight(),
                                    this->get_primal_residual_eps(),
                                    this->get_dual_residual_eps(),
                                    this->get_init_dual_eps(),
                                    this->get_intermediate_primal_eps(),
                                    this->get_intermediate_dual_eps(),
                                    2,
                                    doubleSpinBox_dlweight->value(),
                                    doubleSpinBox_smoothnessWeight->value(),
                                    doubleSpinBox_sparsity->value(),
                                    doubleSpinBox_pNorm->value(),
                                    this->get_max_iteration(),
                                    this->get_primal_max_iteration(),
                                    spinBox_dim->value(),
                                    comboBox_laplacianType->currentIndex(),
                                    checkBox_nonnegative_sbc->isChecked(),
                                    comboBox_smoothPosition->currentIndex(),
                                    checkBox_linearPrecision->isChecked(),
                                    true);
    }
    if (comboBox_solverType->currentIndex() == 5)
    {
        plugin_.test_SBC(this->get_num_threads(),
                         0.0,
                         laplacianminratio->value(),
                         this->get_init_penalty_weight(),
                         this->get_max_penalty_weight(),
                         this->get_primal_residual_eps(),
                         this->get_dual_residual_eps(),
                         this->get_init_dual_eps(),
                         this->get_intermediate_primal_eps(),
                         this->get_intermediate_dual_eps(),
                         2,
                         this->get_max_iteration(),
                         this->get_primal_max_iteration(),
                         doubleSpinBox_dlweight->value(),
                         spinBox_dim->value(),
                         comboBox_laplacianType->currentIndex(),
                         checkBox_nonnegative_sbc->isChecked(),
                         checkBox_linearPrecision->isChecked());
    }
}

void ConstrainedMeshWidget::on_pushButton_loadTetrahedral_clicked()
{
    plugin_.load_TetrahedralMesh();
}

void ConstrainedMeshWidget::on_pushButton_selectCage_clicked()
{
    plugin_.set_SelectObject_as_Cage();
}

void ConstrainedMeshWidget::on_pushButton_selectData_clicked()
{
    plugin_.set_SelectObject_as_Data();
}

void ConstrainedMeshWidget::on_pushButton_bctextureImage_clicked()
{
    plugin_.bcTextureImage(comboBox_weightType->currentIndex());
}

void ConstrainedMeshWidget::on_pushButton_displayDataPoints_clicked()
{
    plugin_.displayAllDataCoordinates(comboBox_weightType->currentIndex(),
                                      doubleSpinBox_weightEpsilon->value());
}

void ConstrainedMeshWidget::on_pushButton_parameterization_clicked()
{
    plugin_.bc_parameterization();
}

void ConstrainedMeshWidget::on_pushButton_Delaunay_clicked()
{
    plugin_.delaunay_Triangulation();
}

void ConstrainedMeshWidget::on_pushButton_bbw_clicked()
{
    plugin_.computeBBW(this->get_num_threads(),
                       laplacianminratio->value(),
                       this->get_init_penalty_weight(),
                       this->get_max_penalty_weight(),
                       this->get_primal_residual_eps(),
                       this->get_dual_residual_eps(),
                       this->get_init_dual_eps(),
                       this->get_intermediate_primal_eps(),
                       this->get_intermediate_dual_eps(),
                       2,
                       this->get_max_iteration(),
                       this->get_primal_max_iteration(),
                       spinBox_dim->value(),
                       comboBox_laplacianType->currentIndex());
}

void ConstrainedMeshWidget::on_pushButton_illustration_clicked()
{
    plugin_.oneDillustration(this->get_num_threads(),
                             laplacianminratio->value(),
                             this->get_init_penalty_weight(),
                             this->get_max_penalty_weight(),
                             this->get_primal_residual_eps(),
                             this->get_dual_residual_eps(),
                             this->get_init_dual_eps(),
                             this->get_intermediate_primal_eps(),
                             this->get_intermediate_dual_eps(),
                             2,
                             this->get_max_iteration(),
                             100,
                             doubleSpinBox_sparsity->value());
}

void ConstrainedMeshWidget::on_pushButton_localExtrema_clicked()
{
    plugin_.displayLocalExtrema(comboBox_weightType->currentIndex());
}

void ConstrainedMeshWidget::on_pushButton_SaveDispLengthColor_clicked()
{
	/*
	bool compare_input_disp = checkBox_CompareInputDisp->isChecked();
	plugin_.save_mesh_disp_length_color_info(compare_input_disp);
	*/
}

void ConstrainedMeshWidget::on_pushButton_FaceColorInfo_clicked()
{
	/*
	int level_num = spinBox_ColorLevels->value();
	bool diag_dist = checkBox_diagDist->isChecked();
	bool use_local_dist = checkBox_LocalDistInfo->isChecked();
	plugin_.save_planarity_dist_color_info(diag_dist, use_local_dist, level_num);
	*/
}

void ConstrainedMeshWidget::on_pushButton_ConvertMTL_clicked()
{
	/*
	int level_num = plugin_.save_colorbar_mtl_file();
	if(level_num > 0){
		spinBox_ColorLevels->setValue(level_num);
	}
	*/
}

void ConstrainedMeshWidget::on_pushButton_ReadDisplacemenVectors_clicked()
{
	//plugin_.load_edgesets();
}

void ConstrainedMeshWidget::on_pushButton_OutputFairnessMatrix_clicked()
{
	/*
	int update_period = this->spinBox_UpdatePeriod->value();
	double sparsity_weight = this->doubleSpinBox_RelSparsityWeight->value();
	double smoothness_weight = this->doubleSpinBox_SmoothnessWeight->value();
	double init_penalty_weight = this->doubleSpinBox_InitPenaltyWeight->value();
	double vtx_disp_weight = this->doubleSpinBox_VtxDispWeight->value();
	double primal_eps = this->doubleSpinBox_AugLagPrimalEps->value();
	double dual_eps = this->doubleSpinBox_AugLagDualEps->value();
	double init_dual_eps = this->doubleSpinBox_AugLagInitDualEps->value();
	int max_primal_iter = this->spinBox_PrimalMaxIter->value();
	int max_iter = this->spinBox_MaxIter->value();
	int nb_threads = this->spinBox_NbThreads->value();
	double tau_incr = 2;
	double inter_primal_eps = this->doubleSpinBox_InterPrimalEps->value();
	double inter_dual_eps = this->doubleSpinBox_InterDualEps->value();
	double init_inter_dual_eps = this->doubleSpinBox_InitInterDualEps->value();
	int nb_phases = this->spinBox_NbPhases->value();
	bool reuse_multipliers = this->checkBox_ReuseMultipliers->isChecked();
	//AugLagFairnessType fairness_type = AUGLAGFAIRNESS_LAPLACIAN;
	AugLagFairnessType fairness_type = get_fairness_type();
	int inner_regular_valence = 4;
	bool weighted_diff = checkBox_WeightedDiff->isChecked();
	bool check_boundary = checkBox_CheckBoundaryValence->isChecked();
	bool use_pq = checkBox_UsePQ->isChecked();
	bool normalize_weights = checkBox_NormalizeWeights->isChecked();
	bool hex_mesh = checkBox_hexmesh->isChecked();

	plugin_.output_fairness_energy_matrix(update_period, sparsity_weight, smoothness_weight, vtx_disp_weight,
			init_penalty_weight, nb_phases, primal_eps, dual_eps, init_dual_eps, inter_primal_eps,
			inter_dual_eps, init_inter_dual_eps, max_iter, max_primal_iter, nb_threads, normalize_weights, fairness_type,
			hex_mesh, inner_regular_valence, check_boundary, weighted_diff, use_pq, reuse_multipliers, tau_incr);
			*/
}

}}//namespaces


