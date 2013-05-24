/*
 * ConstrainedMeshPluginTypedef.h
 *
 *  Created on: Jul 13, 2012
 *      Author: Bailin Deng
 */

#ifndef CONSTRAINEDMESHPLUGINTYPEDEF_H_
#define CONSTRAINEDMESHPLUGINTYPEDEF_H_

#include <Dolphin/Core/DataStructures/OMesh.h>

// GMM matrix library
#include <gmm/gmm.h>
#include <gmm/gmm_iter_solvers.h>

namespace Dolphin {

namespace plugins {

typedef Dolphin::OMesh PolyMeshType;
typedef Dolphin::defines::Vector3 MeshPointType;
typedef Dolphin::VertexGeometry::BaseVertexIterator VertexIterator;
typedef Dolphin::defines::Vector3 Point;
typedef Dolphin::defines::Vector3 Normal;
typedef gmm::row_matrix< gmm::wsvector<double> > RowSparseMatrix;
#define RANGED(min, v, max) ( Max(min, Min(v, max)) )
}

}

#endif /* CONSTRAINEDMESHPLUGINTYPEDEF_H_ */
