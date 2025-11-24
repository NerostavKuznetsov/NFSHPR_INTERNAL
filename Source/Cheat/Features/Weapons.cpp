#include "../../Includes.h"

void UnlimitedRacersWeapons()
{
    if (!Config::UnlimitedRacersWeapons) return;

    uintptr_t Address = *(uintptr_t*)(Client + 0x12791C0);
    if (!Address) return;

    int* JAMMER_Value = (int*)(Address + 0x5E4);
    int* SPIKES_Value = (int*)(Address + 0x5D0);
    int* EMP_Value = (int*)(Address + 0x5DC);
    int* TURBO_Value = (int*)(Address + 0x5D8);

    *JAMMER_Value = 99;
    *SPIKES_Value = 99;
    *EMP_Value = 99;
    *TURBO_Value = 99;
}
