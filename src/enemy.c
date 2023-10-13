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
  if (FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED) || ((p->s).flags2 & STOPPED)) {
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
const EnemyRoutine* const gEnemyFnTable[ENEMY_COUNT] = {
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
  [ENEMY_TOP_GABYOALL] = &gTopGabyoallRoutine,
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
  [ENEMY_WORMER_SNOW_BALL] = &gWormerSnowBallRoutine,
  [ENEMY_BEETANK] = &gBeetankRoutine,
  [ENEMY_SWORDY] = &gSwordyRoutine,
  [ENEMY_PUFFY] = &gPuffyRoutine,
  [ENEMY_CROSSBYNE] = &gCrossbyneRoutine,
  [ENEMY_BURNABLE_WOOD] = &gBurnableWoodRoutine,
  [ENEMY_MELLNET] = &gMellnetRoutine,
  [ENEMY_HELL_BOUNCER] = &gHellBouncerRoutine,
  [ENEMY_P_ZOMBIE] = &gPantheonZombieRoutine,
  [ENEMY_P_AQUA_MOD_OBJ] = &gPantheonAquaModObjRoutine,
  [ENEMY_GLACIERLE_ARM] = &gGlacierleAtkArmRoutine,
  [ENEMY_OMEGA_GOLD_HAND] = &gOmegaGoldHandRoutine,
  [ENEMY_EYE_CANNON] = &gEyeCannonRoutine,
  [ENEMY_42] = &gEnemy42Routine,
  [ENEMY_CAPSULE_CANNON] = &gCapsuleCannonRoutine,
  [ENEMY_P_BOMBER] = &gPantheonBomberRoutine,
  [ENEMY_HANUMACHINE_OBJ] = &gHanumachineObjRoutine,
  [ENEMY_GALLISNI] = &gGallisniRoutine,
  [ENEMY_MOTHJIRO] = &gMothjiroRoutine,
  [ENEMY_METTAUR_SWIM] = &gMettaurSwimRoutine,
  [ENEMY_P_BASE] = &gPantheonBaseRoutine,
  [ENEMY_HANUMACHINE_NECRO] = &gHanumachineNecroRoutine,
  [ENEMY_CARRYBEE_G] = &gCarrybeeGRoutine,
  [ENEMY_OZ_ROCK] = &gOmegaZeroRockRoutine,
  [ENEMY_OMEGA_GOLD_SWORD] = &gOmegaGoldSwordRoutine,
  [ENEMY_GENERATOR_CANNON] = &gGeneratorCannonRoutine,
  [ENEMY_DEATHLOCK] = &gDeathlockRoutine,
  [ENEMY_CLAVEKER] = &gClavekerRoutine,
  [ENEMY_SEIMERAN] = &gSeimeranRoutine,
  [ENEMY_PETATRIA] = &gPetatriaRoutine,
  [ENEMY_59] = &gEnemy59Routine,
  [ENEMY_60] = &gEnemy60Routine,
  [ENEMY_61] = &gEnemy61Routine,
  [ENEMY_SHOTLOID] = &gShotloidRoutine,
  [ENEMY_63] = &gEnemy63Routine,
  [ENEMY_P_FIST] = (const EnemyRoutine*)0x08369F6C,
  [ENEMY_SHELLCRAWLER] = (const EnemyRoutine*)0x0836A078,
  [ENEMY_CANNON_HOPPER] = (const EnemyRoutine*)0x0836A274,
  [ENEMY_CATTATANK] = (const EnemyRoutine*)0x0836A45C,
  [ENEMY_68] = (const EnemyRoutine*)0x0836A678,
  [ENEMY_AZTEC_FALCON] = (const EnemyRoutine*)0x0836A78C,
  [ENEMY_70] = (const EnemyRoutine*)0x0836A848,
  [ENEMY_71] = (const EnemyRoutine*)0x0836A894,
  [ENEMY_72] = (const EnemyRoutine*)0x0836A8A8,
};
// clang-format on
