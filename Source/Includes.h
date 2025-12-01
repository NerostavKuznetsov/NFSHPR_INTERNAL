#define IMGUI_DEFINE_MATH_OPERATORS
#define WIN32_LEAN_AND_MEAN // Excluir APIs pouco usadas dos cabeçalhos do Windows.

// Windows API
#include <windows.h>
#include <iostream>
#include <cinttypes>
#include <string>
#include <atomic>

// DIRECTX-SKJUNE2010 
#include <d3d11.h>
#include <dxgi.h>
#include <D3DX11tex.h>
#pragma comment(lib, "D3DX11.lib")

// ImGui
#include "../External/ImGui/imgui.h"
#include "../External/ImGui/imgui_impl_dx11.h"
#include "../External/ImGui/imgui_impl_win32.h"
#include "../External/ImGui/imgui_internal.h"
#include "../External/ImGui/imgui_settings.h" 
#include "../External/kiero/kiero.h"

// Cheat 
#include "Cheat/Menu/Menu.h"
#include "Cheat/Menu/Font.h"
#include "Cheat/Features/Nitrous.h"
#include "Cheat/Features/GodMode.h"
#include "Cheat/Features/NoCooldownWeapons.h"   
#include "Cheat/Features/Weathers.h"           
#include "Cheat/Features/Weapons.h"             
#include "Cheat/Config/Config.h"
#include "Cheat/Controller/Controller.h"

extern uintptr_t Client;