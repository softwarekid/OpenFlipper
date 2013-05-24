/*
 * ConstrainedMeshWidget.h
 *
 *  Created on: Jul 14, 2012
 *      Author: Bailin Deng
 */

#ifndef CONSTRAINEDMESHWIDGET_H_
#define CONSTRAINEDMESHWIDGET_H_

#include <QtGui/QWidget>
#include "ui_ConstrainedMeshWidget.h"
#include "ConstrainedMeshPluginTypedef.h"

namespace Dolphin {
  class DolphinSettings;
}

namespace Dolphin { namespace plugins {

  class ConstrainedMeshPlugin;



  class ConstrainedMeshWidget: public QWidget, private Ui_ConstrainedMeshWidget {
		Q_OBJECT

  public:

	  ConstrainedMeshWidget(ConstrainedMeshPlugin& _plugin, QWidget* _parent=0);
	  ~ConstrainedMeshWidget();
	  void readSettings(DolphinSettings&);
	  void writeSettings(DolphinSettings&);

  private slots:

	void on_pushButton_LoadDisp_clicked();
//	void on_pushButton_OptimizeL0SDMM_clicked();
//	void on_pushButton_OptimizeL1SDMM_clicked();
//	void on_pushButton_OptimizeL0ADMM_clicked();
//	void on_pushButton_OptimizeL1ADMM_clicked();
//	void on_pushButton_L1_penalty_clicked();
//	void on_pushButton_L1_ADMM2ndDiff_clicked();
//	void on_pushButton_L1ADMMSoftConstraint_clicked();
	void on_pushButton_loadTangentBasis_clicked();
//	void on_pushButton_L1TangentDisp_clicked();
//	void on_pushButton_L1TangentDispOpenMP_clicked();
//	void on_pushButton_L1ADMMSoftConstraintMat_clicked();
	void on_pushButton_SetHandles_clicked();
//	void on_pushButton_InitializeADMMSolver_clicked();
	void on_pushButton_ExitInteractiveMode_clicked();
//	void on_pushButton_L1_penaltymethod_clicked();
//	void on_pushButton_L1AugLag_clicked();
//	void on_pushButton_Planarization_clicked();
	void on_pushButton_AugLagL1Lesssplit_clicked();
	void on_pushButton_OutputDispVec_clicked();
	void on_pushButton_SaveDispLengthColor_clicked();
	void on_pushButton_FaceColorInfo_clicked();
	void on_pushButton_ConvertMTL_clicked();
	void on_pushButton_ReadDisplacemenVectors_clicked();
	void on_pushButton_OutputFairnessMatrix_clicked();
	void on_pushButton_L2Planarization_clicked();
	void on_pushButton_InitDispPlanarization_clicked();
	void on_pushButton_SetOriginalMesh_clicked();
	void on_pushButton_clearFixedVtxDisp_clicked();
	void on_pushButton_OutputObj_clicked();
	void on_pushButton_EnterInteractiveMode_clicked();
	void on_pushButton_HCL2Disp_clicked();
	void on_pushButton_SBC_clicked();
	void on_pushButton_loadData_clicked();
	void on_pushButton_displaySBC_clicked();
    void on_pushButton_meanvaluecoordinate_clicked();
    void on_pushButton_greencoordinate_clicked();
    void on_pushButton_harmoniccoordinate_clicked();
    void on_pushButton_ipoptl0solver_clicked();
    void on_pushButton_smoothBC_clicked();
    void on_pushButton_ipoptlhalfsolver_clicked();
    void on_pushButton_loadTetrahedral_clicked();
    void on_pushButton_selectCage_clicked();
    void on_pushButton_selectData_clicked();
    void on_pushButton_bctextureImage_clicked();
    void on_pushButton_displayDataPoints_clicked();
    void on_pushButton_parameterization_clicked();
    void on_pushButton_Delaunay_clicked();
    void on_pushButton_bbw_clicked();
    void on_pushButton_illustration_clicked();
    void on_pushButton_localExtrema_clicked();

  private:
	ConstrainedMeshPlugin& plugin_;
	//AugLagFairnessType get_fairness_type();

	int get_num_threads(){
		return this->spinBox_NbThreads->value();
	}

	double get_init_penalty_weight(){
		return this->doubleSpinBox_InitPenaltyWeight->value();
	}

	double get_max_penalty_weight(){
		return this->doubleSpinBox_MaxPenaltyRatio->value() * this->doubleSpinBox_InitPenaltyWeight->value();
	}

	double get_primal_residual_eps(){
		return this->doubleSpinBox_AugLagPrimalEps->value();
	}

	double get_dual_residual_eps(){
		return this->doubleSpinBox_AugLagDualEps->value();
	}

	double get_init_dual_eps(){
		return this->doubleSpinBox_AugLagInitDualEps->value();
	}

	double get_intermediate_primal_eps(){
		return this->doubleSpinBox_InterPrimalEps->value();
	}

	double get_intermediate_dual_eps(){
		return this->doubleSpinBox_InterDualEps->value();
	}

	int get_max_iteration(){
		return this->spinBox_MaxIter->value();
	}

	int get_primal_max_iteration(){
		return this->spinBox_PrimalMaxIter->value();
	}
};

}}


#endif /* CONSTRAINEDMESHWIDGET_H_ */
