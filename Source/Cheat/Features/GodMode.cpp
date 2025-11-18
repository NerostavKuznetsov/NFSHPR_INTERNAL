#include "../../Includes.h"

void GodMode()
{
	if (Config::GodMode)
	{
		uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x0141FA88);
		if (!Ptr1) return;
		uintptr_t Ptr2 = *(uintptr_t*)(Ptr1 + 0xC0);
		if (!Ptr2) return;

		uintptr_t GodMode_Value = (Ptr2 + 0x1F60);

		*(float*)GodMode_Value = 0.0f;
	}
}

// GOD MODE FEITO PARA APENAS O MEU CARRO.
// OQUE EU USAVA ANTES PEGAVA TODOS OS CARROS QUANDO DAVA GOD MOD NO MEU E NAS IA																									