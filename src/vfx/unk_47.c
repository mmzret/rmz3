#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_47.inc");

void VFX47_Init(struct VFX* vfx);
void VFX47_Update(struct VFX* vfx);
void VFX47_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX47Routine = {
    [ENTITY_INIT] =      VFX47_Init,
    [ENTITY_UPDATE] =    VFX47_Update,
    [ENTITY_DIE] =       VFX47_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080bf634(struct VFX* vfx);
void FUN_080bf6d8(struct VFX* vfx);
void FUN_080bf890(struct VFX* vfx);
void FUN_080bfa10(struct VFX* vfx);
void FUN_080bfa7c(struct VFX* vfx);
void FUN_080bfb54(struct VFX* vfx);

// clang-format off
static const VFXFunc PTR_ARRAY_0836f0f4[6] = {
    FUN_080bf634,
    FUN_080bf6d8,
    FUN_080bf890,
    FUN_080bfa10,
    FUN_080bfa7c,
    FUN_080bfb54,
};
// clang-format on

// --------------------------------------------

static const u8 sInitModes[5] = {
    0, 2, 3, 4, 5,
};

static const motion_t sMotions[3] = {
    MOTION(SM076_PANTHEON_ZOMBIE, 0x05),
    MOTION(SM076_PANTHEON_ZOMBIE, 0x0A),
    MOTION(SM076_PANTHEON_ZOMBIE, 0x09),
};
