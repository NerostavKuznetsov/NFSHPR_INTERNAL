#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::Tab_0()
{
	//==================================================================================
	//= Child-0-0 Left Side ============================================================
	//==================================================================================
	ImGui::SetCursorPos(ImVec2(266, 76));
	ImGui::BeginChild("Child-0-0", ImVec2(376, 166), false);
	{
		if (ImGui::Checkbox("Unlimited Nitrous", &Config::UnlimitedNitrous))
		{
			Menu::PlayToggleBeep(Config::UnlimitedNitrous);
		}

		if (ImGui::Checkbox("Reset Timer", &Config::ResetTimer))
		{
			Menu::PlayToggleBeep(Config::ResetTimer);
		}

		if (ImGui::Checkbox("God Mode", &Config::GodMode))
		{
			Menu::PlayToggleBeep(Config::GodMode);
		}
	}
	ImGui::EndChild();

	//==================================================================================
	//= Child-0-1 Left Side ============================================================
	//==================================================================================
	ImGui::SetCursorPos(ImVec2(266, 255));
	ImGui::BeginChild("Child-0-1", ImVec2(376, 166), false);
	{

	}
	ImGui::EndChild();

	//==================================================================================
	//= Child-0-2 Right Side =============================d==============================
	//==================================================================================
	ImGui::SetCursorPos(ImVec2(658, 76));
	ImGui::BeginChild("Child-0-2", ImVec2(376, 166), false);
	{
		ImGui::Checkbox("Unlimited Racers Weapons", &Config::UnlimitedRacersWeapons);
		ImGui::Checkbox("No Cooldown Racer Weapons", &Config::NoCooldownRacersWeapons);
		bool AutoJammer = false;	
		ImGui::Checkbox("Auto JAMMER", &AutoJammer);
	}
	ImGui::EndChild();

	//==================================================================================
	//= Child-0-3 Right Side ===========================================================
	//==================================================================================
	ImGui::SetCursorPos(ImVec2(658, 255));
	ImGui::BeginChild("Child-0-3", ImVec2(376, 166), false);
	{
		ImGui::Checkbox("Unlimited Police Weapons", &Config::UnlimitedPoliceWeapons);
		ImGui::Checkbox("No Cooldown Police Weapons", &Config::NoCooldownPoliceWeapons);
		bool AutoEMP = false;
		ImGui::Checkbox("Auto SPIKES", &AutoEMP);
	}
	ImGui::EndChild();
}