#include "../../../../External/ImGui/imgui_settings.h"
#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::Tab_1()
{
	// ----------------------------------------------------------------------------------
	// Note Text 
	// ----------------------------------------------------------------------------------
	ImVec2 childStart = ImGui::GetCursorPos(); // Salva posição normal onde o child deveria começar
	ImGui::SetCursorPos(ImVec2(520, 20));
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(180, 180, 255, 255));
	ImGui::TextWrapped("Note: Weather effects may vary depending on time of day and location.");
	ImGui::PopStyleColor();
	ImGui::SetCursorPos(childStart); // Volta o cursor para a posição original para iniciar os childs alinhados

	// ----------------------------------------------------------------------------------
	// Child-0-0 Left Side
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(266, 76)); // Posição do primeiro child x,y
	ImGui::BeginChild("Child-0-0", ImVec2(376, 166), false); //  Lagura & Altura do child h,l
	{
		const char* TimesOfDay[] =
		{
			"Early Morning",
			"Morning",
			"Noon",
			"Afternoon",
			"Evening",
			"Night",
			"Midnight"
		};

		ImGui::Checkbox("Enable Time of day", &Config::Time);
		ImGui::Combo("Time of day", &Config::TimeValue, TimesOfDay, IM_ARRAYSIZE(TimesOfDay));
	}
	ImGui::EndChild();

	// ----------------------------------------------------------------------------------
	// Child-0-1 Left Side
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(266, 255));
	ImGui::BeginChild("Child-0-1", ImVec2(376, 166), false);
	{
		ImGui::Checkbox("Enable Time Slider", &Config::TimeSlider);

		ImGui::BeginDisabled(!Config::TimeSlider);
		{
			if (ImGui::SliderFloat("Time Slider", &Config::TimeSliderValue, 0.0f, 86400.0f, "%.0f"))
			{
				Config::TimeUserEditing = true;
				Config::TimeEditTimer = 0.50f;
			}
		}
		ImGui::EndDisabled();
	}
	ImGui::EndChild();

	// ----------------------------------------------------------------------------------
	// Child-0-2 Right Side  
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(658, 255));
	ImGui::BeginChild("Child-0-2", ImVec2(376, 166), false);
	{
		const char* MainWeathersID[] =
		{
			"Sunny",
			"Sunny After Rain",
			"Sunny + Rain/Snow [Non-Wet Roads]",
			"Sunny + Rain/Snow [Wet Roads]",
			"Cloudy",
			"Cloudy [Wet Roads]",
			"Cloudy + Rain/Snow [Non-Wet Roads]",
			"Cloudy + Rain/Snow [Wet Roads]",
			"Thunderstorm",
			"Thunderstorm [Wet Roads]",
			"Thunderstorm + Rain [Non-Wet Roads]",
			"Thunderstorm + Rain [Wet Roads]"
		};

		ImGui::Checkbox("Enable Weather Phenomena", &Config::MainWeatherID);
		ImGui::Combo("Weather Phenomena", &Config::MainWeatherIDValue, MainWeathersID, IM_ARRAYSIZE(MainWeathersID));
	}
	ImGui::EndChild();

	// ----------------------------------------------------------------------------------
    // Child-0-3 Right Side 
    // ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(658, 76));
	ImGui::BeginChild("Child-0-3", ImVec2(376, 166), false);
	{
		const char* AlternativeWeathersID[] =
		{
			"Fog 0 (Cloudy Weather is recommended)",
			"Fog 1 (Cloudy Weather is recommended)",
			"Fog 2 (Cloudy Weather is recommended)",
			"Fog 3 (Cloudy Weather is recommended)",
			"Fog 4 (Cloudy Weather is recommended)",
			"Fog 5 (Cloudy Weather is recommended)",
			"Fog 6 (Cloudy Weather is recommended)",

			"Autumn (Sunny Weather is recommended)",
			"Sunny 1 (Sunny Weather is recommended)",
			"Sunny 2 (Sunny Weather is recommended)",

			"Desert",
			"Heatwave 1",
			"Heatwave 2",
			"Heatwave 3",
			"Heatwave 4",
			"Heatwave 5",

			"Foggy/Clear 1 (Fog can be used)",
			"Foggy/Clear 2 (Fog can be used)",
			"Foggy/Clear 3 (Fog can be used)",
			"Polar Night 1 (Fog can be used)",
			"Polar Night 2 (Fog can be used)"
		};

		ImGui::Checkbox("Enable Alternative Weather", &Config::AlternativeWeatherID);
		ImGui::Combo("Alternative Weather", &Config::AlternativeWeatherIDValue, AlternativeWeathersID, IM_ARRAYSIZE(AlternativeWeathersID));
	}
	ImGui::EndChild();
}