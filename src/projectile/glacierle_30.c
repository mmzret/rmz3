#include "collision.h"
#include "global.h"
#include "projectile.h"

// glacierle に関連するのは確定

void Projectile30_Init(Projectile* p);
void Projectile30_Update(Projectile* p);
void Projectile30_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile30Routine = {
    [ENTITY_INIT] =      (void*)Projectile30_Init,
    [ENTITY_UPDATE] =    (void*)Projectile30_Update,
    [ENTITY_DIE] =       (void*)Projectile30_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080aa5e8(s32 x, s32 y, s32 dx, s32 dy) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 30);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
    (p->d).x = dx, (p->d).y = dy;
  }
}

// 0x080AA638
static void nop_080aa638(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

INCASM("asm/projectile/glacierle_30_a.inc");

void FUN_080aa710(Projectile* p) {
}

INCASM("asm/projectile/glacierle_30_b.inc");

// --------------------------------------------

void FUN_080aa710(Projectile* p);

static const ProjectileFunc sUpdates1[1] = {
    FUN_080aa710,
};

void FUN_080aa714(Projectile* p);

static const ProjectileFunc sUpdates2[1] = {
    FUN_080aa714,
};

// --------------------------------------------

static const struct Collision sCollisions[1] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

static const u8 u8_ARRAY_0836c304[2] = {0, 0};

static const motion_t sMotions[8] = {
    MOTION(SM089_GLACIERLE_HAND, 7), MOTION(SM089_GLACIERLE_HAND, 6), MOTION(SM089_GLACIERLE_HAND, 5), MOTION(SM089_GLACIERLE_HAND, 8), MOTION(SM089_GLACIERLE_HAND, 7), MOTION(SM089_GLACIERLE_HAND, 6), MOTION(SM089_GLACIERLE_HAND, 5), MOTION(SM089_GLACIERLE_HAND, 8),
};
