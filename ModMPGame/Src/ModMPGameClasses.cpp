/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#include "ModMPGamePrivate.h"

IMPLEMENT_PACKAGE(ModMPGame)



IMPLEMENT_CLASS(AAdminControl);
FNativeEntry<AAdminControl> AAdminControl::StaticNativeMap[] = {
	MAP_NATIVE(EventLog,0)
	{NULL,NULL}
};
LINK_NATIVES(AAdminControl);

IMPLEMENT_CLASS(AAdminService);
FNativeEntry<AAdminService> AAdminService::StaticNativeMap[] = {
	MAP_NATIVE(ParseCommand,0)
	MAP_NATIVE(ParseToken,0)
	MAP_NATIVE(ParseIntParam,0)
	MAP_NATIVE(ParseFloatParam,0)
	MAP_NATIVE(ParseStringParam,0)
	MAP_NATIVE(ExecCmd,0)
	MAP_NATIVE(EventLog,0)
	{NULL,NULL}
};
LINK_NATIVES(AAdminService);

IMPLEMENT_CLASS(ABotSupport);

IMPLEMENT_CLASS(AMPBot);
FNativeEntry<AMPBot> AMPBot::StaticNativeMap[] = {
	MAP_NATIVE(UpdatePawnAccuracy,0)
	{NULL,NULL}
};
LINK_NATIVES(AMPBot);

IMPLEMENT_CLASS(APatrolPoint);

IMPLEMENT_CLASS(ASmallNavigationPoint);

IMPLEMENT_CLASS(AInventorySpot);

IMPLEMENT_CLASS(UFunctionOverride);
FNativeEntry<UFunctionOverride> UFunctionOverride::StaticNativeMap[] = {
	MAP_NATIVE(Init,0)
	MAP_NATIVE(Deinit,0)
	{NULL,NULL}
};
LINK_NATIVES(UFunctionOverride);
