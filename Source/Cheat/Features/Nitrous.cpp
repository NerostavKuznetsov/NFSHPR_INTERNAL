#include "../../Includes.h"

extern bool UnlimitedNitrous;

void ResolverNitrousNFSHPR()
{
    uintptr_t NitrousBase = Client + 0x1276650;
    uintptr_t NitrousAddress = *(uintptr_t*)NitrousBase;

    float* NitrousValue = (float*)(NitrousAddress + 0x5031C);
    if (UnlimitedNitrous)
    {
        *NitrousValue = 100.0f;
    }
}

void ResolverNitrousFireColorNFSHPR()
{
   
}