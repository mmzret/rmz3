#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "camera.h"
#include "stagerun.h"

void FUN_08076fe8(struct Enemy* p);

INCASM("asm/enemy/wormer_rock_drone_a.inc");

void FUN_08076fe8(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).palID = (p->s).work[2];
      SetMotion(&p->s, MOTION(0x2c, 1));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      UpdateEntityAnim(&p->s);
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x2000) {
        (p->s).flags &= ~DISPLAY;
        (p->s).flags &= ~FLIPABLE;
        EXIT_BODY(p);
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
        break;
      }
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).mode[1] = 0;
      }
      break;
  }
}

INCASM("asm/enemy/wormer_rock_drone_b.inc");

void WormerRockDrone_Init(struct Enemy* p);
void WormerRockDrone_Update(struct Enemy* p);
void WormerRockDrone_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gWormerRockDroneRoutine = {
    [ENTITY_INIT] =      (void*)WormerRockDrone_Init,
    [ENTITY_UPDATE] =    (void*)WormerRockDrone_Update,
    [ENTITY_DIE] =       (void*)WormerRockDrone_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08076fe4(struct Enemy* p);

static const EnemyFunc sUpdates1[1] = {
    FUN_08076fe4,
};

void FUN_08076fe8(struct Enemy* p);

static const EnemyFunc sUpdates2[1] = {
    FUN_08076fe8,
};

// --------------------------------------------

void FUN_080770ac(struct Enemy* p);

static const EnemyFunc sDeads[1] = {
    FUN_080770ac,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[2] = {
    MOTION(SM044_WORMER_ROCK_DRONE, 2),
    MOTION(SM044_WORMER_ROCK_DRONE, 3),
};
