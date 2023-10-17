#include "projectile.h"

#include "entity.h"
#include "global.h"
#include "overworld.h"

void InitProjectileHeader(struct EntityHeader *h, struct Projectile *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_PROJECTILE, &p->s, sizeof(struct Projectile), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gProjectileHeaderPtr = h;
}

void UpdateProjectiles(void) {
  struct Entity *p;
  struct EntityHeader *h = gProjectileHeaderPtr;
  if ((gStageRun.id != STAGE_SPACE_CRAFT) && (((!(gStageRun.missionStatus & MISSION_STAY)) || (gStageRun.vm.active & 1) || (gStageRun.vm.unk_004 & 1)) || gInChat || gIsUsingDoor3D)) {
    gIsLemonCollisionRemoved = TRUE;
  } else {
    gIsLemonCollisionRemoved = FALSE;
  }

  setCurProcessedEntityHeader(h);
  p = h->last->prev;
  h->last = p;
  while (p != (struct Entity *)&h->next) {
    ((EntityFunc)p->onUpdate)(p);
    p = h->last->prev;
    h->last = p;
  }
}

void DeleteProjectile(struct Projectile *p) {
  (p->s).flags &= ~DISPLAY;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

#if MODERN == 0
static struct Coord *unused_0809c978(struct Projectile *p) {
  struct Weapon *w = (struct Weapon *)GetNearestEntity(gWeaponHeaderPtr, &(p->s).coord);
  if (w != NULL) return &(w->s).coord;
  return NULL;
}
#endif

// clang-format off
const ProjectileRoutine *const gProjectileFnTable[PROJECTILE_ENTITY_COUNT] = {
    [0]  = &gLemonRoutine,
    [1]  = &gShotcounterBulletRoutine,
    [2]  = &gProjectile2Routine,
    [3]  = &gGrandCannonBombRoutine,
    [4]  = &gOmegaWhiteProjectileRoutine,
    [5]  = &gProjectile5Routine,
    [6]  = &gProjectile6Routine,
    [7]  = &gProjectile7Routine,
    [8]  = &gProjectile8Routine,
    [9]  = &gBlazinProjectileRoutine,
    [10] = &gBlazinTailRoutine,
    [11] = &gEarShotRoutine,
    [12] = &gProjectile12Routine,
    [13] = &gProjectile13Routine,
    [14] = &gProjectile14Routine,
    [15] = &gHellbatProjectileRoutine,
    [16] = &gProjectile16Routine,
    [17] = &gProjectile17Routine,
    [18] = &gProjectile18Routine,
    [19] = &gTretistaProjectileRoutine,
    [20] = (const ProjectileRoutine*)0x0836BA3C,
    [21] = (const ProjectileRoutine*)0x0836BAEC,
    [22] = (const ProjectileRoutine*)0x0836BB60,
    [23] = (const ProjectileRoutine*)0x0836BE38,
    [24] = (const ProjectileRoutine*)0x0836BED0,
    [25] = (const ProjectileRoutine*)0x0836BF54,
    [26] = (const ProjectileRoutine*)0x0836C008,
    [27] = (const ProjectileRoutine*)0x0836C0BC,
    [28] = (const ProjectileRoutine*)0x0836C1F8,
    [29] = (const ProjectileRoutine*)0x0836C28C,
    [30] = (const ProjectileRoutine*)0x0836C2D0,
    [31] = (const ProjectileRoutine*)0x0836C318,
    [32] = (const ProjectileRoutine*)0x0836C3AC,
    [33] = (const ProjectileRoutine*)0x0836C5F4,
    [34] = (const ProjectileRoutine*)0x0836C704,
    [35] = (const ProjectileRoutine*)0x0836C830,
    [36] = (const ProjectileRoutine*)0x0836C8AC,
    [37] = (const ProjectileRoutine*)0x0836C910,
    [38] = &gOmegaZeroProjectileRoutine,
    [39] = &gClavekerYellowBallsRoutine,
    [40] = &gPhantomProjectileRoutine,
    [41] = &gOmegaZXProjectileRoutine,
    [42] = (const ProjectileRoutine*)0x0836D6FC,
    [43] = (const ProjectileRoutine*)0x0836D734,
    [44] = (const ProjectileRoutine*)0x0836D780,
    [45] = (const ProjectileRoutine*)0x0836D7B8,
    [46] = (const ProjectileRoutine*)0x0836D89C,
    [47] = (const ProjectileRoutine*)0x0836D8D4,
};
// clang-format on
