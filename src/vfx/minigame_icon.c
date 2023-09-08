#include "entity.h"
#include "vfx.h"
#include "global.h"

void Ghost77_Init(struct VFX *p);
void Ghost77_Update(struct VFX *p);
void Ghost77_Die(struct VFX *p);

// clang-format off
const VFXRoutine gMinigameIconRoutine = {
    [ENTITY_INIT] =      Ghost77_Init,
    [ENTITY_MAIN] =      Ghost77_Update,
    [ENTITY_DIE] =       Ghost77_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *CreateMinigameIcon_1(struct Coord *c, u8 n) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 0;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

INCASM("asm/vfx/minigame_icon.inc");

// --------------------------------------------

void FUN_080c843c(struct VFX *p);
void FUN_080c8488(struct VFX *p);
void FUN_080c8628(struct VFX *p);
void FUN_080c8684(struct VFX *p);
void FUN_080c8744(struct VFX *p);

// clang-format off
static const VFXFunc sUpdates[5] = {
    FUN_080c843c,
    FUN_080c8488,
    FUN_080c8628,
    FUN_080c8684,
    FUN_080c8744,
};
// clang-format on

// --------------------------------------------

const motion_t motion_t_ARRAY_0836f998[3] = {
    MOTION(0x0E, 0x08),
    MOTION(0x0E, 0x07),
    MOTION(0x0E, 0x09),
};
