#include "../../Includes.h"

extern bool GodMode;

void ResolverGodModeNFSHPR()
{

	if (Client && GodMode)
	{
		uintptr_t addr = *(uintptr_t*)(Client + 0x0141FA88);
		if (addr == 0) return;
		addr = *(uintptr_t*)(addr + 0xC0);
		if (addr == 0) return;
		addr += 0x1F60;
	
		*(float*)addr = 0.0f;
	}
}

