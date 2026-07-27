#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "stagerun.h"

void OmegaZeroRock_Init(struct Enemy* p);
void OmegaZeroRock_Update(struct Enemy* p);
void OmegaZeroRock_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gOmegaZeroRockRoutine = {
    [ENTITY_INIT] =      (void*)OmegaZeroRock_Init,
    [ENTITY_UPDATE] =    (void*)OmegaZeroRock_Update,
    [ENTITY_DIE] =       (void*)OmegaZeroRock_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void CreateOzChargeSaberRock(s32 x, u8 r1) {
  s32 y;
  s32 prev_x = x;

  x -= PIXEL(48);
  x += (RANDOM(RNG_0202f388) % PIXEL(96));

  y = ((&gStageRun.vm.camera)->viewport).y - PIXEL(112);

  {
    struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
    if (p != NULL) {
      INIT_ENEMY_ROUTINE(p, ENEMY_OZ_ROCK);
      p->work[0] = 0;
      (p->coord).x = x, (p->coord).y = y;
      (p->unk_coord).x = prev_x;
      p->work[3] = r1;
    }
  }
}

// 0x0808B5E4
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

static bool8 FUN_0808b5e8(Object* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    OmegaZeroRock_Die((void*)p);
    return TRUE;
  }
  return FALSE;
}

// --------------------------------------------

INCASM("asm/enemy/omega_zero_rock_a.inc");

void nop_0808b704(struct Enemy* p) {
}

INCASM("asm/enemy/omega_zero_rock_b.inc");

void nop_0808b704(struct Enemy* p);

static const EnemyFunc sUpdates1[1] = {
    nop_0808b704,
};

void FUN_0808b708(struct Enemy* p);

static const EnemyFunc sUpdates2[1] = {
    FUN_0808b708,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(SM237_ROCK, 1),
    MOTION(SM237_ROCK, 2),
    MOTION(SM237_ROCK, 3),
};
