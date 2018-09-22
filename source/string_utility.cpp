/*
 @file string_utility.cpp
 @brief 文字列ユーティリティ
*/

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
#include "string_utility.h"
// c header
#include <stdarg.h>

/*
 @namespace string_utility
 @brief 文字列ユーティリティ
*/
namespace string_utility
{
/*
 @brief 書式指定変換した文字列返却
 @param[in] format 書式指定文字列
 @param[in] ... 可変個引数
 @retval 書式指定変換した文字列
*/
std::wstring Format(const wchar_t* format, ...)
{
	wchar_t formatted_string[4096];
	va_list args;
	va_start(args, format);
	vswprintf_s(formatted_string, format, args);
	va_end(args);
	return formatted_string;
}

};