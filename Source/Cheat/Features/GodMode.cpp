#include "../Config/Config.h"
#include "../Menu/Menu.h"

void GodMode()
{
	if (Config::GodMode)
	{
		uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x141FA88);	
		if (!Ptr1) return;
		uintptr_t Ptr2 = *(uintptr_t*)(Ptr1 + 0xC0);  
		if (!Ptr2) return;
		uintptr_t VehicleDamageAddress = (Ptr2 + 0x1F60);

		*(float*)VehicleDamageAddress = 0.0f;
	}
}																	