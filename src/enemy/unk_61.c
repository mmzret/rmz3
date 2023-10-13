#include "collision.h"
#include "enemy.h"
#include "global.h"

void Enemy61_Init(struct Enemy* p);
void Enemy61_Update(struct Enemy* p);
void Enemy61_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy61Routine = {
    [ENTITY_INIT] =      Enemy61_Init,
    [ENTITY_UPDATE] =    Enemy61_Update,
    [ENTITY_DIE] =       Enemy61_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_08093754(struct Enemy* p);

static const EnemyFunc sUpdates1[1] = {
    FUN_08093754,
};

void FUN_08093758(struct Enemy* p);

static const EnemyFunc sUpdates2[1] = {
    FUN_08093758,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
};

static const s8 s8_ARRAY_08369de8[24] = {
    -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, -3, -3,
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
