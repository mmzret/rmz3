#include "vfx.h"
#include "global.h"
#include "solid.h"

static void Ghost29_Init(struct VFX *p);
void Ghost29_Update(struct VFX *p);
void Ghost29_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost29Routine = {
    [ENTITY_INIT] =      Ghost29_Init,
    [ENTITY_MAIN] =      Ghost29_Update,
    [ENTITY_DIE] =       Ghost29_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

static void Ghost29_Init(struct VFX *p) {
  (p->s).flags |= FLIPABLE;
  FUN_080cb4c0((struct Solid *)p);
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  Ghost29_Update(p);
}

INCASM("asm/vfx/unk_29.inc");
