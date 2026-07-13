#include "global.h"
#include "physics.h"
#include "vfx.h"

// OrWormer の出す土埃のエフェクト

static void VFX35_Init(struct Entity* p);
static void VFX35_Update(struct Entity* p);
static void VFX35_Die(struct Entity* p);

// clang-format off
const VFXRoutine gOrWormerDustCloudRoutine = {
    [ENTITY_INIT] =      (VFXFunc)VFX35_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX35_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX35_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateGhost35(s32 x, s32 y, u8 n) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_ORWORMER_DUST_CLOUD);
    p->work[0] = 0, p->work[2] = n;
    p->coord.x = x;
    p->coord.y = y;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX35_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX35_Update(p);
}

static void _VFX35_Update(struct Entity* p);

static void VFX35_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      _VFX35_Update,
  };  // 0x0836ed9c
  (sUpdates[p->mode[1]])(p);
}

static void VFX35_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// 0x0836eda0
static const u8 sInitModes[4] = {0, 0, 0, 0};

// --------------------------------------------

// 0x080bbf8c
static void _VFX35_Update(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 dy;
      p->palID = p->work[2];
      (p->d).x = (RANDOM(RNG_0202f388) & 0x3FF) - PIXEL(2);

      (p->d).y = -PIXEL(1);
      (p->d).y -= (RANDOM(RNG_0202f388) & 0x1FF);

      SetSpriteAnimation(p, MOTION(SM044_WORMER_ROCK_DRONE, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 delta;

      (p->coord).x += (p->d).x;
      (p->d).y += PIXEL(1) / 4;
      if ((p->d).y > PIXEL(7)) {
        (p->d).y = PIXEL(7);
      }
      (p->coord).y += (p->d).y;
      UpdateSpriteAnimation(p);

      delta = PushoutToUp1((p->coord).x, (p->coord).y);
      if ((delta < 0) && ((p->d).y > 0)) {
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
