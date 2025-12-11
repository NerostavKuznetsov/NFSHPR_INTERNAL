#include "../Config/Config.h"
#include "../Menu/Menu.h"

void Time()
{
	if (!Config::Time) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	float* Current_Time = (float*)(Address + 0x129A80);

	switch (Config::ChangeTime)
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
	if (!Config::UseTimeSlider) return; 

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	float* Current_SliderTime = (float*)(Address + 0x129A80);

	*Current_SliderTime = Config::SliderTime; 
}

void MainWeatherID()
{
	if (!Config::MainWeatherID) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	int* Current_Weather = (int*)(Address + 0x129A94);

	switch (Config::ChangeMainWeatherID)
	{
	case 0: *Current_Weather = 0; break;   // Sunny // Sol
	case 1: *Current_Weather = 1; break;   // Sunny After Rain // Ensolarado após a chuva
	case 2: *Current_Weather = 2; break;   // Sunny + Rain/Snow (Non-Wet Roads) // Ensolarado + Chuva/Neve (Estradas não molhadas)
	case 3: *Current_Weather = 3; break;   // Sunny + Rain/Snow (Wet Roads) // Ensolarado + Chuva/Neve (Estradas Molhadas)
	case 4: *Current_Weather = 8; break;   // Cloudy // Nublado
	case 5: *Current_Weather = 9; break;   // Cloudy (Wet Roads) // Nublado (Estradas Molhadas)
	case 6: *Current_Weather = 10; break;  // Cloudy + Rain/Snow (Non-Wet Roads) // Nublado + Chuva/Neve (Estradas não molhadas)
	case 7: *Current_Weather = 11; break;  // Cloudy + Rain/Snow (Wet Roads) // Nublado + Chuva/Neve (Estradas Molhadas)
	case 8: *Current_Weather = 12; break;  // Thunderstorm // Tempestade
	case 9: *Current_Weather = 13; break;  // Thunderstorm (Wet Roads) // Tempestade (Estradas Molhadas)
	case 10: *Current_Weather = 14; break; // Thunderstorm + Rain (Non-Wet Roads) // Tempestade + Chuva (Estradas não molhadas)
	case 11: *Current_Weather = 15; break; // Thunderstorm + Rain (Wet Roads) // Tempestade + Chuva (Estradas Molhadas)
	default: break;
	}
}