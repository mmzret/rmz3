#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_60.inc");

void VFX60_Init(struct VFX* vfx);
void VFX60_Update(struct VFX* vfx);
void VFX60_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX60Routine = {
    [ENTITY_INIT] =      VFX60_Init,
    [ENTITY_UPDATE] =    VFX60_Update,
    [ENTITY_DIE] =       VFX60_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void nop_080c2d44(struct VFX* vfx);
void FUN_080c2d48(struct VFX* vfx);

static const VFXFunc sUpdates[2] = {
    nop_080c2d44,
    FUN_080c2d48,
};

static const s32 s32_ARRAY_0836f3a4[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

const s32* const PTR_s32_ARRAY_0836f404[3] = {
    &s32_ARRAY_0836f3a4[0],
    &s32_ARRAY_0836f3a4[8],
    &s32_ARRAY_0836f3a4[16],
};
