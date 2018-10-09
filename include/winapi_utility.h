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
#include <vector>

/*
@namespace winapi_utility
@brief ユーティリティ関数群
*/
namespace winapi_utility
{
//! モジュールのディレクトリ取得
extern bool GetModuleDirectory(std::wstring& module_directory);

//! 指定ディレクトリ配下のフォルダリスト作成
extern bool CreateFolderList(const std::wstring& target_directory, const bool& isIncludingSubDirectory, std::vector<std::wstring>& folder_list);
};
#endif // CPPLIB_WINAPI_UTILITY_H_
