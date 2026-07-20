#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "physics.h"
#include "solid.h"

// 赤いトグルスイッチ (兵器再生工場のコンベアの向きを変えるやつ)

static void Solid34_Init(Object* p);
static void Solid34_Update(Object* p);
static void Solid34_Die(void* _ UNUSED);

// clang-format off
const SolidRoutine gToggleSwitchRedRoutine = {
    [ENTITY_INIT] =      (void*)Solid34_Init,
    [ENTITY_UPDATE] =    (void*)Solid34_Update,
    [ENTITY_DIE] =       (void*)Solid34_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void Solid34_Init(Object* p) {
  static const struct Collision sCollision = {
    kind : DRP,
    faction : FACTION_ENEMY,
    LAYER(0xFFFFFFFF),
    hitzone : 1,
    hardness : METAL,
    layer : 0xFFFFFFFF,
    range : {PIXEL(0), PIXEL(8), PIXEL(32), PIXEL(16)},
  };

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollision, 0, NULL);
  p->coord.y = FUN_0800a134(p->coord.x, p->coord.y);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid34_Update(p);
}

static void Solid34_Update(Object* p) {
  switch (p->mode[3]) {
    case 0: {
      p->work[0] = gOverworld.state[0];
      if (p->work[0] == 0) {
        SetSpriteAnimation(p, MOTION(SM118_LEVER_SWITCH_RED, 1));
      } else {
        SetSpriteAnimation(p, MOTION(SM118_LEVER_SWITCH_RED, 2));
      }
      p->mode[3]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->body).status & BODY_STATUS_B3) gOverworld.state[0] ^= 1;
      if (p->work[0] != gOverworld.state[0]) {
        if (p->work[0] == 0) {
          SetSpriteAnimation(p, MOTION(SM118_LEVER_SWITCH_RED, 3));
        } else {
          SetSpriteAnimation(p, MOTION(SM118_LEVER_SWITCH_RED, 4));
        }
        p->work[2] = 30;
        p->mode[3]++;
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if (--p->work[2] == 0) {
        p->mode[3] = 0;
      }
      break;
    }
  }
}

static void Solid34_Die(void* _) {}
