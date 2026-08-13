#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "zero.h"
#include "vfx.h"
#include "score.h"

struct VFX* CreateGhost17_1(struct Entity* p);
void CreateGhost17_2(struct Entity* p, struct Coord* c);
struct Entity* FUN_080b2b40(u8 kind, struct Coord* c, s32 r2, u8 r3);

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x;           // 0xB4
  bool8 xflip_b8;  // 0xB8
  u8 unk_b9;       // 0xB9
  u8 unk_ba;       // 0xBA
  u8 unk_bb;       // 0xBB
  u8 unk_bc;       // 0xBC
  u8 unk_bd;       // 0xBD
  u8 unk_be;       // 0xBE
  u8 unk_bf;       // 0xBF
  Entity* elfx;    // 0xC0, Element FX
} PantheonGuardian;
static_assert(sizeof(PantheonGuardian) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
static const Coords32 Coord_08365b70;

void PantheonGuardian_OnCollision(struct Body* body, Coords32* c1, Coords32* c2);

// ------------------------------------------------------------------------------------------------------------------------------------

static void PantheonGuardian_Init(PantheonGuardian* p);
void PantheonGuardian_Update(PantheonGuardian* p);
void PantheonGuardian_Die(PantheonGuardian* p);

// clang-format off
const EnemyRoutine gPantheonGuardianRoutine = {
    [ENTITY_INIT] =      (void*)PantheonGuardian_Init,
    [ENTITY_UPDATE] =    (void*)PantheonGuardian_Update,
    [ENTITY_DIE] =       (void*)PantheonGuardian_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void PantheonGuardian_Init(PantheonGuardian* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_P_GUARDIAN_HP4) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 14);
  } else {
    _INIT_BODY(p, sCollisions, 10);
  }
  SET_BODY_INTERSECT_HANDLER(p, PantheonGuardian_OnCollision);
  p->x = (p->coord).x;
  (p->coord).y = FUN_08009f6c((p->coord).x, (p->coord).y);
  (p->d).x = (p->d).y = 0;
  p->elfx = NULL;
  p->xflip_b8 = 0;
  p->unk_b9 = 0;

  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  if (((pZero2->s).coord).x - (p->coord).x < 0) {
    p->mode[1] = 1, p->mode[2] = 0;
  } else {
    p->mode[1] = 2, p->mode[2] = 0;
  }
  PantheonGuardian_Update(p);
}

INCASM("asm/enemy/pantheon_guardian_a.inc");

void PantheonGuardian_Die(PantheonGuardian* p) {
  struct Coord c;
  if (gCurStory.s.gameflags[4] & 0x40) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  switch (p->mode[1]) {
    case 0: {
      s32 kc;
      SetMotion((struct Entity*)p, MOTION(0x14, 0x04));
      {
        u8* a0 = (u8*)p + 0xb8;
        u32 d0 = *a0;
        u8* b8 = a0;
        asm("" : "+r"(b8));
        if (d0 != 0) {
          SET_XFLIP(p, 0);
        } else {
          SET_XFLIP(p, 1);
        }
        {
          u32 s = (p->body).status;
          kc = 0x200;
          if ((s & kc) != 0 && *((u8*)p + 0xb9) == 0 && (s & 0x10000) != 0 &&
              FUN_080098a4(p->coord.x, p->coord.y + 0x40) != 0) {
            c.x = p->coord.x;
            c.y = p->coord.y + -0x1400;
            if (*b8 != 0) {
              FUN_080b2b40(0, &c, kc, 0);
            } else {
              FUN_080b2b40(0, &c, kc, 1);
            }
            p->mode[1]++;
          } else {
            p->mode[1] = 0xA;
          }
        }
      }
      EXIT_BODY(p);
      FALLTHROUGH;
    }
    case 1:
    case 10:
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      goto bump;
    case 2:
      InitRotatableMotion((struct Entity*)p);
      SetMotion((struct Entity*)p, MOTION(0x14, 0x06));
      if (*((u8*)p + 0xb8) != 0) {
        SET_XFLIP(p, 0);
      } else {
        SET_XFLIP(p, 1);
      }
      CreateGhost17_1((struct Entity*)p);
      p->work[2] = 0;
      p->work[3] = 1;
      p->mode[1]++;
      FALLTHROUGH;
    case 3: {
      s32 d, d2, nx;
      UpdateEntityAnim((struct Entity*)p);
      {
        register s32 off asm("r6");
        u32 w2 = p->work[2];
        u32 nw3 = (w2 >> 5) + p->work[3];
        s32 s1;
        p->work[3] = nw3;
        s1 = gSineTable[(u8)(w2 + nw3)];
        asm volatile("" ::: "memory");
        d = s1 - gSineTable[p->work[2]];
        p->coord.y -= d * 10;
        if (*((u8*)p + 0xb8) != 0) {
          u32 a;
          register u32 n2 asm("r2");
          *((u8*)p + 0x24) = w2;
          a = p->work[2];
          n2 = a + p->work[3];
          d2 = gSineTable[(u8)(n2 + 0x40)] - gSineTable[(u8)(a + 0x40)];
          nx = p->coord.x - d2 * 10;
          p->coord.x = nx;
          p->work[2] = n2;
          n2 = (u8)n2;
          if (n2 <= 0x3F) {
            break;
          }
          off = 0xA00;
        } else {
          u32 a;
          register u32 n2 asm("r2");
          *((u8*)p + 0x24) = w2;
          a = p->work[2];
          n2 = a + p->work[3];
          d2 = gSineTable[(u8)(n2 + 0x40)] - gSineTable[(u8)(a + 0x40)];
          nx = p->coord.x + d2 * 10;
          p->coord.x = nx;
          p->work[2] = n2;
          n2 = (u8)n2;
          if (n2 <= 0x3F) {
            break;
          }
          off = -0xA00;
        }
        c.x = nx + off;
        asm volatile("" ::"r"(off));
        c.y = p->coord.y;
      }
      CreateSmoke(1, &c);
      PlaySound(0x2A);
    bump:
      p->mode[1]++;
      break;
    }
    case 11:
      c.x = p->coord.x;
      {
        s32 t0 = p->coord.y;
        register s32 ka asm("r1");
        ka = -0xA00;
        asm("" : "+r"(ka));
        c.y = t0 + ka;
      }
      CreateSmoke(1, &c);
      {
        s32 t = c.y;
        register s32 kb asm("r5");
        kb = -0xC00;
        asm("" : "+r"(kb));
        c.y = t + kb;
      }
      CreateSmoke(2, &c);
      PlaySound(0x2A);
      CreateGhost17_2((struct Entity*)p, &c);
      FALLTHROUGH;
    case 4: {
      struct Coord* cp = &p->coord;
      TryDropItem(4, cp);
      if (gScore.enemyCount <= 0x270E) {
        gScore.enemyCount++;
      }
      DropEnemyDisk(p, cp);
      p->flags &= ~DISPLAY;
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
    }
  }
}

INCASM("asm/enemy/pantheon_guardian_b.inc");

void FUN_08063da0(PantheonGuardian* p);
void doNothing_08063e10(PantheonGuardian* p);
void FUN_08063e28(PantheonGuardian* p);
void FUN_08063e80(PantheonGuardian* p);
void FUN_08063ec8(PantheonGuardian* p);
void FUN_08063ef4(PantheonGuardian* p);
void FUN_08063f28(PantheonGuardian* p);

// clang-format off
static void (*const sPantheonGuardianUpdates1[9])(PantheonGuardian*) = {
    FUN_08063da0,
    FUN_08063da0,
    FUN_08063da0,
    doNothing_08063e10,
    FUN_08063e28,
    FUN_08063e80,
    FUN_08063ec8,
    FUN_08063ef4,
    FUN_08063f28,
}; // 0x08365a80
// clang-format on

void FUN_08063f50(PantheonGuardian* p);
void FUN_08063fd8(PantheonGuardian* p);
void FUN_080640dc(PantheonGuardian* p);
void FUN_080641ec(PantheonGuardian* p);
void FUN_0806429c(PantheonGuardian* p);
void FUN_08064354(PantheonGuardian* p);
void FUN_08064444(PantheonGuardian* p);
void FUN_0806447c(PantheonGuardian* p);
void FUN_080644fc(PantheonGuardian* p);

// clang-format off
static void (*const sPantheonGuardianUpdates2[9])(PantheonGuardian*) = {
    FUN_08063f50,
    FUN_08063fd8,
    FUN_080640dc,
    FUN_080641ec,
    FUN_0806429c,
    FUN_08064354,
    FUN_08064444,
    FUN_0806447c,
    FUN_080644fc,
};  // 0x08365aa4
// clang-format on

// --------------------------------------------

// 0x08365ac8
static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1000, 0x1000, 0x2000},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1000, -0x1000, 0x3000, 0x1000},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1000, 0x1000, 0x2000},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x1000, 0x1000},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
};

static const Coords32 Coord_08365b70 = {0, -PIXEL(16)};
