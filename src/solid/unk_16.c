#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

// 多分アナトレーの森でスイッチで動く壁

void Solid16_Init(struct Solid* p);
void Solid16_Update(struct Solid* p);
void Solid16_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid16Routine = {
    [ENTITY_INIT] =      Solid16_Init,
    [ENTITY_MAIN] =      Solid16_Update,
    [ENTITY_DIE] =       Solid16_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* FUN_080cedc0(u8 n) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_016);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
  }
  return p;
}

INCASM("asm/solid/unk_16.inc");

// --------------------------------------------

const struct Collision sSolid16Collision = {
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
  range : {PIXEL(0), PIXEL(0), -PIXEL(1), -PIXEL(96)},
};
