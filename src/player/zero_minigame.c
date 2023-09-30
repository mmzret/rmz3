#include "collision.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void ZeroMini_Init(struct Zero* z);
void ZeroMini_Update(struct Zero* z);
void ZeroMini_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gZeroMiniRoutine = {
  [ENTITY_INIT] =       ZeroMini_Init,
  [ENTITY_MAIN] =       ZeroMini_Update,
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

// --------------------------------------------

const struct Collision sZeroMiniCollisions[7] = {
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
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1000, 0x1400, 0x1A00},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 32,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 32,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 32,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 32,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
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
