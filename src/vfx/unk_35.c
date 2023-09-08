#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_35.inc");

void Ghost35_Init(struct VFX* p);
void Ghost35_Update(struct VFX* p);
void Ghost35_Die(struct VFX* p);

// clang-format off
const VFXRoutine gVFX35Routine = {
    [ENTITY_INIT] =      Ghost35_Init,
    [ENTITY_MAIN] =      Ghost35_Update,
    [ENTITY_DIE] =       Ghost35_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080bbf8c(struct VFX* vfx);

const VFXFunc PTR_ARRAY_0836ed9c[1] = {
    FUN_080bbf8c,
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
