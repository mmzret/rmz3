#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "story.h"

// The element effect this fist is currently carrying, at 0xB4 -- the start of
// PantheonFist's buffer.
#define ELEMENT_EFFECT(p) (*(struct Entity**)&(p)->buffer[0])

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} PantheonFist;
static_assert(sizeof(PantheonFist) == sizeof(struct Enemy));


static const struct Collision sCollisions[6];
static void (*const sDeads[3])(PantheonFist*);
static const Coords32 sElementCoord;
static void (*const sUpdates1[9])(PantheonFist*);
static void (*const sUpdates2[9])(PantheonFist*);
struct Enemy* createPantheonFistInElevator(s32 x, s32 y, u8 a2) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_FIST);
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    p->buffer[5] = a2;
  }
  return p;
}

bool8 FUN_08094fa8(PantheonFist* p, s32 d) {
  s32 x = p->coord.x;
  x -= PIXEL(14);
  if (d > 0) {
    x += PIXEL(28);
  }
  if (FUN_080098a4(x, p->coord.y + PIXEL(10)) != 0) {
    return TRUE;
  }
  return FALSE;
}

bool8 FUN_08094fe0(PantheonFist* p, s32 dy) {
  if (dy > 0) {
    s32 diff;
    p->coord.y += dy;
    diff = FUN_08009f6c(p->coord.x, p->coord.y) - p->coord.y;
    if (diff <= 0x7ff) {
      p->coord.y = p->coord.y + diff;
      return TRUE;
    }
  }
  return FALSE;
}

u32 FUN_08095014(PantheonFist* p, s32 d) {
  if (d != 0) {
    if (d < 0) {
      if (FUN_080098a4(p->coord.x - PIXEL(14), p->coord.y - PIXEL(10)) != 0) {
        return 1;
      }
    } else {
      if (FUN_080098a4(p->coord.x + PIXEL(14), p->coord.y - PIXEL(10)) != 0) {
        return 2;
      }
    }
    p->coord.x += d;
  }
  return 0;
}

u32 FUN_08095074(PantheonFist* p, s32 dx) {
  if (dx == 0) {
    return 0;
  }
  if (dx < 0) {
    if (FUN_080098a4(p->coord.x - 0xE00, p->coord.y - 0xA00) != 0) {
      return 1;
    }
  } else {
    if (FUN_080098a4(p->coord.x + 0xE00, p->coord.y - 0xA00) != 0) {
      return 2;
    }
  }
  return 0;
}

void nop_080950cc(struct Enemy* p) {}

bool8 FUN_080950d0(PantheonFist* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else if ((p->body).status & BODY_STATUS_RECOILED) {
      p->mode[1] = 2;
    } else {
      p->mode[1] = 0;
    }
    return TRUE;
  }
  return FALSE;
}

bool8 FUN_08095124(PantheonFist* p) {
  if (p->mode[1] != 7) {
    struct Entity* fx = ELEMENT_EFFECT(p);
    if (fx == NULL) {
      switch (p->mode[3]) {
        case 0:
          if (IsFrozen(p)) {
            (sUpdates1[p->mode[1]])(p);
            (sUpdates2[p->mode[1]])(p);
            p->mode[3]++;
            UpdateSpriteAnimation(p);
            return TRUE;
          }
          break;
        case 1:
          if (IsFrozen(p)) {
            if (((p->body).status & 0x00020001) == 0x00020001) {
              p->mode[3] = 0;
            } else {
              return TRUE;
            }
          } else {
            p->mode[3] = 0;
          }
          break;
      }
    }
  }
  return FALSE;
}

void FUN_080951b4(PantheonFist* p) {
  if (ELEMENT_EFFECT(p) == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    if (((p->body).status & BODY_STATUS_RECOILED)) {
      p->mode[1] = 7;
      p->mode[2] = 0;
    } else {
      ELEMENT_EFFECT(p) = ApplyElementEffect(0, (Object*)p, &sElementCoord);
      if (ELEMENT_EFFECT(p) != NULL) {
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
    }
  }
}

INCASM("asm/enemy/pantheon_fist_a.inc");

void PantheonFist_Update(PantheonFist* p) {
  if (!FUN_080950d0(p)) {
    FUN_080951b4(p);
    if (!FUN_08095124(p)) {
      (sUpdates1[p->mode[1]])(p);
      (sUpdates2[p->mode[1]])(p);
    }
  }
}

void PantheonFist_Die(PantheonFist* p) {
  if (p->work[1] == 0 && IS_METTAUR) {
    u8 fl = p->flags & ~DISPLAY;
    p->flags = fl & ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    (sDeads[p->mode[1]])(p);
  }
}

void FUN_080953ac(PantheonFist* p) {}

void FUN_080953b0(PantheonFist* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    p->mode[1] = 7;
    p->mode[2] = 0;
  }
}

void FUN_080953d0(PantheonFist* p) {
  if (ELEMENT_EFFECT(p) == NULL || IsDead(ELEMENT_EFFECT(p))) {
    ELEMENT_EFFECT(p) = NULL;
    SetDDP(&p->body, &sCollisions[1]);
    if (!IsFrozen(p)) {
      p->mode[1] = 1;
      p->mode[2] = 0;
    }
  }
  if (((p->body).status & 0x00020001) == 0x00020001) {
    p->mode[1] = 7;
    p->mode[2] = 0;
  }
}

INCASM("asm/enemy/pantheon_fist_b.inc");

void PantheonFist_Init(PantheonFist* p);
void PantheonFist_Update(PantheonFist* p);
void PantheonFist_Die(PantheonFist* p);

// clang-format off
const EnemyRoutine gPantheonFistRoutine = {
    [ENTITY_INIT] =      (void*)PantheonFist_Init,
    [ENTITY_UPDATE] =    (void*)PantheonFist_Update,
    [ENTITY_DIE] =       (void*)PantheonFist_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080953ac(PantheonFist* p);
void FUN_080953b0(PantheonFist* p);
void FUN_080953d0(PantheonFist* p);

// clang-format off
static void (*const sUpdates1[9])(PantheonFist*) = {
    FUN_080953d0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953ac,
    FUN_080953b0,
};
// clang-format on

void FUN_0809542c(PantheonFist* p);
void FUN_080954a4(PantheonFist* p);
void FUN_08095578(PantheonFist* p);
void FUN_08095664(PantheonFist* p);
void FUN_08095778(PantheonFist* p);
void FUN_080957d4(PantheonFist* p);
void FUN_08095914(PantheonFist* p);
void FUN_0809596c(PantheonFist* p);
void FUN_08095ac4(PantheonFist* p);

// clang-format off
static void (*const sUpdates2[9])(PantheonFist*) = {
    FUN_0809542c,
    FUN_080954a4,
    FUN_08095578,
    FUN_08095664,
    FUN_08095778,
    FUN_080957d4,
    FUN_08095914,
    FUN_0809596c,
    FUN_08095ac4,
};
// clang-format on

void FUN_08095b70(PantheonFist* p);
void FUN_08095c20(PantheonFist* p);
void FUN_0809596c(PantheonFist* p);

static void (*const sDeads[3])(PantheonFist*) = {
    FUN_08095b70,
    FUN_08095c20,
    FUN_0809596c,
};

// --------------------------------------------

// 0x08369fd4
static const struct Collision sCollisions[6] = {
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
      damage : 3,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(4), -PIXEL(15), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(4), -PIXEL(15), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : BODY_NATURE_B2,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(22), -PIXEL(19), PIXEL(26), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(10), -PIXEL(13), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(4), -PIXEL(15), PIXEL(19), PIXEL(31)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(8)};
static const u8 sInitModes[2] = {2, 0};

// 0x0836a06e
static const motion_t sMotions[4] = {
    MOTION(SM212_PANTHEON_FIST, 9),
    MOTION(SM212_PANTHEON_FIST, 10),
    MOTION(SM212_PANTHEON_FIST, 11),
    MOTION(SM212_PANTHEON_FIST, 7),
};
