#include "collision.h"
#include "global.h"
#include "solid.h"

void FUN_080dddb0(struct Solid* p);
void FUN_080dde48(struct Solid* p);
NON_MATCH void FUN_080ddec0(struct Solid* p);
void FUN_080ddef4(struct Solid* p);


static const s32 s32_ARRAY_083716d0[10];
static const s32 s32_ARRAY_083716f8[10];
void createCielMiniObj(struct Entity* e, u8 a1, u8 a2) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_UNK_042);
    (p->s).unk_28 = e;
    (p->s).work[0] = a1;
    (p->s).work[1] = a2;
  }
}

void CielMinigameObj_Init(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    FUN_080dddb0(p);
  } else {
    FUN_080dde48(p);
  }
}

void CielMinigameObj_Update(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    FUN_080ddec0(p);
  } else {
    FUN_080ddef4(p);
  }
}

void CielMinigameObj_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080dddb0(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(0xE8, 0x0A));
  UpdateEntityAnim(&p->s);
  SET_XFLIP(p, 0);
  ((p->s).spr).oam.priority = 1;
  (p->s).coord.x = s32_ARRAY_083716d0[(p->s).work[1]];
  (p->s).coord.y = s32_ARRAY_083716f8[(p->s).work[1]];
  CielMinigameObj_Update(p);
}

void FUN_080dde48(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(0xE8, 0x0C));
  UpdateEntityAnim(&p->s);
  SET_XFLIP(p, 0);
  ((p->s).spr).oam.priority = 1;
  CielMinigameObj_Update(p);
}

NON_MATCH void FUN_080ddec0(struct Solid* p) {
#if MODERN
  struct Entity* q = (p->s).unk_28;
  UpdateEntityAnim(&p->s);
  if (((u16*)((u8*)q + 0xDF0))[(p->s).work[1]] == 0xFF) {
    (p->s).flags |= DISPLAY;
  } else {
    (p->s).flags &= ~DISPLAY;
  }
#else
  INCCODE("asm/solid/ciel_mg_obj_ddec0.inc");
#endif
}

void FUN_080ddef4(struct Solid* p) {
  struct Entity* q = (p->s).unk_28;
  u8* b = (u8*)q + 0xDCC;
  u8 idx = *((u8*)q + 0xDEE);
  (p->s).coord.x = s32_ARRAY_083716d0[idx];
  (p->s).coord.y = s32_ARRAY_083716f8[idx];
  if ((p->s).mode[1] == 0) {
    u8 v = *(b + 5);
    if (v == 1) {
      SetMotion(&p->s, MOTION(0xE8, 0x0B));
      (p->s).mode[1] = v;
    }
  } else {
    u8 v = *(b + 5);
    if (v == 0) {
      SetMotion(&p->s, MOTION(0xE8, 0x0C));
      (p->s).mode[1] = v;
    }
  }
  UpdateEntityAnim(&p->s);
}

// シエルのミニゲームで使う様々なオブジェクト

void CielMinigameObj_Init(struct Solid* p);
void CielMinigameObj_Update(struct Solid* p);
void CielMinigameObj_Die(struct Solid* p);

// clang-format off
const SolidRoutine gCielMinigameObjRoutine = {
    [ENTITY_INIT] =      CielMinigameObj_Init,
    [ENTITY_UPDATE] =    CielMinigameObj_Update,
    [ENTITY_DIE] =       CielMinigameObj_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static const s32 s32_ARRAY_083716d0[10] = {
    0x00002800, 0x00006800, 0x00004800, 0x00008800, 0x00002800, 0x00006800, 0x00004800, 0x00008800, 0x00002800, 0x00006800,
};

static const s32 s32_ARRAY_083716f8[10] = {
    0x00002800, 0x00002800, 0x00003800, 0x00003800, 0x00004800, 0x00004800, 0x00005800, 0x00005800, 0x00006800, 0x00006800,
};
