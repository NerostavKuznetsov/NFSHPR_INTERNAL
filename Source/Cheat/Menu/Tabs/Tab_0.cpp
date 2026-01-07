#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"
#include <thread>


void Tabs::Tab_0()
{
	// ----------------------------------------------------------------------------------
	// Child-0-0 / (266, 76) = Posição do child / (376, 166) = Lagura & Altura do child
	// ----------------------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(266, 76));
	ImGui::BeginChild("Child-0-0", ImVec2(376, 320), false);
	{
		if (ImGui::Checkbox("Unlimited Nitrous", &Config::UnlimitedNitrous))
		{
			if (Config::UnlimitedNitrous)
			{
				std::thread([](){Beep(1300, 60);}).detach();
			}
			else
			{
				std::thread([]()
					{
						Beep(700, 90); // DESLIGAR → grave, mais longo
					}).detach();
			}
		}

		if (ImGui::Checkbox("Enable Nitrous Slider", &Config::NitrousSlider))
		{
			if (Config::NitrousSlider)
			{
				std::thread([]()
					{
						Beep(1300, 60); // LIGOU slider → beep curto/agudo
					}).detach();
			}
			else
			{
				std::thread([]()
					{
						Beep(700, 90); // DESLIGOU slider → beep mais grave
					}).detach();
			}
		}

		ImGui::BeginDisabled(!Config::NitrousSlider);
		{
			if (ImGui::SliderFloat("Nitrous Slider", &Config::NitrousSliderValue, 0.0f, 100.0f,  "%.1f"))
			{
				Config::NitrousUserEditing = true;
				Config::NitrousEditTimer = 0.50f; 
			}
		}
		ImGui::EndDisabled();

		ImGui::Checkbox("Reset Timer (once)", &Config::ResetTimerOnce);
		ImGui::Checkbox("Freeze Timer (0.00.00)", &Config::FreezeTimer);



	}
	ImGui::EndChild();

	// ------------------------------------------------------------------
	// Child-0-1 
	// ------------------------------------------------------------------
	ImGui::SetCursorPos(ImVec2(658, 76));
	ImGui::BeginChild("Child-0-1", ImVec2(376, 299), false);
	{
		ImGui::Checkbox("Unlimited Racers Weapons", &Config::UnlimitedRacersWeapons);
		ImGui::Checkbox("No Cooldown Racer Weapons", &Config::NoCooldownRacersWeapons);

		ImGui::Checkbox("Unlimited Police Weapons", &Config::UnlimitedPoliceWeapons);
		ImGui::Checkbox("No Cooldown Police Weapons", &Config::NoCooldownPoliceWeapons);

		ImGui::Checkbox("God Mode", &Config::GodMode);
	}
	ImGui::EndChild();
}