/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#ifndef MODMPGAME_NATIVE_DEFS
#define MODMPGAME_NATIVE_DEFS

#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif

#ifndef MODMPGAME_API
#define MODMPGAME_API DLL_IMPORT
#endif



class MODMPGAME_API AAdminControl : public AActor
{
public:
    BITFIELD bAdminsCanPause:1 GCC_PACK(4);
    TArrayNoInit<FString> ServiceClasses GCC_PACK(4);
    TArrayNoInit<class AAdminService*> Services;
    UBOOL ExecCmd(FString const& Cmd, class APlayerController* PC)
    {
        DECLARE_NAME(ExecCmd);
        struct {
            FString Cmd;
            class APlayerController* PC;
            UBOOL ReturnValue;
        } Parms;
        Parms.Cmd=Cmd;
        Parms.PC=PC;
        Parms.ReturnValue=0;
        ProcessEvent(NExecCmd, &Parms);
        return Parms.ReturnValue;
    }
    DECLARE_CLASS(AAdminControl,AActor,0|CLASS_Config,ModMPGame)
	// Overrides
	virtual void Spawned();
	virtual void Destroy();
};


class MODMPGAME_API AAdminService : public AActor
{
public:
    class UClass* RelevantGameInfoClass;
    BITFIELD bRequiresAdminPermissions:1 GCC_PACK(4);
    void execParseCommand(FFrame& Stack, void* Result);
    void execParseToken(FFrame& Stack, void* Result);
    void execParseIntParam(FFrame& Stack, void* Result);
    void execParseFloatParam(FFrame& Stack, void* Result);
    void execParseStringParam(FFrame& Stack, void* Result);
    void execExecCmd(FFrame& Stack, void* Result);
    DECLARE_CLASS(AAdminService,AActor,0|CLASS_Config,ModMPGame)
	virtual bool ExecCmd(const char* Cmd, class APlayerController* PC = NULL){ return false; }
    DECLARE_NATIVES(AAdminService)
};


class MODMPGAME_API ABotSupport : public AAdminService
{
public:
    INT NumBots;
    FLOAT BotAccuracy;
    TArrayNoInit<class AMPBot*> Bots;
    BITFIELD bBotsCountAsPlayers:1 GCC_PACK(4);
    BITFIELD bAutoImportPaths:1;
    BITFIELD bAutoBuildPaths:1;
    BITFIELD bShowPaths:1;
    BITFIELD bPathsImported:1;
    BITFIELD bShowPathsOnClients:1;
    TArrayNoInit<FVector> NavPtFailLocations GCC_PACK(4);
    TArrayNoInit<FPatrolPoint> BotPatrolRoute;
    TArrayNoInit<class AActor*> NavigationPointIcons;
    void SetupPatrolRoute()
    {
        DECLARE_NAME(SetupPatrolRoute);
        ProcessEvent(NSetupPatrolRoute, NULL);
    }
    DECLARE_CLASS(ABotSupport,AAdminService,0|CLASS_Config,ModMPGame)
	void SpawnNavigationPoint(UClass* NavPtClass, const FVector& Location, const FRotator& Rotation = FRotator(0, 0, 0));
	void ImportPaths();
	void ExportPaths();
	void BuildPaths();
	void ClearPaths();

	// Overrides
	virtual void Spawned();
	virtual UBOOL Tick(FLOAT DeltaTime, ELevelTick TickType);
	virtual void PostRender(class FLevelSceneNode* SceneNode, class FRenderInterface* RI);
	virtual bool ExecCmd(const char* Cmd, class APlayerController* PC);
};


class MODMPGAME_API AMPBot : public ACTBot
{
public:
    INT ChosenSkin;
    FLOAT Accuracy;
    void execUpdatePawnAccuracy(FFrame& Stack, void* Result);
    DECLARE_CLASS(AMPBot,ACTBot,0|CLASS_Config,ModMPGame)
	virtual int Tick(FLOAT DeltaTime, ELevelTick TickType);
    DECLARE_NATIVES(AMPBot)
};


class MODMPGAME_API APatrolPoint : public ANavigationPoint
{
public:
    DECLARE_CLASS(APatrolPoint,ANavigationPoint,0,ModMPGame)
    NO_DEFAULT_CONSTRUCTOR(APatrolPoint)
};


class MODMPGAME_API ASmallNavigationPoint : public ANavigationPoint
{
public:
    DECLARE_CLASS(ASmallNavigationPoint,ANavigationPoint,0,ModMPGame)
    NO_DEFAULT_CONSTRUCTOR(ASmallNavigationPoint)
};


class MODMPGAME_API AInventorySpot : public ASmallNavigationPoint
{
public:
    DECLARE_CLASS(AInventorySpot,ASmallNavigationPoint,0,ModMPGame)
    NO_DEFAULT_CONSTRUCTOR(AInventorySpot)
};



#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#if __STATIC_LINK

#define AUTO_INITIALIZE_REGISTRANTS_MODMPGAME \
	AAdminControl::StaticClass(); \
	AAdminService::StaticClass(); \
	ABotSupport::StaticClass(); \
	AMPBot::StaticClass(); \
	APatrolPoint::StaticClass(); \
	ASmallNavigationPoint::StaticClass(); \
	AInventorySpot::StaticClass(); \

#endif // __STATIC_LINK

#endif // CORE_NATIVE_DEFS
