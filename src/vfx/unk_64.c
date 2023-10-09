#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_64.inc");

void Ghost64_Init(struct VFX *p);
void Ghost64_Update(struct VFX *p);
void Ghost64_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost64Routine = {
    [ENTITY_INIT] =      Ghost64_Init,
    [ENTITY_UPDATE] =    Ghost64_Update,
    [ENTITY_DIE] =       Ghost64_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080c3cbc(struct VFX *p);
void FUN_080c3d84(struct VFX *p);
void FUN_080c3e98(struct VFX *p);
void FUN_080c3f1c(struct VFX *p);
void FUN_080c3f74(struct VFX *p);
void FUN_080c3ffc(struct VFX *p);
void FUN_080c4074(struct VFX *p);
void FUN_080c40ec(struct VFX *p);
void FUN_080c4144(struct VFX *p);

// clang-format off
static const VFXFunc sUpdates[9] = {
    FUN_080c3cbc,
    FUN_080c3d84,
    FUN_080c3e98,
    FUN_080c3f1c,
    FUN_080c3f74,
    FUN_080c3ffc,
    FUN_080c4074,
    FUN_080c40ec,
    FUN_080c4144,
};
// clang-format on

static const u8 sInitModes[7] = {8, 2, 3, 4, 5, 6, 7};
