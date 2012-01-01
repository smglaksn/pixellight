/*********************************************************\
 *  File: MousePicking.cpp                               *
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
#include <PLCore/Frontend/Frontend.h>
#include <PLMath/Vector2i.h>
#include <PLMath/Rectangle.h>
#include <PLScene/Scene/SNCamera.h>
#include "PLEngine/Picking/MousePicking.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLMath;
using namespace PLScene;
namespace PLEngine {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
MousePicking::MousePicking(Frontend &cFrontend, SNCamera *pCamera) :
	EventHandlerCameraDestroy(&MousePicking::OnCameraDestroy, this),
	m_pFrontend(&cFrontend),
	m_pCamera(pCamera)
{
}

/**
*  @brief
*    Destructor
*/
MousePicking::~MousePicking()
{
}

/**
*  @brief
*    Returns the frontend instance used to determine the mouse position
*/
Frontend &MousePicking::GetFrontend() const
{
	return *m_pFrontend;
}

/**
*  @brief
*    Returns the camera to perform the picking with
*/
SNCamera *MousePicking::GetCamera() const
{
	return m_pCamera;
}

/**
*  @brief
*    Sets the camera to perform the picking with
*/
void MousePicking::SetCamera(SNCamera *pCamera)
{
	// Disconnect event handler
	if (m_pCamera)
		m_pCamera->SignalDestroy.Disconnect(EventHandlerCameraDestroy);

	// Set new camera
	m_pCamera = pCamera;

	// Connect event handler
	if (m_pCamera)
		m_pCamera->SignalDestroy.Connect(EventHandlerCameraDestroy);
}

/**
*  @brief
*    Performs picking by using the current camera and current mouse position within the widget
*/
bool MousePicking::PerformMousePicking(PickingResult &cPickingResult, float fMaxDistance)
{
	// Is there a camera?
	if (m_pCamera) {
		// Get current mouse cursor position inside the frontend
		const Vector2i vMousePos(m_pFrontend->GetMousePositionX(), m_pFrontend->GetMousePositionY());

		// Return the picked scene node
		return PerformMousePicking(cPickingResult, vMousePos, fMaxDistance);
	}

	// Error!
	return false;
}

/**
*  @brief
*    Performs picking by using the current camera and the given mouse position
*/
bool MousePicking::PerformMousePicking(PickingResult &cPickingResult, const Vector2i &vMousePos, float fMaxDistance)
{
	// Don't do picking if mouse is outside the frontend - or there's no widget and/or camera at all
	if (m_pCamera && m_pCamera->GetContainer() &&
		vMousePos.x >= 0 && vMousePos.x < static_cast<int>(m_pFrontend->GetWidth()) &&
		vMousePos.y >= 0 && vMousePos.y < static_cast<int>(m_pFrontend->GetHeight())) {
		// Trace line from the camera position to the mouse world position

		// Get the viewport rectangle
		Rectangle cViewport(0.0f, 0.0f, static_cast<float>(m_pFrontend->GetWidth()), static_cast<float>(m_pFrontend->GetHeight()));

		// Get picking line start and end
		Vector3 v2DPos(static_cast<float>(vMousePos.x), static_cast<float>(vMousePos.y), 0.0f);
		Vector3 vLineStartPos = v2DPos.To3DCoordinate(m_pCamera->GetProjectionMatrix(cViewport),
													  m_pCamera->GetViewMatrix(),
													  Matrix4x4::Identity,
													  cViewport);
		v2DPos.z = 1.0f;
		Vector3 vLineEndPos = v2DPos.To3DCoordinate(m_pCamera->GetProjectionMatrix(cViewport),
													m_pCamera->GetViewMatrix(),
													Matrix4x4::Identity,
													cViewport);

		// Is there a maximum picking distance?
		if (fMaxDistance >= 0.0f)
			vLineEndPos = vLineStartPos + (vLineEndPos-vLineStartPos).Normalize()*fMaxDistance;

		// Perform picking and return the result
		return PerformPicking(cPickingResult, *m_pCamera->GetContainer(), vLineStartPos, vLineEndPos);
	}

	// Error!
	return false;
}

/**
*  @brief
*    Called when a camera was destroyed
*/
void MousePicking::OnCameraDestroy()
{
	m_pCamera = nullptr;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLEngine
