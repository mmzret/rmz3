#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_56.inc");

void VFX56_Init(struct VFX* vfx);
void VFX56_Update(struct VFX* vfx);
void VFX56_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX56Routine = {
    [ENTITY_INIT] =      VFX56_Init,
    [ENTITY_MAIN] =      VFX56_Update,
    [ENTITY_DIE] =       VFX56_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c15d4(struct VFX* vfx);
void FUN_080c161c(struct VFX* vfx);
void FUN_080c16fc(struct VFX* vfx);

static const VFXFunc sInitializers[3] = {
    FUN_080c15d4,
    FUN_080c161c,
    FUN_080c16fc,
};

// --------------------------------------------

void FUN_080c17e8(struct VFX* vfx);
void FUN_080c182c(struct VFX* vfx);
void FUN_080c188c(struct VFX* vfx);

static const VFXFunc sUpdates[3] = {
    FUN_080c17e8,
    FUN_080c182c,
    FUN_080c188c,
};
