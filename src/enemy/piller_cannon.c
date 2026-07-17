#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

static const struct Collision sCollisions[14];
static const motion_t sMotions[7];

void PillerCannon_Init(struct Enemy* p);
void PillerCannon_Update(struct Enemy* p);
void PillerCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPillerCannonRoutine = {
    [ENTITY_INIT] =      PillerCannon_Init,
    [ENTITY_UPDATE] =    PillerCannon_Update,
    [ENTITY_DIE] =       PillerCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreatePillerCannon(Coords32* c, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_PILLER_CANNON);
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/enemy/piller_cannon_a.inc");

extern const EnemyFunc sUpdates1[9];
extern const EnemyFunc sUpdates2[9];
void FUN_08068f08(struct Enemy* p);
void PillerCannon_Die(struct Enemy* p);

void PillerCannon_Update(struct Enemy* p) {
  struct Entity** slot;
  u8 m;
  u8* t;
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    PillerCannon_Die(p);
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  FUN_08068f08(p);
  m = (p->s).mode[1];
  if (m == 6) goto check2;
  if (m == 8) goto check2;
  if (IsFrozen(&p->s)) {
    p->buffer[6] = (p->s).mode[1];
    return;
  }
check2:
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (*slot != NULL) {
    if (!isKilled(*slot)) {
      SetDDP(&p->body, &sCollisions[12]);
      return;
    }
    SetDDP(&p->body, &sCollisions[11]);
    *slot = NULL;
  }
  t = (u8*)((u8*)p + 0xc0);
  if (*t != 0) {
    *t = *t - 1;
    return;
  }
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/piller_cannon_b.inc");

bool8 FUN_0806860c(struct Enemy* p) { return TRUE; }


void FUN_08068610(struct Enemy* p) {}

bool8 FUN_08068614(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_c.inc");

bool8 FUN_080686b0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_d.inc");

bool8 FUN_08068780(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_e.inc");

bool8 FUN_08068ad8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_f.inc");

bool8 FUN_08068c84(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_g.inc");

bool8 FUN_08068e60(struct Enemy* p) { return TRUE; }

void FUN_08068e64(struct Enemy* p) {
  struct Entity** slot;
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[12]);
    (p->s).mode[2]++;
  }
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (isKilled(*slot)) {
    SetDDP(&p->body, &sCollisions[11]);
    *slot = NULL;
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
}

bool8 FUN_08068eb0(struct Enemy* p) { return TRUE; }


void FUN_08068eb4(struct Enemy* p) {}

bool8 FUN_08068eb8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_h.inc");

bool8 FUN_0806860c(struct Enemy* p);
bool8 FUN_08068614(struct Enemy* p);
bool8 FUN_080686b0(struct Enemy* p);
bool8 FUN_08068780(struct Enemy* p);
bool8 FUN_08068ad8(struct Enemy* p);
bool8 FUN_08068c84(struct Enemy* p);
bool8 FUN_08068e60(struct Enemy* p);
bool8 FUN_08068eb0(struct Enemy* p);
bool8 FUN_08068eb8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[9] = {
    (EnemyFunc)FUN_0806860c,
    (EnemyFunc)FUN_08068614,
    (EnemyFunc)FUN_080686b0,
    (EnemyFunc)FUN_08068780,
    (EnemyFunc)FUN_08068ad8,
    (EnemyFunc)FUN_08068c84,
    (EnemyFunc)FUN_08068e60,
    (EnemyFunc)FUN_08068eb0,
    (EnemyFunc)FUN_08068eb8,
};
// clang-format on

void FUN_08068610(struct Enemy* p);
void FUN_08068618(struct Enemy* p);
void FUN_080686b4(struct Enemy* p);
void FUN_08068784(struct Enemy* p);
void FUN_08068adc(struct Enemy* p);
void FUN_08068c88(struct Enemy* p);
void FUN_08068e64(struct Enemy* p);
void FUN_08068eb4(struct Enemy* p);
void FUN_08068ebc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[9] = {
    FUN_08068610,
    FUN_08068618,
    FUN_080686b4,
    FUN_08068784,
    FUN_08068adc,
    FUN_08068c88,
    FUN_08068e64,
    FUN_08068eb4,
    FUN_08068ebc,
};
// clang-format on

// 0x0836609c
static const struct Collision sCollisions[14] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1C00, 0x1C00},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1A00},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1C00, 0x1C00},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1300, 0x0000, 0x1200, 0x1400},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-0x1300, 0x0000, 0x1200, 0x1400},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0F00, 0x0000, 0x2100, 0x1400},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-0x0F00, 0x0000, 0x2100, 0x1400},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0700, 0x0000, 0x2400, 0x1400},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-0x0700, 0x0000, 0x2400, 0x1400},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x1400},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x2000, 0x1400},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, 0x0000, 0x1D00, 0x2000},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : 0x01,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {-0x0C00, 0x0000, 0x1D00, 0x2000},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {-0x1400, 0x0000, 0x0D00, 0x1000},
    },
};

const Coords32 Coord_083661ec = {0xFFFFF500, 0x0};

// clang-format off
// 0x083661f4
static const motion_t sMotions[7] = {
    MOTION(SM008_PILLAR_CANNON, 0x01),
    MOTION(SM008_PILLAR_CANNON, 0x02),
    MOTION(SM008_PILLAR_CANNON, 0x03),
    MOTION(SM008_PILLAR_CANNON, 0x04),
    MOTION(SM008_PILLAR_CANNON, 0x03),
    MOTION(SM008_PILLAR_CANNON, 0x02),
    MOTION(SM008_PILLAR_CANNON, 0x01),
};
// clang-format on

static const s32 s32_ARRAY_08366204[7] = {
    3, 5, 7, 9, 7, 5, 3,
};
