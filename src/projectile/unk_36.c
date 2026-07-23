#include "collision.h"
#include "global.h"
#include "projectile.h"

// Hanumachine
typedef struct {
  COLLISION_OBJECT_HDR;
  u8 buffer[16];  // 0xB4
} Projectile36;
static_assert(sizeof(Projectile36) == sizeof(Projectile));

static void Projectile36_Init(Projectile36* p);
static void Projectile36_Update(Projectile36* p);
static void Projectile36_Die(Projectile36* p);

// clang-format off
const ProjectileRoutine gProjectile36Routine = {
    [ENTITY_INIT] =      (void*)Projectile36_Init,
    [ENTITY_UPDATE] =    (void*)Projectile36_Update,
    [ENTITY_DIE] =       (void*)Projectile36_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void hanu_080ad598(Entity* e, u8 a1, u8 a2) {
  Projectile36* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 36);
    p->work[0] = a1, p->work[1] = a2;
    p->unk_28 = e;
    p->coord = e->coord;
  }
}

void FUN_080ad5f0(Entity* e, u8 a1, u8 a2) {
  Projectile36* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 36);
    p->work[0] = a1, p->work[1] = a2;
    p->unk_28 = e;
    p->coord = e->coord;
  }
}

void FUN_080ad698(Projectile36* p);
void FUN_080ad7d0(Projectile36* p);
static void FUN_080ad8b8(Projectile36* p);
static void FUN_080ad994(Projectile36* p);

static void Projectile36_Init(Projectile36* p) {
  static void (*const sInitializers[4])(Projectile36*) = {
      FUN_080ad698,
      FUN_080ad7d0,
      FUN_080ad8b8,
      FUN_080ad994,
  };
  (sInitializers[p->work[0]])(p);
}

void FUN_080ad778(Projectile36* p);
void FUN_080ad840(Projectile36* p);
void FUN_080ad958(Projectile36* p);
void FUN_080ada50(Projectile36* p);

static void Projectile36_Update(Projectile36* p) {
  static void (*const sUpdates[4])(Projectile36*) = {
      FUN_080ad778,
      FUN_080ad840,
      FUN_080ad958,
      FUN_080ada50,
  };
  (sUpdates[p->work[0]])(p);
}

static void Projectile36_Die(Projectile36* p) {
  p->flags &= ~DISPLAY;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/unk_36_a.inc");

static void FUN_080ad8b8(Projectile36* p) {
  EnableSpriteAnimation_Rotatable(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM106_HANUMACHINE_OBJ, 5));
  UpdateSpriteAnimation(p);
  p->angle = 0;
  SET_XFLIP(p, p->work[1]);
  p->work[2] = 0, p->work[3] = 0;
  if (p->flags & X_FLIP) {
    p->work[3] -= 4;
  } else {
    p->work[3] += 4;
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile36_Update(p);
}

void FUN_080ad958(Projectile36* p) {
  UpdateSpriteAnimation(p);
  p->work[2] += p->work[3];
  p->angle = p->work[2];
  if (IsSpriteAnimEnd(p)) SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
}

static void FUN_080ad994(Projectile36* p) {
  Entity* hanu = p->unk_28;
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM106_HANUMACHINE_OBJ, 6));
  SET_XFLIP(p, (hanu->flags & X_FLIP) != 0);
  if (p->flags & X_FLIP) {
    (p->coord).x += PIXEL(10);
  } else {
    (p->coord).x -= PIXEL(10);
  }
  (p->coord).y += PIXEL(16);
  if (FUN_080098a4((p->coord).x, (p->coord).y)) {
    (p->coord).y = FUN_08009f6c((p->coord).x, (p->coord).y);
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile36_Update(p);
}

void FUN_080ada50(Projectile36* p) {
  UpdateSpriteAnimation(p);
  if (IsSpriteAnimEnd(p)) SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
