#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_46.inc");

void VFX46_Init(struct VFX* vfx);
void VFX46_Update(struct VFX* vfx);
void VFX46_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX46Routine = {
    [ENTITY_INIT] =      VFX46_Init,
    [ENTITY_MAIN] =      VFX46_Update,
    [ENTITY_DIE] =       VFX46_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080bef44(struct VFX* vfx);
void FUN_080bf0a0(struct VFX* vfx);
void FUN_080bf17c(struct VFX* vfx);
void FUN_080bf2f0(struct VFX* vfx);

static const VFXFunc sUpdates[4] = {
    FUN_080bef44,
    FUN_080bf0a0,
    FUN_080bf17c,
    FUN_080bf2f0,
};

// clang-format off
static const s32 s32_ARRAY_ARRAY_0836f02c[5][8] = {
    {0x00000120, -0x00000400, -0x000000B0, -0x00000360, -0x000000B0, -0x00000400, 0x00000120, -0x00000260},
    {-0x000000B0, -0x00000260, -0x000000B0, -0x00000400, 0x00000120, -0x00000260, 0x00000120, -0x00000400},
    {-0x000000B0, -0x00000400, 0x00000120, -0x00000360, 0x00000120, -0x00000400, -0x000000B0, -0x00000360},
    {0x00000160, -0x00000260, -0x000000C0, -0x00000400, 0x00000160, -0x00000400, -0x000000C0, -0x00000260},
    {-0x000000E0, -0x00000400, 0x00000180, -0x00000360, -0x000000E0, -0x00000360, 0x00000180, -0x00000400},
};
// clang-format on

static const s32* const PTR_ARRAY_0836f0cc[5] = {
    s32_ARRAY_ARRAY_0836f02c[0], s32_ARRAY_ARRAY_0836f02c[1], s32_ARRAY_ARRAY_0836f02c[2], s32_ARRAY_ARRAY_0836f02c[3], s32_ARRAY_ARRAY_0836f02c[4],
};
