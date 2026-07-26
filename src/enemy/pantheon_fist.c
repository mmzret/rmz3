#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"

struct PantheonFistObject {
  struct Entity s;
  struct Body body;
  // props (16bytes, offset: 0xB4..)
  struct VFX* elementEffect;
  u8 unk_004[12];
};

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
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_FIST);
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    p->buffer[5] = a2;
  }
  return p;
}

bool8 FUN_08094fa8(struct Enemy* p, s32 d) {
  s32 x = (p->s).coord.x;
  x -= PIXEL(14);
  if (d > 0) {
    x += PIXEL(28);
  }
  if (FUN_080098a4(x, (p->s).coord.y + PIXEL(10)) != 0) {
    return TRUE;
  }
  return FALSE;
}

bool8 FUN_08094fe0(struct Enemy* p, s32 dy) {
  if (dy > 0) {
    s32 diff;
    (p->s).coord.y += dy;
    diff = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) - (p->s).coord.y;
    if (diff <= 0x7ff) {
      (p->s).coord.y = (p->s).coord.y + diff;
      return TRUE;
    }
  }
  return FALSE;
}

u32 FUN_08095014(struct Enemy* p, s32 d) {
  if (d != 0) {
    if (d < 0) {
      if (FUN_080098a4((p->s).coord.x - PIXEL(14), (p->s).coord.y - PIXEL(10)) != 0) {
        return 1;
      }
    } else {
      if (FUN_080098a4((p->s).coord.x + PIXEL(14), (p->s).coord.y - PIXEL(10)) != 0) {
        return 2;
      }
    }
    (p->s).coord.x += d;
  }
  return 0;
}

u32 FUN_08095074(struct Enemy* p, s32 dx) {
  if (dx == 0) {
    return 0;
  }
  if (dx < 0) {
    if (FUN_080098a4((p->s).coord.x - 0xE00, (p->s).coord.y - 0xA00) != 0) {
      return 1;
    }
  } else {
    if (FUN_080098a4((p->s).coord.x + 0xE00, (p->s).coord.y - 0xA00) != 0) {
      return 2;
    }
  }
  return 0;
}

void nop_080950cc(struct Enemy* p) {}

bool8 FUN_080950d0(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 2;
    } else {
      (p->s).mode[1] = 0;
    }
    return TRUE;
  }
  return FALSE;
}

bool8 FUN_08095124(struct Enemy* p) {
  if ((p->s).mode[1] != 7) {
    s32 v = *(s32*)&p->buffer[0];
    if (v == 0) {
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
            if (((p->body).status & 0x00020001) == 0x00020001) {
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
  }
  return FALSE;
}

void FUN_080951b4(struct PantheonFistObject* p) {
  if (p->elementEffect == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    if (((p->body).status & BODY_STATUS_RECOILED)) {
      (p->s).mode[1] = 7;
      (p->s).mode[2] = 0;
    } else {
      p->elementEffect = ApplyElementEffect(0, &p->s, &sElementCoord);
      if (p->elementEffect != NULL) {
        (p->s).mode[1] = 0;
        (p->s).mode[2] = 0;
      }
    }
  }
}

INCASM("asm/enemy/pantheon_fist_a.inc");

void PantheonFist_Update(PantheonFist* p) {
  if (!FUN_080950d0(p)) {
    FUN_080951b4((struct PantheonFistObject*)p);
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
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    SetDDP(&p->body, &sCollisions[1]);
    if (!IsFrozen((struct Entity*)p)) {
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
