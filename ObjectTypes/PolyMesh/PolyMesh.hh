/*===========================================================================*\
*                                                                            *
*                              OpenFlipper                                   *
*      Copyright (C) 2001-2011 by Computer Graphics Group, RWTH Aachen       *
*                           www.openflipper.org                              *
*                                                                            *
*--------------------------------------------------------------------------- *
*  This file is part of OpenFlipper.                                         *
*                                                                            *
*  OpenFlipper is free software: you can redistribute it and/or modify       *
*  it under the terms of the GNU Lesser General Public License as            *
*  published by the Free Software Foundation, either version 3 of            *
*  the License, or (at your option) any later version with the               *
*  following exceptions:                                                     *
*                                                                            *
*  If other files instantiate templates or use macros                        *
*  or inline functions from this file, or you compile this file and          *
*  link it with other files to produce an executable, this file does         *
*  not by itself cause the resulting executable to be covered by the         *
*  GNU Lesser General Public License. This exception does not however        *
*  invalidate any other reasons why the executable file might be             *
*  covered by the GNU Lesser General Public License.                         *
*                                                                            *
*  OpenFlipper is distributed in the hope that it will be useful,            *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
*  GNU Lesser General Public License for more details.                       *
*                                                                            *
*  You should have received a copy of the GNU LesserGeneral Public           *
*  License along with OpenFlipper. If not,                                   *
*  see <http://www.gnu.org/licenses/>.                                       *
*                                                                            *
\*===========================================================================*/

/*===========================================================================*\
*                                                                            *
*   $Revision: 13619 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2012-02-01 21:48:01 +0800 (Wed, 01 Feb 2012) $                     *
*                                                                            *
\*===========================================================================*/


/**
 * \file PolyMesh.hh
 * This File contains all required includes for using Polygon Meshes
*/

#ifndef POLY_MESH_INCLUDE_HH
#define POLY_MESH_INCLUDE_HH


//== INCLUDES =================================================================

/** \def DATA_POLY_MESH
 * Use this macro to reference polygonal meshes.
 */
#define DATA_POLY_MESH typeId("PolyMesh")
#include <ObjectTypes/MeshObject/MeshObjectT.hh>
#include <ObjectTypes/PolyMesh/PolyMeshTypes.hh>

/// Typedef for a Meshobject containing a poly mesh
typedef MeshObject< PolyMesh >    PolyMeshObject;

#include <ObjectTypes/PolyMesh/PluginFunctionsPolyMesh.hh>



//=============================================================================
#endif // POLY_MESH_INCLUDE_HH defined
//=============================================================================

