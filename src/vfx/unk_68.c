#include "entity.h"
#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_68.inc");

void FUN_080c4d30(struct VFX* p);
void FUN_080c4db8(struct VFX* p);

const VFXFunc sGhost68Initializers[2] = {
    FUN_080c4d30,
    FUN_080c4db8,
};

void FUN_080c4d60(struct VFX* p);
void FUN_080c4de8(struct VFX* p);

const VFXFunc sGhost68Updates[2] = {
    FUN_080c4d60,
    FUN_080c4de8,
};

// --------------------------------------------

void Ghost68_Init(struct VFX* p);
void Ghost68_Update(struct VFX* p);
void Ghost68_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost68Routine = {
    [ENTITY_INIT] =      Ghost68_Init,
    [ENTITY_UPDATE] =    Ghost68_Update,
    [ENTITY_DIE] =       Ghost68_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on
