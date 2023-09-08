#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_51.inc");

void VFX51_Init(struct VFX* vfx);
void VFX51_Update(struct VFX* vfx);
void VFX51_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX51Routine = {
    [ENTITY_INIT] =      VFX51_Init,
    [ENTITY_MAIN] =      VFX51_Update,
    [ENTITY_DIE] =       VFX51_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c0b68(struct VFX* vfx);

static const VFXFunc sUpdates[1] = {
    FUN_080c0b68,
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
