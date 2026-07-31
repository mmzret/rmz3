#include "motion.h"
#include "global.h"
#include "vfx.h"

// キュービットフォクスター の炎に関係
typedef struct {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  // props (16bytes, offset: 0x74..)
  u8 unk_74[8];  // 0x74
  u8 unk_7c;     // 0x7C
  u8 unk_7d[7];  // 0x7D
} VFX50;
static_assert(sizeof(VFX50) == sizeof(struct VFX));

static const motion_t sVFX50Animations[3];

static void VFX50_Init(VFX50* p);
static void VFX50_Update(VFX50* p);
static void VFX50_Die(VFX50* p);

// clang-format off
const VFXRoutine gVFX50Routine = {
    [ENTITY_INIT] =      (void*)VFX50_Init,
    [ENTITY_UPDATE] =    (void*)VFX50_Update,
    [ENTITY_DIE] =       (void*)VFX50_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080c078c(struct Entity* q, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_050);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

struct Entity* FUN_080c07e4(Coords32* c1, Coords32* c2, u8 xflip, u8 unk7c) {
  VFX50* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_050);
    p->work[0] = xflip;
    p->unk_7c = unk7c;
    p->work[1] = 1;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return (void*)p;
}

static void VFX50_Init(VFX50* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);

  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
    (p->d).x = PIXEL(1) / 2;
  } else {
    SET_XFLIP(p, TRUE);
    (p->d).x = -PIXEL(1) / 2;
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  }

  (p->d).y = 0;
  p->work[2] = 0xFF;
  VFX50_Update(p);
}

void FUN_080c094c(VFX50* p);
void FUN_080c09c8(VFX50* p);

static void VFX50_Update(VFX50* p) {
  static void (*const sUpdates[2])(VFX50*) = {
      FUN_080c094c,
      FUN_080c09c8,
  };  // 0x0836F178
  (sUpdates[p->mode[1]])(p);
}

static void VFX50_Die(VFX50* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080c094c(VFX50* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, sVFX50Animations[p->unk_7c]);
      p->renderPrio = 9;
      p->work[3] = 10;
      p->d.y = 0;
      p->mode[2]++;
      // fallthrough
    case 1:
      p->d.y -= 0x20;
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[3] == 0 || --p->work[3] == 0) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

INCASM("asm/vfx/unk_50_a.inc");

static const motion_t sVFX50Animations[3] = {
    MOTION(DM177_CUBIT_FLAME, 9),
    MOTION(DM177_CUBIT_FLAME, 10),
    MOTION(DM177_CUBIT_FLAME, 11),
};  // 0x0836F180
