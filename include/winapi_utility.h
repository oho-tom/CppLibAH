/*
 @file winapi_utility.h
 @brief ���[�e�B���e�B�֐��w�b�_�t�@�C��
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
@brief ���[�e�B���e�B�֐��Q
*/
namespace winapi_utility
{
//! ���W���[���̃f�B���N�g���擾
extern bool GetModuleDirectory(std::wstring& module_directory);

//! �w��f�B���N�g���z���̃t�H���_���X�g�쐬
extern bool CreateFolderList(const std::wstring& strDir, std::vector<std::wstring>& vFolderList);
};
#endif // CPPLIB_WINAPI_UTILITY_H_
