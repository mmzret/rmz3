#include "entity.h"
#include "vfx.h"
#include "global.h"

void Ghost66_Init(struct VFX* p);
void Ghost66_Update(struct VFX* p);
void Ghost66_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost66Routine = {
    [ENTITY_INIT] =      Ghost66_Init,
    [ENTITY_UPDATE] =    Ghost66_Update,
    [ENTITY_DIE] =       Ghost66_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* FUN_080c4450(struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_066);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

INCASM("asm/vfx/unk_66.inc");

// --------------------------------------------

void nop_080c4668(struct VFX* p);
void FUN_080c466c(struct VFX* p);
void FUN_080c47e0(struct VFX* p);

static const VFXFunc sUpdates[3] = {
    nop_080c4668,
    FUN_080c466c,
    FUN_080c47e0,
};

const s32 s32_ARRAY_0836f5cc[24] = {
    0x00000120, 0x00000260, -0x000000B0, 0x000001A0, -0x000000B0, 0x00000260, 0x00000120, 0x000001A0, -0x000000B0, 0x000001A0, -0x000000B0, 0x00000260, 0x00000120, 0x000001A0, 0x00000120, 0x00000260, -0x000000B0, 0x00000260, 0x00000120, 0x000001A0, 0x00000120, 0x00000260, -0x000000B0, 0x000001A0,
};

const s32* const PTR_ARRAY_0836f62c[3] = {
    &s32_ARRAY_0836f5cc[0],
    &s32_ARRAY_0836f5cc[8],
    &s32_ARRAY_0836f5cc[16],
};
