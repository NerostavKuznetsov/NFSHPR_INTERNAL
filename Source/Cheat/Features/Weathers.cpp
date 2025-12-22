#include "../Config/Config.h"
#include "../Menu/Menu.h"

void Time()
{
	if (!Config::Time) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	float* Current_Time = (float*)(Address + 0x129A80);

	switch (Config::TimeValue)
	{
	case 0: *Current_Time = 17000.0f; break; // Early Morning
	case 1: *Current_Time = 20000.0f; break; // Morning
	case 2: *Current_Time = 50000.0f; break; // Noon
	case 3: *Current_Time = 65000.0f; break; // Afternoon
	case 4: *Current_Time = 73000.0f; break; // Evening
	case 5: *Current_Time = 80000.0f; break; // Night
	case 6: *Current_Time = 0.0f; break;     // Midnight
	default: break;
	}
}

void SliderTime()
{
	if (!Config::TimeSlider) return; 

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	float* Current_TimeSlider = (float*)(Address + 0x129A80);

	*Current_TimeSlider = Config::TimeSliderValue; 
}

void MainWeatherID()
{
	if (!Config::MainWeatherID) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	int* Current_MainWeatherID = (int*)(Address + 0x129A94);

	switch (Config::MainWeatherIDValue)
	{
	case 0: *Current_MainWeatherID = 0; break;   // Sunny // Ensolarado
	case 1: *Current_MainWeatherID = 1; break;   // Sunny After Rain // Ensolarado após a chuva
	case 2: *Current_MainWeatherID = 2; break;   // Sunny + Rain/Snow (Non-Wet Roads) // Ensolarado + Chuva/Neve (Estradas secas)
	case 3: *Current_MainWeatherID = 3; break;   // Sunny + Rain/Snow (Wet Roads) // Ensolarado + Chuva/Neve (Estradas Molhadas)
	case 4: *Current_MainWeatherID = 8; break;   // Cloudy // Nublado
	case 5: *Current_MainWeatherID = 9; break;   // Cloudy (Wet Roads) // Nublado (Estradas Molhadas)
	case 6: *Current_MainWeatherID = 10; break;  // Cloudy + Rain/Snow (Non-Wet Roads) // Nublado + Chuva/Neve (Estradas secas)
	case 7: *Current_MainWeatherID = 11; break;  // Cloudy + Rain/Snow (Wet Roads) // Nublado + Chuva/Neve (Estradas Molhadas)
	case 8: *Current_MainWeatherID = 12; break;  // Thunderstorm // Tempestade
	case 9: *Current_MainWeatherID = 13; break;  // Thunderstorm (Wet Roads) // Tempestade (Estradas Molhadas)
	case 10: *Current_MainWeatherID = 14; break; // Thunderstorm + Rain (Non-Wet Roads) // Tempestade + Chuva (Estradas secas)
	case 11: *Current_MainWeatherID = 15; break; // Thunderstorm + Rain (Wet Roads) // Tempestade + Chuva (Estradas Molhadas)
	default: break;
	}
}

void AlternativeWeatherID()
{
	if (!Config::AlternativeWeatherID) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	int* Current_AlternativeWeatherID = (int*)(Address + 0x12929C);

	switch (Config::AlternativeWeatherIDValue)
	{
	case 0: *Current_AlternativeWeatherID = 11; break; // Fog Weather // Nevoeiro
	case 1: *Current_AlternativeWeatherID = 2; break;  // Fog 1 //	Nevoeiro 1
	case 2: *Current_AlternativeWeatherID = 3; break;  // Fog 2 // Nevoeiro 2
	case 3: *Current_AlternativeWeatherID = 5; break;  // Fog 3 // Nevoeiro 3
	case 4: *Current_AlternativeWeatherID = 14; break; // Fog 4 // Nevoeiro 4
	case 5: *Current_AlternativeWeatherID = 17; break; // Fog 5 // Nevoeiro 5
	case 6: *Current_AlternativeWeatherID = 27; break; // Fog 6 // Nevoeiro 6

    // Sunny (Sunny weather is recommended)  
	case 7: *Current_AlternativeWeatherID = 4; break;  // Autumn // Outono
	case 8: *Current_AlternativeWeatherID = 6; break;  // Sunny 1 // Ensolarado 1
	case 9: *Current_AlternativeWeatherID = 26; break; // Sunny 2 // Ensolarado 2





	default: break;
	}
}

