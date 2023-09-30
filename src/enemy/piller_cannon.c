#include "collision.h"
#include "vfx.h"
#include "global.h"
#include "enemy.h"

static const struct Collision sCollisions[14];
static const motion_t sMotions[7];

void PillerCannon_Init(struct Enemy* p);
void PillerCannon_Update(struct Enemy* p);
void PillerCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPillerCannonRoutine = {
    [ENTITY_INIT] =      PillerCannon_Init,
    [ENTITY_MAIN] =      PillerCannon_Update,
    [ENTITY_DIE] =       PillerCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreatePillerCannon(struct Coord* c, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ZAKO_PILLER_CANNON);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/enemy/piller_cannon.inc");

void FUN_0806860c(struct Enemy* p);
void FUN_08068614(struct Enemy* p);
void FUN_080686b0(struct Enemy* p);
void FUN_08068780(struct Enemy* p);
void FUN_08068ad8(struct Enemy* p);
void FUN_08068c84(struct Enemy* p);
void FUN_08068e60(struct Enemy* p);
void FUN_08068eb0(struct Enemy* p);
void FUN_08068eb8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[9] = {
    FUN_0806860c,
    FUN_08068614,
    FUN_080686b0,
    FUN_08068780,
    FUN_08068ad8,
    FUN_08068c84,
    FUN_08068e60,
    FUN_08068eb0,
    FUN_08068eb8,
};
// clang-format on

void FUN_08068610(struct Enemy* p);
void FUN_08068618(struct Enemy* p);
void FUN_080686b4(struct Enemy* p);
void FUN_08068784(struct Enemy* p);
void FUN_08068adc(struct Enemy* p);
void FUN_08068c88(struct Enemy* p);
void FUN_08068e64(struct Enemy* p);
void FUN_08068eb4(struct Enemy* p);
void FUN_08068ebc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[9] = {
    FUN_08068610,
    FUN_08068618,
    FUN_080686b4,
    FUN_08068784,
    FUN_08068adc,
    FUN_08068c88,
    FUN_08068e64,
    FUN_08068eb4,
    FUN_08068ebc,
};
// clang-format on

static const struct Collision sCollisions[14] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1C00, 0x1C00},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1A00},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1C00, 0x1C00},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x1300, 0x0000, 0x1200, 0x1400},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-0x1300, 0x0000, 0x1200, 0x1400},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x0F00, 0x0000, 0x2100, 0x1400},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-0x0F00, 0x0000, 0x2100, 0x1400},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x0700, 0x0000, 0x2400, 0x1400},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-0x0700, 0x0000, 0x2400, 0x1400},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x1400},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x2000, 0x1400},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x0C00, 0x0000, 0x1D00, 0x2000},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0xFFFFFFFF,
      range : {-0x0C00, 0x0000, 0x1D00, 0x2000},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1400, 0x0000, 0x0D00, 0x1000},
    },
};

const struct Coord Coord_083661ec = {0xFFFFF500, 0x0};

// clang-format off
static const motion_t sMotions[7] = {
    MOTION(SM008_PILLAR_CANNON, 0x01),
    MOTION(SM008_PILLAR_CANNON, 0x02),
    MOTION(SM008_PILLAR_CANNON, 0x03),
    MOTION(SM008_PILLAR_CANNON, 0x04),
    MOTION(SM008_PILLAR_CANNON, 0x03),
    MOTION(SM008_PILLAR_CANNON, 0x02),
    MOTION(SM008_PILLAR_CANNON, 0x01),
};
// clang-format on

static const s32 s32_ARRAY_08366204[7] = {
    3, 5, 7, 9, 7, 5, 3,
};
