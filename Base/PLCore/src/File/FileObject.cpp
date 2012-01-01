/*********************************************************\
 *  File: FileObject.cpp                                 *
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
#ifndef DISABLE_ZIP_SUPPORT	// Although not recommended, it's possible to life without ZIP support for minimal builds
	#include "PLCore/File/FileZip.h"
#endif
#include "PLCore/File/FileHttp.h"
#if defined(WIN32)
	#include "PLCore/File/FileWindows.h"
#elif defined(ANDROID)
	#include "PLCore/File/FileAndroid.h"
#elif defined(LINUX)
	#include "PLCore/File/FileLinux.h"
#endif
#include "PLCore/File/FileStdStream.h"
#include "PLCore/File/FileObject.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Assign a new URL
*/
void FileObject::Assign(const Url &cUrl, const FileAccess *pAccess)
{
	// Get URL
	Url cFinalUrl;
	if (cUrl.IsDirectory() && cUrl.GetPath().GetLength()) {
		const String sUrl = cUrl.GetUrl();
		cFinalUrl = sUrl.GetSubstring(0, sUrl.GetLength() - 1);
	} else {
		cFinalUrl = cUrl;
	}
	cFinalUrl.Collapse();

	// Delete existing file implementation
	if (m_pFileImpl) {
		delete m_pFileImpl;
		m_pFileImpl = nullptr;
	}

	// Create file implementation

	// ZIP
	const String sUrlLower = cFinalUrl.GetUrl().ToLower();
	const int nPos = sUrlLower.LastIndexOf(".zip/");
	if (nPos > -1) {
		// Although not recommended, it's possible to life without ZIP support for minimal builds
		#ifndef DISABLE_ZIP_SUPPORT
			const String sZipFile   = cFinalUrl.GetUrl().GetSubstring(0, nPos+4);
			const String sPathInZip = cFinalUrl.GetUrl().GetSubstring(nPos+5);
			m_pFileImpl = new FileZip(cFinalUrl, sZipFile, sPathInZip, pAccess);
		#endif

	// HTTP
	} else if (cFinalUrl.GetProtocol() == "http://") {
		m_pFileImpl = new FileHttp(cUrl, pAccess);

	// System file
	} else {
		#if defined(WIN32)
			m_pFileImpl = new FileWindows(cFinalUrl, pAccess);
		#elif defined(ANDROID)
			m_pFileImpl = new FileAndroid(cFinalUrl, pAccess);
		#elif defined(LINUX)
			m_pFileImpl = new FileLinux(cFinalUrl, pAccess);
		#else
			#error "Unsupported platform"
		#endif
	}
}

/**
*  @brief
*    Assign a new file
*/
void FileObject::Assign(FILE *pFile, uint32 nAccess)
{
	// Delete existing file implementation
	if (m_pFileImpl) {
		delete m_pFileImpl;
		m_pFileImpl = nullptr;
	}

	// Create file implementation
	m_pFileImpl = new FileStdStream(pFile, nAccess);
}

/**
*  @brief
*    Assign a new file
*/
void FileObject::Assign(handle hFile)
{
	// Delete existing file implementation
	if (m_pFileImpl) {
		delete m_pFileImpl;
		m_pFileImpl = nullptr;
	}

	// Create file implementation
	m_pFileImpl = new FileStdStream(hFile);
}


//[-------------------------------------------------------]
//[ Protected functions                                   ]
//[-------------------------------------------------------]
/**
*  @brief
*    Generic implementation of Copy (if system-implementation does not work)
*/
bool FileObject::GenericCopy(const String &sDestination, bool bOverwrite) const
{
	// Check source file
	File cInput(GetUrl());
	if (cInput.Exists()) {
		// Check destination file
		File cOutput(sDestination);
		if (!cOutput.Exists() || bOverwrite) {
			// Try to copy
			bool bSuccess = false;

			// Open the source file
			if (cInput.Open(File::FileRead)) {
				// Open the destination file, create it in case it doesn't exist
				if (cOutput.Open(File::FileWrite | File::FileCreate)) {
					// Copy the content from the source file into the destination file
					char szBuffer[4096];
					while (!cInput.IsEof()) {
						const uint32 nSize = cInput.Read(szBuffer, 1, 4096);
						cOutput.Write(szBuffer, 1, nSize);
					}

					// Close destination file
					cOutput.Close();

					// The file copy step was done successfully
					bSuccess = true;
				}

				// Close source file
				cInput.Close();
			}

			// Return result
			return bSuccess;
		}
	}

	// Error!
	return false;
}

/**
*  @brief
*    Generic implementation of Move (if system-implementation does not work)
*/
bool FileObject::GenericMove(const String &sDestination)
{
	// The "GenericCopy()"-method is intentionally not reused in order to don't create an input file object, twice

	// Check source file
	File cInput(GetUrl());
	if (cInput.Exists()) {
		// Check destination file
		File cOutput(sDestination);
		if (!cOutput.Exists()) {
			// Try to copy
			bool bSuccess = false;

			// Open the source file
			if (cInput.Open(File::FileRead)) {
				// Open the destination file, create it in case it doesn't exist
				if (cOutput.Open(File::FileWrite | File::FileCreate)) {
					// Copy the content from the source file into the destination file
					char szBuffer[4096];
					while (!cInput.IsEof()) {
						const uint32 nSize = cInput.Read(szBuffer, 1, 4096);
						cOutput.Write(szBuffer, 1, nSize);
					}

					// Close destination file
					cOutput.Close();

					// The file copy step was done successfully
					bSuccess = true;
				}

				// Close source file
				cInput.Close();
			}

			// Delete source file and return result
			return bSuccess ? cInput.Delete() : false;
		}
	}

	// Error!
	return false;
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Copy constructor
*/
FileObject::FileObject(const FileObject &cSource) :
	m_pFileImpl(nullptr)
{
	// No implementation because the copy constructor is never used
}

/**
*  @brief
*    Copy operator
*/
FileObject &FileObject::operator =(const FileObject &cSource)
{
	// No implementation because the copy operator is never used
	return *this;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore
