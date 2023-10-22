#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/glacierle_arm.inc");

void GlacierleAtkArm_Init(struct Enemy* p);
void GlacierleAtkArm_Update(struct Enemy* p);
void GlacierleAtkArm_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGlacierleAtkArmRoutine = {
    [ENTITY_INIT] =      GlacierleAtkArm_Init,
    [ENTITY_UPDATE] =    GlacierleAtkArm_Update,
    [ENTITY_DIE] =       GlacierleAtkArm_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_08082a1c(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    nop_08082a1c,
    nop_08082a1c,
    nop_08082a1c,
};

void FUN_08082a20(struct Enemy* p);
void FUN_08082aa0(struct Enemy* p);
void FUN_08082af8(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    FUN_08082a20,
    FUN_08082aa0,
    FUN_08082af8,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
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
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(12), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
};

static const u8 sInitModes[3] = {0, 1, 2};
