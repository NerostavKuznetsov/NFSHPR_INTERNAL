#include "../Controller/Controller.h"
#include "../Features/NoCooldownWeapons.h"
#include "../Features/Nitrous.h"
#include "../Features/Weapons.h"
#include "../Features/Weathers.h"	
#include "../Features/GodMode.h"

namespace Controller
{
	void Execute()
	{
		UnlimitedNitrous();
		UnlimitedRacersWeapons();
		//UnlimitedPoliceWeapons();

		NoCooldownPoliceWeapons();
		NoCooldownRacerWeapons();

		Time();
		MainWeatherID();


		GodMode();
	}
}