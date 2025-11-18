#pragma once

namespace Config
{
	void Init();

	inline bool ChangeTime;
	inline int ChangeTimeType;



	inline bool       MenuToggleKey = VK_INSERT;
	inline bool       MenuShow = false;
	// No Cooldown Weapons Racer NFSHPR
	inline bool       NoCooldownRacerWeaponsNFSHPR = false;
	// No Cooldown Weapons Police NFSHPR
	inline bool       NoCooldownPoliceWeaponsNFSHPR = false;


	// Weapons Racer NFSHPR
	inline float      RacerWeaponDamageNFSHPR = 1.0f;
	inline float      RacerWeaponRangeNFSHPR = 1.0f;
	inline float      RacerWeaponFireRateNFSHPR = 1.0f;
	inline float      RacerWeaponRecoilNFSHPR = 1.0f;

	// Weapons Police NFSHPR
	inline float      PoliceWeaponDamageNFSHPR = 1.0f;
	inline float      PoliceWeaponRangeNFSHPR = 1.0f;
	inline float      PoliceWeaponFireRateNFSHPR = 1.0f;
	inline float      PoliceWeaponRecoilNFSHPR = 1.0f;
}