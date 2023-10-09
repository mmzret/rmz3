#include "entity.h"
#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_67.inc");

void Ghost67_Init(struct VFX* p);
void Ghost67_Update(struct VFX* p);
void Ghost67_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost67Routine = {
    [ENTITY_INIT] =      Ghost67_Init,
    [ENTITY_UPDATE] =    Ghost67_Update,
    [ENTITY_DIE] =       Ghost67_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c4aac(struct VFX* p);

const VFXFunc sGhost67Updates[1] = {
    FUN_080c4aac,
};

const s32 s32_ARRAY_0836f650[24] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

const s32* const PTR_ARRAY_0836f6b0[3] = {
    &s32_ARRAY_0836f650[0],
    &s32_ARRAY_0836f650[8],
    &s32_ARRAY_0836f650[16],
};
