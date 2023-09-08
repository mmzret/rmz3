#ifndef GUARD_RMZ3_BOSS_H
#define GUARD_RMZ3_BOSS_H

#include "collision.h"
#include "entity.h"
#include "gba/gba.h"

#define SET_BOSS_ROUTINE(boss, routine)          \
  {                                              \
    u32 tbl, id;                                 \
    BossFunc** r;                                \
    tbl = (u32)gBossFnTable;                     \
    id = (((boss)->s).id) << 2;                  \
    r = (BossFunc**)(tbl + id);                  \
                                                 \
    *(u32*)((boss)->s).mode = routine;           \
    ((boss)->s).onUpdate = (void*)(*r)[routine]; \
  }

#define INIT_BOSS_ROUTINE(boss, bossID)              \
  {                                                  \
    u32 tbl;                                         \
    BossFunc** r;                                    \
    tbl = (u32)gBossFnTable;                         \
    ((boss)->s).id = bossID;                         \
                                                     \
    r = (BossFunc**)(tbl + (bossID << 2));           \
    ((boss)->s).onUpdate = (void*)(*r)[ENTITY_INIT]; \
  }

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

// --------------------------------------------

void deleteBoss(struct Boss* p);
void resetBossData(struct Boss* p, const struct Collision* collisions, s16 hp);

#endif  // GUARD_RMZ3_BOSS_H
