#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 x_b4;              // 0xB4
  u8 unk_b8;             // 0xB8
  u8 unk_b9;             // 0xB9
  u8 unk_ba;             // 0xBA
  u8 unk_bb;             // 0xBB
  void* elfx;            // 0xBC, Element FX
  u8 unk_c0[4];          // 0xC0
} PantheonBomber;
static_assert(sizeof(PantheonBomber) == sizeof(struct Enemy));

static const struct Collision sCollisions[5];
static const Coords32 sElementCoord;

static void PantheonBomber_Init(PantheonBomber* p);
static void PantheonBomber_Update(PantheonBomber* p);
void PantheonBomber_Die(PantheonBomber* p);

// clang-format off
const EnemyRoutine gPantheonBomberRoutine = {
    [ENTITY_INIT] =      (void*)PantheonBomber_Init,
    [ENTITY_UPDATE] =    (void*)PantheonBomber_Update,
    [ENTITY_DIE] =       (void*)PantheonBomber_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

PantheonBomber* Unused_CreatePantheonBomber(Coords32* c, u8 mode) {
  PantheonBomber* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_BOMBER);
    p->coord = *c;
    p->work[0] = mode;
  }
  return p;
}

static void PantheonBomber_OnCollision(struct Body* body, Coords32* c, Coords32* _);

static void PantheonBomber_Init(PantheonBomber* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (FLAG(gSystemSavedata.flags, MOD_P_BOMBER) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 12);
  } else {
    _INIT_BODY(p, sCollisions, 8);
  }
  SET_BODY_INTERSECT_HANDLER(p, PantheonBomber_OnCollision);
  p->x_b4 = (p->coord).x;
  p->d = p->coord;
  p->unk_b8 = 0;
  p->elfx = NULL;
  p->unk_b9 = 0;
  (p->coord).x -= PIXEL(8);
  (p->coord).y += PIXEL(8);
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  if (IsFrozen(p)) {
    SetSpriteAnimation(p, MOTION(SM105_PANTHEON_BOMBER, 3));
    UpdateSpriteAnimation(p);
  }
  p->unk_ba = 0;
  PantheonBomber_Update(p);
}

static bool8 nop_08086338(PantheonBomber* p);
static bool8 nop_080863a0(PantheonBomber* p);
static bool8 nop_08086414(PantheonBomber* p);
static bool8 nop_080865d0(PantheonBomber* p);
static bool8 nop_080865f8(PantheonBomber* p);
static bool8 nop_08086600(PantheonBomber* p);

static void pantheon_bomber_0808633c(PantheonBomber* p);
void pantheon_bomber_080863a4(PantheonBomber* p);
void pantheon_bomber_08086418(PantheonBomber* p);
static void FUN_080865d4(PantheonBomber* p);
static void nop_080865fc(PantheonBomber* p);
static void FUN_08086604(PantheonBomber* p);

static bool8 pBomber_08086628(PantheonBomber* p);

static void PantheonBomber_Update(PantheonBomber* p) {
  // clang-format off
  static bool8 (*const sUpdates1[6])(PantheonBomber*) = {
      nop_08086338,
      nop_080863a0,
      nop_08086414,
      nop_080865d0,
      nop_080865f8,
      nop_08086600,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[6])(PantheonBomber*) = {
      pantheon_bomber_0808633c,
      pantheon_bomber_080863a4,
      pantheon_bomber_08086418,
      FUN_080865d4,
      nop_080865fc,
      FUN_08086604,
  };
  // clang-format on

  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    PantheonBomber_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])(p);
  pBomber_08086628(p);

  if (p->elfx == NULL) {
    if (IsFrozen(p)) return;
    if (p->elfx == NULL) goto dispatch2;
  }
  if (isKilled(p->elfx)) {
    SetDDP(&p->body, &sCollisions[1]);
    p->elfx = NULL;
  } else {
    SetDDP(&p->body, &sCollisions[2]);
  }
  return;

dispatch2:
  (sUpdates2[p->mode[1]])(p);
}

INCASM("asm/enemy/pantheon_bomber_b.inc");

static bool8 nop_08086338(PantheonBomber* p) { return TRUE; }

static void pantheon_bomber_0808633c(PantheonBomber* p) {
  switch (p->mode[2]) {
    case 0: {
      GotoSpriteAnimation(p, MOTION(SM105_PANTHEON_BOMBER, 4), 2, 1);
      SetDDP(&p->body, &sCollisions[0]);
      p->unk_b9 = 0;
      p->work[2] = 48;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (p->work[2] == 0 || --p->work[2] == 0) {
        p->mode[1] = 2, p->mode[2] = 0;
      }
      break;
    }
  }
}

static bool8 nop_080863a0(PantheonBomber* p) { return TRUE; }

INCASM("asm/enemy/pantheon_bomber_c.inc");

static bool8 nop_08086414(PantheonBomber* p) { return TRUE; }

INCASM("asm/enemy/pantheon_bomber_d.inc");

static bool8 nop_080865d0(PantheonBomber* p) { return TRUE; }

static void FUN_080865d4(PantheonBomber* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
}

static bool8 nop_080865f8(PantheonBomber* p) { return TRUE; }

static void nop_080865fc(PantheonBomber* p) {}

static bool8 nop_08086600(PantheonBomber* p) { return TRUE; }

static void FUN_08086604(PantheonBomber* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
}

static bool8 pBomber_08086628(PantheonBomber* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    p->elfx = ApplyElementEffect(0, (void*)p, &sElementCoord);
  }
  return TRUE;
}

static void PantheonBomber_OnCollision(struct Body* body, Coords32* c, Coords32* _) {
  const u8 atktype = (body->enemy)->processing->atkType;
  if ((atktype == ATK_UNK3) || (atktype == ATK_UNK14) || (atktype == ATK_UNK15)) {
    PantheonBomber* p = (PantheonBomber*)body->parent;
    if ((p->body).status & BODY_STATUS_DEAD) {
      if ((p->coord).x < c->x) {
        p->unk_ba = 0xFF;
      } else {
        p->unk_ba = 0xFE;
      }
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};
