#include "global.h"
#include "vfx.h"

// アヌビステップ関連
// - アヌビステップの棺
// - パンテオンゾンビの爆散パーティクル

static void VFX47_Init(struct Entity* p);
static void VFX47_Update(struct Entity* p);
static void VFX47_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX47Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX47_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX47_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX47_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080bf390(struct Entity* e) {
  void* q = e->unk_2c;
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_047);
    p->work[0] = 1;
    p->unk_28 = (void*)e;
    p->unk_2c = q;
  }
}

void FUN_080bf3d8(struct Entity* e) {
  s32 i;
  void* q = NULL;
  for (i = 0; i < 2; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_047);
      p->work[0] = 0;
      p->work[2] = i;
      p->unk_28 = (void*)e;
      p->unk_2c = q;
      q = (void*)p;
    }
  }
}

void FUN_080bf438(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_047);
    p->work[0] = 2, p->work[2] = kind;
    (p->coord).x = x, (p->coord).y = y;
  }
}

void FUN_080bf48c(s32 x, s32 y, u8 n) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_047);
      p->work[0] = 3;
      p->work[2] = i;
      p->work[3] = n;
      (p->coord).x = x - PIXEL(8);
      (p->coord).x += RANDOM(RNG_0202f388) & 0xFFF;
      (p->coord).y = y;
    }
  }
}

void FUN_080bf52c(s32 x, s32 y, u8 n) {
  s32 i;
  for (i = 0; i < 6; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_047);
      p->work[0] = 4;
      p->work[2] = i;
      (p->coord).x = x - PIXEL(8);
      (p->coord).x += RANDOM(RNG_0202f388) & 0xFFF;
      (p->coord).y = y;
    }
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX47_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX47_Update((void*)p);
}

void FUN_080bf634(struct VFX* vfx);
void FUN_080bf6d8(struct VFX* vfx);
void FUN_080bf890(struct VFX* vfx);
void FUN_080bfa10(struct VFX* vfx);
void FUN_080bfa7c(struct VFX* vfx);
void FUN_080bfb54(struct VFX* vfx);

static void VFX47_Update(struct Entity* p) {
  // clang-format off
  static const VFXFunc sUpdates[6] = {
      (VFXFunc)FUN_080bf634,
      (VFXFunc)FUN_080bf6d8,
      (VFXFunc)FUN_080bf890,
      (VFXFunc)FUN_080bfa10,
      (VFXFunc)FUN_080bfa7c,
      (VFXFunc)FUN_080bfb54,
  }; // 0x0836f0f4
  // clang-format on
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX47_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

INCASM("asm/vfx/unk_47.inc");

// --------------------------------------------

static const u8 sInitModes[5] = {
    0, 2, 3, 4, 5,
};

// 0x0836f112
static const motion_t sMotions[3] = {
    MOTION(SM076_PANTHEON_ZOMBIE, 5),
    MOTION(SM076_PANTHEON_ZOMBIE, 10),
    MOTION(SM076_PANTHEON_ZOMBIE, 9),
};
