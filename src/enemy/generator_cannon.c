#include "collision.h"
#include "enemy.h"
#include "global.h"

void GeneratorCannon_Init(struct Enemy* p);
void GeneratorCannon_Update(struct Enemy* p);
void GeneratorCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGeneratorCannonRoutine = {
    [ENTITY_INIT] =      GeneratorCannon_Init,
    [ENTITY_UPDATE] =    GeneratorCannon_Update,
    [ENTITY_DIE] =       GeneratorCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x08368f08 0x0836a90c data/zako.bin
INCBIN("data/zako.bin");
