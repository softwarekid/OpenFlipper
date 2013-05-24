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
*   $Revision: 15753 $                                                       *
*   $LastChangedBy: moeller $                                                *
*   $Date: 2012-11-02 23:46:03 +0800 (Fri, 02 Nov 2012) $                     *
*                                                                            *
\*===========================================================================*/



//=============================================================================
//
//  CLASS Core - IMPLEMENTATION
//
//=============================================================================


//== INCLUDES =================================================================

#include "CoreWidget.hh"

#include <OpenFlipper/common/GlobalOptions.hh>

#ifdef WIN32
const QString CoreWidget::homePage_ = "qthelp://org.openflipper.user/user/main.html";
#else
const QString CoreWidget::homePage_ = "qthelp://org.openflipper.user/user/index.html";
#endif

//== IMPLEMENTATION ==========================================================

void CoreWidget::showHelpBrowser(const QString &page /*= homePage_*/) {

	if ( OpenFlipper::Options::nogui() )
		return;

	helpWidget_->show();
	helpWidget_->activateWindow();

	emit changeHelpSite(QUrl(page));

}

//=============================================================================