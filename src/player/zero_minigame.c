#include "collision.h"
#include "entity.h"
#include "global.h"
#include "physics.h"
#include "weapon.h"
#include "zero.h"

static const struct Collision sCollisions[];

static void ZeroMini_Init(struct Zero* z);
void ZeroMini_Update(struct Zero* z);
void ZeroMini_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gZeroMiniRoutine = {
  [ENTITY_INIT] =       ZeroMini_Init,
  [ENTITY_UPDATE] =     ZeroMini_Update,
  [ENTITY_DIE]  =       ZeroMini_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

struct Zero* CreateZeroMini(void* p, struct Coord* c, u8 n) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, 6);
    (z->s).coord = *c;
    (z->s).work[0] = n;
    (z->s).unk_28 = p;
  }
  return z;
}

// --------------------------------------------

static void ZeroMini_Init(struct Zero* z) {
  struct Coord* c;
  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;
  {
    bool8 xflip = FALSE;
    (z->s).spr.xflip = xflip & 1;
    (z->s).spr.oam.xflip = xflip;
    if (xflip) {
      (z->s).flags |= X_FLIP;
    } else {
      (z->s).flags &= ~X_FLIP;
    }
  }
  INIT_BODY(z, &sCollisions[0], 32, NULL);
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  (z->mg).zero.unk_286 = 0;
  LoadZeroPalette((struct Entity*)z, BODY_CHIP_NONE);
  SetWeaponElement(WEAPON_BUSTER, 0);
  SetWeaponElement(WEAPON_SABER, 0);
  (z->mg).zero.unk_27c = 0;
  (z->mg).zero.unk_27d = 0;
  (z->s).work[3] = 0;
  (z->mg).zero.unk_284 = 0;
  (z->mg).zero.unk_285 = 0;

  {
    struct Coord* c;
    c = &(z->s).d;
    c->x = c->y = 0;
    c = &(z->s).unk_coord;
    c->x = c->y = 0;
  }

  ZeroMini_Update(z);
}

INCASM("asm/player/zero_minigame.inc");

// --------------------------------------------

void nop_0803658c(struct Zero* z);
void FUN_080365d8(struct Zero* z);
void FUN_08036848(struct Zero* z);
void FUN_08036904(struct Zero* z);
void FUN_08036b94(struct Zero* z);

// clang-format off
const ZeroFunc sZeroMiniUpdates1[5] = {
    nop_0803658c,
    FUN_080365d8,
    FUN_08036848,
    FUN_08036904,
    FUN_08036b94,
};
// clang-format on

// --------------------------------------------

void zeroMini_08036590(struct Zero* z);
void FUN_080366fc(struct Zero* z);
void FUN_08036870(struct Zero* z);
void recoil_minigame_08036938(struct Zero* z);
void zeroMini_08036b98(struct Zero* z);

// clang-format off
const ZeroFunc sZeroMiniUpdates2[5] = {
    zeroMini_08036590,
    FUN_080366fc,
    FUN_08036870,
    recoil_minigame_08036938,
    zeroMini_08036b98,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x0835eca0
static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1400, 0x1A00},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
};

// --------------------------------------------

// clang-format off
const motion_t sZeroMiniMotions[10] = {
  MOTION(0x1E, 0x00),
  MOTION(0x1E, 0x01),
  MOTION(0x1F, 0x00),
  MOTION(0x1F, 0x01),
  MOTION(0x20, 0x00),
  MOTION(0x20, 0x01),
  MOTION(0x37, 0x00),
  MOTION(0x38, 0x00),
  MOTION(0x39, 0x01),
  MOTION(0x00, 0x00),
};
// clang-format on
