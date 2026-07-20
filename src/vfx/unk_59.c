#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// Pantheon Bomber の出すエフェクト

static void VFX59_Init(struct Entity* p);
static void VFX59_Update(struct Entity* p);
static void VFX59_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX59Routine = {
    [ENTITY_INIT] =      (void*)VFX59_Init,
    [ENTITY_UPDATE] =    (void*)VFX59_Update,
    [ENTITY_DIE] =       (void*)VFX59_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080c26e8(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_059);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080c273c(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_059);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX59_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = -PIXEL(3) / 4;
  } else {
    (p->d).x = PIXEL(3) / 4;
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
  VFX59_Update((void*)p);
}

static void nop_080c28fc(void* _ UNUSED);
void FUN_080c2900(struct VFX* p);
void FUN_080c2a78(struct VFX* p);

static void VFX59_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)nop_080c28fc,
      (void*)FUN_080c2900,
      (void*)FUN_080c2a78,
  };

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX59_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX59_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080c28fc(void* _) {}

INCASM("asm/vfx/unk_59.inc");

// --------------------------------------------

static const s32 s32_ARRAY_0836f31c[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

const s32* const PTR_s32_ARRAY_0836f37c[3] = {
    &s32_ARRAY_0836f31c[0],
    &s32_ARRAY_0836f31c[8],
    &s32_ARRAY_0836f31c[16],
};  // 0x0836F37C
