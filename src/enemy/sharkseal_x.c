#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "overworld.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x_b4;               // 0xB4
  u8 unk_b8[4];           // 0xB8
  u8 xflip_bc;            // 0xBC
  u8 unk_bd;              // 0xBD
  u8 unk_be;              // 0xBE
  u8 unk_bf;              // 0xBF
  struct Entity* unk_c0;  // 0xC0
} SharksealX;
static_assert(sizeof(SharksealX) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
SharksealX* forceWaterLanding(SharksealX* p);

static void SharksealX_Init(SharksealX* p);
void SharksealX_Update(SharksealX* p);
void SharksealX_Die(SharksealX* p);

// clang-format off
const EnemyRoutine gSharksealXRoutine = {
    [ENTITY_INIT] =      (void*)SharksealX_Init,
    [ENTITY_UPDATE] =    (void*)SharksealX_Update,
    [ENTITY_DIE] =       (void*)SharksealX_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x08070028
static struct Entity* Unused_CreateSharksealX(Coords32* c, u8 kind) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SHARKSEAL_X);
    p->coord = *c, p->work[0] = kind;
  }
  return p;
}

static void SharksealX_OnCollision(struct Body* body, Coords32* c1, Coords32* _ UNUSED);

static void SharksealX_Init(SharksealX* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_121) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 10);
  } else {
    _INIT_BODY(p, sCollisions, 6);
  }
  SET_BODY_INTERSECT_HANDLER(p, SharksealX_OnCollision);

  if (gOverworld.sea > (p->coord).y) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  p->x_b4 = (p->coord).x;
  (&p->d)->x = (&p->d)->y = 0;
  p->unk_c0 = NULL;
  p->unk_bd = 0;
  p->x_b4 = (p->coord).x;
  (p->unk_coord).y = (p->coord).y;
  (&p->d)->x = (&p->d)->y = 0;
  p->xflip_bc = FALSE;
  if (IsFrozen(p)) {
    SetSpriteAnimation(p, MOTION(SM024_SHARKSEAL_X, 0));
    UpdateSpriteAnimation(p);
  }
  p->unk_bf = 0;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  SharksealX_Update(p);
}

INCASM("asm/enemy/sharkseal_x_a.inc");

bool8 FUN_080707d0(SharksealX* p) { return TRUE; }

void nop_080707d4(SharksealX* p) {}

bool8 FUN_080707d8(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_b.inc");

bool8 FUN_080708dc(SharksealX* p) { return TRUE; }

void sharksealxMode2(SharksealX* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM024_SHARKSEAL_X, 0));
      SetDDP(&p->body, &sCollisions[0]);
      (&p->d)->x = (&p->d)->y = 0;
      SET_XFLIP(p, p->xflip_bc);
      p->work[2] = 24;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      (p->d).y += PIXEL(1) / 8;
      if ((p->d).y > PIXEL(1)) (p->d).y = PIXEL(1);
      p->coord.y += (p->d).y;
      forceWaterLanding(p);
      if (p->work[2] == 0 || --p->work[2] == 0) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
      break;
    }
  }
}

bool8 FUN_08070990(SharksealX* p) { return TRUE; }

void sharksealxMode3(SharksealX* p0) {
  register SharksealX* p asm("r5");
  p = p0;
  switch (p->mode[2]) {
    case 0: {
      u32 b6;
      u32 x1;
      p->d.y = 0;
      SetMotion((struct Entity*)p, 0x1800);
      SetDDP(&p->body, &sCollisions[0]);
      b6 = *((u8*)p + 0xbc);
      {
        register u32 flr asm("r0");
        if (b6 != 0) {
          u32 va = p->flags;
          flr = 0x10;
          flr |= va;
        } else {
          u32 vb = p->flags;
          flr = 0xEF;
          flr &= vb;
        }
        p->flags = flr;
      }
      x1 = 1 & b6;
      (p->spr).xflip = x1;
      (p->spr).oam.xflip = x1;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 dy;
      s32 tgt;
      u8* bc;
      s32 acc;
      UpdateEntityAnim((struct Entity*)p);
      if (p->coord.y > (pZero2->s).coord.y + -0x1400) {
        if (p->d.y < 0) {
          p->d.y = 0;
        }
        dy = p->d.y;
        tgt = 0x100;
      } else {
        if (p->d.y > 0) {
          p->d.y = 0;
        }
        dy = p->d.y;
        tgt = -0x100;
      }
      dy += ((tgt - dy) * 40) >> 8;
      p->d.y = dy;
      p->coord.y -= dy;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *(u8*)a0;
        bc = (u8*)a0;
        asm("" : "+r"(bc));
        if (d0 == 0) {
          p->d.x += -0x200;
          if (p->d.x < -0x200) {
            p->d.x = -0x200;
          }
        } else {
          p->d.x += 0x200;
          if (p->d.x > 0x200) {
            p->d.x = 0x200;
          }
        }
      }
      p->coord.x += p->d.x;
      acc = (s32)((u8*)p + 0xb8);
      *(s32*)acc += p->d.x;
      forceWaterLanding((SharksealX*)p);
      if (*bc == 0) {
        if ((pZero2->s).coord.x > p->coord.x) {
          p->mode[2]++;
        }
      } else {
        if ((pZero2->s).coord.x < p->coord.x) {
          p->mode[2]++;
        }
      }
      acc = *(s32*)acc;
      if (acc < 0) {
        acc = -acc;
      }
      if (acc > 0x12000) {
        p->mode[1] = 4;
        p->mode[2] = 0;
      }
      break;
    }
    case 2:
      p->work[2] = 0x18;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 nd;
      s32 nx;
      UpdateEntityAnim((struct Entity*)p);
      {
        register s32 od asm("r1");
        register s32 ndp asm("r3");
        register s32 tmp asm("r0");
        od = p->d.y;
        tmp = (-od << 4) >> 8;
        asm("" : "+r"(tmp));
        ndp = od + tmp;
        asm("" : "+r"(ndp));
        nd = ndp;
      }
      p->d.y = nd;
      nx = p->d.x;
      nx += (-nx * 0xB) >> 8;
      p->d.x = nx;
      p->coord.x += nx;
      {
        s32 wy = (pZero2->s).coord.y + -0x1400;
        asm volatile("" ::"r"(wy));
      }
      {
        register s32 t9 asm("r1");
        register s32 cy asm("r0");
        t9 = p->coord.y;
        cy = t9 - nd;
        asm volatile("str %0, [%1, #0x58]" :: "r"(cy), "r"(p) : "memory");
      }
      forceWaterLanding((SharksealX*)p);
      {
        s32 t = p->work[2];
        if (t != 0) {
          t--;
          p->work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 4:
      SetMotion((struct Entity*)p, 0x1801);
      SetDDP(&p->body, &sCollisions[2]);
      p->work[2] = 0xC;
      p->work[3] = 2;
      p->mode[2]++;
      FALLTHROUGH;
    case 5: {
      s32 nd2;
      s32 nx2;
      u32 z;
      {
        register s32 od2 asm("r1");
        register s32 tmp2 asm("r0");
        register s32 ndp2 asm("r3");
        od2 = p->d.y;
        tmp2 = (-od2 << 4) >> 8;
        ndp2 = od2 + tmp2;
        nd2 = ndp2;
      }
      p->d.y = nd2;
      nx2 = p->d.x;
      nx2 += (-nx2 * 0xB) >> 8;
      p->d.x = nx2;
      p->coord.x += nx2;
      {
        register s32 wy2 asm("r0");
        register s32 offs asm("r1");
        wy2 = (pZero2->s).coord.y;
        offs = -0x1400;
        asm volatile("add %0, %0, %1" : "+r"(wy2) : "r"(offs));
      }
      {
        register s32 t9b asm("r1");
        register s32 cy2 asm("r0");
        t9b = p->coord.y;
        cy2 = t9b - nd2;
        asm volatile("str %0, [%1, #0x58] " :: "r"(cy2), "r"(p) : "memory");
      }
      forceWaterLanding((SharksealX*)p);
      {
        s32 t2 = p->work[2];
        if (t2 != 0) {
          t2--;
          p->work[2] = t2;
          if ((t2 << 24) != 0) {
            goto upd;
          }
        }
      }
      p->work[2] = 0xC;
      {
        s32 t3 = p->work[3];
        if (t3 == 0) {
          goto upd;
        }
        t3--;
        p->work[3] = t3;
        z = (u8)t3;
      }
      if (z == 0) {
        p->mode[2] = z;
        break;
      }
      {
        u8* bc2 = (u8*)p + 0xbc;
        u32 b7;
        u32 x2;
        *bc2 ^= 1;
        b7 = *bc2;
        {
          register u32 flr2 asm("r0");
          if (b7 != 0) {
            flr2 = p->flags | 0x10;
          } else {
            register u8 flvb asm("r1");
            flvb = p->flags;
            flr2 = 0xEF;
            flr2 &= flvb;
          }
          p->flags = flr2;
        }
        x2 = 1 & b7;
        (p->spr).xflip = x2;
        (p->spr).oam.xflip = x2;
      }
      SetDDP(&p->body, &sCollisions[0]);
      SetMotion((struct Entity*)p, 0x1806);
    upd:
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

bool8 FUN_08070c68(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_d.inc");

bool8 FUN_08070f3c(SharksealX* p) { return TRUE; }

void sharksealxMode5(SharksealX* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[4]);
    p->mode[2]++;
  }
  if (isKilled(p->unk_c0)) {
    SetDDP(&p->body, &sCollisions[0]);
    p->unk_c0 = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

bool8 FUN_08070f8c(SharksealX* p) { return TRUE; }

void nop_08070f90(SharksealX* p) {}

bool8 FUN_08070f94(SharksealX* p) { return TRUE; }

INCASM("asm/enemy/sharkseal_x_e.inc");

bool8 FUN_080707d0(SharksealX* p);
bool8 FUN_080707d8(SharksealX* p);
bool8 FUN_080708dc(SharksealX* p);
bool8 FUN_08070990(SharksealX* p);
bool8 FUN_08070c68(SharksealX* p);
bool8 FUN_08070f3c(SharksealX* p);
bool8 FUN_08070f8c(SharksealX* p);
bool8 FUN_08070f94(SharksealX* p);

// clang-format off
static bool8 (*const sSharksealXUpdates1[8])(SharksealX*) = {
    FUN_080707d0,
    FUN_080707d8,
    FUN_080708dc,
    FUN_08070990,
    FUN_08070c68,
    FUN_08070f3c,
    FUN_08070f8c,
    FUN_08070f94,
}; // 0x08366A04
// clang-format on

void nop_080707d4(SharksealX* p);
void sharksealxMode1(SharksealX* p);
void sharksealxMode2(SharksealX* p);
void sharksealxMode3(SharksealX* p);
void sharksealxMode4(SharksealX* p);
void sharksealxMode5(SharksealX* p);
void nop_08070f90(SharksealX* p);
void sharksealxMode7(SharksealX* p);

// clang-format off
static void (*const sSharksealXUpdates2[8])(SharksealX*) = {
    nop_080707d4,
    sharksealxMode1,
    sharksealxMode2,
    sharksealxMode3,
    sharksealxMode4,
    sharksealxMode5,
    nop_08070f90,
    sharksealxMode7,
}; // 0x08366A24
// clang-format on

bool32 nop_080711d4(void* _ UNUSED) { return TRUE; }

// 0x080711d8
static void SharksealX_OnCollision(struct Body* body, Coords32* c1, Coords32* _ UNUSED) {
  const u8 atktype = (body->enemy)->processing->atkType;
  if ((atktype == ATK_UNK3) || (atktype == ATK_UNK14) || (atktype == ATK_UNK15)) {
    SharksealX* p = (SharksealX*)body->parent;
    if ((p->body).status & BODY_STATUS_DEAD) {
      if ((p->coord).x < c1->x) {
        p->unk_bf = 0xFF;
      } else {
        p->unk_bf = 0xFE;
      }
    }
  }
}

// 0x08071220
SharksealX* forceWaterLanding(SharksealX* p) {
  if (gOverworld.sea > (p->coord).y) {
    (p->coord).y = gOverworld.sea;
  }
}

// 0x08366A44
static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(5), PIXEL(0), PIXEL(30), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(5), PIXEL(0), PIXEL(32), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(4), PIXEL(1), PIXEL(18), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(5), PIXEL(1), PIXEL(18), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(5), PIXEL(0), PIXEL(32), PIXEL(11)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};  // 0x08366ABC
