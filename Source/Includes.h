#define IMGUI_DEFINE_MATH_OPERATORS

// Windows API
#include <windows.h>
#include <iostream>
#include <cinttypes>
#include <string>

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

// Hooking
#include "../External/kiero/kiero.h"

// Cheat Menu 
#include "Cheat/Menu/Menu.h"
#include "Cheat/Menu/Font.h"       // ERRO DE MULTIPLAS DEFINIÇÕES E SIMBOLOS!   fix with INLINE in Font.h
#include "Cheat/SDK/Offsets.h"

// Cheats
#include "Cheat/Features/UnlimitedNitrous.h"
#include "Cheat/Features/GodMode.h"
#include "Cheat/Features/NoCooldownRacerWeapons.h"

// Declaração 
extern uintptr_t Client;




