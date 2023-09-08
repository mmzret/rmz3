	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08011140
FUN_08011140: @ 0x08011140
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0801116E
	ldr r1, [r3, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #1
	ldr r0, _08011184 @ =gVideoRegBuffer+4
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08011188 @ =0x0000FFFC
	ands r0, r2
	strh r0, [r1]
	ldr r1, _0801118C @ =gBlendRegBuffer
	ldr r0, _08011190 @ =0x00003B44
	strh r0, [r1]
	ldr r0, _08011194 @ =0x00000C04
	strh r0, [r1, #2]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0801116E:
	ldr r1, [r3, #0x34]
	ldr r0, _08011198 @ =0x0000151F
	cmp r1, r0
	bgt _080111A4
	ldr r0, _0801119C @ =gOverworld
	ldr r1, _080111A0 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xa
	b _080111AE
	.align 2, 0
_08011184: .4byte gVideoRegBuffer+4
_08011188: .4byte 0x0000FFFC
_0801118C: .4byte gBlendRegBuffer
_08011190: .4byte 0x00003B44
_08011194: .4byte 0x00000C04
_08011198: .4byte 0x0000151F
_0801119C: .4byte gOverworld
_080111A0: .4byte 0x0002C00C
_080111A4:
	ldr r0, _080111B4 @ =gOverworld
	ldr r1, _080111B8 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
_080111AE:
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080111B4: .4byte gOverworld
_080111B8: .4byte 0x0002C00C

	thumb_func_start FUN_080111bc
FUN_080111bc: @ 0x080111BC
	ldr r1, _080111D0 @ =gBlendRegBuffer
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080111D4 @ =gOverworld
	ldr r1, _080111D8 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	str r1, [r0]
	bx lr
	.align 2, 0
_080111D0: .4byte gBlendRegBuffer
_080111D4: .4byte gOverworld
_080111D8: .4byte 0x0002C00C

	thumb_func_start icebase_080111dc
icebase_080111dc: @ 0x080111DC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	bne _08011248
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _08011250 @ =gVideoRegBuffer+4
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r6, _08011254 @ =0x00008044
	adds r2, r6, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r4, [r0]
	ldr r0, _08011258 @ =0x0852239C
	ldr r0, [r0]
	ldr r2, _0801125C @ =0x085223A4
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _08011260 @ =0x085223A0
	ldr r0, [r0]
	ldr r1, _08011264 @ =0x085223A8
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _08011268 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08011248:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011250: .4byte gVideoRegBuffer+4
_08011254: .4byte 0x00008044
_08011258: .4byte 0x0852239C
_0801125C: .4byte 0x085223A4
_08011260: .4byte 0x085223A0
_08011264: .4byte 0x085223A8
_08011268: .4byte 0x06000800

	thumb_func_start FUN_0801126c
FUN_0801126c: @ 0x0801126C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r7, r0, #0
	cmp r7, #0
	bne _08011286
	b _080113B8
_08011286:
	ldr r2, _080113C4 @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080113C8 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080113CC @ =0xA6600001
	str r0, [r1]
	mov r1, sb
	ldr r0, [r1, #0x34]
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sb
	ldr r0, [r1, #0x38]
	subs r0, #0xe0
	movs r1, #3
	bl __divsi3
	adds r0, #1
	movs r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x8b
	bgt _080112E4
	adds r4, r7, #0
	adds r3, r0, #0
	lsls r1, r3, #0x10
	mov r0, r8
	orrs r1, r0
_080112D6:
	stm r4!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	bgt _080112E4
	adds r0, r3, r2
	cmp r0, #0x8b
	ble _080112D6
_080112E4:
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r1, #0x38]
	ldr r1, _080113D0 @ =0xFFFFFEA0
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r2, #0x9f
	bgt _08011352
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r2
	adds r5, r0, #0
	cmp r1, #0x8f
	bgt _0801132C
	adds r4, r3, #0
	lsls r0, r2, #0x10
	movs r1, #0x90
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	adds r3, r0, r7
	ldr r6, _080113D4 @ =0xFFFF0000
_0801131C:
	stm r3!, {r1}
	adds r1, r1, r6
	adds r2, #1
	cmp r2, #0x9f
	bgt _08011352
	adds r0, r4, r2
	cmp r0, #0x8f
	ble _0801131C
_0801132C:
	cmp r2, #0x9f
	bgt _08011352
	asrs r1, r5, #0x10
	adds r0, r1, r2
	cmp r0, #0xe0
	bgt _08011352
	lsls r0, r2, #2
	adds r4, r0, r7
	adds r3, r1, #0
	lsls r1, r3, #0x10
	mov r0, r8
	orrs r1, r0
_08011344:
	stm r4!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	bgt _08011352
	adds r0, r3, r2
	cmp r0, #0xe0
	ble _08011344
_08011352:
	mov r0, sb
	ldr r1, [r0, #0x34]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r0, sb
	ldr r1, [r0, #0x38]
	ldr r0, _080113D8 @ =0xFFFFFE20
	adds r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r2, #0x9f
	bgt _080113B8
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r2
	adds r5, r0, #0
	cmp r1, #0xdf
	bgt _080113A4
	adds r4, r3, #0
	lsls r0, r2, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	adds r3, r0, r7
	ldr r6, _080113D4 @ =0xFFFF0000
_08011394:
	stm r3!, {r1}
	adds r1, r1, r6
	adds r2, #1
	cmp r2, #0x9f
	bgt _080113B8
	adds r0, r4, r2
	cmp r0, #0xdf
	ble _08011394
_080113A4:
	cmp r2, #0x9f
	bgt _080113B8
	mov r1, r8
	orrs r1, r5
	lsls r0, r2, #2
	adds r0, r0, r7
_080113B0:
	stm r0!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	ble _080113B0
_080113B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080113C4: .4byte gIntrManager
_080113C8: .4byte 0x0400001C
_080113CC: .4byte 0xA6600001
_080113D0: .4byte 0xFFFFFEA0
_080113D4: .4byte 0xFFFF0000
_080113D8: .4byte 0xFFFFFE20

	thumb_func_start FUN_080113dc
FUN_080113dc: @ 0x080113DC
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	bne _080113F2
	movs r0, #0x80
	str r0, [r2, #0x44]
	adds r0, #0x80
	str r0, [r2, #0x48]
	adds r0, r1, #1
	strb r0, [r2, #0xe]
_080113F2:
	ldr r1, [r2, #0x34]
	ldr r0, _08011400 @ =0x00001C1F
	cmp r1, r0
	bgt _08011408
	ldr r0, _08011404 @ =0x00000CA8
	b _0801140A
	.align 2, 0
_08011400: .4byte 0x00001C1F
_08011404: .4byte 0x00000CA8
_08011408:
	ldr r0, _08011410 @ =0x00000E88
_0801140A:
	str r0, [r2, #0x4c]
	pop {r0}
	bx r0
	.align 2, 0
_08011410: .4byte 0x00000E88

	thumb_func_start FUN_08011414
FUN_08011414: @ 0x08011414
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	adds r1, r3, #0
	cmp r1, #0
	bne _0801142E
	movs r0, #0x40
	str r0, [r2, #0x44]
	adds r0, #0xc0
	str r0, [r2, #0x48]
	strh r1, [r2, #0x10]
	adds r0, r3, #1
	strb r0, [r2, #0xe]
_0801142E:
	ldr r1, [r2, #0x34]
	ldr r0, _0801143C @ =0x00001C1F
	cmp r1, r0
	bgt _08011444
	ldr r0, _08011440 @ =0x000012FC
	b _08011446
	.align 2, 0
_0801143C: .4byte 0x00001C1F
_08011440: .4byte 0x000012FC
_08011444:
	ldr r0, _08011460 @ =0x000015CC
_08011446:
	str r0, [r2, #0x4c]
	ldrh r0, [r2, #0x10]
	adds r0, #1
	strh r0, [r2, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0801145A
	movs r0, #0
	strh r0, [r2, #0x10]
_0801145A:
	pop {r0}
	bx r0
	.align 2, 0
_08011460: .4byte 0x000015CC

	thumb_func_start FUN_08011464
FUN_08011464: @ 0x08011464
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	mov r8, r1
	ldr r6, _080114C8 @ =gStageTilesetOffsets+(18*4)
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _080114CC @ =0x08704A20
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
	adds r0, r4, #0
	mov r1, r8
	bl DrawGeneralStageLayer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080114C8: .4byte gStageTilesetOffsets+(18*4)
_080114CC: .4byte 0x08704A20

	thumb_func_start icebase_080114d0
icebase_080114d0: @ 0x080114D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08011528
	ldr r1, [r5, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r4, r1, #1
	ldr r3, _08011530 @ =gVideoRegBuffer+4
	adds r4, r4, r3
	ldr r0, [r5, #0x64]
	movs r2, #0x45
	orrs r0, r2
	strh r0, [r4]
	lsls r1, r1, #2
	adds r0, r3, #0
	adds r0, #8
	adds r1, r1, r0
	str r6, [r1]
	subs r3, #4
	ldrh r1, [r3]
	ldr r0, _08011534 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _08011538 @ =0x085223A4
	ldr r0, [r0]
	ldr r1, _0801153C @ =0x085223AC
	adds r0, r0, r1
	ldrh r2, [r4]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08011528:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011530: .4byte gVideoRegBuffer+4
_08011534: .4byte 0x0000DBFF
_08011538: .4byte 0x085223A4
_0801153C: .4byte 0x085223AC
