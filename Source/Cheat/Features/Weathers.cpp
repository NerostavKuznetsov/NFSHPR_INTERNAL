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
	case 0:
		*Current_Time = 17000.0f; // Early Morning   
		break;
	case 1:
		*Current_Time = 20000.0f; // Morning   
		break;
	case 2:
		*Current_Time = 50000.0f; // Noon   
		break;
	case 3:
		*Current_Time = 65000.0f; // Afternoon   
		break;
	case 4:
		*Current_Time = 73000.0f; // Evening
		break;
	case 5:
		*Current_Time = 80000.0f; // Night   
		break;
	case 6:
		*Current_Time = 0.0f; // Midnight
		break;
	default:
		break;
	}
}

void MainWeatherID()
{
	if (!Config::MainWeatherID) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	int* Current_Weather = (int*)(Address + 0x129A94);

	switch (Config::ChangeMainWeatherID)
	{
	case 0:
		*Current_Weather = 0; // Sunny // Sol
		break;
	case 1:
		*Current_Weather = 1; // Sunny After Rain // Sol após a chuva
		break;
	case 2:
		*Current_Weather = 2; // Sunny + Rain/Snow (Non-Wet Roads) // Sol + Chuva/Neve (Estradas não molhadas)
		break;
	case 3:
		*Current_Weather = 3; // Sunny + Rain/Snow (Wet Roads) // Sol + Chuva/Neve (Estradas Molhadas)
		break;
	case 4:
		*Current_Weather = 8; // Cloudy // Nublado
		break;
	case 5:
		*Current_Weather = 9; // Cloudy (Wet Roads) // Nublado (Estradas Molhadas)
		break;
	case 6:
		*Current_Weather = 10; // Cloudy + Rain/Snow (Non-Wet Roads) // Nublado + Chuva/Neve (Estradas não molhadas)
		break;
	case 7:
		*Current_Weather = 11; // Cloudy + Rain/Snow (Wet Roads) // Nublado + Chuva/Neve (Estradas Molhadas)
		break;
	case 8:
		*Current_Weather = 12; // Thunderstorm // Tempestade
		break;
	case 9:
		*Current_Weather = 13; // Thunderstorm (Wet Roads) // Tempestade (Estradas Molhadas)
		break;
	case 10:
		*Current_Weather = 14; // Thunderstorm + Rain (Non-Wet Roads) // Tempestade + Chuva (Estradas não molhadas)
		break;
	case 11:
		*Current_Weather = 15; // Thunderstorm + Rain (Wet Roads) // Tempestade + Chuva (Estradas Molhadas)
	default:
		break;
	}
}