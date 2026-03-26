#ifndef GUARD_RMZ3_PROJECTILE_H
#define GUARD_RMZ3_PROJECTILE_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define INIT_PROJECTILE_ROUTINE(entity, entityID) INIT_ENTITY_ROUTINE(gProjectileFnTable, entity, entityID)
#define SET_PROJECTILE_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gProjectileFnTable, entity, modeID)

extern const ProjectileRoutine* const gProjectileFnTable[PROJECTILE_ENTITY_COUNT];

// --------------------------------------------

void UpdateProjectiles(void);
void DeleteProjectile(struct Projectile* p);

struct Projectile* CreateLemon(struct Coord* c, s32 r1, u8 r2);

#endif  // GUARD_RMZ3_PROJECTILE_H
