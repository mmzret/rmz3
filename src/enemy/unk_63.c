#include "collision.h"
#include "enemy.h"
#include "global.h"

void Enemy63_Init(struct Enemy* p);
void Enemy63_Update(struct Enemy* p);
void Enemy63_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy63Routine = {
    [ENTITY_INIT] =      Enemy63_Init,
    [ENTITY_UPDATE] =    Enemy63_Update,
    [ENTITY_DIE] =       Enemy63_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x08369edc 0x0836a90c data/zako.bin
INCBIN("data/zako.bin");
