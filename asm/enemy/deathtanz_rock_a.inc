	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateDeathtanzRock
CreateDeathtanzRock: @ 0x0807A4E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov sb, r1
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldr r0, _0807A5B0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0807A544
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807A5B4 @ =gEnemyFnTable
	movs r0, #0x1b
	strb r0, [r4, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	mov r0, sb
	str r0, [r4, #0x54]
	mov r1, r8
	str r1, [r4, #0x58]
	str r5, [r4, #0x28]
	strb r7, [r4, #0x12]
_0807A544:
	movs r5, #0
	movs r6, #0
_0807A548:
	ldr r0, _0807A5B0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r2, r0, #0
	cmp r2, #0
	beq _0807A59A
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807A5B4 @ =gEnemyFnTable
	movs r0, #0x1b
	strb r0, [r2, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r6, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x10]
	mov r1, sb
	str r1, [r2, #0x54]
	ldr r1, _0807A5B8 @ =0x0836773C
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r0, r8
	str r0, [r2, #0x58]
	str r4, [r2, #0x28]
	strb r7, [r2, #0x12]
	strb r5, [r2, #0x13]
_0807A59A:
	adds r5, #1
	cmp r5, #2
	ble _0807A548
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A5B0: .4byte gEnemyHeaderPtr
_0807A5B4: .4byte gEnemyFnTable
_0807A5B8: .4byte 0x0836773C

	thumb_func_start nop_0807a5bc
nop_0807a5bc: @ 0x0807A5BC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807a5c0
FUN_0807a5c0: @ 0x0807A5C0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807A5D6
	movs r0, #0
	b _0807A5F4
_0807A5D6:
	ldr r1, _0807A5F8 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	movs r0, #0
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl DeathtanzRock_Die
	movs r0, #1
_0807A5F4:
	pop {r1}
	bx r1
	.align 2, 0
_0807A5F8: .4byte gEnemyFnTable

	thumb_func_start DeathtanzRock_Init
DeathtanzRock_Init: @ 0x0807A5FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0807A660 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0807A664 @ =0x08367742
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0807A66C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807A668 @ =0x08367664
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x14
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb4
	movs r0, #3
	strb r0, [r1]
	b _0807A68A
	.align 2, 0
_0807A660: .4byte gEnemyFnTable
_0807A664: .4byte 0x08367742
_0807A668: .4byte 0x08367664
_0807A66C:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807A69C @ =0x08367664
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_0807A68A:
	ldr r0, _0807A6A0 @ =nop_0807a5bc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl DeathtanzRock_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A69C: .4byte 0x08367664
_0807A6A0: .4byte nop_0807a5bc
