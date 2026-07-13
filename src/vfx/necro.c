#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

/*
  雑魚敵が死んだあと、爆散始まるまでの状態
  雑魚敵が切断死した際の、切断された方の片方
*/
struct NecroVFX {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  motion_t* motions;  // 0x74
  u8 unk_04;          // 0x78
  u8 unk_05;          // 0x79
  u8 unk_06[10];
};
static_assert(sizeof(struct NecroVFX) == sizeof(struct VFX));

static const u8 sInitModes[5];

static void Necro_Init(struct Entity* p);
static void Necro_Update(struct NecroVFX* p);
static void Necro_Die(struct Entity* p);

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
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 0, (p->s).work[1] = i;
      (p->s).unk_28 = e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      p->unk_04 = 1, p->unk_05 = 0;
    }
  }
}

void FUN_080b7ffc(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 0, (p->s).work[1] = i;
      (p->s).unk_28 = e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      p->unk_04 = 0, p->unk_05 = 0;
    }
  }
}

void FUN_080b8080(struct Enemy* e, Coords32* c, motion_t* motions, u8 len, u8 r4) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 0, (p->s).work[1] = i;
      (p->s).unk_28 = (void*)e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      (p->s).palID = r4;
      p->unk_04 = 1, p->unk_05 = 0;
    }
  }
}

static void Unused_080b8114(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 1, (p->s).work[1] = i;
      (p->s).unk_28 = e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      p->unk_04 = 1, p->unk_05 = 0;
    }
  }
}

void FUN_080b81a0(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 1, (p->s).work[1] = i;
      (p->s).unk_28 = e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      p->unk_04 = 0, p->unk_05 = 0;
    }
  }
}

void FUN_080b822c(struct Enemy* e, Coords32* c, motion_t* motions, u8 len, u8 r4) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 1, (p->s).work[1] = i;
      (p->s).unk_28 = (void*)e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      p->unk_04 = 1, p->unk_05 = 1;
      (p->s).palID = r4;
    }
  }
}

void FUN_080b82c0(struct Entity* e, Coords32* c, motion_t* motions, u8 len) {
  s32 i;
  for (i = 0; i < len; i++) {
    struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_NECRO);
      (p->s).work[0] = 2, (p->s).work[1] = i;
      (p->s).unk_28 = e;
      p->motions = motions;
      (p->s).coord.x = c->x, (p->s).coord.y = c->y;
      p->unk_04 = 1, p->unk_05 = 0;
    }
  }
}

void FUN_080b834c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 3;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    p->unk_04 = 1, p->unk_05 = 0;
  }
}

void FUN_080b83d4(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 3;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    p->unk_04 = 0, p->unk_05 = 0;
  }
}

void FUN_080b8454(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 3;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    (p->s).renderPrio = renderPrio;
    p->unk_04 = 1, p->unk_05 = 0;
  }
}

void FUN_080b84f4(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 4;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    p->unk_04 = 1, p->unk_05 = 0;
  }
}

void FUN_080b857c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 4;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    p->unk_04 = 0, p->unk_05 = 0;
  }
}

void FUN_080b85fc(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 4;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    (p->s).renderPrio = renderPrio;
    p->unk_04 = 1, p->unk_05 = 0;
  }
}

void FUN_080b869c(struct Entity* e, Coords32* c, Coords32* dc, s32 y, motion_t* motions, u8 frame, u8 renderPrio, u8 palID) {
  struct NecroVFX* p = (struct NecroVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_NECRO);
    (p->s).work[0] = 4;
    (p->s).unk_28 = e;
    p->motions = motions;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = dc->x, (p->s).d.y = dc->y;
    (p->s).unk_coord.y = y;
    (p->s).work[2] = frame;
    (p->s).renderPrio = renderPrio, (p->s).palID = palID;
    p->unk_04 = 1, p->unk_05 = 0;
  }
}

// --------------------------------------------

static void Necro_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  Necro_Update((void*)p);
}

static void FUN_080b8804(struct NecroVFX* p);
void FUN_080b8984(struct VFX* p);
void FUN_080b8af8(struct VFX* p);
void FUN_080b8c74(struct VFX* p);
void FUN_080b8d4c(struct VFX* p);

static void Necro_Update(struct NecroVFX* p) {
  // clang-format off
  static const EntityFunc sUpdates[5] = {
      (void*)FUN_080b8804,
      (void*)FUN_080b8984,
      (void*)FUN_080b8af8,
      (void*)FUN_080b8c74,
      (void*)FUN_080b8d4c,
  };
  // clang-format on

  if (IS_METTAUR && p->unk_04 != 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).mode[1]])((void*)p);
}

static void Necro_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

// 0x080b8804
static void FUN_080b8804(struct NecroVFX* p) {
  bool8 xflip = (((p->s).unk_28)->flags & X_FLIP) != 0;
  bool8 yflip = (((p->s).unk_28)->flags & Y_FLIP) != 0;
  u32 idx = (p->s).work[1];
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).flags |= DISPLAY;
      SET_XFLIP(p, xflip);
      SET_YFLIP(p, yflip);
      SetSpriteAnimation(p, p->motions[idx]);
      if (xflip) idx = 2 - idx;
      (p->s).d.x = PIXEL(idx - 1) + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
      (p->s).d.y = -(RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(2);
      (p->s).work[2] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->s).work[2]++;
      if ((p->s).work[2] & 1) {
        (p->s).flags |= DISPLAY;
      } else {
        (p->s).flags &= ~DISPLAY;
      }
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += PIXEL(1) / 4;
      FUN_0801779c(&p->s);
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) && (p->s).d.y > 0) {
        if (p->unk_05 == 0) {
          CreateSmoke(3, &(p->s).coord);
        } else {
          CreateSmoke(2, &(p->s).coord);
        }
        SET_VFX_ROUTINE(&p->s, ENTITY_DIE);
      }
      break;
    }
  }
}

INCASM("asm/vfx/necro.inc");

static const u8 sInitModes[5] = {0, 1, 2, 3, 4};
