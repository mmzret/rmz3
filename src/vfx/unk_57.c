#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_57.inc");

void VFX57_Init(struct VFX* vfx);
void VFX57_Update(struct VFX* vfx);
void VFX57_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX57Routine = {
    [ENTITY_INIT] =      VFX57_Init,
    [ENTITY_UPDATE] =    VFX57_Update,
    [ENTITY_DIE] =       VFX57_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on
