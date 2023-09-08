#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];

static void Solid22_Init(struct Solid* p);
static void Solid22_Update(struct Solid* p);
static void Solid22_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid22Routine = {
    [ENTITY_INIT] =      Solid22_Init,
    [ENTITY_MAIN] =      Solid22_Update,
    [ENTITY_DIE] =       Solid22_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

NAKED static void Solid22_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	movs r5, #0x96\n\
	lsls r5, r5, #4\n\
	ldr r1, _080D7DF8 @ =gStaticMotionGraphics\n\
	adds r0, r5, r1\n\
	ldr r1, _080D7DFC @ =wStaticGraphicTilenums\n\
	adds r1, #0xf0\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080D7E00 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	ldr r0, _080D7E04 @ =wStaticMotionPalIDs\n\
	adds r0, #0xf0\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, _080D7E08 @ =0xFFFFF900\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	movs r2, #0x90\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x58]\n\
	adds r2, r4, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldr r1, _080D7E0C @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	strb r5, [r4, #0xd]\n\
	strb r5, [r4, #0xe]\n\
	adds r0, r4, #0\n\
	bl Solid22_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D7DF8: .4byte gStaticMotionGraphics\n\
_080D7DFC: .4byte wStaticGraphicTilenums\n\
_080D7E00: .4byte gStaticMotionGraphics+12\n\
_080D7E04: .4byte wStaticMotionPalIDs\n\
_080D7E08: .4byte 0xFFFFF900\n\
_080D7E0C: .4byte gSolidFnTable\n\
 .syntax divided\n");
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

INCASM("asm/solid/unk_22.inc");

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
      range : {0x2000, 0x0100, 0x2400, 0x2400},
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
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};
