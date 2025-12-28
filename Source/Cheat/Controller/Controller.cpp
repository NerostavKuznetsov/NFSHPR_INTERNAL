#include "../Controller/Controller.h"
#include "../Features/NoCooldownWeapons.h"
#include "../Features/Nitrous.h"
#include "../Features/Weapons.h"
#include "../Features/Weathers.h"	
#include "../Features/GodMode.h"
#include "../Features/Vegetation.h"

namespace Controller
{
	void Execute()   // Ajustar bagunça
	{
		UnlimitedNitrous();
		NitrousSlider();

		UnlimitedRacersWeapons();
		UnlimitedPoliceWeapons();

		NoCooldownPoliceWeapons();
		NoCooldownRacerWeapons();

		Time();
		SliderTime();
		MainWeatherID();

		Time();
		SliderTime();
		MainWeatherID();
		AlternativeWeatherID();
		szVegetations();
		GodMode();

	}
}