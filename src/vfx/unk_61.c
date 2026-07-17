#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

#define IS_METTAUR (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED))

// Mothjiro 関連

void VFX61_Init(struct VFX* vfx);
void VFX61_Update(struct VFX* vfx);
void VFX61_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX61Routine = {
    [ENTITY_INIT] =      (void*)VFX61_Init,
    [ENTITY_UPDATE] =    (void*)VFX61_Update,
    [ENTITY_DIE] =       (void*)VFX61_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_080c2e7c(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_061);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

struct Entity* FUN_080c2ed0(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_061);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

struct Entity* FUN_080c2f3c(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_061);
    p->work[0] = kind, p->work[1] = 2;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

// --------------------------------------------

static const VFXFunc sUpdates[3];

INCASM("asm/vfx/unk_61_a.inc");

void VFX61_Update(struct VFX* vfx) {
  if (IS_METTAUR) {
    SET_VFX_ROUTINE(vfx, ENTITY_DIE);
    VFX61_Die(vfx);
  } else {
    (sUpdates[(vfx->s).mode[1]])(vfx);
  }
}


void VFX61_Die(struct VFX* vfx) {
  (vfx->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_61_b.inc");

// --------------------------------------------

void FUN_080c3108(struct VFX* vfx);
void FUN_080c3214(struct VFX* vfx);
void FUN_080c338c(struct VFX* vfx);

static const VFXFunc sUpdates[3] = {
    FUN_080c3108,
    FUN_080c3214,
    FUN_080c338c,
};

static const s32 s32_ARRAY_0836f430[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

static const s32* const PTR_s32_ARRAY_0836f490[3] = {
    &s32_ARRAY_0836f430[0],
    &s32_ARRAY_0836f430[8],
    &s32_ARRAY_0836f430[16],
};
