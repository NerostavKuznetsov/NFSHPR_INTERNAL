#include "Includes.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
Present oPresent;
bool init;
bool unloading = false;

uintptr_t Client = (uintptr_t)GetModuleHandle(L"NFS11Remastered.exe");
uintptr_t Authentication = (uintptr_t)GetModuleHandle(L"Activation64.dll");

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
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
    
	// Cheats Resolvers
    ResolverUnlimitedNitrousNFSHPR();
    ResolverGodModeNFSHPR();

	// No Cooldown Weapons
    ResolverNoCooldownRacerWeaponsNFSHPR();
	ResolverNoCooldownPoliceWeaponsNFSHPR();

	// Weathers Resolvers
	ResolverEarlyMorningNFSHPR();
    ResolverMorningNFSHPR();
    ResolverNoonNFSHPR();
    ResolverAfternoonNFSHPR();
    ResolverEveningNFSHPR();
    ResolverNightNFSHPR();
    ResolverMidnightNFSHPR();

    Menu::EndRender();
    return oPresent(pSwapChain, SyncInterval, Flags);
}

void Init()
{

}

void Unload(HMODULE hModule)
{
    unloading = true;

    Menu::Unload();
    kiero::unbind(8);
}

DWORD WINAPI HackThread(HMODULE hModule)
{
	AllocConsole(); 
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << R"()";

    bool init_hook = false;
    do
    {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
        {
            Init();
            init_hook = true;
            kiero::bind(8, (void**)&oPresent, hkPresent);
        }
    } while (!init);

    while (!GetAsyncKeyState(VK_END))
    {
        Sleep(1);
    }

	Unload(hModule); // chama a função de descarregamento
	fclose(f); 
	FreeConsole(); 
	FreeLibraryAndExitThread(hModule, EXIT_SUCCESS); // descarrega o DLL e sai da thread
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hModule);
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr)); // cria a thread principal do hack
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

