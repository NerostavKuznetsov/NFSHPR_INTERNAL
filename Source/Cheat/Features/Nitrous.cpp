#include "../../../External/ImGui/imgui.h"
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
    if (!Config::NitrousSlider)
        return;

    uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x1276650);
    if (!Ptr1) return;

    uintptr_t addr = Ptr1 + 0x5031C;

    float gameValue = *(float*)addr;

    if (!Config::NitrousUserEditing)
    {
        Config::NitrousSliderValue = gameValue;
    }
    else
    {
        *(float*)addr = Config::NitrousSliderValue;

        Config::NitrousEditTimer -= ImGui::GetIO().DeltaTime;
        if (Config::NitrousEditTimer <= 0.0f)
        {
            Config::NitrousUserEditing = false;
        }
    }
}






