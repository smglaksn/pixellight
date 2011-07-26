/*********************************************************\
 *  File: SearchFilterWildcard.h                         *
 *
 *  Copyright (C) 2002-2011 The PixelLight Team (http://www.pixellight.org/)
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


#ifndef __PLCORE_FILE_SEARCHFILTERWILDCARD_H__
#define __PLCORE_FILE_SEARCHFILTERWILDCARD_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/String/String.h"
#include "PLCore/File/SearchFilter.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Search filter working with wildcards (e.g. "*.txt", "pixel?ight.*")
*/
class SearchFilterWildcard : public SearchFilter {


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] sFilter
		*    Search filter (e.g. "*.txt")
		*/
		PLCORE_API SearchFilterWildcard(const String &sFilter);

		/**
		*  @brief
		*    Destructor
		*/
		PLCORE_API virtual ~SearchFilterWildcard();

		/**
		*  @brief
		*    Get filter string
		*
		*  @return
		*    Filter
		*/
		PLCORE_API String GetFilter() const;


	//[-------------------------------------------------------]
	//[ Public virtual SearchFilter functions                 ]
	//[-------------------------------------------------------]
	public:
		PLCORE_API virtual bool CheckFile(const String &sFilename);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		String m_sFilter;	/**< Filter string */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


#endif // __PLCORE_FILE_SEARCHFILTERWILDCARD_H__