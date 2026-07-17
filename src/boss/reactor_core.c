#include "boss.h"
#include "collision.h"
#include "global.h"
#include "script.h"
#include "palette_animation.h"
#include "stagerun.h"

// エネルギー再生施設の炉心(スイッチ押し込み部屋)

static const BossFunc sDeads[1];

INCASM("asm/boss/reactor_core_a.inc");

void ReactorCore_Die(struct Boss* p) {
  StepPaletteAnimation(0xcb);
  StepPaletteAnimation(0xcc);
  (sDeads[(p->s).mode[1]])(p);
}

void ReactorCore_Disappear(struct Boss* p) {
  RemovePaletteAnimation(0xcb);
  RemovePaletteAnimation(0xcc);
  DeleteBoss(p);
}

void nop_08061a74(struct Boss* p) {}

void FUN_08061a78(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(0x8b, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

void FUN_08061aa4(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      if ((p->s).scriptEntity->flags & 1) {
        (p->s).mode[2] = 1;
      }
      break;
    case 1:
      if (!(gStageRun.vm.active & VM_ACTIVE)) {
        (p->s).mode[1] = 0;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_08061adc(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      StopSound(0xe0);
      (p->s).flags2 &= ~0x08;
      EXIT_BODY(p);
      if ((gStageRun.missionStatus & 1) && !(gStageRun.vm.active & VM_ACTIVE)) {
        gStageRun.missionStatus = (gStageRun.missionStatus & 0xfffe) | 0x10;
      }
      (p->s).work[2] = 2;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if (--(p->s).work[2] == 0) {
        gStageRun.vm.active |= 2;
        (p->s).mode[2]++;
      }
      break;
  }
}

void ReactorCore_Init(struct Boss* p);
void ReactorCore_Update(struct Boss* p);
void ReactorCore_Die(struct Boss* p);
void ReactorCore_Disappear(struct Boss* p);

// clang-format off
const BossRoutine gReactorCoreRoutine = {
    [ENTITY_INIT] =      ReactorCore_Init,
    [ENTITY_UPDATE] =    ReactorCore_Update,
    [ENTITY_DIE] =       ReactorCore_Die,
    [ENTITY_DISAPPEAR] = ReactorCore_Disappear,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08061a74(struct Boss* p);

static const BossFunc sUpdates1[2] = {
    nop_08061a74,
    nop_08061a74,
};

void FUN_08061a78(struct Boss* p);
void FUN_08061aa4(struct Boss* p);

static const BossFunc sUpdates2[2] = {
    FUN_08061a78,
    FUN_08061aa4,
};

// --------------------------------------------

void FUN_08061adc(struct Boss* p);

static const BossFunc sDeads[1] = {
    FUN_08061adc,
};

// --------------------------------------------

// 0x083656b0
static const struct Collision sCollisions[1] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(32)},
    },
};

static const struct Rect sSize = {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(26)};
static const u8 sInitModes[4] = {0, 0, 0, 0};
