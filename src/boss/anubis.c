#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/anubis.inc");

void Anubis_Init(struct Boss* p);
void Anubis_Update(struct Boss* p);
void Anubis_Die(struct Boss* p);

// clang-format off
const BossRoutine gAnubisRoutine = {
    [ENTITY_INIT] =      Anubis_Init,
    [ENTITY_UPDATE] =    Anubis_Update,
    [ENTITY_DIE] =       Anubis_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080503c8(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[11] = {
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
    nop_080503c8,
};
// clang-format on

void anubisMode0(struct Boss* p);
void anubisNeutral(struct Boss* p);
void anubisMode2(struct Boss* p);
void anubisMode3(struct Boss* p);
void anubisMode4(struct Boss* p);
void anubisMode5(struct Boss* p);
void anubisMode6(struct Boss* p);
void anubisMode7(struct Boss* p);
void anubisMode8(struct Boss* p);
void FUN_08050e44(struct Boss* p);
void anubis_08050f38(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[11] = {
    anubisMode0,
    anubisNeutral,
    anubisMode2,
    anubisMode3,
    anubisMode4,
    anubisMode5,
    anubisMode6,
    anubisMode7,
    anubisMode8,
    FUN_08050e44,
    anubis_08050f38,
};
// clang-format on

// --------------------------------------------

void anubis_08051018(struct Boss* p);
void anubis_080510f0(struct Boss* p);

static const BossFunc sDeads[2] = {
    anubis_08051018,
    anubis_080510f0,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(52)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 6,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(52)},
    },
};

static const u8 sInitModes[4] = {0, 9, 0, 0};
static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};

static const u8 u8_ARRAY_083635c0[9] = {5, 2, 10, 4, 5, 8, 2, 10, 4};
static const u8 u8_ARRAY_083635c9[8] = {2, 2, 2, 2, 3, 3, 3, 3};
static const u8 u8_ARRAY_083635d1[8] = {2, 2, 3, 3, 3, 4, 4, 4};

static const struct Coord sExplosionCoords[2] = {
    {PIXEL(2), -PIXEL(8)},
    {PIXEL(4), -PIXEL(6)},
};
