#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

// グラフィックはバイル研究所の動く足場だけど、水にぷかぷか浮いてゼロが乗ると少し沈む足場
// 見たところ使われていない、前作の流氷のコードの残骸？

static const struct Collision sCollisions[2];
static const struct Rect sSize;

static void Solid33_Init(Object* p);
static void Solid33_Update(Object* p);
static void Solid33_Die(void* _ UNUSED);

// clang-format off
const SolidRoutine gSolid33Routine = {
    [ENTITY_INIT] =      (void*)Solid33_Init,
    [ENTITY_UPDATE] =    (void*)Solid33_Update,
    [ENTITY_DIE] =       (void*)Solid33_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void Solid33_Init(Object* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, MOTION(SM125_WEILLABO_PLATFORM, 0));
  UpdateSpriteAnimation(p);
  INIT_BODY(p, &sCollisions[0], 0, NULL);
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = &sSize;
  (p->s).physicsAttr = (MTATTR_CONVEYOR1 | SHAPE_BLOCK);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  (p->s).coord.x += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid33_Update(p);
}

static void Solid33_Update(Object* p) {
  s32 y = gOverworld.sea - PIXEL(10);
  if (((p->body).status & BODY_STATUS_B2) && ((p->s).coord.y + PIXEL(8) > (pZero2->s).coord.y)) {
    y = gOverworld.sea - PIXEL(8);
  }
  (p->s).coord.y = (((p->s).coord.y * 7) + y) >> 3;
}

static void Solid33_Die(void* _) {}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(66), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(36), PIXEL(60), PIXEL(8)},
    },
};

static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(64), PIXEL(16)};
