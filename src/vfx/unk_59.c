#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_59.inc");

void VFX59_Init(struct VFX* vfx);
void VFX59_Update(struct VFX* vfx);
void VFX59_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX59Routine = {
    [ENTITY_INIT] =      VFX59_Init,
    [ENTITY_MAIN] =      VFX59_Update,
    [ENTITY_DIE] =       VFX59_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080c28fc(struct VFX* vfx);
void FUN_080c2900(struct VFX* vfx);
void FUN_080c2a78(struct VFX* vfx);

static const VFXFunc sUpdates[3] = {
    nop_080c28fc,
    FUN_080c2900,
    FUN_080c2a78,
};

static const s32 s32_ARRAY_0836f31c[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

const s32* const PTR_s32_ARRAY_0836f37c[3] = {
    &s32_ARRAY_0836f31c[0],
    &s32_ARRAY_0836f31c[8],
    &s32_ARRAY_0836f31c[16],
};
