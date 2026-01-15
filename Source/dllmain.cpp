//===========================================================================================================================//
// ➡️ Cheat created by https://github.com/NerostavKuznetsov/NFSHPR_INTERNAL                                                  //  
// ➡️ DirectX 11 Hook (kiero). Better version: https://github.com/rdbo/ImGui-DirectX-11-Kiero-Hook                           //
// ➡️ Dear ImGui: Bloat-free Graphical User interface for C++ with minimal dependencies: https://github.com/ocornut/imgui    //
// ➡️ Author ImGui: Ostin. Modified by Nerostav Kuznetsov!                                                                   //
// ➡️ DLL entry point                                                                                                        //
//===========================================================================================================================//

#include <Windows.h>
#include <iostream>
#include "Cheat/Controller/Controller.h"
#include "../External/kiero/kiero.h"
#include "Cheat/Menu/Menu.h"

bool init;
bool init_hook = false;
bool unloading = false;

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
Present oPresent;

uintptr_t Client = (uintptr_t)GetModuleHandle("NFS11Remastered.exe");

HRESULT static __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (unloading)
		return oPresent(pSwapChain, SyncInterval, Flags);
	if (!init)
	{
		if (Menu::Init(pSwapChain))
			init = true;
		return oPresent(pSwapChain, SyncInterval, Flags);
	}

	Menu::StartRender();
	Menu::Render();

	Controller::Execute();
	Menu::EndRender();
	return oPresent(pSwapChain, SyncInterval, Flags);
}

void static Unload(HMODULE hModule)
{
	unloading = true;

	Menu::Unload();
	kiero::unbind(8);
}

DWORD static WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	CONSOLE_CURSOR_INFO Cursor = { 1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cursor);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	std::wcout << R"(
                _____   _______________________  _________________ 
                ___  | / /__  ____/_  ___/__  / / /__  __ \__  __ \
                __   |/ /__  /_   _____ \__  /_/ /__  /_/ /_  /_/ /
                _  /|  / _  __/   ____/ /_  __  / _  ____/_  _, _/ 
                /_/ |_/  /_/      /____/ /_/ /_/  /_/     /_/ |_| 

 +--------------------------------------------------------------------------------+
 |             Need For Speed Hot Pursuit Remastered - Cheat Internal             |
 +--------------------------------------------------------------------------------+
 |  [+] Press TAB to toggle menu                                                  |
 |  [+] Made with <3 by Nerostav Kuznetsov                                        |
 +--------------------------------------------------------------------------------+
 |  [!] This program is free software you can redistribute or modify it!          |
 +--------------------------------------------------------------------------------+   )";

	while (!init_hook)
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	}

	while (!GetAsyncKeyState(VK_END))
	{
		Sleep(1);
	}

	Unload(hModule);
	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, EXIT_SUCCESS);
	return 0;
}

BOOL static APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}