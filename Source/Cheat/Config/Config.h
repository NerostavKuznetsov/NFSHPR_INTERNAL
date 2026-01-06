#pragma once

namespace Config
{
    // ========================================================
    // MENU
    // ========================================================
    inline bool MenuImGui = false;


    // ========================================================
    // GAMEPLAY
    // ========================================================

    // --- Nitrous ---
    inline bool  UnlimitedNitrous = false;
    inline bool  NitrousSlider = true;
    inline bool  NitrousUserEditing = false;
    inline float NitrousEditTimer = 0.50f;
    inline float NitrousSliderValue = 0.0f;

    // --- Player ---
    inline bool GodMode = false;

    // --- Weapons ---
    inline bool UnlimitedRacersWeapons = false;
    inline bool UnlimitedPoliceWeapons = false;
    inline bool NoCooldownRacersWeapons = false;
    inline bool NoCooldownPoliceWeapons = false;


    // ========================================================
    // WEATHER / TIME
    // ========================================================

    // --- Time ---
    inline bool  Time = false;
    inline bool  TimeSlider = true;
    inline bool  TimeUserEditing = false;
    inline int   TimeValue = 0;
    inline float TimeEditTimer = 0.0f;
    inline float TimeSliderValue = 0.0f;

    // --- Weather IDs ---
    inline bool MainWeatherID = false;
    inline int  MainWeatherIDValue = 0;

    inline bool AlternativeWeatherID = false;
    inline int  AlternativeWeatherIDValue = 0;


    // ========================================================
    // WORLD / VEGETATION / CLOUDS
    // ========================================================

    // --- Vegetations ---
    inline bool  szVegetationsCheckBox = false;
    inline float szVegetations = 0.007874015719f;

    // --- Cloud Acceleration ---
    inline bool  CloudAccelerationCheckBox = false;
    inline float CloudAcceleration = 0.200000003f;


    // ========================================================
    // TIMER
    // ========================================================

    inline bool ResetTimerOnce = false;   // reseta uma vez
    inline bool FreezeTimer = false;   // congela em 0
}