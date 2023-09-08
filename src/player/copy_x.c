#include "collision.h"
#include "entity.h"
#include "vfx.h"
#include "global.h"
#include "overworld.h"
#include "zero.h"

static const struct Collision sCollision;

static void CopyXMini_Init(struct Zero* z);
void CopyXMini_Update(struct Zero* z);
void CopyXMini_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gCopyXMiniRoutine = {
  [ENTITY_INIT] =       CopyXMini_Init,
  [ENTITY_MAIN] =       CopyXMini_Update,
  [ENTITY_DIE]  =       CopyXMini_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

struct Zero* CreatePlayerCopyX(void* p, struct Coord* c, u8 n) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, PLAYER_MINIGAME_COPY_X);
    (z->s).coord = *c;
    (z->s).work[0] = n;
    (z->s).unk_28 = p;
  }
  return z;
}

static void CopyXMini_Init(struct Zero* z) {
  struct Body* body;
  struct Coord c;

  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;

  (z->s).spr.xflip = TRUE;
  (z->s).spr.oam.xflip = TRUE;
  (z->s).flags |= X_FLIP;

  (z->s).flags |= COLLIDABLE;

  body = &z->body;
  InitBody(body, &sCollision, &(z->s).coord, 32);
  body->parent = (struct CollidableEntity*)z;
  body->fn = NULL;

  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  SET_PLAYER_ROUTINE(z, ENTITY_MAIN);
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;

  c = (z->s).coord;
  z->unk_280[1] = (struct Entity*)CreateCopyXIcon(z, &c, 0);
  z->unk_280[0] = (struct Entity*)CreateCopyXIcon(z, &c, 1);
  z->unk_280[2] = (struct Entity*)CreateCopyXIcon(z, &c, 2);
  z->unk_27d = 3;
  CopyXMini_Update(z);
}

INCASM("asm/player/copy_x.inc");

// --------------------------------------------

void nop_08035a40(struct Zero* z);
void FUN_08035a9c(struct Zero* z);
void FUN_08035b1c(struct Zero* z);
void FUN_08035cd8(struct Zero* z);

const ZeroFunc sCopyXMiniUpdates1[4] = {
    nop_08035a40,
    FUN_08035a9c,
    FUN_08035b1c,
    FUN_08035cd8,
};

void copyXMini_08035a44(struct Zero* z);
void FUN_08035af0(struct Zero* z);
void FUN_08035b44(struct Zero* z);
void FUN_08035d2c(struct Zero* z);

const ZeroFunc sCopyXMiniUpdates2[4] = {
    copyXMini_08035a44,
    FUN_08035af0,
    FUN_08035b44,
    FUN_08035d2c,
};

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DRP,
  layer : 0,
  special : 0,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0x01,
  hardness : METAL,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0xFFFFFFFF,
  range : {0x0000, 0x0000, 0x1600, 0x1600},
};
