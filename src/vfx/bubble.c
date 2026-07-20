#include "vfx/bubble.h"

#include "global.h"
#include "vfx.h"

static void Bubble_Init(BubbleVFX* p);
static void Bubble_Update(BubbleVFX* p);
static void Bubble_Die(BubbleVFX* p);

// clang-format off
const VFXRoutine gBubbleRoutine = {
    [ENTITY_INIT] =      (void*)Bubble_Init,
    [ENTITY_UPDATE] =    (void*)Bubble_Update,
    [ENTITY_DIE] =       (void*)Bubble_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateBubble(s32 x, s32 y, u8 kind) {
  BubbleVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_BUBBLE);
    p->work[0] = kind;
    (p->coord).x = x, (p->coord).y = y;
  }
}

// --------------------------------------------

void FUN_080b2e50(BubbleVFX* p);
void FUN_080b2ef0(BubbleVFX* p);
void FUN_080b2f7c(BubbleVFX* p);
void FUN_080b3024(BubbleVFX* p);

static void Bubble_Init(BubbleVFX* p) {
  static void (*const sInitializers[4])(BubbleVFX*) = {
      FUN_080b2e50,
      FUN_080b2ef0,
      FUN_080b2f7c,
      FUN_080b3024,
  };
  (sInitializers[p->work[0]])(p);
}

void FUN_080b30b4(BubbleVFX* p);
void FUN_080b3144(BubbleVFX* p);
void FUN_080b31d8(BubbleVFX* p);
void FUN_080b3278(BubbleVFX* p);

static void Bubble_Update(BubbleVFX* p) {
  static void (*const sUpdates[4])(BubbleVFX*) = {
      FUN_080b30b4,
      FUN_080b3144,
      FUN_080b31d8,
      FUN_080b3278,
  };
  if (p->unk_78 != 0) {
    if (p->unk_78-- < 32) {
      if (p->unk_78 & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
    }
  } else {
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[p->work[0]])(p);
}

static void Bubble_Die(BubbleVFX* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

void FUN_080b2e50(BubbleVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 13));
  (p->d).x = PIXEL(1) / 4 - (RANDOM(RNG_0202f388) & 0x7F);
  (p->d).y = PIXEL(3) / 4 + (RANDOM(RNG_0202f388) & 0x1F);
  p->x_74 = (p->coord).x;
  p->work[2] = RANDOM(RNG_0202f388);
  p->work[3] = RANDOM(RNG_0202f388);
  p->unk_78 = 0x80;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Bubble_Update(p);
}

void FUN_080b2ef0(BubbleVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 12));
  (p->d).x = PIXEL(2);
  (p->d).y = PIXEL(1) / 2 + (RANDOM(RNG_0202f388) & 0x1F);
  p->x_74 = (p->coord).x;
  p->work[2] = RANDOM(RNG_0202f388);
  p->work[3] = RANDOM(RNG_0202f388);
  p->unk_78 = 0x80;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Bubble_Update(p);
}

void FUN_080b2f7c(BubbleVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 13));
  (p->d).x = PIXEL(1) / 2 - (RANDOM(RNG_0202f388) & 0xFF);
  (p->d).y = PIXEL(9) / 2 + (RANDOM(RNG_0202f388) & 0xFF);
  p->x_74 = (p->coord).x;
  p->work[2] = RANDOM(RNG_0202f388);
  p->work[3] = RANDOM(RNG_0202f388);
  p->unk_78 = 0x80;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Bubble_Update(p);
}

void FUN_080b3024(BubbleVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 12));
  (p->d).x = PIXEL(2);
  (p->d).y = PIXEL(4) + (RANDOM(RNG_0202f388) & 0xFF);
  p->x_74 = (p->coord).x;
  p->work[2] = RANDOM(RNG_0202f388);
  p->work[3] = RANDOM(RNG_0202f388);
  p->unk_78 = 0x80;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Bubble_Update(p);
}

INCASM("asm/vfx/bubble.inc");
