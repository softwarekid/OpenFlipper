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
*   $Revision: 11730 $                                                       *
*   $LastChangedBy: moebius $                                                *
*   $Date: 2011-06-06 20:21:52 +0800 (Mon, 06 Jun 2011) $                     *
*                                                                            *
\*===========================================================================*/

#include "ImageStorage.hh"

#include <iostream>
#include <OpenFlipper/common/GlobalOptions.hh>

static ImageStore store;

ImageStore& imageStore() {
  return store;
}

// ---------------------------------------------------------------------------

ImageStore::ImageStore():
    nextId_(1)
{
}

// ---------------------------------------------------------------------------

int ImageStore::addImageFile( QString _fileName ) {

  // Clean error string
  errorString_ = "No error";

  QString loadFilename;

  // Construct complete filename
  // if it starts with "/" or "." or contains a ":" it is a global filename and we don't touch it
  // otherwise we take a relative path from our texture dir
  if ( _fileName.startsWith("/") || _fileName.startsWith(".") || _fileName.contains(":") )
    loadFilename = _fileName;
  else
    loadFilename = OpenFlipper::Options::textureDirStr() + QDir::separator() + _fileName;

  // Check if it already exists and return the existing one rather than recreating a new one
  if ( filenameMap_.count(loadFilename) > 0 ) {

    // Get id of the existing image
    int existingId = filenameMap_[loadFilename];

    // Update refcount
    refCount_[existingId] = refCount_[existingId] + 1;

    // Return existing ones id
    return existingId;
  }

  QFile file(loadFilename);
  if ( !file.exists() ) {
    errorString_ =  "addedEmptyObject: Cannot load global texture '"+ loadFilename +"'. File not found!" ;
    return -1;

  }

  QImage image;

  //QImage cannot handle tga directly
  if ( QFileInfo(loadFilename).suffix().toLower() == "tga" ){

    QPixmap pic(loadFilename);
    image = pic.toImage();

  } else {
    //load the image
    if ( !image.load( loadFilename ) ){
      errorString_ = "Unable to load Image from file " + loadFilename;
      return -1;
    }
  }

  // Store the mapping from filename to id
  filenameMap_[loadFilename]= nextId_;
  reverseFilenameMap_[nextId_] = loadFilename;

  // Initialize refcount
  refCount_[nextId_] = 1;

  // Store image
  imageMap_[nextId_] = image;

  // Increment for next image
  nextId_++;

  // return the id of the added one
  return (nextId_ - 1);


}

// ---------------------------------------------------------------------------

int  ImageStore::addImage( QImage _image ) {

  // No filename mapping as it does not have a filename

  // Initialize refcount
  refCount_[nextId_] = 1;

  // Store image
  imageMap_[nextId_] = _image;

  // Increment for next image
  nextId_++;

  // return the id of the added one
  return (nextId_ - 1);
}

// ---------------------------------------------------------------------------

int  ImageStore::getImageID(QString _filename) {

  // Check if it already exists and return the existing one rather than recreating a new one
  if ( filenameMap_.count(_filename) > 0 ) {
    return filenameMap_[_filename];
  }

  // Clean error string
  errorString_ = "getImageID failed. No such image :" + _filename;

  return -1;

}

// ---------------------------------------------------------------------------

QImage& ImageStore::getImage(int _id, bool* _ok) {

  if ( imageMap_.count(_id) > 0 ) {
    if ( _ok)
      *_ok = true;
    return imageMap_[_id];
  } else {
    if ( _ok)
      *_ok = false;
    errorString_ = "getImage: Unknown image id : " + QString::number(_id);
    return dummy_;
  }
}

// ---------------------------------------------------------------------------

void ImageStore::removeImage(int _id) {

  // Check if it exists
  if ( refCount_.count(_id) > 0 ) {
    if ( refCount_[_id] > 1 ) {
      refCount_[_id] = refCount_[_id] - 1;
      return;
    } else {

      // Remove from refCount
      refCount_.remove(_id);
      imageMap_.remove(_id);

      // This image is from a file and not directly added
      if ( reverseFilenameMap_.count(_id) > 0 )  {

        // Get the filename
        QString fileName = reverseFilenameMap_[_id];

        reverseFilenameMap_.remove(_id);
        filenameMap_.remove(fileName);

      }

    }
  }
}














