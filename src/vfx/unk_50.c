#include "global.h"
#include "vfx.h"

// キュービットフォクスター の炎に関係
typedef struct {
  ENTITY_HDR;
  ENTITY_SPRITE;
  // props (16bytes, offset: 0x74..)
  u8 unk_74[8];
  u8 unk_7c;
  u8 unk_7d[7];
} VFX50;
static_assert(sizeof(VFX50) == sizeof(struct VFX));

void VFX50_Init(struct VFX* p);
void VFX50_Update(struct VFX* p);
void VFX50_Die(struct VFX* p);

// clang-format off
const VFXRoutine gVFX50Routine = {
    [ENTITY_INIT] =      (void*)VFX50_Init,
    [ENTITY_UPDATE] =    (void*)VFX50_Update,
    [ENTITY_DIE] =       (void*)VFX50_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080c078c(struct Entity* q, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_050);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

struct Entity* FUN_080c07e4(Coords32* c1, Coords32* c2, u8 xflip, u8 unk7c) {
  VFX50* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_050);
    p->work[0] = xflip;
    p->unk_7c = unk7c;
    p->work[1] = 1;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return (void*)p;
}

INCASM("asm/vfx/unk_50.inc");

void FUN_080c094c(struct VFX* p);
void FUN_080c09c8(struct VFX* p);

static const VFXFunc sUpdates[2] = {
    FUN_080c094c,
    FUN_080c09c8,
};

static const motion_t sVFX50Animations[3] = {
    MOTION(DM177_CUBIT_FLAME, 9),
    MOTION(DM177_CUBIT_FLAME, 10),
    MOTION(DM177_CUBIT_FLAME, 11),
};  // 0x0836f180
