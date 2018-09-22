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
 @brief ���W���[���̃p�X�擾
 @param[out] module_path ���W���[���̃p�X
 @retval true ����
 @retval false ���s
*/
bool GetModulePath(std::wstring& module_path)
{
	wchar_t temporary_path[_MAX_PATH];
	memset(temporary_path, 0x00, sizeof(temporary_path));
	::GetModuleFileNameW(NULL, temporary_path, sizeof(temporary_path));
	// �Ō��\�̈ʒu�����߂�
	wchar_t* last_backslash = wcsrchr(temporary_path, L'\\');
	// ������NULL����������
	if (last_backslash != NULL)
		temporary_path[(int)(last_backslash - temporary_path)] = 0x00;

	module_path = string_utility::Format(L"%s", temporary_path);

	return true;
}
};