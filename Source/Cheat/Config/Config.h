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

	inline bool TimeSlider = false;  
	inline float TimeSliderValue = 0.0f;    

	inline bool MainWeatherID = false; 
	inline int MainWeatherIDValue = 0; 

	inline bool AlternativeWeatherID = false; 
	inline int AlternativeWeatherIDValue = 0; 

	

	//TESANDO
	inline int testandoCor = 0;

}