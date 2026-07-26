#include "global.h"
#include "vfx.h"

// OmegaZX関連
typedef struct {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  // props (16bytes, offset: 0x74..)
  Coords32 c_74;  // 0x74
  u8 unk_7c[4];   // 0x7C
  u16 unk_80;     // 0x80
  u16 unk_82;     // 0x82
} VFX69;
static_assert(sizeof(VFX69) == sizeof(struct VFX));

static void Ghost69_Init(VFX69* p);
static void Ghost69_Update(VFX69* p);
static void Ghost69_Die(VFX69* p);

// clang-format off
const VFXRoutine gGhost69Routine = {
    [ENTITY_INIT] =      (void*)Ghost69_Init,
    [ENTITY_UPDATE] =    (void*)Ghost69_Update,
    [ENTITY_DIE] =       (void*)Ghost69_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* FUN_080c4e58(Coords32* c, void* _, Entity* e) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    p->work[0] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = e;
  }
  return (Entity*)p;
}

Entity* FUN_080c4eac(Entity* e, Coords32* c, u8 n) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    p->work[0] = 1, p->work[1] = n;
    (p->unk_coord).x = c->x, (p->unk_coord).y = c->y;
    p->unk_28 = e;
  }
  return (Entity*)p;
}

Entity* FUN_080c4f04(Entity* q, Coords32* c, u8 n) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    p->work[0] = 2, p->work[1] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return (Entity*)p;
}

Entity* FUN_080c4f60(Entity* e, Coords32* c1, Coords32* c2, u8 n) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    p->work[0] = 3, p->work[1] = n;
    (p->unk_coord).x = c1->x, (p->unk_coord).y = c1->y;
    (p->c_74).x = c2->x, (p->c_74).y = c2->y;
    p->unk_28 = e;
  }
  return (Entity*)p;
}

static VFX69* FUN_080c4fc8(Coords32* c) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

static VFX69* FUN_080c5018(Coords32* c, u8 n, u16 unk_80) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->work[1] = n;
    p->unk_80 = unk_80;
  }
  return p;
}

static VFX69* FUN_080c5078(Coords32* c, u8 n, u16 unk_82, u16 unk_80) {
  VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->work[1] = n;
    p->unk_82 = unk_82;
    p->unk_80 = unk_80;
  }
  return p;
}

static void Ghost69_Init(VFX69* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = p->work[0];
  p->mode[2] = 0, p->mode[3] = 0;
  Ghost69_Update((VFX69*)p);
}

void FUN_080c5144(VFX69* p);
void FUN_080c521c(VFX69* p);
void FUN_080c5328(VFX69* p);
void FUN_080c53b8(VFX69* p);
void nop_080c552c(VFX69* p);
void FUN_080c5530(VFX69* p);
void FUN_080c55bc(VFX69* p);

static void Ghost69_Update(VFX69* p) {
  // clang-format off
  static void (*const sGhost69Updates[7])(VFX69*) = {
      FUN_080c5144,
      FUN_080c521c,
      FUN_080c5328,
      FUN_080c53b8,
      nop_080c552c,
      FUN_080c5530,
      FUN_080c55bc,
  }; // 0x0836F6F4
  // clang-format on
  (sGhost69Updates[p->mode[1]])((void*)p);
}

static void Ghost69_Die(VFX69* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_69_a.inc");

void nop_080c552c(VFX69* p) {}

INCASM("asm/vfx/unk_69_b.inc");

void FUN_080c55bc(VFX69* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x50;
      p->mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      p->d.y += 0x20;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      p->coord.x += p->d.x;
      if (p->work[2] == 0 || --p->work[2] == 0) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}
