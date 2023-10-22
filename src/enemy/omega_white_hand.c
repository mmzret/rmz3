#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"

static const struct Collision sCollisions[7];

void OmegaWhiteHand_Init(struct Enemy *p);
void OmegaWhiteHand_Update(struct Enemy *p);
void OmegaWhiteHand_Die(struct Enemy *p);

// clang-format off
const EnemyRoutine gOmegaWhiteHandRoutine = {
    [ENTITY_INIT] =      OmegaWhiteHand_Init,
    [ENTITY_UPDATE] =    OmegaWhiteHand_Update,
    [ENTITY_DIE] =       OmegaWhiteHand_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy *CreateOmegaWhiteHand(struct Coord *c, bool8 isLeftHand, struct Boss *omega) {
  struct Enemy *p = (struct Enemy *)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, 8);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = isLeftHand;
    (p->s).unk_28 = &omega->s;
  }
  return p;
}

INCASM("asm/enemy/omega_white_hand.inc");

// --------------------------------------------

void FUN_0806aa9c(struct Enemy *p);
void FUN_0806ae90(struct Enemy *p);
void FUN_0806af24(struct Enemy *p);
void FUN_0806b094(struct Enemy *p);
void FUN_0806b120(struct Enemy *p);
void FUN_0806b8cc(struct Enemy *p);

// clang-format off
static const EnemyFunc sUpdates[6] = {
    FUN_0806aa9c,
    FUN_0806ae90,
    FUN_0806af24,
    FUN_0806b094,
    FUN_0806b120,
    FUN_0806b8cc,
};
// clang-format on

void FUN_0806aaa0(struct Enemy *p);
void FUN_0806ae94(struct Enemy *p);
void FUN_0806af40(struct Enemy *p);
void FUN_0806b098(struct Enemy *p);
void FUN_0806b124(struct Enemy *p);
void FUN_0806b8d0(struct Enemy *p);

// clang-format off
static const EnemyFunc sUpdateRights[6] = {
    FUN_0806aaa0,
    FUN_0806ae94,
    FUN_0806af40,
    FUN_0806b098,
    FUN_0806b124,
    FUN_0806b8d0,
};
// clang-format on

void FUN_0806ac98(struct Enemy *p);
void FUN_0806aedc(struct Enemy *p);
void FUN_0806afdc(struct Enemy *p);
void FUN_0806b0dc(struct Enemy *p);
void FUN_0806b4cc(struct Enemy *p);
void FUN_0806bb8c(struct Enemy *p);

// clang-format off
static const EnemyFunc sUpdateLefts[6] = {
    FUN_0806ac98,
    FUN_0806aedc,
    FUN_0806afdc,
    FUN_0806b0dc,
    FUN_0806b4cc,
    FUN_0806bb8c,
};
// clang-format on

void FUN_0806a8fc(struct Enemy *p);
void FUN_0806aa54(struct Enemy *p);

static const EnemyFunc sDeinitializers[2] = {
    FUN_0806a8fc,
    FUN_0806aa54,
};

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0100, 0x1600, 0x2900},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0100, 0x1600, 0x2900},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0400, 0x0200, 0x1E00, 0x2800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0400, 0x0200, 0x2000, 0x2A00},
    },
};
