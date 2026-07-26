	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ba07c
FUN_080ba07c: @ 0x080BA07C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BA114
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080BA0F8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BA0FC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080BA100 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r5, #0x10]
	ldr r2, _080BA104 @ =0x0000190C
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5, #0x10]
	ldr r2, _080BA108 @ =0x0000190D
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5, #0x10]
	ldr r2, _080BA10C @ =0x0000190E
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b9ebc
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080BA110 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080BA15C
	.align 2, 0
_080BA0F8: .4byte RNG_0202f388
_080BA0FC: .4byte 0x000343FD
_080BA100: .4byte 0x00269EC3
_080BA104: .4byte 0x0000190C
_080BA108: .4byte 0x0000190D
_080BA10C: .4byte 0x0000190E
_080BA110: .4byte gVFXFnTable
_080BA114:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080BA120
	cmp r0, #1
	beq _080BA136
	b _080BA15C
_080BA120:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r0, _080BA164 @ =0xFFFFFE00
	str r0, [r5, #0x60]
	ldr r1, _080BA168 @ =0x0000190B
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080BA136:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BA146
	str r1, [r5, #0x60]
_080BA146:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
_080BA15C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BA164: .4byte 0xFFFFFE00
_080BA168: .4byte 0x0000190B
