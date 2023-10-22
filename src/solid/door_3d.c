#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "syssav.h"
#include "zero.h"

/*
  水没した図書館のデータの落ちてる部屋のドアの一部分(スプライト部分)
*/

struct Door3D {
  struct Entity s;
  struct Body body;
  struct Zero* z;
  struct Coord* c;
  bool8 allowXFlip;  // 左右反転が許されているか
  u16 msgID;
  u8 unk_bc;
  u8 unk_bd;
  s16 unk_be;
  u8 unk_c0;
  u8 unk_c1;
  u16 unk_c2;
};  // 196 bytes

static const struct Collision sCollisions[6];
static const motion_t sMotions[6][4];

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED);

struct Coord* FUN_0801f7a4(struct Coord* _ UNUSED);
struct Coord* FUN_08019dd0(struct Coord* c);

// ------------------------------------------------------------------------------------------------------------------------------------

static void Door3D_Init(struct Solid* p);
static void Door3D_Update(struct Solid* p);
static void Door3D_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor3DRoutine = {
    [ENTITY_INIT] =      Door3D_Init,
    [ENTITY_UPDATE] =    Door3D_Update,
    [ENTITY_DIE] =       Door3D_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

NAKED static void Door3D_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0x11]\n\
	cmp r0, #0\n\
	beq _080CD16C\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #2\n\
	bne _080CD104\n\
	ldr r0, _080CD15C @ =gStageDiskManager\n\
	ldr r2, [r0]\n\
	ldrb r1, [r2, #2]\n\
	movs r5, #0xf\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	lsrs r0, r0, #1\n\
	movs r4, #1\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080CD104\n\
	ldrb r3, [r2, #4]\n\
	movs r0, #1\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _080CD104\n\
	ldrb r1, [r2, #3]\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	lsrs r0, r0, #3\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080CD104\n\
	adds r0, r5, #0\n\
	ands r0, r3\n\
	lsrs r0, r0, #1\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	bne _080CD1D6\n\
_080CD104:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #2\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080CD160 @ =0x08370064\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	ldr r0, _080CD164 @ =onCollision\n\
	str r0, [r4, #0x24]\n\
	adds r0, r6, #0\n\
	adds r0, #0xb4\n\
	str r5, [r0]\n\
	ldr r0, [r6, #0x58]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x58]\n\
	ldr r1, _080CD168 @ =gSolidFnTable\n\
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
	strb r5, [r6, #0xf]\n\
	strb r5, [r6, #0xe]\n\
	adds r0, r6, #0\n\
	bl Door3D_Update\n\
	b _080CD2CA\n\
	.align 2, 0\n\
_080CD15C: .4byte gStageDiskManager\n\
_080CD160: .4byte sCollisions+48\n\
_080CD164: .4byte onCollision\n\
_080CD168: .4byte gSolidFnTable\n\
_080CD16C:\n\
	ldrb r0, [r6, #0x10]\n\
	adds r4, r0, #0\n\
	adds r3, r0, #0\n\
	cmp r4, #3\n\
	bne _080CD1BC\n\
	ldr r0, _080CD1B4 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0xb]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080CD1BC\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	ldr r1, _080CD1B8 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r4, [r6, #0xc]\n\
	b _080CD206\n\
	.align 2, 0\n\
_080CD1B4: .4byte gSystemSavedataManager\n\
_080CD1B8: .4byte gSolidFnTable\n\
_080CD1BC:\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #5\n\
	bne _080CD218\n\
	ldr r0, _080CD210 @ =gCurStory\n\
	ldr r0, [r0, #4]\n\
	movs r1, #0x82\n\
	lsls r1, r1, #0xb\n\
	ands r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	cmp r0, r1\n\
	bne _080CD218\n\
_080CD1D6:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	ldr r1, _080CD214 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r6, #0xc]\n\
_080CD206:\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r6, #0x14]\n\
	b _080CD2CA\n\
	.align 2, 0\n\
_080CD210: .4byte gCurStory\n\
_080CD214: .4byte gSolidFnTable\n\
_080CD218:\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080CD2AC @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	mov r2, sp\n\
	bl FUN_08008eb8\n\
	ldr r2, [r6, #0x54]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	adds r2, r2, r0\n\
	str r2, [r6, #0x54]\n\
	ldr r0, [r6, #0x58]\n\
	ldr r1, _080CD2B0 @ =0x00000FFF\n\
	adds r0, r0, r1\n\
	ldr r1, [sp, #4]\n\
	adds r3, r0, r1\n\
	str r3, [r6, #0x58]\n\
	ldr r1, _080CD2B4 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r4, #1\n\
	str r4, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	ldr r0, _080CD2B8 @ =pZero2\n\
	ldr r1, [r0]\n\
	ldr r0, [r1, #0x54]\n\
	subs r0, r0, r2\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
	adds r0, r0, r2\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	cmp r0, r2\n\
	bhi _080CD2BC\n\
	ldr r0, [r1, #0x58]\n\
	subs r0, r0, r3\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	cmp r0, r2\n\
	bhi _080CD2BC\n\
	strb r4, [r6, #0xd]\n\
	strb r5, [r6, #0xf]\n\
	strb r5, [r6, #0xe]\n\
	b _080CD2C4\n\
	.align 2, 0\n\
_080CD2AC: .4byte sCollisions\n\
_080CD2B0: .4byte 0x00000FFF\n\
_080CD2B4: .4byte gSolidFnTable\n\
_080CD2B8: .4byte pZero2\n\
_080CD2BC:\n\
	movs r0, #0\n\
	strb r0, [r6, #0xd]\n\
	strb r0, [r6, #0xf]\n\
	strb r0, [r6, #0xe]\n\
_080CD2C4:\n\
	adds r0, r6, #0\n\
	bl Door3D_Update\n\
_080CD2CA:\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080cd354(struct Solid* p);
static void FUN_080cd674(struct Solid* p);
static void FUN_080cd720(struct Door3D* p);

static void Door3D_Update(struct Solid* p) {
  static const SolidFunc sUpdates[] = {
      FUN_080cd354,
      FUN_080cd674,
      (SolidFunc)FUN_080cd720,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Door3D_Die(struct Solid* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// 0x080cd320
static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  struct Door3D* door = (struct Door3D*)body->parent;
  struct Zero* z = (struct Zero*)(body->enemy)->parent;
  if ((z->s).kind == ENTITY_PLAYER) {
    door->z = z;
    gStageRun.vm.unk_004 |= 1;
    z->isAreaChange = TRUE;
  }
}

NAKED static void FUN_080cd354(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #5\n\
	bls _080CD360\n\
	b _080CD666\n\
_080CD360:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080CD36C @ =_080CD370\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080CD36C: .4byte _080CD370\n\
_080CD370: @ jump table\n\
	.4byte _080CD388 @ case 0\n\
	.4byte _080CD3B4 @ case 1\n\
	.4byte _080CD4B0 @ case 2\n\
	.4byte _080CD514 @ case 3\n\
	.4byte _080CD5EC @ case 4\n\
	.4byte _080CD64A @ case 5\n\
_080CD388:\n\
	ldr r1, _080CD3AC @ =sMotions\n\
	ldrb r0, [r5, #0x10]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080CD3B0 @ =sCollisions\n\
	bl SetDDP\n\
	b _080CD502\n\
	.align 2, 0\n\
_080CD3AC: .4byte sMotions\n\
_080CD3B0: .4byte sCollisions\n\
_080CD3B4:\n\
	ldrb r0, [r5, #0xf]\n\
	cmp r0, #0\n\
	bne _080CD3D8\n\
	ldr r0, _080CD3D4 @ =gStageRun+232\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #6\n\
	cmp r0, r1\n\
	bhi _080CD3EE\n\
	movs r0, #0xff\n\
	strb r0, [r5, #0x1f]\n\
	movs r0, #1\n\
	b _080CD3EC\n\
	.align 2, 0\n\
_080CD3D4: .4byte gStageRun+232\n\
_080CD3D8:\n\
	ldr r0, _080CD410 @ =gStageRun+232\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #6\n\
	cmp r0, r1\n\
	bls _080CD3EE\n\
	movs r0, #0\n\
_080CD3EC:\n\
	strb r0, [r5, #0xf]\n\
_080CD3EE:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r2, _080CD414 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CD41C\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080CD418 @ =sCollisions+96\n\
	bl SetDDP\n\
	movs r0, #5\n\
	strb r0, [r5, #0xe]\n\
	b _080CD666\n\
	.align 2, 0\n\
_080CD410: .4byte gStageRun+232\n\
_080CD414: .4byte gStageRun\n\
_080CD418: .4byte sCollisions+96\n\
_080CD41C:\n\
	ldr r0, _080CD470 @ =gIsUsingDoor3D\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080CD430\n\
	ldrh r1, [r2, #0x14]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080CD430\n\
	b _080CD666\n\
_080CD430:\n\
	ldr r0, _080CD474 @ =pZero2\n\
	ldr r2, [r0]\n\
	ldr r0, [r2, #0x54]\n\
	ldr r1, [r5, #0x54]\n\
	subs r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #7\n\
	cmp r0, r3\n\
	bhi _080CD468\n\
	ldr r0, [r2, #0x58]\n\
	ldr r1, [r5, #0x58]\n\
	subs r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	cmp r0, r3\n\
	bhi _080CD468\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x17\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080CD478\n\
_080CD468:\n\
	movs r0, #4\n\
	strb r0, [r5, #0xe]\n\
	b _080CD666\n\
	.align 2, 0\n\
_080CD470: .4byte gIsUsingDoor3D\n\
_080CD474: .4byte pZero2\n\
_080CD478:\n\
	ldrb r1, [r5, #0x10]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080CD490\n\
	ldr r0, _080CD48C @ =0x00000111\n\
	bl PlaySound\n\
	b _080CD498\n\
	.align 2, 0\n\
_080CD48C: .4byte 0x00000111\n\
_080CD490:\n\
	movs r0, #0xa4\n\
	lsls r0, r0, #1\n\
	bl PlaySound\n\
_080CD498:\n\
	ldr r1, _080CD4AC @ =sMotions\n\
	ldrb r0, [r5, #0x10]\n\
	lsls r0, r0, #3\n\
	adds r1, #2\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	b _080CD502\n\
	.align 2, 0\n\
_080CD4AC: .4byte sMotions\n\
_080CD4B0:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r5, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _080CD4C2\n\
	b _080CD666\n\
_080CD4C2:\n\
	ldr r0, _080CD4E0 @ =pZero2\n\
	ldr r0, [r0]\n\
	adds r0, #0x8c\n\
	ldr r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x17\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080CD4E4\n\
	movs r0, #1\n\
	strb r0, [r5, #0xd]\n\
	strb r1, [r5, #0xf]\n\
	strb r1, [r5, #0xe]\n\
	b _080CD666\n\
	.align 2, 0\n\
_080CD4E0: .4byte pZero2\n\
_080CD4E4:\n\
	ldr r1, _080CD50C @ =sMotions\n\
	ldrb r0, [r5, #0x10]\n\
	lsls r0, r0, #3\n\
	adds r1, #4\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldr r0, _080CD510 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
_080CD502:\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
	b _080CD666\n\
	.align 2, 0\n\
_080CD50C: .4byte sMotions\n\
_080CD510: .4byte gStageRun\n\
_080CD514:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _080CD544 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r2, r0, r1\n\
	ldr r1, [r2]\n\
	cmp r1, #0\n\
	beq _080CD52A\n\
	b _080CD666\n\
_080CD52A:\n\
	ldr r0, _080CD548 @ =gIsUsingDoor3D\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	str r0, [r2]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #2\n\
	beq _080CD54C\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	bl FUN_08019d20\n\
	b _080CD554\n\
	.align 2, 0\n\
_080CD544: .4byte gStageRun\n\
_080CD548: .4byte gIsUsingDoor3D\n\
_080CD54C:\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	bl FUN_0801f714\n\
_080CD554:\n\
	adds r1, r5, #0\n\
	adds r1, #0xb8\n\
	str r0, [r1]\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	bne _080CD562\n\
	b _080CD666\n\
_080CD562:\n\
	ldr r4, _080CD5A0 @ =pZero2\n\
	ldr r6, [r4]\n\
	ldr r0, [r0]\n\
	str r0, [r6, #0x54]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x58]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0]\n\
	asrs r0, r0, #8\n\
	movs r1, #0xf0\n\
	bl __modsi3\n\
	cmp r0, #0x77\n\
	bgt _080CD5A4\n\
	adds r1, r6, #0\n\
	adds r1, #0x4c\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r1, [r4]\n\
	adds r1, #0x4a\n\
	ldrb r0, [r1]\n\
	movs r2, #0x10\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldr r1, [r4]\n\
	ldrb r0, [r1, #0xa]\n\
	orrs r2, r0\n\
	strb r2, [r1, #0xa]\n\
	b _080CD5C2\n\
	.align 2, 0\n\
_080CD5A0: .4byte pZero2\n\
_080CD5A4:\n\
	adds r1, r6, #0\n\
	adds r1, #0x4c\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r1, [r4]\n\
	adds r1, #0x4a\n\
	ldrb r2, [r1]\n\
	subs r0, #0x11\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	ldr r2, [r4]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
_080CD5C2:\n\
	ldr r0, [r4]\n\
	bl resetSateliteElfPosition\n\
	ldr r1, _080CD5E4 @ =gStageRun\n\
	ldrh r2, [r1, #0x14]\n\
	ldr r0, _080CD5E8 @ =0x0000FFFE\n\
	ands r0, r2\n\
	movs r3, #0\n\
	movs r2, #0\n\
	strh r0, [r1, #0x14]\n\
	adds r1, #0xe8\n\
	movs r0, #8\n\
	strb r0, [r1, #0x19]\n\
	strh r2, [r1, #0x22]\n\
	strb r3, [r5, #0xe]\n\
	b _080CD666\n\
	.align 2, 0\n\
_080CD5E4: .4byte gStageRun\n\
_080CD5E8: .4byte 0x0000FFFE\n\
_080CD5EC:\n\
	ldr r0, _080CD634 @ =gIsUsingDoor3D\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080CD666\n\
	ldr r0, _080CD638 @ =gStageRun\n\
	ldrh r0, [r0, #0x14]\n\
	movs r3, #1\n\
	ands r3, r0\n\
	cmp r3, #0\n\
	bne _080CD666\n\
	ldr r0, _080CD63C @ =pZero2\n\
	ldr r2, [r0]\n\
	ldr r0, [r2, #0x54]\n\
	ldr r1, [r5, #0x54]\n\
	subs r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	movs r4, #0x80\n\
	lsls r4, r4, #7\n\
	cmp r0, r4\n\
	bhi _080CD640\n\
	ldr r0, [r2, #0x58]\n\
	ldr r1, [r5, #0x58]\n\
	subs r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	cmp r0, r4\n\
	bhi _080CD640\n\
	movs r0, #1\n\
	strb r0, [r5, #0xd]\n\
	strb r3, [r5, #0xf]\n\
	strb r3, [r5, #0xe]\n\
	b _080CD666\n\
	.align 2, 0\n\
_080CD634: .4byte gIsUsingDoor3D\n\
_080CD638: .4byte gStageRun\n\
_080CD63C: .4byte pZero2\n\
_080CD640:\n\
	movs r0, #0\n\
	strb r0, [r5, #0xd]\n\
	strb r0, [r5, #0xf]\n\
	strb r0, [r5, #0xe]\n\
	b _080CD666\n\
_080CD64A:\n\
	ldr r0, _080CD66C @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r4, #0\n\
	bne _080CD666\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080CD670 @ =sCollisions\n\
	bl SetDDP\n\
	strb r4, [r5, #0xe]\n\
_080CD666:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CD66C: .4byte gStageRun\n\
_080CD670: .4byte sCollisions\n\
 .syntax divided\n");
}

static void FUN_080cd674(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetMotion(&p->s, sMotions[(p->s).work[0]][2]);
      (p->s).work[2] = 30;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        if (((p->s).work[0] & 1) == 0) {
          PlaySound(SE_UNK_111);
        } else {
          PlaySound(SE_RBASE_DOOR_CLOSE);
        }
        SetMotion(&p->s, sMotions[(p->s).work[0]][3]);
        (p->s).mode[2]++;
      }
      break;
    }
    case 2: {
      UpdateMotionGraphic(&p->s);
      if ((p->s).motion.state == MOTION_END) {
        (p->s).mode[1] = 0;
        (p->s).mode[3] = 0;
        (p->s).mode[2] = 0;
      }
    }
  }
}

static void FUN_080cd720(struct Door3D* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      if (p->z == NULL) {
        return;
      }
      gStageRun.vm.screenEffect = BLACKOUT;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (gStageRun.vm.screenEffect == NO_SCREEN_EFFECT) {
        (p->z)->isAreaChange = FALSE;
        gStageRun.vm.screenEffect = SCREEN_EFFECT_01;

        if ((p->s).work[0] != 2) {
          p->c = FUN_08019dd0(&(p->s).coord);
        } else {
          p->c = FUN_0801f7a4(&(p->s).coord);
        }
        if (p->c != NULL) {
          (pZero2->s).coord.y = FUN_08009f6c((p->c)->x, (p->c)->y);
          (pZero2->s).coord.x = (p->c)->x;
          resetSateliteElfPosition(pZero2);
          gStageRun.vm.unk_004 &= ~1;

          (&gStageRun.vm.camera)->chaseMode = (1 << 3);
          (&gStageRun.vm.camera)->unk_22 = 0;
          p->z = NULL;
          (p->s).mode[2] = 0;
        }
      }
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : DOOR_3D,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0400, 0x0800, 0x0800},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : DOOR_3D,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x1200, 0x2000},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

// --------------------------------------------

// clang-format off
static const motion_t sMotions[6][4] = {
  {
    MOTION(DM192_OLA_DOOR, 0x03),
    MOTION(DM192_OLA_DOOR, 0x00),
    MOTION(DM192_OLA_DOOR, 0x01),
    MOTION(DM192_OLA_DOOR, 0x02),
  },
  {
    MOTION(DM193_BASE_DOOR, 0x03),
    MOTION(DM193_BASE_DOOR, 0x00),
    MOTION(DM193_BASE_DOOR, 0x01),
    MOTION(DM193_BASE_DOOR, 0x02),
  },
  {
    MOTION(DM195_UNK, 0x03),
    MOTION(DM195_UNK, 0x00),
    MOTION(DM195_UNK, 0x01),
    MOTION(DM195_UNK, 0x02),
  },
  {
    MOTION(DM193_BASE_DOOR, 0x03),
    MOTION(DM193_BASE_DOOR, 0x00),
    MOTION(DM193_BASE_DOOR, 0x01),
    MOTION(DM193_BASE_DOOR, 0x02),
  },
  {
    MOTION(DM195_UNK, 0x03),
    MOTION(DM195_UNK, 0x00),
    MOTION(DM195_UNK, 0x01),
    MOTION(DM195_UNK, 0x02),
  },
  {
    MOTION(DM193_BASE_DOOR, 0x03),
    MOTION(DM193_BASE_DOOR, 0x00),
    MOTION(DM193_BASE_DOOR, 0x01),
    MOTION(DM193_BASE_DOOR, 0x02),
  },
};
// clang-format on
