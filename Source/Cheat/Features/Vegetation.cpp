#include "../../../External/ImGui/imgui.h"
#include "../Config/Config.h"
#include "../Menu/Menu.h"

void szVegetations()
{
	float* newVegetations = (float*)0x140F2B9B0;
	DWORD oldProtect;
	VirtualProtect(newVegetations, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
	*newVegetations = Config::szVegetations;
	VirtualProtect(newVegetations, sizeof(float), oldProtect, &oldProtect);
}