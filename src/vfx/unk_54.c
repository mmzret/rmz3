#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_54.inc");

void VFX54_Init(struct VFX* vfx);
void VFX54_Update(struct VFX* vfx);
void VFX54_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX54Routine = {
    [ENTITY_INIT] =      VFX54_Init,
    [ENTITY_MAIN] =      VFX54_Update,
    [ENTITY_DIE] =       VFX54_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c0ff4(struct VFX* vfx);

static const VFXFunc PTR_ARRAY_0836f1e0[1] = {
    FUN_080c0ff4,
};

// --------------------------------------------

static const u8 sInitModes[2] = {0, 0};
static const motion_t sMotions[3] = {
    MOTION(SM090_ICICLE, 0x08),
    MOTION(SM090_ICICLE, 0x09),
    MOTION(SM090_ICICLE, 0x0A),
};
