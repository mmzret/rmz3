#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_36.inc");

void VFX36_Init(struct VFX* vfx);
void VFX36_Update(struct VFX* vfx);
void VFX36_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX36Routine = {
    [ENTITY_INIT] =      VFX36_Init,
    [ENTITY_UPDATE] =    VFX36_Update,
    [ENTITY_DIE] =       VFX36_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080bc200(struct VFX* vfx);
void FUN_080bc464(struct VFX* vfx);

const VFXFunc PTR_ARRAY_0836edb8[2] = {
    FUN_080bc200,
    FUN_080bc464,
};
