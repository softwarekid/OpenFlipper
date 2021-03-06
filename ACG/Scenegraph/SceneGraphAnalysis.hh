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
*   $Revision: 15112 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2012-07-26 00:23:39 +0800 (Thu, 26 Jul 2012) $                     *
*                                                                            *
\*===========================================================================*/

#ifndef SCENEGRAPHANALYSIS_HH
#define SCENEGRAPHANALYSIS_HH

#include <ACG/Config/ACGDefines.hh>
#include <ACG/GL/GLState.hh>
#include <ACG/Scenegraph/SceneGraph.hh>


/** \file SceneGraphAnalysis.hh
 *
 *   This file contains some convenience functions to traverse the scenegraph and
 *   collect various of its properties
 *
 */

//== INCLUDES =================================================================

//== NAMESPACES ===============================================================

namespace ACG {
namespace SceneGraph {

//== FORWARDDECLARATIONS ======================================================

ACGDLLEXPORT
void analyzeSceneGraph(ACG::SceneGraph::BaseNode* _root,
                       unsigned int&              _maxPasses,
                       ACG::Vec3d&                _bbmin,
                       ACG::Vec3d&                _bbmax);

//=============================================================================
} // namespace SceneGraph
} // namespace ACG
//=============================================================================
#endif //SCENEGRAPHANALYSIS_HH
