#include "../../Includes.h"

extern bool EarlyMorning;
extern bool Morning;
extern bool Noon;
extern bool Afternoon;
extern bool Evening;
extern bool Night;	
extern bool Midnight;

void ResolverEarlyMorningNFSHPR()
{
	if (Client && EarlyMorning)
	{
		uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
		if (Address == 0) return;

		float* EarlyMorning_fTime = (float*)(Address + 0x129A80); 	

		*EarlyMorning_fTime = 17000.0f; 
	}
}

void ResolverMorningNFSHPR()
{
	if (Client && Morning)
	{
		uintptr_t Address = *(uintptr_t*)(Client + 0x1298C10);
		if (Address == 0) return;

		float* Morning_fTime = (float*)(Address + 0x129A80); 

		*Morning_fTime = 20000.0;
	}
}	

void ResolverNoonNFSHPR()
{

}

void ResolverAfternoonNFSHPR()
{

}

void ResolverEveningNFSHPR()
{

}

void ResolverNightNFSHPR()
{

}

void ResolverMidnightNFSHPR()
{

}