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
*   $Revision: 12750 $                                                       *
*   $LastChangedBy: kremer $                                                *
*   $Date: 2011-11-04 00:32:34 +0800 (Fri, 04 Nov 2011) $                    *
*                                                                            *
\*===========================================================================*/

#ifndef PROGRESSEMITTER_HH
#define PROGRESSEMITTER_HH

#include <QObject>
#include <OpenFlipper/BasePlugin/PluginFunctions.hh>

class ProgressEmitter : public QObject
{
  Q_OBJECT
  
  signals:
    void signalJobState(QString _jobId, int _value);
    void changeDescription(QString _jobId, QString _description);

    void backupRequest(int _objId, QString _desc);
  
  public:
    ProgressEmitter() : valid_(false) {}
    
    void attachJob(const QString& _jobId) {
        jobId_ = _jobId;
        valid_ = true;
    }

    void detachJob() {
        jobId_ = "";
        valid_ = false;
    }

    void sendProgressSignal(double _percent) {
        if(!valid_) return;
        emit signalJobState(jobId_, (int)_percent);
//       std::cerr << "Job State for " << jobId_.toStdString() << ": " << (int)_percent << "%" << std::endl;
    }
    
    void sendChangeDescriptionSignal(QString _description) {
        if(!valid_) return;
        emit changeDescription(jobId_, _description);
//       std::cerr << "Job description for " << jobId_.toStdString() << ": '" << _description.toStdString() << "'" << std::endl;
    }

  private:
    QString jobId_;

    bool valid_;
};


#endif //PROGRESSEMITTER_HH