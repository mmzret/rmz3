#ifndef GUARD_RMZ3_BOSS_H
#define GUARD_RMZ3_BOSS_H

#include "entity.h"
#include "gba/gba.h"

struct Collision;

#define SET_BOSS_COLLISION_HANDLER(boss, onCollision) \
  {                                                   \
    void* fn = onCollision;                           \
    struct Body* body = &boss->body;                  \
    body->fn = fn;                                    \
  }

typedef void (*BossFunc)(struct Boss*);
typedef BossFunc BossRoutine[5];
extern const BossRoutine* const gBossFnTable[BOSS_ENTITY_COUNT];

#define INIT_BOSS_ROUTINE(entity, entityID) INIT_OBJECT_ENTITY(24, gBossFnTable, entity, entityID)
#define SET_BOSS_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gBossFnTable, entity, modeID)

// --------------------------------------------

void DeleteBoss(struct Entity* p);
void ResetBossBody(struct Boss* p, const struct Collision* collisions, s16 hp);

#endif  // GUARD_RMZ3_BOSS_H
