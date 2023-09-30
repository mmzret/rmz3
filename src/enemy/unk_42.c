#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/unk_42.inc");

void Enemy42_Init(struct Enemy* p);
void Enemy42_Update(struct Enemy* p);
void Enemy42_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy42Routine = {
    [ENTITY_INIT] =      Enemy42_Init,
    [ENTITY_MAIN] =      Enemy42_Update,
    [ENTITY_DIE] =       Enemy42_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_08084e7c(struct Enemy* p);
void FUN_08084f18(struct Enemy* p);
void FUN_08084fb4(struct Enemy* p);

static const EnemyFunc sInitializers[3] = {
    FUN_08084e7c,
    FUN_08084f18,
    FUN_08084fb4,
};

void FUN_08085060(struct Enemy* p);
void FUN_08085124(struct Enemy* p);
void FUN_080852f4(struct Enemy* p);

static const EnemyFunc sUpdates[3] = {
    FUN_08085060,
    FUN_08085124,
    FUN_080852f4,
};

void FUN_0808534c(struct Enemy* p);
void FUN_0808537c(struct Enemy* p);
void FUN_08085578(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_0808534c,
    FUN_0808537c,
    FUN_08085578,
};

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 4,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(4), -PIXEL(30), PIXEL(8), PIXEL(60)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 4,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(4), -PIXEL(30), PIXEL(8), PIXEL(60)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 4,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(8), -PIXEL(29), PIXEL(16), PIXEL(62)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 4,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(8), -PIXEL(29), PIXEL(16), PIXEL(62)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 4,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(11), -PIXEL(28), PIXEL(22), PIXEL(64)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 4,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(11), -PIXEL(28), PIXEL(22), PIXEL(64)},
    },
};
