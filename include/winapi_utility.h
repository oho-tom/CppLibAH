/*
 @file winapi_utility.h
 @brief ユーティリティ関数ヘッダファイル
*/
#ifndef CPPLIB_WINAPI_UTILITY_H_
#define CPPLIB_WINAPI_UTILITY_H_

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
// c++ header
#include <string>

/*
@namespace winapi_utility
@brief ユーティリティ関数群
*/
namespace winapi_utility
{
//! モジュールのディレクトリ取得
extern bool GetModuleDirectory(std::wstring& module_directory);
};
#endif // CPPLIB_WINAPI_UTILITY_H_
