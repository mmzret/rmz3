#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static const struct Collision sCollisions[5];

static void GyroCannon_Init(struct Enemy *p);
static void GyroCannon_Update(struct Enemy *p);
static void GyroCannon_Die(struct Enemy *p);

// clang-format off
const EnemyRoutine gGyroCannonRoutine = {
    [ENTITY_INIT] =      GyroCannon_Init,
    [ENTITY_UPDATE] =    GyroCannon_Update,
    [ENTITY_DIE] =       GyroCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy *CreateGyroCannon(struct Entity *friend, u8 n, u8 r2) {
  struct Enemy *p = (struct Enemy *)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_GYRO_CANNON);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).unk_28 = friend;
    (p->s).work[0] = n;
    (p->s).work[1] = r2;
  }
  return p;
}

// --------------------------------------------

static void initGyroCannonWithPropeller(struct Enemy *p);
void initGyroCannonWithoutPropeller(struct Enemy *p);

static void GyroCannon_Init(struct Enemy *p) {
  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  if ((p->s).work[0] != 0) {
    initGyroCannonWithoutPropeller(p);
  } else {
    initGyroCannonWithPropeller(p);
  }
  GyroCannon_Update(p);
}

// --------------------------------------------

void gyrocannon_0806d32c(struct Enemy *p);
void gyrocannon_0806d1b4(struct Enemy *p);

static void GyroCannon_Update(struct Enemy *p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_ZAKO_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((p->s).work[0] != 0) {
    gyrocannon_0806d32c(p);
  } else {
    gyrocannon_0806d1b4(p);
  }
}

// --------------------------------------------

void FUN_0806d524(struct Enemy *p);
void FUN_0806d470(struct Enemy *p);

static void GyroCannon_Die(struct Enemy *p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_ZAKO_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((p->s).work[0] != 0) {
    FUN_0806d524(p);
  } else {
    FUN_0806d470(p);
  }
}

// --------------------------------------------

NAKED static void initGyroCannonWithPropeller(struct Enemy *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	movs r1, #0xb8\n\
	lsls r1, r1, #5\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _0806D0F0 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806D0FC\n\
	ldr r0, _0806D0F4 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _0806D0FC\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806D0F8 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0x14\n\
	b _0806D114\n\
	.align 2, 0\n\
_0806D0F0: .4byte gSystemSavedataManager\n\
_0806D0F4: .4byte gCurStory\n\
_0806D0F8: .4byte sCollisions\n\
_0806D0FC:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806D14C @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0x10\n\
_0806D114:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _0806D150 @ =FUN_0806df10\n\
	str r0, [r4, #0x24]\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl CreateGyroCannon\n\
	str r0, [r6, #0x2c]\n\
	adds r2, r6, #0\n\
	adds r2, #0xb4\n\
	movs r1, #0\n\
	strb r1, [r2, #9]\n\
	ldr r0, [r6, #0x58]\n\
	str r0, [r2, #4]\n\
	strb r1, [r2, #0xa]\n\
	strb r1, [r2, #0xb]\n\
	str r1, [r6, #0x60]\n\
	strb r1, [r6, #0x13]\n\
	str r1, [r2]\n\
	movs r0, #2\n\
	strb r0, [r6, #0xd]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806D14C: .4byte sCollisions\n\
_0806D150: .4byte FUN_0806df10\n\
 .syntax divided\n");
}

INCASM("asm/enemy/gyro_cannon.inc");

void FUN_0806d618(struct Enemy *p);
void FUN_0806d684(struct Enemy *p);
void FUN_0806d7e0(struct Enemy *p);
void FUN_0806d8b0(struct Enemy *p);
void FUN_0806d998(struct Enemy *p);
void FUN_0806d9d4(struct Enemy *p);
void FUN_0806da20(struct Enemy *p);
void FUN_0806da5c(struct Enemy *p);
void FUN_0806dab8(struct Enemy *p);
void FUN_0806db58(struct Enemy *p);

// clang-format off
static const EnemyFunc PTR_ARRAY_0836666c[10] = {
    FUN_0806d618,
    FUN_0806d684,
    FUN_0806d7e0,
    FUN_0806d8b0,
    FUN_0806d998,
    FUN_0806d9d4,
    FUN_0806da20,
    FUN_0806da5c,
    FUN_0806dab8,
    FUN_0806db58,
};
// clang-format on

void gyroCannon_0806db8c(struct Enemy *p);
void gyroCannon_0806dccc(struct Enemy *p);
void FUN_0806ddfc(struct Enemy *p);

static const EnemyFunc sUpdates2[3] = {
    gyroCannon_0806db8c,
    gyroCannon_0806dccc,
    FUN_0806ddfc,
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};

static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(20), PIXEL(32), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(20), PIXEL(32), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
};

static const struct SlashedEnemy sSlashedEnemies[4] = {
    {
      m : 0x170B,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0400},
      unk_coord_0c : {0x03FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
      _ : {0, 0, 0, 0},
    },
    {
      m : 0x170C,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
      _ : {0, 0, 0, 0},
    },
    {
      m : 0x170D,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0400},
      unk_coord_0c : {0x03FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
      _ : {0, 0, 0, 0},
    },
    {
      m : 0x170E,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
      _ : {0, 0, 0, 0},
    },
};
