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
*   $Revision: 12292 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2011-09-08 16:47:22 +0800 (Thu, 08 Sep 2011) $                     *
*                                                                            *
\*===========================================================================*/


#include <QObject>

#include <OpenFlipper/BasePlugin/BaseInterface.hh>
#include <OpenFlipper/BasePlugin/PostProcessorInterface.hh>

#include <ACG/GL/globjects.hh>

class PostProcessorDepthImagePlugin : public QObject, BaseInterface, PostProcessorInterface
{
   Q_OBJECT
   Q_INTERFACES(BaseInterface)
   Q_INTERFACES(PostProcessorInterface)

  public:
   PostProcessorDepthImagePlugin();
  
  public :
    QString name() { return (QString("Depth Image Postprocessor Plugin")); };
    QString description( ) { return (QString(tr("Takes the rendered Image and renders the correspoding depth image to the screen"))); };

    
  public slots:
    QString version() { return QString("1.0"); };
    
  private slots:

    void updateDepthStencilTextureBuffer(ACG::GLState* _glstate);

    void postProcess(ACG::GLState* _glstate);

    QString postProcessorName();

  private:
    /// depthStencil texture buffer
    ACG::Texture2D pDepthStencilTexture_;

    /// Current width of the depthStencil texture buffer
    int     depthStencilTextureBufferWidth_;

    /// Current height of the depthStencil texture buffer
    int     depthStencilTextureBufferHeight_;

};

