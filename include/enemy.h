#ifndef GUARD_RMZ3_ZAKO_H
#define GUARD_RMZ3_ZAKO_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define SET_ZAKO_ROUTINE(zako, routine)           \
  {                                               \
    u32 tbl, id;                                  \
    EnemyFunc **r;                                \
    tbl = (u32)gEnemyFnTable;                     \
    id = (((zako)->s).id) << 2;                   \
    r = (EnemyFunc **)(tbl + id);                 \
                                                  \
    *(u32 *)((zako)->s).mode = routine;           \
    ((zako)->s).onUpdate = (void *)(*r)[routine]; \
  }

#if MODERN
#define INIT_ZAKO_ROUTINE(zako, zakoID)                                               \
  {                                                                                   \
    ((zako)->s).id = zakoID;                                                          \
    ((zako)->s).onUpdate = (void *)((*gEnemyFnTable[(((zako)->s).id)])[ENTITY_INIT]); \
  }
#else
#define INIT_ZAKO_ROUTINE(zako, zakoID)               \
  {                                                   \
    u32 tbl;                                          \
    EnemyFunc **r;                                    \
    tbl = (u32)gEnemyFnTable;                         \
    ((zako)->s).id = zakoID;                          \
                                                      \
    r = (EnemyFunc **)(tbl + (zakoID << 2));          \
    ((zako)->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }
#endif

// --------------------------------------------

extern const EnemyRoutine *const gEnemyFnTable[73];

extern const EnemyRoutine gPantheonGuardianRoutine;
extern const EnemyRoutine gPantheonHunterRoutine;
extern const EnemyRoutine gMegamilpaNodeRoutine;
extern const EnemyRoutine gShotcounterRoutine;
extern const EnemyRoutine gBatringRoutine;
extern const EnemyRoutine gPillerCannonRoutine;
extern const EnemyRoutine gGrandCannonRoutine;
extern const EnemyRoutine gShrimporinRoutine;
extern const EnemyRoutine gOmegaWhiteHandRoutine;
extern const EnemyRoutine gFlopperRoutine;
extern const EnemyRoutine gLamplortRoutine;
extern const EnemyRoutine gGyroCannonRoutine;
extern const EnemyRoutine gLemminglesNestRoutine;
extern const EnemyRoutine gLemminglesRoutine;
extern const EnemyRoutine gEnemy14Routine;
extern const EnemyRoutine gSharksealXRoutine;
extern const EnemyRoutine gVolcanoBombRoutine;
extern const EnemyRoutine gCarryArmRoutine;
extern const EnemyRoutine gPantheonAquaRoutine;
extern const EnemyRoutine gChildreObjRoutine;
extern const EnemyRoutine gSnakecordRoutine;
extern const EnemyRoutine gHammerRoutine;
extern const EnemyRoutine gPurpleNerpleRoutine;
extern const EnemyRoutine gWormerRockDroneRoutine;
extern const EnemyRoutine gVolcaireRoutine;
extern const EnemyRoutine gTileCannonRoutine;
extern const EnemyRoutine gShellunoRoutine;
extern const EnemyRoutine gDeathtanzRockRoutine;
extern const EnemyRoutine gHeavyCannonBallRoutine;

// --------------------------------------------

void DeleteEnemy(struct Enemy *p);
bool32 isFrozen(struct Enemy *p);

struct Enemy *CreateOmegaWhiteHand(struct Coord *c, bool8 isLeftHand, struct Boss *omega);

void PantheonGuardian_Die(struct Enemy *p);

#endif  // GUARD_RMZ3_ZAKO_H