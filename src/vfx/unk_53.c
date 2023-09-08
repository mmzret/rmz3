#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_53.inc");

void VFX53_Init(struct VFX* vfx);
void VFX53_Update(struct VFX* vfx);
void VFX53_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX53Routine = {
    [ENTITY_INIT] =      VFX53_Init,
    [ENTITY_MAIN] =      VFX53_Update,
    [ENTITY_DIE] =       VFX53_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on
