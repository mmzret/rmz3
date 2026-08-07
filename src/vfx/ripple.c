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
    [ENTITY_UPDATE] =    Ripple_Update,
    [ENTITY_DIE] =       Ripple_Die,
    [ENTITY_DISAPPEAR] = Ripple_Disappear,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct VFX* CreateRipple(struct Zero* z, bool8 outOfSea) {
  struct VFX* vfx = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (vfx != NULL) {
    INIT_VFX_ROUTINE(vfx, VFX_RIPPLE);
    (vfx->s).unk_28 = &z->s;
    {
      bool8 yflip = outOfSea;
      if (yflip) {
        (vfx->s).flags |= Y_FLIP;
      } else {
        (vfx->s).flags &= ~Y_FLIP;
      }
      (vfx->s).spr.yflip = yflip & 1;
      (vfx->s).spr.oam.yflip = yflip;
    }
    (vfx->s).work[0] = 0;
    (vfx->s).work[1] = 0;
    z->ripple = TRUE;
  }
  return vfx;
}

static void Ripple_Init(struct VFX* p) {
  struct Zero* z = (struct Zero*)(p->s).unk_28;
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 0x13));
  (p->s).flags |= DISPLAY;
  {
    bool8 xflip = FALSE;
    if (xflip) {
      (p->s).flags |= X_FLIP;
    } else {
      (p->s).flags &= ~X_FLIP;
    }
    (p->s).spr.xflip = xflip & 1;
    (p->s).spr.oam.xflip = xflip;
  }
  if (!((z->body).status & BODY_STATUS_DEAD) && ((z->body).hp != 0)) {
    PlaySound(SE_WATER_SURFACE);
  }
  (p->s).coord.x = (z->s).coord.x;
  (p->s).coord.y = gOverworld.sea;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ripple_Update(p);
}

void Ripple_Update(struct VFX* p) {
  struct Entity* pa = (p->s).unk_28;
  u32 st;
  UpdateEntityAnim(&p->s);
  st = *(u32*)((u8*)pa + 0x8c) & 0x200;
  if (st == 0) {
    if (*(s16*)((u8*)pa + 0xa4) != 0) {
      goto main_;
    }
  }
  {
    u32 tbl = (u32)gVFXFnTable;
    u32 id = ((p->s).id) << 2;
    EntityFunc** rt = (EntityFunc**)(tbl + id);
    *(u32*)((p->s).mode) = 2;
    (p->s).onUpdate = (void*)((*rt)[2]);
  }
  Ripple_Die(p);
  return;
main_:
  *(s32*)((u8*)p + 0x7c) = (p->s).coord.x;
  if ((p->s).mode[1] == 0) {
    if (!((p->s).flags & 0x20)) {
      if ((s8)((p->s).motion.cmdIdx) <= 1) {
        *((u8*)pa + 0x11C) = 1;
      }
    }
    if ((p->s).motion.state == 3) {
      (p->s).mode[1]++;
    }
    return;
  }
  (p->s).coord.x = (pa->coord).x;
  (p->s).coord.y = gOverworld.sea;
  switch ((p->s).mode[1]) {
    case 1:
      SetMotion(&p->s, 0x14);
      UpdateEntityAnim(&p->s);
      (p->s).flags &= 0xDF;
      *((u8*)p + 0x4d) = st;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m21 = -0x21;
        m21 &= ov;
        *oa = m21;
      }
      (p->s).mode[1]++;
      // fallthrough
    case 2:
      if (*(s32*)((u8*)p + 0x7c) != (p->s).coord.x) {
        (p->s).mode[1]++;
      }
      break;
    case 3:
      SetMotion(&p->s, 0x15);
      UpdateEntityAnim(&p->s);
      (p->s).mode[1]++;
      // fallthrough
    case 4:
      if (*(s32*)((u8*)p + 0x7c) == (p->s).coord.x) {
        (p->s).mode[1] = 1;
      }
      break;
  }
  {
    s32 rh = gZeroRanges[*((u8*)pa + 0x147)].h;
    s32 zy = (pa->coord).y;
    s32 top = zy - rh;
    if (top > gOverworld.sea || zy < gOverworld.sea) {
      u32 tbl = (u32)gVFXFnTable;
      u32 id = ((p->s).id) << 2;
      EntityFunc** rt = (EntityFunc**)(tbl + id);
      *(u32*)((p->s).mode) = 2;
      (p->s).onUpdate = (void*)((*rt)[2]);
      Ripple_Die(p);
    }
  }
}

void Ripple_Die(struct VFX* p) {
  struct Zero* z = (struct Zero*)(p->s).unk_28;
  (p->s).flags &= ~DISPLAY;
  z->ripple = FALSE;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

void Ripple_Disappear(struct VFX* p) {
  struct Zero* z = (struct Zero*)(p->s).unk_28;
  z->ripple = FALSE;
  DeleteVFX(&p->s);
}
