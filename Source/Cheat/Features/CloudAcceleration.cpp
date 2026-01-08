#include "../../../External/ImGui/imgui.h"
#include "../Config/Config.h"
#include "../Menu/Menu.h"

constexpr float defaultCloudAcceleration = 0.200000003f;

void CloudAcceleration()
{
	float* CloudAccel = (float*)0x1411C4FA8;
	float valueToWrite;

	static bool lastEnabled = false;
	static float lastValue = -1.0f;

	if (lastEnabled && !Config::CloudAccelerationCheckBox)
	{
		valueToWrite = defaultCloudAcceleration;
		Config::CloudAcceleration = defaultCloudAcceleration;
	}
	else if (Config::CloudAccelerationCheckBox)
	{
		valueToWrite = Config::CloudAcceleration;
	}
	else
	{
		valueToWrite = defaultCloudAcceleration;
	}
	lastEnabled = Config::CloudAccelerationCheckBox;

	if (lastValue == valueToWrite)
		return;

	DWORD oldProtect;
	VirtualProtect(CloudAccel, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
	*CloudAccel = valueToWrite;
	VirtualProtect(CloudAccel, sizeof(float), oldProtect, &oldProtect);

	lastValue = valueToWrite;
}