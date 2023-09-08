#include "entity.h"
#include "vfx.h"
#include "global.h"
#include "overworld.h"
#include "zero.h"

/*
  水の波紋？
*/

static void Ripple_Init(struct VFX* p);
void Ripple_Update(struct VFX* p);
void Ripple_Die(struct VFX* p);
void Ripple_Disappear(struct VFX* p);

// clang-format off
const VFXRoutine gRippleRoutine = {
    [ENTITY_INIT] =      Ripple_Init,
    [ENTITY_MAIN] =      Ripple_Update,
    [ENTITY_DIE] =       Ripple_Die,
    [ENTITY_DISAPPEAR] = Ripple_Disappear,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

WIP struct VFX* CreateRipple(struct Zero* z, bool8 outOfSea) {
#if MODERN
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_RIPPLE);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).unk_28 = &z->s;
    if (outOfSea) {
      (g->s).flags |= Y_FLIP;
    } else {
      (g->s).flags &= ~Y_FLIP;
    }
    (g->s).spr.oam.yflip = (g->s).spr.yflip = outOfSea;
    (g->s).work[0] = 0;
    (g->s).work[1] = 0;
    z->ripple = 1;
  }
  return g;
#else
  INCCODE("asm/wip/CreateRipple.inc");
#endif
}

WIP static void Ripple_Init(struct VFX* p) {
#if MODERN
  struct Zero* z = (struct Zero*)(p->s).unk_28;
  InitNonAffineMotion(&p->s);
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x13));
  (p->s).flags |= DISPLAY;
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;
  if (!((z->body).status & BODY_STATUS_DEAD) && ((z->body).hp != 0)) {
    PlaySound(SE_WATER_SURFACE);
  }
  (p->s).coord.x = (z->s).coord.x;
  (p->s).coord.y = SEA;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  Ripple_Update(p);
#else
  INCCODE("asm/wip/Ripple_Init.inc");
#endif
}

INCASM("asm/vfx/ripple.inc");
