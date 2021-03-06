/*********************************************************\
 *  File: CommandLineOption.inl                          *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
inline CommandLineOption::CommandLineOption() :
	m_nType(OptionParam),
	m_bRequired(false)
{
}

/**
*  @brief
*    Destructor
*/
inline CommandLineOption::~CommandLineOption()
{
}

/**
*  @brief
*    Get option type
*/
inline CommandLineOption::EType CommandLineOption::GetType() const
{
	// Return type
	return m_nType;
}

/**
*  @brief
*    Set option type
*/
inline void CommandLineOption::SetType(EType nType)
{
	// Set type
	m_nType = nType;
}

/**
*  @brief
*    Check if this option is required
*/
inline bool CommandLineOption::IsRequired() const
{
	// Return required-flag
	return m_bRequired;
}

/**
*  @brief
*    Set if this option is required
*/
inline void CommandLineOption::SetRequired(bool bRequired)
{
	// Set required-flag
	m_bRequired = bRequired;
}

/**
*  @brief
*    Get name
*/
inline String CommandLineOption::GetName() const
{
	// Return name
	return m_sName;
}

/**
*  @brief
*    Set name
*/
inline void CommandLineOption::SetName(const String &sName)
{
	// Set name
	m_sName = sName;
}

/**
*  @brief
*    Get short name
*/
inline String CommandLineOption::GetShortName() const
{
	// Return short name
	return m_sShortName;
}

/**
*  @brief
*    Set short name
*/
inline void CommandLineOption::SetShortName(const String &sName)
{
	// Set short name
	m_sShortName = sName;
}

/**
*  @brief
*    Get long name
*/
inline String CommandLineOption::GetLongName() const
{
	// Return long name
	return m_sLongName;
}

/**
*  @brief
*    Set long name
*/
inline void CommandLineOption::SetLongName(const String &sName)
{
	// Set long name
	m_sLongName = sName;
}

/**
*  @brief
*    Get description
*/
inline String CommandLineOption::GetDescription() const
{
	// Return description
	return m_sDescription;
}

/**
*  @brief
*    Set description
*/
inline void CommandLineOption::SetDescription(const String &sDescription)
{
	// Set description
	m_sDescription = sDescription;
}

/**
*  @brief
*    Get default value
*/
inline String CommandLineOption::GetDefault() const
{
	// Return default value
	return m_sDefault;
}

/**
*  @brief
*    Set default value
*/
inline void CommandLineOption::SetDefault(const String &sDefault)
{
	// Set default value
	m_sDefault = sDefault;
}

/**
*  @brief
*    Check if option value is set (either by command line or by default value)
*/
inline bool CommandLineOption::IsSet() const
{
	return (m_sValue.GetLength() > 0);
}

/**
*  @brief
*    Get option value
*/
inline String CommandLineOption::GetValue() const
{
	// Return value
	return m_sValue;
}

/**
*  @brief
*    Set value
*/
inline void CommandLineOption::SetValue(const String &sValue)
{
	// Set value
	m_sValue = sValue;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore
