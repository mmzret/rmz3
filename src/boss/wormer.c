#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[15];
static const u8 sInitModes[4];

void Wormer_Init(struct Boss* p);
void Wormer_Update(struct Boss* p);
void Wormer_Die(struct Boss* p);

// clang-format off
const BossRoutine gWormerRoutine = {
    [ENTITY_INIT] =      Wormer_Init,
    [ENTITY_UPDATE] =    Wormer_Update,
    [ENTITY_DIE] =       Wormer_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

void nop_080423e0(struct Body* _ UNUSED) { return; }

bool8 tryKillOrWormer(struct Boss* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    Wormer_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/boss/wormer.inc");

// --------------------------------------------

void nop_08042890(struct Boss* p);
void FUN_08042894(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[11] = {
    nop_08042890,
    nop_08042890,
    nop_08042890,
    FUN_08042894,
    FUN_08042894,
    FUN_08042894,
    FUN_08042894,
    nop_08042890,
    nop_08042890,
    FUN_08042894,
    FUN_08042894,
};
// clang-format on

// --------------------------------------------

void FUN_080428c4(struct Boss* p);
void FUN_08042914(struct Boss* p);
void FUN_08042984(struct Boss* p);
void FUN_08042b48(struct Boss* p);
void FUN_08042c74(struct Boss* p);
void FUN_08042d4c(struct Boss* p);
void FUN_08042da4(struct Boss* p);
void FUN_08042e54(struct Boss* p);
void FUN_08042f9c(struct Boss* p);
void FUN_08042ff8(struct Boss* p);
void FUN_08043204(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[11] = {
    FUN_080428c4,
    FUN_08042914,
    FUN_08042984,
    FUN_08042b48,
    FUN_08042c74,
    FUN_08042d4c,
    FUN_08042da4,
    FUN_08042e54,
    FUN_08042f9c,
    FUN_08042ff8,
    FUN_08043204,
};
// clang-format on

static const struct Collision sCollisions[15] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1B00, 0x1B00, 0x5800},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x05,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x4000, 0x2800, 0x1300},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1C00, 0x1B00, 0x3A00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x05,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0600, -0x3500, 0x2800, 0x1300},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x0200, -0x1300, 0x1B00, 0x2E00},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x05,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1B00, 0x1B00, 0x5800},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x4000, 0x2800, 0x1300},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1C00, 0x1B00, 0x3A00},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0600, -0x3500, 0x2800, 0x1300},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x0200, -0x1300, 0x1B00, 0x2E00},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1600, -0x3400, 0x1300, 0x2300},
    },
};

static const u8 sInitModes[4] = {1, 1, 0, 0};

const struct Coord Coord_08362264 = {-0xA00, -0x2000};

const u8 u8_ARRAY_0836226c[10] = {
    1, 1, 1, 1, 3, 3, 5, 5, 5, 5,
};

const struct Coord Coord_ARRAY_08362278[3] = {
    {-0x180, -0x400},
    {-0x280, -0x480},
    {-0x380, -0x500},
};

const u8 u8_ARRAY_08362290[10] = {
    5, 5, 5, 5, 3, 3, 1, 1, 1, 1,
};

const struct Coord16 ALIGNED(2) Coord_ARRAY_0836229a[4] = {
    {0x080, -0x200},
    {0x140, -0x280},
    {0x200, -0x300},
    {0x2C0, -0x380},
};
