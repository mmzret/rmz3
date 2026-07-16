#include "boss.h"
#include "boss/omega1.h"
#include "collision.h"
#include "global.h"

// Omega (1st gold)

void OmegaGold_Init(struct Boss* p);
void OmegaGold_Update(struct Boss* p);
void OmegaGold_Die(struct Boss* p);
void OmegaGold_Disappear(struct Boss* p);

// clang-format off
const BossRoutine gOmegaGoldRoutine = {
    [ENTITY_INIT] =      (void*)OmegaGold_Init,
    [ENTITY_UPDATE] =    (void*)OmegaGold_Update,
    [ENTITY_DIE] =       (void*)OmegaGold_Die,
    [ENTITY_DISAPPEAR] = (void*)OmegaGold_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* CreateOmegaGold(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_OMEGA_GOLD);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/boss/omega1g.inc");

void FUN_0805b41c(struct Boss* p);
void FUN_0805b45c(struct Boss* p);
void FUN_0805b4a4(struct Boss* p);
void changeGoldOmega1Mode(struct Boss* p);
void nop_0805b5dc(struct Boss* p);
void nop_0805b740(struct Boss* p);
void nop_0805b7ec(struct Boss* p);
static bool32 nop_0805b874(void* _ UNUSED);

// clang-format off
static const BossFunc sUpdates1[8] = {
    (void*)FUN_0805b41c,
    (void*)FUN_0805b45c,
    (void*)FUN_0805b4a4,
    (void*)changeGoldOmega1Mode,
    (void*)nop_0805b5dc,
    (void*)nop_0805b740,
    (void*)nop_0805b7ec,
    (void*)nop_0805b874,
};
// clang-format on

// --------------------------------------------

void goldOmega1_0805b420(struct Boss* p);
void makeGoldOmega1Mode2(struct Boss* p);
void FUN_0805b4a8(struct Boss* p);
void goldOmega1Neutral(struct Boss* p);
void goldOmega1Laser(struct Boss* p);
void FUN_0805b744(struct Boss* p);
void FUN_0805b7f0(struct Boss* p);
static void FUN_0805b878(struct Entity* p);

// clang-format off
static const BossFunc sUpdates2[8] = {
    (void*)goldOmega1_0805b420,
    (void*)makeGoldOmega1Mode2,
    (void*)FUN_0805b4a8,
    (void*)goldOmega1Neutral,
    (void*)goldOmega1Laser,
    (void*)FUN_0805b744,
    (void*)FUN_0805b7f0,
    (void*)FUN_0805b878,
};
// clang-format on

// --------------------------------------------

void FUN_0805b270(struct Boss* p);
void FUN_0805b358(struct Boss* p);

static const BossFunc sDeads[2] = {
    FUN_0805b270,
    FUN_0805b358,
};

// --------------------------------------------

static bool32 nop_0805b874(void* _) { return TRUE; }

static void FUN_0805b878(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      (p->d).x = 0, (p->d).y = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->d).y += (PIXEL(1) / 4);
      if ((p->d).y > (PIXEL(1) / 4)) {
        (p->d).y = (PIXEL(1) / 4);
      }
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

extern const u16 u16_ARRAY_080fefd0[3];

u16 FUN_0805b8ac(struct Boss* _, u32 old) {
  s32 i;
  for (i = 0; i < (s32)ARRAY_COUNT(u16_ARRAY_080fefd0); i++) {
    if (u16_ARRAY_080fefd0[i] == old) {
      return u16_ARRAY_080fefd0[(i + 1) % ((s32)ARRAY_COUNT(u16_ARRAY_080fefd0))];
    }
  }
}

// 0x0805b8e0
static void onCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  {
    struct Boss* p = (struct Boss*)body->parent;
    struct Entity* fx = (struct Entity*)p->unk_2c;
    if (fx != NULL) {
      if (fx->mode[0] >= ENTITY_DIE) {
        p->unk_2c = NULL;
      } else {
        fx->flags &= ~DISPLAY;
      }
    }
  }
  {
    struct Omega1* p = (struct Omega1*)body->parent;
    struct Entity* fx = p->unk_bc;
    if (fx != NULL) {
      if (fx->mode[0] >= ENTITY_DIE) {
        p->unk_bc = NULL;
      } else {
        fx->flags &= ~DISPLAY;
      }
    }
  }
}

// 0x0805B924
// オメガが縦にふわふわする処理
static void floatGoldOmega1(struct Omega1* p) {
  u16 val = (p->unk_c0 + 1) & 0xFF;
  p->unk_c0 = val;
  p->coord.y = p->unk_coord.y + (gSineTable[val] << 3);
}

// --------------------------------------------

// 0x08364c74
static const struct Collision sCollisions[8] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(3), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(20), -PIXEL(64), PIXEL(54), -PIXEL(128)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {PIXEL(2), -PIXEL(102), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(16), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(3), PIXEL(40), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(3), PIXEL(40), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(24), PIXEL(24)},
    },
};
