#include "entity.h"
#include "vfx.h"
#include "global.h"

void Ghost20_Init(struct VFX *p);
void Ghost20_Update(struct VFX *p);
void Ghost20_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost20Routine = {
    [ENTITY_INIT] =      Ghost20_Init,
    [ENTITY_UPDATE] =    Ghost20_Update,
    [ENTITY_DIE] =       Ghost20_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *CreateGhost20(struct Coord *c, u8 n) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_020);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

INCASM("asm/vfx/unk_20.inc");

// --------------------------------------------

void FUN_080b73d0(struct VFX *p);
void FUN_080b73d4(struct VFX *p);
void FUN_080b754c(struct VFX *p);

const VFXFunc sGhost20Updates[3] = {
    FUN_080b73d0,
    FUN_080b73d4,
    FUN_080b754c,
};

const s32 s32_ARRAY_0836e8d8[8 * 3] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

const s32 *const PTR_s32_ARRAY_0836e938[3] = {
    &s32_ARRAY_0836e8d8[0],
    &s32_ARRAY_0836e8d8[8],
    &s32_ARRAY_0836e8d8[16],
};
