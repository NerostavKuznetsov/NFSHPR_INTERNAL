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
		int* JAMMER_Value = (int*)(Address + 0x5E4);
		float* JAMMER_Cooldown = (float*)(Address + 0x3F8);

		if (*JAMMER_Value > 0)
			*JAMMER_Cooldown = 1.0f;
		else
			*JAMMER_Cooldown = 0.0f;

		// SPIKES
		int* SPIKES_Value = (int*)(Address + 0x5D0);
		float* SPIKES_Cooldown = (float*)(Address + 0x3E4);	

		if (*SPIKES_Value > 0)
			*SPIKES_Cooldown = 1.0f;
		else
			*SPIKES_Cooldown = 0.0f;

		// EMP
		int* EMP_Value = (int*)(Address + 0x5DC);
		float* EMPCooldown = (float*)(Address + 0x3F0);

		if (*EMP_Value > 0)
			*EMPCooldown = 1.0f;
		else
			*EMPCooldown = 0.0f;

		// TURBO
		int* TURBO_Value = (int*)(Address + 0x5D8);
		float* TURBO_Cooldown = (float*)(Address + 0x3EC);

		if (*TURBO_Value > 0)
			*TURBO_Cooldown = 1.0f;
		else
			*TURBO_Cooldown = 0.0f;
	}
}

void ResolverNoCooldownPoliceWeaponsNFSHPR()
{
	if (Client && NoCooldownPoliceWeapons)
	{
		uintptr_t Address = *(uintptr_t*)(Client + 0x12791C0);
		if (Address == 0) return;

		// ROADBLOCK
		int* ROADBLOCK_Value = (int*)(Address + 0x5E8);
		float* ROADBLOCK_Cooldown = (float*)(Address + 0x3FC);

		if (*ROADBLOCK_Value > 0)
			*ROADBLOCK_Cooldown = 1.0f;
		else
			*ROADBLOCK_Cooldown = 0.0f;

		// SPIKES
		int* SPIKES_Value = (int*)(Address + 0x5D4);
		float* SPIKES_Cooldown = (float*)(Address + 0x3E8);

		if (*SPIKES_Value > 0)
			*SPIKES_Cooldown = 1.0f;
		else
			*SPIKES_Cooldown = 0.0f;

		// EMP
		int* EMP_Value = (int*)(Address + 0x5CC);
		float* EMP_Cooldown = (float*)(Address + 0x3E0);

		if (*EMP_Value > 0)
			*EMP_Cooldown = 1.0f;
		else
			*EMP_Cooldown = 0.0f;

		// HELICOPTER
		int* HELICOPTER_Value = (int*)(Address + 0x5C8);
		float* HELICOPTER_Cooldown = (float*)(Address + 0x3DC);

		if (*HELICOPTER_Value > 0)
			*HELICOPTER_Cooldown = 1.0f;
		else
			*HELICOPTER_Cooldown = 0.0f;
	}
}

