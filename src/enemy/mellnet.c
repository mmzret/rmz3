#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "zero.h"

static const struct Collision sCollisions[4];
static const motion_t sDiveMotions[3][2];


void FUN_0807dd24(struct Enemy* p);

INCASM("asm/enemy/mellnet_a.inc");

void FUN_0807dd24(struct Enemy* p) {
  s32 onLeft, dx, dy, dist;
  s16 v;
  switch ((p->s).mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      onLeft = 0;
      if ((p->s).coord.x < (pZero2->s).coord.x) {
        onLeft = 1;
      }
      if (onLeft) {
        (p->s).flags |= X_FLIP;
      } else {
        (p->s).flags &= ~X_FLIP;
      }
      v = onLeft;
      ((p->s).spr).xflip = v;
      ((p->s).spr).oam.xflip = v;
      dx = (pZero2->s).coord.x - (p->s).coord.x;
      dy = (pZero2->s).coord.y - PIXEL(24);
      dy -= (p->s).coord.y;
      dist = (dx >> 8) * (dx >> 8);
      dist += (dy >> 8) * (dy >> 8);
      dist = Sqrt(dist) << 8;
      dx = (dx << 8) / dist;
      dy = (dy << 8) / dist;
      {
        s32 sx = dx << 2;
        s32 sy = dy << 2;
        (p->s).d.x = sx;
        (p->s).d.y = sy;
      }
      dist = (p->s).motion.cmdIdx;
      GotoMotion(&p->s, sDiveMotions[0][((p->s).flags & 0x10) ? 1 : 0], dist, 3);
      (p->s).work[2] = 3;
      (p->s).mode[2]++;
      goto tick;
    }
    case 2: {
      dist = (p->s).motion.cmdIdx;
      GotoMotion(&p->s, sDiveMotions[1][((p->s).flags & 0x10) ? 1 : 0], dist, 3);
      (p->s).work[2] = 0xF;
    }
      (p->s).mode[2]++;
      // fallthrough
    case 1:
    case 3:
    tick:
      UpdateEntityAnim(&p->s);
      if (--(p->s).work[2] == 0) {
        (p->s).mode[2]++;
      }
      break;
    case 4: {
      dist = (p->s).motion.cmdIdx;
      GotoMotion(&p->s, sDiveMotions[2][((p->s).flags & 0x10) ? 1 : 0], dist, 3);
      (p->s).work[2] = 3;
    }
      (p->s).mode[2]++;
      // fallthrough
    case 5:
      UpdateEntityAnim(&p->s);
      if (--(p->s).work[2] == 0) {
        (p->s).mode[1] = 5;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/enemy/mellnet_b.inc");

void Mellnet_Init(struct Enemy* p);
void Mellnet_Update(struct Enemy* p);
void Mellnet_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMellnetRoutine = {
    [ENTITY_INIT] =      (void*)Mellnet_Init,
    [ENTITY_UPDATE] =    (void*)Mellnet_Update,
    [ENTITY_DIE] =       (void*)Mellnet_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807d990(struct Enemy* p);
void FUN_0807d994(struct Enemy* p);
void FUN_0807d9b4(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    FUN_0807d9b4,
    FUN_0807d994,
    FUN_0807d994,
    FUN_0807d994,
    FUN_0807d994,
    FUN_0807d994,
    FUN_0807d990,
};
// clang-format on

void FUN_0807da10(struct Enemy* p);
void FUN_0807da34(struct Enemy* p);
void FUN_0807daa0(struct Enemy* p);
void FUN_0807db9c(struct Enemy* p);
void FUN_0807dd24(struct Enemy* p);
void FUN_0807dee8(struct Enemy* p);
void FUN_0807e178(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0807da10,
    FUN_0807da34,
    FUN_0807daa0,
    FUN_0807db9c,
    FUN_0807dd24,
    FUN_0807dee8,
    FUN_0807e178,
};
// clang-format on

void FUN_0807dfa4(struct Enemy* p);
void FUN_0807e060(struct Enemy* p);
void FUN_0807e178(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_0807dfa4,
    FUN_0807e060,
    FUN_0807e178,
};

// --------------------------------------------

// 0x08367cdc
static const struct Collision sCollisions[4] = {
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
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(24)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 sInitModes[2] = {1, 2};

// clang-format off
static const motion_t sMotions[4] = {
    MOTION(SM071_MELLNET, 0x00),
    MOTION(SM071_MELLNET, 0x0A),
    MOTION(SM071_MELLNET, 0x00),
    MOTION(SM071_MELLNET, 0x0A),
};

static const motion_t sDiveMotions[3][2] = {
    {MOTION(SM071_MELLNET, 0x01), MOTION(SM071_MELLNET, 0x0B)},
    {MOTION(SM071_MELLNET, 0x02), MOTION(SM071_MELLNET, 0x0C)},
    {MOTION(SM071_MELLNET, 0x03), MOTION(SM071_MELLNET, 0x0D)},
};

static const motion_t sMotions2[6] = {
    MOTION(SM071_MELLNET, 0x04),
    MOTION(SM071_MELLNET, 0x0E),
    MOTION(SM071_MELLNET, 0x07),
    MOTION(SM071_MELLNET, 0x08),
    MOTION(SM071_MELLNET, 0x09),
    MOTION(SM071_MELLNET, 0x06),
};

static const motion_t sMotions3[2] = {
    MOTION(SM071_MELLNET, 0x00),
    MOTION(SM071_MELLNET, 0x0A),
};
// clang-format on
