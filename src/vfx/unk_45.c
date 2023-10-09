#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_45.inc");

void VFX45_Init(struct VFX* vfx);
void VFX45_Update(struct VFX* vfx);
void VFX45_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX45Routine = {
    [ENTITY_INIT] =      VFX45_Init,
    [ENTITY_UPDATE] =    VFX45_Update,
    [ENTITY_DIE] =       VFX45_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080beb54(struct VFX* vfx);

static const VFXFunc PTR_ARRAY_0836eff8[1] = {
    FUN_080beb54,
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[4] = {
    MOTION(0x40, 0x01),
    MOTION(0x40, 0x02),
    MOTION(0x40, 0x06),
    MOTION(0x40, 0x07),
};
