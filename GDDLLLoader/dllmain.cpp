#include <Windows.h>
#include <string>
#include <filesystem>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

std::wstring get_dll_path() {

	TCHAR dll_path[MAX_PATH] = { 0 };

	GetModuleFileName((HINSTANCE)&__ImageBase, dll_path, _countof(dll_path));

	std::wstring dll_dir = dll_path;

	return dll_dir.substr(0, dll_dir.find_last_of(L"\\/"));

}

DWORD WINAPI main_hook(LPVOID lpParam) {

	if (!std::filesystem::is_directory(L"adaf-dll") || !std::filesystem::exists(L"adaf-dll")) 
		std::filesystem::create_directory(L"adaf-dll");

	std::wstring path = get_dll_path() + L"/adaf-dll/";

	for (const auto& file : std::filesystem::directory_iterator(path)) 
		LoadLibrary(file.path().wstring().c_str());

	return TRUE;

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {

	switch (ul_reason_for_call) {

	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0x1000, &main_hook, 0, 0, NULL);

	case DLL_PROCESS_DETACH:
		break;

	}

	return TRUE;

}
