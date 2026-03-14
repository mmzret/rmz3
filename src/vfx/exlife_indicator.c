#include "gfx.h"
#include "global.h"
#include "task.h"
#include "vfx.h"

static const motion_t sMotions[10];

static void TaskCB_080be5d0(struct Sprite* s, struct DrawPivot* c);

static void ExlifeIndicator_Init(struct VFX* vfx);
void ExlifeIndicator_Update(struct VFX* vfx);
static void ExlifeIndicator_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gExlifeIndicatorRoutine = {
    [ENTITY_INIT] =      ExlifeIndicator_Init,
    [ENTITY_UPDATE] =    ExlifeIndicator_Update,
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
  SetTaskCallback((struct Task*)&(vfx->s).spr, TaskCB_080be5d0);
  (vfx->s).spr.sprites = (struct MetaspriteHeader*)vfx;
  (vfx->s).flags &= ~OAM_PRIO;
  (vfx->s).flags |= DISPLAY;
  LOAD_STATIC_GRAPHIC(SM060_EXLIFE_INDICATOR);
  (vfx->s).coord.x = PIXEL(0);
  (vfx->s).coord.y = PIXEL(148);
  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  (vfx->s).work[2] = 0;
  ExlifeIndicator_Update(vfx);
}

INCASM("asm/vfx/exlife_indicator.inc");

static void ExlifeIndicator_Die(struct VFX* vfx) {
  (vfx->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}

static void TaskCB_080be5d0(struct Sprite* s, struct DrawPivot* c) {
  // clang-format off
  static const motion_t sMotions[10] = {
    MOTION(SM060_EXLIFE_INDICATOR, 0x00),
    MOTION(SM060_EXLIFE_INDICATOR, 0x01),
    MOTION(SM060_EXLIFE_INDICATOR, 0x02),
    MOTION(SM060_EXLIFE_INDICATOR, 0x03),
    MOTION(SM060_EXLIFE_INDICATOR, 0x04),
    MOTION(SM060_EXLIFE_INDICATOR, 0x05),
    MOTION(SM060_EXLIFE_INDICATOR, 0x06),
    MOTION(SM060_EXLIFE_INDICATOR, 0x07),
    MOTION(SM060_EXLIFE_INDICATOR, 0x08),
    MOTION(SM060_EXLIFE_INDICATOR, 0x09),
  };
  // clang-format on
  struct VFX* p = (struct VFX*)s->sprites;
  struct Coord coord;
  coord.x = (p->s).coord.x - PIXEL(120);
  coord.x += (c->coord).x;
  coord.y = (p->s).coord.y - PIXEL(80);
  coord.y += (c->coord).y;
  InitNonAffineMotion((struct Entity*)p);
  SetMotion((struct Entity*)p, sMotions[(p->s).work[0]]);
  (p->s).spr.oam.priority = 0;
  UpdateMotionGraphic((struct Entity*)p);
  (p->s).spr.c = &coord;
  (s->fn)(s, c);
  SetTaskCallback((struct Task*)&(p->s).spr, TaskCB_080be5d0);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~OAM_PRIO;
}
