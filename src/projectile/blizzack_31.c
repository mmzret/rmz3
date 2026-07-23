#include "collision.h"
#include "global.h"
#include "projectile.h"

// Blizzack のつらら飛ばし?(Blizzack関連なのは確定)

void Projectile31_Init(Projectile* p);
void Projectile31_Update(Projectile* p);
static void Projectile31_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile31Routine = {
    [ENTITY_INIT] =      (void*)Projectile31_Init,
    [ENTITY_UPDATE] =    (void*)Projectile31_Update,
    [ENTITY_DIE] =       (void*)Projectile31_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x080aa7a8
Entity* CreateProjectile31(Entity* q, u8 kind1, u8 kind2) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 31);
    p->work[0] = kind1, p->work[1] = kind2;
    p->unk_28 = (void*)q;
    (p->coord) = q->coord;
    return (void*)p;
  }
  return NULL;
}

INCASM("asm/projectile/blizzack_31.inc");

static void Projectile31_Die(Projectile* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

// --------------------------------------------

static const s32 s32_ARRAY_0836c35c[4] = {PIXEL(8), PIXEL(8), PIXEL(32), PIXEL(32)};

static const s32 s32_ARRAY_0836c36c[8] = {
    0x140, 0x180, 0x200, 0x280, 0xA0, 0xC0, 0x100, 0x140,
};

static const s32 s32_ARRAY_0836c38c[8] = {
    -0x600, -0x500, -0x400, -0x300, -0xC00, -0xA00, -0x800, -0x600,
};
