#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"

bool8 FUN_0807d724(struct Enemy* p);
bool8 FUN_0807d780(struct Enemy* p);
void FUN_0807d810(struct Enemy* p);


static const struct Collision sCollisions[4];
static const EnemyFunc sDeads[3];
static const Coords32 sElementCoord;
static const motion_t sMotions[18];
static const EnemyFunc sUpdates1[7];
static const EnemyFunc sUpdates2[7];
void FUN_0807d6c0(s32 x, s32 y, u8 a2) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_MELLNET);
    (p->s).work[0] = 1;
    (p->s).work[2] = a2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
}

void FUN_0807d720(struct Enemy* p) {}

bool8 FUN_0807d724(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 2;
    } else {
      (p->s).mode[1] = 0;
    }
    Mellnet_Die(p);
    return TRUE;
  }
  return FALSE;
}

bool8 FUN_0807d780(struct Enemy* p) {
  if ((p->s).mode[1] != 6 && *(struct VFX**)&p->buffer[0] == NULL) {
    switch ((p->s).mode[3]) {
      case 0:
        if (IsFrozen(&p->s)) {
          (sUpdates1[(p->s).mode[1]])(p);
          (sUpdates2[(p->s).mode[1]])(p);
          (p->s).mode[3]++;
          UpdateMotionGraphic(&p->s);
          return TRUE;
        }
        break;
      case 1:
        if (IsFrozen(&p->s)) {
          if (((p->body).status & 0x20001) == 0x20001) {
            (p->s).mode[3] = 0;
          } else {
            return TRUE;
          }
        } else {
          (p->s).mode[3] = 0;
        }
        break;
    }
  }
  return FALSE;
}

void FUN_0807d810(struct Enemy* p) {
  if (*(struct VFX**)&p->buffer[0] == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    if (((p->body).status & BODY_STATUS_RECOILED)) {
      (p->s).mode[1] = 6;
      (p->s).mode[2] = 0;
    } else {
      struct VFX* e = ApplyElementEffect(0, &p->s, &sElementCoord);
      *(struct VFX**)&p->buffer[0] = e;
      if (e != NULL) {
        (p->s).mode[1] = 0;
        (p->s).mode[2] = 0;
      }
    }
  }
}

INCASM("asm/enemy/mellnet_a.inc");

void Mellnet_Update(struct Enemy* p) {
  if (!FUN_0807d724(p)) {
    FUN_0807d810(p);
    if (!FUN_0807d780(p)) {
      (sUpdates1[(p->s).mode[1]])(p);
      (sUpdates2[(p->s).mode[1]])(p);
    }
  }
}

void Mellnet_Die(struct Enemy* p) {
  if ((p->s).work[0] == 0 && IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    (sDeads[(p->s).mode[1]])(p);
  }
}

void FUN_0807d990(struct Enemy* p) {}

void FUN_0807d994(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 6;
    (p->s).mode[2] = 0;
  }
}

void FUN_0807d9b4(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    SetDDP(&p->body, &sCollisions[1]);
    *slot = NULL;
    if (!IsFrozen(&p->s)) {
      (p->s).mode[1] = 4;
      (p->s).mode[2] = 0;
    }
  }
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 6;
    (p->s).mode[2] = 0;
  }
}

void FUN_0807da10(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    (p->s).mode[2]++;
  }
}

void FUN_0807da34(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x1e;
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion(&p->s, sMotions[((p->s).flags & 0x10) ? 1 : 0]);
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      if (--(p->s).work[2] == 0) {
        (p->s).mode[1] = 3;
        (p->s).mode[2] = 0;
      }
      UpdateMotionGraphic(&p->s);
  }
}

INCASM("asm/enemy/mellnet_b.inc");

void Mellnet_Init(struct Enemy* p);
void Mellnet_Update(struct Enemy* p);
void Mellnet_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMellnetRoutine = {
    [ENTITY_INIT] =      Mellnet_Init,
    [ENTITY_UPDATE] =    Mellnet_Update,
    [ENTITY_DIE] =       Mellnet_Die,
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
static const motion_t sMotions[18] = {
    MOTION(SM071_MELLNET, 0x00),
    MOTION(SM071_MELLNET, 0x0A),
    MOTION(SM071_MELLNET, 0x00),
    MOTION(SM071_MELLNET, 0x0A),
    MOTION(SM071_MELLNET, 0x01),
    MOTION(SM071_MELLNET, 0x0B),
    MOTION(SM071_MELLNET, 0x02),
    MOTION(SM071_MELLNET, 0x0C),
    MOTION(SM071_MELLNET, 0x03),
    MOTION(SM071_MELLNET, 0x0D),
    MOTION(SM071_MELLNET, 0x04),
    MOTION(SM071_MELLNET, 0x0E),
    MOTION(SM071_MELLNET, 0x07),
    MOTION(SM071_MELLNET, 0x08),
    MOTION(SM071_MELLNET, 0x09),
    MOTION(SM071_MELLNET, 0x06),
    MOTION(SM071_MELLNET, 0x00),
    MOTION(SM071_MELLNET, 0x0A),
};
// clang-format on
