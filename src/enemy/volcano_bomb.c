#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/volcano_bomb.inc");

void VolcanoBomb_Init(struct Enemy* p);
void VolcanoBomb_Update(struct Enemy* p);
void VolcanoBomb_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gVolcanoBombRoutine = {
    [ENTITY_INIT] =      VolcanoBomb_Init,
    [ENTITY_MAIN] =      VolcanoBomb_Update,
    [ENTITY_DIE] =       VolcanoBomb_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080713e8(struct Enemy* p);

const EnemyFunc PTR_ARRAY_08366ad8[1] = {
    FUN_080713e8,
};

void FUN_080713ec(struct Enemy* p);

const EnemyFunc PTR_ARRAY_08366adc[1] = {
    FUN_080713ec,
};

static const struct Collision sCollisions[] = {
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
      hitzone : 3,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
};

static const u8 u8_ARRAY_08366b28[2] = {0, 0};

static const motion_t sMotions[4] = {
    MOTION(SM031_VOLCANO_BOMB, 0x01),
    MOTION(SM031_VOLCANO_BOMB, 0x02),
    MOTION(SM031_VOLCANO_BOMB, 0x03),
    MOTION(SM031_VOLCANO_BOMB, 0x04),
};
