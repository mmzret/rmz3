#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"

// Gray horizontal door

static const struct Collision sCollisions[2];

static void Solid22_Init(struct Solid* p);
static void Solid22_Update(struct Solid* p);
static void Solid22_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DGrayHRoutine = {
    [ENTITY_INIT] =      Solid22_Init,
    [ENTITY_UPDATE] =    Solid22_Update,
    [ENTITY_DIE] =       Solid22_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void Solid22_Init(struct Solid* p) {
  LOAD_STATIC_GRAPHIC(SM120_DOOR_2D_GRAY_H);
  (p->s).coord.x -= PIXEL(7);
  (p->s).coord.y += PIXEL(9);
  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  Solid22_Update(p);
}

// --------------------------------------------

void FUN_080d7eb8(struct Solid* p);
void openStageDoor_080d7f0c(struct Solid* p);
void FUN_080d8088(struct Solid* p);
void FUN_080d820c(struct Solid* p);

static void Solid22_Update(struct Solid* p) {
  static SolidFunc const sUpdates[] = {
      FUN_080d7eb8,
      openStageDoor_080d7f0c,
      FUN_080d8088,
      FUN_080d820c,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid22_Die(struct Solid* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED void FUN_080d7e5c(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r3, [r0, #0x2c]\n\
	ldr r0, [r0, #0xc]\n\
	ldr r4, [r0, #0x2c]\n\
	movs r2, #8\n\
	ldrsb r2, [r4, r2]\n\
	cmp r2, #0\n\
	bne _080D7EAA\n\
	ldr r1, [r3, #0x58]\n\
	ldr r0, [r4, #0x58]\n\
	cmp r1, r0\n\
	ble _080D7E84\n\
	ldrb r1, [r3, #0x10]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080D7EAA\n\
	strb r5, [r3, #0xd]\n\
	b _080D7E92\n\
_080D7E84:\n\
	ldrb r1, [r3, #0x10]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D7EAA\n\
	movs r0, #2\n\
	strb r0, [r3, #0xd]\n\
_080D7E92:\n\
	strb r2, [r3, #0xe]\n\
	ldr r0, _080D7EB0 @ =0x00000119\n\
	adds r1, r4, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080D7EB4 @ =gStageRun\n\
	ldrh r1, [r2, #0x14]\n\
	orrs r0, r1\n\
	strh r0, [r2, #0x14]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	str r4, [r0]\n\
_080D7EAA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D7EB0: .4byte 0x00000119\n\
_080D7EB4: .4byte gStageRun\n\
 .syntax divided\n");
}

// --------------------------------------------

INCASM("asm/solid/unk_22.inc");

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(32), PIXEL(1), PIXEL(36), PIXEL(36)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
