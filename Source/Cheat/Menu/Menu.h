#pragma once
#include <dxgi.h>

struct ImFont;
extern ImFont* Inter_S;
extern ImFont* Inter_S_1;
extern ImFont* Inter_S_2;
extern ImFont* Inter_S_3;
extern ImFont* Inter_B;
extern ImFont* Icon;
extern ImFont* Icon_Arrow;

extern uintptr_t Client;
extern float anim_text;

namespace Menu
{
	bool Init(IDXGISwapChain* pSwapChain);
	void StartRender();
	void Render();
	void EndRender();
	void Unload();
}

