#ifndef GUARD_RMZ3_SOLID_H
#define GUARD_RMZ3_SOLID_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#if MODERN
#define SET_SOLID_ROUTINE(solid, routine)                                           \
  {                                                                                 \
    *(u32 *)(&((solid)->s).mode[0]) = routine;                                      \
    ((solid)->s).onUpdate = (void *)((*gSolidFnTable[(((solid)->s).id)])[routine]); \
  }
#else
#define SET_SOLID_ROUTINE(solid, routine)          \
  {                                                \
    u32 tbl, id;                                   \
    SolidFunc **r;                                 \
    tbl = (u32)gSolidFnTable;                      \
    id = (((solid)->s).id) << 2;                   \
    r = (SolidFunc **)(tbl + id);                  \
                                                   \
    *(u32 *)((solid)->s).mode = routine;           \
    ((solid)->s).onUpdate = (void *)(*r)[routine]; \
  }
#endif

#if MODERN
#define INIT_SOLID_ROUTINE(solid, solidID)                                              \
  {                                                                                     \
    ((solid)->s).id = solidID;                                                          \
    ((solid)->s).onUpdate = (void *)((*gSolidFnTable[(((solid)->s).id)])[ENTITY_INIT]); \
  }
#else
#define INIT_SOLID_ROUTINE(solid, solidID)             \
  {                                                    \
    u32 tbl;                                           \
    SolidFunc **r;                                     \
    tbl = (u32)gSolidFnTable;                          \
    ((solid)->s).id = solidID;                         \
                                                       \
    r = (SolidFunc **)(tbl + (solidID << 2));          \
    ((solid)->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }
#endif

extern const SolidRoutine *const gSolidFnTable[SOLID_ENTITY_COUNT];
extern const SolidRoutine gIcebonRoutine;
extern const SolidRoutine gIcebonIceRoutine;
extern const SolidRoutine gDoor2DBlueRoutine;
extern const SolidRoutine gSolid3Routine;
extern const SolidRoutine gIronStarRoutine;
extern const SolidRoutine gHeavyCannonRoutine;
extern const SolidRoutine gSolid6Routine;
extern const SolidRoutine gSolid7Routine;
extern const SolidRoutine gLavaRiverPlatformRoutine;
extern const SolidRoutine gDoor3DRoutine;
extern const SolidRoutine gSolid10Routine;
extern const SolidRoutine gSolid11Routine;
extern const SolidRoutine gAnubisCoffinRoutine;
extern const SolidRoutine gSolid13Routine;
extern const SolidRoutine gLocomoIFPlatformRoutine;
extern const SolidRoutine gGlacierleArmRoutine;
extern const SolidRoutine gSolid16Routine;
extern const SolidRoutine gSolid17Routine;
extern const SolidRoutine gSolid18Routine;
extern const SolidRoutine gBaseElevatorRoutine;
extern const SolidRoutine gDoor2DGrayRoutine;
extern const SolidRoutine gScriptActorRoutine;
extern const SolidRoutine gSolid22Routine;
extern const SolidRoutine gSolid23Routine;
extern const SolidRoutine gPhantomTeleporterRoutine;
extern const SolidRoutine gSolid25Routine;
extern const SolidRoutine gIceBlockRoutine;
extern const SolidRoutine gSolid27Routine;
extern const SolidRoutine gMinigameNinjaStarRoutine;
extern const SolidRoutine gMobNPCRoutine;
extern const SolidRoutine gMainNPCRoutine;
extern const SolidRoutine gCyberSpaceDoorRoutine;
extern const SolidRoutine gSolid32Routine;
extern const SolidRoutine gSolid33Routine;
extern const SolidRoutine gSolid34Routine;
extern const SolidRoutine gContainerRoutine;
extern const SolidRoutine gSolid36Routine;
extern const SolidRoutine gSolid37Routine;
extern const SolidRoutine gSeagullsRoutine;
extern const SolidRoutine gCatRoutine;
extern const SolidRoutine gModPlantRoutine;
extern const SolidRoutine gVolcanoCoffinRoutine;
extern const SolidRoutine gCielMinigameObjRoutine;
extern const SolidRoutine gSolid43Routine;
extern const SolidRoutine gSolid44Routine;
extern const SolidRoutine gSolid45Routine;
extern const SolidRoutine gSolid46Routine;
extern const SolidRoutine gSolid47Routine;
extern const SolidRoutine gCielComputerRoutine;
extern const SolidRoutine gSolid49Routine;
extern const SolidRoutine gStructuralSteelRoutine;
extern const SolidRoutine gModElfRoutine;
extern const SolidRoutine gSolid52Routine;
extern const SolidRoutine gSolid53Routine;
extern const SolidRoutine gSeaLevelButtonRoutine;
extern const SolidRoutine gChildreShipRoutine;

void DeleteSolid(struct Solid *p);
u16 FUN_080d0934(struct Entity *p, motion_t m, u8 r2);
void FUN_080cb4c0(struct Solid *p);
struct Solid *CreateLeafBurn(u8 r0);
void CreateSolid6(struct Solid *s);
struct Solid *CreateResistanceBaseElevator(u8 floor);
void CreateLavaRiverPlatform(u32 x, u32 y);

#endif  // GUARD_RMZ3_SOLID_H
