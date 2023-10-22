#ifndef GUARD_RMZ3_PROJECTILE_H
#define GUARD_RMZ3_PROJECTILE_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define SET_PROJECTILE_ROUTINE(p, routine)     \
  {                                            \
    u32 tbl, id;                               \
    ProjectileFunc **r;                        \
    tbl = (u32)gProjectileFnTable;             \
    id = (((p)->s).id) << 2;                   \
    r = (ProjectileFunc **)(tbl + id);         \
                                               \
    *(u32 *)((p)->s).mode = routine;           \
    ((p)->s).onUpdate = (void *)(*r)[routine]; \
  }

#define INIT_PROJECTILE_ROUTINE(p, projectileID)        \
  {                                                     \
    u32 tbl;                                            \
    ProjectileFunc **r;                                 \
    tbl = (u32)gProjectileFnTable;                      \
    ((p)->s).id = projectileID;                         \
                                                        \
    r = (ProjectileFunc **)(tbl + (projectileID << 2)); \
    ((p)->s).onUpdate = (void *)(*r)[ENTITY_INIT];      \
  }

extern const ProjectileRoutine *const gProjectileFnTable[PROJECTILE_ENTITY_COUNT];

extern const ProjectileRoutine gLemonRoutine;
extern const ProjectileRoutine gShotcounterBulletRoutine;
extern const ProjectileRoutine gProjectile2Routine;
extern const ProjectileRoutine gGrandCannonBombRoutine;
extern const ProjectileRoutine gOmegaWhiteProjectileRoutine;
extern const ProjectileRoutine gProjectile5Routine;
extern const ProjectileRoutine gProjectile6Routine;
extern const ProjectileRoutine gProjectile7Routine;
extern const ProjectileRoutine gProjectile8Routine;
extern const ProjectileRoutine gBlazinProjectileRoutine;
extern const ProjectileRoutine gBlazinTailRoutine;
extern const ProjectileRoutine gEarShotRoutine;
extern const ProjectileRoutine gProjectile12Routine;
extern const ProjectileRoutine gProjectile13Routine;
extern const ProjectileRoutine gProjectile14Routine;
extern const ProjectileRoutine gHellbatProjectileRoutine;
extern const ProjectileRoutine gProjectile16Routine;
extern const ProjectileRoutine gProjectile17Routine;
extern const ProjectileRoutine gProjectile18Routine;
extern const ProjectileRoutine gTretistaProjectileRoutine;
extern const ProjectileRoutine gProjectile20Routine;
extern const ProjectileRoutine gPantheonAquaModProjectileRoutine;
extern const ProjectileRoutine gCubitProjectileRoutine;
// ...
extern const ProjectileRoutine gOmegaZeroProjectileRoutine;
extern const ProjectileRoutine gClavekerYellowBallsRoutine;
extern const ProjectileRoutine gPhantomProjectileRoutine;
extern const ProjectileRoutine gOmegaZXProjectileRoutine;
extern const ProjectileRoutine gProjectile42Routine;

// --------------------------------------------

void UpdateProjectiles(void);
void DeleteProjectile(struct Projectile *p);

struct Projectile *CreateLemon(struct Coord *c, s32 r1, u8 r2);

#endif  // GUARD_RMZ3_PROJECTILE_H
