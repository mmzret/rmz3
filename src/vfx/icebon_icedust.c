#include "entity.h"
#include "global.h"
#include "vfx.h"

// アイスボンの氷のキラキラ

static void IcebonIcedust_Init(struct Entity* p);
static void IcebonIcedust_Update(struct Entity* p);
static void IcebonIcedust_Die(struct Entity* p);

// clang-format off
const VFXRoutine gIcebonIcedustRoutine = {
    [ENTITY_INIT] =      (void*)IcebonIcedust_Init,
    [ENTITY_UPDATE] =    (void*)IcebonIcedust_Update,
    [ENTITY_DIE] =       (void*)IcebonIcedust_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void createIcebonIce(s32 x, s32 y) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_026);
    p->coord.x = x, p->coord.y = y;
    p->work[0] = 0;
  }
}

void FUN_080b98ac(s32 x, s32 y) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_026);
    p->coord.x = x, p->coord.y = y;
    p->work[0] = 1;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void IcebonIcedust_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  IcebonIcedust_Update((void*)p);
}

static void ice_080b996c(struct Entity* p);
static void ice_080b9a0c(struct Entity* p);

static void IcebonIcedust_Update(struct Entity* p) {
  static const EntityFunc sUpdates[2] = {
      ice_080b996c,
      ice_080b9a0c,
  };
  (sUpdates[p->mode[1]])(p);
}

static void IcebonIcedust_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static void ice_080b996c(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM017_ICEBON_ICE, 9));
      (p->d).x = (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->d).y = (RANDOM(RNG_0202f388) & 0x7F) + (PIXEL(1) / 2);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) SET_VFX_ROUTINE(p, ENTITY_DIE);
      break;
    }
  }
}

static void ice_080b9a0c(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM017_ICEBON_ICE, 9));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) SET_VFX_ROUTINE(p, ENTITY_DIE);
      break;
    }
  }
}

// 0x0836eafc
static const u8 sInitModes[4] = {0, 1, 0, 0};
