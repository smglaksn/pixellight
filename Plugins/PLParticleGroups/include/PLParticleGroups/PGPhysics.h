/*********************************************************\
 *  File: PGPhysics.h                                    *
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


#ifndef __PLPG_PGPHYSICS_H__
#define __PLPG_PGPHYSICS_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLParticleGroups/SNParticleGroup.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLParticleGroups {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Abstract physics particle group base class
*/
class PGPhysics : public SNParticleGroup {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(PLPG_RTTI_EXPORT, PGPhysics, "PLParticleGroups", PLParticleGroups::SNParticleGroup, "Abstract physics particle group base class")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Returns the gravity vector
		*
		*  @return
		*    The gravity vector of the physics world this scene node is in, if no
		*    physics world was found (0.0, -9.81, 0.0) is returned instead
		*/
		PLPG_API PLMath::Vector3 GetGravity() const;


	//[-------------------------------------------------------]
	//[ Protected functions                                   ]
	//[-------------------------------------------------------]
	protected:
		/**
		*  @brief
		*    Default constructor
		*/
		PLPG_API PGPhysics();

		/**
		*  @brief
		*    Destructor
		*/
		PLPG_API virtual ~PGPhysics();


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLParticleGroups


#endif // __PLPG_PGPHYSICS_H__
