#include "../../../../External/ImGui/imgui_settings.h"
#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::Weathers()
{
	{
		// ----------------------------------------------------------------------------------
		// Note Text / (valores maiores descem, valores maiores vao para direita)
		// ----------------------------------------------------------------------------------
		ImVec2 childStart = ImGui::GetCursorPos(); // salva posição normal onde o child deveria começar
		ImGui::SetCursorPos(ImVec2(520, 20));
  		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(180, 180, 255, 255));
		ImGui::TextWrapped("Note: Weather effects may vary depending on time of day and location.");
		ImGui::PopStyleColor();
		ImGui::SetCursorPos(childStart); // volta o cursor para a posição original para iniciar os childs alinhados

		// ----------------------------------------------------------------------------------
		// Child-0-0 / (266, 76) = Posição do child / (376, 166) = Lagura & Altura do child
		// ----------------------------------------------------------------------------------
		ImGui::SetCursorPos(ImVec2(266, 76)); // Posição do primeiro child
		ImGui::BeginChild("Child-0-0", ImVec2(376, 400), false); // Início do primeiro child
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
			ImGui::Combo("Time of day", &Config::ValueTime, TimesOfDay, IM_ARRAYSIZE(TimesOfDay));

			ImGui::Checkbox("Enable Slider Time", &Config::UseTimeSlider);
			ImGui::SliderFloat("Slider Time", &Config::SliderTime, 0.0f, 86000.0f, "%.5f");
		}
		ImGui::EndChild(); 

		// ----------------------------------------------------------------------------------
		// Child-0-1
		// ----------------------------------------------------------------------------------
		ImGui::SetCursorPos(ImVec2(658, 76));
		ImGui::BeginChild("Child-0-1", ImVec2(376, 166), false);
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
			ImGui::Combo("Weather Phenomena", &Config::ChangeMainWeatherID, MainWeathersID, IM_ARRAYSIZE(MainWeathersID));
		}
		ImGui::EndChild();
	}
}