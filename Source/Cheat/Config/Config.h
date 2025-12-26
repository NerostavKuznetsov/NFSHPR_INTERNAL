#pragma once

namespace Config
{
	// ------------------------------------------------------------------
	// Menu Configurations
	// ------------------------------------------------------------------
	inline bool MenuImGui = false; 

	// ------------------------------------------------------------------
	// Gameplay Configurations 
	// ------------------------------------------------------------------
	inline bool UnlimitedNitrous = false;

	inline bool NitrousUserEditing = false;
	inline float NitrousEditTimer = 0.0f;
	inline bool NitrousSlider = true;
	inline float NitrousSliderValue = 0.0f;

	inline bool GodMode = false;

	inline bool UnlimitedRacersWeapons = false;
	inline bool UnlimitedPoliceWeapons = false;

	inline bool NoCooldownRacersWeapons = false;
	inline bool NoCooldownPoliceWeapons = false;

	// ------------------------------------------------------------------
	// Weathers Configurations
	// ------------------------------------------------------------------
	inline bool Time = false;           
	inline int TimeValue = 0;      

	inline bool TimeUserEditing = false;
	inline float TimeEditTimer = 0.0f;
	inline bool TimeSlider = true;  
	inline float TimeSliderValue = 0.0f;    

	inline bool MainWeatherID = false; 
	inline int MainWeatherIDValue = 0; 

	inline int LastAppliedAlternativeWeather = -1;
	inline bool AlternativeWeatherID = false; 
	inline int AlternativeWeatherIDValue = 0; 






	/// <summary>
	/// /////////////////////////////////////////// testando 
	/// </summary>
	inline bool szVegetationsEnabled = false;
	inline float szVegetations = 0.007874015719f; // valor inicial
	
	inline int testandoCor = 0;
}