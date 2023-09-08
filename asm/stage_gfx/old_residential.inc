	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800decc
FUN_0800decc: @ 0x0800DECC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x14
	ldr r3, [r4, #0x34]
	ldr r2, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	subs r1, r3, r1
	adds r1, #0xf
	ldr r0, [r4, #0x40]
	subs r0, r2, r0
	adds r5, r0, #0
	adds r5, #0xf
	movs r0, #0xc8
	lsls r0, r0, #3
	adds r2, r2, r0
	ldr r0, [r4, #0x2c]
	asrs r0, r0, #8
	adds r0, r0, r3
	str r0, [sp]
	ldr r0, [r4, #0x30]
	asrs r0, r0, #8
	adds r0, r0, r2
	str r0, [sp, #4]
	cmp r1, #0x1e
	bhi _0800DF12
	cmp r5, #0x1e
	bhi _0800DF12
	ldr r3, _0800DF38 @ =gOverworld
	ldr r1, _0800DF3C @ =0x0002D02C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800DF48
_0800DF12:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _0800DF40 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	ldr r3, _0800DF44 @ =0x020029E0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006ae0
	b _0800DF70
	.align 2, 0
_0800DF38: .4byte gOverworld
_0800DF3C: .4byte 0x0002D02C
_0800DF40: .4byte gVideoRegBuffer+4
_0800DF44: .4byte 0x020029E0
_0800DF48:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _0800DF94 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006bb4
_0800DF70:
	ldr r0, _0800DF98 @ =gOverworld
	ldr r1, _0800DF9C @ =0x0002D02C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r4, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	ldr r0, _0800DFA0 @ =gVideoRegBuffer+12
	adds r1, r1, r0
	adds r0, r6, #0
	bl UpdateBGOFS
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DF94: .4byte gVideoRegBuffer+4
_0800DF98: .4byte gOverworld
_0800DF9C: .4byte 0x0002D02C
_0800DFA0: .4byte gVideoRegBuffer+12

	thumb_func_start FUN_0800dfa4
FUN_0800dfa4: @ 0x0800DFA4
	push {r4, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0xe]
	cmp r4, #0
	bne _0800DFDE
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800DFE4 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800DFE8 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r3, #0x44]
	movs r0, #0x80
	str r0, [r3, #0x48]
	str r4, [r3, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #1
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800DFDE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800DFE4: .4byte gVideoRegBuffer+4
_0800DFE8: .4byte 0x0000FFFC

	thumb_func_start FUN_0800dfec
FUN_0800dfec: @ 0x0800DFEC
	push {r4, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0xe]
	cmp r4, #0
	bne _0800E022
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E028 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E02C @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r3, #0x44]
	str r4, [r3, #0x48]
	str r4, [r3, #0x4c]
	movs r0, #0xa0
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E022:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E028: .4byte gVideoRegBuffer+4
_0800E02C: .4byte 0x0000FFFC

	thumb_func_start FUN_0800e030
FUN_0800e030: @ 0x0800E030
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800E058
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E070 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E074 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E058:
	ldr r2, [r3, #0x34]
	ldr r0, _0800E078 @ =0x000003BF
	cmp r2, r0
	bgt _0800E07C
	movs r0, #0x40
	str r0, [r3, #0x44]
	adds r0, #0xc0
	str r0, [r3, #0x48]
	movs r0, #0xb4
	str r0, [r3, #0x4c]
	movs r0, #0
	b _0800E0C6
	.align 2, 0
_0800E070: .4byte gVideoRegBuffer+4
_0800E074: .4byte 0x0000FFFC
_0800E078: .4byte 0x000003BF
_0800E07C:
	ldr r1, [r3, #0x38]
	movs r0, #0xa0
	lsls r0, r0, #1
	cmp r1, r0
	ble _0800E09C
	movs r0, #0x40
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	ldr r0, _0800E098 @ =0x000004EC
	str r0, [r3, #0x4c]
	movs r0, #0xb4
	lsls r0, r0, #1
	b _0800E0C6
	.align 2, 0
_0800E098: .4byte 0x000004EC
_0800E09C:
	ldr r0, _0800E0B0 @ =0x0000077F
	cmp r2, r0
	bgt _0800E0B8
	movs r0, #0x40
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	ldr r0, _0800E0B4 @ =0x000004EC
	str r0, [r3, #0x4c]
	movs r0, #0x78
	b _0800E0C6
	.align 2, 0
_0800E0B0: .4byte 0x0000077F
_0800E0B4: .4byte 0x000004EC
_0800E0B8:
	movs r0, #0xc0
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	movs r0, #0x87
	lsls r0, r0, #2
	str r0, [r3, #0x4c]
	movs r0, #0x28
_0800E0C6:
	str r0, [r3, #0x50]
	pop {r0}
	bx r0

	thumb_func_start FUN_0800e0cc
FUN_0800e0cc: @ 0x0800E0CC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0800E102
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r3, r3, #1
	ldr r1, _0800E10C @ =gVideoRegBuffer+4
	adds r3, r3, r1
	ldr r1, [r4, #0x64]
	movs r2, #0x47
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _0800E110 @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x37
	movs r3, #0
	bl LoadBgMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800E102:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E10C: .4byte gVideoRegBuffer+4
_0800E110: .4byte gBgMapOffsets

	thumb_func_start ctrlOLSBG3Scroll
ctrlOLSBG3Scroll: @ 0x0800E114
	push {r4, r5, r6, r7, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r1, [r0, #0x38]
	ldr r3, _0800E188 @ =0xFFFFFC40
	adds r1, r1, r3
	asrs r5, r1, #2
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r1, _0800E18C @ =gVideoRegBuffer+12
	adds r3, r2, r1
	ldr r0, [r0, #0x34]
	asrs r0, r0, #2
	strh r0, [r3]
	adds r1, #2
	adds r2, r2, r1
	strh r5, [r2]
	cmp r5, #0x57
	bgt _0800E1E8
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0800E1E8
	ldr r2, _0800E190 @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r4, [r0]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _0800E194 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800E198 @ =0xA6600001
	str r0, [r1]
	cmp r5, #0
	ble _0800E19C
	movs r3, #0
	movs r0, #0x58
	subs r0, r0, r5
	cmp r3, r0
	bge _0800E1AE
	lsls r2, r5, #0x10
	adds r1, r4, #0
	adds r3, r0, #0
_0800E17C:
	stm r1!, {r2}
	subs r3, #1
	cmp r3, #0
	bne _0800E17C
	adds r3, r0, #0
	b _0800E1AE
	.align 2, 0
_0800E188: .4byte 0xFFFFFC40
_0800E18C: .4byte gVideoRegBuffer+12
_0800E190: .4byte gIntrManager
_0800E194: .4byte 0x0400001C
_0800E198: .4byte 0xA6600001
_0800E19C:
	movs r1, #0
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
_0800E1A4:
	str r1, [r0]
	subs r0, #4
	cmp r0, r4
	bge _0800E1A4
	movs r3, #0x58
_0800E1AE:
	adds r0, r5, r3
	cmp r0, #0x57
	bgt _0800E1CE
	lsls r0, r3, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r3, #2
	adds r2, r0, r4
	ldr r6, _0800E1F0 @ =0xFFFF0000
_0800E1C2:
	stm r2!, {r1}
	adds r1, r1, r6
	adds r3, #1
	adds r0, r5, r3
	cmp r0, #0x57
	ble _0800E1C2
_0800E1CE:
	cmp r3, #0x9f
	bgt _0800E1E8
	lsrs r0, r7, #4
	lsls r0, r0, #2
	ldr r1, _0800E1F4 @ =gVideoRegBuffer+12
	adds r2, r0, r1
	lsls r0, r3, #2
	adds r1, r0, r4
_0800E1DE:
	ldr r0, [r2]
	stm r1!, {r0}
	adds r3, #1
	cmp r3, #0x9f
	ble _0800E1DE
_0800E1E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E1F0: .4byte 0xFFFF0000
_0800E1F4: .4byte gVideoRegBuffer+12

	thumb_func_start FUN_0800e1f8
FUN_0800e1f8: @ 0x0800E1F8
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800E220
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E224 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E228 @ =0x0000FFFC
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E220:
	pop {r0}
	bx r0
	.align 2, 0
_0800E224: .4byte gVideoRegBuffer+4
_0800E228: .4byte 0x0000FFFC

	thumb_func_start FUN_0800e22c
FUN_0800e22c: @ 0x0800E22C
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	adds r0, r2, #0
	cmp r0, #0
	bne _0800E24A
	str r0, [r1, #0x44]
	str r0, [r1, #0x48]
	movs r0, #0xc3
	lsls r0, r0, #4
	str r0, [r1, #0x4c]
	movs r0, #0xa0
	str r0, [r1, #0x50]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_0800E24A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800e250
FUN_0800e250: @ 0x0800E250
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800E278
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E27C @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E280 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E278:
	pop {r0}
	bx r0
	.align 2, 0
_0800E27C: .4byte gVideoRegBuffer+4
_0800E280: .4byte 0x0000FFFC

	thumb_func_start FUN_0800e284
FUN_0800e284: @ 0x0800E284
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _0800E294 @ =0x0004FFFF
	cmp r3, r0
	ble _0800E298
	movs r0, #0
	b _0800E2B8
	.align 2, 0
_0800E294: .4byte 0x0004FFFF
_0800E298:
	ldr r2, _0800E2C0 @ =gOverworld
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r5, #0xc8
	lsls r5, r5, #0xb
	adds r0, r3, r5
	asrs r0, r0, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
_0800E2B8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800E2C0: .4byte gOverworld

	thumb_func_start FUN_0800e2c4
FUN_0800e2c4: @ 0x0800E2C4
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r0, _0800E2F8 @ =0x0004FFFF
	cmp r1, r0
	bgt _0800E2F2
	ldr r4, _0800E2FC @ =gOverworld
	movs r0, #0xb0
	lsls r0, r0, #0xa
	adds r5, r4, r0
	ldrh r6, [r5]
	asrs r0, r2, #0xc
	movs r2, #0xc8
	lsls r2, r2, #0xb
	adds r1, r1, r2
	asrs r1, r1, #0xc
	ldr r2, _0800E300 @ =0x0833DFDA
	bl PatchMetatileMap
	strh r6, [r5]
	ldr r0, _0800E304 @ =0x0002D02C
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
_0800E2F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800E2F8: .4byte 0x0004FFFF
_0800E2FC: .4byte gOverworld
_0800E300: .4byte 0x0833DFDA
_0800E304: .4byte 0x0002D02C

	thumb_func_start FUN_0800e308
FUN_0800e308: @ 0x0800E308
	push {lr}
	ldr r1, [r0]
	ldr r2, _0800E32C @ =0xFFFFF000
	adds r1, r1, r2
	asrs r1, r1, #0xc
	ldr r0, [r0, #4]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	asrs r3, r0, #0xc
	cmp r3, #0x13
	bgt _0800E334
	adds r2, r1, #0
	subs r2, #0xf8
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E330 @ =0x0833DFE2
	b _0800E342
	.align 2, 0
_0800E32C: .4byte 0xFFFFF000
_0800E330: .4byte 0x0833DFE2
_0800E334:
	cmp r3, #0x38
	ble _0800E354
	adds r2, r1, #0
	subs r2, #0xf6
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E350 @ =0x0833E032
_0800E342:
	adds r2, r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl PatchMetatileMap
	b _0800E368
	.align 2, 0
_0800E350: .4byte 0x0833E032
_0800E354:
	adds r2, r1, #0
	subs r2, #0xf2
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E36C @ =0x0833DFFA
	adds r2, r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl PatchMetatileMap
_0800E368:
	pop {r0}
	bx r0
	.align 2, 0
_0800E36C: .4byte 0x0833DFFA

	thumb_func_start FUN_0800e370
FUN_0800e370: @ 0x0800E370
	push {r4, r5, r6, r7, lr}
	ldr r1, [r0]
	ldr r2, _0800E3B0 @ =0xFFFFF000
	adds r1, r1, r2
	asrs r5, r1, #0xc
	ldr r0, [r0, #4]
	asrs r6, r0, #0xc
	movs r1, #0
	ldr r7, _0800E3B4 @ =0x0833E048
_0800E382:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	lsls r2, r3, #3
	adds r1, r2, r7
	ldr r1, [r1]
	adds r4, r0, #0
	cmp r5, r1
	bne _0800E3BC
	adds r0, r7, #4
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r6, r0
	bne _0800E3BC
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r0, _0800E3B8 @ =0x0833E0A8
	adds r2, r2, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl PatchMetatileMap
	b _0800E3D4
	.align 2, 0
_0800E3B0: .4byte 0xFFFFF000
_0800E3B4: .4byte 0x0833E048
_0800E3B8: .4byte 0x0833E0A8
_0800E3BC:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _0800E382
	ldr r2, _0800E3DC @ =0x0833E03A
	adds r0, r5, #0
	adds r1, r6, #0
	bl PatchMetatileMap
_0800E3D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E3DC: .4byte 0x0833E03A
