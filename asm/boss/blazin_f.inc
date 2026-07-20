	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode7
blazinMode7: @ 0x0803F714
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xe
	bls _0803F720
	b _0803F9A2
_0803F720:
	lsls r0, r0, #2
	ldr r1, _0803F72C @ =_0803F730
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F72C: .4byte _0803F730
_0803F730: @ jump table
	.4byte _0803F76C @ case 0
	.4byte _0803F77E @ case 1
	.4byte _0803F7B6 @ case 2
	.4byte _0803F7E0 @ case 3
	.4byte _0803F814 @ case 4
	.4byte _0803F860 @ case 5
	.4byte _0803F880 @ case 6
	.4byte _0803F8AA @ case 7
	.4byte _0803F9A2 @ case 8
	.4byte _0803F9A2 @ case 9
	.4byte _0803F8D0 @ case 10
	.4byte _0803F8FE @ case 11
	.4byte _0803F918 @ case 12
	.4byte _0803F948 @ case 13
	.4byte _0803F96C @ case 14
_0803F76C:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _0803F778
	b _0803F95C
_0803F778:
	movs r0, #0xa
	strb r0, [r6, #0xe]
	b _0803F9A2
_0803F77E:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F78A
	b _0803F99C
_0803F78A:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x12
	ldr r2, _0803F7D8 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F7DC @ =gBlazinCollisions+(24*1)
	bl SetDDP
	movs r0, #3
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F7B6:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F7C2
	b _0803F99C
_0803F7C2:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803F7D4
	b _0803F9A2
_0803F7D4:
	b _0803F95C
	.align 2, 0
_0803F7D8: .4byte 0xFFFFA200
_0803F7DC: .4byte gBlazinCollisions+(24*1)
_0803F7E0:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F7EC
	b _0803F99C
_0803F7EC:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x13
	ldr r2, _0803F858 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F85C @ =gBlazinCollisions+(24*9)
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F814:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F820
	b _0803F99C
_0803F820:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803F832
	b _0803F9A2
_0803F832:
	movs r4, #0
	ldrb r0, [r6, #0x13]
	cmp r4, r0
	bge _0803F84C
_0803F83A:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl blazin_0803ffdc
	adds r4, #1
	ldrb r2, [r6, #0x13]
	cmp r4, r2
	blt _0803F83A
_0803F84C:
	movs r0, #0x6f
	bl PlaySound
	movs r0, #2
	b _0803F95A
	.align 2, 0
_0803F858: .4byte 0xFFFFA200
_0803F85C: .4byte gBlazinCollisions+(24*9)
_0803F860:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F86C
	b _0803F99C
_0803F86C:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803F95C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F87E
	b _0803F9A2
_0803F87E:
	b _0803F95C
_0803F880:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F88C
	b _0803F99C
_0803F88C:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x14
	ldr r2, _0803F8CC @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F8AA:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	beq _0803F99C
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803F9A2
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	b _0803F9A2
	.align 2, 0
_0803F8CC: .4byte 0xFFFFA200
_0803F8D0:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x12
	ldr r2, _0803F910 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x73
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F914 @ =gBlazinCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F8FE:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803F9A2
	b _0803F95C
	.align 2, 0
_0803F910: .4byte 0xFFFFA200
_0803F914: .4byte gBlazinCollisions+(24*1)
_0803F918:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x13
	ldr r2, _0803F964 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0xd0
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F968 @ =gBlazinCollisions+(24*9)
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F948:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803F9A2
	movs r0, #8
_0803F95A:
	strb r0, [r6, #0x12]
_0803F95C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0803F9A2
	.align 2, 0
_0803F964: .4byte 0xFFFFA200
_0803F968: .4byte gBlazinCollisions+(24*9)
_0803F96C:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803F97C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F9A2
_0803F97C:
	adds r0, r6, #0
	adds r0, #0xd0
	movs r4, #0
	strb r4, [r0]
	adds r5, r6, #0
	adds r5, #0xc4
	str r4, [r5]
	adds r0, r6, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r5]
	adds r0, r6, #0
	adds r0, #0xc8
	movs r1, #0
	strh r4, [r0]
_0803F99C:
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_0803F9A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

