#include "../../../External/ImGui/imgui.h"
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
	case 0: *Current_Time = 17000.0f; break;
	case 1: *Current_Time = 20000.0f; break;
	case 2: *Current_Time = 50000.0f; break;
	case 3: *Current_Time = 65000.0f; break;
	case 4: *Current_Time = 73000.0f; break;
	case 5: *Current_Time = 80000.0f; break;
	case 6: *Current_Time = 0.0f;     break;
	default: return;
	}
}

void SliderTime()
{
	if (!Config::TimeSlider)
		return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	float* addr = (float*)(Address + 0x129A80);

	float gameValue = *addr;

	// 🔄 se NÃO estiver mexendo → slider segue o jogo
	if (!Config::TimeUserEditing)
	{
		Config::TimeSliderValue = gameValue;
	}
	else
	{
		// ✋ usuário mexendo → escreve no jogo
		*addr = Config::TimeSliderValue;

		Config::TimeEditTimer -= ImGui::GetIO().DeltaTime;
		if (Config::TimeEditTimer <= 0.0f)
		{
			Config::TimeUserEditing = false;
		}
	}
}

void MainWeatherID()
{
	if (!Config::MainWeatherID) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	int* Current_MainWeatherID = (int*)(Address + 0x129A94);

	switch (Config::MainWeatherIDValue)
	{
	case 0: *Current_MainWeatherID = 0;  break; 
	case 1: *Current_MainWeatherID = 1;  break; 
	case 2: *Current_MainWeatherID = 2;  break;
	case 3: *Current_MainWeatherID = 3;  break;
	case 4: *Current_MainWeatherID = 8;  break;
	case 5: *Current_MainWeatherID = 9;  break;
	case 6: *Current_MainWeatherID = 10; break;
	case 7: *Current_MainWeatherID = 11; break;
	case 8: *Current_MainWeatherID = 12; break;
	case 9: *Current_MainWeatherID = 13; break;
	case 10: *Current_MainWeatherID = 14; break;
	case 11: *Current_MainWeatherID = 15; break;
	default: return;
	}
}
 
void AlternativeWeatherID()
{
	if (!Config::AlternativeWeatherID) return;

	uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
	if (!Address) return;

	int* Current_AlternativeWeatherID = (int*)(Address + 0x12929C);

	int newWeather = -1;

	if (Config::AlternativeWeatherID)
	{
		switch (Config::AlternativeWeatherIDValue)
		{
		// Fog
		case 0: newWeather = 11; break; 
		case 1: newWeather = 2;  break; 
		case 2: newWeather = 3;  break; 
		case 3: newWeather = 5;  break; 
		case 4: newWeather = 14; break; 
		case 5: newWeather = 17; break; 
		case 6: newWeather = 27; break; 
		// Sunny
		case 7: newWeather = 4; break; 
		case 8: newWeather = 6; break; 
		case 9: newWeather = 26; break; 
		// Tropical
		case 10: newWeather = 25;  break; 
		case 11: newWeather = 18;  break; 
		case 12: newWeather = 1;  break; 
		case 13: newWeather = 23; break; 
		case 14: newWeather = 24; break; 
		case 15: newWeather = 21; break; 
	    // Sunny and Cloudy (Fog can be used)
		case 16: newWeather = 15;  break;
		case 17: newWeather = 19;  break; 
		case 18: newWeather = 0;  break; 
		case 19: newWeather = 16; break; 
		case 20: newWeather = 20; break; 
		default: return;
		}

		if (newWeather != Config::LastAppliedAlternativeWeather)
		{
			*Current_AlternativeWeatherID = newWeather;
			Config::LastAppliedAlternativeWeather = newWeather;
		}
	}
}

void szVegetations()
{

	float* newVegetations = (float*)0x140F2B9B0;
	DWORD oldProtect;
	VirtualProtect(newVegetations, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
	*newVegetations = Config::szVegetations;
	VirtualProtect(newVegetations, sizeof(float), oldProtect, &oldProtect);
}






