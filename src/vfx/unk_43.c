#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_43.inc");

void VFX43_Init(struct VFX* vfx);
void VFX43_Update(struct VFX* vfx);
void VFX43_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX43Routine = {
    [ENTITY_INIT] =      VFX43_Init,
    [ENTITY_UPDATE] =    VFX43_Update,
    [ENTITY_DIE] =       VFX43_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080be72c(struct VFX* vfx);

const VFXFunc PTR_ARRAY_0836efbc[1] = {
    FUN_080be72c,
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[4] = {
    MOTION(0x39, 0x04),
    MOTION(0x39, 0x05),
    MOTION(0x39, 0x06),
    MOTION(0x39, 0x06),
};
