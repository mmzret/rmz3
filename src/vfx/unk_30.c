#include "global.h"
#include "script.h"
#include "vfx.h"

// 切られた ブレイジンフリザード

static void Ghost30_Init(struct Entity* p);
static void Ghost30_Update(struct Entity* p);
static void Ghost30_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost30Routine = {
    [ENTITY_INIT] =      (void*)Ghost30_Init,
    [ENTITY_UPDATE] =    (void*)Ghost30_Update,
    [ENTITY_DIE] =       (void*)Ghost30_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateGhost30(struct Entity* e, Coords32* c, u8 n, u32 m) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_030);
    p->work[0] = n, p->work[1] = m;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = e;
  }
  return p;
}

static void Ghost30_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = PIXEL(1) / 2;
  } else {
    (p->d).x = -PIXEL(1) / 2;
  }
  (p->d).y = 0;
  p->work[2] = 0xFF;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  Ghost30_Update(p);
}

// --------------------------------------------

static void nop_080ba444(void* _ UNUSED);
static void FUN_080ba448(struct Entity* p);

static void Ghost30_Update(struct Entity* p) {
  static const EntityFunc sUpdates[2] = {
      (void*)nop_080ba444,
      (void*)FUN_080ba448,
  };
  (sUpdates[p->mode[1]])(p);
}

static void Ghost30_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

static void nop_080ba444(void* _) {}

static void FUN_080ba448(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      if (p->work[1] == 1) {
        SetSpriteAnimation(p, MOTION(DM162_BLAZIN, 5));
      } else {
        SetSpriteAnimation(p, MOTION(DM162_BLAZIN, 26));
      }
      p->work[2] = 60;
      if ((p->d).x > 0) {
        (p->unk_coord).x = ((p->unk_28)->coord).x + PIXEL(12);
      } else {
        (p->unk_coord).x = ((p->unk_28)->coord).x - PIXEL(12);
      }
      (p->d).y = 0x80;
      (p->unk_coord).y = ((p->unk_28)->coord).y + PIXEL(6);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->coord).x += (((p->unk_coord).x - (p->coord).x) << 4) >> 8;
      (p->coord).y += (((p->unk_coord).y - (p->coord).y) << 4) >> 8;
      UpdateSpriteAnimation(p);
      if ((p->unk_28)->flags & DISPLAY) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      break;
    }
    case 2: {
      if (((p->unk_28)->scriptEntity)->flags & (1 << 7)) {
        CreateSmoke(1, &p->coord);
        PlaySound(SE_ZAKO_EXPLODE);
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}
