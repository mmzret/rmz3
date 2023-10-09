#include "collision.h"
#include "enemy.h"
#include "global.h"

void OmegaZeroRock_Init(struct Enemy* p);
void OmegaZeroRock_Update(struct Enemy* p);
void OmegaZeroRock_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gOmegaZeroRockRoutine = {
    [ENTITY_INIT] =      OmegaZeroRock_Init,
    [ENTITY_UPDATE] =    OmegaZeroRock_Update,
    [ENTITY_DIE] =       OmegaZeroRock_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_0808b704(struct Enemy* p);

static const EnemyFunc sUpdates1[1] = {
    nop_0808b704,
};

void FUN_0808b708(struct Enemy* p);

static const EnemyFunc sUpdates2[1] = {
    FUN_0808b708,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
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
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
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
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(SM237_ROCK, 1),
    MOTION(SM237_ROCK, 2),
    MOTION(SM237_ROCK, 3),
};
