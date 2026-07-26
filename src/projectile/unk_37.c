#include "collision.h"
#include "global.h"
#include "projectile.h"

// キャリビーG の ミサイル + そのミサイルを撃つ部分

void Projectile37_Init(Projectile* p);
void Projectile37_Update(Projectile* p);
void Projectile37_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile37Routine = {
    [ENTITY_INIT] =      (void*)Projectile37_Init,
    [ENTITY_UPDATE] =    (void*)Projectile37_Update,
    [ENTITY_DIE] =       (void*)Projectile37_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Entity* unused_FUN_080ada80(void* e, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 37);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = e;
  }
  return p;
}

Entity* FUN_080adad0(Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 37);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

INCASM("asm/projectile/unk_37_a.inc");

void Projectile37_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/unk_37_b.inc");

// --------------------------------------------

void FUN_080adc84(Projectile* p);
void FUN_080ae140(Projectile* p);

static const ProjectileFunc sUpdates[2] = {
    FUN_080adc84,
    FUN_080ae140,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};
