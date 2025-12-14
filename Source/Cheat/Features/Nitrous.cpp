#include "../Config/Config.h"
#include "../Menu/Menu.h"

void UnlimitedNitrous()
{
	if (Config::UnlimitedNitrous) 
    {
        uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x1276650);
        if (!Ptr1) return;

        uintptr_t Nitrous_Value = (Ptr1 + 0x5031C);

        *(float*)Nitrous_Value = 100.0f;
    } 
}

void NitrousSlider()
{
    if (Config::NitrousSlider)
    {
		uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x1276650);
		if (!Ptr1) return;

		uintptr_t Current_NitrousSlider = (Ptr1 + 0x5031C);

		*(float*)Current_NitrousSlider = Config::NitrousSliderValue;

    }
}