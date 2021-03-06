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
*   $Revision: 15828 $                                                       *
*   $LastChangedBy: lyon $                                                *
*   $Date: 2012-11-15 23:34:05 +0800 (Thu, 15 Nov 2012) $                     *
*                                                                            *
\*===========================================================================*/

#ifndef INTEGER_WIDGET_HH
#define INTEGER_WIDGET_HH

#include "ui_IntegerWidget.hh"
#include <QtGui>

class IntegerWidget : public QWidget, public Ui::IntegerWidget
{
  Q_OBJECT

public:
  IntegerWidget(QWidget * parent = 0)
    : QWidget(parent)
  {
    setupUi(this);
  }
  
  signals:
    void widgetShown();
        
  protected:
    void showEvent ( QShowEvent* /*event*/ ) {
      emit widgetShown();
    }
};

#endif // INTEGER_WIDGET_HH
