	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode5
blazinMode5: @ 0x0803F400
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0803F40C
	b _0803F52C
_0803F40C:
	lsls r0, r0, #2
	ldr r1, _0803F418 @ =_0803F41C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F418: .4byte _0803F41C
_0803F41C: @ jump table
	.4byte _0803F434 @ case 0
	.4byte _0803F460 @ case 1
	.4byte _0803F480 @ case 2
	.4byte _0803F4A2 @ case 3
	.4byte _0803F4F8 @ case 4
	.4byte _0803F516 @ case 5
_0803F434:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #6
	ldr r2, _0803F478 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F47C @ =gBlazinCollisions+(24*1)
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F460:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803F52C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F52A
	.align 2, 0
_0803F478: .4byte 0xFFFFA200
_0803F47C: .4byte gBlazinCollisions+(24*1)
_0803F480:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F4F0 @ =gBlazinCollisions+(24*5)
	bl SetDDP
	adds r0, r4, #0
	bl blazin_080402a4
	adds r1, r4, #0
	adds r1, #0xcc
	str r0, [r1]
	movs r0, #0x70
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F4A2:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0803F4D2
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _0803F4D2
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #6
	ldr r2, _0803F4F4 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl GotoMotion
	movs r0, #1
	strb r0, [r4, #0x13]
_0803F4D2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r1, r4, #0
	adds r1, #0xcc
	ldr r0, [r1]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0803F52C
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F52A
	.align 2, 0
_0803F4F0: .4byte gBlazinCollisions+(24*5)
_0803F4F4: .4byte 0xFFFFA200
_0803F4F8:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #7
	ldr r2, _0803F534 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F516:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803F52C
	movs r0, #0
	strb r1, [r4, #0xd]
_0803F52A:
	strb r0, [r4, #0xe]
_0803F52C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F534: .4byte 0xFFFFA200

