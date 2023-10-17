#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "zero.h"

bool8 batring_08068130(struct Enemy* p);

static const struct Coord sElementCoord;

static void Batring_Init(struct Enemy* p);
static void Batring_Update(struct Enemy* p);
static void Batring_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gBatringRoutine = {
    [ENTITY_INIT] =      Batring_Init,
    [ENTITY_UPDATE] =    Batring_Update,
    [ENTITY_DIE] =       Batring_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// Unused
static struct Enemy* CreateBatring(struct Coord* c, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ZAKO_BATRING);
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

NAKED static void Batring_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r3, #0\n\
	movs r2, #0\n\
	movs r1, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _08067048\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_0800a134\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x58]\n\
	ldr r0, _08067024 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x14]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08067030\n\
	ldr r0, _08067028 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _08067030\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806702C @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xa\n\
	b _080670A0\n\
	.align 2, 0\n\
_08067024: .4byte gSystemSavedataManager\n\
_08067028: .4byte gCurStory\n\
_0806702C: .4byte sCollisions\n\
_08067030:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08067044 @ =sCollisions\n\
	b _08067098\n\
	.align 2, 0\n\
_08067044: .4byte sCollisions\n\
_08067048:\n\
	ldr r0, _0806707C @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x14]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08067088\n\
	ldr r0, _08067080 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _08067088\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08067084 @ =sCollisions+48\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xa\n\
	b _080670A0\n\
	.align 2, 0\n\
_0806707C: .4byte gSystemSavedataManager\n\
_08067080: .4byte gCurStory\n\
_08067084: .4byte sCollisions+48\n\
_08067088:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080670E8 @ =sCollisions+48\n\
_08067098:\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #6\n\
_080670A0:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _080670EC @ =batring_080681c4\n\
	str r0, [r4, #0x24]\n\
	adds r1, r6, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [r1]\n\
	movs r2, #0\n\
	str r2, [r6, #0x60]\n\
	str r2, [r6, #0x5c]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	str r2, [r0]\n\
	subs r0, #3\n\
	strb r2, [r0]\n\
	subs r0, #1\n\
	strb r2, [r0]\n\
	adds r0, #3\n\
	strb r2, [r0]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _080670F4\n\
	ldr r1, _080670F0 @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	strb r1, [r6, #0xd]\n\
	b _0806710A\n\
	.align 2, 0\n\
_080670E8: .4byte sCollisions+48\n\
_080670EC: .4byte batring_080681c4\n\
_080670F0: .4byte gEnemyFnTable\n\
_080670F4:\n\
	ldr r1, _0806712C @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r6, #0xd]\n\
_0806710A:\n\
	strb r2, [r6, #0xe]\n\
	strb r2, [r6, #0xf]\n\
	movs r0, #0\n\
	strb r0, [r6, #0x11]\n\
	adds r0, r6, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	beq _08067142\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _08067134\n\
	ldr r1, _08067130 @ =0x00000602\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	b _0806713C\n\
	.align 2, 0\n\
_0806712C: .4byte gEnemyFnTable\n\
_08067130: .4byte 0x00000602\n\
_08067134:\n\
	ldr r1, _0806715C @ =0x00000601\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
_0806713C:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
_08067142:\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	subs r0, #6\n\
	strb r1, [r0]\n\
	adds r0, r6, #0\n\
	bl Batring_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806715C: .4byte 0x00000601\n\
 .syntax divided\n");
}

static bool8 FUN_08067694(struct Enemy* p);
static bool8 FUN_080676ac(struct Enemy* p);
static bool8 FUN_080677dc(struct Enemy* p);
void FUN_08067a60(struct Enemy* p);
void FUN_08067c48(struct Enemy* p);
void FUN_08067f18(struct Enemy* p);
void FUN_08067f6c(struct Enemy* p);
void FUN_08067f74(struct Enemy* p);
void FUN_08068014(struct Enemy* p);

// clang-format off
const EnemyFunc sBatringUpdates1[9] = {
    (EnemyFunc)FUN_08067694,
    (EnemyFunc)FUN_080676ac,
    (EnemyFunc)FUN_080677dc,
    FUN_08067a60,
    FUN_08067c48,
    FUN_08067f18,
    FUN_08067f6c,
    FUN_08067f74,
    FUN_08068014,
};
// clang-format on

static void FUN_08067698(struct Enemy* p);
static void FUN_080676b0(struct Enemy* p);
void batring_080677e0(struct Enemy* p);
void FUN_08067a64(struct Enemy* p);
void FUN_08067c4c(struct Enemy* p);
void FUN_08067f1c(struct Enemy* p);
void nop_08067f70(struct Enemy* p);
void FUN_08067f78(struct Enemy* p);
void FUN_08068018(struct Enemy* p);

// clang-format off
const EnemyFunc sBatringUpdates2[9] = {
    FUN_08067698,
    FUN_080676b0,
    batring_080677e0,
    FUN_08067a64,
    FUN_08067c4c,
    FUN_08067f1c,
    nop_08067f70,
    FUN_08067f78,
    FUN_08068018,
};
// clang-format on

NAKED static void Batring_Update(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806719C\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #8\n\
	bne _08067182\n\
	adds r0, r4, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	beq _0806719C\n\
_08067182:\n\
	ldr r1, _08067198 @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _080671D8\n\
	.align 2, 0\n\
_08067198: .4byte gEnemyFnTable\n\
_0806719C:\n\
	ldr r0, _080671B4 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	ldr r1, [r4, #0x54]\n\
	subs r2, r0, r1\n\
	cmp r2, #0\n\
	ble _080671B8\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #9\n\
	cmp r2, r0\n\
	bgt _080671C2\n\
	b _080671E4\n\
	.align 2, 0\n\
_080671B4: .4byte pZero2\n\
_080671B8:\n\
	subs r1, r1, r0\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #9\n\
	cmp r1, r0\n\
	ble _080671E4\n\
_080671C2:\n\
	ldr r1, _080671E0 @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x11]\n\
_080671D8:\n\
	adds r0, r4, #0\n\
	bl Batring_Die\n\
	b _08067222\n\
	.align 2, 0\n\
_080671E0: .4byte gEnemyFnTable\n\
_080671E4:\n\
	ldr r0, _08067228 @ =sBatringUpdates1\n\
	ldrb r1, [r4, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	bl batring_08068130\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #8\n\
	beq _08067212\n\
	cmp r0, #5\n\
	beq _08067212\n\
	cmp r0, #7\n\
	beq _08067212\n\
	adds r0, r4, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	bne _08067222\n\
_08067212:\n\
	ldr r0, _0806722C @ =sBatringUpdates2\n\
	ldrb r1, [r4, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
_08067222:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08067228: .4byte sBatringUpdates1\n\
_0806722C: .4byte sBatringUpdates2\n\
 .syntax divided\n");
}

// --------------------------------------------

NAKED static void Batring_Die(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0x20\n\
	adds r7, r0, #0\n\
	ldr r0, _0806727C @ =gCurStory\n\
	ldrb r1, [r0, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08067284\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _08067280 @ =gEnemyFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	b _08067664\n\
	.align 2, 0\n\
_0806727C: .4byte gCurStory\n\
_08067280: .4byte gEnemyFnTable\n\
_08067284:\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #0xb\n\
	bls _0806728C\n\
	b _08067666\n\
_0806728C:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08067298 @ =_0806729C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08067298: .4byte _0806729C\n\
_0806729C: @ jump table\n\
	.4byte _080672CC @ case 0\n\
	.4byte _0806741C @ case 1\n\
	.4byte _0806731C @ case 2\n\
	.4byte _080673B2 @ case 3\n\
	.4byte _08067428 @ case 4\n\
	.4byte _08067666 @ case 5\n\
	.4byte _08067666 @ case 6\n\
	.4byte _08067666 @ case 7\n\
	.4byte _08067666 @ case 8\n\
	.4byte _08067666 @ case 9\n\
	.4byte _0806741C @ case 10\n\
	.4byte _080675B8 @ case 11\n\
_080672CC:\n\
	ldr r1, _080672F4 @ =0x00000606\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	adds r1, r7, #0\n\
	adds r1, #0x8c\n\
	ldr r2, [r1]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r2\n\
	adds r3, r1, #0\n\
	cmp r0, #0\n\
	beq _080672F8\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080672F8\n\
	movs r0, #1\n\
	b _080672FA\n\
	.align 2, 0\n\
_080672F4: .4byte 0x00000606\n\
_080672F8:\n\
	movs r0, #0xa\n\
_080672FA:\n\
	strb r0, [r7, #0xe]\n\
	movs r1, #0\n\
	str r1, [r3]\n\
	adds r0, r7, #0\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r2, [r7, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r2\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	adds r0, #0x5c\n\
	str r1, [r0, #4]\n\
	str r1, [r7, #0x5c]\n\
	b _0806741C\n\
_0806731C:\n\
	movs r0, #0\n\
	str r0, [r7, #0x60]\n\
	ldr r1, [r7, #0x54]\n\
	str r1, [sp]\n\
	ldr r2, [r7, #0x58]\n\
	str r2, [sp, #4]\n\
	adds r0, r7, #0\n\
	adds r0, #0xb8\n\
	ldrb r0, [r0]\n\
	adds r3, r1, #0\n\
	cmp r0, #0\n\
	bne _08067348\n\
	ldr r1, _08067344 @ =0xFFFFF800\n\
	adds r0, r3, r1\n\
	str r0, [sp]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r2, r1\n\
	b _08067352\n\
	.align 2, 0\n\
_08067344: .4byte 0xFFFFF800\n\
_08067348:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	adds r1, r3, r0\n\
	str r1, [sp]\n\
	adds r0, r2, r0\n\
_08067352:\n\
	str r0, [sp, #4]\n\
	adds r0, r7, #0\n\
	adds r0, #0xba\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _0806737C\n\
	cmp r0, #0xfe\n\
	bne _08067372\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
	b _0806739E\n\
_08067372:\n\
	ldr r0, _0806738C @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r0, r3\n\
	ble _08067390\n\
_0806737C:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #1\n\
	bl FUN_080b2b40\n\
	b _0806739E\n\
	.align 2, 0\n\
_0806738C: .4byte pZero2\n\
_08067390:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
_0806739E:\n\
	ldrb r0, [r7, #0x11]\n\
	cmp r0, #0\n\
	bne _080673AE\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	movs r0, #1\n\
	bl TryDropItem\n\
_080673AE:\n\
	movs r0, #1\n\
	b _0806741A\n\
_080673B2:\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x10\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080673C2\n\
	str r1, [r7, #0x60]\n\
_080673C2:\n\
	ldr r1, [r7, #0x58]\n\
	ldr r0, [r7, #0x60]\n\
	adds r2, r1, r0\n\
	str r2, [r7, #0x58]\n\
	ldr r1, [r7, #0x5c]\n\
	rsbs r0, r1, #0\n\
	lsls r0, r0, #2\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r7, #0x5c]\n\
	ldr r0, [r7, #0x54]\n\
	adds r1, r0, r1\n\
	str r1, [r7, #0x54]\n\
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #0\n\
	beq _080673FC\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080673FC\n\
	adds r0, r1, #0\n\
	adds r1, r2, #0\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080673FC\n\
	b _08067666\n\
_080673FC:\n\
	adds r0, r7, #0\n\
	adds r0, #0x54\n\
	adds r1, r7, #0\n\
	adds r1, #0xb8\n\
	ldrb r1, [r1]\n\
	bl FUN_080b7680\n\
	ldr r1, _08067424 @ =0x00000606\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	movs r0, #0x44\n\
_0806741A:\n\
	strb r0, [r7, #0x12]\n\
_0806741C:\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
	b _08067666\n\
	.align 2, 0\n\
_08067424: .4byte 0x00000606\n\
_08067428:\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x13]\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x10\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _08067444\n\
	str r1, [r7, #0x60]\n\
_08067444:\n\
	ldr r1, [r7, #0x58]\n\
	ldr r0, [r7, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r7, #0x58]\n\
	ldr r2, [r7, #0x5c]\n\
	rsbs r0, r2, #0\n\
	lsls r0, r0, #2\n\
	asrs r0, r0, #8\n\
	adds r2, r2, r0\n\
	str r2, [r7, #0x5c]\n\
	ldr r0, [r7, #0x54]\n\
	adds r0, r0, r2\n\
	str r0, [r7, #0x54]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08067508\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	movs r0, #2\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
	ldr r2, _080674EC @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080674F0 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r0, _080674F4 @ =0x00269EC3\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	lsrs r0, r4, #1\n\
	str r0, [r2]\n\
	lsrs r4, r4, #0x11\n\
	movs r0, #3\n\
	ands r4, r0\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp, #8]\n\
	ldr r0, [r7, #0x58]\n\
	add r6, sp, #8\n\
	str r0, [r6, #4]\n\
	adds r5, r7, #0\n\
	adds r5, #0xb8\n\
	ldrb r1, [r5]\n\
	movs r2, #0xc1\n\
	lsls r2, r2, #3\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r1, [r5]\n\
	ldr r2, _080674F8 @ =0x00000609\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r1, [r5]\n\
	ldr r2, _080674FC @ =0x0000060A\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldrb r0, [r7, #0x11]\n\
	cmp r0, #0\n\
	beq _080674D4\n\
	b _0806764C\n\
_080674D4:\n\
	ldr r2, _08067500 @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _08067504 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _080674E2\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_080674E2:\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	adds r0, r7, #0\n\
	b _08067648\n\
	.align 2, 0\n\
_080674EC: .4byte RNG_0202f388\n\
_080674F0: .4byte 0x000343FD\n\
_080674F4: .4byte 0x00269EC3\n\
_080674F8: .4byte 0x00000609\n\
_080674FC: .4byte 0x0000060A\n\
_08067500: .4byte gMission\n\
_08067504: .4byte 0x0000270E\n\
_08067508:\n\
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #0\n\
	bne _08067510\n\
	b _08067666\n\
_08067510:\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0806751C\n\
	b _08067666\n\
_0806751C:\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	movs r0, #2\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
	ldr r2, _0806759C @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080675A0 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r1, _080675A4 @ =0x00269EC3\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	lsrs r0, r4, #1\n\
	str r0, [r2]\n\
	lsrs r4, r4, #0x11\n\
	movs r0, #3\n\
	ands r4, r0\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp, #0x10]\n\
	ldr r0, [r7, #0x58]\n\
	add r6, sp, #0x10\n\
	str r0, [r6, #4]\n\
	adds r5, r7, #0\n\
	adds r5, #0xb8\n\
	ldrb r1, [r5]\n\
	movs r2, #0xc1\n\
	lsls r2, r2, #3\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r1, [r5]\n\
	ldr r2, _080675A8 @ =0x00000609\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r1, [r5]\n\
	ldr r2, _080675AC @ =0x0000060A\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldrb r0, [r7, #0x11]\n\
	cmp r0, #0\n\
	bne _0806764C\n\
	ldr r2, _080675B0 @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _080675B4 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _08067594\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_08067594:\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	adds r0, r7, #0\n\
	b _08067648\n\
	.align 2, 0\n\
_0806759C: .4byte RNG_0202f388\n\
_080675A0: .4byte 0x000343FD\n\
_080675A4: .4byte 0x00269EC3\n\
_080675A8: .4byte 0x00000609\n\
_080675AC: .4byte 0x0000060A\n\
_080675B0: .4byte gMission\n\
_080675B4: .4byte 0x0000270E\n\
_080675B8:\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	ldrb r0, [r7, #0x11]\n\
	cmp r0, #0\n\
	bne _0806764C\n\
	movs r0, #0x54\n\
	adds r0, r0, r7\n\
	mov r8, r0\n\
	movs r0, #1\n\
	mov r1, r8\n\
	bl TryDropItem\n\
	movs r0, #1\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r2, _08067674 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _08067678 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r1, _0806767C @ =0x00269EC3\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #1\n\
	lsrs r0, r4, #1\n\
	str r0, [r2]\n\
	lsrs r4, r4, #0x11\n\
	movs r0, #3\n\
	ands r4, r0\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp, #0x18]\n\
	ldr r0, [r7, #0x58]\n\
	add r6, sp, #0x18\n\
	str r0, [r6, #4]\n\
	adds r5, r7, #0\n\
	adds r5, #0xb8\n\
	ldrb r1, [r5]\n\
	movs r2, #0xc1\n\
	lsls r2, r2, #3\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r1, [r5]\n\
	ldr r2, _08067680 @ =0x00000609\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r1, [r5]\n\
	ldr r2, _08067684 @ =0x0000060A\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b76d4\n\
	ldrb r0, [r7, #0x11]\n\
	cmp r0, #0\n\
	bne _0806764C\n\
	ldr r2, _08067688 @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _0806768C @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _08067644\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_08067644:\n\
	adds r0, r7, #0\n\
	mov r1, r8\n\
_08067648:\n\
	bl TryDropZakoDisk\n\
_0806764C:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _08067690 @ =gEnemyFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
_08067664:\n\
	str r0, [r7, #0x14]\n\
_08067666:\n\
	add sp, #0x20\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08067674: .4byte RNG_0202f388\n\
_08067678: .4byte 0x000343FD\n\
_0806767C: .4byte 0x00269EC3\n\
_08067680: .4byte 0x00000609\n\
_08067684: .4byte 0x0000060A\n\
_08067688: .4byte gMission\n\
_0806768C: .4byte 0x0000270E\n\
_08067690: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static bool8 FUN_08067694(struct Enemy* p) { return TRUE; }

static void FUN_08067698(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    (p->s).mode[2] = 1;
  }
}

static bool8 FUN_080676ac(struct Enemy* p) { return TRUE; }

NAKED static void FUN_080676b0(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r4, [r5, #0xe]\n\
	cmp r4, #1\n\
	beq _08067750\n\
	cmp r4, #1\n\
	bgt _080676C4\n\
	cmp r4, #0\n\
	beq _080676CA\n\
	b _080677D6\n\
_080676C4:\n\
	cmp r4, #2\n\
	beq _0806776C\n\
	b _080677D6\n\
_080676CA:\n\
	ldr r1, _08067700 @ =0x00000601\n\
	adds r0, r5, #0\n\
	movs r2, #2\n\
	movs r3, #0\n\
	bl GotoMotion\n\
	adds r0, r5, #0\n\
	adds r0, #0xb8\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08067704\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r4, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _08067726\n\
	.align 2, 0\n\
_08067700: .4byte 0x00000601\n\
_08067704:\n\
	movs r2, #1\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_08067726:\n\
	movs r4, #0\n\
	str r4, [r5, #0x60]\n\
	str r4, [r5, #0x5c]\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r5, #0\n\
	adds r0, #0xb9\n\
	strb r4, [r0]\n\
	subs r0, #0x45\n\
	ldr r1, _08067768 @ =sCollisions\n\
	bl SetDDP\n\
	adds r0, r5, #0\n\
	adds r0, #0xbb\n\
	strb r4, [r0]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08067750:\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #0\n\
	beq _08067760\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080677D6\n\
_08067760:\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	b _080677D4\n\
	.align 2, 0\n\
_08067768: .4byte sCollisions\n\
_0806776C:\n\
	ldr r0, _080677B8 @ =pZero2\n\
	ldr r2, [r0]\n\
	ldr r0, [r2, #0x54]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #7\n\
	adds r0, r0, r1\n\
	ldr r1, [r5, #0x54]\n\
	subs r0, r0, r1\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bhs _080677D6\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, [r2, #0x58]\n\
	cmp r1, r0\n\
	bge _080677CE\n\
	ldr r2, _080677BC @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080677C0 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080677C4 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	cmp r0, #0xb\n\
	bhi _080677C8\n\
	movs r0, #0\n\
	movs r1, #3\n\
	strb r1, [r5, #0xd]\n\
	movs r1, #4\n\
	strb r1, [r5, #0xe]\n\
	strb r0, [r5, #0xf]\n\
	b _080677D6\n\
	.align 2, 0\n\
_080677B8: .4byte pZero2\n\
_080677BC: .4byte RNG_0202f388\n\
_080677C0: .4byte 0x000343FD\n\
_080677C4: .4byte 0x00269EC3\n\
_080677C8:\n\
	movs r0, #0\n\
	strb r4, [r5, #0xd]\n\
	b _080677D4\n\
_080677CE:\n\
	movs r0, #0x1e\n\
	strb r0, [r5, #0x12]\n\
	movs r0, #1\n\
_080677D4:\n\
	strb r0, [r5, #0xe]\n\
_080677D6:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static bool8 FUN_080677dc(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/batring.inc");

static const struct Collision sCollisions[14] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(28), PIXEL(19)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(21)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(33), PIXEL(19)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(35), PIXEL(21)},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(20)},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(22)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};
