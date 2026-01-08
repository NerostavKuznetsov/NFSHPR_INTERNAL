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
    if (Config::NitrousSlider)
    {
        uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x1276650);
        if (!Ptr1) return;
        uintptr_t Nitrous_Value = Ptr1 + 0x5031C;

        float CurrentValueInGame = *(float*)Nitrous_Value;

        if (!Config::NitrousUserEditing)
        {
            Config::NitrousSliderValue = CurrentValueInGame;
        }
        else
        {
            *(float*)Nitrous_Value = Config::NitrousSliderValue;

            Config::NitrousEditTimer -= ImGui::GetIO().DeltaTime;
            if (Config::NitrousEditTimer <= 0.0f)
            {
                Config::NitrousUserEditing = false;
            }
        }
    }
}






