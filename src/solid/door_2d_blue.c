#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

// 2Dドア(青色)

static const struct Collision sCollisions[2];

static void Door2DBlue_Init(struct Solid* p);
static void Door2DBlue_Update(struct Solid* p);
static void Door2DBlue_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DBlueRoutine = {
    [ENTITY_INIT] =      Door2DBlue_Init,
    [ENTITY_MAIN] =      Door2DBlue_Update,
    [ENTITY_DIE] =       Door2DBlue_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void Door2DBlue_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r4, [r5, #0x11]\n\
	cmp r4, #0\n\
	bne _080CADD8\n\
	ldr r0, _080CADB8 @ =gSolidHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _080CAD16\n\
	b _080CAE3C\n\
_080CAD16:\n\
	ldr r0, [r5, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	movs r1, #0x90\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r1, r2, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x1e\n\
	strb r0, [r1]\n\
	ldr r1, _080CADBC @ =gSolidFnTable\n\
	movs r0, #2\n\
	strb r0, [r2, #9]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, [r0]\n\
	str r0, [r2, #0x14]\n\
	movs r0, #0\n\
	strh r4, [r2, #0x20]\n\
	adds r1, r2, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldrb r1, [r2, #0xb]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xb]\n\
	ldrb r0, [r2, #0x1c]\n\
	strb r0, [r2, #0x1d]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x11]\n\
	str r5, [r2, #0x28]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, _080CADC0 @ =0xFFFFFF00\n\
	adds r0, r0, r1\n\
	str r0, [r2, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	str r0, [r2, #0x58]\n\
	ldr r0, _080CADC4 @ =gOverworld\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	ldr r2, _080CADC8 @ =wStaticGraphicTilenums\n\
	cmp r0, #3\n\
	bne _080CAD80\n\
	ldr r1, _080CADCC @ =wStaticMotionPalIDs\n\
	movs r0, #0xa\n\
	strh r0, [r1, #0x24]\n\
_080CAD80:\n\
	movs r4, #0xb4\n\
	lsls r4, r4, #1\n\
	ldr r1, _080CADD0 @ =gStaticMotionGraphics\n\
	adds r0, r4, r1\n\
	ldrh r1, [r2, #0x24]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080CADD4 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldr r0, _080CADCC @ =wStaticMotionPalIDs\n\
	ldrh r1, [r0, #0x24]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	b _080CAE04\n\
	.align 2, 0\n\
_080CADB8: .4byte gSolidHeaderPtr\n\
_080CADBC: .4byte gSolidFnTable\n\
_080CADC0: .4byte 0xFFFFFF00\n\
_080CADC4: .4byte gOverworld\n\
_080CADC8: .4byte wStaticGraphicTilenums\n\
_080CADCC: .4byte wStaticMotionPalIDs\n\
_080CADD0: .4byte gStaticMotionGraphics\n\
_080CADD4: .4byte gStaticMotionGraphics+12\n\
_080CADD8:\n\
	movs r1, #0x90\n\
	lsls r1, r1, #5\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
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
_080CAE04:\n\
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
	movs r2, #0\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080CAE44 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r2, [r5, #0xd]\n\
	strb r2, [r5, #0xe]\n\
	adds r0, r5, #0\n\
	bl Door2DBlue_Update\n\
_080CAE3C:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CAE44: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080caf7c(struct Solid* p);
void FUN_080cafd0(struct Solid* p);
void FUN_080cb160(struct Solid* p);
void FUN_080cb2f8(struct Solid* p);

static void Door2DBlue_Update(struct Solid* p) {
  static const SolidFunc sUpdates[4] = {
      FUN_080caf7c,
      FUN_080cafd0,
      FUN_080cb160,
      FUN_080cb2f8,
  };

  if ((p->s).work[1] != 0) {
    struct Entity* friend = (p->s).unk_28;
    if (friend->mode[0] >= 2) {
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Door2DBlue_Die(p);
    } else {
      (p->s).spr.sprites = (friend->spr).sprites;
      (p->s).spr.spriteIdx = (friend->spr).spriteIdx;
    }
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void Door2DBlue_Die(struct Solid* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r3, [r0, #0x2c]\n\
	ldr r0, [r0, #0xc]\n\
	ldr r5, [r0, #0x2c]\n\
	movs r0, #8\n\
	ldrsb r0, [r5, r0]\n\
	cmp r0, #0\n\
	bne _080CAF6E\n\
	ldr r0, [r3, #0x58]\n\
	ldr r1, [r5, #0x58]\n\
	cmp r0, r1\n\
	blt _080CAF6E\n\
	subs r1, r0, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	bgt _080CAF6E\n\
	ldrb r2, [r3, #0x10]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080CAF36\n\
	ldr r0, _080CAF2C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080CAF6E\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080CAF30\n\
	movs r0, #1\n\
	strb r0, [r3, #0xd]\n\
	strb r2, [r3, #0xe]\n\
	b _080CAF58\n\
	.align 2, 0\n\
_080CAF2C: .4byte gCurStory\n\
_080CAF30:\n\
	strb r6, [r3, #0xd]\n\
	strb r2, [r3, #0xe]\n\
	b _080CAF58\n\
_080CAF36:\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080CAF4C\n\
	movs r1, #1\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080CAF6E\n\
	strb r1, [r3, #0xd]\n\
	b _080CAF56\n\
_080CAF4C:\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080CAF6E\n\
	strb r6, [r3, #0xd]\n\
_080CAF56:\n\
	strb r4, [r3, #0xe]\n\
_080CAF58:\n\
	ldr r0, _080CAF74 @ =0x00000119\n\
	adds r1, r5, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080CAF78 @ =gStageRun\n\
	ldrh r1, [r2, #0x14]\n\
	orrs r0, r1\n\
	strh r0, [r2, #0x14]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	str r5, [r0]\n\
_080CAF6E:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CAF74: .4byte 0x00000119\n\
_080CAF78: .4byte gStageRun\n\
 .syntax divided\n");
}

static void FUN_080caf7c(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetMotion(&p->s, MOTION(SM018_DOOR_2D_BLUE, 0));
      INIT_BODY(p, &sCollisions[0], 0, onCollision);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

INCASM("asm/solid/unk_02.inc");

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, -0x2000, 0x2200, 0x4200},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
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
