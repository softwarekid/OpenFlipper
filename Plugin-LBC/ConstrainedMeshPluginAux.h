/*
 * ConstrainedMeshPluginAux.h
 *
 *  Auxiliary routines for constrained mesh plugin
 *
 *  Created on: Jul 13, 2012
 *      Author: Bailin Deng
 */

#ifndef CONSTRAINEDMESHPLUGINAUX_H_
#define CONSTRAINEDMESHPLUGINAUX_H_

#include "ConstrainedMeshPluginTypedef.h"
#include <map>

namespace Dolphin {

namespace plugins {

bool read_vertex_displacement_constraints(const char *filename, std::map< int,  MeshPointType > &vtx_disp);

void get_3rddiff_polyline_idx(PolyMeshType *pmesh, std::vector< std::vector<int> > &polyline_idx);

void get_2nddiff_polyline_idx(PolyMeshType *pmesh, std::vector< std::vector<int> > &polyline_idx);

double average_edge_length(PolyMeshType *pmesh);

bool load_eigen_info(const char *filename, std::vector< std::vector<double> > &sorted_eigen_vecs);

bool write_eigen_info(const char *filename, const std::vector< std::vector<double> > &eigen_vecs,
		const std::vector<double> &eigen_values);

}
}


#endif /* CONSTRAINEDMESHPLUGINAUX_H_ */
