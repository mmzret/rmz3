#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "projectile.h"
#include "story.h"

// GyroCannon bomb

static void Projectile8_Init(struct Projectile* p);
static void Projectile8_Update(struct Projectile* p);
static void Projectile8_Die(struct Projectile* p);

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
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 8);
    (p->coord).x = x, (p->coord).y = y;
  }
}

static const struct Collision sCollisions[2];

static void Projectile8_Init(struct Projectile* p) {
  static const struct Collision sCollision = {
    kind : DDP,
    faction : FACTION_ENEMY,
    damage : 2,
    layer : 0x00000001,
    range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
  };

  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 9));
  SET_XFLIP(p, FALSE);
  INIT_BODY(p, &sCollision, 8, NULL);
  (p->s).d.y = 0;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile8_Update(p);
}

static void Projectile8_Update(struct Projectile* p) {
  static const struct Collision sCollision = {
    kind : DDP,
    faction : FACTION_ENEMY,
    damage : 2,
    layer : 0x00000001,
    range : {PIXEL(0), -PIXEL(12), PIXEL(26), PIXEL(28)},
  };

  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  UpdateSpriteAnimation(p);
  if ((p->s).mode[2] == 0) {
    if ((p->s).d.y < PIXEL(7)) (p->s).d.y += (PIXEL(1) / 4);
    (p->s).coord.y += (p->s).d.y;
    if ((((p->body).status & BODY_STATUS_B2)) || (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0)) {
      SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 10));
      UpdateSpriteAnimation(p);
      PlaySound(SE_UNK_35);
      SetDDP(&p->body, &sCollision);
      (p->s).mode[2]++;
    }
  } else {
    if ((p->s).motion.cmdIdx == 2) {
      EXIT_BODY(p);
    }
    if (IsSpriteAnimEnd(p)) {
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      Projectile8_Die(p);
    }
  }
}

static void Projectile8_Die(struct Projectile* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}
