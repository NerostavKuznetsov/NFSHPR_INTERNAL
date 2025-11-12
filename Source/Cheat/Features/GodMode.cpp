#include "../../Includes.h"

char instructionDamageBytesOriginal[15] = { 0 };

bool initializedGodModeNFSHPR = false;

extern bool GodMode;

// bd code
void ResolverGodModeNFSHPR()
{
	uintptr_t Client = (uintptr_t)GetModuleHandle(L"NFS11Remastered.exe");
	uintptr_t DamageAddress = Client + 0x4D352F;

	if (!initializedGodModeNFSHPR)
	{
		// Salvar os bytes originais
		memcpy(instructionDamageBytesOriginal, (char*)DamageAddress, sizeof(instructionDamageBytesOriginal));
		initializedGodModeNFSHPR = true;
	}

	if (GodMode)
	{
		// NOP nos bytes para desativar o dano
		DWORD oldProtect;
		VirtualProtect((LPVOID)DamageAddress, sizeof(instructionDamageBytesOriginal), PAGE_EXECUTE_READWRITE, &oldProtect);
		memset((LPVOID)DamageAddress, 0x90, sizeof(instructionDamageBytesOriginal)); // 0x90 é o opcode para NOP
		char instructionNOP[] = { 0x48, 0xC7, 0x83, 0x60, 0x1F, 0x00, 0x00, 0x0, 0x00, 0x00, 0x00 };
		memcpy((char*)DamageAddress, instructionNOP, sizeof(instructionNOP));
		VirtualProtect((LPVOID)DamageAddress, sizeof(instructionDamageBytesOriginal), oldProtect, &oldProtect);
	}
	else
	{
		// Restaurar os bytes originais
		DWORD oldProtect;
		VirtualProtect((LPVOID)DamageAddress, sizeof(instructionDamageBytesOriginal), PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy((char*)DamageAddress, instructionDamageBytesOriginal, sizeof(instructionDamageBytesOriginal));
		VirtualProtect((LPVOID)DamageAddress, sizeof(instructionDamageBytesOriginal), oldProtect, &oldProtect);
	}
}