#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

static const u8 sInitModes[4];
static const struct Rect sSize;

bool8 FUN_080cc814(struct Solid* p);

// ------------------------------------------------------------------------------------------------------------------------------------

static void Solid6_Init(struct Solid* p);
static void Solid6_Update(struct Solid* p);
static void Solid6_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid6Routine = {
    [ENTITY_INIT] =      Solid6_Init,
    [ENTITY_MAIN] =      Solid6_Update,
    [ENTITY_DIE] =       Solid6_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateSolid6(struct Solid* s) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_006);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 0;
    (p->s).unk_28 = &s->s;
  }
}

static void Solid6_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = METATILE_GROUND;
  Solid6_Update(p);
}

// --------------------------------------------

static void nop_080cc69c(struct Solid* p);
static void FUN_080cc6a0(struct Solid* p);

static void Solid6_Update(struct Solid* p) {
  static const SolidFunc sUpdates1[1] = {
      nop_080cc69c,
  };
  static const SolidFunc sUpdates2[1] = {
      FUN_080cc6a0,
  };

  if (((p->s).unk_28)->mode[0] == 4) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

static void Solid6_Die(struct Solid* p) {
  (p->s).flags2 &= ~ENTITY_HAZARD;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void nop_080cc69c(struct Solid* p) { return; }

NAKED static void FUN_080cc6a0(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _080CC6CE\n\
	cmp r0, #1\n\
	bgt _080CC6B6\n\
	cmp r0, #0\n\
	beq _080CC6C0\n\
	b _080CC712\n\
_080CC6B6:\n\
	cmp r0, #2\n\
	beq _080CC6EC\n\
	cmp r0, #3\n\
	beq _080CC6FC\n\
	b _080CC712\n\
_080CC6C0:\n\
	ldr r1, _080CC6E8 @ =0x00003A01\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080CC6CE:\n\
	adds r0, r5, #0\n\
	bl FUN_080cc814\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080CC6E0\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080CC6E0:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _080CC712\n\
	.align 2, 0\n\
_080CC6E8: .4byte 0x00003A01\n\
_080CC6EC:\n\
	movs r1, #0xe8\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080CC6FC:\n\
	adds r0, r5, #0\n\
	bl FUN_080cc814\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080CC70C\n\
	strb r0, [r4, #0xe]\n\
_080CC70C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080CC712:\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, _080CC724 @ =0xFFFFF100\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CC724: .4byte 0xFFFFF100\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(40), PIXEL(16)};

static const u8 sInitModes[4] = {0, 0, 0, 0};
