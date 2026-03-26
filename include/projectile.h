#ifndef GUARD_RMZ3_PROJECTILE_H
#define GUARD_RMZ3_PROJECTILE_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define SET_PROJECTILE_ROUTINE(p, routine)    \
  {                                           \
    u32 tbl, id;                              \
    ProjectileFunc** r;                       \
    tbl = (u32)gProjectileFnTable;            \
    id = (((p)->s).id) << 2;                  \
    r = (ProjectileFunc**)(tbl + id);         \
                                              \
    *(u32*)((p)->s).mode = routine;           \
    ((p)->s).onUpdate = (void*)(*r)[routine]; \
  }

#define INIT_PROJECTILE_ROUTINE(p, projectileID)       \
  {                                                    \
    u32 tbl;                                           \
    ProjectileFunc** r;                                \
    tbl = (u32)gProjectileFnTable;                     \
    ((p)->s).id = projectileID;                        \
                                                       \
    r = (ProjectileFunc**)(tbl + (projectileID << 2)); \
    ((p)->s).onUpdate = (void*)(*r)[ENTITY_INIT];      \
  }

extern const ProjectileRoutine* const gProjectileFnTable[PROJECTILE_ENTITY_COUNT];

// --------------------------------------------

void UpdateProjectiles(void);
void DeleteProjectile(struct Projectile* p);

struct Projectile* CreateLemon(struct Coord* c, s32 r1, u8 r2);

#endif  // GUARD_RMZ3_PROJECTILE_H
