#include "collision.h"
#include "enemy.h"
#include "global.h"

void HeavyCannon_Init(struct Enemy* p);
void HeavyCannon_Update(struct Enemy* p);
void HeavyCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHeavyCannonBallRoutine = {
    [ENTITY_INIT] =      HeavyCannon_Init,
    [ENTITY_MAIN] =      HeavyCannon_Update,
    [ENTITY_DIE] =       HeavyCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x08367774 0x0836a90c data/zako.bin
INCBIN("data/zako.bin");
