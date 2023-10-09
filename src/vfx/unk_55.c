#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_55.inc");

void VFX55_Init(struct VFX* vfx);
void VFX55_Update(struct VFX* vfx);
void VFX55_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX55Routine = {
    [ENTITY_INIT] =      VFX55_Init,
    [ENTITY_UPDATE] =    VFX55_Update,
    [ENTITY_DIE] =       VFX55_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c11e0(struct VFX* vfx);
void FUN_080c123c(struct VFX* vfx);
void FUN_080c12b0(struct VFX* vfx);

static const VFXFunc sInitializers[3] = {
    FUN_080c11e0,
    FUN_080c123c,
    FUN_080c12b0,
};

// --------------------------------------------

void FUN_080c1328(struct VFX* vfx);
void FUN_080c13c8(struct VFX* vfx);
void FUN_080c143c(struct VFX* vfx);

static const VFXFunc sUpdates[3] = {
    FUN_080c1328,
    FUN_080c13c8,
    FUN_080c143c,
};
