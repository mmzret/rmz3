#include "collision.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"

// 2Dドア(灰色)

static const struct Collision sCollisions[2];

// ------------------------------------------------------------------------------------------------------------------------------------

static void Door2DGray_Init(struct Solid* p);
static void Door2DGray_Update(struct Solid* p);
static void Door2DGray_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DGrayRoutine = {
    [ENTITY_INIT] =      Door2DGray_Init,
    [ENTITY_MAIN] =      Door2DGray_Update,
    [ENTITY_DIE] =       Door2DGray_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Door2DGray_Init(struct Solid* p) {
  InitNonAffineMotion(&p->s);
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  LOAD_STATIC_GRAPHIC(122);
  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  Door2DGray_Update(p);
}

static void FUN_080d0478(struct Solid* p);
void FUN_080d04cc(struct Solid* p);
void FUN_080d0664(struct Solid* p);
void FUN_080d0804(struct Solid* p);

static void Door2DGray_Update(struct Solid* p) {
  static const SolidFunc sUpdates[4] = {
      FUN_080d0478,
      FUN_080d04cc,
      FUN_080d0664,
      FUN_080d0804,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

static void Door2DGray_Die(struct Solid* p) {
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
	bne _080D046A\n\
	ldr r0, [r3, #0x58]\n\
	ldr r1, [r5, #0x58]\n\
	cmp r0, r1\n\
	blt _080D046A\n\
	subs r1, r0, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	bgt _080D046A\n\
	ldrb r2, [r3, #0x10]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080D0432\n\
	ldr r0, _080D0428 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080D046A\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080D042C\n\
	movs r0, #1\n\
	strb r0, [r3, #0xd]\n\
	strb r2, [r3, #0xe]\n\
	b _080D0454\n\
	.align 2, 0\n\
_080D0428: .4byte gCurStory\n\
_080D042C:\n\
	strb r6, [r3, #0xd]\n\
	strb r2, [r3, #0xe]\n\
	b _080D0454\n\
_080D0432:\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080D0448\n\
	movs r1, #1\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080D046A\n\
	strb r1, [r3, #0xd]\n\
	b _080D0452\n\
_080D0448:\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080D046A\n\
	strb r6, [r3, #0xd]\n\
_080D0452:\n\
	strb r4, [r3, #0xe]\n\
_080D0454:\n\
	ldr r0, _080D0470 @ =0x00000119\n\
	adds r1, r5, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080D0474 @ =gStageRun\n\
	ldrh r1, [r2, #0x14]\n\
	orrs r0, r1\n\
	strh r0, [r2, #0x14]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	str r5, [r0]\n\
_080D046A:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D0470: .4byte 0x00000119\n\
_080D0474: .4byte gStageRun\n\
 .syntax divided\n");
}

static void FUN_080d0478(struct Solid* p) {
  struct Body* body;
  switch ((p->s).mode[2]) {
    case 0: {
      SetMotion(&p->s, MOTION(0x7a, 0x00));
      (p->s).flags |= COLLIDABLE;
      body = &p->body;
      InitBody(body, sCollisions, &(p->s).coord, 0);
      body->parent = (struct CollidableEntity*)p;
      body->fn = onCollision;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

INCASM("asm/solid/unk_20.inc");

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DDP,
      layer : 1,
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
      range : {PIXEL(0), -PIXEL(32), PIXEL(34), PIXEL(66)},
    },
    [1] = {
      kind : DRP,
      layer : 1,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
