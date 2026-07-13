#include "entity.h"
#include "global.h"
#include "vfx.h"

// ファントム(ボス)関連?

void* FUN_080afda4(void* p);

// --------------------------------------------

// なぜか gGhost68Routine より前に配置されてる

static void FUN_080c4d30(struct Entity* p);
static void FUN_080c4db8(struct Entity* p);

static const EntityFunc sInitializers[] = {
    FUN_080c4d30,
    FUN_080c4db8,
};  // 0x0836f6bc

static void FUN_080c4d60(struct Entity* p);
static void FUN_080c4de8(struct Entity* p);

static const EntityFunc sUpdates[] = {
    FUN_080c4d60,
    FUN_080c4de8,
};  // 0x0836f6c4

// --------------------------------------------

static void Ghost68_Init(struct Entity* p);
static void Ghost68_Update(struct Entity* p);
static void Ghost68_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost68Routine = {
    [ENTITY_INIT] =      (void*)Ghost68_Init,
    [ENTITY_UPDATE] =    (void*)Ghost68_Update,
    [ENTITY_DIE] =       (void*)Ghost68_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080c4be0(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_068);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
  }
}

void FUN_080c4c2c(s32 x, s32 y, s32 amplitude, u8 theta) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_068);
    p->work[0] = 1;
    (p->coord).x = x, (p->coord).y = y;
    (p->d).x = Cos(theta, amplitude);
    (p->d).y = Sin(theta, amplitude);
    p->unk_2c = FUN_080afda4(p);
  }
}

// --------------------------------------------

static void Ghost68_Init(struct Entity* p) {
  (sInitializers[p->work[0]])(p);
  Ghost68_Update(p);
}

static void Ghost68_Update(struct Entity* p) { (sUpdates[p->work[0]])(p); }

static void Ghost68_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  p->flags &= ~FLIPABLE;
  SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
}

// --------------------------------------------

static void FUN_080c4d30(struct Entity* p) {
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
}

static void FUN_080c4d60(struct Entity* p) {
  switch (p->mode[1]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM135_UNK, 0));
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

static void FUN_080c4db8(struct Entity* p) {
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
}

static void FUN_080c4de8(struct Entity* p) {
  struct Entity* q = (struct Entity*)(p->unk_2c);
  switch (p->mode[1]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM135_UNK, 1));
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (q->coord).x = (p->coord).x;
      (q->coord).y = (p->coord).y;
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}
