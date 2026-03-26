#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static const struct Collision sCollisions[5];

static void GyroCannon_Init(struct Enemy* p);
static void GyroCannon_Update(struct Enemy* p);
static void GyroCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGyroCannonRoutine = {
    [ENTITY_INIT] =      GyroCannon_Init,
    [ENTITY_UPDATE] =    GyroCannon_Update,
    [ENTITY_DIE] =       GyroCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateGyroCannon(struct Entity* friend, u8 n, u8 r2) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
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

static void initGyroCannonWithPropeller(struct Enemy* p);
static void initGyroCannonWithoutPropeller(struct Enemy* p);

static void GyroCannon_Init(struct Enemy* p) {
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

void gyrocannon_0806d32c(struct Enemy* p);
static void gyrocannon_0806d1b4(struct Enemy* p);

static void GyroCannon_Update(struct Enemy* p) {
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

void FUN_0806d524(struct Enemy* p);
void FUN_0806d470(struct Enemy* p);

static void GyroCannon_Die(struct Enemy* p) {
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

NAKED static void initGyroCannonWithPropeller(struct Enemy* p) {
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

static void initGyroCannonWithoutPropeller(struct Enemy* p) {
  SetMotion(&p->s, MOTION(SM023_GYRO_CANNON, 6));
  UpdateMotionGraphic(&p->s);
  INIT_BODY(p, &sCollisions[2], 6, NULL);

  (p->s).flags &= ~X_FLIP;
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;

  p->props.gyroCannon.elementEffect = NULL;
}

static const struct Coord sElementCoord;
static const EnemyFunc PTR_ARRAY_0836666c[10];

NAKED static void gyrocannon_0806d1b4(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, _0806D204 @ =0xFFFFE800\n\
	adds r1, r1, r2\n\
	bl IsVoidSpace\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	beq _0806D20C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _0806D208 @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D204: .4byte 0xFFFFE800\n\
_0806D208: .4byte gEnemyFnTable\n\
_0806D20C:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r1, r0, #0\n\
	cmp r1, #1\n\
	beq _0806D246\n\
	ldr r0, [r4, #0x2c]\n\
	cmp r0, #0\n\
	beq _0806D222\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0806D222\n\
	str r2, [r4, #0x2c]\n\
_0806D222:\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	beq _0806D246\n\
	adds r3, r4, #0\n\
	adds r3, #0x8c\n\
	ldr r0, [r3]\n\
	ldr r1, _0806D250 @ =0x00020001\n\
	ands r0, r1\n\
	cmp r0, r1\n\
	bne _0806D240\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0806D240:\n\
	ldrb r2, [r4, #0xd]\n\
	cmp r2, #1\n\
	bne _0806D254\n\
_0806D246:\n\
	adds r0, r4, #0\n\
	bl FUN_0806d684\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D250: .4byte 0x00020001\n\
_0806D254:\n\
	ldr r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806D280\n\
	ldr r1, _0806D27C @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl GyroCannon_Die\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D27C: .4byte gEnemyFnTable\n\
_0806D280:\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	cmp r2, #8\n\
	beq _0806D2AC\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0806D2AC\n\
	ldr r6, [r5]\n\
	cmp r6, #0\n\
	bne _0806D2B2\n\
	ldr r2, _0806D2D0 @ =0x083666A0\n\
	movs r0, #0\n\
	adds r1, r4, #0\n\
	bl ApplyElementEffect\n\
	str r0, [r5]\n\
	cmp r0, #0\n\
	beq _0806D2DC\n\
	movs r0, #8\n\
	strb r0, [r4, #0xd]\n\
	strb r6, [r4, #0xe]\n\
_0806D2AC:\n\
	ldr r0, [r5]\n\
	cmp r0, #0\n\
	beq _0806D2DC\n\
_0806D2B2:\n\
	ldr r1, _0806D2D4 @ =0x0836666C\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0806D2D8 @ =0x083666C0\n\
	bl SetDDP\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D2D0: .4byte sElementCoord\n\
_0806D2D4: .4byte PTR_ARRAY_0836666c\n\
_0806D2D8: .4byte sCollisions+(24*1)\n\
_0806D2DC:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0806D324 @ =sCollisions\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	bne _0806D31C\n\
	ldrb r0, [r5, #0xb]\n\
	cmp r0, #0\n\
	bne _0806D306\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	beq _0806D306\n\
	ldr r0, [r4, #0x2c]\n\
	cmp r0, #0\n\
	bne _0806D306\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0806D306:\n\
	ldr r0, _0806D328 @ =0x0836666C\n\
	ldrb r1, [r4, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_0806D31C:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806D324: .4byte sCollisions\n\
_0806D328: .4byte PTR_ARRAY_0836666c\n\
 .syntax divided\n");
}

INCASM("asm/enemy/gyro_cannon.inc");

NAKED static void FUN_0806ddfc(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _0806DE2E\n\
	ldr r1, _0806DE64 @ =0x00001708\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r1, [r4, #0xa]\n\
	lsrs r1, r1, #4\n\
	movs r2, #1\n\
	ands r1, r2\n\
	movs r2, #0\n\
	bl CreateGhost27\n\
	movs r0, #0x30\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
_0806DE2E:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0806DEFA\n\
	adds r7, r4, #0\n\
	adds r7, #0x54\n\
	ldr r0, _0806DE68 @ =0x08366758\n\
	mov ip, r0\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r5, [r2, #8]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r3, #0x10\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	adds r6, r7, #0\n\
	mov r8, r2\n\
	cmp r0, #0\n\
	beq _0806DE6C\n\
	orrs r3, r5\n\
	b _0806DE6E\n\
	.align 2, 0\n\
_0806DE64: .4byte 0x00001708\n\
_0806DE68: .4byte sSlashedEnemies +(28*2)\n\
_0806DE6C:\n\
	adds r3, r5, #0\n\
_0806DE6E:\n\
	adds r0, r7, #0\n\
	mov r1, ip\n\
	movs r2, #0\n\
	bl CreateSlashedEnemy\n\
	adds r5, r6, #0\n\
	ldr r7, _0806DE90 @ =0x08366774\n\
	mov r0, r8\n\
	ldrb r2, [r0, #8]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r3, #0x10\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806DE94\n\
	orrs r3, r2\n\
	b _0806DE96\n\
	.align 2, 0\n\
_0806DE90: .4byte sSlashedEnemies +(28*3)\n\
_0806DE94:\n\
	adds r3, r2, #0\n\
_0806DE96:\n\
	adds r0, r5, #0\n\
	adds r1, r7, #0\n\
	movs r2, #0\n\
	bl CreateSlashedEnemy\n\
	movs r0, #1\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806DEBC\n\
	movs r0, #2\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
	b _0806DEC4\n\
_0806DEBC:\n\
	movs r0, #2\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
_0806DEC4:\n\
	adds r1, r6, #0\n\
	movs r0, #4\n\
	bl TryDropItem\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r2, _0806DF04 @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _0806DF08 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _0806DEE0\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_0806DEE0:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl TryDropZakoDisk\n\
	ldr r1, _0806DF0C @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r4, #0x14]\n\
_0806DEFA:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806DF04: .4byte gMission\n\
_0806DF08: .4byte 0x0000270E\n\
_0806DF0C: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

static void FUN_0806df10(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    struct Zero* other = (struct Zero*)body->enemy->parent;
    struct Enemy* owner = (struct Enemy*)body->parent;
    struct GyroCannonProps* props = (struct GyroCannonProps*)(owner->props).raw;
    props->is_right = (other->s).coord.x > (owner->s).coord.x;
  }
}

void FUN_0806d618(struct Enemy* p);
void FUN_0806d684(struct Enemy* p);
void FUN_0806d7e0(struct Enemy* p);
void FUN_0806d8b0(struct Enemy* p);
void FUN_0806d998(struct Enemy* p);
void FUN_0806d9d4(struct Enemy* p);
void FUN_0806da20(struct Enemy* p);
void FUN_0806da5c(struct Enemy* p);
void FUN_0806dab8(struct Enemy* p);
void FUN_0806db58(struct Enemy* p);

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

void gyroCannon_0806db8c(struct Enemy* p);
void gyroCannon_0806dccc(struct Enemy* p);
static void FUN_0806ddfc(struct Enemy* p);

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
