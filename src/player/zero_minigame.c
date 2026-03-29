#include "collision.h"
#include "entity.h"
#include "global.h"
#include "minigame.h"
#include "physics.h"
#include "weapon.h"
#include "zero.h"

static const struct Collision sCollisions[];

static void ZeroMini_Init(struct Zero* z);
static void ZeroMini_Update(struct Zero* z);
static void ZeroMini_Die(struct Zero* z);

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

// --------------------------------------------

static bool32 nop_0803658c(struct Zero* z);
void FUN_080365d8(struct Zero* z);
void FUN_08036848(struct Zero* z);
void FUN_08036904(struct Zero* z);
static bool32 FUN_08036b94(struct Zero* z);

static void zeroMini_08036590(struct Zero* z);
void FUN_080366fc(struct Zero* z);
void FUN_08036870(struct Zero* z);
void recoil_minigame_08036938(struct Zero* z);
static void zeroMini_08036b98(struct Zero* z);

#define STATE ((struct MinigameState*)(z->s).unk_28)

static void ZeroMini_Update(struct Zero* z) {
  // clang-format off
  static const ZeroFunc sUpdates1[5] = {
      (ZeroFunc)nop_0803658c,
      FUN_080365d8,
      FUN_08036848,
      FUN_08036904,
      (ZeroFunc)FUN_08036b94,
  };
  // clang-format on

  // clang-format off
  static const ZeroFunc sUpdates2[5] = {
      zeroMini_08036590,
      FUN_080366fc,
      FUN_08036870,
      recoil_minigame_08036938,
      zeroMini_08036b98,
  };
  // clang-format on

  struct MinigameState* s = (struct MinigameState*)(z->s).unk_28;
  if (s->unk_04 != 2) {
    (sUpdates1[(z->s).mode[1]])(z);
    (sUpdates2[(z->s).mode[1]])(z);
  } else if (s->unk_0c == 0) {
    (sUpdates1[(z->s).mode[1]])(z);
    (sUpdates2[(z->s).mode[1]])(z);
  }

  if ((z->body).status & BODY_STATUS_WHITE) {
    PlaySound(SE_ZERO_STUN);
    if (((struct MinigameState*)(z->s).unk_28)->unk_0c != 0) {
      PlaySound(SE_NOT_ALLOWED);
      ((struct MinigameState*)(z->s).unk_28)->unk_0c--;
      if (((struct MinigameState*)(z->s).unk_28)->unk_0c == 0) {
        (z->body).status = 0;
        (z->body).prevStatus = 0;
        (z->body).invincibleTime = 0;
        (z->s).flags &= ~COLLIDABLE;
        (z->s).mode[1] = 4;
        (z->s).mode[2] = 0;
      }
    }
  }
  if ((z->body).invincibleTime != 0) {
    if (((z->mg).zero.unk_286 == 0) || (--(z->mg).zero.unk_286 == 0)) {
      (z->body).invincibleTime &= 0x7F;
    }
  }
}

// --------------------------------------------

static void ZeroMini_Die(struct Zero* z) {
  (z->s).flags &= ~DISPLAY;
  (z->s).flags &= ~FLIPABLE;
  (z->body).status = 0;
  (z->body).prevStatus = 0;
  (z->body).invincibleTime = 0;
  (z->s).flags &= ~COLLIDABLE;
  SET_PLAYER_ROUTINE(z, ENTITY_DISAPPEAR);
}

// --------------------------------------------

// 0x0803658c
static bool32 nop_0803658c(struct Zero* z) { return TRUE; }

// 0x08036590
static void zeroMini_08036590(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM000_ZERO_NEUTRAL, 0));
      (z->s).work[2] = 60;
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      if (((z->s).work[2] == 0) || (--(z->s).work[2] == 0)) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
    }
  }
}

// --------------------------------------------

INCASM("asm/player/zero_minigame.inc");

// 0x08036b94
static bool32 FUN_08036b94(struct Zero* z) { return TRUE; }

// 0x08036b98
static void zeroMini_08036b98(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM001_ZERO_DYING, 0));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 dy;
      (z->s).d.y += PIXEL(1) / 4;
      if (PIXEL(7) < (z->s).d.y) {
        (z->s).d.y = PIXEL(7);
      }

      (z->s).coord.y += (z->s).d.y;
      dy = PushoutToUp2((z->s).coord.x, (z->s).coord.y);
      if (dy != 0) {
        (z->s).d.y = 0;
        (z->s).coord.y += dy;
      }
      UpdateMotionGraphic(&z->s);
      break;
    }
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x0835eca0
static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(20), PIXEL(26)},
    },

    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(56), PIXEL(26), PIXEL(56)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(7), -PIXEL(76), PIXEL(36), PIXEL(23)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(36), PIXEL(28), PIXEL(50)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(56), PIXEL(26), PIXEL(56)},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(7), -PIXEL(76), PIXEL(36), PIXEL(23)},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(36), PIXEL(28), PIXEL(50)},
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
