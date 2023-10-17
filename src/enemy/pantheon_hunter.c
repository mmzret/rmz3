#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

static const EnemyFunc sUpdates[13];
static const EnemyFunc sDeads[3];
static const struct Collision sCollisions[3];
static const struct SlashedEnemy sSlashedEnemies[4];

static void PantheonHunter_Init(struct Enemy* p);
static void PantheonHunter_Update(struct Enemy* p);
void PantheonHunter_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonHunterRoutine = {
    [ENTITY_INIT] =      PantheonHunter_Init,
    [ENTITY_UPDATE] =    PantheonHunter_Update,
    [ENTITY_DIE] =       PantheonHunter_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreatePantheonHunter(struct Coord* c, u8 r1, u8 r2) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_P_HUNTER);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = r1;
    (p->s).work[1] = r2;
  }
  return p;
}

NAKED static void PantheonHunter_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r1, _08064760 @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _08064764 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #8]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08064770\n\
	ldr r0, _08064768 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _08064770\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806476C @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xa\n\
	b _08064788\n\
	.align 2, 0\n\
_08064760: .4byte gEnemyFnTable\n\
_08064764: .4byte gSystemSavedataManager\n\
_08064768: .4byte gCurStory\n\
_0806476C: .4byte sCollisions\n\
_08064770:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080647B0 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #6\n\
_08064788:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _080647B4 @ =FUN_080656f4\n\
	str r0, [r4, #0x24]\n\
	movs r0, #0\n\
	str r0, [r6, #0x60]\n\
	str r0, [r6, #0x5c]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #2\n\
	bne _080647B8\n\
	movs r0, #0xc\n\
	strb r0, [r6, #0xd]\n\
	ldrb r1, [r6, #0x11]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbd\n\
	strb r1, [r0]\n\
	adds r2, r0, #0\n\
	b _080647FA\n\
	.align 2, 0\n\
_080647B0: .4byte sCollisions\n\
_080647B4: .4byte FUN_080656f4\n\
_080647B8:\n\
	cmp r0, #0\n\
	beq _080647CA\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080647D4\n\
_080647CA:\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r6, #0x58]\n\
_080647D4:\n\
	movs r0, #6\n\
	strb r0, [r6, #0xd]\n\
	ldr r0, _080647EC @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r1, r0\n\
	bge _080647F0\n\
	adds r1, r6, #0\n\
	adds r1, #0xbd\n\
	movs r0, #1\n\
	b _080647F6\n\
	.align 2, 0\n\
_080647EC: .4byte pZero2\n\
_080647F0:\n\
	adds r1, r6, #0\n\
	adds r1, #0xbd\n\
	movs r0, #0\n\
_080647F6:\n\
	strb r0, [r1]\n\
	adds r2, r1, #0\n\
_080647FA:\n\
	adds r1, r6, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r6, #0x58]\n\
	str r0, [r1]\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	subs r0, #2\n\
	strb r1, [r0]\n\
	ldrb r2, [r2]\n\
	cmp r2, #0\n\
	beq _08064822\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08064828\n\
_08064822:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08064828:\n\
	strb r0, [r6, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
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
	bl PantheonHunter_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

void FUN_08064c38(struct Enemy* p);
void nop_08064ca8(struct Enemy* p);
void phunter_08064cac(struct Enemy* p);
void FUN_08064e0c(struct Enemy* p);
void nop_08064e34(struct Enemy* p);
void FUN_08064e38(struct Enemy* p);
void FUN_08064e7c(struct Enemy* p);
void phunterRaiseArm(struct Enemy* p);
void phunterShotBuster(struct Enemy* p);
void FUN_08065104(struct Enemy* p);
void phunter_080651c0(struct Enemy* p);
void phunter_08065218(struct Enemy* p);
void phunter_080652e8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates[13] = {
    FUN_08064c38,
    nop_08064ca8,
    phunter_08064cac,
    FUN_08064e0c,
    nop_08064e34,
    FUN_08064e38,
    FUN_08064e7c,
    phunterRaiseArm,
    phunterShotBuster,
    FUN_08065104,
    phunter_080651c0,
    phunter_08065218,
    phunter_080652e8,
};
// clang-format on

NAKED static void PantheonHunter_Update(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldr r6, _08064888 @ =gCurStory\n\
	ldrb r1, [r6, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _0806488C\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	b _080648D6\n\
	.align 2, 0\n\
_08064888: .4byte gCurStory\n\
_0806488C:\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #2\n\
	bne _08064904\n\
	ldr r0, _080648F4 @ =gStageRun+232\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bhi _080648BC\n\
	ldrb r1, [r6, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08064904\n\
	ldr r0, _080648F8 @ =gSystemSavedataManager\n\
	ldr r1, [r0, #0x40]\n\
	ldr r0, _080648FC @ =0x000032DA\n\
	cmp r1, r0\n\
	beq _08064904\n\
	cmp r1, #0\n\
	beq _08064904\n\
_080648BC:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	strb r4, [r0]\n\
_080648D6:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _08064900 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _08064AC2\n\
	.align 2, 0\n\
_080648F4: .4byte gStageRun+232\n\
_080648F8: .4byte gSystemSavedataManager\n\
_080648FC: .4byte 0x000032DA\n\
_08064900: .4byte gEnemyFnTable\n\
_08064904:\n\
	adds r0, r5, #0\n\
	bl phunter_08064c10\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #2\n\
	bne _08064918\n\
	adds r0, r5, #0\n\
	bl phunter_08064cac\n\
	b _08064AC2\n\
_08064918:\n\
	adds r7, r5, #0\n\
	adds r7, #0x8c\n\
	ldr r0, [r7]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08064942\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r6, #0x80\n\
	lsls r6, r6, #4\n\
	adds r1, r1, r6\n\
	bl FUN_080098a4\n\
	movs r1, #0x10\n\
	ands r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r4, r1, #0x10\n\
	cmp r4, #0\n\
	beq _08064960\n\
_08064942:\n\
	ldr r1, _0806495C @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl PantheonHunter_Die\n\
	b _08064AC2\n\
	.align 2, 0\n\
_0806495C: .4byte gEnemyFnTable\n\
_08064960:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r1, r1, r2\n\
	bl FUN_0800a40c\n\
	cmp r0, #0\n\
	beq _08064986\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	adds r1, r1, r6\n\
	bl FUN_0800a40c\n\
	ldr r1, [r5, #0x54]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x54]\n\
	strb r4, [r5, #0xd]\n\
	strb r4, [r5, #0xe]\n\
_08064986:\n\
	adds r0, r5, #0\n\
	adds r0, #0xc0\n\
	ldr r4, [r0]\n\
	adds r6, r0, #0\n\
	cmp r4, #0\n\
	bne _080649B6\n\
	ldr r0, [r7]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080649B0\n\
	ldr r2, _08064A30 @ =Coord_08365c84\n\
	movs r0, #0\n\
	adds r1, r5, #0\n\
	bl ApplyElementEffect\n\
	str r0, [r6]\n\
	cmp r0, #0\n\
	beq _08064A40\n\
	str r4, [r5, #0x60]\n\
	str r4, [r5, #0x5c]\n\
_080649B0:\n\
	ldr r0, [r6]\n\
	cmp r0, #0\n\
	beq _08064A40\n\
_080649B6:\n\
	ldr r1, _08064A34 @ =0x00001303\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08064A38 @ =sCollisions+24\n\
	adds r0, r4, #0\n\
	bl SetDDP\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	adds r1, #1\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	adds r7, r4, #0\n\
	cmp r0, #0\n\
	bne _08064A06\n\
	ldr r0, [r5, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r5, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080649F2\n\
	str r1, [r5, #0x60]\n\
_080649F2:\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08064A10\n\
_08064A06:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r5, #0x58]\n\
_08064A10:\n\
	ldr r0, [r6]\n\
	bl isKilled\n\
	cmp r0, #0\n\
	beq _08064AC2\n\
	movs r4, #0\n\
	str r4, [r6]\n\
	ldr r1, _08064A3C @ =sCollisions\n\
	adds r0, r7, #0\n\
	bl SetDDP\n\
	strb r4, [r5, #0xd]\n\
	movs r0, #1\n\
	strb r0, [r5, #0xe]\n\
	b _08064AC2\n\
	.align 2, 0\n\
_08064A30: .4byte Coord_08365c84\n\
_08064A34: .4byte 0x00001303\n\
_08064A38: .4byte sCollisions+24\n\
_08064A3C: .4byte sCollisions\n\
_08064A40:\n\
	adds r0, r5, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	beq _08064AAC\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _08064AA8 @ =sCollisions\n\
	bl SetDDP\n\
	movs r0, #0\n\
	str r0, [r6]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08064A7C\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #1\n\
	bne _08064A9C\n\
_08064A7C:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r4, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_0800a05c\n\
	cmp r4, r0\n\
	beq _08064A9C\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r5, #0x58]\n\
_08064A9C:\n\
	movs r1, #0\n\
	movs r0, #6\n\
	strb r0, [r5, #0xd]\n\
	strb r1, [r5, #0xe]\n\
	b _08064AC2\n\
	.align 2, 0\n\
_08064AA8: .4byte sCollisions\n\
_08064AAC:\n\
	adds r0, r5, #0\n\
	bl phunter_08064bc8\n\
	ldr r0, _08064AC8 @ =sUpdates\n\
	ldrb r1, [r5, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r5, #0\n\
	bl _call_via_r1\n\
_08064AC2:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08064AC8: .4byte sUpdates\n\
 .syntax divided\n");
}

INCASM("asm/enemy/pantheon_hunter.inc");

// --------------------------------------------

void explodePHunter(struct Enemy* p);
void slashPHunter(struct Enemy* p);
void FUN_080656cc(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    explodePHunter,
    slashPHunter,
    FUN_080656cc,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1200, 0x1000},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1200, 0x1400, 0x2200},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      atkType : 0x00,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0200, -0x1000, 0x1000, 0x1000},
    },
};

static const struct SlashedEnemy sSlashedEnemies[4] = {
    [0] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x06),
      unk_02 : {0xFF, 0x11},
      c : {0, 0},
      d : {0x80, 0xFB00},
      unk_coord_0c : {0xFF, 0x1FF},
      unk_10 : {0, 0x40},
      unk_14 : {0x200, 0x200},
    },
    [1] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x07),
      unk_02 : {0xFE, 0x11},
      c : {0, 0},
      d : {0x80, 0xFE00},
      unk_coord_0c : {0x7F, 0x7F},
      unk_10 : {0, 0x40},
      unk_14 : {0x200, 0x200},
    },
    [2] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x08),
      unk_02 : {0xFE, 0x11},
      c : {0, 0},
      d : {0x100, 0xFD00},
      unk_coord_0c : {0x1FF, 0x1FF},
      unk_10 : {0, 0x40},
      unk_14 : {0x200, 0x200},
    },
    [3] = {
      m : MOTION(SM019_PANTHEON_HUNTER, 0x05),
      unk_02 : {0xFF, 0x4},
      c : {0, 0},
      d : {0, 0},
      unk_coord_0c : {0, 0},
      unk_10 : {0, 0x40},
      unk_14 : {0x800, 0x200},
    },
};

const struct Coord Coord_08365c84 = {0, -0x1000};
const struct Coord Coord_08365c8c = {0xFFFFF780, 0x880};
