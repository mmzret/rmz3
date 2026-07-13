#include "collision.h"
#include "global.h"
#include "metatile.h"
#include "projectile.h"

// CopyX Normal Shot

static void Projectile25_Init(struct Entity* p);
static void Projectile25_Update(struct Entity* p);
static void Projectile25_Die(Object* p);

// clang-format off
const ProjectileRoutine gProjectile25Routine = {
    [ENTITY_INIT] =      (void*)Projectile25_Init,
    [ENTITY_UPDATE] =    (void*)Projectile25_Update,
    [ENTITY_DIE] =       (void*)Projectile25_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a83e4(struct Entity* e, u8 param_2, u8 param_3) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 25);
    p->work[0] = param_2, p->work[1] = param_3;
    p->unk_28 = (void*)e;
    (p->coord) = e->coord;
  }
}

// --------------------------------------------

static void FUN_080a84c4(Object* p);
static void FUN_080a85a0(Object* p);
static void FUN_080a8684(Object* p);
static void FUN_080a8794(Object* p);

static void Projectile25_Init(struct Entity* p) {
  static const EntityFunc sInitializers[4] = {
      (void*)FUN_080a84c4,
      (void*)FUN_080a85a0,
      (void*)FUN_080a8684,
      (void*)FUN_080a8794,
  };  // 0x0836bf68
  (sInitializers[p->work[0]])(p);
}

static void Projectile25_Update(struct Entity* p) {
  UpdateSpriteAnimation(p);
  (p->coord).x += (p->d).x;
  (p->coord).y += (p->d).y;
  if (FUN_080098a4((p->coord).x, (p->coord).y)) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

static void Projectile25_Die(Object* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static const struct Collision sCollisions[];

static void FUN_080a84c4(Object* p) {
  struct Entity* q = (p->s).unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM093_COPYX_NORMAL_SHOT, 0));
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x += PIXEL(16);
    (p->s).d.x = PIXEL(4);
  } else {
    (p->s).coord.x -= PIXEL(16);
    (p->s).d.x = -PIXEL(4);
  }
  (p->s).coord.y -= PIXEL(24);
  (p->s).d.y = 0;
  INIT_BODY(p, sCollisions, 64, NULL);
  Projectile25_Update((void*)p);
}

static void FUN_080a85a0(Object* p) {
  struct Entity* q = (p->s).unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM093_COPYX_NORMAL_SHOT, 1));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x += PIXEL(16);
    (p->s).d.x = PIXEL(4);
  } else {
    (p->s).coord.x -= PIXEL(16);
    (p->s).d.x = -PIXEL(4);
  }
  (p->s).coord.y -= PIXEL(24);
  (p->s).d.y = 0;
  INIT_BODY(p, &sCollisions[2], 64, NULL);
  Projectile25_Update((void*)p);
}

static void FUN_080a8684(Object* p) {
  struct Entity* q = (p->s).unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  InitRotatableMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM093_COPYX_NORMAL_SHOT, 0));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x += PIXEL(16);
    (p->s).d.x = COS(32) << 2, (p->s).d.y = SIN(32) << 2;
  } else {
    (p->s).coord.x -= PIXEL(16);
    (p->s).d.x = SIN(128 + 32) << 2, (p->s).d.y = COS(32) << 2;
  }
  *(&(p->s).angle) = 0xE0;
  (p->s).coord.y -= PIXEL(18);
  INIT_BODY(p, &sCollisions[4], 64, NULL);
  Projectile25_Update((void*)p);
}

static void FUN_080a8794(Object* p) {
  struct Entity* q = (p->s).unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  InitRotatableMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM093_COPYX_NORMAL_SHOT, 1));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x += PIXEL(16);
    (p->s).d.x = COS(32) << 2, (p->s).d.y = SIN(32) << 2;
  } else {
    (p->s).coord.x -= PIXEL(16);
    (p->s).d.x = SIN(128 + 32) << 2, (p->s).d.y = COS(32) << 2;
  }
  *(&(p->s).angle) = 0xE0;
  (p->s).coord.y -= PIXEL(18);
  INIT_BODY(p, &sCollisions[2], 64, NULL);
  Projectile25_Update((void*)p);
}

// --------------------------------------------

// 0x0836BF78
static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 6,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
