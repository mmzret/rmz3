	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start missileFactory_0800f2ec
missileFactory_0800f2ec: @ 0x0800F2EC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #6
	bls _0800F2FA
	b _0800F532
_0800F2FA:
	lsls r0, r0, #2
	ldr r1, _0800F304 @ =_0800F308
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800F304: .4byte _0800F308
_0800F308: @ jump table
	.4byte _0800F324 @ case 0
	.4byte _0800F360 @ case 1
	.4byte _0800F3E6 @ case 2
	.4byte _0800F410 @ case 3
	.4byte _0800F4A8 @ case 4
	.4byte _0800F4CC @ case 5
	.4byte _0800F3DC @ case 6
_0800F324:
	ldr r4, _0800F350 @ =gOverworld
	ldr r1, _0800F354 @ =0x0002D024
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0800F332
	b _0800F532
_0800F332:
	movs r0, #0xd0
	movs r1, #0
	bl StartPaletteAnimation
	ldr r2, _0800F358 @ =0x0002D025
	adds r1, r4, r2
	movs r4, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0800F35C @ =0x00000121
	bl PlaySound
	strh r4, [r6, #0x10]
	b _0800F52C
	.align 2, 0
_0800F350: .4byte gOverworld
_0800F354: .4byte 0x0002D024
_0800F358: .4byte 0x0002D025
_0800F35C: .4byte 0x00000121
_0800F360:
	movs r0, #0xd0
	bl StepPaletteAnimation
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0800F378
	movs r0, #6
	strh r0, [r6, #0x10]
_0800F378:
	ldrh r0, [r6, #0x10]
	movs r1, #3
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xd
	ldr r0, _0800F3CC @ =0x0833EDFC
	adds r2, r2, r0
	movs r0, #0xf0
	movs r1, #0x65
	bl ShiftMetatile
	ldrh r0, [r6, #0x10]
	movs r1, #3
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xd
	ldr r0, _0800F3D0 @ =0x0833EE1C
	adds r2, r2, r0
	movs r0, #0xeb
	movs r1, #0x65
	bl ShiftMetatile
	ldr r0, _0800F3D4 @ =gOverworld
	ldr r1, _0800F3D8 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800F3BA
	b _0800F532
_0800F3BA:
	movs r0, #0xd0
	bl RemovePaletteAnimation
	movs r0, #0xd5
	movs r1, #0
	bl StartPaletteAnimation
	movs r0, #6
	b _0800F530
	.align 2, 0
_0800F3CC: .4byte 0x0833EDFC
_0800F3D0: .4byte 0x0833EE1C
_0800F3D4: .4byte gOverworld
_0800F3D8: .4byte 0x0002D025
_0800F3DC:
	movs r0, #0xd5
	bl StepPaletteAnimation
	movs r0, #2
	b _0800F530
_0800F3E6:
	movs r0, #0xd5
	bl RemovePaletteAnimation
	ldr r0, _0800F408 @ =gOverworld
	ldr r2, _0800F40C @ =0x0002D025
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800F3FA
	b _0800F532
_0800F3FA:
	movs r0, #0xcf
	movs r1, #0
	bl StartPaletteAnimation
	movs r0, #0
	strh r0, [r6, #0x10]
	b _0800F52C
	.align 2, 0
_0800F408: .4byte gOverworld
_0800F40C: .4byte 0x0002D025
_0800F410:
	movs r0, #0xcf
	bl StepPaletteAnimation
	ldrh r0, [r6, #0x10]
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800F42C
	movs r0, #0x90
	lsls r0, r0, #1
	bl PlaySound
_0800F42C:
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	ldr r7, _0800F498 @ =gOverworld
	ldr r0, _0800F49C @ =0x0002D025
	adds r5, r7, r0
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x10
	lsls r4, r0, #4
	subs r4, r4, r0
	ldrh r0, [r6, #0x10]
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xd
	ldr r0, _0800F4A0 @ =0x0833EDE4
	adds r2, r2, r0
	adds r0, r4, #0
	movs r1, #0x65
	bl ShiftMetatile
	ldrh r0, [r6, #0x10]
	cmp r0, #0x19
	bls _0800F532
	ldr r0, [r6, #0x34]
	lsls r0, r0, #8
	str r0, [sp]
	ldr r0, [r6, #0x38]
	lsls r0, r0, #8
	str r0, [sp, #4]
	movs r0, #0xcf
	bl RemovePaletteAnimation
	ldrb r0, [r5]
	adds r0, #4
	ldr r2, _0800F4A4 @ =0x0002D024
	adds r1, r7, r2
	strb r0, [r1]
	movs r0, #0x10
	mov r1, sp
	bl AppendQuake
	movs r0, #6
	strh r0, [r6, #0x10]
	b _0800F52C
	.align 2, 0
_0800F498: .4byte gOverworld
_0800F49C: .4byte 0x0002D025
_0800F4A0: .4byte 0x0833EDE4
_0800F4A4: .4byte 0x0002D024
_0800F4A8:
	ldrh r0, [r6, #0x10]
	subs r0, #1
	strh r0, [r6, #0x10]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0800F532
	ldr r0, _0800F4C8 @ =0x00000121
	bl PlaySound
	movs r0, #0xd0
	movs r1, #0
	bl StartPaletteAnimation
	strh r4, [r6, #0x10]
	b _0800F52C
	.align 2, 0
_0800F4C8: .4byte 0x00000121
_0800F4CC:
	movs r0, #0xd0
	bl StepPaletteAnimation
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0800F4E4
	movs r0, #6
	strh r0, [r6, #0x10]
_0800F4E4:
	ldr r7, _0800F53C @ =gOverworld
	ldr r0, _0800F540 @ =0x0002D025
	adds r5, r7, r0
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x10
	lsls r4, r0, #4
	subs r4, r4, r0
	ldrh r0, [r6, #0x10]
	movs r1, #3
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xd
	ldr r0, _0800F544 @ =0x0833EDFC
	adds r2, r2, r0
	adds r0, r4, #0
	movs r1, #0x65
	bl ShiftMetatile
	ldrb r0, [r5]
	cmp r0, #0
	bne _0800F532
	movs r0, #0xd0
	bl RemovePaletteAnimation
	movs r0, #0xd5
	movs r1, #0
	bl StartPaletteAnimation
	ldr r2, _0800F548 @ =0x0002D024
	adds r1, r7, r2
	movs r0, #4
	strb r0, [r1]
_0800F52C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
_0800F530:
	strb r0, [r6, #0xe]
_0800F532:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F53C: .4byte gOverworld
_0800F540: .4byte 0x0002D025
_0800F544: .4byte 0x0833EDFC
_0800F548: .4byte 0x0002D024

