#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

/*
  ロコモIF戦で出現する台座
*/

// ------------------------------------------------------------------------------------------------------------------------------------

void LocomoIFPlatform_Init(struct Solid* p);
void LocomoIFPlatform_Update(struct Solid* p);
void LocomoIFPlatform_Die(struct Solid* p);

// clang-format off
const SolidRoutine gLocomoIFPlatformRoutine = {
    [ENTITY_INIT] =      LocomoIFPlatform_Init,
    [ENTITY_MAIN] =      LocomoIFPlatform_Update,
    [ENTITY_DIE] =       LocomoIFPlatform_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateLocomoIFPlatform(struct Boss* locomoif) {
  s32 i;
  for (i = 0; i < 2; i++) {
    struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
    if (p != NULL) {
      u16 val;
      (p->s).taskCol = 30;
      INIT_SOLID_ROUTINE(p, SOLID_LOCOMOIF_PLATFORM);
      (p->s).tileNum = 0;
      (p->s).palID = 0;
      (p->s).flags2 |= ENTITY_FLAGS2_B4;
      (p->s).invincibleID = (p->s).uniqueID;
      (p->s).work[0] = 0;
      (p->props).lifp.unk_00 = (i << 15);
      (p->s).unk_28 = &locomoif->s;
    }
  }
}

INCASM("asm/solid/locomoif_platform.inc");

// --------------------------------------------

void nop_080ce70c(struct Solid* p);

const SolidFunc sLocomoIFPlatformUpdates1[4] = {
    nop_080ce70c,
    nop_080ce70c,
    nop_080ce70c,
    nop_080ce70c,
};

// --------------------------------------------

void FUN_080ce710(struct Solid* p);
void FUN_080ce7a4(struct Solid* p);
void FUN_080ce760(struct Solid* p);
void FUN_080ce80c(struct Solid* p);

const SolidFunc sLocomoIFPlatformUpdates2[4] = {
    FUN_080ce710,
    FUN_080ce7a4,
    FUN_080ce760,
    FUN_080ce80c,
};

// --------------------------------------------

const struct Collision sLocomoIFPlatformCollision = {
  kind : DDP,
  layer : 1,
  special : 0,
  damage : 255,
  unk_04 : 0x00,
  element : 0x00,
  nature : 0x04,
  comboLv : 0x00,
  hitzone : 0x00,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000001,
  range : {0x0000, 0x0D00, 0x2F00, 0x1600},
};

const u8 u8_ARRAY_08370310[4] = {0, 0, 0, 0};

const struct Rect Rect_08370314 = {0x0, 0xB00, 0x3000, 0x1600};
