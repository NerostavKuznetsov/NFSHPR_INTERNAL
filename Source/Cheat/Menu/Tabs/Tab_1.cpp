#include "../../../../External/ImGui/imgui_settings.h"
#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::Weathers()
{
	{
		// ----------------------------------------------------------------------------------
		// Weathers Animated Text
		// ----------------------------------------------------------------------------------
		const auto& p = ImGui::GetWindowPos();
		ImGui::GetWindowDrawList()->AddText(Inter_S_2, 23.f, ImVec2(p.x + 246 + anim_text, p.y + 18), ImGui::GetColorU32(c::text_active), "[Weathers]");

		// ----------------------------------------------------------------------------------
		// Child-0-0 / (266, 76) = Posição do child / (376, 166) = Lagura & Altura do child
		// ----------------------------------------------------------------------------------
		ImGui::SetCursorPos(ImVec2(266, 76)); // Posição do primeiro child
		ImGui::BeginChild("Child-0-0", ImVec2(376, 166), false); // Início do primeiro child
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

			ImGui::Checkbox("Enable Time", &Config::Time);
			ImGui::Combo("Time", &Config::ChangeTime, TimesOfDay, IM_ARRAYSIZE(TimesOfDay));
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
				"Sunny + Rain/Snow (Non-Wet Roads)",
				"Sunny + Rain/Snow (Wet Roads)",
				"Cloudy",
				"Cloudy (Wet Roads)",
				"Cloudy + Rain/Snow (Non-Wet Roads)",
				"Cloudy + Rain/Snow (Wet Roads)",
				"Thunderstorm",
				"Thunderstorm (Wet Roads)",
				"Thunderstorm + Rain (Non-Wet Roads)",
				"Thunderstorm + Rain (Wet Roads)"
			};

			ImGui::Checkbox("Enable MainWeatherID", &Config::MainWeatherID);
			ImGui::Combo("MainWeatherID", &Config::ChangeMainWeatherID, MainWeathersID, IM_ARRAYSIZE(MainWeathersID));
		}
		ImGui::EndChild();
	}
}