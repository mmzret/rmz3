#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[8];         // 0xB4
  struct Entity* elfx;  // 0xBC, Element Effect
  u8 unk_c0[2];         // 0xC0
  u8 unk_c2;
  u8 unk_c3;
} TopGabyoall;
static_assert(sizeof(TopGabyoall) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
static const Coords32 sElementCoords[];

static void Enemy14_Init(struct Enemy* p);
static void Enemy14_Update(TopGabyoall* p);
void Enemy14_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gTopGabyoallRoutine = {
    [ENTITY_INIT] =      (void*)Enemy14_Init,
    [ENTITY_UPDATE] =    (void*)Enemy14_Update,
    [ENTITY_DIE] =       (void*)Enemy14_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateTopGabyoall(Coords32* c, u8 r1, u8 r2) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_TOP_GABYOALL);
    p->work[0] = r1;
    p->work[1] = r2;
    p->coord = *c;
    return p;
  } else {
    return NULL;
  }
}

// --------------------------------------------

void FUN_0806f5d0(struct Enemy* p);
void FUN_0806f6cc(struct Enemy* p);
void FUN_0806f7dc(struct Enemy* p);
void FUN_0806f89c(struct Enemy* p);

static void Enemy14_Init(struct Enemy* p) {
  static const EnemyFunc sInitializers[4] = {
      (EnemyFunc)FUN_0806f5d0,
      (EnemyFunc)FUN_0806f6cc,
      (EnemyFunc)FUN_0806f7dc,
      (EnemyFunc)FUN_0806f89c,
  };
  (sInitializers[(p->s).work[0]])((void*)p);
}

void FUN_0806f964(struct Enemy* p);
void FUN_0806fb08(struct Enemy* p);
void FUN_0806fc78(struct Enemy* p);
void FUN_0806fe38(struct Enemy* p);

static const EntityFunc sUpdates[4] = {
    (void*)FUN_0806f964,
    (void*)FUN_0806fb08,
    (void*)FUN_0806fc78,
    (void*)FUN_0806fe38,
};  // 0x08366960

static void Enemy14_Update(TopGabyoall* p) {
  if (p->work[1] == 2) {
    if ((pZero2 != NULL) && ((pZero2->input).raw & INPUT_DISABLED)) {
      return;
    }
  } else if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (p->unk_c2) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    return;
  }

  if ((MOTION_VALUE(p) != MOTION(SM021_TOP_GABYOALL, 3)) && ((p->body).status & BODY_STATUS_WHITE)) {
    if (p->elfx == NULL) {
      p->elfx = (void*)ApplyElementEffect(0, (Object*)p, &sElementCoords[p->work[0]]);
      if (p->elfx != NULL) {
        SetDDP(&p->body, &sCollisions[1 + (p->work[0] & 2)]);
      }
    }
  }

  if (p->elfx != NULL) {
    SetSpriteAnimation(p, MOTION(SM021_TOP_GABYOALL, 0));
    UpdateSpriteAnimation(p);
    if (IsDead(p->elfx)) {
      p->elfx = NULL;
      SetDDP(&p->body, &sCollisions[p->work[0] & 2]);
      p->mode[1] = 0, p->mode[2] = 0;
    }
    return;
  }

  if (!IsFrozen(p)) (sUpdates[p->work[0]])((void*)p);
}

void Enemy14_Die(struct Enemy* p) {
  CreateSmoke(1, &(p->s).coord);
  PlaySound(0x2a);
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/enemy/top_gabyoall_a.inc");

// 0x08070000
void FUN_08070000(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & (BODY_STATUS_WHITE | BODY_STATUS_B3)) {
    struct Entity* p = (struct Entity*)body->parent;
    if (p->mode[1] != 2) {
      p->mode[1] = 2, p->mode[2] = 0;
    } else {
      p->work[2] = 64;
    }
  }
}

// --------------------------------------------

// 0x08366970
static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : NO_DAMAGE,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : NO_DAMAGE,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
};

static const Coords32 sElementCoords[4] = {
    {PIXEL(0), -PIXEL(8)},
    {PIXEL(0), -PIXEL(8)},
    {PIXEL(0), -PIXEL(8)},
    {PIXEL(0), PIXEL(8)},
};
