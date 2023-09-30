#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollision;

static void Solid43_Init(struct Solid* p);
void Solid43_Update(struct Solid* p);
void Solid43_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid43Routine = {
    [ENTITY_INIT] =      Solid43_Init,
    [ENTITY_MAIN] =      Solid43_Update,
    [ENTITY_DIE] =       Solid43_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void Solid43_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	movs r0, #0\n\
	str r0, [r5, #0x60]\n\
	str r0, [r5, #0x5c]\n\
	ldrb r2, [r5, #0x10]\n\
	cmp r2, #0\n\
	bne _080DDFF8\n\
	ldr r0, _080DDFB0 @ =gCurStory\n\
	ldrb r1, [r0, #0xa]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #0\n\
	beq _080DDFB8\n\
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
	ldr r1, _080DDFB4 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080DE02C\n\
	.align 2, 0\n\
_080DDFB0: .4byte gCurStory\n\
_080DDFB4: .4byte gSolidFnTable\n\
_080DDFB8:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080DDFF0 @ =sCollision\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	ldr r1, _080DDFF4 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl Solid43_Update\n\
	b _080DE02C\n\
	.align 2, 0\n\
_080DDFF0: .4byte sCollision\n\
_080DDFF4: .4byte gSolidFnTable\n\
_080DDFF8:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	movs r1, #0x9c\n\
	lsls r1, r1, #8\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldr r1, _080DE034 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl Solid43_Die\n\
_080DE02C:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DE034: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

INCASM("asm/solid/unk_43.inc");

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 0,
  damage : 0,
  unk_04 : 0x00,
  element : 0x78,
  nature : 0x00,
  comboLv : 0x00,
  hitzone : 0xFF,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000000,
  range : {PIXEL(0), PIXEL(8), PIXEL(16), PIXEL(64)},
};
