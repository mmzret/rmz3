#include "collision.h"
#include "entity.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

// 敵が撃ってくる Lemon(豆)
typedef struct {
  COLLISION_OBJECT_HDR;
  s32 amplitude;  // 0xB4
  u8 unk_b8[12];  // 0xB8
} ProjectileLemon;
static_assert(sizeof(ProjectileLemon) == sizeof(struct Projectile));

static const struct Collision sCollisions[6];

static void Lemon_Init(ProjectileLemon* p);
static void Lemon_Update(ProjectileLemon* p);
static void Lemon_Die(ProjectileLemon* p);

// clang-format off
const ProjectileRoutine gLemonRoutine = {
    [ENTITY_INIT] =      (void*)Lemon_Init,
    [ENTITY_UPDATE] =    (void*)Lemon_Update,
    [ENTITY_DIE] =       (void*)Lemon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x0809c99c
struct Projectile* CreateLemon(Coords32* c, s32 amplitude, u8 r2) {
  ProjectileLemon* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 0);
    p->coord.x = c->x, p->coord.y = c->y;
    r2 += 0x80;
    p->amplitude = amplitude;
    p->d.x = Cos(r2, amplitude);
    p->d.y = Sin(r2, amplitude);
    p->work[0] = 1;
  }
  return (void*)p;
}

NAKED static struct Projectile* unused_0809ca34(Coords32* c, s32 r1, u8 r2) { INCCODE("asm/unused/unused_0809ca34.inc"); }

static void Lemon_Init(ProjectileLemon* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 0, NULL);
  SetSpriteAnimation(p, MOTION(SM002_LEMON, 0));
  p->work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Lemon_Update(p);
}

static void Lemon_Update(struct Projectile* p) {
  metatile_attr_t r;
  UpdateSpriteAnimation(&p->s);
  if ((p->body).status & BODY_STATUS_BLOCKED) {
    if ((p->s).mode[1] == 0) {
      INIT_BODY(p, &sCollisions[2], 0, NULL);
      (p->s).d.x = -((p->s).d.x * 3) / 2;
      (p->s).d.y = -((p->s).d.y * 3) / 2;
      (p->s).mode[1] = 1;
    } else if ((p->s).d.y < 0) {
      PlaySound(0x2b);
      (p->s).d.x = -(p->s).d.x;
    } else {
      PlaySound(0x2b);
      (p->s).d.y = -(p->s).d.y;
    }
  }
  if ((p->body).status & 0x400100) {
    EXIT_BODY(p);
    CreateSmoke(3, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if ((p->body).status & BODY_STATUS_B2) {
    EXIT_BODY(p);
    CreateSmoke(2, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if (--(p->s).work[2] == 0) {
    CreateSmoke(3, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else if ((p->s).work[0] != 0 && (r = FUN_080098a4((p->s).coord.x, (p->s).coord.y)) != 0 && !(r & 0x8000)) {
    CreateSmoke(3, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    if ((p->s).mode[1] == 0) {
      if ((p->s).mode[2] == 0) {
        if (gIsLemonCollisionRemoved) {
          SetDDP(&p->body, &sCollisions[4]);
          (p->s).mode[2] = 1;
        }
      } else if (!gIsLemonCollisionRemoved) {
        SetDDP(&p->body, &sCollisions[0]);
        (p->s).mode[2] = 0;
      }
    }
    (p->s).coord.x += (p->s).d.x;
    (p->s).coord.y += (p->s).d.y;
  }
}

static void Lemon_Die(ProjectileLemon* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0xFF,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },

    // --------------------------------------------

    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0xFF,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },
};
