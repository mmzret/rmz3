#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

void FUN_080770ac(struct Enemy* p);

void FUN_08076fe4(struct Enemy* p);

void WormerRockDrone_Update(struct Enemy* p);

void WormerRockDrone_Init(struct Enemy* p);

static const EnemyFunc sUpdates1[1];
static const EnemyFunc sUpdates2[1];
static const EnemyFunc sDeads[1];
static const struct Collision sCollisions[2];
static const u8 sInitModes[2];

void CreateWormerRockDrone(s32 x, s32 y, u8 angle, u8 w2) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_WORMER_ROCK_DRONE);
    (p->s).work[0] = 0;
    (p->s).work[2] = w2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).d.x = COS(angle);
    (p->s).d.y = SIN(angle);
  }
}

void nop_08076ee0(struct Enemy* p) {}

void WormerRockDrone_Die(struct Enemy* p);


static bool8 FUN_08076ee4(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = 0;
    WormerRockDrone_Die(p);
    return TRUE;
  }
  return FALSE;
}

void WormerRockDrone_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, sCollisions, 6, (void*)nop_08076ee0);
  WormerRockDrone_Update(p);
}

void WormerRockDrone_Update(struct Enemy* p) {
  if (!FUN_08076ee4(p)) {
    (sUpdates1[(p->s).mode[1]])((void*)p);
    (sUpdates2[(p->s).mode[1]])((void*)p);
  }
}

void WormerRockDrone_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])((void*)p);
}

void FUN_08076fe4(struct Enemy* p) {}

INCASM("asm/enemy/wormer_rock_drone_a.inc");

extern void FUN_080b7f70(struct Enemy* p, struct Coord* c, motion_t* m, s32 n);

void FUN_080770ac(struct Enemy* p) {
  struct Coord c;
  EXIT_BODY(p);
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y;
  CreateSmoke(2, &c);
  FUN_080b7f70(p, &c, (motion_t*)0x08367252, 2);
  PlaySound(0x122);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

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
