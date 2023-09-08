#include "boss.h"
#include "collision.h"
#include "global.h"

static const struct Collision sCollisions[29];

void Hellbat_Init(struct Boss* p);
void Hellbat_Update(struct Boss* p);
void Hellbat_Die(struct Boss* p);

// clang-format off
const BossRoutine gHellbatRoutine = {
    [ENTITY_INIT] =      Hellbat_Init,
    [ENTITY_MAIN] =      Hellbat_Update,
    [ENTITY_DIE] =       Hellbat_Die,
    [ENTITY_DISAPPEAR] = deleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Boss* CreateHellbat(struct Coord* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;

    INIT_BOSS_ROUTINE(p, BOSS_HELLBAT);

    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/boss/hellbat.inc");

void FUN_0804b520(struct Boss* p);
void FUN_0804b56c(struct Boss* p);
void FUN_0804b5e8(struct Boss* p);
void FUN_0804b6b4(struct Boss* p);
void FUN_0804b900(struct Boss* p);
void FUN_0804ba40(struct Boss* p);
void FUN_0804bcf4(struct Boss* p);
void FUN_0804bee0(struct Boss* p);
void FUN_0804c220(struct Boss* p);
void FUN_0804c554(struct Boss* p);
void nop_0804c9ec(struct Boss* p);
void FUN_0804caa0(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[12] = {
    FUN_0804b520,
    FUN_0804b56c,
    FUN_0804b5e8,
    FUN_0804b6b4,
    FUN_0804b900,
    FUN_0804ba40,
    FUN_0804bcf4,
    FUN_0804bee0,
    FUN_0804c220,
    FUN_0804c554,
    nop_0804c9ec,
    FUN_0804caa0,
};
// clang-format on

void hellbatMode0(struct Boss* p);
void hellbatMode1(struct Boss* p);
void hellbatMode2(struct Boss* p);
void hellbatNeutral(struct Boss* p);
void hellbatMode4(struct Boss* p);
void hellbatDisappear(struct Boss* p);
void hellbatBatShower(struct Boss* p);
void hellbatEchoWave(struct Boss* p);
void hellbatThunderRevorb(struct Boss* p);
void hellbatEX(struct Boss* p);
void hellbatDamage(struct Boss* p);
void hellbatKnockBackDamage(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[12] = {
    hellbatMode0,
    hellbatMode1,
    hellbatMode2,
    hellbatNeutral,
    hellbatMode4,
    hellbatDisappear,
    hellbatBatShower,
    hellbatEchoWave,
    hellbatThunderRevorb,
    hellbatEX,
    hellbatDamage,
    hellbatKnockBackDamage,
};
// clang-format on

void hellbatDeath0(struct Boss* p);
void hellbatDeath1(struct Boss* p);

static const BossFunc sDeads[2] = {
    hellbatDeath0,
    hellbatDeath1,
};

static const struct Collision sCollisions[29] = {
    [0] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
    },
    [1] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [2] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [3] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [4] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [5] = {
      kind : DRP2,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : METAL,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(20), -PIXEL(21), PIXEL(11), PIXEL(42)},
    },

    // --------------------------------------------

    [6] = {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 6,
      unk_0c : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
    },
    [7] = {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
    },
    [8] = {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [9] = {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [10] = {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 6,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [11] = {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 6,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [12] = {
      kind : DRP2,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : METAL,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(20), -PIXEL(21), PIXEL(11), PIXEL(42)},
    },

    // --------------------------------------------

    [13] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 7,
      unk_0c : 0x00000001,
      range : {0x1C00, -0x2E00, 0x1700, 0x2A00},
    },
    [14] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 6,
      unk_0c : 0x00000001,
      range : {0x1C00, -0x2E00, 0x1700, 0x2A00},
    },
    [15] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000001,
      range : {-0x1400, -0x2E00, 0x1200, 0x2A00},
    },
    [16] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000001,
      range : {-0x1400, -0x2E00, 0x1200, 0x2A00},
    },
    [17] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {0x0300, -0x3D00, 0x1B00, 0x2600},
    },
    [18] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x0300, -0x3D00, 0x1B00, 0x2600},
    },
    [19] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [20] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
    [21] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [22] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [23] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [24] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [25] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [26] = {
      kind : DDP,
      layer : 1,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
    [27] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [28] = {
      kind : DRP,
      layer : 1,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
};

static const struct Coord sCoords[3] = {
    {0x00000000, -0x00002000},
    {0x00000000, -0x00002000},
    {0x00000000, -0x00002000},
};
