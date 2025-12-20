#pragma once

namespace Config
{
	// ------------------------------------------------------------------
	// Menu Configurations
	// ------------------------------------------------------------------
	inline bool MenuImGui = false; 

	// ------------------------------------------------------------------
	// Weathers Configurations
	// ------------------------------------------------------------------
	inline bool Time = false;           
	inline int TimeValue = 0;      

	inline bool TimeSlider = false;  
	inline float TimeSliderValue = 0.0f;     

	// ------------------------------------------------------------------
	// Nitrous Configurations 
	// ------------------------------------------------------------------
	inline bool UnlimitedNitrous = false;

	inline bool NitrousUserEditing = false;
	inline float NitrousEditTimer = 0.0f;

	inline bool NitrousSlider = false;
	inline float NitrousSliderValue = 0.0f;

	// ------------------------------------------------------------------
	// Weapons Configurations
	// ------------------------------------------------------------------
	inline bool UnlimitedRacersWeapons = false;
	inline bool UnlimitedPoliceWeapons = false;

	inline bool NoCooldownRacersWeapons = false;
	inline bool NoCooldownPoliceWeapons = false;




	/////////////  AJUSTAR //////////////	
	
	inline bool MainWeatherID = false; // MainWeatherID
	inline int ChangeMainWeatherID = 0; // MainWeatherID

	//inline bool AlternativeWeatherID = false; // AlternativeWeatherID      not implemented yet
	//inline int ChangeAlternativeWeatherID = 0; // AlternativeWeatherID     not implemented yet

	inline int testandoCor = 0;

	inline bool GodMode = false;

	
}