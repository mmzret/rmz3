#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

/*
  雑魚敵が死んだあと、爆散始まるまでの状態
  雑魚敵が切断死した際の、切断された方の片方
*/

static const VFXFunc sUpdates[5];
static const u8 sInitModes[5];

static void Necro_Init(struct VFX *vfx);
static void Necro_Update(struct VFX *vfx);
static void Necro_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gNecroRoutine = {
    [ENTITY_INIT] =      Necro_Init,
    [ENTITY_UPDATE] =    Necro_Update,
    [ENTITY_DIE] =       Necro_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void FUN_080b7f70(struct CollidableEntity *p, struct Coord *c, motion_t *motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 0;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->props).necro.unk_04 = 1;
      (vfx->props).necro.unk_05 = 0;
    }
  }
}

void FUN_080b7ffc(struct CollidableEntity *p, struct Coord *c, motion_t *motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 0;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->props).necro.unk_04 = 0;
      (vfx->props).necro.unk_05 = 0;
    }
  }
}

void FUN_080b8080(struct Enemy *p, struct Coord *c, motion_t *motions, u8 len, u8 r4) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 0;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->s).palID = r4;
      (vfx->props).necro.unk_04 = 1;
      (vfx->props).necro.unk_05 = 0;
    }
  }
}

void Unused_080b8114(struct CollidableEntity *p, struct Coord *c, motion_t *motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 1;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->props).necro.unk_04 = 1;
      (vfx->props).necro.unk_05 = 0;
    }
  }
}

void FUN_080b81a0(struct CollidableEntity *p, struct Coord *c, motion_t *motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 1;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->props).necro.unk_04 = 0;
      (vfx->props).necro.unk_05 = 0;
    }
  }
}

void FUN_080b822c(struct Enemy *p, struct Coord *c, motion_t *motions, u8 len, u8 r4) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 1;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->props).necro.unk_04 = 1;
      (vfx->props).necro.unk_05 = 1;
      (vfx->s).palID = r4;
    }
  }
}

void FUN_080b82c0(struct CollidableEntity *p, struct Coord *c, motion_t *motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (vfx != NULL) {
      (vfx->s).taskCol = 1;
      INIT_VFX_ROUTINE(vfx, VFX_NECRO);
      (vfx->s).tileNum = 0;
      (vfx->s).palID = 0;
      (vfx->s).work[0] = 2;
      (vfx->s).work[1] = i;
      (vfx->s).unk_28 = &p->s;
      (vfx->props).necro.motions = motions;
      (vfx->s).coord.x = c->x;
      (vfx->s).coord.y = c->y;
      (vfx->props).necro.unk_04 = 1;
      (vfx->props).necro.unk_05 = 0;
    }
  }
}

void FUN_080b834c(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 3;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->props).necro.unk_04 = 1;
    (vfx->props).necro.unk_05 = 0;
  }
}

void FUN_080b83d4(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 3;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->props).necro.unk_04 = 0;
    (vfx->props).necro.unk_05 = 0;
  }
}

void FUN_080b8454(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame, u8 taskCol) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 3;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->s).taskCol = taskCol;
    (vfx->props).necro.unk_04 = 1;
    (vfx->props).necro.unk_05 = 0;
  }
}

void FUN_080b84f4(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 4;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->props).necro.unk_04 = 1;
    (vfx->props).necro.unk_05 = 0;
  }
}

void FUN_080b857c(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 4;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->props).necro.unk_04 = 0;
    (vfx->props).necro.unk_05 = 0;
  }
}

void FUN_080b85fc(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame, u8 taskCol) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 4;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->s).taskCol = taskCol;
    (vfx->props).necro.unk_04 = 1;
    (vfx->props).necro.unk_05 = 0;
  }
}

void FUN_080b869c(struct CollidableEntity *p, struct Coord *c, struct Coord *dc, s32 y, motion_t *motions, u8 frame, u8 taskCol, u8 palID) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = 4;
    (vfx->s).unk_28 = &p->s;
    (vfx->props).necro.motions = motions;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->s).d.x = dc->x;
    (vfx->s).d.y = dc->y;
    (vfx->s).unk_coord.y = y;
    (vfx->s).work[2] = frame;
    (vfx->s).taskCol = taskCol;
    (vfx->s).palID = palID;
    (vfx->props).necro.unk_04 = 1;
    (vfx->props).necro.unk_05 = 0;
  }
}

// --------------------------------------------

static void Necro_Init(struct VFX *vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  (vfx->s).mode[1] = sInitModes[(vfx->s).work[0]];
  (vfx->s).flags |= FLIPABLE;
  (vfx->s).flags |= DISPLAY;
  InitNonAffineMotion(&vfx->s);
  Necro_Update(vfx);
}

// --------------------------------------------

void FUN_080b8804(struct VFX *p);
void FUN_080b8984(struct VFX *p);
void FUN_080b8af8(struct VFX *p);
void FUN_080b8c74(struct VFX *p);
void FUN_080b8d4c(struct VFX *p);

static void Necro_Update(struct VFX *vfx) {
  // clang-format off
  static const VFXFunc sUpdates[5] = {
      FUN_080b8804,
      FUN_080b8984,
      FUN_080b8af8,
      FUN_080b8c74,
      FUN_080b8d4c,
  };
  // clang-format on

  if (IS_METTAUR && (vfx->props).necro.unk_04 != 0) {
    (vfx->s).flags &= ~DISPLAY;
    (vfx->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(vfx, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(vfx->s).mode[1]])(vfx);
}

// --------------------------------------------

static void Necro_Die(struct VFX *vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
  return;
}

// --------------------------------------------

INCASM("asm/vfx/necro.inc");

static const u8 sInitModes[5] = {0, 1, 2, 3, 4};
