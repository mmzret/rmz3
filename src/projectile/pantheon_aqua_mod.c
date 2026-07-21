#include "collision.h"
#include "global.h"
#include "trig.h"
#include "palette_animation.h"
#include "projectile.h"

static const ProjectileFunc PTR_ARRAY_0836bb00[3];
static const ProjectileFunc PTR_ARRAY_0836bb0c[3];
static const struct Collision sCollisions[2];
static const u8 sInitModes[2];
static const motion_t sMotions[10];
u8 GetEntityPalID(struct Entity* p);

void FUN_080a5bb4(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 5; i++) {
    struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
    if (p != NULL) {
      INIT_PROJECTILE_ROUTINE(p, 21);
      (p->s).work[0] = 0;
      (p->s).work[2] = i;
      (p->s).coord.x = x;
      (p->s).coord.y = y;
    }
  }
}

void nop_080a5c10(struct Enemy* p) {}

void PantheonAquaModProjectile_Init(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, (void*)nop_080a5c10);
  PantheonAquaModProjectile_Update(p);
}

void PantheonAquaModProjectile_Update(struct Projectile* p) {
  (PTR_ARRAY_0836bb00[(p->s).mode[1]])(p);
  (PTR_ARRAY_0836bb0c[(p->s).mode[1]])(p);
}

void PantheonAquaModProjectile_Die(struct Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &(p->s).coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080a5cf8(struct Projectile* p) {}

void FUN_080a5cfc(struct Projectile* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[0]);
      SetSpriteAnimation(p, sMotions[(p->s).work[2]]);
      StartPaletteAnimation(0x57, ((u8)GetEntityPalID(&p->s) << 5) | 0x200);
      (p->s).d.x = gSineTable[(u8)(-0x40 - (p->s).work[2] * 0x20)] * 3;
      (p->s).d.y = gSineTable[(u8)(-0x80 - (p->s).work[2] * 0x20)] * 3;
      SET_XFLIP(p, (p->s).work[2] > 2);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      StepPaletteAnimation(0x57);
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      UpdateSpriteAnimation(p);
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_080a5e00(struct Projectile* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      const motion_t* m;
      SetDDP(&p->body, &sCollisions[1]);
      m = &sMotions[5];
      SetSpriteAnimation(p, m[(p->s).work[2]]);
      (p->s).work[3] = 0x30;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      StepPaletteAnimation(0x57);
      UpdateSpriteAnimation(p);
      if (--(p->s).work[3] == 0) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_080a5e64(struct Projectile* p) {
  s32 m = (p->s).mode[2];
  switch (m) {
    case 0:
      (p->body).status = m;
      (p->body).prevStatus = m;
      (p->body).invincibleTime = m;
      (p->s).flags &= ~COLLIDABLE;
      (p->s).work[3] = 0xa;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if ((p->s).work[3] & 1) {
        (p->s).flags &= ~DISPLAY;
      } else {
        (p->s).flags |= DISPLAY;
      }
      if (--(p->s).work[3] == 0) {
        RemovePaletteAnimation(0x57);
        (p->s).flags &= ~DISPLAY;
        (p->s).flags &= ~FLIPABLE;
        EXIT_BODY(p);
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
  }
}

void PantheonAquaModProjectile_Init(struct Projectile* p);
void PantheonAquaModProjectile_Update(struct Projectile* p);
void PantheonAquaModProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gPantheonAquaModProjectileRoutine = {
    [ENTITY_INIT] =      PantheonAquaModProjectile_Init,
    [ENTITY_UPDATE] =    PantheonAquaModProjectile_Update,
    [ENTITY_DIE] =       PantheonAquaModProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080a5cf8(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836bb00[3] = {
    FUN_080a5cf8,
    FUN_080a5cf8,
    FUN_080a5cf8,
};

void FUN_080a5cfc(struct Projectile* p);
void FUN_080a5e00(struct Projectile* p);
void FUN_080a5e64(struct Projectile* p);

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
