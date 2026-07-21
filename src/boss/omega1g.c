#include "boss.h"
#include "boss/omega1.h"
#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"

// Omega (1st gold)

static const struct Collision sCollisions[8];
static void Omega1g_OnCollision(struct Body* body, Coords32* c1, Coords32* c2);

static void OmegaGold_Init(Omega1* p);
static void OmegaGold_Update(Omega1* p);
static void OmegaGold_Die(Omega1* p);
static void OmegaGold_Disappear(Omega1* p);

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

void FUN_08016080(void*);

static void OmegaGold_Init(Omega1* p) {
  s32 y;
  Coords32 c;
  struct Body* body;
  void* fn;

  FUN_08016080(p);
  gOverworld.state[1] = 1;
  LOAD_STATIC_GRAPHIC(SM009_OMEGA_HAND);
  LOAD_STATIC_GRAPHIC(SM010_OMEGA_RING);
  wStaticGraphicTilenums[SM012_OMEGA_RUBBLE] = 768, wStaticMotionPalIDs[SM012_OMEGA_RUBBLE] = 7;
  LOAD_STATIC_GRAPHIC(SM012_OMEGA_RUBBLE);
  wStaticGraphicTilenums[SM101_OMEGA_WHITE_SWORD] = 788, wStaticMotionPalIDs[SM101_OMEGA_WHITE_SWORD] = 8;
  LOAD_STATIC_GRAPHIC(SM101_OMEGA_WHITE_SWORD);

  ResetBossBody((void*)p, &sCollisions[0], 96);
  SET_BOSS_COLLISION_HANDLER(p, Omega1g_OnCollision);

  p->unk_b4[0] = 0;
  p->unk_b4[1] = 0xFF;
  p->unk_b4[2] = 0xFF;
  p->unk_bc = NULL;
  p->unk_b4[3] = 0;
  p->unk_c0 = 0;

  y = (p->coord).y - PIXEL(80);
  (p->coord).y = FUN_08009f6c((p->coord).x, y);
  (p->unk_coord).y = p->unk_y = (p->coord).y;

  if (p->work[0] == 0) {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 3, p->mode[2] = 0, p->mode[3] = 0;
  }
  FUN_08082b58(&c, FALSE, p);
  p->unk_2c = NULL;
  FUN_08082b58(&c, TRUE, p);
  p->sword = CreateOmega1gSword(&p->coord, 0, p);
  StartPaletteAnimation(11, 672);
  StartPaletteAnimation(102, 768);
  StartPaletteAnimation(271, 640);
  OmegaGold_Update(p);
}

bool8 FUN_0805b41c(Omega1* p);
bool8 FUN_0805b45c(Omega1* p);
bool8 FUN_0805b4a4(Omega1* p);
bool8 changeGoldOmega1Mode(Omega1* p);
bool8 nop_0805b5dc(Omega1* p);
bool8 nop_0805b740(Omega1* p);
bool8 nop_0805b7ec(Omega1* p);
static bool8 nop_0805b874(Omega1* _ UNUSED);

void goldOmega1_0805b420(struct Boss* p);
void makeGoldOmega1Mode2(struct Boss* p);
void FUN_0805b4a8(struct Boss* p);
void goldOmega1Neutral(struct Boss* p);
void goldOmega1Laser(struct Boss* p);
void FUN_0805b744(struct Boss* p);
void FUN_0805b7f0(struct Boss* p);
static void FUN_0805b878(Omega1* p);

static void OmegaGold_Update(Omega1* p) {
  // clang-format off
  static bool8 (*const sUpdates1[8])(Omega1*) = {
      FUN_0805b41c,
      FUN_0805b45c,
      FUN_0805b4a4,
      changeGoldOmega1Mode,
      nop_0805b5dc,
      nop_0805b740,
      nop_0805b7ec,
      nop_0805b874,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[8])(Omega1*) = {
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

  if (((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) {
    if (!(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
      SET_BOSS_ROUTINE(p, ENTITY_DIE);
      OmegaGold_Die(p);
      return;
    }
  }
  if (p->mode[1] > 1 && p->mode[1] != 6) StepPaletteAnimation(102);
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

void FUN_0805b270(Omega1* p);
void FUN_0805b358(Omega1* p);

static void OmegaGold_Die(Omega1* p) {
  static void (*const sDeads[2])(Omega1*) = {
      FUN_0805b270,
      FUN_0805b358,
  };
  (sDeads[p->mode[1]])(p);
}

static void OmegaGold_Disappear(Omega1* p) {
  RemovePaletteAnimation(11);
  RemovePaletteAnimation(102);
  RemovePaletteAnimation(103);
  RemovePaletteAnimation(271);
  DeleteBoss((void*)p);
}

INCASM("asm/boss/omega1g.inc");

// --------------------------------------------

static bool8 nop_0805b874(Omega1* _) { return TRUE; }

static void FUN_0805b878(Omega1* p) {
  switch (p->mode[2]) {
    case 0: {
      (p->d).x = 0, (p->d).y = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->d).y += (PIXEL(1) / 4);
      if ((p->d).y > (PIXEL(1) / 4)) (p->d).y = (PIXEL(1) / 4);
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
static void Omega1g_OnCollision(struct Body* body, Coords32* c1, Coords32* c2) {
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
    Omega1* p = (Omega1*)body->parent;
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
static void floatGoldOmega1(Omega1* p) {
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
