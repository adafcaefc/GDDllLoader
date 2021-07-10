#include <Windows.h>
#include <string>
#include <filesystem>
#include "file_utils.hpp"
#include "settings.hpp"

DWORD WINAPI main_hook(LPVOID lpParam) 
{
#if DL_NO_FOLDER != 1
	auto base_path = DL_GET_BASE_PATH() / DL_FOLDER_NAME;
	if (!std::filesystem::is_directory(base_path) || !std::filesystem::exists(base_path))
	{
#if DL_CREATE_FOLDER != 1
		return TRUE;
#endif
		std::filesystem::create_directory(base_path);
	}
#else
	auto base_path = get_executable_path();
#endif

	for (const auto& file : std::filesystem::directory_iterator(base_path))
	{
#if DL_USE_PREFIX == 1
		if (file.path().filename().string().find(DL_PREFIX) != std::string::npos) continue;
#endif
		LoadLibrary(file.path().DL_STR().c_str());
	}

	return TRUE;
}

__declspec(dllexport) void _pe_stub()
{
	return;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) 
{
	switch (ul_reason_for_call) 
	{
	case DLL_PROCESS_DETACH:
		break;
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, NULL, &main_hook, nullptr, NULL, nullptr);
	default:
		break;
	}
	return TRUE;
}