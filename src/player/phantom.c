#include "collision.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

static const struct Collision sCollisions[2];
static const u8 sInitModes[4];

static void PhantomMini_Init(struct Zero* z);
void PhantomMini_Update(struct Zero* z);
void PhantomMini_Die(struct Zero* z);

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
    return 0x6E000;
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
    (z->s).unk_28 = (struct Entity*)p;
  }
  return z;
}

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  u8* p;
  struct Zero* z = (struct Zero*)body->parent;
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    PlaySound(SE_NOT_ALLOWED);
    PlaySound(SE_PHANTOM_DAMAGE);
    p = (u8*)(z->s).unk_28;
    if (p[213] != 0) {
      p[213]--;
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

INCASM("asm/player/phantom.inc");

// --------------------------------------------

void FUN_08034b28(struct Zero* z);
void nop_08034b24(struct Zero* z);

const ZeroFunc sPhantomMiniUpdates1[4] = {
    FUN_08034b28,
    nop_08034b24,
    nop_08034b24,
    nop_08034b24,
};

void phantom_08034b4c(struct Zero* z);
void FUN_08034d40(struct Zero* z);
void phantom_08034dc0(struct Zero* z);
void FUN_08034e50(struct Zero* z);

const ZeroFunc sPhantomMiniUpdates2[4] = {
    phantom_08034b4c,
    FUN_08034d40,
    phantom_08034dc0,
    FUN_08034e50,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1000, 0x1000, 0x2400},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1000, 0x1000, 0x2400},
    },
};

// --------------------------------------------

static const u8 sInitModes[4] = {0, 0, 0, 0};
