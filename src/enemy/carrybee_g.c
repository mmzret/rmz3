#include "collision.h"
#include "enemy.h"
#include "global.h"

void nop_0808b534(struct Enemy* p);

void CarrybeeG_Init(struct Enemy* p);
void CarrybeeG_Update(struct Enemy* p);
void CarrybeeG_Die(struct Enemy* p);
void CarrybeeG_Disappear(struct Enemy* p);

// clang-format off
const EnemyRoutine gCarrybeeGRoutine = {
    [ENTITY_INIT] =      CarrybeeG_Init,
    [ENTITY_UPDATE] =    CarrybeeG_Update,
    [ENTITY_DIE] =       CarrybeeG_Die,
    [ENTITY_DISAPPEAR] = CarrybeeG_Disappear,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* FUN_0808a854(Coords32* c) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CARRYBEE_G);
    (p->s).coord = *c;
    (p->s).work[0] = 0;
  }
  return p;
}

struct Enemy* FUN_0808a8b0(struct Entity* e) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CARRYBEE_G);
    (p->s).work[0] = 1;
    (p->s).unk_28 = e;
  }
  return p;
}

INCASM("asm/enemy/carrybee_g_a.inc");

bool8 FUN_0808af78(struct Enemy* p) {
  return TRUE;
}

INCASM("asm/enemy/carrybee_g_b.inc");

bool8 FUN_0808b008(struct Enemy* p) {
  return TRUE;
}

INCASM("asm/enemy/carrybee_g_c.inc");

bool8 FUN_0808b108(struct Enemy* p) {
  return TRUE;
}

INCASM("asm/enemy/carrybee_g_d.inc");

bool8 FUN_0808b2b0(struct Enemy* p) {
  return TRUE;
}

INCASM("asm/enemy/carrybee_g_e.inc");

bool8 FUN_0808b418(struct Enemy* p) {
  return TRUE;
}

INCASM("asm/enemy/carrybee_g_f.inc");

void nop_0808b534(struct Enemy* p) {
}

bool8 FUN_0808af78(struct Enemy* p);
bool8 FUN_0808b008(struct Enemy* p);
bool8 FUN_0808b108(struct Enemy* p);
bool8 FUN_0808b2b0(struct Enemy* p);
bool8 FUN_0808b418(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[5] = {
    (EnemyFunc)FUN_0808af78,
    (EnemyFunc)FUN_0808b008,
    (EnemyFunc)FUN_0808b108,
    (EnemyFunc)FUN_0808b2b0,
    (EnemyFunc)FUN_0808b418,
};
// clang-format on

void FUN_0808af7c(struct Enemy* p);
void carrybeeg_0808b00c(struct Enemy* p);
void FUN_0808b10c(struct Enemy* p);
void FUN_0808b2b4(struct Enemy* p);
void FUN_0808b41c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[5] = {
    FUN_0808af7c,
    carrybeeg_0808b00c,
    FUN_0808b10c,
    FUN_0808b2b4,
    FUN_0808b41c,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 7,
      layer : 0x00000001,
      range : {PIXEL(30), -PIXEL(4), PIXEL(69), PIXEL(39)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 6,
      range : {PIXEL(30), -PIXEL(4), PIXEL(69), PIXEL(39)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 5,
      layer : 0x00000001,
      range : {-PIXEL(36), -PIXEL(7), PIXEL(62), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 4,
      range : {-PIXEL(36), -PIXEL(7), PIXEL(62), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(18), PIXEL(10), PIXEL(26), PIXEL(11)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 2,
      range : {-PIXEL(18), PIXEL(10), PIXEL(26), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(6), PIXEL(23), PIXEL(57), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(6), PIXEL(23), PIXEL(57), PIXEL(16)},
    },
};
