#include "enemy.h"
#include "global.h"

// 旧居住区の燃やしてショートカットできる木

INCASM("asm/enemy/burnable_wood.inc");

void BurnableWood_Init(struct Enemy* p);
void BurnableWood_Update(struct Enemy* p);
void BurnableWood_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gBurnableWoodRoutine = {
    [ENTITY_INIT] =      BurnableWood_Init,
    [ENTITY_UPDATE] =    BurnableWood_Update,
    [ENTITY_DIE] =       BurnableWood_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static const struct Rect sSize = {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)};
