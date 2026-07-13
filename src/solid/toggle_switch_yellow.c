#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

// エネルギーしせつの(鉄骨リフトの)トグルスイッチ
// 兵器再生工場の(コンベアの)トグルスイッチと同じグラフィックだけど、色が黄色(兵器再生工場のは赤)

static void Solid52_Init(Object* p);
static void Solid52_Update(Object* p);
static void Solid52_Die(void* _ UNUSED);

// clang-format off
const SolidRoutine gToggleSwitchYellowRoutine = {
    [ENTITY_INIT] =      (SolidFunc)Solid52_Init,
    [ENTITY_UPDATE] =    (SolidFunc)Solid52_Update,
    [ENTITY_DIE] =       (SolidFunc)Solid52_Die,
    [ENTITY_DISAPPEAR] = (SolidFunc)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid52_Init(Object* p) {
  static const struct Collision sCollision = {
    kind : DRP,
    faction : FACTION_ENEMY,
    LAYER(0xFFFFFFFF),
    hitzone : 1,
    hardness : METAL,
    layer : 0xFFFFFFFF,
    range : {PIXEL(0), PIXEL(8), PIXEL(32), PIXEL(16)},
  };  // 0x0837191c

  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SET_YFLIP(p, TRUE);
  INIT_BODY(p, &sCollision, 0, NULL);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + PIXEL(2) + 1;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid52_Update(p);
}

static void Solid52_Update(Object* p) {
  switch ((p->s).mode[3]) {
    case 0: {
      if (((p->s).work[0] = gOverworld.state[0]) == 0) {
        SetSpriteAnimation(p, MOTION(SM210_LEVER_SWITCH_YELLOW, 1));
      } else {
        SetSpriteAnimation(p, MOTION(SM210_LEVER_SWITCH_YELLOW, 2));
      }
      (p->s).mode[3]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->body).status & BODY_STATUS_B3) {
        gOverworld.state[0] ^= 1;
      }
      if ((p->s).work[0] != gOverworld.state[0]) {
        if ((p->s).work[0] == 0) {
          SetSpriteAnimation(p, MOTION(SM210_LEVER_SWITCH_YELLOW, 3));
        } else {
          SetSpriteAnimation(p, MOTION(SM210_LEVER_SWITCH_YELLOW, 4));
        }
        (p->s).work[2] = 30;
        (p->s).mode[3]++;
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if (--(p->s).work[2] == 0) {
        (p->s).mode[3] = 0;
      }
      break;
    }
  }
}

static void Solid52_Die(void* _) {}
