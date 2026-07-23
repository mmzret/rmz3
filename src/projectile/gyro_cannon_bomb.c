#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "projectile.h"
#include "story.h"

// GyroCannon bomb

static void Projectile8_Init(Projectile* p);
static void Projectile8_Update(Projectile* p);
static void Projectile8_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile8Routine = {
    [ENTITY_INIT] =      (void*)Projectile8_Init,
    [ENTITY_UPDATE] =    (void*)Projectile8_Update,
    [ENTITY_DIE] =       (void*)Projectile8_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateProjectile8(s32 x, s32 y) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 8);
    (p->coord).x = x, (p->coord).y = y;
  }
}

static const struct Collision sCollisions[2];

static void Projectile8_Init(Projectile* p) {
  static const struct Collision sCollision = {
    kind : DDP,
    faction : FACTION_ENEMY,
    damage : 2,
    layer : 0x00000001,
    range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
  };

  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 9));
  SET_XFLIP(p, FALSE);
  INIT_BODY(p, &sCollision, 8, NULL);
  (p->d).y = 0;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile8_Update(p);
}

static void Projectile8_Update(Projectile* p) {
  static const struct Collision sCollision = {
    kind : DDP,
    faction : FACTION_ENEMY,
    damage : 2,
    layer : 0x00000001,
    range : {PIXEL(0), -PIXEL(12), PIXEL(26), PIXEL(28)},
  };

  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  UpdateSpriteAnimation(p);
  if (p->mode[2] == 0) {
    if (p->d.y < PIXEL(7)) p->d.y += (PIXEL(1) / 4);
    p->coord.y += p->d.y;
    if ((((p->body).status & BODY_STATUS_B2)) || (FUN_080098a4(p->coord.x, p->coord.y) != 0)) {
      SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 10));
      UpdateSpriteAnimation(p);
      PlaySound(SE_UNK_35);
      SetDDP(&p->body, &sCollision);
      p->mode[2]++;
    }
  } else {
    if ((p->motion).cmdIdx == 2) {
      EXIT_BODY(p);
    }
    if (IsSpriteAnimEnd(p)) {
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      Projectile8_Die(p);
    }
  }
}

static void Projectile8_Die(Projectile* p) {
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}
