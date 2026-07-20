#include "collision.h"
#include "entity.h"
#include "global.h"
#include "minigame.h"
#include "zero.h"

static const struct Collision sCollisions[2];
static const u8 sInitModes[4];

static void PhantomMini_Init(Player* p);
static void PhantomMini_Update(struct Entity* p);
static void PhantomMini_Die(struct Entity* p);

// clang-format off
const ZeroRoutine gPhantomMiniRoutine = {
  [ENTITY_INIT] =       (void*)PhantomMini_Init,
  [ENTITY_UPDATE] =     (void*)PhantomMini_Update,
  [ENTITY_DIE]  =       (void*)PhantomMini_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on

s32 FUN_080349a8(struct Entity* p) {
  if ((p->coord).x < PIXEL(2400) || (p->coord).x > PIXEL(2880)) {
    return PIXEL(1760);
  }
  return FUN_08009f6c((p->coord).x, (p->coord).y);
}

struct Entity* CreatePlayerPhantom(void* q, s32 x, s32 y) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_PHANTOM);
    p->work[0] = 0;
    p->coord.x = x, p->coord.y = y;
    p->unk_28 = q;
  }
  return p;
}

static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  struct MinigameState* s;
  struct Zero* z = (struct Zero*)body->parent;
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    PlaySound(SE_NOT_ALLOWED);
    PlaySound(SE_PHANTOM_DAMAGE);

    s = (struct MinigameState*)(z->s).unk_28;
    if (s->unk_d5 != 0) s->unk_d5--;
    PlaySound(SE_ZERO_STUN);
  }
}

static void PhantomMini_Init(Player* z) {
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = sInitModes[(z->s).work[0]];

  (z->s).flags |= FLIPABLE;
  (z->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(z);
  SetSpriteTableDynamic(z);
  INIT_BODY(z, &sCollisions[0], 6, onCollision);
  (z->s).unk_coord.y = (z->s).coord.y;
  (z->s).work[3] = 0;
  PhantomMini_Update((void*)z);
}

// --------------------------------------------

static void FUN_08034b28(struct Entity* p);
static void nop_08034b24(void* _ UNUSED);

void phantom_08034b4c(struct Zero* z);
void FUN_08034d40(struct Zero* z);
void phantom_08034dc0(struct Zero* z);
void FUN_08034e50(struct Zero* z);

static void PhantomMini_Update(struct Entity* p) {
  s32 max_y;
  static const ZeroFunc sUpdates1[4] = {
      (void*)FUN_08034b28,
      (void*)nop_08034b24,
      (void*)nop_08034b24,
      (void*)nop_08034b24,
  };
  static const ZeroFunc sUpdates2[4] = {
      (void*)phantom_08034b4c,
      (void*)FUN_08034d40,
      (void*)phantom_08034dc0,
      (void*)FUN_08034e50,
  };

  struct MinigameState* q = (struct MinigameState*)p->unk_28;
  p->coord.x += q->unk_14;
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);

  max_y = p->unk_coord.y + PIXEL(240);
  if (p->coord.y > max_y) {
    p->coord.y = max_y;
  }
}

static void PhantomMini_Die(struct Entity* p) { SET_PLAYER_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static void nop_08034b24(void* _) {}

static void FUN_08034b28(struct Entity* p) {
  struct MinigameState* q = (struct MinigameState*)p->unk_28;
  if ((q->unk_d6 != 0) && (q->unk_00[1] != 3)) {
    p->mode[1] = 3, p->mode[2] = 0;
  }
}

INCASM("asm/player/phantom.inc");

// --------------------------------------------

// 0x0835ea88
static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(36)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(36)},
    },
};

// --------------------------------------------

static const u8 sInitModes[4] = {0, 0, 0, 0};
