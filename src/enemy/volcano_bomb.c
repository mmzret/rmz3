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
    [ENTITY_UPDATE] =    VolcanoBomb_Update,
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
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      hardness : 8,
      remaining : 0,
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
