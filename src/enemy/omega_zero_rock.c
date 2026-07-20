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

static const EnemyFunc sUpdates1[1];
static const EnemyFunc sUpdates2[1];
static const struct Collision sCollisions[2];
static const u8 sInitModes[2];
static const motion_t sMotions[3];

void OmegaZeroRock_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 5, onCollision);
  OmegaZeroRock_Update(p);
}

void OmegaZeroRock_Update(struct Enemy* p) {
  if (!FUN_0808b5e8((Object*)p)) {
    sUpdates1[(p->s).mode[1]](p);
    sUpdates2[(p->s).mode[1]](p);
  }
}

void OmegaZeroRock_Die(struct Enemy* p) {
  PlaySound(0x41);
  FUN_080b7ffc((struct Entity*)p, &(p->s).coord, (motion_t*)sMotions, 3);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void nop_0808b704(struct Enemy* p) {}

void FUN_0808b708(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).d.y = 0;
      (p->s).work[2] = 0x10;
      SetSpriteAnimation(p, 0xed00);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      if ((p->s).work[2] != 0) {
        if (--(p->s).work[2] == 0 && (p->s).work[3] <= 1) {
          CreateOzChargeSaberRock((p->s).unk_coord.x, (p->s).work[3] + 1);
        }
      } else if ((u16)FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      }
      UpdateSpriteAnimation(p);
      break;
  }
}

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
