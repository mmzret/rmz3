#include "global.h"
#include "vfx.h"

static void Ghost64_Init(struct Entity* p);
static void Ghost64_Update(struct Entity* p);
static void Ghost64_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost64Routine = {
    [ENTITY_INIT] =      (void*)Ghost64_Init,
    [ENTITY_UPDATE] =    (void*)Ghost64_Update,
    [ENTITY_DIE] =       (void*)Ghost64_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void oz_080c39a0(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->unk_28 = (void*)e;
    p->work[0] = 0;
  }
}

void FUN_080c39e8(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->unk_28 = (void*)e;
    p->work[0] = 1;

    // (p->coord).x = (e->coord).x + ((e->flags & X_FLIP) ? -PIXEL(12) : PIXEL(12));
    {
      s32 ex = (e->coord).x;
      s32 x = (p->coord).x = ex + PIXEL(12);
      if ((e->flags & X_FLIP) != 0) {
        x = ex - PIXEL(12);
      }
      (p->coord).x = x;
    }
    (p->coord).y = (e->coord).y - PIXEL(32);
  }
}

void oz_Rekkoha_080c3a5c(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->unk_28 = (void*)e;
    p->work[0] = 3;

    // (p->coord).x = (e->coord).x + ((e->flags & X_FLIP) ? -PIXEL(12) : PIXEL(12));
    {
      s32 ex = (e->coord).x;
      s32 x = (p->coord).x = ex + PIXEL(12);
      if ((e->flags & X_FLIP) != 0) {
        x = ex - PIXEL(12);
      }
      (p->coord).x = x;
    }
    (p->coord).y = (e->coord).y - PIXEL(32);
  }
}

// 0x080c3ad4
void ozMessenkou2(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->work[0] = 2;

    // (p->coord).x = (e->coord).x + ((e->flags & X_FLIP) ? PIXEL(5) : -PIXEL(5));
    {
      s32 ex = (e->coord).x;
      s32 x = (p->coord).x = ex - PIXEL(5);
      if ((e->flags & X_FLIP) != 0) {
        x = ex + PIXEL(5);
      }
      (p->coord).x = x;
    }
    (p->coord).y = (e->coord).y + PIXEL(1);
  }
}

void oz_080c3b44(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->work[0] = 4;
    (p->coord).x = (e->coord).x;
    (p->coord).y = (e->coord).y - PIXEL(22);
  }
}

void oz_080c3b9c(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->work[0] = 5;
    (p->coord).x = (e->coord).x;
    (p->coord).y = (e->coord).y - PIXEL(22);
  }
}

void FUN_080c3bf4(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_064);
    p->work[0] = 6;
    (p->coord).x = x, (p->coord).y = y;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void Ghost64_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  Ghost64_Update(p);
}

void FUN_080c3cbc(struct VFX* p);
void FUN_080c3d84(struct VFX* p);
void FUN_080c3e98(struct VFX* p);
void FUN_080c3f1c(struct VFX* p);
void FUN_080c3f74(struct VFX* p);
void FUN_080c3ffc(struct VFX* p);
void FUN_080c4074(struct VFX* p);
void FUN_080c40ec(struct VFX* p);
void FUN_080c4144(struct VFX* p);

static void Ghost64_Update(struct Entity* p) {
  // clang-format off
  static const VFXFunc sUpdates[9] = {
      (void*)FUN_080c3cbc,
      (void*)FUN_080c3d84,
      (void*)FUN_080c3e98,
      (void*)FUN_080c3f1c,
      (void*)FUN_080c3f74,
      (void*)FUN_080c3ffc,
      (void*)FUN_080c4074,
      (void*)FUN_080c40ec,
      (void*)FUN_080c4144,
  };
  // clang-format on
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void Ghost64_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

INCASM("asm/vfx/unk_64_a.inc");

void FUN_080c3f1c(struct VFX* v) {
  u8 state;

  switch ((v->s).mode[2]) {
    case 0:
      SetMotion(&v->s, MOTION(0x80, 4));
      (v->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&v->s);
      state = (v->s).motion.state;
      if (state == 3) {
        (v->s).flags &= ~DISPLAY;
        (v->s).flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(v, ENTITY_DISAPPEAR);
      }
      break;
  }
}

INCASM("asm/vfx/unk_64_b.inc");

void FUN_080c40ec(struct VFX* v) {
  u8 state;

  switch ((v->s).mode[2]) {
    case 0:
      SetMotion(&v->s, MOTION(0x80, 6));
      (v->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&v->s);
      state = (v->s).motion.state;
      if (state == 3) {
        (v->s).flags &= ~DISPLAY;
        (v->s).flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(v, ENTITY_DISAPPEAR);
      }
      break;
  }
}

INCASM("asm/vfx/unk_64_c.inc");

static const u8 sInitModes[7] = {8, 2, 3, 4, 5, 6, 7};
