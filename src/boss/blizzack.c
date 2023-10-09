#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/blizzack.inc");

void Blizzack_Init(struct Boss* p);
void Blizzack_Update(struct Boss* p);
void Blizzack_Die(struct Boss* p);

// clang-format off
const BossRoutine gBlizzackRoutine = {
    [ENTITY_INIT] =      Blizzack_Init,
    [ENTITY_UPDATE] =    Blizzack_Update,
    [ENTITY_DIE] =       Blizzack_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

void blizzackMode0(struct Boss* p);
void blizzackMode1(struct Boss* p);
void blizzackNeutral(struct Boss* p);
void blizzackPreAI(struct Boss* p);
void blizzackNextMode(struct Boss* p);
void blizzackJump(struct Boss* p);
void blizzackStamp(struct Boss* p);
void blizzackMode7(struct Boss* p);
void blizzackMode8(struct Boss* p);
void blizzackMode9(struct Boss* p);
void blizzackStartBlizzard(struct Boss* p);
void blizzackBlizzard(struct Boss* p);
void blizzackEndBlizzard(struct Boss* p);
void blizzackBombJump(struct Boss* p);
void blizzackBomb(struct Boss* p);
void blizzackBombFall(struct Boss* p);
void blizzackBombStamp(struct Boss* p);
void blizzackMode17(struct Boss* p);
void blizzackMode18(struct Boss* p);
void blizzackMode19(struct Boss* p);
void blizzackMode20(struct Boss* p);

// clang-format off
static const BossFunc sUpdates[21] = {
    blizzackMode0,
    blizzackMode1,
    blizzackNeutral,
    blizzackPreAI,
    blizzackNextMode,
    blizzackJump,
    blizzackStamp,
    blizzackMode7,
    blizzackMode8,
    blizzackMode9,
    blizzackStartBlizzard,
    blizzackBlizzard,
    blizzackEndBlizzard,
    blizzackBombJump,
    blizzackBomb,
    blizzackBombFall,
    blizzackBombStamp,
    blizzackMode17,
    blizzackMode18,
    blizzackMode19,
    blizzackMode20,
};
// clang-format on

// --------------------------------------------

void blizzack_0805ac5c(struct Boss* p);
void blizzack_0805ad2c(struct Boss* p);
void blizzack_0805add0(struct Boss* p);

static const BossFunc sDeads[3] = {
    blizzack_0805ac5c,
    blizzack_0805ad2c,
    blizzack_0805add0,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 8,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(34), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 4,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(24), PIXEL(34), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 8,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(8), -PIXEL(24), PIXEL(50), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 4,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(8), -PIXEL(24), PIXEL(50), PIXEL(48)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(24)};
