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

extern const EnemyRoutine *const gEnemyFnTable[ENEMY_COUNT];

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
extern const EnemyRoutine gTopGabyoallRoutine;
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
extern const EnemyRoutine gWormerSnowBallRoutine;
extern const EnemyRoutine gBeetankRoutine;
extern const EnemyRoutine gSwordyRoutine;
extern const EnemyRoutine gPuffyRoutine;
extern const EnemyRoutine gCrossbyneRoutine;
extern const EnemyRoutine gBurnableWoodRoutine;
extern const EnemyRoutine gMellnetRoutine;
extern const EnemyRoutine gHellBouncerRoutine;
extern const EnemyRoutine gPantheonZombieRoutine;
extern const EnemyRoutine gPantheonAquaModObjRoutine;
extern const EnemyRoutine gGlacierleAtkArmRoutine;
extern const EnemyRoutine gOmegaGoldHandRoutine;
extern const EnemyRoutine gEyeCannonRoutine;
extern const EnemyRoutine gEnemy42Routine;
extern const EnemyRoutine gCapsuleCannonRoutine;
extern const EnemyRoutine gPantheonBomberRoutine;
extern const EnemyRoutine gHanumachineObjRoutine;
extern const EnemyRoutine gGallisniRoutine;
extern const EnemyRoutine gMothjiroRoutine;
extern const EnemyRoutine gMettaurSwimRoutine;
extern const EnemyRoutine gPantheonBaseRoutine;
extern const EnemyRoutine gHanumachineNecroRoutine;
extern const EnemyRoutine gCarrybeeGRoutine;
extern const EnemyRoutine gOmegaZeroRockRoutine;
extern const EnemyRoutine gOmegaGoldSwordRoutine;
extern const EnemyRoutine gGeneratorCannonRoutine;

// --------------------------------------------

void DeleteEnemy(struct Enemy *p);
bool32 isFrozen(struct Enemy *p);

struct Enemy *CreateOmegaWhiteHand(struct Coord *c, bool8 isLeftHand, struct Boss *omega);

void PantheonGuardian_Die(struct Enemy *p);

#endif  // GUARD_RMZ3_ZAKO_H
