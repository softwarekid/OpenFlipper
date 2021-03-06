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
*   $Revision: 10745 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2011-01-26 17:23:50 +0800 (Wed, 26 Jan 2011) $                     *
*                                                                            *
\*===========================================================================*/



//=============================================================================
//
//  CLASS CoreWidget - IMPLEMENTATION
//
//=============================================================================


//== INCLUDES =================================================================

// -------------------- mview
#include "CoreWidget.hh"

#include <OpenFlipper/common/GlobalOptions.hh>

//== IMPLEMENTATION ========================================================== 

StackWidgetInfo::StackWidgetInfo(bool _editable,QString _name,QWidget* _widget) :
    editable(_editable),
    name(_name),
    widget(_widget)
{
}

void CoreWidget::slotGetStackWidget( QString _name, QWidget*& _widget) {
  
  for ( uint i = 0 ; i < stackWidgetList_.size(); ++i) {
    if ( stackWidgetList_[i].name == _name ) {
      _widget = stackWidgetList_[i].widget;
      return; 
    }
  }
  
  _widget = 0;
}

void CoreWidget::slotAddStackWidget( QString _name, QWidget* _widget ) {
  QWidget* widget;
  
  slotGetStackWidget( _name, widget );
  
  if ( widget ) {
    emit log(LOGERR,tr("Name already existing"));
    return; 
  }
  
  stackedWidget_->addWidget(_widget);
  stackWidgetList_.push_back( StackWidgetInfo( true, _name , _widget ) );
  
  slotUpdateStackMenu();
}


void CoreWidget::slotUpdateStackWidget( QString _name, QWidget* _widget ) {
   
  QWidget* oldWidget = 0;      
  uint index = 0;
  for ( uint i = 0 ; i < stackWidgetList_.size(); ++i) {
    if ( stackWidgetList_[i].name == _name ) {
      oldWidget = stackWidgetList_[i].widget;
      index = i;
      break;
    }
  }
  
  if ( oldWidget == 0 ) {
    emit log(LOGERR,tr("Did not find widget to update stackwidget"));
    return; 
  }
  
  stackedWidget_->removeWidget( oldWidget );
  stackWidgetList_.erase( stackWidgetList_.begin() + index );
  
  stackedWidget_->addWidget(_widget);
  stackWidgetList_.push_back( StackWidgetInfo( true, _name , _widget ) );
  
  slotUpdateStackMenu();
}

void CoreWidget::slotViewMenuAction( QAction * _action) {
  
  // Get the object Name from the action
  QString objectName = _action->text();
  
  QWidget* widget = 0;      
  for ( uint i = 0 ; i < stackWidgetList_.size(); ++i) {
    if ( stackWidgetList_[i].name == objectName ) {
      widget = stackWidgetList_[i].widget;
      break;
    }
  }
  
  if ( widget == 0 ) {
    emit log(LOGERR,tr("Cannot set Widget"));
    return; 
  }
  
  stackedWidget_->setCurrentWidget ( widget ); 
}

void CoreWidget::slotUpdateStackMenu() {
  // Only create menu if there are more then two widgets
  if ( stackWidgetList_.size() > 1 ) {
    
    if ( stackMenu_ == 0 ) {
      stackMenu_ = new QMenu(tr("Views"));
      menuBar()->addMenu(stackMenu_ );
    }
  
    
    if ( ! stackMenu_->isEmpty() )
      stackMenu_->clear();
  
    // Create an action group for every view
    QActionGroup* actionGroup = new QActionGroup( stackMenu_ );
    actionGroup->setExclusive( true );
    
    for ( uint i = 0 ; i < stackWidgetList_.size() ; ++i ) {
      QAction* newAction = new QAction(stackWidgetList_[i].name, actionGroup);  
      newAction->setText(stackWidgetList_[i].name);
    }
    
    stackMenu_->addActions(actionGroup->actions());   
    
    // Connect this actiongoup to a slot
    connect( actionGroup, SIGNAL( triggered( QAction * ) ), this, SLOT( slotViewMenuAction( QAction * ) ) );
  
    stackMenu_->show();
  } else {
    // Only One widget left, so delete the switching menu
    if ( stackMenu_ != 0 ) {
      
      // remove menu from menuBar
      menuBar()->removeAction( stackMenu_->menuAction() );
      delete stackMenu_;
      
      stackMenu_ = 0;
    }
  }
}


//=============================================================================
