#include "collision.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/unk_49.inc");

void Solid49_Init(struct Solid* p);
void Solid49_Update(struct Solid* p);
void Solid49_Die(struct Solid* p);

// clang-format off
const SolidRoutine gGraffitiRoutine = {
    [ENTITY_INIT] =      Solid49_Init,
    [ENTITY_UPDATE] =    Solid49_Update,
    [ENTITY_DIE] =       Solid49_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// clang-format off
static const motion_t sMotions[5] = {
    MOTION(SM162_PAINTING_MMBN, 0),
    MOTION(SM163_GRAFFITI_ZERO1, 0),
    MOTION(SM164_GRAFFITI_CIEL, 0),
    MOTION(SM165_GRAFFITI_ZERO2, 0),
    MOTION(SM166_PAINTING_CIEL, 0),
};
// clang-format on

const u16 u16_ARRAY_08371892[5] = {
    91, 108, 108, 108, 91,
};
