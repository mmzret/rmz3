#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/sharkseal_x.inc");

void SharksealX_Init(struct Enemy* p);
void SharksealX_Update(struct Enemy* p);
void SharksealX_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSharksealXRoutine = {
    [ENTITY_INIT] =      SharksealX_Init,
    [ENTITY_UPDATE] =    SharksealX_Update,
    [ENTITY_DIE] =       SharksealX_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080707d0(struct Enemy* p);
void FUN_080707d8(struct Enemy* p);
void FUN_080708dc(struct Enemy* p);
void FUN_08070990(struct Enemy* p);
void FUN_08070c68(struct Enemy* p);
void FUN_08070f3c(struct Enemy* p);
void FUN_08070f8c(struct Enemy* p);
void FUN_08070f94(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08366a04[8] = {
    FUN_080707d0,
    FUN_080707d8,
    FUN_080708dc,
    FUN_08070990,
    FUN_08070c68,
    FUN_08070f3c,
    FUN_08070f8c,
    FUN_08070f94,
};
// clang-format on

void nop_080707d4(struct Enemy* p);
void sharksealxMode1(struct Enemy* p);
void sharksealxMode2(struct Enemy* p);
void sharksealxMode3(struct Enemy* p);
void sharksealxMode4(struct Enemy* p);
void sharksealxMode5(struct Enemy* p);
void nop_08070f90(struct Enemy* p);
void sharksealxMode7(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366a24[8] = {
    nop_080707d4,
    sharksealxMode1,
    sharksealxMode2,
    sharksealxMode3,
    sharksealxMode4,
    sharksealxMode5,
    nop_08070f90,
    sharksealxMode7,
};
// clang-format on

static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(5), PIXEL(0), PIXEL(30), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(5), PIXEL(0), PIXEL(32), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(4), PIXEL(1), PIXEL(18), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(5), PIXEL(1), PIXEL(18), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(5), PIXEL(0), PIXEL(32), PIXEL(11)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};
