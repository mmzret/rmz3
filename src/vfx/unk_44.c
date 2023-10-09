#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_44.inc");

void VFX44_Init(struct VFX* vfx);
void VFX44_Update(struct VFX* vfx);
void VFX44_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX44Routine = {
    [ENTITY_INIT] =      VFX44_Init,
    [ENTITY_UPDATE] =    VFX44_Update,
    [ENTITY_DIE] =       VFX44_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080be974(struct VFX* vfx);

static const VFXFunc sUpdates[1] = {
    FUN_080be974,
};
