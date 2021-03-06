/*===========================================================================*\
 *                                                                           *
 *                              OpenFlipper                                  *
 *      Copyright (C) 2001-2011 by Computer Graphics Group, RWTH Aachen      *
 *                           www.openflipper.org                             *
 *                                                                           *
 *---------------------------------------------------------------------------*
 *  This file is part of OpenFlipper.                                        *
 *                                                                           *
 *  OpenFlipper is free software: you can redistribute it and/or modify      *
 *  it under the terms of the GNU Lesser General Public License as           *
 *  published by the Free Software Foundation, either version 3 of           *
 *  the License, or (at your option) any later version with the              *
 *  following exceptions:                                                    *
 *                                                                           *
 *  If other files instantiate templates or use macros                       *
 *  or inline functions from this file, or you compile this file and         *
 *  link it with other files to produce an executable, this file does        *
 *  not by itself cause the resulting executable to be covered by the        *
 *  GNU Lesser General Public License. This exception does not however       *
 *  invalidate any other reasons why the executable file might be            *
 *  covered by the GNU Lesser General Public License.                        *
 *                                                                           *
 *  OpenFlipper is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU Lesser General Public License for more details.                      *
 *                                                                           *
 *  You should have received a copy of the GNU LesserGeneral Public          *
 *  License along with OpenFlipper. If not,                                  *
 *  see <http://www.gnu.org/licenses/>.                                      *
 *                                                                           *
\*===========================================================================*/

/*===========================================================================*\
 *                                                                           *
 *   $Revision: 10745 $                                                       *
 *   $Author: moebius $                                                      *
 *   $Date: 2011-01-26 17:23:50 +0800 (Wed, 26 Jan 2011) $                   *
 *                                                                           *
\*===========================================================================*/



//=============================================================================
//
//  CLASS GlutExaminer
//
//=============================================================================


#ifndef ACG_GLUTEXAMINER_HH
#define ACG_GLUTEXAMINER_HH


//== INCLUDES =================================================================


#include "GlutViewer.hh"
#include "../GL/GLTrackball.hh"
#include "../Config/ACGDefines.hh"


//== NAMESPACES ===============================================================

namespace ACG {

//== CLASS DEFINITION =========================================================



class ACGDLLEXPORT GlutExaminer : public GlutViewer
{
public:

  GlutExaminer(const char* _title, int _width, int _height);
  ~GlutExaminer() {}


  void   setup_scene(const Vec3f& _center, float _radius);
  void   view_all();
  double measure_fps();


protected:

  virtual void init();
  virtual void draw();
  virtual void motion(int x, int y);
  virtual void mouse(int button, int state, int x, int y);
  virtual void keyboard(int key, int x, int y);


protected:

  GLTrackball  trackball_;
  Vec3f        center_;
  float        radius_;
};


//=============================================================================
} // namespace ACG
//=============================================================================
#endif // ACG_GLUTEXAMINER_HH defined
//=============================================================================

