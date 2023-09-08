	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Flopper_Die
Flopper_Die: @ 0x0806BF38
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x54
	movs r0, #4
	adds r1, r6, #0
	bl AppendQuake
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r2, [r5]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0806BF74
	movs r1, #0xc0
	lsls r1, r1, #1
	lsrs r2, r2, #3
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	bl CreateProjectile7
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_0806BF74:
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bne _0806BFC4
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	movs r0, #0
	adds r1, r6, #0
	bl TryDropItem
	ldr r2, _0806BFCC @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0806BFD0 @ =0x0000270E
	cmp r1, r0
	bhi _0806BFAA
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806BFAA:
	adds r0, r4, #0
	adds r1, r6, #0
	bl TryDropZakoDisk
	ldr r1, _0806BFD4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806BFC4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806BFCC: .4byte gMission
_0806BFD0: .4byte 0x0000270E
_0806BFD4: .4byte gEnemyFnTable

	thumb_func_start Flopper_onCollision
Flopper_onCollision: @ 0x0806BFD8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806bfdc
FUN_0806bfdc: @ 0x0806BFDC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0806BFEC
	cmp r1, #1
	beq _0806C002
	b _0806C03E
_0806BFEC:
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C002:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r0]
	str r2, [r4, #0x58]
	ldr r1, _0806C044 @ =gSineTable
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r4, #0x58]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C048 @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806C03E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806C044: .4byte gSineTable
_0806C048: .4byte 0x0000FFFF

	thumb_func_start FUN_0806c04c
FUN_0806c04c: @ 0x0806C04C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0806C05C
	cmp r1, #1
	beq _0806C072
	b _0806C0AE
_0806C05C:
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C072:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	str r2, [r4, #0x54]
	ldr r1, _0806C0B4 @ =gSineTable
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C0B8 @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806C0AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806C0B4: .4byte gSineTable
_0806C0B8: .4byte 0x0000FFFF

	thumb_func_start FUN_0806c0bc
FUN_0806c0bc: @ 0x0806C0BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0806C0CC
	cmp r1, #1
	beq _0806C0E2
	b _0806C140
_0806C0CC:
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806C0E2:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r0]
	str r2, [r5, #0x54]
	ldr r4, _0806C148 @ =gSineTable
	adds r3, r5, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r2, [r0]
	str r2, [r5, #0x58]
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C14C @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0806C140:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C148: .4byte gSineTable
_0806C14C: .4byte 0x0000FFFF

	thumb_func_start FUN_0806c150
FUN_0806c150: @ 0x0806C150
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0806C160
	cmp r1, #1
	beq _0806C176
	b _0806C1D4
_0806C160:
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806C176:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r0]
	str r2, [r5, #0x54]
	ldr r4, _0806C1DC @ =gSineTable
	adds r3, r5, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	subs r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r2, [r0]
	str r2, [r5, #0x58]
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C1E0 @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0806C1D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C1DC: .4byte gSineTable
_0806C1E0: .4byte 0x0000FFFF
