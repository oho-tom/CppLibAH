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
 @brief モジュールのディレクトリ取得
 @param[out] module_directory モジュールのディレクトリ
 @retval true 成功
 @retval false 失敗
*/
bool GetModuleDirectory(std::wstring& module_directory)
{
	wchar_t temporary_path[_MAX_PATH];
	memset(temporary_path, 0x00, sizeof(temporary_path));
	::GetModuleFileNameW(NULL, temporary_path, sizeof(temporary_path));
	// 最後の\の位置を求める
	wchar_t* last_backslash = wcsrchr(temporary_path, L'\\');
	// 末尾にNULL文字を入れる
	if (last_backslash != NULL)
		temporary_path[(int)(last_backslash - temporary_path)] = 0x00;

	module_directory = string_utility::Format(L"%s", temporary_path);

	return true;
}

bool CreateFolderList(const std::wstring& target_directory, const bool& isIncludingSubDirectory, std::vector<std::wstring>& folder_list)
{
	try
	{
		//----------------------------------------------------------------------
		// 指定フォルダ以下のフォルダリストを取得
		//----------------------------------------------------------------------
		WIN32_FIND_DATAW tFindData;
		std::wstring strTarget;
		if (target_directory.back() != '\\') {
			strTarget = target_directory + L"\\*";
		}
		else {
			strTarget = target_directory + L"*";
		}
		HANDLE hFindFolder = FindFirstFileW(strTarget.c_str(), &tFindData);
		//----------------------------------------------------------------------
		// 取得した一覧の数だけ繰返す
		//----------------------------------------------------------------------
		BOOL bGotFile = (hFindFolder != INVALID_HANDLE_VALUE);
		while (bGotFile)
		{
			//------------------------------------------------------------------
			// フォルダであるか判定
			//------------------------------------------------------------------
			if (!(tFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				// 次の情報へ
				bGotFile = FindNextFileW(hFindFolder, &tFindData);
				continue;
			}
			std::wstring strFolderName(tFindData.cFileName);

			//------------------------------------------------------------------
			// 無効なフォルダを除外
			//------------------------------------------------------------------
			if (strFolderName == L"." || strFolderName == L"..")
			{
				// 次の情報へ
				bGotFile = FindNextFileW(hFindFolder, &tFindData);
				continue;
			}

			// 検索用の文字"\\*"を削除
			if (strTarget.back() == '*')
			{
				strTarget.pop_back();
			}
			if (strTarget.back() == '\\')
			{
				strTarget.pop_back();
			}

			//------------------------------------------------------------------
			// サブフォルダパス作成
			//------------------------------------------------------------------
			std::wstring strSubFolder = strTarget + L"\\" + strFolderName;
			//------------------------------------------------------------------
			// フォルダパスを出力変数に追加
			//------------------------------------------------------------------
			folder_list.push_back(strSubFolder);
			//------------------------------------------------------------------
			// サブフォルダ以下検索
			//------------------------------------------------------------------
			if(isIncludingSubDirectory)
			{
				if (!CreateFolderList(strSubFolder, true, folder_list))
				{
					//--------------------------------------------------------------
					// 検索ハンドルクローズ
					//--------------------------------------------------------------
					FindClose(hFindFolder);
					return false;
				}
			}

			//------------------------------------------------------------------
			// 次の情報へ
			//------------------------------------------------------------------
			bGotFile = FindNextFileW(hFindFolder, &tFindData);
		}
		//----------------------------------------------------------------------
		// 検索ハンドルクローズ
		//----------------------------------------------------------------------
		FindClose(hFindFolder);
	}
	catch (...)
	{
		// 例外
		return false;
	}
	return true;
}

};