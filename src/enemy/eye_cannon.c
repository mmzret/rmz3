#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "story.h"
#include "score.h"

bool8 FUN_08084744(struct Enemy* p);
void FUN_080847b8(struct Enemy* p);
void FUN_080b7f70(struct Enemy* p, struct Coord* c, motion_t* m, s32 n);
static const struct Collision sCollisions[3];
static const EnemyFunc sDeads[1];
static const motion_t sMotions[3];
static const EnemyFunc sUpdates1[6];
static const EnemyFunc sUpdates2[6];
static const u32 u32_ARRAY_08368358[4];

void EyeCannon_Init(struct Enemy* p);
void EyeCannon_Update(struct Enemy* p);
void EyeCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEyeCannonRoutine = {
    [ENTITY_INIT] =      (void*)EyeCannon_Init,
    [ENTITY_UPDATE] =    (void*)EyeCannon_Update,
    [ENTITY_DIE] =       (void*)EyeCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};




void _killEyeCannon(struct Enemy* p);
void FUN_08084cbc(struct Enemy* p);
void FUN_08084974(struct Enemy* p);
void FUN_08084934(struct Enemy* p);
// clang-format on

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  // NOP
  return;
}

static bool8 FUN_08084708(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = 0;
    EyeCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/enemy/eye_cannon_a.inc");

void EyeCannon_Update(struct Enemy* p) {
  if (!FUN_08084708(p)) {
    FUN_080847b8(p);
    if (!FUN_08084744(p)) {
      (sUpdates1[(p->s).mode[1]])((void*)p);
      (sUpdates2[(p->s).mode[1]])((void*)p);
    }
  }
}

void EyeCannon_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])((void*)p);
}

INCASM("asm/enemy/eye_cannon_b.inc");

void FUN_08084934(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    SetDDP(&p->body, &sCollisions[1]);
    if (!IsFrozen(&p->s)) {
      (p->s).mode[1] = 1;
      (p->s).mode[2] = 0;
    }
  }
}

void FUN_08084974(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0x66, 0));
      SetDDP(&p->body, &sCollisions[2]);
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&p->s);
      break;
  }
}

INCASM("asm/enemy/eye_cannon_c.inc");

void FUN_08084cbc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      PlaySound(0x8f << 1);
      SetMotion(&p->s, MOTION(0x66, 3));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = (p->s).motion.state;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void _killEyeCannon(struct Enemy* p) {
  struct Coord c;
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y + 0x1200;
  FUN_080b7f70(p, &c, (motion_t*)sMotions, 3);
  CreateSmoke(1, &c);
  PlaySound(0x2a);
  TryDropItem(3, &(p->s).coord);
  if (gScore.enemyCount <= 0x270e) {
    gScore.enemyCount++;
  }
  DropEnemyDisk(p, &(p->s).coord);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  if ((p->s).work[0] != 0) {
    SET_FLAG(gCurStory.s.gameflags, u32_ARRAY_08368358[(p->s).work[0] - 1]);
  }
}

void FUN_08084934(struct Enemy* p);
void FUN_08084930(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_08084934,
    FUN_08084930,
    FUN_08084930,
    FUN_08084930,
    FUN_08084930,
    FUN_08084930,
};
// clang-format on

void FUN_08084974(struct Enemy* p);
void FUN_080849b0(struct Enemy* p);
void FUN_08084a80(struct Enemy* p);
void FUN_08084b2c(struct Enemy* p);
void FUN_08084c30(struct Enemy* p);
void FUN_08084cbc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_08084974,
    FUN_080849b0,
    FUN_08084a80,
    FUN_08084b2c,
    FUN_08084c30,
    FUN_08084cbc,
};
// clang-format on

void _killEyeCannon(struct Enemy* p);

static const EnemyFunc sDeads[1] = {
    _killEyeCannon,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
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
      range : {PIXEL(0), PIXEL(18), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(18), PIXEL(20), PIXEL(20)},
    },
};

static const u32 u32_ARRAY_08368358[4] = {
    45,
    46,
    47,
    48,
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(18)};

static const u8 u8_ARRAY_08368370[4] = {
    249,
    135,
    224,
    160,
};

static const motion_t sMotions[3] = {
    MOTION(102, 5),
    MOTION(102, 6),
    MOTION(102, 7),
};
