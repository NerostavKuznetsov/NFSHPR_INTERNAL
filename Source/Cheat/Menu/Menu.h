#pragma once
#include "../../Includes.h"

namespace Menu
{
	bool Init(IDXGISwapChain* pSwapChain);
	void StartRender();
	void Render();
	void EndRender();
	void Unload();
}