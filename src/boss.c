#include "boss.h"

#include "collision.h"
#include "global.h"

// clang-format off
const BossRoutine* const gBossFnTable[BOSS_ENTITY_COUNT] = {
    [BOSS_MEGAMILPA] =          &gMegamilpaRoutine,
    [BOSS_OMEGA_WHITE] =        &gOmegaWhiteRoutine,
    [BOSS_BLAZIN] =             &gBlazinRoutine,
    [BOSS_CHILDRE] =            &gChildreRoutine,
    [BOSS_WORMER] =             &gWormerRoutine,
    [BOSS_VOLTEEL] =            &gVolteelRoutine,
    [BOSS_BABY_ELF] =           &gBabyElfRoutine,
    [BOSS_DEATHTANZ] =          &gDeathtanzRoutine,
    [BOSS_HELLBAT] =            &gHellbatRoutine,
    [BOSS_BEE_SERVER] =         &gBeeServerRoutine,
    [BOSS_TRETISTA] =           &gTretistaRoutine,
    [BOSS_ANUBIS] =             &gAnubisRoutine,
    [BOSS_PANTHEON_AQUA_MOD] =  &gPantheonAquaModRoutine,
    [BOSS_CUBIT] =              &gCubitRoutine,
    [BOSS_LOCOMO_IF] =          &gLocomoIFRoutine,
    [BOSS_COPY_X] =             &gCopyXRoutine,
    [BOSS_GLACIERLE] =          &gGlacierleRoutine,
    [BOSS_BLIZZACK] =           &gBlizzackRoutine,
    [BOSS_OMEGA_GOLD] =         &gOmegaGoldRoutine,
    [BOSS_HANUMACHINE] =        &gHanumachineRoutine,
    [BOSS_OMEGA_ZERO] =         &gOmegaZeroRoutine,
    [BOSS_PHANTOM] =            &gPhantomBossRoutine,
    [BOSS_OMEGA_ZX] =           &gOmegaZXRoutine,
    [BOSS_REACTOR_CORE] =       &gReactorCoreRoutine,
    [BOSS_SPEAROOK] =           &gSpearookRoutine,
};
// clang-format on

void InitBossHeader(struct EntityHeader *h, struct Boss *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_BOSS, &p->s, sizeof(struct Boss), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gBossHeaderPtr = h;
}

void DeleteBoss(struct Boss *p) {
  (p->s).flags &= ~DISPLAY;
  SET_BOSS_ROUTINE(p, ENTITY_EXIT);
}

#if MODERN == 0
static struct Weapon *unused_0803d120(struct Entity *p) {
  struct Weapon *w = (struct Weapon *)GetNearestEntity(gWeaponHeaderPtr, &p->coord);
  if (w == NULL) return NULL;
  return w;
}
#endif

#if MODERN == 0
static struct Coord *unused_0803d13c(struct Entity *p) {
  struct Entity *w = GetNearestEntity(gWeaponHeaderPtr, &p->coord);
  if (w != NULL) return &w->coord;
  return NULL;
}
#endif

void ResetBossBody(struct Boss *p, const struct Collision *collisions, s16 hp) { INIT_BODY(p, &collisions[0], hp, NULL); }
