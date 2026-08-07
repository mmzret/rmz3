#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "element.h"
#include "vfx.h"
#include "physics.h"
#include "overworld.h"
#include "physics.h"
#include "script.h"
#include "zero.h"

struct VFX* FUN_080b2b40(u8 kind, Coords32* c, s32 d, u8 xflip);
struct Projectile* FUN_0809c3b4(Coords32* c, u8 r1, u8 r2);

s32 PushoutToUp2(s32 x, s32 y);
s32 PushoutToLeft2(s32 x, s32 y);
s32 PushoutToRight2(s32 x, s32 y);
s32 PushoutToUp2(s32 x, s32 y);
s32 PushoutToLeft2(s32 x, s32 y);
s32 PushoutToRight2(s32 x, s32 y);
bool8 FUN_080459d4(struct Boss* p);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  s8 prevModes[2];       // 0xB5
  u8 unk_b7;             // 0xB7
  Coords32 initCoords;   // 0xB8
  void* unk_c0;          // 0xC0
  u8 unk_c4[5];          // 0xC4
  u8 unk_c9;             // 0xC9
  u8 unk_ca;             // 0xCA
  u8 unk_cb[9];          // 0xCB
  s32 unk_d4;            // 0xD4
  s32 unk_d8;            // 0xD8
  s32 unk_dc;            // 0xDC
  s32 unk_e0;            // 0xE0
} Volteel;

void volteel_08045abc(Volteel* p);
void FUN_080459e8(Volteel* p);
struct Projectile* FUN_0809f4dc(struct Entity* e, Coords32* c, Coords32* d, u8 n);
static_assert(sizeof(Volteel) == sizeof(Boss));

static const struct Collision sCollisions[24];

bool8 volteel_080457c4(Volteel* p);

void Volteel_OnCollision(struct Body* body, Coords32* c1, Coords32* c2);

NON_MATCH static void Volteel_Init(Volteel* p);
static void Volteel_Update(Volteel* p);
static void Volteel_Die(Volteel* p);

// clang-format off
const BossRoutine gVolteelRoutine = {
    [ENTITY_INIT] =      (void*)Volteel_Init,
    [ENTITY_UPDATE] =    (void*)Volteel_Update,
    [ENTITY_DIE] =       (void*)Volteel_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


const Coords32 Coord_ARRAY_08362570[7];
static Volteel* Unused_CreateVolteel(Coords32* c, u8 n) {
  Volteel* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_VOLTEEL);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

NON_MATCH static void Volteel_Init(Volteel* p) {
#if MODERN
  s32 y;
  EnableSpriteAnimation_Normal(p);
  p->angle = 0;
  (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
  SetSpriteTableDynamic(p);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  (p->spr).xflip = FALSE, (p->spr).oam.xflip = FALSE;
  p->flags &= ~X_FLIP;
  ResetBossBody((void*)p, &sCollisions[0], 64);
  p->unk_c9 = 64;
  SET_BOSS_COLLISION_HANDLER(p, Volteel_OnCollision);
  p->unk_b4 = 0;
  p->prevModes[0] = -1, p->prevModes[1] = -1;
  p->unk_c0 = NULL;
  p->unk_b7 = 0;
  y = (p->coord).y - PIXEL(64);
  (p->coord).y = FUN_0800a05c((p->coord).x, y);
  (p->initCoords).x = (p->coord).x, (p->initCoords).y = (p->coord).y;

  {
    s32 tmp = FUN_0800a134((p->coord).x, (p->coord).y);
    s32 tmp_e0 = FUN_0800a22c((p->coord).x, tmp);
    s32 tmp_dc = FUN_0800a31c((p->coord).x, tmp);
    s32 tmpX = tmp_dc + ((tmp_e0 - tmp_dc) >> 1);
    p->unk_d4 = FUN_0800a134(tmpX, (p->coord).y);
    p->unk_d8 = FUN_0800a05c(tmpX, (p->coord).y);
    p->unk_dc = tmp_dc;
    p->unk_e0 = tmp_e0;
  }
  p->unk_ca = 0;
  if (p->work[0] == 0) {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 3, p->mode[2] = 0, p->mode[3] = 0;
  }
  p->work[1] = 0;
  Volteel_Update(p);
#else
  INCCODE("asm/wip/Volteel_Init.inc");
#endif
}

bool8 nop_080438a4(Volteel* p);
bool8 FUN_080438f0(Volteel* p);
bool8 FUN_08043988(Volteel* p);
bool8 nop_080439d0(Volteel* p);
bool8 nop_08043db0(Volteel* p);
bool8 FUN_080440c0(Volteel* p);
bool8 FUN_080449f0(Volteel* p);
bool8 FUN_08044cb4(Volteel* p);
bool8 FUN_08044f00(Volteel* p);
bool8 FUN_080450bc(Volteel* p);
bool8 FUN_08045464(Volteel* p);
bool8 FUN_08045570(Volteel* p);
bool8 FUN_08045610(Volteel* p);

void volteelMode0(Volteel* p);
void volteelMode1(Volteel* p);
void volteelMode2(Volteel* p);
void volteelNeutral(Volteel* p);
void volteelMode4(Volteel* p);
void volteelMode5(Volteel* p);
void volteelMode6(Volteel* p);
void volteelElectricCage(Volteel* p);
void volteelMode8(Volteel* p);
void volteelMode9(Volteel* p);
void volteelEX(Volteel* p);
void volteelMode11(Volteel* p);
void volteelKnockBackDamage(Volteel* p);

static void Volteel_Update(Volteel* p) {
  // clang-format off
  static bool8 (*const sUpdates1[])(Volteel*) = {
      nop_080438a4,
      FUN_080438f0,
      FUN_08043988,
      nop_080439d0,
      nop_08043db0,
      FUN_080440c0,
      FUN_080449f0,
      FUN_08044cb4,
      FUN_08044f00,
      FUN_080450bc,
      FUN_08045464,
      FUN_08045570,
      FUN_08045610,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[])(Volteel*) = {
      volteelMode0,
      volteelMode1,
      volteelMode2,
      volteelNeutral,
      volteelMode4,
      volteelMode5,
      volteelMode6,
      volteelElectricCage,
      volteelMode8,
      volteelMode9,
      volteelEX,
      volteelMode11,
      volteelKnockBackDamage,
  };
  // clang-format on
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_VOLTEEL_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[3] = 1;
    } else {
      p->mode[3] = 0;
    }
    Volteel_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])(p);
  volteel_080457c4(p);
  (sUpdates2[p->mode[1]])(p);
}

void volteelDeath0(Volteel* p);
void volteelDeath1(Volteel* p);

static void Volteel_Die(Volteel* p) {
  static void (*const seq[2])(Volteel*) = {
      volteelDeath0,
      volteelDeath1,
  };
  (seq[p->mode[1]])(p);
}

NON_MATCH void volteelDeath0(Volteel* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      u16 ms = gStageRun.missionStatus;
      s32 one = 1;
      if ((one & ms) && !(one & gStageRun.vm.active)) {
        gStageRun.missionStatus = (ms & 0xFFFE) | 0x10;
      }
      p->angle = 0;
      one = 0;
      (p->spr).mag.x = 0x100;
      (p->spr).mag.y = 0x100;
      p->spr.yflip = one;
      (p->spr).oam.yflip = 0;
      p->flags &= ~0x20;
      if (_isSoundPlaying(0x7F)) {
        StopSound(0x7F);
      }
      if ((*(u16*)(g + 0x1D0) & 0x7F) == 0xD) {
        gOverworld.state[0] = one;
      } else {
        gOverworld.state[2] = one;
      }
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      p->flags &= ~COLLIDABLE;
      p->d.y = 0;
      p->d.x = 0;
      p->work[2] = 1;
      p->mode[2]++;
    }
      /* fallthrough */
    case 1:
      if (p->work[2] != 0) {
        if ((u8)--p->work[2] != 0) {
          break;
        }
        p->mode[2]++;
      }
      break;
    case 2:
      p->mode[1] = 1, p->mode[2] = 0;
      break;
  }
#else
  INCCODE("asm/boss/volteel_3540.inc");
#endif
}

void volteelDeath1(Volteel* p) {
  switch (p->mode[2]) {
    case 0: {
      register u32* st asm("r2");
      register u32 z asm("r1");
      u8 m3;
      {
        u8* a = (u8*)p + 0x49;
        u32 v = *a;
        s32 m = -0xd;
        u32 e8a;
        m &= v;
        e8a = 8;
        asm volatile("" : "+l"(e8a));
        m |= e8a;
        *a = m;
      }
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x04));
      {
        u32 fl = p->flags;
        u32 f = 1;
        f |= fl;
        p->flags = f;
      }
      st = (u32*)((u8*)p + 0x8c);
      if ((*st & (0x80 << 2)) == 0) {
        if (*(s16*)((u8*)p + 0xa4) != 0) {
          goto ten;
        }
      }
      {
        u32 ms = gStageRun.missionStatus;
        u32 e8 = 8;
        e8 &= ms;
        if (e8 != 0) {
          goto ten;
        }
      }
      m3 = p->mode[3];
      if (m3 != 1) {
      ten:
        m3 = 0xa;
      }
      p->mode[2] = m3;
      z = 0;
      *st = z;
      *(u32*)((u8*)p + 0x90) = z;
      *((u8*)p + 0x94) = z;
      {
        u32 fv = p->flags;
        u32 f2 = 0xfb;
        f2 &= fv;
        p->flags = f2;
      }
      {
        s32* d = (s32*)((u8*)p + 0x5c);
        d[1] = z;
      }
      p->d.x = z;
      FALLTHROUGH;
    }
    case 1:
    case 10:
      UpdateEntityAnim((struct Entity*)p);
      goto inc;
    case 2: {
      struct Coord c;
      s32 cx;
      s32 cy;
      u8 w1;
      p->d.y = 0;
      cx = p->coord.x;
      c.x = cx;
      cy = p->coord.y;
      c.y = cy;
      if ((p->flags & 0x10) != 0) {
        *(volatile s32*)&c.x = cx;
      }
      c.y = cy - 0x2500;
      w1 = p->work[1];
      if (w1 == 0xff) {
        goto one;
      }
      if (w1 == 0xfe) {
        ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x80 << 2, 0);
        goto snd;
      }
      if ((pZero2->s).coord.x <= cx) {
        goto zero;
      }
    one:
      ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x80 << 2, 1);
      goto snd;
    zero:
      ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x80 << 2, 0);
    snd:
      PlaySound(0x2f);
      goto inc;
    }
    case 3: {
      struct Coord* cc = &p->coord;
      u32 dir;
      {
        register s32 mo asm("r2");
        mo = MOTION(0xA5, 0x05);
        asm volatile("" : "+l"(mo));
        dir = (p->flags >> 4) & 1;
        ((void (*)(struct Entity*, struct Coord*, s32, s32))FUN_0809c3b4)(
            (struct Entity*)p, cc, mo, dir);
      }
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x06));
      UpdateEntityAnim((struct Entity*)p);
      p->work[2] = 0x44;
      goto inc;
    }
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] != 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      FALLTHROUGH;
    case 11:
      if ((p->scriptEntity->flags & 0x80) == 0) {
        break;
      }
      p->mode[2] = 0x14;
      break;
    case 20:
      p->work[2] = 0x50;
      p->mode[2]++;
      FALLTHROUGH;
    case 21:
      if ((p->scriptEntity->flags & 0x80) == 0) {
        break;
      }
      goto inc;
    case 22: {
      const struct Coord* ec;
      if ((p->flags & 0x10) == 0) {
        ec = (const struct Coord*)0x08362578;
        asm volatile("" : "+l"(ec));
      } else {
        ec = (const struct Coord*)0x08362580;
        asm volatile("" : "+l"(ec));
      }
      *(struct Entity**)((u8*)p + 0xc0) = CreateBossExplosion((struct Entity*)p, (struct Coord*)ec);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 23:
      if ((*(struct Entity**)((u8*)p + 0xc0))->mode[0] <= 1) {
        break;
      }
    inc:
      p->mode[2]++;
      break;
    case 24: {
      register struct StageRun* sr asm("r2");
      register s32 g asm("r0");
      register s32 h asm("r1");
      p->work[2] = 0x3c;
      sr = &gStageRun;
      h = *((u8*)sr + 0x12);
      asm("" : "+r"(h));
      g = 2;
      g |= h;
      *((u8*)sr + 0x12) = g;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 25:
      if (p->work[2] != 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      {
        u32 fv = p->flags;
        u32 f = 0xfe;
        f &= fv;
        p->flags = f;
      }
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
      break;
  }
}

bool8 nop_080438a4(Volteel* p) { return TRUE; }

void volteelMode0(Volteel* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, MOTION(DM165_VOLTEEL, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->scriptEntity)->flags & (1 << 0)) p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

bool8 FUN_080438f0(Volteel* p) { return TRUE; }

void volteelMode1(Volteel* p) {
  motion_t m;
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x3C;
      PlaySound(0x79);
      m = MOTION(0xA5, 0x0E);
      goto setmotion;
    case 2:
      if (p->work[2] != 0) {
        if ((u8)--p->work[2] != 0) {
          break;
        }
      }
      goto advance;
    case 3:
      m = MOTION(0xA5, 0x10);
    setmotion:
      SetMotion((struct Entity*)p, m);
      p->mode[2]++;
      /* fallthrough */
    case 1:
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    advance:
      p->mode[2]++;
      break;
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      p->mode[1] = 2, p->mode[2] = 0;
      break;
  }
}

bool8 FUN_08043988(Volteel* p) { return TRUE; }

void volteelMode2(Volteel* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM165_VOLTEEL, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (!(gStageRun.vm.active & VM_ACTIVE)) p->mode[1] = 3, p->mode[2] = 0;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

bool8 nop_080439d0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_c.inc");

bool8 nop_08043db0(Volteel* p) { return TRUE; }

void volteelMode4(Volteel* p) {
  s32 nm;
  switch (p->mode[2]) {
    case 0: {
      s32 best;
      register s32 bx asm("r6");
      register s32 cand asm("r4");
      best = 0x7FFFFFFF;
      {
        register s32 v asm("r0");
        register s32 k asm("r1");
        v = (pZero2->s).coord.x;
        k = -0x1200;
        bx = v + k;
      }
      {
        register s32 r asm("r1");
        register s32 cy asm("r1");
        cy = p->coord.y + -0x5000;
        r = FUN_0800a05c(bx, cy);
        if (r < best && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          best = r;
        }
      }
      {
        register s32 v asm("r0");
        register s32 k asm("r1");
        v = (pZero2->s).coord.x;
        k = 0x90 << 5;
        cand = v + k;
      }
      {
        register s32 r asm("r1");
        register s32 cy asm("r1");
        cy = p->coord.y + -0x5000;
        r = FUN_0800a05c(cand, cy);
        if (r < best && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          best = r;
          bx = cand;
        }
      }
      {
        register s32 r asm("r1");
        register s32 cy asm("r1");
        cand = (pZero2->s).coord.x;
        cy = p->coord.y + -0x5000;
        r = FUN_0800a05c(cand, cy);
        if (r < best && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          best = r;
          bx = cand;
        }
      }
      p->work[2] = 0x50;
      p->d.x = (bx - p->coord.x) / 0x50;
      {
        register s32 c asm("r1");
        register s32 dy asm("r0");
        c = 0xc8 << 8;
        dy = p->coord.y;
        dy = best - dy;
        c -= dy;
        p->d.y = -(c / 0x50);
      }
      p->work[2] = 0x4f;
      p->work[3] = 1;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      volteel_08045abc(p);
      if (p->work[3] != 0) {
        s32 t = p->work[3] - 1;
        p->work[3] = t;
        if ((t << 24) == 0) {
          goto inc1;
        }
        break;
      }
    inc1:
      nm = p->mode[2] + 1;
      asm volatile("");
      goto setmode;
    case 2:
      SetMotion((struct Entity*)p, 0xA501);
      SetDDP(&p->body, &sCollisions[3]);
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      register s32 hit asm("r6");
      register s32 r asm("r4");
      hit = 0;
      {
        register s32 dy asm("r2");
        dy = p->d.y + 0x10;
        p->d.y = dy;
        {
          register s32 cx asm("r0");
          register s32 dx asm("r1");
          cx = p->coord.x;
          dx = p->d.x;
          cx += dx;
          p->coord.x = cx;
          {
            register s32 cy asm("r1");
            register s32 k asm("r2");
            cy = p->coord.y;
            cy += dy;
            p->coord.y = cy;
            k = 0x90 << 5;
            cx += k;
            r = PushoutToUp2(cx, cy);
          }
        }
      }
      if (r != 0) {
        register s32 a asm("r1");
        a = r;
        if (r < 0) {
          a = -r;
        }
        if (a <= 0x7FF) {
          p->coord.y += r;
          hit = 1;
        }
      }
      {
        register s32 cx asm("r0");
        register s32 k asm("r1");
        cx = p->coord.x;
        k = -0x1200;
        cx += k;
        r = PushoutToUp2(cx, p->coord.y);
      }
      if (r != 0) {
        register s32 a asm("r1");
        a = r;
        if (r < 0) {
          a = -r;
        }
        if (a <= 0x7FF) {
          p->coord.y += r;
          hit = 1;
        }
      }
      r = PushoutToUp2(p->coord.x, p->coord.y);
      if (r != 0) {
        register s32 a asm("r1");
        a = r;
        if (r < 0) {
          a = -r;
        }
        if (a <= 0x7FF) {
          p->coord.y += r;
          hit = 1;
        }
      }
      {
        register s32 cx asm("r0");
        register s32 k asm("r2");
        cx = p->coord.x;
        k = 0x90 << 5;
        cx += k;
        r = PushoutToLeft2(cx, p->coord.y);
      }
      if (r != 0) {
        p->coord.x += r;
      }
      {
        register s32 cx asm("r0");
        register s32 k asm("r1");
        cx = p->coord.x;
        k = -0x1200;
        cx += k;
        PushoutToRight2(cx, p->coord.y);
      }
      if (r != 0) {
        p->coord.x += r;
      }
      {
        register s32 mv asm("r1");
        u32 cur = MOTION_VALUE(p);
        mv = 0xA502;
        if (cur != mv && p->d.y > 0) {
          SetMotion((struct Entity*)p, mv);
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] != 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          goto chkhit;
        }
      }
      nm = p->mode[2] + 1;
      asm volatile("");
      goto setmode;
    chkhit:
      if (hit != 1) {
        break;
      }
      nm = p->mode[2] + 1;
      goto setmode;
    }
    case 4: {
      register s32 best asm("r4");
      SetMotion((struct Entity*)p, 0xA503);
      SetDDP(&p->body, &sCollisions[1]);
      best = 0x7FFFFFFF;
      {
        register s32 cx asm("r0");
        register s32 r asm("r1");
        register s32 cy asm("r1");
        register s32 k asm("r2");
        cx = p->coord.x;
        cy = p->coord.y;
        k = -0x1000;
        cy += k;
        r = FUN_0800a05c(cx, cy);
        if (r < best && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          best = r;
          p->coord.y = best;
        }
      }
      {
        register s32 r asm("r1");
        register s32 cx asm("r0");
        register s32 cy asm("r1");
        register s32 k asm("r2");
        cx = p->coord.x;
        k = -0x1200;
        cx += k;
        cy = p->coord.y;
        k = -0x1000;
        cy += k;
        r = FUN_0800a05c(cx, cy);
        if (r < best && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          best = r;
          p->coord.y = best;
        }
      }
      {
        register s32 r asm("r1");
        register s32 cx asm("r0");
        register s32 cy asm("r1");
        register s32 k asm("r2");
        cx = p->coord.x;
        k = 0x90 << 5;
        cx += k;
        cy = p->coord.y;
        k = -0x1000;
        cy += k;
        r = FUN_0800a05c(cx, cy);
        if (r < best && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          p->coord.y = r;
        }
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      register u32 st asm("r1");
      UpdateEntityAnim((struct Entity*)p);
      st = *((u8*)p + 0x73);
      if (st != 3) {
        break;
      }
      nm = 0;
      p->mode[1] = st;
    setmode:
      p->mode[2] = nm;
      break;
    }
  }
}

bool8 FUN_080440c0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_e.inc");

bool8 FUN_080449f0(Volteel* p) { return TRUE; }

void volteelMode6(Volteel* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 mid;
      {
        s32* pa;
        register s32* pb asm("r6");
        register s32 t asm("r2");
        register s32 zx asm("r3");
        register s32 b asm("r5");
        register s32* q1 asm("r1");
        register s32* q2 asm("r0");
        register s32 u asm("r1");
        register s32 v asm("r0");
        s32 a;
        {
          u8 fl = p->flags;
          u32 f = 1;
          f |= fl;
          p->flags = f;
        }
        {
          struct Zero* z0 = pZero2;
          q1 = (s32*)((u8*)p + 0xdc);
          zx = (z0->s).coord.x;
        }
        a = *q1;
        t = zx - a;
        pa = q1;
        if (t <= 0) {
          t = a - zx;
        }
        q2 = (s32*)((u8*)p + 0xe0);
        b = *q2;
        u = zx - b;
        pb = q2;
        if (u > 0 ? t > u : t > (v = b - zx)) {
          register u8* q asm("r2");
          register u32 z asm("r1");
          p->coord.x = *pb;
          p->unk_coord.x = *pa + (0x80 << 7);
          q = (u8*)p + 0xca;
          z = 0;
          *q = 1;
          {
            u8* x = (u8*)p + 0x4c;
            *x = z;
          }
          q -= 0x80;
          {
            s32 ov = *q;
            s32 m11 = -0x11;
            m11 &= ov;
            *q = m11;
          }
          {
            u8 fl = p->flags;
            u32 f = 0xEF;
            f &= fl;
            p->flags = f;
          }
        } else {
          register u8* q asm("r1");
          register u32 k asm("r1");
          p->coord.x = *pa;
          p->unk_coord.x = *pb + -0x4000;
          q = (u8*)p + 0xca;
          *q = 3;
          q -= 0x7e;
          *q = 1;
          {
            u8* oa = (u8*)p + 0x4a;
            u32 v = *oa;
            k = 0x10;
            v |= k;
            *oa = v;
          }
          {
            u8 fl = p->flags;
            k |= fl;
            p->flags = k;
          }
        }
      }
      {
        s32* hi = (s32*)((u8*)p + 0xd8);
        s32* lo = (s32*)((u8*)p + 0xd4);
        s32 h = *hi;
        mid = h - ((h - *lo) >> 1);
      }
      p->coord.y = mid + (0x90 << 6);
      p->unk_coord.y = 0x7FFFFFFF;
      {
        register s32 r asm("r2");
        r = FUN_0800a05c(p->unk_coord.x, mid + -0x2C00);
        if (r < p->unk_coord.y && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          p->unk_coord.y = r;
        }
      }
      {
        register s32 r asm("r2");
        r = FUN_0800a05c(p->unk_coord.x + (0x90 << 5), p->coord.y + -0x5000);
        if (r < p->unk_coord.y && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          p->unk_coord.y = r;
        }
      }
      {
        register s32 r asm("r2");
        r = FUN_0800a05c(p->unk_coord.x + -0x1200, p->coord.y + -0x5000);
        if (r < p->unk_coord.y && r > *(s32*)((u8*)p + 0xbc) + -0x5000) {
          p->unk_coord.y = r;
        }
      }
      {
        register s32 ux asm("r0");
        s32 q;
        ux = p->unk_coord.x;
        p->work[2] = 0x50;
        p->d.x = (ux - p->coord.x) / 0x50;
        {
          register s32 c asm("r2");
          register s32 uy asm("r0");
          register s32 cy asm("r1");
          c = 0xc8 << 8;
          uy = p->unk_coord.y;
          cy = p->coord.y;
          uy -= cy;
          c -= uy;
          q = c / 0x50;
        }
        p->d.y = -q;
      }
      {
        u8 w = 0x4f;
        p->work[2] = w;
        p->work[3] = w;
      }
      PlaySound(0x7a);
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x12));
      SetDDP(&p->body, &sCollisions[0]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 mv asm("r5");
      u32 mvv;
      s32 dy = p->d.y + 0x10;
      p->d.y = dy;
      p->coord.x += p->d.x;
      p->coord.y += dy;
      mvv = MOTION_VALUE(p);
      asm("" : "+r"(mvv));
      mv = 0xA513;
      if (mvv != mv) {
        register u32 half asm("r0");
        register u32 w2 asm("r1");
        half = p->work[3];
        w2 = p->work[2];
        half >>= 1;
        if (w2 < half) {
          {
            u8 fl = p->flags;
            u32 f = 1;
            f |= fl;
            p->flags = f;
          }
          SetDDP(&p->body, &sCollisions[15]);
          {
            register struct Entity* e asm("r0");
            register s32 m asm("r1");
            e = (struct Entity*)p;
            m = mv;
            SetMotion(e, m);
          }
        } else {
          register u32 one asm("r0");
          register u32 f asm("r0");
          one = 1;
          one &= w2;
          if (one != 0) {
            u8 fl = p->flags;
            f = 1;
            f |= fl;
          } else {
            u8 fl = p->flags;
            f = 0xFE;
            f &= fl;
          }
          p->flags = f;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      if (p->work[2] != 0) {
        p->work[2]--;
      }
      break;
    }
    case 2: {
      u8* a = (u8*)p + 0x49;
      u32 v = *a;
      s32 m = -0xd;
      u32 e8a;
      m &= v;
      e8a = 8;
      m |= e8a;
      *a = m;
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x02));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s32 dy = p->d.y + 0x10;
      p->d.y = dy;
      p->coord.x += p->d.x;
      p->coord.y += dy;
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] != 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 4: {
      u8 z = 0;
      p->mode[1] = 3;
      p->mode[2] = z;
      break;
    }
  }
}

bool8 FUN_08044cb4(Volteel* p) { return TRUE; }

NON_MATCH void volteelElectricCage(Volteel* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0:
      if (!(p->flags & 0x10)) {
        s32 r0v = FUN_08009f6c(p->coord.x + 0x3600, p->coord.y + -0x800);
        s32 r;
        asm volatile("add %0, %1, #0" : "=&l"(r) : "l"(r0v));
        if (r != p->coord.y) {
          p->mode[2]++;
        } else {
          p->mode[2] = 0xA;
        }
      } else {
        s32 r0v = FUN_08009f6c(p->coord.x + -0x3600, p->coord.y + -0x800);
        s32 r;
        asm volatile("add %0, %1, #0" : "=&l"(r) : "l"(r0v));
        if (r != p->coord.y) {
          p->mode[2]++;
        } else {
          p->mode[2] = 0xA;
        }
      }
      break;
    case 1:
      SetMotion((struct Entity*)p, 0xA507);
      p->mode[2]++;
      FALLTHROUGH;
    case 2:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        u32 m10;
        if (!(p->flags & ({ m10 = 0x10; asm("" : "+r"(m10)); 0x10; }))) {
          u8* xa = (u8*)p + 0x4c;
          u8 ov;
          u8 fv;
          *xa = 1;
          xa -= 2;
          ov = *xa;
          ov |= m10;
          *xa = ov;
          fv = p->flags;
          fv |= m10;
          p->flags = fv;
        } else {
          u8* xa = (u8*)p + 0x4c;
          s32 z = 0;
          asm("" : "+r"(z));
          *xa = z;
          {
            u8* oa = (u8*)p + 0x4a;
            *oa = *oa & (({ asm("" : "+r"(z)); z; }) - 0x11);
          }
          p->flags &= ~0x10;
        }
        p->mode[2] = 0xA;
      }
      break;
    case 10:
      p->work[2] = 0x46;
      SetMotion((struct Entity*)p, 0xA508);
      SetDDP(&p->body, &sCollisions[1]);
      p->work[3] = 0x12;
      p->mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      t = p->work[3];
      if (t != 0) {
        t--;
        p->work[3] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 12: {
      u8* ow;
      s32 k;
      SetMotion((struct Entity*)p, 0xA509);
      SetDDP(&p->body, &sCollisions[5]);
      ow = (u8*)&gOverworld;
      if ((*(u16*)(ow + 0x1D0) & 0x7F) == 0xD) {
        k = 0x2D024;
        asm volatile("");
      } else {
        k = 0x2D026;
      }
      *(ow + k) = 1;
      PlaySound(0x7D);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 13: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2];
      if (t != 0) {
        t--;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 14: {
      u8* ow;
      s32 k;
      SetMotion((struct Entity*)p, 0xA50A);
      ow = (u8*)&gOverworld;
      if ((*(u16*)(ow + 0x1D0) & 0x7F) == 0xD) {
        k = 0x2D024;
        asm volatile("");
      } else {
        k = 0x2D026;
      }
      *(ow + k) = 0;
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 15:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 3;
        p->mode[2] = 0;
      }
      break;
  }
#else
  INCCODE("asm/boss/volteel_cage.inc");
#endif
}

bool8 FUN_08044f00(Volteel* p) { return TRUE; }

void volteelMode8(Volteel* p) {
  register s32 nm asm("r0");
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x1e;
      SetMotion((struct Entity*)p, 0xA50C);
      SetDDP(&p->body, &sCollisions[1]);
      PlaySound(0x7b);
      UpdateEntityAnim((struct Entity*)p);
      p->work[3] = 0xb;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      if (p->work[3] != 0) {
        if ((u8)--p->work[3] != 0) {
          break;
        }
      }
      p->work[3] = 0;
      nm = p->mode[2] + 1;
      asm volatile("");
      goto setm;
    case 2:
      if (p->work[3] == 0) {
        if ((s8)*((u8*)p + 0x71) == 4) {
          SetDDP(&p->body, (const struct Collision*)0x08362528);
          p->work[3] = 1;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] != 0) {
        if ((u8)--p->work[2] != 0) {
          break;
        }
      }
      nm = p->mode[2] + 1;
      asm volatile("");
      goto setm;
    case 3:
      SetMotion((struct Entity*)p, 0xA50D);
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      nm = p->mode[2] + 1;
      asm volatile("");
      goto setm;
    case 5: {
      register s32 z asm("r4");
      z = 0;
      p->work[2] = 0x1e;
      SetMotion((struct Entity*)p, 0xA50B);
      SetDDP(&p->body, &sCollisions[1]);
      PlaySound(0x7b);
      p->work[3] = z;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 6:
      if (p->work[3] == 0) {
        if ((s8)*((u8*)p + 0x71) == 4) {
          register s32 one asm("r0");
          SetDDP(&p->body, (const struct Collision*)0x08362528);
          one = 1;
          asm volatile("strb %0, [%1, #0x13]" ::"l"(one), "l"(p) : "memory");
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      asm volatile("");
      if (p->work[2] != 0) {
        if ((u8)--p->work[2] != 0) {
          break;
        }
      }
      asm volatile("");
      nm = p->mode[2] + 1;
      asm volatile("");
      goto setm;
    case 7:
      SetMotion((struct Entity*)p, 0xA50D);
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      asm volatile("");
      FALLTHROUGH;
    case 8: {
      register s32 st asm("r1");
      UpdateEntityAnim((struct Entity*)p);
      st = *((u8*)p + 0x73);
      if (st != 3) {
        break;
      }
      nm = 0;
      p->mode[1] = st;
    setm:
      p->mode[2] = nm;
      break;
    }
  }
}

bool8 FUN_080450bc(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_i.inc");

bool8 FUN_08045464(Volteel* p) { return TRUE; }

void volteelEX(Volteel* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x30;
      p->work[3] = 4;
      SetMotion((struct Entity*)p, MOTION(0xa5, 0xe));
      SetDDP(&p->body, &sCollisions[8]);
      p->mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->mode[2]++;
      break;
    case 2:
      PlaySound(0x7F);
      SetMotion((struct Entity*)p, MOTION(0xa5, 0xf));
      p->mode[2]++;
      /* fallthrough */
    case 3: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2];
      if (t != 0) {
        t -= 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      t = p->work[3];
      if (t != 0) {
        t -= 1;
        p->work[3] = t;
        if ((t << 24) != 0) goto ex;
      }
      p->mode[2]++;
      break;
    ex:
      FUN_080459e8(p);
      PlaySound(0x80);
      p->work[2] = 0x30;
      break;
    }
    case 4:
      StopSound(0x7F);
      SetMotion((struct Entity*)p, MOTION(0xa5, 0xa));
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      /* fallthrough */
    case 5: {
      u8 st;
      UpdateEntityAnim((struct Entity*)p);
      st = p->motion.state;
      if (st == 3) {
        p->mode[1] = st;
        p->mode[2] = 0;
      }
      break;
    }
  }
}

bool8 FUN_08045570(Volteel* p) { return TRUE; }

void volteelMode11(Volteel* p) {
  struct Entity** slot;
  register u8 m asm("r5");
  m = p->mode[2];
  if (m == 0) {
    if (isSoundPlaying(0x7F)) {
      StopSound(0x7F);
    }
    {
      register s32 off asm("r1");
      u8* g;
      g = (u8*)&gOverworld;
      if ((gOverworld.terrain.id & 0x7F) == 0xD) {
        off = 0x2D024;
        asm("" : "+r"(off) : "r"(m));
      } else {
        off = 0x2D026;
        asm("" : "+r"(off));
      }
      {
        register u8* t asm("r0");
        t = g + off;
        *t = m;
      }
    }
    {
      u8 v = p->flags;
      register u8 fv asm("r1");
      fv = 1;
      fv |= v;
      p->flags = fv;
    }
    PlaySound(0x81);
    p->mode[2]++;
  }
  slot = (struct Entity**)((u8*)p + 0xc0);
  if (isKilled(*slot)) {
    u32 z = 0;
    u8 a;
    u8 r;
    *slot = (struct Entity*)z;
    a = *(u8*)((u8*)p + 0xd0);
    {
      register s32 ac asm("r1");
      asm volatile("add %0, %1, #0" : "=&l"(ac) : "l"(a));
      if (ac != 5 && ac != 9) {
        goto other;
      }
    }
    {
      p->mode[1] = a;
      p->mode[2] = *(u8*)((u8*)p + 0xd1);
      r = *(u8*)((u8*)p + 0xd2);
      goto done;
    }
  other:
    {
      p->mode[1] = 3;
      p->mode[2] = z;
      r = 0xFF;
    }
  done:
    p->mode[3] = r;
  }
}

bool8 FUN_08045610(Volteel* p) { return TRUE; }

void volteelKnockBackDamage(Volteel* p) {
  register s32 z asm("r5");
  z = p->mode[2];
  switch (z) {
    case 0: {
      register u8* oa asm("r2");
      PlaySound(0x81);
      SetMotion((struct Entity*)p, 0xA504);
      if (isSoundPlaying(0x7f)) {
        StopSound(0x7f);
      }
      if ((pZero2->s).coord.x > p->coord.x) {
        register s32 g asm("r0");
        register s32 k asm("r1");
        p->d.x = -0x200;
        *((u8*)p + 0x4c) = 1;
        oa = (u8*)p + 0x4a;
        g = *oa;
        k = 0x10;
        g |= k;
        *oa = g;
        {
          register s32 fv asm("r0");
          fv = p->flags;
          k |= fv;
          p->flags = k;
        }
      } else {
        register s32 ov asm("r1");
        register s32 m asm("r0");
        p->d.x = 0x80 << 2;
        *((u8*)p + 0x4c) = z;
        oa = (u8*)p + 0x4a;
        ov = *oa;
        m = -0x11;
        m &= ov;
        *oa = m;
        {
          register u8 h asm("r1");
          register u8 g2 asm("r0");
          h = p->flags;
          asm("" : "+r"(h));
          g2 = 0xEF;
          g2 &= h;
          p->flags = g2;
        }
      }
      {
        register u8* oa2 asm("r5");
        register s32 zr asm("r3");
        oa2 = oa;
        {
          register s32* cp asm("r0");
          cp = (s32*)((u8*)p + 0xc0);
          zr = 0;
          *cp = zr;
        }
        {
          register u8* gw asm("r2");
          register s32 off asm("r1");
          register u8* dst asm("r0");
          gw = (u8*)&gOverworld;
          off = 0xe8 << 1;
          if ((*(u16*)(gw + off) & 0x7f) == 0xd) {
            off = 0x0002D024;
          } else {
            off = 0x0002D026;
          }
          dst = gw + off;
          *dst = zr;
        }
        {
          register s32 g3 asm("r0");
          register s32 h3 asm("r1");
          register s32 z2 asm("r2");
          h3 = p->flags;
          asm("" : "+r"(h3));
          g3 = 1;
          z2 = 0;
          g3 |= h3;
          p->flags = g3;
          {
            register u8* q asm("r3");
            register s32 ov2 asm("r1");
            register s32 m2 asm("r0");
            register s32 k8 asm("r1");
            q = (u8*)p + 0x49;
            ov2 = *q;
            m2 = 0xd;
            m2 = -m2;
            m2 &= ov2;
            k8 = 8;
            m2 |= k8;
            *q = m2;
          }
          {
            register u8* a2 asm("r0");
            a2 = (u8*)p + 0x24;
            *a2 = z2;
            a2 += 0x29;
            asm("" : "+r"(a2));
            *a2 = z2;
          }
        }
        {
          register s32 ov3 asm("r1");
          register s32 m3 asm("r0");
          ov3 = *oa2;
          m3 = -0x21;
          m3 &= ov3;
          *oa2 = m3;
        }
        {
          register u8 h4 asm("r1");
          register u8 g4 asm("r0");
          h4 = p->flags;
          asm("" : "+r"(h4));
          g4 = 0xDF;
          g4 &= h4;
          p->flags = g4;
        }
      }
      p->work[2] = 0x28;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dx asm("r1");
      register s32 cy asm("r2");
      UpdateEntityAnim((struct Entity*)p);
      {
        register s32 v asm("r0");
        v = p->d.x;
        dx = -v;
        dx <<= 3;
        dx >>= 8;
        v += dx;
        p->d.x = v;
      }
      {
        register s32 v2 asm("r0");
        register s32 lim asm("r1");
        v2 = p->d.y;
        v2 += 0x20;
        p->d.y = v2;
        lim = 0xe0 << 3;
        if (v2 > lim) {
          p->d.y = lim;
        }
      }
      {
        register s32 yv asm("r1");
        register s32 dyv asm("r0");
        yv = p->coord.y;
        dyv = p->d.y;
        cy = yv + dyv;
        p->coord.y = cy;
      }
      {
        register s32 cx asm("r0");
        cx = p->coord.x;
        dx = p->d.x;
        cx += dx;
        p->coord.x = cx;
        if (dx > 0) {
          register s32 k3 asm("r3");
          register s32 yy asm("r1");
          k3 = 0x90 << 5;
          cx += k3;
          k3 = -0x800;
          yy = cy + k3;
          yy = PushoutToLeft2(cx, yy);
          if (yy != 0) {
            p->coord.x += yy;
          }
        }
      }
      if (p->d.x < 0) {
        register s32 xx asm("r0");
        register s32 k4 asm("r1");
        register s32 k5 asm("r2");
        xx = p->coord.x;
        k4 = -0x1200;
        xx += k4;
        k4 = p->coord.y;
        k5 = -0x800;
        k4 += k5;
        k4 = PushoutToRight2(xx, k4);
        if (k4 != 0) {
          p->coord.x += k4;
        }
      }
      {
        register s32 pu asm("r1");
        pu = PushoutToUp2(p->coord.x, p->coord.y);
        if (pu != 0) {
          p->coord.y += pu;
        }
      }
      if (p->work[2] != 0) {
        if ((u8)--p->work[2] != 0) {
          break;
        }
      }
      {
        register s32 z3 asm("r0");
        register s32 three asm("r1");
        z3 = 0;
        three = 3;
        p->mode[1] = three;
        p->mode[2] = z3;
        p->mode[3] = 0xff;
      }
      break;
    }
  }
}

bool8 volteel_080457c4(Volteel* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xc0);
  if (*slot != NULL) {
    return TRUE;
  }
  if (!((p->body).status & 1)) {
    return TRUE;
  }
  {
    const struct Coord* c;
    if (p->mode[1] == 9) {
      u8 w = p->work[3];
      if (w == 0) {
        c = &Coord_ARRAY_08362570[4];
      } else if (w == 1) {
        c = &Coord_ARRAY_08362570[5];
      } else if (w == 2) {
        c = &Coord_ARRAY_08362570[3];
      } else if (w == 3) {
        c = &Coord_ARRAY_08362570[6];
      } else {
        goto after;
      }
    } else {
      c = &Coord_ARRAY_08362570[0];
    }
    *slot = (struct Entity*)ApplyElementEffect(0xd, (struct CollisionObject*)p, c);
  }
after : {
  struct Entity** s2 = (struct Entity**)((u8*)p + 0xc0);
  if (*s2 == NULL) {
    return TRUE;
  }
  if ((*((u8*)p + 0x97) & 0xf0) == 0x30) {
    s32 z;
    u8 v1 = p->mode[1];
    u8* d0 = (u8*)p + 0xd0;
    asm("" : "+r"(d0));
    z = 0;
    *d0 = v1;
    {
      u8 v2 = p->mode[2];
      u8* d1 = (u8*)p + 0xd1;
      u8 v3;
      asm("" : "+r"(d1));
      *d1 = v2;
      v3 = p->mode[3];
      d1 += 1;
      asm("" : "+r"(d1));
      *d1 = v3;
    }
    p->mode[1] = 0xb;
    p->mode[2] = z;
  } else {
    *s2 = NULL;
  }
}
  return TRUE;
}

INCASM("asm/boss/volteel_l_a.inc");

NON_MATCH u16 FUN_08045910(Boss* p, u32 m, s32 flag) {
#if MODERN
  s32 ret;
  s32 i;
  s32 idx;
  const u16* t;
  const u16* q;
  if (flag == 1) {
    ret = ((s32(*)(Boss*))FUN_080459d4)(p);
    if (ret != 0) {
      i = 0;
      t = &unk_080fee80[8];
      q = t;
      do {
        if (*q == m) {
          idx = (i + 1) % 3;
          goto pick;
        }
        q++;
        i++;
      } while (i <= 2);
    } else {
      i = 0;
      t = &unk_080fee80[3];
      q = t;
      do {
        if (*q == m) {
          idx = (i + 1) % 5;
          goto pick;
        }
        q++;
        i++;
      } while (i <= 4);
    }
  } else {
    ret = ((s32(*)(Boss*))FUN_080459d4)(p);
    if (ret != 0) {
      i = 0;
      t = &unk_080fee80[8];
      q = t;
      do {
        if (*q == m) {
          idx = (i + 1) % 3;
          goto pick;
        }
        q++;
        i++;
      } while (i <= 2);
    } else {
      i = 0;
      t = &unk_080fee80[3];
      q = t;
      do {
        if (*q == m) {
          idx = (i + 1) % 4;
          goto pick;
        }
        q++;
        i++;
      } while (i <= 3);
    }
  }
  return ret;
pick:
  return t[idx];
#else
  INCCODE("asm/boss/volteel_p14_p1_b.inc");
#endif
}

bool8 FUN_080459d4(struct Boss* p) {
  if (p->mode[1] == 5) return TRUE;
  return FALSE;
}

void FUN_080459e8(Volteel* p) {
  struct Coord c;
  struct Coord d;
  const s16* st;
  s32 cx = p->coord.x;
  c.x = cx;
  c.y = p->coord.y - 0x3E00;
  if ((p->flags & 0x10) == 0) {
    c.x = cx - 0x1200;
    st = gSineTable;
    d.x = st[0xb2];
    d.y = st[0xf2];
    FUN_0809f4dc((struct Entity*)p, &c, &d, 0x72);
    d.x = st[0xce];
    d.y = st[0xe];
    FUN_0809f4dc((struct Entity*)p, &c, &d, 0x8e);
  } else {
    c.x = cx + 0x1200;
    st = gSineTable;
    d.x = st[0x32];
    d.y = st[0x72];
    FUN_0809f4dc((struct Entity*)p, &c, &d, 0xf2);
    d.x = st[0x4e];
    d.y = st[0x8e];
    FUN_0809f4dc((struct Entity*)p, &c, &d, 0xe);
  }
}

void volteel_08045abc(Volteel* p) {
  if (MOTION_VALUE(p) == MOTION(0xA5, 0x07)) {
    if (p->motion.state == 3) {
      if ((p->flags & X_FLIP) == 0) {
        p->spr.xflip = TRUE;
        p->spr.oam.xflip = TRUE;
        p->flags |= X_FLIP;
      } else {
        p->spr.xflip = FALSE;
        p->spr.oam.xflip = FALSE;
        p->flags &= ~X_FLIP;
      }
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x00));
    }
  } else if (pZero2->s.coord.x > p->coord.x) {
    if ((p->flags & X_FLIP) == 0) {
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x07));
    }
  } else {
    if ((p->flags & X_FLIP) != 0) {
      SetMotion((struct Entity*)p, MOTION(0xA5, 0x07));
    }
  }
}

// --------------------------------------------

// 0x08362330
static const struct Collision sCollisions[24] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, -0x1200, 0x2400, 0x2600},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1800, 0x1C00, 0x2600},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, -0x1900, 0x1E00, 0x2800},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1C00, 0x3C00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, -0x1D00, 0x1E00, 0x3E00},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0200, -0x1C00, 0x1A00, 0x3600},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x2800, -0x0F00, 0x1700, 0x2100},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {-0x0300, -0x1D00, 0x1C00, 0x3800},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0700, -0x1600, 0x1F00, 0x2600},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0A00, -0x3F00, 0x2300, 0x1100},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {-0x0800, -0x1700, 0x2100, 0x2800},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0600, -0x1100, 0x7C00, 0x1000},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0700, -0x1200, 0x7E00, 0x1200},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1100, 0x1000, 0x7C00},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, -0x1200, 0x1200, 0x7E00},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1A00, 0x3600},
    },
    [16] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0100, -0x1D00, 0x1C00, 0x3800},
    },
    [17] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0E00, 0x0000, 0x1C00, 0x0E00},
    },
    [18] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {-0x0F00, 0x0000, 0x1E00, 0x1000},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0E00, 0x0E00, 0x1C00},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, 0x0F00, 0x1000, 0x1E00},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1A00, 0x3600},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      atkType : 0x00,
      element : 0x01,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000002,
      range : {-0x4E00, -0x1900, 0x4500, 0x1000},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0100, -0x1D00, 0x1C00, 0x3800},
    },
};

// 0x08362570
const Coords32 Coord_ARRAY_08362570[7] = {
    {0x00000000, -0x00002000}, {0x00000600, -0x00002500}, {0x00000600, -0x00002500}, {0x00000000, 0x00000400}, {0x00000000, 0x00000400}, {-0x00001000, 0x00000000}, {-0x00001000, 0x00000000},
};
