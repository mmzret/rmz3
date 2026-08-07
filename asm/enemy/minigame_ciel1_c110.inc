	.include "asm/macros.inc"

	.syntax unified

	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r5, [r0, #0x28]
	ldr r0, [r0, #0x54]
	asrs r1, r0, #8
	adds r0, r1, #0
	subs r0, #0x18
	cmp r0, #0
	bge _0809C12C
	adds r0, r1, #7
_0809C12C:
	asrs r0, r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0
	ldr r1, _0809C1A4 @ =u8_ARRAY_ARRAY_0836a85c
	mov r8, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r6, r1, #1
	ldr r2, _0809C1A8 @ =u8_ARRAY_ARRAY_0836a87a
	mov sb, r2
	lsls r1, r0, #2
	adds r1, r1, r0
	mov sl, r1
_0809C148:
	adds r0, r4, r6
	mov r7, r8
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0809C1BA
	ldrb r2, [r1]
	lsrs r0, r2, #1
	lsls r0, r0, #0xc
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r3, r0, r1
	lsls r1, r2, #1
	movs r7, #0xdf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0xff
	beq _0809C1B0
	mov r0, ip
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, r3
	bge _0809C1B0
	mov r1, ip
	ldr r0, [r1, #0x58]
	cmp r0, r3
	blt _0809C1B0
	mov r0, ip
	adds r0, #0xbc
	strb r2, [r0]
	ldr r2, _0809C1AC @ =0x00000E04
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r7, ip
	str r3, [r7, #0x58]
	mov r1, sl
	adds r0, r4, r1
	add r0, sb
	ldrb r0, [r0]
	b _0809C1BC
	.align 2, 0
_0809C1A4: .4byte u8_ARRAY_ARRAY_0836a85c
_0809C1A8: .4byte u8_ARRAY_ARRAY_0836a87a
_0809C1AC: .4byte 0x00000E04
_0809C1B0:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _0809C148
_0809C1BA:
	movs r0, #0
_0809C1BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
