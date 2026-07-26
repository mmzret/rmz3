#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "zero.h"
#include "story.h"

void FUN_08097cc8(struct Enemy* p);

void FUN_080978e0(struct Enemy* p);

void FUN_08097904(struct Enemy* p);

void FUN_080978e4(struct Enemy* p);

void CannonHopper_Die(struct Enemy* p);

static const EnemyFunc sDeads[4];

INCASM("asm/enemy/cannon_hopper_a.inc");

void CannonHopper_Die(struct Enemy* p) {
  if (gCurStory.s.gameflags[4] & 0x40) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    (sDeads[(p->s).mode[1]])((void*)p);
  }
}

void FUN_080978c8(struct Enemy* p) {
  struct Enemy* parent = (struct Enemy*)(p->s).unk_2c;
  *(s32*)((u8*)parent + 0xb4) = pZero2->s.coord.x - (parent->s).coord.x;
}

void FUN_080978e0(struct Enemy* p) {}


void FUN_080978e4(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
}


void FUN_08097904(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/cannon_hopper_b.inc");

void FUN_08097cc8(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(0xdc, 3));
      (p->s).work[2] = 0xc;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      UpdateSpriteAnimation(p);
      break;
  }
}

INCASM("asm/enemy/cannon_hopper_c.inc");

void CannonHopper_Init(struct Enemy* p);
void CannonHopper_Update(struct Enemy* p);
void CannonHopper_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCannonHopperRoutine = {
    [ENTITY_INIT] =      (void*)CannonHopper_Init,
    [ENTITY_UPDATE] =    (void*)CannonHopper_Update,
    [ENTITY_DIE] =       (void*)CannonHopper_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// 0x0836A288
static const struct Collision sCollisions[14] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(24), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(34), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(34), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(40), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(40), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
};

void FUN_080978e4(struct Enemy* p);
void FUN_08097904(struct Enemy* p);
void FUN_080978e0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_080978e4,
    FUN_08097904,
    FUN_08097904,
    FUN_080978e4,
    FUN_080978e4,
    FUN_080978e0,
};
// clang-format on

void FUN_08097924(struct Enemy* p);
void cannonHopper_08097a14(struct Enemy* p);
void cannonHopper_08097af8(struct Enemy* p);
void FUN_08097cc8(struct Enemy* p);
void cannonHopper_08097d10(struct Enemy* p);
void FUN_0809860c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_08097924,
    cannonHopper_08097a14,
    cannonHopper_08097af8,
    FUN_08097cc8,
    cannonHopper_08097d10,
    FUN_0809860c,
};
// clang-format on

// --------------------------------------------

void FUN_08097f3c(struct Enemy* p);
void FUN_08098110(struct Enemy* p);
void FUN_08098414(struct Enemy* p);
void FUN_0809860c(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_08097f3c,
    FUN_08098110,
    FUN_08098414,
    FUN_0809860c,
};

// --------------------------------------------

// 0x0836A418
static const u8 sInitModes[4] = {0, 0, 0, 0};
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(19)};

// 0x0836A424
static const u8 u8_ARRAY_0836a424[14] = {
    0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x16, 0x2B, 0x40, 0x55, 0x6A,
};

// 0x0836A434
static const s32 s32_ARRAY_0836a434[10] = {
    -PIXEL(8), -PIXEL(6), PIXEL(0), PIXEL(6), PIXEL(8), -PIXEL(18), -PIXEL(18), -PIXEL(20), -PIXEL(18), -PIXEL(18),
};
