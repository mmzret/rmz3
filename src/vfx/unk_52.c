#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_52.inc");

void VFX52_Init(struct VFX* vfx);
void VFX52_Update(struct VFX* vfx);
void VFX52_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX52Routine = {
    [ENTITY_INIT] =      VFX52_Init,
    [ENTITY_UPDATE] =    VFX52_Update,
    [ENTITY_DIE] =       VFX52_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on
