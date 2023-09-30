#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

static const EnemyFunc sUpdates[13];
static const EnemyFunc sDeads[3];
static const struct Collision sCollisions[3];
static const struct SlashedEnemy sSlashedEnemies[4];

INCASM("asm/enemy/pantheon_hunter.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

void PantheonHunter_Init(struct Enemy* p);
void PantheonHunter_Update(struct Enemy* p);
void PantheonHunter_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonHunterRoutine = {
    [ENTITY_INIT] =      PantheonHunter_Init,
    [ENTITY_MAIN] =      PantheonHunter_Update,
    [ENTITY_DIE] =       PantheonHunter_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08064c38(struct Enemy* p);
void nop_08064ca8(struct Enemy* p);
void phunter_08064cac(struct Enemy* p);
void FUN_08064e0c(struct Enemy* p);
void nop_08064e34(struct Enemy* p);
void FUN_08064e38(struct Enemy* p);
void FUN_08064e7c(struct Enemy* p);
void phunterRaiseArm(struct Enemy* p);
void phunterShotBuster(struct Enemy* p);
void FUN_08065104(struct Enemy* p);
void phunter_080651c0(struct Enemy* p);
void phunter_08065218(struct Enemy* p);
void phunter_080652e8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates[13] = {
    FUN_08064c38,
    nop_08064ca8,
    phunter_08064cac,
    FUN_08064e0c,
    nop_08064e34,
    FUN_08064e38,
    FUN_08064e7c,
    phunterRaiseArm,
    phunterShotBuster,
    FUN_08065104,
    phunter_080651c0,
    phunter_08065218,
    phunter_080652e8,
};
// clang-format on

// --------------------------------------------

void explodePHunter(struct Enemy* p);
void slashPHunter(struct Enemy* p);
void FUN_080656cc(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    explodePHunter,
    slashPHunter,
    FUN_080656cc,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    [0] = {
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
      range : {-0x0200, -0x1000, 0x1200, 0x1000},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0200, -0x1200, 0x1400, 0x2200},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_UNK2,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
};

static const struct SlashedEnemy sSlashedEnemies[4] = {
    [0] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x06),
      unk_02 : {0xFF, 0x11},
      c : {0, 0},
      d : {0x80, 0xFB00},
      unk_0c : {0xFF, 0x1FF},
      unk_10 : {0, 0x40},
      unk_14 : {0x200, 0x200},
    },
    [1] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x07),
      unk_02 : {0xFE, 0x11},
      c : {0, 0},
      d : {0x80, 0xFE00},
      unk_0c : {0x7F, 0x7F},
      unk_10 : {0, 0x40},
      unk_14 : {0x200, 0x200},
    },
    [2] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x08),
      unk_02 : {0xFE, 0x11},
      c : {0, 0},
      d : {0x100, 0xFD00},
      unk_0c : {0x1FF, 0x1FF},
      unk_10 : {0, 0x40},
      unk_14 : {0x200, 0x200},
    },
    [3] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x05),
      unk_02 : {0xFF, 0x4},
      c : {0, 0},
      d : {0, 0},
      unk_0c : {0, 0},
      unk_10 : {0, 0x40},
      unk_14 : {0x800, 0x200},
    },
};

const struct Coord Coord_08365c84 = {0, -0x1000};
const struct Coord Coord_08365c8c = {0xFFFFF780, 0x880};
