#include "enemy.h"
#include "global.h"

// 旧居住区の燃やしてショートカットできる木

metatile_attr_t FUN_0800e284(s32 x, s32 y);

static void BurnableWood_Init(struct Enemy* p);
static void BurnableWood_Update(struct Enemy* p);
static void BurnableWood_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gBurnableWoodRoutine = {
    [ENTITY_INIT] =      BurnableWood_Init,
    [ENTITY_UPDATE] =    BurnableWood_Update,
    [ENTITY_DIE] =       BurnableWood_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static void BurnableWood_Init(struct Enemy* p) {
  static const struct Rect sSize = {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)};

  (p->s).d.x = (p->s).d.y = PIXEL(0);
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8) + 1;
  if (FUN_0800e284((p->s).coord.x, (p->s).coord.y)) {
    (p->s).flags2 |= ENTITY_HAZARD;
    (p->s).size = &sSize;
    (p->s).hazardAttr = METATILE_GROUND;
  }
  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  BurnableWood_Update(p);
}

static void BurnableWood_Update(struct Enemy* p) {
  if (FUN_0800e284((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).flags2 &= ~ENTITY_HAZARD;
    SET_ZAKO_ROUTINE(p, ENTITY_DIE);
  }
}

static void BurnableWood_Die(struct Enemy* p) {
  SET_ZAKO_ROUTINE(p, ENTITY_EXIT);
  return;
}
