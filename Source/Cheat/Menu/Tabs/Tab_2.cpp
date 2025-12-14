#include "../../../../External/ImGui/imgui_settings.h"
#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::VehicleOptions()
{
	{
		// ----------------------------------------------------------------------------------
		// Child-0-0
		// ----------------------------------------------------------------------------------
		ImGui::SetCursorPos(ImVec2(266, 76));
		ImGui::BeginChild("Child-0-0", ImVec2(376, 166), false);
		{
			const char* ColorTypes[] =
			{
				"Black", "Blue", "Yellow", "Green", "Purple", "Cyan", "DodgerBlue", "Chocolate", "Orchid", "SlateBlue", "SeaGreen"
			};

			static bool Testando = false;
			ImGui::Checkbox("Enable Drift Smoke", &Testando);
			ImGui::Combo("Smoke Colors", &Config::testandoCor, ColorTypes, IM_ARRAYSIZE(ColorTypes));
		}
		ImGui::EndChild();
	}
}