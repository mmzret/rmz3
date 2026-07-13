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
    [ENTITY_UPDATE] =    Solid46_Update,
    [ENTITY_DIE] =       Solid46_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateGiantElevatorPlatform(u8 isRight) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_GE_PLATFORM);
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
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, MOTION(SM155_GIANT_ELEVATOR_PLATFORM, 0));
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = &sSize;
  (p->s).physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  (p->s).d.x = PIXEL(0);
  (p->s).d.y = PIXEL(2);
  if ((p->s).work[0] == 0) {
    LOAD_STATIC_GRAPHIC(SM155_GIANT_ELEVATOR_PLATFORM);
  }
  (p->s).work[1] = (gCurStory.s.gameflags[4] >> 6) & 1;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid46_Update(p);
}

INCASM("asm/solid/giant_elevator_platform.inc");

// 0x083717c0
static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(64), PIXEL(16)};
