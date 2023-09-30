#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/capsule_cannon.inc");

void CapsuleCannon_Init(struct Enemy* p);
void CapsuleCannon_Update(struct Enemy* p);
void CapsuleCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCapsuleCannonRoutine = {
    [ENTITY_INIT] =      CapsuleCannon_Init,
    [ENTITY_MAIN] =      CapsuleCannon_Update,
    [ENTITY_DIE] =       CapsuleCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_08085a08(struct Enemy* p);
void FUN_08085a10(struct Enemy* p);
void FUN_08085a9c(struct Enemy* p);
void FUN_08085c14(struct Enemy* p);
void FUN_08085c2c(struct Enemy* p);
void FUN_08085c34(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_08085a08,
    FUN_08085a10,
    FUN_08085a9c,
    FUN_08085c14,
    FUN_08085c2c,
    FUN_08085c34,
};
// clang-format on

void nop_08085a0c(struct Enemy* p);
void FUN_08085a14(struct Enemy* p);
void FUN_08085aa0(struct Enemy* p);
void FUN_08085c18(struct Enemy* p);
void FUN_08085c30(struct Enemy* p);
void FUN_08085c38(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    nop_08085a0c,
    FUN_08085a14,
    FUN_08085aa0,
    FUN_08085c18,
    FUN_08085c30,
    FUN_08085c38,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 1,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
};

static const struct Coord sElementCoord = {-PIXEL(8), PIXEL(0)};