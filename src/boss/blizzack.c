#include "boss.h"
#include "collision.h"
#include "global.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[48];         // 0xB4
} Blizzack;
static_assert(sizeof(Blizzack) == sizeof(Boss));

void Blizzack_Init(Blizzack* p);
void Blizzack_Update(Blizzack* p);
void Blizzack_Die(Blizzack* p);

// clang-format off
const BossRoutine gBlizzackRoutine = {
    [ENTITY_INIT] =      (void*)Blizzack_Init,
    [ENTITY_UPDATE] =    (void*)Blizzack_Update,
    [ENTITY_DIE] =       (void*)Blizzack_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateBlizzack(Coords32* c) {
  Blizzack* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_BLIZZACK);
    p->coord = *c;
    p->work[0] = 0, p->work[1] = 0;
  }
}

// --------------------------------------------

static void (*const sDeads[3])(Blizzack*);

INCASM("asm/boss/blizzack_a.inc");

void Blizzack_Die(Blizzack* p) {
  (sDeads[p->mode[1]])((void*)p);
}

// blizzackMode0/Mode1 do not match: agbcc schedules the mode[2]=0 zero early,
// forcing the 0x64xx constant into a spare reg + copy (regmove) the target
// avoids. Logic is faithful in the MODERN branches; the INCCODE asm bodies
// match the ROM byte-for-byte.
INCASM("asm/boss/blizzack_b.inc");

INCASM("asm/boss/blizzack_c.inc");

INCASM("asm/boss/blizzack_d.inc");

// blizzackNextMode does not match for the same regmove reason as blizzackMode1:
// agbcc schedules the mode[2]=0 zero early, forcing the 0x6402 constant into a
// spare reg + copy the target avoids. Logic is faithful in the MODERN branch;
// the INCCODE asm body matches the ROM byte-for-byte.
INCASM("asm/boss/blizzack_e.inc");

INCASM("asm/boss/blizzack_f.inc");

void FUN_080aabd4(Blizzack* p);

void blizzackMode8(Blizzack* p) {
  if (p->mode[2] != 0) {
    p->mode[2] = 0;
    p->work[2] = 0xb4;
    FUN_080aabd4(p);
  }
  UpdateSpriteAnimation(p);
  if ((u8)--p->work[2] == 0xff) {
    p->mode[1] = 9;
    p->mode[2] = 1;
  }
}

INCASM("asm/boss/blizzack_g.inc");

void FUN_0805af14(Blizzack* p) {
  if (p->coord.x < *(s32*)((u8*)p + 0xb4) + 0x2000 ||
      p->coord.x > *(s32*)((u8*)p + 0xd8) - 0x2000) {
    p->coord.x = *(s32*)((u8*)p + 0xc0);
  }
  *(s32*)((u8*)p + 0xc0) = p->coord.x;
}

void blizzackMode0(Blizzack* p);
void blizzackMode1(Blizzack* p);
void blizzackNeutral(Blizzack* p);
void blizzackPreAI(Blizzack* p);
void blizzackNextMode(Blizzack* p);
void blizzackJump(Blizzack* p);
void blizzackStamp(Blizzack* p);
void blizzackMode7(Blizzack* p);
void blizzackMode8(Blizzack* p);
void blizzackMode9(Blizzack* p);
void blizzackStartBlizzard(Blizzack* p);
void blizzackBlizzard(Blizzack* p);
void blizzackEndBlizzard(Blizzack* p);
void blizzackBombJump(Blizzack* p);
void blizzackBomb(Blizzack* p);
void blizzackBombFall(Blizzack* p);
void blizzackBombStamp(Blizzack* p);
void blizzackMode17(Blizzack* p);
void blizzackMode18(Blizzack* p);
void blizzackMode19(Blizzack* p);
void blizzackMode20(Blizzack* p);

// clang-format off
// 0x08364b50
static void (*const sUpdates[21])(Blizzack*) = {
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

void blizzack_0805ac5c(Blizzack* p);
void blizzack_0805ad2c(Blizzack* p);
void blizzack_0805add0(Blizzack* p);

static void (*const sDeads[3])(Blizzack*) = {
    blizzack_0805ac5c,
    blizzack_0805ad2c,
    blizzack_0805add0,
};

// --------------------------------------------

// 0x08364bb0
static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      hitzone : 8,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(34), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(24), PIXEL(34), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      hitzone : 8,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(24), PIXEL(50), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      remaining : 0,
      range : {PIXEL(8), -PIXEL(24), PIXEL(50), PIXEL(48)},
    },
};

// 0x08364c10
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(24)};
