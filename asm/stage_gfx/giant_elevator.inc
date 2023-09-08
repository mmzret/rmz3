	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start gelevator_08013e88
gelevator_08013e88: @ 0x08013E88
	push {r4, r5, lr}
	ldr r2, _08013EC4 @ =gOverworld
	ldr r1, _08013EC8 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xe
	bne _08013ED0
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _08013ED0
	ldr r0, _08013ECC @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08013EBC
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xd8
	movs r1, #0
	bl LoadBlink
_08013EBC:
	movs r0, #0xd8
	bl GetBlinkMotionState
	b _08013EEC
	.align 2, 0
_08013EC4: .4byte gOverworld
_08013EC8: .4byte 0x000007D4
_08013ECC: .4byte 0x0002D028
_08013ED0:
	ldr r0, _08013F28 @ =gOverworld
	ldr r1, _08013F2C @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013EEC
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xd8
	bl ClearBlink
_08013EEC:
	ldr r2, _08013F28 @ =gOverworld
	ldr r1, _08013F30 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xe
	bne _08013F34
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _08013F34
	ldr r0, _08013F2C @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08013F1E
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xd7
	movs r1, #0
	bl LoadBlink
_08013F1E:
	movs r0, #0xd7
	bl GetBlinkMotionState
	b _08013F50
	.align 2, 0
_08013F28: .4byte gOverworld
_08013F2C: .4byte 0x0002D028
_08013F30: .4byte 0x000007D6
_08013F34:
	ldr r0, _08013FB0 @ =gOverworld
	ldr r1, _08013FB4 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08013F50
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xd7
	bl ClearBlink
_08013F50:
	ldr r0, _08013FB0 @ =gOverworld
	ldr r2, _08013FB8 @ =0x000007D6
	adds r1, r0, r2
	ldrh r2, [r1]
	lsrs r1, r2, #8
	adds r5, r0, #0
	cmp r1, #0xe
	bne _08014014
	movs r0, #0xff
	ands r0, r2
	cmp r0, #2
	bne _08014014
	ldr r0, _08013FB4 @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _08013F8E
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xd9
	movs r1, #0
	bl LoadBlink
	ldr r1, _08013FBC @ =0x0002D02E
	adds r0, r5, r1
	strh r4, [r0]
_08013F8E:
	movs r0, #0xd9
	bl GetBlinkMotionState
	ldr r2, _08013FC0 @ =0x0002D024
	adds r4, r5, r2
	ldrb r3, [r4]
	adds r1, r3, #0
	cmp r1, #0xa
	bls _08013FC8
	ldr r0, _08013FC4 @ =0x0002D02C
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08013FE8
	subs r0, #2
	strh r0, [r1]
	b _08013FE8
	.align 2, 0
_08013FB0: .4byte gOverworld
_08013FB4: .4byte 0x0002D028
_08013FB8: .4byte 0x000007D6
_08013FBC: .4byte 0x0002D02E
_08013FC0: .4byte 0x0002D024
_08013FC4: .4byte 0x0002D02C
_08013FC8:
	cmp r1, #1
	bls _08013FE8
	ldr r0, _08013FDC @ =0x0002D02C
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0xff
	bhi _08013FE0
	adds r0, #2
	strh r0, [r2]
	b _08013FE8
	.align 2, 0
_08013FDC: .4byte 0x0002D02C
_08013FE0:
	cmp r1, #2
	bne _08013FE8
	adds r0, r3, #1
	strb r0, [r4]
_08013FE8:
	ldr r0, _08014008 @ =gOverworld
	ldr r1, _0801400C @ =0x0002D02E
	adds r2, r0, r1
	subs r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08014010 @ =0x09FF0000
	cmp r0, r1
	bls _0801402E
	movs r0, #0
	strh r0, [r2]
	b _0801402E
	.align 2, 0
_08014008: .4byte gOverworld
_0801400C: .4byte 0x0002D02E
_08014010: .4byte 0x09FF0000
_08014014:
	ldr r0, _08014034 @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801402E
	movs r0, #4
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xd9
	bl ClearBlink
_0801402E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014034: .4byte 0x0002D028

	thumb_func_start gelevator_08014038
gelevator_08014038: @ 0x08014038
	push {r4, r5, r6, lr}
	ldr r5, _08014090 @ =gOverworld
	ldr r1, _08014094 @ =0x000007D6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xe
	bne _08014088
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _08014088
	ldr r6, _08014098 @ =gStageTilesetOffsets+(18*4)
	ldr r0, _0801409C @ =0x0002D02E
	adds r5, r5, r0
	ldrh r0, [r5]
	lsrs r0, r0, #9
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080140A0 @ =0x087050EC
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrh r0, [r5]
	lsrs r0, r0, #9
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08014088:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014090: .4byte gOverworld
_08014094: .4byte 0x000007D6
_08014098: .4byte gStageTilesetOffsets+(18*4)
_0801409C: .4byte 0x0002D02E
_080140A0: .4byte 0x087050EC

	thumb_func_start nop_080140a4
nop_080140a4: @ 0x080140A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080140a8
FUN_080140a8: @ 0x080140A8
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x34]
	ldr r0, _080140CC @ =0x00000B3F
	cmp r1, r0
	bgt _080140D8
	ldr r1, [r2, #0x38]
	ldr r0, _080140D0 @ =0x000003BF
	cmp r1, r0
	bgt _080140D8
	movs r0, #0x40
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	ldr r0, _080140D4 @ =0x000004EC
	str r0, [r2, #0x4c]
	movs r0, #0xf0
	b _08014118
	.align 2, 0
_080140CC: .4byte 0x00000B3F
_080140D0: .4byte 0x000003BF
_080140D4: .4byte 0x000004EC
_080140D8:
	ldr r1, [r2, #0x34]
	ldr r0, _080140FC @ =0x00000EFF
	cmp r1, r0
	bgt _0801410A
	movs r0, #0x80
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	movs r0, #0xb4
	lsls r0, r0, #3
	str r0, [r2, #0x4c]
	ldr r1, [r2, #0x38]
	ldr r0, _08014100 @ =0x000003BF
	cmp r1, r0
	bgt _08014104
	movs r0, #0xc8
	lsls r0, r0, #1
	b _08014118
	.align 2, 0
_080140FC: .4byte 0x00000EFF
_08014100: .4byte 0x000003BF
_08014104:
	movs r0, #0xc8
	lsls r0, r0, #2
	b _08014118
_0801410A:
	movs r0, #0x80
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	ldr r0, _08014120 @ =0x000008E8
	str r0, [r2, #0x4c]
	movs r0, #0x82
	lsls r0, r0, #3
_08014118:
	str r0, [r2, #0x50]
	pop {r0}
	bx r0
	.align 2, 0
_08014120: .4byte 0x000008E8

	thumb_func_start giant_elevator_08014124
giant_elevator_08014124: @ 0x08014124
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	bne _08014168
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r4, r3, #1
	ldr r5, _08014178 @ =gVideoRegBuffer+4
	adds r4, r4, r5
	ldr r1, [r6, #0x60]
	ldr r2, [r6, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r4]
	lsls r3, r3, #2
	adds r5, #8
	adds r3, r3, r5
	str r7, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _0801417C @ =gBgMapOffsets
	str r7, [sp]
	movs r2, #0x62
	movs r3, #0
	bl LoadBgMap
	strh r7, [r6, #0x10]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08014168:
	ldr r1, [r6, #0x34]
	ldr r0, _08014180 @ =0x0000034F
	cmp r1, r0
	bgt _08014184
	ldrh r0, [r6, #0x10]
	subs r0, #1
	b _08014188
	.align 2, 0
_08014178: .4byte gVideoRegBuffer+4
_0801417C: .4byte gBgMapOffsets
_08014180: .4byte 0x0000034F
_08014184:
	ldrh r0, [r6, #0x10]
	adds r0, #1
_08014188:
	strh r0, [r6, #0x10]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08014194
FUN_08014194: @ 0x08014194
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _080141B4 @ =0x0000034F
	cmp r3, r0
	bgt _080141BC
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _080141B8 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	adds r1, r3, #0
	subs r1, #0xf0
	b _080141C8
	.align 2, 0
_080141B4: .4byte 0x0000034F
_080141B8: .4byte gVideoRegBuffer+12
_080141BC:
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _080141E4 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	ldr r5, _080141E8 @ =0xFFFFFB50
	adds r1, r3, r5
_080141C8:
	asrs r1, r1, #1
	strh r1, [r0]
	lsrs r2, r2, #4
	lsls r2, r2, #2
	ldr r0, _080141EC @ =0x0200214E
	adds r2, r2, r0
	ldr r1, [r4, #0x38]
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #1
	adds r1, r1, r0
	strh r1, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080141E4: .4byte gVideoRegBuffer+12
_080141E8: .4byte 0xFFFFFB50
_080141EC: .4byte 0x0200214E

	thumb_func_start FUN_080141f0
FUN_080141f0: @ 0x080141F0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0801422C
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r3, r3, #1
	ldr r1, _0801423C @ =gVideoRegBuffer+4
	adds r3, r3, r1
	ldr r1, [r4, #0x60]
	ldr r2, [r4, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _08014240 @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x61
	movs r3, #0
	bl LoadBgMap
	strh r5, [r4, #0x10]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801422C:
	ldr r1, [r4, #0x34]
	ldr r0, _08014244 @ =0x0000034F
	cmp r1, r0
	bgt _08014248
	ldrh r0, [r4, #0x10]
	adds r0, #1
	b _0801424C
	.align 2, 0
_0801423C: .4byte gVideoRegBuffer+4
_08014240: .4byte gBgMapOffsets
_08014244: .4byte 0x0000034F
_08014248:
	ldrh r0, [r4, #0x10]
	subs r0, #1
_0801424C:
	strh r0, [r4, #0x10]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08014258
FUN_08014258: @ 0x08014258
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _08014278 @ =0x0000034F
	cmp r3, r0
	bgt _08014280
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _0801427C @ =gVideoRegBuffer+12
	adds r0, r0, r1
	adds r1, r3, #0
	subs r1, #0xf0
	b _0801428C
	.align 2, 0
_08014278: .4byte 0x0000034F
_0801427C: .4byte gVideoRegBuffer+12
_08014280:
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _080142A8 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	ldr r5, _080142AC @ =0xFFFFFB50
	adds r1, r3, r5
_0801428C:
	asrs r1, r1, #2
	strh r1, [r0]
	lsrs r2, r2, #4
	lsls r2, r2, #2
	ldr r0, _080142B0 @ =0x0200214E
	adds r2, r2, r0
	ldr r1, [r4, #0x38]
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #2
	adds r1, r1, r0
	strh r1, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080142A8: .4byte gVideoRegBuffer+12
_080142AC: .4byte 0xFFFFFB50
_080142B0: .4byte 0x0200214E

	thumb_func_start gelevator_080142b4
gelevator_080142b4: @ 0x080142B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrb r0, [r7, #0xe]
	cmp r0, #0xa
	bls _080142C8
	b _0801458E
_080142C8:
	lsls r0, r0, #2
	ldr r1, _080142D4 @ =_080142D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080142D4: .4byte _080142D8
_080142D8: @ jump table
	.4byte _08014304 @ case 0
	.4byte _08014392 @ case 1
	.4byte _080143B4 @ case 2
	.4byte _08014408 @ case 3
	.4byte _080143B4 @ case 4
	.4byte _08014408 @ case 5
	.4byte _080143B4 @ case 6
	.4byte _08014408 @ case 7
	.4byte _080143B4 @ case 8
	.4byte _08014484 @ case 9
	.4byte _08014574 @ case 10
_08014304:
	lsrs r5, r2, #4
	lsls r5, r5, #1
	ldr r0, _080143D4 @ =gVideoRegBuffer+4
	adds r5, r5, r0
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	orrs r0, r1
	ldr r3, _080143D8 @ =0x00008044
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r5]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldr r6, _080143DC @ =gBgMapOffsets
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x60
	movs r3, #0
	bl LoadBgMap
	ldrh r1, [r5]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	ldr r5, _080143E0 @ =0x06000800
	adds r0, r0, r5
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x5f
	movs r3, #0
	bl loadBgMap_08004248
	ldr r1, _080143E4 @ =gOverworld
	ldr r6, _080143E8 @ =0x0002D034
	adds r0, r1, r6
	str r4, [r0]
	ldr r2, _080143EC @ =0x0002D038
	adds r0, r1, r2
	str r4, [r0]
	ldr r3, _080143F0 @ =0x0002D03C
	adds r0, r1, r3
	str r4, [r0]
	ldr r5, _080143F4 @ =0x0002D044
	adds r0, r1, r5
	str r4, [r0]
	adds r6, #0x14
	adds r0, r1, r6
	str r4, [r0]
	adds r2, #0x18
	adds r0, r1, r2
	str r4, [r0]
	adds r3, #0x18
	adds r0, r1, r3
	str r4, [r0]
	subs r5, #0x14
	adds r0, r1, r5
	str r4, [r0]
	subs r6, #8
	adds r0, r1, r6
	str r4, [r0]
	ldr r0, _080143F8 @ =0x0002D04C
	adds r1, r1, r0
	str r4, [r1]
	movs r0, #0x80
	strh r0, [r7, #0x10]
	strh r4, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08014392:
	ldr r0, _080143E4 @ =gOverworld
	ldr r1, _080143FC @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _080143A0
	b _0801458E
_080143A0:
	ldr r0, _08014400 @ =0x00000141
	bl PlaySound
	ldr r1, _08014404 @ =gStageRun+288
	movs r0, #4
	bl AppendQuake
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080143B4:
	ldr r2, _080143E4 @ =gOverworld
	ldr r3, _080143EC @ =0x0002D038
	adds r0, r2, r3
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bgt _080143C6
	b _0801458E
_080143C6:
	ldr r5, _080143FC @ =0x0002D024
	adds r0, r2, r5
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	b _0801446C
	.align 2, 0
_080143D4: .4byte gVideoRegBuffer+4
_080143D8: .4byte 0x00008044
_080143DC: .4byte gBgMapOffsets
_080143E0: .4byte 0x06000800
_080143E4: .4byte gOverworld
_080143E8: .4byte 0x0002D034
_080143EC: .4byte 0x0002D038
_080143F0: .4byte 0x0002D03C
_080143F4: .4byte 0x0002D044
_080143F8: .4byte 0x0002D04C
_080143FC: .4byte 0x0002D024
_08014400: .4byte 0x00000141
_08014404: .4byte gStageRun+288
_08014408:
	ldr r0, _08014440 @ =gOverworld
	ldr r6, _08014444 @ =0x0002D038
	adds r2, r0, r6
	movs r1, #0x80
	lsls r1, r1, #9
	str r1, [r2]
	ldr r1, _08014448 @ =0x0002D024
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08014424
	b _0801458E
_08014424:
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	bne _08014450
	ldr r0, _0801444C @ =0x00000141
	bl stopSound
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0x80
	lsls r0, r0, #2
	b _08014460
	.align 2, 0
_08014440: .4byte gOverworld
_08014444: .4byte 0x0002D038
_08014448: .4byte 0x0002D024
_0801444C: .4byte 0x00000141
_08014450:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl stopSound
	ldr r0, _08014474 @ =0x00000141
	bl PlaySound
	movs r0, #0x80
_08014460:
	strh r0, [r7, #0x10]
	ldr r0, _08014478 @ =gOverworld
	ldr r2, _0801447C @ =0x0002D038
	adds r0, r0, r2
	ldr r1, _08014480 @ =0xFFFF0000
	str r1, [r0]
_0801446C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0801458E
	.align 2, 0
_08014474: .4byte 0x00000141
_08014478: .4byte gOverworld
_0801447C: .4byte 0x0002D038
_08014480: .4byte 0xFFFF0000
_08014484:
	ldrh r0, [r7, #0x12]
	cmp r0, #0x3f
	bhi _08014490
	adds r0, #1
	strh r0, [r7, #0x12]
	b _080144F0
_08014490:
	ldr r4, _08014544 @ =gOverworld
	ldr r3, _08014548 @ =0x0002D03C
	adds r6, r4, r3
	ldr r0, [r6]
	movs r5, #0xf0
	lsls r5, r5, #9
	subs r0, r5, r0
	asrs r1, r0, #5
	ldr r0, _0801454C @ =0x0002D030
	adds r2, r4, r0
	ldr r0, [r2]
	cmp r1, r0
	bge _080144AC
	str r1, [r2]
_080144AC:
	cmp r1, #0
	bne _080144F0
	ldr r2, _08014550 @ =0x083458B4
	movs r0, #0xf7
	movs r1, #0x64
	bl ShiftMetatile
	str r5, [r6]
	ldr r0, _08014554 @ =0x00000141
	bl stopSound
	movs r0, #0xa1
	lsls r0, r0, #1
	bl stopSound
	ldr r0, _08014558 @ =0x00000143
	bl PlaySound
	movs r0, #0xa2
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, _0801455C @ =gStageRun+288
	movs r0, #2
	bl AppendQuake
	ldr r2, _08014560 @ =0x0002D024
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080144F0:
	ldr r3, _08014544 @ =gOverworld
	ldr r5, _08014548 @ =0x0002D03C
	adds r4, r3, r5
	ldr r6, _08014564 @ =gSineTable
	ldrb r1, [r7, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r6
	movs r5, #0
	ldrsh r2, [r0, r5]
	ldr r5, _0801454C @ =0x0002D030
	adds r0, r3, r5
	ldr r5, [r0]
	adds r0, r2, #0
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r2, [r4]
	adds r2, r2, r0
	str r2, [r4]
	ldr r0, _08014568 @ =0x0002D038
	adds r4, r3, r0
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	muls r1, r5, r1
	asrs r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0801456C @ =0x0002D034
	adds r3, r3, r0
	ldr r0, [r7, #0x34]
	lsls r0, r0, #8
	ldr r1, _08014570 @ =0xFFF19800
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r2, r2, r0
	str r2, [r3]
	b _0801458E
	.align 2, 0
_08014544: .4byte gOverworld
_08014548: .4byte 0x0002D03C
_0801454C: .4byte 0x0002D030
_08014550: .4byte 0x083458B4
_08014554: .4byte 0x00000141
_08014558: .4byte 0x00000143
_0801455C: .4byte gStageRun+288
_08014560: .4byte 0x0002D024
_08014564: .4byte gSineTable
_08014568: .4byte 0x0002D038
_0801456C: .4byte 0x0002D034
_08014570: .4byte 0xFFF19800
_08014574:
	ldr r1, _08014648 @ =gOverworld
	ldr r3, _0801464C @ =0x0002D034
	adds r2, r1, r3
	ldr r5, _08014650 @ =0x0002D03C
	adds r1, r1, r5
	ldr r0, [r7, #0x34]
	lsls r0, r0, #8
	ldr r6, _08014654 @ =0xFFF19800
	adds r0, r0, r6
	asrs r0, r0, #2
	ldr r1, [r1]
	adds r1, r1, r0
	str r1, [r2]
_0801458E:
	ldrb r4, [r7, #0xe]
	cmp r4, #8
	bhi _080145BA
	ldr r2, _08014648 @ =gOverworld
	ldr r0, _0801464C @ =0x0002D034
	adds r3, r2, r0
	ldr r1, [r7, #0x34]
	lsls r1, r1, #8
	ldr r5, _08014654 @ =0xFFF19800
	adds r1, r1, r5
	asrs r0, r1, #2
	str r0, [r3]
	ldr r6, _08014658 @ =0x0002D044
	adds r3, r2, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #4
	str r0, [r3]
	ldr r0, _0801465C @ =0x0002D050
	adds r2, r2, r0
	asrs r1, r1, #3
	str r1, [r2]
_080145BA:
	subs r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bhi _0801463E
	ldr r5, _08014648 @ =gOverworld
	ldr r1, _08014660 @ =0x0002D030
	adds r2, r5, r1
	ldrh r1, [r7, #0x10]
	lsls r0, r1, #1
	adds r4, r0, r1
	lsls r3, r4, #1
	ldr r0, [r2]
	adds r6, r1, #0
	cmp r0, r3
	bge _080145DE
	adds r0, #6
	str r0, [r2]
_080145DE:
	ldr r0, [r2]
	cmp r0, r3
	ble _080145E8
	subs r0, #6
	str r0, [r2]
_080145E8:
	ldr r3, _08014664 @ =0x0002D038
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r2, [r2]
	adds r1, r1, r2
	str r1, [r0]
	ldr r0, _08014668 @ =0x0002D040
	adds r2, r5, r0
	lsls r1, r6, #2
	ldr r0, [r2]
	cmp r0, r1
	bge _08014604
	adds r0, #4
	str r0, [r2]
_08014604:
	ldr r0, [r2]
	cmp r0, r1
	ble _0801460E
	subs r0, #4
	str r0, [r2]
_0801460E:
	ldr r1, _0801466C @ =0x0002D048
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, [r2]
	adds r1, r1, r2
	str r1, [r0]
	ldr r3, _08014670 @ =0x0002D04C
	adds r2, r5, r3
	ldr r0, [r2]
	cmp r0, r4
	bge _08014628
	adds r0, #3
	str r0, [r2]
_08014628:
	ldr r0, [r2]
	cmp r0, r4
	ble _08014632
	subs r0, #3
	str r0, [r2]
_08014632:
	ldr r6, _08014674 @ =0x0002D054
	adds r0, r5, r6
	ldr r1, [r0]
	ldr r2, [r2]
	adds r1, r1, r2
	str r1, [r0]
_0801463E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014648: .4byte gOverworld
_0801464C: .4byte 0x0002D034
_08014650: .4byte 0x0002D03C
_08014654: .4byte 0xFFF19800
_08014658: .4byte 0x0002D044
_0801465C: .4byte 0x0002D050
_08014660: .4byte 0x0002D030
_08014664: .4byte 0x0002D038
_08014668: .4byte 0x0002D040
_0801466C: .4byte 0x0002D048
_08014670: .4byte 0x0002D04C
_08014674: .4byte 0x0002D054

	thumb_func_start gelevator_08014678
gelevator_08014678: @ 0x08014678
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r1, _08014708 @ =gOverworld
	ldr r2, _0801470C @ =0x0002D034
	adds r0, r1, r2
	ldr r0, [r0]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r6, _08014710 @ =0x0002D038
	adds r0, r1, r6
	ldr r0, [r0]
	lsls r0, r0, #8
	lsrs r4, r0, #0x10
	ldr r7, _08014714 @ =0x0002D044
	adds r0, r1, r7
	ldr r0, [r0]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _08014718 @ =0x0002D048
	adds r1, r1, r0
	ldr r0, [r1]
	lsls r0, r0, #0xf
	lsrs r5, r0, #0x17
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	beq _0801477C
	ldr r2, _0801471C @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r2, r7
	ldr r0, _08014720 @ =0x04000018
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08014724 @ =0xA6600001
	str r0, [r1]
	movs r2, #0
	lsls r4, r4, #0x10
	str r4, [sp]
	movs r1, #0x80
	lsls r1, r1, #1
	mov ip, r1
	lsls r4, r5, #0x10
	mov r7, r8
	orrs r4, r7
	adds r0, r5, r1
	lsls r3, r0, #0x10
	orrs r3, r7
	adds r1, r6, #0
_080146FA:
	adds r0, r2, r5
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq _08014728
	str r4, [r1]
	b _0801472A
	.align 2, 0
_08014708: .4byte gOverworld
_0801470C: .4byte 0x0002D034
_08014710: .4byte 0x0002D038
_08014714: .4byte 0x0002D044
_08014718: .4byte 0x0002D048
_0801471C: .4byte gIntrManager
_08014720: .4byte 0x04000018
_08014724: .4byte 0xA6600001
_08014728:
	str r3, [r1]
_0801472A:
	adds r1, #4
	adds r2, #1
	cmp r2, #0x9f
	ble _080146FA
	ldr r0, [sp]
	asrs r1, r0, #0x10
	cmp r1, #0xff
	ble _08014742
	mov r2, sb
	ldrb r0, [r2, #0xe]
	cmp r0, #7
	bls _0801477C
_08014742:
	movs r2, #0
	adds r3, r1, #0
	movs r7, #0x80
	lsls r7, r7, #1
	lsls r5, r3, #0x10
	mov r0, sl
	orrs r5, r0
	adds r0, r3, r7
	lsls r4, r0, #0x10
	mov r1, sl
	orrs r4, r1
	adds r1, r6, #0
_0801475A:
	adds r0, r2, r3
	ands r0, r7
	cmp r0, #0
	bne _08014766
	str r5, [r1]
	b _08014774
_08014766:
	mov r6, sb
	ldrb r0, [r6, #0xe]
	cmp r0, #7
	bls _08014774
	cmp r3, #0
	ble _08014774
	str r4, [r1]
_08014774:
	adds r1, #4
	adds r2, #1
	cmp r2, #0x9f
	ble _0801475A
_0801477C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801478c
FUN_0801478c: @ 0x0801478C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrb r4, [r7, #0xe]
	cmp r4, #1
	beq _080147E0
	cmp r4, #1
	bgt _080147AE
	cmp r4, #0
	beq _080147B4
	b _08014856
_080147AE:
	cmp r4, #2
	beq _0801484A
	b _08014856
_080147B4:
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _08014864 @ =gVideoRegBuffer+4
	adds r2, r2, r0
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	orrs r0, r1
	movs r1, #0x44
	orrs r0, r1
	strh r0, [r2]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014868 @ =gBgMapOffsets
	str r4, [sp]
	movs r2, #0x5e
	movs r3, #0
	bl LoadBgMap
	strh r4, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080147E0:
	ldr r0, _0801486C @ =gOverworld
	ldr r1, _08014870 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #9
	bls _08014856
	mov r3, r8
	ldr r4, [r3, #8]
	lsrs r2, r5, #4
	lsls r2, r2, #1
	ldr r6, _08014864 @ =gVideoRegBuffer+4
	adds r2, r2, r6
	ldr r0, [r7, #0x64]
	ldr r3, _08014874 @ =0x00004046
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, [r4]
	adds r3, r3, r4
	ldr r5, [r4, #8]
	adds r5, r5, r4
	adds r0, r7, #0
	adds r0, #0x14
	adds r1, r7, #0
	adds r1, #0x34
	ldr r2, [r7, #0x5c]
	lsrs r2, r2, #4
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r4, [r2]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r4
	lsls r2, r2, #3
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r2, r2, r4
	str r5, [sp]
	ldrh r5, [r7, #0xc]
	lsls r5, r5, #2
	mov r4, r8
	adds r4, #0xc
	adds r4, r4, r5
	ldr r4, [r4]
	str r4, [sp, #4]
	bl ResetLayerGraphic
	ldr r0, _08014878 @ =0x80000001
	str r0, [r7, #0x40]
	str r0, [r7, #0x3c]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0801484A:
	ldr r0, _0801486C @ =gOverworld
	ldr r1, _0801487C @ =0x0002D03C
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	str r0, [r7, #0x4c]
_08014856:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014864: .4byte gVideoRegBuffer+4
_08014868: .4byte gBgMapOffsets
_0801486C: .4byte gOverworld
_08014870: .4byte 0x0002D024
_08014874: .4byte 0x00004046
_08014878: .4byte 0x80000001
_0801487C: .4byte 0x0002D03C

	thumb_func_start giantElevator_08014880
giantElevator_08014880: @ 0x08014880
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r4, _080148B8 @ =gOverworld
	ldr r3, _080148BC @ =0x0002D024
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #9
	bhi _080148CC
	ldr r1, [r2, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #2
	ldr r2, _080148C0 @ =gVideoRegBuffer+12
	adds r3, r1, r2
	ldr r5, _080148C4 @ =0x0002D050
	adds r0, r4, r5
	ldr r0, [r0]
	asrs r0, r0, #8
	strh r0, [r3]
	adds r2, #2
	adds r1, r1, r2
	ldr r2, _080148C8 @ =0x0002D054
	adds r0, r4, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	strh r0, [r1]
	b _080148D2
	.align 2, 0
_080148B8: .4byte gOverworld
_080148BC: .4byte 0x0002D024
_080148C0: .4byte gVideoRegBuffer+12
_080148C4: .4byte 0x0002D050
_080148C8: .4byte 0x0002D054
_080148CC:
	adds r0, r2, #0
	bl DrawGeneralStageLayer
_080148D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start giantElevator_080148d8
giantElevator_080148d8: @ 0x080148D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r8, r1
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	bne _08014946
	lsrs r2, r0, #0x14
	lsls r4, r2, #1
	ldr r3, _0801498C @ =gVideoRegBuffer+4
	adds r4, r4, r3
	ldr r0, [r6, #0x60]
	ldr r1, [r6, #0x64]
	orrs r0, r1
	ldr r5, _08014990 @ =0x00008044
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r4]
	lsls r2, r2, #2
	adds r3, #8
	adds r2, r2, r3
	str r7, [r2]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _08014994 @ =gBgMapOffsets
	str r7, [sp]
	adds r1, r5, #0
	movs r2, #0x5a
	movs r3, #0
	bl LoadBgMap
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, _08014998 @ =0x06000800
	adds r0, r0, r2
	str r7, [sp]
	adds r1, r5, #0
	movs r2, #0x5a
	movs r3, #0
	bl loadBgMap_08004248
	strh r7, [r6, #0x10]
	strh r7, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08014946:
	ldr r0, _0801499C @ =gOverworld
	ldr r5, _080149A0 @ =0x0002D025
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014960
	ldrh r1, [r6, #0x12]
	ldr r0, _080149A4 @ =0x000007FF
	cmp r1, r0
	bhi _08014960
	adds r0, r1, #0
	adds r0, #8
	strh r0, [r6, #0x12]
_08014960:
	ldrh r0, [r6, #0x12]
	lsrs r0, r0, #8
	ldrh r2, [r6, #0x10]
	adds r1, r0, r2
	strh r1, [r6, #0x10]
	ldrb r0, [r6, #0xe]
	adds r2, r0, #0
	cmp r2, #1
	bne _080149AC
	lsls r1, r1, #0x10
	ldr r0, _080149A8 @ =0x14FF0000
	cmp r1, r0
	bls _080149AC
	mov r5, r8
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014994 @ =gBgMapOffsets
	movs r2, #0
	str r2, [sp]
	movs r2, #0x5b
	b _08014A12
	.align 2, 0
_0801498C: .4byte gVideoRegBuffer+4
_08014990: .4byte 0x00008044
_08014994: .4byte gBgMapOffsets
_08014998: .4byte 0x06000800
_0801499C: .4byte gOverworld
_080149A0: .4byte 0x0002D025
_080149A4: .4byte 0x000007FF
_080149A8: .4byte 0x14FF0000
_080149AC:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _080149F4
	ldrh r1, [r6, #0x10]
	ldr r0, _080149E4 @ =0x000015FF
	cmp r1, r0
	bls _080149F4
	mov r1, r8
	lsrs r0, r1, #4
	lsls r0, r0, #1
	ldr r1, _080149E8 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, _080149EC @ =0x06000800
	adds r0, r0, r2
	ldr r1, _080149F0 @ =gBgMapOffsets
	movs r2, #0
	str r2, [sp]
	movs r2, #0x5d
	movs r3, #0
	bl loadBgMap_08004248
	b _08014A18
	.align 2, 0
_080149E4: .4byte 0x000015FF
_080149E8: .4byte gVideoRegBuffer+4
_080149EC: .4byte 0x06000800
_080149F0: .4byte gBgMapOffsets
_080149F4:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08014A1E
	ldrh r1, [r6, #0x10]
	ldr r0, _08014A2C @ =0x000016FF
	cmp r1, r0
	bls _08014A1E
	mov r5, r8
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014A30 @ =gBgMapOffsets
	movs r2, #0
	str r2, [sp]
	movs r2, #0x5d
_08014A12:
	movs r3, #0
	bl LoadBgMap
_08014A18:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08014A1E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014A2C: .4byte 0x000016FF
_08014A30: .4byte gBgMapOffsets

	thumb_func_start giantElevator_08014a34
giantElevator_08014a34: @ 0x08014A34
	push {r4, r5, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r3, _08014A5C @ =gVideoRegBuffer+12
	adds r4, r2, r3
	ldr r1, [r0, #0x34]
	ldr r5, _08014A60 @ =0xFFFFEBD8
	adds r1, r1, r5
	asrs r1, r1, #2
	strh r1, [r4]
	adds r3, #2
	adds r2, r2, r3
	ldrh r0, [r0, #0x10]
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014A5C: .4byte gVideoRegBuffer+12
_08014A60: .4byte 0xFFFFEBD8

	thumb_func_start giantElevator_08014a64
giantElevator_08014a64: @ 0x08014A64
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08014AAA
	lsrs r2, r0, #0x14
	lsls r3, r2, #1
	ldr r4, _08014AC4 @ =gVideoRegBuffer+4
	adds r3, r3, r4
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	orrs r0, r1
	movs r1, #0x44
	orrs r0, r1
	strh r0, [r3]
	lsls r2, r2, #2
	adds r4, #8
	adds r2, r2, r4
	str r6, [r2]
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014AC8 @ =gBgMapOffsets
	str r6, [sp]
	movs r2, #0x5c
	movs r3, #0
	bl LoadBgMap
	strh r6, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08014AAA:
	ldr r0, _08014ACC @ =gOverworld
	ldr r1, _08014AD0 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014ABC
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
_08014ABC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014AC4: .4byte gVideoRegBuffer+4
_08014AC8: .4byte gBgMapOffsets
_08014ACC: .4byte gOverworld
_08014AD0: .4byte 0x0002D025

	thumb_func_start giantElevator_08014ad4
giantElevator_08014ad4: @ 0x08014AD4
	push {r4, r5, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r3, _08014AFC @ =gVideoRegBuffer+12
	adds r4, r2, r3
	ldr r1, [r0, #0x34]
	ldr r5, _08014B00 @ =0xFFFFEBD8
	adds r1, r1, r5
	asrs r1, r1, #7
	strh r1, [r4]
	adds r3, #2
	adds r2, r2, r3
	ldrh r0, [r0, #0x10]
	lsrs r0, r0, #2
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014AFC: .4byte gVideoRegBuffer+12
_08014B00: .4byte 0xFFFFEBD8

	thumb_func_start FUN_08014b04
FUN_08014b04: @ 0x08014B04
	push {lr}
	ldr r2, _08014B20 @ =0x083458BC
	movs r0, #0xb4
	movs r1, #0x72
	bl ShiftMetatile
	ldr r2, _08014B24 @ =gCurStory
	ldrb r1, [r2, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0xa]
	pop {r0}
	bx r0
	.align 2, 0
_08014B20: .4byte 0x083458BC
_08014B24: .4byte gCurStory
