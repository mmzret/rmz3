#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"
#include "story.h"
#include "overworld.h"
#include "stagerun.h"

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

void Solid46_Update(struct Solid* p) {
  UpdateEntityAnim(&p->s);
  {
    register s32 w1 asm("r1");
    register s32 g asm("r2");
    register s32 one asm("r0");
    w1 = (p->s).work[1];
    one = gCurStory.s.gameflags[4];
    g = one >> 6;
    one = 1;
    one &= g;
    if (w1 != one) {
      g &= 1;
      (p->s).work[1] = g;
      LOAD_STATIC_GRAPHIC(SM155_GIANT_ELEVATOR_PLATFORM);
    }
  }
  switch ((p->s).mode[1]) {
    case 0:
    {
      register s32 cy asm("r0");
      register s32 v asm("r1");
      register s32 t asm("r2");
      register s32 base asm("r3");
      cy = (p->s).coord.y;
      v = (0xe0 << 0xb) - cy;
      t = (s32)(v << 0xb) >> 0x10;
      v = (p->s).d.y;
      base = cy;
      if (t < v) {
        (p->s).d.y = t;
      }
      cy = base + (p->s).d.y;
      (p->s).coord.y = cy;
      if (t > 0x20) {
        break;
      }
    }
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 1:
      {
        register u8* gw asm("r0");
        register s32 off asm("r1");
        gw = (u8*)&gOverworld;
        off = 0x0002D024;
        if (*(gw + off) <= 4) {
          break;
        }
      }
      (p->s).d.y = 0;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 2:
    {
      register s32 dy asm("r0");
      register s32 ny asm("r1");
      dy = (p->s).d.y + 4;
      (p->s).d.y = dy;
      ny = (p->s).coord.y - dy;
      (p->s).coord.y = ny;
      {
        struct Camera* cam = &gStageRun.vm.camera;
        if (ny >= cam->viewport.y + -0x8000) {
          break;
        }
      }
    }
      (p->s).flags2 &= 0xF7;
      (p->s).d.y = 0x80 << 2;
      (p->s).mode[1]++;
      break;
    case 3:
      {
        register u8* gw asm("r0");
        register s32 off asm("r1");
        gw = (u8*)&gOverworld;
        off = 0x0002D024;
        if (*(gw + off) <= 6) {
          break;
        }
      }
      (p->s).flags2 |= 8;
      (p->s).size = (struct Rect*)&sSize;
      (p->s).physicsAttr = 0x2001;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 4:
    {
      register s32 cy asm("r0");
      register s32 v asm("r1");
      register s32 t asm("r2");
      register s32 base asm("r3");
      cy = (p->s).coord.y;
      v = (0xe0 << 0xb) - cy;
      t = (s32)(v << 0xb) >> 0x10;
      v = (p->s).d.y;
      base = cy;
      if (t < v) {
        (p->s).d.y = t;
      }
      cy = base + (p->s).d.y;
      (p->s).coord.y = cy;
      if (t > 0x20) {
        break;
      }
    }
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 5:
      {
        register u8* gw asm("r0");
        register s32 off asm("r1");
        gw = (u8*)&gOverworld;
        off = 0x0002D024;
        if (*(gw + off) <= 8) {
          break;
        }
      }
      (p->s).d.y = 0;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 6:
    {
      register s32 dy asm("r0");
      register s32 ny asm("r1");
      dy = (p->s).d.y + 4;
      (p->s).d.y = dy;
      ny = (p->s).coord.y - dy;
      (p->s).coord.y = ny;
      {
        struct Camera* cam = &gStageRun.vm.camera;
        if (ny >= cam->viewport.y + -0x8000) {
          break;
        }
      }
    }
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Solid46_Die(p);
      break;
  }
}

void Solid46_Die(struct Solid* p) {
  (p->s).flags &= ~DISPLAY;
  (p->s).flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// 0x083717c0
static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(64), PIXEL(16)};
