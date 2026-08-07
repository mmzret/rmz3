#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "element.h"
#include "vfx.h"
#include "physics.h"
#include "overworld.h"
#include "script.h"

extern const Coords16 ALIGNED(2) Coord_ARRAY_0836229a[4];

void summonPurpleNerple(struct Entity* e, s32 x);
struct Entity* CreateSmoke(u8 kind, struct Coord* c);
s32 FUN_08009f6c(s32 x, s32 y);
void CreateGhost35(s32 x, s32 y, u8 r2);
void CreateWormerRockDrone(s32 x, s32 y, u8 angle, u8 w2);
void FUN_08075c40(s32 x, s32 y, s32 dx, s32 dy);
void CreateGhost35(s32 x, s32 y, u8 r2);
void FUN_0807b124(s32 x, s32 y, s32 dx, s32 dy);

static const struct Collision sCollisions[15];
static const u8 sInitModes[4];

void Wormer_Init(struct Boss* p);
void Wormer_Update(struct Boss* p);
void Wormer_Die(struct Boss* p);

// clang-format off
const BossRoutine gWormerRoutine = {
    [ENTITY_INIT] =      (void*)Wormer_Init,
    [ENTITY_UPDATE] =    (void*)Wormer_Update,
    [ENTITY_DIE] =       (void*)Wormer_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on


const Coords32 Coord_08362264;
const Coords32 Coord_ARRAY_08362278[3];
static const BossFunc sUpdates1[11];
static const BossFunc sUpdates2[11];
const u8 u8_ARRAY_08362290[10];
void nop_080423e0(struct Body* _ UNUSED) { return; }

bool8 tryKillOrWormer(struct Boss* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    Wormer_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/boss/wormer_a.inc");

void Wormer_Update(struct Boss* p0) {
  register Boss* p asm("r5");
  register struct VFX** ep asm("r4");
  struct VFX* nv;
  p = p0;
  ep = (struct VFX**)((u8*)p + 0xbc);
  if (*ep != NULL) {
    if (!isKilled((struct Entity*)*ep)) {
      goto after;
    }
    nv = NULL;
    goto store;
  }
  if ((*(u32*)((u8*)p + 0x8c) & 1) == 0) {
    goto after;
  }
  if (p->work[0] != 1) {
    goto after;
  }
  nv = (struct VFX*)ApplyElementEffect(0xC, (struct CollisionObject*)p, &Coord_08362264);
store:
  *ep = nv;
after:
  if (p->work[0] == 0 && p->mode[1] != 1) {
    u16* t = (u16*)((u8*)p + 0xb8);
    s32 v = *t - 1;
    *t = v;
    if ((v << 16) == 0) {
      struct Camera* cam;
      s32 d;
      *t = 0xC0;
      cam = &gStageRun.vm.camera;
      d = ((RANDOM(RNG_0202f388) % 3) * 3) << 12;
      d -= 0x800;
      summonPurpleNerple((struct Entity*)p, cam->viewport.x + d);
    }
  }
  if (!tryKillOrWormer(p)) {
    (sUpdates1[p->mode[1]])(p);
    (sUpdates2[p->mode[1]])(p);
  }
}

void Wormer_Die(struct Boss* p) {
  switch (p->mode[1]) {
    case 0: {
      register s32 one asm("r4");
      {
        register u16 ms asm("r2");
        ms = gStageRun.missionStatus;
        one = 1;
        if ((one & ms) != 0) {
          register s32 av asm("r1");
          register s32 t2 asm("r0");
          av = gStageRun.vm.active;
          t2 = one;
          t2 &= av;
          if (t2 == 0) {
            gStageRun.missionStatus = (ms & 0xFFFE) | 0x10;
          }
        }
      }
      {
        register u8 g asm("r0");
        register u8 h asm("r1");
        h = p->flags;
        asm("" : "+r"(h));
        g = 1;
        one = 0;
        g |= h;
        p->flags = g;
      }
      SetMotion((struct Entity*)p, 0x2B08);
      p->work[2] = 0xff;
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
      p->flags &= 0xFB;
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      register u8 w2 asm("r2");
      UpdateEntityAnim((struct Entity*)p);
      p->work[2] = p->work[2] - 1;
      asm volatile("" ::: "memory");
      {
        register s32 wv asm("r0");
        register s32 sev asm("r1");
        wv = p->work[2];
        sev = 7;
        wv &= sev;
        if (wv != 0) {
          goto snd;
        }
      }
      {
        register s32 cx asm("r4");
        register u32* rp asm("r5");
        register u32 K asm("sb");
        register u32 C asm("r8");
        register u32 st asm("r6");
        struct Coord c;
        cx = p->coord.x + 0xFFFFEC00;
        c.x = cx;
        rp = &RNG_0202f388;
        {
          register u32 raw asm("r0");
          register u32 t asm("r1");
          raw = *rp;
          {
            register u32 k1 asm("r1");
            k1 = 0x343FD;
            asm volatile("mov %0, %1" : "=r"(K) : "l"(k1));
          }
          t = K;
          t *= raw;
          raw = t;
          {
            register u32 c1 asm("r1");
            c1 = 0x269EC3;
            asm volatile("mov %0, %1" : "=r"(C) : "l"(c1));
          }
          raw += C;
          raw <<= 1;
          st = raw >> 1;
          *rp = st;
          raw >>= 0x11;
          c.x = raw % (0xc0 << 6) + cx;
        }
        {
          register s32 cy asm("r2");
          register u32 raw2 asm("r0");
          cy = p->coord.y;
          raw2 = st * K;
          raw2 += C;
          raw2 <<= 1;
          *rp = raw2 >> 1;
          raw2 <<= 1;
          cy -= raw2 >> 0x12;
          c.y = cy;
        }
        CreateSmoke(1, &c);
      }
    snd:
      if (((u8)(p->work[2] % 0xc) << 24) == 0) {
        PlaySound(0x2A);
      }
      {
        register s32 sv asm("r0");
        asm volatile("mov r0, #0x12\n\tldrsb %0, [%1, r0]" : "=l"(sv) : "l"(p) : "r0");
        w2 = p->work[2];
        if (sv < 0) {
          goto skip;
        }
      }
      {
        register u8 g2 asm("r0");
        if ((w2 & 2) != 0) {
          register s32 k1 asm("r1");
          g2 = p->flags;
          k1 = 1;
          g2 |= k1;
        } else {
          register u8 h2 asm("r1");
          h2 = p->flags;
          asm("" : "+r"(h2));
          g2 = 0xFE;
          g2 &= h2;
        }
        p->flags = g2;
      }
    skip:
      {
        register s32 t3 asm("r0");
        t3 = w2 << 24;
        if (t3 != 0) {
          break;
        }
      }
      if (p->work[0] == 0) {
        TryDropItem(0xa, &p->coord);
      } else {
        TryDropItem(0xb, &p->coord);
      }
      gStageRun.vm.active |= 2;
      p->mode[1]++;
      break;
    }
    case 2:
      break;
  }
}

void nop_08042890(struct Boss* p) {}

void FUN_08042894(struct Boss* p) {
  if (p->work[0] == 1) {
    if (*(u32*)((u8*)p + 0x8c) & 1) {
      if ((*(u8*)((u8*)p + 0x97) & 0xf0) == 0x20) {
        p->mode[1] = 8;
        p->mode[2] = 0;
      }
    }
  }
}

void FUN_080428c4(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, sCollisions);
      p->flags &= ~DISPLAY;
      p->work[2] = 0x80;
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      u8 t = --p->work[2];
      if (t == 0) {
        p->mode[1] = 2;
        p->mode[2] = t;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_08042914(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      if (p->work[0] == 1) {
        *((u8*)&p->spr.oam + 5) |= 0xC;
      }
      p->flags &= ~DISPLAY;
      p->mode[2]++;
      // fallthrough
    case 1:
      if (p->scriptEntity->flags & 1) {
        p->mode[2]++;
      }
      break;
    case 2:
      p->mode[2] = 3;
      // fallthrough
    case 3:
      if (!(gStageRun.vm.active & 1)) {
        p->mode[1] = 2;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_08042984(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 w0 asm("r4");
      w0 = p->work[0];
      if (w0 == 1) {
        PlaySound(0x55);
        p->coord.x = *(s32*)((u8*)p + 0xc4);
        {
          register s32 f asm("r1");
          register s32 cx asm("r0");
          register s32 k asm("r1");
          f = *((u8*)p + 0xc0);
          if (f != 0) {
            register u8* oa asm("r2");
            *((u8*)p + 0x4c) = w0;
            oa = (u8*)p + 0x4a;
            *oa = *oa | 0x10;
            p->flags = 0x10 | p->flags;
            asm volatile("ldr %0, [%1, #0x54]" : "=l"(cx) : "l"(p));
            k = -0x6000;
          } else {
            register u8* oa2 asm("r2");
            register s32 m11 asm("r0");
            register s32 ov asm("r1");
            *((u8*)p + 0x4c) = f;
            oa2 = (u8*)p + 0x4a;
            ov = *oa2;
            m11 = 0x11;
            m11 = -m11;
            m11 &= ov;
            *oa2 = m11;
            {
              register u8 g asm("r0");
              register u8 h asm("r1");
              h = p->flags;
              asm("" : "+r"(h));
              g = 0xEF;
              g &= h;
              p->flags = g;
            }
            asm volatile("ldr %0, [%1, #0x54]" : "=l"(cx) : "l"(p));
            k = 0x6000;
          }
          p->coord.x = cx + k;
        }
        {
          register s32 xx asm("r0");
          asm volatile("ldr %0, [%1, #0x54]" : "=l"(xx) : "l"(p));
          *(s32*)((u8*)p + 0xb4) = FUN_08009f6c(xx, p->coord.y);
        }
      } else {
        PlaySound(0x55);
      }
      {
        register s32 z asm("r4");
        register u8* qb asm("r1");
        u8 v = *((u8*)p + 0xba);
        qb = (u8*)p + 0xbb;
        z = 0;
        *qb = v;
        SetDDP(&p->body, (const struct Collision*)(0x08362110 + p->work[0] * 0xa8));
        p->flags |= 1;
        {
          register s32 base asm("r0");
          register s32 off asm("r1");
          base = *(s32*)((u8*)p + 0xb4);
          off = 0x5400;
          p->coord.y = base + off;
        }
        p->d.y = -0x150;
        SetMotion((struct Entity*)p, 0xac << 6);
        p->work[2] = z;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32* pb;
      p->work[2] = p->work[2] + 1;
      {
        register u32 wv asm("r0");
        register u32 c1w asm("r1");
        wv = *(volatile u8*)&p->work[2];
        c1w = 1;
        wv &= c1w;
        pb = (s32*)((u8*)p + 0xb4);
        if (wv == 0) {
          register s32 t asm("r0");
          register s32 c2 asm("r1");
          t = RANDOM(RNG_0202f388) % 0x1800;
          c2 = -0xC00;
          asm("" : "+r"(c2));
          t += c2;
          CreateGhost35(p->coord.x + t, *pb, p->palID);
        }
      }
      {
        register s32 ny asm("r0");
        register s32 dy asm("r1");
        ny = p->coord.y;
        dy = p->d.y;
        ny += dy;
        p->coord.y = ny;
        if (ny < *pb) {
          p->coord.y = *pb;
          p->mode[2]++;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      SetMotion((struct Entity*)p, 0x2B01);
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      register s32 st asm("r1");
      {
        register struct Body* bd asm("r0");
        register u8* tbl asm("r2");
        register u8* q asm("r1");
        register s32 w0 asm("r3");
        register s32 k asm("r2");
        bd = &p->body;
        tbl = (u8*)0x0836226C;
        asm("" : "+r"(tbl));
        {
          register s32 idx asm("r1");
          idx = *((u8*)p + 0x71);
          asm("" : "+r"(idx));
          idx = (idx << 24) >> 24;
          q = (u8*)(idx + (s32)tbl);
        }
        w0 = p->work[0];
        k = w0 * 8 - w0;
        k += *q;
        {
          register s32 o asm("r1");
          register s32 cb asm("r2");
          o = k * 2;
          o += k;
          o <<= 3;
          cb = (s32)sCollisions;
          o += cb;
          SetDDP(bd, (const struct Collision*)o);
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      st = *((u8*)p + 0x73);
      if (st == 3) {
        p->mode[1] = st;
        p->mode[2] = 0;
      }
      break;
    }
  }
}

void FUN_08042b48(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, (const struct Collision*)((u8*)&sCollisions[5] + p->work[0] * 0xa8));
      p->work[2] = 2;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      if ((RANDOM(RNG_0202f388) & 3) == 0) {
        SetMotion((struct Entity*)p, 0x2B04);
      } else {
        SetMotion((struct Entity*)p, 0x2B03);
      }
      p->mode[2]++;
      FALLTHROUGH;
    case 2: {
      s32 r;
      UpdateEntityAnim((struct Entity*)p);
      if ((u8)(p->motion.state - 3) > 1) {
        break;
      }
      {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((u8)t == 0) {
          r = p->mode[2] + 1;
        } else {
          r = 1;
        }
      }
      p->mode[2] = r;
      break;
    }
    case 3:
      SetMotion((struct Entity*)p, 0x2B05);
      p->mode[2]++;
      FALLTHROUGH;
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      if (p->work[0] == 0) {
        if (*((u8*)p + 0xbb) != 0) {
          p->mode[1] = 6;
        } else {
          p->mode[1] = 4;
        }
      } else {
        u8* f0 = (u8*)p + 0xc0;
        u8 v = *f0;
        u8* f = f0;
        if (v != 0) {
          p->mode[1] = 0xA;
        } else {
          p->mode[1] = 9;
        }
        *f ^= 1;
      }
      p->mode[2] = 0;
      break;
  }
}

void FUN_08042c74(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[5 + 7 * p->work[0]]);
      SetMotion((struct Entity*)p, MOTION(0x2b, 6));
      p->work[2] = 4;
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      s32 x;
      s32 y;
      u32 n;
      p->work[3] = 0x18;
      PlaySound(0x2D);
      x = p->coord.x - 0x2600;
      y = p->coord.y - 0x4800;
      n = RANDOM(RNG_0202f388) % 0x28;
      n += 0x6c;
      CreateWormerRockDrone(x, y, n, p->palID);
      p->mode[2]++;
    }
      /* fallthrough */
    case 2: {
      s32 raw3 = p->work[3] - 1;
      p->work[3] = raw3;
      if ((raw3 << 24) == 0) {
        s32 raw2 = p->work[2] - 1;
        u8 t;
        p->work[2] = raw2;
        t = raw2;
        if (t == 0) {
          p->mode[1] = 5;
          p->mode[2] = t;
        } else {
          p->mode[2] = 1;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_08042d4c(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[5 + 7 * p->work[0]]);
      SetMotion((struct Entity*)p, MOTION(0x2b, 7));
      p->mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 7;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_08042da4(struct Boss* p) {
  s32 m = p->mode[2];
  switch (m) {
    case 0:
      SetDDP(&p->body, &sCollisions[5 + 7 * p->work[0]]);
      SetMotion((struct Entity*)p, MOTION(0x2b, 6));
      p->work[2] = m;
      p->mode[2]++;
      /* fallthrough */
    case 1:
      FUN_08075c40(p->coord.x - 0x2600, p->coord.y - 0x4000,
                   Coord_ARRAY_08362278[p->work[2]].x,
                   Coord_ARRAY_08362278[p->work[2]].y);
      p->work[3] = 0x10;
      p->mode[2]++;
      /* fallthrough */
    case 2: {
      u8 t = --p->work[3];
      if (t == 0) {
        s32 n = p->work[2] + 1;
        p->work[2] = n;
        if ((u8)n > 2) {
          p->mode[1] = 5;
          p->mode[2] = t;
        } else {
          p->mode[2] = 1;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_08042e54(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, 0x2B02);
      p->mode[2]++;
      /* fallthrough */
    case 1:
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08362290[p->motion.cmdIdx] + p->work[0] * 7]);
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 2:
      if (p->work[0] == 1) {
        PlaySound(0x55);
      } else {
        PlaySound(0x55);
      }
      SetDDP(&p->body, &sCollisions[1] + p->work[0] * 7);
      p->d.y = 0x2A0;
      SetMotion((struct Entity*)p, 0x2B00);
      p->work[2] = 0;
      p->mode[2]++;
      /* fallthrough */
    case 3: {
      s32 z6;
      s32* pb;
      {
        s32 raw = p->work[2] + 1;
        z6 = 0;
        p->work[2] = raw;
      }
      {
        register u32 wv asm("r0");
        register u32 c1w asm("r1");
        u32 tv;
        wv = *(volatile u8*)&p->work[2];
        c1w = 1;
        asm("" : "+r"(c1w));
        tv = wv & c1w;
        pb = (s32*)((u8*)p + 0xb4);
        if (tv == 0) {
        s32 t = (RANDOM(RNG_0202f388) % 0x1800) + -0xC00;
        s32 xx = p->coord.x + t;
        CreateGhost35(xx, *pb, p->palID);
        }
      }
      {
        s32 ny = p->coord.y + p->d.y;
        p->coord.y = ny;
        if (ny > *pb + 0x5400) {
          *((u8*)p + 0xba) = z6;
          p->coord.y = *pb + 0x5400;
          p->mode[1] = z6;
          p->mode[2] = z6;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_08042f9c(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0x2b, 3));
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[7 + 7 * p->work[0]]);
      p->work[2] = 0x20;
      p->mode[2]++;
      // fallthrough
    case 1:
      if (--p->work[2] == 0) {
        p->mode[1] = 7;
        p->mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/boss/wormer_b.inc");

void FUN_08043204(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x28;
      p->work[3] = 0;
      SetMotion((struct Entity*)p, MOTION(0x2b, 6));
      p->mode[2]++;
      // fallthrough
    case 1:
      if (p->work[2] == 0) {
        p->mode[2]++;
        break;
      }
      if (p->work[2] % 10 == 0) {
        PlaySound(SE_BLIZZACK_BOMB);
        FUN_0807b124(p->coord.x + 0x2C00, p->coord.y - 0x4600, Coord_ARRAY_0836229a[p->work[3]].x,
                     Coord_ARRAY_0836229a[p->work[3]].y);
        p->work[3]++;
      }
      p->work[2]--;
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 2:
      p->work[2] = 0x20;
      p->mode[2]++;
      // fallthrough
    case 3:
      if (--p->work[2] == 0) {
        p->mode[1] = 5;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

// --------------------------------------------

void nop_08042890(struct Boss* p);
void FUN_08042894(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[11] = {
    nop_08042890,
    nop_08042890,
    nop_08042890,
    FUN_08042894,
    FUN_08042894,
    FUN_08042894,
    FUN_08042894,
    nop_08042890,
    nop_08042890,
    FUN_08042894,
    FUN_08042894,
};
// clang-format on

// --------------------------------------------

void FUN_080428c4(struct Boss* p);
void FUN_08042914(struct Boss* p);
void FUN_08042984(struct Boss* p);
void FUN_08042b48(struct Boss* p);
void FUN_08042c74(struct Boss* p);
void FUN_08042d4c(struct Boss* p);
void FUN_08042da4(struct Boss* p);
void FUN_08042e54(struct Boss* p);
void FUN_08042f9c(struct Boss* p);
void FUN_08042ff8(struct Boss* p);
void FUN_08043204(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[11] = {
    FUN_080428c4,
    FUN_08042914,
    FUN_08042984,
    FUN_08042b48,
    FUN_08042c74,
    FUN_08042d4c,
    FUN_08042da4,
    FUN_08042e54,
    FUN_08042f9c,
    FUN_08042ff8,
    FUN_08043204,
};
// clang-format on

// 0x083620f8
static const struct Collision sCollisions[15] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1B00, 0x1B00, 0x5800},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x4000, 0x2800, 0x1300},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1B00, 0x3A00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x3500, 0x2800, 0x1300},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0200, -0x1300, 0x1B00, 0x2E00},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1B00, 0x1B00, 0x5800},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x4000, 0x2800, 0x1300},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1B00, 0x3A00},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x3500, 0x2800, 0x1300},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0200, -0x1300, 0x1B00, 0x2E00},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
};

static const u8 sInitModes[4] = {1, 1, 0, 0};

const Coords32 Coord_08362264 = {-0xA00, -0x2000};

const u8 u8_ARRAY_0836226c[10] = {
    1, 1, 1, 1, 3, 3, 5, 5, 5, 5,
};

const Coords32 Coord_ARRAY_08362278[3] = {
    {-0x180, -0x400},
    {-0x280, -0x480},
    {-0x380, -0x500},
};

const u8 u8_ARRAY_08362290[10] = {
    5, 5, 5, 5, 3, 3, 1, 1, 1, 1,
};

const Coords16 ALIGNED(2) Coord_ARRAY_0836229a[4] = {
    {0x080, -0x200},
    {0x140, -0x280},
    {0x200, -0x300},
    {0x2C0, -0x380},
};
