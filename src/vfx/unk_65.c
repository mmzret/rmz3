#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_65.inc");

void Ghost65_Init(struct VFX* p);
void Ghost65_Update(struct VFX* p);
void Ghost65_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost65Routine = {
    [ENTITY_INIT] =      Ghost65_Init,
    [ENTITY_MAIN] =      Ghost65_Update,
    [ENTITY_DIE] =       Ghost65_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c4320(struct VFX* p);

const VFXFunc sGhost65Updates[1] = {
    FUN_080c4320,
};

const u8 u8_ARRAY_0836f59c[2] = {0, 0};

// clang-format off
const motion_t sGhost65Motions[6] = {
  MOTION(0x74, 0x09),
  MOTION(0x74, 0x0A),
  MOTION(0x74, 0x0B),
  MOTION(0x74, 0x0C),
  MOTION(0x74, 0x0D),
  MOTION(0x74, 0x08),
};
// clang-format on
