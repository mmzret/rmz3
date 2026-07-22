#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "physics.h"
#include "story.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 initX;             // 0xB4
  u8 unk_b8;             // 0xB8
  u8 unk_b9;             // 0xB9
  u8 unk_ba;             // 0xBA
  u8 unk_bb;             // 0xBB
  Entity* elfx;          // 0xBC
  u8 unk_c0[4];          // 0xC0
} Claveker;
static_assert(sizeof(Claveker) == sizeof(struct Enemy));

static const struct Collision sCollisions[3];
static const Coords32 sElementCoord;

static void Claveker_Init(Claveker* p);
static void Claveker_Update(Claveker* p);
void Claveker_Die(Claveker* p);

// clang-format off
const EnemyRoutine gClavekerRoutine = {
    [ENTITY_INIT] =      (void*)Claveker_Init,
    [ENTITY_UPDATE] =    (void*)Claveker_Update,
    [ENTITY_DIE] =       (void*)Claveker_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Claveker* Unused_CreateClaveker(Coords32* c, u8 n) {
  Claveker* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CLAVEKER);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

static void Claveker_OnCollision(struct Body* body, Coords32* c, Coords32* _);

static void Claveker_Init(Claveker* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_CLAVEKER) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, &sCollisions[1], 14);
  } else {
    _INIT_BODY(p, &sCollisions[1], 10);
  }
  SET_BODY_INTERSECT_HANDLER(p, Claveker_OnCollision);
  (p->coord).y = FUN_0800a134((p->coord).x, (p->coord).y);
  p->initX = (p->coord).x;
  p->unk_b8 = 0;
  p->elfx = NULL;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  if (IsFrozen(p)) {
    SetSpriteAnimation(p, MOTION(SM117_CLAVEKER, 0));
    UpdateSpriteAnimation(p);
  }
  p->unk_bb = 0;
  Claveker_Update(p);
}

static bool8 FUN_0808eb20(Claveker* p);
static bool8 FUN_0808ebb0(Claveker* p);
static bool8 FUN_0808effc(Claveker* p);
static bool8 FUN_0808f158(Claveker* p);
static bool8 FUN_0808f198(Claveker* p);
static bool8 FUN_0808f1a0(Claveker* p);

void FUN_0808eb24(Claveker* p);
void FUN_0808ebb4(Claveker* p);
void FUN_0808f000(Claveker* p);
static void FUN_0808f15c(Claveker* p);
static void FUN_0808f19c(Claveker* p);
static void FUN_0808f1a4(Claveker* p);

static bool8 FUN_0808f1e0(Claveker* p);

static void Claveker_Update(Claveker* p) {
  // clang-format off
  static bool8 (*const sUpdates1[6])(Claveker*) = {
      FUN_0808eb20,
      FUN_0808ebb0,
      FUN_0808effc,
      FUN_0808f158,
      FUN_0808f198,
      FUN_0808f1a0,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[6])(Claveker*) = {
      FUN_0808eb24,
      FUN_0808ebb4,
      FUN_0808f000,
      FUN_0808f15c,
      FUN_0808f19c,
      FUN_0808f1a4,
  };
  // clang-format on

  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Claveker_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])(p);
  FUN_0808f1e0(p);

  if (IsFrozen(p)) {
    u8 m = p->mode[1];
    if (m == 2) goto skip_reset;
    if (m == 3) goto skip_reset;
    if (m == 5) goto skip_reset;
    if (m == 4) goto skip_reset;
    p->mode[1] = 0, p->mode[2] = 0;
  skip_reset:;
  }
  if (p->elfx == NULL) {
    if (IsFrozen(p)) {
      p->unk_ba = p->mode[1];
      return;
    }
  }
  if (IsFrozen(p)) {
    p->mode[1] = 0, p->mode[2] = 0;
  }
  if (p->elfx == NULL) {
    goto dispatch2;
  }
  if (isKilled(p->elfx)) {
    SetDDP(&p->body, &sCollisions[1]);
    p->elfx = NULL;
    p->mode[1] = 0, p->mode[2] = 0;
    return;
  }
  SetDDP(&p->body, &sCollisions[2]);
  return;

dispatch2:
  (sUpdates2[p->mode[1]])(p);
}

INCASM("asm/enemy/claveker_b.inc");

static bool8 FUN_0808eb20(Claveker* p) { return TRUE; }

INCASM("asm/enemy/claveker_c.inc");

static bool8 FUN_0808ebb0(Claveker* p) { return TRUE; }

INCASM("asm/enemy/claveker_d.inc");

static bool8 FUN_0808effc(Claveker* p) { return TRUE; }

INCASM("asm/enemy/claveker_e.inc");

static bool8 FUN_0808f158(Claveker* p) { return TRUE; }

static void FUN_0808f15c(Claveker* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
  if (isKilled(p->elfx)) {
    p->elfx = NULL;
    p->mode[1] = 0, p->mode[2] = 0;
  }
}

static bool8 FUN_0808f198(Claveker* p) { return TRUE; }

static void FUN_0808f19c(Claveker* p) {}

static bool8 FUN_0808f1a0(Claveker* p) { return TRUE; }

static void FUN_0808f1a4(Claveker* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
  if (isKilled(p->elfx)) {
    p->elfx = NULL;
    p->mode[1] = 0, p->mode[2] = 0;
  }
}

static bool8 FUN_0808f1e0(Claveker* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    p->elfx = ApplyElementEffect(0, (void*)p, &sElementCoord);
    if (p->elfx != NULL) {
      if ((p->body).elemented == ELEMENT_THUNDER) {
        p->mode[1] = 3, p->mode[2] = 0;
      } else if ((p->body).elemented == ELEMENT_ICE) {
        p->mode[1] = 5, p->mode[2] = 0;
      }
    }
  }
  return TRUE;
}

static void Claveker_OnCollision(struct Body* body, Coords32* c, Coords32* _) {
  const u8 atktype = (body->enemy)->processing->atkType;
  if ((atktype == ATK_UNK3) || (atktype == ATK_UNK14) || (atktype == ATK_UNK15)) {
    Claveker* p = (Claveker*)body->parent;
    if ((p->body).status & BODY_STATUS_DEAD) {
      if ((p->coord).x < c->x) {
        p->unk_bb = 0xFF;
      } else {
        p->unk_bb = 0xFE;
      }
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(12)};
