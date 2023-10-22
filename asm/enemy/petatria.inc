	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreatePetatria
CreatePetatria: @ 0x0808FE74
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0808FECC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808FEC2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808FED0 @ =gEnemyFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_0808FEC2:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808FECC: .4byte gZakoHeaderPtr
_0808FED0: .4byte gEnemyFnTable

	thumb_func_start Petatria_Init
Petatria_Init: @ 0x0808FED4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0808FF14 @ =nop_0809127c
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x4c
	str r2, [r0]
	subs r0, #7
	strb r2, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0808FF50
	ldr r0, _0808FF18 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r6, #0x54]
	cmp r2, r0
	ble _0808FF1C
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _0808FF1E
	.align 2, 0
_0808FF14: .4byte nop_0809127c
_0808FF18: .4byte pZero2
_0808FF1C:
	movs r0, #0xcc
_0808FF1E:
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x58]
	adds r0, r2, #0
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0808FF4C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	b _0808FFE6
	.align 2, 0
_0808FF4C: .4byte gEnemyFnTable
_0808FF50:
	cmp r0, #0
	bne _0808FF74
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, _0808FF6C @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	ldr r1, _0808FF70 @ =0xFFFFE000
	b _0808FFAE
	.align 2, 0
_0808FF6C: .4byte 0xFFFFF600
_0808FF70: .4byte 0xFFFFE000
_0808FF74:
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	movs r1, #0x80
	lsls r1, r1, #6
_0808FFAE:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _0808FFC4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _0808FFC8
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _0808FFCA
	.align 2, 0
_0808FFC4: .4byte pZero2
_0808FFC8:
	movs r0, #0xcc
_0808FFCA:
	str r0, [r6, #0x60]
	ldr r1, _0809000C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
_0808FFE6:
	adds r0, r6, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	beq _08090060
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _08090014
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090010 @ =0x08369608
	b _08090024
	.align 2, 0
_0809000C: .4byte gEnemyFnTable
_08090010: .4byte 0x08369608
_08090014:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090048 @ =0x08369638
_08090024:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0809004C
	movs r1, #0xfc
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	b _08090054
	.align 2, 0
_08090048: .4byte 0x08369638
_0809004C:
	ldr r1, _0809005C @ =0x00007E06
	adds r0, r6, #0
	bl SetMotion
_08090054:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0809009A
	.align 2, 0
_0809005C: .4byte 0x00007E06
_08090060:
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0809007C
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090078 @ =0x08369608
	b _0809008A
	.align 2, 0
_08090078: .4byte 0x08369608
_0809007C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080900A8 @ =0x08369638
_0809008A:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_0809009A:
	adds r0, r6, #0
	bl Petatria_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080900A8: .4byte 0x08369638

	thumb_func_start Petatria_Update
Petatria_Update: @ 0x080900AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080900DC
	ldr r1, _080900D8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Petatria_Die
	b _08090122
	.align 2, 0
_080900D8: .4byte gEnemyFnTable
_080900DC:
	ldr r0, _08090128 @ =0x083695B8
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08091188
	adds r0, r4, #0
	bl isFrozen
	adds r6, r0, #0
	cmp r6, #0
	bne _08090122
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	beq _08090112
	bl isKilled
	cmp r0, #0
	beq _08090122
	str r6, [r5]
_08090112:
	ldr r0, _0809012C @ =0x083695E0
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08090122:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090128: .4byte 0x083695B8
_0809012C: .4byte 0x083695E0

	thumb_func_start Petatria_Die
Petatria_Die: @ 0x08090130
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0809017C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08090184
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08090180 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08090270
	.align 2, 0
_0809017C: .4byte gCurStory
_08090180: .4byte gEnemyFnTable
_08090184:
	ldrb r2, [r7, #0xe]
	cmp r2, #1
	beq _080901BC
	cmp r2, #1
	bgt _08090194
	cmp r2, #0
	beq _0809019E
	b _08090272
_08090194:
	cmp r2, #0xa
	beq _080901BC
	cmp r2, #0xb
	beq _080901C4
	b _08090272
_0809019E:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	str r2, [r7, #0x60]
	str r2, [r7, #0x5c]
_080901BC:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08090272
_080901C4:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #4
	mov r1, r8
	bl TryDropItem
	ldr r2, _08090280 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090284 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _08090288 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r1, _0809028C @ =0xFFFFF400
	adds r0, r0, r1
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08090290 @ =0x00007E1A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08090294 @ =0x00007E1B
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08090298 @ =0x00007E1C
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldr r2, _0809029C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080902A0 @ =0x0000270E
	cmp r1, r0
	bhi _08090250
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08090250:
	adds r0, r7, #0
	mov r1, r8
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080902A4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08090270:
	str r0, [r7, #0x14]
_08090272:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090280: .4byte RNG_0202f388
_08090284: .4byte 0x000343FD
_08090288: .4byte 0x00269EC3
_0809028C: .4byte 0xFFFFF400
_08090290: .4byte 0x00007E1A
_08090294: .4byte 0x00007E1B
_08090298: .4byte 0x00007E1C
_0809029C: .4byte gMission
_080902A0: .4byte 0x0000270E
_080902A4: .4byte gEnemyFnTable

	thumb_func_start FUN_080902a8
FUN_080902a8: @ 0x080902A8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080902C0
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080902C0:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080902c8
FUN_080902c8: @ 0x080902C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x17
	bls _080902D4
	b _080906E0
_080902D4:
	lsls r0, r0, #2
	ldr r1, _080902E0 @ =_080902E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080902E0: .4byte _080902E4
_080902E4: @ jump table
	.4byte _08090344 @ case 0
	.4byte _0809039A @ case 1
	.4byte _080903AE @ case 2
	.4byte _08090490 @ case 3
	.4byte _080904D8 @ case 4
	.4byte _0809051C @ case 5
	.4byte _080906E0 @ case 6
	.4byte _080906E0 @ case 7
	.4byte _080906E0 @ case 8
	.4byte _080906E0 @ case 9
	.4byte _080906E0 @ case 10
	.4byte _080906E0 @ case 11
	.4byte _080906E0 @ case 12
	.4byte _080906E0 @ case 13
	.4byte _080906E0 @ case 14
	.4byte _080906E0 @ case 15
	.4byte _080906E0 @ case 16
	.4byte _080906E0 @ case 17
	.4byte _080906E0 @ case 18
	.4byte _080906E0 @ case 19
	.4byte _08090548 @ case 20
	.4byte _0809062C @ case 21
	.4byte _0809068C @ case 22
	.4byte _080906BC @ case 23
_08090344:
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080903A4 @ =0x08369608
	bl SetDDP
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	movs r1, #0xfc
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809039A:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080903A8
	movs r0, #2
	b _080903AA
	.align 2, 0
_080903A4: .4byte 0x08369608
_080903A8:
	movs r0, #0x14
_080903AA:
	strb r0, [r5, #0xe]
	b _08090680
_080903AE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0xb9
	cmp r0, #3
	bne _080903F4
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080903D4
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5, #0x13]
_080903D4:
	ldr r1, _08090478 @ =0x0836978C
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x64]
	ldr r1, _0809047C @ =0x08369768
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_080903F4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	ldrb r0, [r4]
	cmp r0, #3
	bls _08090432
	movs r6, #0
	strb r6, [r4]
	ldr r3, _08090480 @ =0x08369728
	ldr r2, _08090484 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090488 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809048C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08090432
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
_08090432:
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _0809043A
	b _080906E0
_0809043A:
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809045A
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809045A:
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r1, r0
	bne _08090472
	b _080906E0
_08090472:
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _08090604
	.align 2, 0
_08090478: .4byte 0x0836978C
_0809047C: .4byte 0x08369768
_08090480: .4byte 0x08369728
_08090484: .4byte RNG_0202f388
_08090488: .4byte 0x000343FD
_0809048C: .4byte 0x00269EC3
_08090490:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r2, _080904D0 @ =0xFFFF8200
	adds r0, r1, r2
	cmp r0, #1
	bhi _080904A6
	b _08090646
_080904A6:
	ldr r0, _080904D4 @ =0x00007E05
	cmp r1, r0
	bne _080904AE
	b _08090646
_080904AE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080904BA
	b _08090680
_080904BA:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi _080904CA
	b _08090670
_080904CA:
	movs r0, #0
	b _0809066E
	.align 2, 0
_080904D0: .4byte 0xFFFF8200
_080904D4: .4byte 0x00007E05
_080904D8:
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _08090544 @ =0x00007E0C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809051C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0809052E
	b _080906E0
_0809052E:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xcc
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	strb r1, [r5, #0xd]
	strb r2, [r5, #0xe]
	b _080906E0
	.align 2, 0
_08090544: .4byte 0x00007E0C
_08090548:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0xb9
	cmp r0, #3
	bne _0809058A
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08090560
	subs r0, #1
	b _08090568
_08090560:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #5
_08090568:
	strb r0, [r5, #0x13]
	ldr r1, _0809060C @ =0x08369774
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x64]
	ldr r1, _08090610 @ =0x08369768
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_0809058A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	ldrb r0, [r4]
	cmp r0, #3
	bls _080905C8
	movs r6, #0
	strb r6, [r4]
	ldr r3, _08090614 @ =0x08369728
	ldr r2, _08090618 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809061C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08090620 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080905C8
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
_080905C8:
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _080905D0
	b _080906E0
_080905D0:
	ldr r0, [r5, #0x54]
	ldr r2, _08090624 @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _080905EE
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080905EE:
	ldr r0, [r5, #0x54]
	ldr r1, _08090628 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r1, r0
	beq _080906E0
	movs r0, #0xcc
_08090604:
	str r0, [r5, #0x5c]
	movs r0, #1
	strb r0, [r5, #0xe]
	b _080906E0
	.align 2, 0
_0809060C: .4byte 0x08369774
_08090610: .4byte 0x08369768
_08090614: .4byte 0x08369728
_08090618: .4byte RNG_0202f388
_0809061C: .4byte 0x000343FD
_08090620: .4byte 0x00269EC3
_08090624: .4byte 0xFFFFE000
_08090628: .4byte 0xFFFFF000
_0809062C:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r2, _08090650 @ =0xFFFF8200
	adds r0, r1, r2
	cmp r0, #1
	bls _08090646
	ldr r0, _08090654 @ =0x00007E05
	cmp r1, r0
	bne _08090658
_08090646:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080906E0
	.align 2, 0
_08090650: .4byte 0xFFFF8200
_08090654: .4byte 0x00007E05
_08090658:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090680
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0809066C
	subs r0, #1
	b _0809066E
_0809066C:
	movs r0, #5
_0809066E:
	strb r0, [r5, #0x13]
_08090670:
	ldr r0, _08090688 @ =0x08369768
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
_08090680:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080906E0
	.align 2, 0
_08090688: .4byte 0x08369768
_0809068C:
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
	ldr r1, _080906E8 @ =0x00007E0C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080906BC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080906E0
	adds r0, r5, #0
	adds r0, #0xb8
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcc
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080906E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080906E8: .4byte 0x00007E0C

	thumb_func_start FUN_080906ec
FUN_080906ec: @ 0x080906EC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08090704
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08090704:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809070c
FUN_0809070c:
	.byte 0x70, 0xB5, 0x04, 0x1C
	.byte 0xA0, 0x7B, 0x17, 0x28, 0x00, 0xD9, 0x00, 0xE2, 0x80, 0x00, 0x02, 0x49, 0x40, 0x18, 0x00, 0x68
	.byte 0x87, 0x46, 0x00, 0x00, 0x28, 0x07, 0x09, 0x08, 0x88, 0x07, 0x09, 0x08, 0xA8, 0x07, 0x09, 0x08
	.byte 0xC6, 0x07, 0x09, 0x08, 0xCC, 0x08, 0x09, 0x08, 0x22, 0x09, 0x09, 0x08, 0x30, 0x09, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x58, 0x09, 0x09, 0x08, 0x74, 0x0A, 0x09, 0x08
	.byte 0xDC, 0x0A, 0x09, 0x08, 0xEA, 0x0A, 0x09, 0x08, 0x20, 0x1C, 0x74, 0x30, 0x09, 0x49, 0x76, 0xF7
	.byte 0x41, 0xFD, 0x00, 0x20, 0xE0, 0x74, 0xA0, 0x6D, 0xA0, 0x66, 0x07, 0x49, 0x20, 0x1C, 0x86, 0xF7
	.byte 0xE3, 0xFE, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x6E, 0x00, 0x28, 0x06, 0xDD, 0x02, 0x20
	.byte 0x05, 0xE0, 0x00, 0x00, 0x38, 0x96, 0x36, 0x08, 0x06, 0x7E, 0x00, 0x00, 0x14, 0x20, 0xA0, 0x73
	.byte 0x20, 0x1C, 0x86, 0xF7, 0x4B, 0xFF, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x25, 0x1C, 0xB9, 0x35
	.byte 0x03, 0x28, 0x19, 0xD1, 0xE0, 0x7C, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x38, 0x03, 0xE0, 0x28, 0x78
	.byte 0x01, 0x30, 0x28, 0x70, 0x05, 0x20, 0xE0, 0x74, 0x29, 0x49, 0xE0, 0x7C, 0x80, 0x00, 0x40, 0x18
	.byte 0xA1, 0x6E, 0x00, 0x68, 0x09, 0x1A, 0xA1, 0x66, 0x26, 0x49, 0xE0, 0x7C, 0x40, 0x00, 0x40, 0x18
	.byte 0x01, 0x88, 0x20, 0x1C, 0x86, 0xF7, 0xB0, 0xFE, 0x20, 0x1C, 0x86, 0xF7, 0x27, 0xFF, 0xA0, 0x6E
	.byte 0xA0, 0x65, 0x28, 0x78, 0x03, 0x28, 0x16, 0xD9, 0x00, 0x26, 0x2E, 0x70, 0x1E, 0x4B, 0x1F, 0x4A
	.byte 0x11, 0x68, 0x1F, 0x48, 0x48, 0x43, 0x1F, 0x49, 0x40, 0x18, 0x40, 0x00, 0x41, 0x08, 0x11, 0x60
	.byte 0x40, 0x0C, 0x0F, 0x21, 0x08, 0x40, 0x80, 0x00, 0xC0, 0x18, 0x00, 0x68, 0x00, 0x28, 0x02, 0xD0
	.byte 0x03, 0x20, 0x60, 0x73, 0xA6, 0x73, 0x60, 0x7B, 0x03, 0x28, 0x00, 0xD1, 0x65, 0xE1, 0x60, 0x6D
	.byte 0xA1, 0x6D, 0x79, 0xF7, 0x9D, 0xF8, 0x01, 0x1C, 0x00, 0x29, 0x05, 0xD0, 0xA0, 0x6D, 0x40, 0x18
	.byte 0xA0, 0x65, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0xB8, 0x30, 0x05, 0x78, 0x01, 0x2D
	.byte 0x1A, 0xD1, 0x60, 0x6D, 0xA1, 0x6D, 0x79, 0xF7, 0xD9, 0xFC, 0x01, 0x1C, 0x60, 0x6D, 0x80, 0x22
	.byte 0x92, 0x01, 0x80, 0x18, 0x81, 0x42, 0x00, 0xD1, 0x47, 0xE1, 0xCC, 0x20, 0x40, 0x42, 0xCA, 0xE0
	.byte 0xB0, 0x97, 0x36, 0x08, 0xA4, 0x97, 0x36, 0x08, 0x28, 0x97, 0x36, 0x08, 0x88, 0xF3, 0x02, 0x02
	.byte 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00, 0x60, 0x6D, 0xA1, 0x6D, 0x79, 0xF7, 0x36, 0xFD
	.byte 0x01, 0x1C, 0x60, 0x6D, 0x04, 0x4A, 0x80, 0x18, 0x81, 0x42, 0x00, 0xD1, 0x2D, 0xE1, 0xCC, 0x20
	.byte 0x40, 0x42, 0x20, 0x66, 0x01, 0x20, 0x27, 0xE1, 0x00, 0xE0, 0xFF, 0xFF, 0xA0, 0x7F, 0x01, 0x02
	.byte 0x20, 0x1C, 0x70, 0x30, 0x00, 0x78, 0x01, 0x43, 0x04, 0x4A, 0x88, 0x18, 0x01, 0x28, 0x02, 0xD9
	.byte 0x03, 0x48, 0x81, 0x42, 0x06, 0xD1, 0xA0, 0x7B, 0x01, 0x30, 0x15, 0xE1, 0xFA, 0x81, 0xFF, 0xFF
	.byte 0x0B, 0x7E, 0x00, 0x00, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x00, 0xD0, 0xE6, 0xE0
	.byte 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78, 0x01, 0x28, 0x04, 0xD1, 0xE0, 0x7C, 0x00, 0x28, 0x06, 0xD0
	.byte 0x01, 0x38, 0xD3, 0xE0, 0xE0, 0x7C, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x38, 0xCE, 0xE0, 0x05, 0x20
	.byte 0xCC, 0xE0, 0x0C, 0x49, 0x20, 0x1C, 0x86, 0xF7, 0x1F, 0xFE, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73
	.byte 0x20, 0x1C, 0x86, 0xF7, 0x93, 0xFE, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x00, 0xD0
	.byte 0xEB, 0xE0, 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78, 0x01, 0x28, 0x00, 0xD0, 0xE0, 0xE0, 0xCC, 0x20
	.byte 0x40, 0x42, 0xDE, 0xE0, 0x0D, 0x7E, 0x00, 0x00, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x25, 0x1C
	.byte 0xB9, 0x35, 0x03, 0x28, 0x1B, 0xD1, 0xE0, 0x7C, 0x01, 0x30, 0xE0, 0x74, 0x00, 0x06, 0x00, 0x0E
	.byte 0x05, 0x28, 0x04, 0xD9, 0x28, 0x78, 0x01, 0x30, 0x28, 0x70, 0x00, 0x20, 0xE0, 0x74, 0x2B, 0x49
	.byte 0xE0, 0x7C, 0x80, 0x00, 0x40, 0x18, 0xA1, 0x6E, 0x00, 0x68, 0x09, 0x18, 0xA1, 0x66, 0x28, 0x49
	.byte 0xE0, 0x7C, 0x40, 0x00, 0x40, 0x18, 0x01, 0x88, 0x20, 0x1C, 0x86, 0xF7, 0xE5, 0xFD, 0x20, 0x1C
	.byte 0x86, 0xF7, 0x5C, 0xFE, 0xA0, 0x6E, 0xA0, 0x65, 0x28, 0x78, 0x03, 0x28, 0x16, 0xD9, 0x00, 0x26
	.byte 0x2E, 0x70, 0x20, 0x4B, 0x20, 0x4A, 0x11, 0x68, 0x20, 0x48, 0x48, 0x43, 0x20, 0x49, 0x40, 0x18
	.byte 0x40, 0x00, 0x41, 0x08, 0x11, 0x60, 0x40, 0x0C, 0x0F, 0x21, 0x08, 0x40, 0x80, 0x00, 0xC0, 0x18
	.byte 0x00, 0x68, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x20, 0x60, 0x73, 0xA6, 0x73, 0x60, 0x7B, 0x03, 0x28
	.byte 0x00, 0xD1, 0x9A, 0xE0, 0x60, 0x6D, 0xA1, 0x6D, 0x16, 0x4A, 0x89, 0x18, 0x79, 0xF7, 0x84, 0xF8
	.byte 0x01, 0x1C, 0x00, 0x29, 0x03, 0xD0, 0xCC, 0x20, 0x20, 0x66, 0x01, 0x20, 0xA0, 0x73, 0x20, 0x1C
	.byte 0xB8, 0x30, 0x05, 0x78, 0x01, 0x2D, 0x21, 0xD1, 0x60, 0x6D, 0xA1, 0x6D, 0x0E, 0x4A, 0x89, 0x18
	.byte 0x79, 0xF7, 0x0C, 0xFC, 0x01, 0x1C, 0x60, 0x6D, 0x80, 0x22, 0x92, 0x01, 0x80, 0x18, 0x81, 0x42
	.byte 0x00, 0xD1, 0x7A, 0xE0, 0xCC, 0x20, 0x20, 0x66, 0xA5, 0x73, 0x76, 0xE0, 0xC8, 0x97, 0x36, 0x08
	.byte 0xA4, 0x97, 0x36, 0x08, 0x28, 0x97, 0x36, 0x08, 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00
	.byte 0xC3, 0x9E, 0x26, 0x00, 0x00, 0xA0, 0xFF, 0xFF, 0x00, 0xD0, 0xFF, 0xFF, 0x60, 0x6D, 0xA1, 0x6D
	.byte 0x06, 0x4A, 0x89, 0x18, 0x79, 0xF7, 0x62, 0xFC, 0x01, 0x1C, 0x60, 0x6D, 0x04, 0x4A, 0x80, 0x18
	.byte 0x81, 0x42, 0x5A, 0xD0, 0xCC, 0x20, 0x20, 0x66, 0x01, 0x20, 0x55, 0xE0, 0x00, 0xD0, 0xFF, 0xFF
	.byte 0x00, 0xE0, 0xFF, 0xFF, 0xA0, 0x7F, 0x01, 0x02, 0x20, 0x1C, 0x70, 0x30, 0x00, 0x78, 0x01, 0x43
	.byte 0x04, 0x4A, 0x88, 0x18, 0x01, 0x28, 0x02, 0xD9, 0x03, 0x48, 0x81, 0x42, 0x06, 0xD1, 0xA0, 0x7B
	.byte 0x01, 0x30, 0x41, 0xE0, 0xFA, 0x81, 0xFF, 0xFF, 0x0B, 0x7E, 0x00, 0x00, 0x20, 0x1C, 0x73, 0x30
	.byte 0x00, 0x78, 0x03, 0x28, 0x13, 0xD1, 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78, 0xE0, 0x7C, 0x01, 0x30
	.byte 0xE0, 0x74, 0x00, 0x06, 0x00, 0x0E, 0x05, 0x28, 0x01, 0xD9, 0x00, 0x20, 0xE0, 0x74, 0x06, 0x48
	.byte 0xE1, 0x7C, 0x49, 0x00, 0x09, 0x18, 0x09, 0x88, 0x20, 0x1C, 0x86, 0xF7, 0x4D, 0xFD, 0x20, 0x1C
	.byte 0x86, 0xF7, 0xC4, 0xFD, 0x21, 0xE0, 0x00, 0x00, 0xA4, 0x97, 0x36, 0x08, 0x0B, 0x49, 0x20, 0x1C
	.byte 0x86, 0xF7, 0x42, 0xFD, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0x86, 0xF7, 0xB6, 0xFD
	.byte 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x0F, 0xD1, 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78
	.byte 0x01, 0x28, 0x05, 0xD1, 0xCC, 0x20, 0x40, 0x42, 0x03, 0xE0, 0x00, 0x00, 0x0D, 0x7E, 0x00, 0x00
	.byte 0xCC, 0x20, 0xE0, 0x65, 0x00, 0x20, 0x60, 0x73, 0xA0, 0x73, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_08090b20
FUN_08090b20:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090b24
FUN_08090b24: @ 0x08090B24
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090B32
	b _08090C54
_08090B32:
	lsls r0, r0, #2
	ldr r1, _08090B3C @ =_08090B40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090B3C: .4byte _08090B40
_08090B40: @ jump table
	.4byte _08090B64 @ case 0
	.4byte _08090B7C @ case 1
	.4byte _08090BA0 @ case 2
	.4byte _08090BB8 @ case 3
	.4byte _08090BE0 @ case 4
	.4byte _08090C00 @ case 5
	.4byte _08090C12 @ case 6
	.4byte _08090C30 @ case 7
	.4byte _08090C3E @ case 8
_08090B64:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090B98 @ =0x08369668
	bl SetDDP
	ldr r1, _08090B9C @ =0x00007E0E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090B7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
	.align 2, 0
_08090B98: .4byte 0x08369668
_08090B9C: .4byte 0x00007E0E
_08090BA0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090C54
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
_08090BB8:
	ldr r1, _08090BF8 @ =0x00007E0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08090BFC @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809118c
	movs r0, #0x2c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090BE0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
	.align 2, 0
_08090BF8: .4byte 0x00007E0F
_08090BFC: .4byte 0xFFFFE400
_08090C00:
	ldr r1, _08090C2C @ =0x00007E10
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090C24
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C24:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08090C54
	.align 2, 0
_08090C2C: .4byte 0x00007E10
_08090C30:
	ldr r1, _08090C5C @ =0x00007E11
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C3E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	movs r0, #0
	strb r0, [r4, #0xd]
_08090C52:
	strb r0, [r4, #0xe]
_08090C54:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090C5C: .4byte 0x00007E11

	thumb_func_start FUN_08090c60
FUN_08090c60:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090c64
FUN_08090c64: @ 0x08090C64
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090C72
	b _08090D96
_08090C72:
	lsls r0, r0, #2
	ldr r1, _08090C7C @ =_08090C80
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090C7C: .4byte _08090C80
_08090C80: @ jump table
	.4byte _08090CA4 @ case 0
	.4byte _08090CBC @ case 1
	.4byte _08090D52 @ case 2
	.4byte _08090CDC @ case 3
	.4byte _08090D20 @ case 4
	.4byte _08090D40 @ case 5
	.4byte _08090D52 @ case 6
	.4byte _08090D70 @ case 7
	.4byte _08090D7E @ case 8
_08090CA4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090CD4 @ =0x083696B0
	bl SetDDP
	ldr r1, _08090CD8 @ =0x00007E12
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090CBC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	b _08090D30
	.align 2, 0
_08090CD4: .4byte 0x083696B0
_08090CD8: .4byte 0x00007E12
_08090CDC:
	ldr r1, _08090CF8 @ =0x00007E13
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #1
	bne _08090CFC
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	b _08090D00
	.align 2, 0
_08090CF8: .4byte 0x00007E13
_08090CFC:
	ldr r0, [r4, #0x54]
	ldr r1, _08090D38 @ =0xFFFFFC00
_08090D00:
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08090D3C @ =0xFFFFE700
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809118c
	movs r0, #0x2c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D20:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
_08090D30:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08090D96
	.align 2, 0
_08090D38: .4byte 0xFFFFFC00
_08090D3C: .4byte 0xFFFFE700
_08090D40:
	ldr r1, _08090D6C @ =0x00007E14
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D52:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090D64
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D64:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08090D96
	.align 2, 0
_08090D6C: .4byte 0x00007E14
_08090D70:
	ldr r1, _08090DA0 @ =0x00007E15
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D7E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08090D96:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090DA0: .4byte 0x00007E15

	thumb_func_start FUN_08090da4
FUN_08090da4:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090da8
FUN_08090da8: @ 0x08090DA8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _08090DB4
	b _08090ED0
_08090DB4:
	lsls r0, r0, #2
	ldr r1, _08090DC0 @ =_08090DC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090DC0: .4byte _08090DC4
_08090DC4: @ jump table
	.4byte _08090DE4 @ case 0
	.4byte _08090DF8 @ case 1
	.4byte _08090E10 @ case 2
	.4byte _08090E2C @ case 3
	.4byte _08090E58 @ case 4
	.4byte _08090E84 @ case 5
	.4byte _08090EAC @ case 6
	.4byte _08090EBA @ case 7
_08090DE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090E0C @ =0x08369710
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090DF8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E0C: .4byte 0x08369710
_08090E10:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090E50 @ =0x083696F8
	bl SetDDP
	ldr r1, _08090E54 @ =0x00007E16
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090E2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090ED0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E50: .4byte 0x083696F8
_08090E54: .4byte 0x00007E16
_08090E58:
	ldr r1, _08090E9C @ =0x00007E18
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08090EA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090EA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08090EA8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090E84:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E9C: .4byte 0x00007E18
_08090EA0: .4byte RNG_0202f388
_08090EA4: .4byte 0x000343FD
_08090EA8: .4byte 0x00269EC3
_08090EAC:
	ldr r1, _08090ED8 @ =0x00007E19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090EBA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090ED0
	movs r0, #0
	strb r0, [r4, #0xd]
_08090ECE:
	strb r0, [r4, #0xe]
_08090ED0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090ED8: .4byte 0x00007E19

	thumb_func_start FUN_08090edc
FUN_08090edc:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090ee0
FUN_08090ee0: @ 0x08090EE0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090EEC
	b _0809105C
_08090EEC:
	lsls r0, r0, #2
	ldr r1, _08090EF8 @ =_08090EFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090EF8: .4byte _08090EFC
_08090EFC: @ jump table
	.4byte _08090F20 @ case 0
	.4byte _08090F34 @ case 1
	.4byte _08090F4C @ case 2
	.4byte _08090F8A @ case 3
	.4byte _08090FC2 @ case 4
	.4byte _08090FE4 @ case 5
	.4byte _08091010 @ case 6
	.4byte _08091038 @ case 7
	.4byte _08091046 @ case 8
_08090F20:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090F48 @ =0x08369710
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090F34:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08090F42
	b _0809105C
_08090F42:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
	.align 2, 0
_08090F48: .4byte 0x08369710
_08090F4C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090F74 @ =0x083696F8
	bl SetDDP
	ldr r1, _08090F78 @ =0x00007E17
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x60
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #1
	bne _08090F7C
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _08090F7E
	.align 2, 0
_08090F74: .4byte 0x083696F8
_08090F78: .4byte 0x00007E17
_08090F7C:
	movs r0, #0xcc
_08090F7E:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090F8A:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08090F9A
	str r1, [r4, #0x60]
_08090F9A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809105C
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
_08090FC2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809105C
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0809105C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
_08090FE4:
	ldr r1, _08091028 @ =0x00007E18
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _0809102C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08091030 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08091034 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091010:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809105C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
	.align 2, 0
_08091028: .4byte 0x00007E18
_0809102C: .4byte RNG_0202f388
_08091030: .4byte 0x000343FD
_08091034: .4byte 0x00269EC3
_08091038:
	ldr r1, _08091064 @ =0x00007E19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091046:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809105C
	movs r0, #0
	strb r0, [r4, #0xd]
_0809105A:
	strb r0, [r4, #0xe]
_0809105C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091064: .4byte 0x00007E19

	thumb_func_start FUN_08091068
FUN_08091068:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0809106c
FUN_0809106c: @ 0x0809106C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _0809107C
	cmp r6, #1
	beq _08091124
	b _08091146
_0809107C:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080910C2
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080910C2:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08091102
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
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
	b _0809111E
_08091102:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809111E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091124:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ldr r2, _0809114C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r1]
_08091146:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809114C: .4byte 0xFFFFFE00

	thumb_func_start FUN_08091150
FUN_08091150:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08091154
FUN_08091154: @ 0x08091154
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _08091162
	movs r0, #1
	strb r0, [r1, #0xe]
_08091162:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08091168
FUN_08091168: @ 0x08091168
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809116c
FUN_0809116c: @ 0x0809116C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08091170
FUN_08091170: @ 0x08091170
	movs r0, #1
	bx lr

	thumb_func_start FUN_08091174
FUN_08091174: @ 0x08091174
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _08091182
	movs r0, #1
	strb r0, [r1, #0xe]
_08091182:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08091188
FUN_08091188: @ 0x08091188
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809118c
FUN_0809118c: @ 0x0809118C
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r0, _080911F8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r7]
	subs r4, r1, r0
	ldr r0, [r7, #4]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	subs r5, r1, r0
	asrs r0, r4, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r5, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0xe
	cmp r6, #0
	beq _080911D8
	lsls r0, r4, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
_080911D8:
	cmp r4, #0
	ble _0809122A
	cmp r5, #0
	ble _08091206
	ldr r0, _080911FC @ =gSineTable
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08091200
	movs r0, #0x7e
	subs r0, r0, r2
	b _0809123E
	.align 2, 0
_080911F8: .4byte pZero2
_080911FC: .4byte gSineTable
_08091200:
	adds r0, r2, #0
	adds r0, #0x7e
	b _0809123E
_08091206:
	ldr r0, _08091220 @ =gSineTable
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08091224
	adds r0, r2, #0
	adds r0, #0x7f
	b _0809123E
	.align 2, 0
_08091220: .4byte gSineTable
_08091224:
	rsbs r0, r2, #0
	adds r0, #0x7f
	b _0809123E
_0809122A:
	cmp r5, #0
	ble _08091248
	ldr r0, _08091244 @ =gSineTable
	adds r1, r5, #0
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
_0809123E:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _08091256
	.align 2, 0
_08091244: .4byte gSineTable
_08091248:
	ldr r1, _08091278 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrb r2, [r0]
_08091256:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, #0
	bl CreateLemon
	adds r1, r0, #0
	cmp r1, #0
	beq _08091272
	lsls r0, r4, #9
	asrs r0, r0, #8
	str r0, [r1, #0x5c]
	lsls r0, r5, #9
	asrs r0, r0, #8
	str r0, [r1, #0x60]
_08091272:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091278: .4byte gSineTable

	thumb_func_start nop_0809127c
nop_0809127c: @ 0x0809127C
	bx lr
	.align 2, 0
