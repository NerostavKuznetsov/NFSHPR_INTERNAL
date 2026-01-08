#pragma once

namespace Config
{
	// ========================================================
	// MENU
	// ========================================================
	inline bool MenuImGui;

	// ========================================================
	// GAMEPLAY
	// ========================================================

	// --- Nitrous ---
	inline bool  UnlimitedNitrous;
	inline bool  NitrousSlider = true;
	inline bool  NitrousUserEditing;
	inline float NitrousEditTimer;
	inline float NitrousSliderValue;

	// --- Player ---
	inline bool GodMode; 

	// --- Weapons ---
	inline bool UnlimitedRacersWeapons;
	inline bool UnlimitedPoliceWeapons;
	inline bool NoCooldownRacersWeapons;
	inline bool NoCooldownPoliceWeapons;

	// ========================================================
	// WEATHER / TIME
	// ========================================================

	// --- Time ---
	inline bool Time;
	inline bool TimeSlider = true;
	inline bool TimeUserEditing;
	inline int TimeValue;
	inline float TimeEditTimer;
	inline float TimeSliderValue;

	// --- Weather IDs ---
	inline bool MainWeatherID;
	inline int  MainWeatherIDValue;

	inline bool AlternativeWeatherID;
	inline int  AlternativeWeatherIDValue;

	// ========================================================
	// WORLD / VEGETATION / CLOUDS
	// ========================================================

	// --- Vegetations ---
	inline bool  szVegetationsCheckBox;
	inline float szVegetations = 0.007874015719f; // Default value

	// --- Cloud Acceleration ---
	inline bool  CloudAccelerationCheckBox;
	inline float CloudAcceleration = 0.200000003f; // Default value

	// ========================================================
	// TIMER
	// ========================================================

	// --- Timer ---
	inline bool ResetTimerOnce; // reseta uma vez
	inline bool FreezeTimer;    // congela em 0
}