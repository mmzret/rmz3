#include "collision.h"
#include "enemy.h"
#include "global.h"

void nop_0809a1ec(struct Enemy* p);

void LeviathanMinigameEnemy_Init(struct Enemy* p);

static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];
static const EnemyFunc sDeads[4];
static const struct Collision sCollisions[6];
static const u8 u8_ARRAY_0836a764[6];
static const u8 u8_ARRAY_0836a76a[8];
static const motion_t sMotions[12];

INCASM("asm/enemy/minigame_leviathan_a.inc");

void nop_0809a0b4(struct Enemy* p) {}

static const struct Collision sCollisions[6];
static const u8 u8_ARRAY_0836a764[6];
static const u8 u8_ARRAY_0836a76a[8];
static const motion_t sMotions[12];
static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];

void LeviathanMinigameEnemy_Die(struct Enemy* p);
void LeviathanMinigameEnemy_Update(struct Enemy* p);

bool8 FUN_0809a0b8(struct Enemy* p) {
  if ((p->body).status & 0x200) {
    *(u8*)((u8*)(p->s).unk_28 + 0x31) = 10;
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = u8_ARRAY_0836a764[(p->s).work[0]];
    LeviathanMinigameEnemy_Die(p);
    return TRUE;
  }
  return FALSE;
}

void LeviathanMinigameEnemy_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = u8_ARRAY_0836a76a[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  if ((p->s).work[0] != 6) {
    SetSpriteAnimation(p, sMotions[(p->s).work[0]]);
  }
  UpdateSpriteAnimation(p);
  INIT_BODY(p, sCollisions, 1, (void*)nop_0809a0b4);
  LeviathanMinigameEnemy_Update(p);
}

void LeviathanMinigameEnemy_Update(struct Enemy* p) {
  if (!FUN_0809a0b8(p)) {
    sUpdates1[(p->s).mode[1]](p);
    sUpdates2[(p->s).mode[1]](p);
  }
}

void LeviathanMinigameEnemy_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])((void*)p);
}

void nop_0809a1ec(struct Enemy* p) {}

INCASM("asm/enemy/minigame_leviathan_b.inc");

void LeviathanMinigameEnemy_Init(struct Enemy* p);
void LeviathanMinigameEnemy_Update(struct Enemy* p);
void LeviathanMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gLeviathanMinigameEnemyRoutine = {
    [ENTITY_INIT] =      (void*)LeviathanMinigameEnemy_Init,
    [ENTITY_UPDATE] =    (void*)LeviathanMinigameEnemy_Update,
    [ENTITY_DIE] =       (void*)LeviathanMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0809a1ec(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
};
// clang-format on

void FUN_0809a1f0(struct Enemy* p);
void FUN_0809a31c(struct Enemy* p);
void FUN_0809a4bc(struct Enemy* p);
void FUN_0809a5e0(struct Enemy* p);
void FUN_0809a700(struct Enemy* p);
void FUN_0809a90c(struct Enemy* p);
void FUN_0809ab28(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0809a1f0,
    FUN_0809a31c,
    FUN_0809a4bc,
    FUN_0809a5e0,
    FUN_0809a700,
    FUN_0809a90c,
    FUN_0809ab28,
};
// clang-format on

// --------------------------------------------

void FUN_0809ac28(struct Enemy* p);
void FUN_0809acdc(struct Enemy* p);
void FUN_0809ad8c(struct Enemy* p);
void FUN_0809ae68(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_0809ac28,
    FUN_0809acdc,
    FUN_0809ad8c,
    FUN_0809ae68,
};

// --------------------------------------------

// 0x0836a6d4
static const struct Collision sCollisions[6] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(6), PIXEL(1), PIXEL(20), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(4), PIXEL(1), PIXEL(33), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(11), PIXEL(11)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(2), PIXEL(18), PIXEL(16)},
    },
};

static const u8 u8_ARRAY_0836a764[6] = {
    0, 1, 2, 2, 3, 3,
};

static const u8 u8_ARRAY_0836a76a[8] = {
    0, 1, 2, 3, 4, 5, 6, 0,
};

// clang-format off
// 0x0836a772
static const motion_t sMotions[12] = {
    MOTION(SM024_SHARKSEAL_X, 0),
    MOTION(SM053_SHELLUNO, 1),
    MOTION(SM240_SEA_BREAM, 0),
    MOTION(SM239_ANGEL_FISH, 0),
    MOTION(SM241_CRAB, 1),
    MOTION(SM242_FISH_SCHOOL, 0),
    MOTION(SM024_SHARKSEAL_X, 4),
    MOTION(SM024_SHARKSEAL_X, 5),
    MOTION(SM024_SHARKSEAL_X, 5),
    MOTION(SM053_SHELLUNO, 6),
    MOTION(SM053_SHELLUNO, 7),
    MOTION(SM053_SHELLUNO, 8),
};
// clang-format on
