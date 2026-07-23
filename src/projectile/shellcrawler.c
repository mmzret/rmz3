#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"
#include "vfx.h"

// Shellcrawler's bullet

static void Projectile43_Init(struct Entity* p);
static void Projectile43_Update(Object* p);
static void Projectile43_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gShellcrawlerProjectileRoutine = {
    [ENTITY_INIT] =      (void*)Projectile43_Init,
    [ENTITY_UPDATE] =    (void*)Projectile43_Update,
    [ENTITY_DIE] =       (void*)Projectile43_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
}; // 0x0836d734
// clang-format on

// 0x080B145C
void CreateProjectile43(Coords32* c, s32 dx) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 43);
    (p->coord).x = c->x, (p->coord).y = c->y;
    (p->d).x = dx;
    p->work[2] = (dx > 0) ? 1 : 0;
    p->work[0] = 0;
  }
}

static const u8 sInitModes[];

static void Projectile43_Init(struct Entity* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  Projectile43_Update((void*)p);
}

static void _Projectile43_Update(Object* p);

static void Projectile43_Update(Object* p) {
  static const ObjectFunc sUpdates[1] = {
      _Projectile43_Update,
  };  // 0x0836d748
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static const struct Collision sCollision[];

// 0x080b155c
static void _Projectile43_Update(Object* p) {
  switch (p->mode[2]) {
    case 0: {
      INIT_BODY(p, sCollision, 0, NULL);
      EnableSpriteAnimation_Normal(p);
      SetSpriteAnimation(p, MOTION(SM219_SHELLCRAWLER, 13));
      SET_XFLIP(p, p->work[2]);
      p->mode[2]++;
      p->work[3] = 85;
      p->work[2] = 6;
      FALLTHROUGH;
    }
    case 1: {
      p->work[3]--;
      if (p->work[3] == 0) {
        CreateSmoke(3, &p->coord);
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
        return;
      }
      if (p->work[2] == 0) {
        u8 attr;
        p->coord.x += p->d.x;
        attr = FUN_080098a4(p->coord.x, p->coord.y);
        if (attr != 0 && !(attr & (1 << 7))) SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      } else {
        p->work[2]--;
      }
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

static void Projectile43_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static const struct Collision sCollision[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
};

// 0x0836d77c
static const u8 sInitModes[1] = {0};
