#include "global.h"
#include "stagerun.h"
#include "vfx.h"

// MMBN4との通信で出現する敵に関係するエフェクト?

static void VFX44_Init(struct Entity* p);
static void VFX44_Update(struct Entity* p);
static void VFX44_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX44Routine = {
    [ENTITY_INIT] =      (void*)VFX44_Init,
    [ENTITY_UPDATE] =    (void*)VFX44_Update,
    [ENTITY_DIE] =       (void*)VFX44_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* createGhost44(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_MMBN4_044);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

// --------------------------------------------

static void VFX44_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  (p->d).y = 0;
  p->work[2] = 0xFF;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  VFX44_Update(p);
}

void FUN_080be974(struct Entity* p);

static void VFX44_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      FUN_080be974,
  };
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED) || gStageRun.vm.entities[1].entity != NULL) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void VFX44_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

void FUN_080be974(struct Entity* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion(p, 0x3d00);
      p->work[2] = 0x14;
      p->mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(p);
      if (p->work[2]-- & 2) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      if (p->work[2] != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 2:
      SetMotion(p, 0x3d01);
      PlaySound(0x62);
      p->flags |= DISPLAY;
      p->mode[2]++;
      break;
    case 3:
      UpdateEntityAnim(p);
      if (p->motion.state == 3) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}
