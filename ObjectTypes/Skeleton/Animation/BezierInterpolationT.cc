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

#include "AnimationHelper.hh"
#include <utility>

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
std::vector<Scalar> BezierInterpolationT<Scalar>::getValue(Scalar _atX) {
  float bezierParam = AnimationHelper::approximateCubicBezierParameter<Scalar>(_atX, P0_.first, P1_.first, C0_.first, C1_.first);
  return AnimationHelper::evaluateBezier<Scalar>(bezierParam, P0_.second, P1_.second, C0_.second, C1_.second);
}

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
Scalar BezierInterpolationT<Scalar>::getMaxInput() {
  typedef std::vector<Scalar> Scalars;
  
  Scalars p0_x; p0_x.push_back(P0_.first);
  Scalars p1_x; p1_x.push_back(P1_.first);
  Scalars c0_x; c0_x.push_back(C0_.first);
  Scalars c1_x; c1_x.push_back(C1_.first);
  
  return AnimationHelper::evaluateBezier<Scalar>(1.0f, p0_x, p1_x, c0_x, c1_x)[0];
}

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
Scalar BezierInterpolationT<Scalar>::getMinInput() {
  typedef std::vector<Scalar> Scalars;
  
  Scalars p0_x; p0_x.push_back(P0_.first);
  Scalars p1_x; p1_x.push_back(P1_.first);
  Scalars c0_x; c0_x.push_back(C0_.first);
  Scalars c1_x; c1_x.push_back(C1_.first);
  
  return AnimationHelper::evaluateBezier<Scalar>(0.0f, p0_x, p1_x, c0_x, c1_x)[0];
}

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
typename BezierInterpolationT<Scalar>::Point&
BezierInterpolationT<Scalar>::P0(){
  return P0_;
}

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
typename BezierInterpolationT<Scalar>::Point&
BezierInterpolationT<Scalar>::C0(){
  return C0_;
}

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
typename BezierInterpolationT<Scalar>::Point&
BezierInterpolationT<Scalar>::C1(){
  return C1_;
}

//-----------------------------------------------------------------------------------------------------

template<typename Scalar>
typename BezierInterpolationT<Scalar>::Point&
BezierInterpolationT<Scalar>::P1(){
  return P1_;
}

//-----------------------------------------------------------------------------------------------------
