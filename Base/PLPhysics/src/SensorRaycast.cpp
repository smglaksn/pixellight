/*********************************************************\
 *  File: SensorRaycast.cpp                              *
 *
 *  Copyright (C) 2002-2012 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  PixelLight is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PixelLight is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
\*********************************************************/


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLPhysics/SensorRaycast.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLMath;
namespace PLPhysics {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Destructor
*/
SensorRaycast::~SensorRaycast()
{
}

/**
*  @brief
*    Returns the start point
*/
const Vector3 &SensorRaycast::GetStart() const
{
	return m_vStart;
}

/**
*  @brief
*    Sets the start point
*/
void SensorRaycast::SetStart(const Vector3 &vPoint)
{
	m_vStart = vPoint;
}

/**
*  @brief
*    Returns the end point
*/
const Vector3 &SensorRaycast::GetEnd() const
{
	return m_vEnd;
}

/**
*  @brief
*    Sets the end point
*/
void SensorRaycast::SetEnd(const Vector3 &vPoint)
{
	m_vEnd = vPoint;
}


//[-------------------------------------------------------]
//[ Protected functions                                   ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
SensorRaycast::SensorRaycast(World &cWorld, const Vector3 &vStart, const Vector3 &vEnd, uint32 nFlags) : Sensor(cWorld, nFlags),
	m_vStart(vStart),
	m_vEnd(vEnd)
{
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLPhysics
