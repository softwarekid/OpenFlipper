/*
 * ConstrainedMeshPlugin.cpp
 *
 *  Created on: Jul 13, 2012
 *      Author: Bailin Deng
 */


#include "ConstrainedMeshPlugin.h"
#include "ConstrainedMeshPluginAux.h"
#include "ConstrainedMeshWidget.h"
#include <Dolphin/Core/Utilities/dolphinstream.h>
#include <Dolphin/Core/Scenegraph/Scenegraph.h>
#include <Dolphin/Core/Scenegraph/Geometry/EdgeSetNode.h>
#include <Dolphin/Core/DataStructures/EdgeSet.h>
#include <Utilities/Qt/Visualization/MeshHistogram.h>
#include <Utilities/Qt/Widgets/HistogramWidget/HistogramWidget.h>
#include <PluginsExtension/HistogramPlugin/HistogramPlugin.h>
#include <Dolphin/Plugins/PluginManager/PluginManager.h>
#include <Dolphin/GUI/Qt4/Widgets/NodeDialogs/OpenMeshNodeDialog/OpenMeshNodeTextureDialog.h>
#include <Dolphin/Core/Scenegraph/Core/Texture.h>
#include <QtGui>
#include <QImage>
#include <fstream>
#include <iomanip>
#include <Dolphin/Core/Scenegraph/Geometry/SplineNode.h>
#include "IpoptHalfNormSBC.h"

// Picker
#include <Dolphin/Core/Selection/BasePicker.h>
#include <Dolphin/Core/Selection/RayPicker.h>

// Paths
#include <Dolphin/Core/Scenegraph/Geometry/OMeshPathNode.h>
#include <Dolphin/Core/DataStructures/OMeshPath.h>

// Eigen
#include <Eigen/LU>

// Time
#include <ctime>


#ifdef MATLAB_EXISTS
#include <Utilities/Matlab/EngineWrapper.h>
#include <Utilities/Matlab/MxWrapper.h>
#include <Utilities/Matlab/MatlabUtilities.h>
#endif


#include <boost/lexical_cast.hpp>

//using namespace Dolphin::utilities::shapeup;

#define _MAX_NORM_EPS_ 1e-4

namespace Dolphin { namespace plugins {


ConstrainedMeshPlugin::ConstrainedMeshPlugin()
:widget(new ConstrainedMeshWidget(*this)), interactive_orig_meshnode(NULL),  interactive_disp_edgeset_node(NULL), interactive_mode(false)
{
    sbcl0_solver = NULL;
    coordinateType_ = 0;
    hasCage_ = false;
    color_map_ = false;
    smoothness_bound = 0;
    linearPrecision_ = true;
    pickedCageVertex = -1;
}

ConstrainedMeshPlugin::~ConstrainedMeshPlugin(){}


void ConstrainedMeshPlugin::init(MainApplication *_mainApplication)
{
    Plugin_interface::init(_mainApplication);
    setMaxiWidget(widget.get());
}
/*
void ConstrainedMeshPlugin::l0_optimize_PQMesh_Disp_SDMM(int update_period, double rel_sparsity_weight, double smoothness_weight,
		double init_penalty_weight, double stop_ep_abs, double stop_ep_rel, double lambda, double tau_incr, double tau_decr,
		bool use_mat_var)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispSDMM sdmm;
	double sparsity_weight = l0_sparsity_weight(rel_sparsity_weight);
	sdmm.initialize_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight, init_penalty_weight, stop_ep_abs,
			stop_ep_rel, lambda, tau_incr, tau_decr, use_mat_var);
//	double Z_weight = 1;
//	double Y_weight = 1;
//	double W_weight = 1;
//	double min_change_bound = get_min_vec_change(deformedMeshNode->getMesh().get());
//	sdmm.initialize_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight, init_penalty_weight,
//			Z_weight, Y_weight, W_weight, min_change_bound, lambda, tau_incr, tau_decr, use_mat_var);
	std::vector<MeshPointType> opt_disp;

	DrawModes* modes = deformedMeshNode->getDrawModes();
	modes->setMode(DrawModes::FACE_DRAWING,true);
    modes->setMode(DrawModes::FACE_COLOR_FLAT,true);
    modes->resetMode(DrawModes::FACE_SHADING_FLAT,true);
	HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	histogram->getColorMap()->setBoundaries(0.0, 0.01);
	mesh_histogram = std::tr1::shared_ptr<MeshHistogram>( new MeshHistogram(histogram,deformedMeshNode, sdmm.face_diagonal_dist_measure(), utilities::FACE));
	mesh_histogram->showOnMesh(false);
	sdmm.set_histogram(mesh_histogram.get());

	sdmm.L0_optimize(opt_disp);
	//sdmm.weighted_L0_optimize(opt_disp);
}

void ConstrainedMeshPlugin::l0_optimize_PQMesh_Disp_ADMM(int update_period, double rel_sparsity_weight, double smoothness_weight, double penalty_weight,
		double stop_ep_abs, double stop_ep_rel, bool use_mat_var)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispADMM admm;
	double sparsity_weight = l0_sparsity_weight(rel_sparsity_weight);
	admm.initialize_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight, penalty_weight, stop_ep_abs,
			stop_ep_rel, use_mat_var);
	std::vector<MeshPointType> opt_disp;
	admm.L0_optimize(opt_disp);
}

void ConstrainedMeshPlugin::l1_optimize_PQMesh_Disp_ADMM(int update_period, double rel_sparsity_weight, double smoothness_weight, double penalty_weight,
		double stop_ep_abs, double stop_ep_rel, bool use_mat_var)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispADMM admm;
	double sparsity_weight = l1_sparsity_weight(rel_sparsity_weight);
	admm.initialize_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight,
			penalty_weight, stop_ep_abs, stop_ep_rel, use_mat_var);
	std::vector<MeshPointType> opt_disp;
	admm.L1_optimize(opt_disp);
}


void ConstrainedMeshPlugin::L1_optimize_PQMesh_Disp_softconstraint_matrix(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool soft_constraint_disp)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispSoftCon admm;
	double sparsity_weight = rel_sparsity_weight_;
	admm.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness, vtx_disp_weight, soft_constraint_disp);
	std::vector<MeshPointType> opt_disp;

	DrawModes* modes = deformedMeshNode->getDrawModes();
	modes->setMode(DrawModes::FACE_DRAWING,true);
    modes->setMode(DrawModes::FACE_COLOR_FLAT,true);
    modes->resetMode(DrawModes::FACE_SHADING_FLAT,true);
	HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	double avg_edge_length = average_edge_length(deformed_pmesh.get());
	histogram->getColorMap()->setBoundaries(0.0, 4 * ( avg_edge_length * avg_edge_length * 0.0001 ));
	mesh_histogram = std::tr1::shared_ptr<MeshHistogram>( new MeshHistogram(histogram,deformedMeshNode, std::vector<double>(deformed_pmesh->n_faces(), 0.0), utilities::FACE) );
	mesh_histogram->showOnMesh(false);
	admm.set_histogram(mesh_histogram.get());
	admm.L1_optimize(opt_disp);
}


void ConstrainedMeshPlugin::L1_optimize_PQMesh_Disp_softconstraint(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool diffvec_planarity)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispSoftConstraint admm;
	double sparsity_weight = rel_sparsity_weight_;
	admm.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, vtx_disp_weight, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_,
			threshold_smoothness, 10000, diffvec_planarity);
	std::vector<MeshPointType> opt_disp;

	admm.L1_optimize(opt_disp);
}



void ConstrainedMeshPlugin::L1_optimize_PQMesh_Disp_softconstraint_rowmajor(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool diffvec_planarity)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispSoftConRowMajor admm;
	double sparsity_weight = rel_sparsity_weight_;
	admm.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, vtx_disp_weight, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_,
			threshold_smoothness, diffvec_planarity);
	std::vector<MeshPointType> opt_disp;

	admm.L1_optimize(opt_disp);
}


void ConstrainedMeshPlugin::L1_PQMesh_tangent_disp_softconstraint(int update_period_, double rel_sparsity_weight_,
		double smoothness_weight_, double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

//    if(!is_valid_tangent_basis(pmesh.get())){
//    	return;
//    }

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	Eigen::SparseMatrix<double> Nb;
	get_PQMesh_normal_space_basis(deformed_pmesh.get(), Nb);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	//PQTangentSparseDisp admm;
	PQTangentDispNormalConstraint admm;
	double sparsity_weight = rel_sparsity_weight_;

	//admm.initialize_variables(deformedMeshNode, tangent_basis, update_period_, fixed_vtx_disp, sparsity_weight,
	//		smoothness_weight_, vtx_disp_weight,init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness);
	admm.initialize_variables(deformedMeshNode, Nb, update_period_, fixed_vtx_disp, sparsity_weight,
		smoothness_weight_, vtx_disp_weight,init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness);
	std::vector<MeshPointType> opt_disp;
	admm.L1_optimize(opt_disp);

	show_displacements(meshNode, &getScenegraph(), opt_disp, "Tangent Disp");
}


void ConstrainedMeshPlugin::L1_PQMesh_tangent_disp_softconstraint_openmp(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

//    if(!is_valid_tangent_basis(pmesh.get())){
//    	return;
//    }

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	Eigen::SparseMatrix<double> Nb;
	get_PQMesh_normal_space_basis(deformed_pmesh.get(), Nb);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispViaTangentSpace admm;
	double sparsity_weight = rel_sparsity_weight_;

	admm.initialize_variables(deformedMeshNode, Nb, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, vtx_disp_weight,init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness, 5000);
	std::vector<MeshPointType> tangent_disp, opt_disp;
	admm.L1_optimize(tangent_disp, opt_disp);


	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");

	show_deformed_mesh(meshNode, tangent_disp, "Tangent Displaced Mesh");
	show_displacements(meshNode, &getScenegraph(), tangent_disp, "Tangent Disp");
}


void ConstrainedMeshPlugin::L1_PQMesh_sparse_disp_softconstraint_penaltymethod(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

//    if(!is_valid_tangent_basis(pmesh.get())){
//    	return;
//    }

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
//	Eigen::SparseMatrix<double> Nb;
//	get_PQMesh_normal_space_basis(deformed_pmesh.get(), Nb);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispPenaltyMethod solver;
	double sparsity_weight = rel_sparsity_weight_;
	double avg_edge_length = average_edge_length(deformed_pmesh.get());

	solver.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, vtx_disp_weight, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness, avg_edge_length * 1e-3, 20000);
	std::vector<MeshPointType> opt_disp;
	solver.L1_optimize(opt_disp);

	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}

void ConstrainedMeshPlugin::show_2nddiff_sequences()
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    std::vector< std::vector<int> > polyline_idx;
    get_2nddiff_polyline_idx(pmesh.get(), 4, false, polyline_idx);

    for(int i = 0; i < static_cast<int>(polyline_idx.size()); i++){

    	int b_num = 0;
    	for(int k = 0; k < 3; k++){
    		if(pmesh->is_boundary(PolyMeshType::VertexHandle(polyline_idx[i][k]))){
    			b_num ++;
    		}
    	}

    	if(b_num == 2){
    		dolphinErr() << "sequence with 2 boundary vertices" << std::endl;
    	}


    	if(!(pmesh->is_boundary(PolyMeshType::VertexHandle(polyline_idx[i][0]))
    		&& pmesh->is_boundary(PolyMeshType::VertexHandle(polyline_idx[i][1]))
    		&& pmesh->is_boundary(PolyMeshType::VertexHandle(polyline_idx[i][2])))){
    		continue;
    	}



    	std::tr1::shared_ptr<EdgeSet> dEdgeSet(new EdgeSet());
    	for(int j = 0; j < 2; j++){
    		dEdgeSet->addEdge(pmesh->point(PolyMeshType::VertexHandle(polyline_idx[i][j])),
    				pmesh->point(PolyMeshType::VertexHandle(polyline_idx[i][j+1])));
    	}
    	EdgeSetNode* dEdgeSetNode = new EdgeSetNode(&getScenegraph(), dEdgeSet);
    	dEdgeSetNode->setName("Seq");
    	dEdgeSetNode->setGeometryChanged();
    }
}


void ConstrainedMeshPlugin::L1_sparse_disp_auglag_PQ_lesssplit(int update_period_, double sparsity_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type,
		bool hex_mesh,
		int inner_regular_valence, bool check_boundary, bool weighted_diff, bool reuse_multipliers, double tau_incr_,
		double max_penalty_ratio)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();


    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQL1SparseDispOptimizer solver;
	solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
			vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
			tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization,
			fairness_type, hex_mesh, inner_regular_valence, check_boundary, weighted_diff, max_penalty_ratio);
	std::vector<MeshPointType> opt_disp;
	solver.L1_optimize(opt_disp);
	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}



void ConstrainedMeshPlugin::output_fairness_energy_matrix(int update_period_, double sparsity_weight, double smoothness_weight_,
			double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
			double primal_eps, double dual_eps, double init_dual_eps,
			double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
			int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type,
			bool hex_mesh,
			int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
			bool reuse_multipliers, double tau_incr_)
{

	QString fileName = QFileDialog::getSaveFileName(0, tr("Choose file to save energy matrix"));

	if(fileName.isNull()){
		return;
	}

	std::ofstream ofile(fileName.toAscii().data());
	if(!ofile.is_open()){
		std::cerr << "Unable to create matrix file" << std::endl;
		return;
	}

	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();


//    if(!is_valid_displacement(pmesh.get())){
//    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
//    	return;
//    }

//	meshNode->setVisible(false);
//
//	//copy to original mesh:
//	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
//	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
//	deformedMeshNode->setSelected(false);
//	deformedMeshNode->setName( "Deformed Mesh" );
//	setMeshMaterial( deformedMeshNode );

	ofile.precision(20);

	if(use_pq_mesh){
		PQL1SparseDispOptimizer solver;
		solver.initialize_variables(meshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type,
				hex_mesh, inner_regular_valence, check_boundary_valence, weighted_diff);
		ofile << solver.get_E();
	}
	else{
		PolygonalPlanarMeshL1SparseDisp solver;
		//PolygonalPlanarMeshL1SparseDispMC solver;
		solver.initialize_variables(meshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type,
				hex_mesh, inner_regular_valence, check_boundary_valence, weighted_diff);
		ofile << solver.get_E();
	}
}


void ConstrainedMeshPlugin::HC_L2_planarization(int update_period_, double l2_disp_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization,
		double quad_dist_on_boundary, AugLagFairnessType fairness_type,
		int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
		bool reuse_multipliers, double tau_incr_, double max_penalty_ratio)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();
	meshNode->setVisible(false);

	if(this->fixed_vtx_disp.empty()){
		std::cout << "No hard constraint" << std::endl;
	}

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Planarized Mesh" );
	setMeshMaterial( deformedMeshNode );
	std::vector<MeshPointType> opt_disp;
	std::vector<double> individual_vtx_disp_weight(deformedMeshNode->getMesh()->n_vertices(), l2_disp_weight);

	if(use_pq_mesh){
		PQL2HCDisp solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, this->fixed_vtx_disp, nb_phases, individual_vtx_disp_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, quad_dist_on_boundary, fairness_type, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);
		solver.L2_optimize(opt_disp);
	}
	else{
		PolygonalPlanarMeshL2HCDisp solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, this->fixed_vtx_disp, nb_phases, individual_vtx_disp_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, quad_dist_on_boundary, fairness_type, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);

		solver.L2_optimize(opt_disp);
	}

	show_displacements(meshNode, &getScenegraph(), opt_disp, "Planarization Disp");
}


void ConstrainedMeshPlugin::L2_planarization(int update_period_, double l2_disp_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization,
		double quad_dist_on_boundary, AugLagFairnessType fairness_type,
		int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
		bool reuse_multipliers, double tau_incr_, double max_penalty_ratio)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();
	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Planarized Mesh" );
	setMeshMaterial( deformedMeshNode );
	std::vector<MeshPointType> opt_disp;
	std::vector<double> individual_vtx_disp_weight(deformedMeshNode->getMesh()->n_vertices(), l2_disp_weight);

	if(use_pq_mesh){
		PQL2DispOptimizer solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, this->fixed_vtx_disp, nb_phases, individual_vtx_disp_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, quad_dist_on_boundary, fairness_type, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);
		solver.L2_optimize(opt_disp);
	}
	else{
		PolygonalPlanarMeshL2Disp solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, this->fixed_vtx_disp, nb_phases, individual_vtx_disp_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, quad_dist_on_boundary, fairness_type, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);

		solver.L2_optimize(opt_disp);
	}

	show_displacements(meshNode, &getScenegraph(), opt_disp, "Planarization Disp");
}
*/

void ConstrainedMeshPlugin::set_orig_mesh()
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    original_mesh = meshNode->getMesh();
    dolphinOut() << "Set original mesh" << std::endl;
}

/*
void ConstrainedMeshPlugin::init_disp_planarization(int update_period_, double sparsity_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization,
		bool quad_dist_on_boundary, AugLagFairnessType fairness_type, bool hex_mesh,
		int inner_regular_valence, bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
		bool reuse_multipliers, double tau_incr_, double max_penalty_ratio,
		bool use_reweighting, double reweighted_tolerance_ratio)
{
	if(!original_mesh){
		dolphinErr() << "No original mesh" << std::endl;
		return;
	}

	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();
    if(pmesh.get() == original_mesh.get()){
    	dolphinErr() << "Selected mesh is the same as original mesh" << std::endl;
    	return;
    }

    if(pmesh->n_vertices() != original_mesh->n_vertices()){
    	dolphinErr() << "Different number of vertices between selected mesh and original mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);


	std::vector<MeshPointType> opt_disp, init_disp;

	int n_vtx = pmesh->n_vertices();
	for(int i = 0; i < n_vtx; i++){
		init_disp.push_back(pmesh->point(PolyMeshType::VertexHandle(i)) - original_mesh->point(PolyMeshType::VertexHandle(i)));
	}


//	void initialize_variables(OpenMeshNode *mesh_, int update_period_, int nb_threads, const std::map<int, MeshPointType> &fixed_vtx_disp,
//			const std::vector<MeshPointType> &init_disp,  int nb_phases,
//			double sparsity_weight, double init_disp_weight, double smoothness_weight_, double vtx_disp_weight_, double init_penalty_weight_, double primal_eps_val_, double dual_eps_val_,
//			double init_dual_eps_val, double inter_primal_eps_val, double inter_dual_eps_val, double init_inter_dual_eps_val,
//			double tau_incr_, bool reuse_multipliers, int max_iter, int primal_max_iter, bool weight_normalization,
//			AugLagFairnessType fairness_type, int inner_regular_valence, bool boundary_valence_check,
//			bool weighted_diff_, double max_penalty_ratio = 1e4, bool blend_fairness = false, double start_blend_value = 0, double end_blend_value = 1);

	if(use_reweighting){
		std::vector<double> l2_disp_weights;
		reweighted_L2_weights(init_disp, reweighted_tolerance_ratio, init_disp_weight, l2_disp_weights);

		std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
		OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
		deformedMeshNode->setSelected(false);
		deformedMeshNode->setName( "Planarized Mesh" );
		setMeshMaterial( deformedMeshNode );

		if(use_pq_mesh){
			PQL2DispOptimizer solver;
			solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, l2_disp_weights, smoothness_weight_,
					vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
					tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, quad_dist_on_boundary, fairness_type, inner_regular_valence,
					check_boundary_valence, weighted_diff, max_penalty_ratio);
			solver.L2_optimize(opt_disp);
		}
		else{
			PolygonalPlanarMeshL2Disp solver;
			solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, l2_disp_weights, smoothness_weight_,
					vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
					tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, quad_dist_on_boundary, fairness_type, inner_regular_valence,
					check_boundary_valence, weighted_diff, max_penalty_ratio);

			solver.L2_optimize(opt_disp);
		}
	}
	else{


		std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*original_mesh));
		OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
		deformedMeshNode->setSelected(false);
		deformedMeshNode->setName( "Planarized Mesh" );
		setMeshMaterial( deformedMeshNode );

		if(use_pq_mesh){
			PQInitDispL1DispOptimizer solver;
			solver.initialize_variables(deformedMeshNode, pmesh.get(), update_period_, nb_threads, fixed_vtx_disp, init_disp, nb_phases, sparsity_weight,
					init_disp_weight, smoothness_weight_,
					vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
					tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type,
					hex_mesh, inner_regular_valence,
					check_boundary_valence, weighted_diff, max_penalty_ratio);
			solver.L1_optimize(opt_disp);
		}
		else{
			PolygonalPlanarMeshInitDiapL1SparseDisp solver;
			//PolygonalPlanarMeshInitDiapL1SparseDispMC solver;
			solver.initialize_variables(deformedMeshNode, pmesh.get(), update_period_, nb_threads, fixed_vtx_disp, init_disp, nb_phases, sparsity_weight,
					init_disp_weight, smoothness_weight_,
					vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
					tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type,
					hex_mesh, inner_regular_valence,
					check_boundary_valence, weighted_diff, max_penalty_ratio);

			solver.L1_optimize(opt_disp);
		}

		for(unsigned int i = 0; i < opt_disp.size(); i++){
			opt_disp[i] -= init_disp[i];
		}
	}

	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}



void ConstrainedMeshPlugin::output_obj_file()
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();
    QString fileName = QFileDialog::getSaveFileName(0, tr("Choose obj file to save mesh"), QString(), tr("Wavefront OBJ File (*.obj)"));
    if(!fileName.isNull()){
    	export_obj_file(fileName.toAscii().data(), pmesh.get());
    }
}



void ConstrainedMeshPlugin::interactive_L1_sparse_disp_auglag_polygonal_planar_mesh(int update_period_, double sparsity_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type,
		bool hex_mesh,
		int inner_regular_valence,  bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
		bool reuse_multipliers, double tau_incr_, double max_penalty_ratio)
{
    if(!this->interactive_orignal_mesh){
    	dolphinErr() << "No original mesh" << std::endl;
        return;
    }


    if(!is_valid_displacement(interactive_orignal_mesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    //meshNode->setVisible(false);
    this->interactive_orig_meshnode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*interactive_orignal_mesh));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	//deformedMeshNode->setVisible(false);
	if(getScenegraph().getChildIndex(interactive_disp_edgeset_node)>=0){
		this->interactive_disp_edgeset_node->setVisible(false);
	}
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );
	std::vector<MeshPointType> opt_disp;

	if(use_pq_mesh){
		PQL1SparseDispOptimizer solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type, hex_mesh, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);
		solver.L1_optimize(opt_disp);
	}
	else{
		PolygonalPlanarMeshL1SparseDisp solver;
		//PolygonalPlanarMeshL1SparseDispMC solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type, hex_mesh, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);

		solver.L1_optimize(opt_disp);
	}

	this->interactive_orig_meshnode->setVisible(false);
	deformedMeshNode->setVisible(true);
	//deformedMeshNode->setVisible(true);

	//show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}



void ConstrainedMeshPlugin::normal_L1_sparse_disp_auglag_polygonal_planar_mesh(int update_period_, double sparsity_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type,
		bool hex_mesh,
		int inner_regular_valence,  bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
		bool reuse_multipliers, double tau_incr_, double max_penalty_ratio)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();


    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	//deformedMeshNode->setVisible(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );
	std::vector<MeshPointType> opt_disp;

	if(use_pq_mesh){
		PQL1SparseDispOptimizer solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type, hex_mesh, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);
		solver.L1_optimize(opt_disp);
	}
	else{
		PolygonalPlanarMeshL1SparseDisp solver;
		//PolygonalPlanarMeshL1SparseDispMC solver;
		solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps, inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
				tau_incr_, reuse_multipliers, max_iter, primal_max_iter, weight_normalization, fairness_type, hex_mesh, inner_regular_valence,
				check_boundary_valence, weighted_diff, max_penalty_ratio);

		solver.L1_optimize(opt_disp);
	}

	//deformedMeshNode->setVisible(true);
	//meshNode->setVisible(false);
	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}



void ConstrainedMeshPlugin::L1_sparse_disp_auglag_polygonal_planar_mesh(int update_period_, double sparsity_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases,
		double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool weight_normalization, AugLagFairnessType fairness_type,
		bool hex_mesh,
		int inner_regular_valence,  bool check_boundary_valence, bool weighted_diff, bool use_pq_mesh,
		bool reuse_multipliers, double tau_incr_, double max_penalty_ratio)
{
	if(interactive_mode){
		interactive_L1_sparse_disp_auglag_polygonal_planar_mesh(update_period_, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, nb_phases, primal_eps, dual_eps, init_dual_eps,
				inter_primal_eps, inter_dual_eps, init_inter_dual_eps, max_iter, primal_max_iter, nb_threads, weight_normalization, fairness_type,
				hex_mesh, inner_regular_valence, check_boundary_valence, weighted_diff, use_pq_mesh, reuse_multipliers, tau_incr_, max_penalty_ratio);
	}
	else{
		normal_L1_sparse_disp_auglag_polygonal_planar_mesh(update_period_, sparsity_weight, smoothness_weight_,
				vtx_disp_weight, init_penalty_weight_, nb_phases, primal_eps, dual_eps, init_dual_eps,
				inter_primal_eps, inter_dual_eps, init_inter_dual_eps, max_iter, primal_max_iter, nb_threads, weight_normalization, fairness_type,
				hex_mesh, inner_regular_valence, check_boundary_valence, weighted_diff, use_pq_mesh, reuse_multipliers, tau_incr_, max_penalty_ratio);
	}
}



void ConstrainedMeshPlugin::L1_sparse_disp_auglag_PQ(int update_period_, double sparsity_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, int nb_phases, double primal_eps, double dual_eps, double init_dual_eps,
		double inter_primal_eps, double inter_dual_eps, double init_inter_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool diffvec_planarity, bool use_2nddiff,
		bool reuse_multipliers, double tau_incr_, bool threshold_smoothness)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();


    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	//PQSparseDispAugLag solver;
	SparseDispAugLag_PQ_Eigen solver;
	//double avg_edge_length = average_edge_length(deformed_pmesh.get());
	solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, fixed_vtx_disp, nb_phases, sparsity_weight,
			smoothness_weight_, vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps,
			inter_primal_eps, inter_dual_eps, init_inter_dual_eps,
			tau_incr_, use_2nddiff, threshold_smoothness, diffvec_planarity,
			reuse_multipliers, max_iter, primal_max_iter);
	std::vector<MeshPointType> opt_disp;
	solver.L1_optimize(opt_disp);
	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");

}



void ConstrainedMeshPlugin::PQ_planarization_auglag(int update_period_, double individual_vtx_weight, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_, double primal_eps, double dual_eps, double init_dual_eps,
		int max_iter, int primal_max_iter, int nb_threads, bool diffvec_planarity, bool use_2nddiff,
		double tau_incr_, bool threshold_smoothness)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	//PQSparseDispAugLag solver;
	Planarization_PQ_Eigen solver;
	//double avg_edge_length = average_edge_length(deformed_pmesh.get());
	solver.initialize_variables(deformedMeshNode, update_period_, nb_threads, individual_vtx_weight,
			smoothness_weight_, vtx_disp_weight, init_penalty_weight_, primal_eps, dual_eps, init_dual_eps,
			tau_incr_, use_2nddiff, threshold_smoothness, diffvec_planarity, max_iter, primal_max_iter);
	std::vector<MeshPointType> opt_disp;
	solver.L1_optimize(opt_disp);
	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}



void ConstrainedMeshPlugin::L1_PQMesh_sparse_disp_softconstraint_auglag(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

//    if(!is_valid_tangent_basis(pmesh.get())){
//    	return;
//    }

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
//	Eigen::SparseMatrix<double> Nb;
//	get_PQMesh_normal_space_basis(deformed_pmesh.get(), Nb);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	//PQSparseDispAugLag solver;
	PQSparseDispSoftConstraintAugLag solver;
	double sparsity_weight = rel_sparsity_weight_;
	double avg_edge_length = average_edge_length(deformed_pmesh.get());

	int primal_max_iter = 50;
	solver.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, vtx_disp_weight, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness, avg_edge_length * 1e-2, 10000, primal_max_iter);
	std::vector<MeshPointType> opt_disp;
	solver.L1_optimize(opt_disp);


	show_displacements(meshNode, &getScenegraph(), opt_disp, "Final Disp");
}


bool ConstrainedMeshPlugin::is_valid_tangent_basis(PolyMeshType *pmesh)
{
	if(tangent_basis.empty()){
		dolphinErr() << "No tangent basis for this mesh" << std::endl;
		return false;
	}

	if(pmesh->n_vertices() * 3 != tangent_basis.front().size()){
		dolphinErr() << "Invalid tangent basis for this mesh" << std::endl;
		return false;
	}

	return true;
}

void ConstrainedMeshPlugin::L0_optimize_PQMesh_Disp_softconstraint(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double vtx_disp_weight, double init_penalty_weight_,
		double ep_abs_, double ep_rel_, double tau_incr_, bool threshold_smoothness, bool soft_constraint_disp)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispSoftCon admm;
	double sparsity_weight = rel_sparsity_weight_;
	admm.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, threshold_smoothness,
			vtx_disp_weight, soft_constraint_disp);
	std::vector<MeshPointType> opt_disp;

	DrawModes* modes = deformedMeshNode->getDrawModes();
	modes->setMode(DrawModes::FACE_DRAWING,true);
    modes->setMode(DrawModes::FACE_COLOR_FLAT,true);
    modes->resetMode(DrawModes::FACE_SHADING_FLAT,true);
	HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	double avg_edge_length = average_edge_length(deformed_pmesh.get());
	histogram->getColorMap()->setBoundaries(0.0, 4 * ( avg_edge_length * avg_edge_length * 0.0001 ));
	mesh_histogram = std::tr1::shared_ptr<MeshHistogram>( new MeshHistogram(histogram,deformedMeshNode, std::vector<double>(deformed_pmesh->n_faces(), 0.0), utilities::FACE) );
	mesh_histogram->showOnMesh(false);
	admm.set_histogram(mesh_histogram.get());
	admm.L0_optimize(opt_disp);
}


void ConstrainedMeshPlugin::L1_optimize_PQMesh_Disp_2nddiff(int update_period_, double rel_sparsity_weight_, double smoothness_weight_,
		double init_penalty_weight_, double ep_abs_, double ep_rel_, double tau_incr_, bool use_mat_var_)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	setMeshMaterial( deformedMeshNode );

	PQSparseDispADMM2ndDiffEnergy admm;
	double sparsity_weight = l1_sparsity_weight(rel_sparsity_weight_);
	admm.initialize_variables(deformedMeshNode, update_period_, fixed_vtx_disp, sparsity_weight,
			smoothness_weight_, init_penalty_weight_, ep_abs_, ep_rel_, tau_incr_, use_mat_var_);
	std::vector<MeshPointType> opt_disp;

	DrawModes* modes = deformedMeshNode->getDrawModes();
	modes->setMode(DrawModes::FACE_DRAWING,true);
    modes->setMode(DrawModes::FACE_COLOR_FLAT,true);
    modes->resetMode(DrawModes::FACE_SHADING_FLAT,true);
	HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	histogram->getColorMap()->setBoundaries(0.0, 0.01);
	mesh_histogram = std::tr1::shared_ptr<MeshHistogram>( new MeshHistogram(histogram,deformedMeshNode, admm.face_diagonal_dist_measure(), utilities::FACE));
	mesh_histogram->showOnMesh(false);
	admm.set_histogram(mesh_histogram.get());
	admm.L1_optimize(opt_disp);
}


void ConstrainedMeshPlugin::l1_optimize_PQMesh_Disp_penalty(int update_period, double rel_sparsity_weight, double smoothness_weight, double init_penalty_weight,
		double penalty_incr_ratio, bool)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	//setMeshMaterial( deformedMeshNode );

	PQSparseDispSDMM sdmm;
	double sparsity_weight = l1_sparsity_weight(rel_sparsity_weight);
	sdmm.initialize_penalty_method_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight,
			init_penalty_weight, penalty_incr_ratio);
	std::vector<MeshPointType> opt_disp;

	DrawModes* modes = deformedMeshNode->getDrawModes();
	modes->setMode(DrawModes::FACE_DRAWING,true);
    modes->setMode(DrawModes::FACE_COLOR_FLAT,true);
    modes->resetMode(DrawModes::FACE_SHADING_FLAT,true);
	HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	histogram->getColorMap()->setBoundaries(0.0, 0.01);
	mesh_histogram = std::tr1::shared_ptr<MeshHistogram>( new MeshHistogram(histogram,deformedMeshNode, sdmm.face_diagonal_dist_measure(), utilities::FACE));
	mesh_histogram->showOnMesh(false);
	sdmm.set_histogram(mesh_histogram.get());

	sdmm.L1_penalty_optimize(opt_disp);
}


void ConstrainedMeshPlugin::l1_optimize_PQMesh_Disp_SDMM(int update_period, double rel_sparsity_weight, double smoothness_weight,
		double init_penalty_weight, double stop_ep_abs, double stop_ep_rel, double lambda, double tau_incr, double tau_decr,
		bool use_mat_var)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(!is_valid_displacement(pmesh.get())){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(!is_quad_mesh(pmesh.get())){
    	dolphinErr() << "Not a quad mesh" << std::endl;
    	return;
    }

	meshNode->setVisible(false);

	//copy to original mesh:
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*meshNode->getMesh()));
	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName( "Deformed Mesh" );
	//setMeshMaterial( deformedMeshNode );

	PQSparseDispSDMM sdmm;
	double sparsity_weight = l1_sparsity_weight(rel_sparsity_weight);
	sdmm.initialize_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight, init_penalty_weight, stop_ep_abs,
			stop_ep_rel, lambda, tau_incr, tau_decr, use_mat_var);
	//double Z_weight = 1;
	//double Y_weight = 1;
	//double W_weight = 1;
	//double min_change_bound = get_min_vec_change(deformedMeshNode->getMesh().get());
	//sdmm.initialize_variables(deformedMeshNode, update_period, fixed_vtx_disp, sparsity_weight, smoothness_weight, init_penalty_weight,
	//		Z_weight, Y_weight, W_weight, min_change_bound, lambda, tau_incr, tau_decr, use_mat_var);
	std::vector<MeshPointType> opt_disp;

	DrawModes* modes = deformedMeshNode->getDrawModes();
	modes->setMode(DrawModes::FACE_DRAWING,true);
    modes->setMode(DrawModes::FACE_COLOR_FLAT,true);
    modes->resetMode(DrawModes::FACE_SHADING_FLAT,true);
	HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	histogram->getColorMap()->setBoundaries(0.0, 0.01);
	mesh_histogram = std::tr1::shared_ptr<MeshHistogram>( new MeshHistogram(histogram,deformedMeshNode, sdmm.face_diagonal_dist_measure(), utilities::FACE));
	mesh_histogram->showOnMesh(false);
	sdmm.set_histogram(mesh_histogram.get());

	sdmm.L1_optimize(opt_disp);
	//sdmm.weighted_L1_optimize(opt_disp);
}

void ConstrainedMeshPlugin::setMeshMaterial( OpenMeshNode *n )
{
	n->getDefaultMaterial()->setFaceColor(255./255.,255./255.,255./255.,1.);
	//n->getDefaultMaterial()->setEdgeWidth(4.);
	n->getDefaultMaterial()->setShininess(20.);
	n->getDefaultMaterial()->setSpecularity(0.);
	n->getDrawModes()->setMode(DrawModes::EDGE_DRAWING);
}


void ConstrainedMeshPlugin::read_vertex_displacement()
{
	QString fileName = QFileDialog::getOpenFileName(0, tr("Choose file to load displacement vectors"),
			QString(), tr("Displacement Vector Array (*.dva)"));

	if(!fileName.isNull()){
		std::map<int, MeshPointType> temp_vtx_disp;
		if(read_vertex_displacement_constraints(fileName.toAscii().data(), temp_vtx_disp)){
			fixed_vtx_disp = temp_vtx_disp;
			dolphinOut() << "Read " << fixed_vtx_disp.size() << " displacement vectors" << std::endl;

			OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
		    if(meshNode){
		    	PolyMeshType *orig_mesh = meshNode->getMesh().get();
		    	bool valid = true;
		    	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
		    		if(iter->first >= static_cast<int>(orig_mesh->n_vertices())){
		    			valid = false;
		    			break;
		    		}
		    	}

		    	if(valid){
			    	std::tr1::shared_ptr<EdgeSet> dEdgeSet(new EdgeSet());
			    	EdgeSetNode* dEdgeSetNode = new EdgeSetNode(&getScenegraph(), dEdgeSet);
			    	dEdgeSetNode->setName("Input Displacement");

			    	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
			    		int idx = iter->first;
			    		MeshPointType orig_pt = orig_mesh->point(PolyMeshType::VertexHandle(idx));
			    		dEdgeSet->addEdge(orig_pt, orig_pt + iter->second);
			    	}

			    	dEdgeSetNode->setGeometryChanged();
		    	}
		    }
		}
		else{
			dolphinErr() << "Failed to read displacement vectors" << std::endl;
		}
	}
}

double ConstrainedMeshPlugin::get_min_vec_change(PolyMeshType *pmesh)
{
	return 1e-3 * average_edge_length(pmesh);
}

double ConstrainedMeshPlugin::l0_sparsity_weight(double rel_weight)
{
	if(fixed_vtx_disp.empty()){
		return 0;
	}

	// Compute average squared norm of the displacements
	double avg_sqr_norm = 0;
	for(std::map<int, MeshPointType>::const_iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
		avg_sqr_norm += iter->second.sqrnorm();
	}
	avg_sqr_norm /= fixed_vtx_disp.size();

	return avg_sqr_norm * rel_weight * rel_weight;
}

double ConstrainedMeshPlugin::l1_sparsity_weight(double rel_weight)
{
	if(fixed_vtx_disp.empty()){
		return 0;
	}

	// Compute average squared norm of the displacements
	double avg_norm = 0;
	for(std::map<int, MeshPointType>::const_iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
		avg_norm += iter->second.norm();
	}
	avg_norm /= fixed_vtx_disp.size();

	return avg_norm * rel_weight * rel_weight;
}
*/

void ConstrainedMeshPlugin::onUnload() {
	removeAllActions();
}


void ConstrainedMeshPlugin::onNodeUpdate(Node*, shared_ptr<NodeUpdate>  ){
	//udpate_ADMM_optimization();
	//this->update_handle_positions();
	//this->update_interactive_disp_edgeset();
}

/*
bool ConstrainedMeshPlugin::is_valid_displacement(PolyMeshType *pmesh)
{
	if(fixed_vtx_disp.empty()){
		return false;
	}

	int n_vtx = pmesh->n_vertices();
	for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
		if(iter->first < 0 || iter->first >= n_vtx){
			return false;
		}
	}

	return true;
}

bool ConstrainedMeshPlugin::is_quad_mesh(PolyMeshType *pmesh)
{
	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		if(pmesh->valence(f_it.handle()) != 4){
			return false;
		}
	}

	return true;
}

void ConstrainedMeshPlugin::load_tangent_basis()
{
	QString fileName = QFileDialog::getOpenFileName(0, tr("Choose file to basis vectors"),
			QString(), tr("Eigen Info File (*.ei)"));

	if(!fileName.isNull()){
		std::vector< std::vector<double> > basis_vecs;
		if(load_eigen_info(fileName.toAscii().data(), basis_vecs)){
			std::cout << "Loaded " << static_cast<int>(basis_vecs.size()) << " vectors of length" << static_cast<int>(basis_vecs.front().size()) << std::endl;
			tangent_basis = basis_vecs;
		}
	}
}


void ConstrainedMeshPlugin::update_interactive_disp_edgeset()
{
	if(interactive_disp_edgeset_node && getScenegraph().getChildIndex(interactive_disp_edgeset_node) >=0){
		std::tr1::shared_ptr<EdgeSet> dEdgeSet = interactive_disp_edgeset_node->getEdgeSet();
		std::tr1::shared_ptr<PointCloud> pc = handles->getPointCloud();
		//int n = pc->nPoints();

		int i = 0;
		for(EdgeSet::EdgeIterator e_it = dEdgeSet->edgesBegin(); e_it != dEdgeSet->edgesEnd(); ++ e_it){
			PointCloud::Point pt = pc->getVertexPosition(i);
			Halfedge heh = dEdgeSet->halfedge(*e_it, 0);
			//dEdgeSet->point(dEdgeSet->from_vertex(heh)) = handle_orig_pos[i];
			dEdgeSet->setVertexPosition(dEdgeSet->from_vertex(heh).idx(), handle_orig_pos[i]);
			//dEdgeSet->point(dEdgeSet->to_vertex(heh)) = pt;
			dEdgeSet->setVertexPosition(dEdgeSet->to_vertex(heh).idx(), pt);
			i++;
		}

		interactive_disp_edgeset_node->setGeometryChanged();
	}
}


void ConstrainedMeshPlugin::update_handle_positions()
{
	std::map< int, MeshPointType > cur_fixed_vtx_disp;
	std::tr1::shared_ptr<PointCloud> pc = handles->getPointCloud();
	int n = pc->nPoints();
	for(int i = 0; i < n; i++){
		PointCloud::Point pt = pc->getVertexPosition(i);
		cur_fixed_vtx_disp[ static_cast<int>(handleIndices[i]) ] = MeshPointType(pt[0], pt[1], pt[2]) - handle_orig_pos[i];
	}

	this->fixed_vtx_disp = cur_fixed_vtx_disp;
}

void ConstrainedMeshPlugin::udpate_ADMM_optimization()
{
	if(interactive_mode){
		std::map< int, MeshPointType > fixed_vtx_disp;
		std::tr1::shared_ptr<PointCloud> pc = handles->getPointCloud();
		int n = pc->nPoints();
		for(int i = 0; i < n; i++){
			PointCloud::Point pt = pc->getVertexPosition(i);

			fixed_vtx_disp[ static_cast<int>(handleIndices[i]) ] = MeshPointType(pt[0], pt[1], pt[2]) - handle_orig_pos[i];
		}

		std::vector< MeshPointType > opt_disp;
		for(std::map<int, MeshPointType>::iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
			std::cout << " Disp for vertex " << iter->first << ": (" << iter->second[0] << "," << iter->second[1] << "," << iter->second[2] << ")" << std::endl;
		}
		admm_solver.threaded_L1_optimize(fixed_vtx_disp, opt_disp);
	}
}


void ConstrainedMeshPlugin::exit_interactive_mode()
{
	this->interactive_mode = false;
//	if(interactive_disp_edgeset_node && getScenegraph().getChildIndex(interactive_disp_edgeset_node) >=0){
//		getScenegraph()
//	}

	interactive_disp_edgeset_node = NULL;
}

void ConstrainedMeshPlugin::enter_interactive_mode()
{
	OpenMeshNode *cMeshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
	if(!cMeshNode){
		dolphinOut() << "ConstrainedMeshPlugin > No mesh selected." << std::endl;
		return;
	}
	std::tr1::shared_ptr<OMesh> mesh = cMeshNode->getMesh();

	if(!handleIndices.empty()){

		//cMeshNode->getDrawModes()->resetMode(DrawModes::VERTEX_DRAWING );
		cMeshNode->setSelected(false);
		setMeshMaterial( cMeshNode );
		//this->interactive_orig_meshnode = cMeshNode;
		//this->interactive_orignal_mesh = cMeshNode->getMesh();
		//cMeshNode->setVisible(false);

		//Setup deformed mesh
		//std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*cMeshNode->getMesh()));
		interactive_orignal_mesh = mesh;	// Keep track of the original mesh
		interactive_orig_meshnode = cMeshNode;
		//OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
		//deformedMeshNode->setSelected(false);
		//deformedMeshNode->setName( "Deformed Mesh" );
		//setMeshMaterial( deformedMeshNode );


		//deselect existing clouds and remove observation:
		QList<PointCloudNode*> clouds;
		getScenegraph().getDescendants<PointCloudNode*>(clouds);
		for( QList<PointCloudNode*>::iterator it=clouds.begin();it!=clouds.end();++it){
			(*it)->removeObserver(this);
			(*it)->setSelected(false);
		}

		//add the pointcloudnode
		std::tr1::shared_ptr<PointCloud> pointCloud( new PointCloud());
		PointCloudNode *pointCloudNode = new PointCloudNode(&getScenegraph(), pointCloud);
		pointCloudNode->setName("ConstrainedMesh Vertex Handles");
		pointCloudNode->setSelected(true);
		handles=pointCloudNode;
		handle_orig_pos.clear();
		//HandlesConstraint c;

		for(std::vector<unsigned int>::iterator it=handleIndices.begin();it!=handleIndices.end();++it){
			//c.addIndex(*it);
			PointCloud::Point cur_pt = mesh->point(OMesh::VertexHandle(*it));
			pointCloud->add_vertex(cur_pt);
			handle_orig_pos.push_back(MeshPointType(cur_pt[0], cur_pt[1], cur_pt[2]));
		}

		std::tr1::shared_ptr<EdgeSet> dEdgeSet(new EdgeSet());
		interactive_disp_edgeset_node = new EdgeSetNode(&getScenegraph(), dEdgeSet);
		interactive_disp_edgeset_node->setName("Input Disp");
		for(unsigned int i = 0; i < handle_orig_pos.size(); i++){
			dEdgeSet->addEdge(handle_orig_pos[i], handle_orig_pos[i]);//, EdgeSet::Color(0.,0.,1.,1.));
		}
		interactive_disp_edgeset_node->getDefaultMaterial()->setEdgeWidth(3);
		interactive_disp_edgeset_node->getDefaultMaterial()->setEdgeColor(0.66, 0.33, 1., 1.);
		interactive_disp_edgeset_node->setGeometryChanged();



		//c.setHandles(pointCloud);

//		std::vector<int> constrained_vtx_idx;
//		for(unsigned int i = 0; i < handleIndices.size(); i++){
//			constrained_vtx_idx.push_back(handleIndices[i]);
//		}
//
//		admm_solver.initialize_variables(deformedMeshNode, update_period_, constrained_vtx_idx,
//				sparsity_weight_, smoothness_weight_, vtx_disp_weight_, init_penalty_weight_,
//				ep_abs_, ep_rel_, tau_incr_, max_iteration, true);

		//set material:
		pointCloudNode->getDefaultMaterial()->setVertexRadius(15.0f);
		pointCloudNode->getDefaultMaterial()->setPointColor(0./255.,141./255.,184./255.,1.);

		pointCloudNode->setGeometryChanged();
		pointCloudNode->addObserver(this);
		interactive_mode = true;
	}
}

void ConstrainedMeshPlugin::setVertexIndices( std::vector<unsigned int>& v )
{
	OpenMeshNode *mNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
	if(!mNode){ dolphinOut() << "ConstrainedMeshPlugin: No mesh selected." <<std::endl; return;}
	std::tr1::shared_ptr<OMesh> mesh = mNode->getMesh();

	v.clear();
	for(OMesh::ConstVertexIter vI=mesh->vertices_begin();vI!=mesh->vertices_end();++vI){
		if(mesh->status(vI).selected()){
			v.push_back(vI.handle().idx());
		}
	}
}


void ConstrainedMeshPlugin::get_PQMesh_normal_space_basis(PolyMeshType *pmesh, Eigen::SparseMatrix<double> &Nb)
{
	Nb.resize(pmesh->n_faces(), 3 * pmesh->n_vertices());
	typedef Eigen::Triplet<double> T;
	std::vector<T> triplets_Nb;

	PolyMeshType::FaceIter f_it, f_end = pmesh->faces_end();
	PolyMeshType::FaceVertexIter fv_it;
	int row_n = 0;
	for(f_it = pmesh->faces_begin(); f_it != f_end; ++ f_it){
		std::vector<MeshPointType> pts;
		std::vector<int> idx;
		for(fv_it = pmesh->fv_iter(f_it); fv_it; ++ fv_it){
			pts.push_back(pmesh->point(fv_it.handle()));
			idx.push_back(fv_it.handle().idx());
		}

		MeshPointType N = Dolphin::defines::cross(pts[2] - pts[0], pts[3] - pts[1]).normalize();
		double factor[] = {0.5, -0.5, 0.5, -0.5};
		for(int i = 0; i < 4; i++){
			for(int k = 0; k < 3; k++){
				triplets_Nb.push_back(T(row_n, 3 * idx[i] + k, N[k] * factor[i]));
			}
		}

		row_n ++;
	}

	Nb.setFromTriplets(triplets_Nb.begin(), triplets_Nb.end());
}

void ConstrainedMeshPlugin::setHandleIndices(){
	setVertexIndices(handleIndices);
}

void ConstrainedMeshPlugin::show_displacements(OpenMeshNode *orig_mesh_node, scenegraph::Node *parent,
		const std::vector<MeshPointType> &disp, const char *name)
{
	PolyMeshType *orig_mesh = orig_mesh_node->getMesh().get();

	std::tr1::shared_ptr<EdgeSet> dEdgeSet(new EdgeSet());
	EdgeSetNode* dEdgeSetNode = new EdgeSetNode(parent, dEdgeSet);
	dEdgeSetNode->setName(name);

	PolyMeshType::VertexIter v_it, v_end = orig_mesh->vertices_end();
	for(v_it = orig_mesh->vertices_begin(); v_it != v_end; ++ v_it){
	  MeshPointType orig_pt = orig_mesh->point(v_it);
	  int idx = v_it.handle().idx();
	  dEdgeSet->addEdge(orig_pt, orig_pt + disp[idx]);
	}

	dEdgeSetNode->setGeometryChanged();
}

OpenMeshNode* ConstrainedMeshPlugin::show_deformed_mesh(OpenMeshNode *orig_mesh, const std::vector< MeshPointType > &disp, const char *name)
{
	std::tr1::shared_ptr<OMesh> deformed_pmesh = std::tr1::shared_ptr<OMesh>( new OMesh(*orig_mesh->getMesh()));
	PolyMeshType *pmesh = deformed_pmesh.get();
	PolyMeshType::VertexIter v_it, v_end = pmesh->vertices_end();
	for(v_it = pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		pmesh->set_point(v_it, pmesh->point(v_it) + disp[v_it.handle().idx()]);
	}

	OpenMeshNode *deformedMeshNode = new OpenMeshNode(&getScenegraph(), deformed_pmesh);
	deformedMeshNode->setSelected(false);
	deformedMeshNode->setName(name);
	setMeshMaterial( deformedMeshNode );

	return deformedMeshNode;
}


void ConstrainedMeshPlugin::get_edgeset_vertices(EdgeSetNode* node, std::vector< std::pair<MeshPointType, MeshPointType> > &vtx_pairs)
{
	EdgeSet *edgeset = node->getEdgeSet().get();
	for(EdgeSet::EdgeIterator iter = edgeset->edgesBegin(); iter != edgeset->edgesEnd(); ++ iter){
		Halfedge h = edgeset->halfedge(*iter, 0);
		MeshPointType pt0 = edgeset->point(edgeset->from_vertex(h)), pt1 = edgeset->point(edgeset->to_vertex(h));
		vtx_pairs.push_back(std::make_pair(pt0, pt1 - pt0));
	}
}


void ConstrainedMeshPlugin::load_edgesets()
{
    QString fileName = QFileDialog::getOpenFileName(0, tr("Choose file to read displacement vectors"));
	if(!fileName.isNull()){
		std::vector< std::pair<MeshPointType, MeshPointType> > edgeset_vtx;
		if(!read_edgesets(fileName.toAscii().data(), edgeset_vtx)){
			dolphinErr() << "Error reading displacements" << std::endl;
			return;
		}

		std::tr1::shared_ptr<EdgeSet> dEdgeSet(new EdgeSet());
		EdgeSetNode* dEdgeSetNode = new EdgeSetNode(&getScenegraph(), dEdgeSet);
		dEdgeSetNode->setName("Displacements");
		for(unsigned int i = 0; i < edgeset_vtx.size(); i++){
		  dEdgeSet->addEdge(edgeset_vtx[i].first, edgeset_vtx[i].second);
		}

		dEdgeSetNode->setGeometryChanged();
	}
}


void ConstrainedMeshPlugin::output_edgesets()
{
	EdgeSetNode *edgeNode = getScenegraph().getFirstDescendant<EdgeSetNode*>(true);
    if(!edgeNode){
    	dolphinErr() << "No EdgeSet selected" << std::endl;
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(0, tr("Choose file to output displacement vectors"));
	if(!fileName.isNull()){
		std::vector< std::pair<MeshPointType, MeshPointType> > edgeset_vtx;
		get_edgeset_vertices(edgeNode, edgeset_vtx);
		write_edgeset_array(fileName.toAscii().data(), edgeset_vtx);
	}
}

void ConstrainedMeshPlugin::save_mesh_disp_length_color_info(bool compare_input_disp)
{
	EdgeSetNode *edgeNode = getScenegraph().getFirstDescendant<EdgeSetNode*>(true);
    if(!edgeNode){
    	dolphinErr() << "No Displacement selected" << std::endl;
        return;
    }

	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    std::tr1::shared_ptr<EdgeSet> edge_set = edgeNode->getEdgeSet();
    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();

    if(compare_input_disp && (!is_valid_displacement(pmesh.get()))){
    	dolphinErr() << "Invalid displacement for this mesh" << std::endl;
    	return;
    }

    if(edge_set->n_edges() != pmesh->n_vertices()){
    	std::cout << "Invalid displacement vectors" << std::endl;
    	return;
    }


    std::vector<double> disp_length;
    for(EdgeSet::EdgeIterator e_it = edge_set->edgesBegin(); e_it != edge_set->edgesEnd(); ++ e_it){
    	disp_length.push_back(edge_set->edge_length(*e_it));
    }

    // Normalize the lengths
    double max_length = 0;

    if(compare_input_disp){
    	for(std::map< int, MeshPointType >::iterator iter = fixed_vtx_disp.begin(); iter != fixed_vtx_disp.end(); ++ iter){
    		max_length = std::max(max_length, iter->second.norm());
    	}

    	max_length = std::max(1e-8, max_length);
    }
    else{
    	max_length = std::max(1e-8, *std::max_element(disp_length.begin(), disp_length.end()));
    }

    for(unsigned int i = 0; i < disp_length.size(); i++){
    	disp_length[i] /= max_length;
    	disp_length[i] = std::max(0.0, disp_length[i]);
    	disp_length[i] = std::min(1.0, disp_length[i]);
    }

    QString fileName = QFileDialog::getSaveFileName(0, tr("Choose file to output textured mesh"), QString(), tr("Wavefront OBJ File (*.obj)"));
	if(!fileName.isNull()){
		write_obj_with_vertex_texture(fileName.toAscii().data(), pmesh.get(), disp_length);
	}
}


void ConstrainedMeshPlugin::save_planarity_dist_color_info(bool diag_dist, bool use_local_dist, int level_num)
{
	OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
    	dolphinErr() << "No mesh selected" << std::endl;
        return;
    }

    PolyMeshType *pmesh = meshNode->getMesh().get();

    std::vector<double> global_rel_dist, local_rel_dist;

    if(diag_dist && is_quad_mesh(pmesh)){
    	compute_pqmesh_rel_diagdist(pmesh, global_rel_dist, local_rel_dist);
    }
    else{
    	compute_polygonal_mesh_rel_planaritydist(pmesh, global_rel_dist, local_rel_dist);
    }

    double bound_val = 0.01;
    for(unsigned int i = 0; i < global_rel_dist.size(); i++){
    	global_rel_dist[i] = std::min(1.0, global_rel_dist[i] / bound_val);
    }
    for(unsigned int i = 0; i < local_rel_dist.size(); i++){
    	local_rel_dist[i] = std::min(1.0, local_rel_dist[i] / bound_val);
    }

    QString fileName = QFileDialog::getSaveFileName(0, tr("Choose file to output face-colored mesh"), QString(), tr("Wavefront OBJ File (*.obj)"));
	if(!fileName.isNull()){
	    if(use_local_dist){
	    	write_obj_with_face_color(fileName.toAscii().data(), pmesh, local_rel_dist, level_num);
	    }
	    else{
	    	write_obj_with_face_color(fileName.toAscii().data(), pmesh, global_rel_dist, level_num);
	    }
	}
}

int ConstrainedMeshPlugin::save_colorbar_mtl_file()
{
	QString fileNameImage = QFileDialog::getOpenFileName(0, tr("Choose image file"));

	if(fileNameImage.isNull()){
		return -1;
	}

	QImage image;
	if((!image.load(fileNameImage)) || image.isNull()){
		return -1;
	}

	QString fileNameMTL = QFileDialog::getSaveFileName(0, tr("Choose mtl file to save face colors"), QString(), tr("Material File (*.mtl)"));
	if(fileNameMTL.isNull()){
		return -1;
	}

	return output_color_bar_mtl_file(image, fileNameMTL.toAscii().data());
}
*/

void ConstrainedMeshPlugin::bc_parameterization()
{
    int vUnknown = 0, vKnown = 0;
    for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
    {
        if (pmesh_->status(vIt).selected())
        {
            vKnown++;
        }
        else
        {
            vUnknown++;
        }
    }

    Eigen::MatrixXd matrix_A, matrix_b, matrix_x;
    matrix_A.setZero(vUnknown, vUnknown);
    matrix_b.setZero(vUnknown, 3);
    matrix_x.setZero(vUnknown, 3);

    int row_index = 0, col_index = 0;
    for(OMesh::VertexIter v_it = pmesh_->vertices_begin(); v_it != pmesh_->vertices_end(); ++v_it)
    {
        int vIdx = v_it.handle().idx();
        if (!(pmesh_->status(v_it).selected()))
        {
            col_index = 0;
            for (int i = 0; i < n_data_pt; ++i)
            {
                OMesh::VertexHandle vHandle = pmesh_->vertex_handle(i);
                Point p = pmesh_->point(vHandle);
                if (!(pmesh_->status(vHandle).selected()))
                {
                    matrix_A(row_index, col_index) = w(vIdx, i);
                    if (vIdx == i)
                        matrix_A(row_index, col_index) = -1.0;

                    for (int j = 0; j < 3; ++j)
                    {
                        matrix_x(row_index, j) = p[j];
                    }
                    col_index++;
                }
                else
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        matrix_b(row_index, j) -= w(vIdx, i)*p[j];
                    }
                }
            }
            row_index++;
        }
    }

    Eigen::ConjugateGradient<Eigen::MatrixXd> cg;
    cg.compute(matrix_A);
    matrix_x = cg.solveWithGuess(matrix_b, matrix_x);

    int vIdx = 0;
    for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
    {
        if (!(pmesh_->status(vIt).selected()))
        {
            pmesh_->point(vIt) = Point(matrix_x(vIdx, 0), matrix_x(vIdx, 1), matrix_x(vIdx, 2));
            vIdx++;
        }
    }

    meshNode_->setGeometryChanged();
}

void ConstrainedMeshPlugin::delaunay_Triangulation()
{
    double cageRelLength = 0.1;
    double modelRelLength = 1;
    vector<ManifoldVertex*> modelNodes;
    vector<ManifoldVertex*> cageNodes;
    vector<bool> modelSelected;
    vector<bool> cageSelected;

    std::tr1::shared_ptr<VertexGeometry> cageObject;
    EdgeSetNode *edgesetNode = getScenegraph().getFirstDescendant<EdgeSetNode*>(true);
    if (!edgesetNode)
    {
        dolphinErr() << "No object selected" << std::endl;

        SplineNode *splineNode = getScenegraph().getFirstDescendant<SplineNode*>(true);
        if (!splineNode)
        {
            return;
        }
        else
        {
            cageObject = splineNode->getGeometry();
        }
    }
    else
    {
        cageObject = edgesetNode->getGeometry();
    }
    for (size_t i = 0; i < cageObject->nPoints(); ++i)
    {
        Point2D p;
        ManifoldVertex *vm = new ManifoldVertex;
        p[0] = cageObject->getVertexPosition(i)[0];
        p[1] = cageObject->getVertexPosition(i)[1];
        vm->setCoords(p);
        cageNodes.push_back(vm);
        if (cageObject->isVertexSelected(i))
        {
            cageSelected.push_back(true);
        }
        else
        {
            cageSelected.push_back(false);
        }
    }

    OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if (!meshNode)
    {
        dolphinErr() << "No tri-mesh selected.\n";
        return;
    }
    std::tr1::shared_ptr<OMesh> mesh = meshNode->getMesh();
    meshNode->setSelected(false, false);

    //get its boundary
    OMesh::VertexHandle vHandle;
    OMesh::HalfedgeIter h_it, hend = mesh->halfedges_end();
    OMesh::HalfedgeHandle first_boundary_heh;
    for (h_it = mesh->halfedges_begin(); h_it != hend; ++ h_it)
    {
        if (mesh->is_boundary(h_it.handle()))
        {
            first_boundary_heh = h_it.handle();
            break;
        }
    }
    if (first_boundary_heh.is_valid())
    {
        Point2D p;
        ManifoldVertex *vm = new ManifoldVertex;
        vHandle = mesh->to_vertex_handle(first_boundary_heh);
        p[0] = mesh->point(vHandle)[0];
        p[1] = mesh->point(vHandle)[1];
        vm->setCoords(p);
        modelNodes.push_back(vm);
        if (mesh->status(vHandle).selected())
            modelSelected.push_back(true);
        else
            modelSelected.push_back(false);

        OMesh::HalfedgeHandle next_heh = mesh->next_halfedge_handle(first_boundary_heh);

        while (next_heh != first_boundary_heh)
        {
            Point2D p;
            ManifoldVertex *vm = new ManifoldVertex;
            vHandle = mesh->to_vertex_handle(next_heh);
            p[0] = mesh->point(vHandle)[0];
            p[1] = mesh->point(vHandle)[1];
            vm->setCoords(p);
            modelNodes.push_back(vm);
            if (mesh->status(vHandle).selected())
                modelSelected.push_back(true);
            else
                modelSelected.push_back(false);
            next_heh = mesh->next_halfedge_handle(next_heh);
        }
    }
    //end of getting its boundary

    //do triangulation operation
    int numCageNodes   = cageNodes.size();
    int numModelNodes  = modelNodes.size();

    cout << " #of Cage  Points      " << numCageNodes  << endl;
    cout << " #of Model Points      " << numModelNodes << endl;

    double len0 = getBoundaryLength(modelNodes);
    len0 /=  double(modelNodes.size());
    refinedBoundary(modelNodes, modelSelected, modelRelLength*len0, modelSegments);

    // Find the length of the cage ...
    double len1 = getBoundaryLength(cageNodes);
    len1 /= double(cageNodes.size());
    refinedBoundary(cageNodes, cageSelected, cageRelLength*len1, cageSegments);

    double sArea = BasicMeasuring::surfaceArea(mesh.get());
    std::string maxTArea = boost::lexical_cast<std::string>(sArea*0.002);
    delaunay_triangulation(cageSegments, modelSegments, maxTArea);

    string inFile = "/Users/Juyong/Mesh-CGL/src/Libraries/bin/data.1.off";
    string outFile = "/Users/Juyong/Works/SBC/Results/" + meshNode->objectName().toStdString() + "-Delaunary-Mesh.off";
    std::tr1::shared_ptr<OMesh> delaunaryMesh(new OMesh());
    OpenMesh::IO::read_mesh(*delaunaryMesh, inFile.c_str());
    OpenMesh::IO::write_mesh(*delaunaryMesh, outFile.c_str());
    delaunaryMesh->update_normals();

    OpenMeshNode* openMeshNodeSurface = new OpenMeshNode(&getScenegraph(), delaunaryMesh);
    openMeshNodeSurface->setName(meshNode->objectName() + "-Delaunary-Mesh");
    openMeshNodeSurface->setSelected(true, false);

    //update scenegraph
    resetExaminerToBoundingSphere();
    openMeshNodeSurface->nodeUpdated();

    set_SelectObject_as_Cage();
    set_SelectObject_as_Data();
}

void ConstrainedMeshPlugin::computeBBW(int num_threads,
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
                                       int dimension,
                                       int laplaceType)
{
    linearPrecision_ = false;

    initialization();
    initialize_fairness_energy_matrix(laplaceType);
    initialize_P_and_C(dimension);

    if (boundedBiharmonicW.rows() == 0)
        boundedBiharmonicW.setZero(n_data_pt, n_boundary_pt);

    //begin
    std::vector<int> aData, lData;
    std::vector<bool> identical(n_data_pt, false);
    for (int i = 0; i < n_boundary_pt; ++i)
    {
        int nSub = cageSegments[i].size();
        assert(nSub >= 2);
        double dt = 1.0/(nSub - 1.0);
        for (int j = 0; j < nSub - 1; ++j)
        {
            Eigen::VectorXd coor(2);
            coor(0) = (cageSegments[i][j]->getCoords())[0];
            coor(1) = (cageSegments[i][j]->getCoords())[1];

            double d_min = std::numeric_limits<int>::max();
            int index_min = -1;
            for (int k = 0; k < n_data_pt; ++k)
            {
                double d = (coor - P_mat.col(k)).norm();
                if (d < d_min)
                {
                    d_min = d;
                    index_min = k;
                }
            }
            aData.push_back(index_min);
            identical[index_min] = true;
            boundedBiharmonicW.row(index_min).setZero();
            boundedBiharmonicW(index_min, i) = 1.0 - dt*j;
            boundedBiharmonicW(index_min, (i + 1)%n_boundary_pt) = dt*j;
        }
    }

    for (int i = 0; i < n_data_pt; ++i)
    {
        if (!identical[i])
        {
            lData.push_back(i);
        }
    }

    SparseMatrixXd l1_temp(n_data_pt, aData.size());
    SparseMatrixXd l1(lData.size(), aData.size());
    Eigen::MatrixXd wd(aData.size(), n_boundary_pt);
    for (size_t i = 0; i < aData.size(); ++i)
    {
        l1_temp.col(i) = matrix_L.col(aData[i]);
        wd.row(i) = boundedBiharmonicW.row(aData[i]);
    }
    SparseMatrixXd l1_temp_t = l1_temp.transpose();
    SparseMatrixXd l1_t(aData.size(), lData.size());
    std::vector<bool> has_fixed_neighbor(lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        l1_t.col(i) = l1_temp_t.col(lData[i]);
        has_fixed_neighbor[i] = (l1_t.col(i).nonZeros() > 0)?true:false;
    }
    l1 = l1_t.transpose();
    Eigen::MatrixXd a_ = l1*wd;

    SparseMatrixXd L_temp(n_data_pt, lData.size());
    SparseMatrixXd L_(lData.size(), lData.size());
    Eigen::MatrixXd data_points_(dimension, lData.size());
    Eigen::MatrixXd wud(lData.size(), n_boundary_pt);
    for (size_t i = 0; i < lData.size(); ++i)
    {
        wud.row(i) = boundedBiharmonicW.row(lData[i]);
        L_temp.col(i) = matrix_L.col(lData[i]);
        data_points_.col(i) = P_mat.col(lData[i]);
    }
    SparseMatrixXd L_temp_t = L_temp.transpose();
    SparseMatrixXd L_t(lData.size(), lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        L_t.col(i) = L_temp_t.col(lData[i]);
    }
    L_ = L_t.transpose();
    //end

    ReWeightedL2 reWeighted_solver;
    Eigen::MatrixXd D_(lData.size(), n_boundary_pt);
    reWeighted_solver.assign_other_coordinate(wud);

    std::cout<<"initial w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
    std::cout<<"initial ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;

    if (laplaceType != 0)
    {
        //solve wud by linear system
        Eigen::SimplicialLDLT<SparseMatrixXd> solver;
        solver.compute(L_);
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            wud.col(i) = solver.solve(-a_.col(i));
        }
        //end of linear system
    }
    else
    {
        reWeighted_solver.init_variables(num_threads,
                                         laplacian_bound_min_ratio,
                                         init_penalty_weight_,
                                         max_penalty_weight,
                                         primal_eps_val_*0.1,
                                         dual_eps_val_*0.1,
                                         init_dual_eps_*0.1,
                                         initval_primal_eps_*0.1,
                                         initval_dual_eps_*0.1,
                                         tau_incr_,
                                         0,
                                         0,
                                         max_iter,
                                         primal_max_iter,
                                         dimension,
                                         L_,
                                         a_,
                                         D_,
                                         C_mat,
                                         data_points_,
                                         has_fixed_neighbor,
                                         true,
                                         false,
                                         false,
                                         true);

        reWeighted_solver.solve_smooth();
        wud = reWeighted_solver.get_w();
    }

    for (size_t i = 0; i < lData.size(); ++i)
    {
        boundedBiharmonicW.row(lData[i]) = wud.row(i);
    }

    std::cout<<"data w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
    std::cout<<"||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;

    //assign barycentric coordinate to the original mesh
    QList<Node*> selected;
    getScenegraph().getDescendants(selected, false);
    std::tr1::shared_ptr<OMesh> originalMesh;
    OpenMeshNode *originalmeshNode;
    for(QList<Node*>::iterator it = selected.begin(); it != selected.end(); ++it)
    {
        if ((*it)->getType() == OPEN_MESH_NODE && (*it) != meshNode_)
        {
            (*it)->setSelected(true, false);
            originalmeshNode = qobject_cast<OpenMeshNode*>(*it);
            originalMesh = originalmeshNode->getMesh();
            break;
        }
    }
    Eigen::MatrixXd final_smooth_w(originalMesh->n_vertices(), n_boundary_pt);
    utilities::NearestTriangleSearch nts;
    nts.initializeKDTreeBasedSearchStructure(pmesh_.get(), 12, 30);
    std::vector<BarycentricCoordinates> v_bc(originalMesh->n_vertices());
    std::vector<OMesh::FaceHandle> v_fh(originalMesh->n_vertices());
    for (OMesh::VertexIter vIt = originalMesh->vertices_begin(); vIt != originalMesh->vertices_end(); ++vIt)
    {
        Point p = originalMesh->point(vIt.handle());
        OMesh::FaceHandle fh;
        nts.computeClosestTriangleOfPoint(p, pmesh_.get(), fh);
        Point projectedPoint;
        BarycentricCoordinates bc;
        BasicMeasuring::squaredDistancePointToTriangle(p, pmesh_.get(), fh, projectedPoint, bc);
        v_bc[vIt.handle().idx()] = bc;
        v_fh[vIt.handle().idx()] = fh;

        OMesh::ConstFaceVertexIter fvI = pmesh_->cfv_iter(fh);
        int v0 = fvI.handle().idx(); ++fvI;
        int v1 = fvI.handle().idx(); ++fvI;
        int v2 = fvI.handle().idx();
        final_smooth_w.row(vIt.handle().idx()) = bc.u_*boundedBiharmonicW.row(v0) + bc.v_*boundedBiharmonicW.row(v1) + bc.w_*boundedBiharmonicW.row(v2);
    }

    boundedBiharmonicW = final_smooth_w;
	string filename = "/Users/juyong/Works/SBC/Results/boundedBiharmonicW-mat-" + originalmeshNode->objectName().toStdString() + ".txt";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        outfile<<boundedBiharmonicW;
    }
    outfile.close();

    meshNode_->setVisible(false, false);
    meshNode_->setSelected(false, false);
    set_SelectObject_as_Data();
}

void ConstrainedMeshPlugin::computeMeanCoordinate(int dimension)
{
    initialization();

    meanw.resize(n_data_pt, n_boundary_pt);

    if (dimension == 2)
    {
        for (int k = 0; k < n_data_pt; ++k)
        {
            vector<OMesh::Point> s(n_boundary_pt);
            for( int i = 0; i < n_boundary_pt; ++i)
            {
                s[i] = point_data[vhs[i]] - point_data[datapt_idx_to_vtx_idx_map[k]];
            }

            int ip, im;      // (i+1) and (i-1)
            double ri, rp, Ai, Di;  // Distance

            // Page #12, from the paper
            vector<double> tanalpha(n_boundary_pt); // tan(alpha/2)
            for( int i = 0; i < n_boundary_pt; ++i)
            {
                ip = (i + 1)%n_boundary_pt;
                im = (n_boundary_pt + i - 1)%n_boundary_pt;
                ri = sqrt(s[i][0]*s[i][0] + s[i][1]*s[i][1]);
                rp = sqrt(s[ip][0]*s[ip][0] + s[ip][1]*s[ip][1]);
                Ai = 0.5*(s[i][0]*s[ip][1] - s[ip][0]*s[i][1]);
                Di = s[ip][0]*s[i][0] + s[ip][1]*s[i][1];
                tanalpha[i] = (ri*rp - Di)/(2.0*Ai);
            }

            // Equation #11, from the paper
            double wi, wsum = 0.0;
            for( int i = 0; i < n_boundary_pt; i++)
            {
                im = (n_boundary_pt + i - 1)%n_boundary_pt;
                ri = sqrt(s[i][0]*s[i][0] + s[i][1]*s[i][1]);
                wi = 2.0*(tanalpha[i] + tanalpha[im])/ri;
                wsum += wi;
                meanw(k, vtx_idx_to_control_pt_idx_map[vhs[i]]) = wi;
            }

            if(fabs(wsum) > 0.0)
            {
                for( int i = 0; i < n_boundary_pt; i++)
                    meanw(k, i) /= wsum;
            }
        }
    }

    if (dimension == 3)
    {
        MeanValueCooridnates mvc;

        for (int k = 0; k < n_data_pt; ++k)
        {
            Point dataPoint = point_data[datapt_idx_to_vtx_idx_map[k]];

            std::vector<double> mvCoordinate;
            mvCoordinate = mvc.weights(dataPoint, cageMesh_.get());

            for( int i = 0; i < n_boundary_pt; i++)
            {
                meanw(k, i) = mvCoordinate[i];
            }
        }
    }
	string filename = "/Users/juyong/Works/SBC/Results/" + meshNode_->objectName().toStdString() + "-mvc.txt";
    std::ofstream ofile(filename.c_str());
    if (!ofile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        ofile<<meanw;
    }

    std::ofstream outBoundary("/Users/juyong/Works/SBC/Results/meanboundary.txt");
    for (int i = 0; i < n_boundary_pt; ++i)
    {
        outBoundary<<controlpt_idx_to_vtx_idx_map[i]<<" ";
    }

    std::ofstream outData("/Users/juyong/Works/SBC/Results/meanvalue.txt");
    for (int i = 0; i < n_data_pt + n_boundary_pt; ++i)
    {
        int index = vtx_idx_to_datapt_idx_map[i];
        if (index >= 0)
        {
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                outData<<meanw(index, j)<<" ";
            }
            outData<<std::endl;
        }
        else
        {
            index = vtx_idx_to_control_pt_idx_map[i];
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                if (j == index)
                    outData<<"1 ";
                else
                    outData<<"0 ";
            }
            outData<<std::endl;
        }
    }
}

void ConstrainedMeshPlugin::computeGreenCoordinate(int dimension)
{
    dim = dimension;

    initialization();

    old_control_edge_length = control_edge_length;

    greenw.resize(n_data_pt, 2*n_boundary_pt);

    if (dimension == 2)
    {
        for (int k = 0; k < n_data_pt; ++k)
        {
            OMesh::Vector3 queryCoord = point_data[datapt_idx_to_vtx_idx_map[k]];

            OMesh::Vector3 a, b, nj;
            double V, Q, S, R, BA, SRT, L0, L1, A0, A1, A10, L10;

            vector<double> phi(n_boundary_pt, 0.0);
            vector<double> psi(n_boundary_pt, 0.0);

            for(int j = 0; j < n_boundary_pt; j++)
            {
                int jp = (j + 1)%n_boundary_pt;
                const OMesh::Vector3 &vj1 = point_data[vhs[j]];
                const OMesh::Vector3 &vj2 = point_data[vhs[jp]];

                a[0] = vj2[0] - vj1[0];
                a[1] = vj2[1] - vj1[1];

                nj[0] =  a[1];
                nj[1] = -a[0];

                b[0] = vj1[0] - queryCoord[0];
                b[1] = vj1[1] - queryCoord[1];

                Q     = a[0]*a[0] + a[1]*a[1];
                S     = b[0]*b[0] + b[1]*b[1];
                R     = 2.0*(a[0]*b[0] + a[1]*b[1]);
                BA    = b[0]*nj[0] + b[1]*nj[1];   // Remember do not normalize Normal vector here.
                V     = 4.0*S*Q - R*R;
                assert(V >  0.0);
                SRT   = sqrt(V);
                assert(SRT > 0.0);
                L0    = log(S);
                L1    = log(S + Q + R );
                A0    = atan(R/SRT)/SRT;
                A1    = atan((2*Q+R)/SRT)/SRT;
                A10   = A1-A0;
                L10   = L1-L0;
                psi[j]    = sqrt(Q)/(4.0*M_PI)*((4.0*S-(R*R/Q))*A10 + (R/(2.0*Q))*L10 + L1 - 2);
                phi[jp]  -=  (BA/(2.0*M_PI))*((L10/(2.0*Q)) - A10*R/Q);
                phi[j]   +=  (BA/(2.0*M_PI))*((L10/(2.0*Q)) - A10*(2.0 + R/Q));
            }

            double sum = 0.0;
            for( int i = 0; i < n_boundary_pt; ++i)
                sum += phi[i];

            for( int i = 0; i < n_boundary_pt; ++i)
                phi[i] /= sum;

            sum = 0.0;
            for( int i = 0; i < n_boundary_pt; ++i)
                sum += phi[i];
            assert(fabs(sum -1.0) < 1.0E-06);

            for( int i = 0; i < n_boundary_pt; ++i)
            {
                int cIndex = vtx_idx_to_control_pt_idx_map[vhs[i]];
                greenw(k, cIndex) = phi[i];
                greenw(k, cIndex + n_boundary_pt) = psi[i];
            }
        }
    }

    if (dimension == 3)
    {
        GreenCoordinates gCoordinate(pmesh_.get(), cageMesh_.get());
        threeDGreen = gCoordinate.coords;

        for (OMesh::VertexIter vIt = cageMesh_->vertices_begin(); vIt != cageMesh_->vertices_end(); ++vIt)
        {
            orginalCagePos.push_back(cageMesh_->point(vIt.handle()));
        }
    }

	string filename = "/Users/juyong/Works/SBC/Results/Greenmat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream ofile(filename.c_str());
    if(!ofile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        ofile<<greenw;
    }
}

void ConstrainedMeshPlugin::computeHarmonicCoordinate()
{
    initialization();

    harmonicw.resize(n_data_pt, n_boundary_pt);

    for (int k = 0; k < n_data_pt; ++k)
    {
        vector<double> distance(n_boundary_pt, 0);
        vector<double> length(n_boundary_pt, 0);
        OMesh::Point datapos = point_data[datapt_idx_to_vtx_idx_map[k]];
        double sum = 0;
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            OMesh::Point controlpos0 = point_data[vhs[i]];
            OMesh::Point controlpos1 = point_data[vhs[(i + 1)%n_boundary_pt]];
            distance[i] = (controlpos0 - datapos).norm();
            length[i] = (controlpos0 - controlpos1).norm();
        }
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            double a = acos((pow(distance[(i + 1)%n_boundary_pt], 2) + pow(length[i], 2) - pow(distance[i], 2))/2/distance[(i + 1)%n_boundary_pt]/length[i]);
            double b = acos((pow(distance[((i - 1) + n_boundary_pt)%n_boundary_pt], 2) + pow(length[((i - 1) + n_boundary_pt)%n_boundary_pt], 2) - pow(distance[i], 2))/2/distance[((i - 1) + n_boundary_pt)%n_boundary_pt]/length[((i - 1) + n_boundary_pt)%n_boundary_pt]);

            harmonicw(k, vtx_idx_to_control_pt_idx_map[vhs[i]]) = 1/tan(a) + 1/tan(b);
            sum += harmonicw(k, vtx_idx_to_control_pt_idx_map[vhs[i]]);
        }
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            harmonicw(k, i) /= sum;
        }
    }

	string filename = "/Users/juyong/Works/SBC/Results/Harmonicmat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream ofile1(filename.c_str());
    if (!ofile1.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        ofile1<<harmonicw;
    }
}

void ConstrainedMeshPlugin::computeSmoothBC(int num_threads,
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
                                            int dimension,
                                            int laplaceType,
                                            bool nonnegativeConstraint,
                                            bool linearPrecision)
{
    if (sbcl0_solver == NULL)
        sbcl0_solver = new SBCLHalfMesh(pmesh_.get(), dimension, hasCage_, cageObject_.get(), laplaceType, nonnegativeConstraint);

    sbcl0_solver->initialize_variables(num_threads, laplacian_energy_bound, laplacian_bound_min_ratio, init_penalty_weight_, max_penalty_weight, primal_eps_val_, dual_eps_val_, init_dual_eps_, initval_primal_eps_, initval_dual_eps_, tau_incr_, max_iter, primal_max_iter, dlweight_, linearPrecision);

    init_w = sbcl0_solver->get_init_w();

	string filename = "/Users/juyong/Works/SBC/Results/ADM-L1mat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream outfile(filename.c_str());
    if(!outfile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        outfile<<init_w;
    }

    initialization();
    initialize_fairness_energy_matrix(laplaceType);

    std::cout<<"Initial smoothness energy: "<<(matrix_L*init_w).norm()<<std::endl;
}

void ConstrainedMeshPlugin::test_SBC(int num_threads, double laplacian_energy_bound, double laplacian_bound_min_ratio, double init_penalty_weight_, double max_penalty_weight, double primal_eps_val_, double dual_eps_val_, double init_dual_eps_, double initval_primal_eps_, double initval_dual_eps_, double tau_incr_, int max_iter, int primal_max_iter, double dlweight_, int dimension, int laplaceType, bool nonnegativeConstraint, bool linearPrecision)
{/*
    if (sbcl0_solver == NULL)
        sbcl0_solver = new SBCLHalfMesh(pmesh_.get(), dimension, hasCage_, cageObject_.get(), laplaceType, nonnegativeConstraint);

    sbcl0_solver->initialize_variables(num_threads, laplacian_energy_bound, laplacian_bound_min_ratio, init_penalty_weight_, max_penalty_weight, primal_eps_val_, dual_eps_val_, init_dual_eps_, initval_primal_eps_, initval_dual_eps_, tau_incr_, max_iter, primal_max_iter, dlweight_, linearPrecision);
    sbcl0_solver->solve();
    w = sbcl0_solver->get_w();*/

    SBCL0Mesh* solver = new SBCL0Mesh(pmesh_.get(), dimension, hasCage_, cageObject_.get(), laplaceType, nonnegativeConstraint);

    solver->initialize_variables(num_threads, laplacian_energy_bound, laplacian_bound_min_ratio, init_penalty_weight_, max_penalty_weight, primal_eps_val_, dual_eps_val_, init_dual_eps_, initval_primal_eps_, initval_dual_eps_, tau_incr_, max_iter, primal_max_iter, dlweight_, linearPrecision);
    solver->solve();
    w = solver->get_w();

	string filename = "/Users/juyong/Works/SBC/Results/ADM-LhalfMat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        outfile<<w;
    }
}

void ConstrainedMeshPlugin::initialization()
{
    if (!pmesh_)
    {
        set_SelectObject_as_Cage();
        set_SelectObject_as_Data();
    }

    point_data.clear();
    vtx_idx_to_control_pt_idx_map.clear();
    datapt_idx_to_vtx_idx_map.clear();
    controlpt_idx_to_vtx_idx_map.clear();
    vtx_idx_to_datapt_idx_map.clear();
    n_boundary_pt = 0;
    n_data_pt = 0;

    OMesh::VertexIter v_it, v_end = pmesh_->vertices_end();

    for (v_it = pmesh_->vertices_begin(); v_it != v_end; ++ v_it)
    {
        if (!hasCage_)
        {
            if(pmesh_->is_boundary(v_it))
            {
                vtx_idx_to_control_pt_idx_map.push_back(controlpt_idx_to_vtx_idx_map.size());
                vtx_idx_to_datapt_idx_map.push_back(-1);
                controlpt_idx_to_vtx_idx_map.push_back(point_data.size());
                n_boundary_pt++;
            }
            else
            {
                vtx_idx_to_datapt_idx_map.push_back(datapt_idx_to_vtx_idx_map.size());
                vtx_idx_to_control_pt_idx_map.push_back(-1);
                datapt_idx_to_vtx_idx_map.push_back(point_data.size());
                n_data_pt++;
            }
        }
        else
        {
            vtx_idx_to_datapt_idx_map.push_back(datapt_idx_to_vtx_idx_map.size());
            vtx_idx_to_control_pt_idx_map.push_back(-1);
            datapt_idx_to_vtx_idx_map.push_back(point_data.size());
            n_data_pt++;
        }

        OMesh::Point cur_pt = pmesh_->point(v_it);
        point_data.push_back(cur_pt);
    }

    vhs.clear();
    if (!hasCage_)
    {
        OMesh::HalfedgeIter h_it, hend = pmesh_->halfedges_end();
        OMesh::HalfedgeHandle first_boundary_heh;
        for(h_it = pmesh_->halfedges_begin(); h_it != hend; ++ h_it)
        {
            if(pmesh_->is_boundary(h_it.handle()))
            {
                first_boundary_heh = h_it.handle();
                break;
            }
        }
        if(first_boundary_heh.is_valid())
        {
            vhs.push_back(pmesh_->to_vertex_handle(first_boundary_heh).idx());
            OMesh::HalfedgeHandle next_heh = pmesh_->next_halfedge_handle(first_boundary_heh);

            while(next_heh != first_boundary_heh)
            {
                vhs.push_back(pmesh_->to_vertex_handle(next_heh).idx());
                next_heh = pmesh_->next_halfedge_handle(next_heh);
            }
        }
    }
    else
    {
        VertexIterator v_it, v_end = cageObject_->vertexEnd();
        for(v_it = cageObject_->vertexBegin(); v_it != v_end; ++v_it)
        {
            vtx_idx_to_control_pt_idx_map.push_back(controlpt_idx_to_vtx_idx_map.size());
            vtx_idx_to_datapt_idx_map.push_back(-1);
            controlpt_idx_to_vtx_idx_map.push_back(point_data.size());
            n_boundary_pt++;
            vhs.push_back(point_data.size());
            point_data.push_back(v_it->getPosition());
        }
    }

    double area = 0;
    for (int i = 0; i < n_boundary_pt; ++i)
    {
        area += point_data[vhs[i]][0]*(point_data[vhs[(i + 1)%n_boundary_pt]][1] - point_data[vhs[(i - 1 + n_boundary_pt)%n_boundary_pt]][1]);
        area *= 0.5;
    }

    if (area < 0)
        std::reverse(vhs.begin(), vhs.end());

    control_edge_length.resize(n_boundary_pt);
    control_edge_normal.resize(n_boundary_pt);
    for(int i = 0; i < n_boundary_pt; ++i)
    {
        int cIndex = vtx_idx_to_control_pt_idx_map[vhs[i]];
        OMesh::Point p0 = point_data[vhs[i]];
        OMesh::Point p1 = point_data[vhs[(i + 1)%n_boundary_pt]];
        control_edge_length[cIndex] = (p0 - p1).norm();

        double x  = p1[0] - p0[0];
        double y  = p1[1] - p0[1];

        double len = sqrt(x*x + y*y);
        control_edge_normal[cIndex] = OMesh::Vector3(y/len, -x/len, 0);
    }
}

void ConstrainedMeshPlugin::load_data(int coordinateType)
{
    initialization();

	//load data from file
    std::string coordinateFileName = QFileDialog::getOpenFileName(0, tr("(Open file with coordinate value)")).toStdString();
    std::ifstream infile;
    infile.open(coordinateFileName.c_str());
    if (!infile.is_open())
	{
		dolphinErr()<<"Can not open file!"<<endl;
		return;
    }

    int index;
    double weight;
    switch (coordinateType)
    {
    case 0:
        init_w.setZero(n_data_pt, n_boundary_pt);
        index = 0;
        while(infile.good() && index < n_data_pt*n_boundary_pt)
        {
            infile>>weight;
            init_w(index/n_boundary_pt, index%n_boundary_pt) = weight;
            index++;
        }
        break;
    case 1:
        w.setZero(n_data_pt, n_boundary_pt);
        index = 0;
        while(infile.good() && index < n_data_pt*n_boundary_pt)
        {
            infile>>weight;
            w(index/n_boundary_pt, index%n_boundary_pt) = weight;
            index++;
        }
        break;
    case 2:
        meanw.setZero(n_data_pt, n_boundary_pt);
        index = 0;
        while(infile.good() && index < n_data_pt*n_boundary_pt)
        {
            infile>>weight;
            meanw(index/n_boundary_pt, index%n_boundary_pt) = weight;
            index++;
        }
        break;
    case 3:
        harmonicw.setZero(n_data_pt, n_boundary_pt);
        index = 0;
        while (infile.good() && index < n_data_pt*n_boundary_pt)
        {
            infile>>weight;
            harmonicw(index/n_boundary_pt, index%n_boundary_pt) = weight;
            index++;
        }
        break;
    case 4:
        boundedBiharmonicW.setZero(n_data_pt, n_boundary_pt);
        index = 0;
        while (infile.good() && index < n_data_pt*n_boundary_pt)
        {
            infile>>weight;
            boundedBiharmonicW(index/n_boundary_pt, index%n_boundary_pt) = weight;
            index++;
        }
        break;
    default:
        break;
    }
    //end of loading data
}

void ConstrainedMeshPlugin::setCoordinateType(int type)
{
    coordinateType_ = type;
    std::cout<<"Current coordinate type: ";
    switch (coordinateType_)
    {
    case 0:
        std::cout<<"L1 smooth coordinate"<<std::endl;
        break;
    case 1:
        std::cout<<"L0 sparse coordinate"<<std::endl;
        break;
    case 2:
        std::cout<<"Mean value coordinate"<<std::endl;
        break;
    case 3:
        std::cout<<"Harmonic coordinate"<<std::endl;
        break;
    case 4:
        std::cout<<"Bounded biharmonic weight"<<std::endl;
        break;
    case 5:
        std::cout<<"Green coordinate"<<std::endl;
        break;
    default:
        std::cout<<"Wrong type"<<std::endl;
        break;
    }
}

void ConstrainedMeshPlugin::displayAllDataCoordinates(int coordinateType, double epsilon)
{
    initialization();

    std::vector<double> w_tex_coord;
    double nMax = 0;
    for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
    {
        int vIndex = vIt.handle().idx();
        int vid = vtx_idx_to_datapt_idx_map[vIndex];
        if (vid >= 0)
        {
            double nonzeros = 0;
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                switch (coordinateType)
                {
                case 0:
                    if (init_w.rows() == 0)
                        return;
                    if (init_w(vid, j) > epsilon)
                        nonzeros++;
                    break;
                case 1:
                    if (w.rows() == 0)
                        return;
                    if (w(vid, j) > epsilon)
                        nonzeros++;
                    break;
                case 2:
                    if (meanw.rows() == 0)
                        return;
                    if (meanw(vid, j) > epsilon)
                        nonzeros++;
                    break;
                case 3:
                    if (harmonicw.rows() == 0)
                        return;
                    if (harmonicw(vid, j) > epsilon)
                        nonzeros++;
                    break;
                case 4:
                    if (boundedBiharmonicW.rows() == 0)
                        return;
                    if (boundedBiharmonicW(vid, j) > epsilon)
                        nonzeros++;
                    break;
                case 5:
                    if (greenw.rows() == 0)
                        return;
                    if (greenw(vid, j) > epsilon)
                        nonzeros++;
                    break;
                default:
                    break;
                }
            }

            w_tex_coord.push_back(nonzeros);
            nMax = (nonzeros > nMax)?nonzeros:nMax;
        }
        else
            w_tex_coord.push_back(0);
    }

    std::cout<<coordinateType<<": "<<nMax<<std::endl;

    std::tr1::shared_ptr<OMesh> tex_pmesh = std::tr1::shared_ptr<OMesh>(new OMesh(*pmesh_));

    OpenMeshNode *textureMeshNode = new OpenMeshNode(&getScenegraph(), tex_pmesh);

    textureMeshNode->setName("nonzero_texture");

    if(!tex_pmesh->has_vertex_texcoords2D())
    {
        tex_pmesh->request_vertex_texcoords2D();
        assert(tex_pmesh->has_vertex_texcoords2D());
    }

    int m = pmesh_->n_vertices();
    for(int i = 0; i < m; i++)
    {
        PolyMeshType::VertexHandle vh(i);
        tex_pmesh->set_texcoord2D(vh, PolyMeshType::TexCoord2D(w_tex_coord[i]/nMax, w_tex_coord[i]/nMax));
    }

    Dolphin::scenegraph::Texture& texture = *(textureMeshNode->getTexture());

    if (!texture.hasTexture())
    {
        Dolphin::scenegraph::TextureProps& texProps = texture.getTextureProps();
        texProps.textureLoadType_=Dolphin::scenegraph::TextureProps::SOIL_TYPE_MESH_TEX_COORD;
        texProps.textureLayoutFlags_|=Dolphin::scenegraph::TextureProps::SOIL_FLAG_TEXTURE_REPEATS;
        texProps.texWarpMode_=Dolphin::scenegraph::TextureProps::TEX_WARP_REPEAT;
		texProps.textureFileName=std::string("/Users/juyong/Works/SBC/Code/colorbar_texture.png");

        OpenMeshNode* opmn = NULL;
        Dolphin::gui::OpenMeshNodeTextureDialog::loadTextureToObject(textureMeshNode, opmn);
    }

    textureMeshNode->getDrawModes()->setMode(DrawModes::FACE_SHADING_SMOOTH);
}

void ConstrainedMeshPlugin::displayCoordinates()
{
    initialization();

    for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
	{
        if (pmesh_->status(vIt).selected())
		{
            std::vector<double> measures;
            std::vector<int> indexArray;

            int vid = vIt.handle().idx();
            for (int i = 0; i < n_boundary_pt; ++i)
            {
                double weight = 0;
                switch (coordinateType_)
                {
                case 0:
                    if (init_w.rows() == 0)
                        return;
                    weight = init_w(vid, i);
                    break;
                case 1:
                    if (w.rows() == 0)
                        return;
                    weight = w(vid, i);
                    break;
                case 2:
                    if (meanw.rows() == 0)
                        return;
                    weight = meanw(vid, i);
                    break;
                case 3:
                    if (harmonicw.rows() == 0)
                        return;
                    weight = harmonicw(vid, i);
                    break;
                case 4:
                    if (boundedBiharmonicW.rows() == 0)
                        return;
                    weight = boundedBiharmonicW(vid, i);
                    break;
                case 5:
                    if (greenw.rows() == 0)
                        return;
                    weight = greenw(vid, i);
                    break;
                default:
                    weight = 0;
                    break;
                }

                measures.push_back(weight);
                if (hasCage_)
                    indexArray.push_back(i);
                else
                    indexArray.push_back(controlpt_idx_to_vtx_idx_map[i]);
            }

            if (hasCage_)
                VisualizeMeasure(cageNode_, measures, indexArray);
            else
                VisualizeMeasure(meshNode_, measures, indexArray);
		}
    }

    for (size_t i = 0; i < cageObject_->nPoints(); ++i)
    {
        if (cageObject_->isVertexSelected(i))
        {
            meshNode_->getDrawModes()->setMode(DrawModes::FACE_COLOR_SMOOTH);
            cageObject_->setVertexColor(i, OMesh::Color(1.0, 0.0, 0.0, 1.0));
            for (size_t j = 0; j < cageObject_->nPoints(); ++j)
            {
                if (j != i)
                    cageObject_->setVertexColor(j, OMesh::Color(0.0, 0.0, 1.0, 1.0));
            }
/*
            bool exist = false;
            std::tr1::shared_ptr<EdgeSet> dEdgeSet;
            EdgeSetNode* dEdgeSetNode;
            QList<EdgeSetNode*> clouds;
            getScenegraph().getDescendants<EdgeSetNode*>(clouds);
            for( QList<EdgeSetNode*>::iterator it = clouds.begin(); it != clouds.end(); ++it)
            {
                if ((*it)->objectName().toStdString() == "control-point")
                {
                    dEdgeSetNode = (*it);
                    dEdgeSet = dEdgeSetNode->getEdgeSet();
                    exist = true;
                    break;
                }
            }
            if (!exist)
            {
                std::tr1::shared_ptr<EdgeSet> dtemp(new EdgeSet());
                dEdgeSet = dtemp;
                dEdgeSetNode = new EdgeSetNode(&getScenegraph(), dEdgeSet);
                dEdgeSetNode->setName(QString("control-point"));
            }

            dEdgeSet->add_vertex(cageObject_->getVertexPosition(i));
            dEdgeSetNode->getDefaultMaterial()->setVertexRadius(15.0);
            dEdgeSet->setVertexColor(0, OMesh::Color(1.0, 0.0, 0.0, 1.0));
            dEdgeSetNode->getDrawModes()->setMode(DrawModes::VERTEX_COLOR);
            dEdgeSetNode->getDrawModes()->setMode(DrawModes::VERTEX_DRAWING);
            dEdgeSetNode->setGeometryChanged();
            dEdgeSetNode->nodeUpdated();
*/
            std::vector<double> measures;
            std::vector<int> indexArray;
            for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
            {
                int vIndex = vIt.handle().idx();
                double weight = 0;
                switch (coordinateType_)
                {
                case 0:
                    if (init_w.rows() == 0)
                        return;
                    weight = init_w(vIndex, i);
                    break;
                case 1:
                    if (w.rows() == 0)
                        return;
                    weight = w(vIndex, i);
                    break;
                case 2:
                    if (meanw.rows() == 0)
                        return;
                    weight = meanw(vIndex, i);
                    break;
                case 3:
                    if (harmonicw.rows() == 0)
                        return;
                    weight = harmonicw(vIndex, i);
                    break;
                case 4:
                    if (boundedBiharmonicW.rows() == 0)
                        return;
                    weight = boundedBiharmonicW(vIndex, i);
                    break;
                case 5:
                    if (greenw.rows() == 0)
                        return;
                    weight = greenw(vIndex, i);
                    break;
                default:
                    weight = 0;
                    break;
                }

                double new_weight = 0;
                if (weight < 1.0e-4)
                    new_weight = -4.0;
                else
                    new_weight = std::log10(weight);

                measures.push_back(new_weight);
                indexArray.push_back(vIndex);
            }

            VisualizeMeasure(meshNode_, measures, indexArray, true, -4.0, 0.0);
        }
    }
}

void ConstrainedMeshPlugin::addParametrizationtexture(OpenMeshNode* meshNode)
{
    QDir textureDir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
    if (textureDir.dirName() == "MacOS") {
        textureDir.cdUp();
    }
#endif

    textureDir.cd("Resources");
    textureDir.cd("textures");
    QString q = textureDir.absolutePath();

    Dolphin::scenegraph::Texture& texture = *(meshNode->getTexture());
    if (!texture.hasTexture())
    {
        Dolphin::scenegraph::TextureProps& texProps = texture.getTextureProps();
        texProps.textureLoadType_=Dolphin::scenegraph::TextureProps::SOIL_TYPE_MESH_TEX_COORD;
        texProps.textureLayoutFlags_|=Dolphin::scenegraph::TextureProps::SOIL_FLAG_TEXTURE_REPEATS;
        texProps.texWarpMode_=Dolphin::scenegraph::TextureProps::TEX_WARP_REPEAT;

        texProps.textureFileName=std::string(q.append("/2d_lines_blur.png").toStdString());

        OpenMeshNode* opmn = NULL;
        Dolphin::gui::OpenMeshNodeTextureDialog::loadTextureToObject(meshNode,opmn);
    }

    //Adjust drawing to use the method that actually read the halfedge texture cooridnates
    meshNode->getDrawModes()->setMode(DrawModes::FACE_SHADING_SMOOTH);
    meshNode->getDrawModes()->resetMode(DrawModes::FACE_COLOR_SMOOTH);
    meshNode->getDrawModes()->resetMode(DrawModes::FACE_COLOR_FLAT);
}

void ConstrainedMeshPlugin::displayAlongControls()
{
    meshNode_->getDrawModes()->setMode(DrawModes::FACE_COLOR_SMOOTH);
    initialization();

    bool exist = false;
    std::tr1::shared_ptr<EdgeSet> dEdgeSet;
    EdgeSetNode* dEdgeSetNode;
    QList<EdgeSetNode*> clouds;
    getScenegraph().getDescendants<EdgeSetNode*>(clouds);
    for( QList<EdgeSetNode*>::iterator it = clouds.begin(); it != clouds.end(); ++it)
    {
        if ((*it)->objectName().toStdString() == "control-point")
        {
            dEdgeSetNode = (*it);
            dEdgeSet = dEdgeSetNode->getEdgeSet();
            exist = true;
            break;
        }
    }
    if (!exist)
    {
        std::tr1::shared_ptr<EdgeSet> dtemp(new EdgeSet());
        dEdgeSet = dtemp;
        dEdgeSetNode = new EdgeSetNode(&getScenegraph(), dEdgeSet);
        dEdgeSetNode->setName(QString("control-point"));
    }

    dEdgeSet->add_vertex(cageObject_->getVertexPosition(0));
    dEdgeSetNode->getDefaultMaterial()->setVertexRadius(15.0);
    dEdgeSet->setVertexColor(0, OMesh::Color(1.0, 0.0, 0.0, 1.0));
    dEdgeSetNode->getDrawModes()->setMode(DrawModes::VERTEX_COLOR);
    dEdgeSetNode->getDrawModes()->setMode(DrawModes::VERTEX_DRAWING);
    dEdgeSetNode->setGeometryChanged();
    dEdgeSetNode->nodeUpdated();

    for (size_t i = 0; i < cageObject_->nPoints(); ++i)
    {
        std::vector<double> measures;
        std::vector<int> indexArray;
        for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
        {
            int vIndex = vIt.handle().idx();
            double weight = 0;
            switch (coordinateType_)
            {
            case 0:
                if (init_w.rows() == 0)
                    return;
                weight = init_w(vIndex, i);
                break;
            case 1:
                if (w.rows() == 0)
                    return;
                weight = w(vIndex, i);
                break;
            case 2:
                if (meanw.rows() == 0)
                    return;
                weight = meanw(vIndex, i);
                break;
            case 3:
                if (harmonicw.rows() == 0)
                    return;
                weight = harmonicw(vIndex, i);
                break;
            case 4:
                if (boundedBiharmonicW.rows() == 0)
                    return;
                weight = boundedBiharmonicW(vIndex, i);
                break;
            case 5:
                if (greenw.rows() == 0)
                    return;
                weight = greenw(vIndex, i);
                break;
            default:
                weight = 0;
                break;
            }

            double new_weight = 0;
            if (weight < 1.0e-4)
                new_weight = -4.0;
            else
                new_weight = std::log10(weight);

            measures.push_back(new_weight);
            indexArray.push_back(vIndex);
        }

        VisualizeMeasure(meshNode_, measures, indexArray, true, -4.0, 0.0);

        cageObject_->setVertexColor(i, OMesh::Color(1.0, 0.0, 0.0, 1.0));
        for (size_t j = 0; j < cageObject_->nPoints(); ++j)
        {
            if (j != i)
            {
                cageObject_->setVertexColor(j, OMesh::Color(0.0, 0.0, 1.0, 1.0));
            }
        }
        cageNode_->setGeometryChanged();
        dEdgeSet->setVertexPosition(0, cageObject_->getVertexPosition(i));
        dEdgeSetNode->setGeometryChanged();

        clock_t temp = clock() + 0.4*CLOCKS_PER_SEC;
        while (clock() < temp) {}
    }
}

void ConstrainedMeshPlugin::mouseMoveEvent(QMouseEvent* _event)
{
    if (_event->buttons() & Qt::LeftButton)
    {
        cagebasedDeformation(false);
    }

    if (_event->buttons() & Qt::RightButton)
    {
        Scenegraph* s = &Plugin_interface::getScenegraph();
        QGLViewer* v = Plugin_interface::getQGLViewer();
        Dolphin::picking::BasePicker basePicker(s, v);
        basePicker.setPickUnselected(true);
        std::tr1::shared_ptr<Dolphin::picking::RayPicker> rp = basePicker.pickWithPoint(_event->x(), _event->y(), 40);
        if (rp->pickedVertex() != -1)
        {
            if (rp->pickedNode() == meshNode_)
            {
                OMesh::VertexHandle vHandle = pmesh_->vertex_handle(rp->pickedVertex());
                pmesh_->status(vHandle).set_selected(true);
                displayCoordinates();
                pmesh_->status(vHandle).set_selected(false);
            }/*
            if (rp->pickedNode() == cageNode_)
            {
                cageObject_->setVertexSelected(rp->pickedVertex(), true);
                displayCoordinates();
                cageObject_->setVertexSelected(rp->pickedVertex(), false);
            }*/
        }
        displayCoordinates();
    }
}

void ConstrainedMeshPlugin::keyPressEvent(QKeyEvent* _event)
{
    if(_event->key() == Qt::Key_C)
        displayAlongControls();

    if (_event->key() == Qt::Key_D)
        displayCoordinates();

    if (_event->key() == Qt::Key_P)
        displayCoordinatesAlongPath();

    if (_event->key() == Qt::Key_Q)
        cagebasedDeformation(true);

    if (_event->key() == Qt::Key_M)
	{
        color_map_ = !color_map_;
		if (color_map_)
			dolphinOut()<<"Color map is on!"<<std::endl;
		else
			dolphinOut()<<"Color map is off!"<<std::endl;
    }
}

void ConstrainedMeshPlugin::displayCoordinatesAlongPath()
{
    OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
        dolphinErr() << "No mesh selected" << std::endl;
        return;
    }
    std::tr1::shared_ptr<PolyMeshType> pmesh = meshNode->getMesh();


    OMeshPathNode *omeshpathNode = getScenegraph().getFirstDescendant<OMeshPathNode*>(true);
    if(!omeshpathNode){
        dolphinErr() << "No mesh selected" << std::endl;
        return;
    }
    std::tr1::shared_ptr<OMeshPath> omeshpath = omeshpathNode->getOMeshPath();

    initialization();

    if (w.rows() == 0)
    {
        return;
    }

    meshNode->getDrawModes()->setMode(DrawModes::VERTEX_COLOR);
    omeshpathNode->getDrawModes()->setMode(DrawModes::VERTEX_COLOR);

    unsigned nPoints = omeshpath->nPoints();
    for (unsigned i = 0; i < nPoints; ++i)
    {
        std::vector<double> measures;
        std::vector<int> indexArray;
        BarycentricCoordinates bc = omeshpath->getCoordinates(i);
        OpenMesh::FaceHandle fHandle(omeshpath->getFaceIndex(i));

        if (i >= 1)
            omeshpath->setPointColor(i - 1, OMesh::Color(1., 1., 1., 1.));
        else
            omeshpath->setPointColor(nPoints - 1, OMesh::Color(1., 1., 1., 1.));

        omeshpath->setPointColor(i, OMesh::Color(1., 0., 0., 1.));

        omeshpathNode->setGeometryChanged();

        OMesh::FaceVertexIter fvIt = pmesh->fv_iter(fHandle);
        int v0 = fvIt.handle().idx(); ++fvIt;
        int v1 = fvIt.handle().idx(); ++fvIt;
        int v2 = fvIt.handle().idx();

        int vid0 = vtx_idx_to_datapt_idx_map[v0];
        int vid1 = vtx_idx_to_datapt_idx_map[v1];
        int vid2 = vtx_idx_to_datapt_idx_map[v2];
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            double weight;
            switch (coordinateType_)
            {
            case 0:
                weight = bc.u_*init_w(vid0, j) + bc.v_*init_w(vid1, j) + bc.w_*init_w(vid2, j);
                break;
            case 1:
                weight = bc.u_*w(vid0, j) + bc.v_*w(vid1, j) + bc.w_*w(vid2, j);
                break;
            case 2:
                weight = bc.u_*meanw(vid0, j) + bc.v_*meanw(vid1, j) + bc.w_*meanw(vid2, j);
                break;
            case 3:
                weight = bc.u_*harmonicw(vid0, j) + bc.v_*harmonicw(vid1, j) + bc.w_*harmonicw(vid2, j);
                break;
            case 4:
                weight = bc.u_*boundedBiharmonicW(vid0, j) + bc.v_*boundedBiharmonicW(vid1, j) + bc.w_*boundedBiharmonicW(vid2, j);
                break;
            case 5:
                weight = bc.u_*greenw(vid0, j) + bc.v_*greenw(vid1, j) + bc.w_*greenw(vid2, j);
                break;
            default:
                weight = 0;
                    break;
            }

            measures.push_back(weight);
            indexArray.push_back(controlpt_idx_to_vtx_idx_map[j]);
        }

        if (hasCage_)
            VisualizeMeasure(cageNode_, measures, indexArray);
        else
            VisualizeMeasure(meshNode_, measures, indexArray);

        clock_t temp = clock() + 0.4*CLOCKS_PER_SEC;
        while (clock() < temp) {}
    }
}

void ConstrainedMeshPlugin::VisualizeMeasure(VertexBasedGeometryNode * histogramNode,
                                             std::vector<double> measures,
											 std::vector<int>& indexarray,
											 bool setBoundary_,
											 double leftBoundary_,
											 double rightBoundary_)
{
    HistogramWidget* histogram = (static_cast<HistogramPlugin*>(getPluginManager().getLoadedPluginByName("HistogramPlugin")))->getHistogramWidget();
	std::tr1::shared_ptr<Dolphin::utilities::MeshHistogram> meshHistogram_ = std::tr1::shared_ptr<MeshHistogram>(new MeshHistogram(histogram, histogramNode, measures, utilities::VERTEX, indexarray, setBoundary_, leftBoundary_, rightBoundary_));
    meshHistogram_->showOnMesh(false);
}

void ConstrainedMeshPlugin::cagebasedDeformation(bool readData)
{
    initialization();

    std::vector<Eigen::MatrixXd> controlDatas;
    if (!readData)
    {
        ofstream outfile;
        outfile.open ("coordinates.txt", fstream::in | fstream::out | fstream::app);
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            OMesh::Point pos = point_data[controlpt_idx_to_vtx_idx_map[j]];
            outfile<<j<<" "<<pos<<std::endl;
        }
    }
    else
    {
        std::string frameFile = QFileDialog::getOpenFileName(0, tr("(Open key frames)")).toStdString();
        ifstream infile(frameFile.c_str());
        int index;
        double x, y, z;
        Eigen::MatrixXd coord(n_boundary_pt, 3);
        while (infile>>index>>x>>y>>z)
        {
            coord(index, 0) = x;
            coord(index, 1) = y;
            coord(index, 2) = z;
            if (index == n_boundary_pt - 1)
                controlDatas.push_back(coord);
        }
    }

    if (original_positions_.size() == 0)
    {
        for (size_t i = 0; i < point_data.size(); ++i)
        {
            original_positions_.push_back(point_data[i]);
        }
    }

	double controlLen = 0;
    for (int i = 0; i < n_boundary_pt; ++i)
	{
        if ((point_data[controlpt_idx_to_vtx_idx_map[i]] - initial_cage_positions_[i]).norm() > controlLen)
		{
            controlLen = (point_data[controlpt_idx_to_vtx_idx_map[i]] - initial_cage_positions_[i]).norm();
		}
	}

    int iters = 1;
    if (readData)
    {
        iters = controlDatas.size();
    }

    int deformNum = 0;
    while (deformNum < 5)
    {
        deformNum++;
        for (int k = 0; k < iters; ++k)
        {
            int itNum = 1;
            std::vector<Eigen::MatrixXd> cPositions;
            if (readData)
            {
                itNum = 10;
                for (int i = 0; i < itNum; ++i)
                {
                    cPositions.push_back(controlDatas[(k - 1 + iters)%iters] + (controlDatas[k] - controlDatas[(k - 1 + iters)%iters])*double(i + 1)/double(itNum));
                }
            }

            for (int it = 0; it < itNum; ++it)
            {
                if (readData)
                {
                    for (int j = 0; j < n_boundary_pt; ++j)
                    {
                        OMesh::Point pos = OMesh::Point(cPositions[it](j, 0), cPositions[it](j, 1), cPositions[it](j, 2));
                        cageObject_->setVertexPosition(j, pos);
                    }
                    cageNode_->setGeometryChanged();
                    initialization();
                }

                std::vector<double> measures;
                std::vector<int> indexArray;
                for (int i = 0; i < n_data_pt; ++i)
                {
                    OMesh::VertexHandle vHandle = pmesh_->vertex_handle(datapt_idx_to_vtx_idx_map[i]);
                    OMesh::Vector3 weighted_pt(0.0, 0.0, 0.0);
                    for (int j = 0; j < n_boundary_pt; ++j)
                    {
                        OMesh::Point pos = point_data[controlpt_idx_to_vtx_idx_map[j]];

                        switch (coordinateType_)
                        {
                        case 0:
                            weighted_pt += init_w(i, j)*pos;
                            break;
                        case 1:
                            if (linearPrecision_)
                                weighted_pt += w(i, j)*pos;
                            else
                                weighted_pt += w(i, j)*(pos - initial_cage_positions_[j]);
                            break;
                        case 2:
                            weighted_pt += meanw(i, j)*pos;
                            break;
                        case 3:
                            weighted_pt += harmonicw(i, j)*pos;
                            break;
                        case 4:
                            weighted_pt += boundedBiharmonicW(i, j)*(pos - initial_cage_positions_[j]);
                            break;
                        case 5:
                            if (dim == 2)
                            {
                                weighted_pt += greenw(i, j)*pos + greenw(i, j + n_boundary_pt)*control_edge_length[j]*control_edge_normal[j]/old_control_edge_length[j];
                            }
                            if (dim == 3)
                                weighted_pt += threeDGreen[i].coord_v[j]*pos;
                            break;
                        default:
                            weighted_pt += OMesh::Vector3(0., 0., 0.);
                            break;
                        }
                    }

                    if (coordinateType_ == 5 && dim == 3)
                    {
                        // Compute scale factor per face
                        OMesh::FaceIter fit, fend = cageMesh_->faces_end();
                        for(fit = cageMesh_->faces_begin(); fit != fend; ++fit)
                        {
                            int fIndex = fit.handle().idx();
                            OMesh::FaceVertexIter fv_it = cageMesh_->fv_iter(fit.handle());
                            uint vi0 = fv_it.handle().idx();
                            Point& p10 = cageMesh_->point(fv_it.handle());
                            ++fv_it;
                            uint vi1 = fv_it.handle().idx();
                            const Point& p11 = cageMesh_->point(fv_it.handle());
                            ++fv_it;
                            uint vi2 = fv_it.handle().idx();
                            const Point& p12 = cageMesh_->point(fv_it.handle());

                            const Point& p00 = orginalCagePos[vi0];
                            const Point& p01 = orginalCagePos[vi1];
                            const Point& p02 = orginalCagePos[vi2];

                            Point u0 = p01 - p00; Point u1 = p11 - p10;
                            Point v0 = p02 - p00; Point v1 = p12 - p10;

                            double s = sqrt(u1.sqrnorm()*v0.sqrnorm() - 2.0f*dot(u1, v1)*dot(u0, v0) + v1.sqrnorm()*u0.sqrnorm())/(sqrt(8.0f)*BasicMeasuring::triangleSurfaceArea(fit.handle(), cageMesh_.get()));

                            weighted_pt += threeDGreen[i].coord_n[fIndex]*s*cageMesh_->normal(fit.handle());
                        }
                    }

                    if ((coordinateType_ == 1 && !linearPrecision_) || coordinateType_ == 4)
                        pmesh_->point(vHandle) = initial_data_positions_[vHandle.idx()] + weighted_pt;
                    else
                        pmesh_->point(vHandle) = weighted_pt;

                    double new_weight = std::log10((pmesh_->point(vHandle) - initial_data_positions_[i]).norm()/controlLen);
                    measures.push_back(std::max(-3.0, new_weight));
                    indexArray.push_back(i);
                }
                meshNode_->setGeometryChanged();

                if (color_map_)
                    VisualizeMeasure(meshNode_, measures, indexArray, true, -3.0, 0.0);

                if (readData)
                {
                    clock_t temp = clock() + 0.03*CLOCKS_PER_SEC;
                    while (clock() < temp) {}
                }
            }
        }
        if (!readData)
            break;
    }
}

void ConstrainedMeshPlugin::initialize_fairness_energy_matrix_keenan()
{
    RowSparseMatrix mat_J(n_data_pt, n_data_pt);
    matrix_a.setZero(n_data_pt, n_boundary_pt);
	for (OMesh::FaceIter fIt = pmesh_->faces_begin(); fIt != pmesh_->faces_end(); ++fIt)
	{
		OMesh::FaceVertexIter fv_it = pmesh_->fv_iter(fIt.handle());
		int v0 = fv_it.handle().idx(); Point p0 = pmesh_->point(fv_it);
		int v1 = (++fv_it).handle().idx(); Point p1 = pmesh_->point(fv_it);
		int v2 = (++fv_it).handle().idx(); Point p2 = pmesh_->point(fv_it);

		//faceweight
        double w0 = BasicMeasuring::triangleAngleBAC(p1, p0, p2);
        double w1 = BasicMeasuring::triangleAngleBAC(p2, p1, p0);
        double w2 = BasicMeasuring::triangleAngleBAC(p0, p2, p1);

        w0 = 1.0/tan(w0);
        w1 = 1.0/tan(w1);
        w2 = 1.0/tan(w2);

        int d0 = vtx_idx_to_datapt_idx_map[v0];
        int d1 = vtx_idx_to_datapt_idx_map[v1];
        int d2 = vtx_idx_to_datapt_idx_map[v2];

        //check whether this edge is on the boundary or not
		OMesh::FaceHalfedgeIter fhe_it = pmesh_->fh_iter(fIt.handle());
        double eb0 = pmesh_->is_boundary(fhe_it.handle());
        double eb1 = pmesh_->is_boundary((++fhe_it).handle());
        double eb2 = pmesh_->is_boundary((++fhe_it).handle());

        mat_J(d0, d0) += (w1 + w2);
        mat_J(d1, d0) += (-w2);
        mat_J(d2, d0) += (-w1);

        mat_J(d0, d1) += (-w2);
        mat_J(d1, d1) += (w0 + w2);
        mat_J(d2, d1) += (-w0);

        mat_J(d0, d2) += (-w1);
        mat_J(d1, d2) += (-w0);
        mat_J(d2, d2) += (w0 + w1);

		//deal with boundary case
		//keenan's method
		//see the document for the algorithm
		if (eb0)
        {
            mat_J(d2, d0) += (-w2);
            mat_J(d0, d0) += (-w2);

            mat_J(d2, d1) += (w0 + w2);
            mat_J(d0, d1) += (w0 + w2);

            mat_J(d2, d2) += (-w0);
            mat_J(d0, d2) += (-w0);
		}
		if (eb1)
        {
            mat_J(d0, d0) += (-w1);
            mat_J(d1, d0) += (-w1);
            mat_J(d0, d1) += (-w0);
            mat_J(d1, d1) += (-w0);
            mat_J(d0, d2) += (w0 + w1);
            mat_J(d1, d2) += (w0 + w1);
		}
		if (eb2)
        {
            mat_J(d1, d0) += (w1 + w2);
            mat_J(d2, d0) += (w1 + w2);
            mat_J(d1, d1) += (-w2);
            mat_J(d2, d1) += (-w2);
            mat_J(d1, d2) += (-w1);
            mat_J(d2, d2) += (-w1);
		}
		//end fo keenan's boundary method
	}

    matrix_L.resize(n_data_pt, n_data_pt);
	typedef Eigen::Triplet<double> Triplet_type;
	std::vector<Triplet_type> triplets_L;
	//copy to matrix_L
	int row_index = 0;
	for (gmm::linalg_traits<RowSparseMatrix >::row_iterator rIt = gmm::linalg_traits<RowSparseMatrix >::row_begin(mat_J);
		 rIt != gmm::linalg_traits<RowSparseMatrix >::row_end(mat_J);
		 ++rIt, ++row_index)
	{
		gmm::linalg_traits< gmm::wsvector<double> >::const_iterator it = vect_const_begin(*rIt);
		gmm::linalg_traits< gmm::wsvector<double> >::const_iterator ite = vect_const_end(*rIt);

		for (; it != ite; ++it)
		{
			int colInd = it.index();
			triplets_L.push_back(Triplet_type(row_index, colInd, (*it)));
		}
	}
    matrix_L.setFromTriplets(triplets_L.begin(), triplets_L.end());
}

void ConstrainedMeshPlugin::initialize_fairness_energy_matrix(int laplaceType)
{
    matrix_L.resize(n_data_pt, n_data_pt);
    matrix_a.setZero(n_data_pt, n_boundary_pt);

    typedef Eigen::Triplet<double> Triplet_type;
    std::vector<Triplet_type> triplets_L;
    std::vector<Triplet_type> triplets_uniformL;
    std::vector<Triplet_type> triplets_meanvalueL;

    OMesh::VertexIter v_it, v_end = pmesh_->vertices_end();
    OMesh::VertexOHalfedgeIter vohe_it;

    for(v_it = pmesh_->vertices_begin(); v_it != v_end; ++v_it)
    {
        int vidx = v_it.handle().idx();
        int centerpt_idx = vtx_idx_to_datapt_idx_map[vidx];
        if(centerpt_idx >= 0)
        {
            Vector3 center_pt = point_data[vidx];

            std::vector<Vector3> neighbor_pts;
            std::vector<Vector3> neighbor_vec;
            std::vector<int> neighbor_idx;
            std::vector<bool> boundary_edge;
            for (vohe_it = pmesh_->voh_iter(v_it.handle()); vohe_it; ++vohe_it)
            {
                OMesh::VertexHandle vh = pmesh_->to_vertex_handle(vohe_it.handle());
                neighbor_idx.push_back(vh.idx());
                neighbor_pts.push_back(point_data[vh.idx()]);
                neighbor_vec.push_back(neighbor_pts.back() - center_pt);
                if (pmesh_->is_boundary(pmesh_->edge_handle(vohe_it.handle())))
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
            double uniform_weight = 0.0;
            double meanvalue_weight = 0.0;

            //if want to take out the triangle area weight
            sqrt_total_area = 1.0;
            //end of triangle area weight

            for(int i = 0; i < n_neighbor; i++)
            {
                Vector3 vec1 = neighbor_pts[i] - neighbor_pts[(i + n_neighbor - 1)%n_neighbor],
                        vec2 = center_pt - neighbor_pts[(i + n_neighbor - 1)%n_neighbor];
                Vector3 vec3 = neighbor_pts[i] - neighbor_pts[(i + 1)%n_neighbor],
                        vec4 = center_pt - neighbor_pts[(i + 1)%n_neighbor];

                Vector3 vec0 = center_pt - neighbor_pts[i];

                double cot1 = 0, cot2 = 0;
                double alphai_1 = 0, alphai = 0;
                if (i > 0 || (!boundary_edge[i] || !boundary_edge[(i + n_neighbor - 1)%n_neighbor]))
                {
                    cot1 = dot(vec1, vec2)/cross(vec1, vec2).norm();
                    alphai_1 = BasicMeasuring::triangleAngleBAC(neighbor_pts[i], center_pt, neighbor_pts[(i + n_neighbor - 1)%n_neighbor]);
                }
                if (i + 1 < n_neighbor || (!boundary_edge[i] || !boundary_edge[(i + 1)%n_neighbor]))
                {
                    cot2 = dot(vec3, vec4)/cross(vec3, vec4).norm();
                    alphai = BasicMeasuring::triangleAngleBAC(neighbor_pts[i], center_pt, neighbor_pts[(i + 1)%n_neighbor]);
                }

                center_weight -= (cot1 + cot2)/sqrt_total_area;
                uniform_weight -= 1.0;
                meanvalue_weight -= (std::tan(alphai_1/2.0) + std::tan(alphai/2.0))/vec0.norm();

                if(vtx_idx_to_datapt_idx_map[neighbor_idx[i]] >= 0)
                {
                    triplets_L.push_back(Triplet_type(centerpt_idx, vtx_idx_to_datapt_idx_map[neighbor_idx[i]], (cot1 + cot2)/sqrt_total_area));
                    triplets_uniformL.push_back(Triplet_type(centerpt_idx, vtx_idx_to_datapt_idx_map[neighbor_idx[i]], 1.0));
                    triplets_meanvalueL.push_back(Triplet_type(centerpt_idx, vtx_idx_to_datapt_idx_map[neighbor_idx[i]], (std::tan(alphai_1/2.0) + std::tan(alphai/2.0))/vec0.norm()));
                }
                else
                {
                    if (laplaceType == 0)
                        matrix_a(centerpt_idx, vtx_idx_to_control_pt_idx_map[neighbor_idx[i]]) = (cot1 + cot2)/sqrt_total_area;
                    else
                    {
                        if (laplaceType == 3)
                            matrix_a(centerpt_idx, vtx_idx_to_control_pt_idx_map[neighbor_idx[i]]) = (std::tan(alphai_1/2.0) + std::tan(alphai/2.0))/vec0.norm();
                        else
                            matrix_a(centerpt_idx, vtx_idx_to_control_pt_idx_map[neighbor_idx[i]]) = 1.0;
                    }
                }
            }

            triplets_L.push_back(Triplet_type(centerpt_idx, centerpt_idx, center_weight));
            triplets_uniformL.push_back(Triplet_type(centerpt_idx, centerpt_idx, uniform_weight));
            triplets_meanvalueL.push_back(Triplet_type(centerpt_idx, centerpt_idx, meanvalue_weight));
        }
    }

    if (laplaceType == 0)
        matrix_L.setFromTriplets(triplets_L.begin(), triplets_L.end());
    else
    {
        if (laplaceType == 3)
            matrix_L.setFromTriplets(triplets_meanvalueL.begin(), triplets_meanvalueL.end());
        else
            matrix_L.setFromTriplets(triplets_uniformL.begin(), triplets_uniformL.end());
    }
}

void ConstrainedMeshPlugin::initialize_3D_fairness_energy_matrix()
{
    int vNumber = TetrahedralMesh_node_.rows();
    int eleNumber = TetrahedralMesh_ele_.rows();

    matrix_L.resize(vNumber, vNumber);
    typedef Eigen::Triplet<double> T;
    std::vector<T> triplets_K;
    for (int i = 0; i < eleNumber; ++i)
    {
        SparseMatrixXd matrixJ(3, 3), matrixJT(3, 3);
        Eigen::Matrix3d denseJ;
        std::vector<T> triplets_J;
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                denseJ(j, k) = TetrahedralMesh_node_(TetrahedralMesh_ele_(i, j), k) - TetrahedralMesh_node_(TetrahedralMesh_ele_(i, 3), k);
                triplets_J.push_back(T(j, k, TetrahedralMesh_node_(TetrahedralMesh_ele_(i, j), k) - TetrahedralMesh_node_(TetrahedralMesh_ele_(i, 3), k)));
            }
        }
        matrixJ.setFromTriplets(triplets_J.begin(), triplets_J.end());
        matrixJT = matrixJ.transpose();
        Eigen::MatrixXd matrixb, matrixE;
        matrixb.setZero(3, 4);
        matrixE.setZero(3, 4);
        matrixb(0, 0) = 1.0;
        matrixb(0, 3) = -1.0;
        matrixb(1, 1) = 1.0;
        matrixb(1, 3) = -1.0;
        matrixb(2, 2) = 1.0;
        matrixb(2, 3) = -1.0;

        Eigen::SimplicialLDLT<SparseMatrixXd> solver;
        solver.compute(matrixJT);

        for (int j = 0; j < 4; ++j)
            matrixE.col(j) = solver.solve(matrixb.col(j));

        Eigen::MatrixXd matrixKi = std::fabs(denseJ.determinant())*matrixE.transpose()*matrixE/6.0;
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                triplets_K.push_back(T(TetrahedralMesh_ele_(i, j), TetrahedralMesh_ele_(i, k), matrixKi(j, k)));
            }
        }
    }
    matrix_L.setFromTriplets(triplets_K.begin(), triplets_K.end());
}

void ConstrainedMeshPlugin::initialization_3D()
{
    point_data.clear();
    vtx_idx_to_control_pt_idx_map.clear();
    datapt_idx_to_vtx_idx_map.clear();
    controlpt_idx_to_vtx_idx_map.clear();
    vtx_idx_to_datapt_idx_map.clear();
    n_boundary_pt = 0;
    n_data_pt = 0;

    for(int i = 0; i < TetrahedralMesh_node_.rows(); ++i)
    {
        vtx_idx_to_datapt_idx_map.push_back(datapt_idx_to_vtx_idx_map.size());
        vtx_idx_to_control_pt_idx_map.push_back(-1);
        datapt_idx_to_vtx_idx_map.push_back(point_data.size());
        n_data_pt++;

        OMesh::Point cur_pt(TetrahedralMesh_node_(i, 0), TetrahedralMesh_node_(i, 1), TetrahedralMesh_node_(i, 2));
        point_data.push_back(cur_pt);
    }

    if (hasCage_)
    {
        VertexIterator v_it, v_end = cageObject_->vertexEnd();
        for(v_it = cageObject_->vertexBegin(); v_it != v_end; ++v_it)
        {
            vtx_idx_to_control_pt_idx_map.push_back(controlpt_idx_to_vtx_idx_map.size());
            vtx_idx_to_datapt_idx_map.push_back(-1);
            controlpt_idx_to_vtx_idx_map.push_back(point_data.size());
            n_boundary_pt++;
            point_data.push_back(v_it->getPosition());
        }
    }
}

void ConstrainedMeshPlugin::load_TetrahedralMesh()
{
    std::string nodeFile = QFileDialog::getOpenFileName(0, tr("(Open Tetrahedral Mesh file)")).toStdString();
    std::ifstream inFile;
    inFile.open(nodeFile.c_str());
    if (!inFile.is_open())
    {
        dolphinErr()<<"Can not open file!"<<endl;
        return;
    }

    int vNumber, fNumber, tNumber, index;
    int v0, v1, v2, v3;
    std::string symbol;
    double x, y, z;
    inFile>>symbol>>index;
    inFile>>symbol>>index>>symbol>>vNumber;
    TetrahedralMesh_node_.setZero(vNumber, 3);
    int iter = 0;
    while (iter < vNumber)
    {
        inFile>>x>>y>>z>>index;
        TetrahedralMesh_node_(iter, 0) = x;
        TetrahedralMesh_node_(iter, 1) = y;
        TetrahedralMesh_node_(iter, 2) = z;
        iter++;
    }

    inFile>>symbol>>fNumber;
    TetrahedralMesh_face_.setZero(fNumber, 3);
    iter = 0;
    while (iter < fNumber)
    {
        inFile>>v0>>v1>>v2>>index;
        TetrahedralMesh_face_(iter, 0) = v0 - 1;
        TetrahedralMesh_face_(iter, 1) = v1 - 1;
        TetrahedralMesh_face_(iter, 2) = v2 - 1;
        iter++;
    }

    inFile>>symbol>>tNumber;
    TetrahedralMesh_ele_.setZero(tNumber, 4);
    iter = 0;
    while (iter < tNumber)
    {
        inFile>>v0>>v1>>v2>>v3>>index;
        TetrahedralMesh_ele_(iter, 0) = v0 - 1;
        TetrahedralMesh_ele_(iter, 1) = v1 - 1;
        TetrahedralMesh_ele_(iter, 2) = v2 - 1;
        TetrahedralMesh_ele_(iter, 3) = v3 - 1;
        iter++;
    }
}

void ConstrainedMeshPlugin::set_SelectObject_as_Data()
{
    OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if(!meshNode){
        dolphinErr() << "No mesh selected" << std::endl;
        return;
    }
    meshNode_ = meshNode;
    pmesh_ = meshNode->getMesh();

    initial_data_positions_.clear();
    for(OMesh::VertexIter v_it = pmesh_->vertices_begin(); v_it != pmesh_->vertices_end(); ++v_it)
    {
        initial_data_positions_.push_back(pmesh_->point(v_it));
    }
}

void ConstrainedMeshPlugin::set_SelectObject_as_Cage()
{
    bool hasCurve = false;
    QList<Node*> selected;
    getScenegraph().getDescendants(selected, false);
    for(QList<Node*>::iterator it = selected.begin(); it != selected.end(); ++it)
    {
        if ((*it)->getType() == SPLINE_NODE || (*it)->getType() == EDGE_SET_NODE)
        {
            cageNode_ = qobject_cast<VertexBasedGeometryNode*>(*it);
            cageObject_ = cageNode_->getGeometry();
            hasCage_ = true;
            hasCurve = true;
            break;
        }
    }
    if (!hasCurve)
    {
        VertexBasedGeometryNode *vbgNode = getScenegraph().getFirstDescendant<VertexBasedGeometryNode*>(true);
        if (!vbgNode)
        {
            dolphinErr() << "No object selected" << std::endl;
            return;
        }
        cageObject_ = vbgNode->getGeometry();
        hasCage_ = true;
        cageNode_ = vbgNode;
    }

    initial_cage_positions_.clear();
    for (unsigned int i = 0; i < cageObject_->nPoints(); ++i)
    {
        initial_cage_positions_.push_back(cageObject_->getVertexPosition(i));
    }

    OpenMeshNode *meshNode = getScenegraph().getFirstDescendant<OpenMeshNode*>(true);
    if (!meshNode)
    {
        dolphinErr() << "No mesh selected" << std::endl;
        return;
    }
    cageMesh_ = meshNode->getMesh();
}

void ConstrainedMeshPlugin::initialize_P_and_C(int dim)
{
    P_mat.resize(dim, n_data_pt);
    for(int i = 0; i < n_data_pt; i++)
    {
        P_mat.col(i) = Eigen::Map<const Eigen::VectorXd>(point_data[datapt_idx_to_vtx_idx_map[i]].data(), dim);
    }

    C_mat.resize(dim, n_boundary_pt);
    for(int i = 0; i < n_boundary_pt; i++)
    {
        C_mat.col(i) = Eigen::Map<const Eigen::VectorXd>(point_data[controlpt_idx_to_vtx_idx_map[i]].data(), dim);
    }
}


//bailin
void ConstrainedMeshPlugin::ipopt_halfnorm_sbc_opt(int smoothness_position,
												   double lambda,
												   bool supplyHessian,
												   int init_type,
												   int dimension,
												   int laplaceType,
												   bool controlVariables,
												   bool nonnegative_sbc)
{
   initialization();

   initialize_P_and_C(dimension);

   initialize_fairness_energy_matrix(laplaceType);

   w = init_w;

   IpoptSBCParam param;
   param.hessian_approx = !supplyHessian;
   param.smoothness_bound = smoothness_bound;
   param.smoothness_hard_constraint = (smoothness_position == 1)?false:true;
   param.smoothness_weight= lambda;
   param.nonnegative_sbc = nonnegative_sbc;
   param.control_variables = controlVariables;

   // Create a new instance of your nlp
   //  (use a SmartPtr, not raw)
   SmartPtr<TNLP> mynlp = new IpoptHalfNormSBC(C_mat, P_mat, w,
matrix_L, matrix_a, param);

   // Create a new instance of IpoptApplication
   //  (use a SmartPtr, not raw)
   SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

   // Change some options
   //app->Options()->SetNumericValue("tol", opt()->stop_step);
   //app->Options()->SetNumericValue("acceptable_tol", opt()->stop_step * 10);
   //app->Options()->SetIntegerValue("max_iter", opt()->max_iterations);
   //app->Options()->SetNumericValue("acceptable_obj_change_tol", opt()->residual_change_ratio_stopvalue);
   app->Options()->SetIntegerValue("max_iter", 100000);
   app->Options()->SetStringValue("mu_strategy", "monotone");
   //app->Options()->SetStringValue("linear_solver", "mumps");
   app->Options()->SetStringValue("output_file", "ipopt.out");

   if (!supplyHessian)
       app->Options()->SetStringValue("hessian_approximation",
"limited-memory");

   app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
   //app->Options()->SetStringValue("derivative_test", "first-order");
   //app->Options()->SetStringValue("derivative_test_print_all", "yes");
   //app->Options()->SetNumericValue("derivative_test_tol", 1e-4);


   // Initialize the IpoptApplication and process the options
   ApplicationReturnStatus status = app->Initialize();
   if (status != Solve_Succeeded)
   {
       std::cout << "Error during initialization!\n" << std::endl;
       return;
   }

   // Ask Ipopt to solve the problem
   status = app->OptimizeTNLP(mynlp);

   if (status == Solve_Succeeded)
   {
       std::cout << "The problem solved!" << std::endl;

	   IpoptHalfNormSBC* sbcnlp = dynamic_cast<IpoptHalfNormSBC*>(GetRawPtr(mynlp));
	   w = sbcnlp->get_W();
       // Retrieve some statistics about the solve
       Index iter_count = app->Statistics()->IterationCount();
       std::cout << std::endl << std::endl << "*** The problem solved in " << iter_count << " iterations!" << std::endl;

       Number final_obj = app->Statistics()->FinalObjective();
       std::cout << std::endl << std::endl << "*** The final value of the objective function is " << final_obj << '.' << std::endl;

       std::cout << std::endl <<std::endl << "*** The final smoothness energy is " << pow((matrix_L*w + matrix_a).norm(), 2.0) << std::endl;
       std::cout << std::endl <<std::endl << "*** The smoothness bound is " << smoothness_bound << std::endl;

       double init_half_norm = 0, final_half_norm = 0;
       for (int i = 0; i < n_data_pt; ++i)
       {
           for (int j = 0; j < n_boundary_pt; ++j)
           {
               init_half_norm += std::sqrt(std::fabs(init_w(i, j)));
               final_half_norm += std::sqrt(std::fabs(w(i, j)));
           }
       }
       std::cout << std::endl <<std::endl << "*** the half norm of init value " << init_half_norm << std::endl;
       std::cout << std::endl <<std::endl << "*** the half norm of final value " << final_half_norm << std::endl;


	   string filename = "/Users/juyong/Works/SBC/Results/Lhalfmat-" + meshNode_->objectName().toStdString() + ".txt";
       std::ofstream ofile(filename.c_str());
       if (!ofile.is_open()){
           std::cerr << "Unable to create matrix file" << std::endl;
       }
       else
       {
           ofile<<w;
       }
       ofile.close();
   }
   else
   {
       std::cout << "The problem FAILED...." << std::endl;
   }
}

ConstrainedMeshPlugin::IpoptL0Solver::IpoptL0Solver(ConstrainedMeshPlugin* o_)
:o(o_){}

ConstrainedMeshPlugin::IpoptL0Solver::~IpoptL0Solver(){}

bool ConstrainedMeshPlugin::IpoptL0Solver::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                          Index& nnz_h_lag, IndexStyleEnum& index_style)
{
    return o->ipoptl0_get_nlp_info(n, m, nnz_jac_g, nnz_h_lag, index_style);
}

bool ConstrainedMeshPlugin::IpoptL0Solver::get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u)
{
    return o->ipoptl0_get_bounds_info(n, x_l, x_u, m, g_l, g_u);
}

bool ConstrainedMeshPlugin::IpoptL0Solver::get_starting_point(Index n, bool init_x, Number* x, bool init_z, Number* z_L, Number* z_U, Index m, bool init_lambda, Number* lambda)
{
    return o->ipoptl0_get_starting_point(n, init_x, x, init_z, z_L, z_U, m, init_lambda, lambda);
}

bool ConstrainedMeshPlugin::IpoptL0Solver::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    return o->ipoptl0_eval_f(n, x, new_x, obj_value);
}

bool ConstrainedMeshPlugin::IpoptL0Solver::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    return o->ipoptl0_eval_grad_f(n, x, new_x, grad_f);
}

bool ConstrainedMeshPlugin::IpoptL0Solver::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
    return o->ipoptl0_eval_g(n, x, new_x, m, g);
}

bool ConstrainedMeshPlugin::IpoptL0Solver::eval_jac_g(Index n, const Number* x, bool new_x, Index m, Index nele_jac, Index* iRow, Index *jCol, Number* values)
{
    return o->ipoptl0_eval_jac_g(n, x, new_x, m, nele_jac, iRow, jCol, values);
}

void ConstrainedMeshPlugin::IpoptL0Solver::finalize_solution(SolverReturn status,
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

    for (int i = 0; i < o->n_data_pt; ++i)
    {
        for (int j = 0; j < o->n_boundary_pt; ++j)
        {
            o->w(i, j) = x[i*o->n_boundary_pt + j];
        }
    }
}

bool ConstrainedMeshPlugin::ipoptl0_get_nlp_info(Index& n, Index& m, Index& nnz_jac_g, Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style)
{
    n = n_data_pt*n_boundary_pt;
    m = (1 + dim)*n_data_pt + 1;
    // in this example the Jacobian is dense and contains 8 nonzeros
	nnz_jac_g = (2 + dim)*n_data_pt*n_boundary_pt;
    // the Hessian is also dense and has 16 total nonzeros, but we
    // only need the lower left corner (since it is symmetric)
    nnz_h_lag = (1 + n)*n/2;
    // use the C style indexing (0-based)
    index_style = TNLP::C_STYLE;
    return true;
}

bool ConstrainedMeshPlugin::ipoptl0_get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u)
{
    // here, the n and m we gave IPOPT in get_nlp_info are passed back to us.
    // If desired, we could assert to make sure they are what we think they are.
    assert(n == n_data_pt*n_boundary_pt);
    assert(m == (1 + dim)*n_data_pt + 1);
    // the variables have lower bounds of 1
    for (Index i = 0; i < n; ++i)
    {
        x_l[i] = 0.0;
        x_u[i] = 1.0;
    }
    // the first constraint g1 has a lower bound of 25
    for (Index i = 0; i < n_data_pt; ++i)
    {
        g_l[i] = 1.0;
        g_u[i] = 1.0;
        for (Index j = 0; j < dim; ++j)
        {
            g_l[(j + 1)*n_data_pt + i] = point_data[datapt_idx_to_vtx_idx_map[i]][j];
            g_u[(j + 1)*n_data_pt + i] = point_data[datapt_idx_to_vtx_idx_map[i]][j];
        }
	}
    g_l[(1 + dim)*n_data_pt] = -2e19;
    g_u[(1 + dim)*n_data_pt] = smoothness_bound;
    return true;
}

bool ConstrainedMeshPlugin::ipoptl0_get_starting_point(Index n, bool init_x, Number* x,
                              bool init_z, Number* z_L, Number* z_U,
                              Index m, bool init_lambda,
                              Number* lambda)
{
    // Here, we assume we only have starting values for x, if you code
    // your own NLP, you can provide starting values for the dual variables
    // if you wish to use a warmstart option
    assert(init_x == true);
    assert(init_z == false);
    assert(init_lambda == false);
    // initialize to the given starting point
    Index index = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            x[index++] = init_w(i, j);
        }
    }
    return true;
}

bool ConstrainedMeshPlugin::ipoptl0_eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    assert(n == n_data_pt*n_boundary_pt);
    obj_value = 0;
    for (Index i = 0; i < n; ++i)
    {
        //approximation l_0 norm
        //obj_value += 1.0 - std::exp(-x[i]/(2.0*epsilon*epsilon));

        //approximation l_1 norm
        obj_value += std::sqrt(x[i]*x[i] + epsilon);
    }
    return true;
}

bool ConstrainedMeshPlugin::ipoptl0_eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    assert(n == n_data_pt*n_boundary_pt);
    for (Index i = 0; i < n; ++i)
    {
        //approximation l_0 norm
        //grad_f[i] = std::exp(-x[i]/(2.0*epsilon*epsilon))/(2.0*epsilon*epsilon);

        //approximation l_1 norm
        grad_f[i] = x[i]/(std::sqrt(x[i]*x[i] + epsilon));
    }
    return true;
}

bool ConstrainedMeshPlugin::ipoptl0_eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
    assert(n == n_data_pt*n_boundary_pt);
	assert(m == (1 + dim)*n_data_pt + 1);
	memset(g, 0, sizeof(Number)*((1 + dim)*n_data_pt + 1));
    for (Index i = 0; i < n_data_pt; ++i)
	{
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            temp_w(i, j) = x[i*n_boundary_pt + j];
            g[i] += x[i*n_boundary_pt + j];
            for (Index k = 0; k < dim; ++k)
            {
				g[n_data_pt*(k + 1) + i] += x[i*n_boundary_pt + j]*point_data[controlpt_idx_to_vtx_idx_map[j]][k];
            }
        }
    }

    g[n_data_pt*(1 + dim)] = pow((matrix_L*temp_w + matrix_a).norm(), 2.0);

    return true;
}

bool ConstrainedMeshPlugin::ipoptl0_eval_jac_g(Index n, const Number* x, bool new_x,
                      Index m, Index nele_jac, Index* iRow, Index *jCol,
                      Number* values)
{
    if (values == NULL)
    {
        // return the structure of the Jacobian
        // this particular Jacobian is dense
        Index index = 0;
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                iRow[index] = i;
                jCol[index] = i*n_boundary_pt + j;
                index++;
            }
        }
        for (Index k = 0; k < dim; ++k)
        {
            for (Index i = 0; i < n_data_pt; ++i)
            {
                for (Index j = 0; j < n_boundary_pt; ++j)
                {
                    iRow[index] = n_data_pt*(k + 1) + i;
                    jCol[index] = i*n_boundary_pt + j;
                    index++;
                }
            }
        }
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                iRow[index] = n_data_pt*(dim + 1);
                jCol[index] = i*n_boundary_pt + j;
                index++;
            }
        }
    }
    else
    {
        // return the values of the Jacobian of the constraints
        Index index = 0;
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                temp_w(i, j) = x[i*n_boundary_pt + j];
                values[index++] = 1.0;
            }
        }
        for (Index k = 0; k < dim; ++k)
        {
            for (Index i = 0; i < n_data_pt; ++i)
            {
                for (Index j = 0; j < n_boundary_pt; ++j)
                {
                    values[index++] = point_data[controlpt_idx_to_vtx_idx_map[j]][k];
                }
            }
        }
		temp_w = 2.0*matrix_Lt*(matrix_L*temp_w + matrix_a);
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                values[index++] = temp_w(i, j);
            }
        }
    }

    return true;
}

//half norm minimization
bool ConstrainedMeshPlugin::ipoptlhalf_get_nlp_info(Index& n, Index& m, Index& nnz_jac_g, Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style)
{
    n = n_data_pt*n_boundary_pt;
	if (controlVariables_)
        n += n_boundary_pt*dim;

    if (smoothness_position_ == 0)
    {
        m = (1 + dim)*n_data_pt + n_data_pt*n_boundary_pt;
        nnz_jac_g = (1 + dim)*n_data_pt*n_boundary_pt;
    }
    else
    {
        m = (1 + dim)*n_data_pt + n_data_pt*n_boundary_pt + 1;
        nnz_jac_g = (2 + dim)*n_data_pt*n_boundary_pt;
    }

    //superharmonic&subharmonic
    for (Index i = 0; i < n_data_pt; ++i)
    {
        nnz_jac_g += (matrix_Lt.col(i)).nonZeros()*n_boundary_pt;
    }
    //end of superharmonic&subharmonic

	if (controlVariables_)
		nnz_jac_g += dim*n_data_pt*n_boundary_pt;

    // we only need the lower left corner (since it is symmetric)
	nnz_h_lag = n_LTL_nonzeros + n_data_pt*n_boundary_pt;
	if (!nonnegativeConstraint_)
        nnz_h_lag += n_data_pt*n_boundary_pt;

    // use the C style indexing (0-based)
    index_style = TNLP::C_STYLE;
    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u)
{
    // here, the n and m we gave IPOPT in get_nlp_info are passed back to us.
	// If desired, we could assert to make sure they are what we think they are.
    for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        if (nonnegativeConstraint_)
        {
            x_l[i] = 0.0;
            x_u[i] = 1.0;
        }
        else
        {
            // without nonnegative constraint
            x_l[i] = -2e19;
            x_u[i] = 2e19;
        }
    }

	if (controlVariables_)
	{
        Index index = n_data_pt*n_boundary_pt;
        for (int i = index; i < index + dim*n_boundary_pt; ++i)
		{
			x_l[i] = -2e19;
			x_u[i] = 2e19;
		}
	}

    for (Index i = 0; i < n_data_pt; ++i)
    {
        g_l[i] = 1.0;
        g_u[i] = 1.0;
        for (Index j = 0; j < dim; ++j)
        {
            g_l[(j + 1)*n_data_pt + i] = P_mat(j, i);
            g_u[(j + 1)*n_data_pt + i] = P_mat(j, i);
        }
    }

    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            g_l[(1 + dim)*n_data_pt + i*n_boundary_pt + j] = Bound_low(i, j);
            g_u[(1 + dim)*n_data_pt + i*n_boundary_pt + j] = Bound_up(i, j);
        }
    }

    if (smoothness_position_ == 1)
    {
        Index index = (1 + dim)*n_data_pt + n_data_pt*n_boundary_pt;
		g_l[index] = -2e19;
		g_u[index] = smoothness_bound;
    }
    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_get_starting_point(Index n, bool init_x, Number* x,
                              bool init_z, Number* z_L, Number* z_U,
                              Index m, bool init_lambda,
                              Number* lambda)
{
    // Here, we assume we only have starting values for x, if you code
    // your own NLP, you can provide starting values for the dual variables
    // if you wish to use a warmstart option
    assert(init_x == true);
    assert(init_z == false);
    assert(init_lambda == false);
    // initialize to the given starting point
    Index index = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            x[index++] = wud(i, j);
        }
    }

	if (controlVariables_)
    {
		for (Index i = 0; i < n_boundary_pt; ++i)
		{
			for (Index j = 0; j < dim; ++j)
			{
				x[index++] = C_mat(j, i);
			}
		}
	}
    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    obj_value = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            temp_w(i, j) = x[i*n_boundary_pt + j];

            obj_value += weighted_D(i, j)*x[i*n_boundary_pt + j]*weighted_D(i, j)*x[i*n_boundary_pt + j];
        }
    }

    if (smoothness_position_ == 0)
        obj_value += dl_weight*pow((matrix_L*temp_w + matrix_a).norm(), 2.0);

	if (controlVariables_)
	{
        Index index = n_data_pt*n_boundary_pt;
		for (int i = 0; i < n_boundary_pt; ++i)
		{
			for (int j = 0; j < dim; ++j)
			{
				obj_value += control_weight_*pow(x[index + i*dim + j] - mean_cage_[j], 2.0);
			}
		}
	}
    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
	memset(grad_f, 0, sizeof(Number)*n);

    Index index = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            temp_w(i, j) = x[i*n_boundary_pt + j];
            grad_f[index++] = 2.0*weighted_D(i, j)*weighted_D(i, j)*x[i*n_boundary_pt + j];
        }
    }

    if (smoothness_position_ == 0)
    {
        temp_w = 2.0*dl_weight*(matrix_LTL*temp_w + matrix_LTa);
        index = 0;
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                grad_f[index++] += temp_w(i, j);
            }
        }
    }

	if (controlVariables_)
	{
        index = n_data_pt*n_boundary_pt;
		for (int i = 0; i < n_boundary_pt; ++i)
		{
			for (int j = 0; j < dim; ++j)
			{
                grad_f[index] = 2.0*control_weight_*(x[index] - mean_cage_[j]);
                index++;
			}
		}
	}
    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
	memset(g, 0, sizeof(Number)*m);

    Index index = n_data_pt*n_boundary_pt;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            temp_w(i, j) = x[i*n_boundary_pt + j];

            g[i] += x[i*n_boundary_pt + j];
            for (Index k = 0; k < dim; ++k)
			{
				if (controlVariables_)
				{
                    g[n_data_pt*(k + 1) + i] += x[i*n_boundary_pt + j]*x[index + j*dim + k];
				}
				else
				{
                    g[n_data_pt*(k + 1) + i] += x[i*n_boundary_pt + j]*C_mat(k, j);
				}
			}

            for (Index i = 0; i < n_data_pt; ++i)
            {
                for (Index j = 0; j < n_boundary_pt; ++j)
                {
                    g[(1 + dim)*n_data_pt + i*n_boundary_pt + j] += matrix_a(i, j);
                    for (SparseMatrixXd::InnerIterator it(matrix_Lt, i); it; ++it)
                    {
                        int row = it.row();
                        g[(1 + dim)*n_data_pt + i*n_boundary_pt + j] += it.value()*x[row*n_boundary_pt + j];
                    }
                }
            }
        }
    }

    if (smoothness_position_ == 1)
    {
        g[(1 + dim)*n_data_pt + n_data_pt*n_boundary_pt] = pow((matrix_L*temp_w + matrix_a).norm(), 2.0);
	}

    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_eval_jac_g(Index n,
												  const Number* x,
												  bool new_x,
												  Index m,
												  Index nele_jac,
												  Index* iRow,
												  Index *jCol,
												  Number* values)
{
    if (values == NULL)
    {
        // return the structure of the Jacobian
        Index index = 0;
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                iRow[index] = i;
                jCol[index] = index;
                index++;
            }
        }
        for (Index k = 0; k < dim; ++k)
        {
            for (Index i = 0; i < n_data_pt; ++i)
            {
                for (Index j = 0; j < n_boundary_pt; ++j)
                {
                    iRow[index] = n_data_pt*(k + 1) + i;
                    jCol[index++] = i*n_boundary_pt + j;
                }
            }
        }
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                for (SparseMatrixXd::InnerIterator it(matrix_Lt, i); it; ++it)
                {
                    iRow[index] = (dim + 1)*n_data_pt + i*n_boundary_pt + j;
                    jCol[index++] = it.row()*n_boundary_pt + j;
                }
            }
        }

        if (smoothness_position_ == 1)
        {
            Index r_index = (1 + dim)*n_data_pt + n_data_pt*n_boundary_pt;
            for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
			{
				iRow[index] = r_index;
				jCol[index++] = i;
			}
        }

		if (controlVariables_)
        {
            Index start_i = n_data_pt*n_boundary_pt;
			for (Index k = 0; k < dim; ++k)
			{
				for (Index i = 0; i < n_data_pt; ++i)
				{
					for (Index j = 0; j < n_boundary_pt; ++j)
					{
						iRow[index] = n_data_pt*(k + 1) + i;
                        jCol[index++] = start_i + j*dim + k;
					}
				}
			}
		}
    }
    else
    {
		// return the values of the Jacobian of the constraints
        Index index = 0;
		if (controlVariables_)
        {
			for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
			{
				values[index++] = 1.0;
			}

            Index start_i = n_data_pt*n_boundary_pt;
			for (int k = 0; k < dim; ++k)
			{
				for (int i = 0; i < n_data_pt; ++i)
				{
					for (int j = 0; j < n_boundary_pt; ++j)
					{
                        values[index++] = x[start_i + j*dim + k];
					}
				}
			}
		}
		else
		{
			memcpy(values, lhalf_jac_g, (1 + dim)*n_data_pt*n_boundary_pt*sizeof(Number));
        }

        index = (1 + dim)*n_data_pt*n_boundary_pt;
        //superharmonic&subharmonic constraint
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                for (SparseMatrixXd::InnerIterator it(matrix_Lt, i); it; ++it)
                {
                    values[index++] = it.value();
                }
            }
        }
        //end of superharmonic&subharmonic constraint

        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                temp_w(i, j) = x[i*n_boundary_pt + j];
            }
        }

        if (smoothness_position_ == 1)
        {
            temp_w = 2.0*(matrix_LTL*temp_w + matrix_LTa);
            for (Index i = 0; i < n_data_pt; ++i)
            {
                for (Index j = 0; j < n_boundary_pt; ++j)
                {
                    values[index++] = temp_w(i, j);
                }
            }
        }

		if (controlVariables_)
		{
			for (Index k = 0; k < dim; ++k)
			{
				for (Index i = 0; i < n_data_pt; ++i)
				{
					for (Index j = 0; j < n_boundary_pt; ++j)
					{
						values[index++] = x[i*n_boundary_pt + j];
					}
				}
			}
		}
    }

    return true;
}

bool ConstrainedMeshPlugin::ipoptlhalf_eval_h(Index n, const Number *x, bool new_x, Number obj_factor, Index m, const Number *lambda, bool new_lambda, Index nele_hess, Index *iRow, Index *jCol, Number *values)
{
    if (values == NULL)
    {
        // return the structure. This is a symmetric matrix, fill the lower left
        // triangle only.
        Index idx = 0;
        for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
        {
            Index row = i/n_boundary_pt;
            Index col = i%n_boundary_pt;
            for (SparseMatrixXd::InnerIterator it(matrix_LTL, row); it; ++it)
            {
                int j = it.row();
                if (j*n_boundary_pt + col <= i)
                {
                    iRow[idx] = i;
                    jCol[idx] = j*n_boundary_pt + col;
                    idx++;
                }
            }
        }
        for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
        {
            iRow[idx] = n_data_pt*n_boundary_pt + i;
            jCol[idx] = n_data_pt*n_boundary_pt + i;
            idx++;
        }
        assert(idx == nele_hess);
    }
    else
    {
        // return the values. This is a symmetric matrix, fill the lower left
        // triangle only
        // fill the objective portion
        memset(values, 0, sizeof(Number)*nele_hess);

        Index idx = 0;
        Eigen::VectorXd vTemp = 2.0*obj_factor*dl_weight*LTL_hessian_values;
        if (smoothness_position_ == 0)
        {
            for (Index i = 0; i < n_LTL_nonzeros; ++i)
            {
                values[i] = vTemp[i];
            }
        }
        else
        {
            for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
            {
                Index row = i/n_boundary_pt;
                Index col = i%n_boundary_pt;
                for (SparseMatrixXd::InnerIterator it(matrix_LTL, row); it; ++it)
                {
                    int j = it.row();
                    if (j*n_boundary_pt + col <= i)
                    {
                        values[idx++] = 2.0*lambda[(1 + dim)*n_data_pt + n_data_pt*n_boundary_pt]*it.value();
                    }
                }
            }
        }
        idx = n_LTL_nonzeros;
        // add the portion for the constraint: w_i^2 = x_i^4
        for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
        {
            values[diagonalIndex[i]] = 2.0*lambda[(1 + dim)*n_data_pt + i];
            values[idx++] = -12.0*lambda[(1 + dim)*n_data_pt + i]*pow(x[n_data_pt*n_boundary_pt + i], 2.0);
        }
    }

    return true;
}

//smooth optimization
bool ConstrainedMeshPlugin::ipoptsmooth_get_nlp_info(Index& n, Index& m, Index& nnz_jac_g, Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style)
{
    n = n_data_pt*n_boundary_pt;

    m = (1 + dim)*n_data_pt;
    nnz_jac_g = (1 + dim)*n_data_pt*n_boundary_pt;

    // we only need the lower left corner (since it is symmetric)
    nnz_h_lag = 0;

    // use the C style indexing (0-based)
    index_style = TNLP::C_STYLE;
    return true;
}

bool ConstrainedMeshPlugin::ipoptsmooth_get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u)
{
    // here, the n and m we gave IPOPT in get_nlp_info are passed back to us.
    // If desired, we could assert to make sure they are what we think they are.
    for (Index i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        if (nonnegativeConstraint_)
        {
            x_l[i] = 0.0;
            x_u[i] = 1.0;
        }
        else
        {
            x_l[i] = -2e19;
            x_u[i] = 2e19;
        }
    }

    for (size_t i = 0; i < control_data_correspondence_.size(); ++i)
    {
        int idx = control_data_correspondence_[i];
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            if (j != i)
            {
                x_l[idx*n_boundary_pt + j] = 0;
                x_u[idx*n_boundary_pt + j] = 0;
            }
            else
            {
                x_l[idx*n_boundary_pt + j] = 1.0;
                x_u[idx*n_boundary_pt + j] = 1.0;
            }
        }
    }

    if (meshless_parameterization_)
    {
        for (int i = 0; i < n_data_pt; ++i)
        {
            x_l[i*n_data_pt + i] = 0;
            x_u[i*n_data_pt + i] = 0;
        }
    }

    for (Index i = 0; i < n_data_pt; ++i)
    {
        g_l[i] = 1.0;
        g_u[i] = 1.0;
        for (Index j = 0; j < dim; ++j)
        {
            g_l[(j + 1)*n_data_pt + i] = point_data[datapt_idx_to_vtx_idx_map[i]][j];
            g_u[(j + 1)*n_data_pt + i] = point_data[datapt_idx_to_vtx_idx_map[i]][j];
        }
    }

    return true;
}

bool ConstrainedMeshPlugin::ipoptsmooth_get_starting_point(Index n, bool init_x, Number* x,
                              bool init_z, Number* z_L, Number* z_U,
                              Index m, bool init_lambda,
                              Number* lambda)
{
    // Here, we assume we only have starting values for x, if you code
    // your own NLP, you can provide starting values for the dual variables
    // if you wish to use a warmstart option
    assert(init_x == true);
    assert(init_z == false);
    assert(init_lambda == false);
    // initialize to the given starting point
    memset(x, 0, sizeof(Number)*n_data_pt*n_boundary_pt);
    for (Index i = 0; i < n_data_pt; ++i)
    {
        x[i*n_boundary_pt + i%n_boundary_pt] = 1.0;
    }

    return true;
}

bool ConstrainedMeshPlugin::ipoptsmooth_eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    obj_value = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            temp_w(i, j) = x[i*n_boundary_pt + j];
        }
    }

    // to test ((w_i^j)^2 + \epsilon^2)^{0.25}
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            obj_value += pow(x[i*n_boundary_pt + j]*x[i*n_boundary_pt + j] + 1e-4, 0.25);
        }
    }
    // end of test

    obj_value += dl_weight*pow((matrix_L*temp_w + matrix_a).norm(), 2.0);

    return true;
}

bool ConstrainedMeshPlugin::ipoptsmooth_eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    memset(grad_f, 0, sizeof(Number)*n);

    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            temp_w(i, j) = x[i*n_boundary_pt + j];
        }
    }

    temp_w = 2.0*dl_weight*(matrix_LTL*temp_w + matrix_LTa);

    Index index = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            grad_f[index++] += temp_w(i, j);
        }
    }

    // to test ((w_i^j)^2 + \epsilon^2)^{0.25}
    index = 0;
    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            grad_f[index++] += 0.5*pow(x[i*n_boundary_pt + j]*x[i*n_boundary_pt + j] + 1e-4, -0.75)*x[i*n_boundary_pt + j];
        }
    }
    // end of test

    return true;
}

bool ConstrainedMeshPlugin::ipoptsmooth_eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
    memset(g, 0, sizeof(Number)*m);

    for (Index i = 0; i < n_data_pt; ++i)
    {
        for (Index j = 0; j < n_boundary_pt; ++j)
        {
            g[i] += x[i*n_boundary_pt + j];
            for (Index k = 0; k < dim; ++k)
            {
                g[n_data_pt*(k + 1) + i] += x[i*n_boundary_pt + j]*point_data[controlpt_idx_to_vtx_idx_map[j]][k];
            }
        }
    }

    return true;
}

bool ConstrainedMeshPlugin::ipoptsmooth_eval_jac_g(Index n,
                                                  const Number* x,
                                                  bool new_x,
                                                  Index m,
                                                  Index nele_jac,
                                                  Index* iRow,
                                                  Index *jCol,
                                                  Number* values)
{
    if (values == NULL)
    {
        // return the structure of the Jacobian
        // this particular Jacobian is dense
        Index index = 0;
        for (Index i = 0; i < n_data_pt; ++i)
        {
            for (Index j = 0; j < n_boundary_pt; ++j)
            {
                iRow[index] = i;
                jCol[index] = index;
                index++;
            }
        }
        for (Index k = 0; k < dim; ++k)
        {
            for (Index i = 0; i < n_data_pt; ++i)
            {
                for (Index j = 0; j < n_boundary_pt; ++j)
                {
                    iRow[index] = n_data_pt*(k + 1) + i;
                    jCol[index++] = i*n_boundary_pt + j;
                }
            }
        }
    }
    else
    {
        // return the values of the Jacobian of the constraints
        memcpy(values, lhalf_jac_g, (1 + dim)*n_data_pt*n_boundary_pt*sizeof(Number));
    }

    return true;
}

//l0 norm minimization
void ConstrainedMeshPlugin::ipoptl0_solve(int dimension,
                                          int laplaceType,
                                          bool nonnegativeConstraint)
{
    initialization();

    initialize_fairness_energy_matrix(laplaceType);

    nonnegativeConstraint_ = nonnegativeConstraint;

	matrix_Lt = matrix_L.transpose();
	temp_w.setZero(n_data_pt, n_boundary_pt);
    epsilon = 1.0e-6;
    dim = dimension;
    w.setZero(n_data_pt, n_boundary_pt);
	//end of initialization

	// Create a new instance of your nlp
	//  (use a SmartPtr, not raw)
    SmartPtr<TNLP> mynlp = new IpoptL0Solver(this);

	// Create a new instance of IpoptApplication
	//  (use a SmartPtr, not raw)
	SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

	// Change some options
	//app->Options()->SetNumericValue("tol", opt()->stop_step);
	//app->Options()->SetNumericValue("acceptable_tol", opt()->stop_step * 10);
	//app->Options()->SetIntegerValue("max_iter", opt()->max_iterations);
	//app->Options()->SetNumericValue("acceptable_obj_change_tol", opt()->residual_change_ratio_stopvalue);
    app->Options()->SetIntegerValue("max_iter", 100000);
    app->Options()->SetStringValue("mu_strategy", "monotone");
	//app->Options()->SetStringValue("linear_solver", "mumps");
	app->Options()->SetStringValue("output_file", "ipopt.out");
	app->Options()->SetStringValue("hessian_approximation", "limited-memory");
	app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
    //app->Options()->SetStringValue("derivative_test", "first-order");
	//app->Options()->SetStringValue("derivative_test_print_all", "yes");
    //app->Options()->SetNumericValue("derivative_test_tol", 1e-4);


	// Initialize the IpoptApplication and process the options
	ApplicationReturnStatus status = app->Initialize();
    if (status != Solve_Succeeded)
    {
		std::cout << "Error during initialization!\n" << std::endl;
		return;
	}

	// Ask Ipopt to solve the problem
	status = app->OptimizeTNLP(mynlp);

	if (status == Solve_Succeeded)
	{
		std::cout << "The problem solved!" << std::endl;

		// Retrieve some statistics about the solve
		Index iter_count = app->Statistics()->IterationCount();
		std::cout << std::endl << std::endl << "*** The problem solved in " << iter_count << " iterations!" << std::endl;

		Number final_obj = app->Statistics()->FinalObjective();
		std::cout << std::endl << std::endl << "*** The final value of the objective function is " << final_obj << '.' << std::endl;

        std::cout << std::endl <<std::endl << "*** The final smoothness energy is " << pow((matrix_L*w + matrix_a).norm(), 2.0) << std::endl;
        std::cout << std::endl <<std::endl << "*** The smoothness bound is " << smoothness_bound << std::endl;

        double init_half_norm = 0, final_half_norm = 0;
        for (int i = 0; i < n_data_pt; ++i)
        {
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                init_half_norm += std::sqrt(std::fabs(init_w(i, j)));
                final_half_norm += std::sqrt(std::fabs(w(i, j)));
            }
        }
        std::cout << std::endl <<std::endl << "*** the half norm of init value " << init_half_norm << std::endl;
        std::cout << std::endl <<std::endl << "*** the half norm of final value " << final_half_norm << std::endl;
	}
	else
	{
		std::cout << "The problem FAILED...." << std::endl;
    }
}


static bool fabs_greater(double elem1, double elem2)
{
    return fabs(elem1) > fabs(elem2);
}

//juyong
void ConstrainedMeshPlugin::ipoptlhalf_solve(int smoothness_position,
                                             double lambda,
                                             bool supplyHessian,
                                             int init_type,
                                             int dimension,
                                             int laplaceType,
											 bool controlVariables,
											 double controlWeight,
											 bool nonnegativeConstraint,
											 double tol,
                                             double dual_inf_tol,
                                             bool meshlessparameterization,
                                             double sparsity)
{
    initialization();

    original_positions_.clear();
    for (size_t i = 0; i < point_data.size(); ++i)
    {
        original_positions_.push_back(point_data[i]);
    }

	initialize_P_and_C(dimension);
    mean_cage_ = Eigen::Vector3d(0.0, 0.0, 0.0);
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < n_boundary_pt; ++j)
		{
			mean_cage_[i] += C_mat(i, j);
		}
	}
	mean_cage_ /= double(n_boundary_pt);

	if (laplaceType == 2)
		initialize_fairness_energy_matrix_keenan();
	else
		initialize_fairness_energy_matrix(laplaceType);

	controlVariables_ = controlVariables;
	control_weight_ = controlWeight;
    nonnegativeConstraint_ = nonnegativeConstraint;
    meshless_parameterization_ = meshlessparameterization;

    dim = dimension;
    dl_weight = lambda;

    if (w.rows() == 0)
    {
        w.setZero(n_data_pt, n_boundary_pt);

        switch (init_type)
        {
        case 0:
            w = init_w;
            break;
        case 2:
            w = meanw;
            break;
        case 3:
            w = harmonicw;
            break;
        case 4:
            w = boundedBiharmonicW;
            break;
        case 5:
            w = greenw;
            break;
        default:
            break;
        }
    }

    //begin
    //assign barycentric coordinate to the original mesh
    QList<Node*> selected;
    getScenegraph().getDescendants(selected, false);
    std::tr1::shared_ptr<OMesh> originalMesh;
    for(QList<Node*>::iterator it = selected.begin(); it != selected.end(); ++it)
    {
        if ((*it)->getType() == OPEN_MESH_NODE && (*it) != meshNode_)
        {
            (*it)->setSelected(true, false);
            originalMesh = qobject_cast<OpenMeshNode*>(*it)->getMesh();
            break;
        }
    }
    Eigen::MatrixXd final_init_w(originalMesh->n_vertices(), n_boundary_pt);
    Eigen::MatrixXd final_w(originalMesh->n_vertices(), n_boundary_pt);
    utilities::NearestTriangleSearch nts;
    nts.initializeKDTreeBasedSearchStructure(pmesh_.get(), 12, 30);
    std::vector<BarycentricCoordinates> v_bc(originalMesh->n_vertices());
    std::vector<OMesh::FaceHandle> v_fh(originalMesh->n_vertices());
    for (OMesh::VertexIter vIt = originalMesh->vertices_begin(); vIt != originalMesh->vertices_end(); ++vIt)
    {
        Point p = originalMesh->point(vIt.handle());
        OMesh::FaceHandle fh;
        nts.computeClosestTriangleOfPoint(p, pmesh_.get(), fh);
        Point projectedPoint;
        BarycentricCoordinates bc;
        BasicMeasuring::squaredDistancePointToTriangle(p, pmesh_.get(), fh, projectedPoint, bc);
        v_bc[vIt.handle().idx()] = bc;
        v_fh[vIt.handle().idx()] = fh;

        OMesh::ConstFaceVertexIter fvI = pmesh_->cfv_iter(fh);
        int v0 = fvI.handle().idx(); ++fvI;
        int v1 = fvI.handle().idx(); ++fvI;
        int v2 = fvI.handle().idx();
        final_init_w.row(vIt.handle().idx()) = bc.u_*init_w.row(v0) + bc.v_*init_w.row(v1) + bc.w_*init_w.row(v2);
    }

    init_w = final_init_w;
	string filename = "/Users/juyong/Works/SBC/Results/smooth-mat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        outfile<<init_w;
    }
    outfile.close();

    std::vector<int> aData, lData;
    std::vector<bool> identical(n_data_pt, false);
    for (int i = 0; i < n_boundary_pt; ++i)
    {
        int nSub = cageSegments[i].size();
        assert(nSub >= 2);
        double dt = 1.0/(nSub - 1.0);
        for (int j = 0; j < nSub - 1; ++j)
        {
            Eigen::VectorXd coor(2);
            coor(0) = (cageSegments[i][j]->getCoords())[0];
            coor(1) = (cageSegments[i][j]->getCoords())[1];

            double d_min = std::numeric_limits<int>::max();
            int index_min = -1;
            for (int k = 0; k < n_data_pt; ++k)
            {
                double d = (coor - P_mat.col(k)).norm();
                if (d < d_min)
                {
                    d_min = d;
                    index_min = k;
                }
            }
            aData.push_back(index_min);
            identical[index_min] = true;
            w.row(index_min).setZero();
            w(index_min, i) = 1.0 - dt*j;
            w(index_min, (i + 1)%n_boundary_pt) = dt*j;
        }
    }

    for (int i = 0; i < n_data_pt; ++i)
    {
        if (!identical[i])
        {
            lData.push_back(i);
        }
    }

    //begin replace
    SparseMatrixXd l1_temp(n_data_pt, aData.size());
    SparseMatrixXd l1(lData.size(), aData.size());
    Eigen::MatrixXd wd(aData.size(), n_boundary_pt);
    for (size_t i = 0; i < aData.size(); ++i)
    {
        l1_temp.col(i) = matrix_L.col(aData[i]);
        wd.row(i) = w.row(aData[i]);
    }
    SparseMatrixXd l1_temp_t = l1_temp.transpose();
    SparseMatrixXd l1_t(aData.size(), lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        l1_t.col(i) = l1_temp_t.col(lData[i]);
    }
    l1 = l1_t.transpose();
    Eigen::MatrixXd a_ = l1*wd;

    SparseMatrixXd L_temp(n_data_pt, lData.size());
    SparseMatrixXd L_(lData.size(), lData.size());
    Eigen::MatrixXd data_points_(dimension, lData.size());
    wud.resize(lData.size(), n_boundary_pt);
    weighted_D.resize(lData.size(), n_boundary_pt);
    std::vector<double> wud_vector(lData.size()*n_boundary_pt);
    for (size_t i = 0; i < lData.size(); ++i)
    {
        wud.row(i) = w.row(lData[i]);
        L_temp.col(i) = matrix_L.col(lData[i]);
        data_points_.col(i) = P_mat.col(lData[i]);
    }
    SparseMatrixXd L_temp_t = L_temp.transpose();
    SparseMatrixXd L_t(lData.size(), lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        L_t.col(i) = L_temp_t.col(lData[i]);
    }
    L_ = L_t.transpose();
    //end replace
    //end

    n_data_pt = lData.size();
    temp_w.setZero(n_data_pt, n_boundary_pt);
    lhalf_jac_g = new Number[(1 + dim)*n_data_pt*n_boundary_pt];
    int index = 0;
	for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
	{
		lhalf_jac_g[index++] = 1.0;
    }
    for (int k = 0; k < dim; ++k)
    {
        for (int i = 0; i < n_data_pt; ++i)
        {
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                lhalf_jac_g[index++] = C_mat(k, j);
            }
        }
    }

    matrix_L = L_;
    matrix_Lt = L_.transpose();
    matrix_a = a_;
    matrix_LTL = matrix_Lt*matrix_L;
    matrix_LTa = matrix_Lt*matrix_a;
    smoothness_bound = 1.2*pow((matrix_L*wud + matrix_a).norm(), 2.0);

    int idx = 0;
    for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        int row = i/n_boundary_pt;
        int col = i%n_boundary_pt;
        //as sparse matrix is column-based, actually, it visits the rowth-column datas
        //however, LTL is symmetric
        for (SparseMatrixXd::InnerIterator it(matrix_LTL, row); it; ++it)
        {
            int j = it.row();
            if (j*n_boundary_pt + col <= i)
            {
                idx++;
            }
        }
    }
    n_LTL_nonzeros = idx;

    LTL_hessian_values.resize(n_LTL_nonzeros);
    idx = 0;
    for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        int row = i/n_boundary_pt;
        int col = i%n_boundary_pt;
        //as sparse matrix is column-based, actually, it visits the rowth-column datas
        //however, LTL is symmetric
        for (SparseMatrixXd::InnerIterator it(matrix_LTL, row); it; ++it)
        {
            int j = it.row();
            if (j*n_boundary_pt + col <= i)
            {
                if (j*n_boundary_pt + col == i)
                    diagonalIndex.push_back(idx);

                LTL_hessian_values[idx++] = it.value();
            }
        }
    }

    switch (smoothness_position)
    {
    case 0:
        smoothness_position_ = 1;
        break;
    case 1:
        smoothness_position_ = 0;
        break;
    default:
        smoothness_position_ = 0;
        break;
    }
    //end of initialization

    // Create a new instance of your nlp
    //  (use a SmartPtr, not raw)
    SmartPtr<TNLP> mynlp = new IpoptLhalfSolver(this);

    // Create a new instance of IpoptApplication
    //  (use a SmartPtr, not raw)
    SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

	// Change some options
    //app->Options()->SetNumericValue("tol", opt()->stop_step);
    //app->Options()->SetNumericValue("acceptable_tol", opt()->stop_step * 10);
    //app->Options()->SetIntegerValue("max_iter", opt()->max_iterations);
	//app->Options()->SetNumericValue("acceptable_obj_change_tol", opt()->residual_change_ratio_stopvalue);
    app->Options()->SetIntegerValue("max_iter", 100000);
    app->Options()->SetIntegerValue("print_level", 5);
    //app->Options()->SetStringValue("mu_strategy", "adaptive");
    app->Options()->SetStringValue("output_file", "ipopt.out");

    if (!supplyHessian)
        app->Options()->SetStringValue("hessian_approximation", "limited-memory");

    //app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
    //app->Options()->SetStringValue("derivative_test", "first-order");
    //app->Options()->SetStringValue("derivative_test_print_all", "yes");
	//app->Options()->SetNumericValue("derivative_test_tol", 1e-4);

	//added by juyong
	app->Options()->SetStringValue("nlp_scaling_method", "equilibration-based");
	//app->Options()->SetStringValue("print_options_documentation", "yes");
	app->Options()->SetNumericValue("tol", tol);
	app->Options()->SetNumericValue("dual_inf_tol", dual_inf_tol);
    app->Options()->SetStringValue("mu_strategy", "adaptive");
    app->Options()->SetStringValue("start_with_resto", "yes");
    app->Options()->SetStringValue("linear_solver", "ma57");
    app->Options()->SetStringValue("hessian_constant", "yes");
    app->Options()->SetStringValue("linear_scaling_on_demand", "yes");
    app->Options()->SetStringValue("linear_system_scaling", "mc19");

    Bound_low.resize(n_data_pt, n_boundary_pt);
    Bound_up.resize(n_data_pt, n_boundary_pt);
    Bound_low = matrix_L*wud + matrix_a;
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            double bound = fabs(Bound_low(i, j));
            Bound_low(i, j) = -1.2*bound;
            Bound_up(i, j) = 1.2*bound;
        }
    }

    int sparse_index = lData.size()*n_boundary_pt*sparsity;
    Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], lData.size(), n_boundary_pt) = wud;
    std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);
    double epsilon = wud_vector[sparse_index];

    //compute sparsity energy
    double whalfnorm = 0;
    for (int i = 0; i < wud.rows()*wud.cols(); ++i)
    {
        whalfnorm += sqrt(fabs(wud(i)));
    }

    std::cout<<"Initial epsilon: "<<epsilon<<std::endl;
    std::cout<<"initial half norm: "<<whalfnorm<<std::endl;
    std::cout<<"initial w smoothness: "<<(matrix_L*wud + matrix_a).squaredNorm()<<std::endl;
    std::cout<<"initial ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;
    //end of computing sparsity energy

    int iter = 0;
    while (fabs(epsilon) > 1.0e-4 && iter < 200)
    {
        iter++;
        std::cout<<"The "<<iter<<"-th iteration:"<<std::endl;

        for (int i = 0; i < wud.rows(); ++i)
        {
            for (int j = 0; j < wud.cols(); ++j)
            {
                weighted_D(i, j) = 1.0/std::sqrt(epsilon*epsilon + wud(i, j)*wud(i, j));
            }
        }

        // Initialize the IpoptApplication and process the options
        ApplicationReturnStatus status = app->Initialize();
        if (status != Solve_Succeeded)
        {
            std::cout << "Error during initialization!\n" << std::endl;
            return;
        }

        // Ask Ipopt to solve the problem
        status = app->OptimizeTNLP(mynlp);

        Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], lData.size(), n_boundary_pt) = wud;

        std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);

        epsilon = std::min(epsilon, wud_vector[sparse_index]);

        //compute sparsity energy
        whalfnorm = 0;
        for (int i = 0; i < wud.rows(); ++i)
        {
            for (int j = 0; j < wud.cols(); ++j)
            {
                whalfnorm += sqrt(fabs(wud(i, j)));
            }
        }
        //end of computing sparsity energy

        //save current result
        for (size_t i = 0; i < lData.size(); ++i)
        {
            w.row(lData[i]) = wud.row(i);
        }

        std::cout<<iter<<"-th iteration:"<<std::endl;
        std::cout<<"Current epsilon: "<<epsilon<<std::endl;
        std::cout<<"half norm: "<<whalfnorm<<std::endl;
        std::cout<<"data w smoothness: "<<(L_*wud + a_).squaredNorm()<<std::endl;
        std::cout<<"||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;

        for (size_t vi = 0; vi < originalMesh->n_vertices(); ++vi)
        {
            BarycentricCoordinates bc = v_bc[vi];
            OMesh::ConstFaceVertexIter fvI = pmesh_->cfv_iter(v_fh[vi]);
            int v0 = fvI.handle().idx(); ++fvI;
            int v1 = fvI.handle().idx(); ++fvI;
            int v2 = fvI.handle().idx();
            final_w.row(vi) = bc.u_*w.row(v0) + bc.v_*w.row(v1) + bc.w_*w.row(v2);
        }

		string filename = "/Users/juyong/Works/SBC/Results/ReWeighted-L2-mat-" + meshNode_->objectName().toStdString() + boost::lexical_cast<string>(iter) + ".txt";
        std::ofstream outfile(filename.c_str());
        if (!outfile.is_open())
        {
            std::cerr << "Unable to create matrix file" << std::endl;
        }
        else
        {
            outfile<<final_w;
        }
        outfile.close();
        //end of saving current result
    }

    w.resize(n_data_pt, n_boundary_pt);
    w = final_w;
    meshNode_->setVisible(false, false);
    meshNode_->setSelected(false, false);
    set_SelectObject_as_Data();

    if (controlVariables_)
    {
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            cageObject_->setVertexPosition(i, Point(optimized_C_mat(i, 0), optimized_C_mat(i, 1), optimized_C_mat(i, 2)));
        }
        cageNode_->setGeometryChanged();
    }

    // Retrieve some statistics about the solve
    Index iter_count = app->Statistics()->IterationCount();
    std::cout << std::endl << std::endl << "*** The problem solved in " << iter_count << " iterations!" << std::endl;

    Number final_obj = app->Statistics()->FinalObjective();
    std::cout << std::endl << std::endl << "*** The final value of the objective function is " << final_obj << '.' << std::endl;

    std::cout<<std::endl<<"Constraint violation: "<<(w*C_mat.transpose() - P_mat.transpose()).norm()<<std::endl;

    Eigen::MatrixXd matrix_ones, m_ones;
    matrix_ones.setOnes(n_boundary_pt, 1);
    m_ones.setOnes(n_data_pt, 1);
    std::cout<<std::endl<<"1 norm: "<<(w*matrix_ones - m_ones).norm()<<endl;

    std::cout << std::endl <<std::endl << "*** The final smoothness energy is " << pow((matrix_L*wud + matrix_a).norm(), 2.0) << std::endl;
    std::cout << std::endl <<std::endl << "*** The smoothness bound is " << smoothness_bound << std::endl;

    if (lhalf_jac_g)
    {
        delete[] lhalf_jac_g;
        lhalf_jac_g = NULL;
    }
}

void ConstrainedMeshPlugin::ipoptsmooth_solve(int dimension,
                                              int laplaceType,
                                              bool nonnegativeConstraint,
                                              bool meshlessparameterization,
                                              double laplacian_bound_min_ratio,
                                              double tol,
                                              double dual_inf_tol,
                                              double lambda)
{
    initialization();

    if (laplaceType == 2)
        initialize_fairness_energy_matrix_keenan();
    else
        initialize_fairness_energy_matrix(laplaceType);

    nonnegativeConstraint_ = nonnegativeConstraint;
    meshless_parameterization_ = meshlessparameterization;
    temp_w.setZero(n_data_pt, n_boundary_pt);

    dim = dimension;
    dl_weight = lambda;

    if (init_w.rows() == 0)
    {
        init_w.setZero(n_data_pt, n_boundary_pt);
    }

    lhalf_jac_g = new Number[(1 + dim)*n_data_pt*n_boundary_pt];
    int index = 0;
    for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        lhalf_jac_g[index++] = 1.0;
    }
    for (int k = 0; k < dim; ++k)
    {
        for (int i = 0; i < n_data_pt; ++i)
        {
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                lhalf_jac_g[index++] = point_data[controlpt_idx_to_vtx_idx_map[j]][k];
            }
        }
    }

    matrix_Lt = matrix_L.transpose();
    matrix_LTL = matrix_Lt*matrix_L;
    matrix_LTa = matrix_Lt*matrix_a;
    //end of initialization

    // Create a new instance of your nlp
    //  (use a SmartPtr, not raw)
    SmartPtr<TNLP> mynlp = new IpoptSmoothSolver(this);

    // Create a new instance of IpoptApplication
    //  (use a SmartPtr, not raw)
    SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

    // Change some options
    //app->Options()->SetNumericValue("tol", opt()->stop_step);
    //app->Options()->SetNumericValue("acceptable_tol", opt()->stop_step * 10);
    //app->Options()->SetIntegerValue("max_iter", opt()->max_iterations);
    //app->Options()->SetNumericValue("acceptable_obj_change_tol", opt()->residual_change_ratio_stopvalue);
    app->Options()->SetIntegerValue("max_iter", 100000);
    app->Options()->SetIntegerValue("print_level", 5);
    //app->Options()->SetStringValue("output_file", "ipopt.out");

    app->Options()->SetStringValue("hessian_approximation", "limited-memory");

    //app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
    //app->Options()->SetStringValue("derivative_test", "first-order");
    //app->Options()->SetStringValue("derivative_test_print_all", "yes");
    //app->Options()->SetNumericValue("derivative_test_tol", 1e-4);

    //added by juyong
    app->Options()->SetStringValue("nlp_scaling_method", "equilibration-based");
    //app->Options()->SetStringValue("print_options_documentation", "yes");
    app->Options()->SetStringValue("mu_strategy", "adaptive");
    //app->Options()->SetStringValue("start_with_resto", "yes");
    //app->Options()->SetStringValue("linear_solver", "MA86");
    app->Options()->SetNumericValue("tol", tol);
    app->Options()->SetNumericValue("dual_inf_tol", dual_inf_tol);

    // Initialize the IpoptApplication and process the options
    ApplicationReturnStatus status = app->Initialize();
    if (status != Solve_Succeeded)
    {
        std::cout << "Error during initialization!\n" << std::endl;
        return;
    }

    // Ask Ipopt to solve the problem
    status = app->OptimizeTNLP(mynlp);

    if (status == Solve_Succeeded)
    {
        std::cout << "The problem solved!" << std::endl;

        // Retrieve some statistics about the solve
        Index iter_count = app->Statistics()->IterationCount();
        std::cout << std::endl << std::endl << "*** The problem solved in " << iter_count << " iterations!" << std::endl;

        Number final_obj = app->Statistics()->FinalObjective();
        std::cout << std::endl << std::endl << "*** The final value of the objective function is " << final_obj << '.' << std::endl;

        std::cout<<std::endl<<"Constraint violation: "<<(w*C_mat.transpose() - P_mat.transpose()).norm()<<std::endl;

        Eigen::MatrixXd matrix_ones, m_ones;
        matrix_ones.setOnes(n_boundary_pt, 1);
        for (int i = 0; i < n_boundary_pt; ++i)
            matrix_ones(i, 0) = 1.0;
        m_ones.setOnes(n_data_pt, 1);
        for (int i = 0; i < n_data_pt; ++i)
            m_ones(i, 0) = 1.0;
        std::cout<<std::endl<<"1 norm: "<<(init_w*matrix_ones - m_ones).norm()<<endl;

        std::cout << std::endl <<std::endl << "*** The final smoothness energy is " << pow((matrix_L*init_w + matrix_a).norm(), 2.0) << std::endl;

        smoothness_bound = laplacian_bound_min_ratio*pow((matrix_L*init_w + matrix_a).norm(), 2.0);
        std::cout << std::endl <<std::endl << "*** The smoothness bound is " << smoothness_bound << std::endl;

        double final_half_norm = 0;
        for (int i = 0; i < n_data_pt; ++i)
        {
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                final_half_norm += std::sqrt(std::fabs(init_w(i, j)));
            }
        }
        std::cout << std::endl <<std::endl << "*** the half norm of final value " << final_half_norm << std::endl;


		string filename = "/Users/juyong/Works/SBC/Results/Smoothmat-" + meshNode_->objectName().toStdString() + ".txt";
        std::ofstream ofile(filename.c_str());
        if(!ofile.is_open()){
            std::cerr << "Unable to create matrix file" << std::endl;
        }
        else
        {
            ofile<<init_w;
        }
    }
    else
    {
        std::cout << "The problem FAILED...." << std::endl;
    }

    if (lhalf_jac_g)
    {
        delete[] lhalf_jac_g;
        lhalf_jac_g = NULL;
    }
}

int ConstrainedMeshPlugin::knitro_lhalf_solve(int smoothness_position,
                                              double smooth_weight,
                                              bool supplyHessian,
                                              int init_type,
                                              int dimension,
                                              int laplaceType,
                                              bool controlVariables,
                                              double controlWeight,
                                              bool nonnegativeConstraint,
                                              double tol,
                                              double dual_inf_tol,
                                              bool meshlessparameterization,
                                              double laplacianminratio)
{
    //initialization
    initialization();

    original_positions_.clear();
    for (size_t i = 0; i < point_data.size(); ++i)
    {
        original_positions_.push_back(point_data[i]);
    }

    initialize_P_and_C(dimension);
    mean_cage_ = Eigen::Vector3d(0.0, 0.0, 0.0);
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            mean_cage_[i] += C_mat(i, j);
        }
    }
    mean_cage_ /= double(n_boundary_pt);

    if (laplaceType == 2)
        initialize_fairness_energy_matrix_keenan();
    else
        initialize_fairness_energy_matrix(laplaceType);

    controlVariables_ = controlVariables;
    control_weight_ = controlWeight;
    nonnegativeConstraint_ = nonnegativeConstraint;
    meshless_parameterization_ = meshlessparameterization;

    temp_w.setZero(n_data_pt, n_boundary_pt);
    dim = dimension;
    dl_weight = smooth_weight;

    if (w.rows() == 0)
    {
        w.setZero(n_data_pt, n_boundary_pt);
        switch (init_type)
        {
        case 0:
            w = init_w;
            break;
        case 2:
            w = meanw;
            break;
        case 3:
            w = harmonicw;
            break;
        case 4:
            w = boundedBiharmonicW;
            break;
        case 5:
            w = greenw;
            break;
        default:
            break;
        }
    }

    lhalf_jac_g = new Number[(1 + dim)*n_data_pt*n_boundary_pt];
    int index = 0;
    for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        lhalf_jac_g[index++] = 1.0;
    }
    for (int k = 0; k < dim; ++k)
    {
        for (int i = 0; i < n_data_pt; ++i)
        {
            for (int j = 0; j < n_boundary_pt; ++j)
            {
                lhalf_jac_g[index++] = point_data[controlpt_idx_to_vtx_idx_map[j]][k];
            }
        }
    }

    matrix_Lt = matrix_L.transpose();
    matrix_LTL = matrix_Lt*matrix_L;
    matrix_LTa = matrix_Lt*matrix_a;

    int idx = 0;
    for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        int row = i/n_boundary_pt;
        int col = i%n_boundary_pt;
        //as sparse matrix is column-based, actually, it visits the rowth-column datas
        //however, LTL is symmetric
        for (SparseMatrixXd::InnerIterator it(matrix_LTL, row); it; ++it)
        {
            int j = it.row();
            if (j*n_boundary_pt + col <= i)
            {
                idx++;
            }
        }
    }
    n_LTL_nonzeros = idx;

    LTL_hessian_values.resize(n_LTL_nonzeros);
    idx = 0;
    for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
    {
        int row = i/n_boundary_pt;
        int col = i%n_boundary_pt;
        //as sparse matrix is column-based, actually, it visits the rowth-column datas
        //however, LTL is symmetric
        for (SparseMatrixXd::InnerIterator it(matrix_LTL, row); it; ++it)
        {
            int j = it.row();
            if (j*n_boundary_pt + col <= i)
            {
                if (j*n_boundary_pt + col == i)
                    diagonalIndex.push_back(idx);

                LTL_hessian_values[idx++] = it.value();
            }
        }
    }

    switch (smoothness_position)
    {
    case 0:
        smoothness_position_ = 1;
        break;
    case 1:
        smoothness_position_ = 0;
        break;
    default:
        smoothness_position_ = 0;
        break;
    }
    //end of initialization

    QDir binDir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
    binDir.cdUp();
    binDir.cdUp();
    binDir.cdUp();
    binDir.cdUp();
#endif
    binDir.cd("src");
    binDir.cd("Libraries");
    binDir.cd("bin");

    if (smoothness_bound == 0)
        smoothness_bound = laplacianminratio*pow((matrix_L*w + matrix_a).norm(), 2.0);
	ofstream outsetting("/Users/juyong/Mesh-CGL/src/Libraries/bin/parameters");
    outsetting<<n_data_pt<<endl;
    outsetting<<n_boundary_pt<<endl;
    outsetting<<controlVariables_<<endl;
    outsetting<<smoothness_position_<<endl;
    outsetting<<nonnegativeConstraint_<<endl;
    outsetting<<meshless_parameterization_<<endl;
    outsetting<<dim<<endl;
    outsetting<<dl_weight<<endl;
    outsetting<<control_weight_<<endl;
    outsetting<<smoothness_bound<<endl;
    outsetting.close();

	ofstream outinitw("/Users/juyong/Mesh-CGL/src/Libraries/bin/initw");
    outinitw.precision(20);
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            outinitw<<w(i, j)<<" ";
        }
        outinitw<<endl;
    }
    outinitw.close();

	ofstream outmatrixL("/Users/juyong/Mesh-CGL/src/Libraries/bin/matrixL");
    outmatrixL.precision(20);
    outmatrixL<<matrix_L.nonZeros()<<endl;
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (SparseMatrixXd::InnerIterator it(matrix_L, i); it; ++it)
        {
            outmatrixL<<it.row()<<" "<<it.col()<<" "<<it.value()<<endl;
        }
    }
    outmatrixL.close();

	ofstream outmatrixa("/Users/juyong/Mesh-CGL/src/Libraries/bin/matrixa");
    outmatrixa.precision(20);
    outmatrixa<<matrix_a;
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            outmatrixa<<matrix_a(i, j)<<" ";
        }
        outmatrixa<<endl;
    }
    outmatrixa.close();

	ofstream outpmat("/Users/juyong/Mesh-CGL/src/Libraries/bin/pmat");
    outpmat.precision(20);
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < n_data_pt; ++j)
        {
            outpmat<<P_mat(i, j)<<" ";
        }
        outpmat<<endl;
    }
    outpmat.close();

	ofstream outcmat("/Users/juyong/Mesh-CGL/src/Libraries/bin/cmat");
    outcmat.precision(20);
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            outcmat<<C_mat(i, j)<<" ";
        }
        outcmat<<endl;
    }
    outcmat.close();

	ofstream outmeancage("/Users/juyong/Mesh-CGL/src/Libraries/bin/meancage");
    outmeancage.precision(20);
    for (int i = 0; i < 3; ++i)
    {
        outmeancage<<mean_cage_(i)<<" ";
    }
    outmeancage.close();

    ofstream outcontrol_data_correspondence("/Users/Juyong/Mesh-CGL/src/Libraries/bin/control_data_correspondence");
    outcontrol_data_correspondence.precision(20);
    outcontrol_data_correspondence<<control_data_correspondence_.size()<<endl;
    for (size_t i = 0; i < control_data_correspondence_.size(); ++i)
    {
        outcontrol_data_correspondence<<control_data_correspondence_[i]<<endl;
    }
    outcontrol_data_correspondence.close();

    std::string parameters;
    parameters = binDir.absolutePath().toStdString() + "/run_program";

    system(parameters.c_str());

    ifstream infinalw("/Users/Juyong/Mesh-CGL/src/Libraries/bin/finalw");
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            infinalw>>w(i, j);
        }
    }

    if (controlVariables_)
    {
        optimized_C_mat.setZero(n_boundary_pt, dim);
        double d_temp;
        for (int i = 0; i < n_data_pt*n_boundary_pt; ++i)
            infinalw>>d_temp;
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            for (int j = 0; j < dim; ++j)
                infinalw>>optimized_C_mat(i, j);
        }
    }
    infinalw.close();

    if (controlVariables_)
    {
        if (hasCage_)
        {
            int i = 0;
            VertexIterator v_it, v_end = cageObject_->vertexEnd();
            for(v_it = cageObject_->vertexBegin(); v_it != v_end; ++v_it, ++i)
            {
                OMesh::Vector3 new_control_position(0.0, 0.0, 0.0);
                for (int j = 0; j < dim; ++j)
                {
                    new_control_position[j] = optimized_C_mat(i, j);
                }
                cageObject_->setVertexPosition(i, new_control_position);
            }
            cageNode_->setGeometryChanged();
        }
        else
        {
            for (int i = 0; i < n_boundary_pt; ++i)
            {
                OMesh::VertexHandle vHandle = pmesh_->vertex_handle(controlpt_idx_to_vtx_idx_map[i]);
                OMesh::Vector3 new_control_position(0.0, 0.0, 0.0);
                for (int j = 0; j < dim; ++j)
                {
                    new_control_position[j] = optimized_C_mat(i, j);
                }
                pmesh_->point(vHandle) = new_control_position;
            }
            meshNode_->setGeometryChanged();
        }
    }

    if (controlVariables_)
    {
        std::cout<<std::endl<<"Constraint violation: "<<(w*optimized_C_mat - P_mat.transpose()).norm()<<std::endl;
    }
    else
    {
        std::cout<<std::endl<<"Constraint violation: "<<(w*C_mat.transpose() - P_mat.transpose()).norm()<<std::endl;
    }

    Eigen::MatrixXd matrix_ones, m_ones;
    matrix_ones.setOnes(n_boundary_pt, 1);
    for (int i = 0; i < n_boundary_pt; ++i)
        matrix_ones(i, 0) = 1.0;
    m_ones.setOnes(n_data_pt, 1);
    for (int i = 0; i < n_data_pt; ++i)
        m_ones(i, 0) = 1.0;
    std::cout<<std::endl<<"sum1 error: "<<(init_w*matrix_ones - m_ones).norm()<<endl;

    std::cout << std::endl <<std::endl << "*** The final smoothness energy is " << pow((matrix_L*w + matrix_a).norm(), 2.0) << std::endl;
    std::cout << std::endl <<std::endl << "*** The smoothness bound is " << smoothness_bound << std::endl;

    double init_half_norm = 0, final_half_norm = 0;
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            init_half_norm += std::sqrt(std::fabs(init_w(i, j)));
            final_half_norm += std::sqrt(std::fabs(w(i, j)));
        }
    }
    std::cout << std::endl <<std::endl << "*** the half norm of init value " << init_half_norm << std::endl;
    std::cout << std::endl <<std::endl << "*** the half norm of final value " << final_half_norm << std::endl;

	string filename = "/Users/juyong/Works/SBC/Results/Lhalfmat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream ofile(filename.c_str());
    if (!ofile.is_open()){
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        ofile<<w;
    }
}

void ConstrainedMeshPlugin::reWeighted_l2_solve(int num_threads,
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
                                                double sparsity,
                                                double pNorm,
                                                int max_iter,
                                                int primal_max_iter,
                                                int dimension,
                                                int laplaceType,
                                                bool nonnegativeConstraint,
                                                int smoothPosition,
                                                bool linearPrecision,
                                                bool harmonicSolver)
{
    if (w.rows() == 0)
    {
        if (init_w.rows() == 0)
            w.setZero(n_data_pt, n_boundary_pt);
        else
            w = init_w;
    }

    linearPrecision_ = linearPrecision;

    initialization();
    initialize_fairness_energy_matrix(laplaceType);
    initialize_P_and_C(dimension);

    //assign barycentric coordinate to the original mesh
    QList<Node*> selected;
    getScenegraph().getDescendants(selected, false);
    std::tr1::shared_ptr<OMesh> originalMesh;
    OpenMeshNode *originalmeshNode;
    std::string meshName = meshNode_->objectName().toStdString();
    bool hasOriginal = false;
    for(QList<Node*>::iterator it = selected.begin(); it != selected.end(); ++it)
    {
        if ((*it)->getType() == OPEN_MESH_NODE && (*it) != meshNode_)
        {
            (*it)->setSelected(true, false);
            originalmeshNode = qobject_cast<OpenMeshNode*>(*it);
            originalMesh = originalmeshNode->getMesh();
            hasOriginal = true;
            break;
        }
    }
    Eigen::MatrixXd final_smooth_w;
    Eigen::MatrixXd final_w;
    std::vector<BarycentricCoordinates> v_bc;
    std::vector<OMesh::FaceHandle> v_fh;
    if (hasOriginal)
    {
        final_smooth_w.resize(originalMesh->n_vertices(), n_boundary_pt);
        final_w.resize(originalMesh->n_vertices(), n_boundary_pt);
        v_bc.resize(originalMesh->n_vertices());
        v_fh.resize(originalMesh->n_vertices());
        utilities::NearestTriangleSearch nts;
        nts.initializeKDTreeBasedSearchStructure(pmesh_.get(), 12, 30);
        for (OMesh::VertexIter vIt = originalMesh->vertices_begin(); vIt != originalMesh->vertices_end(); ++vIt)
        {
            Point p = originalMesh->point(vIt.handle());
            OMesh::FaceHandle fh;
            nts.computeClosestTriangleOfPoint(p, pmesh_.get(), fh);
            Point projectedPoint;
            BarycentricCoordinates bc;
            BasicMeasuring::squaredDistancePointToTriangle(p, pmesh_.get(), fh, projectedPoint, bc);
            v_bc[vIt.handle().idx()] = bc;
            v_fh[vIt.handle().idx()] = fh;

            OMesh::ConstFaceVertexIter fvI = pmesh_->cfv_iter(fh);
            int v0 = fvI.handle().idx(); ++fvI;
            int v1 = fvI.handle().idx(); ++fvI;
            int v2 = fvI.handle().idx();
            final_smooth_w.row(vIt.handle().idx()) = bc.u_*init_w.row(v0) + bc.v_*init_w.row(v1) + bc.w_*init_w.row(v2);
        }
        init_w = final_smooth_w;
        meshName = originalmeshNode->objectName().toStdString();
    }

    string filename = "/Users/Juyong/Works/SBC/Results/smooth-mat-" + meshName + ".txt";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        outfile<<init_w;
    }
    outfile.close();

    bool smoothness_hard_constraint_ = (smoothPosition == 1)?false:true;

    //begin
    std::vector<int> aData, lData;
    std::vector<bool> identical(n_data_pt, false);
    if (cageSegments.size() > 0)
    {
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            int nSub = cageSegments[i].size();
            assert(nSub >= 2);
            double dt = 1.0/(nSub - 1.0);
            for (int j = 0; j < nSub - 1; ++j)
            {
                Eigen::VectorXd coor(2);
                coor(0) = (cageSegments[i][j]->getCoords())[0];
                coor(1) = (cageSegments[i][j]->getCoords())[1];

                double d_min = std::numeric_limits<int>::max();
                int index_min = -1;
                for (int k = 0; k < n_data_pt; ++k)
                {
                    double d = (coor - P_mat.col(k)).norm();
                    if (d < d_min)
                    {
                        d_min = d;
                        index_min = k;
                    }
                }
                aData.push_back(index_min);
                identical[index_min] = true;
                w.row(index_min).setZero();
                w(index_min, i) = 1.0 - dt*j;
                w(index_min, (i + 1)%n_boundary_pt) = dt*j;
            }
        }
    }

    for (int i = 0; i < n_data_pt; ++i)
    {
        if (!identical[i])
        {
            lData.push_back(i);
        }
    }

    //begin replace
    SparseMatrixXd l1_temp(n_data_pt, aData.size());
    SparseMatrixXd l1(lData.size(), aData.size());
    Eigen::MatrixXd wd(aData.size(), n_boundary_pt);
    for (size_t i = 0; i < aData.size(); ++i)
    {
        l1_temp.col(i) = matrix_L.col(aData[i]);
        wd.row(i) = w.row(aData[i]);
    }
    SparseMatrixXd l1_temp_t = l1_temp.transpose();
    SparseMatrixXd l1_t(aData.size(), lData.size());
    std::vector<bool> has_fixed_neighbor(lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        l1_t.col(i) = l1_temp_t.col(lData[i]);
        has_fixed_neighbor[i] = (l1_t.col(i).nonZeros() > 0)?true:false;
    }
    l1 = l1_t.transpose();
    Eigen::MatrixXd a_ = l1*wd;

    if (aData.size() == 0)
        a_ = matrix_a;

    SparseMatrixXd L_temp(n_data_pt, lData.size());
    SparseMatrixXd L_(lData.size(), lData.size());
    Eigen::MatrixXd data_points_(dimension, lData.size());
    Eigen::MatrixXd wud(lData.size(), n_boundary_pt);
    std::vector<double> wud_vector(lData.size()*n_boundary_pt);
    for (size_t i = 0; i < lData.size(); ++i)
    {
        wud.row(i) = w.row(lData[i]);
        L_temp.col(i) = matrix_L.col(lData[i]);
        data_points_.col(i) = P_mat.col(lData[i]);
    }
    SparseMatrixXd L_temp_t = L_temp.transpose();
    SparseMatrixXd L_t(lData.size(), lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        L_t.col(i) = L_temp_t.col(lData[i]);
    }
    L_ = L_t.transpose();
    //end replace

    //compute sparsity energy
    double whalfnorm = 0;
    for (int i = 0; i < wud.rows()*wud.cols(); ++i)
    {
        whalfnorm += sqrt(fabs(wud(i)));
    }
    std::cout<<"initial half norm: "<<whalfnorm<<std::endl;
    std::cout<<"initial w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
    std::cout<<"initial ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;
    //end of computing sparsity energy

    int sparse_index = lData.size()*n_boundary_pt*sparsity;
    Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], lData.size(), n_boundary_pt) = wud;
    std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);
    std::cout<<"Initial epsilon: "<<wud_vector[sparse_index]<<std::endl;

    ReWeightedL2 reWeighted_solver;
    Eigen::MatrixXd D_(lData.size(), n_boundary_pt);
    reWeighted_solver.assign_other_coordinate(wud);
    reWeighted_solver.init_variables(num_threads,
                                     laplacian_bound_min_ratio,
                                     init_penalty_weight_,
                                     max_penalty_weight,
                                     primal_eps_val_,
                                     dual_eps_val_,
                                     init_dual_eps_,
                                     initval_primal_eps_,
                                     initval_dual_eps_,
                                     tau_incr_,
                                     dlWeight_,
                                     smoothWeight_,
                                     max_iter,
                                     primal_max_iter,
                                     dimension,
                                     L_,
                                     a_,
                                     D_,
                                     C_mat,
                                     data_points_,
                                     has_fixed_neighbor,
                                     nonnegativeConstraint,
                                     smoothness_hard_constraint_,
                                     linearPrecision,
                                     false);
    if (harmonicSolver)
    {
        reWeighted_solver.initialize_v_harmonic_vars();
        reWeighted_solver.harmonic_initialize_stopping_criteria_var();
    }

    int iter = 0;
    Eigen::MatrixXd prev_wud = wud;
    while (iter < 10)
    {
        iter++;
        std::cout<<"The "<<iter<<"-th iteration:"<<std::endl;

        double epsilon = 1.0e-5;
        for (int i = 0; i < wud.rows(); ++i)
        {
            for (int j = 0; j < wud.cols(); ++j)
            {
                D_(i, j) = 1.0/std::pow(epsilon*epsilon + wud(i, j)*wud(i, j), 0.5 - pNorm/4.0);
            }
        }

        reWeighted_solver.assign_weighted_matrix(D_);
        if (harmonicSolver)
        {
            reWeighted_solver.solve_harmonic();
        }
        else
        {
            reWeighted_solver.solve();
        }

        wud = reWeighted_solver.get_w();

        Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], lData.size(), n_boundary_pt) = wud;
        std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);

        //compute sparsity energy
        whalfnorm = 0;
        for (int i = 0; i < wud.rows(); ++i)
        {
            for (int j = 0; j < wud.cols(); ++j)
            {
                whalfnorm += sqrt(fabs(wud(i, j)));
            }
        }
        //end of computing sparsity energy

        //save current result
        for (size_t i = 0; i < lData.size(); ++i)
        {
            w.row(lData[i]) = wud.row(i);
        }

        std::cout<<"Current half norm: "<<whalfnorm<<std::endl;
        std::cout<<"Current data w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
        std::cout<<"Current ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;
        std::cout<<"Current epsilon: "<<wud_vector[sparse_index]<<std::endl;

        if (hasOriginal)
        {
            for (size_t vi = 0; vi < originalMesh->n_vertices(); ++vi)
            {
                BarycentricCoordinates bc = v_bc[vi];
                OMesh::ConstFaceVertexIter fvI = pmesh_->cfv_iter(v_fh[vi]);
                int v0 = fvI.handle().idx(); ++fvI;
                int v1 = fvI.handle().idx(); ++fvI;
                int v2 = fvI.handle().idx();
                final_w.row(vi) = bc.u_*w.row(v0) + bc.v_*w.row(v1) + bc.w_*w.row(v2);
            }
        }

        string filename = "/Users/juyong/Works/SBC/Results/LBC-mat-";
        if (harmonicSolver)
            filename += "harmonic-";
        if (!linearPrecision)
            filename += "bbw-";
        filename += meshName + "-bound-" + boost::lexical_cast<string>(laplacian_bound_min_ratio) + "-pNorm-" + boost::lexical_cast<string>(pNorm) + "-" + boost::lexical_cast<string>(iter) + ".txt";
        std::ofstream outfile(filename.c_str());
        if (!outfile.is_open())
        {
            std::cerr << "Unable to create matrix file" << std::endl;
        }
        else
        {
            if (hasOriginal)
                outfile<<final_w;
            else
            {
                outfile<<w;

                std::ofstream outData("/Users/juyong/Works/SBC/Results/lbcvalue.txt");
                for (int i = 0; i < n_data_pt + n_boundary_pt; ++i)
                {
                    int index = vtx_idx_to_datapt_idx_map[i];
                    if (index >= 0)
                    {
                        for (int j = 0; j < n_boundary_pt; ++j)
                        {
                            outData<<w(index, j)<<" ";
                        }
                        outData<<std::endl;
                    }
                    else
                    {
                        index = vtx_idx_to_control_pt_idx_map[i];
                        for (int j = 0; j < n_boundary_pt; ++j)
                        {
                            if (j == index)
                                outData<<"1 ";
                            else
                                outData<<"0 ";
                        }
                        outData<<std::endl;
                    }
                }
            }
        }
        outfile.close();
        //end of saving current result

        double max_difference = ( prev_wud - wud ).lpNorm<Eigen::Infinity>();
        std::cout << "Infinity norm of variable difference with previous iteration: " << max_difference << std::endl;
        if(max_difference < _MAX_NORM_EPS_)
        {
            break;
        }
        prev_wud = wud;
    }

    if (hasOriginal)
        w = final_w;
    meshNode_->setVisible(false, false);
    meshNode_->setSelected(false, false);
    set_SelectObject_as_Data();
}

void ConstrainedMeshPlugin::reWeighted_l2_smooth(int num_threads,
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
                                                 int dimension,
                                                 int laplaceType,
                                                 bool nonnegativeConstraint,
                                                 bool linearPrecision)
{
    linearPrecision_ = linearPrecision;

    initialization();
    initialize_fairness_energy_matrix(laplaceType);
    initialize_P_and_C(dimension);

    std::cout<<"laplacian matrix norm: "<<matrix_L.norm()<<std::endl;

    if (init_w.rows() == 0)
        init_w.setZero(n_data_pt, n_boundary_pt);

    //begin
    std::vector<int> aData, lData;
    std::vector<bool> identical(n_data_pt, false);
    if (cageSegments.size() > 0)
    {
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            int nSub = cageSegments[i].size();
            assert(nSub >= 2);
            double dt = 1.0/(nSub - 1.0);
            for (int j = 0; j < nSub - 1; ++j)
            {
                Eigen::VectorXd coor(2);
                coor(0) = (cageSegments[i][j]->getCoords())[0];
                coor(1) = (cageSegments[i][j]->getCoords())[1];

                double d_min = std::numeric_limits<int>::max();
                int index_min = -1;
                for (int k = 0; k < n_data_pt; ++k)
                {
                    double d = (coor - P_mat.col(k)).norm();
                    if (d < d_min)
                    {
                        d_min = d;
                        index_min = k;
                    }
                }
                aData.push_back(index_min);
                identical[index_min] = true;
                init_w.row(index_min).setZero();
                init_w(index_min, i) = 1.0 - dt*j;
                init_w(index_min, (i + 1)%n_boundary_pt) = dt*j;
            }
        }
    }

    for (int i = 0; i < n_data_pt; ++i)
    {
        if (!identical[i])
        {
            lData.push_back(i);
        }
    }

    SparseMatrixXd l1_temp(n_data_pt, aData.size());
    SparseMatrixXd l1(lData.size(), aData.size());
    Eigen::MatrixXd wd(aData.size(), n_boundary_pt);
    for (size_t i = 0; i < aData.size(); ++i)
    {
        l1_temp.col(i) = matrix_L.col(aData[i]);
        wd.row(i) = init_w.row(aData[i]);
    }
    SparseMatrixXd l1_temp_t = l1_temp.transpose();
    SparseMatrixXd l1_t(aData.size(), lData.size());
    std::vector<bool> has_fixed_neighbor(lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        l1_t.col(i) = l1_temp_t.col(lData[i]);
        has_fixed_neighbor[i] = (l1_t.col(i).nonZeros() > 0)?true:false;
    }
    l1 = l1_t.transpose();
    Eigen::MatrixXd a_ = l1*wd;

    if (aData.size() == 0)
        a_ = matrix_a;

    SparseMatrixXd L_temp(n_data_pt, lData.size());
    SparseMatrixXd L_(lData.size(), lData.size());
    Eigen::MatrixXd data_points_(dimension, lData.size());
    Eigen::MatrixXd wud(lData.size(), n_boundary_pt);
    for (size_t i = 0; i < lData.size(); ++i)
    {
        wud.row(i) = init_w.row(lData[i]);
        L_temp.col(i) = matrix_L.col(lData[i]);
        data_points_.col(i) = P_mat.col(lData[i]);
    }
    SparseMatrixXd L_temp_t = L_temp.transpose();
    SparseMatrixXd L_t(lData.size(), lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        L_t.col(i) = L_temp_t.col(lData[i]);
    }
    L_ = L_t.transpose();
    //end

    ReWeightedL2 reWeighted_solver;
    Eigen::MatrixXd D_(lData.size(), n_boundary_pt);
    reWeighted_solver.assign_other_coordinate(wud);

    std::cout<<"initial w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
    std::cout<<"initial ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;

    reWeighted_solver.init_variables(num_threads,
                                     laplacian_bound_min_ratio,
                                     init_penalty_weight_,
                                     max_penalty_weight,
                                     primal_eps_val_*0.01,
                                     dual_eps_val_*0.1,
                                     init_dual_eps_*0.1,
                                     initval_primal_eps_*0.01,
                                     initval_dual_eps_*0.1,
                                     tau_incr_,
                                     0,
                                     0,
                                     max_iter,
                                     primal_max_iter,
                                     dimension,
                                     L_,
                                     a_,
                                     D_,
                                     C_mat,
                                     data_points_,
                                     has_fixed_neighbor,
                                     nonnegativeConstraint,
                                     false,
                                     linearPrecision,
                                     true);

    reWeighted_solver.solve_smooth();
    wud = reWeighted_solver.get_w();
    for (size_t i = 0; i < lData.size(); ++i)
    {
        init_w.row(lData[i]) = wud.row(i);
    }

    std::cout<<"data w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
    std::cout<<"||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;
}

void ConstrainedMeshPlugin::oneDillustration(int num_threads,
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
                                             int n,
                                             double sparsity)
{
    int sparse_index = n*sparsity;
    w.setZero(n, 1);
    for (int i = 0; i < n/2; ++i)
    {
        w(i, 0) = w(n - 1 - i, 0) = double(i + 1)/double(n/2 + 1);
    }
    typedef Eigen::Triplet<double> T;
    std::vector<T> triplets_lap;
    triplets_lap.push_back(T(0, 0, -2.0));
    triplets_lap.push_back(T(0, 1, 1.0));
    triplets_lap.push_back(T(n - 1, n - 2, 1.0));
    triplets_lap.push_back(T(n - 1, n - 1, -2.0));
    for (int i = 1; i < n - 1; ++i)
    {
        if (i != n/2 - 1 && i != n/2)
        {
            triplets_lap.push_back(T(i, i - 1, 1.0));
            triplets_lap.push_back(T(i, i + 1, 1.0));
            triplets_lap.push_back(T(i, i, -2.0));
        }
        else
        {
            if (i == n/2 - 1)
            {
                triplets_lap.push_back(T(i, i - 1, 1.0));
                //triplets_lap.push_back(T(i, i + 1, 1.0));
                triplets_lap.push_back(T(i, i, -2.0));
            }
            if (i == n/2)
            {
                //triplets_lap.push_back(T(i, i - 1, 1.0));
                triplets_lap.push_back(T(i, i + 1, 1.0));
                triplets_lap.push_back(T(i, i, -2.0));
            }
        }
    }
    matrix_L.resize(n, n);
    matrix_L.setFromTriplets(triplets_lap.begin(), triplets_lap.end());
    matrix_a.setZero(n, 1);
    matrix_a(n/2 - 1, 0) = 1.0;
    matrix_a(n/2, 0) = 1.0;

    std::vector<double> wud_vector(n);
    Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], n, 1) = w;
    std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);
    double epsilon = wud_vector[sparse_index];
    std::cout<<"Initial epsilon: "<<epsilon<<std::endl;

    //use reweighted-l2 method to compute the values...
    ReWeightedL2 reWeighted_solver;
    weighted_D.setZero(n, 1);
    reWeighted_solver.assign_other_coordinate(w);
    reWeighted_solver.illustrate_init_variables(num_threads,
                                                laplacian_bound_min_ratio,
                                                init_penalty_weight_,
                                                max_penalty_weight,
                                                primal_eps_val_,
                                                dual_eps_val_,
                                                init_dual_eps_,
                                                initval_primal_eps_,
                                                initval_dual_eps_,
                                                tau_incr_,
                                                max_iter,
                                                matrix_L,
                                                matrix_a);
    int iter = 0;
    while (fabs(epsilon) > 1.0e-6 && iter < 100)
    {
        iter++;
        std::cout<<"The "<<iter<<"-th iteration:"<<std::endl;

        for (int i = 0; i < n; ++i)
        {
            weighted_D(i) = 1.0/std::sqrt(epsilon*epsilon + w(i)*w(i));
        }

        //solve the problem
        reWeighted_solver.assign_weighted_matrix(weighted_D);
        reWeighted_solver.solve_illustrate();
        w = reWeighted_solver.get_w();
        Eigen::VectorXd finalw(n + 3);
        finalw[0] = finalw[n + 2] = 0;
        finalw[n/2 + 1] = 1.0;
        for (int i = 0; i < n/2; ++i)
        {
            finalw[i + 1] = w(i, 0);
            finalw[i + n/2 + 2] = w(i + n/2, 0);
        }
		string filename = "/Users/juyong/Works/SBC/Results/ReWeighted-L2-mat-illustration-" + boost::lexical_cast<string>(iter) + ".txt";
        std::ofstream outfile(filename.c_str());
        if (!outfile.is_open())
        {
            std::cerr << "Unable to create matrix file" << std::endl;
        }
        else
        {
            outfile<<finalw;
        }
        outfile.close();
        //end of solving the problem

        Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], n, 1) = w;
        std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);
        epsilon = wud_vector[sparse_index];
        std::cout<<"Current epsilon: "<<epsilon<<std::endl;

        //compute sparsity energy
        double whalfnorm = 0;
        for (int i = 0; i < n; ++i)
        {
            whalfnorm += sqrt(fabs(w(i)));
        }
        std::cout<<"Current half norm: "<<whalfnorm<<std::endl;
        //end of computing sparsity energy
    }
}

void ConstrainedMeshPlugin::twoDillustration()
{
}

void ConstrainedMeshPlugin::displayLocalExtrema(int coordinateType)
{
    double maxdiff = std::numeric_limits<double>::min();
    double mindiff = std::numeric_limits<double>::min();
    int num_minimum = 0;
    int num_maximum = 0;
    for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
    {
        if (!(pmesh_->is_boundary(vIt)))
        {
            int index = vIt.handle().idx();
            bool maximum = false;
            bool minimum = false;
            for (int i = 0; i < n_boundary_pt; ++i)
            {
                bool localMaximum = true;
                bool localMinimum = true;
                double localmaxdiff = std::numeric_limits<double>::max();
                double localmindiff = std::numeric_limits<double>::max();
                for (OMesh::VertexVertexIter vv_it = pmesh_->vv_iter(vIt.handle()); vv_it; ++vv_it)
                {
                    double value = 0;
                    double nvalue = 0;
                    int ni = vv_it.handle().idx();
                    switch (coordinateType)
                    {
                    case 0:
                        value = init_w(index, i);
                        nvalue = init_w(ni, i);
                        break;
                    case 1:
                        value = w(index, i);
                        nvalue = w(ni, i);
                        break;
                    case 2:
                        value = meanw(index, i);
                        nvalue = meanw(ni, i);
                        break;
                    case 3:
                        value = harmonicw(index, i);
                        nvalue = harmonicw(ni, i);
                        break;
                    case 4:
                        value = boundedBiharmonicW(index, i);
                        nvalue = boundedBiharmonicW(ni, i);
                        break;
                    default:
                        break;
                    }
                    if (nvalue > value)
                    {
                        localMaximum = false;
                        localmindiff = (localmindiff < (nvalue - value))?localmindiff:(nvalue - value);
                    }
                    if (nvalue < value)
                    {
                        localMinimum = false;
                        localmaxdiff = (localmaxdiff < (value - nvalue))?localmaxdiff:(value - nvalue);
                    }
                }
                if (localMaximum)
                {
                    maximum = true;
                    num_maximum++;
                    maxdiff = (maxdiff > localmaxdiff)?maxdiff:localmaxdiff;
                }
                if (localMinimum)
                {
                    minimum = true;
                    num_minimum++;
                    mindiff = (mindiff > localmindiff)?mindiff:localmindiff;
                }
            }
            if (maximum && !minimum)
                pmesh_->setVertexColor(index, OMesh::Color(1., 0., 0., 1.));
            if (!maximum && minimum)
                pmesh_->setVertexColor(index, OMesh::Color(0., 1., 0., 1.));
            if (maximum && minimum)
                pmesh_->setVertexColor(index, OMesh::Color(0., 0., 1., 1.));
        }
    }

    std::cout<<"maxdiff: "<<maxdiff<<std::endl;
    std::cout<<"mindiff: "<<mindiff<<std::endl;
    std::cout<<"number of local maximum: "<<num_maximum<<std::endl;
    std::cout<<"number of local minimum: "<<num_minimum<<std::endl;
}

void ConstrainedMeshPlugin::compute3D_LBC(int num_threads,
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
                                          double sparsity,
                                          int max_iter,
                                          int primal_max_iter,
                                          int dimension,
                                          bool nonnegativeConstraint,
                                          int smoothPosition,
                                          bool linearPrecision,
                                          bool harmonicSolver)
{
    using namespace igl;
    using namespace std;
    using namespace Eigen;

    // number of domain vertices
    int tet_n = TetrahedralMesh_node_.rows();
    cotmatrix(TetrahedralMesh_node_, TetrahedralMesh_ele_, matrix_L);

    linearPrecision_ = linearPrecision;
    initialization();
    initialize_P_and_C(dimension);
    init_w.setZero(tet_n, n_boundary_pt);
    w.setZero(tet_n, n_boundary_pt);

    Eigen::MatrixXd final_smooth_w(n_data_pt, n_boundary_pt);
    Eigen::MatrixXd final_w(n_data_pt, n_boundary_pt);
    Eigen::VectorXi correspondence(n_data_pt);
    for (OMesh::VertexIter vIt = pmesh_->vertices_begin(); vIt != pmesh_->vertices_end(); ++vIt)
    {
        Point p = pmesh_->point(vIt);
        double min_d = std::numeric_limits<double>::max();
        int index_d = 0;
        for (int i = 0; i < TetrahedralMesh_node_.rows(); ++i)
        {
            Point q = Point(TetrahedralMesh_node_(i, 0), TetrahedralMesh_node_(i, 1), TetrahedralMesh_node_(i, 2));
            if ((p - q).norm() < min_d)
            {
                min_d = (p - q).norm();
                index_d = i;
            }
        }
        correspondence[vIt.handle().idx()] = index_d;
    }

    bool smoothness_hard_constraint_ = (smoothPosition == 1)?false:true;
    std::vector<int> aData, lData;
    std::vector<bool> identical(tet_n, false);
    std::vector<bool> visited(tet_n, false);
    utilities::NearestTriangleSearch nts;
    nts.initializeKDTreeBasedSearchStructure(cageMesh_.get(), 12, 30);
    for (int i = 0; i < TetrahedralMesh_face_.rows(); ++i)
    {
        for (int j = 0; j < TetrahedralMesh_face_.cols(); ++j)
        {
            int vIndex = TetrahedralMesh_face_(i, j);
            if (!visited[vIndex])
            {
                visited[vIndex] = true;
                double x = TetrahedralMesh_node_(vIndex, 0);
                double y = TetrahedralMesh_node_(vIndex, 1);
                double z = TetrahedralMesh_node_(vIndex, 2);
                Point p = Point(x, y, z);
                OMesh::FaceHandle fh;
                nts.computeClosestTriangleOfPoint(p, cageMesh_.get(), fh);
                Point projectedPoint;
                BarycentricCoordinates bc;
                BasicMeasuring::squaredDistancePointToTriangle(p, cageMesh_.get(), fh, projectedPoint, bc);

                OMesh::ConstFaceVertexIter fvI = cageMesh_->cfv_iter(fh);
                int v0 = fvI.handle().idx(); ++fvI;
                int v1 = fvI.handle().idx(); ++fvI;
                int v2 = fvI.handle().idx();

                aData.push_back(vIndex);
                identical[vIndex] = true;
                init_w(vIndex, v0) = w(vIndex, v0) = bc.u_;
                init_w(vIndex, v1) = w(vIndex, v1) = bc.v_;
                init_w(vIndex, v2) = w(vIndex, v2) = bc.w_;
            }
        }
    }
    for (int i = 0; i < tet_n; ++i)
    {
        if (!identical[i])
        {
            lData.push_back(i);
        }
    }

    //begin replace
    SparseMatrixXd l1_temp(tet_n, aData.size());
    SparseMatrixXd l1(lData.size(), aData.size());
    Eigen::MatrixXd wd(aData.size(), n_boundary_pt);
    for (size_t i = 0; i < aData.size(); ++i)
    {
        l1_temp.col(i) = matrix_L.col(aData[i]);
        wd.row(i) = w.row(aData[i]);
    }
    SparseMatrixXd l1_temp_t = l1_temp.transpose();
    SparseMatrixXd l1_t(aData.size(), lData.size());
    std::vector<bool> has_fixed_neighbor(lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        l1_t.col(i) = l1_temp_t.col(lData[i]);
        has_fixed_neighbor[i] = (l1_t.col(i).nonZeros() > 0)?true:false;
    }
    l1 = l1_t.transpose();
    Eigen::MatrixXd a_ = l1*wd;

    SparseMatrixXd L_temp(tet_n, lData.size());
    SparseMatrixXd L_(lData.size(), lData.size());
    Eigen::MatrixXd data_points_(dimension, lData.size());
    Eigen::MatrixXd wud(lData.size(), n_boundary_pt);
    std::vector<double> wud_vector(lData.size()*n_boundary_pt);
    for (size_t i = 0; i < lData.size(); ++i)
    {
        wud.row(i) = w.row(lData[i]);
        L_temp.col(i) = matrix_L.col(lData[i]);
        data_points_(0, i) = TetrahedralMesh_node_(lData[i], 0);
        data_points_(1, i) = TetrahedralMesh_node_(lData[i], 1);
        data_points_(2, i) = TetrahedralMesh_node_(lData[i], 2);
    }
    SparseMatrixXd L_temp_t = L_temp.transpose();
    SparseMatrixXd L_t(lData.size(), lData.size());
    for (size_t i = 0; i < lData.size(); ++i)
    {
        L_t.col(i) = L_temp_t.col(lData[i]);
    }
    L_ = L_t.transpose();
    //end replace

    ReWeightedL2 reWeighted_solver;
    Eigen::MatrixXd D_(lData.size(), n_boundary_pt);

    //compute harmonic coordinate
    reWeighted_solver.assign_other_coordinate(wud);
    reWeighted_solver.init_variables(num_threads,
                                     laplacian_bound_min_ratio,
                                     init_penalty_weight_,
                                     max_penalty_weight,
                                     primal_eps_val_,
                                     dual_eps_val_,
                                     init_dual_eps_,
                                     initval_primal_eps_,
                                     initval_dual_eps_,
                                     tau_incr_,
                                     0,
                                     0,
                                     max_iter,
                                     primal_max_iter,
                                     dimension,
                                     L_,
                                     a_,
                                     D_,
                                     C_mat,
                                     data_points_,
                                     has_fixed_neighbor,
                                     nonnegativeConstraint,
                                     false,
                                     linearPrecision,
                                     true);

    reWeighted_solver.solve_smooth();
    wud = reWeighted_solver.get_w();
    for (size_t i = 0; i < lData.size(); ++i)
    {
        init_w.row(lData[i]) = wud.row(i);
    }
    for (int i = 0; i < n_data_pt; ++i)
    {
        final_smooth_w.row(i) = init_w.row(correspondence[i]);
    }

    init_w = final_smooth_w;
    string filename = "/Users/Juyong/Works/SBC/Results/3D-smooth-mat-" + meshNode_->objectName().toStdString() + ".txt";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        outfile<<init_w;
    }
    outfile.close();

    //compute sparsity energy
    double whalfnorm = 0;
    for (int i = 0; i < wud.rows()*wud.cols(); ++i)
    {
        whalfnorm += sqrt(fabs(wud(i)));
    }
    int sparse_index = lData.size()*n_boundary_pt*sparsity;
    Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], lData.size(), n_boundary_pt) = wud;
    std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);
    std::cout<<"initial half norm: "<<whalfnorm<<std::endl;
    std::cout<<"initial w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
    std::cout<<"initial ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;
    std::cout<<"Initial epsilon: "<<wud_vector[sparse_index]<<std::endl;
    //end of computing sparsity energy
    //end of computing harmonic coordinate

    reWeighted_solver.assign_other_coordinate(wud);
    reWeighted_solver.init_variables(num_threads,
                                     laplacian_bound_min_ratio,
                                     init_penalty_weight_,
                                     max_penalty_weight,
                                     primal_eps_val_,
                                     dual_eps_val_,
                                     init_dual_eps_,
                                     initval_primal_eps_,
                                     initval_dual_eps_,
                                     tau_incr_,
                                     dlWeight_,
                                     smoothWeight_,
                                     max_iter,
                                     primal_max_iter,
                                     dimension,
                                     L_,
                                     a_,
                                     D_,
                                     C_mat,
                                     data_points_,
                                     has_fixed_neighbor,
                                     nonnegativeConstraint,
                                     smoothness_hard_constraint_,
                                     linearPrecision,
                                     false);
    if (harmonicSolver)
    {
        reWeighted_solver.initialize_v_harmonic_vars();
        reWeighted_solver.harmonic_initialize_stopping_criteria_var();
    }

    Eigen::MatrixXd last_wud(lData.size(), n_boundary_pt);
    last_wud = wud;
    int iter = 0;
    while (iter < 100)
    {
        iter++;
        std::cout<<"The "<<iter<<"-th iteration:"<<std::endl;

        double epsilon = 1.0e-5;
        for (int i = 0; i < wud.rows(); ++i)
        {
            for (int j = 0; j < wud.cols(); ++j)
            {
                D_(i, j) = 1.0/std::sqrt(epsilon*epsilon + wud(i, j)*wud(i, j));
            }
        }

        reWeighted_solver.assign_weighted_matrix(D_);
        if (harmonicSolver)
        {
            reWeighted_solver.solve_harmonic();
        }
        else
        {
            if (linearPrecision)
                reWeighted_solver.solve();
            else
                reWeighted_solver.solve_dl();
        }

        wud = reWeighted_solver.get_w();
        for (size_t i = 0; i < lData.size(); ++i)
        {
            w.row(lData[i]) = wud.row(i);
        }
        for (int i = 0; i < n_data_pt; ++i)
        {
            final_w.row(i) = w.row(correspondence[i]);
        }

        Eigen::Map<Eigen::MatrixXd>(&wud_vector[0], lData.size(), n_boundary_pt) = wud;
        std::nth_element(wud_vector.begin(), wud_vector.begin() + sparse_index, wud_vector.end(), fabs_greater);

        //compute sparsity energy
        whalfnorm = 0;
        for (int i = 0; i < wud.rows(); ++i)
        {
            for (int j = 0; j < wud.cols(); ++j)
            {
                whalfnorm += sqrt(fabs(wud(i, j)));
            }
        }
        //end of computing sparsity energy

        std::cout<<"Current half norm: "<<whalfnorm<<std::endl;
        std::cout<<"Current data w smoothness: "<<(L_*wud + a_).norm()<<std::endl;
        std::cout<<"Current ||p-wc|| value: "<<(data_points_ - C_mat*wud.transpose()).norm() <<std::endl;
        std::cout<<"Current epsilon: "<<wud_vector[sparse_index]<<std::endl;

        string filename = "/Users/Juyong/Works/SBC/Results/3DReWeighted-L2-mat-";
        if (harmonicSolver)
            filename = "/Users/Juyong/Works/SBC/Results/3DReWeighted-L2-harmonic-mat-";
        filename += meshNode_->objectName().toStdString() + "-bound-" + boost::lexical_cast<string>(laplacian_bound_min_ratio) + "-" + boost::lexical_cast<string>(iter) + ".txt";
        std::ofstream outfile(filename.c_str());
        if (!outfile.is_open())
        {
            std::cerr << "Unable to create matrix file" << std::endl;
        }
        else
        {
            outfile<<final_w;
        }
        outfile.close();
        //end of saving current result

        std::cout<<"coordinate l2 norm:"<<last_wud.norm()<<", "<<wud.norm()<<std::endl;
        if ((wud - last_wud).norm()/wud.norm() < 5.0e-3)
            break;
        last_wud = wud;
    }
    outfile.close();

    w = final_w;
}

void ConstrainedMeshPlugin::knitro_smooth_solve(int dimension, int laplaceType, bool nonnegativeConstraint, bool meshlessparameterization, bool linearPrecision)
{
    //initialization
    initialization();

    initialize_P_and_C(dimension);

    if (laplaceType == 2)
        initialize_fairness_energy_matrix_keenan();
    else
        initialize_fairness_energy_matrix(laplaceType);

    nonnegativeConstraint_ = nonnegativeConstraint;
    meshless_parameterization_ = meshlessparameterization;
    linearPrecision_ = linearPrecision;

    temp_w.setZero(n_data_pt, n_boundary_pt);
    dim = dimension;

    if (init_w.rows() == 0)
    {
        init_w.setZero(n_data_pt, n_boundary_pt);
    }

    matrix_Lt = matrix_L.transpose();
    matrix_LTL = matrix_Lt*matrix_L;
    matrix_LTa = matrix_Lt*matrix_a;
    //end of initialization


    QDir binDir(qApp->applicationDirPath());
#if defined(Q_OS_MAC)
    binDir.cdUp();
    binDir.cdUp();
    binDir.cdUp();
    binDir.cdUp();
#endif
    binDir.cd("src");
    binDir.cd("Libraries");
    binDir.cd("bin");

    ofstream outsetting("/Users/Juyong/Mesh-CGL/src/Libraries/bin/parameters");
    outsetting<<n_data_pt<<endl;
    outsetting<<n_boundary_pt<<endl;
    outsetting<<nonnegativeConstraint_<<endl;
    outsetting<<meshless_parameterization_<<endl;
    outsetting<<linearPrecision_<<endl;
    outsetting<<dim<<endl;

    ofstream outinitw("/Users/Juyong/Mesh-CGL/src/Libraries/bin/initw");
    outinitw.precision(20);
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            outinitw<<init_w(i, j)<<" ";
        }
        outinitw<<endl;
    }
    ofstream outmatrixL("/Users/Juyong/Mesh-CGL/src/Libraries/bin/matrixL");
    outmatrixL.precision(20);
    outmatrixL<<matrix_L.nonZeros()<<endl;
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (SparseMatrixXd::InnerIterator it(matrix_L, i); it; ++it)
        {
            outmatrixL<<it.row()<<" "<<it.col()<<" "<<it.value()<<endl;
        }
    }
    ofstream outmatrixa("/Users/Juyong/Mesh-CGL/src/Libraries/bin/matrixa");
    outmatrixa.precision(20);
    outmatrixa<<matrix_a;
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            outmatrixa<<matrix_a(i, j)<<" ";
        }
        outmatrixa<<endl;
    }
    ofstream outpmat("/Users/Juyong/Mesh-CGL/src/Libraries/bin/pmat");
    outpmat.precision(20);
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < n_data_pt; ++j)
        {
            outpmat<<P_mat(i, j)<<" ";
        }
        outpmat<<endl;
    }
    ofstream outcmat("/Users/Juyong/Mesh-CGL/src/Libraries/bin/cmat");
    outcmat.precision(20);
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            outcmat<<C_mat(i, j)<<" ";
        }
        outcmat<<endl;
    }
    ofstream outcontrol_data_correspondence("/Users/Juyong/Mesh-CGL/src/Libraries/bin/control_data_correspondence");
    outcontrol_data_correspondence.precision(20);
    outcontrol_data_correspondence<<control_data_correspondence_.size()<<endl;
    for (size_t i = 0; i < control_data_correspondence_.size(); ++i)
    {
        outcontrol_data_correspondence<<control_data_correspondence_[i]<<endl;
    }

    std::string parameters;
    parameters = binDir.absolutePath().toStdString() + "/run_smoothprogram";

    system(parameters.c_str());

    ifstream infinalw("/Users/Juyong/Mesh-CGL/src/Libraries/bin/finalsmoothw");
    if (!linearPrecision_)
    {
        boundedBiharmonicW.setZero(n_data_pt, n_boundary_pt);
    }
    for (int i = 0; i < n_data_pt; ++i)
    {
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            if (linearPrecision)
                infinalw>>init_w(i, j);
            else
                infinalw>>boundedBiharmonicW(i, j);
        }
    }
    infinalw.close();

    std::cout<<std::endl<<"Constraint violation: "<<(init_w*C_mat.transpose() - P_mat.transpose()).norm()<<std::endl;

    Eigen::MatrixXd matrix_ones, m_ones;
    matrix_ones.setOnes(n_boundary_pt, 1);
    for (int i = 0; i < n_boundary_pt; ++i)
        matrix_ones(i, 0) = 1.0;
    m_ones.setOnes(n_data_pt, 1);
    for (int i = 0; i < n_data_pt; ++i)
        m_ones(i, 0) = 1.0;
    std::cout<<std::endl<<"1 norm: "<<(init_w*matrix_ones - m_ones).norm()<<endl;

    std::cout << std::endl <<std::endl << "*** The knitro smoothness energy is " << pow((matrix_L*init_w + matrix_a).norm(), 2.0) << std::endl;

    string filename = "/Users/Juyong/Works/SBC/Results/KnitroSmoothmat-" + meshNode_->objectName().toStdString() + ".txt";

    if (!linearPrecision_)
        filename = "/Users/Juyong/Works/SBC/Results/KnitroSorkinmat-" + meshNode_->objectName().toStdString() + ".txt";

    std::ofstream ofile(filename.c_str());
    if(!ofile.is_open()){
        std::cerr << "Unable to create matrix file" << std::endl;
    }
    else
    {
        if (linearPrecision_)
            ofile<<init_w;
        else
            ofile<<boundedBiharmonicW;
    }
}

void ConstrainedMeshPlugin::bcTextureImage(int coordinateType)
{
    initialization();

    if (color_map_)
    {
        std::tr1::shared_ptr<ColorMap> colorMap = std::tr1::shared_ptr<ColorMap>(new ColorMap(0, 1.0, ColorMap::JET));

        double min_coord = 0.001, max_coord = 0.999;
        double total_length = 0.0;
        std::vector<double> accum_length;
        accum_length.push_back(0.0);
        for (int i = 0; i < n_boundary_pt; ++i)
        {
            double cur_length = (point_data[controlpt_idx_to_vtx_idx_map[i]] - point_data[controlpt_idx_to_vtx_idx_map[(i + 1)%n_boundary_pt]]).norm();
            total_length += cur_length;
            accum_length.push_back(accum_length.back() + cur_length);
        }

        double mid_length = total_length/2.0;
        for (int i = 0; i < n_boundary_pt; i++)
        {
            double cur_length = accum_length[i];
            double normalized_coord = (cur_length <= mid_length)?cur_length/mid_length: (total_length - cur_length)/mid_length;
            double coord = max_coord*normalized_coord + min_coord*(1.0 - normalized_coord);
            QColor qc = colorMap->getColor(coord);
            OMesh::Color c(qc.redF(), qc.greenF(), qc.blueF(), 1.0);
            cageObject_->setVertexColor(i, c);
        }
    }

    for (size_t i = 0; i < pmesh_->nPoints(); ++i)
    {
        OMesh::Color dc = OMesh::Color(0.0, 0.0, 0.0, 0.0);
        for (int j = 0; j < n_boundary_pt; ++j)
        {
            switch (coordinateType)
            {
            case 0:
                dc += init_w(i, j)*cageObject_->getVertexColor(j);
                break;
            case 1:
                dc += w(i, j)*cageObject_->getVertexColor(j);
                break;
            case 2:
                dc += meanw(i, j)*cageObject_->getVertexColor(j);
                break;
            case 3:
                dc += harmonicw(i, j)*cageObject_->getVertexColor(j);
                break;
            case 4:
                dc += boundedBiharmonicW(i, j)*cageObject_->getVertexColor(j);
                break;
            default:
                break;
            }
        }
        pmesh_->setVertexColor(i, dc);
    }

    cageNode_->setGeometryChanged();
    meshNode_->setGeometryChanged();
    cageNode_->nodeUpdated();
    meshNode_->nodeUpdated();
}

void ConstrainedMeshPlugin::get_test_tex_coord(Eigen::VectorXd &boundary_value,
											   Eigen::VectorXd &w_tex_coord,
                                               int coordinateType)
{
    w_tex_coord.resize(n_data_pt);

    double min_coord = 0.001, max_coord = 0.999;
    double total_length = 0.0;
    std::vector<double> accum_length;
    accum_length.push_back(0.0);
    for (int i = 0; i < n_boundary_pt; ++i)
    {
        double cur_length = (point_data[controlpt_idx_to_vtx_idx_map[i]] - point_data[controlpt_idx_to_vtx_idx_map[(i + 1)%n_boundary_pt]]).norm();
        total_length += cur_length;
        accum_length.push_back(accum_length.back() + cur_length);
    }

    double mid_length = total_length/2.0;
	boundary_value.resize(n_boundary_pt);

    for (int i = 0; i < n_boundary_pt; i++)
    {
        double cur_length = accum_length[i];
        double normalized_coord = (cur_length <= mid_length)?cur_length/mid_length: (total_length - cur_length)/mid_length;
		double coord = max_coord*normalized_coord + min_coord*(1.0 - normalized_coord);

        boundary_value(i) = coord;
    }

    switch (coordinateType)
    {
    case 0:
        w_tex_coord = init_w*boundary_value;
        break;
    case 1:
        w_tex_coord = w*boundary_value;
        break;
    case 2:
        w_tex_coord = meanw*boundary_value;
        break;
    case 3:
        w_tex_coord = harmonicw*boundary_value;
        break;
	case 4:
		w_tex_coord = boundedBiharmonicW*boundary_value;
		break;
    default:
        break;
    }
}

//half norm minimization
ConstrainedMeshPlugin::IpoptLhalfSolver::IpoptLhalfSolver(ConstrainedMeshPlugin* o_)
:o(o_){}

ConstrainedMeshPlugin::IpoptLhalfSolver::~IpoptLhalfSolver(){}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                          Index& nnz_h_lag, IndexStyleEnum& index_style)
{
    return o->ipoptlhalf_get_nlp_info(n, m, nnz_jac_g, nnz_h_lag, index_style);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u)
{
    return o->ipoptlhalf_get_bounds_info(n, x_l, x_u, m, g_l, g_u);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::get_starting_point(Index n, bool init_x, Number* x, bool init_z, Number* z_L, Number* z_U, Index m, bool init_lambda, Number* lambda)
{
    return o->ipoptlhalf_get_starting_point(n, init_x, x, init_z, z_L, z_U, m, init_lambda, lambda);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    return o->ipoptlhalf_eval_f(n, x, new_x, obj_value);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    return o->ipoptlhalf_eval_grad_f(n, x, new_x, grad_f);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
    return o->ipoptlhalf_eval_g(n, x, new_x, m, g);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::eval_jac_g(Index n, const Number* x, bool new_x, Index m, Index nele_jac, Index* iRow, Index *jCol, Number* values)
{
    return o->ipoptlhalf_eval_jac_g(n, x, new_x, m, nele_jac, iRow, jCol, values);
}

bool ConstrainedMeshPlugin::IpoptLhalfSolver::eval_h(Index n, const Number *x, bool new_x, Number obj_factor, Index m, const Number *lambda, bool new_lambda, Index nele_hess, Index *iRow, Index *jCol, Number *values)
{
    return o->ipoptlhalf_eval_h(n, x, new_x, obj_factor, m, lambda, new_lambda, nele_hess, iRow, jCol, values);
}

void ConstrainedMeshPlugin::IpoptLhalfSolver::finalize_solution(SolverReturn status,
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

    for (int i = 0; i < o->n_data_pt; ++i)
    {
        for (int j = 0; j < o->n_boundary_pt; ++j)
        {
            o->wud(i, j) = x[i*o->n_boundary_pt + j];
        }
    }

	if (o->controlVariables_)
	{
		//copy the results to control points
		o->optimized_C_mat.setZero(o->n_boundary_pt, o->dim);
		for (int i = 0; i < o->n_boundary_pt; ++i)
		{
			for (int j = 0; j < o->dim; ++j)
			{
				o->optimized_C_mat(i, j) = x[2*o->n_boundary_pt*o->n_data_pt + i*o->dim + j];
			}
		}
	}
}

//half norm minimization
ConstrainedMeshPlugin::IpoptSmoothSolver::IpoptSmoothSolver(ConstrainedMeshPlugin* o_)
:o(o_){}

ConstrainedMeshPlugin::IpoptSmoothSolver::~IpoptSmoothSolver(){}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                          Index& nnz_h_lag, IndexStyleEnum& index_style)
{
    return o->ipoptsmooth_get_nlp_info(n, m, nnz_jac_g, nnz_h_lag, index_style);
}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::get_bounds_info(Index n, Number* x_l, Number* x_u, Index m, Number* g_l, Number* g_u)
{
    return o->ipoptsmooth_get_bounds_info(n, x_l, x_u, m, g_l, g_u);
}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::get_starting_point(Index n, bool init_x, Number* x, bool init_z, Number* z_L, Number* z_U, Index m, bool init_lambda, Number* lambda)
{
    return o->ipoptsmooth_get_starting_point(n, init_x, x, init_z, z_L, z_U, m, init_lambda, lambda);
}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    return o->ipoptsmooth_eval_f(n, x, new_x, obj_value);
}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    return o->ipoptsmooth_eval_grad_f(n, x, new_x, grad_f);
}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
    return o->ipoptsmooth_eval_g(n, x, new_x, m, g);
}

bool ConstrainedMeshPlugin::IpoptSmoothSolver::eval_jac_g(Index n, const Number* x, bool new_x, Index m, Index nele_jac, Index* iRow, Index *jCol, Number* values)
{
    return o->ipoptsmooth_eval_jac_g(n, x, new_x, m, nele_jac, iRow, jCol, values);
}

void ConstrainedMeshPlugin::IpoptSmoothSolver::finalize_solution(SolverReturn status,
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

    for (int i = 0; i < o->n_data_pt; ++i)
    {
        for (int j = 0; j < o->n_boundary_pt; ++j)
        {
            o->init_w(i, j) = x[i*o->n_boundary_pt + j];
        }
    }
}

ConstrainedMeshPlugin::GreenCoordinates::GreenCoordinates(PolyMeshType* forShape, PolyMeshType* usingCage )
{
    this->shape = forShape;
    this->cage = usingCage;

    for (OMesh::VertexIter vIt = cage->vertices_begin(); vIt != cage->vertices_end(); ++vIt)
    {
        orginalCagePos.push_back(cage->point(vIt.handle()));
    }
    for (OMesh::FaceIter fIt = cage->faces_begin(); fIt != cage->faces_end(); ++fIt)
    {
        orginalCageNormal.push_back(cage->normal(fIt.handle()));
    }

    coords.resize(shape->n_vertices());

    // For all points in shape, compute coordinates
    std::vector<Point> shapePoints;
    for (OMesh::VertexIter vIt = shape->vertices_begin(); vIt != shape->vertices_end(); ++vIt)
    {
        shapePoints.push_back(shape->point(vIt.handle()));
    }

    #pragma omp parallel for
    for (int i = 0; i < (int)shapePoints.size(); i++)
    {
        GreenCoordiante gc = computeCoordinates(shapePoints[i]);

        coords[i].coord_v = gc.coord_v;
        coords[i].coord_n = gc.coord_n;
    }
}

ConstrainedMeshPlugin::GreenCoordinates::GreenCoordiante ConstrainedMeshPlugin::GreenCoordinates::computeCoordinates(Point point)
{
    GreenCoordiante gc;

    OMesh::FaceIter fit, fend = cage->faces_end();

    gc.coord_v.resize(cage->n_vertices(), 0);
    gc.coord_n.resize(cage->n_faces(), 0);

    gc.insideCage = true;
    gc.valid = true;

    // For each face in cage
    for(fit = cage->faces_begin(); fit != fend; ++fit)
    {
        Point v[3], s, I, II, N[3], Zero(0, 0, 0);

        std::vector<Point> facePnts;
        std::vector<uint> faceVrts;
        OMesh::FaceVertexIter fv_it = cage->fv_iter(fit.handle());
        faceVrts.push_back(fv_it.handle().idx());
        facePnts.push_back(cage->point(fv_it.handle()));
        ++fv_it;
        faceVrts.push_back(fv_it.handle().idx());
        facePnts.push_back(cage->point(fv_it.handle()));
        ++fv_it;
        faceVrts.push_back(fv_it.handle().idx());
        facePnts.push_back(cage->point(fv_it.handle()));

        uint fi = fit.handle().idx();
        Normal n = orginalCageNormal[fi];

        // 1) First "foreach"
        for (int l = 0; l < 3; l++)
            v[l] = (facePnts[l] - point);

        // 2 ) Assign "p"
        Point p = dot(v[0], n)*n;

        // 3) For each vertex 1, 2, 3
        for (int l = 0; l < 3; l++)
        {
            int l1 = (l + 1)%3;

            double DOT = dot((cross((v[l] - p), (v[l1] - p))), n);
            s[l] = DOT < 0.0 ? -1.0 : 1.0;  // Sign

            I[l] = GCTriInt(p,    v[l], v[l1], Zero);
            II[l] = GCTriInt(Zero, v[l1], v[l], Zero);

            N[l] = cross(v[l1] , v[l]).normalized();
        }

        // 4) Psi
        double& psi = gc.coord_n[fi];
        for (int k = 0; k < 3; k++)
            psi += s[k]*I[k];

        psi = fabs(psi);

        // Robustness check (bug?)
        if(psi != psi)
        {
            gc.valid = false;
            return gc;
        }

        // 5) "w"
        Point w = -psi*n;
        for (int k = 0; k < 3; k++)
            w += II[k]*N[k];

        // 6) Phi
        for (int l = 0; l < 3; l++)
        {
            int l1 = (l + 1)%3;

            double& phi = gc.coord_v[faceVrts[l]];
            phi += dot(N[l1], w)/dot(N[l1], v[l]);
        }
    }

    double coord_v_sum = 0;

    for (int i = 0; i < cage->n_vertices(); ++i)
        coord_v_sum += gc.coord_v[i];

    if(coord_v_sum < 0.5f)
        gc.insideCage = false;

    // Check if vertex is exterior to the cage
    if (!gc.insideCage)
    {
        OMesh::FaceIter closestFace;
        double dist_min = DBL_MAX;

        // find the nearest face (naive, based on Euclid distance)
        for(fit = cage->faces_begin(); fit != fend; ++fit)
        {
            double dist = 0;

            Point faceCenter;
            OMesh::FaceVertexIter fv_it = cage->fv_iter(fit.handle());
            faceCenter = cage->point(fv_it.handle());
            ++fv_it;
            faceCenter += cage->point(fv_it.handle());
            ++fv_it;
            faceCenter += cage->point(fv_it.handle());
            faceCenter /= 3.0;

            dist += (faceCenter - point).norm();

            if (dist < dist_min){
                dist_min = dist;
                closestFace = fit;
            }
        }

        // Get face points and vertex indices
        std::vector<Point> facePnts;
        std::vector<uint> faceVrts;
        OMesh::FaceVertexIter fv_it = cage->fv_iter(closestFace.handle());
        faceVrts.push_back(fv_it.handle().idx());
        facePnts.push_back(cage->point(fv_it.handle()));
        ++fv_it;
        faceVrts.push_back(fv_it.handle().idx());
        facePnts.push_back(cage->point(fv_it.handle()));
        ++fv_it;
        faceVrts.push_back(fv_it.handle().idx());
        facePnts.push_back(cage->point(fv_it.handle()));

        uint fi = closestFace.handle().idx();

        // compute alpha[3] and beta
        Eigen::Matrix4d A;

        for (int i = 0; i < 3; i++){
            Eigen::Vector4d fp;
            fp << facePnts[i].x(), facePnts[i].y(), facePnts[i].z(), 1.0;
            A.col(i) = fp;
        }

        Eigen::Vector4d fn;
        fn << orginalCageNormal[ fi ].x(), orginalCageNormal[ fi ].y(), orginalCageNormal[ fi ].z(), 0.0;
        A.col(3) = fn;

        Eigen::Vector4d pnt;
        pnt << point.x(), point.y(), point.z(), 1.0;

        Eigen::Vector4d x = A.fullPivLu().solve(pnt);

        // Set special coordinates
        for (int i = 0; i < 3; i++)
            gc.coord_v[ faceVrts[i] ] += x[i];
        gc.coord_n[ fi ] += x[3];
    }

    return gc;
}

double ConstrainedMeshPlugin::GreenCoordinates::GCTriInt(const Point& p, const Point& v1, const Point& v2, const Point& e)
{
    const double alpha = acos(RANGED(-1.0, dot((v2 - v1).normalized() , (p - v1).normalized()), 1.0));
    const double beta  = acos(RANGED(-1.0, dot((v1 - p ).normalized() , (v2 -p ).normalized()), 1.0));
    const double lambda = (p - v1).sqrnorm() * sin(alpha) * sin(alpha);
    const double c      = (p - e).sqrnorm();
    const double theta[2] = { M_PI - alpha, M_PI - alpha - beta };

    Eigen::Vector2d I(0, 0);

    for (int i = 0; i < 2; ++i)
    {
        double S = sin(theta[i]);
        double C = cos(theta[i]);

        double sign = S < 0 ? -1.0 : 0 < S ? 1.0 : 0.0;

        if (sign == 0.0)
            I[i] = 0.0;
        else
        {
            double M = (-sign/2.0);
            double N = 2 * sqrt(c) * atan((sqrt(c) * C) / sqrt(lambda + (S * S * c)));
            double O = sqrt(lambda);
            double P = (2 * sqrt(lambda) * S * S) / pow(1.0 - C, 2);
            double denom = ( (c*(1+C) + lambda + sqrt((lambda * lambda) + (lambda * c * S * S)) ));
            double Q = (2 * c * C) / denom;
            double R = 1.0 - Q;

            I[i] = M * (N + (O * log(P * R)));
        }
    }

    double ret = (-0.25/M_PI)*fabs(I[0] - I[1] - sqrt(c)*beta);

    return ret;
}

Q_EXPORT_PLUGIN2(ConstrainedMeshPlugin, ConstrainedMeshPlugin)

}}//namespaces



