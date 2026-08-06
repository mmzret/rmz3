#include "collision.h"
#include "global.h"
#include "palette_animation.h"
#include "solid.h"
#include "zero.h"

void FUN_080bf438(s32 x, s32 y, u8 n);
void FUN_080bf390(struct Entity* e);
void FUN_080cdd64(struct Solid* p);
void FUN_080bf438(s32 x, s32 y, u8 n);

// ------------------------------------------------------------------------------------------------------------------------------------

void AnubisCoffin_Init(struct Solid* p);
void AnubisCoffin_Update(struct Solid* p);
void AnubisCoffin_Die(struct Solid* p);

// clang-format off
const SolidRoutine gAnubisCoffinRoutine = {
    [ENTITY_INIT] =      AnubisCoffin_Init,
    [ENTITY_UPDATE] =    AnubisCoffin_Update,
    [ENTITY_DIE] =       AnubisCoffin_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on


const struct Rect Rect_08370238;
const struct Collision sAnubisCoffinCollisions[2];
const SolidFunc sAnubisCoffinUpdates1[3];
const SolidFunc sAnubisCoffinUpdates2[3];
const u8 u8_ARRAY_08370240[4];
void CreateAnubisCoffins(struct Entity* anubis, bool8 r1) {
  s32 i;
  struct Solid* another = NULL;
  for (i = 0; i < 2; i++) {
    struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
    if (p != NULL) {
      INIT_SOLID_ROUTINE(p, SOLID_ANUBIS_COFFIN);
      (p->s).work[0] = 0;
      (p->s).work[2] = i;
      (p->s).work[3] = r1;
      (p->s).unk_28 = anubis;
      (p->s).unk_2c = (struct Entity*)another;
      another = p;
    }
  }
}

void FUN_080cdd64(struct Solid* p) {
  struct Solid* q = (struct Solid*)(p->s).unk_2c;
  s32 dx;
  s32 px;
  if (((p->body).status & 0x24) || ((q->body).status & 0x24)) {
    *((u8*)p + 0xbc) = 1;
  }
  dx = (p->s).coord.x;
  dx -= (q->s).coord.x;
  dx += -0x1800;
  {
    u8 lk = *((u8*)p + 0xbc);
    px = *(volatile s32*)&(p->s).coord.x;
    if (lk == 0) {
    struct Zero* z;
      if (dx > 0x1DFF) goto normal;
      z = pZero2;
      if ((z->s).coord.x < (q->s).coord.x + 0xC00) goto normal;
      if ((z->s).coord.x > px - 0xC00) goto normal;
      if ((z->s).coord.y <= (p->s).coord.y - 0x1E00) goto normal;
    }
  }
  (pZero2->s).coord.x = *(s32*)((u8*)p + 0xb8);
  SetDDP(&p->body, &sAnubisCoffinCollisions[1]);
  (p->s).flags2 &= ~ENTI_PHYSICS;
  SetDDP(&q->body, &sAnubisCoffinCollisions[1]);
  (q->s).flags2 &= ~ENTI_PHYSICS;
  return;

normal:
  SetDDP(&p->body, &sAnubisCoffinCollisions[0]);
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = (struct Rect*)&Rect_08370238;
  (p->s).physicsAttr = 1;
  SetDDP(&q->body, &sAnubisCoffinCollisions[0]);
  (q->s).flags2 |= ENTI_PHYSICS;
  (q->s).size = (struct Rect*)&Rect_08370238;
  (q->s).physicsAttr = 1;
}

void nop_080cde6c(struct Solid* p) {}

void AnubisCoffin_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = u8_ARRAY_08370240[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, sAnubisCoffinCollisions, 1, (void*)nop_080cde6c);
  *(u8*)((u8*)p + 0xbc) = 0;
  AnubisCoffin_Update(p);
}

void AnubisCoffin_Update(struct Solid* p) {
  (sAnubisCoffinUpdates1[(p->s).mode[1]])(p);
  (sAnubisCoffinUpdates2[(p->s).mode[1]])(p);
}

void AnubisCoffin_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080cdf34(struct Solid* p) {}

void coffin_080cdf38(struct Solid* p) {
  struct Entity* q = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0: {
      s32* src;
      (p->s).flags2 |= 8;
      (p->s).size = (struct Rect*)&Rect_08370238;
      (p->s).physicsAttr = 1;
      if ((p->s).work[3] != 0) {
        register s32* a asm("r1");
        register s32 v asm("r0");
        register s32 k asm("r2");
        if ((p->s).work[2] == 0) {
          SetMotion(&p->s, 0x96 << 7);
          a = (s32*)((u8*)q + 0xb8);
          v = *a;
          k = -0x8800;
        } else {
          SetMotion(&p->s, 0x4B01);
          a = (s32*)((u8*)q + 0xb8);
          v = *a;
          k = 0x88 << 8;
        }
        v += k;
        (p->s).coord.x = v;
        src = a;
        *(s32*)((u8*)p + 0xb8) = *src;
      } else {
        register s32 v asm("r1");
        register s32 k asm("r2");
        (p->s).coord.x = (pZero2->s).coord.x;
        if ((p->s).work[2] == 0) {
          SetMotion(&p->s, 0x96 << 7);
          v = (p->s).coord.x;
          k = -0x3000;
        } else {
          SetMotion(&p->s, 0x4B01);
          v = (p->s).coord.x;
          k = 0xc0 << 6;
        }
        {
          register s32 r asm("r0");
          r = v + k;
          (p->s).coord.x = r;
        }
        *(s32*)((u8*)p + 0xb8) = v;
        src = (s32*)((u8*)q + 0xb8);
      }
      (p->s).work[3] = 0xc;
      (p->s).coord.y = FUN_08009f6c(*src, *(s32*)((u8*)q + 0xbc));
      *(s32*)((u8*)p + 0xb4) = (p->s).coord.y;
      FUN_080bf438((p->s).coord.x, (p->s).coord.y, 0);
      (p->s).coord.y += 0x80 << 6;
      (p->s).flags &= ~DISPLAY;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      if ((u8)--(p->s).work[3] == 0) {
        (p->s).mode[2]++;
      }
      break;
    case 2: {
      {
        u32 v = GetEntityPaletteID(&p->s);
        u32 sv = ((u32)(u8)v) << 5;
        u32 k = 0x200;
        u32 kc;
        asm volatile("add %0, %1, #0" : "=&l"(kc) : "l"(k));
        ((void (*)(u16, u32))StartPaletteAnimation)(0x46, sv | kc);
      }
      {
        register s32 tv asm("r0");
        register u8* tp asm("r1");
        tv = (p->s).work[2];
        tv <<= 2;
        tv += 0x16;
        asm("" : "+r"(tv));
        tp = (u8*)p + 0x25;
        *tp = tv;
      }
      (p->s).flags |= DISPLAY;
      (p->s).d.y = -0x300;
      {
        register u8* o asm("r2");
        register s32 ov asm("r0");
        register s32 k asm("r1");
        o = (u8*)p + 0x49;
        ov = *o;
        k = 0xc;
        ov |= k;
        *o = ov;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      register s32 cy asm("r1");
      register s32 lim asm("r0");
      cy = (p->s).coord.y;
      cy += (p->s).d.y;
      (p->s).coord.y = cy;
      lim = *(s32*)((u8*)p + 0xb4);
      lim += -0x1C00;
      if (cy < lim) {
        register s32 z asm("r1");
        (p->s).coord.y = lim;
        z = 0;
        (p->s).mode[1] = 1;
        (p->s).mode[2] = z;
      }
      StepPaletteAnimation(0x46);
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void coffin_080ce0d4(struct Solid* p) {
  struct Entity* a = (p->s).unk_2c;
  switch ((p->s).mode[2]) {
    case 0:
      PlaySound(0x80);
      RemovePaletteAnimation(0x46);
      {
        u32 g0 = GetEntityPaletteID(&p->s);
        u32 g = (u8)g0 << 5;
        StartPaletteAnimation(0x47, g | 0x200);
      }
      (p->s).work[3] = 0x10;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      if ((p->s).work[2] == 1) {
        if ((((u32)(p->s).work[3] % 3) << 24) == 0) {
          FUN_080bf390(&p->s);
        }
      }
      {
        s32 t = (p->s).work[3] - 1;
        (p->s).work[3] = t;
        if ((t << 24) == 0) {
          (p->s).mode[2]++;
        }
      }
      StepPaletteAnimation(0x47);
      break;
    case 2:
      (p->s).work[3] = 0;
      {
        s32 c = 0x3C0;
        c -= ((p->s).work[2] * 15) << 7;
        (p->s).d.x = c;
      }
      (p->s).mode[2]++;
      /* fallthrough */
    case 3:
      (p->s).work[3]++;
      if ((p->s).work[2] == 1) {
        if ((((u32)(p->s).work[3] % 3) << 24) == 0) {
          if ((p->s).coord.x - a->coord.x > 0x2000) {
            FUN_080bf390(&p->s);
          }
        }
      }
      {
        s32 x = (p->s).coord.x + (p->s).d.x;
        u8 w2;
        (p->s).coord.x = x;
        w2 = (p->s).work[2];
        if (w2 == 0) {
          s32 lim = *(s32*)((u8*)p + 0xb8) + -0x300;
          if (x > lim) {
            (p->s).coord.x = lim;
            (p->s).mode[1] = 2;
            (p->s).mode[2] = w2;
          }
        } else {
          s32 lim = *(s32*)((u8*)p + 0xb8) + 0x300;
          if (x < lim) {
            (p->s).coord.x = lim;
            (p->s).mode[1] = 2;
            (p->s).mode[2] = 0;
          }
        }
      }
      StepPaletteAnimation(0x47);
      UpdateEntityAnim(&p->s);
      break;
  }
  if ((p->s).work[2] == 1) {
    FUN_080cdd64(p);
  }
}

void coffin_080ce204(struct Solid* p) {
  register s32 m asm("r5");
  m = (p->s).mode[2];
  switch (m) {
    case 0:
      RemovePaletteAnimation(0x47);
      StartPaletteAnimation(0x46, ((u32)GetEntityPaletteID(&p->s) << 5) | 0x200);
      (p->s).work[3] = m;
      (p->s).d.y = m;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      register s32 z asm("r6");
      register s32* b4 asm("r5");
      register s32 ny asm("r1");
      {
        register s32 t asm("r0");
        t = (p->s).work[3];
        t++;
        z = 0;
        (p->s).work[3] = t;
        t <<= 24;
        t = (u32)t >> 24;
        b4 = (s32*)((u8*)p + 0xb4);
        if (t == 4) {
          FUN_080bf438((p->s).coord.x, *b4, 0);
        }
      }
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      {
        register s32 dv asm("r0");
        ny = (p->s).coord.y;
        dv = (p->s).d.y;
        ny += dv;
        (p->s).coord.y = ny;
      }
      if (ny > *b4 + 0x2000) {
        (p->s).flags2 &= ~8;
        {
          register u8 g asm("r0");
          register u8 h asm("r1");
          h = (p->s).flags;
          asm("" : "+r"(h));
          g = 0xFE;
          g &= h;
          h = 0xFD;
          g &= h;
          (p->s).flags = g;
        }
        {
          u8* a = (u8*)p + 0x8c;
          *(u32*)a = z;
          asm("" : "+r"(a));
          a += 4;
          asm("" : "+r"(a));
          *(u32*)a = z;
          asm("" : "+r"(a));
          a += 4;
          asm("" : "+r"(a));
          *a = z;
        }
        (p->s).flags &= 0xFB;
        SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
        RemovePaletteAnimation(0x46);
        return;
      }
      StepPaletteAnimation(0x46);
      UpdateEntityAnim(&p->s);
      break;
    }
  }
  if ((p->s).work[3] == 0) {
    FUN_080cdd64(p);
  }
}

// --------------------------------------------

void FUN_080cdf34(struct Solid* p);

const SolidFunc sAnubisCoffinUpdates1[3] = {
    FUN_080cdf34,
    FUN_080cdf34,
    FUN_080cdf34,
};

// --------------------------------------------

void coffin_080cdf38(struct Solid* p);
void coffin_080ce0d4(struct Solid* p);
void coffin_080ce204(struct Solid* p);

const SolidFunc sAnubisCoffinUpdates2[3] = {
    coffin_080cdf38,
    coffin_080ce0d4,
    coffin_080ce204,
};

// --------------------------------------------

const struct Collision sAnubisCoffinCollisions[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1800, 0x3C00},
    },
};

// --------------------------------------------

const struct Rect Rect_08370238 = {0, 0, 0x1800, 0x3C00};

const u8 u8_ARRAY_08370240[4] = {0, 0, 0, 0};
