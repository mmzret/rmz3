	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start VFX61_Init
VFX61_Init: @ 0x080C2F94
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080C2FD0
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080C2FF0
_080C2FD0:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080C2FF0:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080C2FFC
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080C2FFE
_080C2FFC:
	movs r0, #0xc0
_080C2FFE:
	str r0, [r4, #0x5c]
	movs r5, #0
	str r5, [r4, #0x60]
	ldrb r3, [r4, #0x11]
	cmp r3, #0
	bne _080C3028
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C3024 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080C3088
	.align 2, 0
_080C3024: .4byte gVFXFnTable
_080C3028:
	cmp r3, #1
	bne _080C3070
	ldr r2, _080C3060 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C3064 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C3068 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080C306C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
	b _080C3088
	.align 2, 0
_080C3060: .4byte RNG_0202f388
_080C3064: .4byte 0x000343FD
_080C3068: .4byte 0x00269EC3
_080C306C: .4byte gVFXFnTable
_080C3070:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C3098 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
_080C3088:
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
	adds r0, r4, #0
	bl VFX61_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3098: .4byte gVFXFnTable

