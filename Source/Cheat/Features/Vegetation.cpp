#include "../../../External/ImGui/imgui.h"
#include "../Config/Config.h"
#include "../Menu/Menu.h"

void szVegetations()
{
	float* SizeVegetations = (float*)0x140F2B9B0;
	DWORD oldProtect;
	VirtualProtect(SizeVegetations, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
	*SizeVegetations = Config::szVegetations;
	VirtualProtect(SizeVegetations, sizeof(float), oldProtect, &oldProtect);
}