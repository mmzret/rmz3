#include "boss.h"
#include "global.h"
#include "vfx.h"

static void VFX25_Init(struct VFX *vfx);
static void VFX25_Update(struct VFX *vfx);
static void VFX25_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gVFX25Routine = {
    [ENTITY_INIT] =      VFX25_Init,
    [ENTITY_UPDATE] =    VFX25_Update,
    [ENTITY_DIE] =       VFX25_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *FUN_080b9184(struct Coord *c, u8 n) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_UNK_025);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = n;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
  }
  return vfx;
}

struct VFX *omegaWhite_080b91d4(struct Coord *c, u8 n, struct Boss *omega) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_UNK_025);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = n;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).unk_28 = &omega->s;
  }
  return vfx;
}

struct VFX *FUN_080b9228(struct Coord *c) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_UNK_025);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 4;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
  }
  return vfx;
}

// --------------------------------------------

static void VFX25_Init(struct VFX *vfx) {
  if ((vfx->s).work[0] == 0) {
    InitNonAffineMotion(&vfx->s);
    (vfx->s).flags |= DISPLAY;
    (vfx->s).flags |= FLIPABLE;
    (vfx->s).work[2] = 8;
    SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
    (vfx->s).mode[1] = 0;
    (vfx->s).mode[2] = 0;
    (vfx->s).mode[3] = 0;

  } else if ((vfx->s).work[0] == 1) {
    InitNonAffineMotion(&vfx->s);
    (vfx->s).flags |= DISPLAY;
    (vfx->s).flags |= FLIPABLE;
    (vfx->s).work[2] = 8;
    SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
    (vfx->s).mode[1] = 1;
    (vfx->s).mode[2] = 0;
    (vfx->s).mode[3] = 0;

  } else if ((vfx->s).work[0] == 2) {
    InitNonAffineMotion(&vfx->s);
    (vfx->s).flags |= DISPLAY;
    (vfx->s).flags |= FLIPABLE;
    (vfx->props).unk25.c.x = 0;
    (vfx->props).unk25.c.y = 0;
    SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
    (vfx->s).mode[1] = 2;
    (vfx->s).mode[2] = 0;
    (vfx->s).mode[3] = 0;
    (vfx->s).taskCol = 24;

  } else if ((vfx->s).work[0] == 3) {
    InitNonAffineMotion(&vfx->s);
    (vfx->s).flags |= DISPLAY;
    (vfx->s).flags |= FLIPABLE;
    (vfx->props).unk25.c.x = 0;
    (vfx->props).unk25.c.y = 0;
    SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
    (vfx->s).mode[1] = 3;
    (vfx->s).mode[2] = 0;
    (vfx->s).mode[3] = 0;
    (vfx->s).taskCol = 24;
    (vfx->s).work[2] = 160;

  } else if ((vfx->s).work[0] == 4) {
    struct VFX *vfx2;
    (vfx->s).work[2] = 60;
    SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
    (vfx->s).mode[1] = 4;
    (vfx->s).mode[2] = 0;
    (vfx->s).mode[3] = 0;
    vfx2 = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx2 != NULL) {
      (vfx2->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx2, VFX_UNK_025);
      (vfx2->s).tileNum = 0;
      (vfx2->s).palID = 0;
      (vfx2->s).work[0] = 5;
      (vfx2->s).coord = (vfx->s).coord;
      (vfx2->s).d.x = 0;
      (vfx2->props).unk25.unk_80 = 0xe000;
      (vfx2->s).d.y = 0xC0;
    }

  } else if ((vfx->s).work[0] == 5) {
    InitScalerotMotion1(&vfx->s);
    (vfx->s).flags |= DISPLAY;
    (vfx->s).flags |= FLIPABLE;
    RNG_0202f388 = LCG(RNG_0202f388);
    (vfx->s).work[2] = ((RNG_0202f388 >> 16) & 0x7) + 60;
    SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
    (vfx->s).mode[1] = 5;
    (vfx->s).mode[2] = 0;
    (vfx->s).mode[3] = 0;
  }

  VFX25_Update(vfx);
}

// --------------------------------------------

static void FUN_080b9494(struct VFX *vfx);
void FUN_080b94dc(struct VFX *vfx);
void FUN_080b9530(struct VFX *vfx);
void FUN_080b963c(struct VFX *vfx);
void FUN_080b970c(struct VFX *vfx);
void FUN_080b9738(struct VFX *vfx);
void FUN_080b97f4(struct VFX *vfx);

static void VFX25_Update(struct VFX *vfx) {
  // clang-format off
  static const VFXFunc sUpdates[7] = {
      FUN_080b9494,
      FUN_080b94dc,
      FUN_080b9530,
      FUN_080b963c,
      FUN_080b970c,
      FUN_080b9738,
      FUN_080b97f4,
  };
  // clang-format on
  (sUpdates[(vfx->s).mode[1]])(vfx);
}

// --------------------------------------------

static void VFX25_Die(struct VFX *vfx) {
  (vfx->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080b9494(struct VFX *vfx) {
  (vfx->s).work[2]--;
  if ((vfx->s).work[2] == 0) {
    (vfx->s).work[2] = 8;
    (vfx->s).mode[1] = 1;
    (vfx->s).mode[2] = 0;
    return;
  }

  switch ((vfx->s).mode[2]) {
    case 0: {
      SetMotion(&vfx->s, MOTION(SM010_OMEGA_RING, 8));
      (vfx->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&vfx->s);
      break;
    }
  }
}

INCASM("asm/vfx/unk_25.inc");
