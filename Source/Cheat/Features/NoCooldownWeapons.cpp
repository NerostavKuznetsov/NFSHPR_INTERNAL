#include "../../Includes.h"

extern bool NoCooldownRacerWeapons;
extern bool NoCooldownPoliceWeapons;

void ResolverNoCooldownRacerWeaponsNFSHPR()
{
	if (Client && NoCooldownRacerWeapons)
	{
		uintptr_t Address = *(uintptr_t*)(Client + 0x12791C0);
		if (Address == 0) return;
		
		// JAMMER
		int* JAMMERCount = (int*)(Address + 0x5E4);
		float* JAMMERCooldown = (float*)(Address + 0x3F8);

		if (*JAMMERCount > 0 )
			*JAMMERCooldown = 1.0f;
		else
			*JAMMERCooldown = 0.0f;

		// SPIKES
		int* SPIKECount = (int*)(Address + 0x5D0);
		float* SPIKECooldown = (float*)(Address + 0x3E4);	

		if (*SPIKECount > 0 )
			*SPIKECooldown = 1.0f;
		else
			*SPIKECooldown = 0.0f;

		// EMP
		int* EMPCount = (int*)(Address + 0x5DC);
		float* EMPCooldown = (float*)(Address + 0x3F0);

		if (*EMPCount > 0 )
			*EMPCooldown = 1.0f;
		else
			*EMPCooldown = 0.0f;

		// TURBO
		int* TURBOCount = (int*)(Address + 0x5D8);
		float* TURBOCooldown = (float*)(Address + 0x3EC);

		if (*TURBOCount > 0 )
			*TURBOCooldown = 1.0f;
		else
			*TURBOCooldown = 0.0f;	
	}
}

void ResolverNoCooldownPoliceWeaponsNFSHPR()
{
	if (Client && NoCooldownPoliceWeapons)
	{

	}
}

