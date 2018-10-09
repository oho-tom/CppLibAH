/*
 @file winapi_utility.cpp
 @brief ���[�e�B���e�B�֐��w�b�_�t�@�C��
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
// ���������[�N���o�錾
//------------------------------------------------------------------------------
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace winapi_utility
{
/*
 @brief ���W���[���̃f�B���N�g���擾
 @param[out] module_directory ���W���[���̃f�B���N�g��
 @retval true ����
 @retval false ���s
*/
bool GetModuleDirectory(std::wstring& module_directory)
{
	wchar_t temporary_path[_MAX_PATH];
	memset(temporary_path, 0x00, sizeof(temporary_path));
	::GetModuleFileNameW(NULL, temporary_path, sizeof(temporary_path));
	// �Ō��\�̈ʒu�����߂�
	wchar_t* last_backslash = wcsrchr(temporary_path, L'\\');
	// ������NULL����������
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
		// �w��t�H���_�ȉ��̃t�H���_���X�g���擾
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
		// �擾�����ꗗ�̐������J�Ԃ�
		//----------------------------------------------------------------------
		BOOL bGotFile = (hFindFolder != INVALID_HANDLE_VALUE);
		while (bGotFile)
		{
			//------------------------------------------------------------------
			// �t�H���_�ł��邩����
			//------------------------------------------------------------------
			if (!(tFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				// ���̏���
				bGotFile = FindNextFileW(hFindFolder, &tFindData);
				continue;
			}
			std::wstring strFolderName(tFindData.cFileName);

			//------------------------------------------------------------------
			// �����ȃt�H���_�����O
			//------------------------------------------------------------------
			if (strFolderName == L"." || strFolderName == L"..")
			{
				// ���̏���
				bGotFile = FindNextFileW(hFindFolder, &tFindData);
				continue;
			}

			// �����p�̕���"\\*"���폜
			if (strTarget.back() == '*')
			{
				strTarget.pop_back();
			}
			if (strTarget.back() == '\\')
			{
				strTarget.pop_back();
			}

			//------------------------------------------------------------------
			// �T�u�t�H���_�p�X�쐬
			//------------------------------------------------------------------
			std::wstring strSubFolder = strTarget + L"\\" + strFolderName;
			//------------------------------------------------------------------
			// �t�H���_�p�X���o�͕ϐ��ɒǉ�
			//------------------------------------------------------------------
			folder_list.push_back(strSubFolder);
			//------------------------------------------------------------------
			// �T�u�t�H���_�ȉ�����
			//------------------------------------------------------------------
			if(isIncludingSubDirectory)
			{
				if (!CreateFolderList(strSubFolder, true, folder_list))
				{
					//--------------------------------------------------------------
					// �����n���h���N���[�Y
					//--------------------------------------------------------------
					FindClose(hFindFolder);
					return false;
				}
			}

			//------------------------------------------------------------------
			// ���̏���
			//------------------------------------------------------------------
			bGotFile = FindNextFileW(hFindFolder, &tFindData);
		}
		//----------------------------------------------------------------------
		// �����n���h���N���[�Y
		//----------------------------------------------------------------------
		FindClose(hFindFolder);
	}
	catch (...)
	{
		// ��O
		return false;
	}
	return true;
}

};