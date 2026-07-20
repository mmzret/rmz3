#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

static void VFX60_Init(struct Entity* p);
static void VFX60_Update(struct Entity* p);
static void VFX60_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX60Routine = {
    [ENTITY_INIT] =      (void*)VFX60_Init,
    [ENTITY_UPDATE] =    (void*)VFX60_Update,
    [ENTITY_DIE] =       (void*)VFX60_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateVFX60(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_060);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX60_Init(struct Entity* p) {
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

  p->work[2] = 127 + (RANDOM(RNG_0202f388) & 7);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  VFX60_Update(p);
}

static void nop_080c2d44(void* _ UNUSED);
void FUN_080c2d48(VFXUnkCommon* p);

static void VFX60_Update(struct Entity* p) {
  static const VFXFunc sUpdates[2] = {
      (void*)nop_080c2d44,
      (void*)FUN_080c2d48,
  };

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX60_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX60_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080c2d44(void* _) {}

INCASM("asm/vfx/unk_60.inc");

static const s32 s32_ARRAY_0836f3a4[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

const s32* const PTR_s32_ARRAY_0836f404[3] = {
    &s32_ARRAY_0836f3a4[0],
    &s32_ARRAY_0836f3a4[8],
    &s32_ARRAY_0836f3a4[16],
};  // 0x0836F404
