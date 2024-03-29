#include "solid.h"

#include "entity.h"
#include "global.h"

// clang-format off
const SolidRoutine* const gSolidFnTable[SOLID_ENTITY_COUNT] = {
    [SOLID_ICEBON] =                 &gIcebonRoutine,
    [SOLID_ICEBON_ICE] =             &gIcebonIceRoutine,
    [SOLID_DOOR_2D_BLUE] =           &gDoor2DBlueRoutine,
    [SOLID_UNK_003] =                &gSolid3Routine,
    [SOLID_UNK_004] =                &gIronStarRoutine,
    [SOLID_HEAVY_CANNON] =           &gHeavyCannonRoutine,
    [SOLID_LAVA_GEYSER_PLATFORM] =   &gLavaGeyserPlatformRoutine,
    [SOLID_LAVA_GEYSER] =            &gLavaGeyserRoutine,
    [SOLID_LAVA_RIVER_PLATFORM] =    &gLavaRiverPlatformRoutine,
    [SOLID_DOOR_3D] =                &gDoor3DRoutine,
    [SOLID_UNK_010] =                &gSolid10Routine,
    [SOLID_UNK_011] =                &gSolid11Routine,
    [SOLID_ANUBIS_COFFIN] =          &gAnubisCoffinRoutine,
    [SOLID_UNK_013] =                &gSolid13Routine,
    [SOLID_LOCOMOIF_PLATFORM] =      &gLocomoIFPlatformRoutine,
    [SOLID_GLACIERLE_ARM] =          &gGlacierleArmRoutine,
    [SOLID_UNK_016] =                &gSolid16Routine,
    [SOLID_UNK_017] =                &gSolid17Routine,
    [SOLID_SNOWBOARD] =              &gSnowboardRoutine,
    [SOLID_BASE_ELEVATOR] =          &gBaseElevatorRoutine,
    [SOLID_DOOR_2D_GRAY_V] =         &gDoor2DGrayVRoutine,
    [SOLID_SCRIPT_ACTOR] =           &gScriptActorRoutine,
    [SOLID_DOOR_2D_GRAY_H] =         &gDoor2DGrayHRoutine,
    [SOLID_UNK_023] =                &gSolid23Routine,
    [SOLID_PHANTOM_TELEPORTER] =     &gPhantomTeleporterRoutine,
    [SOLID_UNK_025] =                &gSolid25Routine,
    [SOLID_ICE_BLOCK] =              &gIceBlockRoutine,
    [SOLID_UNK_027] =                &gSolid27Routine,
    [SOLID_MG_NINJASTAR] =           &gMinigameNinjaStarRoutine,
    [SOLID_MOB_NPC] =                &gMobNPCRoutine,
    [SOLID_MAIN_NPC] =               &gMainNPCRoutine,
    [SOLID_CYBERSPACE_DOOR] =        &gCyberSpaceDoorRoutine,
    [SOLID_LIGHT_SWITCH] =           &gLightSwitchRoutine,
    [SOLID_UNK_033] =                &gSolid33Routine,
    [SOLID_UNK_034] =                &gSolid34Routine,
    [SOLID_CONTAINER] =              &gContainerRoutine,
    [SOLID_UNK_036] =                &gSolid36Routine,
    [SOLID_UNK_037] =                &gSolid37Routine,
    [SOLID_SEAGULLS] =               &gSeagullsRoutine,
    [SOLID_CAT] =                    &gCatRoutine,
    [SOLID_MOD_PLANT] =              &gModPlantRoutine,
    [SOLID_VOLCANO_COFFIN] =         &gVolcanoCoffinRoutine,
    [SOLID_UNK_042] =                &gCielMinigameObjRoutine,
    [SOLID_UNK_043] =                &gSolid43Routine,
    [SOLID_UNK_044] =                &gSolid44Routine,
    [SOLID_GE_PIER] =                &gGiantElevatorPierRoutine,
    [SOLID_GE_PLATFORM] =            &gGiantElevatorPlatformRoutine,
    [SOLID_ANATRE_CUBE] =            &gAnatreCubeRoutine,
    [SOLID_CIEL_COMPUTER] =          &gCielComputerRoutine,
    [SOLID_GRAFFITI] =               &gGraffitiRoutine,
    [SOLID_STRUCTURAL_STEEL] =       &gStructuralSteelRoutine,
    [SOLID_MOD_ELF] =                &gModElfRoutine,
    [SOLID_UNK_052] =                &gSolid52Routine,
    [SOLID_OCEAN_ROD_WALL] =         &gOceanRodWallRoutine,
    [SOLID_SEA_LV_BTN] =             &gSeaLevelButtonRoutine,
    [SOLID_CHILDRE_SHIP] =           &gChildreShipRoutine,
};
// clang-format on

void InitSolidHeader(struct EntityHeader *h, struct Solid *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_SOLID, &p->s, sizeof(struct Solid), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gSolidHeaderPtr = h;
}

void DeleteSolid(struct Solid *p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~(COLLIDABLE);
  (p->s).flags2 &= ~ENTITY_HAZARD;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}
