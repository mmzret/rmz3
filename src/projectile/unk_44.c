#include "collision.h"
#include "global.h"
#include "stagerun.h"
#include "projectile.h"
#include "vfx.h"

static const ProjectileFunc PTR_ARRAY_0836d794[2];
static const u8 u8_ARRAY_0836d7b4[4];
static const struct Collision Collision_0836d79c;

void FUN_080b1698(s32 x, s32 y, u8 a2, u8 a3) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 44);
    p->work[0] = 0;
    p->coord.x = x;
    p->coord.y = y;
    p->work[2] = a2;
    p->work[3] = a3;
  }
}

static void nop_080b16f0(struct Projectile* p) {}

static const struct Collision Collision_0836d79c;
static const u8 u8_ARRAY_0836d7b4[4];

void FUN_080b1764(struct Projectile* p);

void FUN_080b16f4(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = u8_ARRAY_0836d7b4[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &Collision_0836d79c, 1, (void*)nop_080b16f0);
  FUN_080b1764(p);
}


INCASM("asm/projectile/unk_44_x.inc");

void FUN_080b1798(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080b17d8(Projectile* p) {}

void FUN_080b17dc(Projectile* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 v;
      p->unk_coord.x = 0x40;
      v = Sqrt(0xa0 << 3);
      p->d.x = -p->unk_coord.x * (s16)v;
      if (p->work[2]) {
        p->unk_coord.x = -p->unk_coord.x;
        p->d.x = -p->d.x;
      }
      p->unk_coord.y = (s16)v * 2;
      p->d.y = 0xa0;
      p->d.y -= p->work[3] * 320;
      SetSpriteAnimation(p, MOTION(0xd7, 0));
      p->mode[2]++;
    }
    FALLTHROUGH;
    case 1:
      p->coord.x += p->d.x;
      if (p->unk_coord.y != 0) {
        p->unk_coord.y--;
        p->d.x += p->unk_coord.x;
      }
      p->coord.y += p->d.y;
      UpdateSpriteAnimation(p);
      if (p->work[2]) {
        if (p->coord.x >= (&gStageRun.vm.camera)->viewport.x - 0xD800) {
          return;
        }
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(p);
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      } else {
        if (p->coord.x <= (&gStageRun.vm.camera)->viewport.x + 0xD7FF) {
          return;
        }
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(p);
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
  }
}

void FUN_080b16f4(Projectile* p);
void FUN_080b1764(Projectile* p);
void FUN_080b1798(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile44Routine = {
    [ENTITY_INIT] =      (void*)FUN_080b16f4,
    [ENTITY_UPDATE] =    (void*)FUN_080b1764,
    [ENTITY_DIE] =       (void*)FUN_080b1798,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080b17d8(Projectile* p);
void FUN_080b17dc(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d794[2] = {
    FUN_080b17d8,
    FUN_080b17dc,
};
// clang-format on

static const struct Collision Collision_0836d79c = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 4,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(13)},
};

static const u8 u8_ARRAY_0836d7b4[4] = {0, 0, 0, 0};
