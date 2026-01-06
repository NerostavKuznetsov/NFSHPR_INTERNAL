#include "../Config/Config.h"
#include "../Menu/Menu.h"

void GodMode()
{
	if (Config::GodMode)
	{
		uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x141FA88);	/// ajustar endereço com client ...
		if (!Ptr1) return;
		uintptr_t Ptr2 = *(uintptr_t*)(Ptr1 + 0xC0);  
		if (!Ptr2) return;

		uintptr_t GodMode_Value = (Ptr2 + 0x1F60);

		*(float*)GodMode_Value = 0.0f;
	}
}																	