#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_34.inc");

void Ghost34_Init(struct VFX* p);
void Ghost34_Update(struct VFX* p);
void Ghost34_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost34Routine = {
    [ENTITY_INIT] =      Ghost34_Init,
    [ENTITY_UPDATE] =    Ghost34_Update,
    [ENTITY_DIE] =       Ghost34_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void nop_080bbe20(struct VFX* p);
void FUN_080bbe24(struct VFX* p);

static const VFXFunc sUpdates[2] = {
    nop_080bbe20,
    FUN_080bbe24,
};
