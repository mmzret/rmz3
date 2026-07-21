#include "boss/anubis.h"

#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/anubis.inc");

void Anubis_Init(Anubis* p);
void Anubis_Update(Anubis* p);
void Anubis_Die(Anubis* p);

// clang-format off
const BossRoutine gAnubisRoutine = {
    [ENTITY_INIT] =      (void*)Anubis_Init,
    [ENTITY_UPDATE] =    (void*)Anubis_Update,
    [ENTITY_DIE] =       (void*)Anubis_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080503c8(Anubis* p);

// clang-format off
static void (*const sUpdates1[11])(Anubis*) = {
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

void anubisMode0(Anubis* p);
void anubisNeutral(Anubis* p);
void anubisMode2(Anubis* p);
void anubisMode3(Anubis* p);
void anubisMode4(Anubis* p);
void anubisMode5(Anubis* p);
void anubisMode6(Anubis* p);
void anubisMode7(Anubis* p);
void anubisMode8(Anubis* p);
void FUN_08050e44(Anubis* p);
void anubis_08050f38(Anubis* p);

// clang-format off
static void (*const sUpdates2[11])(Anubis*) = {
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

void anubis_08051018(Anubis* p);
void anubis_080510f0(Anubis* p);

static void (*const sDeads[2])(Anubis*) = {
    anubis_08051018,
    anubis_080510f0,
};

// --------------------------------------------

// 0x0836356c
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(52)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(52)},
    },
};

// 0x083635b4
static const u8 sInitModes[4] = {0, 9, 0, 0};

// 0x083635b8
static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};

static const u8 u8_ARRAY_083635c0[9] = {5, 2, 10, 4, 5, 8, 2, 10, 4};
static const u8 u8_ARRAY_083635c9[8] = {2, 2, 2, 2, 3, 3, 3, 3};
static const u8 u8_ARRAY_083635d1[8] = {2, 2, 3, 3, 3, 4, 4, 4};

// 0x083635dc
static const Coords32 sExplosionCoords[2] = {
    {PIXEL(2), -PIXEL(8)},
    {PIXEL(4), -PIXEL(6)},
};
