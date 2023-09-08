#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_58.inc");

void VFX58_Init(struct VFX* vfx);
void VFX58_Update(struct VFX* vfx);
void VFX58_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX58Routine = {
    [ENTITY_INIT] =      VFX58_Init,
    [ENTITY_MAIN] =      VFX58_Update,
    [ENTITY_DIE] =       VFX58_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c2124(struct VFX* vfx);
void FUN_080c216c(struct VFX* vfx);
void FUN_080c21c0(struct VFX* vfx);
void FUN_080c2294(struct VFX* vfx);
void FUN_080c2364(struct VFX* vfx);
void FUN_080c2390(struct VFX* vfx);
void FUN_080c248c(struct VFX* vfx);
void FUN_080c2500(struct VFX* vfx);
void FUN_080c25f4(struct VFX* vfx);

// clang-format off
static const VFXFunc sUpdates[9] = {
    FUN_080c2124,
    FUN_080c216c,
    FUN_080c21c0,
    FUN_080c2294,
    FUN_080c2364,
    FUN_080c2390,
    FUN_080c248c,
    FUN_080c2500,
    FUN_080c25f4,
};
// clang-format on

static const s32 s32_ARRAY_0836f290[8 * 3] = {
    0x000002C0, -0x00000300, -0x00000220, -0x00000260, -0x00000220, -0x00000300, 0x000002C0, -0x00000260, -0x00000100, -0x000001F0, -0x00000200, -0x00000280, 0x00000160, -0x000001F0, 0x00000260, -0x00000280, -0x000000B0, -0x00000340, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0,
};

const s32* const PTR_s32_ARRAY_0836f2f0[3] = {
    &s32_ARRAY_0836f290[0],
    &s32_ARRAY_0836f290[8],
    &s32_ARRAY_0836f290[16],
};
