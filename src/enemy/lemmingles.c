#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "stagerun.h"
#include "camera.h"
#include "story.h"

struct EnemyLemmingles {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];
  s32 unk_b8_x;
  u8 unk_bc[8];
};
static_assert(sizeof(struct EnemyLemmingles) == sizeof(struct Enemy));

void Lemmingles_Init(struct Enemy* p);
void Lemmingles_Update(struct Enemy* p);
void Lemmingles_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gLemminglesRoutine = {
    [ENTITY_INIT] =      (EnemyFunc)Lemmingles_Init,
    [ENTITY_UPDATE] =    (EnemyFunc)Lemmingles_Update,
    [ENTITY_DIE] =       (EnemyFunc)Lemmingles_Die,
    [ENTITY_DISAPPEAR] = (EnemyFunc)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0806e590(struct Entity* e, u8 kind1, u8 kind2, u8 kind3) {
  struct EnemyLemmingles* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_LEMMINGLES);
    p->coord.x = e->coord.x;
    p->coord.y = e->coord.y;
    p->unk_28 = (void*)e;
    p->work[0] = kind1;
    p->work[1] = kind3;
    p->work[2] = kind2;
    p->unk_b8_x = e->coord.x;
  }
}

// 0x0806e600
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];
static const struct Collision sCollisions[7];

INCASM("asm/enemy/lemmingles_a.inc");

static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];
bool8 FUN_0806e604(struct Enemy* p);
void FUN_0806e704(struct Enemy* p);
bool8 FUN_0806e674(struct Enemy* p);
void Lemmingles_Die(struct Enemy* p);

void Lemmingles_Update(struct Enemy* p) {
  struct Entity* par = (p->s).unk_28;
  if (par != NULL) {
    if (par->mode[0] > 1) {
      (p->s).unk_28 = NULL;
    }
  }
  if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x6000 ||
      (gCurStory.s.gameflags[4] & 0x42)) {
    if (par != NULL) {
      *(u32*)((u8*)par + 0xb4) &= ~(1 << (p->s).work[1]);
    }
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    (p->s).flags &= ~COLLIDABLE;
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (FUN_0806e604(p)) {
    return;
  }
  FUN_0806e704(p);
  if (FUN_0806e674(p)) {
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/lemmingles_b.inc");

void nop_0806e96c(struct Enemy* p) {}


void FUN_0806e970(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 6;
    (p->s).mode[2] = 0;
  }
}


void FUN_0806e990(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    SetDDP(&p->body, (p->s).work[0] > 1 ? &sCollisions[3] : &sCollisions[1]);
    if (!IsFrozen(&p->s)) {
      (p->s).mode[1] = 1;
      (p->s).mode[2] = 1;
      *((u8*)p + 0xbd) = 0;
    }
  }
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 6;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/lemmingles_c.inc");

// --------------------------------------------

void FUN_0806e990(struct Enemy* p);
void FUN_0806e970(struct Enemy* p);
void nop_0806e96c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    FUN_0806e990,
    FUN_0806e970,
    FUN_0806e970,
    FUN_0806e970,
    FUN_0806e970,
    FUN_0806e970,
    nop_0806e96c,
};
// clang-format on

void FUN_0806e9fc(struct Enemy* p);
void FUN_0806ea64(struct Enemy* p);
void FUN_0806ed08(struct Enemy* p);
void FUN_0806ee0c(struct Enemy* p);
void FUN_0806ee94(struct Enemy* p);
void FUN_0806efa4(struct Enemy* p);
void FUN_0806f07c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0806e9fc,
    FUN_0806ea64,
    FUN_0806ed08,
    FUN_0806ee0c,
    FUN_0806ee94,
    FUN_0806efa4,
    FUN_0806f07c,
};
// clang-format on

// --------------------------------------------

void FUN_0806f1dc(struct Enemy* p);
void FUN_0806f274(struct Enemy* p);
void FUN_0806f07c(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_0806f1dc,
    FUN_0806f274,
    FUN_0806f07c,
};

// --------------------------------------------

// 0x0836686c
static const struct Collision sCollisions[7] = {
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
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(8)};
static const u8 sInitModes[4] = {1, 1, 1, 1};

// clang-format off
// 0x08366920
static const motion_t sMotions[13] = {
    MOTION(SM029_LEMMINGLES, 1),
    MOTION(SM029_LEMMINGLES, 0),
    MOTION(SM029_LEMMINGLES, 3),
    MOTION(SM029_LEMMINGLES, 2),
    // --------------------------------------------
    MOTION(SM029_LEMMINGLES, 1),
    MOTION(SM029_LEMMINGLES, 5),
    MOTION(SM029_LEMMINGLES, 3),
    MOTION(SM029_LEMMINGLES, 11),
    // --------------------------------------------
    MOTION(SM029_LEMMINGLES, 22),
    MOTION(SM029_LEMMINGLES, 23),
    MOTION(SM029_LEMMINGLES, 24),
    // --------------------------------------------
    MOTION(SM029_LEMMINGLES, 19),
    MOTION(SM029_LEMMINGLES, 17),
};
// clang-format on
