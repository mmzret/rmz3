#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "overworld.h"
#include "vfx.h"

static const u8 sInitModes[2];
static const struct Collision sCollisions[3];
static const motion_t sMotions[4];

static void VolcanoBomb_Init(struct Enemy* p);
static void VolcanoBomb_Update(struct Enemy* p);
static void VolcanoBomb_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gVolcanoBombRoutine = {
    [ENTITY_INIT] =      VolcanoBomb_Init,
    [ENTITY_UPDATE] =    VolcanoBomb_Update,
    [ENTITY_DIE] =       VolcanoBomb_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateVolcanoBomb(s32 x, s32 y) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_VOLCANO_BOMB);
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[0] = 0;
  }
#if MODERN
  return p;
#endif
}

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  // NOP
  return;
}

bool8 FUN_08071298(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    VolcanoBomb_Die(p);
    return TRUE;
  }
  return FALSE;
}

// --------------------------------------------

static void VolcanoBomb_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 4, onCollision);
  (p->s).coord.y = (&gStageRun.vm.camera)->viewport.y - PIXEL(112);
  VolcanoBomb_Update(p);
}

// --------------------------------------------

static void FUN_080713e8(struct Enemy* p);
void FUN_080713ec(struct Enemy* p);

static void VolcanoBomb_Update(struct Enemy* p) {
  static const EnemyFunc sUpdates1[1] = {
      FUN_080713e8,
  };
  static const EnemyFunc sUpdates2[1] = {
      FUN_080713ec,
  };

  bool8 killed = FUN_08071298(p);
  if (!killed) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

// --------------------------------------------

static void VolcanoBomb_Die(struct Enemy* p) {
  Coords32 c;

  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y;
  FUN_080b7ffc((struct Entity*)p, &c, (motion_t*)sMotions, 4);
  PlaySound(SE_UNK_41);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080713e8(struct Enemy* p) {
  // nop
  return;
}

INCASM("asm/enemy/volcano_bomb.inc");

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
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
      hitzone : 3,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[4] = {
    MOTION(SM031_VOLCANO_BOMB, 1),
    MOTION(SM031_VOLCANO_BOMB, 2),
    MOTION(SM031_VOLCANO_BOMB, 3),
    MOTION(SM031_VOLCANO_BOMB, 4),
};
