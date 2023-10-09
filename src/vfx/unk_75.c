#include "entity.h"
#include "global.h"
#include "vfx.h"

void Ghost75_Init(struct VFX *p);
void Ghost75_Update(struct VFX *p);
void Ghost75_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost75Routine = {
    [ENTITY_INIT] =      Ghost75_Init,
    [ENTITY_UPDATE] =    Ghost75_Update,
    [ENTITY_DIE] =       Ghost75_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *FUN_080c7518(struct Coord *c, u8 n) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_075);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX *FUN_080c7570(struct Coord *c, u8 n, u16 r2, void *r3) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_075);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 1;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->props).unk28.unk_0 = r2;
    (p->props).unk28.unk_4 = (s32)r3;
  }
  return p;
}

INCASM("asm/vfx/unk_75.inc");

// --------------------------------------------

void nop_080c76fc(struct VFX *p);
void FUN_080c7700(struct VFX *p);
void FUN_080c77f0(struct VFX *p);

static const VFXFunc sUpdates[3] = {
    nop_080c76fc,
    FUN_080c7700,
    FUN_080c77f0,
};

// --------------------------------------------

const s32 s32_ARRAY_0836f8c0[24] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

const s32 *const PTR_ARRAY_0836f920[3] = {
    &s32_ARRAY_0836f8c0[0],
    &s32_ARRAY_0836f8c0[8],
    &s32_ARRAY_0836f8c0[16],
};
