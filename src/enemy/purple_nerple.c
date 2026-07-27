#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "element.h"

void FUN_08075d3c(struct Enemy* p);

static const Coords32 sElementCoord;

INCASM("asm/enemy/purple_nerple_a_a.inc");

void FUN_08075d3c(struct Enemy* p) {
}

INCASM("asm/enemy/purple_nerple_a_b.inc");

void FUN_08075e8c(struct Enemy* p) {
  struct Entity** slot;
  u32 frozen;

  if ((p->s).work[0] == 0) {
    slot = (struct Entity**)&p->buffer[0];
    if (*slot == NULL && ((p->body).status & 1)) {
      frozen = (p->body).status & 0x20000;
      if (frozen != 0) {
        (p->s).mode[1] = 8;
        (p->s).mode[2] = 0;
      } else {
        *slot = ApplyElementEffect(0, (Object*)p, &sElementCoord);
        if (*slot != NULL) {
          (p->s).mode[1] = 0;
          (p->s).mode[2] = 0;
        }
      }
    }
  }
}

INCASM("asm/enemy/purple_nerple_b.inc");

void PurpleNerple_Init(struct Enemy* p);
void PurpleNerple_Update(struct Enemy* p);
void PurpleNerple_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPurpleNerpleRoutine = {
    [ENTITY_INIT] =      (void*)PurpleNerple_Init,
    [ENTITY_UPDATE] =    (void*)PurpleNerple_Update,
    [ENTITY_DIE] =       (void*)PurpleNerple_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08076140(struct Enemy* p);
void FUN_08076144(struct Enemy* p);
void FUN_08076178(struct Enemy* p);
void FUN_08076198(struct Enemy* p);
void FUN_080761b8(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_083670d0[10] = {
    FUN_080761b8,
    FUN_08076144,
    FUN_08076144,
    FUN_08076140,
    FUN_08076178,
    FUN_08076140,
    FUN_08076198,
    FUN_08076140,
    FUN_08076140,
    FUN_08076178,
};
// clang-format on

// --------------------------------------------

void FUN_08076220(struct Enemy* p);
void FUN_080762ec(struct Enemy* p);
void FUN_080763f8(struct Enemy* p);
void FUN_08076508(struct Enemy* p);
void FUN_08076594(struct Enemy* p);
void FUN_08076780(struct Enemy* p);
void FUN_08076638(struct Enemy* p);
void FUN_08076830(struct Enemy* p);
void FUN_080768e0(struct Enemy* p);
void FUN_08076a50(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_083670f8[10] = {
    FUN_08076220,
    FUN_080762ec,
    FUN_080763f8,
    FUN_08076508,
    FUN_08076594,
    FUN_08076780,
    FUN_08076638,
    FUN_08076830,
    FUN_080768e0,
    FUN_08076a50,
};
// clang-format on

// --------------------------------------------

void FUN_08076b30(struct Enemy* p);
void FUN_08076be4(struct Enemy* p);
void FUN_08076d30(struct Enemy* p);
void FUN_08076d9c(struct Enemy* p);
void FUN_08076df8(struct Enemy* p);
void FUN_080768e0(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08367120[6] = {
    FUN_08076b30,
    FUN_08076be4,
    FUN_08076d30,
    FUN_08076d9c,
    FUN_08076df8,
    FUN_080768e0,
};
// clang-format on

// --------------------------------------------

// 0x08367138
static const struct Collision sCollisions[] = {
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
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(18), PIXEL(22), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(14), PIXEL(14)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(8)};

static const u8 sInitModes[4] = {1, 3, 7, 0};

// clang-format off
// 0x083671ec
static const motion_t sMotions[9] = {
    MOTION(SM042_PURPLE_NERPLE, 0x11),
    MOTION(SM042_PURPLE_NERPLE, 0x12),
    MOTION(SM042_PURPLE_NERPLE, 0x11),
    MOTION(SM042_PURPLE_NERPLE, 0x0D),
    MOTION(SM042_PURPLE_NERPLE, 0x0E),
    MOTION(SM042_PURPLE_NERPLE, 0x0F),
    MOTION(SM042_PURPLE_NERPLE, 0x10),
    MOTION(SM042_PURPLE_NERPLE, 0x11),
    MOTION(SM042_PURPLE_NERPLE, 0x12),
};
// clang-format on
