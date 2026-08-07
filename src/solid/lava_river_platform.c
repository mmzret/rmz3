#include "collision.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "solid.h"
#include "stagerun.h"

s32 FUN_0800a40c(s32 x, s32 y);

struct Solid8Object {
  struct Entity s;
  struct Body body;
  // props (16bytes, offset: 0xB4..)
  s32 y;
  u8 unk_04[12];
};

typedef struct {
  COLLISION_OBJECT_HDR;
  s32 y;
  u8 unk_04[12];
} Solid8Object;
static_assert(sizeof(Solid8Object) == sizeof(struct Solid));

static const struct Rect sSize;
static const u8 sInitMode[4];

static void LavaRiverPlatform_Init(Solid8Object* p);
static void LavaRiverPlatform_Update(Solid8Object* p);
static void LavaRiverPlatform_Die(Solid8Object* p);

// clang-format off
const SolidRoutine gLavaRiverPlatformRoutine = {
    [ENTITY_INIT] =      (void*)LavaRiverPlatform_Init,
    [ENTITY_UPDATE] =    (void*)LavaRiverPlatform_Update,
    [ENTITY_DIE] =       (void*)LavaRiverPlatform_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateLavaRiverPlatform(u32 x, u32 y) {
  Solid8Object* p = AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_RIVER_PLATFORM);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
  }
}

// --------------------------------------------

static void LavaRiverPlatform_Init(Solid8Object* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitMode[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  p->flags2 |= ENTI_PHYSICS;
  p->size = (struct Rect*)&sSize;
  p->physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  p->y = PIXEL(40);
  LavaRiverPlatform_Update(p);
}

static void nop_080ccef8(Solid8Object* p);
void FUN_080ccefc(Solid8Object* p);
void FUN_080cd03c(Solid8Object* p);

static void LavaRiverPlatform_Update(Solid8Object* p) {
  static void (*const sUpdates1[2])(Solid8Object*) = {
      nop_080ccef8,
      nop_080ccef8,
  };
  static void (*const sUpdates2[2])(Solid8Object*) = {
      FUN_080ccefc,
      FUN_080cd03c,
  };
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void LavaRiverPlatform_Die(Solid8Object* p) {
  p->flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ccef8(Solid8Object* _) {}

void FUN_080ccefc(Solid8Object* p) {
  register s32 m asm("r4");
  m = p->mode[2];
  switch (m) {
    case 0:
      PlaySound(0x77);
      p->d.y = m;
      p->work[2] = m;
      p->unk_coord.x = m;
      SetMotion((struct Entity*)p, 0x3B00);
      UpdateEntityAnim((struct Entity*)p);
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      s32 fl;
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      {
        s32 ny = p->coord.y + p->d.y;
        s32 po;
        p->coord.y = ny;
        po = PushoutToUp2(p->coord.x, ny + ((struct Solid8Object*)p)->y);
        if (po < 0) {
          p->coord.y += po;
        }
      }
      fl = p->coord.y;
      fl += ((struct Solid8Object*)p)->y;
      {
        s32 lim = p->coord.y + 0x1000;
        if (fl < lim) {
          fl = lim;
        }
      }
      {
        s32 po2 = FUN_0800a40c(p->coord.x, fl + 0x800);
        if (po2 != 0) {
          p->coord.x += po2;
        }
      }
      p->unk_coord.x += 1;
      {
        s32 w = p->work[2] + 1;
        p->work[2] = w;
        if ((w & 3) == 0) {
          if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) <= 0x7FF) {
            if (p->unk_coord.x <= 0x77) {
              struct Coord c;
              s32 bx = p->coord.x - 0x2800;
              c.x = bx;
              c.x = (RANDOM(RNG_0202f388) % 0x2800) + bx;
              c.y = fl - 0x400;
              CreateParticle(&c, 1, 0);
            }
          }
        }
      }
      ((struct Solid8Object*)p)->y -= 0x60;
      if (((struct Solid8Object*)p)->y < -0x1000) {
        SET_SOLID_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

void FUN_080cd03c(Solid8Object* p) {
  u8 m = p->mode[2];
  switch (m) {
    case 0:
      p->work[2] = m;
      p->d.y = m;
      SetMotion((struct Entity*)p, MOTION(0x3B, 0x00));
      p->mode[2]++;
    case 1: {
      s32 hit;
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      hit = PushoutToUp2(p->coord.x, p->coord.y + *(s32*)((u8*)p + 0xb4));
      if (p->work[2] == 0) {
        p->d.y = 0x80;
        if (hit == 0) {
          p->work[2] = 1;
        }
      } else if (hit < 0) {
        p->coord.y += hit;
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(24), PIXEL(48), PIXEL(48)};

static const u8 sInitMode[4] = {1, 0, 0, 0};
