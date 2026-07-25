#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "metatile.h"
#include "story.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  Entity* elfx;          // 0xB4, Element Effect
  u8 unk_b8[12];         // 0xB8
} PantheonFist;
static_assert(sizeof(PantheonFist) == sizeof(struct Enemy));

static void (*const sUpdates1[9])(PantheonFist*);
static void (*const sUpdates2[9])(PantheonFist*);

// 0x08095124
bool8 FUN_08095124(PantheonFist* p) {
  if (p->mode[1] != 7) {
    Entity* v = p->elfx;
    if (v == NULL) {
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
            if ((p->body.status & (BODY_STATUS_RECOILED | BODY_STATUS_WHITE)) ==
                (BODY_STATUS_RECOILED | BODY_STATUS_WHITE)) {
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

INCASM("asm/enemy/pantheon_fist_a_s1.inc");

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

INCASM("asm/enemy/pantheon_fist_a_s2.inc");

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

INCASM("asm/enemy/pantheon_fist_a_s3.inc");

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

static const Coords32 sElementCoord;

void FUN_080951b4(PantheonFist* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    if (((p->body).status & BODY_STATUS_RECOILED)) {
      p->mode[1] = 7, p->mode[2] = 0;
    } else {
      p->elfx = (void*)ApplyElementEffect(0, (Object*)p, &sElementCoord);
      if (p->elfx != NULL) {
        p->mode[1] = 0, p->mode[2] = 0;
      }
    }
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
