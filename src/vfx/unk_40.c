#include "global.h"
#include "metatile.h"
#include "vfx.h"

// デスタンツマンティスク に関係

static void VFX40_Init(struct Entity* p);
static void VFX40_Update(struct Entity* p);
static void VFX40_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX40Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX40_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX40_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX40_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080bdaf8(s32 x, s32 y) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_040);
    p->coord.x = x;
    p->coord.y = y;
    p->work[0] = 0;
  }
}

void FUN_080bdb44(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_040);
      p->work[0] = 1;
      p->work[1] = i;
      p->coord.x = x;
      p->coord.y = y;
    }
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX40_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX40_Update((void*)p);
}

static void FUN_080bdc1c(struct Entity* p);
static void FUN_080bdc74(struct Entity* p);

static void VFX40_Update(struct Entity* p) {
  static const EntityFunc sUpdates[2] = {
      FUN_080bdc1c,
      FUN_080bdc74,
  };  // 0x0836eed4
  (sUpdates[p->mode[1]])(p);
}

static void VFX40_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static void FUN_080bdc1c(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM055_DEATHTANZ_PROJECTILE, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
    default: {
      break;
    }
  }
}

static const u8 sInitModes[2] = {0, 1};

static void FUN_080bdc74(struct Entity* p) {
  static const motion_t sMotions[3] = {
      MOTION(DM167_DEATHTANZ, 58),
      MOTION(DM167_DEATHTANZ, 59),
      MOTION(DM167_DEATHTANZ, 59),
  };  // 0x0836EEDE

  u8 idx = p->work[1];
  switch (p->mode[2]) {
    case 0: {
      u32 dx;
      p->flags |= DISPLAY;
      ResetDynamicMotion(p);
      SetSpriteAnimation(p, sMotions[idx]);

      dx = (idx - 1) * PIXEL(1);

      (p->d).x = dx + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->d).y = -(RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(2);

      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[2]++;
      if (p->work[2] & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += PIXEL(1) / 4;
      FUN_0801779c(p);
      if (FUN_080098a4((p->coord).x, (p->coord).y) && ((p->d).y > 0)) {
        CreateSmoke(3, &p->coord);
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
    default: {
      break;
    }
  }
}
