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
*   $Revision: 14996 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2012-07-13 20:37:45 +0800 (Fri, 13 Jul 2012) $                     *
*                                                                            *
\*===========================================================================*/


#ifndef SPLATCLOUDBACKUP_HH
#define SPLATCLOUDBACKUP_HH


//== INCLUDES ====================================================


#include <OpenFlipper/common/BaseBackup.hh>

#include <ObjectTypes/SplatCloud/SplatCloud.hh>


//== CLASS DEFINITION ============================================


/**
 * @brief Class that encapsulates a backup
 */
class SplatCloudBackup : public BaseBackup
{
public:

  SplatCloudBackup( SplatCloudObject *_object, QString _name, UpdateType _type );
  ~SplatCloudBackup();

  //-- BaseBackup --
  void apply();

private:

  SplatCloudObject *splatCloudObject_;
  SplatCloud       *splatCloudBackup_;
};


//================================================================


#endif // SPLATCLOUDBACKUP_HH