	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807bd40
FUN_0807bd40: @ 0x0807BD40
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0807BD6E
	cmp r0, #1
	bgt _0807BD56
	cmp r0, #0
	beq _0807BD5C
	b _0807BDDA
_0807BD56:
	cmp r0, #2
	beq _0807BDC4
	b _0807BDDA
_0807BD5C:
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _0807BD98 @ =0x00003E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BD6E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807BD7E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807BDC4
_0807BD7E:
	ldr r3, [r4, #0x54]
	str r3, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807BD9C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807BDA0
	ldr r2, _0807BD9C @ =0xFFFFF000
	b _0807BDA4
	.align 2, 0
_0807BD98: .4byte 0x00003E01
_0807BD9C: .4byte 0xFFFFF000
_0807BDA0:
	movs r2, #0x80
	lsls r2, r2, #5
_0807BDA4:
	adds r0, r3, r2
	str r0, [sp]
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #1
	ands r2, r0
	mov r0, sp
	mov r1, sp
	bl FUN_080a244c
	movs r0, #0x2d
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BDC4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807BDDA
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807BDDA:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
