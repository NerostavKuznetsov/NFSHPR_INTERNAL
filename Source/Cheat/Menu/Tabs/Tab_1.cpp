#include "../../../Includes.h"

void Tabs::Weathers()
{
	{
		// Aqui vai tudo que estava dentro de -> if (active_tab == 1) { ... }
		//const auto& p = ImGui::GetWindowPos();

		ImGui::GetWindowDrawList()->AddText(Inter_S_2, 23.f, ImVec2(p.x + 246 + anim_text, p.y + 18), ImGui::GetColorU32(c::text_active), "[Weathers]");
		ImGui::SetCursorPos(ImVec2(266, 76));
		ImGui::BeginChild("Tab-2", ImVec2(376, 166), false);
		{
			const char* TimesOfDay[] =
			{
				"Early Morning", "Morning", "Noon", "Afternoon", "Evening", "Night", "Midnight"
			};

			ImGui::Checkbox("Enable Time Override", &Config::ChangeTime);
			ImGui::Combo("Time of Day", &Config::ChangeTimeType, TimesOfDay, IM_ARRAYSIZE(TimesOfDay));
		}
		ImGui::EndChild();
	}
}