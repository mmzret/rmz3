#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"
#include "story.h"

// 多分巨大エレベータで雑魚ラッシュ中に上にある二つの台

static const struct Rect sSize;

static void Solid46_Init(struct Solid* p);
void Solid46_Update(struct Solid* p);
void Solid46_Die(struct Solid* p);

// clang-format off
const SolidRoutine gGiantElevatorPlatformRoutine = {
    [ENTITY_INIT] =      Solid46_Init,
    [ENTITY_MAIN] =      Solid46_Update,
    [ENTITY_DIE] =       Solid46_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateGiantElevatorPlatform(u8 isRight) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_GE_PLATFORM);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = isRight;
    if (isRight == 0) {
      (p->s).coord.x = PIXEL(3696);
    } else {
      (p->s).coord.x = PIXEL(3984);
    }
    (p->s).coord.y = PIXEL(1712);
  }
  return p;
}

static void Solid46_Init(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  SetMotion(&p->s, MOTION(SM155_GIANT_ELEVATOR_PLATFORM, 0));
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = 0x2001;
  (p->s).d.x = PIXEL(0);
  (p->s).d.y = PIXEL(2);
  if ((p->s).work[0] == 0) {
    LOAD_STATIC_GRAPHIC(SM155_GIANT_ELEVATOR_PLATFORM);
  }
  (p->s).work[1] = (gCurStory.s.gameflags[4] >> 6) & 1;
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid46_Update(p);
}

INCASM("asm/solid/giant_elevator_platform.inc");

static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(64), PIXEL(16)};
