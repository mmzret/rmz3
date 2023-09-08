#include "vfx.h"
#include "global.h"

INCASM("asm/vfx/unk_33.inc");

void Ghost33_Init(struct VFX* p);
void Ghost33_Update(struct VFX* p);
void Ghost33_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost33Routine = {
    [ENTITY_INIT] =      Ghost33_Init,
    [ENTITY_MAIN] =      Ghost33_Update,
    [ENTITY_DIE] =       Ghost33_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080bba18(struct VFX* p);
void FUN_080bba8c(struct VFX* p);
void FUN_080bbb30(struct VFX* p);
void FUN_080bbbd4(struct VFX* p);

static const VFXFunc sUpdates[4] = {
    FUN_080bba18,
    FUN_080bba8c,
    FUN_080bbb30,
    FUN_080bbbd4,
};

static const u8 sInitModes[4] = {0, 1, 2, 3};

static const motion_t sMotions[3] = {
    MOTION(SM040_SNAKECORD, 0x01),
    MOTION(SM040_SNAKECORD, 0x00),
    MOTION(SM040_SNAKECORD, 0x00),
};
