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
	case 6: *Current_Time = 0.0f; break;
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
	case 0: *Current_MainWeatherID = 0; break;
	case 1: *Current_MainWeatherID = 1; break;
	case 2: *Current_MainWeatherID = 2; break;
	case 3: *Current_MainWeatherID = 3; break;
	case 4: *Current_MainWeatherID = 8; break;
	case 5: *Current_MainWeatherID = 9; break;
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

	if (Config::AlternativeWeatherID)
	{
		switch (Config::AlternativeWeatherIDValue)
		{
		case 0: *Current_AlternativeWeatherID = 11; break;
		case 1: *Current_AlternativeWeatherID = 2;  break;
		case 2: *Current_AlternativeWeatherID = 3;  break;
		case 3: *Current_AlternativeWeatherID = 5;  break;
		case 4: *Current_AlternativeWeatherID = 14; break;
		case 5: *Current_AlternativeWeatherID = 17; break;
		case 6: *Current_AlternativeWeatherID = 27; break;
		case 7: *Current_AlternativeWeatherID = 4; break;
		case 8: *Current_AlternativeWeatherID = 6; break;
		case 9: *Current_AlternativeWeatherID = 26; break;
		case 10: *Current_AlternativeWeatherID = 25;  break;
		case 11: *Current_AlternativeWeatherID = 18;  break;
		case 12: *Current_AlternativeWeatherID = 1;  break;
		case 13: *Current_AlternativeWeatherID = 23; break;
		case 14: *Current_AlternativeWeatherID = 24; break;
		case 15: *Current_AlternativeWeatherID = 21; break;
		case 16: *Current_AlternativeWeatherID = 15;  break;
		case 17: *Current_AlternativeWeatherID = 19;  break;
		case 18: *Current_AlternativeWeatherID = 0;  break;
		case 19: *Current_AlternativeWeatherID = 16; break;
		case 20: *Current_AlternativeWeatherID = 20; break;
		default: return;
		}
	}
}







