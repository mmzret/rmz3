#include "projectile.h"

#include "entity.h"
#include "global.h"
#include "overworld.h"

void InitProjectileHeader(struct EntityHeader* h, struct Projectile* p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_PROJECTILE, &p->s, sizeof(struct Projectile), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gProjectileHeaderPtr = h;
}

void UpdateProjectiles(void) {
  struct Entity* p;
  struct EntityHeader* h = gProjectileHeaderPtr;
  if ((gStageRun.id != STAGE_SPACE_CRAFT) && (((!(gStageRun.missionStatus & MISSION_STAY)) || (gStageRun.vm.active & 1) || (gStageRun.vm.unk_004 & 1)) || gInChat || gIsUsingDoor3D)) {
    gIsLemonCollisionRemoved = TRUE;
  } else {
    gIsLemonCollisionRemoved = FALSE;
  }

  setCurProcessedEntityHeader(h);
  p = h->last->prev;
  h->last = p;
  while (p != (struct Entity*)&h->next) {
    ((EntityFunc)p->onUpdate)(p);
    p = h->last->prev;
    h->last = p;
  }
}

void DeleteProjectile(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

#if MODERN == 0
static struct Coord* unused_0809c978(struct Projectile* p) {
  struct Weapon* w = (struct Weapon*)GetNearestEntity(gWeaponHeaderPtr, &(p->s).coord);
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
    [20] = &gProjectile20Routine,
    [21] = &gPantheonAquaModProjectileRoutine,
    [22] = &gCubitProjectileRoutine,
    [23] = &gProjectile23Routine,
    [24] = &gCopyXProjectileRoutine,
    [25] = &gProjectile25Routine,
    [26] = &gProjectile26Routine,
    [27] = &gProjectile27Routine,
    [28] = &gProjectile28Routine,
    [29] = &gProjectile29Routine,
    [30] = &gProjectile30Routine,
    [31] = &gProjectile31Routine,
    [32] = &gProjectile32Routine,
    [33] = &gOmegaGoldProjectileRoutine,
    [34] = &gProjectile34Routine,
    [35] = &gPantheonBombProjectileRoutine,
    [36] = &gProjectile36Routine,
    [37] = &gProjectile37Routine,
    [38] = &gOmegaZeroProjectileRoutine,
    [39] = &gClavekerYellowBallsRoutine,
    [40] = &gPhantomProjectileRoutine,
    [41] = &gOmegaZXProjectileRoutine,
    [42] = &gProjectile42Routine,
    [43] = &gProjectile43Routine,
    [44] = &gProjectile44Routine,
    [45] = &gProjectile45Routine,
    [46] = &gProjectile46Routine,
    [47] = &gProjectile47Routine,
};
// clang-format on
