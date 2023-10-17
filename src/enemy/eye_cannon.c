#include "collision.h"
#include "enemy.h"
#include "global.h"

void EyeCannon_Init(struct Enemy* p);
void EyeCannon_Update(struct Enemy* p);
void EyeCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEyeCannonRoutine = {
    [ENTITY_INIT] =      EyeCannon_Init,
    [ENTITY_UPDATE] =    EyeCannon_Update,
    [ENTITY_DIE] =       EyeCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  // NOP
  return;
}

static bool8 FUN_08084708(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ZAKO_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = 0;
    EyeCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/enemy/eye_cannon.inc");

void FUN_08084934(struct Enemy* p);
void FUN_08084930(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_08084934,
    FUN_08084930,
    FUN_08084930,
    FUN_08084930,
    FUN_08084930,
    FUN_08084930,
};
// clang-format on

void FUN_08084974(struct Enemy* p);
void FUN_080849b0(struct Enemy* p);
void FUN_08084a80(struct Enemy* p);
void FUN_08084b2c(struct Enemy* p);
void FUN_08084c30(struct Enemy* p);
void FUN_08084cbc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_08084974,
    FUN_080849b0,
    FUN_08084a80,
    FUN_08084b2c,
    FUN_08084c30,
    FUN_08084cbc,
};
// clang-format on

void _killEyeCannon(struct Enemy* p);

static const EnemyFunc sDeads[1] = {
    _killEyeCannon,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(18), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(18), PIXEL(20), PIXEL(20)},
    },
};

static const u32 u32_ARRAY_08368358[4] = {
    45,
    46,
    47,
    48,
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(18)};

static const u8 u8_ARRAY_08368370[4] = {
    249,
    135,
    224,
    160,
};

static const motion_t sMotions[3] = {
    MOTION(102, 5),
    MOTION(102, 6),
    MOTION(102, 7),
};
