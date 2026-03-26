#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "projectile.h"
#include "story.h"

static void Projectile8_Init(struct Projectile* p);
static void Projectile8_Update(struct Projectile* p);
static void Projectile8_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile8Routine = {
    [ENTITY_INIT] =      Projectile8_Init,
    [ENTITY_UPDATE] =    Projectile8_Update,
    [ENTITY_DIE] =       Projectile8_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void CreateProjectile8(s32 x, s32 y) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 8);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
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

  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM023_GYRO_CANNON, 9));
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
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  UpdateMotionGraphic(&p->s);
  if ((p->s).mode[2] == 0) {
    if ((p->s).d.y < PIXEL(7)) (p->s).d.y += (PIXEL(1) / 4);
    (p->s).coord.y += (p->s).d.y;
    if ((((p->body).status & BODY_STATUS_B2)) || (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0)) {
      SetMotion(&p->s, MOTION(SM023_GYRO_CANNON, 10));
      UpdateMotionGraphic(&p->s);
      PlaySound(SE_UNK_35);
      SetDDP(&p->body, &sCollision);
      (p->s).mode[2]++;
    }
  } else {
    if ((p->s).motion.cmdIdx == 2) {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
    }
    if ((p->s).motion.state == MOTION_END) {
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      Projectile8_Die(p);
    }
  }
}

static void Projectile8_Die(struct Projectile* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}
