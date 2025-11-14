#include "../../Includes.h"

extern bool NoCooldownRacerWeapons;

void ResolverNoCooldownRacerWeaponsNFSHPR()
{
    if (Client && NoCooldownRacerWeapons)
    {
        uintptr_t Address = *(uintptr_t*)(Client + 0x12791C0);
        if (Address == 0) return;

        // RACER EMP 
        *(float*)(Address + 0x3F0) = 1.0f;

        // RACER SPIKE 
        *(float*)(Address + 0x3E4) = 1.0f;

        // RACER JAMMER 
        *(float*)(Address + 0x3F8) = 1.0f;

        // RACER TURBO 
        *(float*)(Address + 0x3EC) = 1.0f;
    }
}
