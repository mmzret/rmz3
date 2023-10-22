#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[8];

void BeeServer_Init(struct Boss* p);
void BeeServer_Update(struct Boss* p);
void BeeServer_Die(struct Boss* p);

// clang-format off
const BossRoutine gBeeServerRoutine = {
    [ENTITY_INIT] =      BeeServer_Init,
    [ENTITY_UPDATE] =    BeeServer_Update,
    [ENTITY_DIE] =       BeeServer_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

static bool8 tryKillBeeServer(struct Boss* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = 0;
    BeeServer_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/boss/bee_server.inc");

// --------------------------------------------

void FUN_0804d0a4(struct Boss* p);
void nop_0804d0a0(struct Boss* p);

static const BossFunc sUpdates1[4] = {
    FUN_0804d0a4,
    nop_0804d0a0,
    FUN_0804d0a4,
    FUN_0804d0a4,
};

// --------------------------------------------

void FUN_0804d0f8(struct Boss* p);
void FUN_0804d1ac(struct Boss* p);
void FUN_0804d240(struct Boss* p);
void FUN_0804d418(struct Boss* p);

static const BossFunc sUpdates2[4] = {
    FUN_0804d0f8,
    FUN_0804d1ac,
    FUN_0804d240,
    FUN_0804d418,
};

// --------------------------------------------

void FUN_0804d494(struct Boss* p);

static const BossFunc sDeads[1] = {
    FUN_0804d494,
};

// --------------------------------------------

static const struct Collision sCollisions[8] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(84)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(84)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(88)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(94)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      comboLv : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(55), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(35), PIXEL(55), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(7), PIXEL(55), PIXEL(19)},
    },
};

static const u8 sInitModes[4] = {1, 0, 0, 0};

const struct Coord Coord_0836331c = {0, 0};

const u8 u8_ARRAY_ARRAY_08363324[3][5] = {
    {2, 3, 4, 5, 5},
    {4, 3, 3, 2, 2},
    {5, 5, 4, 3, 2},
};
