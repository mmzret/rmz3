#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

void FUN_080ce538(struct Solid* p);

// ロコモIF戦で出現する台座
typedef struct {
  COLLISION_OBJECT_HDR;
  u16 unk_b4;     // 0xB4
  u8 unk_b6[14];  // 0xB6
} LocomoIFPlatform;
static_assert(sizeof(LocomoIFPlatform) == sizeof(struct Solid));

// ------------------------------------------------------------------------------------------------------------------------------------

void LocomoIFPlatform_Init(LocomoIFPlatform* p);
void LocomoIFPlatform_Update(LocomoIFPlatform* p);
void LocomoIFPlatform_Die(LocomoIFPlatform* p);

// clang-format off
const SolidRoutine gLocomoIFPlatformRoutine = {
    [ENTITY_INIT] =      (void*)LocomoIFPlatform_Init,
    [ENTITY_UPDATE] =    (void*)LocomoIFPlatform_Update,
    [ENTITY_DIE] =       (void*)LocomoIFPlatform_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateLocomoIFPlatform(struct Boss* locomoif) {
  s32 i;
  for (i = 0; i < 2; i++) {
    LocomoIFPlatform* p = (LocomoIFPlatform*)AllocEntityLast(gSolidHeaderPtr);
    if (p != NULL) {
      INIT_SOLID_ROUTINE(p, SOLID_LOCOMOIF_PLATFORM);
      p->work[0] = 0;
      p->unk_b4 = (i << 15);
      p->unk_28 = (void*)locomoif;
    }
  }
}

INCASM("asm/solid/locomoif_platform_a.inc");

void FUN_080ce80c(LocomoIFPlatform* p) {
  struct Entity* owner = p->unk_28;
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x40;
      p->mode[2]++;
      // fallthrough
    case 1: {
      s32 t;
      u32 zero;
      u16* q;
      s32 dx;
      u32 hv;
      dx = p->d.x - 4;
      p->d.x = dx;
      q = &p->unk_b4;
      hv = *q + dx;
      zero = 0;
      asm("" : "+l"(zero));
      *q = hv;
      FUN_080ce538((struct Solid*)p);
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) == 0) {
        StopSound(0x10B);
        *(u8*)((u8*)owner + 0xbd) = zero;
        p->mode[1] = zero;
        p->mode[2] = zero;
      }
      break;
    }
  }
}

// --------------------------------------------

void nop_080ce70c(LocomoIFPlatform* p);

const SolidFunc sLocomoIFPlatformUpdates1[4] = {
    (SolidFunc)nop_080ce70c,
    (SolidFunc)nop_080ce70c,
    (SolidFunc)nop_080ce70c,
    (SolidFunc)nop_080ce70c,
};

// --------------------------------------------

void FUN_080ce710(LocomoIFPlatform* p);
void FUN_080ce7a4(LocomoIFPlatform* p);
void FUN_080ce760(LocomoIFPlatform* p);
void FUN_080ce80c(LocomoIFPlatform* p);

const SolidFunc sLocomoIFPlatformUpdates2[4] = {
    (SolidFunc)FUN_080ce710,
    (SolidFunc)FUN_080ce7a4,
    (SolidFunc)FUN_080ce760,
    (SolidFunc)FUN_080ce80c,
};

// --------------------------------------------

const struct Collision sLocomoIFPlatformCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 255,
  nature : BODY_NATURE_B2,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(13), PIXEL(47), PIXEL(22)},
};

const u8 u8_ARRAY_08370310[4] = {0, 0, 0, 0};

const struct Rect Rect_08370314 = {PIXEL(0), PIXEL(11), PIXEL(48), PIXEL(22)};
