	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08034e50
FUN_08034e50: @ 0x08034E50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08034E68
	cmp r4, #1
	beq _08034EA4
	b _08034FEE
_08034E68:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08034F38 @ =0x0835EAA0
	bl SetDDP
	strb r4, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r1, _08034F3C @ =0x0000BC13
	adds r0, r5, #0
	bl SetMotion
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08034EA4:
	ldr r2, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _08034F54
	movs r3, #0
	ldr r0, _08034F40 @ =gOverworld
	movs r4, #0xe9
	lsls r4, r4, #1
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r3, r1
	bge _08034EE0
	movs r7, #0xea
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r0, r2
	beq _08034EE0
	adds r6, r1, #0
	adds r1, r4, #0
_08034ED0:
	adds r1, #0x18
	adds r3, #1
	cmp r3, r6
	bge _08034EE0
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne _08034ED0
_08034EE0:
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r3, r0
	beq _08034F44
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r0, r2, r0
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r3, #8
	adds r0, r4, r3
	adds r0, r2, r0
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x54]
	mov r3, r8
	ldr r0, [r3, #0x14]
	subs r1, r1, r0
	str r1, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r2, r0
	ldr r1, [r5, #0x58]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r2, r2, r0
	ldr r0, [r2]
	subs r1, r1, r0
	str r1, [r5, #0x58]
	b _08034F4A
	.align 2, 0
_08034F38: .4byte sCollisions+(24*1)
_08034F3C: .4byte 0x0000BC13
_08034F40: .4byte gOverworld
_08034F44:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_08034F4A:
	ldr r1, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08034F96
_08034F54:
	adds r0, r5, #0
	bl FUN_080349a8
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	ldr r1, _08034FD8 @ =0x000007FF
	cmp r0, r1
	bgt _08034F68
	str r2, [r5, #0x58]
_08034F68:
	movs r4, #1
	rsbs r4, r4, #0
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r0, r4, #0
	bl isStageBlocking
	adds r3, r0, #0
	cmp r3, r4
	beq _08034F96
	ldr r0, _08034FDC @ =gOverworld
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #0xea
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	str r0, [r5, #0x5c]
_08034F96:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08034FB2
	movs r0, #1
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08034FB2
	ldr r1, _08034FE0 @ =0x0000BC02
	adds r0, r5, #0
	bl SetMotion
_08034FB2:
	ldr r1, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08034FE8
	ldr r1, _08034FE4 @ =0x0000BC03
	adds r0, r5, #0
	movs r2, #3
	movs r3, #4
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08034FEE
	.align 2, 0
_08034FD8: .4byte 0x000007FF
_08034FDC: .4byte gOverworld
_08034FE0: .4byte 0x0000BC02
_08034FE4: .4byte 0x0000BC03
_08034FE8:
	adds r0, r5, #0
	bl UpdateEntityAnim
_08034FEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
