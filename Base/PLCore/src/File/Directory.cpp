/*********************************************************\
 *  File: Directory.cpp                                  *
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
#include "PLCore/File/FileSearch.h"
#include "PLCore/File/Directory.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Create a directory recursively
*/
bool Directory::CreateRecursive()
{
	// Does this directory already exist?
	if (Exists())
		return true; // Done
	else {
		// Get the first path
		String sNextPath;
		uint32 nPathPos = 0;
		String sPath    = GetUrl().GetProtocol() + GetUrl().GetRoot() + GetUrl().GetFirstPath(nPathPos);
		do {
			// Get the directory and check whether it's exist
			Directory cDirectory(sPath);
			if (!cDirectory.Exists()) {
				// Create the directory
				if (!cDirectory.Create())
					return false; // Error!
			}

			// Get the next path
			sNextPath = GetUrl().GetNextPath(nPathPos);
			if (sNextPath.GetLength())
				sPath +=  '/' + sNextPath;
		} while (sNextPath.GetLength());

		// Create this directory
		return Create();
	}
}

/**
*  @brief
*    Returns a file searcher for listing the content of a directory
*/
FileSearch *Directory::Search(const String &sFilter) const
{
	return new FileSearch(*this, sFilter);
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Copy constructor
*/
Directory::Directory(const Directory &cSource)
{
	// No implementation because the copy constructor is never used
}

/**
*  @brief
*    Copy operator
*/
Directory &Directory::operator =(const Directory &cSource)
{
	// No implementation because the copy operator is never used
	return *this;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore
