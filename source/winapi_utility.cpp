/*
 @file winapi_utility.cpp
 @brief ユーティリティ関数ヘッダファイル
*/

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
#include "winapi_utility.h"
// windows header
#include <Windows.h>
// this project header
#include "string_utility.h"

//------------------------------------------------------------------------------
// メモリリーク検出宣言
//------------------------------------------------------------------------------
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace winapi_utility
{
/*
 @brief モジュールのパス取得
 @param[out] module_path モジュールのパス
 @retval true 成功
 @retval false 失敗
*/
bool GetModulePath(std::wstring& module_path)
{
	wchar_t temporary_path[_MAX_PATH];
	memset(temporary_path, 0x00, sizeof(temporary_path));
	::GetModuleFileNameW(NULL, temporary_path, sizeof(temporary_path));
	// 最後の\の位置を求める
	wchar_t* last_backslash = wcsrchr(temporary_path, L'\\');
	// 末尾にNULL文字を入れる
	if (last_backslash != NULL)
		temporary_path[(int)(last_backslash - temporary_path)] = 0x00;

	module_path = string_utility::Format(L"%s", temporary_path);

	return true;
}
};