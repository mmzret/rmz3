#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_65.inc");

void Ghost65_Init(struct VFX* vfx);
void Ghost65_Update(struct VFX* vfx);
void Ghost65_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gGhost65Routine = {
    [ENTITY_INIT] =      Ghost65_Init,
    [ENTITY_UPDATE] =    Ghost65_Update,
    [ENTITY_DIE] =       Ghost65_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c4320(struct VFX* vfx);

static const VFXFunc sUpdates[1] = {
    FUN_080c4320,
};

const u8 u8_ARRAY_0836f59c[2] = {0, 0};

// clang-format off
static const motion_t sMotions[6] = {
  MOTION(SM116_DEATHLOCK, 0x09),
  MOTION(SM116_DEATHLOCK, 0x0A),
  MOTION(SM116_DEATHLOCK, 0x0B),
  MOTION(SM116_DEATHLOCK, 0x0C),
  MOTION(SM116_DEATHLOCK, 0x0D),
  MOTION(SM116_DEATHLOCK, 0x08),
};
// clang-format on
