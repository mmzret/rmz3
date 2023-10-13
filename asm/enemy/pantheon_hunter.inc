	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonHunter_Die
PantheonHunter_Die: @ 0x08064ACC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08064B5E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08064AFC
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _08064B04
_08064AFC:
	strb r5, [r4, #0xd]
	adds r5, r4, #0
	adds r5, #0x8c
	b _08064B42
_08064B04:
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	adds r5, r1, #0
	cmp r2, #0
	beq _08064B40
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08064B3C @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r3, [r0]
	movs r0, #0
	mov r1, sp
	bl FUN_080b2b40
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08064B42
	.align 2, 0
_08064B3C: .4byte 0xFFFFEC00
_08064B40:
	strb r2, [r4, #0xd]
_08064B42:
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064B5E:
	ldr r0, _08064BA4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08064BAC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08064BA8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08064BBC
	.align 2, 0
_08064BA4: .4byte gCurStory
_08064BA8: .4byte gEnemyFnTable
_08064BAC:
	ldr r0, _08064BC4 @ =sDeads
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08064BBC:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08064BC4: .4byte sDeads

	thumb_func_start phunter_08064bc8
phunter_08064bc8: @ 0x08064BC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	bls _08064C08
	cmp r0, #0xc
	beq _08064C08
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08064C04
	ldr r1, [r4, #0x58]
	ldr r0, _08064C00 @ =0xFFFFF000
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _08064C08
	.align 2, 0
_08064C00: .4byte 0xFFFFF000
_08064C04:
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08064C08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start phunter_08064c10
phunter_08064c10: @ 0x08064C10
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xd]
	cmp r0, #2
	beq _08064C30
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08064C34 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08064C30
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08064C30:
	pop {r0}
	bx r0
	.align 2, 0
_08064C34: .4byte 0x00020001

	thumb_func_start FUN_08064c38
FUN_08064c38: @ 0x08064C38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08064C54
	movs r1, #0x98
	lsls r1, r1, #5
	bl SetMotion
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064C54:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08064C6A
	str r1, [r4, #0x60]
_08064C6A:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08064CA4 @ =0x0000800F
	cmp r1, r0
	beq _08064C9C
	cmp r1, #0
	beq _08064C9C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	movs r0, #6
	strb r0, [r4, #0xf]
_08064C9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08064CA4: .4byte 0x0000800F

	thumb_func_start nop_08064ca8
nop_08064ca8: @ 0x08064CA8
	bx lr
	.align 2, 0

	thumb_func_start phunter_08064cac
phunter_08064cac: @ 0x08064CAC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _08064DA6
	ldr r1, _08064D1C @ =0x00001303
	adds r0, r5, #0
	bl SetMotion
	ldr r4, _08064D20 @ =pZero2
	ldr r2, [r4]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	ldr r2, _08064D24 @ =0xFFFFE800
	adds r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _08064D28
	ldr r0, [r5, #0x5c]
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08064D42
	.align 2, 0
_08064D1C: .4byte 0x00001303
_08064D20: .4byte pZero2
_08064D24: .4byte 0xFFFFE800
_08064D28:
	ldr r0, [r4]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08064D3A
	movs r0, #0xc0
	lsls r0, r0, #3
	b _08064D3C
_08064D3A:
	ldr r0, _08064D68 @ =0xFFFFFA00
_08064D3C:
	str r0, [r5, #0x5c]
	movs r0, #0
	str r0, [r5, #0x60]
_08064D42:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _08064D6C
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08064D8E
	.align 2, 0
_08064D68: .4byte 0xFFFFFA00
_08064D6C:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08064D8E:
	adds r1, r5, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08064E00 @ =sCollisions+48
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08064DA6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	adds r2, #0x40
	str r2, [r5, #0x60]
	adds r0, r0, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08064DE2
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08064E04 @ =0xFFFFE800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08064DFA
_08064DE2:
	ldr r1, _08064E08 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl PantheonHunter_Die
_08064DFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064E00: .4byte sCollisions+48
_08064E04: .4byte 0xFFFFE800
_08064E08: .4byte gEnemyFnTable

	thumb_func_start FUN_08064e0c
FUN_08064e0c: @ 0x08064E0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08064E24
	ldr r1, _08064E30 @ =0x00001303
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064E24:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064E30: .4byte 0x00001303

	thumb_func_start nop_08064e34
nop_08064e34: @ 0x08064E34
	bx lr
	.align 2, 0

	thumb_func_start FUN_08064e38
FUN_08064e38: @ 0x08064E38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08064E58
	movs r1, #0x98
	lsls r1, r1, #5
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064E58:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08064E74
	ldrb r0, [r4, #0xf]
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08064E74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08064e7c
FUN_08064e7c: @ 0x08064E7C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08064E92
	movs r0, #0xb
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl phunter_08065218
	b _0806500A
_08064E92:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08064EF4
	ldr r1, _08064EB0 @ =0x00001309
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _08064EB4
	movs r0, #0x80
	b _08064EB8
	.align 2, 0
_08064EB0: .4byte 0x00001309
_08064EB4:
	movs r0, #0x80
	rsbs r0, r0, #0
_08064EB8:
	str r0, [r4, #0x5c]
	ldrb r2, [r2]
	cmp r2, #0
	beq _08064EC8
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08064ECE
_08064EC8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08064ECE:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08064EFC
_08064EF4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08064EFC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08064F1E
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806500A
_08064F1E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r2, _08064F68 @ =Coord_08365c8c
	adds r1, r4, #0
	adds r1, #0xbd
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r4, #0x54]
	ldr r1, [r1]
	adds r5, r2, r1
	ldr r3, _08064F6C @ =0xFFFFF800
	adds r1, r0, r3
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r6, r0, r2
	adds r0, r5, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne _08064F60
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08064F70
_08064F60:
	movs r1, #0
	movs r0, #9
	b _08065006
	.align 2, 0
_08064F68: .4byte Coord_08365c8c
_08064F6C: .4byte 0xFFFFF800
_08064F70:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08064F98
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #6
	adds r0, r0, r3
	ldr r2, [r4, #0x54]
	cmp r2, r0
	ble _08064FB4
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r7, [r4, #0xe]
	b _0806500A
_08064F98:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _08064FB0 @ =0xFFFFD800
	adds r0, r0, r2
	ldr r2, [r4, #0x54]
	cmp r2, r0
	bge _08064FB4
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	b _0806500A
	.align 2, 0
_08064FB0: .4byte 0xFFFFD800
_08064FB4:
	ldr r0, _08065010 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r3, #0xa
	ldrsh r0, [r0, r3]
	cmp r0, #6
	ble _0806500A
	movs r6, #0
	ldr r0, _08065014 @ =pZero2
	ldr r5, [r0]
	ldr r3, [r5, #0x54]
	cmp r3, r2
	bgt _08064FCE
	movs r6, #1
_08064FCE:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	ands r0, r1
	cmp r6, r0
	beq _0806500A
	subs r0, r3, r2
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806500A
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806500A
	ldrb r0, [r4, #0xd]
	movs r1, #0
	strb r0, [r4, #0xf]
	movs r0, #7
_08065006:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806500A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065010: .4byte gProjectileHeaderPtr
_08065014: .4byte pZero2

	thumb_func_start phunterRaiseArm
phunterRaiseArm: @ 0x08065018
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08065034
	ldr r1, _08065058 @ =0x00001301
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065034:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08065050
	movs r0, #8
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08065050:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065058: .4byte 0x00001301

	thumb_func_start phunterShotBuster
phunterShotBuster: @ 0x0806505C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08065076
	ldr r1, _0806508C @ =0x00001302
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065076:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #5
	beq _0806509A
	cmp r0, #5
	bgt _08065090
	cmp r0, #0
	beq _0806509A
	b _080650F4
	.align 2, 0
_0806508C: .4byte 0x00001302
_08065090:
	cmp r0, #0xa
	beq _0806509A
	cmp r0, #0x30
	beq _080650EC
	b _080650F4
_0806509A:
	ldr r0, [r4, #0x58]
	ldr r1, _080650C4 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080650C8
	ldr r0, [r4, #0x54]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp]
	movs r1, #0x90
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #0x80
	bl CreateLemon
	b _080650DC
	.align 2, 0
_080650C4: .4byte 0xFFFFEE00
_080650C8:
	ldr r0, [r4, #0x54]
	ldr r1, _080650E8 @ =0xFFFFE500
	adds r0, r0, r1
	str r0, [sp]
	movs r1, #0x90
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #0
	bl CreateLemon
_080650DC:
	cmp r0, #0
	beq _080650F4
	movs r0, #0x2c
	bl PlaySound
	b _080650F4
	.align 2, 0
_080650E8: .4byte 0xFFFFE500
_080650EC:
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080650F4:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08065104
FUN_08065104: @ 0x08065104
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08065122
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065122:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _08065184 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	cmp r0, #6
	ble _0806518C
	movs r6, #0
	ldr r0, _08065188 @ =pZero2
	ldr r5, [r0]
	ldr r3, [r5, #0x54]
	ldr r2, [r4, #0x54]
	cmp r3, r2
	bgt _08065144
	movs r6, #1
_08065144:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r6, r0
	beq _0806518C
	subs r0, r3, r2
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806518C
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806518C
	ldrb r0, [r4, #0xd]
	movs r1, #0
	strb r0, [r4, #0xf]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080651B8
	.align 2, 0
_08065184: .4byte gProjectileHeaderPtr
_08065188: .4byte pZero2
_0806518C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080651B8
	movs r0, #6
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0xbd
	ldrb r0, [r1]
	cmp r0, #0
	bne _080651B0
	movs r2, #1
_080651B0:
	strb r2, [r1]
	adds r0, r4, #0
	bl FUN_08064e7c
_080651B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start phunter_080651c0
phunter_080651c0: @ 0x080651C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080651EA
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080651DC
	adds r0, #0x1f
_080651DC:
	asrs r0, r0, #5
	str r0, [r4, #0x64]
	movs r0, #0x1f
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080651EA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08065212
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
_08065212:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start phunter_08065218
phunter_08065218: @ 0x08065218
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08065234
	movs r1, #0x98
	lsls r1, r1, #5
	bl SetMotion
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065234:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, _08065258 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0806524A
	movs r2, #1
_0806524A:
	cmp r2, #0
	beq _0806525C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08065262
	.align 2, 0
_08065258: .4byte pZero2
_0806525C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08065262:
	strb r0, [r4, #0xa]
	movs r6, #1
	adds r1, r6, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _080652E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	cmp r0, #6
	ble _080652D8
	movs r5, #0
	ldr r0, _080652E4 @ =pZero2
	ldr r3, [r0]
	ldr r2, [r3, #0x54]
	ldr r1, [r4, #0x54]
	cmp r2, r1
	bgt _0806529E
	movs r5, #1
_0806529E:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	ands r0, r6
	cmp r5, r0
	beq _080652D8
	subs r0, r2, r1
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #8
	cmp r0, r1
	bhi _080652D8
	ldr r0, [r3, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _080652D8
	ldrb r0, [r4, #0xd]
	strb r0, [r4, #0xf]
	movs r0, #7
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080652D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080652E0: .4byte gProjectileHeaderPtr
_080652E4: .4byte pZero2

	thumb_func_start phunter_080652e8
phunter_080652e8: @ 0x080652E8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08065310
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r0, [r0]
	cmp r0, #0
	beq _08065300
	movs r0, #0x80
	b _08065304
_08065300:
	movs r0, #0x80
	rsbs r0, r0, #0
_08065304:
	str r0, [r4, #0x5c]
	ldr r0, _08065368 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065310:
	ldr r1, _0806536C @ =0x00001309
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0806533C
	str r0, [r4, #0x60]
_0806533C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08065362
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0xb8
	str r0, [r1]
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08065362:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065368: .4byte 0xFFFFFD00
_0806536C: .4byte 0x00001309

	thumb_func_start explodePHunter
explodePHunter: @ 0x08065370
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	bne _0806538E
	ldr r1, _080653C8 @ =0x00001303
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0806538E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080653A0
	b _08065500
_080653A0:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080653CC @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r6, _080653D0 @ =sSlashedEnemies
	adds r2, r7, #0
	adds r2, #0xbc
	ldrb r4, [r2]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _080653D4
	orrs r3, r4
	b _080653D6
	.align 2, 0
_080653C8: .4byte 0x00001303
_080653CC: .4byte 0xFFFFE800
_080653D0: .4byte sSlashedEnemies
_080653D4:
	adds r3, r4, #0
_080653D6:
	mov r0, sp
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r6, _080653F8 @ =sSlashedEnemies+28
	ldrb r2, [r5]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080653FC
	orrs r3, r2
	b _080653FE
	.align 2, 0
_080653F8: .4byte sSlashedEnemies+28
_080653FC:
	adds r3, r2, #0
_080653FE:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r6, _08065420 @ =sSlashedEnemies+56
	ldrb r2, [r5]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08065424
	orrs r3, r2
	b _08065426
	.align 2, 0
_08065420: .4byte sSlashedEnemies+56
_08065424:
	adds r3, r2, #0
_08065426:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r0, [r7, #0x58]
	ldr r1, _0806550C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r3, _08065510 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r2, _08065514 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r5, _08065518 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	movs r6, #0x1f
	ands r1, r6
	movs r4, #0x10
	subs r1, r4, r1
	lsls r1, r1, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	bl CreateSmoke
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r6
	subs r4, r4, r0
	lsls r4, r4, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0806551C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08065520 @ =0x0000270E
	cmp r1, r0
	bhi _080654E6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080654E6:
	adds r0, r7, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _08065524 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
_08065500:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806550C: .4byte 0xFFFFF000
_08065510: .4byte RNG_0202f388
_08065514: .4byte 0x000343FD
_08065518: .4byte 0x00269EC3
_0806551C: .4byte gMission
_08065520: .4byte 0x0000270E
_08065524: .4byte gEnemyFnTable

	thumb_func_start slashPHunter
slashPHunter: @ 0x08065528
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _080655B6
	ldr r1, _0806556C @ =0x00001304
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08065570
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	adds r4, r5, #0
	adds r4, #0xbc
	ldrb r3, [r4]
	movs r1, #0
	bl CreateGhost18
	b _0806558A
	.align 2, 0
_0806556C: .4byte 0x00001304
_08065570:
	adds r0, r5, #0
	adds r0, #0x54
	ldr r1, _080655A0 @ =sSlashedEnemies+84
	ldrb r2, [r5, #0xa]
	movs r3, #0x10
	ands r3, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r2, #0
	bl CreateSlashedEnemy
	adds r4, r5, #0
	adds r4, #0xbc
_0806558A:
	ldr r0, [r5, #0x58]
	ldr r1, _080655A4 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r4]
	cmp r0, #0
	beq _080655A8
	movs r0, #0x80
	rsbs r0, r0, #0
	b _080655AA
	.align 2, 0
_080655A0: .4byte sSlashedEnemies+84
_080655A4: .4byte 0xFFFFE000
_080655A8:
	movs r0, #0x80
_080655AA:
	str r0, [r5, #0x5c]
	ldr r0, _08065610 @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080655B6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080655CC
	str r1, [r5, #0x60]
_080655CC:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080656B4
	adds r7, r5, #0
	adds r7, #0x54
	ldr r0, _08065614 @ =sSlashedEnemies
	mov ip, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r6, [r2]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	mov r8, r7
	adds r4, r2, #0
	cmp r0, #0
	beq _08065618
	orrs r3, r6
	b _0806561A
	.align 2, 0
_08065610: .4byte 0xFFFFFF00
_08065614: .4byte sSlashedEnemies
_08065618:
	adds r3, r6, #0
_0806561A:
	adds r0, r7, #0
	mov r1, ip
	movs r2, #0
	bl CreateSlashedEnemy
	mov r6, r8
	ldr r7, _0806563C @ =sSlashedEnemies+28
	ldrb r2, [r4]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08065640
	orrs r3, r2
	b _08065642
	.align 2, 0
_0806563C: .4byte sSlashedEnemies+28
_08065640:
	adds r3, r2, #0
_08065642:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r6, r8
	ldr r7, _08065664 @ =sSlashedEnemies+56
	ldrb r2, [r4]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08065668
	orrs r3, r2
	b _0806566A
	.align 2, 0
_08065664: .4byte sSlashedEnemies+56
_08065668:
	adds r3, r2, #0
_0806566A:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, r8
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080656C0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080656C4 @ =0x0000270E
	cmp r1, r0
	bhi _0806569A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806569A:
	adds r0, r5, #0
	mov r1, r8
	bl TryDropZakoDisk
	ldr r1, _080656C8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080656B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080656C0: .4byte gMission
_080656C4: .4byte 0x0000270E
_080656C8: .4byte gEnemyFnTable

	thumb_func_start FUN_080656cc
FUN_080656cc: @ 0x080656CC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _080656E4
	ldr r1, _080656F0 @ =0x00001303
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_080656E4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080656F0: .4byte 0x00001303

	thumb_func_start FUN_080656f4
FUN_080656f4: @ 0x080656F4
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806571A
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x2c]
	ldr r2, [r2, #0x2c]
	movs r3, #0
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08065714
	movs r3, #1
_08065714:
	adds r0, r2, #0
	adds r0, #0xbc
	strb r3, [r0]
_0806571A:
	pop {r0}
	bx r0
	.align 2, 0
