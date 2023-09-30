#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/enemy.inc");

void Mothjiro_Init(struct Enemy* p);
void Mothjiro_Update(struct Enemy* p);
void Mothjiro_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMothjiroRoutine = {
    [ENTITY_INIT] =      Mothjiro_Init,
    [ENTITY_MAIN] =      Mothjiro_Update,
    [ENTITY_DIE] =       Mothjiro_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x08368778 0x0836a90c data/zako.bin
INCBIN("data/zako.bin");
