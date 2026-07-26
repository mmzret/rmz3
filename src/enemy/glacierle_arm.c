#include "entity/macros.h"
#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/glacierle_arm_a.inc");

struct Enemy* createGlacierleJoint(struct Entity* e, struct Entity* parent) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);

  if (p != NULL) {
    struct Entity* prev;

    INIT_ENEMY_ROUTINE(p, 39);
    (p->s).work[0] = 1;
    (p->s).unk_2c = e->unk_2c;
    (p->s).unk_28 = e;
    prev = e->unk_2c;
    if (prev != NULL) {
      prev->unk_28 = (struct Entity*)p;
      (p->s).d.x = prev->d.x;
      (p->s).d.y = prev->d.y;
      (p->s).coord.x = prev->coord.x;
      (p->s).coord.y = prev->coord.y;
      if (prev->unk_2c != NULL) {
        (p->s).coord.x += prev->coord.x - (prev->unk_2c)->coord.x;
        (p->s).coord.y += prev->coord.y - (prev->unk_2c)->coord.y;
      }
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).unk_coord.y = (p->s).coord.y;
    } else {
      (p->s).d.x = 0;
      (p->s).d.y = 0;
    }
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = parent->uniqueID;
    *(struct Entity**)&p->buffer[8] = parent;
    e->unk_2c = (struct Entity*)p;
    p->buffer[2] = ((struct Enemy*)e)->buffer[0];
    ((struct Enemy*)e)->buffer[0]++;
  }
  return p;
}

struct Enemy* createGlacierleSucker(struct Entity* e, struct Entity* parent) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);

  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, 39);
    (p->s).work[0] = 2;
    (p->s).unk_2c = e;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = parent->uniqueID;
    *(struct Entity**)&p->buffer[8] = parent;
  }
  return p;
}

INCASM("asm/enemy/glacierle_arm_b.inc");

void GlacierleAtkArm_Init(struct Enemy* p);
void GlacierleAtkArm_Update(struct Enemy* p);
void GlacierleAtkArm_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGlacierleAtkArmRoutine = {
    [ENTITY_INIT] =      GlacierleAtkArm_Init,
    [ENTITY_UPDATE] =    GlacierleAtkArm_Update,
    [ENTITY_DIE] =       GlacierleAtkArm_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_08082a1c(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    nop_08082a1c,
    nop_08082a1c,
    nop_08082a1c,
};

void FUN_08082a20(struct Enemy* p);
void FUN_08082aa0(struct Enemy* p);
void FUN_08082af8(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    FUN_08082a20,
    FUN_08082aa0,
    FUN_08082af8,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
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
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(12), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
};

static const u8 sInitModes[3] = {0, 1, 2};
