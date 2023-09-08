#include "collision.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

static const struct Collision sCollisions[7];

void Harpuia_Init(struct Zero* z);
void Harpuia_Update(struct Zero* z);
void Harpuia_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gHarpuiaRoutine = {
  [ENTITY_INIT] =       Harpuia_Init,
  [ENTITY_MAIN] =       Harpuia_Update,
  [ENTITY_DIE]  =       Harpuia_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

struct Zero* CreatePlayerHarpuia(void* p, struct Coord* c, u8 n) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, 3);
    (z->s).coord = *c;
    (z->s).work[0] = n;
    (z->s).unk_28 = p;
  }
  return z;
}

// static void Harpuia_Init(struct Zero* z) {
//   struct Body* body;
//   struct Coord c;

//   InitNonAffineMotion(&z->s);
//   ResetDynamicMotion(&z->s);
//   (z->s).flags |= DISPLAY;
//   (z->s).flags |= FLIPABLE;

//   (z->s).spr.xflip = TRUE;
//   (z->s).spr.oam.xflip = TRUE;
//   (z->s).flags |= X_FLIP;

//   (z->s).flags |= COLLIDABLE;

//   body = &z->body;
//   InitBody(body, sCollisions, &(z->s).coord, 32);
//   body->parent = (struct CollidableEntity*)z;
//   body->fn = NULL;

//   (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
//   SET_PLAYER_ROUTINE(z, ENTITY_MAIN);
//   (z->s).mode[1] = 0;
//   (z->s).mode[2] = 0;
//   (z->s).mode[3] = 0;

//   c = (z->s).coord;
//   z->unk_280[0] = (struct Entity*)FUN_0809af20(z, &c, 0);
//   Harpuia_Update(z);
// }

INCASM("asm/player/harpuia.inc");

// --------------------------------------------

void FUN_0803532c(struct Zero* z);
void FUN_0803537c(struct Zero* z);
void FUN_080353e4(struct Zero* z);
void FUN_080354a4(struct Zero* z);
void FUN_080355c0(struct Zero* z);

// clang-format off
const ZeroFunc sHarpuiaUpdates1[5] = {
    FUN_0803532c,
    FUN_0803537c,
    FUN_080353e4,
    FUN_080354a4,
    FUN_080355c0,
};
// clang-format on

// --------------------------------------------

void FUN_08035330(struct Zero* z);
void FUN_080353a8(struct Zero* z);
void FUN_0803540c(struct Zero* z);
void harpuia_080354d4(struct Zero* z);
void FUN_080355c4(struct Zero* z);

// clang-format off
const ZeroFunc sHarpuiaUpdates2[5] = {
    FUN_08035330,
    FUN_080353a8,
    FUN_0803540c,
    harpuia_080354d4,
    FUN_080355c4,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DRP,
      layer : 0,
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
    [1] = {
      kind : DDP,
      layer : 0,
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
      layer : 0,
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
      layer : 0,
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
      layer : 0,
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
      layer : 0,
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
      layer : 0,
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
