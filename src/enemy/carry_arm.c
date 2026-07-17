#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/carry_arm_a.inc");

void nop_08071568(struct Enemy* p) {}

void CarryArm_Die(struct Enemy* p);

static bool8 FUN_0807156c(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = (p->s).work[0];
    CarryArm_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/enemy/carry_arm_b.inc");

extern const EnemyFunc PTR_ARRAY_08366b48[6];
extern const EnemyFunc PTR_ARRAY_08366b60[6];
extern const EnemyFunc PTR_ARRAY_08366b78[2];

void CarryArm_Update(struct Enemy* p) {
  if (!FUN_0807156c(p)) {
    (PTR_ARRAY_08366b48[(p->s).mode[1]])(p);
    (PTR_ARRAY_08366b60[(p->s).mode[1]])(p);
  }
}

void CarryArm_Die(struct Enemy* p) {
  (PTR_ARRAY_08366b78[(p->s).mode[1]])(p);
}

void FUN_080716a8(struct Enemy* p) {}

INCASM("asm/enemy/carry_arm_c.inc");

void FUN_08071c70(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void CarryArm_Init(struct Enemy* p);
void CarryArm_Update(struct Enemy* p);
void CarryArm_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCarryArmRoutine = {
    [ENTITY_INIT] =      CarryArm_Init,
    [ENTITY_UPDATE] =    CarryArm_Update,
    [ENTITY_DIE] =       CarryArm_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080716a8(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366b48[6] = {
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
};
// clang-format on

void FUN_080716ac(struct Enemy* p);
void FUN_08071778(struct Enemy* p);
void FUN_08071888(struct Enemy* p);
void FUN_08071964(struct Enemy* p);
void FUN_08071a28(struct Enemy* p);
void FUN_08071b88(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366b60[6] = {
    FUN_080716ac,
    FUN_08071778,
    FUN_08071888,
    FUN_08071964,
    FUN_08071a28,
    FUN_08071b88,
};
// clang-format on

void FUN_08071bf0(struct Enemy* p);
void FUN_08071c70(struct Enemy* p);

const EnemyFunc PTR_ARRAY_08366b78[2] = {
    FUN_08071bf0,
    FUN_08071c70,
};

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
};

const u8 u8_ARRAY_08366bb0[2] = {0, 3};

static const motion_t sMotions[4] = {
    MOTION(SM034_CARRYARM, 0x02),
    MOTION(SM034_CARRYARM, 0x03),
    MOTION(SM034_CARRYARM, 0x04),
    MOTION(SM034_CARRYARM, 0x05),
};
