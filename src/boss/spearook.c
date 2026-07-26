#include "boss.h"
#include "collision.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"

void nop_08063510(struct Boss* p);

void FUN_08063514(struct Boss* p);

void nop_08063170(struct Boss* p);

void nop_0806316c(struct Boss* p);

void FUN_08062268(struct Boss* p);

void FUN_08062264(struct Boss* p);

void FUN_08062304(struct Boss* p);

void Spearook_Die(struct Boss* p);

static const BossFunc sDeads[5];

INCASM("asm/boss/spearook_a_a.inc");

struct Boss* FUN_08061c74(struct Entity* e) {
  struct Boss* p = (struct Boss*)AllocEntityLast(gBossHeaderPtr);

  if (p != NULL) {
    p->renderPrio = 24;
    INIT_BOSS_ROUTINE(p, 24);
    p->tileNum = 0;
    p->palID = 0;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = p->uniqueID;
    p->work[0] = 1;
    p->unk_28 = e;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = e->uniqueID;
  }
  return p;
}

void FUN_08061ccc(struct Entity* e, struct Entity* e2) {
  struct Boss* p = (struct Boss*)AllocEntityLast(gBossHeaderPtr);

  if (p != NULL) {
    p->renderPrio = 24;
    INIT_BOSS_ROUTINE(p, 24);
    p->tileNum = 0;
    p->palID = 0;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = p->uniqueID;
    p->work[0] = 2;
    p->unk_28 = e;
    p->unk_2c = e2;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = e->uniqueID;
  }
}

INCASM("asm/boss/spearook_a_b_a.inc");

void Spearook_Die(struct Boss* p) {
  (sDeads[p->mode[1]])((void*)p);
}

void FUN_08062264(struct Boss* p) {}

void FUN_08062268(struct Boss* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    p->mode[1] = 0;
    p->mode[2] = 0;
  }
}

INCASM("asm/boss/spearook_b.inc");

void FUN_08062304(struct Boss* p) {
  u32 v = *(u32*)((u8*)p + 0x8c);
  if (v & 1) {
    if (v & 0x20000) {
      *(u32*)((u8*)p + 0xbc) &= ~4;
      p->mode[1] = 14;
      p->mode[2] = 0;
    }
  }
}

INCASM("asm/boss/spearook_c.inc");

void nop_0806316c(struct Boss* p) {}

void nop_08063170(struct Boss* p) {}

INCASM("asm/boss/spearook_d.inc");

void nop_08063510(struct Boss* p) {}

void FUN_08063514(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      EXIT_BODY(p);
      p->d.y = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      {
        s32 push = PushoutToUp1(p->coord.x, p->coord.y);
        if (push < 0) {
          p->coord.y += push;
          CreateSmoke(1, &p->coord);
          PlaySound(0x2a);
          p->flags &= ~DISPLAY;
          p->flags &= ~FLIPABLE;
          EXIT_BODY(p);
          SET_BOSS_ROUTINE(p, ENTITY_DISAPPEAR);
        }
      }
      break;
  }
}

void Spearook_Init(struct Boss* p);
void Spearook_Update(struct Boss* p);
void Spearook_Die(struct Boss* p);

// clang-format off
const BossRoutine gSpearookRoutine = {
    [ENTITY_INIT] =      (void*)Spearook_Init,
    [ENTITY_UPDATE] =    (void*)Spearook_Update,
    [ENTITY_DIE] =       (void*)Spearook_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08062304(struct Boss* p);
void FUN_08062264(struct Boss* p);
void FUN_0806228c(struct Boss* p);
void FUN_08062268(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[17] = {
    FUN_08062304,
    FUN_08062264,
    FUN_0806228c,
    FUN_08062264,
    FUN_08062304,
    FUN_0806228c,
    FUN_08062264,
    FUN_08062304,
    FUN_0806228c,
    FUN_08062304,
    FUN_0806228c,
    FUN_0806228c,
    FUN_0806228c,
    FUN_0806228c,
    FUN_08062304,
    FUN_08062268,
    FUN_08062264,
};
// clang-format on

void FUN_08062338(struct Boss* p);
void FUN_080623bc(struct Boss* p);
void FUN_080624b0(struct Boss* p);
void FUN_08062588(struct Boss* p);
void FUN_0806267c(struct Boss* p);
void FUN_08062754(struct Boss* p);
void FUN_08062848(struct Boss* p);
void FUN_0806293c(struct Boss* p);
void FUN_08062a94(struct Boss* p);
void FUN_08062b70(struct Boss* p);
void FUN_08062bb4(struct Boss* p);
void FUN_08062c78(struct Boss* p);
void FUN_08062e30(struct Boss* p);
void FUN_08062fe0(struct Boss* p);
void FUN_08063074(struct Boss* p);
void nop_0806316c(struct Boss* p);
void nop_08063170(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[17] = {
    FUN_08062338,
    FUN_080623bc,
    FUN_080624b0,
    FUN_08062588,
    FUN_0806267c,
    FUN_08062754,
    FUN_08062848,
    FUN_0806293c,
    FUN_08062a94,
    FUN_08062b70,
    FUN_08062bb4,
    FUN_08062c78,
    FUN_08062e30,
    FUN_08062fe0,
    FUN_08063074,
    nop_0806316c,
    nop_08063170,
};
// clang-format on

// --------------------------------------------

void FUN_08063174(struct Boss* p);
void FUN_080632a0(struct Boss* p);
void FUN_080632f8(struct Boss* p);
void FUN_08063514(struct Boss* p);
void nop_08063510(struct Boss* p);

// clang-format off
static const BossFunc sDeads[5] = {
    FUN_08063174,
    FUN_080632a0,
    FUN_080632f8,
    FUN_08063514,
    nop_08063510,
};
// clang-format on

// --------------------------------------------

// 0x08365784
static const struct Collision sCollisions[17] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
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
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(42), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(20), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 5,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 2,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 7,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(64), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 6,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 5,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 3,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(64), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 2,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
};

static const u8 u8_ARRAY_0836591c[16] = {
    7, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9,
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(16)};
static const u8 sInitModes[4] = {1, 2, 3, 16};

static const u8 u8_ARRAY_08365938[16] = {
    3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7,
};
