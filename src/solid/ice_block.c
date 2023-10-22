#include "collision.h"
#include "global.h"
#include "solid.h"

// 壊れた宇宙船の屋内とかで上から落ちてくる氷ブロック

static const struct Collision sCollisions[2];
static const struct Rect sSize;

bool16 FUN_0800bd38(s32 x, s32 y);
void FUN_0800bd78(s32 x, s32 y);

static void IceBlock_Init(struct Solid* p);
void IceBlock_Update(struct Solid* p);
void IceBlock_Die(struct Solid* p);
void IceBlock_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gIceBlockRoutine = {
    [ENTITY_INIT] =      IceBlock_Init,
    [ENTITY_UPDATE] =    IceBlock_Update,
    [ENTITY_DIE] =       IceBlock_Die,
    [ENTITY_DISAPPEAR] = IceBlock_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NON_MATCH static void IceBlock_Init(struct Solid* p) {
#if MODERN
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y -= PIXEL(11);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);

  if (FUN_0800bd38((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + PIXEL(32);
    if (FUN_0800bd38((p->s).coord.x, (p->s).coord.y) == 0) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }
    if (FUN_0800bd38((p->s).coord.x, (p->s).coord.y + PIXEL(32))) {
      (p->s).coord.y += PIXEL(32);
    }
    (p->s).flags2 |= ENTITY_HAZARD;
    (p->s).size = &sSize;
    (p->s).hazardAttr = 0x3801;
    FUN_0800bd78((p->s).coord.x, (p->s).coord.y);
    SetMotion(&p->s, MOTION(SM203_ICE_BLOCK, 1));
    INIT_BODY(p, &sCollisions[1], 80, NULL);
    (p->s).mode[1] = (p->s).work[0] = 2;
  } else {
    SetMotion(&p->s, MOTION(SM203_ICE_BLOCK, 0));
    INIT_BODY(p, &sCollisions[0], 80, NULL);
  }
  IceBlock_Update(p);
#else
  INCCODE("asm/wip/IceBlock_Init.inc");
#endif
}

INCASM("asm/solid/ice_block.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 254,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(20), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(12), PIXEL(40), PIXEL(28)},
    },
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(12), PIXEL(32), PIXEL(32)};
