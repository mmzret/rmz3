#include "boss/anubis.h"

#include "boss.h"
#include "collision.h"
#include "global.h"
#include "element.h"
#include "vfx.h"
#include "physics.h"
#include "script.h"
#include "trig.h"
#include "stagerun.h"
#include "zero.h"

void FUN_08010188(s32 n);
NON_MATCH bool8 FUN_080500f4(Anubis* p);
void FUN_080bf3d8(struct Entity* p);
void FUN_080a4ef8(struct Entity* p);
NON_MATCH void FUN_08050090(Anubis* p);
void createPantheonZombie(struct Boss* anubis, s32 x, s32 y);
struct Entity* CreateBossExplosion(struct Entity* boss, struct Coord* c);


void Anubis_Update(Anubis* p);
void CreateAnubisCoffins(struct Boss* p, u8 a);
struct Entity* FUN_080b2b40(u8 kind, struct Coord* c, s32 r2, u8 r3);
static const struct Collision sCollisions[3];
static void (*const sDeads[2])(Anubis*);
static const Coords32 sElementCoord;
static const u8 sInitModes[4];
static void (*const sUpdates1[11])(Anubis*);
static void (*const sUpdates2[11])(Anubis*);
static const u8 u8_ARRAY_083635c9[8];
NON_MATCH void FUN_08050090(Anubis* p) {
#if MODERN
  s32 base;
  *(u16*)((u8*)p + 0xc8) += 0x200;
  base = *(s32*)((u8*)p + 0xc4);
  p->coord.y = base + (SIN(*(u16*)((u8*)p + 0xc8) >> 8) << 2);
#else
  INCCODE("asm/boss/anubis_08050090_body.inc");
#endif
}

void FUN_080500c8(struct Body* body) {
  Anubis* atk = (Anubis*)((body->enemy)->parent);
  Anubis* self = (Anubis*)body->parent;
  if (body->hitboxFlags & 1) {
    u8 r = 0;
    if (self->coord.x < atk->coord.x) {
      r = 1;
    }
    *(u8*)((u8*)self + 0xcc) = r;
  }
}

NON_MATCH bool8 FUN_080500f4(Anubis* p0) {
#if MODERN
  register Anubis* p asm("r4");
  register u32* st asm("r7");
  p = p0;
  st = (u32*)((u8*)p + 0x8c);
  if ((*st & 0x200) == 0 && *(s16*)((u8*)p + 0xa4) != 0) {
    return 0;
  }
  {
    register u16 f asm("r6");
    { u16 ms = gStageRun.missionStatus; s32 m_ = 8; m_ &= ms; f = m_; }
    if (f != 0) {
      return 0;
    }
    {
      s16* sp = (s16*)((u8*)p + 0xd0);
      if (*sp != -1) {
        StopSound(*sp);
        *sp = -1;
      }
    }
    {
      u8* q = (u8*)p + 0xce;
      if (*q != 0) {
        *q = f;
        FUN_08010188(0);
      }
    }
    SET_BOSS_ROUTINE(p, 2);
    {
      s32 v = *st & 0x10000;
      if (v != 0) {
        p->mode[1] = 1;
      } else {
        p->mode[1] = v;
      }
    }
    Anubis_Die(p);
    return 1;
  }
#else
  INCCODE("asm/boss/anubis_080500f4.inc");
#endif
}

void Anubis_Init(Anubis* p) {
  s32 z5;
  {
    u32 tbl = (u32)gBossFnTable;
    u32 id = (p->id) << 2;
    EntityFunc** rt = (EntityFunc**)(tbl + id);
    register u32 one asm("r1");
    one = 1;
    *(u32*)(p->mode) = one;
    p->onUpdate = (void*)((*rt)[1]);
  }
  {
    u8 m = sInitModes[p->work[0]];
    z5 = 0;
    p->mode[1] = m;
  }
  {
    u32 fl = p->flags;
    fl |= 2;
    asm("" : "+r"(fl));
    fl |= 1;
    p->flags = fl;
  }
  InitNonAffineMotion((struct Entity*)p);
  ResetDynamicMotion((struct Entity*)p);
  ResetBossBody((struct Boss*)p, sCollisions, 0x40);
  {
    void* f = (void*)FUN_080500c8;
    u8* b = (u8*)p + 0x74;
    *(void**)(b + 0x24) = f;
    asm("" : "+r"(b));
    b += 0x40;
    asm("" : "+r"(b));
    *(u32*)b = z5;
  }
  if (p->work[0] != 1) {
    {
      s32* pb = (s32*)((u8*)p + 0xb8);
      s32 cx = p->coord.x >> 8;
      s32 q;
      *pb = cx;
      q = cx / 0xF0;
      *pb = (((q << 4) - q) << 12) + 0x7800;
      asm("" : "+r"(pb));
      pb += 1;
      {
        s32 cy = p->coord.y >> 8;
        s32 q2;
        *pb = cy;
        q2 = cy / 0xA0;
        q2 += 1;
        *pb = ((q2 << 2) + q2) << 13;
      }
    }
    {
      u8* w = (u8*)p + 0xc0;
      s32 z1;
      *(u32*)w = z5;
      asm("" : "+r"(w));
      w += 8;
      z1 = 0;
      *(u16*)w = z5;
      asm("" : "+r"(w));
      w += 2;
      *w = z1;
      asm("" : "+r"(w));
      w += 1;
      *w = z1;
      *((u8*)p + 0xcd) = 0x40;
      {
        u8* w2 = (u8*)p + 0xce;
        *w2 = z1;
        asm("" : "+r"(w2));
        w2 += 1;
        *w2 = z1;
      }
    }
    LOAD_STATIC_GRAPHIC(SM073_ANUBIS_ROD);
    LOAD_STATIC_GRAPHIC(SM074_ANUBIS_SAND);
    {
      u16* a2 = (u16*)((u8*)p + 0xd0);
      register u32 v asm("r0");
      v = 0xFFFF;
      *a2 = v;
    }
    *((u8*)p + 0xd2) = 1;
  }
  Anubis_Update(p);
}

void Anubis_Update(Anubis* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  struct Entity* e;
  u8* t;
  s32 v;
  if (*slot != NULL) {
    if (!isKilled(*slot)) {
      goto next;
    }
    e = NULL;
  } else {
    if (!((p->body).status & 1)) {
      goto next;
    }
    e = (struct Entity*)ApplyElementEffect(0x14, (struct CollisionObject*)p, &sElementCoord);
  }
  *slot = e;
next:
  t = (u8*)((u8*)p + 0xca);
  if (*t != 0) {
    v = *t - 1;
  } else {
    if (!((pZero2->body).status & 1)) {
      goto skip;
    }
    v = 0x60;
  }
  *t = v;
skip:
  if (FUN_080500f4(p)) {
    return;
  }
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

void Anubis_Die(Anubis* p) {
  (sDeads[p->mode[1]])(p);
}

void nop_080503c8(Anubis* p) {}

void anubisMode0(Anubis* p) {
  switch (p->mode[2]) {
    case 0: {
      u32 f0 = p->flags;
      u32 t0 = 0xFE;
      t0 &= f0;
      p->flags = t0;
      if (p->work[0] == 0) {
        LOAD_STATIC_GRAPHIC(SM075_ANUBIS_COFFIN);
        {
          s32* c = (s32*)((u8*)p + 0xbc);
          register s32 n asm("r1");
          register s32 q asm("r0");
          p->coord.y = *c + -0xC000;
          SetMotion((struct Entity*)p, 0xAF0C);
          {
            register s32 cv asm("r0");
            cv = *c;
            n = cv + -0x7600;
          }
          n -= p->coord.y;
          q = n;
          if (n < 0) {
            q = n + 3;
          }
          q >>= 2;
          p->d.y = ((u32)Sqrt(q) << 16) >> 13;
        }
        FUN_080bf3d8((struct Entity*)p);
        p->work[2] = 0x10;
        p->mode[2]++;
      } else {
        s32* c = (s32*)((u8*)p + 0xbc);
        s32 y = *c + -0x7600;
        p->coord.y = y;
        *(s32*)((u8*)p + 0xc4) = y;
        p->mode[2] = 6;
        break;
      }
      FALLTHROUGH;
    }
    case 1: {
      s32 dy = p->d.y;
      if (dy < 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          goto upd;
        }
        p->flags |= 1;
        {
          u32* a = (u32*)((u8*)p + 0xc0);
          *a |= 1;
        }
        goto inc2;
      }
      p->coord.y += dy;
      p->d.y = dy - 8;
      goto upd;
    }
    case 2:
      *(s32*)((u8*)p + 0xc4) = p->coord.y;
      p->work[2] = 0x64;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      goto inc2b;
    }
    case 4:
      SetMotion((struct Entity*)p, 0xAF0D);
      p->mode[2]++;
      goto st;
    case 6:
      {
        u32 f6 = p->flags;
        u32 t6 = 1;
        t6 |= f6;
        p->flags = t6;
      }
      FUN_080a4ef8((struct Entity*)p);
      SetMotion((struct Entity*)p, 0xAF01);
      p->mode[2]++;
      FALLTHROUGH;
    case 7:
      FUN_08050090(p);
      if ((p->scriptEntity->flags & 1) == 0) {
        goto upd;
      }
    inc2:
      p->mode[2]++;
    upd:
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 8:
      SetMotion((struct Entity*)p, 0xAF02);
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
    case 9:
    st:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    inc2b:
      p->mode[2]++;
      break;
    case 10:
      SetMotion((struct Entity*)p, 0xAF01);
      p->mode[2]++;
      FALLTHROUGH;
    case 11: {
      register s32 one asm("r4");
      register s32 m asm("r0");
      register s32 g asm("r1");
      FUN_08050090(p);
      g = gStageRun.vm.active;
      one = 1;
      m = one;
      m &= g;
      if (m == 0) {
        SetDDP(&p->body, (const struct Collision*)0x08363584);
        p->mode[1] = one;
        p->mode[2] = one;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

INCASM("asm/boss/anubis_a.inc");

void anubisMode2(Anubis* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 k asm("r1");
      u32* st;
      u32 v;
      *(u16*)((u8*)p + 0xd0) = PlaySound(0x54);
      st = (u32*)((u8*)p + 0xc0);
      v = *st;
      k = 2;
      v |= k;
      k -= 7;
      v &= k;
      k -= 0xc;
      v &= k;
      *st = v;
      SetMotion((struct Entity*)p, 0xAF02);
      p->mode[2]++;
    }
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)*(u8*)((u8*)p + 0x71) == 3) {
        p->mode[2]++;
      }
      break;
    case 2: {
      u32* st2 = (u32*)((u8*)p + 0xc0);
      s32 dx;
      *st2 &= -3;
      {
        s32 dx0 = 0x200;
        *(volatile s32*)&p->d.x = dx0;
        asm volatile("add %0, %1, #0" : "=&l"(dx) : "l"(dx0));
      }
      if (p->flags & 0x10) {
        dx = -0x200;
      }
      p->d.x = dx;
      p->mode[2]++;
    }
      /* fallthrough */
    case 3:
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) > 0x2000) {
        u8 z = 0;
        p->mode[1] = 3;
        p->mode[2] = z;
      }
      break;
  }
}

void anubisMode3(Anubis* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x3C;
      UpdateEntityAnim((struct Entity*)p);
      p->mode[2]++;
      // fallthrough
    case 1: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) == 0) {
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      u32 sv;
      u32 xf;
      u32 xf2;
      s32 k16;
      {
        u32* st = (u32*)((u8*)p + 0xc0);
        *st |= 4;
      }
      sv = (u16)Sqrt(0x680);
      p->work[2] = sv;
      p->d.x = sv << 4;
      xf = ((p->flags >> 4) ^ 1) & 1;
      (p->spr).xflip = xf;
      xf2 = ((p->flags >> 4) ^ 1) & 1;
      {
        register u8* oa asm("r5");
        u32 sh4;
        s32 ov, m11;
        oa = (u8*)p + 0x4a;
        sh4 = xf2 << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
      }
      if (xf2 != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
      {
        u32 fl2 = p->flags;
        register u32 res asm("r0");
        k16 = 0x10;
        asm("" : "+r"(k16));
        res = k16;
        asm volatile("" : "+r"(res));
        res &= fl2;
        if (res == 0) {
          goto arm2;
        }
      }
      if (1) {
        p->coord.x = *(s32*)((u8*)p + 0xb8) - 0x9800;
        p->unk_coord.x = -0x10;
      } else {
      arm2:
        p->coord.x = *(s32*)((u8*)p + 0xb8) + 0x9800;
        p->d.x = -p->d.x;
        p->unk_coord.x = k16;
      }
      SetMotion((struct Entity*)p, 0xAF01);
      p->mode[2]++;
    }
      // fallthrough
    case 3: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) == 0) {
        p->mode[2]++;
      }
      p->coord.x += p->d.x;
      p->d.x += p->unk_coord.x;
      FUN_08050090(p);
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 4:
      FUN_08050090(p);
      UpdateEntityAnim((struct Entity*)p);
      if ((*(u32*)((u8*)p + 0xc0) & 4) == 0) {
        s16* snd = (s16*)((u8*)p + 0xd0);
        register s32 v asm("r1");
        v = *snd;
        if (v != -1) {
          u32 mv;
          StopSound(v);
          mv = 0xFFFF;
          asm("" : "+r"(mv));
          *snd = mv;
        }
        p->mode[1] = 1;
        p->mode[2] = 1;
      }
      break;
  }
}

void anubisMode4(Anubis* p0) {
  register Anubis* p asm("r4");
  s32 m;
  p = p0;
  switch (p->mode[2]) {
    case 0: {
      s16 sv;
      u32* st;
      register u32 v asm("r0");
      register s32 k asm("r1");
      sv = PlaySound(SE_ANUBIS_BOOMERANG);
      *(s16*)((u8*)p + 0xd0) = sv;
      st = (u32*)((u8*)p + 0xc0);
      v = *st;
      k = 8;
      v |= k;
      k = 0x10;
      v |= k;
      *st = v;
      SetMotion((struct Entity*)p, 0xAF02);
      p->mode[2]++;
    }
      // fallthrough
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (*(u8*)((u8*)p + 0x73) != 3) {
        break;
      }
      m = p->mode[2] + 1;
      goto store;
    case 2: {
      u32* st = (u32*)((u8*)p + 0xc0);
      *st &= -9;
      SetMotion((struct Entity*)p, 0xAF01);
      p->mode[2]++;
    }
      // fallthrough
    case 3:
      FUN_08050090(p);
      UpdateEntityAnim((struct Entity*)p);
      if ((*(u32*)((u8*)p + 0xc0) & 0x10) == 0) {
        s16* snd = (s16*)((u8*)p + 0xd0);
        register s32 v asm("r1");
        v = *snd;
        if (v != -1) {
          u32 mv;
          StopSound(v);
          mv = 0xFFFF;
          asm("" : "+r"(mv));
          *snd = mv;
        }
        m = 1;
        p->mode[1] = m;
      store:
        p->mode[2] = m;
      }
      break;
  }
}

void anubisMode5(Anubis* p) {
  switch (p->mode[2]) {
    case 0:
      if (p->unk_cc[2] != 0) {
        UpdateEntityAnim((struct Entity*)p);
        p->mode[1] = 1;
        p->mode[2] = 2;
        p->work[2] = 2;
        break;
      }
      SetDDP(&p->body, sCollisions);
      {
        u32 v = p->unk_c0;
        v |= 0x100;
        asm("" : "+r"(v));
        v |= 0x20;
        v &= ~0x40;
        p->unk_c0 = v;
      }
      SetMotion((struct Entity*)p, MOTION(0xAF, 0x08));
      p->mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->unk_c0 &= ~0x100;
        p->mode[1] = 6;
        p->mode[2] = 0;
      }
      break;
  }
}

void anubisMode6(Anubis* p) {
  switch (p->mode[2]) {
    case 0: {
      register const u8* tb asm("r3");
      s32 r;
      p->flags &= 0xFE;
      LOAD_STATIC_GRAPHIC(SM075_ANUBIS_COFFIN);
      tb = u8_ARRAY_083635c9;
      r = RANDOM(RNG_0202f388) & 7;
      if (*(s16*)((u8*)p + 0xa4) <= 0x1F) {
        r += 8;
      }
      {
        register s32 idx asm("r1");
        register const u8* e asm("r0");
        idx = r;
        asm volatile("add %0, %1, %2" : "=l"(e) : "l"(idx), "l"(tb));
        p->work[2] = *e;
      }
      p->work[3] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 t0 asm("r0");
      register s32 w2 asm("r1");
      if ((u8)--p->work[3] != 0) {
        break;
      }
      p->work[3] = 0x60;
      t0 = p->work[2] - 1;
      p->work[2] = t0;
      t0 <<= 24;
      w2 = (u32)t0 >> 24;
      if (w2 == 0) {
        p->mode[1] = 7;
        p->mode[2] = w2;
      } else {
        p->mode[2] = 1;
      }
      PlaySound(0x55);
      {
        register s32 f asm("r1");
        f = 0;
        if (p->work[2] == 0) {
          f = 1;
        }
        ((void (*)(Anubis*, s32))CreateAnubisCoffins)(p, f);
      }
      break;
    }
  }
}

void anubisMode7(Anubis* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x60;
      p->mode[2]++;
      /* fallthrough */
    case 1:
      if ((u8)--p->work[2] != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 2:
      p->unk_c0 = (p->unk_c0 & ~0x20) | 0x40;
      p->flags |= DISPLAY;
      SetMotion((struct Entity*)p, MOTION(0xAF, 0x0E));
      p->mode[2]++;
      /* fallthrough */
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        u16 h = (p->body).hp;
        u8* a = &p->unk_cc[1];
        s32 z = 0;
        *a = h;
        p->mode[1] = 1;
        p->mode[2] = z;
      }
      break;
  }
}

void anubisMode8(Anubis* p) {
  register u32* fp asm("r8");
  s32 off;
  switch (p->mode[2]) {
    case 0:
      PlaySound(0x53);
      p->work[2] = 0x3C;
      SetMotion((struct Entity*)p, MOTION(0xAF, 0x03));
      *(u32*)((u8*)p + 0xc0) |= 0x80;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 t = p->work[2];
      fp = (u32*)((u8*)p + 0xc0);
      if (t == 0) {
        goto upd;
      }
      t--;
      p->work[2] = t;
      if ((u8)t != 0) {
        goto upd;
      }
      LOAD_STATIC_GRAPHIC(SM076_PANTHEON_ZOMBIE);
      {
        register s32 cnt asm("r6");
        register u32 rnd asm("r1");
        register u32 acc asm("r0");
        u32 rv;
        rnd = RNG_0202f388;
        acc = 0x343FD;
        acc *= rnd;
        acc += 0x269EC3;
        rv = acc << 1;
        asm("" : "+r"(rv));
        RNG_0202f388 = rv >> 1;
        {
          register u32 b1 asm("r1");
          register s32 n1 asm("r0");
          b1 = rv >> 0x11;
          n1 = 1;
          b1 &= n1;
          n1 = b1 + 1;
          if (n1 == 0) {
            goto snd;
          }
          off = 0;
          cnt = n1;
        }
        do {
          register s32 x asm("r4");
          register s32 b asm("r0");
          s32 y;
          {
            register struct Zero* z asm("r0");
            z = pZero2;
            x = (z->s).coord.x;
          }
          x += -0x3200;
          x += off;
          {
            register u8* bp asm("r0");
            bp = (u8*)p;
            asm("" : "+r"(bp));
            bp += 0xb8;
            b = *(s32*)bp;
          }
          {
            register s32 lo asm("r1");
            lo = b + -0x7000;
            if (x < lo) {
              x = lo;
            }
          }
          b += 0xE0 * 128;
          if (x > b) {
            x = b;
          }
          y = FUN_08009f6c(x, p->coord.y);
          createPantheonZombie((struct Boss*)p, x, y);
          off += 0xC8 * 128;
          cnt--;
        } while (cnt != 0);
      }
    snd:
      PlaySound(0x55);
    upd:
      UpdateEntityAnim((struct Entity*)p);
      asm volatile("" ::"r"(off));
      {
        register s32 f asm("r1");
        register s32 k asm("r0");
        f = *fp;
        k = 0x80;
        f &= k;
        if (f == 0) {
          p->mode[1] = 1;
          p->mode[2] = f;
        }
      }
      break;
    }
  }
}

void FUN_08050e44(Anubis* p) {
  struct Entity* e = p->unk_28;
  register s32 m asm("r1");
  m = p->mode[2];
  switch (m) {
    case 0: {
      s32 k10;
      register s32 z6 asm("r6");
      {
        register u8 f2 asm("r0");
        f2 = p->flags2;
        k10 = 0x10;
        asm("" : "+r"(k10));
        z6 = 0;
        f2 |= k10;
        p->flags2 = f2;
      }
      p->invincibleID = e->uniqueID;
      {
        u8* a = (u8*)p + 0x8c;
        *(s32*)a = m;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = m;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = m;
      }
      p->flags &= ~4;
      {
        register s32 one asm("r2");
        register s32 xv asm("r1");
        u32 t0 = e->flags;
        t0 >>= 4;
        one = 1;
        t0 &= one;
        (p->spr).xflip = t0;
        xv = (u32)e->flags >> 4;
        xv &= one;
        {
          register u8* oa asm("ip");
          s32 sh4, ov, m11;
          oa = (u8*)p + 0x4a;
          sh4 = xv << 4;
          ov = *oa;
          m11 = -0x11;
          m11 &= ov;
          m11 |= sh4;
          *oa = m11;
        }
        if (xv != 0) {
          register u8 g asm("r0");
          g = p->flags;
          g |= k10;
          p->flags = g;
        } else {
          register u8 h asm("r1");
          register u8 g2 asm("r0");
          h = p->flags;
          asm("" : "+r"(h));
          g2 = 0xEF;
          g2 &= h;
          p->flags = g2;
        }
      }
      SetMotion((struct Entity*)p, 0xAF07);
      p->mode[2]++;
      asm volatile("" : "+l"(z6));
      FALLTHROUGH;
    }
    case 1: {
      register s32 dx asm("r1");
      {
        s32 cx = p->coord.x;
        dx = p->d.x;
        p->coord.x = cx + dx;
      }
      {
        register s32 k asm("r0");
        if (p->work[3] != 0) {
          k = 0xF6;
        } else {
          k = 0xFA;
        }
        p->d.x = dx * k / 256;
      }
      FUN_0801779c((struct Entity*)p);
      if (e->mode[0] == 4) {
        register u8 g asm("r0");
        register u8 h asm("r1");
        register s32 zr asm("r2");
        u8* a;
        h = p->flags;
        asm("" : "+r"(h));
        g = 0xFE;
        g &= h;
        zr = 0;
        h = 0xFD;
        g &= h;
        p->flags = g;
        a = (u8*)p + 0x8c;
        *(s32*)a = zr;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = zr;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = zr;
        p->flags &= ~4;
        SET_BOSS_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void anubis_08050f38(Anubis* p) {
  switch (p->mode[2]) {
    case 0:
      PlaySound(0x53);
      *((u8*)p + 0xcf) = 2;
      *(u32*)((u8*)p + 0xc0) |= 0x100;
      p->work[2] = 0x1E;
      SetMotion((struct Entity*)p, MOTION(0xAF, 0x03));
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      t <<= 24;
      if (t == 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2: {
      register u8* pc asm("r5");
      s32 v;
      {
        register u8* pc0 asm("r0");
        register u8 cv asm("r1");
        pc0 = (u8*)p + 0xce;
        cv = *pc0;
        asm volatile("add %0, %1, #0" : "=&l"(pc) : "l"(pc0));
        if (cv != 0) {
          v = 0;
        } else {
          v = RANDOM(RNG_0202f388) % 3 + 1;
        }
      }
      *pc = v;
      FUN_08010188(*pc);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      register u32 rv asm("r3");
      rv = FUN_080101a8();
      if (rv == 0) {
        *(u32*)((u8*)p + 0xc0) &= ~0x100;
        p->mode[1] = 1;
        p->mode[2] = rv;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void anubis_08051018(Anubis* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 one asm("r5");
      {
        u8* a = (u8*)p + 0x8c;
        s32 z = 0;
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
      p->flags &= ~COLLIDABLE;
      {
        register u16 ms asm("r2");
        register s32 t asm("r0");
        ms = gStageRun.missionStatus;
        one = 1;
        asm volatile("add %0, %1, #0" : "=&l"(t) : "l"(one));
        t &= ms;
        if (t != 0) {
          register u8 av asm("r1");
          register s32 t2 asm("r0");
          av = gStageRun.vm.active;
          asm volatile("add %0, %1, #0" : "=&l"(t2) : "l"(one));
          t2 &= av;
          if (t2 == 0) {
            gStageRun.missionStatus = (ms & 0xFFFE) | MISSION_SUCCESS;
          }
        }
      }
      p->work[2] = 0x50;
      SetMotion((struct Entity*)p, MOTION(0xAF, 0x04));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      p->work[2]--;
      if ((p->scriptEntity->flags & 0x80) == 0) {
        break;
      }
      goto inc;
    case 2:
      p->unk_2c = CreateBossExplosion((struct Entity*)p, (struct Coord*)0x083635DC);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if ((p->unk_2c)->mode[0] <= 1) {
        break;
      }
      gStageRun.vm.active |= 2;
    inc:
      p->mode[2]++;
      break;
    case 4:
      break;
  }
}

void anubis_080510f0(Anubis* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 dir asm("r6");
      struct Entity* e;
      PlaySound(0x2f);
      dir = *((u8*)p + 0xcc);
      e = AllocEntityLast(gBossHeaderPtr);
      if (e != NULL) {
        register s32 z asm("r2");
        register s32 z0 asm("r0");
        {
          register u8* tc asm("r1");
          tc = (u8*)e + 0x25;
          z = 0;
          z0 = 0x18;
          *tc = z0;
        }
        {
          register const BossFunc** tb asm("r1");
          tb = (const BossFunc**)gBossFnTable;
          e->id = 0xb;
          e->onUpdate = (void*)tb[0xb][0];
        }
        z0 = 0;
        *(u16*)((u8*)e + 0x20) = z;
        *((u8*)e + 0x22) = z0;
        {
          register s32 h asm("r1");
          register s32 g asm("r0");
          h = e->flags2;
          asm("" : "+r"(h));
          g = 0x10;
          g |= h;
          e->flags2 = g;
        }
        *((u8*)e + 0x1d) = *((u8*)e + 0x1c);
        e->coord.x = p->coord.x;
        e->coord.y = p->coord.y;
        {
          register s32 v asm("r0");
          register s32 sh asm("r1");
          v = 0x80 << 1;
          sh = dir << 9;
          v -= sh;
          e->d.x = v;
        }
        e->unk_28 = (struct Entity*)p;
        {
          register s32 one asm("r1");
          register s32 fv asm("r0");
          one = 1;
          *((u8*)e + 0x10) = one;
          fv = (u32)p->flags >> 4;
          fv &= one;
          fv ^= dir;
          *((u8*)e + 0x13) = fv;
        }
      }
      SetMotion((struct Entity*)p, 0xAF06);
      {
        register u8* a asm("r0");
        register s32 z1 asm("r1");
        a = (u8*)p + 0x8c;
        z1 = 0;
        asm volatile("str %0, [%1]" ::"l"(z1), "l"(a) : "memory");
        a += 4;
        asm("" : "+r"(a));
        asm volatile("str %0, [%1]" ::"l"(z1), "l"(a) : "memory");
        a += 4;
        asm("" : "+r"(a));
        *a = z1;
      }
      {
        register u8 h2 asm("r1");
        register u8 g2 asm("r0");
        h2 = p->flags;
        asm("" : "+r"(h2));
        g2 = 0xFB;
        g2 &= h2;
        p->flags = g2;
      }
      {
        if ((gStageRun.missionStatus & 1) != 0) {
          if ((*((u8*)&gStageRun + 0x12) & 1) == 0) {
            gStageRun.missionStatus = (gStageRun.missionStatus & 0xFFFE) | 0x10;
          }
        }
      }
      {
        register s32 v2 asm("r0");
        register s32 sh2 asm("r1");
        v2 = 0x80 << 1;
        sh2 = dir << 9;
        v2 -= sh2;
        p->d.x = v2;
      }
      {
        struct Coord c;
        c.x = p->coord.x;
        c.y = p->coord.y;
        ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x80 << 2, dir);
      }
      p->work[2] = 0x32;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dv asm("r2");
      register s32 dir2 asm("r3");
      p->coord.x += p->d.x;
      dv = p->d.x;
      dir2 = *((u8*)p + 0xcc);
      {
        register s32 m asm("r0");
        if ((p->flags & 0x10) != 0) {
          if (dir2 != 1) {
            goto fast;
          }
          goto slow;
        } else {
          if (dir2 == 0) {
            goto slow;
          }
        fast:
          m = 0xfa;
          goto mul;
        }
      slow:
        m = 0xf6;
      mul:
        m = dv * m;
        if (m < 0) {
          m += 0xff;
        }
        p->d.x = m >> 8;
      }
      p->work[2]--;
      if ((p->scriptEntity->flags & 0x80) != 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      p->unk_2c = (struct Entity*)CreateBossExplosion((struct Entity*)p, (struct Coord*)0x083635E4);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if ((p->unk_2c)->mode[0] <= 1) {
        break;
      }
      {
        register struct StageRun* sr2 asm("r2");
        register s32 g3 asm("r0");
        register s32 h3 asm("r1");
        sr2 = &gStageRun;
        h3 = *((u8*)sr2 + 0x12);
        asm("" : "+r"(h3));
        g3 = 2;
        g3 |= h3;
        *((u8*)sr2 + 0x12) = g3;
      }
      p->mode[2]++;
      break;
    case 4:
      break;
  }
}

void Anubis_Init(Anubis* p);
void Anubis_Update(Anubis* p);
void Anubis_Die(Anubis* p);

// clang-format off
const BossRoutine gAnubisRoutine = {
    [ENTITY_INIT] =      (void*)Anubis_Init,
    [ENTITY_UPDATE] =    (void*)Anubis_Update,
    [ENTITY_DIE] =       (void*)Anubis_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080503c8(Anubis* p);

// clang-format off
static void (*const sUpdates1[11])(Anubis*) = {
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
};
// clang-format on

void anubisMode0(Anubis* p);
void anubisNeutral(Anubis* p);
void anubisMode2(Anubis* p);
void anubisMode3(Anubis* p);
void anubisMode4(Anubis* p);
void anubisMode5(Anubis* p);
void anubisMode6(Anubis* p);
void anubisMode7(Anubis* p);
void anubisMode8(Anubis* p);
void FUN_08050e44(Anubis* p);
void anubis_08050f38(Anubis* p);

// clang-format off
static void (*const sUpdates2[11])(Anubis*) = {
    anubisMode0,
    anubisNeutral,
    anubisMode2,
    anubisMode3,
    anubisMode4,
    anubisMode5,
    anubisMode6,
    anubisMode7,
    anubisMode8,
    FUN_08050e44,
    anubis_08050f38,
};
// clang-format on

void anubis_08051018(Anubis* p);
void anubis_080510f0(Anubis* p);

static void (*const sDeads[2])(Anubis*) = {
    anubis_08051018,
    anubis_080510f0,
};

// --------------------------------------------

// 0x0836356c
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(52)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(52)},
    },
};

// 0x083635b4
static const u8 sInitModes[4] = {0, 9, 0, 0};

// 0x083635b8
static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};

static const u8 u8_ARRAY_083635c0[9] = {5, 2, 10, 4, 5, 8, 2, 10, 4};
static const u8 u8_ARRAY_083635c9[8] = {2, 2, 2, 2, 3, 3, 3, 3};
static const u8 u8_ARRAY_083635d1[8] = {2, 2, 3, 3, 3, 4, 4, 4};

// 0x083635dc
static const Coords32 sExplosionCoords[2] = {
    {PIXEL(2), -PIXEL(8)},
    {PIXEL(4), -PIXEL(6)},
};
