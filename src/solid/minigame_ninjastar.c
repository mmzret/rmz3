#include "collision.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "solid.h"

// ファントムのミニゲームに出てくるでかい手裏剣

static const u8 sInitModes[4];

static void MgNinjaStar_Init(struct Solid* p);
void MgNinjaStar_Update(struct Solid* p);
void MgNinjaStar_Die(struct Solid* p);

// clang-format off
const SolidRoutine gMinigameNinjaStarRoutine = {
    [ENTITY_INIT] =      MgNinjaStar_Init,
    [ENTITY_MAIN] =      MgNinjaStar_Update,
    [ENTITY_DIE] =       MgNinjaStar_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void FUN_080d915c(struct MenuState* m, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_MG_NINJASTAR);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_28 = (struct Entity*)m;
  }
}

void FUN_080d91b4(struct MenuState* m, s32 x, s32 y, u8 r3) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_MG_NINJASTAR);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_28 = (struct Entity*)m;
    (p->s).work[2] = r3;
  }
}

static void MgNinjaStar_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  MgNinjaStar_Update(p);
}

INCASM("asm/solid/minigame_ninjastar.inc");

// --------------------------------------------

void nop_080d9304(struct Solid* p);

static const SolidFunc sUpdates1[2] = {
    nop_080d9304,
    nop_080d9304,
};

void FUN_080d9308(struct Solid* p);
void FUN_080d9368(struct Solid* p);

static const SolidFunc sUpdates2[2] = {
    FUN_080d9308,
    FUN_080d9368,
};

static const u8 sInitModes[4] = {0, 1, 0, 0};

const struct Rect Rect_ARRAY_08371194[2] = {
    {0, 0x600, 0x2000, 0x1000},
    {0, 0x600, 0x2000, 0x1000},
};
