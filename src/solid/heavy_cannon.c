#include "collision.h"
#include "global.h"
#include "vfx.h"
#include "element.h"
#include "solid.h"
#include "story.h"
#include "score.h"
#include "zero.h"

void FUN_080b82c0(struct Entity* e, struct Coord* c, motion_t* motions, u8 len);
void TryDropZakoDisk(struct Solid* p, struct Coord* c);

static const struct Collision sCollisions[];

void initHeavyCannon(struct Solid* p);
void heavyCannonAI(struct Solid* p);
void killHeavyCannon(struct Solid* p);
void FUN_080cc284(struct Solid* p);

// clang-format off
const SolidRoutine gHeavyCannonRoutine = {
    [ENTITY_INIT] =      initHeavyCannon,
    [ENTITY_UPDATE] =    heavyCannonAI,
    [ENTITY_DIE] =       killHeavyCannon,
    [ENTITY_DISAPPEAR] = FUN_080cc284,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on


const Coords32 Coord_0836ff28;
struct Projectile* CreateHeavyCannonBall(s32 x, s32 y, u8 f);
const struct Rect Rect_ARRAY_0836ff30[2];
const motion_t gHeavyCannonMotions[3];
const SolidFunc gHeavyCannonUpdates1[3];
const SolidFunc gHeavyCannonUpdates2[3];
static bool8 FUN_080cbdc0(Object* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    struct Entity* next;
    if (p->work[0] < 4) {
      next = (struct Entity*)p->unk_2c;
      while (next != NULL) {
        SET_SOLID_ROUTINE(next, ENTITY_DIE);
        next = (struct Entity*)next->unk_2c;
      }
    } else {
      struct Entity* prev = (struct Entity*)p->unk_28;
      next = (struct Entity*)p->unk_2c;
      if (prev != NULL) prev->unk_2c = next;
      if (next != NULL) next->unk_28 = prev;
    }
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    killHeavyCannon((void*)p);
    return TRUE;
  }
  return FALSE;
}

void FUN_080cbe38(struct Solid* p) {
  struct Entity* parent = (p->s).unk_2c;
  if (parent != NULL) {
    if ((parent->coord).y - (p->s).coord.y > 0x1000) {
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
    } else {
      (p->s).coord.y = (parent->coord).y - 0x1000;
      (p->s).d.y = 0;
    }
  } else {
    (p->s).d.y += 0x40;
    if ((p->s).d.y > 0x700) {
      (p->s).d.y = 0x700;
    }
    (p->s).coord.y += (p->s).d.y;
    if ((p->s).coord.y > *(s32*)((u8*)p + 0xb4)) {
      (p->s).coord.y = *(s32*)((u8*)p + 0xb4);
      (p->s).d.y = 0;
    }
  }
}

void nop_080cbea4(struct Solid* p) {}

INCASM("asm/solid/heavy_cannon_a.inc");

void heavyCannonAI(struct Solid* p) {
  register u8 f asm("r0");
  register u32 g asm("r2");
  if ((p->s).work[0] == 4) {
    u8 fl = gCurStory.s.gameflags[4];
    register s32 c40 asm("r0");
    c40 = 0x40;
    c40 &= fl;
    asm volatile("" ::"r"(fl));
    {
      u32 fv = (u32)c40 << 24;
      asm("" : "+r"(fv));
      g = fv >> 24;
    }
    if (g != 0) {
      u8 t = (p->s).flags;
      f = 0xFE;
      f &= t;
      asm volatile("" ::"r"(t));
      g = 0;
      goto common;
    }
    {
      struct Entity* q = (p->s).unk_28;
      if (q != NULL && q->mode[0] == 4) {
        u8 t = (p->s).flags;
        f = 0xFE;
        f &= t;
        asm volatile("" ::"r"(t));
      common: {
        register u8 k2 asm("r1");
        u8* qq;
        k2 = 0xFD;
        f &= k2;
        (p->s).flags = f;
        qq = (u8*)p + 0x8c;
        asm("" : "+r"(qq));
        *(s32*)qq = g;
        asm("" : "+r"(qq));
        qq += 4;
        asm("" : "+r"(qq));
        *(s32*)qq = g;
        asm("" : "+r"(qq));
        qq += 4;
        asm("" : "+r"(qq));
        *qq = g;
        {
          register u8 f3 asm("r0");
          register u8 t3 asm("r1");
          t3 = (p->s).flags;
          f3 = 0xFB;
          f3 &= t3;
          (p->s).flags = f3;
          asm volatile("" ::"r"(t3));
        }
        SET_SOLID_ROUTINE(p, 3);
        return;
      }
      }
    }
  }
  if (!FUN_080cbdc0((Object*)p)) {
    (gHeavyCannonUpdates1[(p->s).mode[1]])(p);
    (gHeavyCannonUpdates2[(p->s).mode[1]])(p);
  }
}

void killHeavyCannon(struct Solid* p) {
  struct Coord c;
  s32 z;
  {
    u8 f2 = (p->s).flags2 & ~ENTI_PHYSICS;
    z = 0;
    (p->s).flags2 = f2;
  }
  *(u32*)((u8*)p + 0x8c) = z;
  *(u32*)((u8*)p + 0x90) = z;
  *(u8*)((u8*)p + 0x94) = z;
  {
    register u8 fv asm("r1");
    register u8 t asm("r0");
    register u8 k2 asm("r0");
    s32 y;
    t = (p->s).flags;
    fv = 0xFB;
    fv &= t;
    asm volatile("" ::"r"(t));
    k2 = 0xFE;
    fv &= k2;
    (p->s).flags = fv;
    c.x = (p->s).coord.x;
    y = (p->s).coord.y;
    c.y = y - 0x800;
    {
      s32 cy = c.y;
      if ((fv & 0x20) != 0) {
        cy = y + 0x800;
      }
      c.y = cy;
    }
  }
  CreateSmoke(1, &c);
  PlaySound(0x2A);
  FUN_080b82c0(&p->s, &c, (motion_t*)gHeavyCannonMotions, 3);
  if ((p->s).work[0] != 4) {
    struct Coord* pc = &(p->s).coord;
    TryDropItem(0, pc);
    if (gScore.enemyCount <= 0x270E) {
      gScore.enemyCount++;
    }
    TryDropZakoDisk(p, pc);
  }
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080cc284(struct Solid* p) {
  (p->s).flags2 &= ~ENTI_PHYSICS;
  DeleteSolid((Object*)p);
}

void FUN_080cc298(struct Solid* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb8);
  struct Entity* old = *slot;
  if (old == NULL && (*(u32*)((u8*)p + 0x8c) & 1)) {
    *slot = (struct Entity*)ApplyElementEffect(0, (struct CollisionObject*)p, &Coord_0836ff28);
    if (*slot != NULL) {
      (p->s).mode[1] = 2;
      (p->s).mode[3] = (u8)(u32)old;
    }
  }
}

void FUN_080cc2d4(struct Solid* p) {
  struct Entity** q = (struct Entity**)((u8*)p + 0xb8);
  if (*q == NULL || isKilled(*q)) {
    s32 z = 0;
    *q = NULL;
    if ((p->s).work[0] <= 3) {
      (p->s).mode[1] = z;
      SetDDP(&p->body, &sCollisions[3]);
    } else {
      (p->s).mode[1] = 1;
      SetDDP(&p->body, &sCollisions[1]);
    }
  }
}

void FUN_080cc320(struct Solid* p) {
  register s32 nm asm("r0");
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 g asm("r1");
      register s32 k asm("r0");
      register const struct Rect* rc asm("r1");
      (p->s).work[2] = 0x30;
      g = (p->s).flags2;
      asm("" : "+r"(g));
      k = 8;
      k |= g;
      (p->s).flags2 = k;
      rc = Rect_ARRAY_0836ff30;
      asm("" : "+r"(rc));
      if ((p->s).work[0] == 3) {
        rc = (const struct Rect*)((u8*)rc + 8);
      }
      (p->s).size = (struct Rect*)rc;
      (p->s).physicsAttr = 0x801;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      SetDDP(&p->body, &sCollisions[3]);
      SetMotion(&p->s, 0x3801);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 2: {
      register s32 f asm("r2");
      (p->s).work[2]--;
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] == 0) {
        (p->s).mode[2] = 5;
        return;
      }
      f = 0;
      if ((p->s).coord.x < (pZero2->s).coord.x) {
        f = 1;
      }
      if (((p->s).flags & 0x10) != 0) {
        if (f == 0) {
          goto adv;
        }
        break;
      }
      if (f == 0) {
        break;
      }
    adv:
      nm = (p->s).mode[2] + 1;
      goto setmode;
    }
    case 3:
      SetMotion(&p->s, 0x3803);
      (p->s).work[3] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      register s32 xf asm("r1");
      register s32 fl asm("r2");
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      if ((p->s).work[3] == 1) {
        (p->s).mode[2] = 0;
        return;
      }
      {
        register s32 sh asm("r0");
        fl = (p->s).flags;
        sh = (u32)fl >> 4;
        xf = 1;
        xf &= ~sh;
        if (xf != 0) {
          register s32 g2 asm("r0");
          g2 = 0x10;
          g2 |= fl;
          (p->s).flags = g2;
        } else {
          register s32 g3 asm("r0");
          g3 = 0xEF;
          g3 &= fl;
          (p->s).flags = g3;
        }
      }
      {
        register u8* oa asm("r3");
        s32 sh4, ov, m11;
        *((u8*)p + 0x4c) = xf;
        oa = (u8*)p + 0x4a;
        sh4 = xf << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
      }
      (p->s).work[3]++;
      SetMotion(&p->s, 0x3808);
      UpdateEntityAnim(&p->s);
      break;
    }
    case 5: {
      register s32 bx asm("r5");
      register s32 fl2 asm("r2");
      {
        register s32 cx asm("r1");
        register s32 k2 asm("r0");
        cx = (p->s).coord.x;
        k2 = -0x1800;
        bx = cx + k2;
        fl2 = (p->s).flags;
        k2 = 0x10;
        k2 &= fl2;
        if (k2 != 0) {
          k2 = 0xc0 << 5;
          bx = cx + k2;
        }
      }
      {
        register s32 cy asm("r3");
        register s32 by asm("r1");
        register s32 k3 asm("r0");
        cy = (p->s).coord.y;
        k3 = -0x900;
        by = cy + k3;
        k3 = 0x20;
        k3 &= fl2;
        if (k3 != 0) {
          k3 = 0x90 << 4;
          by = cy + k3;
        }
        {
          register s32 xf2 asm("r2");
          register s32 one asm("r0");
          xf2 = (u32)fl2 >> 4;
          one = 1;
          xf2 &= one;
          ((void (*)(s32, s32, s32))CreateHeavyCannonBall)(bx, by, xf2);
        }
      }
      SetMotion(&p->s, 0x3802);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 6:
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      (p->s).work[2] = 0x70;
      nm = 1;
    setmode:
      (p->s).mode[2] = nm;
      break;
  }
  FUN_080cbe38(p);
}

void FUN_080cc4dc(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion(&p->s, MOTION(0x38, 0));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&p->s);
      break;
  }
  FUN_080cbe38(p);
}

// --------------------------------------------

void FUN_080cc298(struct Solid* p);
void FUN_080cc2d4(struct Solid* p);

const SolidFunc gHeavyCannonUpdates1[3] = {
    (void*)FUN_080cc298,
    (void*)FUN_080cc298,
    (void*)FUN_080cc2d4,
};

void FUN_080cc320(struct Solid* p);
void FUN_080cc4dc(struct Solid* p);
static void FUN_080cc51c(struct Solid* p);

const SolidFunc gHeavyCannonUpdates2[3] = {
    (void*)FUN_080cc320,
    (void*)FUN_080cc4dc,
    (void*)FUN_080cc51c,
};

// --------------------------------------------

void FUN_080cbe38(struct Solid* p);

static void FUN_080cc51c(struct Solid* p) {
  if ((p->s).mode[3] == 0) {
    if ((p->s).work[0] < 4) {
      SetDDP(&p->body, &sCollisions[5]);
    } else {
      SetDDP(&p->body, &sCollisions[2]);
    }
    (p->s).mode[3]++;
  }
  FUN_080cbe38((void*)p);
}

// --------------------------------------------

// 0x0836FE8C
static const struct Collision sCollisions[6] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(16)},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(16)},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      nature : 0x04,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(25), PIXEL(22), PIXEL(8)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(26), PIXEL(31)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(26), PIXEL(23)},
    },
};

// 0x0836ff1c
const u8 u8_ARRAY_0836ff1c[6] = {0, 0, 0, 0, 1, 0};

// 0x0836ff22
const motion_t gHeavyCannonMotions[3] = {
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 6),
    MOTION(SM056_HEAVY_CANNON, 7),
};

// 0x0836ff28
const Coords32 Coord_0836ff28 = {PIXEL(0), -PIXEL(8)};

// 0x0836ff30
const struct Rect Rect_ARRAY_0836ff30[2] = {
    {PIXEL(0), PIXEL(9), PIXEL(22), PIXEL(64)},
    {PIXEL(0), PIXEL(10), PIXEL(22), PIXEL(26)},
};
