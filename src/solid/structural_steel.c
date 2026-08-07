#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollision;
static const u8 sInitModes[4];
static const struct Rect sSize;

static void Solid50_Init(struct Solid* p);
static void Solid50_Update(struct Solid* p);
static void Solid50_Die(struct Solid* p);
static void Solid50_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gStructuralSteelRoutine = {
    [ENTITY_INIT] =      Solid50_Init,
    [ENTITY_UPDATE] =    Solid50_Update,
    [ENTITY_DIE] =       Solid50_Die,
    [ENTITY_DISAPPEAR] = Solid50_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateStructuralSteel(s32 x, s32 y, u8 r2, u8 r3, u8 n) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_STRUCTURAL_STEEL);
    (p->s).work[0] = n;
    (p->s).work[2] = r2;
    (p->s).work[3] = r3;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_coord.x = x;
    (p->s).unk_coord.y = y;
  }
  return p;
}

static void FUN_080df5ac(struct Entity* e) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_STRUCTURAL_STEEL);
    (p->s).work[0] = 2;
    (p->s).unk_28 = e;
  }
}

// --------------------------------------------

static void Solid50_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);

  if ((p->s).work[0] != 2) {
    FUN_080df5ac(&p->s);
  } else {
    INIT_BODY(p, &sCollision, 1, NULL);
    (p->s).flags2 |= ENTI_PHYSICS;
    (p->s).size = &sSize;
    (p->s).physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  }

  Solid50_Update(p);
}

// --------------------------------------------

NON_MATCH void FUN_080df6d8(struct Solid* p);
NON_MATCH void FUN_080df768(struct Solid* p);

static void Solid50_Update(struct Solid* p) {
  static const SolidFunc sUpdates[2] = {
      FUN_080df6d8,
      FUN_080df768,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid50_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
  return;
}

// --------------------------------------------

static void Solid50_Disappear(struct Solid* p) {
  (p->s).flags2 &= ~ENTI_PHYSICS;
  DeleteSolid((void*)p);
}

// --------------------------------------------

NON_MATCH void FUN_080df6d8(struct Solid* p) {
#if MODERN
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).renderPrio = 0x1F;
      SetMotion(&p->s, MOTION(0xDE, 0x00));
      (p->s).mode[2]++;
      /* fallthrough */
    case 1: {
      s32 v;
      s32 m;
      if ((p->s).work[3] == 0) {
        struct Overworld* ow = &gOverworld;
        v = *(s32*)((u8*)ow + 0x2D02C) * 256;
        v += (p->s).work[2] << 16;
      } else {
        struct Overworld* ow = &gOverworld;
        v = *(s32*)((u8*)ow + 0x2D030) * 256;
        v -= (p->s).work[2] << 15;
      }
      if ((p->s).work[0] != 0) {
        m = 0x22000;
      } else {
        m = 0x61000;
      }
      v = v % m;
      (p->s).coord.x = v + (p->s).unk_coord.x;
      (p->s).coord.y = (p->s).unk_coord.y;
      UpdateEntityAnim(&p->s);
      break;
    }
  }
#else
  INCCODE("asm/solid/structural_steel_6d8.inc");
#endif
}

NON_MATCH void FUN_080df768(struct Solid* p) {
#if MODERN
  struct Entity* e = (p->s).unk_28;
  if (e->mode[0] > 1) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  switch ((p->s).mode[2]) {
    case 0:
      *(u16*)((u8*)p + 0xb4) = 0;
      *(u16*)((u8*)p + 0xb6) = 0;
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, 0xDE01);
      *(u32*)((u8*)p + 0x40) = (u32)&(p->s).d;
      (p->s).coord.x = e->coord.x;
      (p->s).coord.y = e->coord.y;
      (p->s).mode[2]++;
      // fallthrough
    case 1: {
      s16* pb4;
      s16* pb6;
      (p->s).d.x = e->coord.x;
      (p->s).d.y = e->coord.y;
      {
        u32 st = (p->body).status & 4;
        if (st != 0) {
          struct Zero* z = pZero2;
          if (z->s.coord.y < (p->s).coord.y && *((u8*)z + 0x18D) != 0) {
            register s32 zx1 asm("r1");
            s32 v;
            zx1 = z->s.coord.x;
            v = (((zx1 - e->coord.x) * 3) << 6) / 256;
            *(s16*)((u8*)p + 0xb4) = v;
            pb4 = (s16*)((u8*)p + 0xb4);
            goto joined;
          }
        }
        pb4 = (s16*)((u8*)p + 0xb4);
        *pb4 = ((*pb4 * 7) << 5) / 256;
      }
    joined:
      {
        register s32 v4 asm("r1");
        s32 diff;
        v4 = *pb4;
        pb6 = (s16*)((u8*)p + 0xb6);
        diff = v4 - *pb6;
        {
          s32 adj = diff;
          if (diff < 0) {
            adj += 0xF;
            asm volatile("" :: "r"(diff));
          }
          *(u16*)pb6 += adj >> 4;
        }
      }
      if ((u32)(*pb6 + 0xF) <= 0x1F) {
        *pb6 = 0;
      }
      (p->s).angle = *(u16*)pb6 >> 8;
      (p->s).coord.x = e->coord.x;
      {
        struct Zero* z2 = pZero2;
        s32 ex = e->coord.x;
        s32 lim = ex + -0x2800;
        s32 zx = z2->s.coord.x;
        if (zx >= lim && zx <= ex + 0x2800) {
          s32 num;
          const s16* stb;
          s32 hb;
          s32 q;
          s32 ey;
          zx -= ex;
          num = zx << 8;
          stb = gSineTable;
          hb = ((s32)(*(u16*)pb6 << 16)) >> 24;
          q = num / stb[(u8)(hb + 0x40)];
          ey = e->coord.y;
          (p->s).coord.y = ey;
          (p->s).coord.y = ey + (q * stb[*(volatile u16*)pb6 >> 8]) / 256;
        } else {
          (p->s).coord.y = e->coord.y;
        }
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
#else
  INCCODE("asm/solid/steel_df768.inc");
#endif
}

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 255,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(52), PIXEL(10)},
};

static const u8 sInitModes[4] = {0, 0, 1, 0};
static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(52), PIXEL(16)};
