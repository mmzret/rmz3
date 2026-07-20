#include "collision.h"
#include "entity.h"
#include "global.h"
#include "minigame.h"
#include "zero.h"

static const struct Collision sCollisions[3];
static const u8 sInitModes[4];

static void Leviathan_Init(Player* p);
static void Leviathan_Update(Player* p);
static void Leviathan_Die(struct Entity* p);

// clang-format off
const ZeroRoutine gLeviathanRoutine = {
  [ENTITY_INIT] =       (void*)Leviathan_Init,
  [ENTITY_UPDATE] =     (void*)Leviathan_Update,
  [ENTITY_DIE]  =       (void*)Leviathan_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on

bool8 FUN_08035e48(struct Entity* p) {
  if ((p->d).x >= 1) {
    (p->d).x -= 4;
    if ((p->d).x < 0) return TRUE;
  } else {
    (p->d).x += 4;
    if ((p->d).x > 0) return TRUE;
  }
  return FALSE;
}

void FUN_08035e6c(struct Zero* p) {
  s32 dx, x, y;
  x = (p->s).unk_coord.x;
  y = (p->s).unk_coord.y;
  if (x > y) {
    dx = (y - x) * 12;
    if (dx < 0) {
      dx += 0xFF;
    }
    (p->s).unk_coord.x += (dx >> 8);
    if ((p->s).unk_coord.x < y) {
      (p->s).unk_coord.x = y;
    }
  }
}

struct Entity* CreatePlayerLeviathan(void* q, s32 x, s32 y) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_LEVIATHAN);
    p->work[0] = 0;
    p->coord.x = x, p->coord.y = y;
    p->unk_28 = q;
  }
  return p;
}

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

static void Leviathan_Init(Player* p) {
  SET_PLAYER_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];

  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  (p->s).spr.xflip = TRUE;
  (p->s).spr.oam.xflip = TRUE;
  (p->s).flags |= X_FLIP;
  INIT_BODY(p, &sCollisions[0], 6, onCollision);
  (p->mg).leviathan.x = (p->s).coord.x;
  (p->s).unk_coord.y = (p->s).coord.y;
  (p->s).work[3] = 0;
  (p->s).d.x = 0, (p->s).d.y = 0;
  Leviathan_Update(p);
}

static void leviathanMode0Pre(struct Entity* p);
static void leviathanMode1Pre(struct Entity* p);
static void nop_08036044(void* _ UNUSED);

void leviathanMode0(struct Zero* z);
void leviathanMode1(struct Zero* z);
void leviathanMode2(struct Zero* z);

static void Leviathan_Update(Player* p) {
  static const ZeroFunc sUpdates1[3] = {
      (void*)leviathanMode0Pre,
      (void*)leviathanMode1Pre,
      (void*)nop_08036044,
  };  // 0x0835ec00
  static const ZeroFunc sUpdates2[3] = {
      (void*)leviathanMode0,
      (void*)leviathanMode1,
      (void*)leviathanMode2,
  };  // 0x0835ec0c

  struct MinigameState* s = (struct MinigameState*)(p->s).unk_28;
  if (s->unk_31 == 0) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }

  {
    s32 min_x, max_x;
    min_x = (p->mg).leviathan.x - PIXEL(108);
    if ((p->s).coord.x <= min_x) {
      (p->s).coord.x = min_x, (p->s).d.x = 0;
    }
    max_x = (p->mg).leviathan.x + PIXEL(108);
    if ((p->s).coord.x >= max_x) {
      (p->s).coord.x = max_x, (p->s).d.x = 0;
    }
  }
}

static void Leviathan_Die(struct Entity* p) { SET_PLAYER_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

// 0x08035FF8
static void leviathanMode0Pre(struct Entity* p) {
  struct MinigameState* s = (struct MinigameState*)p->unk_28;
  if (s->unk_10 & 0x30) {
    p->mode[1] = 1, p->mode[2] = 0;
  }
  if (s->unk_12 & (1 << 1)) {
    p->mode[1] = 2, p->mode[2] = 0;
  }
}

// 0x08036028
static void leviathanMode1Pre(struct Entity* p) {
  struct MinigameState* s = (struct MinigameState*)p->unk_28;
  if (s->unk_12 & (1 << 1)) {
    p->mode[1] = 2, p->mode[2] = 0;
  }
}

static void nop_08036044(void* _) {}

INCASM("asm/player/leviathan.inc");

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0A00, 0x1600, 0x0C00, 0x0900},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0A00, 0x1F00, 0x0800, 0x1B00},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
