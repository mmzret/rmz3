#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/pantheon_zombie.inc");

void PantheonZombie_Init(struct Enemy* p);
void PantheonZombie_Update(struct Enemy* p);
void PantheonZombie_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonZombieRoutine = {
    [ENTITY_INIT] =      PantheonZombie_Init,
    [ENTITY_UPDATE] =    PantheonZombie_Update,
    [ENTITY_DIE] =       PantheonZombie_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807ffb0(struct Enemy* p);
void FUN_0807ff40(struct Enemy* p);
void nop_0807ff3c(struct Enemy* p);
void FUN_0807ff6c(struct Enemy* p);
void FUN_0807ff94(struct Enemy* p);
void FUN_0807ff6c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_0807ffb0,
    FUN_0807ff40,
    nop_0807ff3c,
    FUN_0807ff6c,
    FUN_0807ff94,
    FUN_0807ff6c,
    nop_0807ff3c,
    nop_0807ff3c,
};
// clang-format on

void FUN_0807ffd8(struct Enemy* p);
void FUN_08080054(struct Enemy* p);
void FUN_0808027c(struct Enemy* p);
void FUN_08080324(struct Enemy* p);
void FUN_080803dc(struct Enemy* p);
void FUN_080804a8(struct Enemy* p);
void FUN_08080610(struct Enemy* p);
void FUN_08080734(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_0807ffd8,
    FUN_08080054,
    FUN_0808027c,
    FUN_08080324,
    FUN_080803dc,
    FUN_080804a8,
    FUN_08080610,
    FUN_08080734,
};
// clang-format on

void FUN_08080674(struct Enemy* p);
void FUN_080806e0(struct Enemy* p);
void FUN_08080734(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_08080674,
    FUN_080806e0,
    FUN_08080734,
};

// --------------------------------------------

static const struct Collision sCollisions[8] = {
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
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(16), PIXEL(14), PIXEL(32)},
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
      range : {PIXEL(4), -PIXEL(16), PIXEL(14), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      unk_0a : 0x21,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(16), PIXEL(22), PIXEL(32)},
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
      range : {PIXEL(2), -PIXEL(16), PIXEL(22), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      unk_0a : 0x21,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(16), PIXEL(64), PIXEL(64)},
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
      range : {PIXEL(2), -PIXEL(16), PIXEL(22), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(16), PIXEL(14), PIXEL(32)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(16)};
static const u8 sInitModes[4] = {2, 0, 0, 0};
