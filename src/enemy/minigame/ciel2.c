#include "collision.h"
#include "enemy.h"
#include "global.h"

void CielMinigameEnemy2_Init(struct Enemy* p);
void CielMinigameEnemy2_Update(struct Enemy* p);
void CielMinigameEnemy2_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCielMinigameEnemy2Routine = {
    [ENTITY_INIT] =      CielMinigameEnemy2_Init,
    [ENTITY_UPDATE] =    CielMinigameEnemy2_Update,
    [ENTITY_DIE] =       CielMinigameEnemy2_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on
