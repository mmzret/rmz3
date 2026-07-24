#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "story.h"

INCASM("asm/enemy/gallisni_a1.inc");

void Gallisni_Die(struct Enemy* p);

bool8 gallisni_080870bc(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 2;
    } else {
      (p->s).mode[1] = 0;
    }
    Gallisni_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/enemy/gallisni_a2.inc");

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  Entity* elfx;          // 0xB4, Element Effect
  u8 unk_b8[12];         // 0xB8
} Gallisni;
static_assert(sizeof(Gallisni) == sizeof(struct Enemy));

static const Coords32 sElementCoord;

void gallisni_080871b4(Gallisni* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    if (((p->body).status & BODY_STATUS_RECOILED)) {
      p->mode[1] = 7, p->mode[2] = 0;
    } else {
      p->elfx = (void*)ApplyElementEffect(0, (Object*)p, &sElementCoord);
      if (p->elfx != NULL) {
        p->mode[1] = 0, p->mode[2] = 0;
      }
    }
  }
}

INCASM("asm/enemy/gallisni_b.inc");

void Gallisni_Init(struct Enemy* p);
void Gallisni_Update(struct Enemy* p);
void Gallisni_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGallisniRoutine = {
    [ENTITY_INIT] =      Gallisni_Init,
    [ENTITY_UPDATE] =    Gallisni_Update,
    [ENTITY_DIE] =       Gallisni_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080873a0(struct Enemy* p);
void nop_0808737c(struct Enemy* p);
void FUN_08087380(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_080873a0,
    nop_0808737c,
    nop_0808737c,
    FUN_08087380,
    FUN_08087380,
    FUN_08087380,
    FUN_08087380,
    nop_0808737c,
};
// clang-format on

void FUN_080873fc(struct Enemy* p);
void FUN_08087434(struct Enemy* p);
void FUN_080874ac(struct Enemy* p);
void FUN_08087518(struct Enemy* p);
void FUN_080875c8(struct Enemy* p);
void FUN_0808772c(struct Enemy* p);
void FUN_0808778c(struct Enemy* p);
void FUN_08087ab0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_080873fc,
    FUN_08087434,
    FUN_080874ac,
    FUN_08087518,
    FUN_080875c8,
    FUN_0808772c,
    FUN_0808778c,
    FUN_08087ab0,
};
// clang-format on

void FUN_080878f0(struct Enemy* p);
void FUN_08087988(struct Enemy* p);
void FUN_08087ab0(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_080878f0,
    FUN_08087988,
    FUN_08087ab0,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(30), PIXEL(14), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 sInitModes[2] = {1, 3};

static const motion_t sMotions[4] = {
    MOTION(103, 8),
    MOTION(103, 9),
    MOTION(103, 10),
    MOTION(103, 6),
};
