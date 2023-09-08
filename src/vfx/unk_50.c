#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_50.inc");

void VFX50_Init(struct VFX* vfx);
void VFX50_Update(struct VFX* vfx);
void VFX50_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX50Routine = {
    [ENTITY_INIT] =      VFX50_Init,
    [ENTITY_MAIN] =      VFX50_Update,
    [ENTITY_DIE] =       VFX50_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c094c(struct VFX* vfx);
void FUN_080c09c8(struct VFX* vfx);

static const VFXFunc sUpdates[2] = {
    FUN_080c094c,
    FUN_080c09c8,
};

static const motion_t sMotions[3] = {
    MOTION(0xB1, 0x09),
    MOTION(0xB1, 0x0A),
    MOTION(0xB1, 0x0B),
};
