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
*   $Revision: 15085 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2012-07-25 14:57:39 +0800 (Wed, 25 Jul 2012) $                     *
*                                                                            *
\*===========================================================================*/


//=============================================================================
//
//  Plugin Functions for Planes
//
//=============================================================================

#include <OpenFlipper/common/Types.hh>
#include "Plane.hh"

#include "PluginFunctionsPlane.hh"
#include <OpenFlipper/BasePlugin/PluginFunctions.hh>

namespace PluginFunctions {

// ===============================================================================
// Get objects
// ===============================================================================

bool getObject(  int _identifier , PlaneObject*& _object ) {
  
  if ( _identifier == -1 ) {
    _object = 0;
    return false;
  }

  // Get object by using the map accelerated plugin function
  BaseObjectData* object = 0;
  PluginFunctions::getObject(_identifier,object);

  _object = dynamic_cast< PlaneObject* >(object);
  return ( _object != 0 );
}


// ===============================================================================
// Getting data from objects and casting between them
// ===============================================================================

PlaneNode* planeNode( BaseObjectData* _object ) {
  
  if ( _object->dataType(DATA_PLANE) ) {
    PlaneObject* object = dynamic_cast< PlaneObject* >(_object);
    return object->planeNode();
  } else
    return 0;
}


Plane* plane( BaseObjectData* _object ) {
  if ( _object->dataType(DATA_PLANE) ) {
     PlaneObject* object = dynamic_cast< PlaneObject* >(_object);
     return & object->plane();
   } else
     return 0;
}

PlaneObject* planeObject( BaseObjectData* _object ) {
  if ( ! _object->dataType(DATA_PLANE) )
    return 0;
  return dynamic_cast< PlaneObject* >( _object );
}

PlaneObject* planeObject( int _objectId ) {
  if ( _objectId == -1 ) {
    return 0;
  }

  // Get object by using the map accelerated plugin function
  BaseObjectData* object = 0;
  PluginFunctions::getObject(_objectId,object);

  PlaneObject* plane  = dynamic_cast< PlaneObject* >(object);
  return plane;
}

}
