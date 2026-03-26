#ifndef GUARD_RMZ3_BOSS_H
#define GUARD_RMZ3_BOSS_H

#include "collision.h"
#include "entity.h"
#include "gba/gba.h"

#define SET_BOSS_COLLISION_HANDLER(boss, onCollision) \
  {                                                   \
    fn = onCollision;                                 \
    body = &boss->body;                               \
    body->fn = fn;                                    \
  }

#define INIT_BOSS_ROUTINE(entity, entityID) INIT_ENTITY_ROUTINE(gBossFnTable, entity, entityID)
#define SET_BOSS_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gBossFnTable, entity, modeID)

// --------------------------------------------

extern const BossRoutine* const gBossFnTable[BOSS_ENTITY_COUNT];

extern const BossRoutine gMegamilpaRoutine;
extern const BossRoutine gOmegaWhiteRoutine;
extern const BossRoutine gBlazinRoutine;
extern const BossRoutine gChildreRoutine;
extern const BossRoutine gWormerRoutine;
extern const BossRoutine gVolteelRoutine;
extern const BossRoutine gBabyElfRoutine;
extern const BossRoutine gDeathtanzRoutine;
extern const BossRoutine gHellbatRoutine;
extern const BossRoutine gBeeServerRoutine;
extern const BossRoutine gTretistaRoutine;
extern const BossRoutine gAnubisRoutine;
extern const BossRoutine gPantheonAquaModRoutine;
extern const BossRoutine gCubitRoutine;
extern const BossRoutine gLocomoIFRoutine;
extern const BossRoutine gCopyXRoutine;
extern const BossRoutine gGlacierleRoutine;
extern const BossRoutine gBlizzackRoutine;
extern const BossRoutine gOmegaGoldRoutine;
extern const BossRoutine gHanumachineRoutine;
extern const BossRoutine gOmegaZeroRoutine;
extern const BossRoutine gPhantomBossRoutine;
extern const BossRoutine gOmegaZXRoutine;
extern const BossRoutine gReactorCoreRoutine;
extern const BossRoutine gSpearookRoutine;

// --------------------------------------------

void DeleteBoss(struct Boss* p);
void ResetBossBody(struct Boss* p, const struct Collision* collisions, s16 hp);

#endif  // GUARD_RMZ3_BOSS_H
