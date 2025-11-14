#include "../../Includes.h"

extern bool NoCooldownRacerWeapons; /// OFFSETS ERRADOS,  AJUSTAR
  

void ResolverNoCooldownRacerWeaponsNFSHPR()
{
	if (Client && NoCooldownRacerWeapons)
	{
		uintptr_t Address = *(uintptr_t*)(Client + 0x0141FA88);
		if (Address == 0) return;
		Address = *(uintptr_t*)(Address + 0xC0);
		if (Address == 0) return;
		Address += 0x1F60;

		*(float*)Address = 0.0f;
	}


}	