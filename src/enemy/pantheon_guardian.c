#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "zero.h"

struct PantheonGuardianObject {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x;  // 0xB4
  u8 unk_b8[4];
  u8 unk_bc;
  u8 unk_bd;
  u8 unk_be;
  u8 unk_bf;
  struct Entity* unk_c0;
};
static_assert(sizeof(struct PantheonGuardianObject) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
static const Coords32 Coord_08365b70;

void FUN_0806465c(struct Body* body, Coords32* c1, Coords32* c2);

// ------------------------------------------------------------------------------------------------------------------------------------

static void PantheonGuardian_Init(struct PantheonGuardianObject* p);
void PantheonGuardian_Update(struct Enemy* p);
void PantheonGuardian_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonGuardianRoutine = {
    [ENTITY_INIT] =      (EnemyFunc)PantheonGuardian_Init,
    [ENTITY_UPDATE] =    (EnemyFunc)PantheonGuardian_Update,
    [ENTITY_DIE] =       (EnemyFunc)PantheonGuardian_Die,
    [ENTITY_DISAPPEAR] = (EnemyFunc)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static void PantheonGuardian_Init(struct PantheonGuardianObject* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_P_GUARDIAN_HP4) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 14);
  } else {
    _INIT_BODY(p, sCollisions, 10);
  }
  SET_BODY_INTERSECT_HANDLER(p, FUN_0806465c);
  p->x = p->coord.x;
  p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
  p->d.x = p->d.y = 0;
  p->unk_c0 = NULL;
  p->unk_b8[0] = 0, p->unk_b8[1] = 0;

  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  if ((pZero2->s).coord.x - p->coord.x < 0) {
    p->mode[1] = 1, p->mode[2] = 0;
  } else {
    p->mode[1] = 2, p->mode[2] = 0;
  }
  PantheonGuardian_Update((void*)p);
}

INCASM("asm/enemy/pantheon_guardian.inc");

void FUN_08063da0(struct Enemy* p);
void doNothing_08063e10(struct Enemy* p);
void FUN_08063e28(struct Enemy* p);
void FUN_08063e80(struct Enemy* p);
void FUN_08063ec8(struct Enemy* p);
void FUN_08063ef4(struct Enemy* p);
void FUN_08063f28(struct Enemy* p);

// clang-format off
// 0x08365a80
const EnemyFunc sPantheonGuardianUpdates1[9] = {
    (EnemyFunc)FUN_08063da0,
    (EnemyFunc)FUN_08063da0,
    (EnemyFunc)FUN_08063da0,
    (EnemyFunc)doNothing_08063e10,
    (EnemyFunc)FUN_08063e28,
    (EnemyFunc)FUN_08063e80,
    (EnemyFunc)FUN_08063ec8,
    (EnemyFunc)FUN_08063ef4,
    (EnemyFunc)FUN_08063f28,
};
// clang-format on

void FUN_08063f50(struct Enemy* p);
void FUN_08063fd8(struct Enemy* p);
void FUN_080640dc(struct Enemy* p);
void FUN_080641ec(struct Enemy* p);
void FUN_0806429c(struct Enemy* p);
void FUN_08064354(struct Enemy* p);
void FUN_08064444(struct Enemy* p);
void FUN_0806447c(struct Enemy* p);
void FUN_080644fc(struct Enemy* p);

// clang-format off
// 0x08365aa4
static const EnemyFunc sPantheonGuardianUpdates2[9] = {
    (EnemyFunc)FUN_08063f50,
    (EnemyFunc)FUN_08063fd8,
    (EnemyFunc)FUN_080640dc,
    (EnemyFunc)FUN_080641ec,
    (EnemyFunc)FUN_0806429c,
    (EnemyFunc)FUN_08064354,
    (EnemyFunc)FUN_08064444,
    (EnemyFunc)FUN_0806447c,
    (EnemyFunc)FUN_080644fc,
};
// clang-format on

// --------------------------------------------

// 0x08365ac8
static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1000, 0x1000, 0x2000},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1000, -0x1000, 0x3000, 0x1000},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1000, 0x1000, 0x2000},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x1000, 0x1000},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
};

static const Coords32 Coord_08365b70 = {0, -PIXEL(16)};
