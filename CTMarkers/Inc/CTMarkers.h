/*===========================================================================
	C++ class definitions exported from UnrealScript.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#ifndef CTMARKERS_NATIVE_DEFS
#define CTMARKERS_NATIVE_DEFS

#include "../../CTGame/Inc/CTGame.h"

#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif

#ifndef CTMARKERS_API
#define CTMARKERS_API DLL_IMPORT
LINK_LIB(CTMarkers)
#endif

/*
*	ExplosiveCharge
*/

class CTMARKERS_API AExplosiveCharge : public AActivateItem{
public:
	FActivationInfo ChargeUnplaced;
	FActivationInfo ChargePlaced;
	FActivationInfo ChargeArmed;
	FActivationInfo ChargeExplode;
	class AProp* PropToDestroy;
	BYTE ExplosionStimulus;
	BITFIELD bExplodeOnTimer:1;

	DECLARE_CLASS(AExplosiveCharge,AActivateItem,0,CTMarkers)
	NO_DEFAULT_CONSTRUCTOR(AExplosiveCharge)
};

/*
*	MarkerDemolitionNative
*/

class CTMARKERS_API AMarkerDemolitionNative : public ACTMarker{
public:
	FName PlaceEvent;

	DECLARE_CLASS(AMarkerDemolitionNative,ACTMarker,0,CTMarkers)

	//UBOOL Initiate(APawn* Instigator);
	UBOOL Update();
	virtual UBOOL FinishMarker();
	virtual void OnCancel(APawn *Instigator);
};

/*
*	MarkerDisarmTrapNative
*/

class CTMARKERS_API AMarkerDisarmTrapNative : public ACTMarker{
public:
	FName RemoveEvent;

	DECLARE_CLASS(AMarkerDisarmTrapNative,ACTMarker,0,CTMarkers)

	UBOOL Initiate(APawn* Instigator);
	UBOOL Update();
	virtual void ParticipantResume(APawn *Member, UGoalObject *CurrentGoal);
	virtual UBOOL FinishMarker();
	virtual void OnCancel(APawn *Instigator);
};

/*
*	MarkerDoorBreachNative
*/

class CTMARKERS_API AMarkerDoorBreachNative : public ACTMarker{
public:
	FName DestroySwitchEvent;
	FName TossGrenadeEvent;
	class UClass* GrenadeClass;
	class AActor* GrenadeTarget;

	DECLARE_CLASS(AMarkerDoorBreachNative,ACTMarker,0,CTMarkers)

	UBOOL Initiate(APawn* Instigator);
	UBOOL Update();
	virtual void ParticipantResume(APawn *Member, UGoalObject *CurrentGoal);
	//virtual bool SortParticipants(int PotentialParticipants, int TotalParticipants);
};

/*
*	MarkerHackDoorNative
*/

class CTMARKERS_API AMarkerHackDoorNative : public ACTMarker{
public:
	DECLARE_CLASS(AMarkerHackDoorNative,ACTMarker,0,CTMarkers)

	UBOOL Update();
	virtual UBOOL FinishMarker();
	virtual void OnCancel(APawn *Instigator);
};

/*
*	MarkerHackTerminalNative
*/

class CTMARKERS_API AMarkerHackTerminalNative : public ACTMarker{
public:
	DECLARE_CLASS(AMarkerHackTerminalNative,ACTMarker,0,CTMarkers)

	UBOOL Update();
	virtual UBOOL FinishMarker();
	virtual void OnCancel(APawn *Instigator);
};

/*
*	MarkerSetProximityMinNative
*/

class CTMARKERS_API AMarkerSetProximityMineNative : public ACTMarker{
public:
	FName PlaceEvent;
	FName ArmEvent;

	DECLARE_CLASS(AMarkerSetProximityMineNative,ACTMarker,0,CTMarkers)

	//UBOOL Initiate(APawn* Instigator);
	virtual UBOOL Update();
};

/*
*	MarkerTriggerLoop
*/

class CTMARKERS_API AMarkerTriggerLoop : public ACTMarker{
public:
	FName CancelUntriggerEvent;
	FName CancelTriggerEvent;
	class AActor* DirectTrigger;

	DECLARE_CLASS(AMarkerTriggerLoop,ACTMarker,0,CTMarkers)

	UBOOL Update();
	virtual UBOOL FinishMarker();
	virtual UBOOL CanInitiateFor(APawn *Pawn);
	//virtual UBOOL IsRelevantFor(APawn *Pawn);
};

/*
*	MarkerTurretNative
*/

class CTMARKERS_API AMarkerTurretNative : public ACTMarker{
public:
	DECLARE_CLASS(AMarkerTurretNative,ACTMarker,0,CTMarkers)

	UBOOL Initiate(APawn* Instigator);
	UBOOL Update();
	virtual UBOOL FinishMarker();
	//virtual void MemberKilled(APawn *Victim, AController *Killer, UClass *DamageType);
};

/*
*	MarkerWeapon
*/

enum EMarkerWeaponType{
	MWT_Sniper,
	MWT_AntiArmor,
	MWT_Grenade,
	MWT_MAX
};

class CTMARKERS_API AMarkerWeapon : public ACTMarker{
public:
	BYTE MarkerWeaponType;
	class AActor* WeaponTarget;
	FLOAT WeaponTargetRadius;
	FLOAT Accuracy;
	FLOAT FOV;
	class UClass* GrenadeClass;
	BYTE CompleteCue;
	class UStaticMesh* LocationPreviewMesh;
	class AActor* LocationPreviewActor;

	DECLARE_CLASS(AMarkerWeapon,ACTMarker,0,CTMarkers)

	virtual UBOOL Initiate(APawn* Instigator);
	virtual UBOOL Update();
	virtual UBOOL FinishMarker();
};

/*
*	StateMarkerAttack
*/

class CTMARKERS_API UStateMarkerAttack : public UStateAbstractAttack{
public:
	class AMarkerWeapon* Marker;
	FLOAT ShotInterval;
	FLOAT LastWeaponChange;
	INT NumKills;
	INT WeaponGroup;
	FRotator StartRotation;
	FVector StartLocation;
	BITFIELD bNormalRifle:1;

	DECLARE_CLASS(UStateMarkerAttack,UStateAbstractAttack,0,CTMarkers)
};

#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#endif // CTMARKERS_NATIVE_DEFS