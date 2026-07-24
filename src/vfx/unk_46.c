#include "global.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// トレテスタ・ケルベリアン関連
// - トレテスタ・ケルベリアンが死んだ際のパーティクル
// - コンテナが壊れる時のパーティクル

void VFX46_Init(struct VFX* vfx);
void VFX46_Update(struct VFX* vfx);
void VFX46_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX46Routine = {
    [ENTITY_INIT] =      (void*)VFX46_Init,
    [ENTITY_UPDATE] =    (void*)VFX46_Update,
    [ENTITY_DIE] =       (void*)VFX46_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x080bec34
struct Entity* FUN_080bec34(struct Entity* e, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_046);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = (void*)e;
  }
  return p;
}

// 0x080bec8c
struct Entity* FUN_080bec8c(Coords32* c, u8 kind, motion_t m, u32 n) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_046);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = n;
  }
  return (void*)p;
}

// 0x080becf8
struct Entity* FUN_080becf8(Coords32* c, u8 kind, motion_t m, u32 n) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_046);
    p->work[0] = kind, p->work[1] = 2;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = n;
  }
  return (void*)p;
}

// 0x080bed5c
struct Entity* FUN_080bed5c(struct Entity* e, Coords32* c, u8 kind, u8 param_4) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_046);
    p->work[0] = kind;
    p->unk_7c = param_4;
    p->work[1] = 2;
    p->coord.x = c->x;
    p->coord.y = c->y;
    p->unk_28 = (void*)e;
  }
  return (void*)p;
}

INCASM("asm/vfx/unk_46_a.inc");

void VFX46_Init(struct VFX* p) {
  EnableSpriteAnimation_Normal(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteTableDynamic(&p->s);
  if ((p->s).work[0] == 0) {
    SET_XFLIP(p, FALSE);
    ((p->s).d).x = PIXEL(1) / 2;
  } else {
    SET_XFLIP(p, TRUE);
    ((p->s).d).x = -PIXEL(1) / 2;
  }
  ((p->s).d).y = 0;

  if ((p->s).work[1] == 0) {
    (p->s).work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 1, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  } else if ((p->s).work[1] == 1) {
    (p->s).work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 0, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  } else if ((p->s).work[1] == 2) {
    (p->s).work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 2, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  } else if ((p->s).work[1] == 3) {
    (p->s).work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 3, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  }
  VFX46_Update(p);
}

INCASM("asm/vfx/unk_46_b.inc");

void FUN_080bef44(struct VFX* vfx);
void FUN_080bf0a0(struct VFX* vfx);
void FUN_080bf17c(struct VFX* vfx);
void FUN_080bf2f0(struct VFX* vfx);

static const VFXFunc sUpdates[4] = {
    FUN_080bef44,
    FUN_080bf0a0,
    FUN_080bf17c,
    FUN_080bf2f0,
};

// clang-format off
static const s32 s32_ARRAY_ARRAY_0836f02c[5][8] = {
    {0x00000120, -0x00000400, -0x000000B0, -0x00000360, -0x000000B0, -0x00000400, 0x00000120, -0x00000260},
    {-0x000000B0, -0x00000260, -0x000000B0, -0x00000400, 0x00000120, -0x00000260, 0x00000120, -0x00000400},
    {-0x000000B0, -0x00000400, 0x00000120, -0x00000360, 0x00000120, -0x00000400, -0x000000B0, -0x00000360},
    {0x00000160, -0x00000260, -0x000000C0, -0x00000400, 0x00000160, -0x00000400, -0x000000C0, -0x00000260},
    {-0x000000E0, -0x00000400, 0x00000180, -0x00000360, -0x000000E0, -0x00000360, 0x00000180, -0x00000400},
};
// clang-format on

static const s32* const PTR_ARRAY_0836f0cc[5] = {
    s32_ARRAY_ARRAY_0836f02c[0], s32_ARRAY_ARRAY_0836f02c[1], s32_ARRAY_ARRAY_0836f02c[2], s32_ARRAY_ARRAY_0836f02c[3], s32_ARRAY_ARRAY_0836f02c[4],
};
