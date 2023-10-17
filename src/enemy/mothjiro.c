#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/mothjiro.inc");

void Mothjiro_Init(struct Enemy* p);
void Mothjiro_Update(struct Enemy* p);
void Mothjiro_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMothjiroRoutine = {
    [ENTITY_INIT] =      Mothjiro_Init,
    [ENTITY_UPDATE] =    Mothjiro_Update,
    [ENTITY_DIE] =       Mothjiro_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_080881d8(struct Enemy* p);
void nop_080884a0(struct Enemy* p);
void nop_080885f8(struct Enemy* p);
void nop_0808889c(struct Enemy* p);
void nop_08088a1c(struct Enemy* p);
void nop_08088a44(struct Enemy* p);
void nop_08088a4c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    nop_080881d8,
    nop_080884a0,
    nop_080885f8,
    nop_0808889c,
    nop_08088a1c,
    nop_08088a44,
    nop_08088a4c,
};
// clang-format on

void mothjiro_080881dc(struct Enemy* p);
void mothjiro_080884a4(struct Enemy* p);
void mothjiro_080885fc(struct Enemy* p);
void mothjiro_080888a0(struct Enemy* p);
void mothjiro_08088a20(struct Enemy* p);
void nop_08088a48(struct Enemy* p);
void mothjiro_08088a50(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    mothjiro_080881dc,
    mothjiro_080884a4,
    mothjiro_080885fc,
    mothjiro_080888a0,
    mothjiro_08088a20,
    nop_08088a48,
    mothjiro_08088a50,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(20)},
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
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(26), PIXEL(20)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(4)};
