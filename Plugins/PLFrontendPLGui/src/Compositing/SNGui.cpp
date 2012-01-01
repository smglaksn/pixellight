/*********************************************************\
 *  File: SNGui.cpp                                      *
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
#include <PLGui/Gui/Gui.h>
#include <PLRenderer/RendererContext.h>
#include <PLScene/Scene/SceneContext.h>
#include <PLEngine/Application/EngineApplication.h>
#include "PLFrontendPLGui/Compositing/GuiPL.h"
#include "PLFrontendPLGui/Compositing/SNGui.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLRenderer;
using namespace PLScene;
namespace PLFrontendPLGui {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(SNGui)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Default constructor
*/
SNGui::SNGui() :
	EventHandlerUpdate(&SNGui::OnUpdate, this),
	m_pGui(nullptr),
	m_bFocus(true)
{
	// Set draw function flags
	SetDrawFunctionFlags(static_cast<uint8>(GetDrawFunctionFlags() | UseDrawPost));
}

/**
*  @brief
*    Destructor
*/
SNGui::~SNGui()
{
	// Destroy the GUI
	if (m_pGui) {
		delete m_pGui;
		m_pGui = nullptr;
	}
}

/**
*  @brief
*    Returns the GUI
*/
PLGui::Gui *SNGui::GetGui() const
{
	return m_pGui;
}

/**
*  @brief
*    Returns whether this GUI has the focus or not
*/
bool SNGui::HasFocus() const
{
	return m_bFocus;
}

/**
*  @brief
*    Sets whether this GUI has the focus or not
*/
void SNGui::SetFocus(bool bFocus)
{
	m_bFocus = bFocus;
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Called when the scene node needs to be updated
*/
void SNGui::OnUpdate()
{
	// Get the PixelLight ingame GUI implementation
	GuiPL *pGuiPL = static_cast<GuiPL*>(m_pGui->GetImpl());
	if (pGuiPL) {
		// Check if there are system messages waiting
		if (m_pGui->HasPendingMessages())
			m_pGui->ProcessMessages();

		// Update the ingame GUI
		pGuiPL->Update();
	}
}


//[-------------------------------------------------------]
//[ Public virtual PLScene::SceneNode functions           ]
//[-------------------------------------------------------]
void SNGui::DrawPost(Renderer &cRenderer, const VisNode *pVisNode)
{
	if (m_pGui) {
		// Call base implementation
		SceneNode::DrawPost(cRenderer, pVisNode);

		// Get the PixelLight ingame GUI implementation
		GuiPL *pGuiPL = static_cast<GuiPL*>(m_pGui->GetImpl());
		if (pGuiPL) {
			// Draw the ingame GUI
			pGuiPL->Render();
		}
	}
}


//[-------------------------------------------------------]
//[ Private virtual PLScene::SceneNode functions          ]
//[-------------------------------------------------------]
void SNGui::InitFunction()
{
	// Call base implementation
	SceneNode::InitFunction();

	// Create the GUI
	if (!m_pGui) {
		m_pGui = new PLGui::Gui("PLFrontendPLGui::GuiPL");

		// [TODO] The GUI already needs a renderer instance during the initialization...
		// Get the PixelLight ingame GUI implementation
		GuiPL *pGuiPL = static_cast<GuiPL*>(m_pGui->GetImpl());
		if (pGuiPL) {
			pGuiPL->m_pRenderer = &GetSceneContext()->GetRendererContext().GetRenderer();
			CoreApplication *pCoreApplication = CoreApplication::GetApplication();
			if (pCoreApplication && pCoreApplication->IsInstanceOf("PLEngine::EngineApplication")) {
				pGuiPL->SetInputController(static_cast<PLEngine::EngineApplication*>(pCoreApplication)->GetInputController());
			}
		}
	}

	// Connect/disconnect event handler
	SceneContext *pSceneContext = GetSceneContext();
	if (pSceneContext)
		pSceneContext->EventUpdate.Connect(EventHandlerUpdate);
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLFrontendPLGui
