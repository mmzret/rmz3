	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080105e4
FUN_080105e4: @ 0x080105E4
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
	movs r0, #0xf0
	lsls r0, r0, #1
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
	bhi _0801062A
	cmp r5, #0x1e
	bhi _0801062A
	ldr r3, _08010650 @ =gOverworld
	ldr r1, _08010654 @ =0x0002D02C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08010660
_0801062A:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _08010658 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	ldr r3, _0801065C @ =0x020029E0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006ae0
	b _08010688
	.align 2, 0
_08010650: .4byte gOverworld
_08010654: .4byte 0x0002D02C
_08010658: .4byte gVideoRegBuffer+4
_0801065C: .4byte 0x020029E0
_08010660:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _080106AC @ =gVideoRegBuffer+4
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
_08010688:
	ldr r0, _080106B0 @ =gOverworld
	ldr r1, _080106B4 @ =0x0002D02C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r4, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	ldr r0, _080106B8 @ =gVideoRegBuffer+12
	adds r1, r1, r0
	adds r0, r6, #0
	bl UpdateBGOFS
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080106AC: .4byte gVideoRegBuffer+4
_080106B0: .4byte gOverworld
_080106B4: .4byte 0x0002D02C
_080106B8: .4byte gVideoRegBuffer+12

	thumb_func_start anatre_080106bc
anatre_080106bc: @ 0x080106BC
	push {r4, lr}
	ldr r0, _080106D8 @ =gOverworld
	ldr r1, _080106DC @ =0x0002D030
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, #0
	bne _080106D2
	movs r0, #0
	bl FUN_080cedc0
	str r0, [r4]
_080106D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080106D8: .4byte gOverworld
_080106DC: .4byte 0x0002D030

	thumb_func_start FUN_080106e0
FUN_080106e0: @ 0x080106E0
	push {r4, lr}
	ldr r0, _0801072C @ =gOverworld
	ldr r1, _08010730 @ =0x0002D030
	adds r4, r0, r1
	ldr r3, [r4]
	cmp r3, #0
	beq _08010726
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08010734 @ =gSolidFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	str r2, [r4]
_08010726:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801072C: .4byte gOverworld
_08010730: .4byte 0x0002D030
_08010734: .4byte gSolidFnTable

	thumb_func_start anatre_08010738
anatre_08010738: @ 0x08010738
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r6, r0, #0x10
	lsrs r0, r6, #0x10
	str r0, [sp, #0x1c]
	movs r1, #0
	mov sb, r1
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	bne _08010842
	lsrs r6, r6, #0x14
	lsls r6, r6, #1
	ldr r0, _080108BC @ =gVideoRegBuffer+4
	adds r6, r6, r0
	ldr r1, [r7, #0x64]
	ldr r2, _080108C0 @ =0x00004046
	adds r0, r2, #0
	orrs r1, r0
	strh r1, [r6]
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	mov r3, sb
	str r3, [sp, #0x14]
	add r0, sp, #0x14
	ldr r2, _080108C4 @ =0x01000400
	bl CpuFastSet
	ldr r0, [sp, #0x1c]
	lsls r5, r0, #0x18
	lsrs r5, r5, #0x18
	ldr r1, _080108C8 @ =gBgMapOffsets
	mov r8, r1
	mov r2, sb
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x6a
	movs r3, #0
	bl LoadBgMap
	mov r3, sb
	str r3, [sp]
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0x6b
	movs r3, #0x10
	bl LoadBgMap
	ldrh r0, [r6]
	ands r4, r0
	lsls r4, r4, #3
	ldr r5, _080108CC @ =0x06000800
	adds r4, r4, r5
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0x6c
	movs r3, #0
	bl loadBgMap_08004248
	ldr r2, _080108D0 @ =gWindowRegBuffer
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xff
	strb r0, [r2, #0xd]
	ldrb r1, [r2, #0xe]
	movs r0, #6
	orrs r0, r1
	movs r1, #0xf7
	ands r0, r1
	strb r0, [r2, #0xe]
	movs r3, #0
	ldr r5, _080108D4 @ =gOverworld+184360
	movs r4, #0
_080107EA:
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
	movs r1, #3
	ands r1, r2
	asrs r0, r0, #0x12
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r1, r5
	strb r4, [r1]
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r5
	str r4, [r0]
	adds r0, r2, #0
	adds r0, #0x15
	lsls r0, r0, #2
	adds r0, r0, r5
	str r4, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #9
	ble _080107EA
	movs r3, #0
	ldr r4, _080108D4 @ =gOverworld+184360
	movs r2, #0
_08010822:
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r4
	str r2, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08010822
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08010842:
	ldr r0, [r7, #0x34]
	lsls r0, r0, #8
	ldr r1, [r7, #0x2c]
	adds r0, r0, r1
	mov sl, r0
	ldr r0, [r7, #0x38]
	lsls r0, r0, #8
	ldr r1, [r7, #0x30]
	adds r0, r0, r1
	str r0, [sp, #0x20]
	movs r3, #0
	ldr r5, [sp, #0x1c]
	lsls r5, r5, #8
	str r5, [sp, #0x28]
	ldr r0, _080108D4 @ =gOverworld+184360
	mov r8, r0
_08010862:
	lsls r2, r3, #0x10
	asrs r3, r2, #0x10
	movs r1, #3
	ands r1, r3
	asrs r0, r2, #0x12
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	add r1, r8
	ldrb r0, [r1]
	adds r7, r2, #0
	cmp r0, #0
	beq _080108E0
	adds r0, r3, #7
	lsls r0, r0, #2
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r4]
	ldr r5, _080108D8 @ =0x00003FFF
	cmp r0, r5
	bgt _08010914
	ldr r6, _080108DC @ =gStageRun+288
	movs r0, #1
	adds r1, r6, #0
	bl AppendQuake
	ldr r0, [r4]
	adds r0, #0x80
	str r0, [r4]
	movs r2, #1
	mov sb, r2
	cmp r0, r5
	ble _08010914
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r4]
	movs r0, #3
	adds r1, r6, #0
	bl AppendQuake
	movs r0, #0xe2
	bl PlaySound
	b _08010914
	.align 2, 0
_080108BC: .4byte gVideoRegBuffer+4
_080108C0: .4byte 0x00004046
_080108C4: .4byte 0x01000400
_080108C8: .4byte gBgMapOffsets
_080108CC: .4byte 0x06000800
_080108D0: .4byte gWindowRegBuffer
_080108D4: .4byte gOverworld+184360
_080108D8: .4byte 0x00003FFF
_080108DC: .4byte gStageRun+288
_080108E0:
	adds r0, r3, #7
	lsls r0, r0, #2
	mov r3, r8
	adds r4, r0, r3
	ldr r0, [r4]
	cmp r0, #0
	beq _08010914
	ldr r5, _08010944 @ =gStageRun+288
	movs r0, #1
	adds r1, r5, #0
	bl AppendQuake
	ldr r0, [r4]
	subs r0, #0x40
	str r0, [r4]
	movs r1, #1
	mov sb, r1
	cmp r0, #0
	bne _08010914
	movs r0, #3
	adds r1, r5, #0
	bl AppendQuake
	movs r0, #0xe2
	bl PlaySound
_08010914:
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r7, r2
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08010862
	mov r3, sb
	cmp r3, #0
	beq _0801094C
	ldr r4, _08010948 @ =0x0000010D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _0801093A
	adds r0, r4, #0
	bl PlaySound
_0801093A:
	adds r0, r4, #0
	bl SetStageNoiseVolume
	b _0801095E
	.align 2, 0
_08010944: .4byte gStageRun+288
_08010948: .4byte 0x0000010D
_0801094C:
	ldr r4, _080109C8 @ =0x0000010D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _0801095E
	adds r0, r4, #0
	bl stopSound
_0801095E:
	movs r5, #0
	mov r8, r5
	ldr r0, _080109CC @ =0x08340134
	mov ip, r0
	ldr r7, _080109D0 @ =gOverworld+184360
	movs r1, #0xf0
	lsls r1, r1, #8
	add r1, sl
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r2, r2, r3
	mov sb, r2
_0801097A:
	mov r5, r8
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r1, r2, #4
	mov r3, ip
	adds r0, r1, r3
	ldr r6, [r0]
	str r6, [sp, #4]
	mov r0, ip
	adds r0, #4
	adds r0, r1, r0
	ldr r4, [r0]
	str r4, [sp, #8]
	mov r0, ip
	adds r0, #8
	adds r0, r1, r0
	ldr r5, [r0]
	str r5, [sp, #0xc]
	ldr r0, _080109D4 @ =0x08340140
	adds r1, r1, r0
	ldr r3, [r1]
	str r3, [sp, #0x10]
	lsls r0, r2, #1
	ldr r1, _080109D8 @ =0x083401D5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080109DC
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	subs r1, r4, r1
	str r1, [sp, #8]
	ldr r0, [r0]
	subs r0, r3, r0
	str r0, [sp, #0x10]
	b _08010A20
	.align 2, 0
_080109C8: .4byte 0x0000010D
_080109CC: .4byte 0x08340134
_080109D0: .4byte gOverworld+184360
_080109D4: .4byte 0x08340140
_080109D8: .4byte 0x083401D5
_080109DC:
	cmp r0, #1
	bne _080109F4
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r1, r4, r1
	str r1, [sp, #8]
	ldr r0, [r0]
	adds r0, r3, r0
	str r0, [sp, #0x10]
	b _08010A20
_080109F4:
	cmp r0, #2
	bne _08010A0A
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	subs r1, r6, r1
	str r1, [sp, #4]
	ldr r0, [r0]
	subs r0, r5, r0
	b _08010A1E
_08010A0A:
	cmp r0, #3
	bne _08010A20
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r1, r6, r1
	str r1, [sp, #4]
	ldr r0, [r0]
	adds r0, r5, r0
_08010A1E:
	str r0, [sp, #0xc]
_08010A20:
	ldr r6, [sp, #4]
	ldr r2, [sp, #0x24]
	cmp r2, r6
	ble _08010A3C
	ldr r0, [sp, #0xc]
	cmp sl, r0
	bge _08010A3C
	ldr r0, [sp, #8]
	cmp sb, r0
	ble _08010A3C
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x20]
	cmp r3, r0
	blt _08010A50
_08010A3C:
	mov r5, r8
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	mov r8, r2
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0801097A
_08010A50:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r5, r0, #0x10
	adds r7, r0, #0
	cmp r5, #0xa
	bne _08010A6C
	ldr r1, _08010A68 @ =gVideoRegBuffer
	ldrh r0, [r1]
	ldr r5, [sp, #0x28]
	bics r0, r5
	strh r0, [r1]
	b _08010B50
	.align 2, 0
_08010A68: .4byte gVideoRegBuffer
_08010A6C:
	ldr r0, [sp, #0x1c]
	lsrs r3, r0, #4
	lsls r3, r3, #2
	ldr r2, _08010AC4 @ =gVideoRegBuffer+12
	adds r4, r3, r2
	mov r0, sl
	subs r1, r0, r6
	asrs r1, r1, #8
	lsls r0, r5, #1
	ldr r5, _08010AC8 @ =0x083401D4
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #7
	adds r1, r1, r0
	strh r1, [r4]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x20]
	subs r0, r2, r1
	asrs r0, r0, #8
	strh r0, [r3]
	mov r3, sl
	subs r2, r6, r3
	lsls r2, r2, #8
	ldr r5, [sp, #0x20]
	subs r1, r1, r5
	lsls r1, r1, #8
	lsrs r5, r1, #0x10
	ldr r0, [sp, #0xc]
	subs r0, r0, r3
	lsls r0, r0, #8
	lsrs r1, r0, #0x10
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x20]
	subs r0, r0, r3
	lsls r0, r0, #8
	lsrs r4, r0, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08010ACC
	movs r6, #0
	b _08010AD2
	.align 2, 0
_08010AC4: .4byte gVideoRegBuffer+12
_08010AC8: .4byte 0x083401D4
_08010ACC:
	cmp r2, #0xef
	ble _08010AD2
	movs r6, #0xef
_08010AD2:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08010ADE
	movs r5, #0
	b _08010AE4
_08010ADE:
	cmp r0, #0x9f
	ble _08010AE4
	movs r5, #0x9f
_08010AE4:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08010AF0
	movs r1, #1
	b _08010AF6
_08010AF0:
	cmp r0, #0xf0
	ble _08010AF6
	movs r1, #0xf0
_08010AF6:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08010B02
	movs r4, #1
	b _08010B08
_08010B02:
	cmp r0, #0xa0
	ble _08010B08
	movs r4, #0xa0
_08010B08:
	ldr r3, _08010BC0 @ =gWindowRegBuffer
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xff
	ands r1, r2
	lsls r0, r6, #0x10
	asrs r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #6]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ands r0, r2
	lsls r1, r5, #0x10
	asrs r1, r1, #8
	orrs r0, r1
	strh r0, [r3, #0xa]
	movs r5, #0x80
	lsls r5, r5, #0x18
	adds r0, r7, r5
	lsrs r0, r0, #0x10
	ldr r1, _08010BC4 @ =0x00002001
	asrs r2, r7, #0xf
	ldr r3, _08010BC8 @ =0x083401D4
	adds r2, r2, r3
	ldrb r3, [r2]
	lsls r3, r3, #3
	ldr r2, _08010BCC @ =0x083401E8
	adds r3, r3, r2
	add r2, sp, #4
	bl AppendHazard
	ldr r1, _08010BD0 @ =gVideoRegBuffer
	ldrh r0, [r1]
	ldr r5, [sp, #0x28]
	orrs r5, r0
	strh r5, [r1]
_08010B50:
	movs r3, #0
	ldr r6, _08010BD4 @ =gOverworld+184360
_08010B54:
	lsls r0, r3, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x11
	lsls r0, r0, #2
	adds r5, r0, r6
	ldr r0, [r5]
	cmp r0, #0
	bne _08010B72
	lsls r0, r4, #3
	ldr r1, _08010BD8 @ =0x08340200
	adds r0, r0, r1
	bl FUN_080deb10
	str r0, [r5]
_08010B72:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08010B54
	movs r3, #0
	ldr r6, _08010BD4 @ =gOverworld+184360
_08010B82:
	lsls r0, r3, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x15
	lsls r0, r0, #2
	adds r5, r0, r6
	ldr r0, [r5]
	cmp r0, #0
	bne _08010BA4
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r4, #3
	ldr r2, _08010BDC @ =0x08340220
	adds r1, r1, r2
	bl FUN_080deb6c
	str r0, [r5]
_08010BA4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08010B82
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010BC0: .4byte gWindowRegBuffer
_08010BC4: .4byte 0x00002001
_08010BC8: .4byte 0x083401D4
_08010BCC: .4byte 0x083401E8
_08010BD0: .4byte gVideoRegBuffer
_08010BD4: .4byte gOverworld+184360
_08010BD8: .4byte 0x08340200
_08010BDC: .4byte 0x08340220

	thumb_func_start FUN_08010be0
FUN_08010be0: @ 0x08010BE0
	push {r4, r5, r6, lr}
	ldr r1, _08010CBC @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _08010CC0 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	movs r1, #0
	ldr r6, _08010CC4 @ =gOverworld+184360
	movs r4, #0
	ldr r5, _08010CC8 @ =gSolidFnTable
_08010BFC:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	cmp r2, #0
	beq _08010C40
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08010C40:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08010BFC
	movs r1, #0
	ldr r6, _08010CC4 @ =gOverworld+184360
	movs r4, #0
	ldr r5, _08010CC8 @ =gSolidFnTable
_08010C54:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x15
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	cmp r2, #0
	beq _08010C98
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08010C98:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08010C54
	ldr r4, _08010CCC @ =0x0000010D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08010CB6
	adds r0, r4, #0
	bl stopSound
_08010CB6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010CBC: .4byte gWindowRegBuffer
_08010CC0: .4byte 0x0000BFFF
_08010CC4: .4byte gOverworld+184360
_08010CC8: .4byte gSolidFnTable
_08010CCC: .4byte 0x0000010D

	thumb_func_start FUN_08010cd0
FUN_08010cd0: @ 0x08010CD0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _08010D08 @ =0x000EFFFF
	cmp r4, r0
	bgt _08010D18
	ldr r0, _08010D0C @ =0xFFFEC000
	adds r1, r3, r0
	ldr r0, _08010D10 @ =0x00013FFF
	cmp r1, r0
	bhi _08010D18
	ldr r2, _08010D14 @ =gOverworld
	movs r5, #0xfc
	lsls r5, r5, #3
	adds r2, r2, r5
	ldrh r1, [r2]
	movs r5, #0xf0
	lsls r5, r5, #9
	adds r0, r3, r5
	asrs r0, r0, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _08010D1A
	.align 2, 0
_08010D08: .4byte 0x000EFFFF
_08010D0C: .4byte 0xFFFEC000
_08010D10: .4byte 0x00013FFF
_08010D14: .4byte gOverworld
_08010D18:
	movs r0, #0
_08010D1A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010d20
FUN_08010d20: @ 0x08010D20
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08010D5C @ =0xFFFEC000
	adds r1, r2, r0
	ldr r0, _08010D60 @ =0x00013FFF
	cmp r1, r0
	bhi _08010D54
	ldr r4, _08010D64 @ =gOverworld
	ldr r0, _08010D68 @ =0x0002D02C
	adds r1, r4, r0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	asrs r0, r3, #0xc
	movs r3, #0xf0
	lsls r3, r3, #9
	adds r1, r2, r3
	asrs r1, r1, #0xc
	ldr r2, _08010D6C @ =0x08340270
	bl PatchMetatileMap
	movs r0, #0xb0
	lsls r0, r0, #0xa
	adds r4, r4, r0
	strh r5, [r4]
_08010D54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010D5C: .4byte 0xFFFEC000
_08010D60: .4byte 0x00013FFF
_08010D64: .4byte gOverworld
_08010D68: .4byte 0x0002D02C
_08010D6C: .4byte 0x08340270

	thumb_func_start FUN_08010d70
FUN_08010d70: @ 0x08010D70
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _08010DC0 @ =0x001A3FFF
	cmp r3, r0
	ble _08010DD0
	ldr r0, _08010DC4 @ =0xFFFF6000
	adds r1, r5, r0
	ldr r0, _08010DC8 @ =0x00013FFF
	cmp r1, r0
	bhi _08010DD0
	ldr r2, _08010DCC @ =gOverworld
	movs r6, #0xfc
	lsls r6, r6, #3
	adds r2, r2, r6
	ldrh r4, [r2]
	asrs r0, r5, #0xc
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r3, r3, #0xc
	adds r1, r1, r3
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r6, #0xa0
	lsls r6, r6, #0xa
	adds r0, r5, r6
	asrs r0, r0, #0xc
	muls r0, r4, r0
	adds r0, r0, r3
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _08010DD2
	.align 2, 0
_08010DC0: .4byte 0x001A3FFF
_08010DC4: .4byte 0xFFFF6000
_08010DC8: .4byte 0x00013FFF
_08010DCC: .4byte gOverworld
_08010DD0:
	movs r0, #0
_08010DD2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010dd8
FUN_08010dd8: @ 0x08010DD8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08010E96
	ldr r0, _08010E18 @ =0x001D0FFF
	cmp r4, r0
	ble _08010E4C
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r5, r0
	ble _08010E1C
	asrs r0, r4, #0xc
	subs r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r4, r1, #1
	asrs r0, r5, #0xc
	adds r0, #2
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r5, r1, #2
	b _08010E3C
	.align 2, 0
_08010E18: .4byte 0x001D0FFF
_08010E1C:
	asrs r0, r4, #0xc
	subs r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r4, r1, #1
	asrs r0, r5, #0xc
	adds r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r5, r1, #1
_08010E3C:
	ldr r2, _08010E48 @ =0x08340278
	adds r0, r4, #0
	adds r1, r5, #0
	bl PatchMetatileMap
	b _08010E7C
	.align 2, 0
_08010E48: .4byte 0x08340278
_08010E4C:
	ldr r0, _08010E9C @ =0x001B2FFF
	cmp r4, r0
	ble _08010E7C
	asrs r0, r4, #0xc
	subs r0, #2
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r4, r1, #2
	asrs r0, r5, #0xc
	subs r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r5, r1, #1
	ldr r2, _08010EA0 @ =0x08340278
	adds r0, r4, #0
	adds r1, r5, #0
	bl PatchMetatileMap
_08010E7C:
	movs r0, #0x41
	bl isSoundPlaying
	cmp r0, #0
	bne _08010E8C
	movs r0, #0x41
	bl PlaySound
_08010E8C:
	lsls r1, r4, #0xc
	lsls r2, r5, #0xc
	movs r0, #0
	bl FUN_080cee14
_08010E96:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010E9C: .4byte 0x001B2FFF
_08010EA0: .4byte 0x08340278
