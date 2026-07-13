#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

enum ElevatorSkin {
  ELEVATOR_DEFAULT,
  ELEVATOR_WOOD,
  ELEVATOR_MMX,
};

struct ElevatorObject {
  OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  Coords32 c;
  u8 unk_bc;
  u8 skin;  // 1: Wood, 2: MMX
  SoundIDS16 se;
  u8 unk_c0;
  u8 unk_c1;
  u16 unk_c2;
};
static_assert(sizeof(struct ElevatorObject) == sizeof(struct Solid));

#define level work[1]

static const struct Collision sCollisions[2];
static const struct Rect Rect_08370728;

static void BaseElevator_Init(struct Solid* p);
void BaseElevator_Update(struct Solid* p);
static void BaseElevator_Die(struct ElevatorObject* p);
static void BaseElevator_Disappear(struct ElevatorObject* p);

// clang-format off
const SolidRoutine gBaseElevatorRoutine = {
    [ENTITY_INIT] =      (void*)BaseElevator_Init,
    [ENTITY_UPDATE] =    (void*)BaseElevator_Update,
    [ENTITY_DIE] =       (void*)BaseElevator_Die,
    [ENTITY_DISAPPEAR] = (void*)BaseElevator_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Solid* CreateResistanceBaseElevator(u8 lv) {
  struct ElevatorObject* p = (struct ElevatorObject*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_BASE_ELEVATOR);
    (p->s).work[0] = 0;
    (p->s).level = lv;
    p->skin = gSystemSavedata.elevator;
  }
  return (void*)p;
}

// 0x080cfc40
static void CreateResistanceBaseElevator2(struct Entity* e, u8 r1, u8 lv) {
  struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_BASE_ELEVATOR);
    p->unk_28 = e;
    p->work[0] = r1;
    p->level = lv;
  }
}

// --------------------------------------------

static void rBase_080cfd4c(struct ElevatorObject* p);
void FUN_080cff48(struct Solid* p);
void FUN_080d0008(struct Solid* p);
void FUN_080d0024(struct Solid* p);

static void BaseElevator_Init(struct Solid* p) {
  if ((p->s).work[0] != 0) {
    FUN_080cff48(p);
    return;
  }
  rBase_080cfd4c((void*)p);
}

void BaseElevator_Update(struct Solid* p) {
  if ((p->s).work[0] != 0) {
    FUN_080d0024(p);
  } else {
    FUN_080d0008(p);
  }
}

static void BaseElevator_Die(struct ElevatorObject* p) {
  if ((p->s).work[0] == 0) {
    if (p->se != MUS_NONE) {
      StopSound(p->se);
      p->se = MUS_NONE;
    }
  }
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void BaseElevator_Disappear(struct ElevatorObject* p) {
  if ((p->s).work[0] == 0) {
    if (p->se != MUS_NONE) {
      StopSound(p->se);
      p->se = MUS_NONE;
    }
  }
  DeleteSolid((void*)p);
}

// 0x080cfd4c
static void rBase_080cfd4c(struct ElevatorObject* p) {
  if (p->skin == ELEVATOR_DEFAULT) LOAD_STATIC_GRAPHIC(SM115_ELEVATOR);
  if (p->skin == ELEVATOR_WOOD) LOAD_STATIC_GRAPHIC(SM137_ELEVATOR_WOOD);
  if (p->skin == ELEVATOR_MMX) LOAD_STATIC_GRAPHIC(SM138_ELEVATOR_MMX);

  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SET_XFLIP(p, FALSE);
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = &Rect_08370728;
  (p->s).physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  INIT_BODY(p, sCollisions, 0, NULL);
  (p->c).x = PIXEL(1616), (p->c).y = PIXEL(608);
  (p->s).coord.x = (p->c).x;
  (p->s).coord.y = (p->c).y + (p->s).level * PIXEL(160);

  p->se = MUS_NONE;
  CreateResistanceBaseElevator2((void*)p, 1, 0);
  gOverworld.range.left = PIXEL(0);
  gOverworld.range.top = PIXEL(0);
  gOverworld.range.right = MAX_X;
  gOverworld.range.bottom = MAX_Y;
  p->unk_c0 = 0;
  p->unk_c1 = 5;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  BaseElevator_Update((void*)p);
}

INCASM("asm/solid/base_elevator.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(16), PIXEL(18)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

// --------------------------------------------

// clang-format off
const motion_t sBaseElevatorMotions[6] = {
    MOTION(SM115_ELEVATOR, 6),
    MOTION(SM115_ELEVATOR, 5),
    MOTION(SM115_ELEVATOR, 4),
    MOTION(SM115_ELEVATOR, 3),
    MOTION(SM115_ELEVATOR, 2),
    MOTION(SM115_ELEVATOR, 1),
};
// clang-format on

// --------------------------------------------

static const struct Rect Rect_08370728 = {PIXEL(0), PIXEL(8), PIXEL(64), PIXEL(16)};
const struct Rect Rect_08370730 = {PIXEL(0), -PIXEL(72), PIXEL(64), PIXEL(16)};

#undef level
