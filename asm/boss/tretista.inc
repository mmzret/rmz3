	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804d804
FUN_0804d804: @ 0x0804D804
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x49
	bl GetBlinkMotionState
	movs r0, #0x4a
	bl GetBlinkMotionState
	movs r0, #0x4b
	bl GetBlinkMotionState
	movs r0, #0x4c
	bl GetBlinkMotionState
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0804D8AE
	cmp r0, #1
	bgt _0804D830
	cmp r0, #0
	beq _0804D836
	b _0804D8E0
_0804D830:
	cmp r0, #2
	beq _0804D8D8
	b _0804D8E0
_0804D836:
	ldr r3, _0804D8CC @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804D858
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804D858
	ldr r0, _0804D8D0 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804D858:
	ldr r1, _0804D8D4 @ =0x0000AB25
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
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
	adds r0, r4, #0
	adds r0, #0x5c
	str r2, [r0, #4]
	str r2, [r4, #0x5c]
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804D8AE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804D8E0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804D8E0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804D8E0
	.align 2, 0
_0804D8CC: .4byte gStageRun
_0804D8D0: .4byte 0x0000FFFE
_0804D8D4: .4byte 0x0000AB25
_0804D8D8:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804D8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start tretista_0804d8e8
tretista_0804d8e8: @ 0x0804D8E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	movs r0, #0x49
	bl GetBlinkMotionState
	movs r0, #0x4a
	bl GetBlinkMotionState
	movs r0, #0x4b
	bl GetBlinkMotionState
	movs r0, #0x4c
	bl GetBlinkMotionState
	ldrb r0, [r7, #0xe]
	cmp r0, #0x19
	bls _0804D912
	b _0804DC7C
_0804D912:
	lsls r0, r0, #2
	ldr r1, _0804D91C @ =_0804D920
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804D91C: .4byte _0804D920
_0804D920: @ jump table
	.4byte _0804D988 @ case 0
	.4byte _0804DADE @ case 1
	.4byte _0804DB14 @ case 2
	.4byte _0804DB86 @ case 3
	.4byte _0804DBB8 @ case 4
	.4byte _0804DC7C @ case 5
	.4byte _0804DC7C @ case 6
	.4byte _0804DC7C @ case 7
	.4byte _0804DC7C @ case 8
	.4byte _0804DC7C @ case 9
	.4byte _0804DADE @ case 10
	.4byte _0804DBCE @ case 11
	.4byte _0804DC7C @ case 12
	.4byte _0804DC7C @ case 13
	.4byte _0804DC7C @ case 14
	.4byte _0804DC7C @ case 15
	.4byte _0804DC7C @ case 16
	.4byte _0804DC7C @ case 17
	.4byte _0804DC7C @ case 18
	.4byte _0804DC7C @ case 19
	.4byte _0804DBE0 @ case 20
	.4byte _0804DBEA @ case 21
	.4byte _0804DBF8 @ case 22
	.4byte _0804DC20 @ case 23
	.4byte _0804DC38 @ case 24
	.4byte _0804DC64 @ case 25
_0804D988:
	ldr r1, _0804DAE8 @ =0x0000AB25
	adds r0, r7, #0
	bl SetMotion
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0804D9AC
	adds r0, r7, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804D9BE
_0804D9AC:
	ldr r0, _0804DAEC @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0804D9BE
	ldrb r0, [r7, #0xf]
	cmp r0, #1
	beq _0804D9C0
_0804D9BE:
	movs r0, #0xa
_0804D9C0:
	strb r0, [r7, #0xe]
	movs r0, #0
	mov r8, r0
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	mov r1, r8
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r0, [r7, #0xa]
	movs r6, #0xfb
	ands r6, r0
	strb r6, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	cmp r0, #0
	bne _0804DA58
	ldr r3, [r7, #0x54]
	movs r0, #0x90
	lsls r0, r0, #5
	adds r3, r3, r0
	str r3, [sp]
	ldr r2, [r7, #0x58]
	ldr r1, _0804DAF0 @ =0xFFFFAC00
	adds r2, r2, r1
	str r2, [sp, #4]
	ldr r5, _0804DAF4 @ =RNG_0202f388
	ldr r1, [r5]
	ldr r0, _0804DAF8 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0804DAFC @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r5]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	str r3, [sp, #8]
	add r5, sp, #8
	str r2, [r5, #4]
	lsrs r1, r6, #4
	movs r6, #1
	ands r1, r6
	ldr r2, _0804DB00 @ =0x0000AB28
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0804DB04 @ =0x0000AB29
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0804DB08 @ =0x0000AB2A
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0804DB0C @ =0x0000AB2B
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
_0804DA58:
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0
	bne _0804DAD4
	ldr r3, [r7, #0x54]
	ldr r1, _0804DB10 @ =0xFFFFF000
	adds r3, r3, r1
	str r3, [sp]
	ldr r2, [r7, #0x58]
	ldr r0, _0804DAF0 @ =0xFFFFAC00
	adds r2, r2, r0
	str r2, [sp, #4]
	ldr r5, _0804DAF4 @ =RNG_0202f388
	ldr r1, [r5]
	ldr r0, _0804DAF8 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0804DAFC @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r5]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	str r3, [sp, #0x10]
	add r6, sp, #0x10
	str r2, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _0804DB00 @ =0x0000AB28
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0804DB04 @ =0x0000AB29
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0804DB08 @ =0x0000AB2A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0804DB0C @ =0x0000AB2B
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
_0804DAD4:
	adds r0, r7, #0
	adds r0, #0x5c
	mov r1, r8
	str r1, [r0, #4]
	str r1, [r7, #0x5c]
_0804DADE:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0804DC2C
	.align 2, 0
_0804DAE8: .4byte 0x0000AB25
_0804DAEC: .4byte gStageRun
_0804DAF0: .4byte 0xFFFFAC00
_0804DAF4: .4byte RNG_0202f388
_0804DAF8: .4byte 0x000343FD
_0804DAFC: .4byte 0x00269EC3
_0804DB00: .4byte 0x0000AB28
_0804DB04: .4byte 0x0000AB29
_0804DB08: .4byte 0x0000AB2A
_0804DB0C: .4byte 0x0000AB2B
_0804DB10: .4byte 0xFFFFF000
_0804DB14:
	movs r0, #0
	str r0, [r7, #0x60]
	ldr r2, [r7, #0x54]
	str r2, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804DB2C
	str r2, [sp]
_0804DB2C:
	ldr r1, _0804DB4C @ =0xFFFFD000
	adds r0, r3, r1
	str r0, [sp, #4]
	ldrb r0, [r7, #0x11]
	cmp r0, #0xff
	beq _0804DB5A
	cmp r0, #0xfe
	bne _0804DB50
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _0804DB7E
	.align 2, 0
_0804DB4C: .4byte 0xFFFFD000
_0804DB50:
	ldr r0, _0804DB6C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	ble _0804DB70
_0804DB5A:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _0804DB7E
	.align 2, 0
_0804DB6C: .4byte pZero2
_0804DB70:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_0804DB7E:
	movs r0, #0x2f
	bl PlaySound
	b _0804DC2C
_0804DB86:
	adds r1, r7, #0
	adds r1, #0x54
	ldr r2, _0804DBB0 @ =0x0000AB27
	ldrb r3, [r7, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r7, #0
	bl FUN_0809c3b4
	ldr r1, _0804DBB4 @ =0x0000AB26
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0x44
	strb r0, [r7, #0x12]
	b _0804DC2C
	.align 2, 0
_0804DBB0: .4byte 0x0000AB27
_0804DBB4: .4byte 0x0000AB26
_0804DBB8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0804DBCE
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804DC7C
_0804DBCE:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804DC7C
	movs r0, #0x14
	strb r0, [r7, #0xe]
	b _0804DC7C
_0804DBE0:
	movs r0, #0x50
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804DBEA:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804DC7C
	b _0804DC2C
_0804DBF8:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804DC0C
	ldr r1, _0804DC08 @ =0x083634E8
	b _0804DC0E
	.align 2, 0
_0804DC08: .4byte 0x083634E8
_0804DC0C:
	ldr r1, _0804DC34 @ =0x083634F0
_0804DC0E:
	adds r0, r7, #0
	bl CreateBossExplosion
	adds r1, r7, #0
	adds r1, #0xc0
	str r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804DC20:
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0804DC7C
_0804DC2C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0804DC7C
	.align 2, 0
_0804DC34: .4byte 0x083634F0
_0804DC38:
	movs r0, #0x48
	strb r0, [r7, #0x12]
	movs r0, #0x49
	bl ClearBlink
	movs r0, #0x4a
	bl ClearBlink
	movs r0, #0x4b
	bl ClearBlink
	movs r0, #0x4c
	bl ClearBlink
	ldr r2, _0804DC88 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804DC64:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0804DC74
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804DC7C
_0804DC74:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
_0804DC7C:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804DC88: .4byte gStageRun

	thumb_func_start FUN_0804dc8c
FUN_0804dc8c: @ 0x0804DC8C
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804dc90
tretista_0804dc90: @ 0x0804DC90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0804DCC0
	cmp r0, #1
	bgt _0804DCA4
	cmp r0, #0
	beq _0804DCAA
	b _0804DCFA
_0804DCA4:
	cmp r0, #2
	beq _0804DCE0
	b _0804DCFA
_0804DCAA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804DCDC @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804DCC0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804DCFA
	movs r0, #0
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804DCF8
	.align 2, 0
_0804DCDC: .4byte 0x0000AB09
_0804DCE0:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0804DCF2
	adds r0, r4, #0
	bl tretista_0804dd00
	cmp r0, #1
	bne _0804DCFA
	b _0804DCF4
_0804DCF2:
	movs r0, #1
_0804DCF4:
	strb r0, [r4, #0xd]
	movs r0, #7
_0804DCF8:
	strb r0, [r4, #0xe]
_0804DCFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start tretista_0804dd00
tretista_0804dd00: @ 0x0804DD00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0xf
	bls _0804DD12
	b _0804DF60
_0804DD12:
	lsls r0, r0, #2
	ldr r1, _0804DD1C @ =_0804DD20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DD1C: .4byte _0804DD20
_0804DD20: @ jump table
	.4byte _0804DD60 @ case 0
	.4byte _0804DDE2 @ case 1
	.4byte _0804DE10 @ case 2
	.4byte _0804DE38 @ case 3
	.4byte _0804DE74 @ case 4
	.4byte _0804DF1C @ case 5
	.4byte _0804DE84 @ case 6
	.4byte _0804DE92 @ case 7
	.4byte _0804DEA0 @ case 8
	.4byte _0804DF1C @ case 9
	.4byte _0804DEB4 @ case 10
	.4byte _0804DED0 @ case 11
	.4byte _0804DEEC @ case 12
	.4byte _0804DF1C @ case 13
	.4byte _0804DF34 @ case 14
	.4byte _0804DF42 @ case 15
_0804DD60:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	mov r8, r1
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r6, _0804DE04 @ =pZero2
	ldr r0, [r6]
	ldr r0, [r0, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	movs r3, #0
	bl createHellBouncer
	adds r4, r7, #0
	adds r4, #0xc8
	str r0, [r4]
	adds r0, #0xb9
	mov r1, r8
	strb r1, [r0]
	ldr r1, [r4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldr r0, [r5]
	str r0, [r1, #0x64]
	ldr r0, [r7, #0x58]
	ldr r1, _0804DE08 @ =0xFFFF6000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r6]
	ldr r0, [r0, #0x54]
	ldr r1, _0804DE0C @ =0xFFFF8800
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	movs r3, #1
	bl createHellBouncer
	adds r2, r7, #0
	adds r2, #0xcc
	str r0, [r2]
	adds r0, #0xb9
	mov r1, r8
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, [r5]
	str r0, [r1, #0x64]
	ldr r1, [r2]
	ldr r0, [r4]
	str r0, [r1, #0x2c]
	ldr r1, [r4]
	ldr r0, [r2]
	str r0, [r1, #0x2c]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DDE2:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804DDF2
	b _0804DF60
_0804DDF2:
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804DE02
	b _0804DF60
_0804DE02:
	b _0804DF2C
	.align 2, 0
_0804DE04: .4byte pZero2
_0804DE08: .4byte 0xFFFF6000
_0804DE0C: .4byte 0xFFFF8800
_0804DE10:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0804DE68 @ =0x0000AB01
	adds r0, r7, #0
	bl SetMotion
	str r4, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x58]
	ldr r1, _0804DE6C @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DE38:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804DE48
	str r1, [r7, #0x60]
_0804DE48:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, _0804DE70 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bgt _0804DE64
	b _0804DF60
_0804DE64:
	str r0, [r7, #0x58]
	b _0804DF2C
	.align 2, 0
_0804DE68: .4byte 0x0000AB01
_0804DE6C: .4byte 0xFFFFB000
_0804DE70: .4byte pZero2
_0804DE74:
	movs r0, #0xd4
	bl PlaySound
	ldr r1, _0804DE80 @ =0x0000AB02
	b _0804DEA2
	.align 2, 0
_0804DE80: .4byte 0x0000AB02
_0804DE84:
	ldr r1, _0804DE9C @ =0x0000AB03
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DE92:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0804DF2C
	.align 2, 0
_0804DE9C: .4byte 0x0000AB03
_0804DEA0:
	ldr r1, _0804DEB0 @ =0x0000AB04
_0804DEA2:
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	b _0804DF1C
	.align 2, 0
_0804DEB0: .4byte 0x0000AB04
_0804DEB4:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	movs r1, #2
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	strb r1, [r0]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DED0:
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF0E
	movs r0, #0xd7
	bl PlaySound
	ldr r1, _0804DEE8 @ =0x0000AB06
	b _0804DF02
	.align 2, 0
_0804DEE8: .4byte 0x0000AB06
_0804DEEC:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF0E
	movs r0, #0xd7
	bl PlaySound
	ldr r1, _0804DF18 @ =0x0000AB08
_0804DF02:
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DF0E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0804DF60
	.align 2, 0
_0804DF18: .4byte 0x0000AB08
_0804DF1C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF60
_0804DF2C:
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	b _0804DF60
_0804DF34:
	ldr r1, _0804DF5C @ =0x0000AB1F
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DF42:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF60
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	movs r0, #1
	b _0804DF62
	.align 2, 0
_0804DF5C: .4byte 0x0000AB1F
_0804DF60:
	movs r0, #0
_0804DF62:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804df70
FUN_0804df70: @ 0x0804DF70
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804df74
tretista_0804df74: @ 0x0804DF74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bhi _0804E014
	lsls r0, r0, #2
	ldr r1, _0804DF88 @ =_0804DF8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DF88: .4byte _0804DF8C
_0804DF8C: @ jump table
	.4byte _0804DFAC @ case 0
	.4byte _0804DFE0 @ case 1
	.4byte _0804DFB8 @ case 2
	.4byte _0804DFE0 @ case 3
	.4byte _0804DFC0 @ case 4
	.4byte _0804DFD2 @ case 5
	.4byte _0804DFE0 @ case 6
	.4byte _0804DFFC @ case 7
_0804DFAC:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r1, _0804DFB4 @ =0x0000AB21
	b _0804DFD4
	.align 2, 0
_0804DFB4: .4byte 0x0000AB21
_0804DFB8:
	ldr r1, _0804DFBC @ =0x0000AB22
	b _0804DFD4
	.align 2, 0
_0804DFBC: .4byte 0x0000AB22
_0804DFC0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804DFF0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E014
	b _0804DFF0
_0804DFD2:
	ldr r1, _0804DFF8 @ =0x0000AB23
_0804DFD4:
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804DFE0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804E014
_0804DFF0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804E014
	.align 2, 0
_0804DFF8: .4byte 0x0000AB23
_0804DFFC:
	adds r0, r5, #0
	adds r0, #0xc8
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0804E014:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e01c
FUN_0804e01c: @ 0x0804E01C
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804e020
tretista_0804e020: @ 0x0804E020
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804E030
	cmp r5, #1
	beq _0804E048
	b _0804E07E
_0804E030:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804E084 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E048:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0804E064
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804E064
	strb r2, [r4, #0x12]
	movs r0, #0xd4
	bl PlaySound
_0804E064:
	ldr r0, _0804E088 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0804E078
	strb r1, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804E078:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0804E07E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E084: .4byte 0x0000AB09
_0804E088: .4byte gStageRun

	thumb_func_start FUN_0804e08c
FUN_0804e08c: @ 0x0804E08C
	movs r0, #1
	bx lr

	thumb_func_start tretistaNeutral
tretistaNeutral: @ 0x0804E090
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0804E116
	cmp r0, #1
	bgt _0804E0AA
	cmp r0, #0
	beq _0804E0B0
	b _0804E3E4
_0804E0AA:
	cmp r0, #2
	beq _0804E158
	b _0804E3E4
_0804E0B0:
	ldrb r0, [r6, #0xd]
	adds r1, r6, #0
	adds r1, #0xe1
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0804E0D4
	ldr r1, _0804E0D0 @ =0x0000AB09
	adds r0, r6, #0
	bl SetMotion
	b _0804E0DC
	.align 2, 0
_0804E0D0: .4byte 0x0000AB09
_0804E0D4:
	ldr r1, _0804E104 @ =0x0000AB0D
	adds r0, r6, #0
	bl SetMotion
_0804E0DC:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804E108 @ =0x083633C8
	bl SetDDP
	movs r1, #0
	str r1, [r6, #0x60]
	str r1, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r1, [r0, #4]
	str r1, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _0804E10C
	movs r0, #1
	strb r0, [r6, #0x13]
	strb r1, [r6, #0xf]
	b _0804E110
	.align 2, 0
_0804E104: .4byte 0x0000AB0D
_0804E108: .4byte 0x083633C8
_0804E10C:
	movs r0, #0x14
	strb r0, [r6, #0x13]
_0804E110:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804E116:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804E130
	str r1, [r6, #0x68]
_0804E130:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _0804E14A
	ldr r1, _0804E154 @ =0x0000AB09
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804E14A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0804E3E4
	.align 2, 0
_0804E154: .4byte 0x0000AB09
_0804E158:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl FUN_0804ff5c
	ldr r0, [r6, #0x70]
	ldr r1, _0804E234 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _0804E238 @ =0x00080200
	cmp r0, r1
	bne _0804E180
	movs r0, #0xd4
	bl PlaySound
_0804E180:
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804E190
	str r1, [r6, #0x68]
_0804E190:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r4
	ble _0804E19E
	str r4, [r6, #0x58]
_0804E19E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _0804E1AE
	b _0804E3E4
_0804E1AE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0804E1B6
	b _0804E3E4
_0804E1B6:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0804E1C4
	b _0804E3E4
_0804E1C4:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _0804E2AC
	ldr r0, _0804E23C @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804E250
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E240 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E244 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E248 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E24C @ =0x080FEF0A
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r4, r0
	beq _0804E224
	b _0804E31E
_0804E224:
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl tretista_0804fecc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0804E31E
	.align 2, 0
_0804E234: .4byte 0x00FFFF00
_0804E238: .4byte 0x00080200
_0804E23C: .4byte gMission
_0804E240: .4byte RNG_0202f388
_0804E244: .4byte 0x000343FD
_0804E248: .4byte 0x00269EC3
_0804E24C: .4byte 0x080FEF0A
_0804E250:
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E29C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E2A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E2A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E2A8 @ =0x080FEEE8
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r4, r0
	bne _0804E31E
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl tretista_0804fecc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0804E31E
	.align 2, 0
_0804E29C: .4byte RNG_0202f388
_0804E2A0: .4byte 0x000343FD
_0804E2A4: .4byte 0x00269EC3
_0804E2A8: .4byte 0x080FEEE8
_0804E2AC:
	ldr r0, _0804E2D8 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804E2EC
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E2DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E2E0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E2E4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E2E8 @ =0x080FEF0A
	b _0804E30A
	.align 2, 0
_0804E2D8: .4byte gMission
_0804E2DC: .4byte RNG_0202f388
_0804E2E0: .4byte 0x000343FD
_0804E2E4: .4byte 0x00269EC3
_0804E2E8: .4byte 0x080FEF0A
_0804E2EC:
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E344 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E348 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E34C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E350 @ =0x080FEEE8
_0804E30A:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_0804E31E:
	strb r4, [r6, #0xd]
	strb r7, [r6, #0xe]
	subs r0, r4, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804E3B0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	ldr r1, [r6, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0804E358
	ldr r0, _0804E354 @ =0x000077FF
	cmp r2, r0
	ble _0804E360
	b _0804E378
	.align 2, 0
_0804E344: .4byte RNG_0202f388
_0804E348: .4byte 0x000343FD
_0804E34C: .4byte 0x00269EC3
_0804E350: .4byte 0x080FEEE8
_0804E354: .4byte 0x000077FF
_0804E358:
	subs r1, r1, r0
	ldr r0, _0804E370 @ =0x000077FF
	cmp r1, r0
	bgt _0804E378
_0804E360:
	ldr r0, _0804E374 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	bge _0804E3B0
	b _0804E3A8
	.align 2, 0
_0804E370: .4byte 0x000077FF
_0804E374: .4byte pZero2
_0804E378:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	ldr r1, [r6, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0804E394
	ldr r0, _0804E390 @ =0x000077FF
	cmp r2, r0
	ble _0804E39C
	b _0804E3B0
	.align 2, 0
_0804E390: .4byte 0x000077FF
_0804E394:
	subs r1, r1, r0
	ldr r0, _0804E3C4 @ =0x000077FF
	cmp r1, r0
	bgt _0804E3B0
_0804E39C:
	ldr r0, _0804E3C8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _0804E3B0
_0804E3A8:
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_0804E3B0:
	cmp r4, #5
	bne _0804E3D0
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	cmp r3, #0
	bne _0804E3CC
	strb r3, [r6, #0xf]
	b _0804E3D0
	.align 2, 0
_0804E3C4: .4byte 0x000077FF
_0804E3C8: .4byte pZero2
_0804E3CC:
	movs r0, #1
	strb r0, [r6, #0xf]
_0804E3D0:
	adds r0, r6, #0
	adds r0, #0xe2
	movs r1, #0
	strb r1, [r0]
	mov r1, r8
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, r8
	strb r4, [r0]
_0804E3E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804e3f0
FUN_0804e3f0: @ 0x0804E3F0
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804e3f4
tretista_0804e3f4: @ 0x0804E3F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0804E4B4
	cmp r5, #1
	bgt _0804E408
	cmp r5, #0
	beq _0804E416
	b _0804E53C
_0804E408:
	cmp r5, #2
	bne _0804E40E
	b _0804E530
_0804E40E:
	cmp r5, #3
	bne _0804E414
	b _0804E534
_0804E414:
	b _0804E53C
_0804E416:
	ldr r1, _0804E458 @ =0x0000AB0A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E45C @ =0x083633C8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E464
	ldr r1, _0804E460 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	adds r6, r1, #0
	cmp r2, r0
	ble _0804E48E
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r3
	b _0804E48C
	.align 2, 0
_0804E458: .4byte 0x0000AB0A
_0804E45C: .4byte 0x083633C8
_0804E460: .4byte pZero2
_0804E464:
	ldr r1, _0804E49C @ =pZero2
	ldr r0, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	adds r6, r1, #0
	cmp r2, r0
	bge _0804E4A4
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804E48C:
	strb r0, [r4, #0xa]
_0804E48E:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0804E4A4
	ldr r0, _0804E4A0 @ =0xFFFFFEA0
	b _0804E4A8
	.align 2, 0
_0804E49C: .4byte pZero2
_0804E4A0: .4byte 0xFFFFFEA0
_0804E4A4:
	movs r0, #0xb0
	lsls r0, r0, #1
_0804E4A8:
	str r0, [r4, #0x5c]
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E4B4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x70]
	ldr r0, _0804E4F0 @ =0x00FFFF00
	ands r1, r0
	movs r0, #0x81
	lsls r0, r0, #9
	cmp r1, r0
	beq _0804E4CE
	ldr r0, _0804E4F4 @ =0x00010900
	cmp r1, r0
	bne _0804E4D4
_0804E4CE:
	movs r0, #0xde
	bl PlaySound
_0804E4D4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0804E4F8
	movs r1, #0xd8
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804E502
	.align 2, 0
_0804E4F0: .4byte 0x00FFFF00
_0804E4F4: .4byte 0x00010900
_0804E4F8:
	ldr r1, _0804E52C @ =0xFFFF9400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804E502:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E512
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #1
	strb r0, [r4, #0x12]
_0804E512:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804E522
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E53C
_0804E522:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804E53C
	.align 2, 0
_0804E52C: .4byte 0xFFFF9400
_0804E530:
	movs r0, #3
	strb r0, [r4, #0xe]
_0804E534:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804E53C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e544
FUN_0804e544: @ 0x0804E544
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804e548
tretista_0804e548: @ 0x0804E548
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804E558
	cmp r0, #2
	beq _0804E558
	b _0804E6F0
_0804E558:
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804E560
	b _0804E8E0
_0804E560:
	lsls r0, r0, #2
	ldr r1, _0804E56C @ =_0804E570
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E56C: .4byte _0804E570
_0804E570: @ jump table
	.4byte _0804E594 @ case 0
	.4byte _0804E7B2 @ case 1
	.4byte _0804E5D8 @ case 2
	.4byte _0804E62A @ case 3
	.4byte _0804E642 @ case 4
	.4byte _0804E660 @ case 5
	.4byte _0804E672 @ case 6
	.4byte _0804E69C @ case 7
	.4byte _0804E6C8 @ case 8
_0804E594:
	ldr r1, _0804E5C8 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E5CC @ =0x083633C8
	bl SetDDP
	ldr r0, _0804E5D0 @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldrb r0, [r4, #0xf]
	cmp r0, #2
	beq _0804E5D4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804E5BE
	b _0804E778
_0804E5BE:
	ldr r0, [r4, #0x54]
	cmp r5, r0
	bgt _0804E5C6
	b _0804E78A
_0804E5C6:
	b _0804E77E
	.align 2, 0
_0804E5C8: .4byte 0x0000AB0C
_0804E5CC: .4byte 0x083633C8
_0804E5D0: .4byte pZero2
_0804E5D4:
	movs r0, #0
	b _0804E788
_0804E5D8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E5EA
	b _0804E8E0
_0804E5EA:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _0804E620
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804E626
_0804E620:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804E626:
	strb r0, [r4, #0xa]
	b _0804E88C
_0804E62A:
	ldr r1, _0804E658 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E65C @ =0x083633C8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E642:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E654
	b _0804E8E0
_0804E654:
	b _0804E88C
	.align 2, 0
_0804E658: .4byte 0x0000AB0C
_0804E65C: .4byte 0x083633C8
_0804E660:
	ldr r1, _0804E698 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E672:
	ldr r1, [r4, #0x60]
	adds r1, #0x20
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r3, r0, r2
	str r3, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	cmp r2, #0
	bgt _0804E68C
	b _0804E848
_0804E68C:
	movs r2, #0xa0
	lsls r2, r2, #6
	adds r0, r3, r2
	bl PushoutToLeft1
	b _0804E850
	.align 2, 0
_0804E698: .4byte 0x0000AB0D
_0804E69C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E6E4 @ =0x083633C8
	bl SetDDP
	ldr r1, _0804E6E8 @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804E6EC @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xde
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E6C8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	beq _0804E6DA
	b _0804E8E0
_0804E6DA:
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0804E8E0
	.align 2, 0
_0804E6E4: .4byte 0x083633C8
_0804E6E8: .4byte 0x0000AB0F
_0804E6EC: .4byte 0xFFFFF000
_0804E6F0:
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804E6F8
	b _0804E8E0
_0804E6F8:
	lsls r0, r0, #2
	ldr r1, _0804E704 @ =_0804E708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E704: .4byte _0804E708
_0804E708: @ jump table
	.4byte _0804E72C @ case 0
	.4byte _0804E7B2 @ case 1
	.4byte _0804E7C4 @ case 2
	.4byte _0804E62A @ case 3
	.4byte _0804E642 @ case 4
	.4byte _0804E80E @ case 5
	.4byte _0804E820 @ case 6
	.4byte _0804E89C @ case 7
	.4byte _0804E8C8 @ case 8
_0804E72C:
	ldr r1, _0804E750 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E754 @ =0x083633C8
	bl SetDDP
	ldr r0, _0804E758 @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r5, r0
	ble _0804E760
	ldr r0, _0804E75C @ =0xFFFF7900
	adds r5, r5, r0
	b _0804E766
	.align 2, 0
_0804E750: .4byte 0x0000AB0C
_0804E754: .4byte 0x083633C8
_0804E758: .4byte pZero2
_0804E75C: .4byte 0xFFFF7900
_0804E760:
	movs r2, #0x87
	lsls r2, r2, #8
	adds r5, r5, r2
_0804E766:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E778
	ldr r0, [r4, #0x54]
	cmp r5, r0
	ble _0804E78A
	b _0804E77E
_0804E778:
	ldr r0, [r4, #0x54]
	cmp r5, r0
	bge _0804E78A
_0804E77E:
	ldr r1, _0804E7C0 @ =0x0000AB0B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
_0804E788:
	strb r0, [r4, #0x13]
_0804E78A:
	movs r0, #0x38
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r5, r0
	movs r1, #0x38
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xc4
	lsls r0, r0, #8
	movs r1, #0x38
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x37
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E7B2:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	beq _0804E88C
	movs r0, #4
	strb r0, [r4, #0xe]
	b _0804E8E0
	.align 2, 0
_0804E7C0: .4byte 0x0000AB0B
_0804E7C4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E7D6
	b _0804E8E0
_0804E7D6:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	bne _0804E806
	b _0804E620
_0804E806:
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804E626
_0804E80E:
	ldr r1, _0804E844 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E820:
	ldr r1, [r4, #0x60]
	adds r1, #0x20
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r3, r0, r2
	str r3, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	cmp r2, #0
	ble _0804E848
	movs r2, #0xa0
	lsls r2, r2, #6
	adds r0, r3, r2
	bl PushoutToLeft1
	b _0804E850
	.align 2, 0
_0804E844: .4byte 0x0000AB0D
_0804E848:
	ldr r2, _0804E894 @ =0xFFFFD800
	adds r0, r3, r2
	bl PushoutToRight1
_0804E850:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E85C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804E85C:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0804E876
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804E876
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E898 @ =0x08363410
	bl SetDDP
_0804E876:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804E88C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E8E0
_0804E88C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804E8E0
	.align 2, 0
_0804E894: .4byte 0xFFFFD800
_0804E898: .4byte 0x08363410
_0804E89C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E8E8 @ =0x083633C8
	bl SetDDP
	ldr r1, _0804E8EC @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804E8F0 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xde
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E8C8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804E8E0
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
_0804E8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E8E8: .4byte 0x083633C8
_0804E8EC: .4byte 0x0000AB0F
_0804E8F0: .4byte 0xFFFFF000

	thumb_func_start FUN_0804e8f4
FUN_0804e8f4: @ 0x0804E8F4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0804e8f8
FUN_0804e8f8: @ 0x0804E8F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804E904
	b _0804EB26
_0804E904:
	lsls r0, r0, #2
	ldr r1, _0804E910 @ =_0804E914
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E910: .4byte _0804E914
_0804E914: @ jump table
	.4byte _0804E938 @ case 0
	.4byte _0804E9AA @ case 1
	.4byte _0804E9C0 @ case 2
	.4byte _0804EA1A @ case 3
	.4byte _0804EA32 @ case 4
	.4byte _0804EA50 @ case 5
	.4byte _0804EA62 @ case 6
	.4byte _0804EAE4 @ case 7
	.4byte _0804EB10 @ case 8
_0804E938:
	ldr r1, _0804E964 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E968 @ =0x083633C8
	bl SetDDP
	ldr r0, _0804E96C @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E970
	ldr r0, [r4, #0x54]
	cmp r5, r0
	ble _0804E982
	b _0804E976
	.align 2, 0
_0804E964: .4byte 0x0000AB0C
_0804E968: .4byte 0x083633C8
_0804E96C: .4byte pZero2
_0804E970:
	ldr r0, [r4, #0x54]
	cmp r5, r0
	bge _0804E982
_0804E976:
	ldr r1, _0804E9B8 @ =0x0000AB0B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0x13]
_0804E982:
	movs r0, #0x38
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r5, r0
	movs r1, #0x38
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xc4
	lsls r0, r0, #8
	movs r1, #0x38
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x37
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E9AA:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0804E9BC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
	.align 2, 0
_0804E9B8: .4byte 0x0000AB0B
_0804E9BC:
	movs r0, #4
	b _0804EB24
_0804E9C0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E9D2
	b _0804EB26
_0804E9D2:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0804EA0C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804EA12
_0804EA0C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804EA12:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
_0804EA1A:
	ldr r1, _0804EA48 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EA4C @ =0x083633C8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EA32:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804EB26
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
	.align 2, 0
_0804EA48: .4byte 0x0000AB0C
_0804EA4C: .4byte 0x083633C8
_0804EA50:
	ldr r1, _0804EAA4 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EA62:
	ldr r2, [r4, #0x60]
	adds r2, #0x20
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	cmp r2, #0
	ble _0804EA8E
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804EA8E
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EAA8 @ =0x08363410
	bl SetDDP
_0804EA8E:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0804EAAC
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804EAB8
	.align 2, 0
_0804EAA4: .4byte 0x0000AB0D
_0804EAA8: .4byte 0x08363410
_0804EAAC:
	ldr r0, [r4, #0x54]
	ldr r2, _0804EAE0 @ =0xFFFFD800
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804EAB8:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804EAC4
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804EAC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804EADA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804EB26
_0804EADA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
	.align 2, 0
_0804EAE0: .4byte 0xFFFFD800
_0804EAE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EB2C @ =0x083633C8
	bl SetDDP
	ldr r1, _0804EB30 @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804EB34 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xde
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EB10:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804EB26
	movs r0, #0
	strb r1, [r4, #0xd]
_0804EB24:
	strb r0, [r4, #0xe]
_0804EB26:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EB2C: .4byte 0x083633C8
_0804EB30: .4byte 0x0000AB0F
_0804EB34: .4byte 0xFFFFF000

	thumb_func_start FUN_0804eb38
FUN_0804eb38: @ 0x0804EB38
	movs r0, #1
	bx lr

	thumb_func_start tretistaPipeThrow
tretistaPipeThrow: @ 0x0804EB3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x35
	bls _0804EB48
	b _0804F2AA
_0804EB48:
	lsls r0, r0, #2
	ldr r1, _0804EB54 @ =_0804EB58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804EB54: .4byte _0804EB58
_0804EB58: @ jump table
	.4byte _0804EC30 @ case 0
	.4byte _0804EC60 @ case 1
	.4byte _0804EC80 @ case 2
	.4byte _0804EC9C @ case 3
	.4byte _0804ED32 @ case 4
	.4byte _0804ED72 @ case 5
	.4byte _0804F2AA @ case 6
	.4byte _0804F2AA @ case 7
	.4byte _0804F2AA @ case 8
	.4byte _0804F2AA @ case 9
	.4byte _0804EDB6 @ case 10
	.4byte _0804EDEC @ case 11
	.4byte _0804EE08 @ case 12
	.4byte _0804F2AA @ case 13
	.4byte _0804F2AA @ case 14
	.4byte _0804F2AA @ case 15
	.4byte _0804F2AA @ case 16
	.4byte _0804F2AA @ case 17
	.4byte _0804F2AA @ case 18
	.4byte _0804F2AA @ case 19
	.4byte _0804EE5A @ case 20
	.4byte _0804EC60 @ case 21
	.4byte _0804EEE8 @ case 22
	.4byte _0804EF04 @ case 23
	.4byte _0804EF70 @ case 24
	.4byte _0804F0A8 @ case 25
	.4byte _0804F2AA @ case 26
	.4byte _0804F2AA @ case 27
	.4byte _0804F2AA @ case 28
	.4byte _0804F2AA @ case 29
	.4byte _0804EF98 @ case 30
	.4byte _0804EC60 @ case 31
	.4byte _0804F034 @ case 32
	.4byte _0804F04C @ case 33
	.4byte _0804F090 @ case 34
	.4byte _0804F0A8 @ case 35
	.4byte _0804F2AA @ case 36
	.4byte _0804F2AA @ case 37
	.4byte _0804F2AA @ case 38
	.4byte _0804F2AA @ case 39
	.4byte _0804F0CC @ case 40
	.4byte _0804F0F8 @ case 41
	.4byte _0804F12C @ case 42
	.4byte _0804F14E @ case 43
	.4byte _0804F194 @ case 44
	.4byte _0804F1B0 @ case 45
	.4byte _0804F2AA @ case 46
	.4byte _0804F2AA @ case 47
	.4byte _0804F2AA @ case 48
	.4byte _0804F2AA @ case 49
	.4byte _0804F1E0 @ case 50
	.4byte _0804F212 @ case 51
	.4byte _0804F274 @ case 52
	.4byte _0804F286 @ case 53
_0804EC30:
	ldr r1, _0804EC74 @ =0x0000AB11
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EC78 @ =0x083633C8
	bl SetDDP
	movs r1, #0
	movs r0, #0x34
	strb r0, [r4, #0x12]
	str r1, [r4, #0x5c]
	ldr r0, _0804EC7C @ =0x0001A680
	movs r1, #0x34
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x33
_0804EC58:
	strb r0, [r4, #0x12]
_0804EC5A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EC60:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804EC72
	b _0804F2AA
_0804EC72:
	b _0804F268
	.align 2, 0
_0804EC74: .4byte 0x0000AB11
_0804EC78: .4byte 0x083633C8
_0804EC7C: .4byte 0x0001A680
_0804EC80:
	ldr r1, _0804ED00 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804ED04 @ =0x08363410
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EC9C:
	ldr r2, [r4, #0x60]
	adds r2, #0x50
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	cmp r2, #0
	bgt _0804ECB6
	b _0804F252
_0804ECB6:
	ldrb r6, [r4, #0x13]
	cmp r6, #0
	beq _0804ECBE
	b _0804F252
_0804ECBE:
	movs r5, #1
	strb r5, [r4, #0x13]
	ldr r1, _0804ED08 @ =0x0000AB12
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _0804ED0C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804ED10 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804ED14 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r5
	cmp r0, #0
	beq _0804ED18
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	adds r0, r4, #0
	bl tretista_080a36f4
	adds r1, r4, #0
	adds r1, #0xc4
	str r0, [r1]
	strb r6, [r4, #0xf]
	b _0804F252
	.align 2, 0
_0804ED00: .4byte 0x0000AB0D
_0804ED04: .4byte 0x08363410
_0804ED08: .4byte 0x0000AB12
_0804ED0C: .4byte RNG_0202f388
_0804ED10: .4byte 0x000343FD
_0804ED14: .4byte 0x00269EC3
_0804ED18:
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	adds r0, r4, #0
	bl tretista_080a369c
	adds r1, r4, #0
	adds r1, #0xc4
	str r0, [r1]
	strb r5, [r4, #0xf]
	b _0804F252
_0804ED32:
	ldr r1, _0804EDA4 @ =0x0000AB12
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804EDA8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EDAC @ =0x083633C8
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804ED72:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804ED84
	b _0804F2AA
_0804ED84:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804ED96
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804ED96
	b _0804F2AA
_0804ED96:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0804EDB0
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804EDA4: .4byte 0x0000AB12
_0804EDA8: .4byte 0xFFFFF000
_0804EDAC: .4byte 0x083633C8
_0804EDB0:
	movs r0, #0x28
	strb r0, [r4, #0xe]
	b _0804F2AA
_0804EDB6:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #8
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	bl PlaySound
	ldr r1, _0804EE00 @ =0x0000AB13
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EE04 @ =0x083633C8
	bl SetDDP
	movs r1, #0
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EDEC:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0804EDFA
	b _0804F252
_0804EDFA:
	movs r0, #1
	strb r0, [r4, #0x13]
	b _0804F252
	.align 2, 0
_0804EE00: .4byte 0x0000AB13
_0804EE04: .4byte 0x083633C8
_0804EE08:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0804EE18
	movs r0, #1
	strb r0, [r4, #0x13]
_0804EE18:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0804EE22
	movs r1, #0
	b _0804F2A4
_0804EE22:
	ldr r2, _0804EE44 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804EE48 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804EE4C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804EE50
	movs r0, #0x14
	b _0804EE52
	.align 2, 0
_0804EE44: .4byte RNG_0202f388
_0804EE48: .4byte 0x000343FD
_0804EE4C: .4byte 0x00269EC3
_0804EE50:
	movs r0, #0x1e
_0804EE52:
	strb r0, [r4, #0xe]
	movs r0, #0x1e
	strb r0, [r4, #0xe]
	b _0804F2AA
_0804EE5A:
	ldr r1, _0804EE94 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EE98 @ =0x083633C8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804EEA4
	ldr r0, [r4, #0x54]
	ldr r2, _0804EE9C @ =0xFFFF6800
	adds r5, r0, r2
	ldr r1, _0804EEA0 @ =0xFFFF2800
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	bge _0804EEC2
	movs r2, #0x80
	lsls r2, r2, #7
	b _0804EEC0
	.align 2, 0
_0804EE94: .4byte 0x0000AB0C
_0804EE98: .4byte 0x083633C8
_0804EE9C: .4byte 0xFFFF6800
_0804EEA0: .4byte 0xFFFF2800
_0804EEA4:
	ldr r0, [r4, #0x54]
	movs r1, #0x98
	lsls r1, r1, #8
	adds r5, r0, r1
	movs r1, #0xd8
	lsls r1, r1, #8
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	ble _0804EEC2
	ldr r2, _0804EEE4 @ =0xFFFFC000
_0804EEC0:
	adds r5, r1, r2
_0804EEC2:
	movs r0, #0x38
	strb r0, [r4, #0x12]
	subs r0, r5, r3
	movs r1, #0x38
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xf5
	lsls r0, r0, #9
	movs r1, #0x38
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x37
	b _0804EC58
	.align 2, 0
_0804EEE4: .4byte 0xFFFFC000
_0804EEE8:
	ldr r1, _0804EF60 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EF64 @ =0x083633C8
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EF04:
	ldr r2, [r4, #0x60]
	adds r2, #0x50
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	cmp r2, #0
	ble _0804EF30
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804EF30
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EF68 @ =0x08363410
	bl SetDDP
_0804EF30:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0804EF6C @ =0xFFFFD300
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bgt _0804EF44
	b _0804F252
_0804EF44:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bgt _0804EF4C
	b _0804F252
_0804EF4C:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	str r0, [r1]
	b _0804F252
	.align 2, 0
_0804EF60: .4byte 0x0000AB0D
_0804EF64: .4byte 0x083633C8
_0804EF68: .4byte 0x08363410
_0804EF6C: .4byte 0xFFFFD300
_0804EF70:
	ldr r1, _0804EF90 @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xde
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804EF94 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _0804F098
	.align 2, 0
_0804EF90: .4byte 0x0000AB0F
_0804EF94: .4byte 0xFFFFF000
_0804EF98:
	ldr r1, _0804EFD0 @ =0x0000AB14
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EFD4 @ =0x083634A0
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804EFEC
	ldr r0, [r4, #0x54]
	ldr r1, _0804EFD8 @ =0xFFFF2800
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	bge _0804EFDC
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r1, r2
	b _0804EFE0
	.align 2, 0
_0804EFD0: .4byte 0x0000AB14
_0804EFD4: .4byte 0x083634A0
_0804EFD8: .4byte 0xFFFF2800
_0804EFDC:
	ldr r0, _0804EFE4 @ =0xFFFFA800
	adds r1, r3, r0
_0804EFE0:
	ldr r0, _0804EFE8 @ =0xFFFFFD00
	b _0804F016
	.align 2, 0
_0804EFE4: .4byte 0xFFFFA800
_0804EFE8: .4byte 0xFFFFFD00
_0804EFEC:
	ldr r0, [r4, #0x54]
	movs r1, #0xd8
	lsls r1, r1, #8
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	ble _0804F00C
	ldr r2, _0804F008 @ =0xFFFFC000
	adds r1, r1, r2
	b _0804F012
	.align 2, 0
_0804F008: .4byte 0xFFFFC000
_0804F00C:
	movs r0, #0xb0
	lsls r0, r0, #7
	adds r1, r3, r0
_0804F012:
	movs r0, #0xc0
	lsls r0, r0, #2
_0804F016:
	str r0, [r4, #0x5c]
	subs r0, r1, r3
	cmp r0, #0
	bgt _0804F020
	subs r0, r3, r1
_0804F020:
	str r0, [r4, #0x60]
	ldr r1, _0804F030 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r4, #0x68]
	movs r0, #0
	str r0, [r4, #0x64]
	b _0804EC5A
	.align 2, 0
_0804F030: .4byte 0xFFFFE000
_0804F034:
	ldr r1, _0804F088 @ =0x0000AB15
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F08C @ =0x083633C8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F04C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	bge _0804F05A
	rsbs r1, r1, #0
_0804F05A:
	ldr r0, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	ble _0804F076
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	str r0, [r1]
_0804F076:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	ldr r0, [r4, #0x60]
	cmp r1, r0
	bgt _0804F086
	b _0804F2AA
_0804F086:
	b _0804F268
	.align 2, 0
_0804F088: .4byte 0x0000AB15
_0804F08C: .4byte 0x083633C8
_0804F090:
	ldr r1, _0804F0C4 @ =0x0000AB16
	adds r0, r4, #0
	bl SetMotion
_0804F098:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F0C8 @ =0x083633C8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F0A8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	beq _0804F0BA
	b _0804F2AA
_0804F0BA:
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804F0C4: .4byte 0x0000AB16
_0804F0C8: .4byte 0x083633C8
_0804F0CC:
	ldr r1, _0804F120 @ =0x0000AB17
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F124 @ =0x08363458
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F0F8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x70]
	ldr r1, _0804F128 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _0804F112
	movs r0, #0xd8
	bl PlaySound
_0804F112:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F11E
	b _0804F2AA
_0804F11E:
	b _0804F258
	.align 2, 0
_0804F120: .4byte 0x0000AB17
_0804F124: .4byte 0x08363458
_0804F128: .4byte 0x00FFFF00
_0804F12C:
	ldr r1, _0804F18C @ =0x0000AB18
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F190 @ =0x083633C8
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0xb7
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F14E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804F17A
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0804F17A
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #4
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	bl PlaySound
_0804F17A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F268
	b _0804F1C6
	.align 2, 0
_0804F18C: .4byte 0x0000AB18
_0804F190: .4byte 0x083633C8
_0804F194:
	ldr r1, _0804F1D8 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F1DC @ =0x083633C8
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F1B0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804F29C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F29C
_0804F1C6:
	adds r0, r4, #0
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F2AA
	movs r0, #0x32
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804F1D8: .4byte 0x0000AB09
_0804F1DC: .4byte 0x083633C8
_0804F1E0:
	ldr r1, _0804F200 @ =0x0000AB24
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804F204
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	b _0804F20A
	.align 2, 0
_0804F200: .4byte 0x0000AB24
_0804F204:
	ldr r0, [r4, #0x54]
	ldr r1, _0804F238 @ =0xFFFFF000
	adds r0, r0, r1
_0804F20A:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F212:
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804F23C
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804F246
	.align 2, 0
_0804F238: .4byte 0xFFFFF000
_0804F23C:
	ldr r1, _0804F270 @ =0xFFFFD200
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804F246:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804F252
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804F252:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0804F258:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804F268
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F2AA
_0804F268:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804F270: .4byte 0xFFFFD200
_0804F274:
	ldr r1, _0804F2B0 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x32
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F286:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804F29C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F2AA
_0804F29C:
	adds r0, r4, #0
	adds r0, #0xb7
	movs r1, #0
	strb r1, [r0]
_0804F2A4:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804F2AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F2B0: .4byte 0x0000AB09

	thumb_func_start FUN_0804f2b4
FUN_0804f2b4: @ 0x0804F2B4
	movs r0, #1
	bx lr

	thumb_func_start tretistaHellBouncers
tretistaHellBouncers: @ 0x0804F2B8
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xe
	bls _0804F2C6
	b _0804F5A6
_0804F2C6:
	lsls r0, r0, #2
	ldr r1, _0804F2D0 @ =_0804F2D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F2D0: .4byte _0804F2D4
_0804F2D4: @ jump table
	.4byte _0804F310 @ case 0
	.4byte _0804F38C @ case 1
	.4byte _0804F3B8 @ case 2
	.4byte _0804F3D4 @ case 3
	.4byte _0804F3F8 @ case 4
	.4byte _0804F45E @ case 5
	.4byte _0804F480 @ case 6
	.4byte _0804F4A0 @ case 7
	.4byte _0804F4CC @ case 8
	.4byte _0804F4E4 @ case 9
	.4byte _0804F514 @ case 10
	.4byte _0804F54C @ case 11
	.4byte _0804F558 @ case 12
	.4byte _0804F570 @ case 13
	.4byte _0804F588 @ case 14
_0804F310:
	ldr r1, _0804F350 @ =0x0000AB1C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F354 @ =0x083633C8
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r0, [r0]
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	cmp r1, r0
	bge _0804F358
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
	b _0804F382
	.align 2, 0
_0804F350: .4byte 0x0000AB1C
_0804F354: .4byte 0x083633C8
_0804F358:
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r2, _0804F3B4 @ =0xFFFFCE00
	adds r0, r0, r2
	cmp r1, r0
	ble _0804F382
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_0804F382:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F38C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F39E
	b _0804F5A6
_0804F39E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F3A6
	b _0804F568
_0804F3A6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F3B2
	b _0804F5A6
_0804F3B2:
	b _0804F568
	.align 2, 0
_0804F3B4: .4byte 0xFFFFCE00
_0804F3B8:
	ldr r1, _0804F3F0 @ =0x0000AB1D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F3F4 @ =0x08363458
	bl SetDDP
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F3D4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F3E2
	b _0804F568
_0804F3E2:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F3EE
	b _0804F5A6
_0804F3EE:
	b _0804F568
	.align 2, 0
_0804F3F0: .4byte 0x0000AB1D
_0804F3F4: .4byte 0x08363458
_0804F3F8:
	ldr r0, [r5, #0x58]
	ldr r1, _0804F474 @ =0xFFFFD500
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	ldr r2, _0804F478 @ =0xFFFFEF00
	adds r0, r0, r2
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #1
	movs r3, #1
	bl createHellBouncer
	adds r4, r5, #0
	adds r4, #0xc8
	str r0, [r4]
	ldr r0, [r5, #0x54]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #1
	movs r3, #0
	bl createHellBouncer
	adds r2, r5, #0
	adds r2, #0xcc
	str r0, [r2]
	ldr r1, [r4]
	str r1, [r0, #0x2c]
	ldr r1, [r4]
	ldr r0, [r2]
	str r0, [r1, #0x2c]
	movs r0, #0xd6
	bl PlaySound
	ldr r1, _0804F47C @ =0x0000AB1A
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F45E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F466
	b _0804F558
_0804F466:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F472
	b _0804F5A6
_0804F472:
	b _0804F558
	.align 2, 0
_0804F474: .4byte 0xFFFFD500
_0804F478: .4byte 0xFFFFEF00
_0804F47C: .4byte 0x0000AB1A
_0804F480:
	ldr r1, _0804F4C4 @ =0x0000AB03
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F4C8 @ =0x083633C8
	bl SetDDP
	movs r0, #0xff
	strb r0, [r5, #0x12]
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F4A0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F5A6
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F5A6
	b _0804F568
	.align 2, 0
_0804F4C4: .4byte 0x0000AB03
_0804F4C8: .4byte 0x083633C8
_0804F4CC:
	ldr r1, _0804F50C @ =0x0000AB04
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F510 @ =0x08363458
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F4E4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	movs r1, #2
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	strb r1, [r0]
	b _0804F568
	.align 2, 0
_0804F50C: .4byte 0x0000AB04
_0804F510: .4byte 0x08363458
_0804F514:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
	ldr r1, _0804F548 @ =0x0000AB08
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0804F568
	.align 2, 0
_0804F548: .4byte 0x0000AB08
_0804F54C:
	movs r0, #0xd7
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F558:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
_0804F568:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804F5A6
_0804F570:
	ldr r1, _0804F5B8 @ =0x0000AB1F
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F5BC @ =0x083633C8
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F588:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _0804F5A6
	adds r0, #0x55
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	strb r2, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804F5A6:
	ldrb r1, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xe2
	strb r1, [r0]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F5B8: .4byte 0x0000AB1F
_0804F5BC: .4byte 0x083633C8

	thumb_func_start FUN_0804f5c0
FUN_0804f5c0: @ 0x0804F5C0
	movs r0, #1
	bx lr

	thumb_func_start tretistaBreathGas
tretistaBreathGas: @ 0x0804F5C4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0804F5D2
	b _0804F7CE
_0804F5D2:
	lsls r0, r0, #2
	ldr r1, _0804F5DC @ =_0804F5E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F5DC: .4byte _0804F5E0
_0804F5E0: @ jump table
	.4byte _0804F600 @ case 0
	.4byte _0804F626 @ case 1
	.4byte _0804F658 @ case 2
	.4byte _0804F682 @ case 3
	.4byte _0804F744 @ case 4
	.4byte _0804F762 @ case 5
	.4byte _0804F77A @ case 6
	.4byte _0804F7A4 @ case 7
_0804F600:
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x4c
	bl LoadBlink
	ldr r1, _0804F650 @ =0x0000AB1C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F654 @ =0x083633C8
	bl SetDDP
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F626:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F638
	b _0804F7CE
_0804F638:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F640
	b _0804F794
_0804F640:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F64C
	b _0804F7CE
_0804F64C:
	b _0804F794
	.align 2, 0
_0804F650: .4byte 0x0000AB1C
_0804F654: .4byte 0x083633C8
_0804F658:
	ldr r1, _0804F730 @ =0x0000AB1E
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F734 @ =0x08363458
	bl SetDDP
	movs r0, #0xd9
	bl PlaySound
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0x12]
	movs r0, #3
	strb r0, [r5, #0x13]
	strb r1, [r5, #0xf]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F682:
	movs r0, #0x4c
	bl GetBlinkMotionState
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F6E2
	ldrb r0, [r5, #0xf]
	subs r0, #1
	movs r1, #0x50
	bl __modsi3
	cmp r0, #0
	bne _0804F6E2
	ldr r0, [r5, #0x54]
	ldr r1, _0804F738 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0804F73C @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl createTretistaBreathGas
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #1
	bl createTretistaBreathGas
	movs r0, #0xda
	bl PlaySound
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
_0804F6E2:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0804F724
	ldrb r0, [r5, #0xf]
	subs r0, #1
	movs r1, #0x3c
	bl __modsi3
	cmp r0, #0
	bne _0804F724
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r1, _0804F740 @ =0xFFFFD600
	adds r0, r0, r1
	add r4, sp, #8
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #2
	bl createTretistaBreathGas
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #3
	bl createTretistaBreathGas
	movs r0, #0xda
	bl PlaySound
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
_0804F724:
	ldrh r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F7CE
	movs r0, #0x14
	b _0804F792
	.align 2, 0
_0804F730: .4byte 0x0000AB1E
_0804F734: .4byte 0x08363458
_0804F738: .4byte 0xFFFFD000
_0804F73C: .4byte 0xFFFFC000
_0804F740: .4byte 0xFFFFD600
_0804F744:
	movs r0, #0x4c
	bl GetBlinkMotionState
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F794
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F7CE
	b _0804F794
_0804F762:
	ldr r1, _0804F79C @ =0x0000AB1F
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F7A0 @ =0x083633C8
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F77A:
	movs r0, #0x4c
	bl GetBlinkMotionState
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F7CE
	movs r0, #0x32
_0804F792:
	strb r0, [r5, #0x12]
_0804F794:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804F7CE
	.align 2, 0
_0804F79C: .4byte 0x0000AB1F
_0804F7A0: .4byte 0x083633C8
_0804F7A4:
	movs r0, #0x4c
	bl GetBlinkMotionState
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F7C0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F7CE
_0804F7C0:
	movs r0, #0x4c
	bl ClearBlink
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804F7CE:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804f7d8
FUN_0804f7d8: @ 0x0804F7D8
	movs r0, #1
	bx lr

	thumb_func_start tretistaLaserCraw
tretistaLaserCraw: @ 0x0804F7DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x25
	bls _0804F7E8
	b _0804FC5E
_0804F7E8:
	lsls r0, r0, #2
	ldr r1, _0804F7F4 @ =_0804F7F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F7F4: .4byte _0804F7F8
_0804F7F8: @ jump table
	.4byte _0804F890 @ case 0
	.4byte _0804F8C0 @ case 1
	.4byte _0804F8E4 @ case 2
	.4byte _0804F900 @ case 3
	.4byte _0804F96C @ case 4
	.4byte _0804F9AC @ case 5
	.4byte _0804FC5E @ case 6
	.4byte _0804FC5E @ case 7
	.4byte _0804FC5E @ case 8
	.4byte _0804FC5E @ case 9
	.4byte _0804F9E8 @ case 10
	.4byte _0804FA1A @ case 11
	.4byte _0804FA40 @ case 12
	.4byte _0804FC5E @ case 13
	.4byte _0804FC5E @ case 14
	.4byte _0804FC5E @ case 15
	.4byte _0804FC5E @ case 16
	.4byte _0804FC5E @ case 17
	.4byte _0804FC5E @ case 18
	.4byte _0804FC5E @ case 19
	.4byte _0804FC5E @ case 20
	.4byte _0804FC5E @ case 21
	.4byte _0804FC5E @ case 22
	.4byte _0804FC5E @ case 23
	.4byte _0804FC5E @ case 24
	.4byte _0804FC5E @ case 25
	.4byte _0804FC5E @ case 26
	.4byte _0804FC5E @ case 27
	.4byte _0804FC5E @ case 28
	.4byte _0804FC5E @ case 29
	.4byte _0804FA44 @ case 30
	.4byte _0804FA60 @ case 31
	.4byte _0804FA94 @ case 32
	.4byte _0804FAC8 @ case 33
	.4byte _0804FB16 @ case 34
	.4byte _0804FB6A @ case 35
	.4byte _0804FBF4 @ case 36
	.4byte _0804FC2C @ case 37
_0804F890:
	ldr r1, _0804F8D8 @ =0x0000AB11
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F8DC @ =0x083633C8
	bl SetDDP
	movs r1, #0
	movs r0, #0x34
	strb r0, [r5, #0x12]
	str r1, [r5, #0x5c]
	ldr r0, _0804F8E0 @ =0x0001A680
	movs r1, #0x34
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x33
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F8C0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F8D2
	b _0804FC5E
_0804F8D2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804F8D8: .4byte 0x0000AB11
_0804F8DC: .4byte 0x083633C8
_0804F8E0: .4byte 0x0001A680
_0804F8E4:
	ldr r1, _0804F960 @ =0x0000AB0D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F964 @ =0x08363410
	bl SetDDP
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F900:
	ldr r2, [r5, #0x60]
	adds r2, #0x50
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r5, #0x58]
	cmp r2, #0
	ble _0804F942
	ldrb r6, [r5, #0x13]
	cmp r6, #0
	bne _0804F942
	movs r4, #1
	strb r4, [r5, #0x13]
	ldr r1, _0804F968 @ =0x0000AB12
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	ands r2, r4
	adds r0, r5, #0
	bl tretista_080a36f4
	adds r1, r5, #0
	adds r1, #0xc4
	str r0, [r1]
	strb r6, [r5, #0xf]
_0804F942:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F95A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F95A
	b _0804FC5E
_0804F95A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804F960: .4byte 0x0000AB0D
_0804F964: .4byte 0x08363410
_0804F968: .4byte 0x0000AB12
_0804F96C:
	ldr r1, _0804F9DC @ =0x0000AB12
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0804F9E0 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F9E4 @ =0x083633C8
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	bl PlaySound
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F9AC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F9BE
	b _0804FC5E
_0804F9BE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F9D0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F9D0
	b _0804FC5E
_0804F9D0:
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	beq _0804F9D8
	b _0804FC5E
_0804F9D8:
	movs r0, #0xa
	b _0804FC5C
	.align 2, 0
_0804F9DC: .4byte 0x0000AB12
_0804F9E0: .4byte 0xFFFFF000
_0804F9E4: .4byte 0x083633C8
_0804F9E8:
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #8
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	bl PlaySound
	ldr r1, _0804FA38 @ =0x0000AB13
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FA3C @ =0x083633C8
	bl SetDDP
	movs r0, #0x5a
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FA1A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804FA32
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804FA32
	b _0804FC5E
_0804FA32:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804FA38: .4byte 0x0000AB13
_0804FA3C: .4byte 0x083633C8
_0804FA40:
	movs r0, #0x1e
	b _0804FC5C
_0804FA44:
	ldr r1, _0804FA8C @ =0x0000AB20
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FA90 @ =0x083633C8
	bl SetDDP
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FA60:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804FA72
	b _0804FC5E
_0804FA72:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804FA84
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804FA84
	b _0804FC5E
_0804FA84:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804FA8C: .4byte 0x0000AB20
_0804FA90: .4byte 0x083633C8
_0804FA94:
	adds r1, r5, #0
	adds r1, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl FUN_080a374c
	adds r1, r5, #0
	adds r1, #0xc0
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x49
	bl LoadBlink
	movs r0, #0xdb
	bl PlaySound
	movs r0, #0
	strb r0, [r5, #0x12]
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FAC8:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0804FAE8
	ldrb r0, [r5, #0x12]
	cmp r0, #0x14
	bls _0804FAE8
	movs r0, #1
	strb r0, [r5, #0x13]
	movs r0, #0x49
	bl ClearBlink
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x4a
	bl LoadBlink
_0804FAE8:
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bne _0804FAF6
	movs r0, #0x4a
	bl GetBlinkMotionState
	b _0804FAFC
_0804FAF6:
	movs r0, #0x49
	bl GetBlinkMotionState
_0804FAFC:
	ldrb r0, [r5, #0x12]
	cmp r0, #0x1e
	bhi _0804FB10
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bhi _0804FB10
	b _0804FC5E
_0804FB10:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
_0804FB16:
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0804FB48 @ =0x0000AB22
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FB4C @ =0x083633C8
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FB54
	ldr r0, _0804FB50 @ =0xFFFFFD00
	b _0804FB58
	.align 2, 0
_0804FB48: .4byte 0x0000AB22
_0804FB4C: .4byte 0x083633C8
_0804FB50: .4byte 0xFFFFFD00
_0804FB54:
	movs r0, #0xc0
	lsls r0, r0, #2
_0804FB58:
	str r0, [r5, #0x5c]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r5, #0x60]
	movs r0, #0
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FB6A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	bge _0804FB78
	rsbs r1, r1, #0
_0804FB78:
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	movs r0, #0x4a
	bl GetBlinkMotionState
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _0804FB9A
	ldr r0, [r5, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	b _0804FBA6
_0804FB9A:
	ldr r0, [r5, #0x54]
	ldr r2, _0804FBF0 @ =0xFFFFD200
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
_0804FBA6:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FBB2
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0804FBB2:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	asrs r0, r0, #1
	ldr r1, [r5, #0x64]
	cmp r1, r0
	ble _0804FBDA
	adds r3, r5, #0
	adds r3, #0xc4
	ldr r2, [r3]
	cmp r2, #0
	beq _0804FBDA
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	str r0, [r3]
_0804FBDA:
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x60]
	cmp r1, r0
	ble _0804FC5E
	movs r0, #0x4a
	bl ClearBlink
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804FBF0: .4byte 0xFFFFD200
_0804FBF4:
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x4b
	bl LoadBlink
	ldr r1, _0804FC64 @ =0x0000AB23
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FC68 @ =0x083633C8
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FC2C:
	movs r0, #0x4b
	bl GetBlinkMotionState
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r4, [r0]
	cmp r4, #3
	bne _0804FC5E
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804FC52
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804FC5E
_0804FC52:
	movs r0, #0x4b
	bl ClearBlink
	movs r0, #0
	strb r4, [r5, #0xd]
_0804FC5C:
	strb r0, [r5, #0xe]
_0804FC5E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804FC64: .4byte 0x0000AB23
_0804FC68: .4byte 0x083633C8

	thumb_func_start FUN_0804fc6c
FUN_0804fc6c: @ 0x0804FC6C
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804fc70
tretista_0804fc70: @ 0x0804FC70
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804FC80
	cmp r5, #1
	beq _0804FD1C
	b _0804FDF0
_0804FC80:
	movs r0, #0xdc
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xe1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0804FC98
	ldr r1, _0804FCC4 @ =0x0000AB24
	adds r0, r4, #0
	bl SetMotion
_0804FC98:
	ldr r0, _0804FCC8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0804FCD0
	ldr r0, _0804FCCC @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804FCF2
	.align 2, 0
_0804FCC4: .4byte 0x0000AB24
_0804FCC8: .4byte pZero2
_0804FCCC: .4byte 0xFFFFFE00
_0804FCD0:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0804FCF2:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x49
	bl ClearBlink
	movs r0, #0x4a
	bl ClearBlink
	movs r0, #0x4b
	bl ClearBlink
	movs r0, #0x4c
	bl ClearBlink
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804FD1C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804FD3E
	str r1, [r4, #0x60]
_0804FD3E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0804FD6C
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r3, _0804FDD0 @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FD6C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804FD6C:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804FD8E
	ldr r0, [r4, #0x54]
	ldr r1, _0804FDD4 @ =0xFFFFD200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _0804FDD0 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FD8E
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804FD8E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FDA2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804FDA2:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804FDB2
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804FDF0
_0804FDB2:
	adds r0, r4, #0
	adds r0, #0xe1
	ldrb r1, [r0]
	cmp r1, #7
	bne _0804FDE4
	adds r0, #1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804FDE4
	cmp r0, #7
	bhi _0804FDD8
	strb r1, [r4, #0xd]
	movs r0, #6
	strb r0, [r4, #0xe]
	b _0804FDF0
	.align 2, 0
_0804FDD0: .4byte 0xFFFFF800
_0804FDD4: .4byte 0xFFFFD200
_0804FDD8:
	cmp r0, #9
	bhi _0804FDE4
	strb r1, [r4, #0xd]
	movs r0, #8
	strb r0, [r4, #0xe]
	b _0804FDF0
_0804FDE4:
	movs r0, #0
	movs r1, #3
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	movs r0, #0xff
	strb r0, [r4, #0xf]
_0804FDF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804fdf8
FUN_0804fdf8:
	.byte 0x10, 0xB5, 0x03, 0x1C, 0xD8, 0x68, 0x42, 0x68
	.byte 0x10, 0x79, 0x03, 0x28, 0x03, 0xD0, 0x0E, 0x28, 0x01, 0xD0, 0x0F, 0x28, 0x20, 0xD1, 0xDA, 0x6A
	.byte 0xD8, 0x68, 0xC4, 0x6A, 0x10, 0x1C, 0x8C, 0x30, 0x00, 0x68, 0x80, 0x21, 0x89, 0x00, 0x08, 0x40
	.byte 0x00, 0x28, 0x05, 0xD1, 0x10, 0x1C, 0xA4, 0x30, 0x00, 0x21, 0x40, 0x5E, 0x00, 0x28, 0x0F, 0xD1
	.byte 0x05, 0x48, 0x01, 0x89, 0x08, 0x20, 0x08, 0x40, 0x00, 0x28, 0x09, 0xD1, 0xE0, 0x6D, 0x00, 0x28
	.byte 0x04, 0xDA, 0xFF, 0x20, 0x03, 0xE0, 0x00, 0x00, 0x60, 0xFE, 0x02, 0x02, 0xFE, 0x20, 0x50, 0x74
	.byte 0xDA, 0x6A, 0xD8, 0x68, 0x40, 0x68, 0x40, 0x78, 0x02, 0x28, 0x0C, 0xD1, 0x59, 0x68, 0x08, 0x78
	.byte 0x02, 0x28, 0x08, 0xD0, 0xC9, 0x68, 0x01, 0x20, 0x40, 0x42, 0x81, 0x42, 0x03, 0xD0, 0x11, 0x1C
	.byte 0xB7, 0x31, 0x01, 0x20, 0x08, 0x70, 0xD8, 0x68, 0x42, 0x68, 0x59, 0x68, 0x08, 0x78, 0x02, 0x28
	.byte 0x1F, 0xD0, 0xC9, 0x68, 0x01, 0x20, 0x40, 0x42, 0x81, 0x42, 0x1A, 0xD0, 0x50, 0x68, 0x0E, 0x49
	.byte 0x08, 0x40, 0xFD, 0x39, 0x88, 0x42, 0x14, 0xD1, 0xDA, 0x6A, 0x53, 0x7B, 0x18, 0x1C, 0x0A, 0x28
	.byte 0x0F, 0xD0, 0x06, 0x28, 0x0D, 0xD0, 0x09, 0x28, 0x0B, 0xD0, 0x07, 0x28, 0x02, 0xD1, 0x90, 0x7B
	.byte 0x09, 0x28, 0x06, 0xD8, 0x10, 0x1C, 0xE1, 0x30, 0x00, 0x21, 0x03, 0x70, 0x0A, 0x20, 0x50, 0x73
	.byte 0x91, 0x73, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xFF, 0x00, 0x02, 0x00

	thumb_func_start tretista_0804fecc
tretista_0804fecc: @ 0x0804FECC
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _0804FF06
	movs r2, #0
	ldr r5, _0804FEEC @ =u16_ARRAY_080fef2c
	adds r3, r5, #0
_0804FEDA:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804FEF0
	adds r3, #2
	adds r2, #1
	cmp r2, #5
	ble _0804FEDA
	b _0804FF1A
	.align 2, 0
_0804FEEC: .4byte u16_ARRAY_080fef2c
_0804FEF0:
	adds r0, r2, #1
	movs r1, #6
	b _0804FEFA
_0804FEF6:
	adds r0, r2, #1
	movs r1, #5
_0804FEFA:
	bl __modsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0804FF1A
_0804FF06:
	movs r2, #0
	ldr r5, _0804FF20 @ =u16_ARRAY_080fef2c
	adds r3, r5, #0
_0804FF0C:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804FEF6
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0804FF0C
_0804FF1A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804FF20: .4byte u16_ARRAY_080fef2c

	thumb_func_start isTretistaFarAway
isTretistaFarAway: @ 0x0804FF24
	push {lr}
	ldr r1, _0804FF3C @ =pZero2
	ldr r1, [r1]
	ldr r3, [r1, #0x54]
	ldr r1, [r0, #0x54]
	subs r2, r3, r1
	cmp r2, #0
	ble _0804FF44
	ldr r0, _0804FF40 @ =0x000086FF
	cmp r2, r0
	ble _0804FF4C
	b _0804FF54
	.align 2, 0
_0804FF3C: .4byte pZero2
_0804FF40: .4byte 0x000086FF
_0804FF44:
	subs r1, r1, r3
	ldr r0, _0804FF50 @ =0x000086FF
	cmp r1, r0
	bgt _0804FF54
_0804FF4C:
	movs r0, #0
	b _0804FF56
	.align 2, 0
_0804FF50: .4byte 0x000086FF
_0804FF54:
	movs r0, #1
_0804FF56:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ff5c
FUN_0804ff5c: @ 0x0804FF5C
	push {r4, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r4, _0804FFA0 @ =0x0000AB0B
	cmp r1, r4
	bne _0804FFAC
	ldr r0, [r2, #0x70]
	ldr r1, _0804FFA4 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _0804FFA8 @ =0x00010300
	cmp r0, r1
	bne _08050008
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FFEC
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08050006
	.align 2, 0
_0804FFA0: .4byte 0x0000AB0B
_0804FFA4: .4byte 0x00FFFF00
_0804FFA8: .4byte 0x00010300
_0804FFAC:
	ldr r3, _0804FFE4 @ =0x0000AB05
	cmp r1, r3
	bne _08050034
	ldr r0, [r2, #0x70]
	ldr r1, _0804FFE8 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _08050008
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FFEC
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08050006
	.align 2, 0
_0804FFE4: .4byte 0x0000AB05
_0804FFE8: .4byte 0x00FFFF00
_0804FFEC:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_08050006:
	strb r0, [r2, #0xa]
_08050008:
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050024
	ldr r1, _08050020 @ =0x0000AB09
	b _08050026
	.align 2, 0
_08050020: .4byte 0x0000AB09
_08050024:
	ldr r1, _08050030 @ =0x0000AB03
_08050026:
	adds r0, r2, #0
	bl SetMotion
	b _0805008A
	.align 2, 0
_08050030: .4byte 0x0000AB03
_08050034:
	ldr r0, _08050060 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08050064
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08050078
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _0805008A
	.align 2, 0
_08050060: .4byte pZero2
_08050064:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050082
_08050078:
	adds r0, r2, #0
	adds r1, r4, #0
	bl SetMotion
	b _0805008A
_08050082:
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_0805008A:
	pop {r4}
	pop {r0}
	bx r0
