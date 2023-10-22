#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

bool8 shotcounter_08066da0(struct Enemy* p);

static const struct Collision sCollisions[12];

static void Shotcounter_Init(struct Enemy* p);
static void Shotcounter_Update(struct Enemy* p);
static void Shotcounter_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShotcounterRoutine = {
    [ENTITY_INIT] =      Shotcounter_Init,
    [ENTITY_UPDATE] =    Shotcounter_Update,
    [ENTITY_DIE] =       Shotcounter_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// Unused
static struct Enemy* CreateShotcounter(struct Coord* c, u8 r1) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    s32 x, y;
    (p->s).taskCol = 0x18;
    INIT_ZAKO_ROUTINE(p, 3);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = r1;
  }
  return p;
}

NAKED static void Shotcounter_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
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
	ldr r0, _0806602C @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x14]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08066038\n\
	ldr r0, _08066030 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _08066038\n\
	movs r0, #4\n\
	orrs r2, r0\n\
	strb r2, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08066034 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xc\n\
	b _08066050\n\
	.align 2, 0\n\
_0806602C: .4byte gSystemSavedataManager\n\
_08066030: .4byte gCurStory\n\
_08066034: .4byte sCollisions\n\
_08066038:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806607C @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #8\n\
_08066050:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _08066080 @ =FUN_08066e34\n\
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
	bne _08066084\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	strb r1, [r0]\n\
	adds r4, r0, #0\n\
	b _0806608E\n\
	.align 2, 0\n\
_0806607C: .4byte sCollisions\n\
_08066080: .4byte FUN_08066e34\n\
_08066084:\n\
	adds r1, r6, #0\n\
	adds r1, #0xbc\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r4, r1, #0\n\
_0806608E:\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	movs r5, #0\n\
	str r5, [r0]\n\
	subs r0, #3\n\
	strb r5, [r0]\n\
	subs r0, #5\n\
	str r5, [r0]\n\
	adds r0, r6, #0\n\
	bl isFrozen\n\
	cmp r0, #0\n\
	beq _08066112\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r2, [r4]\n\
	cmp r2, #0\n\
	bne _080660E4\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	str r2, [r6, #0x5c]\n\
	ldr r0, _080660E0 @ =0xFFFFFF00\n\
	b _0806610C\n\
	.align 2, 0\n\
_080660E0: .4byte 0xFFFFFF00\n\
_080660E4:\n\
	movs r2, #1\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
	str r5, [r6, #0x5c]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
_0806610C:\n\
	str r0, [r6, #0x64]\n\
	movs r0, #0\n\
	str r0, [r6, #0x60]\n\
_08066112:\n\
	adds r0, r6, #0\n\
	adds r0, #0xbf\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	subs r0, #1\n\
	strb r1, [r0]\n\
	ldr r2, _08066144 @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	movs r2, #1\n\
	str r2, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	strb r2, [r6, #0xd]\n\
	strb r1, [r6, #0xe]\n\
	strb r1, [r6, #0xf]\n\
	adds r0, r6, #0\n\
	bl Shotcounter_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08066144: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

static bool8 FUN_080665e0(struct Enemy* p);
static bool8 FUN_080665e8(struct Enemy* p);
void FUN_080667b8(struct Enemy* p);
void nop_08066978(struct Enemy* p);
void FUN_08066ad0(struct Enemy* p);
void FUN_08066ad8(struct Enemy* p);
void FUN_08066b30(struct Enemy* p);
void FUN_08066b38(struct Enemy* p);
void FUN_08066bdc(struct Enemy* p);

static void FUN_080665e4(struct Enemy* p);
void FUN_080665ec(struct Enemy* p);
void shotcounter_080667bc(struct Enemy* p);
void shotcounter_0806697c(struct Enemy* p);
void FUN_08066ad4(struct Enemy* p);
void FUN_08066adc(struct Enemy* p);
void FUN_08066b34(struct Enemy* p);
void FUN_08066b3c(struct Enemy* p);
void shotcounter_08066be0(struct Enemy* p);

static void Shotcounter_Update(struct Enemy* p) {
  // clang-format off
  static const EnemyFunc sUpdates1[9] = {
      (EnemyFunc)FUN_080665e0,
      (EnemyFunc)FUN_080665e8,
      FUN_080667b8,
      nop_08066978,
      FUN_08066ad0,
      FUN_08066ad8,
      FUN_08066b30,
      FUN_08066b38,
      FUN_08066bdc,
  };
  // clang-format on

  // clang-format off
  static const EnemyFunc sUpdates2[9] = {
      FUN_080665e4,
      FUN_080665ec,
      shotcounter_080667bc,
      shotcounter_0806697c,
      FUN_08066ad4,
      FUN_08066adc,
      FUN_08066b34,
      FUN_08066b3c,
      shotcounter_08066be0,
  };
  // clang-format on

  if (((p->body).status & BODY_STATUS_DEAD) && ((p->s).mode[1] != 8 || isFrozen(p))) {
    SET_ZAKO_ROUTINE(p, ENTITY_DIE);
    Shotcounter_Die(p);
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  shotcounter_08066da0(p);
  if ((p->s).mode[1] == 8 || (p->s).mode[1] == 5 || (p->s).mode[1] == 7 || !isFrozen(p)) {
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

NAKED static void Shotcounter_Die(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0x20\n\
	adds r7, r0, #0\n\
	ldr r0, _08066220 @ =gCurStory\n\
	ldrb r1, [r0, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08066228\n\
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
	ldr r1, _08066224 @ =gEnemyFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	b _080665AE\n\
	.align 2, 0\n\
_08066220: .4byte gCurStory\n\
_08066224: .4byte gEnemyFnTable\n\
_08066228:\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #0xb\n\
	bls _08066230\n\
	b _080665B0\n\
_08066230:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0806623C @ =_08066240\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0806623C: .4byte _08066240\n\
_08066240: @ jump table\n\
	.4byte _08066270 @ case 0\n\
	.4byte _08066388 @ case 1\n\
	.4byte _080662C0 @ case 2\n\
	.4byte _080662D4 @ case 3\n\
	.4byte _08066390 @ case 4\n\
	.4byte _080665B0 @ case 5\n\
	.4byte _080665B0 @ case 6\n\
	.4byte _080665B0 @ case 7\n\
	.4byte _080665B0 @ case 8\n\
	.4byte _080665B0 @ case 9\n\
	.4byte _08066388 @ case 10\n\
	.4byte _08066510 @ case 11\n\
_08066270:\n\
	ldr r1, _08066298 @ =0x00000406\n\
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
	beq _0806629C\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _0806629C\n\
	movs r0, #1\n\
	b _0806629E\n\
	.align 2, 0\n\
_08066298: .4byte 0x00000406\n\
_0806629C:\n\
	movs r0, #0xa\n\
_0806629E:\n\
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
	b _08066388\n\
_080662C0:\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r7, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080662D2\n\
	b _080665B0\n\
_080662D2:\n\
	b _08066388\n\
_080662D4:\n\
	ldr r1, _08066314 @ =0x00000406\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	movs r0, #0\n\
	strb r0, [r7, #0x13]\n\
	str r0, [r7, #0x60]\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	adds r4, r7, #0\n\
	adds r4, #0xbc\n\
	ldrb r1, [r4]\n\
	mov r0, sp\n\
	bl CreateGhost20\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	bne _0806631C\n\
	ldr r0, [sp]\n\
	ldr r1, _08066318 @ =0xFFFFF800\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	b _08066328\n\
	.align 2, 0\n\
_08066314: .4byte 0x00000406\n\
_08066318: .4byte 0xFFFFF800\n\
_0806631C:\n\
	ldr r0, [sp]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
_08066328:\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	adds r0, r7, #0\n\
	adds r0, #0xbe\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _08066356\n\
	cmp r0, #0xfe\n\
	bne _0806634A\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
	b _0806637A\n\
_0806634A:\n\
	ldr r0, _08066368 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r7, #0x54]\n\
	cmp r1, r0\n\
	ble _0806636C\n\
_08066356:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #1\n\
	bl FUN_080b2b40\n\
	b _0806637A\n\
	.align 2, 0\n\
_08066368: .4byte pZero2\n\
_0806636C:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
_0806637A:\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	movs r0, #4\n\
	bl TryDropItem\n\
	movs r0, #0x44\n\
	strb r0, [r7, #0x12]\n\
_08066388:\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
	b _080665B0\n\
_08066390:\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x10\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080663A6\n\
	str r1, [r7, #0x60]\n\
_080663A6:\n\
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
	beq _08066464\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	movs r0, #2\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
	ldr r2, _08066444 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _08066448 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r0, _0806644C @ =0x00269EC3\n\
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
	adds r5, #0xbc\n\
	ldrb r1, [r5]\n\
	ldr r2, _08066450 @ =0x00000409\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldrb r1, [r5]\n\
	ldr r2, _08066454 @ =0x0000040A\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldrb r1, [r5]\n\
	ldr r2, _08066458 @ =0x0000040B\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r2, _0806645C @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _08066460 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _0806643A\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_0806643A:\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	adds r0, r7, #0\n\
	b _08066592\n\
	.align 2, 0\n\
_08066444: .4byte RNG_0202f388\n\
_08066448: .4byte 0x000343FD\n\
_0806644C: .4byte 0x00269EC3\n\
_08066450: .4byte 0x00000409\n\
_08066454: .4byte 0x0000040A\n\
_08066458: .4byte 0x0000040B\n\
_0806645C: .4byte gMission\n\
_08066460: .4byte 0x0000270E\n\
_08066464:\n\
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #0\n\
	bne _0806646C\n\
	b _080665B0\n\
_0806646C:\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08066478\n\
	b _080665B0\n\
_08066478:\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	movs r0, #2\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
	ldr r2, _080664F0 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080664F4 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r1, _080664F8 @ =0x00269EC3\n\
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
	adds r5, #0xbc\n\
	ldrb r1, [r5]\n\
	ldr r2, _080664FC @ =0x00000409\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldrb r1, [r5]\n\
	ldr r2, _08066500 @ =0x0000040A\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldrb r1, [r5]\n\
	ldr r2, _08066504 @ =0x0000040B\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r2, _08066508 @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _0806650C @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _080664E8\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_080664E8:\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	adds r0, r7, #0\n\
	b _08066592\n\
	.align 2, 0\n\
_080664F0: .4byte RNG_0202f388\n\
_080664F4: .4byte 0x000343FD\n\
_080664F8: .4byte 0x00269EC3\n\
_080664FC: .4byte 0x00000409\n\
_08066500: .4byte 0x0000040A\n\
_08066504: .4byte 0x0000040B\n\
_08066508: .4byte gMission\n\
_0806650C: .4byte 0x0000270E\n\
_08066510:\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [sp, #4]\n\
	movs r0, #1\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	movs r0, #0x54\n\
	adds r0, r0, r7\n\
	mov r8, r0\n\
	movs r0, #4\n\
	mov r1, r8\n\
	bl TryDropItem\n\
	ldr r2, _080665BC @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080665C0 @ =0x000343FD\n\
	adds r4, r1, #0\n\
	muls r4, r0, r4\n\
	ldr r1, _080665C4 @ =0x00269EC3\n\
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
	adds r5, #0xbc\n\
	ldrb r1, [r5]\n\
	ldr r2, _080665C8 @ =0x00000409\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldrb r1, [r5]\n\
	ldr r2, _080665CC @ =0x0000040A\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldrb r1, [r5]\n\
	ldr r2, _080665D0 @ =0x0000040B\n\
	adds r0, r6, #0\n\
	adds r3, r4, #0\n\
	bl FUN_080b721c\n\
	ldr r2, _080665D4 @ =gMission\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _080665D8 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _0806658E\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_0806658E:\n\
	adds r0, r7, #0\n\
	mov r1, r8\n\
_08066592:\n\
	bl TryDropZakoDisk\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _080665DC @ =gEnemyFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
_080665AE:\n\
	str r0, [r7, #0x14]\n\
_080665B0:\n\
	add sp, #0x20\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080665BC: .4byte RNG_0202f388\n\
_080665C0: .4byte 0x000343FD\n\
_080665C4: .4byte 0x00269EC3\n\
_080665C8: .4byte 0x00000409\n\
_080665CC: .4byte 0x0000040A\n\
_080665D0: .4byte 0x0000040B\n\
_080665D4: .4byte gMission\n\
_080665D8: .4byte 0x0000270E\n\
_080665DC: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

static bool8 FUN_080665e0(struct Enemy* p) { return TRUE; }

static void FUN_080665e4(struct Enemy* p) { return; }

static bool8 FUN_080665e8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/shotcounter.inc");

static const struct Collision sCollisions[12] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 4,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1A00},
    },
    [1] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      hardness : METAL,
      remaining : 3,
      range : {-0x0C00, 0x0000, 0x0800, 0x1E00},
    },
    [2] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      hardness : METAL,
      remaining : 2,
      layer : 0xFFFFFFFF,
      range : {-0x0600, 0x0C00, 0x0C00, 0x0800},
    },
    [3] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {-0x0600, -0x0C00, 0x0C00, 0x0800},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {0x0E00, 0x0000, 0x0800, 0x1600},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0C00, 0x1A00},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x0C00, 0x1A00},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1A00},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {-0x0A00, 0x0000, 0x0800, 0x1200},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {0x0E00, 0x0000, 0x0800, 0x1600},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1A00},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1A00, 0x1A00},
    },
};

const struct Coord Coord_08365e84 = {0, 0};
