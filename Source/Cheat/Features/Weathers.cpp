#include "../../Includes.h"

void ChangeTime()
{
	if (!Config::ChangeTime) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (Address == 0) return;

	float* Current_Time = (float*)(Address + 0x129A80);

	switch (Config::ChangeTimeType)
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
	int* Current_Weather = (int*)(Client + 0x129A80);

	// NOT IMPLEMENTED YET
	switch (Config::ChangeWeatherType)
	{
	case 0:
		*Current_Weather = 0; // Sunny 
		break;
	case 1:
		*Current_Weather = 1; // Sunny After Rain
		break;
	case 2:
		*Current_Weather = 2; // Sunny + Rain/Snow (Non-Wet Roads)
		break;
	case 3:
		*Current_Weather = 3; // Sunny + Rain/Snow (Wet Roads)
		break;
	case 4:
		*Current_Weather = 8; // Cloudy
		break;
	case 5:
		*Current_Weather = 5;
		break;
	case 6:
		*Current_Weather = 6;
		break;
	default:
		break;
	}
}