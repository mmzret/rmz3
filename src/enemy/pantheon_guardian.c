#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "zero.h"

static const struct Collision sCollisions[7];

void FUN_0806465c(struct Body* body, struct Coord* c1, struct Coord* c2);

// ------------------------------------------------------------------------------------------------------------------------------------

static void PantheonGuardian_Init(struct Enemy* p);
void PantheonGuardian_Update(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonGuardianRoutine = {
    [ENTITY_INIT] =      PantheonGuardian_Init,
    [ENTITY_UPDATE] =    PantheonGuardian_Update,
    [ENTITY_DIE] =       PantheonGuardian_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

WIP static void PantheonGuardian_Init(struct Enemy* p) {
#if MODERN
  s32 hp;
  struct PantheonProps* props;
  struct Body* body;

  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  if ((gSystemSavedataManager.mods[1] & (1 << 4)) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    hp = 14;
  } else {
    hp = 10;
  }
  INIT_BODY(p, sCollisions, hp, FUN_0806465c);
  props = &p->props.pantheon;
  props->x = (p->s).coord.x;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  (p->s).d.x = (p->s).d.y = 0;
  props->unk_c0 = NULL;
  props->unk_b8[0] = 0;
  props->unk_b8[1] = 0;

  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  if ((pZero2->s).coord.x < (p->s).coord.x) {
    (p->s).mode[1] = 1;
  } else {
    (p->s).mode[1] = 2;
  }
  (p->s).mode[2] = 0;
  PantheonGuardian_Update(p);
#else
  INCCODE("asm/wip/PantheonGuardian_Init.inc");
#endif
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
const EnemyFunc sPantheonGuardianUpdates1[9] = {
    FUN_08063da0,
    FUN_08063da0,
    FUN_08063da0,
    doNothing_08063e10,
    FUN_08063e28,
    FUN_08063e80,
    FUN_08063ec8,
    FUN_08063ef4,
    FUN_08063f28,
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
static const EnemyFunc sPantheonGuardianUpdates2[9] = {
    FUN_08063f50,
    FUN_08063fd8,
    FUN_080640dc,
    FUN_080641ec,
    FUN_0806429c,
    FUN_08064354,
    FUN_08064444,
    FUN_0806447c,
    FUN_080644fc,
};
// clang-format on

// --------------------------------------------

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

const struct Coord Coord_08365b70 = {0, -0x1000};
