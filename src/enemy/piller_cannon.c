#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "score.h"
#include "story.h"
#include "vfx.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 x_b4;              // 0xB4
  u8 unk_b8;             // 0xB8
  u8 unk_b9;             // 0xB9
  u8 unk_ba;             // 0xBA
  u8 unk_bb;             // 0xBB
  Entity* elfx;          // 0xBC, Element FX
  u8 unk_c0;             // 0xC0
  u8 unk_c1[3];          // 0xC1
} PillerCannon;
static_assert(sizeof(PillerCannon) == sizeof(struct Enemy));

static const struct Collision sCollisions[14];
static const motion_t sMotions[7];

static void PillerCannon_Init(PillerCannon* p);
static void PillerCannon_Update(PillerCannon* p);
static void PillerCannon_Die(PillerCannon* p);

// clang-format off
const EnemyRoutine gPillerCannonRoutine = {
    [ENTITY_INIT] =      (void*)PillerCannon_Init,
    [ENTITY_UPDATE] =    (void*)PillerCannon_Update,
    [ENTITY_DIE] =       (void*)PillerCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static PillerCannon* Unused_CreatePillerCannon(Coords32* c, u8 n) {
  PillerCannon* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_PILLER_CANNON);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

void PillerCannon_OnCollision(struct Body* body, Coords32* c1, Coords32* _ UNUSED);

static void PillerCannon_Init(PillerCannon* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_PILLER_CANNON) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 12);
  } else {
    _INIT_BODY(p, sCollisions, 8);
  }
  SET_BODY_INTERSECT_HANDLER(p, PillerCannon_OnCollision);
  p->x_b4 = (p->coord).x;
  p->d = p->coord;
  p->unk_b8 = 0;
  p->elfx = NULL;
  p->unk_b9 = 0;
  p->unk_bb = 0;
  p->unk_c0 = 0;
  (p->coord).x += PIXEL(8);
  if (p->work[0] == 0) {
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
  }
  if (IsFrozen(p)) {
    SetSpriteAnimation(p, MOTION(SM008_PILLAR_CANNON, 0));
    UpdateSpriteAnimation(p);
  }
  PillerCannon_Update(p);
}

bool8 FUN_0806860c(PillerCannon* p);
bool8 FUN_08068614(PillerCannon* p);
bool8 FUN_080686b0(PillerCannon* p);
bool8 FUN_08068780(PillerCannon* p);
bool8 FUN_08068ad8(PillerCannon* p);
bool8 FUN_08068c84(PillerCannon* p);
bool8 FUN_08068e60(PillerCannon* p);
bool8 FUN_08068eb0(PillerCannon* p);
bool8 FUN_08068eb8(PillerCannon* p);

void FUN_08068610(PillerCannon* p);
void FUN_08068618(PillerCannon* p);
void FUN_080686b4(PillerCannon* p);
void FUN_08068784(PillerCannon* p);
void FUN_08068adc(PillerCannon* p);
void FUN_08068c88(PillerCannon* p);
void FUN_08068e64(PillerCannon* p);
void FUN_08068eb4(PillerCannon* p);
void FUN_08068ebc(PillerCannon* p);

void FUN_08068f08(PillerCannon* p);

void PillerCannon_Update(PillerCannon* p) {
  // clang-format off
  static bool8 (*const sUpdates1[9])(PillerCannon*) = {
      FUN_0806860c,
      FUN_08068614,
      FUN_080686b0,
      FUN_08068780,
      FUN_08068ad8,
      FUN_08068c84,
      FUN_08068e60,
      FUN_08068eb0,
      FUN_08068eb8,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[9])(PillerCannon*) = {
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

  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    PillerCannon_Die(p);
    return;
  }
  (sUpdates1[p->mode[1]])(p);
  FUN_08068f08(p);

  if (p->mode[1] != 6 && p->mode[1] != 8 && IsFrozen(p)) {
    p->unk_ba = p->mode[1];
    return;
  }
  if (p->elfx != NULL) {
    if (!isKilled(p->elfx)) {
      SetDDP(&p->body, &sCollisions[12]);
      return;
    }
    SetDDP(&p->body, &sCollisions[11]);
    p->elfx = NULL;
  }
  if (p->unk_c0 > 0) {
    p->unk_c0--;
    return;
  }
  (sUpdates2[p->mode[1]])(p);
}

static void PillerCannon_Die(PillerCannon* p) {
  Coords32 c;
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  switch (p->mode[2]) {
    case 0: {
      p->mode[2] = 1;
      EXIT_BODY(p);
      FALLTHROUGH;
    }
    case 1: {
      c.x = (p->coord).x, c.y = (p->coord).y;  // ??
      p->mode[2]++;
      break;
    }
    case 2: {
      c.x = (p->d).x, c.y = (p->d).y;
      CreateSmoke(1, &c);
      PlaySound(SE_ZAKO_EXPLODE);
      TryDropItem(4, &p->coord);
      if (gScore.enemyCount < 9999) gScore.enemyCount++;
      DropEnemyDisk(p, &p->coord);
      p->flags &= ~DISPLAY;
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
    }
  }
}

bool8 FUN_0806860c(PillerCannon* p) { return TRUE; }

void FUN_08068610(PillerCannon* p) {}

bool8 FUN_08068614(PillerCannon* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_c.inc");

bool8 FUN_080686b0(PillerCannon* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_d.inc");

bool8 FUN_08068780(PillerCannon* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_e.inc");

bool8 FUN_08068ad8(PillerCannon* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_f.inc");

bool8 FUN_08068c84(PillerCannon* p) { return TRUE; }

INCASM("asm/enemy/piller_cannon_g.inc");

bool8 FUN_08068e60(PillerCannon* p) { return TRUE; }

void FUN_08068e64(PillerCannon* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[12]);
    p->mode[2]++;
  }
  if (isKilled(p->elfx)) {
    SetDDP(&p->body, &sCollisions[11]);
    p->elfx = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

bool8 FUN_08068eb0(PillerCannon* p) { return TRUE; }

void FUN_08068eb4(PillerCannon* p) {}

bool8 FUN_08068eb8(PillerCannon* p) { return TRUE; }

void FUN_08068ebc(PillerCannon* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[12]);
    p->mode[2]++;
  }
  if (isKilled(p->elfx)) {
    SetDDP(&p->body, &sCollisions[11]);
    p->elfx = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

INCASM("asm/enemy/piller_cannon_h.inc");

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
    MOTION(SM008_PILLAR_CANNON, 1),
    MOTION(SM008_PILLAR_CANNON, 2),
    MOTION(SM008_PILLAR_CANNON, 3),
    MOTION(SM008_PILLAR_CANNON, 4),
    MOTION(SM008_PILLAR_CANNON, 3),
    MOTION(SM008_PILLAR_CANNON, 2),
    MOTION(SM008_PILLAR_CANNON, 1),
};
// clang-format on

static const s32 s32_ARRAY_08366204[7] = {
    3, 5, 7, 9, 7, 5, 3,
};
