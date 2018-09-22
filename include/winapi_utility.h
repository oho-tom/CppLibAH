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

/*
@namespace winapi_utility
@brief ���[�e�B���e�B�֐��Q
*/
namespace winapi_utility
{
//! ���W���[���̃p�X�擾
extern bool GetModulePath(std::wstring& module_path);
};
#endif // CPPLIB_WINAPI_UTILITY_H_
