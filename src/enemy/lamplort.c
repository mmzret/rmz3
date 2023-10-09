#include "collision.h"
#include "enemy.h"
#include "global.h"

void Lamplort_Init(struct Enemy *p);
void Lamplort_Update(struct Enemy *p);
void Lamplort_Die(struct Enemy *p);
void Lamplort_Disappear(struct Enemy *p);

// clang-format off
const EnemyRoutine gLamplortRoutine = {
    [ENTITY_INIT] =      Lamplort_Init,
    [ENTITY_UPDATE] =    Lamplort_Update,
    [ENTITY_DIE] =       Lamplort_Die,
    [ENTITY_DISAPPEAR] = Lamplort_Disappear,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy *CreateLamplort(struct Coord *c, u8 n) {
  struct Enemy *p = (struct Enemy *)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_LAMPLORT);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/enemy/lamplort.inc");

void FUN_0806c81c(struct Enemy *p);
void FUN_0806c824(struct Enemy *p);
void FUN_0806c8c8(struct Enemy *p);
void FUN_0806c9c0(struct Enemy *p);
void true_0806cac4(struct Enemy *p);
void FUN_0806cb58(struct Enemy *p);
void FUN_0806cc00(struct Enemy *p);
void true_0806cd48(struct Enemy *p);
void FUN_0806cda4(struct Enemy *p);
void FUN_0806cdac(struct Enemy *p);

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    FUN_0806c81c,
    FUN_0806c824,
    FUN_0806c8c8,
    FUN_0806c9c0,
    true_0806cac4,
    FUN_0806cb58,
    FUN_0806cc00,
    true_0806cd48,
    FUN_0806cda4,
    FUN_0806cdac,
};
// clang-format on

void FUN_0806c820(struct Enemy *p);
void FUN_0806c828(struct Enemy *p);
void FUN_0806c8cc(struct Enemy *p);
void FUN_0806c9c4(struct Enemy *p);
void FUN_0806cac8(struct Enemy *p);
void FUN_0806cb5c(struct Enemy *p);
void lamplort_0806cc04(struct Enemy *p);
void FUN_0806cd4c(struct Enemy *p);
void FUN_0806cda8(struct Enemy *p);
void FUN_0806cdb0(struct Enemy *p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    FUN_0806c820,
    FUN_0806c828,
    FUN_0806c8cc,
    FUN_0806c9c4,
    FUN_0806cac8,
    FUN_0806cb5c,
    lamplort_0806cc04,
    FUN_0806cd4c,
    FUN_0806cda8,
    FUN_0806cdb0,
};
// clang-format on

static const struct Collision sCollisions[8] = {
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000000,
      range : {-PIXEL(9), -PIXEL(14), PIXEL(26), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(8), -PIXEL(14), PIXEL(24), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {PIXEL(10), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(6), -PIXEL(14), PIXEL(31), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {-PIXEL(23), -PIXEL(14), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(2), -PIXEL(12), PIXEL(22), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(1), -PIXEL(11), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(2), -PIXEL(12), PIXEL(22), PIXEL(20)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(10)};
