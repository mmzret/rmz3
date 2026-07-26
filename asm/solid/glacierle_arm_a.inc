	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start GlacierleArm_Init
GlacierleArm_Init: @ 0x080CE920
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _080CE92E
	cmp r0, #2
	bne _080CE932
_080CE92E:
	movs r0, #0
	b _080CE934
_080CE932:
	movs r0, #8
_080CE934:
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _080CE940
	subs r0, #1
	strb r0, [r5, #0x10]
_080CE940:
	ldr r1, _080CE9B4 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _080CE9B8 @ =0x08370538
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080CE9BC @ =0x08370340
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080CE9C0 @ =onCollision
	str r0, [r4, #0x24]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a134
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	adds r0, r5, #0
	bl GlacierleArm_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE9B4: .4byte gSolidFnTable
_080CE9B8: .4byte 0x08370538
_080CE9BC: .4byte 0x08370340
_080CE9C0: .4byte onCollision
