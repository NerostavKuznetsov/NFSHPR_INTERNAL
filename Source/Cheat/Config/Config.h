#pragma once

namespace Config
{
	// --------------------------------------------------------
	// Menu Configurations
	// --------------------------------------------------------
	inline bool MenuImGui = false; 

	// --------------------------------------------------------
	// Gameplay Configurations 
	// --------------------------------------------------------
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

	// --------------------------------------------------------
	// Weathers Configurations
	// --------------------------------------------------------
	inline bool Time = false;           
	inline int TimeValue = 0;      

	inline bool TimeUserEditing = false;
	inline float TimeEditTimer = 0.0f;
	inline bool TimeSlider = true;  
	inline float TimeSliderValue = 0.0f;    

	inline bool MainWeatherID = false; 
	inline int MainWeatherIDValue = 0; 

	inline bool AlternativeWeatherID = false; 
	inline int AlternativeWeatherIDValue = 0; 

	// --------------------------------------------------------
	// Vegetations Configurations
	// --------------------------------------------------------
	inline bool szVegetationsCheckBox = false;
	inline float szVegetations = 0.007874015719f; 

	// --------------------------------------------------------
	// Cloud Acceleration Configurations
	// --------------------------------------------------------
	inline bool CloudAccelerationCheckBox = false;
	inline float CloudAcceleration = 0.200000003f;













	// --------------------------------------------------------
	// Reset Timer Configurations
	// --------------------------------------------------------

	inline bool ResetTimerOnce = false;     // reseta uma vez
	inline bool FreezeTimer = false;        // congela em 0



}