	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080739ac
FUN_080739ac: @ 0x080739AC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080739BC
	cmp r0, #1
	beq _080739D0
	b _08073A00
_080739BC:
	movs r0, #0x40
	strb r0, [r4, #0x12]
	movs r1, #0x90
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080739D0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080739FA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl ExplodeSplitMine
	ldr r1, _08073A08 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldrb r0, [r4, #0x10]
	strb r0, [r4, #0xd]
_080739FA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08073A00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073A08: .4byte gEnemyFnTable

	thumb_func_start FUN_08073a0c
FUN_08073a0c: @ 0x08073A0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08073A1C
	cmp r0, #1
	beq _08073A30
	b _08073A66
_08073A1C:
	ldr r0, _08073A6C @ =0x00002401
	adds r1, r0, #0
	ldrb r0, [r4, #0x11]
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08073A30:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08073A60
	ldr r1, _08073A70 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldrb r0, [r4, #0x10]
	strb r0, [r4, #0xd]
_08073A60:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08073A66:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073A6C: .4byte 0x00002401
_08073A70: .4byte gEnemyFnTable

	thumb_func_start FUN_08073a74
FUN_08073a74: @ 0x08073A74
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08073A84
	cmp r0, #1
	beq _08073AE0
	b _08073B16
_08073A84:
	adds r0, r4, #0
	bl InitRotatableMotion
	ldrb r1, [r4, #0x12]
	movs r0, #0x80
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r1, _08073B1C @ =0x00002502
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08073B20 @ =gSineTable
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08073ABA
	adds r0, #0xff
_08073ABA:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08073AD4
	adds r0, #0xff
_08073AD4:
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08073AE0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08073B10
	ldr r1, _08073B24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldrb r0, [r4, #0x10]
	strb r0, [r4, #0xd]
_08073B10:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08073B16:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073B1C: .4byte 0x00002502
_08073B20: .4byte gSineTable
_08073B24: .4byte gEnemyFnTable

	thumb_func_start FUN_08073b28
FUN_08073b28: @ 0x08073B28
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08073B9A
	cmp r0, #1
	bgt _08073B40
	cmp r0, #0
	beq _08073B4C
	ldr r3, [r5, #0x54]
	b _08073CC6
_08073B40:
	cmp r0, #2
	beq _08073BF0
	cmp r0, #3
	beq _08073C00
	ldr r3, [r5, #0x54]
	b _08073CC6
_08073B4C:
	strb r0, [r5, #0x13]
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #8
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xf0
	lsls r0, r0, #7
	adds r1, r1, r0
	str r1, [r4]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r5, #0
	adds r1, #0xb8
	str r0, [r1]
	ldr r1, _08073BDC @ =0x00002406
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #9
	ldr r1, _08073BE0 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldr r0, _08073BE4 @ =0xFFFFFC00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08073B9A:
	ldr r1, [r5, #0x54]
	str r1, [r5, #0x64]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x5c]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08073BB8
	str r1, [r5, #0x60]
_08073BB8:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	ldr r3, [r5, #0x54]
	cmp r1, #0
	bgt _08073BC8
	b _08073CC6
_08073BC8:
	ldr r0, _08073BE8 @ =gOverworld
	ldr r1, _08073BEC @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r2, r0
	ble _08073CC6
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08073CC6
	.align 2, 0
_08073BDC: .4byte 0x00002406
_08073BE0: .4byte 0xFFFFFF00
_08073BE4: .4byte 0xFFFFFC00
_08073BE8: .4byte gOverworld
_08073BEC: .4byte 0x0002C00C
_08073BF0:
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #0xa
	ldr r2, _08073D68 @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08073C00:
	ldr r3, [r5, #0x54]
	str r3, [r5, #0x64]
	ldr r1, [r5, #0x58]
	str r1, [r5, #0x68]
	ldr r0, _08073D6C @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	subs r3, r0, r3
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r1, r0
	ldr r0, [r2, #0x58]
	subs r4, r0, r1
	asrs r0, r3, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r4, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r2, r0, #8
	lsls r0, r4, #8
	adds r1, r2, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #1
	ldr r1, [r5, #0x60]
	subs r0, r4, r1
	cmp r0, #0
	bge _08073C4A
	adds r0, #7
_08073C4A:
	asrs r2, r0, #3
	adds r2, r1, r2
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #6
	cmp r0, #0
	bge _08073C64
	adds r0, #0xff
_08073C64:
	asrs r0, r0, #8
	ldr r1, [r5, #0x58]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, _08073D70 @ =gOverworld
	ldr r2, _08073D74 @ =0x0002C00C
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bge _08073C7A
	str r0, [r5, #0x58]
_08073C7A:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r1, [r5, #0x58]
	ldr r0, [r0]
	cmp r1, r0
	ble _08073C88
	str r0, [r5, #0x58]
_08073C88:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	subs r2, r0, r1
	movs r0, #0xd0
	lsls r0, r0, #7
	adds r2, r2, r0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r3, r1, #0
	cmp r2, r0
	bhi _08073CB0
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08073CC6
_08073CB0:
	ldr r1, _08073D78 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	ldrb r0, [r5, #0x10]
	strb r0, [r5, #0xd]
_08073CC6:
	ldr r0, [r5, #0x64]
	subs r3, r3, r0
	ldr r2, [r5, #0x58]
	ldr r1, [r5, #0x68]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	adds r0, #0x10
	lsls r0, r0, #0x18
	ldr r1, _08073D7C @ =0x08366DF8
	lsrs r0, r0, #0x1d
	lsls r4, r0, #1
	adds r1, r4, r1
	ldrh r1, [r1]
	adds r0, r5, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r5, #0
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x13]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08073D5E
	ldr r2, _08073D80 @ =0x08366E08
	adds r0, r4, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r2, #1
	adds r2, r4, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #8
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	add r2, sp, #0x10
	str r3, [r2, #4]
	ldr r0, _08073D84 @ =0x08366E18
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	adds r0, r5, #0
	add r1, sp, #8
	movs r3, #0
	bl FUN_080b834c
_08073D5E:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073D68: .4byte 0xFFFFFE00
_08073D6C: .4byte pZero2
_08073D70: .4byte gOverworld
_08073D74: .4byte 0x0002C00C
_08073D78: .4byte gEnemyFnTable
_08073D7C: .4byte 0x08366DF8
_08073D80: .4byte 0x08366E08
_08073D84: .4byte 0x08366E18

	thumb_func_start FUN_08073d88
FUN_08073d88: @ 0x08073D88
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl CreateVFX31_1
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _08073DD4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073DD4: .4byte gEnemyFnTable

	thumb_func_start FUN_08073dd8
FUN_08073dd8: @ 0x08073DD8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _08073E14 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073E14: .4byte gEnemyFnTable

	thumb_func_start FUN_08073e18
FUN_08073e18: @ 0x08073E18
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x3f
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl CreateVFX31_2
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08073E5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073E5C: .4byte gEnemyFnTable

	thumb_func_start FUN_08073e60
FUN_08073e60: @ 0x08073E60
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _08073EA4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	movs r0, #0x35
	bl PlaySound
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073EA4: .4byte gEnemyFnTable
