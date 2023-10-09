#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/shelluno.inc");

void Shelluno_Init(struct Enemy* p);
void Shelluno_Update(struct Enemy* p);
void Shelluno_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShellunoRoutine = {
    [ENTITY_INIT] =      Shelluno_Init,
    [ENTITY_UPDATE] =    Shelluno_Update,
    [ENTITY_DIE] =       Shelluno_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0807939c(struct Enemy* p);
void FUN_080795b8(struct Enemy* p);
void FUN_0807a018(struct Enemy* p);
void FUN_0807a064(struct Enemy* p);
void FUN_0807a06c(struct Enemy* p);
void FUN_0807a0fc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    nop_0807939c,
    FUN_080795b8,
    FUN_0807a018,
    FUN_0807a064,
    FUN_0807a06c,
    FUN_0807a0fc,
};
// clang-format on

void shelluno_080793a0(struct Enemy* p);
void FUN_080795f0(struct Enemy* p);
void FUN_0807a01c(struct Enemy* p);
void FUN_0807a068(struct Enemy* p);
void shelluno_0807a070(struct Enemy* p);
void shelluno_0807a100(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    shelluno_080793a0,
    FUN_080795f0,
    FUN_0807a01c,
    FUN_0807a068,
    shelluno_0807a070,
    shelluno_0807a100,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[6] = {
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
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
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
      hardness : 1,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
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
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
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
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_UNK2,
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
      range : {PIXEL(0), -PIXEL(10), PIXEL(18), PIXEL(25)},
    },
    {
      kind : DRP,
      faction : FACTION_UNK2,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(10), PIXEL(18), PIXEL(25)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(9)};
