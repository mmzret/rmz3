#include "solid.h"

#include "entity.h"
#include "global.h"

// clang-format off
const SolidRoutine* const gSolidFnTable[SOLID_ENTITY_COUNT] = {
    [SOLID_ICEBON] =              &gIcebonRoutine,
    [SOLID_ICEBON_ICE] =          &gIcebonIceRoutine,
    [SOLID_DOOR_2D_BLUE] =        &gDoor2DBlueRoutine,
    [SOLID_UNK_003] =             &gSolid3Routine,
    [SOLID_UNK_004] =             &gIronStarRoutine,
    [SOLID_HEAVY_CANNON] =        &gHeavyCannonRoutine,
    [SOLID_UNK_006] =             &gSolid6Routine,
    [SOLID_UNK_007] =             &gSolid7Routine,
    [SOLID_LAVA_RIVER_PLATFORM] = &gLavaRiverPlatformRoutine,
    [SOLID_DOOR_3D] =             &gDoor3DRoutine,
    [SOLID_UNK_010] =             &gSolid10Routine,
    [SOLID_UNK_011] =             &gSolid11Routine,
    [SOLID_ANUBIS_COFFIN] =       &gAnubisCoffinRoutine,
    [SOLID_UNK_013] =             &gSolid13Routine,
    [SOLID_LOCOMOIF_PLATFORM] =   &gLocomoIFPlatformRoutine,
    [SOLID_GLACIERLE_ARM] =       &gGlacierleArmRoutine,
    [SOLID_UNK_016] =             &gSolid16Routine,
    [SOLID_UNK_017] =             &gSolid17Routine,
    [SOLID_UNK_018] =             &gSolid18Routine,
    [SOLID_BASE_ELEVATOR] =       &gBaseElevatorRoutine,
    [SOLID_DOOR_2D_GRAY] =        &gDoor2DGrayRoutine,
    [SOLID_SCRIPT_ACTOR] =        &gScriptActorRoutine,
    [SOLID_UNK_022] =             &gSolid22Routine,
    [SOLID_UNK_023] =             &gSolid23Routine,
    [SOLID_PHANTOM_TELEPORTER] =  &gPhantomTeleporterRoutine,
    [SOLID_UNK_025] =             &gSolid25Routine,
    [SOLID_ICE_BLOCK] =           &gIceBlockRoutine,
    [SOLID_UNK_027] =             &gSolid27Routine,
    [SOLID_MG_NINJASTAR] =        &gMinigameNinjaStarRoutine,
    [SOLID_MOB_NPC] =             &gMobNPCRoutine,
    [SOLID_MAIN_NPC] =            &gMainNPCRoutine,
    [SOLID_CYBERSPACE_DOOR] =     &gCyberSpaceDoorRoutine,
    [SOLID_UNK_032] =             &gSolid32Routine,
    [SOLID_UNK_033] =             &gSolid33Routine,
    [SOLID_UNK_034] =             &gSolid34Routine,
    [SOLID_CONTAINER] =           &gContainerRoutine,
    [SOLID_UNK_036] =             &gSolid36Routine,
    [SOLID_UNK_037] =             &gSolid37Routine,
    [SOLID_SEAGULLS] =            &gSeagullsRoutine,
    [SOLID_CAT] =                 &gCatRoutine,
    [SOLID_MOD_PLANT] =           &gModPlantRoutine,
    [SOLID_VOLCANO_COFFIN] =      &gVolcanoCoffinRoutine,
    [SOLID_UNK_042] =             &gCielMinigameObjRoutine,
    [SOLID_UNK_043] =             &gSolid43Routine,
    [SOLID_UNK_044] =             &gSolid44Routine,
    [SOLID_UNK_045] =             &gSolid45Routine,
    [SOLID_UNK_046] =             &gSolid46Routine,
    [SOLID_UNK_047] =             &gSolid47Routine,
    [SOLID_CIEL_COMPUTER] =       &gCielComputerRoutine,
    [SOLID_UNK_049] =             &gSolid49Routine,
    [SOLID_STRUCTURAL_STEEL] =    &gStructuralSteelRoutine,
    [SOLID_MOD_ELF] =             &gModElfRoutine,
    [SOLID_UNK_052] =             &gSolid52Routine,
    [SOLID_UNK_053] =             &gSolid53Routine,
    [SOLID_SEA_LV_BTN] =          &gSeaLevelButtonRoutine,
    [SOLID_CHILDRE_SHIP] =        &gChildreShipRoutine,
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
