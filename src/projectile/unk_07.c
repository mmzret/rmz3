#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 amplitude_b4;      // 0xB4
  u8 unk_b8[12];         // 0xB8
} Projectile7;
static_assert(sizeof(Projectile7) == sizeof(Projectile));

static void Projectile7_Init(Projectile7* p);
static void Projectile7_Update(Projectile7* p);
static void Projectile7_Die(Projectile7* p);

// clang-format off
const ProjectileRoutine gProjectile7Routine = {
    [ENTITY_INIT] =      (void*)Projectile7_Init,
    [ENTITY_UPDATE] =    (void*)Projectile7_Update,
    [ENTITY_DIE] =       (void*)Projectile7_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* CreateProjectile7(Coords32* c, s32 amplitude, u8 angle) {
  Projectile7* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 7);
    (p->coord).x = c->x, (p->coord).y = c->y;
    angle += 0x80;
    p->amplitude_b4 = amplitude;
    (p->d).x = Cos(angle, amplitude);
    (p->d).y = Sin(angle, amplitude);
  }
  return (void*)p;
}

static const struct Collision sCollisions[2];

static void Projectile7_Init(Projectile7* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  _INIT_BODY(p, &sCollisions[0], 0);
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 1));
  p->work[2] = 0xFF;
  (p->spr).oam.priority = 1;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile7_Update(p);
}

static void Projectile7_Update(Projectile7* p) {
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (p->coord).x += (p->d).x;
  (p->coord).y += (p->d).y;
  UpdateSpriteAnimation(p);
  if (IsSpriteAnimEnd(p)) {
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

static void Projectile7_Die(Projectile7* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
};
