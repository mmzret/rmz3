#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

static const VFXFunc sUpdates[3];

static void VFX22_Init(struct Entity* p);
static void Ghost22_Update(struct Entity* p);
static void Ghost22_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost22Routine = {
    [ENTITY_INIT] =      (void*)VFX22_Init,
    [ENTITY_UPDATE] =    (void*)Ghost22_Update,
    [ENTITY_DIE] =       (void*)Ghost22_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080b7b38(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_022);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080b7b8c(Coords32* c, u8 kind, motion_t m, u32 val) {
  struct VFXUnkCommon* p = (struct VFXUnkCommon*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_022);
    (p->s).work[0] = kind, (p->s).work[1] = 1;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX22_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = -PIXEL(1) / 2;
  } else {
    (p->d).x = PIXEL(1) / 2;
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    p->work[2] = 127 + (RANDOM(RNG_0202f388) & 7);
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
  }
  Ghost22_Update((void*)p);
}

static void nop_080b7d48(void* _ UNUSED);
void FUN_080b7d4c(struct VFX* p);
void FUN_080b7e3c(struct VFX* p);

static void Ghost22_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)nop_080b7d48,
      (void*)FUN_080b7d4c,
      (void*)FUN_080b7e3c,
  };

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost22_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void Ghost22_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080b7d48(void* _) {}

INCASM("asm/vfx/unk_22.inc");

const s32 s32_ARRAY_0836e9f0[24] = {
    0x00000120,  -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120,  -0x00000160,  // 0
    -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120,  -0x00000160, 0x00000120,  -0x00000200,  // 1
    -0x000000B0, -0x00000200, 0x00000120,  -0x00000160, 0x00000120,  -0x00000200, -0x000000B0, -0x00000160,  // 2
};

// 0x0836EA50
const s32* const PTR_ARRAY_0836ea50[3] = {
    &s32_ARRAY_0836e9f0[0],
    &s32_ARRAY_0836e9f0[8],
    &s32_ARRAY_0836e9f0[16],
};
