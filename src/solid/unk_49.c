#include "collision.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/unk_49.inc");

void Solid49_Init(struct Solid* p);
void Solid49_Update(struct Solid* p);
void Solid49_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid49Routine = {
    [ENTITY_INIT] =      Solid49_Init,
    [ENTITY_MAIN] =      Solid49_Update,
    [ENTITY_DIE] =       Solid49_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// clang-format off
static const motion_t sMotions[5] = {
    MOTION(0xA2, 0x00),
    MOTION(0xA3, 0x00),
    MOTION(0xA4, 0x00),
    MOTION(0xA5, 0x00),
    MOTION(0xA6, 0x00),
};
// clang-format on

const u16 u16_ARRAY_08371892[5] = {
    91, 108, 108, 108, 91,
};
