#pragma once

namespace Config
{
	
	inline bool MenuImGui;



	// --- Nitrous ---
	inline bool  UnlimitedNitrous;


	// --- Player ---
	inline bool GodMode; 



	// --- Weapons ---
	inline bool UnlimitedRacersWeapons;
	inline bool UnlimitedPoliceWeapons;
	inline bool NoCooldownRacersWeapons;
	inline bool NoCooldownPoliceWeapons;



	// --- Time ---
	inline bool TimeCheckBox;
	inline int TimeValue;

	inline bool TimeSliderCheckBox;
	inline float TimeSliderValue;
	inline bool TimeInitialized;



	// --- Weather IDs ---
	inline bool MainWeatherID;
	inline int  MainWeatherIDValue;

	inline bool AlternativeWeatherID;
	inline int  AlternativeWeatherIDValue;



	// --- Vegetations ---
	inline bool  szVegetationsCheckBox;
	inline float szVegetations = 0.007874015719f; // Default value


	// --- Cloud Acceleration ---
	inline bool  CloudAccelerationCheckBox;
	inline float CloudAcceleration = 0.200000003f; // Default value


	// --- Timer ---
	inline bool ResetTimer; 
}