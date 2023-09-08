#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_39.inc");

void VFX39_Init(struct VFX* vfx);
void VFX39_Update(struct VFX* vfx);
void VFX39_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX39Routine = {
    [ENTITY_INIT] =      VFX39_Init,
    [ENTITY_MAIN] =      VFX39_Update,
    [ENTITY_DIE] =       VFX39_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080bd48c(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);

const VFXFunc PTR_ARRAY_0836eeb0[4] = {
    FUN_080bd48c,
    FUN_080bd578,
    FUN_080bd578,
    FUN_080bd578,
};
