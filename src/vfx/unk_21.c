#include "entity.h"
#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_21.inc");

void Ghost21_Init(struct VFX *p);
void Ghost21_Update(struct VFX *p);
void Ghost21_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost21Routine = {
    [ENTITY_INIT] =      Ghost21_Init,
    [ENTITY_MAIN] =      Ghost21_Update,
    [ENTITY_DIE] =       Ghost21_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080b788c(struct VFX *p);
void FUN_080b7890(struct VFX *p);
void FUN_080b7a04(struct VFX *p);

const VFXFunc sUpdates[3] = {
    nop_080b788c,
    FUN_080b7890,
    FUN_080b7a04,
};

// --------------------------------------------

const s32 s32_ARRAY_0836e964[8 * 3] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

const s32 *const PTR_s32_ARRAY_0836e9c4[3] = {
    &s32_ARRAY_0836e964[0],
    &s32_ARRAY_0836e964[8],
    &s32_ARRAY_0836e964[16],
};
