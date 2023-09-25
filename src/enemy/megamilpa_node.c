#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "vfx.h"

INCASM("asm/enemy/megamilpa_node.inc");

void MegamilpaNode_Init(struct Enemy* p);
void MegamilpaNode_Update(struct Enemy* p);
void MegamilpaNode_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMegamilpaNodeRoutine = {
    [ENTITY_INIT] =      MegamilpaNode_Init,
    [ENTITY_MAIN] =      MegamilpaNode_Update,
    [ENTITY_DIE] =       MegamilpaNode_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08065928(struct Enemy* p);

const EnemyFunc sMegamilpaNodeUpdates1[3] = {
    nop_08065928,
    nop_08065928,
    nop_08065928,
};

// --------------------------------------------

void MegamilpaNode_0806592c(struct Enemy* p);
void MegamilpaNode_08065988(struct Enemy* p);
void MegamilpaNode_08065cbc(struct Enemy* p);

const EnemyFunc sMegamilpaNodeUpdates2[3] = {
    MegamilpaNode_0806592c,
    MegamilpaNode_08065988,
    MegamilpaNode_08065cbc,
};

const struct Collision gMegamilpaNodeHitbox[2] = {
    [0] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x1400, 0x1400},
    },
    [1] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0400, 0x0000, 0x0800, 0x1000},
    },
};

const u8 u8_ARRAY_08365cf0[2] = {0, 0};

// clang-format off
const motion_t sMegamilpaNodeMotions[10] = {
    MOTION(DM160_MEGAMILPA, 0x00),
    MOTION(DM160_MEGAMILPA, 0x01),
    MOTION(DM160_MEGAMILPA, 0x02),
    MOTION(DM160_MEGAMILPA, 0x03),
    MOTION(DM160_MEGAMILPA, 0x04),
    MOTION(DM160_MEGAMILPA, 0x06),
    MOTION(DM160_MEGAMILPA, 0x07),
    MOTION(DM160_MEGAMILPA, 0x08),
    MOTION(DM160_MEGAMILPA, 0x09),
    MOTION(DM160_MEGAMILPA, 0x0A),
};
// clang-format on
