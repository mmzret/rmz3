#include "global.h"
#include "vfx.h"

struct VFX69 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  Coords32 c;    // 0x74
  u8 unk_7c[8];  // 0x7C
};
static_assert(sizeof(struct VFX69) == sizeof(struct VFX));

void Ghost69_Init(struct VFX* p);
void Ghost69_Update(struct VFX* p);
void Ghost69_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost69Routine = {
    [ENTITY_INIT] =      Ghost69_Init,
    [ENTITY_UPDATE] =    Ghost69_Update,
    [ENTITY_DIE] =       Ghost69_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* FUN_080c4e58(Coords32* c, void* _, struct Entity* e) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    (p->s).work[0] = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = e;
  }
  return p;
}

struct VFX* FUN_080c4eac(struct Entity* e, Coords32* c, u8 n) {
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    (p->s).work[0] = 1;
    (p->s).work[1] = n;
    (p->s).unk_coord.x = c->x;
    (p->s).unk_coord.y = c->y;
    (p->s).unk_28 = e;
  }
  return p;
}

Entity* FUN_080c4f04(Entity* q, Coords32* c, u8 n) {
  Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    p->work[0] = 2, p->work[1] = n;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = q;
  }
  return p;
}

struct Entity* FUN_080c4f60(struct Entity* e, Coords32* c1, Coords32* c2, u8 n) {
  struct VFX69* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_069);
    (p->s).work[0] = 3, (p->s).work[1] = n;
    (p->s).unk_coord.x = c1->x;
    (p->s).unk_coord.y = c1->y;
    (p->c).x = c2->x, (p->c).y = c2->y;
    (p->s).unk_28 = e;
  }
  return (void*)p;
}

INCASM("asm/vfx/unk_69.inc");

// --------------------------------------------

void FUN_080c5144(struct VFX* p);
void FUN_080c521c(struct VFX* p);
void FUN_080c5328(struct VFX* p);
void FUN_080c53b8(struct VFX* p);
void nop_080c552c(struct VFX* p);
void FUN_080c5530(struct VFX* p);
void FUN_080c55bc(struct VFX* p);

// clang-format off
const VFXFunc sGhost69Updates[7] = {
    FUN_080c5144,
    FUN_080c521c,
    FUN_080c5328,
    FUN_080c53b8,
    nop_080c552c,
    FUN_080c5530,
    FUN_080c55bc,
};
// clang-format on
