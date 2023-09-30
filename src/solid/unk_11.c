#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

void FUN_0800e370(struct Coord* c);

static const struct Collision sCollision;

static void Solid11_Init(struct Solid* p);
static void Solid11_Update(struct Solid* p);
static void Solid11_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid11Routine = {
    [ENTITY_INIT] =      Solid11_Init,
    [ENTITY_MAIN] =      Solid11_Update,
    [ENTITY_DIE] =       Solid11_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid11_Init(struct Solid* p) {
  struct Coord* velocity;

  const metatile_attr_t attr = GetMetatileAttr((p->s).coord.x, (p->s).coord.y);
  if (attr == 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  INIT_BODY(p, &sCollision, 0, NULL);
  velocity = &(p->s).d;
  velocity->x = velocity->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid11_Update(p);
}

static void Solid11_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_B17) {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM072_UNK, 0));
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Solid11_Die(p);
    }
  }
}

static void Solid11_Die(struct Solid* p) {
  s32 y;

  switch ((p->s).mode[1]) {
    case 0: {
      FUN_0800e370(&(p->s).coord);
      AppendQuake(4, &(p->s).coord);
      PlaySound(SE_UNK_11d);
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      if ((p->s).d.y < PIXEL(7)) {
        (p->s).d.y += PIXEL(1) / 8;
      }
      y = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = y;
      (p->s).unk_coord.y = y;
      if (CalcFromCamera(&gStageRun.vm.camera, &(p->s).coord) > PIXEL(48)) {
        (p->s).flags &= ~DISPLAY;
        SET_SOLID_ROUTINE(p, ENTITY_EXIT);
      }
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 0,
  unk_04 : 0x00,
  element : 0x78,
  nature : 0x00,
  hitzone : 0xFF,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000000,
  range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
};
