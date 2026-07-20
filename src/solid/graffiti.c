#include "collision.h"
#include "global.h"
#include "mod.h"
#include "solid.h"

// 改造カードでベースに出現する 絵 と 落書き

enum Graffiti {
  GRAFFITI_MMBN = 0,  // MMBNのロックマンの絵
  GRAFFITI_ZERO1,     // ゼロの落書き
  GRAFFITI_CIEL1,     // シエルの落書き
  GRAFFITI_ZERO2,     // ゼロの落書き (ZERO1 と酷似した落書き + "ぜろ"という文字が入っている)
  GRAFFITI_CIEL2,     // シエルの絵(かわいい)
};

static void Graffiti_Init(Object* p);
static void Graffiti_Update(struct Entity* p);
static void Graffiti_Die(struct Entity* p);

// clang-format off
const SolidRoutine gGraffitiRoutine = {
    [ENTITY_INIT] =      (SolidFunc)Graffiti_Init,
    [ENTITY_UPDATE] =    (SolidFunc)Graffiti_Update,
    [ENTITY_DIE] =       (SolidFunc)Graffiti_Die,
    [ENTITY_DISAPPEAR] = (SolidFunc)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// 0x080df420
static void Graffiti_Init(Object* p) {
  static const motion_t sMotions[5] = {
      MOTION(SM162_PAINTING_MMBN, 0), MOTION(SM163_GRAFFITI_ZERO1, 0), MOTION(SM164_GRAFFITI_CIEL, 0), MOTION(SM165_GRAFFITI_ZERO2, 0), MOTION(SM166_PAINTING_CIEL, 0),
  };  // 0x08371888

  // clang-format off
  static const u16 sFlags[] = {
      [GRAFFITI_MMBN]  = MOD_POSTER,
      [GRAFFITI_ZERO1] = MOD_GRAFFITI,
      [GRAFFITI_CIEL1] = MOD_GRAFFITI,
      [GRAFFITI_ZERO2] = MOD_GRAFFITI,
      [GRAFFITI_CIEL2] = MOD_POSTER,
  };  // 0x08371892
  // clang-format on

  if (!FLAG(gSystemSavedata.flags, sFlags[p->work[0]])) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, sMotions[p->work[0]]);
  SET_XFLIP(p, FALSE);
  p->renderPrio = 31;
  if (p->work[0] == GRAFFITI_CIEL2) {
    p->coord.x -= PIXEL(4);
    p->coord.y -= PIXEL(4);
  }
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Graffiti_Update((void*)p);
}

static void Graffiti_Update(struct Entity* p) { UpdateSpriteAnimation(p); }

static void Graffiti_Die(struct Entity* p) { SET_SOLID_ROUTINE(p, ENTITY_EXIT); }
