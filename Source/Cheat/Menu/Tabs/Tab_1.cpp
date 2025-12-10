#include "../../../Includes.h"

void Tabs::Weathers()
{
	{
		const auto& p = ImGui::GetWindowPos();
		ImGui::GetWindowDrawList()->AddText(Inter_S_2, 23.f, ImVec2(p.x + 246 + anim_text, p.y + 18), ImGui::GetColorU32(c::text_active), "[Weathers]";





		ImGui::SetCursorPos(ImVec2(266, 76)); // Posição do primeiro child
		ImGui::BeginChild("Tab-1-A", ImVec2(376, 166), false); // Início do primeiro child
		{
			const char* TimesOfDay[] =
			{
				"Early Morning", "Morning", "Noon", "Afternoon", "Evening", "Night", "Midnight"
			};

			ImGui::Checkbox("Enable Time Override", &Config::ChangeTime);
			ImGui::Combo("Time of Day", &Config::ChangeTimeType, TimesOfDay, IM_ARRAYSIZE(TimesOfDay));
		}
		ImGui::EndChild(); 

		/////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////

		ImGui::SetCursorPos(ImVec2(658, 76));
		ImGui::BeginChild("Tab-1-B", ImVec2(376, 166), false);
		{




		}
		ImGui::EndChild();
	}
}