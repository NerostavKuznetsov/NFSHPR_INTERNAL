//#include "../../Includes.h"
//
//char instructionCooldownBytesOriginal[6] = { 0 };
//
//bool initializedNoCooldownNFSHPR = false;
//
//extern bool NoCooldown;
//
//void ResolverNoCooldownNFSHPR()
//{
//	uintptr_t Client = (uintptr_t)GetModuleHandle(L"NFS11Remastered.exe");
//	uintptr_t NoCooldownAddress = Client + 0x25B406;
//
//	if (!initializedNoCooldownNFSHPR)
//	{
//		// Salvar os bytes originais
//		memcpy(instructionCooldownBytesOriginal, (char*)NoCooldownAddress, sizeof(instructionCooldownBytesOriginal));
//		initializedNoCooldownNFSHPR = true;
//	}
//
//	if (NoCooldown)
//	{
//		DWORD oldProtect;
//		VirtualProtect((LPVOID)NoCooldownAddress, sizeof(instructionCooldownBytesOriginal), PAGE_EXECUTE_READWRITE, &oldProtect);
//		memset((LPVOID)NoCooldownAddress, 0x90, sizeof(instructionCooldownBytesOriginal)); // 0x90 é o opcode para NOP
//		//char instructionNOP[] = {  };	
//	}
//}