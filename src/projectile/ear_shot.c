#include "camera.h"
#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "stagerun.h"

static const u8 sInitModes[4];
static const struct Collision sCollisions[4];

static void EarShot_Init(struct ProjectileV2* p);
static void EarShot_Update(struct ProjectileV2* p);
static void EarShot_Die(struct ProjectileV2* p);

// clang-format off
const ProjectileRoutine gEarShotRoutine = {
    [ENTITY_INIT] =      (void*)EarShot_Init,
    [ENTITY_UPDATE] =    (void*)EarShot_Update,
    [ENTITY_DIE] =       (void*)EarShot_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void createEarShot(s32 x, s32 y, u8 n, bool8 is_big) {
  struct ProjectileV2* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 11);
    p->work[0] = !!is_big;
    p->work[2] = n;
    (p->coord).x = x, (p->coord).y = y;
  }
}

// 0x0809f2f0
static void EarShot_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

// --------------------------------------------

static void EarShot_Init(struct ProjectileV2* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollisions[p->work[0] == 1], 1, EarShot_OnCollision);
  EarShot_Update(p);
}

static void nop_0809f3d0(struct ProjectileV2* p);
static void _EarShot_Update(struct ProjectileV2* p);

static void EarShot_Update(struct ProjectileV2* p) {
  static const ProjectileV2Func sUpdates1[1] = {
      nop_0809f3d0,
  };
  static const ProjectileV2Func sUpdates2[1] = {
      _EarShot_Update,
  };
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void EarShot_Die(struct ProjectileV2* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_0809f3d0(struct ProjectileV2* p) {}

static void _EarShot_Update(struct ProjectileV2* p) {
  switch (p->mode[2]) {
    case 0: {
      if (p->work[0] == 0) {
        SetSpriteAnimation(p, MOTION(SM037_EAR_SHOT, 0));
      } else {
        SetSpriteAnimation(p, MOTION(SM037_EAR_SHOT, 1));
      }
      (p->d).x = (p->work[2] << 11) - PIXEL(4);
      SET_XFLIP(p, p->work[2]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->coord).x += (p->d).x;
      UpdateSpriteAnimation(p);
      if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) > PIXEL(96)) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x1200, 0x0000, 0x2600, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x2400, 0x0000, 0x4200, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x3E00, -0x0B00, 0x2400, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x3E00, 0x0B00, 0x2400, 0x0A00},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
