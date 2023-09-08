	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX51
CreateVFX51: @ 0x080C0AA4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _080C0AE8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C0AE2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C0AEC @ =gVFXFnTable
	movs r1, #0x33
	strb r1, [r3, #9]
	adds r0, #0xcc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x28]
_080C0AE2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C0AE8: .4byte gVFXHeaderPtr
_080C0AEC: .4byte gVFXFnTable

	thumb_func_start VFX51_Init
VFX51_Init: @ 0x080C0AF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C0B30 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080C0B34 @ =0x0836F1A0
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl VFX51_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0B30: .4byte gVFXFnTable
_080C0B34: .4byte 0x0836F1A0

	thumb_func_start VFX51_Update
VFX51_Update: @ 0x080C0B38
	push {lr}
	ldr r2, _080C0B4C @ =0x0836F19C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C0B4C: .4byte 0x0836F19C

	thumb_func_start VFX51_Die
VFX51_Die: @ 0x080C0B50
	ldr r2, _080C0B64 @ =gVFXFnTable
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
_080C0B64: .4byte gVFXFnTable

	thumb_func_start FUN_080c0b68
FUN_080c0b68: @ 0x080C0B68
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080C0B78
	cmp r6, #1
	beq _080C0BC6
	b _080C0C54
_080C0B78:
	ldr r4, _080C0BDC @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080C0BE0 @ =0x000343FD
	muls r0, r1, r0
	ldr r2, _080C0BE4 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	ldr r7, _080C0BE8 @ =0xFFFFFE00
	adds r0, r0, r7
	str r0, [r5, #0x5c]
	adds r0, r3, #0
	muls r0, r1, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	muls r1, r3, r1
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r4]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	ldr r0, _080C0BEC @ =0x0000540B
	adds r1, r1, r0
	adds r0, r5, #0
	bl SetMotion
	strb r6, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C0BC6:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C0BF0
	ldrb r0, [r5, #0xa]
	orrs r0, r1
	b _080C0BF6
	.align 2, 0
_080C0BDC: .4byte RNG_0202f388
_080C0BE0: .4byte 0x000343FD
_080C0BE4: .4byte 0x00269EC3
_080C0BE8: .4byte 0xFFFFFE00
_080C0BEC: .4byte 0x0000540B
_080C0BF0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C0BF6:
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C0C10
	str r1, [r5, #0x60]
_080C0C10:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C0C54
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080C0C5C @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080C0C54:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0C5C: .4byte gVFXFnTable
