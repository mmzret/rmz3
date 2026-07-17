	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

