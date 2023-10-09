#include "entity.h"
#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_22.inc");

static const VFXFunc sUpdates[3];

void Ghost22_Init(struct VFX *p);
void Ghost22_Update(struct VFX *p);
void Ghost22_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost22Routine = {
    [ENTITY_INIT] =      Ghost22_Init,
    [ENTITY_UPDATE] =    Ghost22_Update,
    [ENTITY_DIE] =       Ghost22_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void nop_080b7d48(struct VFX *p);
void FUN_080b7d4c(struct VFX *p);
void FUN_080b7e3c(struct VFX *p);

static const VFXFunc sUpdates[3] = {
    nop_080b7d48,
    FUN_080b7d4c,
    FUN_080b7e3c,
};

const s32 s32_ARRAY_0836e9f0[24] = {
    0x00000120,  -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120,  -0x00000160,  // 0
    -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120,  -0x00000160, 0x00000120,  -0x00000200,  // 1
    -0x000000B0, -0x00000200, 0x00000120,  -0x00000160, 0x00000120,  -0x00000200, -0x000000B0, -0x00000160,  // 2
};

const s32 *const PTR_ARRAY_0836ea50[3] = {
    &s32_ARRAY_0836e9f0[0],
    &s32_ARRAY_0836e9f0[8],
    &s32_ARRAY_0836e9f0[16],
};
