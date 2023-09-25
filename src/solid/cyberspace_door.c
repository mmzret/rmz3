#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "story.h"

static void CyberSpaceDoor_Init(struct Solid* p);
static void CyberSpaceDoor_Update(struct Solid* p);
static void CyberSpaceDoor_Die(struct Solid* p);
static void CyberSpaceDoor_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gCyberSpaceDoorRoutine = {
    [ENTITY_INIT] =      CyberSpaceDoor_Init,
    [ENTITY_MAIN] =      CyberSpaceDoor_Update,
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
	ldr r1, _080DBB30 @ =sCyberSpaceDoorCollisions\n\
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
_080DBB30: .4byte sCyberSpaceDoorCollisions\n\
_080DBB34: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

void FUN_080dbbd4(struct Solid* p);

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
    if ((gOverworld.unk_1c8.id & 0x7F) != STAGE_AREA_X2) {
      border = &gStageRun.vm.camera.right;
      val = 0x3c0000;
    } else {
      border = &gStageRun.vm.camera.left;
      val = 0;
    }
    *border = val;
  }
  DeleteSolid(p);
}

INCASM("asm/solid/cyberspace_door.inc");

void FUN_080dbbd4(struct Solid* p);

const struct Collision sCyberSpaceDoorCollisions[2] = {
    {
      kind : DDP,
      layer : 1,
      special : DOOR_3D,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(4), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      layer : 1,
      special : DOOR_3D,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
