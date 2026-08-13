	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start desert_0800ff98
desert_0800ff98: @ 0x0800FF98
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r3, [r6, #0xe]
	cmp r3, #0
	bne _0801001E
	ldr r4, [r6, #0x5c]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x14
	lsls r2, r4, #1
	ldr r5, _08010024 @ =gVideoRegBuffer+4
	adds r2, r2, r5
	ldr r1, [r6, #0x60]
	ldr r0, [r6, #0x64]
	orrs r1, r0
	movs r0, #0x44
	orrs r1, r0
	strh r1, [r2]
	lsls r4, r4, #2
	adds r0, r5, #0
	adds r0, #8
	adds r0, r4, r0
	str r3, [r0]
	ldr r0, _08010028 @ =0x08522398
	ldr r0, [r0]
	ldr r2, _0801002C @ =0x085223A0
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldr r1, _08010030 @ =gBlendRegBuffer
	ldr r0, _08010034 @ =0x00003D42
	strh r0, [r1]
	ldr r2, _08010038 @ =gWindowRegBuffer
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xff
	strb r0, [r2, #0xd]
	ldrb r1, [r2, #0xe]
	movs r0, #0xc
	orrs r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xe]
	movs r0, #0xff
	strh r0, [r2, #6]
	adds r5, #0xa
	adds r4, r4, r5
	ldr r1, _0801003C @ =0x0000FF80
	adds r0, r1, #0
	strh r0, [r4]
	ldr r0, _08010040 @ =0x000080A0
	strh r0, [r2, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0801001E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010024: .4byte gVideoRegBuffer+4
_08010028: .4byte 0x08522398
_0801002C: .4byte 0x085223A0
_08010030: .4byte gBlendRegBuffer
_08010034: .4byte 0x00003D42
_08010038: .4byte gWindowRegBuffer
_0801003C: .4byte 0x0000FF80
_08010040: .4byte 0x000080A0

	thumb_func_start FUN_08010044
FUN_08010044: @ 0x08010044
	push {r4, r5, r6, r7, lr}
	ldr r1, [r0, #0x5c]
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r7, #0x20
	ldr r0, [r0, #0x38]
	ldr r2, _08010094 @ =0xFFFFFE20
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsrs r1, r1, #0x14
	lsls r4, r1, #2
	ldr r2, _08010098 @ =gVideoRegBuffer+12
	adds r3, r4, r2
	movs r0, #0
	strh r0, [r3]
	adds r0, r2, #2
	adds r4, r4, r0
	strh r5, [r4]
	lsls r1, r1, #1
	subs r2, #8
	adds r2, r1, r2
	ldrh r1, [r2]
	ldr r3, _0801009C @ =0x0000FFFC
	adds r0, r3, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080100A0 @ =gOverworld
	ldr r1, _080100A4 @ =0x0002D02A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080100A8
	ldrh r0, [r4]
	subs r0, #0x80
	strh r0, [r4]
	b _080100D8
	.align 2, 0
_08010094: .4byte 0xFFFFFE20
_08010098: .4byte gVideoRegBuffer+12
_0801009C: .4byte 0x0000FFFC
_080100A0: .4byte gOverworld
_080100A4: .4byte 0x0002D02A
_080100A8:
	cmp r0, #1
	bne _080100B6
	ldrh r0, [r4]
	subs r0, #0x40
	strh r0, [r4]
	movs r7, #0x40
	b _080100D8
_080100B6:
	cmp r0, #2
	bne _080100C2
	ldrh r0, [r4]
	subs r0, #0x20
	strh r0, [r4]
	b _080100D8
_080100C2:
	cmp r0, #4
	bne _080100D8
	ldrh r0, [r4]
	adds r0, #0x20
	strh r0, [r4]
	ldrh r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
_080100D8:
	movs r3, #0xa0
	subs r1, r3, r7
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x9f
	ble _080100FC
	ldr r2, _080100F8 @ =gVideoRegBuffer
	lsls r1, r6, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	b _08010110
	.align 2, 0
_080100F8: .4byte gVideoRegBuffer
_080100FC:
	ldr r2, _08010118 @ =gVideoRegBuffer
	lsls r0, r6, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0801011C @ =gWindowRegBuffer
	lsls r0, r5, #0x10
	asrs r0, r0, #8
	orrs r0, r3
	strh r0, [r1, #0xa]
_08010110:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010118: .4byte gVideoRegBuffer
_0801011C: .4byte gWindowRegBuffer
