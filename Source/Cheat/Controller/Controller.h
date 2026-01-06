#pragma once
#include "../Features/Features.h"

namespace Controller
{
    inline void Execute() // inline para evitar múltiplas definições em vários .cp
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