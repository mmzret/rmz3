#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"
#include "vfx.h"

// Shotloid (巨大エレベーターに出現) の弾

static void Projectile42_Init(Object* p);
static void Projectile42_Update(Object* p);
static void Projectile42_Die(Object* p);

// clang-format off
const ProjectileRoutine gShotloidProjectileRoutine = {
    [ENTITY_INIT] =      (void*)Projectile42_Init,
    [ENTITY_UPDATE] =    (void*)Projectile42_Update,
    [ENTITY_DIE] =       (void*)Projectile42_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
}; // 0x0836d6fc
// clang-format on

void FUN_080b1234(s32 x, s32 y, s32 dx, s32 dy, u8 n) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 42);
    p->work[0] = n;
    (p->coord).x = x, (p->coord).y = y;
    (p->d).x = dx, (p->d).y = dy;
  }
}

// 0x080b1298
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

// --------------------------------------------

static const u8 u8_ARRAY_0836d730[4];
static const struct Collision sCollision;

static void Projectile42_Init(Object* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = u8_ARRAY_0836d730[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollision, 1, onCollision);
  Projectile42_Update((void*)p);
}

static void FUN_080b13d8(void* _ UNUSED);
static void _Projectile42_Update(Object* p);

static void Projectile42_Update(Object* p) {
  static const EntityFunc sUpdates1[] = {
      (void*)FUN_080b13d8,
  };
  static const EntityFunc sUpdates2[] = {
      (void*)_Projectile42_Update,
  };

  if ((p->work[0] == 0) && FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

static void Projectile42_Die(Object* p) {
  EXIT_BODY(p);
  CreateSmoke(1, &p->coord);
  PlaySound(SE_ZAKO_EXPLODE);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080b13d8(void* _) {}

// 0x080B13DC
static void _Projectile42_Update(Object* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM142_SHOTLOID, 12));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->coord.x += p->d.x;
      p->d.y += PIXEL(1) / 4;
      if (p->d.y > PIXEL(7)) {
        p->d.y = PIXEL(7);
      }
      p->coord.y += p->d.y;
      UpdateSpriteAnimation(p);
      if (FUN_080098a4(p->coord.x, p->coord.y) || (((p->body).status & BODY_STATUS_B2))) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 4,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
};

// 0x0836d730
static const u8 u8_ARRAY_0836d730[4] = {0, 0, 0, 0};
