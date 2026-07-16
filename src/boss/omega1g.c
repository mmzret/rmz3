#include "boss.h"
#include "boss/omega1.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"

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

INCASM("asm/boss/omega1g_a.inc");

static const BossFunc sUpdates1[8];
static const BossFunc sUpdates2[8];
static const BossFunc sDeads[2];
static const struct Collision sCollisions[8];
static void floatGoldOmega1(struct Omega1* p);

void OmegaGold_Update(struct Boss* p) {
  u8 m;
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if (*(s16*)((u8*)p + 0xa4) != 0) {
      goto alive;
    }
  }
  if (gStageRun.missionStatus & MISSION_PLAYER_DEAD) {
    goto alive;
  }
  SET_BOSS_ROUTINE(p, ENTITY_DIE);
  OmegaGold_Die(p);
  return;

alive:
  m = (p->s).mode[1];
  if (m > 1 && m != 6) {
    StepPaletteAnimation(0x66);
  }
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

void OmegaGold_Die(struct Boss* p) { (sDeads[(p->s).mode[1]])(p); }

void OmegaGold_Disappear(struct Boss* p) {
  RemovePaletteAnimation(0xb);
  RemovePaletteAnimation(0x66);
  RemovePaletteAnimation(0x67);
  RemovePaletteAnimation(0x10f);
  DeleteBoss((void*)p);
}

INCASM("asm/boss/omega1g_b.inc");

bool8 FUN_0805b41c(struct Boss* p) { return TRUE; }

void goldOmega1_0805b420(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      if ((p->s).scriptEntity->flags & 1) {
        gOverworld.state[1] = 1;
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_0805b45c(struct Boss* p) { return TRUE; }

void makeGoldOmega1Mode2(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      (p->s).work[2] = 0x3c;
      FALLTHROUGH;
    case 1:
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        (p->s).mode[2]++;
      }
      break;
    case 2:
      (p->s).mode[1] = (p->s).mode[2];
      (p->s).mode[2] = 0;
      break;
  }
}

bool8 FUN_0805b4a4(struct Boss* p) { return TRUE; }

void FUN_0805b4a8(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      if (!(gStageRun.vm.active & VM_ACTIVE)) {
        (p->s).mode[1] = 3, (p->s).mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/boss/omega1g_c.inc");

void goldOmega1Neutral(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).work[3] = 0x1e;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      floatGoldOmega1((struct Omega1*)p);
      break;
  }
}

bool8 nop_0805b5dc(struct Boss* p) { return TRUE; }

INCASM("asm/boss/omega1g_d.inc");

bool8 nop_0805b740(struct Boss* p) { return TRUE; }

void FUN_0805b744(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).spr.xflip = 0;
      (p->s).spr.oam.xflip = 0;
      (p->s).flags &= ~X_FLIP;
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).work[2] = 0xff;
      (p->s).work[3] = -1;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
      } else if ((p->s).work[3] != 0 && --(p->s).work[3] == 0) {
        (p->s).work[2] = 0x3c;
        (p->s).mode[2]++;
      }
      StepPaletteAnimation(0xb);
      floatGoldOmega1((struct Omega1*)p);
      break;
    case 2:
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        (p->s).mode[1] = 3, (p->s).mode[2] = 0;
      }
      StepPaletteAnimation(0xb);
      floatGoldOmega1((struct Omega1*)p);
      break;
  }
}

bool8 nop_0805b7ec(struct Boss* p) { return TRUE; }

void FUN_0805b7f0(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).spr.xflip = 0;
      (p->s).spr.oam.xflip = 0;
      (p->s).flags &= ~X_FLIP;
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).work[2] = 0xFF;
      (p->s).work[3] = -1;
      RemovePaletteAnimation(0x66);
      StartPaletteAnimation(0x67, 0x300);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if ((*(struct Entity**)((u8*)p + 0xc8))->mode[2] > 0x1d) {
        StartPaletteAnimation(0x66, 0x300);
        (p->s).mode[1] = 3, (p->s).mode[2] = 0;
      } else {
        StepPaletteAnimation(0x67);
        floatGoldOmega1((struct Omega1*)p);
      }
      break;
  }
}

void changeGoldOmega1Mode(struct Boss* p);
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

void goldOmega1Laser(struct Boss* p);
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
    struct Entity* fx = (struct Entity*)(p->s).unk_2c;
    if (fx != NULL) {
      if (fx->mode[0] >= ENTITY_DIE) {
        (p->s).unk_2c = NULL;
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
  (p->s).coord.y = (p->s).unk_coord.y + (gSineTable[val] << 3);
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
