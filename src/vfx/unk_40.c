#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_40.inc");

void VFX40_Init(struct VFX* vfx);
void VFX40_Update(struct VFX* vfx);
void VFX40_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX40Routine = {
    [ENTITY_INIT] =      VFX40_Init,
    [ENTITY_MAIN] =      VFX40_Update,
    [ENTITY_DIE] =       VFX40_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080bdc1c(struct VFX* vfx);
void FUN_080bdc74(struct VFX* vfx);

const VFXFunc PTR_ARRAY_0836eed4[2] = {
    FUN_080bdc1c,
    FUN_080bdc74,
};

static const u8 u8_ARRAY_0836eedc[2] = {0, 1};

static const motion_t sMotions[3] = {
    MOTION(0xa7, 0x3a),
    MOTION(0xa7, 0x3b),
    MOTION(0xa7, 0x3b),
};
