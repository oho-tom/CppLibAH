/*
 @file string_utility.h
 @brief �����񃆁[�e�B���e�B
*/
#ifndef CPPLIB_STRING_UTILITY_H_
#define CPPLIB_STRING_UTILITY_H_

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
// c header
#include <wchar.h>
// c++ header
#include <string>

/*
 @namespace string_utility
 @brief �����񃆁[�e�B���e�B
*/
namespace string_utility
{
	//! �����w��ϊ�����������ԋp
	std::wstring Format(const wchar_t* format, ...);
};
#endif // CPPLIB_STRING_UTILITY_H_
