#include "collision.h"
#include "enemy.h"
#include "global.h"

void CielMinigameEnemy_Init(struct Enemy* p);
void CielMinigameEnemy_Update(struct Enemy* p);
void CielMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCielMinigameEnemy1Routine = {
    [ENTITY_INIT] =      CielMinigameEnemy_Init,
    [ENTITY_UPDATE] =    CielMinigameEnemy_Update,
    [ENTITY_DIE] =       CielMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// clang-format off
static const u8 u8_ARRAY_ARRAY_0836a85c[5][6] = {
    {0x00, 0x04, 0x08, 0xFF, 0x00, 0x00},
    {0x00, 0x02, 0x04, 0x06, 0x08, 0xFF},
    {0x01, 0x02, 0x05, 0x06, 0x09, 0xFF},
    {0x01, 0x03, 0x05, 0x07, 0x09, 0xFF},
    {0x03, 0x07, 0xFF, 0x00, 0x00, 0x00},
};
// clang-format on

// clang-format off
static const u8 u8_ARRAY_ARRAY_0836a87a[5][5] = {
    {1, 1, 1, 0, 0},
    {2, 1, 2, 1, 2},
    {1, 2, 1, 2, 1},
    {2, 1, 2, 1, 2},
    {2, 2, 0, 0, 0},
};
// clang-format on
