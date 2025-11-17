#include "../../Includes.h"

extern bool UnlimitedNitrous;

void ResolverUnlimitedNitrousNFSHPR()
{
    uintptr_t Address = *(uintptr_t*)(Client + 0x1276650);
    if (Address == 0) return;

    float* Nitrous_Value = (float*)(Address + 0x5031C);

    if (UnlimitedNitrous)
    {
        *Nitrous_Value = 100.0f;
    }
}

void ResolverNitrousFireColorNFSHPR() // not implemented yet
{
   
}