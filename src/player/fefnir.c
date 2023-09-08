#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "zero.h"

static const struct Collision sCollisions[3];
static const u8 sInitModes[4];

static void Fefnir_Init(struct Zero* z);
void Fefnir_Update(struct Zero* z);
void Fefnir_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gFefnirRoutine = {
  [ENTITY_INIT] =       Fefnir_Init,
  [ENTITY_MAIN] =       Fefnir_Update,
  [ENTITY_DIE]  =       Fefnir_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

void CreatePlayerFefnir(void* p, s32 x, s32 y) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, 1);
    (z->s).work[0] = 0;
    (z->s).coord.x = x;
    (z->s).coord.y = y;
    (z->s).unk_28 = p;
  }
}

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

static void Fefnir_Init(struct Zero* z) {
  struct Body* body;

  SET_PLAYER_ROUTINE(z, ENTITY_MAIN);
  (z->s).mode[1] = sInitModes[(z->s).work[0]];

  (z->s).flags |= FLIPABLE;
  (z->s).flags |= DISPLAY;
  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  (z->s).flags |= COLLIDABLE;

  body = &z->body;
  InitBody(body, sCollisions, &(z->s).coord, 6);
  body->parent = (struct CollidableEntity*)z;
  body->fn = onCollision;

  (z->s).work[3] = 0;
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  Fefnir_Update(z);
}

INCASM("asm/player/fefnir.inc");

// --------------------------------------------

void FUN_08034744(struct Zero* z);
void FUN_08034774(struct Zero* z);
void nop_08034740(struct Zero* z);

const ZeroFunc gFefnirUpdates1[4] = {
    FUN_08034744,
    FUN_08034774,
    nop_08034740,
    nop_08034740,
};

void FUN_080347a0(struct Zero* z);
void fefnir_080347f0(struct Zero* z);
void fefnir_080348bc(struct Zero* z);
void fefnir_08034974(struct Zero* z);

const ZeroFunc gFefnirUpdates2[4] = {
    FUN_080347a0,
    fefnir_080347f0,
    fefnir_080348bc,
    fefnir_08034974,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      layer : 0,
      special : 0,
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
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      layer : 0,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
    {
      kind : DRP,
      layer : 0,
      special : 0,
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
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
