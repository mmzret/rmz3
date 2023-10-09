#include "collision.h"
#include "global.h"
#include "solid.h"
#include "story.h"

static const struct Collision sCollision;
static const struct Rect sSize;

static void Solid32_Init(struct Solid* p);
void Solid32_Update(struct Solid* p);
void Solid32_Die(struct Solid* p);
void Solid32_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gLightSwitchRoutine = {
    [ENTITY_INIT] =      Solid32_Init,
    [ENTITY_UPDATE] =    Solid32_Update,
    [ENTITY_DIE] =       Solid32_Die,
    [ENTITY_DISAPPEAR] = Solid32_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid32_Init(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  SetMotion(&p->s, MOTION(SM223_LIGHT_SWITCH, 0));
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = METATILE_GROUND;
  (p->s).flags2 &= ~WHITE_PAINTABLE;
  (p->s).invincibleID = (p->s).uniqueID;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  if ((gCurStory.unk_54 >> (p->s).work[0]) & 1) {
    (p->s).mode[3] = 2;
  } else {
    (p->s).mode[3] = 0;
  }
  Solid32_Update(p);
}

INCASM("asm/solid/light_switch.inc");

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0xFF,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0xFFFDEF7B,
  range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)};
const struct Coord Coord_083714bc = {0, 0xFFFFF000};
