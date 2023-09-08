#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];

static void Solid44_Init(struct Solid* p);
void Solid44_Update(struct Solid* p);
void Solid44_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid44Routine = {
    [ENTITY_INIT] =      Solid44_Init,
    [ENTITY_MAIN] =      Solid44_Update,
    [ENTITY_DIE] =       Solid44_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void Solid44_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldrb r6, [r5, #0x10]\n\
	cmp r6, #0\n\
	bne _080DE2A0\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080DE24C\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r6, [r0]\n\
	adds r0, #4\n\
	str r6, [r0]\n\
	adds r0, #4\n\
	strb r6, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080DE248 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080DE2C0\n\
	.align 2, 0\n\
_080DE248: .4byte gSolidFnTable\n\
_080DE24C:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080DE298 @ =sCollisions\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	ldr r0, [r5, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r5, #0x58]\n\
	ldr r1, _080DE29C @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl Solid44_Update\n\
	b _080DE2C0\n\
	.align 2, 0\n\
_080DE298: .4byte sCollisions\n\
_080DE29C: .4byte gSolidFnTable\n\
_080DE2A0:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080DE2C8 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl Solid44_Die\n\
_080DE2C0:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DE2C8: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

INCASM("asm/solid/unk_44.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      layer : 1,
      special : 0,
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
      range : {0x0000, 0x0800, 0x2200, 0x1200},
    },
    {
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
