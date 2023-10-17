#include "collision.h"
#include "global.h"
#include "solid.h"

/*
  旧居住区などの蔦の燃える判定(グラフィックは別)
  他にも用途あるかも
*/

static const struct Collision sCollision;

// --------------------------------------------

void Solid3_Init(struct Solid* p);
void Solid3_Update(struct Solid* p);
void Solid3_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid3Routine = {
    [ENTITY_INIT] =      Solid3_Init,
    [ENTITY_UPDATE] =    Solid3_Update,
    [ENTITY_DIE] =       Solid3_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// 旧居住区などの蔦の燃える判定部分(グラフィックは別)
struct Solid* CreateLeafBurn(u8 r0) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_003);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = r0;
    (p->s).work[1] = 0;
  }
  return p;
}

INCASM("asm/solid/unk_03.inc");

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  LAYER(0x442108),
  hitzone : 0xFF,
  remaining : 0,
  range : {PIXEL(0), PIXEL(0), -PIXEL(1), -PIXEL(1)},
};
