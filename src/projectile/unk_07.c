#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static void Projectile7_Init(struct Projectile* p);
static void Projectile7_Update(struct Projectile* p);
static void Projectile7_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile7Routine = {
    [ENTITY_INIT] =      Projectile7_Init,
    [ENTITY_UPDATE] =    Projectile7_Update,
    [ENTITY_DIE] =       Projectile7_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* CreateProjectile7(struct Coord* c, s32 amplitude, u8 angle) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 7);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    angle += 0x80;
    *(s32*)p->work = amplitude;
    (p->s).d.x = Cos(angle, amplitude);
    (p->s).d.y = Sin(angle, amplitude);
  }
  return p;
}

static const struct Collision sCollisions[2];

static void Projectile7_Init(struct Projectile* p) {
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  INIT_BODY(p, &sCollisions[0], 0, NULL);
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 1));
  (p->s).work[2] = 0xFF;
  (p->s).spr.oam.priority = 1;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile7_Update(p);
}

static void Projectile7_Update(struct Projectile* p) {
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

  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  UpdateMotionGraphic(&p->s);
  if ((p->s).motion.state == MOTION_END) {
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

static void Projectile7_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
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
