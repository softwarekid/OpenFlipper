/*
 * ConstrainedMeshPluginAux.cpp
 *
 *  Created on: Jul 13, 2012
 *      Author: Bailin Deng
 */

#include "ConstrainedMeshPluginAux.h"
#include <fstream>
#include <iostream>
#include <set>
#include <utility>
#include <stdio.h>

namespace Dolphin { namespace plugins {

bool read_vertex_displacement_constraints(const char *filename, std::map< int,  MeshPointType> &vtx_disp)
{
	std::ifstream ifile(filename);
	if(!ifile.is_open()){
		std::cerr << "Unable to open linear constraint file" << std::endl;
		return false;
	}

	vtx_disp.clear();

	int idx;
	double x, y, z;
	while(true){
		ifile >> idx >> x >> y >> z;
		if(ifile.fail()){
			return true;
		}

		vtx_disp[idx] = MeshPointType(x, y, z);
	}

	return true;
}


bool get_next_vertex_handle(PolyMeshType *pmesh, const PolyMeshType::VertexHandle &vh,
		const PolyMeshType::VertexHandle &prev_vh, PolyMeshType::VertexHandle &next_vh)
{
	if(pmesh->is_boundary(vh)){
		if(pmesh->valence(vh) == 3 && pmesh->is_boundary(prev_vh)){
			for(PolyMeshType::VertexVertexIter vv_it = pmesh->vv_iter(vh); vv_it; ++ vv_it){
				PolyMeshType::VertexHandle cur_vh = vv_it.handle();
				if(pmesh->is_boundary(cur_vh) && cur_vh != prev_vh){
					next_vh = cur_vh;
					return true;
				}
			}

			return false;
		}
		else{
			return false;
		}
	}
	else{
		if(pmesh->valence(vh) == 4){
			std::vector<PolyMeshType::VertexHandle> vhs;
			for(PolyMeshType::VertexVertexIter vv_it = pmesh->vv_iter(vh); vv_it; ++ vv_it){
				vhs.push_back(vv_it.handle());
			}

			int prev_vh_idx = std::find(vhs.begin(), vhs.end(), prev_vh) - vhs.begin();
			next_vh = vhs[ (prev_vh_idx + 2) % 4 ];
			return true;
		}
		else{
			return false;
		}
	}
}

void get_3rddiff_polyline_idx(PolyMeshType *pmesh, std::vector< std::vector<int> > &polyline_idx)
{
	PolyMeshType::EdgeIter e_it, e_end = pmesh->edges_end();
	for(e_it = pmesh->edges_begin(); e_it != e_end; ++ e_it){
		PolyMeshType::HalfedgeHandle heh = pmesh->halfedge_handle(e_it, 0);
		PolyMeshType::VertexHandle vh1 = pmesh->from_vertex_handle(heh),
				vh2 = pmesh->to_vertex_handle(heh);
		PolyMeshType::VertexHandle vh0, vh3;

		if(get_next_vertex_handle(pmesh, vh1, vh2, vh0) && get_next_vertex_handle(pmesh, vh2, vh1, vh3)){
			std::vector<int> cur_idx;
			cur_idx.push_back(vh0.idx());
			cur_idx.push_back(vh1.idx());
			cur_idx.push_back(vh2.idx());
			cur_idx.push_back(vh3.idx());
			polyline_idx.push_back(cur_idx);
		}
	}
}


void get_neighboring_vertex_polyline(PolyMeshType *pmesh, const PolyMeshType::VertexHandle &center_vh,
		std::vector< std::vector< int > > &polyline_idx)
{
	if(!pmesh->is_boundary(center_vh)){
		if(pmesh->valence(center_vh) == 4){
			std::vector< PolyMeshType::VertexHandle > neighboring_vtx;
			PolyMeshType::VertexVertexIter vv_it;
			for(vv_it = pmesh->vv_iter(center_vh); vv_it; ++ vv_it){
				neighboring_vtx.push_back(vv_it.handle());
			}

			int n = neighboring_vtx.size();
			int m = n / 2;
			for(int k = 0; k < m; k++){
				std::vector<int> cur_idx;
				cur_idx.push_back(neighboring_vtx[k].idx());
				cur_idx.push_back(center_vh.idx());
				cur_idx.push_back(neighboring_vtx[k+m].idx());
				polyline_idx.push_back(cur_idx);
			}
		}
	}
	else{
		// We assume regular triangulation at the boundary
		if(pmesh->valence(center_vh) == 3){
			std::vector< PolyMeshType::VertexHandle > neighboring_vtx;
			PolyMeshType::VertexVertexIter vv_it;
			for(vv_it = pmesh->vv_iter(center_vh); vv_it; ++ vv_it){
				neighboring_vtx.push_back(vv_it.handle());
			}

			int n = neighboring_vtx.size();
			for(int k = 0; k < n; k++){
				if(pmesh->is_boundary(neighboring_vtx[k]) && pmesh->is_boundary(neighboring_vtx[(k+1)%n])){
					int start_idx = (k+1)%n;
					for(int j = 0; j < n - 2; j++){
						std::vector<int> cur_idx;
						cur_idx.push_back(neighboring_vtx[(start_idx + j)%n].idx());
						cur_idx.push_back(center_vh.idx());
						cur_idx.push_back(neighboring_vtx[(start_idx + j + 2)%n].idx());
						polyline_idx.push_back(cur_idx);
					}

					return;
				}
			}
		}
	}
}

void get_2nddiff_polyline_idx(PolyMeshType *pmesh, std::vector< std::vector<int> > &polyline_idx)
{
	PolyMeshType::VertexIter v_it, v_end = pmesh->vertices_end();
	for(v_it = pmesh->vertices_begin(); v_it != v_end; ++ v_it){
		std::vector< std::vector<int> > idx;
		get_neighboring_vertex_polyline(pmesh, v_it.handle(), idx);
		polyline_idx.insert(polyline_idx.end(), idx.begin(), idx.end());
	}
}



double average_edge_length(PolyMeshType *pmesh)
{
	if(pmesh->n_edges() == 0){
		return 0.0;
	}
	else{
		double L = 0.0;
		PolyMeshType::EdgeIter e_it, e_end(pmesh->edges_end());
		for(e_it = pmesh->edges_begin(); e_it != e_end; ++ e_it){
			L += pmesh->calc_edge_length(e_it);
		}

		return L / pmesh->n_edges();
	}
}


bool load_eigen_info(const char *filename, std::vector< std::vector<double> > &sorted_eigen_vecs)
{
	FILE* fp = fopen(filename, "rb" );
	if(fp == NULL){
		fprintf( stderr, "ERROR: can not open file!!\n" );
		return false;
	}

	std::vector< std::vector<double> > eigen_vecs;
	std::vector< double > eigen_values;

	int num1, num2;

	//read number of eigenvectors
	fread( &num1, sizeof(int), 1, fp );

	//read length of each eigenvector
	fread( &num2, sizeof(int), 1, fp );

	eigen_vecs.resize(num1);
	eigen_values.resize(num1);

	for(int i = 0; i < num1; i++){
		std::vector<double> vec(num2);
		eigen_vecs[i] = vec;

		for(int j = 0; j < static_cast<int>(eigen_vecs[i].size()); j++){
			fread( &(eigen_vecs[i][j]), sizeof(double), 1, fp );
		}
	}

	for(int i = 0; i < num1; i++){
		fread( &(eigen_values[i]), sizeof(double), 1, fp );
	}

	fclose(fp);


	std::set< std::pair<double, int> > sorted_eigen_val;
	for( int i = 0; i < num1; i++ ){
		sorted_eigen_val.insert(std::make_pair(eigen_values[i], i));
	}

	sorted_eigen_vecs.clear();
	for(std::set< std::pair<double, int> >::iterator iter = sorted_eigen_val.begin(); iter != sorted_eigen_val.end(); ++ iter){
		sorted_eigen_vecs.push_back(eigen_vecs[iter->second]);
	}

	return true;
}

bool write_eigen_info(const char *filename, const std::vector< std::vector<double> > &eigen_vecs,
		const std::vector<double> &eigen_values)
{
	FILE* fp = fopen(filename, "wb");
	if(fp == NULL){
		fprintf( stderr, "ERROR: can not open file to write!!\n" );
		return false;
	}

	if(eigen_vecs.empty()){
		return false;
	}

	// Write dimension information
	int num1 = eigen_vecs.size(), num2 = eigen_vecs.front().size();
	fwrite( &num1, sizeof(int), 1, fp );
	fwrite( &num2, sizeof(int), 1, fp );

	// Write eigen-vectors
	for(int i = 0; i < num1; i++){
		for(int j = 0; j < num2; j++){
			fwrite( &(eigen_vecs[i][j]), sizeof(double), 1, fp );
		}
	}

	// Write eigen-values
	for(int i = 0; i < num1; i++){
		fwrite( &(eigen_values[i]), sizeof(double), 1, fp );
	}

	fclose( fp );
	return true;
}


}} //namespaces
