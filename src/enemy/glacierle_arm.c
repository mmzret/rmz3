#include "collision.h"
#include "enemy.h"
#include "global.h"

static const EnemyFunc sUpdates1[3];
static const EnemyFunc sUpdates2[3];
static const struct Collision sCollisions[2];
static const u8 sInitModes[3];

struct Enemy* createGlacierleAtkHand(struct Entity* e) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_GLACIERLE_ARM);
    (p->s).work[0] = 0;
    InitRotatableMotion(&p->s);
    (p->s).unk_2c = NULL;
    (p->s).unk_28 = e;
    (p->s).d.x = 0;
    (p->s).d.y = 0;
    p->buffer[1] = 1;
    p->buffer[0] = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = e->uniqueID;
  }
  return p;
}

INCASM("asm/enemy/glacierle_arm_a.inc");

void nop_080828dc(struct Enemy* p) {}

void GlacierleAtkArm_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  if ((p->s).work[0] == 0) {
    INIT_BODY(p, sCollisions, 1, (void*)nop_080828dc);
  }
  GlacierleAtkArm_Update(p);
}

void GlacierleAtkArm_Update(struct Enemy* p) {
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/glacierle_arm_b.inc");

void nop_08082a1c(struct Enemy* p) {}

void FUN_08082a20(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      u8 savedAngle = (p->s).angle;
      InitRotatableMotion(&p->s);
      SetSpriteAnimation(p, MOTION(0x59, 0));
      (p->s).angle = savedAngle;
      if (p->buffer[1] == 0) {
        UpdateSpriteAnimation(p);
      }
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).mode[2]++;
    }
      FALLTHROUGH;
    case 1:
      if (p->buffer[1] != 0) {
        UpdateSpriteAnimation(p);
      }
      break;
  }
  if (((struct Entity*)(p->s).unk_28)->mode[0] > 1) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  }
}

void FUN_08082aa0(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      EnableSpriteAnimation_Normal(p);
      SetSpriteAnimation(p, MOTION(0x59, 1));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
  }
  if ((*(struct Entity**)&p->buffer[8])->mode[0] > 1) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  }
}

void FUN_08082af8(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      u8 savedAngle = (p->s).angle;
      InitRotatableMotion(&p->s);
      SetSpriteAnimation(p, MOTION(0x59, 2));
      (p->s).angle = savedAngle;
      (p->s).mode[2]++;
    }
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
  }
  if ((*(struct Entity**)&p->buffer[8])->mode[0] > 1) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  }
}

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
