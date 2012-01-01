/*********************************************************\
 *  File: AbstractLifecycle.cpp                          *
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
#include "PLCore/Core/AbstractLifecycle.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Protected functions                                   ]
//[-------------------------------------------------------]
/**
*  @brief
*    Default constructor
*/
AbstractLifecycle::AbstractLifecycle()
{
}

/**
*  @brief
*    Destructor
*/
AbstractLifecycle::~AbstractLifecycle()
{
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Copy constructor
*/
AbstractLifecycle::AbstractLifecycle(const AbstractLifecycle &cSource)
{
	// No implementation because the copy constructor is never used
}

/**
*  @brief
*    Copy operator
*/
AbstractLifecycle &AbstractLifecycle::operator =(const AbstractLifecycle &cSource)
{
	// No implementation because the copy operator is never used
	return *this;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore
