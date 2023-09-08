#include "enemy.h"

#include "entity.h"
#include "global.h"
#include "story.h"

void InitEnemyHeader(struct EntityHeader* h, struct Enemy* p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_ENEMY, &p->s, sizeof(struct Enemy), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gZakoHeaderPtr = h;
}

void DeleteEnemy(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ZAKO_ROUTINE(p, ENTITY_EXIT);
}

bool32 isFrozen(struct Enemy* p) {
  bool32 result = FALSE;
  if ((gCurStory.s.elfFlags & TIME_ELF_ENABLED) || ((p->s).flags2 & STOPPED)) {
    result = TRUE;
  }
  return result;
}

#if MODERN == 0
static struct Enemy* unused_08063674(struct Entity* e) {
  struct Enemy* p = (struct Enemy*)GetNearestEntity(gZeroHeaderPtr, &e->coord);
  if (p == NULL) {
    return NULL;
  }
  return p;
}
#endif

#if MODERN == 0
static struct Enemy* unused_08063690(u8 n) {
  struct Entity* p;
  struct EntityHeader* h = gZeroHeaderPtr;
  ignoreEntityFn(h);

  p = h->last = h->last->prev;
  while (p != (struct Entity*)END) {
    if (p->work[0] == n) {
      return (struct Enemy*)p;
    }

    p = h->last = h->last->prev;
  }
  return NULL;
}
#endif

#if MODERN == 0
static struct Weapon* unused_080636d4(struct Entity* e) {
  struct Weapon* p = (struct Weapon*)GetNearestEntity(gWeaponHeaderPtr, &e->coord);
  if (p == NULL) {
    return NULL;
  }
  return p;
}
#endif

#if MODERN == 0
static struct Coord* unused_080636f0(struct Entity* p) {
  struct Entity* w = GetNearestEntity(gWeaponHeaderPtr, &p->coord);
  if (w != NULL) return &w->coord;
  return NULL;
}
#endif

#if MODERN == 0
static u16 unused_CountSpecificZako(void* _ UNUSED, u8 id) { return countSpecificEntities1(gZakoHeaderPtr, id); }
#endif

#if MODERN == 0
static u16 unused_CountSpecificProjectile(void* _ UNUSED, u8 id, u8 r2, u8 r3) { return countSpecificEntities2(gProjectileHeaderPtr, id, r2, r3); }
#endif

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
const EnemyRoutine* const gEnemyFnTable[73] = {
  [ENEMY_P_GUARDIAN] =  &gPantheonGuardianRoutine,
  [ENEMY_P_HUNTER] =  &gPantheonHunterRoutine,
  [ENEMY_MEGAMILPA_NODE] =  &gMegamilpaNodeRoutine,
  [ENEMY_SHOTCOUNTER] =  &gShotcounterRoutine,
  [ENEMY_BATRING] =  &gBatringRoutine,
  [ENEMY_PILLER_CANNON] =  &gPillerCannonRoutine,
  [ENEMY_GRAND_CANNON] =  &gGrandCannonRoutine,
  [ENEMY_SHRIMPORIN] =  &gShrimporinRoutine,
  [ENEMY_OMEGA_WHITE_HAND] =  &gOmegaWhiteHandRoutine,
  [ENEMY_FLOPPER] =  &gFlopperRoutine,
  [ENEMY_LAMPLORT] = &gLamplortRoutine,
  [ENEMY_GYRO_CANNON] = &gGyroCannonRoutine,
  [ENEMY_LEMMINGLES_NEST] = &gLemminglesNestRoutine,
  [ENEMY_LEMMINGLES] = &gLemminglesRoutine,
  [ENEMY_14] = &gEnemy14Routine,
  [ENEMY_SHARKSEAL_X] = &gSharksealXRoutine,
  [ENEMY_VOLCANO_BOMB] = &gVolcanoBombRoutine,
  [ENEMY_CARRY_ARM] = &gCarryArmRoutine,
  [ENEMY_P_AQUA] = &gPantheonAquaRoutine,
  [ENEMY_CHILDRE_OBJ] = &gChildreObjRoutine,
  [ENEMY_SNAKECORD] = &gSnakecordRoutine,
  [ENEMY_HAMMER] = &gHammerRoutine,
  [ENEMY_PURPLE_NERPLE] = &gPurpleNerpleRoutine,
  [ENEMY_WORMER_ROCK_DRONE] = &gWormerRockDroneRoutine,
  [ENEMY_VOLCAIRE] = &gVolcaireRoutine,
  [ENEMY_TILE_CANNON] = &gTileCannonRoutine,
  [ENEMY_SHELLUNO] = &gShellunoRoutine,
  [ENEMY_DEATHTANZ_ROCK] = &gDeathtanzRockRoutine,
  [ENEMY_HEAVY_CANNON_BALL] = &gHeavyCannonBallRoutine,
  [29] = (const EnemyRoutine*)0x083677D4,
  [30] = (const EnemyRoutine*)0x083679B0,
  [31] = (const EnemyRoutine*)0x08367A24,
  [32] = (const EnemyRoutine*)0x08367AD8,
  [33] = (const EnemyRoutine*)0x08367B44,
  [34] = (const EnemyRoutine*)0x08367C68,
  [35] = (const EnemyRoutine*)0x08367C84,
  [36] = (const EnemyRoutine*)0x08367D6C,
  [37] = (const EnemyRoutine*)0x08367E70,
  [38] = (const EnemyRoutine*)0x08367F9C,
  [39] = (const EnemyRoutine*)0x08368114,
  [40] = (const EnemyRoutine*)0x08368174,
  [41] = (const EnemyRoutine*)0x083682C8,
  [42] = (const EnemyRoutine*)0x0836837C,
  [43] = (const EnemyRoutine*)0x08368444,
  [44] = (const EnemyRoutine*)0x083684F0,
  [45] = (const EnemyRoutine*)0x083685B4,
  [46] = (const EnemyRoutine*)0x08368678,
  [47] = (const EnemyRoutine*)0x08368764,
  [48] = (const EnemyRoutine*)0x08368800,
  [49] = (const EnemyRoutine*)0x08368958,
  [50] = (const EnemyRoutine*)0x08368C04,
  [51] = (const EnemyRoutine*)0x08368C18,
  [52] = (const EnemyRoutine*)0x08368D2C,
  [53] = (const EnemyRoutine*)0x08368D80,
  [54] = (const EnemyRoutine*)0x08368EF4,
  [55] = (const EnemyRoutine*)0x08369134,
  [56] = (const EnemyRoutine*)0x0836932C,
  [57] = (const EnemyRoutine*)0x083693C0,
  [58] = (const EnemyRoutine*)0x083695A4,
  [59] = (const EnemyRoutine*)0x083697E0,
  [60] = (const EnemyRoutine*)0x08369A24,
  [61] = (const EnemyRoutine*)0x08369D24,
  [62] = (const EnemyRoutine*)0x08369E04,
  [63] = (const EnemyRoutine*)0x08369EC8,
  [64] = (const EnemyRoutine*)0x08369F6C,
  [65] = (const EnemyRoutine*)0x0836A078,
  [66] = (const EnemyRoutine*)0x0836A274,
  [67] = (const EnemyRoutine*)0x0836A45C,
  [68] = (const EnemyRoutine*)0x0836A678,
  [69] = (const EnemyRoutine*)0x0836A78C,
  [70] = (const EnemyRoutine*)0x0836A848,
  [71] = (const EnemyRoutine*)0x0836A894,
  [72] = (const EnemyRoutine*)0x0836A8A8,
};
// clang-format on
