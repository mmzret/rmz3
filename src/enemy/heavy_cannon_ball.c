#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "story.h"
#include "stagerun.h"
#include "zero.h"

void FUN_0807aae8(struct Body* body, struct Coord* r1, struct Coord* r2);
void FUN_080b7f70(struct Enemy* p, struct Coord* c, motion_t* m, s32 n);
s32 PushoutToUp1(s32 x, s32 y);

void HeavyCannon_Init(struct Enemy* p);
void HeavyCannon_Update(struct Enemy* p);
void HeavyCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHeavyCannonBallRoutine = {
    [ENTITY_INIT] =      (void*)HeavyCannon_Init,
    [ENTITY_UPDATE] =    (void*)HeavyCannon_Update,
    [ENTITY_DIE] =       (void*)HeavyCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


static const EnemyFunc PTR_ARRAY_08367774[2];
static const EnemyFunc PTR_ARRAY_0836777c[2];
static const struct Collision sCollisions[3];
static const u8 sInitModes[2];
static const motion_t sMotions[3];
void CreateHeavyCannonBall(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HEAVY_CANNON_BALL);
    p->work[0] = 0, p->work[2] = kind;
    (p->coord).x = x, (p->coord).y = y;
  }
}

void FUN_0807aae8(struct Body* body, struct Coord* r1, struct Coord* r2) {
  struct Enemy* atk = (struct Enemy*)((body->enemy)->parent);
  struct Enemy* self = (struct Enemy*)body->parent;
  if (body->hitboxFlags & 1) {
    self->buffer[0] = ((atk->s).coord.x - (self->s).coord.x) > 0 ? 1 : 0;
  }
  if (body->hitboxFlags & 4) {
    if ((atk->body).hp == 0) {
      (self->s).work[2] = 0xff;
    }
  }
}

static bool8 FUN_0807ab30(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    HeavyCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

void HeavyCannon_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, sCollisions, 10, FUN_0807aae8);
  (p->s).renderPrio = 30;
  HeavyCannon_Update(p);
}

void HeavyCannon_Update(struct Enemy* p) {
  if (gCurStory.s.gameflags[4] & 0x40) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else if (!FUN_0807ab30(p)) {
    PTR_ARRAY_08367774[(p->s).mode[1]](p);
    PTR_ARRAY_0836777c[(p->s).mode[1]](p);
  }
}

void HeavyCannon_Die(struct Enemy* p) {
  struct Coord c;
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y;
  CreateSmoke(1, &c);
  PlaySound(0x2a);
  FUN_080b7f70(p, &c, (motion_t*)sMotions, 3);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_0807acd0(struct Enemy* p) {}

void FUN_0807acd4(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register u32 w asm("r2");
      register u32 z4 asm("r4");
      SetDDP(&p->body, &sCollisions[1]);
      {
        register u8* q asm("r1");
        q = (u8*)p + 0x25;
        *q = 0x1f;
      }
      w = (p->s).work[2];
      if (w != 0) {
        register u32 fl asm("r0");
        register u32 m asm("r1");
        fl = (p->s).flags;
        m = 0x10;
        fl |= m;
        (p->s).flags = fl;
      } else {
        register u32 fl asm("r1");
        register u32 m asm("r0");
        fl = (p->s).flags;
        m = 0xEF;
        m &= fl;
        (p->s).flags = m;
      }
      {
        register u32 xf asm("r1");
        xf = 1;
        xf &= w;
        {
          u8* q = (u8*)p + 0x4c;
          z4 = 0;
          *q = xf;
        }
        {
          register u8* oa asm("r3");
          oa = (u8*)p + 0x4a;
          xf <<= 4;
          {
            register s32 ov asm("r2");
            register s32 m11 asm("r0");
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= xf;
            *oa = m11;
          }
        }
      }
      SetMotion(&p->s, 0x3804);
      *(volatile u8*)&(p->s).work[2] = z4;
      (p->s).work[3] = 0xff;
      (p->s).d.y = z4;
      {
        register s32 k asm("r2");
        register s32 k0 asm("r0");
        k0 = -0x180;
        (p->s).d.x = k0;
        k = k0;
        {
          register u32 fl asm("r1");
          register u32 m asm("r0");
          fl = (p->s).flags;
          m = 0x10;
          m &= fl;
          if (m != 0) {
            k = 0xc0;
            k <<= 1;
          }
        }
        (p->s).d.x = k;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 bounced asm("r6");
      u32* st;
      bounced = 0;
      {
        register u32* q asm("r0");
        register u32 v asm("r1");
        register u32 m asm("r2");
        q = (u32*)((u8*)p + 0x8c);
        v = *q;
        m = 0x20001;
        v &= m;
        st = q;
        if (v != m) {
          goto nohit;
        }
        {
          register u32 side asm("r2");
          register u32 fl asm("r1");
          register u32 k asm("r0");
          side = *((u8*)q + 0x28);
          fl = (p->s).flags;
          k = 0x10;
          k &= fl;
          if (k == 0) {
            goto notflipped;
          }
          if (side != 1) {
            goto nohit;
          }
          goto flipdx;
        notflipped:
          if (side != 0) {
            goto nohit;
          }
        }
      flipdx:
        (p->s).d.x = -(p->s).d.x;
      }
    nohit : {
      register s32 dy asm("r0");
      register s32 lim asm("r1");
      dy = (p->s).d.y + 0x40;
      (p->s).d.y = dy;
      lim = 0xe0;
      lim <<= 3;
      if (dy > lim) {
        (p->s).d.y = lim;
      }
    }
      {
        register s32 cy asm("r2");
        register s32 dy asm("r1");
        register s32 cx asm("r0");
        cx = (p->s).coord.y;
        dy = (p->s).d.y;
        cy = cx + dy;
        (p->s).coord.y = cy;
        if (dy <= 0) {
          goto noland;
        }
        {
          register s32 r asm("r4");
          register s32 k asm("r3");
          k = 0xc0;
          k <<= 3;
          r = PushoutToUp1((p->s).coord.x, cy + k);
          if (r >= 0) {
            goto noland;
          }
          {
            register s32 v asm("r1");
            register s32 t asm("r0");
            v = (p->s).d.y;
            t = 0xb0;
            t <<= 2;
            if (v <= t) {
              goto soft;
            }
            PlaySound(0x105);
            bounced = 1;
            v = (p->s).d.y;
            v = -v;
            t = v << 1;
            t += v;
            t <<= 6;
            if (t < 0) {
              t += 0xff;
            }
            t >>= 8;
            goto setdy;
          soft:
            t = 0x80;
            t <<= 1;
            if (v > t) {
              t += 5;
              PlaySound(t);
            }
            t = 0;
          setdy:
            (p->s).d.y = t;
          }
          (p->s).coord.y = (p->s).coord.y + r;
          if ((p->s).d.x < 0) {
            register s32 g asm("r4");
            g = FUN_08009f6c((p->s).coord.x - 0x40, (p->s).coord.y);
            asm("" : "+r"(g));
            {
              register s32 v asm("r1");
              register s32 k2 asm("r0");
              k2 = -0x600;
              v = g + k2;
              k2 = (p->s).coord.y;
              g = v - k2;
              {
                register s32 lim asm("r0");
                cy = 0x80 << 5;
                v = g + cy;
                lim = 0x1FFF;
                if ((u32)v > (u32)lim) {
                  goto noland;
                }
              }
            }
            if (g < 0) {
              register s32 t3 asm("r0");
              t3 = g + 3;
              g = t3 >> 2;
            }
            {
              register s32 t asm("r0");
              t = (p->s).d.x - g;
              (p->s).d.x = t;
            }
          } else {
            register s32 g asm("r4");
            g = FUN_08009f6c((p->s).coord.x + 0x40, (p->s).coord.y);
            asm("" : "+r"(g));
            {
              register s32 v asm("r1");
              register s32 k2 asm("r0");
              k2 = -0x600;
              v = g + k2;
              k2 = (p->s).coord.y;
              g = v - k2;
              {
                register s32 lim asm("r0");
                cy = 0x80 << 5;
                v = g + cy;
                lim = 0x1FFF;
                if ((u32)v > (u32)lim) {
                  goto noland;
                }
              }
            }
            if (g < 0) {
              register s32 t3 asm("r0");
              t3 = g + 3;
              g = t3 >> 2;
            }
            {
              register s32 t asm("r0");
              t = (p->s).d.x + g;
              (p->s).d.x = t;
            }
          }
        }
      }
    noland : {
      register s32 v asm("r0");
      register s32 lim asm("r1");
      v = (p->s).d.y;
      lim = 0x80;
      lim <<= 1;
      v += lim;
      lim += 0xff;
      if ((u32)v > (u32)lim) {
        goto nosnap;
      }
      {
        register s32 cx2 asm("r0");
        register s32 cy asm("r1");
        register s32 k asm("r2");
        cx2 = (p->s).coord.x;
        cy = (p->s).coord.y;
        k = 0x80 << 4;
        cy += k;
        if (((u16)FUN_080098a4(cx2, cy)) == 0) {
          goto nosnap;
        }
      }
      {
        register s32 g asm("r0");
        register s32 k asm("r3");
        g = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
        k = -0x600;
        g += k;
        (p->s).coord.y = g;
      }
      (p->s).d.y = 0;
    }
    nosnap : {
      register s32 cx asm("r0");
      register s32 k asm("r2");
      register s32 cy asm("r1");
      {
        register s32 dx asm("r1");
        cx = (p->s).coord.x;
        dx = (p->s).d.x;
        cx += dx;
        (p->s).coord.x = cx;
        if (dx >= 0) {
          goto posarm;
        }
      }
      k = -0x800;
      cx += k;
      cy = (p->s).coord.y;
      goto callwall;
    posarm : {
      register s32 k2 asm("r1");
      k2 = 0x80;
      k2 <<= 4;
      cx += k2;
    }
      cy = (p->s).coord.y;
      k = -0x800;
    callwall:
      cy += k;
      if (((u16)FUN_080098a4(cx, cy)) == 0) {
        goto nowall;
      }
      bounced = 1;
      PlaySound(0x105);
      (p->s).d.x = -(p->s).d.x;
      {
        register s32 v asm("r0");
        register s32 lim asm("r1");
        v = (p->s).d.y;
        lim = 0x2FF;
        v += lim;
        if ((u32)v <= (u32)lim) {
          (p->s).d.y = -0x300;
        }
      }
    }
    nowall:
      if ((*(u32*)((u8*)pZero2 + 0x8c) & 1) != 0 && (*st & 4) != 0) {
        PlaySound(0x105);
        (p->s).d.x = -(p->s).d.x;
      }
      {
        register s32 t asm("r1");
        register u32 n asm("r0");
        {
          register s32 w3 asm("r0");
          w3 = (p->s).work[3];
          t = w3 - 1;
          (p->s).work[3] = t;
        }
        n = (p->s).work[2];
        n = bounced + n;
        (p->s).work[2] = n;
        n = (u32)(n << 24) >> 24;
        if (n > 4) {
          goto die;
        }
        {
          register s32 sh asm("r0");
          sh = t << 24;
          if (sh != 0) {
            goto alive;
          }
        }
      }
    die:
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      break;
    alive:
      if ((p->s).d.x < 0) {
        register u32 z asm("r2");
        {
          register u32 fl asm("r1");
          register u32 m asm("r0");
          z = 0;
          fl = (p->s).flags;
          m = 0xEF;
          m &= fl;
          (p->s).flags = m;
        }
        {
          u8* q = (u8*)p + 0x4c;
          *q = z;
        }
        {
          register u8* oa asm("r2");
          oa = (u8*)p + 0x4a;
          {
            register s32 ov asm("r1");
            register s32 m11 asm("r0");
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            *oa = m11;
          }
        }
      } else {
        register u32 one asm("r2");
        one = 1;
        {
          register u32 fl asm("r0");
          register u32 m asm("r1");
          fl = (p->s).flags;
          m = 0x10;
          fl |= m;
          (p->s).flags = fl;
        }
        {
          u8* q = (u8*)p + 0x4c;
          *q = one;
        }
        {
          register u8* oa asm("r3");
          register s32 k asm("r2");
          oa = (u8*)p + 0x4a;
          k = 0x10;
          {
            register s32 ov asm("r1");
            register s32 m11 asm("r0");
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= k;
            *oa = m11;
          }
        }
      }
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > (0xc0 << 7)) {
        register u32 z asm("r2");
        {
          register u32 fl asm("r1");
          register u32 m asm("r0");
          fl = (p->s).flags;
          m = 0xFE;
          m &= fl;
          z = 0;
          {
            u32 mm = 0xFD;
            m &= mm;
          }
          (p->s).flags = m;
        }
        *st = z;
        {
          register u8* a asm("r0");
          a = (u8*)p + 0x90;
          asm volatile("str %0, [%1]" ::"l"(z), "l"(a) : "memory");
          a += 4;
          asm("" : "+r"(a));
          asm volatile("strb %0, [%1]" ::"l"(z), "l"(a) : "memory");
        }
        {
          register u32 fl asm("r1");
          register u32 m asm("r0");
          fl = (p->s).flags;
          m = 0xFB;
          m &= fl;
          (p->s).flags = m;
        }
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
        break;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void FUN_0807b008(struct Enemy* p) {
  s32 m = (p->s).mode[2];
  switch (m) {
    case 0: {
      u8* a = (u8*)p + 0x8c;
      *(u32*)a = m;
      asm("" : "+r"(a));
      a += 4;
      asm("" : "+r"(a));
      *(u32*)a = m;
      asm("" : "+r"(a));
      a += 4;
      asm("" : "+r"(a));
      *a = m;
      (p->s).flags &= 0xFB;
      (p->s).work[2] = m;
      (p->s).mode[2]++;
    }
      /* fallthrough */
    case 1: {
      s32 dy;
      s32 w;
      (p->s).coord.x += (p->s).d.x;
      dy = (p->s).d.y + 0x40;
      (p->s).d.y = dy;
      if (dy > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      w = (p->s).work[2] + 1;
      (p->s).work[2] = w;
      w &= 2;
      if (w != 0) {
        (p->s).flags |= 1;
      } else {
        (p->s).flags &= 0xFE;
      }
      UpdateEntityAnim(&p->s);
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x6000) {
        s32 z;
        {
          register u8 fv asm("r0");
          register u8 fl asm("r1");
          fl = (p->s).flags;
          asm("" : "+r"(fl));
          fv = 0xFE;
          fv &= fl;
          z = 0;
          fl = 0xFD;
          fv &= fl;
          (p->s).flags = fv;
        }
        {
          u8* b = (u8*)p + 0x8c;
          *(u32*)b = z;
          asm("" : "+r"(b));
          b += 4;
          asm("" : "+r"(b));
          *(u32*)b = z;
          asm("" : "+r"(b));
          b += 4;
          asm("" : "+r"(b));
          *b = z;
        }
        (p->s).flags &= 0xFB;
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_0807acd0(struct Enemy* p);
void FUN_0807acd0(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367774[2] = {
    (void*)FUN_0807acd0,
    (void*)FUN_0807acd0,
};

void FUN_0807acd4(struct Enemy* p);
void FUN_0807b008(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_0836777c[2] = {
    (void*)FUN_0807acd4,
    (void*)FUN_0807b008,
};

// --------------------------------------------

// 0x08367784
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};

// 0x083677CC
static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 5),
};
