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

#ifndef DL_SETTINGS_HPP
#define DL_SETTINGS_HPP

/* 
 * --------------------------------------------------------------------------------------
 * Edit your settings here, don not change anything if you don't know what you are doing!
 * --------------------------------------------------------------------------------------
 */

    #define DL_DEFAULT		 1			// Use default settings
    #define DL_FOLDER_NAME   "adaf-dll"	// Folder name
    #define DL_NO_FOLDER     0			// Load DLL directly from Geometry Dash directory
    #define DL_DLL_BASE		 0			// Use DLL directory as base path
    #define DL_CREATE_FOLDER 1			// Create a folder if it doesn't exist
    #define DL_USE_PREFIX    0			// Use prefix for loading dll
    #define DL_PREFIX		 "adaf_"	// DLL prefix

 /*
  * --------------------------------------------------------------------------------------
  * Do not edit anything below this line!
  * --------------------------------------------------------------------------------------
  */

    #if		DL_DLL_BASE    == 1
        #define DL_GET_BASE_PATH  get_dll_directory
    #else
        #define DL_GET_BASE_PATH  get_executable_directory
    #endif

    #ifndef UNICODE
        #define DL_STR string
    #else
        #define DL_STR wstring
    #endif

    #if		DL_DEFAULT    == 1
        #undef	DL_FOLDER_NAME, DL_NO_FOLDER, DL_DLL_BASE, DL_CREATE_FOLDER, DL_USE_PREFIX, DL_PREFIX
        #define DL_FOLDER_NAME   "adaf-dll"
        #define DL_NO_FOLDER     0			
        #define DL_DLL_BASE		 0			
        #define DL_CREATE_FOLDER 1			
        #define DL_USE_PREFIX    0		
        #define DL_PREFIX		 ""
    #endif  

#endif