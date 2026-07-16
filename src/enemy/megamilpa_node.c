#include "collision.h"
#include "enemy.h"
#include "global.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];   // 0xB4
  u8 nodeIdx;     // 0xB8
  u8 unk_b9[11];  // 0xB9
} MegamilpaNode;
static_assert(sizeof(MegamilpaNode) == sizeof(struct Enemy));

void MegamilpaNode_Init(struct Enemy* p);
void MegamilpaNode_Update(struct Enemy* p);
void MegamilpaNode_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMegamilpaNodeRoutine = {
    [ENTITY_INIT] =      (EnemyFunc)MegamilpaNode_Init,
    [ENTITY_UPDATE] =    (EnemyFunc)MegamilpaNode_Update,
    [ENTITY_DIE] =       (EnemyFunc)MegamilpaNode_Die,
    [ENTITY_DISAPPEAR] = (EnemyFunc)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* CreateMegamilpaNode(u8 idx) {
  MegamilpaNode* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_MEGAMILPA_NODE);
    p->work[0] = 0;
    p->nodeIdx = idx;
  }
  return (void*)p;
}

// --------------------------------------------

INCASM("asm/enemy/megamilpa_node.inc");

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
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(16)},
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
