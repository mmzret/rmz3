#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

static const u16 u16_ARRAY_08371064[10];
static const struct Collision sCollisions[2];

static void PhantomTeleporter_Init(struct Solid* p);
static void PhantomTeleporter_Update(struct Solid* p);
static void PhantomTeleporter_Die(struct Solid* p);

// clang-format off
const SolidRoutine gPhantomTeleporterRoutine = {
    [ENTITY_INIT] =      PhantomTeleporter_Init,
    [ENTITY_UPDATE] =    PhantomTeleporter_Update,
    [ENTITY_DIE] =       PhantomTeleporter_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void PhantomTeleporter_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #8\n\
	bne _080D8714\n\
	ldr r0, _080D870C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080D8714\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
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
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080D8710 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080D8770\n\
	.align 2, 0\n\
_080D870C: .4byte gCurStory\n\
_080D8710: .4byte gSolidFnTable\n\
_080D8714:\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	adds r2, r5, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r0, [r5, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	ldr r1, _080D8778 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r4, [r5, #0xd]\n\
	strb r4, [r5, #0xf]\n\
	strb r4, [r5, #0xe]\n\
	adds r0, r5, #0\n\
	bl PhantomTeleporter_Update\n\
_080D8770:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D8778: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

static void updatePhantomTeleporter(struct Solid* p);

static void PhantomTeleporter_Update(struct Solid* p) {
  static const SolidFunc sUpdates[1] = {
      updatePhantomTeleporter,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

static void PhantomTeleporter_Die(struct Solid* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  struct CollidableEntity* parent = body->parent;
  struct Zero* z = (struct Zero*)(body->enemy)->parent;
  if ((z->s).kind == ENTITY_PLAYER) {
    *((struct Zero**)parent->work) = z;
  }
}

NAKED static void updatePhantomTeleporter(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0xe]\n\
	cmp r0, #5\n\
	bls _080D87F4\n\
	b _080D8A24\n\
_080D87F4:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080D8800 @ =_080D8804\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080D8800: .4byte _080D8804\n\
_080D8804: @ jump table\n\
	.4byte _080D881C @ case 0\n\
	.4byte _080D88AC @ case 1\n\
	.4byte _080D88F8 @ case 2\n\
	.4byte _080D8920 @ case 3\n\
	.4byte _080D8988 @ case 4\n\
	.4byte _080D89C4 @ case 5\n\
_080D881C:\n\
	ldr r1, _080D8870 @ =gCurStory\n\
	ldr r2, _080D8874 @ =u16_ARRAY_08371064\n\
	ldrb r0, [r6, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r2, [r0]\n\
	lsrs r0, r2, #3\n\
	adds r1, #4\n\
	adds r0, r0, r1\n\
	ldrb r5, [r0]\n\
	movs r0, #7\n\
	ands r0, r2\n\
	asrs r5, r0\n\
	movs r0, #1\n\
	ands r5, r0\n\
	cmp r5, #0\n\
	bne _080D8884\n\
	ldr r1, _080D8878 @ =0x00007B01\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080D887C @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	ldr r0, _080D8880 @ =onCollision\n\
	str r0, [r4, #0x24]\n\
	adds r0, r6, #0\n\
	adds r0, #0xb4\n\
	str r5, [r0]\n\
	b _080D88A6\n\
	.align 2, 0\n\
_080D8870: .4byte gCurStory\n\
_080D8874: .4byte u16_ARRAY_08371064\n\
_080D8878: .4byte 0x00007B01\n\
_080D887C: .4byte sCollisions\n\
_080D8880: .4byte onCollision\n\
_080D8884:\n\
	movs r1, #0xf6\n\
	lsls r1, r1, #7\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	adds r0, #0x8c\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
_080D88A6:\n\
	ldrb r0, [r6, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xe]\n\
_080D88AC:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _080D88F0 @ =gInTransport\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080D88C8\n\
	ldr r0, _080D88F4 @ =gStageRun\n\
	ldrh r1, [r0, #0x14]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080D88C8\n\
	b _080D8A24\n\
_080D88C8:\n\
	adds r0, r6, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	blt _080D88D4\n\
	b _080D8A24\n\
_080D88D4:\n\
	adds r0, r6, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _080D88E0\n\
	b _080D8A24\n\
_080D88E0:\n\
	ldr r2, _080D88F4 @ =gStageRun\n\
	ldrh r1, [r2, #0x14]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2, #0x14]\n\
	movs r0, #0x1e\n\
	strb r0, [r6, #0x12]\n\
	b _080D89B4\n\
	.align 2, 0\n\
_080D88F0: .4byte gInTransport\n\
_080D88F4: .4byte gStageRun\n\
_080D88F8:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	cmp r0, #0\n\
	bne _080D8994\n\
	movs r0, #0xa5\n\
	lsls r0, r0, #1\n\
	bl PlaySound\n\
	ldr r1, _080D891C @ =0x00007B02\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #0x14\n\
	strb r0, [r6, #0x12]\n\
	b _080D89B4\n\
	.align 2, 0\n\
_080D891C: .4byte 0x00007B02\n\
_080D8920:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	cmp r0, #0\n\
	bne _080D8994\n\
	ldr r0, _080D8980 @ =gStageRun+232\n\
	movs r1, #1\n\
	bl SetCameraMode\n\
	adds r0, r6, #0\n\
	adds r0, #0x54\n\
	bl FUN_08019d20\n\
	adds r1, r0, #0\n\
	adds r2, r6, #0\n\
	adds r2, #0xb8\n\
	str r1, [r2]\n\
	cmp r1, #0\n\
	beq _080D895A\n\
	ldr r0, _080D8984 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r1]\n\
	str r1, [r0, #0x54]\n\
	ldr r1, [r2]\n\
	ldr r1, [r1, #4]\n\
	str r1, [r0, #0x58]\n\
	bl resetSateliteElfPosition\n\
_080D895A:\n\
	ldr r3, _080D8984 @ =pZero2\n\
	ldr r0, [r3]\n\
	adds r0, #0x4c\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r1, [r3]\n\
	adds r1, #0x4a\n\
	ldrb r0, [r1]\n\
	movs r2, #0x10\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldr r1, [r3]\n\
	ldrb r0, [r1, #0xa]\n\
	orrs r2, r0\n\
	strb r2, [r1, #0xa]\n\
	movs r0, #0x5a\n\
	strb r0, [r6, #0x12]\n\
	b _080D89B4\n\
	.align 2, 0\n\
_080D8980: .4byte gStageRun+232\n\
_080D8984: .4byte pZero2\n\
_080D8988:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	cmp r0, #0\n\
	beq _080D899A\n\
_080D8994:\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	b _080D8A24\n\
_080D899A:\n\
	movs r0, #0x9b\n\
	bl PlaySound\n\
	ldr r1, _080D89BC @ =0x00007B03\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldr r0, _080D89C0 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
_080D89B4:\n\
	ldrb r0, [r6, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xe]\n\
	b _080D8A24\n\
	.align 2, 0\n\
_080D89BC: .4byte 0x00007B03\n\
_080D89C0: .4byte gStageRun\n\
_080D89C4:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r4, _080D8A30 @ =gStageRun\n\
	movs r0, #0xaa\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	mov r8, r0\n\
	ldr r7, [r0]\n\
	cmp r7, #0\n\
	bne _080D8A24\n\
	ldrh r1, [r4, #0x14]\n\
	ldr r0, _080D8A34 @ =0x0000FFFD\n\
	ands r0, r1\n\
	movs r5, #0\n\
	strh r0, [r4, #0x14]\n\
	adds r4, #0xe8\n\
	adds r0, r4, #0\n\
	movs r1, #6\n\
	bl SetCameraMode\n\
	movs r0, #8\n\
	strb r0, [r4, #0x19]\n\
	strh r7, [r4, #0x22]\n\
	movs r0, #1\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	ldr r0, _080D8A38 @ =gInTransport\n\
	strb r5, [r0]\n\
	movs r0, #0x9a\n\
	bl PlaySound\n\
	ldr r4, _080D8A3C @ =pZero2\n\
	ldr r0, [r4]\n\
	bl resetSateliteElfPosition\n\
	ldr r1, [r4]\n\
	movs r0, #0xa\n\
	strb r0, [r1, #0xd]\n\
	ldr r1, [r4]\n\
	movs r0, #4\n\
	strb r0, [r1, #0xe]\n\
	ldr r0, [r4]\n\
	strb r5, [r0, #0xf]\n\
	adds r0, r6, #0\n\
	adds r0, #0xb4\n\
	str r7, [r0]\n\
	strb r5, [r6, #0xe]\n\
_080D8A24:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D8A30: .4byte gStageRun\n\
_080D8A34: .4byte 0x0000FFFD\n\
_080D8A38: .4byte gInTransport\n\
_080D8A3C: .4byte pZero2\n\
 .syntax divided\n");
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_TELEPORTAL,
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
      range : {0x0000, -0x0400, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_TELEPORTAL,
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
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

static const u16 u16_ARRAY_08371064[10] = {
    0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F, 0x0017, 0x0000,
};
