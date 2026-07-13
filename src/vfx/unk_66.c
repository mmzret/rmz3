#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// claveker

static void Ghost66_Init(struct Entity* p);
static void Ghost66_Update(struct Entity* p);
static void Ghost66_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost66Routine = {
    [ENTITY_INIT] =      (void*)Ghost66_Init,
    [ENTITY_UPDATE] =    (void*)Ghost66_Update,
    [ENTITY_DIE] =       (void*)Ghost66_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080c4450(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_066);
    p->work[0] = n, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080c44a8(Coords32* c, u8 kind, motion_t m, u32 val) {
  struct VFXUnkCommon* p = (struct VFXUnkCommon*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_066);
    (p->s).work[0] = kind, (p->s).work[1] = 1;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void Ghost66_Init(struct Entity* p) {
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
  Ghost66_Update(p);
}

static void nop_080c4668(void* _ UNUSED);
void FUN_080c466c(struct VFX* p);
void FUN_080c47e0(struct VFX* p);

static void Ghost66_Update(struct Entity* p) {
  static const EntityFunc sUpdates[3] = {
      (void*)nop_080c4668,
      (void*)FUN_080c466c,
      (void*)FUN_080c47e0,
  };  // 0x0836f5c0
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost66_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void Ghost66_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080c4668(void* _) {}

INCASM("asm/vfx/unk_66.inc");

// --------------------------------------------

const s32 s32_ARRAY_0836f5cc[24] = {
    0x00000120, 0x00000260, -0x000000B0, 0x000001A0, -0x000000B0, 0x00000260, 0x00000120, 0x000001A0, -0x000000B0, 0x000001A0, -0x000000B0, 0x00000260, 0x00000120, 0x000001A0, 0x00000120, 0x00000260, -0x000000B0, 0x00000260, 0x00000120, 0x000001A0, 0x00000120, 0x00000260, -0x000000B0, 0x000001A0,
};

// 0x0836f62c
const s32* const PTR_ARRAY_0836f62c[3] = {
    &s32_ARRAY_0836f5cc[0],
    &s32_ARRAY_0836f5cc[8],
    &s32_ARRAY_0836f5cc[16],
};
