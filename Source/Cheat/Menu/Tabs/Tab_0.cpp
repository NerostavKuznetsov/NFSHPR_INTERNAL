#include "../../../../External/ImGui/imgui_settings.h"
#include "../../Config/Config.h"
#include "../Tabs/Tab_Config.h"
#include "../Menu.h"

void Tabs::Gameplay()
{
	void Gameplay();
	{
		// ----------------------------------------------------------------------------------
		// Child-0-0 / (266, 76) = Posição do child / (376, 166) = Lagura & Altura do child
		// ----------------------------------------------------------------------------------
		ImGui::SetCursorPos(ImVec2(266, 76)); 
		ImGui::BeginChild("Child-0-0", ImVec2(376, 220), false); 
		{
			ImGui::Checkbox("Unlimited Nitrous", &Config::UnlimitedNitrous);

			ImGui::Checkbox("Enable Nitrous Slider", &Config::NitrousSlider);
			ImGui::SliderFloat("Nitrous Slider Value", &Config::NitrousSliderValue, 0.0f, 100.0f);


			static float color1[4] = { 255.f / 255.f, 0.f / 255.f, 0.f / 255.f };
			ImGui::ColorEdit4("Nitrous Fire Color", color1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("God Mode", &Config::GodMode);
		}
		ImGui::EndChild();

		// ------------------------------------------------------------------
		// Child-0-1 
		// ------------------------------------------------------------------
		ImGui::SetCursorPos(ImVec2(658, 76)); 
		ImGui::BeginChild("Child-0-1", ImVec2(376, 220), false); 
		{
			static bool Testando1 = false;
			ImGui::Checkbox("Unlimited Racers Weapons", &Config::UnlimitedRacersWeapons);
			ImGui::Checkbox("No Cooldown Racer Weapons", &Config::NoCooldownRacersWeapons);

			static bool Testando2 = false;
			ImGui::Checkbox("Unlimited Police Weapons", &Testando2);
			ImGui::Checkbox("No Cooldown Police Weapons", &Config::NoCooldownPoliceWeapons);
		}
		ImGui::EndChild();











	}
}