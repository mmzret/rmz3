#include "vfx/necro.h"

#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

enum NecroKind {
  NECRO_0,
  NECRO_1,
  NECRO_2,
  NECRO_3,
  NECRO_4,
};

static const u8 sNecro_InitModes[5];

static void Necro_Init(NecroVFX* p);
static void Necro_Update(NecroVFX* p);
static void Necro_Die(NecroVFX* p);

// clang-format off
const VFXRoutine gNecroRoutine = {
    [ENTITY_INIT] =      (void*)Necro_Init,
    [ENTITY_UPDATE] =    (void*)Necro_Update,
    [ENTITY_DIE] =       (void*)Necro_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080b7f70(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_0, p->work[1] = i;
      p->unk_28 = e;
      p->anim74 = motions;
      (p->coord).x = c->x, (p->coord).y = c->y;
      p->unk_78 = 1, p->unk_79 = 0;
    }
  }
}

void FUN_080b7ffc(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_0, p->work[1] = i;
      p->unk_28 = e;
      p->anim74 = motions;
      p->coord.x = c->x, p->coord.y = c->y;
      p->unk_78 = 0, p->unk_79 = 0;
    }
  }
}

void FUN_080b8080(struct Enemy* e, Coords32* c, motion_t* motions, u8 len, u8 r4) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_0, p->work[1] = i;
      p->unk_28 = (void*)e;
      p->anim74 = motions;
      p->coord.x = c->x, p->coord.y = c->y;
      p->palID = r4;
      p->unk_78 = 1, p->unk_79 = 0;
    }
  }
}

static void Unused_080b8114(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_1, p->work[1] = i;
      p->unk_28 = e;
      p->anim74 = motions;
      p->coord.x = c->x, p->coord.y = c->y;
      p->unk_78 = 1, p->unk_79 = 0;
    }
  }
}

void FUN_080b81a0(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_1, p->work[1] = i;
      p->unk_28 = e;
      p->anim74 = motions;
      p->coord.x = c->x, p->coord.y = c->y;
      p->unk_78 = 0, p->unk_79 = 0;
    }
  }
}

void FUN_080b822c(struct Enemy* e, Coords32* c, motion_t* motions, u8 len, u8 r4) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_1, p->work[1] = i;
      p->unk_28 = (void*)e;
      p->anim74 = motions;
      p->coord.x = c->x, p->coord.y = c->y;
      p->unk_78 = 1, p->unk_79 = 1;
      p->palID = r4;
    }
  }
}

void FUN_080b82c0(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      p->work[0] = NECRO_2, p->work[1] = i;
      p->unk_28 = e;
      p->anim74 = motions;
      p->coord.x = c->x, p->coord.y = c->y;
      p->unk_78 = 1, p->unk_79 = 0;
    }
  }
}

void FUN_080b834c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_3;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->unk_78 = 1, p->unk_79 = 0;
  }
}

void FUN_080b83d4(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_3;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->unk_78 = 0, p->unk_79 = 0;
  }
}

void FUN_080b8454(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_3;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->renderPrio = renderPrio;
    p->unk_78 = 1, p->unk_79 = 0;
  }
}

void FUN_080b84f4(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_4;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->unk_78 = 1, p->unk_79 = 0;
  }
}

void FUN_080b857c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_4;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->unk_78 = 0, p->unk_79 = 0;
  }
}

void FUN_080b85fc(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_4;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->renderPrio = renderPrio;
    p->unk_78 = 1, p->unk_79 = 0;
  }
}

void FUN_080b869c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio, u8 palID) {
  NecroVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    p->work[0] = NECRO_4;
    p->unk_28 = e;
    p->anim74 = motions;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = dc->x, p->d.y = dc->y;
    p->unk_coord.y = y;
    p->work[2] = frame;
    p->renderPrio = renderPrio, p->palID = palID;
    p->unk_78 = 1, p->unk_79 = 0;
  }
}

// --------------------------------------------

static void Necro_Init(NecroVFX* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sNecro_InitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  Necro_Update(p);
}

static void Necro_Update_0(NecroVFX* p);
static void Necro_Update_1(NecroVFX* p);
static void Necro_Update_2(NecroVFX* p);
static void Necro_Update_3(NecroVFX* p);
static void Necro_Update_4(NecroVFX* p);

static void Necro_Update(NecroVFX* p) {
  // clang-format off
  static void (*const sUpdates[5])(NecroVFX*) = {
      Necro_Update_0,
      Necro_Update_1,
      Necro_Update_2,
      Necro_Update_3,
      Necro_Update_4,
  };
  // clang-format on
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED) && p->unk_78 != 0) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void Necro_Die(NecroVFX* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

// 0x080b8804
static void Necro_Update_0(NecroVFX* p) {
  bool8 xflip = ((p->unk_28)->flags & X_FLIP) != 0;
  bool8 yflip = ((p->unk_28)->flags & Y_FLIP) != 0;
  u32 idx = p->work[1];
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SET_XFLIP(p, xflip);
      SET_YFLIP(p, yflip);
      SetSpriteAnimation(p, p->anim74[idx]);
      if (xflip) idx = 2 - idx;
      (p->d).x = PIXEL(idx - 1) + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->d).y = -(RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(2);
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[2]++;
      if (p->work[2] & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += PIXEL(1) / 4;
      _FUN_0801779c(p);
      if (FUN_080098a4((p->coord).x, (p->coord).y) && (p->d).y > 0) {
        if (p->unk_79 == 0) {
          CreateSmoke(3, &p->coord);
        } else {
          CreateSmoke(2, &p->coord);
        }
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

static void Necro_Update_1(NecroVFX* p) {
  bool8 xflip = ((p->unk_28)->flags & X_FLIP) != 0;
  bool8 yflip = ((p->unk_28)->flags & Y_FLIP) != 0;
  u32 idx = p->work[1];
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SET_XFLIP(p, xflip);
      SET_YFLIP(p, yflip);
      SetSpriteAnimation(p, p->anim74[idx]);
      if (xflip) idx = 2 - idx;
      (p->d).x = PIXEL(idx - 1) + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->d).y = -PIXEL(2) - (RANDOM(RNG_0202f388) & 0x100);
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[2]++;
      if (p->work[2] & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += PIXEL(1) / 8;
      _FUN_0801779c(p);
      if (FUN_080098a4((p->coord).x, (p->coord).y)) {
        if (p->unk_79 == 0) {
          CreateSmoke(3, &p->coord);
        } else {
          CreateSmoke(2, &p->coord);
        }
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

static void Necro_Update_2(NecroVFX* p) {
  bool8 xflip = ((p->unk_28)->flags & X_FLIP) != 0;
  bool8 yflip = ((p->unk_28)->flags & Y_FLIP) != 0;
  u32 idx = p->work[1];
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SET_XFLIP(p, xflip);
      SET_YFLIP(p, yflip);
      SetSpriteAnimation(p, p->anim74[idx]);
      if (xflip) idx = 2 - idx;
      (p->d).x = PIXEL(idx - 1) + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->d).y = -PIXEL(2) - (RANDOM(RNG_0202f388) & 0x100);
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[2]++;
      if (p->work[2] & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += PIXEL(1) / 4;
      _FUN_0801779c(p);
      if ((p->work[2] > 24) && FUN_080098a4((p->coord).x, (p->coord).y)) {
        if (p->unk_79 == 0) {
          CreateSmoke(3, &p->coord);
        } else {
          CreateSmoke(2, &p->coord);
        }
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

static void Necro_Update_3(NecroVFX* p) {
  bool8 xflip = ((p->unk_28)->flags & X_FLIP) != 0;
  bool8 yflip = ((p->unk_28)->flags & Y_FLIP) != 0;
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SET_XFLIP(p, xflip);
      SET_YFLIP(p, yflip);
      SetSpriteAnimation(p, p->anim74[0]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += (p->unk_coord).y;
      p->work[2]--;
      if (p->work[2] == 0) SET_VFX_ROUTINE(p, ENTITY_DIE);
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

static void Necro_Update_4(NecroVFX* p) {
  bool8 xflip = ((p->unk_28)->flags & X_FLIP) != 0;
  bool8 yflip = ((p->unk_28)->flags & Y_FLIP) != 0;
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SET_XFLIP(p, xflip);
      SET_YFLIP(p, yflip);
      SetSpriteAnimation(p, p->anim74[0]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      (p->d).y += (p->unk_coord).y;
      p->work[2]--;
      if (p->work[2] == 0 || FUN_080098a4((p->coord).x, (p->coord).y)) {
        CreateSmoke(1, &p->coord);
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

static const u8 sNecro_InitModes[5] = {0, 1, 2, 3, 4};  // 0x0836ea84
