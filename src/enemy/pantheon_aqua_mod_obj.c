#include "collision.h"
#include "enemy.h"
#include "global.h"

void nop_08080eb8(struct Enemy* p);

void PantheonAquaModObj_Init(struct Enemy* p);
void PantheonAquaModObj_Update(struct Enemy* p);
void PantheonAquaModObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonAquaModObjRoutine = {
    [ENTITY_INIT] =      (void*)PantheonAquaModObj_Init,
    [ENTITY_UPDATE] =    (void*)PantheonAquaModObj_Update,
    [ENTITY_DIE] =       (void*)PantheonAquaModObj_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void createPAquaModRubble(s32 x) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 8;
    (p->coord).x = x;
  }
}

void FUN_08080858(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 6;
    (p->coord).x = e->coord.x, (p->coord).y = e->coord.y;
    p->unk_28 = (void*)e;
  }
}

void FUN_080808b4(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 3;
    p->unk_28 = (void*)e;
  }
}

void FUN_08080908(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 0;
    (p->coord).x = e->coord.x, (p->coord).y = e->coord.y;
    p->unk_28 = (void*)e;
  }
}

void FUN_08080964(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 1;
    (p->coord).x = e->coord.x, (p->coord).y = e->coord.y;
    p->unk_28 = (void*)e;
  }
}

void createLaserSign2(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 2, p->work[1] = 1;
    (p->coord).x = e->coord.x, (p->coord).y = e->coord.y - PIXEL(12);
    p->unk_28 = (void*)e;
  }
}

void createSweepLaserSign(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 2, p->work[1] = 1;
    (p->coord).x = e->coord.x, (p->coord).y = e->coord.y - PIXEL(12);
    p->unk_28 = (void*)e;
  }
}

void createStretchedGrabArm(struct Entity* e, bool8 is_right_arm) {
  s32 i;
  struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);  // hand
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 5, p->work[1] = is_right_arm;
    (p->coord).x = (e->coord).x - PIXEL(23);
    (p->coord).x += is_right_arm * PIXEL(46);
    (p->coord).y = (e->coord).y - PIXEL(4);
    p->unk_28 = (void*)e;
  }
  for (i = 0; i < 6; i++) {
    // joints
    struct Entity* q = AllocEntityLast(gEnemyHeaderPtr);
    if (q != NULL) {
      INIT_ENEMY_ROUTINE(q, ENEMY_P_AQUA_MOD_OBJ);
      q->work[0] = 4, q->work[1] = is_right_arm;
      q->unk_28 = (void*)e, q->unk_2c = (void*)p;
      q->work[2] = i + 1;
    }
  }
}

void createStretchedArms(struct Entity* e) {
  s32 i, j;
  for (i = 0; i < 2; i++) {
    struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);  // hand
    if (p != NULL) {
      INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
      p->work[0] = 7, p->work[1] = i;
      (p->coord).x = (e->coord).x - PIXEL(23);
      (p->coord).x += i * PIXEL(46);
      (p->coord).y = (e->coord).y + PIXEL(4);
      p->unk_28 = (void*)e;
    }
    for (j = 0; j < 6; j++) {
      struct Entity* q = AllocEntityLast(gEnemyHeaderPtr);  // joints
      if (q != NULL) {
        INIT_ENEMY_ROUTINE(q, ENEMY_P_AQUA_MOD_OBJ);
        q->work[0] = 4, q->work[1] = i;
        q->unk_28 = (void*)e, q->unk_2c = (void*)p;
        q->work[2] = j + 1;
      }
    }
  }
}

void FUN_08080c64(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA_MOD_OBJ);
    p->work[0] = 9;
    (p->coord).x = x, (p->coord).y = y;
  }
}

INCASM("asm/enemy/pantheon_aqua_mod_obj_a.inc");

void nop_08080eb8(struct Enemy* p) {
}

INCASM("asm/enemy/pantheon_aqua_mod_obj_b.inc");

void FUN_08080fe8(struct Enemy* p) {
}

INCASM("asm/enemy/pantheon_aqua_mod_obj_c.inc");

void FUN_08080fe8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
};
// clang-format on

void FUN_08080fec(struct Enemy* p);
void FUN_08081208(struct Enemy* p);
void FUN_08081438(struct Enemy* p);
void FUN_080817a8(struct Enemy* p);
void FUN_080818b8(struct Enemy* p);
void FUN_08081990(struct Enemy* p);
void FUN_08081d2c(struct Enemy* p);
void FUN_08081e00(struct Enemy* p);
void FUN_08081fc4(struct Enemy* p);
void FUN_080820b8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    FUN_08080fec,
    FUN_08081208,
    FUN_08081438,
    FUN_080817a8,
    FUN_080818b8,
    FUN_08081990,
    FUN_08081d2c,
    FUN_08081e00,
    FUN_08081fc4,
    FUN_080820b8,
};
// clang-format on

// --------------------------------------------

// 0x08368000
static const struct Collision sCollisions[10] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      unk_0a : 0x41,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), -PIXEL(128), -PIXEL(128)},
    },
};

static const u8 sInitModes[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// clang-format off
static const motion_t sMotions[8] = {
    MOTION(SM079_PANTHEON_AQUA_MOD_ROCK, 1),
    MOTION(SM079_PANTHEON_AQUA_MOD_ROCK, 2),
    MOTION(SM079_PANTHEON_AQUA_MOD_ROCK, 2),
    MOTION(SM039_PANTHEON_AQUA, 10),
    MOTION(SM039_PANTHEON_AQUA, 19),
    MOTION(SM039_PANTHEON_AQUA, 20),
    MOTION(SM039_PANTHEON_AQUA, 21),
    MOTION(SM039_PANTHEON_AQUA, 22),
};
// clang-format on

static const u8 u8_ARRAY_ARRAY_0836810a[3][3] = {
    {0x3F, 0x3F, 0x3F},
    {0x3F, 0x0A, 0x3F},
    {0x3F, 0x0A, 0x3F},
};
