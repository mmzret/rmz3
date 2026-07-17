#include "global.h"
#include "vfx.h"

// 雪玉のパーティクル

static void VFX45_Init(struct Entity* p);
static void VFX45_Update(struct Entity* p);
static void VFX45_Die(struct Entity* p);

// clang-format off
const VFXRoutine gIceballParticleRoutine = {
    [ENTITY_INIT] =      (VFXFunc)VFX45_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX45_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX45_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x080bea24
void CreateIceballParticle2(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 2; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_ICEBALL_PARTICLE);
      p->work[0] = 0;
      p->work[1] = i;
      p->coord.x = x;
      p->coord.y = y;
    }
  }
}

// 0x080bea80
void CreateIceballParticle4(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 4; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_ICEBALL_PARTICLE);
      p->work[0] = 0;
      p->work[1] = i;
      p->coord.x = x;
      p->coord.y = y;
    }
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX45_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX45_Update((void*)p);
}

static void _VFX45_Update(struct Entity* p);

static void VFX45_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      _VFX45_Update,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX45_Die(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
  return;
}

// --------------------------------------------

// 0x0836effc
static const u8 sInitModes[2] = {0, 0};

// 0x080beb54
static void _VFX45_Update(struct Entity* p) {
  static const motion_t sMotions[4] = {
      MOTION(SM064_ICE_BALL, 0x01),
      MOTION(SM064_ICE_BALL, 0x02),
      MOTION(SM064_ICE_BALL, 0x06),
      MOTION(SM064_ICE_BALL, 0x07),
  };  // 0x0836effe

  u8 idx = p->work[1];
  switch (p->mode[2]) {
    case 0: {
      s32 dx;
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, sMotions[idx]);

      dx = (idx - 1) * PIXEL(1);

      (p->d).x = dx + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->d).y = -(RANDOM(RNG_0202f388) & 0xFF) - PIXEL(1);

      p->work[2] = 32;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[2]--;
      if (p->work[2] & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += PIXEL(1) / 4;
      _FUN_0801779c(p);
      if (p->work[2] == 0) {
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
