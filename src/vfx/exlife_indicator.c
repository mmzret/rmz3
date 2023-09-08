#include "gfx.h"
#include "global.h"
#include "task.h"
#include "vfx.h"

static const motion_t sMotions[10];

void FUN_080be5d0(struct Sprite* s, struct DrawPivot* c);

static void ExlifeIndicator_Init(struct VFX* vfx);
void ExlifeIndicator_Update(struct VFX* vfx);
void ExlifeIndicator_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gExlifeIndicatorRoutine = {
    [ENTITY_INIT] =      ExlifeIndicator_Init,
    [ENTITY_MAIN] =      ExlifeIndicator_Update,
    [ENTITY_DIE] =       ExlifeIndicator_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateExlifeIndicator(u8 extraLife) {
  struct VFX* vfx = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_EXLIFE_INDICATOR);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = extraLife;
  }
  return vfx;
}

static void ExlifeIndicator_Init(struct VFX* vfx) {
  SetTaskCallback((struct Task*)&(vfx->s).spr, FUN_080be5d0);
  (vfx->s).spr.sprites = (struct MetaspriteHeader*)vfx;
  (vfx->s).flags &= ~OAM_PRIO;
  (vfx->s).flags |= DISPLAY;
  LOAD_STATIC_GRAPHIC(60);
  (vfx->s).coord.x = PIXEL(0);
  (vfx->s).coord.y = PIXEL(148);
  SET_VFX_ROUTINE(vfx, ENTITY_MAIN);
  (vfx->s).work[2] = 0;
  ExlifeIndicator_Update(vfx);
}

INCASM("asm/vfx/exlife_indicator.inc");

// clang-format off
static const motion_t sMotions[10] = {
    MOTION(0x3C, 0x00),
    MOTION(0x3C, 0x01),
    MOTION(0x3C, 0x02),
    MOTION(0x3C, 0x03),
    MOTION(0x3C, 0x04),
    MOTION(0x3C, 0x05),
    MOTION(0x3C, 0x06),
    MOTION(0x3C, 0x07),
    MOTION(0x3C, 0x08),
    MOTION(0x3C, 0x09),
};
// clang-format on
