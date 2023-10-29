#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "sprite.h"
#include "story.h"

static const struct Collision sCollisions[2];

static void CyberSpaceDoor_Init(struct Solid* p);
static void CyberSpaceDoor_Update(struct Solid* p);
static void CyberSpaceDoor_Die(struct Solid* p);
static void CyberSpaceDoor_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gCyberSpaceDoorRoutine = {
    [ENTITY_INIT] =      CyberSpaceDoor_Init,
    [ENTITY_UPDATE] =    CyberSpaceDoor_Update,
    [ENTITY_DIE] =       CyberSpaceDoor_Die,
    [ENTITY_DISAPPEAR] = CyberSpaceDoor_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void CyberSpaceDoor_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r2, _080DBA54 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080DBA58\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _080DBA7A\n\
	b _080DBA5E\n\
	.align 2, 0\n\
_080DBA54: .4byte gCurStory\n\
_080DBA58:\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	beq _080DBA7A\n\
_080DBA5E:\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080DBABC\n\
	ldr r0, _080DBAB4 @ =gOverworld\n\
	movs r1, #0xe8\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	cmp r0, #0xf\n\
	beq _080DBABC\n\
_080DBA7A:\n\
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
	ldr r1, _080DBAB8 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r6, #0x14]\n\
	b _080DBB2A\n\
	.align 2, 0\n\
_080DBAB4: .4byte gOverworld\n\
_080DBAB8: .4byte gSolidFnTable\n\
_080DBABC:\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	adds r1, r6, #0\n\
	adds r1, #0x25\n\
	movs r5, #0\n\
	movs r0, #0x1f\n\
	strb r0, [r1]\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080DBB30 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, [r6, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r6, #0x58]\n\
	strb r5, [r6, #0x11]\n\
	ldr r1, _080DBB34 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	strb r5, [r6, #0xd]\n\
	strb r5, [r6, #0xf]\n\
	strb r5, [r6, #0xe]\n\
	adds r0, r6, #0\n\
	bl CyberSpaceDoor_Update\n\
_080DBB2A:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DBB30: .4byte sCollisions\n\
_080DBB34: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

static void FUN_080dbbd4(struct Solid* p);

static void CyberSpaceDoor_Update(struct Solid* p) {
  static const SolidFunc sUpdates[1] = {
      FUN_080dbbd4,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

static void CyberSpaceDoor_Die(struct Solid* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void CyberSpaceDoor_Disappear(struct Solid* p) {
  s32* border;
  s32 val;
  if (((p->s).work[1] != 0) && FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
    if ((gOverworld.id & 0x7F) != STAGE_AREA_X2) {
      border = &gStageRun.vm.camera.right;
      val = PIXEL(15360);
    } else {
      border = &gStageRun.vm.camera.left;
      val = 0;
    }
    *border = val;
  }
  DeleteSolid(p);
}

// --------------------------------------------

NAKED static void FUN_080dbbd4(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _080DBC2A\n\
	cmp r0, #1\n\
	bgt _080DBBE8\n\
	cmp r0, #0\n\
	beq _080DBBF0\n\
	b _080DBDE6\n\
_080DBBE8:\n\
	cmp r0, #5\n\
	bne _080DBBEE\n\
	b _080DBDCC\n\
_080DBBEE:\n\
	b _080DBDE6\n\
_080DBBF0:\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r1, r4, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r4, #0x3c]\n\
	str r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x34\n\
	ldr r1, _080DBC8C @ =FUN_080dbdf4\n\
	bl SetTaskCallback\n\
	str r4, [r4, #0x3c]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080DBC90 @ =sCollisions\n\
	bl SetDDP\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080DBC2A:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080DBCBE\n\
	ldr r5, _080DBC94 @ =gStageRun+232\n\
	ldr r1, [r5, #0x38]\n\
	ldr r2, _080DBC98 @ =0xFFFF5800\n\
	adds r0, r1, r2\n\
	ldr r3, [r4, #0x54]\n\
	cmp r3, r0\n\
	bge _080DBC40\n\
	b _080DBDE6\n\
_080DBC40:\n\
	ldr r7, _080DBC9C @ =0x0000A7FF\n\
	adds r0, r1, r7\n\
	cmp r3, r0\n\
	ble _080DBC4A\n\
	b _080DBDE6\n\
_080DBC4A:\n\
	ldr r2, [r5, #0x3c]\n\
	ldr r6, _080DBCA0 @ =0xFFFF8000\n\
	adds r0, r2, r6\n\
	ldr r1, [r4, #0x58]\n\
	cmp r1, r0\n\
	bge _080DBC58\n\
	b _080DBDE6\n\
_080DBC58:\n\
	ldr r7, _080DBCA4 @ =0x0000CFFF\n\
	adds r0, r2, r7\n\
	cmp r1, r0\n\
	ble _080DBC62\n\
	b _080DBDE6\n\
_080DBC62:\n\
	ldr r0, _080DBCA8 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080DBCB4\n\
	ldr r0, _080DBCAC @ =gOverworld\n\
	movs r1, #0xe8\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	cmp r0, #0xa\n\
	beq _080DBCB0\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	adds r0, r3, r2\n\
	str r0, [r5, #0x60]\n\
	b _080DBCB4\n\
	.align 2, 0\n\
_080DBC8C: .4byte FUN_080dbdf4\n\
_080DBC90: .4byte sCollisions\n\
_080DBC94: .4byte gStageRun+232\n\
_080DBC98: .4byte 0xFFFF5800\n\
_080DBC9C: .4byte 0x0000A7FF\n\
_080DBCA0: .4byte 0xFFFF8000\n\
_080DBCA4: .4byte 0x0000CFFF\n\
_080DBCA8: .4byte gCurStory\n\
_080DBCAC: .4byte gOverworld\n\
_080DBCB0:\n\
	adds r0, r3, r6\n\
	str r0, [r5, #0x5c]\n\
_080DBCB4:\n\
	movs r0, #0xff\n\
	strb r0, [r4, #0x1f]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x11]\n\
	b _080DBD40\n\
_080DBCBE:\n\
	ldr r3, _080DBD10 @ =gStageRun+232\n\
	ldr r2, [r3, #0x38]\n\
	ldr r5, _080DBD14 @ =0xFFFF5800\n\
	adds r0, r2, r5\n\
	ldr r1, [r4, #0x54]\n\
	cmp r1, r0\n\
	blt _080DBCE8\n\
	ldr r7, _080DBD18 @ =0x0000A7FF\n\
	adds r0, r2, r7\n\
	cmp r1, r0\n\
	bgt _080DBCE8\n\
	ldr r2, [r3, #0x3c]\n\
	ldr r1, _080DBD1C @ =0xFFFF8000\n\
	adds r0, r2, r1\n\
	ldr r1, [r4, #0x58]\n\
	cmp r1, r0\n\
	blt _080DBCE8\n\
	ldr r3, _080DBD20 @ =0x0000CFFF\n\
	adds r0, r2, r3\n\
	cmp r1, r0\n\
	ble _080DBD40\n\
_080DBCE8:\n\
	ldr r0, _080DBD24 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080DBD36\n\
	ldr r0, _080DBD28 @ =gOverworld\n\
	movs r5, #0xe8\n\
	lsls r5, r5, #1\n\
	adds r0, r0, r5\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	cmp r0, #0xa\n\
	beq _080DBD30\n\
	ldr r1, _080DBD2C @ =gStageRun+328\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xe\n\
	b _080DBD34\n\
	.align 2, 0\n\
_080DBD10: .4byte gStageRun+232\n\
_080DBD14: .4byte 0xFFFF5800\n\
_080DBD18: .4byte 0x0000A7FF\n\
_080DBD1C: .4byte 0xFFFF8000\n\
_080DBD20: .4byte 0x0000CFFF\n\
_080DBD24: .4byte gCurStory\n\
_080DBD28: .4byte gOverworld\n\
_080DBD2C: .4byte gStageRun+328\n\
_080DBD30:\n\
	ldr r1, _080DBD3C @ =gStageRun+324\n\
	movs r0, #0\n\
_080DBD34:\n\
	str r0, [r1]\n\
_080DBD36:\n\
	movs r0, #0\n\
	strb r0, [r4, #0x11]\n\
	b _080DBDE6\n\
	.align 2, 0\n\
_080DBD3C: .4byte gStageRun+324\n\
_080DBD40:\n\
	ldr r0, _080DBD6C @ =gIsUsingDoor3D\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080DBD54\n\
	ldr r0, _080DBD70 @ =gStageRun\n\
	ldrh r1, [r0, #0x14]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080DBDE6\n\
_080DBD54:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x17\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080DBD74\n\
	movs r0, #5\n\
	strb r0, [r4, #0xe]\n\
	b _080DBDE6\n\
	.align 2, 0\n\
_080DBD6C: .4byte gIsUsingDoor3D\n\
_080DBD70: .4byte gStageRun\n\
_080DBD74:\n\
	ldr r2, _080DBD98 @ =gCollisionManager\n\
	ldrb r1, [r2]\n\
	movs r0, #0x80\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldr r0, _080DBD9C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080DBDA4\n\
	ldr r0, _080DBDA0 @ =gGameState\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	bl SetGameMode\n\
	b _080DBDAC\n\
	.align 2, 0\n\
_080DBD98: .4byte gCollisionManager\n\
_080DBD9C: .4byte gCurStory\n\
_080DBDA0: .4byte gGameState\n\
_080DBDA4:\n\
	ldr r0, _080DBDC0 @ =gGameState\n\
	ldr r1, _080DBDC4 @ =0x01000700\n\
	bl SetGameMode\n\
_080DBDAC:\n\
	ldr r1, _080DBDC8 @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _080DBDE6\n\
	.align 2, 0\n\
_080DBDC0: .4byte gGameState\n\
_080DBDC4: .4byte 0x01000700\n\
_080DBDC8: .4byte gSolidFnTable\n\
_080DBDCC:\n\
	ldr r0, _080DBDEC @ =gIsUsingDoor3D\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080DBDE6\n\
	ldr r0, _080DBDF0 @ =gStageRun\n\
	ldrh r0, [r0, #0x14]\n\
	movs r1, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080DBDE6\n\
	strb r1, [r4, #0xd]\n\
	strb r1, [r4, #0xf]\n\
	strb r1, [r4, #0xe]\n\
_080DBDE6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DBDEC: .4byte gIsUsingDoor3D\n\
_080DBDF0: .4byte gStageRun\n\
 .syntax divided\n");
}

void FUN_080dbdf4(struct Sprite* s, struct DrawPivot* dp) {
  struct Solid* p = (struct Solid*)s->sprites;
  if (!FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
    if ((p->s).work[0] != 0) {
      return;
    }
  } else {
    if ((p->s).work[0] == 0) {
      return;
    }
  }

  (p->s).spr.sprites = (p->props.cyberDoor).sprites;
  UpdateMotionGraphic(&p->s);
  TaskCB_DrawNoAffineSprite(s, dp);
  (p->props.cyberDoor).sprites = (p->s).spr.sprites;
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : DOOR_3D,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(4), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : DOOR_3D,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
