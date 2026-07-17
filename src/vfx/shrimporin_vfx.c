#include "global.h"
#include "story.h"
#include "vfx.h"

static const u8 sInitModes[3];

static void VFX24_Init(struct VFX* vfx);
static void VFX24_Update(struct VFX* vfx);
static void VFX24_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gShrimporinVFXRoutine = {
    [ENTITY_INIT] =      VFX24_Init,
    [ENTITY_UPDATE] =    VFX24_Update,
    [ENTITY_DIE] =       VFX24_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void createShrimporinIce(s32 x, s32 y, u8 frame) {
  struct VFX* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_SHRIMPORIN);
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[0] = 0;
    (p->s).work[2] = frame;
  }
}

void shrimporinIceCrash(s32 x, s32 y, u8 frame) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct VFX* p = AllocEntityFirst(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_SHRIMPORIN);
      (p->s).coord.x = x;
      (p->s).coord.y = y;

      (p->s).d.x = 0x180;
      (p->s).d.x += (RANDOM(RNG_0202f388) & 0xFF);
      if ((i & 1) != 0) {
        (p->s).d.x = -(p->s).d.x;
      }

      (p->s).d.y = -0x180;
      (p->s).d.y -= RANDOM(RNG_0202f388) % 0x180;

      (p->s).work[0] = 1;
      (p->s).work[2] = frame;
    }
  }
}

void FUN_080b8f68(s32 x, s32 y, u8 frame) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_SHRIMPORIN);
    (p->coord).x = x, (p->coord).y = y;
    p->work[0] = 2;
    p->work[2] = frame;
  }
}

// --------------------------------------------

static void VFX24_Init(struct VFX* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  (p->s).palID = (p->s).work[2];
  VFX24_Update(p);
}

// --------------------------------------------

void FUN_080b9070(struct VFX* vfx);
void FUN_080b90bc(struct VFX* vfx);
void FUN_080b9134(struct VFX* vfx);

static void VFX24_Update(struct VFX* vfx) {
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

static void VFX24_Die(struct VFX* vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
  return;
}

void FUN_080b9070(struct VFX* vfx) {
  switch ((vfx->s).mode[2]) {
    case 0:
      SetMotion(&vfx->s, 0xd00);
      (vfx->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&vfx->s);
      if ((vfx->s).motion.state == 3) {
        SET_VFX_ROUTINE(vfx, ENTITY_DIE);
      }
      break;
  }
}

void FUN_080b90bc(struct VFX* vfx) {
  switch ((vfx->s).mode[2]) {
    case 0:
      SetMotion(&vfx->s, 0xd09);
      (vfx->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&vfx->s);
      (vfx->s).coord.x += (vfx->s).d.x;
      (vfx->s).d.y += 0x80;
      if ((vfx->s).d.y > 0x700) {
        (vfx->s).d.y = 0x700;
      }
      (vfx->s).coord.y += (vfx->s).d.y;
      if ((vfx->s).d.y > 0 && FUN_080098a4((vfx->s).coord.x, (vfx->s).coord.y)) {
        SET_VFX_ROUTINE(vfx, ENTITY_DIE);
      }
      break;
  }
}

void FUN_080b9134(struct VFX* vfx) {
  switch ((vfx->s).mode[2]) {
    case 0:
      SetMotion(&vfx->s, 0xd01);
      (vfx->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&vfx->s);
      if ((vfx->s).motion.state == 4) {
        SET_VFX_ROUTINE(vfx, ENTITY_DIE);
      }
      break;
  }
}

static const u8 sInitModes[3] = {0, 1, 2};
