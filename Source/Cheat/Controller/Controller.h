#pragma once
#include "../Features/Features.h"

namespace Controller
{
    inline void Execute() // Inline para evitar múltiplas definições em vários .cpp's
    {
        UnlimitedNitrous();
        NitrousSlider();
        GodMode();
        UnlimitedRacersWeapons();
        UnlimitedPoliceWeapons();
        NoCooldownPoliceWeapons();
        NoCooldownRacerWeapons();
        Time();
        SliderTime();
        MainWeatherID();
        AlternativeWeatherID();
        SizeOfVegetations();
        CloudAcceleration();
        ResetTimer();
    }
}