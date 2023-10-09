#include "entity.h"
#include "global.h"
#include "solid.h"

// リコイルロッドで押せる棺桶みたいなコンテナ

static const struct Collision sCollision;
static const struct Rect sSize;

void VolcanoCoffin_Init(struct Solid* p);
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

INCASM("asm/solid/volcano_coffin.inc");

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 0,
  damage : 0,
  unk_04 : 0x00,
  element : 0x78,
  nature : 0x00,
  comboLv : 0x00,
  hitzone : 0xFF,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000000,
  range : {0x0000, 0x1400, 0x5000, 0x2800},
};

static const struct Rect sSize = {0x0, 0x1200, 0x5000, 0x2400};

const u16 u16_ARRAY_083716b8[2] = {0x46, 0x47};
