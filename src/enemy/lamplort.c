#include "collision.h"
#include "enemy.h"
#include "global.h"

static void Lamplort_Init(struct Enemy *p);
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

// --------------------------------------------

NAKED static void Lamplort_Init(struct Enemy *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	orrs r2, r3\n\
	strb r2, [r6, #0xa]\n\
	ldr r0, _0806C290 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x15]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806C29C\n\
	ldr r0, _0806C294 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _0806C29C\n\
	movs r0, #4\n\
	orrs r2, r0\n\
	strb r2, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806C298 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xc\n\
	b _0806C2B4\n\
	.align 2, 0\n\
_0806C290: .4byte gSystemSavedataManager\n\
_0806C294: .4byte gCurStory\n\
_0806C298: .4byte sCollisions\n\
_0806C29C:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806C2E0 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #8\n\
_0806C2B4:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _0806C2E4 @ =FUN_0806ce60\n\
	str r0, [r4, #0x24]\n\
	adds r1, r6, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [r1]\n\
	movs r0, #0\n\
	str r0, [r6, #0x60]\n\
	str r0, [r6, #0x5c]\n\
	ldrb r1, [r6, #0x10]\n\
	cmp r1, #0\n\
	bne _0806C2E8\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	strb r1, [r0]\n\
	adds r4, r0, #0\n\
	b _0806C2F2\n\
	.align 2, 0\n\
_0806C2E0: .4byte sCollisions\n\
_0806C2E4: .4byte FUN_0806ce60\n\
_0806C2E8:\n\
	adds r1, r6, #0\n\
	adds r1, #0xbc\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r4, r1, #0\n\
_0806C2F2:\n\
	ldrb r2, [r4]\n\
	cmp r2, #0\n\
	beq _0806C300\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _0806C306\n\
_0806C300:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0806C306:\n\
	strb r0, [r6, #0xa]\n\
	movs r7, #1\n\
	adds r1, r7, #0\n\
	ands r1, r2\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	movs r5, #0\n\
	strb r1, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	str r5, [r0]\n\
	strb r5, [r6, #0x12]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_0800a05c\n\
	str r0, [r6, #0x58]\n\
	ldrb r2, [r4]\n\
	adds r0, r6, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl CreateProjectile6\n\
	str r0, [r6, #0x2c]\n\
	adds r0, r6, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	beq _0806C362\n\
	movs r1, #0xc8\n\
	lsls r1, r1, #5\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
_0806C362:\n\
	adds r0, r6, #0\n\
	adds r0, #0xbb\n\
	strb r5, [r0]\n\
	ldr r1, _0806C38C @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r7, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	strb r7, [r6, #0xd]\n\
	strb r5, [r6, #0xe]\n\
	strb r5, [r6, #0xf]\n\
	adds r0, r6, #0\n\
	bl Lamplort_Update\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806C38C: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

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
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : METAL,
      remaining : 4,
      range : {-PIXEL(9), -PIXEL(14), PIXEL(26), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 3,
      priorityLayer : 0xFFFFFFFF,
      range : {-PIXEL(8), -PIXEL(14), PIXEL(24), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      remaining : 2,
      range : {PIXEL(10), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(6), -PIXEL(14), PIXEL(31), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(14), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      hardness : METAL,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(2), -PIXEL(12), PIXEL(22), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(11), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(12), PIXEL(22), PIXEL(20)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(10)};
