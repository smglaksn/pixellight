/*********************************************************\
 *  File: LED.h                                          *
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


#ifndef __PLINPUT_LED_H__
#define __PLINPUT_LED_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLInput/Input/Controls/Control.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLInput {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    LED control
*
*  @remarks
*    An LED control can manage up to 32 LEDs
*/
class LED : public Control {


	//[-------------------------------------------------------]
	//[ Class definition                                      ]
	//[-------------------------------------------------------]
	pl_class(PLINPUT_RTTI_EXPORT, LED, "PLInput", PLInput::Control, "LED control")
		#ifdef PLINPUT_EXPORTS	// The following is only required when compiling PLInput
			// Methods
			pl_method_0(GetLEDs,	pl_ret_type(PLCore::uint32),							"Returns the state of all LEDs as a bit field.",																		"")
			pl_method_1(SetLEDs,	pl_ret_type(void),				PLCore::uint32,			"Set state of all LEDs as a bit field. LED states as first parameter.",													"")
			pl_method_1(IsOn,		pl_ret_type(bool),				int,					"Get LED status. Index of LED (0..31) as first parameter. Returns 'true' if the LED is currently on, else 'false'.",	"")
			pl_method_2(SetOn,		pl_ret_type(void),				int,			bool,	"Set LED status. Index of LED (0..31) as first parameter. 'true' as second parameter, if the LED is on, else 'false'.",	"")
		#endif
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    LED
		*
		*  @param[in] pController
		*    Owning controller, can, but shouldn't be a null pointer
		*  @param[in] sName
		*    Control name
		*  @param[in] sDescription
		*    Control description
		*/
		PLINPUT_API LED(Controller *pController, const PLCore::String &sName, const PLCore::String &sDescription);

		/**
		*  @brief
		*    Copy constructor
		*
		*  @param[in] cOther
		*    Other LED
		*/
		PLINPUT_API LED(const LED &cOther);

		/**
		*  @brief
		*    Destructor
		*/
		PLINPUT_API virtual ~LED();

		/**
		*  @brief
		*    Comparison operator
		*
		*  @param[in] cOther
		*    LED to compare with
		*
		*  @return
		*    'true', if both LEDs are equal, else 'false'
		*/
		PLINPUT_API bool operator ==(const LED &cOther) const;

		/**
		*  @brief
		*    Copy operator
		*
		*  @param[in] cOther
		*    Other LED
		*
		*  @return
		*    Reference to this LED
		*/
		PLINPUT_API LED &operator =(const LED &cOther);

		/**
		*  @brief
		*    Get state of all LEDs as a bit field
		*
		*  @return
		*    LED states
		*/
		PLINPUT_API PLCore::uint32 GetLEDs() const;

		/**
		*  @brief
		*    Set state of all LEDs as a bit field
		*
		*  @param[in] nLEDs
		*    LED states
		*/
		PLINPUT_API void SetLEDs(PLCore::uint32 nLEDs);

		/**
		*  @brief
		*    Get LED status
		*
		*  @param[in] nLED
		*    Index of LED (0..31)
		*
		*  @return
		*    'true', if the LED is currently on, else 'false'
		*/
		PLINPUT_API bool IsOn(int nLED) const;

		/**
		*  @brief
		*    Set LED status
		*
		*  @param[in] nLED
		*    Index of LED (0..31)
		*  @param[in] bOn
		*    'true', if the LED is on, else 'false'
		*/
		PLINPUT_API void SetOn(int nLED, bool bOn);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		PLCore::uint32 m_nLEDs;	/**< State of all LEDs */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLInput


#endif // __PLINPUT_LED_H__
