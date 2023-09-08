#include "global.h"
#include "vfx.h"

static const motion_t sMotions[3];

INCASM("asm/vfx/unk_62.inc");

void VFX62_Init(struct VFX* vfx);
void VFX62_Update(struct VFX* vfx);
void VFX62_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX62Routine = {
    [ENTITY_INIT] =      VFX62_Init,
    [ENTITY_MAIN] =      VFX62_Update,
    [ENTITY_DIE] =       VFX62_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080c3574(struct VFX* vfx);

static const VFXFunc sInitializers[1] = {
    FUN_080c3574,
};

void FUN_080c3678(struct VFX* vfx);

static const VFXFunc sUpdates[1] = {
    FUN_080c3678,
};

static const motion_t sMotions[3] = {
    MOTION(SM221_METTAUR, 16),
    MOTION(SM221_METTAUR, 16),
    MOTION(SM221_METTAUR, 17),
};
