#include "boss.h"
#include "collision.h"
#include "global.h"
#include "element.h"

static const BossFunc sDeads[1];
static const Coords32 sElementCoord;
static const BossFunc sUpdates1[7];
static const BossFunc sUpdates2[7];
bool8 tryKillLocomoIF(struct Boss* p);

void FUN_08054adc(struct Boss* p);

void nop_08054ad8(struct Boss* p);

void LocomoIF_Die(struct Boss* p);

void LocomoIF_Update(struct Boss* p);

void nop_0805474c(struct Boss* p) {}

INCASM("asm/boss/locomo_if_a.inc");

void LocomoIF_Update(struct Boss* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  struct Entity* e;
  if (*slot != NULL) {
    if (!isKilled(*slot)) {
      goto next;
    }
    e = NULL;
  } else {
    if (!((p->body).status & 1)) {
      goto next;
    }
    if ((*(u8*)((u8*)p + 0x97) & 0xf0) != 0x20) {
      goto next;
    }
    e = ApplyElementEffect(0x17, (Object*)p, &sElementCoord);
  }
  *slot = e;
next:
  if (tryKillLocomoIF(p)) {
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

void LocomoIF_Die(struct Boss* p) {
  (sDeads[p->mode[1]])((void*)p);
}

void nop_08054ad8(struct Boss* p) {}

void FUN_08054adc(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x1e;
      SetSpriteAnimation(p, MOTION(0x54, 0));
      p->mode[2]++;
      // fallthrough
    case 1:
      p->work[2]--;
      if (p->work[2] == 0) {
        p->mode[1] = 2;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

INCASM("asm/boss/locomo_if_b.inc");

void LocomoIF_Init(struct Boss* p);
void LocomoIF_Update(struct Boss* p);
void LocomoIF_Die(struct Boss* p);

// clang-format off
const BossRoutine gLocomoIFRoutine = {
    [ENTITY_INIT] =      (BossFunc)LocomoIF_Init,
    [ENTITY_UPDATE] =    (BossFunc)LocomoIF_Update,
    [ENTITY_DIE] =       (BossFunc)LocomoIF_Die,
    [ENTITY_DISAPPEAR] = (BossFunc)DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08054ad8(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[7] = {
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
};
// clang-format on

void FUN_08054adc(struct Boss* p);
void FUN_08054b20(struct Boss* p);
void FUN_08054b98(struct Boss* p);
void FUN_08054cac(struct Boss* p);
void FUN_08054e94(struct Boss* p);
void locomoIF_08054f18(struct Boss* p);
void FUN_08054fcc(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[7] = {
    FUN_08054adc,
    FUN_08054b20,
    FUN_08054b98,
    FUN_08054cac,
    FUN_08054e94,
    locomoIF_08054f18,
    FUN_08054fcc,
};
// clang-format on

// --------------------------------------------

void locomoIF_080550ec(struct Boss* p);

static const BossFunc sDeads[1] = {
    locomoIF_080550ec,
};

// --------------------------------------------

// 0x08363af8
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
};

static const u8 sInitModes[2] = {1, 0};
static const Coords32 sElementCoord = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(0x54, 0x9),
    MOTION(0x54, 0xA),
    MOTION(0x54, 0xA),
};
