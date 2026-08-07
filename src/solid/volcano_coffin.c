#include "collision.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "solid.h"
#include "story.h"
#include "stagerun.h"
#include "zero.h"

s32 PushoutToUp1(s32 x, s32 y);
struct Entity* CreateSmoke(u8 kind, struct Coord* c);

// リコイルロッドで押せる棺桶みたいなコンテナ

static const u16 u16_ARRAY_083716b8[2];

static const struct Collision sCollision;
static const struct Rect sSize;

static void VolcanoCoffin_Init(struct Solid* p);
void VolcanoCoffin_Update(struct Solid* p);
void VolcanoCoffin_Die(struct Solid* p);

// clang-format off
const SolidRoutine gVolcanoCoffinRoutine = {
    [ENTITY_INIT] =      (void*)VolcanoCoffin_Init,
    [ENTITY_UPDATE] =    (void*)VolcanoCoffin_Update,
    [ENTITY_DIE] =       (void*)VolcanoCoffin_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Solid* CreateVolcanoCoffin(u8 n, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_VOLCANO_COFFIN);
    (p->s).work[0] = n;
    (p->s).coord.x = x;
    (p->s).unk_coord.y = x;
    (p->s).coord.y = y;
  }
  return p;
}

// --------------------------------------------

static void VolcanoCoffin_Init(struct Solid* p) {
  s8 px;
  (p->s).flags |= FLIPABLE;
  px = gCurStory.s.counts[u16_ARRAY_083716b8[(p->s).work[0]]];
  (p->s).coord.x += (px * PIXEL(1));
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  (p->s).coord.y -= (PIXEL(32) - 1);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  VolcanoCoffin_Update(p);
}

// --------------------------------------------

void VolcanoCoffin_Update(struct Solid* p) {
  u8 m = (p->s).mode[1];
  switch (m) {
    case 0:
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x2C00) {
        break;
      }
      (p->s).flags |= DISPLAY;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(0x99, 0x00));
      INIT_BODY(p, &sCollision, 0, NULL);
      (p->s).flags2 &= ~WHITE_PAINTABLE;
      (p->s).invincibleID = (p->s).uniqueID;
      (p->s).flags2 |= ENTI_PHYSICS;
      (p->s).size = &sSize;
      (p->s).physicsAttr = 0x2001;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 1: {
      u32* st;
      UpdateEntityAnim(&p->s);
      {
        u32* a = (u32*)((u8*)p + 0x8c);
        u32 f = *a & 0x20000;
        asm volatile("add %0, %1, #0" : "=&l"(st) : "l"(a));
        if (f != 0) {
          struct Zero* z = pZero2;
          s32 cx = (p->s).coord.x;
          s32 k = 0xA80 << 2;
          s32 lim = cx + k;
          s32 zx = (z->s).coord.x;
          if (zx > lim) {
            (p->s).d.x = -0x440;
            (p->s).unk_coord.x = -0x2A00;
            (p->s).work[2] = 0;
            (p->s).mode[1] = 2;
            break;
          }
          if (zx < cx - 0x2A00) {
            (p->s).d.x = 0x440;
            (p->s).unk_coord.x = k;
            (p->s).work[2] = 0;
            (p->s).mode[1] = 2;
            break;
          }
        }
      }
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) <= 0x2C00) {
        break;
      }
      {
        u32 zz;
        u8 fl = (p->s).flags & ~DISPLAY;
        zz = 0;
        (p->s).flags = fl;
        *st = zz;
        (p->body).prevStatus = zz;
        (p->body).invincibleTime = zz;
        (p->s).flags &= ~COLLIDABLE;
        (p->s).flags2 &= ~ENTI_PHYSICS;
        (p->s).mode[1] = zz;
      }
      break;
    }
    case 2: {
      s32 cx0 = (p->s).coord.x;
      s32 dx = (p->s).d.x;
      s32 nx = cx0 + dx;
      s32 hit;
      s32 k;
      s32 w;
      s32 a0;
      s32 cy;
      (p->s).coord.x = nx;
      (p->s).d.x = dx * 15 / 16;
      hit = 1;
      a0 = nx + (p->s).unk_coord.x;
      cy = (p->s).coord.y;
      k = 0x800;
      if (PushoutToUp1(a0, cy + k) != 0) {
        hit = 0;
        if ((p->s).unk_coord.x < 0) {
          (p->s).coord.x += PushoutToRight1((p->s).coord.x + (p->s).unk_coord.x, (p->s).coord.y + k);
        } else {
          (p->s).coord.x += PushoutToLeft1((p->s).coord.x + (p->s).unk_coord.x, (p->s).coord.y + k);
        }
      }
      w = (p->s).work[2] + 1;
      (p->s).work[2] = w;
      if ((w & 1) != 0 && hit != 0) {
        struct Coord c;
        u32 rr;
        s32 v;
        rr = RNG_0202f388 * 0x343FD + 0x269EC3;
        rr <<= 1;
        RNG_0202f388 = rr >> 1;
        v = (rr >> 0x11) % 0x46;
        v -= 0x23;
        c.x = (p->s).coord.x + (v << 8);
        c.y = (p->s).coord.y + 0x2400;
        CreateSmoke(3, &c);
      }
      if ((u32)((p->s).d.x + 0x40) <= 0x80) {
        gCurStory.s.counts[u16_ARRAY_083716b8[(p->s).work[0]]] =
            ((p->s).coord.x - (p->s).unk_coord.y) >> 8;
        (p->s).d.x = 0;
        (p->s).mode[1] = 1;
      }
      break;
    }
  }
}

void VolcanoCoffin_Die(struct Solid* p) {}

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  LAYER(RECOIL_PUSHABLE),
  hitzone : 0xFF,
  remaining : 0,
  range : {PIXEL(0), PIXEL(20), PIXEL(80), PIXEL(40)},
};

static const struct Rect sSize = {PIXEL(0), PIXEL(18), PIXEL(80), PIXEL(36)};

static const u16 u16_ARRAY_083716b8[2] = {70, 71};
