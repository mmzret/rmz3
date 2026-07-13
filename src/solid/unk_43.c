#include "collision.h"
#include "global.h"
#include "solid.h"
#include "story.h"

static const struct Collision sCollision;

static void Solid43_Init(struct Solid* p);
void Solid43_Update(struct Solid* p);
void Solid43_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid43Routine = {
    [ENTITY_INIT] =      (void*)Solid43_Init,
    [ENTITY_UPDATE] =    (void*)Solid43_Update,
    [ENTITY_DIE] =       (void*)Solid43_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void Solid43_Init(struct Solid* p) {
  (p->s).d.x = (p->s).d.y = 0;
  if ((p->s).work[0] == 0) {
    if (FLAG(gCurStory.s.gameflags, FLAG_49)) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    } else {
      INIT_BODY(p, &sCollision, 0, NULL);
      SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
      Solid43_Update(p);
    }
    return;
  }

  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, MOTION(SM156_UNK_ICE, 0));
  SET_SOLID_ROUTINE(p, ENTITY_DIE);
  Solid43_Die(p);
}

INCASM("asm/solid/unk_43.inc");

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  LAYER(RECOIL_PUSHABLE),
  hitzone : 0xFF,
  remaining : 0,
  range : {PIXEL(0), PIXEL(8), PIXEL(16), PIXEL(64)},
};
