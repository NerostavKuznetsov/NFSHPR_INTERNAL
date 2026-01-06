#include "../../../../External/ImGui/imgui_settings.h"
#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::VehicleOptions()
{

	// ----------------------------------------------------------------------------------
	// Child-0-0 Left Side
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(266, 76));
	ImGui::BeginChild("Child-0-0", ImVec2(376, 166), false);
	{
		{
			ImGui::Checkbox("Enable Size of Vegetations", &Config::szVegetationsCheckBox);

			ImGui::BeginDisabled(!Config::szVegetationsCheckBox);
			ImGui::SliderFloat("Size of Vegetations", &Config::szVegetations, 0.0f, 0.08f, "%.12f");
			ImGui::EndDisabled();
		}
		ImGui::EndChild();
	}

	// ----------------------------------------------------------------------------------
	// Child-0-1 Right Side
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(658, 76));
	ImGui::BeginChild("Child-0-1", ImVec2(376, 166), false);
	{
		ImGui::Checkbox("Enable Cloud Acceleration", &Config::CloudAccelerationCheckBox);

		ImGui::BeginDisabled(!Config::CloudAccelerationCheckBox);
		ImGui::SliderFloat("Cloud Acceleration", &Config::CloudAcceleration, 0.200000003f, 999.0f, "%.9f");
		ImGui::EndDisabled();
	}
	ImGui::EndChild();

	// ----------------------------------------------------------------------------------
	// Child-0-2 Left Side
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(266, 255));	
	ImGui::BeginChild("Child-0-2", ImVec2(376, 166), false); 
	{

	}
	ImGui::EndChild();

	// ----------------------------------------------------------------------------------
	// Child-0-3 Left Side
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(658, 255));
	ImGui::BeginChild("Child-0-3", ImVec2(376, 166), false);
	{

	}
	ImGui::EndChild();	
}