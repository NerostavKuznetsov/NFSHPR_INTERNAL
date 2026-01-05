#include "../../../External/ImGui/imgui.h"
#include "../Config/Config.h"
#include "../Menu/Menu.h"

constexpr float defaultVegetationSize = 0.007874015719f;

void SizeOfVegetations()
{
	float* SizeVegetations = (float*)0x140F2B9B0;
	if (!SizeVegetations) return;

    static bool lastEnabled = false;
    static float lastValue = -1.0f;

    float valueToWrite;

    if (lastEnabled && !Config::szVegetationsCheckBox)
    {
        valueToWrite = defaultVegetationSize;
        Config::szVegetations = defaultVegetationSize; 
    }
    else if (Config::szVegetationsCheckBox)
    {
        valueToWrite = Config::szVegetations;
    }
    else
    {
        valueToWrite = defaultVegetationSize;
    }

    lastEnabled = Config::szVegetationsCheckBox;

    if (lastValue == valueToWrite)
        return;

	DWORD oldProtect;
	VirtualProtect(SizeVegetations, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
    *SizeVegetations = valueToWrite;
	VirtualProtect(SizeVegetations, sizeof(float), oldProtect, &oldProtect);

    lastValue = valueToWrite;
}