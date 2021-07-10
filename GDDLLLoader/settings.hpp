#ifndef DL_SETTINGS_HPP
#define DL_SETTINGS_HPP

// Edit your settings here, don not change anything if you don't know what you are doing!

#define DL_FOLDER_NAME  "adaf-dll"	// Folder name
#define DL_NO_FOLDER     0			// Load dll directly from Geometry Dash directory
#if		DL_NO_FOLDER  != 1
#define DL_DLL_BASE		 0			// Use dll directory as base path
#define DL_CREATE_FOLDER 1			// Create folder if it doesn't exist
#endif
#define DL_USE_PREFIX    0			// Use prefix for loading dll
#if		DL_USE_PREFIX == 1
#define DL_PREFIX		 "adaf_"
#endif

// Do not edit anything here!

#if DL_DLL_BASE == 1
#define DL_GET_BASE_PATH  get_dll_directory
#else
#define DL_GET_BASE_PATH  get_executable_directory
#endif

#ifndef UNICODE
#define DL_STR string
#else
#define DL_STR wstring
#endif

#endif