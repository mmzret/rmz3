#include "collision.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "solid.h"

// ファントムのミニゲームに出てくるでかい手裏剣

struct MenuState;

static const u8 sInitModes[4];

static void MgNinjaStar_Init(struct Solid* p);
void MgNinjaStar_Update(struct Solid* p);
void MgNinjaStar_Die(struct Solid* p);

// clang-format off
const SolidRoutine gMinigameNinjaStarRoutine = {
    [ENTITY_INIT] =      MgNinjaStar_Init,
    [ENTITY_UPDATE] =    MgNinjaStar_Update,
    [ENTITY_DIE] =       MgNinjaStar_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on


const struct Rect Rect_ARRAY_08371194[2];
static const SolidFunc sUpdates1[2];
static const SolidFunc sUpdates2[2];
void FUN_080d915c(struct MenuState* m, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_MG_NINJASTAR);
    (p->s).work[0] = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_28 = (struct Entity*)m;
  }
}

void FUN_080d91b4(struct MenuState* m, s32 x, s32 y, u8 r3) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_MG_NINJASTAR);
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_28 = (struct Entity*)m;
    (p->s).work[2] = r3;
  }
}

static void MgNinjaStar_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  MgNinjaStar_Update(p);
}

void MgNinjaStar_Update(struct Solid* p) {
  if ((*(struct Entity**)((u8*)(p->s).unk_28 + 8))->coord.x - (p->s).coord.x > 0xc000) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    (p->s).coord.x += *(s32*)((u8*)(p->s).unk_28 + 0x14);
    (p->s).unk_coord.x += *(s32*)((u8*)(p->s).unk_28 + 0x14);
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

void MgNinjaStar_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void nop_080d9304(struct Solid* p) {}

void FUN_080d9308(struct Solid* p) {
  struct Entity* q = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0x86, 0));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      if ((*(struct Entity**)((u8*)q + 8))->coord.y < (p->s).coord.y - PIXEL(1)) {
        (p->s).flags2 |= 8;
        (p->s).size = Rect_ARRAY_08371194;
        (p->s).physicsAttr = 1;
      } else {
        (p->s).flags2 &= ~8;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_080d9368(struct Solid* p) {
  struct Entity* q = (p->s).unk_28;
  s32 z = (p->s).mode[2];
  switch (z) {
    case 0:
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).unk_coord.y = (p->s).coord.y;
      (p->s).d.x = z;
      (p->s).d.y = *(s16*)((u8*)q + 0x2c);
      SetMotion(&p->s, MOTION(0x86, 0));
      SET_XFLIP(&p->s, 1);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      register s32 cx asm("r3");
      register s32 cy asm("r2");
      const s16* tb;
      s32 a;
      s32 i;
      cx = (p->s).unk_coord.x;
      (p->s).coord.x = cx;
      asm volatile("" ::: "memory");
      tb = gSineTable;
      a = (p->s).d.x;
      i = a >> 8;
      cx += tb[(u8)(i + 0x40)] * 48;
      (p->s).coord.x = cx;
      cy = (p->s).unk_coord.y;
      (p->s).coord.y = cy;
      asm volatile("" ::: "memory");
      cy += tb[(u8)i] * 8;
      (p->s).coord.y = cy;
      if ((p->s).work[2] != 0) {
        (p->s).d.x = a + (p->s).d.y;
      } else {
        (p->s).d.x = a - (p->s).d.y;
      }
      if ((*(struct Entity**)((u8*)q + 8))->coord.y < (p->s).coord.y - PIXEL(1)) {
        (p->s).flags2 |= 8;
        (p->s).size = &Rect_ARRAY_08371194[1];
        (p->s).physicsAttr = 1;
      } else {
        (p->s).flags2 &= ~8;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

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
