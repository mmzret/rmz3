#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

// 2Dドア(青色)

static const struct Collision sCollisions[2];

static void Door2DBlue_Init(struct Solid* p);
static void Door2DBlue_Update(struct Solid* p);
static void Door2DBlue_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DBlueRoutine = {
    [ENTITY_INIT] =      Door2DBlue_Init,
    [ENTITY_UPDATE] =    Door2DBlue_Update,
    [ENTITY_DIE] =       Door2DBlue_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NON_MATCH static void Door2DBlue_Init(struct Solid* p) {
#if MODERN
  bool8 xflip;

  InitNonAffineMotion(&p->s);
  if ((p->s).work[1] == 0) {
    struct Solid* otherside = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
    if (otherside == NULL) {
      return;
    }
    (p->s).coord.x += PIXEL(8);
    (p->s).coord.y += PIXEL(9);
    (otherside->s).taskCol = 30;
    INIT_SOLID_ROUTINE(otherside, SOLID_DOOR_2D_BLUE);
    (otherside->s).tileNum = 0;
    (otherside->s).palID = 0;
    (otherside->s).flags2 |= WHITE_PAINTABLE;
    (otherside->s).invincibleID = (otherside->s).uniqueID;
    (otherside->s).work[1] = 1;
    (otherside->s).unk_28 = &p->s;
    (otherside->s).coord.x = (p->s).coord.x - PIXEL(1);
    (otherside->s).coord.y = (p->s).coord.y;
    if ((gOverworld.id & 0x7F) == STAGE_OCEAN) {
      wStaticMotionPalIDs[SM018_DOOR_2D_BLUE] = 10;
    }
    LOAD_STATIC_GRAPHIC(SM018_DOOR_2D_BLUE);
  } else {
    SetMotion(&p->s, MOTION(SM018_DOOR_2D_BLUE, 0));
    xflip = TRUE;
    (p->s).flags |= X_FLIP;
    (p->s).spr.xflip = xflip;
    (p->s).spr.oam.xflip |= TRUE;
  }

  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  Door2DBlue_Update(p);
#else
  INCCODE("asm/wip/Door2DBlue_Init.inc");
#endif
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
      damage : 255,
      atkType : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x2000, 0x2200, 0x4200},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};
