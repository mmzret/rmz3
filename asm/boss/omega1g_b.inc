	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805b270
FUN_0805b270: @ 0x0805B270
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0805B2F4
	cmp r0, #1
	bgt _0805B284
	cmp r0, #0
	beq _0805B28A
	b _0805B352
_0805B284:
	cmp r0, #2
	beq _0805B32C
	b _0805B352
_0805B28A:
	ldr r3, _0805B320 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0805B2AC
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0805B2AC
	ldr r0, _0805B324 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805B2AC:
	movs r0, #0xe8
	bl PlaySound
	movs r0, #0xb
	bl RemovePaletteAnimation
	movs r0, #0x66
	bl RemovePaletteAnimation
	movs r0, #0x67
	bl RemovePaletteAnimation
	ldr r0, _0805B328 @ =0x0000010F
	bl RemovePaletteAnimation
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B2F4:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B352
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B352
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805B352
	.align 2, 0
_0805B320: .4byte gStageRun
_0805B324: .4byte 0x0000FFFE
_0805B328: .4byte 0x0000010F
_0805B32C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805B352
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805B352:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b358
FUN_0805b358: @ 0x0805B358
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _0805B382
	cmp r1, #1
	bgt _0805B36C
	cmp r1, #0
	beq _0805B372
	b _0805B408
_0805B36C:
	cmp r1, #2
	beq _0805B3EC
	b _0805B408
_0805B372:
	movs r0, #0xb4
	strb r0, [r4, #0x12]
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B382:
	ldr r0, [r4, #0x60]
	adds r0, #8
	str r0, [r4, #0x60]
	movs r1, #0x90
	lsls r1, r1, #1
	cmp r0, r1
	ble _0805B392
	str r1, [r4, #0x60]
_0805B392:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805B3C8
	ldr r2, _0805B3E0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805B3E4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805B3E8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	subs r0, #3
	lsls r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x54]
_0805B3C8:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B3D8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B408
_0805B3D8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805B408
	.align 2, 0
_0805B3E0: .4byte RNG_0202f388
_0805B3E4: .4byte 0x000343FD
_0805B3E8: .4byte 0x00269EC3
_0805B3EC:
	ldr r2, _0805B410 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	movs r3, #0
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _0805B414 @ =gOverworld
	ldr r1, _0805B418 @ =0x0002D025
	adds r0, r0, r1
	strb r3, [r0]
_0805B408:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805B410: .4byte gStageRun
_0805B414: .4byte gOverworld
_0805B418: .4byte 0x0002D025

