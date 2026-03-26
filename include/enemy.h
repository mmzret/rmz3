#ifndef GUARD_RMZ3_ZAKO_H
#define GUARD_RMZ3_ZAKO_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define INIT_ZAKO_ROUTINE(entity, entityID) INIT_ENTITY_ROUTINE(gEnemyFnTable, entity, entityID)
#define SET_ZAKO_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gEnemyFnTable, entity, modeID)

// --------------------------------------------

extern const EnemyRoutine* const gEnemyFnTable[ENEMY_COUNT];

// --------------------------------------------

void DeleteEnemy(struct Enemy* p);
bool32 isFrozen(struct Enemy* p);

struct Enemy* CreateOmegaWhiteHand(struct Coord* c, bool8 isLeftHand, struct Boss* omega);

void PantheonGuardian_Die(struct Enemy* p);

#endif  // GUARD_RMZ3_ZAKO_H
