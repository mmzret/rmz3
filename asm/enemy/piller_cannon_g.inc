	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068c88
FUN_08068c88: @ 0x08068C88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _08068C94
	b _08068E50
_08068C94:
	lsls r0, r0, #2
	ldr r1, _08068CA0 @ =_08068CA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068CA0: .4byte _08068CA4
_08068CA4: @ jump table
	.4byte _08068CD4 @ case 0
	.4byte _08068D10 @ case 1
	.4byte _08068D56 @ case 2
	.4byte _08068E50 @ case 3
	.4byte _08068E50 @ case 4
	.4byte _08068E50 @ case 5
	.4byte _08068E50 @ case 6
	.4byte _08068E50 @ case 7
	.4byte _08068E50 @ case 8
	.4byte _08068E50 @ case 9
	.4byte _08068DE0 @ case 10
	.4byte _08068E30 @ case 11
_08068CD4:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08068CEA
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	strb r0, [r4, #0x13]
	movs r0, #1
	b _08068CF4
_08068CEA:
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	strb r0, [r4, #0x13]
	movs r0, #2
_08068CF4:
	strb r0, [r4, #0xe]
	ldr r1, _08068D0C @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	b _08068DCC
	.align 2, 0
_08068D0C: .4byte sMotions
_08068D10:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068DCC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08068DCC
	ldrb r0, [r4, #0x13]
	cmp r0, #5
	bhi _08068D6E
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08068D9C
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _08068D9C
_08068D56:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068DCC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08068DCC
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _08068D74
_08068D6E:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08068DCC
_08068D74:
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08068D9C
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_08068D9C:
	ldr r1, _08068DD4 @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08068DD8 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08068DDC @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
_08068DCC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08068E50
	.align 2, 0
_08068DD4: .4byte sMotions
_08068DD8: .4byte 0x08366204
_08068DDC: .4byte sCollisions
_08068DE0:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068E58 @ =0x0836609C
	bl SetDDP
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r3, [r5]
	cmp r3, #0
	beq _08068E26
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r5]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _08068E5C @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068E26:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068E30:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068E50
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08068E50
	ldrb r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068E50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068E58: .4byte sCollisions
_08068E5C: .4byte gVFXFnTable

