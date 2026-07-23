#include "collision.h"
#include "global.h"
#include "palette_animation.h"
#include "projectile.h"
#include "trig.h"
#include "vfx.h"

static const ProjectileFunc PTR_ARRAY_0836bb00[3];
static const ProjectileFunc PTR_ARRAY_0836bb0c[3];
static const struct Collision sCollisions[2];
static const u8 sInitModes[2];
static const motion_t sMotions[10];

static void PantheonAquaModProjectile_Init(Projectile* p);
static void PantheonAquaModProjectile_Update(Projectile* p);
static void PantheonAquaModProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gPantheonAquaModProjectileRoutine = {
    [ENTITY_INIT] =      (void*)PantheonAquaModProjectile_Init,
    [ENTITY_UPDATE] =    (void*)PantheonAquaModProjectile_Update,
    [ENTITY_DIE] =       (void*)PantheonAquaModProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a5bb4(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 5; i++) {
    Entity* p = AllocEntityLast(gProjectileHeaderPtr);
    if (p != NULL) {
      INIT_PROJECTILE_ROUTINE(p, 21);
      p->work[0] = 0;
      p->work[2] = i;
      (p->coord).x = x, (p->coord).y = y;
    }
  }
}

void PantheonAquaModProjectile_OnCollision(struct Body* _, Coords32* c1, Coords32* c2) {}

static void PantheonAquaModProjectile_Init(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, PantheonAquaModProjectile_OnCollision);
  PantheonAquaModProjectile_Update(p);
}

static void PantheonAquaModProjectile_Update(Projectile* p) {
  (PTR_ARRAY_0836bb00[p->mode[1]])(p);
  (PTR_ARRAY_0836bb0c[p->mode[1]])(p);
}

static void PantheonAquaModProjectile_Die(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080a5cf8(Projectile* p) {}

void FUN_080a5cfc(Projectile* p) {
  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[0]);
      SetSpriteAnimation(p, sMotions[p->work[2]]);
      StartPaletteAnimation(87, ((u8)GetEntityPaletteID(p) << 5) | 0x200);
      p->d.x = gSineTable[(u8)(-0x40 - p->work[2] * 0x20)] * 3;
      p->d.y = gSineTable[(u8)(-0x80 - p->work[2] * 0x20)] * 3;
      SET_XFLIP(p, p->work[2] > 2);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      StepPaletteAnimation(87);
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      UpdateSpriteAnimation(p);
      if (FUN_080098a4(p->coord.x, p->coord.y) != 0) {
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
    }
  }
}

void FUN_080a5e00(Projectile* p) {
  switch (p->mode[2]) {
    case 0: {
      const motion_t* m;
      SetDDP(&p->body, &sCollisions[1]);
      m = &sMotions[5];
      SetSpriteAnimation(p, m[p->work[2]]);
      p->work[3] = 0x30;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      StepPaletteAnimation(87);
      UpdateSpriteAnimation(p);
      if (--p->work[3] == 0) {
        p->mode[1] = 2;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_080a5e64(Projectile* p) {
  switch (p->mode[2]) {
    case 0: {
      EXIT_BODY(p);
      p->work[3] = 10;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (p->work[3] & 1) {
        p->flags &= ~DISPLAY;
      } else {
        p->flags |= DISPLAY;
      }
      if (--p->work[3] == 0) {
        RemovePaletteAnimation(87);
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(p);
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_080a5cf8(Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836bb00[3] = {
    FUN_080a5cf8,
    FUN_080a5cf8,
    FUN_080a5cf8,
};

void FUN_080a5cfc(Projectile* p);
void FUN_080a5e00(Projectile* p);
void FUN_080a5e64(Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836bb0c[3] = {
    FUN_080a5cfc,
    FUN_080a5e00,
    FUN_080a5e64,
};

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(24)},
    },
};

static const u8 sInitModes[2] = {0, 0};

// clang-format off
static const motion_t sMotions[10] = {
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 4),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 6),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 8),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 6),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 4),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 5),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 7),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 9),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 7),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 5),
};
// clang-format on
