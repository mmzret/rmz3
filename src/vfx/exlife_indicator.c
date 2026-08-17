#include "gfx.h"
#include "global.h"
#include "renderer.h"
#include "vfx.h"

// Z x (残機数) の表示

static void TaskCB_080be5d0(struct Sprite* s, struct DrawPivot* c);

static void ExlifeIndicator_Init(struct Entity* p);
static void ExlifeIndicator_Update(struct VFX* vfx);
static void ExlifeIndicator_Die(struct Entity* p);

// clang-format off
const VFXRoutine gExlifeIndicatorRoutine = {
    [ENTITY_INIT] =      (VFXFunc)ExlifeIndicator_Init,
    [ENTITY_UPDATE] =    (VFXFunc)ExlifeIndicator_Update,
    [ENTITY_DIE] =       (VFXFunc)ExlifeIndicator_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

Entity* CreateExlifeIndicator(u8 extraLife) {
  Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_EXLIFE_INDICATOR);
    p->work[0] = extraLife;
  }
  return p;
}

static void ExlifeIndicator_Init(struct Entity* p) {
  SetTaskCallback((void*)&p->spr, TaskCB_080be5d0);
  (p->spr).sprites = (struct MetaspriteHeader*)p;
  p->flags &= ~USE_COMMON_OAM_RENDERER;
  p->flags |= DISPLAY;
  LOAD_STATIC_GRAPHIC(SM060_EXLIFE_INDICATOR);
  (p->coord).x = PIXEL(0), (p->coord).y = PIXEL(148);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->work[2] = 0;
  ExlifeIndicator_Update((void*)p);
}

static void ExlifeIndicator_Update(struct VFX* vfx) {
  register u8 told asm("r4");
  u32 tw;
  u8 t;
  s32 x;
  told = (vfx->s).work[2];
  tw = told + 1;
  asm("" : "+l"(told));
  (vfx->s).work[2] = tw;
  t = (u8)tw;
  if (t <= 0x20) {
    x = SIN(tw * 2) * 0xDC;
    goto store;
  }
  if (t > 0x7E) {
    x = 0xDC * 0x200 - 0xDC * SIN((u8)(told * 2 + 0x42));
  store:
    (vfx->s).coord.x = x;
  }
  asm volatile("" ::"l"(told));
  if ((vfx->s).work[2] == 0xA0) {
    SET_VFX_ROUTINE(vfx, ENTITY_DIE);
  }
}

static void ExlifeIndicator_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

static void TaskCB_080be5d0(struct Sprite* s, struct DrawPivot* c) {
  // clang-format off
  static const motion_t sMotions[10] = {
    MOTION(SM060_EXLIFE_INDICATOR, 0), // Zx0
    MOTION(SM060_EXLIFE_INDICATOR, 1), // Zx1
    MOTION(SM060_EXLIFE_INDICATOR, 2), // Zx2
    MOTION(SM060_EXLIFE_INDICATOR, 3), // Zx3
    MOTION(SM060_EXLIFE_INDICATOR, 4), // Zx4
    MOTION(SM060_EXLIFE_INDICATOR, 5), // Zx5
    MOTION(SM060_EXLIFE_INDICATOR, 6), // Zx6
    MOTION(SM060_EXLIFE_INDICATOR, 7), // Zx7
    MOTION(SM060_EXLIFE_INDICATOR, 8), // Zx8
    MOTION(SM060_EXLIFE_INDICATOR, 9), // Zx9
  };
  // clang-format on
  struct VFX* p = (struct VFX*)s->sprites;
  Coords32 coord;
  coord.x = (p->s).coord.x - PIXEL(120);
  coord.x += (c->coord).x;
  coord.y = (p->s).coord.y - PIXEL(80);
  coord.y += (c->coord).y;
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, sMotions[(p->s).work[0]]);
  (p->s).spr.oam.priority = 0;
  UpdateSpriteAnimation(p);
  (p->s).spr.c = &coord;
  (s->fn)(s, c);
  SetTaskCallback((void*)&(p->s).spr, TaskCB_080be5d0);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~USE_COMMON_OAM_RENDERER;
}
