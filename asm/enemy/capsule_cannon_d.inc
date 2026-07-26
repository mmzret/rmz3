	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08085aa0
FUN_08085aa0: @ 0x08085AA0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08085AAE
	b _08085C04
_08085AAE:
	lsls r0, r0, #2
	ldr r1, _08085AB8 @ =_08085ABC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08085AB8: .4byte _08085ABC
_08085ABC: @ jump table
	.4byte _08085AD4 @ case 0
	.4byte _08085AF2 @ case 1
	.4byte _08085B0C @ case 2
	.4byte _08085B28 @ case 3
	.4byte _08085B4C @ case 4
	.4byte _08085BE6 @ case 5
_08085AD4:
	movs r1, #0xd0
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08085B08 @ =0x00000103
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08085AF2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08085B04
	b _08085C04
_08085B04:
	b _08085B3E
	.align 2, 0
_08085B08: .4byte 0x00000103
_08085B0C:
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085B48 @ =0x083684B8
	bl SetDDP
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08085B28:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08085B3E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08085C04
_08085B3E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08085C04
	.align 2, 0
_08085B48: .4byte 0x083684B8
_08085B4C:
	ldr r3, [r4, #0x54]
	str r3, [sp]
	ldr r2, [r4, #0x58]
	str r2, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08085B68
	movs r5, #0x15
	ldr r1, _08085B64 @ =0xFFFFEE00
	b _08085B6E
	.align 2, 0
_08085B64: .4byte 0xFFFFEE00
_08085B68:
	movs r5, #0x6b
	movs r1, #0x90
	lsls r1, r1, #5
_08085B6E:
	adds r0, r3, r1
	str r0, [sp]
	ldr r1, _08085BA4 @ =0xFFFFF600
	adds r0, r2, r1
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r5, #0
	bl CreateLemon
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r3, [r4, #0x54]
	str r3, [sp]
	ldr r2, [r4, #0x58]
	str r2, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08085BAC
	movs r5, #0xeb
	ldr r1, _08085BA8 @ =0xFFFFEE00
	b _08085BB2
	.align 2, 0
_08085BA4: .4byte 0xFFFFF600
_08085BA8: .4byte 0xFFFFEE00
_08085BAC:
	movs r5, #0x95
	movs r1, #0x90
	lsls r1, r1, #5
_08085BB2:
	adds r0, r3, r1
	str r0, [sp]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r5, #0
	bl CreateLemon
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2c
	bl PlaySound
	ldr r1, _08085C0C @ =0x00006802
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08085BE6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08085C04
	ldr r0, _08085C10 @ =0x00000103
	bl PlaySound
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08085C04:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085C0C: .4byte 0x00006802
_08085C10: .4byte 0x00000103
