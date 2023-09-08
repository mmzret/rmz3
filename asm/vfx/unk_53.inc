	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX53
CreateVFX53: @ 0x080C0DFC
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080C0E54 @ =gVFXHeaderPtr
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	cmp r0, #0x17
	ble _080C0E4C
	adds r0, r1, #0
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C0E4C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C0E58 @ =gVFXFnTable
	movs r1, #0x35
	strb r1, [r3, #9]
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080C0E4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0E54: .4byte gVFXHeaderPtr
_080C0E58: .4byte gVFXFnTable

	thumb_func_start VFX53_Init
VFX53_Init: @ 0x080C0E5C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C0EA0 @ =0x00005C04
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldr r1, _080C0EA4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	adds r0, r4, #0
	bl VFX53_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0EA0: .4byte 0x00005C04
_080C0EA4: .4byte gVFXFnTable

	thumb_func_start VFX53_Update
VFX53_Update: @ 0x080C0EA8
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bls _080C0EC6
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C0ECC
_080C0EC6:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C0ECC:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080C0EEA
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080C0EF0
_080C0EEA:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C0F02
_080C0EF0:
	ldr r1, _080C0F08 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C0F02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0F08: .4byte gVFXFnTable

	thumb_func_start VFX53_Die
VFX53_Die: @ 0x080C0F0C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C0F28 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080C0F28: .4byte gVFXFnTable
