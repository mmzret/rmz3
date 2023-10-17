#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

// 水没した図書館関連の何か

INCASM("asm/solid/unk_27.inc");

void Solid27_Init(struct Solid* p);
void Solid27_Update(struct Solid* p);
void Solid27_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid27Routine = {
    [ENTITY_INIT] =      Solid27_Init,
    [ENTITY_UPDATE] =    Solid27_Update,
    [ENTITY_DIE] =       Solid27_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

const struct Collision Collision_ARRAY_083710f4[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x5000, 0x0800, -0x6200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0600, -0x1000, 0x1000, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0600, -0x1000, 0x1000, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0600, 0x0800, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0600, 0x0800, 0x1000},
    },
};
