#ifndef GUARD_RMZ3_PROJECTILE_H
#define GUARD_RMZ3_PROJECTILE_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

typedef void (*ProjectileFunc)(Projectile*);
typedef ProjectileFunc ProjectileRoutine[5];
extern const ProjectileRoutine* const gProjectileFnTable[PROJECTILE_ENTITY_COUNT];

#define INIT_PROJECTILE_ROUTINE(entity, entityID) INIT_RENDER_ENTITY(8, gProjectileFnTable, entity, entityID)
#define SET_PROJECTILE_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gProjectileFnTable, entity, modeID)

// --------------------------------------------

void UpdateProjectiles(void);
void DeleteProjectile(Entity* p);

Entity* CreateLemon(Coords32* c, s32 r1, u8 r2);

#endif  // GUARD_RMZ3_PROJECTILE_H
