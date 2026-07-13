#include "entity.h"
#include "global.h"
#include "vfx.h"

/*
  !などの吹き出し
*/

static const motion_t sMotions[3];

static void EmotionBubble_Init(struct VFX* p);
static void EmotionBubble_Update(struct VFX* p);
static void EmotionBubble_Die(struct VFX* p);

// clang-format off
const VFXRoutine gEmotionBubbleRoutine = {
    [ENTITY_INIT] =      (void*)EmotionBubble_Init,
    [ENTITY_UPDATE] =    (void*)EmotionBubble_Update,
    [ENTITY_DIE] =       (void*)EmotionBubble_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static struct Entity* unused_CreateGhost15(u8 n, Coords32* c) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_EMOTION_BUBBLE);
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->work[0] = 0;
    EnableSpriteAnimation_Normal(p);
    SetSpriteAnimation(p, sMotions[n]);
  }
  return p;
}

// 0x080b6340
struct Entity* CreateEmotionBubble(u8 kind, Coords32* target, Coords32* offset) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_EMOTION_BUBBLE);
    p->unk_28 = (void*)target;
    (p->unk_coord).x = offset->x, (p->unk_coord).y = offset->y;
    p->work[0] = 1;
    EnableSpriteAnimation_Normal(p);
    SetSpriteAnimation(p, sMotions[kind]);
    SET_XFLIP(p, (offset->x < 0));
  }
  return p;
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void EmotionBubble_Init(struct VFX* p) {
  (p->s).flags |= DISPLAY;
  (p->s).spr.oam.priority = 0;
  (p->s).work[2] = SECOND;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  EmotionBubble_Update(p);
}

static void EmotionBubble_Update(struct VFX* p) {
  UpdateSpriteAnimation(p);
  if ((p->s).work[0] != 0) {
    Coords32* from = (Coords32*)(p->s).unk_28;
    (p->s).coord.x = from->x + (p->s).unk_coord.x;
    (p->s).coord.y = from->y + (p->s).unk_coord.y;
  }
  if (--(p->s).work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

static void EmotionBubble_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static const motion_t sMotions[3] = {
    MOTION(SM003_EMOTION_BUBBLE, 0),
    MOTION(SM003_EMOTION_BUBBLE, 1),
    MOTION(SM003_EMOTION_BUBBLE, 2),
};
