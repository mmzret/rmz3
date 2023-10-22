#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/seimeran.inc");

void Seimeran_Init(struct Enemy* p);
void Seimeran_Update(struct Enemy* p);
void Seimeran_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSeimeranRoutine = {
    [ENTITY_INIT] =      Seimeran_Init,
    [ENTITY_UPDATE] =    Seimeran_Update,
    [ENTITY_DIE] =       Seimeran_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0808f728(struct Enemy* p);
void FUN_0808f72c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_0808f72c,
    FUN_0808f728,
    FUN_0808f728,
    FUN_0808f728,
    FUN_0808f728,
    FUN_0808f728,
    FUN_0808f728,
    FUN_0808f728,
};
// clang-format on

void FUN_0808f7ac(struct Enemy* p);
void FUN_0808f824(struct Enemy* p);
void FUN_0808f8e0(struct Enemy* p);
void FUN_0808f934(struct Enemy* p);
void FUN_0808fa24(struct Enemy* p);
void FUN_0808fa70(struct Enemy* p);
void FUN_0808fb10(struct Enemy* p);
void FUN_0808fc10(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_0808f7ac,
    FUN_0808f824,
    FUN_0808f8e0,
    FUN_0808f934,
    FUN_0808fa24,
    FUN_0808fa70,
    FUN_0808fb10,
    FUN_0808fc10,
};
// clang-format on

// --------------------------------------------

void maybeKillSeimeran(struct Enemy* p);
void FUN_0808fd88(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08369414[2] = {
    maybeKillSeimeran,
    FUN_0808fd88,
};

// --------------------------------------------

static const struct Collision sCollisions[15] = {
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
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(15), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(9), PIXEL(18), PIXEL(21)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(15), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(11), PIXEL(18), PIXEL(25)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(11), PIXEL(15), PIXEL(25)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(18), PIXEL(29)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(13), PIXEL(15), PIXEL(29)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(18), PIXEL(35)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(15), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(17), PIXEL(18), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(17), PIXEL(15), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(15), PIXEL(15)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(15), PIXEL(15)},
    },
};

static const u8 sCollisionIdxs[16] = {1, 1, 3, 3, 5, 5, 7, 7, 9, 9, 11, 11, 11, 0, 0, 0};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(8)};

static const u8 sInitModes[4] = {1, 5, 7, 0};

static const motion_t sMotions[1] = {
    MOTION(SM119_SEIMERAN, 5),
};
