#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"
#include "story.h"
#include "overworld.h"
#include "zero.h"

/*
  ファントムのミニゲームに出てくるトゲ付き鉄球
*/

void initIronStar(struct Solid* p);
void ironStarAI(struct Solid* p);
void killIronStar(struct Solid* p);

// clang-format off
const SolidRoutine gIronStarRoutine = {
    [ENTITY_INIT] =      initIronStar,
    [ENTITY_UPDATE] =    ironStarAI,
    [ENTITY_DIE] =       killIronStar,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on


const struct Collision Collision_ARRAY_0836fe10[3];
const Coords32 Coord_0836fe58;
const SolidFunc PTR_ARRAY_0836fe00[2];
const SolidFunc PTR_ARRAY_0836fe08[2];
void CreateIronStar(struct Entity* e, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_UNK_004);
    (p->s).work[0] = 2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_28 = e;
  }
}

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  // NOP
  return;
}

void initIronStar(struct Solid* p) {
  register u32 tbl asm("r3");
  register s32 one asm("r2");
  register s32 n asm("r4");
  register s32 w0 asm("r1");
  tbl = (u32)gSolidFnTable;
  {
    register s32 idx asm("r0");
    register EntityFunc** rt asm("r0");
    idx = ((p->s).id) << 2;
    asm volatile("add %0, %1, %2" : "=l"(rt) : "l"(idx), "l"(tbl));
    one = 1;
    *(u32*)((p->s).mode) = one;
    (p->s).onUpdate = (void*)((*rt)[1]);
  }
  {
    s32 b = gCurStory.s.gameflags[5] << 24;
    n = ((u32)b >> 25) & one;
    n += ((u32)b >> 26) & one;
    n += ((u32)b >> 27) & one;
    n += ((u32)b >> 28) & one;
  }
  w0 = (p->s).work[0];
  if ((u8)(w0 - 3) <= 1) {
    if (n > 2) {
      goto disable;
    }
  }
  {
    register s32 t5 asm("r0");
    t5 = w0 - 5;
    asm("" : "+r"(t5));
    t5 <<= 24;
    t5 = (u32)t5 >> 24;
    if ((u32)t5 > 1) {
      goto normal;
    }
  }
  if (n > 2) {
    goto normal;
  }
disable : {
  {
    register u8 g asm("r0");
    register u8 h asm("r1");
    h = (p->s).flags;
    asm("" : "+r"(h));
    g = 0xFE;
    g &= h;
    one = 0;
    h = 0xFD;
    g &= h;
    (p->s).flags = g;
  }
  {
    u8* a = (u8*)p + 0x8c;
    *(s32*)a = one;
    asm("" : "+r"(a));
    a += 4;
    asm("" : "+r"(a));
    *(s32*)a = one;
    asm("" : "+r"(a));
    a += 4;
    asm("" : "+r"(a));
    *a = one;
  }
  {
    register u8 g2 asm("r0");
    register u8 h2 asm("r1");
    h2 = (p->s).flags;
    asm("" : "+r"(h2));
    g2 = 0xFB;
    g2 &= h2;
    (p->s).flags = g2;
  }
  {
    register s32 idx2 asm("r0");
    register EntityFunc** rt2 asm("r0");
    register s32 three asm("r1");
    idx2 = ((p->s).id) << 2;
    asm volatile("add %0, %1, %2" : "=l"(rt2) : "l"(idx2), "l"(tbl));
    three = 3;
    *(u32*)((p->s).mode) = three;
    (p->s).onUpdate = (void*)((*rt2)[3]);
  }
  return;
}
normal : {
  u8 w = (p->s).work[0];
  register u8 nm asm("r0");
  if (w == 0 || w == 3 || w == 5) {
    nm = 0;
  } else {
    nm = 1;
  }
  (p->s).mode[1] = nm;
  {
    register u8 fv asm("r0");
    register u8 k asm("r1");
    k = (p->s).flags;
    fv = 2;
    fv |= k;
    k = 1;
    fv |= k;
    (p->s).flags = fv;
  }
  InitNonAffineMotion(&p->s);
  {
    register u8 fl asm("r1");
    register u8 g3 asm("r0");
    fl = (p->s).flags;
    g3 = 4;
    g3 |= fl;
    (p->s).flags = g3;
  }
  {
    struct Body* body = &p->body;
    InitBody(body, Collision_ARRAY_0836fe10, &(p->s).coord, 1);
    body->parent = (struct Entity*)p;
    body->fn = (void*)onCollision;
  }
  ironStarAI(p);
}
}

void ironStarAI(struct Solid* p) {
  if ((p->s).work[0] == 2) {
    struct Entity* q = (p->s).unk_28;
    if ((*(struct Entity**)((u8*)q + 8))->coord.x - (p->s).coord.x > 0xC000) {
      register u8* w asm("r0");
      u8 fl;
      u32 z;
      fl = (p->s).flags & 0xFE;
      z = 0;
      fl &= 0xFD;
      (p->s).flags = fl;
      w = (u8*)p + 0x8c;
      *(u32*)w = z;
      asm volatile("add %0, #4" : "+r"(w));
      *(u32*)w = z;
      asm volatile("add %0, #4" : "+r"(w));
      *w = z;
      (p->s).flags &= 0xFB;
      SET_SOLID_ROUTINE(p, 3);
      return;
    }
    (p->s).coord.x += *(s32*)((u8*)q + 0x14);
  }
  (PTR_ARRAY_0836fe00[(p->s).mode[1]])(p);
  (PTR_ARRAY_0836fe08[(p->s).mode[1]])(p);
}

void killIronStar(struct Solid* p) {
  (p->s).flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void nop_080cbcc0(struct Solid* p) {}

void FUN_080cbcc4(struct Solid* p) {
  u8 m = (p->s).mode[2];
  switch (m) {
    case 0:
      (p->s).work[2] = m;
      (p->s).flags2 |= 8;
      (p->s).size = (const struct Rect*)&Coord_0836fe58;
      (p->s).physicsAttr = 0x801;
      SetMotion(&p->s, MOTION(0x2D, 0x01));
      (p->s).coord.y = gOverworld.sea;
      (p->s).mode[2]++;
    case 1: {
      s32 y;
      s32 d;
      s32 mk = *(u32*)((u8*)p + 0x8c) & 4;
      y = (p->s).coord.y;
      if (mk != 0 && y > (pZero2->s).coord.y) {
        (p->s).unk_coord.y = 0x800;
      } else {
        (p->s).unk_coord.y = 0;
      }
      d = gOverworld.sea + (p->s).unk_coord.y - y;
      (p->s).coord.y = y + d / 8;
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void FUN_080cbd6c(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &Collision_ARRAY_0836fe10[2]);
      SetMotion(&p->s, MOTION(0x2D, 0x00));
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      if ((p->s).work[0] != 2) {
        struct Overworld* ow = &gOverworld;
        (p->s).coord.y = ow->sea;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

// --------------------------------------------

void nop_080cbcc0(struct Solid* p);

const SolidFunc PTR_ARRAY_0836fe00[2] = {
    nop_080cbcc0,
    nop_080cbcc0,
};

// --------------------------------------------

void FUN_080cbcc4(struct Solid* p);
void FUN_080cbd6c(struct Solid* p);

const SolidFunc PTR_ARRAY_0836fe08[2] = {
    FUN_080cbcc4,
    FUN_080cbd6c,
};

// --------------------------------------------

const struct Collision Collision_ARRAY_0836fe10[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0600, 0x1A00, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0A00, 0x2000, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1800, 0x1800},
    },
};

const Coords32 Coord_0836fe58 = {-0x04000000, 0x10002000};
