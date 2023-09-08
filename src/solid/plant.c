#include "collision.h"
#include "entity.h"
#include "vfx.h"
#include "global.h"
#include "solid.h"
#include "syssav.h"

// 改造カードで出現する、鉢植え、花

static void ModPlant_Init(struct Solid* p);
static void ModPlant_Update(struct Solid* p);
static void ModPlant_Die(struct Solid* p);

// clang-format off
const SolidRoutine gModPlantRoutine = {
    [ENTITY_INIT] =      ModPlant_Init,
    [ENTITY_MAIN] =      ModPlant_Update,
    [ENTITY_DIE] =       ModPlant_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void ModPlant_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080DD914\n\
	ldr r0, _080DD910 @ =gSystemSavedataManager\n\
	ldrb r0, [r0, #8]\n\
	movs r2, #1\n\
	ands r2, r0\n\
	b _080DD920\n\
	.align 2, 0\n\
_080DD910: .4byte gSystemSavedataManager\n\
_080DD914:\n\
	ldr r0, _080DD95C @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x11]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080DD920:\n\
	cmp r2, #0\n\
	bne _080DD964\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080DD960 @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080DD9E4\n\
	.align 2, 0\n\
_080DD95C: .4byte gSystemSavedataManager\n\
_080DD960: .4byte gSolidFnTable\n\
_080DD964:\n\
	ldr r1, _080DD99C @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080DD9A0\n\
	movs r1, #0xe7\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080DD9A8\n\
	.align 2, 0\n\
_080DD99C: .4byte gSolidFnTable\n\
_080DD9A0:\n\
	ldr r1, _080DD9EC @ =0x0000E701\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080DD9A8:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	movs r2, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x1e\n\
	strb r0, [r1]\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl ModPlant_Update\n\
_080DD9E4:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DD9EC: .4byte 0x0000E701\n\
 .syntax divided\n");
}

static void ModPlant_Update(struct Solid* p) {
  UpdateMotionGraphic(&p->s);
  return;
}

static void ModPlant_Die(struct Solid* p) { SET_SOLID_ROUTINE(p, ENTITY_EXIT); }
