#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::Tab_2()
{
	// ==================================================================================
	// Child-0-0 Left Side
	// ==================================================================================
	ImGui::SetCursorPos(ImVec2(266, 76));
	ImGui::BeginChild("Child-0-0", ImVec2(376, 166), false);
	{
		{
			if (ImGui::Checkbox("Enable Size of Vegetations", &Config::szVegetationsCheckBox))
			{
				Menu::PlayToggleBeep(Config::szVegetationsCheckBox);
			}
			ImGui::BeginDisabled(!Config::szVegetationsCheckBox);
			ImGui::SliderFloat("Size of Vegetations", &Config::szVegetations, 0.0f, 0.08f, "");
			ImGui::EndDisabled();
		}
		ImGui::EndChild();
	}

	// ==================================================================================
	// Child-0-1 Right Side
	// ==================================================================================
	ImGui::SetCursorPos(ImVec2(658, 76));
	ImGui::BeginChild("Child-0-1", ImVec2(376, 166), false);
	{
		if (ImGui::Checkbox("Enable Cloud Acceleration", &Config::CloudAccelerationCheckBox))
		{
			Menu::PlayToggleBeep(Config::CloudAccelerationCheckBox);
		}
		ImGui::BeginDisabled(!Config::CloudAccelerationCheckBox);
		ImGui::SliderFloat("Cloud Acceleration", &Config::CloudAcceleration, 0.200000003f, 500.0f, "");
		ImGui::EndDisabled();
	}
	ImGui::EndChild();
}