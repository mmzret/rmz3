#include "global.h"
#include "story.h"
#include "vfx.h"

static const u8 sInitModes[3];

static void VFX24_Init(struct VFX *vfx);
static void VFX24_Update(struct VFX *vfx);
static void VFX24_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gShrimporinVFXRoutine = {
    [ENTITY_INIT] =      VFX24_Init,
    [ENTITY_MAIN] =      VFX24_Update,
    [ENTITY_DIE] =       VFX24_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void createShrimporinIce(s32 x, s32 y, u8 frame) {
  struct VFX *vfx = (struct VFX *)AllocEntityLast(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_SHRIMPORIN);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).coord.x = x;
    (vfx->s).coord.y = y;
    (vfx->s).work[0] = 0;
    (vfx->s).work[2] = frame;
  }
}

void shrimporinIceCrash(s32 x, s32 y, u8 frame) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityLast(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_SHRIMPORIN);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).coord.x = x;
      (vfx->s).coord.y = y;

      (vfx->s).d.x = 0x180;
      RNG_0202f388 = (LCG(RNG_0202f388) << 1) >> 1;
      (vfx->s).d.x += ((RNG_0202f388 >> 16) & 0xFF);
      if ((i & 1) != 0) {
        (vfx->s).d.x = -(vfx->s).d.x;
      }

      (vfx->s).d.y = -0x180;
      RNG_0202f388 = (LCG(RNG_0202f388) << 1) >> 1;
      (vfx->s).d.y -= (RNG_0202f388 >> 16) % 0x180;

      (vfx->s).work[0] = 1;
      (vfx->s).work[2] = frame;
    }
  }
}

void FUN_080b8f68(s32 x, s32 y, u8 frame) {
  struct VFX *vfx = (struct VFX *)AllocEntityLast(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_SHRIMPORIN);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).coord.x = x;
    (vfx->s).coord.y = y;
    (vfx->s).work[0] = 2;
    (vfx->s).work[2] = frame;
  }
}

// --------------------------------------------

static void VFX24_Init(struct VFX *vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_MAIN);
  (vfx->s).mode[1] = sInitModes[(vfx->s).work[0]];
  (vfx->s).flags |= FLIPABLE;
  (vfx->s).flags |= DISPLAY;
  InitNonAffineMotion(&vfx->s);
  (vfx->s).palID = (vfx->s).work[2];
  VFX24_Update(vfx);
}

// --------------------------------------------

void FUN_080b9070(struct VFX *vfx);
void FUN_080b90bc(struct VFX *vfx);
void FUN_080b9134(struct VFX *vfx);

static void VFX24_Update(struct VFX *vfx) {
  static const VFXFunc sUpdates[3] = {
      FUN_080b9070,
      FUN_080b90bc,
      FUN_080b9134,
  };

  if (IS_METTAUR) {
    (vfx->s).flags &= ~DISPLAY;
    (vfx->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(vfx, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(vfx->s).mode[1]])(vfx);
}

// --------------------------------------------

static void VFX24_Die(struct VFX *vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
  return;
}

INCASM("asm/vfx/unk_24.inc");

static const u8 sInitModes[3] = {0, 1, 2};
