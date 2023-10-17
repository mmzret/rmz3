#include "collision.h"
#include "global.h"
#include "solid.h"
#include "story.h"

// リコイルロッドで押せる棺桶みたいなコンテナ

static const u16 u16_ARRAY_083716b8[2];

static const struct Collision sCollision;
static const struct Rect sSize;

static void VolcanoCoffin_Init(struct Solid* p);
void VolcanoCoffin_Update(struct Solid* p);
void VolcanoCoffin_Die(struct Solid* p);

// clang-format off
const SolidRoutine gVolcanoCoffinRoutine = {
    [ENTITY_INIT] =      VolcanoCoffin_Init,
    [ENTITY_UPDATE] =    VolcanoCoffin_Update,
    [ENTITY_DIE] =       VolcanoCoffin_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateVolcanoCoffin(u8 n, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_VOLCANO_COFFIN);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = n;
    (p->s).coord.x = x;
    (p->s).unk_coord.y = x;
    (p->s).coord.y = y;
  }
  return p;
}

// --------------------------------------------

static void VolcanoCoffin_Init(struct Solid* p) {
  struct Coord* d;
  s8 px;

  (p->s).flags |= FLIPABLE;
  px = gCurStory.s.counts[u16_ARRAY_083716b8[(p->s).work[0]]];
  (p->s).coord.x += PIXEL(px);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  (p->s).coord.y -= (PIXEL(32) - 1);
  d = &(p->s).d;
  d->x = d->y = 0;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  VolcanoCoffin_Update(p);
}

// --------------------------------------------

INCASM("asm/solid/volcano_coffin.inc");

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  LAYER(RECOIL_PUSHABLE),
  hitzone : 0xFF,
  remaining : 0,
  range : {PIXEL(0), PIXEL(20), PIXEL(80), PIXEL(40)},
};

static const struct Rect sSize = {PIXEL(0), PIXEL(18), PIXEL(80), PIXEL(36)};

static const u16 u16_ARRAY_083716b8[2] = {70, 71};
