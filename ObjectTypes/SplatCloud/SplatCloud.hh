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
*   $Revision: 14246 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2012-03-21 22:12:50 +0800 (Wed, 21 Mar 2012) $                     *
*                                                                            *
\*===========================================================================*/

/**
 * \file ObjectTypes/SplatCloud/SplatCloud.hh
 * This File contains all required includes for using SplatClouds
 */


#ifndef SPLATCLOUD_INCLUDE_HH
#define SPLATCLOUD_INCLUDE_HH


//== DEFINES =====================================================

/** \def DATA_SPLATCLOUD
 * Use this macro to reference Splat Clouds
 */
#define DATA_SPLATCLOUD typeId( "SplatCloud" )


//== INCLUDES ====================================================


#include <ObjectTypes/SplatCloud/SplatCloudObject.hh>

#include <ObjectTypes/SplatCloud/PluginFunctionsSplatCloud.hh>

#include <ObjectTypes/SplatCloud/SplatCloudTypes.hh>


//================================================================


#endif // SPLATCLOUD_INCLUDE_HH