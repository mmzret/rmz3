#include "collision.h"
#include "entity.h"
#include "global.h"
#include "minigame.h"
#include "zero.h"

static const struct Collision sCollisions[2];
static const u8 sInitModes[4];

static void PhantomMini_Init(struct Zero* z);
static void PhantomMini_Update(struct Zero* z);
static void PhantomMini_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gPhantomMiniRoutine = {
  [ENTITY_INIT] =       PhantomMini_Init,
  [ENTITY_UPDATE] =     PhantomMini_Update,
  [ENTITY_DIE]  =       PhantomMini_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

s32 FUN_080349a8(struct Zero* z) {
  if ((z->s).coord.x - 0x96000U >= 0x1E001) {
    return PIXEL(1760);
  }
  return FUN_08009f6c((z->s).coord.x, (z->s).coord.y);
}

struct Zero* CreatePlayerPhantom(void* p, s32 x, s32 y) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, PLAYER_MINIGAME_PHANTOM);
    (z->s).work[0] = 0;
    (z->s).coord.x = x;
    (z->s).coord.y = y;
    (z->s).unk_28 = p;
  }
  return z;
}

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  struct MinigameState* s;
  struct Zero* z = (struct Zero*)body->parent;
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    PlaySound(SE_NOT_ALLOWED);
    PlaySound(SE_PHANTOM_DAMAGE);

    s = (struct MinigameState*)(z->s).unk_28;
    if (s->unk_d5 != 0) {
      s->unk_d5--;
    }
    PlaySound(SE_ZERO_STUN);
  }
}

static void PhantomMini_Init(struct Zero* z) {
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = sInitModes[(z->s).work[0]];

  (z->s).flags |= FLIPABLE;
  (z->s).flags |= DISPLAY;
  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  INIT_BODY(z, &sCollisions[0], 6, onCollision);
  (z->s).unk_coord.y = (z->s).coord.y;
  (z->s).work[3] = 0;
  PhantomMini_Update(z);
}

// --------------------------------------------

static void FUN_08034b28(struct Zero* z);
static void nop_08034b24(struct Zero* z);

void phantom_08034b4c(struct Zero* z);
void FUN_08034d40(struct Zero* z);
void phantom_08034dc0(struct Zero* z);
void FUN_08034e50(struct Zero* z);

static void PhantomMini_Update(struct Zero* z) {
  s32 max_y;
  static const ZeroFunc sUpdates1[4] = {
      FUN_08034b28,
      nop_08034b24,
      nop_08034b24,
      nop_08034b24,
  };
  static const ZeroFunc sUpdates2[4] = {
      phantom_08034b4c,
      FUN_08034d40,
      phantom_08034dc0,
      FUN_08034e50,
  };

  struct MinigameState* s = (struct MinigameState*)(z->s).unk_28;
  (z->s).coord.x += s->unk_14;
  (sUpdates1[(z->s).mode[1]])(z);
  (sUpdates2[(z->s).mode[1]])(z);

  max_y = (z->s).unk_coord.y + PIXEL(240);
  if ((z->s).coord.y > max_y) {
    (z->s).coord.y = max_y;
  }
}

static void PhantomMini_Die(struct Zero* z) {
  SET_PLAYER_ROUTINE(z, ENTITY_EXIT);
  return;
}

// --------------------------------------------

static void nop_08034b24(struct Zero* z) { return; }

static void FUN_08034b28(struct Zero* z) {
  struct MinigameState* s = (struct MinigameState*)(z->s).unk_28;
  if ((s->unk_d6 != 0) && (s->unk_00[1] != 3)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
}

INCASM("asm/player/phantom.inc");

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2400},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2400},
    },
};

// --------------------------------------------

static const u8 sInitModes[4] = {0, 0, 0, 0};
