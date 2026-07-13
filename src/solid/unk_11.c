#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

void FUN_0800e370(Coords32* c);

static void Solid11_Init(struct Solid* p);
static void Solid11_Update(struct Solid* p);
static void Solid11_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid11Routine = {
    [ENTITY_INIT] =      (void*)Solid11_Init,
    [ENTITY_UPDATE] =    (void*)Solid11_Update,
    [ENTITY_DIE] =       (void*)Solid11_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void Solid11_Init(struct Solid* p) {
  static const struct Collision sCollision = {
    kind : DRP,
    faction : FACTION_ENEMY,
    LAYER(RECOIL_PUSHABLE),
    hitzone : 0xFF,
    remaining : 0,
    range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
  };

  const metatile_attr_t attr = GetMetatileAttr((p->s).coord.x, (p->s).coord.y);
  if (attr == 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  INIT_BODY(p, &sCollision, 0, NULL);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid11_Update(p);
}

static void Solid11_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      EXIT_BODY(p);
      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      EnableSpriteAnimation_Normal(p);
      SetSpriteAnimation(p, MOTION(SM072_UNK, 0));
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
      UpdateSpriteAnimation(p);
      if ((p->s).d.y < PIXEL(7)) {
        (p->s).d.y += PIXEL(1) / 8;
      }
      y = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = y;
      (p->s).unk_coord.y = y;
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > PIXEL(48)) {
        (p->s).flags &= ~DISPLAY;
        SET_SOLID_ROUTINE(p, ENTITY_EXIT);
      }
      break;
    }
  }
}
