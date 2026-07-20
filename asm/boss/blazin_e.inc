	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode6
blazinMode6: @ 0x0803F53C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0803F548
	b _0803F708
_0803F548:
	lsls r0, r0, #2
	ldr r1, _0803F554 @ =_0803F558
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F554: .4byte _0803F558
_0803F558: @ jump table
	.4byte _0803F578 @ case 0
	.4byte _0803F5A0 @ case 1
	.4byte _0803F5C4 @ case 2
	.4byte _0803F600 @ case 3
	.4byte _0803F630 @ case 4
	.4byte _0803F66A @ case 5
	.4byte _0803F6F4 @ case 6
	.4byte _0803F700 @ case 7
_0803F578:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0xa
	ldr r2, _0803F5BC @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803F5C0 @ =gBlazinCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F5A0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803F5B2
	b _0803F708
_0803F5B2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0803F708
	.align 2, 0
_0803F5BC: .4byte 0xFFFFA200
_0803F5C0: .4byte gBlazinCollisions+(24*1)
_0803F5C4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803F624 @ =0x08361D70
	bl SetDDP
	movs r0, #0
	strb r0, [r5, #0x13]
	ldr r4, _0803F628 @ =0x080FED98
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r2, _0803F62C @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r4, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F600:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803F610
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F6E2
_0803F610:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0803F6A2
	ldr r4, _0803F628 @ =0x080FED98
	b _0803F6B6
	.align 2, 0
_0803F624: .4byte gBlazinCollisions+(11*24)
_0803F628: .4byte u16_ARRAY_080fed66+(25*2)
_0803F62C: .4byte 0xFFFFA200
_0803F630:
	movs r0, #0
	strb r0, [r5, #0xf]
	strb r0, [r5, #0x13]
	ldr r4, _0803F6AC @ =u16_080fed64
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r2, _0803F6B0 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r4, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x12]
	movs r0, #0x48
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F66A:
	ldrb r0, [r5, #0xf]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803F67E
	ldrb r1, [r5, #0x12]
	ldrb r2, [r5, #0x13]
	adds r0, r5, #0
	bl blazin_08040044
_0803F67E:
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803F694
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F6E2
_0803F694:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _0803F6B4
_0803F6A2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0803F6E2
	.align 2, 0
_0803F6AC: .4byte u16_080fed64
_0803F6B0: .4byte 0xFFFFA200
_0803F6B4:
	ldr r4, _0803F6EC @ =u16_080fed64
_0803F6B6:
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r1, r5, #0
	adds r1, #0xc8
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r2, _0803F6F0 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r4, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x12]
_0803F6E2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0803F708
	.align 2, 0
_0803F6EC: .4byte u16_080fed64
_0803F6F0: .4byte 0xFFFFA200
_0803F6F4:
	movs r0, #0x48
	bl StopSound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F700:
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803F708:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

