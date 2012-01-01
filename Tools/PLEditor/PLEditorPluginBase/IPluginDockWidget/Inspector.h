/*********************************************************\
 *  File: Inspector.h                                    *
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


#ifndef INSPECTOR_H
#define INSPECTOR_H
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <QDockWidget>
#include <PLEditor/Interfaces/IPluginDockWidget.h>
#include <PLFrontendQt/DataModels/PLIntrospectionModel.h>
#include <QTreeView>

//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLCore{
	class Object;
}

//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLEditorPluginBase {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Editor dock widget plugin interface
*/
class Inspector : public QDockWidget, public PLEditor::IPluginDockWidget {


	//[-------------------------------------------------------]
	//[ Qt definitions (MOC)                                  ]
	//[-------------------------------------------------------]
	Q_OBJECT


	//[-------------------------------------------------------]
	//[ Public virtual PLEditor::IPluginDockWidget methods    ]
	//[-------------------------------------------------------]
	public:
		virtual EType getType() const;
		virtual QString getName() const;
		virtual Qt::DockWidgetArea InitialArea();
		virtual QDockWidget* GetWidget() { return this; }
		virtual PLEditor::IPlugin* Clone() const;
		
		void SetObject(PLCore::Object *Obj);


	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Default constructor
		*/
		Inspector();

		/**
		*  @brief
		*    Destructor
		*/
		virtual ~Inspector();
		
	private:
		QTreeView m_cTreeView;
		PLFrontendQt::DataModels::PLIntrospectionModel m_cModel;
};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLEditorPluginBase


#endif // INSPECTOR_H
