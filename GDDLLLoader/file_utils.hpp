/*
 * -----------------------------------------------------------------------------
 * GD DLL Loader by Adafcaefc
 * -----------------------------------------------------------------------------
 *
 * Put the provided libExtensions.dll and GDDLLLoader.dll to the Geometry Dash directory.
 * Put DLLs in the adaf-dll folder.
 * You can check the settings on settings.hpp file
 *
 * -- Contacts --
 * Github:  https://github.com/adafcaefc
 * YouTube: https://www.youtube.com/channel/UCDnlxnVCzm-rdK7b13eDkRQ
 * Website: https://adaf.xyz/adaf/
 * Discord: https://discord.com/invite/GQbFHR6jNW
 *
 * -----------------------------------------------------------------------------
 * Requirements
 * -----------------------------------------------------------------------------
 *
 * The recommended version of C++ is C++17
 * Recommended C++ compilers
 *
 * Visual Studio https://visualstudio.microsoft.com/
 * MinGW		 https://sourceforge.net/projects/mingw/
 * CMake		 https://cmake.org/
 *
 */

#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <Windows.h>
#include <filesystem>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

static std::filesystem::path get_dll_path()
{
	TCHAR DllPath[MAX_PATH] = { 0 };
	GetModuleFileName((HINSTANCE)&__ImageBase, DllPath, _countof(DllPath));
	return std::filesystem::path(DllPath);
}

static std::filesystem::path get_dll_directory()
{
	return get_dll_path().parent_path();
}

static std::filesystem::path get_executable_path()
{
	char szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
	return szFilePath;
}

static std::filesystem::path get_executable_directory()
{
	return get_executable_path().parent_path();
}

#endif