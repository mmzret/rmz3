#include "collision.h"
#include "enemy.h"
#include "global.h"

void Crossbyne_Init(struct Enemy* p);
void Crossbyne_Update(struct Enemy* p);
void Crossbyne_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCrossbyneRoutine = {
    [ENTITY_INIT] =      Crossbyne_Init,
    [ENTITY_UPDATE] =    Crossbyne_Update,
    [ENTITY_DIE] =       Crossbyne_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_0807cbf4(s32 x, s32 y, u8 n) {
  struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CROSSBYNE);
    p->work[0] = n;
    (p->coord).x = x, (p->coord).y = y;
  }
  return p;
}

static const Coords16 Coord16_ARRAY_08367c14[4];

// 0x0807cc50
static void FUN_0807cc50(s32 x, s32 y) {
  s32 i;
  const Coords16* c = Coord16_ARRAY_08367c14;

  for (i = 0; i < (s32)ARRAY_COUNT(Coord16_ARRAY_08367c14); i++) {
    struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
    if (p != NULL) {
      INIT_ENEMY_ROUTINE(p, ENEMY_CROSSBYNE);
      p->work[0] = 2, p->work[1] = i;
      (p->coord).x = x;
      (p->coord).x += c[i].x;
      (p->coord).y = y;
      (p->coord).y += c[i].y;
    }
  }
}

static const Coords16 Coord16_ARRAY_08367c24[4];

static void FUN_0807cce0(s32 x, s32 y) {
  s32 i;
  const Coords16* c = Coord16_ARRAY_08367c24;

  for (i = 0; i < (s32)ARRAY_COUNT(Coord16_ARRAY_08367c24); i++) {
    struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
    if (p != NULL) {
      INIT_ENEMY_ROUTINE(p, ENEMY_CROSSBYNE);
      p->work[0] = 3, p->work[1] = i;
      (p->coord).x = x;
      (p->coord).x += c[i].x;
      (p->coord).y = y;
      (p->coord).y += c[i].y;
    }
  }
}

// 0x0807cd70
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];
static const EnemyFunc sDeads[3];
static const struct Collision sCollisions[5];
static const motion_t sMotions[19];

INCASM("asm/enemy/crossbyne_a.inc");

extern const EnemyFunc sUpdates1[7];
extern const EnemyFunc sUpdates2[7];
bool8 FUN_0807cd74(struct Enemy* p);
void crossbyne_0807cdc4(struct Enemy* p);

void Crossbyne_Update(struct Enemy* p) {
  if (!FUN_0807cd74(p)) {
    crossbyne_0807cdc4(p);
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

void Crossbyne_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])(p);
}

void FUN_0807cf5c(struct Enemy* p) {}

void FUN_0807cf60(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    (p->s).mode[1] = 2;
    (p->s).mode[2] = 0;
  }
}

void FUN_0807cf88(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    (p->s).mode[2]++;
  }
}


void FUN_0807cfac(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      PlaySound(0x12b);
      SetSpriteAnimation(p, sMotions[(p->s).work[0]]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/enemy/crossbyne_b.inc");

// --------------------------------------------

void FUN_0807cf5c(struct Enemy* p);
void FUN_0807cf60(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    FUN_0807cf60,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
};
// clang-format on

void FUN_0807cf88(struct Enemy* p);
void FUN_0807cfac(struct Enemy* p);
void FUN_0807d000(struct Enemy* p);
void crossbyne_0807d080(struct Enemy* p);
void FUN_0807d0f0(struct Enemy* p);
void FUN_0807d178(struct Enemy* p);
void FUN_0807d2b8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0807cf88,
    FUN_0807cfac,
    FUN_0807d000,
    crossbyne_0807d080,
    FUN_0807d0f0,
    FUN_0807d178,
    FUN_0807d2b8,
};
// clang-format on

void MaybeKillCrossbyne(struct Enemy* p);
void FUN_0807d478(struct Enemy* p);
void FUN_0807d5c4(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    MaybeKillCrossbyne,
    FUN_0807d478,
    FUN_0807d5c4,
};

// --------------------------------------------

// 0x08367b9c
static const struct Collision sCollisions[5] = {
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
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

// 0x08367c14
static const Coords16 Coord16_ARRAY_08367c14[4] = {
    {-PIXEL(14), PIXEL(0)},
    {PIXEL(14), PIXEL(0)},
    {PIXEL(0), -PIXEL(14)},
    {PIXEL(0), PIXEL(14)},
};

static const Coords16 Coord16_ARRAY_08367c24[4] = {
    {-PIXEL(9), -PIXEL(9)},
    {PIXEL(9), -PIXEL(9)},
    {-PIXEL(9), PIXEL(9)},
    {PIXEL(9), PIXEL(9)},
};

// 0x08367C34
static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};

// 0x08367C3C
static const u8 sInitModes[4] = {1, 1, 5, 6};

// clang-format off
// 0x08367c40
static const motion_t sMotions[19] = {
    MOTION(SM067_CROSSBYNE, 0x00),
    MOTION(SM067_CROSSBYNE, 0x01),
    MOTION(SM067_CROSSBYNE, 0x04),
    MOTION(SM067_CROSSBYNE, 0x05),
    MOTION(SM067_CROSSBYNE, 0x10),
    MOTION(SM067_CROSSBYNE, 0x11),
    MOTION(SM067_CROSSBYNE, 0x02),
    MOTION(SM067_CROSSBYNE, 0x03),
    MOTION(SM067_CROSSBYNE, 0x15),
    MOTION(SM067_CROSSBYNE, 0x16),
    MOTION(SM067_CROSSBYNE, 0x17),
    MOTION(SM067_CROSSBYNE, 0x09),
    MOTION(SM067_CROSSBYNE, 0x07),
    MOTION(SM067_CROSSBYNE, 0x0D),
    MOTION(SM067_CROSSBYNE, 0x0B),
    MOTION(SM067_CROSSBYNE, 0x08),
    MOTION(SM067_CROSSBYNE, 0x06),
    MOTION(SM067_CROSSBYNE, 0x0C),
    MOTION(SM067_CROSSBYNE, 0x0A),
};
// clang-format on
