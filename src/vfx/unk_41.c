#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_41.inc");

void VFX41_Init(struct VFX* vfx);
void VFX41_Update(struct VFX* vfx);
void VFX41_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX41Routine = {
    [ENTITY_INIT] =      VFX41_Init,
    [ENTITY_MAIN] =      VFX41_Update,
    [ENTITY_DIE] =       VFX41_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080be020(struct VFX* vfx);
void FUN_080be154(struct VFX* vfx);
void FUN_080be230(struct VFX* vfx);
void FUN_080be330(struct VFX* vfx);

const VFXFunc PTR_ARRAY_0836eef8[4] = {
    FUN_080be020,
    FUN_080be154,
    FUN_080be230,
    FUN_080be330,
};

static const s32 s32_ARRAY_ARRAY_0836ef08[8 * 3] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

static const s32* const PTR_ARRAY_0836ef68[3] = {
    &s32_ARRAY_ARRAY_0836ef08[0],
    &s32_ARRAY_ARRAY_0836ef08[8],
    &s32_ARRAY_ARRAY_0836ef08[16],
};

static const motion_t motion_t_ARRAY_0836ef74[3] = {
    MOTION(0xA9, 0x09),
    MOTION(0xA9, 0x08),
    MOTION(0xA9, 0x07),
};

static const motion_t motion_t_ARRAY_0836ef7a[3] = {
    MOTION(0xA9, 0x0D),
    MOTION(0xA9, 0x0C),
    MOTION(0xA9, 0x0B),
};
