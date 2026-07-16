#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "score.h"
#include "stagerun.h"
#include "camera.h"

INCASM("asm/enemy/cattatank_a.inc");

static const EnemyFunc sUpdates1[10];
static const EnemyFunc sUpdates2[10];
void Cattatank_Die(struct Enemy* p);
void cattatank_08099e20(struct Enemy* p);

void TryDropZakoDisk(struct Enemy* p, Coords32* c);

void Cattatank_Update(struct Enemy* p) {
  u8 m;
  if ((p->body).status & BODY_STATUS_DEAD) {
    if ((p->s).mode[1] == 6) {
      if (!IsFrozen(&p->s)) {
        goto dispatch1;
      }
    }
    (p->s).mode[3] = 0;
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Cattatank_Die(p);
    return;
  }
  if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x3000) {
    if (gStageRun.vm.camera.viewport.y + 0x4FFF < (p->s).coord.y + 0x2000) {
      if ((p->s).work[1] == 1) {
        (p->s).mode[3] = 1;
        PlaySound(0x2a);
        TryDropItem(1, &(p->s).coord);
        if (gScore.enemyCount <= 0x270E) {
          gScore.enemyCount++;
        }
        TryDropZakoDisk(p, &(p->s).coord);
        (p->s).flags &= ~DISPLAY;
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
        return;
      }
    }
  }
dispatch1:
  (sUpdates1[(p->s).mode[1]])(p);
  cattatank_08099e20(p);
  m = (p->s).mode[1];
  if (m == 6 || m == 7) goto dispatch2;
  if (m == 9) goto dispatch2;
  if (IsFrozen(&p->s)) {
    return;
  }
dispatch2:
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/cattatank_b.inc");

bool8 nop_08099090(struct Enemy* p) { return TRUE; }

void cattatank_08099094(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags &= ~DISPLAY;
      (p->s).work[2] = 0x32;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      if ((p->s).work[2] != 0) {
        if (--(p->s).work[2] != 0) break;
      }
      (p->s).mode[1] = 1;
      (p->s).mode[2] = 0;
      break;
  }
}

bool8 nop_080990d4(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_c.inc");

bool8 nop_0809925c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_d.inc");

bool8 nop_080994e8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_e.inc");

bool8 nop_0809973c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_f.inc");

bool8 nop_08099950(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_g.inc");

bool8 nop_08099a94(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_h.inc");

bool8 nop_08099ce0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_i.inc");

bool8 nop_08099d7c(struct Enemy* p) { return TRUE; }

void nop_08099d80(struct Enemy* p) {}

bool8 nop_08099d84(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/cattatank_j.inc");

void Cattatank_Init(struct Enemy* p);
void Cattatank_Update(struct Enemy* p);
void Cattatank_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCattatankRoutine = {
    [ENTITY_INIT] =      Cattatank_Init,
    [ENTITY_UPDATE] =    Cattatank_Update,
    [ENTITY_DIE] =       Cattatank_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------


// clang-format off
static const EnemyFunc sUpdates1[10] = {
    (EnemyFunc)nop_08099090,
    (EnemyFunc)nop_080990d4,
    (EnemyFunc)nop_0809925c,
    (EnemyFunc)nop_080994e8,
    (EnemyFunc)nop_0809973c,
    (EnemyFunc)nop_08099950,
    (EnemyFunc)nop_08099a94,
    (EnemyFunc)nop_08099ce0,
    (EnemyFunc)nop_08099d7c,
    (EnemyFunc)nop_08099d84,
};
// clang-format on

void cattatank_08099094(struct Enemy* p);
void FUN_080990d8(struct Enemy* p);
void FUN_08099260(struct Enemy* p);
void FUN_080994ec(struct Enemy* p);
void FUN_08099740(struct Enemy* p);
void FUN_08099954(struct Enemy* p);
void FUN_08099a98(struct Enemy* p);
void FUN_08099ce4(struct Enemy* p);
void FUN_08099d88(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    cattatank_08099094,
    FUN_080990d8,
    FUN_08099260,
    FUN_080994ec,
    FUN_08099740,
    FUN_08099954,
    FUN_08099a98,
    FUN_08099ce4,
    nop_08099d80,
    FUN_08099d88,
};
// clang-format on

// --------------------------------------------

// 0x0836A4C0
static const struct Collision sCollisions[18] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(12), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(16), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(37), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(49), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
};

// 0x0836a670
static const Coords32 sElementCoords[1] = {
    {PIXEL(0), -PIXEL(18)},
};
