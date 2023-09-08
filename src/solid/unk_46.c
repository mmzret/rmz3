#include "collision.h"
#include "global.h"
#include "solid.h"

// 多分巨大エレベータで雑魚ラッシュ中に上にある二つの台

static const struct Rect sSize;

void Solid46_Init(struct Solid* p);
void Solid46_Update(struct Solid* p);
void Solid46_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid46Routine = {
    [ENTITY_INIT] =      Solid46_Init,
    [ENTITY_MAIN] =      Solid46_Update,
    [ENTITY_DIE] =       Solid46_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateSolid46(u8 isRight) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_046);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = isRight;
    if (isRight == 0) {
      (p->s).coord.x = 0xE7000;
    } else {
      (p->s).coord.x = 0xF9000;
    }
    (p->s).coord.y = 0x6b000;
  }
  return p;
}

INCASM("asm/solid/unk_46.inc");

static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(64), PIXEL(16)};
