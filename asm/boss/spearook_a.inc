	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08061b68
FUN_08061b68: @ 0x08061B68
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsrs r2, r0, #8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08061B84
	rsbs r4, r4, #0
_08061B84:
	ldr r1, _08061BF4 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r6, [r0, r3]
	adds r0, r4, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _08061B9E
	adds r0, #0xff
_08061B9E:
	asrs r3, r0, #8
	str r3, [sp]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	rsbs r0, r1, #0
	muls r0, r7, r0
	cmp r0, #0
	bge _08061BB4
	adds r0, #0xff
_08061BB4:
	asrs r0, r0, #8
	adds r3, r0, r3
	str r3, [sp]
	adds r0, r4, #0
	muls r0, r1, r0
	cmp r0, #0
	bge _08061BC4
	adds r0, #0xff
_08061BC4:
	asrs r1, r0, #8
	str r1, [sp, #4]
	adds r0, r7, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _08061BD2
	adds r0, #0xff
_08061BD2:
	asrs r0, r0, #8
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r1, r1, r3
	str r1, [sp]
	ldr r1, [r5, #0x58]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061BF4: .4byte gSineTable

	thumb_func_start FUN_08061bf8
FUN_08061bf8: @ 0x08061BF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, _08061C04 @ =RNG_0202f388
	ldr r7, _08061C08 @ =0x0836591C
	b _08061C14
	.align 2, 0
_08061C04: .4byte RNG_0202f388
_08061C08: .4byte 0x0836591C
_08061C0C:
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _08061C40
_08061C14:
	ldr r1, [r6]
	ldr r0, _08061C54 @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _08061C58 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r3, r0, #0x11
	movs r0, #0xf
	ands r3, r0
	adds r0, r5, #0
	adds r0, #0xc2
	adds r2, r3, r7
	ldrb r1, [r0]
	movs r4, #0xc3
	adds r4, r4, r5
	mov ip, r4
	adds r4, r0, #0
	ldrb r2, [r2]
	cmp r1, r2
	beq _08061C0C
_08061C40:
	adds r0, r3, r7
	ldrb r1, [r0]
	ldrb r0, [r4]
	cmp r0, r1
	bne _08061C5C
	mov r1, ip
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08061C64
	.align 2, 0
_08061C54: .4byte 0x000343FD
_08061C58: .4byte 0x00269EC3
_08061C5C:
	movs r0, #0
	strb r1, [r4]
	mov r4, ip
	strb r0, [r4]
_08061C64:
	adds r0, r3, r7
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
