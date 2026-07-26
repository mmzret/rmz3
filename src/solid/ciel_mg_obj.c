#include "collision.h"
#include "global.h"
#include "solid.h"

void CielMinigameObj_Die(struct Solid* p);

void CielMinigameObj_Update(struct Solid* p);

void CielMinigameObj_Init(struct Solid* p);

void FUN_080dddb0(struct Solid* p);
void FUN_080dde48(struct Solid* p);
void FUN_080ddec0(struct Solid* p);
void FUN_080ddef4(struct Solid* p);

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

INCASM("asm/solid/ciel_mg_obj_a.inc");

// シエルのミニゲームで使う様々なオブジェクト

void CielMinigameObj_Init(struct Solid* p);
void CielMinigameObj_Update(struct Solid* p);
void CielMinigameObj_Die(struct Solid* p);

// clang-format off
const SolidRoutine gCielMinigameObjRoutine = {
    [ENTITY_INIT] =      (void*)CielMinigameObj_Init,
    [ENTITY_UPDATE] =    (void*)CielMinigameObj_Update,
    [ENTITY_DIE] =       (void*)CielMinigameObj_Die,
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
