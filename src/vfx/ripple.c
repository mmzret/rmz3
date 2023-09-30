#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "vfx.h"
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

NON_MATCH struct VFX* CreateRipple(struct Zero* z, bool8 outOfSea) {
#if MODERN
  bool8 yflip;
  struct VFX* vfx = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_RIPPLE);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).unk_28 = &z->s;
    if (outOfSea) {
      (vfx->s).flags |= Y_FLIP;
    } else {
      (vfx->s).flags &= ~Y_FLIP;
    }
    yflip = outOfSea & 1;
    (vfx->s).spr.yflip = yflip;
    (vfx->s).spr.oam.yflip = yflip;
    (vfx->s).work[0] = 0;
    (vfx->s).work[1] = 0;
    z->ripple = TRUE;
  }
  return vfx;
#else
  INCCODE("asm/wip/CreateRipple.inc");
#endif
}

NON_MATCH static void Ripple_Init(struct VFX* p) {
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
