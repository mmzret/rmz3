#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/shelluno_a.inc");

void FUN_0807a3ec(struct Body* body, struct Coord* c) {
  register const struct Collision* col asm("r4");
  u8 t;
  col = (body->enemy)->processing;
  t = col->atkType;
  if (t == 3 || t == 14 || t == 15) {
    Object* parent = (Object*)body->parent;
    if ((parent->body).status & BODY_STATUS_DEAD) {
      if (parent->coord.x < c->x) {
        ((struct Enemy*)parent)->buffer[6] = 0xFF;
      } else {
        ((struct Enemy*)parent)->buffer[6] = 0xFE;
      }
    }
  }
  if ((*(u32*)((u8*)col + 4) & 0x200FF) == 0x20002) {
    Object* parent = (Object*)body->parent;
    if (parent->mode[1] != 5 && ((struct Enemy*)parent)->buffer[5] != 0) {
      SET_ENEMY_ROUTINE((struct Enemy*)parent, ENTITY_DIE);
    }
  }
}

INCASM("asm/enemy/shelluno_b.inc");

void Shelluno_Init(struct Enemy* p);
void Shelluno_Update(struct Enemy* p);
void Shelluno_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShellunoRoutine = {
    [ENTITY_INIT] =      (void*)Shelluno_Init,
    [ENTITY_UPDATE] =    (void*)Shelluno_Update,
    [ENTITY_DIE] =       (void*)Shelluno_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0807939c(struct Enemy* p);
void FUN_080795b8(struct Enemy* p);
void FUN_0807a018(struct Enemy* p);
void FUN_0807a064(struct Enemy* p);
void FUN_0807a06c(struct Enemy* p);
void FUN_0807a0fc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    nop_0807939c,
    FUN_080795b8,
    FUN_0807a018,
    FUN_0807a064,
    FUN_0807a06c,
    FUN_0807a0fc,
};
// clang-format on

void shelluno_080793a0(struct Enemy* p);
void FUN_080795f0(struct Enemy* p);
void FUN_0807a01c(struct Enemy* p);
void FUN_0807a068(struct Enemy* p);
void shelluno_0807a070(struct Enemy* p);
void shelluno_0807a100(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    shelluno_080793a0,
    FUN_080795f0,
    FUN_0807a01c,
    FUN_0807a068,
    shelluno_0807a070,
    shelluno_0807a100,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(18), PIXEL(25)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(18), PIXEL(25)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(9)};
