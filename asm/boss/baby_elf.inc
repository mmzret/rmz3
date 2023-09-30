	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08045b68
FUN_08045b68: @ 0x08045B68
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08045BBC
	adds r5, r4, #0
	adds r5, #0xd0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08045B82
	cmp r0, #1
	beq _08045BA4
	b _08045BBC
_08045B82:
	adds r0, r4, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045BBC
	movs r1, #0xc8
	lsls r1, r1, #2
	movs r0, #0x19
	bl LoadBlink
	movs r0, #0x19
	bl UpdateBlinkMotionState
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08045BBC
_08045BA4:
	movs r0, #0x19
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	adds r0, #0xcf
	ldrb r4, [r0]
	cmp r4, #0
	bne _08045BBC
	movs r0, #0x19
	bl ClearBlink
	strb r4, [r5]
_08045BBC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start babyelf_08045bc4
babyelf_08045bc4: @ 0x08045BC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	ldr r0, [r0, #0x2c]
	mov sb, r0
	movs r7, #0
	mov r0, ip
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2f
	bgt _08045BE2
	movs r7, #1
_08045BE2:
	mov r2, ip
	ldrb r0, [r2, #0x11]
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r4, ip
	adds r4, #0xcd
	ldr r6, _08045BFC @ =RNG_0202f388
	mov r5, ip
	adds r5, #0xcc
	ldr r0, _08045C00 @ =0x083626D4
	mov r8, r0
	b _08045C0A
	.align 2, 0
_08045BFC: .4byte RNG_0202f388
_08045C00: .4byte 0x083626D4
_08045C04:
	ldrb r0, [r4]
	cmp r0, #1
	bls _08045C2E
_08045C0A:
	ldr r1, [r6]
	ldr r0, _08045C40 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08045C44 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r3, r0, #0x11
	movs r0, #0xf
	ands r3, r0
	lsls r2, r7, #4
	adds r0, r3, r2
	add r0, r8
	ldrb r1, [r5]
	ldrb r0, [r0]
	cmp r1, r0
	beq _08045C04
_08045C2E:
	adds r0, r3, r2
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r5]
	cmp r0, r1
	bne _08045C48
	ldrb r0, [r4]
	adds r0, #1
	b _08045C4C
	.align 2, 0
_08045C40: .4byte 0x000343FD
_08045C44: .4byte 0x00269EC3
_08045C48:
	movs r0, #0
	strb r1, [r5]
_08045C4C:
	strb r0, [r4]
	adds r0, r3, r2
	add r0, r8
	ldrb r1, [r0]
	cmp r1, #1
	beq _08045C78
	mov r2, ip
	strb r1, [r2, #0xd]
	ldrb r0, [r0]
	cmp r0, #5
	bne _08045C6A
	movs r0, #6
	mov r1, sb
	strb r0, [r1, #0xd]
	b _08045C6E
_08045C6A:
	mov r2, sb
	strb r0, [r2, #0xd]
_08045C6E:
	movs r0, #0
	mov r1, ip
	strb r0, [r1, #0xe]
	mov r2, sb
	strb r0, [r2, #0xe]
_08045C78:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start babyelf_08045c84
babyelf_08045c84: @ 0x08045C84
	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0xbc
	ldr r1, [r0]
	mov r0, ip
	str r1, [r0, #0x54]
	adds r0, #0xc0
	ldr r4, [r0]
	mov r2, ip
	str r4, [r2, #0x58]
	adds r0, #4
	ldrh r3, [r0]
	ldr r0, _08045CD4 @ =0x000001FF
	ands r3, r0
	cmp r3, #0xff
	bgt _08045CE0
	ldr r2, _08045CD8 @ =gSineTable
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #4
	adds r0, r1, r0
	mov r1, ip
	str r0, [r1, #0x54]
	ldr r5, _08045CDC @ =0xFFFFF000
	adds r1, r4, r5
	mov r0, ip
	str r1, [r0, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	b _08045D14
	.align 2, 0
_08045CD4: .4byte 0x000001FF
_08045CD8: .4byte gSineTable
_08045CDC: .4byte 0xFFFFF000
_08045CE0:
	ldr r0, _08045D20 @ =0xFFFFFF00
	adds r3, r3, r0
	ldr r2, _08045D24 @ =gSineTable
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #4
	adds r0, r1, r0
	mov r1, ip
	str r0, [r1, #0x54]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r4, r5
	mov r0, ip
	str r1, [r0, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	subs r1, r1, r0
_08045D14:
	mov r5, ip
	str r1, [r5, #0x58]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08045D20: .4byte 0xFFFFFF00
_08045D24: .4byte gSineTable

	thumb_func_start FUN_08045d28
FUN_08045d28: @ 0x08045D28
	push {lr}
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08045D50
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bne _08045D50
	ldr r1, [r2, #0x28]
	adds r1, #0xa4
	ldrh r0, [r1]
	adds r2, #0xa4
	subs r0, #0x60
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x60
	strh r0, [r2]
_08045D50:
	pop {r0}
	bx r0

	thumb_func_start FUN_08045d54
FUN_08045d54: @ 0x08045D54
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08045DF4
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08045DF4
	ldr r0, _08045DD4 @ =0x00000119
	bl PlaySound
	ldr r3, _08045DD8 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _08045D92
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08045D92
	ldr r0, _08045DDC @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08045D92:
	ldr r3, [r4, #0x2c]
	movs r5, #0
	ldrb r1, [r4, #0xd]
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08045DA8
	cmp r1, #0x10
	bne _08045DAA
_08045DA8:
	movs r5, #1
_08045DAA:
	ldr r2, _08045DE0 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	cmp r5, #0
	beq _08045DE4
	movs r0, #0
	b _08045DE6
	.align 2, 0
_08045DD4: .4byte 0x00000119
_08045DD8: .4byte gStageRun
_08045DDC: .4byte 0x0000FFFE
_08045DE0: .4byte gBossFnTable
_08045DE4:
	movs r0, #1
_08045DE6:
	strb r0, [r4, #0xd]
	strb r0, [r3, #0xd]
	adds r0, r4, #0
	bl BabyElf_Die
	movs r0, #1
	b _08045DF6
_08045DF4:
	movs r0, #0
_08045DF6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start BabyElf_Init
BabyElf_Init: @ 0x08045DFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	beq _08045E16
	adds r1, r6, #0
	adds r1, #0xd1
	movs r0, #0
	strb r0, [r1]
_08045E16:
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _08045E24
	movs r0, #0
	strb r0, [r6, #0x10]
	movs r0, #1
	b _08045E50
_08045E24:
	cmp r0, #3
	bne _08045E38
	movs r1, #0
	strb r1, [r6, #0x10]
	movs r0, #2
	strb r0, [r6, #0x11]
	adds r0, r6, #0
	adds r0, #0xd1
	strb r1, [r0]
	b _08045E52
_08045E38:
	cmp r0, #4
	bne _08045E4E
	movs r0, #0
	strb r0, [r6, #0x10]
	movs r0, #2
	strb r0, [r6, #0x11]
	adds r1, r6, #0
	adds r1, #0xd1
	movs r0, #1
	strb r0, [r1]
	b _08045E52
_08045E4E:
	movs r0, #0
_08045E50:
	strb r0, [r6, #0x11]
_08045E52:
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	ldr r1, _080460BC @ =gBossFnTable
	adds r0, r0, r1
	movs r2, #1
	str r2, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080460C0 @ =0x08362714
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r2, #0
	mov sl, r2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080460C4 @ =0x0836265C
	adds r0, r6, #0
	movs r2, #0x60
	bl ResetBossBody
	ldr r1, _080460C8 @ =FUN_08045d28
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r4, r6, #0
	adds r4, #0xb4
	ldr r0, [r6, #0x54]
	asrs r0, r0, #8
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	ldr r0, _080460CC @ =0xFFFFF800
	adds r1, r1, r0
	str r1, [r4]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	movs r1, #0xa0
	bl __divsi3
	adds r0, #1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	str r1, [r0]
	ldr r2, _080460D0 @ =0xFFFFB000
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc4
	movs r1, #0
	mov r8, r1
	strh r5, [r0]
	adds r1, r6, #0
	adds r1, #0xcc
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xcd
	mov r2, r8
	strb r2, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	subs r0, #0xa
	strb r2, [r0]
	ldrb r0, [r6, #0x10]
	subs r1, #5
	strb r0, [r1]
	ldrb r0, [r6, #0x10]
	mov sb, r0
	cmp r0, #0
	beq _08045F16
	b _080460A8
_08045F16:
	ldrb r0, [r6, #0x11]
	cmp r0, #2
	beq _08045F58
	movs r4, #0x82
	lsls r4, r4, #3
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080460D8 @ =wStaticGraphicTilenums
	adds r1, #0x68
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080460E0 @ =wStaticMotionPalIDs
	adds r0, #0x68
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
_08045F58:
	movs r4, #0xf0
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r7, _080460D8 @ =wStaticGraphicTilenums
	adds r1, r7, #0
	adds r1, #0x60
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r5, _080460E0 @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldrb r0, [r6, #0x11]
	cmp r0, #2
	beq _08046052
	movs r4, #0xf5
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xfa
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	adds r1, r7, #0
	adds r1, #0x64
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x64
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xff
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	adds r1, r7, #0
	adds r1, #0x66
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x66
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_08046052:
	ldr r0, _080460E4 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r2, r0, #0
	cmp r2, #0
	beq _080460A6
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #6
	strb r0, [r2, #9]
	ldr r1, _080460BC @ =gBossFnTable
	ldr r0, [r1, #0x18]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	mov r0, sb
	strh r0, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	mov r1, r8
	strb r1, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x10]
	ldr r0, [r6, #0x54]
	str r0, [r2, #0x54]
	ldr r0, [r6, #0x58]
	str r0, [r2, #0x58]
	adds r0, r6, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0xd1
	strb r0, [r1]
	str r6, [r2, #0x28]
_080460A6:
	str r2, [r6, #0x2c]
_080460A8:
	adds r0, r6, #0
	bl BabyElf_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080460BC: .4byte gBossFnTable
_080460C0: .4byte 0x08362714
_080460C4: .4byte 0x0836265C
_080460C8: .4byte FUN_08045d28
_080460CC: .4byte 0xFFFFF800
_080460D0: .4byte 0xFFFFB000
_080460D4: .4byte gStaticMotionGraphics
_080460D8: .4byte wStaticGraphicTilenums
_080460DC: .4byte gStaticMotionGraphics+12
_080460E0: .4byte wStaticMotionPalIDs
_080460E4: .4byte gBossHeaderPtr

	thumb_func_start BabyElf_Update
BabyElf_Update: @ 0x080460E8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08045b68
	adds r0, r4, #0
	bl FUN_08045d54
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804611C
	ldr r1, _08046124 @ =0x083625BC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08046128 @ =0x08362608
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0804611C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08046124: .4byte 0x083625BC
_08046128: .4byte 0x08362608

	thumb_func_start BabyElf_Die
BabyElf_Die: @ 0x0804612C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08045b68
	ldr r1, _0804614C @ =0x08362654
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804614C: .4byte 0x08362654

	thumb_func_start nop_08046150
nop_08046150: @ 0x08046150
	bx lr
	.align 2, 0

	thumb_func_start babyelf_08046154
babyelf_08046154: @ 0x08046154
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	ldrb r0, [r6, #0xe]
	cmp r0, #9
	bls _0804616A
	b _08046618
_0804616A:
	lsls r0, r0, #2
	ldr r1, _08046174 @ =_08046178
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08046174: .4byte _08046178
_08046178: @ jump table
	.4byte _080461A0 @ case 0
	.4byte _080461C8 @ case 1
	.4byte _08046618 @ case 2
	.4byte _08046618 @ case 3
	.4byte _0804633C @ case 4
	.4byte _0804636E @ case 5
	.4byte _08046410 @ case 6
	.4byte _08046472 @ case 7
	.4byte _080464A0 @ case 8
	.4byte _08046530 @ case 9
_080461A0:
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0xc4
	movs r4, #0
	strh r4, [r0]
	adds r0, r6, #0
	bl babyelf_08045c84
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	str r4, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080461C8:
	adds r4, r6, #0
	adds r4, #0xc4
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #2
	subs r1, #2
	ldrh r0, [r4]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4]
	ldr r1, _08046240 @ =0x000001FF
	ands r0, r1
	strh r0, [r4]
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	adds r0, r6, #0
	bl babyelf_08045c84
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _08046200
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08046212
_08046200:
	cmp r2, #1
	bne _08046248
	mov r1, r8
	ldr r0, [r1, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08046248
_08046212:
	ldr r3, _08046244 @ =gSineTable
	ldr r2, [r6, #0x5c]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r1, r1, #1
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	lsls r0, r2, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #1
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r2, #0x20
	str r2, [r6, #0x5c]
	b _0804624C
	.align 2, 0
_08046240: .4byte 0x000001FF
_08046244: .4byte gSineTable
_08046248:
	movs r0, #0
	str r0, [r6, #0x5c]
_0804624C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrh r0, [r4]
	adds r1, r6, #0
	adds r1, #0xd1
	ldrb r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, #7
	bl __modsi3
	cmp r0, #0
	bne _080462B2
	ldr r5, [r6, #0x58]
	mov ip, r5
	ldr r0, [r6, #0x68]
	subs r0, r5, r0
	lsls r7, r0, #1
	cmp r7, #0
	bge _0804627A
	movs r7, #0
_0804627A:
	ldr r5, _080462D0 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080462D4 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _080462D8 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _080462DC @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	adds r1, r2, #0
	muls r1, r4, r1
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	str r2, [r5]
	lsls r1, r1, #5
	lsrs r1, r1, #0x16
	add r1, ip
	movs r2, #0
	adds r3, r7, #0
	bl FUN_080bc540
_080462B2:
	ldrb r1, [r6, #0x10]
	cmp r1, #1
	bne _08046300
	mov r3, r8
	ldrb r2, [r3, #0x11]
	cmp r2, #2
	bne _080462F0
	ldr r0, [r3, #0x18]
	ldrb r1, [r0, #9]
	ands r2, r1
	cmp r2, #0
	beq _080462E0
	movs r1, #0
	movs r0, #0x11
	b _08046322
	.align 2, 0
_080462D0: .4byte RNG_0202f388
_080462D4: .4byte 0x000343FD
_080462D8: .4byte 0x00269EC3
_080462DC: .4byte 0xFFFFFC00
_080462E0:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080462EA
	b _08046618
_080462EA:
	movs r0, #0x12
	strb r0, [r6, #0xd]
	b _08046616
_080462F0:
	mov r5, r8
	ldr r0, [r5, #0x18]
	ldrb r0, [r0, #9]
	ands r1, r0
	cmp r1, #0
	bne _080462FE
	b _08046618
_080462FE:
	b _08046336
_08046300:
	ldrb r1, [r6, #0x11]
	cmp r1, #2
	bne _08046328
	ldr r0, [r6, #0x18]
	ldrb r2, [r0, #9]
	ands r1, r2
	cmp r1, #0
	beq _08046316
	movs r1, #0
	movs r0, #0x11
	b _08046322
_08046316:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _08046320
	b _08046618
_08046320:
	movs r0, #0x12
_08046322:
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _08046618
_08046328:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08046336
	b _08046618
_08046336:
	movs r0, #4
	strb r0, [r6, #0xe]
	b _08046618
_0804633C:
	movs r0, #0
	str r0, [r6, #0x5c]
	str r0, [r6, #0x60]
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xc
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #0x50
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804636E:
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r5, [r6, #0x54]
	subs r2, r0, r5
	ldr r3, _0804640C @ =0xFFFFA800
	adds r2, r2, r3
	ldrb r1, [r6, #0x10]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0xc
	adds r2, r2, r0
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r4, [r6, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r1, r4, r3
	ldr r0, [r0]
	subs r3, r0, r1
	adds r0, r2, #0
	cmp r2, #0
	bge _080463A2
	adds r0, #0x1f
_080463A2:
	asrs r2, r0, #5
	adds r0, r3, #0
	cmp r3, #0
	bge _080463AC
	adds r0, #0x1f
_080463AC:
	asrs r3, r0, #5
	ldr r1, [r6, #0x5c]
	subs r0, r2, r1
	cmp r0, #0
	bge _080463B8
	adds r0, #0xf
_080463B8:
	asrs r0, r0, #4
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r2, [r6, #0x60]
	subs r0, r3, r2
	cmp r0, #0
	bge _080463C8
	adds r0, #0xf
_080463C8:
	asrs r0, r0, #4
	adds r0, r2, r0
	str r0, [r6, #0x60]
	adds r1, r5, r1
	str r1, [r6, #0x54]
	adds r0, r4, r0
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r4, r6, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	bl UpdateBlinkMotionState
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080463F6
	b _08046618
_080463F6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046402
	bl ClearBlink
	strb r5, [r4]
_08046402:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _08046618
	.align 2, 0
_0804640C: .4byte 0xFFFFA800
_08046410:
	ldrb r0, [r6, #0x10]
	adds r1, r6, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0804644A
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	orrs r1, r0
	movs r0, #0x13
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0x13
	b _0804646A
_0804644A:
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xe
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0xe
_0804646A:
	strb r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08046472:
	adds r4, r6, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08046498
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046492
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_08046492:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08046498:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _08046618
_080464A0:
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0xbc
	adds r7, r6, #0
	adds r7, #0xc0
_080464AA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	lsls r3, r4, #0x1d
	lsrs r3, r3, #0x18
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0x80
	lsls r2, r2, #1
	bl FUN_080bc7a4
	adds r4, #1
	cmp r4, #7
	ble _080464AA
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	str r0, [r5]
	ldr r0, [r6, #0x58]
	str r0, [r7]
	movs r1, #0
	strb r1, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0xc4
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08046508
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x14
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0x14
	b _08046528
_08046508:
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	orrs r1, r0
	movs r0, #0xf
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0xf
_08046528:
	strb r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08046530:
	adds r7, r6, #0
	adds r7, #0xc4
	ldrb r1, [r6, #0x10]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080465D4 @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r2, [r7]
	adds r0, r0, r2
	strh r0, [r7]
	adds r0, r6, #0
	bl babyelf_08045c84
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080465A2
	ldr r5, _080465D8 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080465DC @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _080465E0 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _080465E4 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_080465A2:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r2, [r6, #0x10]
	cmp r2, #1
	bne _080465F0
	ldr r0, _080465E8 @ =gStageRun
	ldrb r1, [r0, #0x12]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08046618
	movs r3, #0
	ldrsh r1, [r7, r3]
	adds r0, r1, #0
	cmp r1, #0
	bge _0804660C
	ldr r5, _080465EC @ =0x000001FF
	adds r0, r1, r5
	b _0804660C
	.align 2, 0
_080465D4: .4byte 0x0000FFFD
_080465D8: .4byte RNG_0202f388
_080465DC: .4byte 0x000343FD
_080465E0: .4byte 0x00269EC3
_080465E4: .4byte 0xFFFFFC00
_080465E8: .4byte gStageRun
_080465EC: .4byte 0x000001FF
_080465F0:
	ldr r0, _08046624 @ =gStageRun
	ldrb r1, [r0, #0x12]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08046618
	movs r0, #0
	ldrsh r1, [r7, r0]
	adds r0, r1, #0
	cmp r1, #0
	bge _0804660C
	ldr r3, _08046628 @ =0x000001FF
	adds r0, r1, r3
_0804660C:
	asrs r0, r0, #9
	lsls r0, r0, #9
	subs r0, r1, r0
	strh r0, [r7]
	strb r2, [r6, #0xd]
_08046616:
	strb r2, [r6, #0xe]
_08046618:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046624: .4byte gStageRun
_08046628: .4byte 0x000001FF

	thumb_func_start babyelf_0804662c
babyelf_0804662c: @ 0x0804662C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _0804663E
	cmp r4, #1
	beq _080466C4
	b _0804679A
_0804663E:
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	strb r4, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0xc4
	strh r4, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08046686
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x14
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0x14
	b _080466A6
_08046686:
	adds r0, r6, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xf
	bl LoadBlink
	adds r1, r6, #0
	adds r1, #0xc6
	movs r0, #0xf
_080466A6:
	strb r0, [r1]
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r6, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	ble _080466B8
	movs r2, #1
_080466B8:
	adds r0, r6, #0
	adds r0, #0xc7
	strb r2, [r0]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080466C4:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080467A4 @ =0x08362674
	bl SetDDP
	adds r2, r6, #0
	adds r2, #0xc4
	adds r3, r6, #0
	adds r3, #0xc7
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080467A8 @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r1, [r2]
	adds r4, r0, r1
	strh r4, [r2]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0804672E
	ldr r0, _080467AC @ =pZero2
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r0, r2
	cmp r0, #0
	bne _0804672E
	adds r0, r1, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0804672E
	lsls r0, r4, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080467B0 @ =0x0000FDFF
	cmp r1, r0
	bhi _0804671E
	ldrb r0, [r3]
	cmp r0, #0
	beq _08046728
_0804671E:
	cmp r1, r2
	bls _0804672E
	ldrb r0, [r3]
	cmp r0, #1
	bne _0804672E
_08046728:
	adds r0, r6, #0
	bl babyelf_08045bc4
_0804672E:
	adds r0, r6, #0
	bl babyelf_08045c84
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804678A
	ldr r5, _080467B4 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080467B8 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _080467BC @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _080467C0 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_0804678A:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0804679A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080467A4: .4byte 0x08362674
_080467A8: .4byte 0x0000FFFD
_080467AC: .4byte pZero2
_080467B0: .4byte 0x0000FDFF
_080467B4: .4byte RNG_0202f388
_080467B8: .4byte 0x000343FD
_080467BC: .4byte 0x00269EC3
_080467C0: .4byte 0xFFFFFC00

	thumb_func_start babyelf_080467c4
babyelf_080467c4: @ 0x080467C4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _080467D2
	b _08046A02
_080467D2:
	lsls r0, r0, #2
	ldr r1, _080467E4 @ =0x080467E8
	adds r0, r0, r1
	ldr r0, [r0]
	adds r2, r6, #0
	adds r2, #0xc4
	adds r5, r6, #0
	adds r5, #0xc7
	mov pc, r0
	.align 2, 0
_080467E4: .4byte 0x080467E8
_080467E8:
	.byte 0x00, 0x68, 0x04, 0x08, 0x10, 0x68, 0x04, 0x08
	.byte 0x58, 0x68, 0x04, 0x08, 0xE4, 0x68, 0x04, 0x08, 0x68, 0x69, 0x04, 0x08, 0xB4, 0x69, 0x04, 0x08
	.byte 0x31, 0x1C, 0xC4, 0x31, 0x00, 0x20, 0x08, 0x80, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x0A, 0x1C
	.byte 0x33, 0x1C, 0xC7, 0x33, 0x18, 0x78, 0x41, 0x00, 0x09, 0x18, 0x49, 0x00, 0x0C, 0x48, 0x09, 0x18
	.byte 0x10, 0x88, 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x0C, 0x0A, 0x48, 0x81, 0x42, 0x02, 0xD8
	.byte 0x18, 0x78, 0x00, 0x28, 0x04, 0xD0, 0x80, 0x29, 0x05, 0xD9, 0x18, 0x78, 0x01, 0x28, 0x02, 0xD1
	.byte 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x30, 0x1C, 0xFF, 0xF7, 0x1C, 0xFA, 0x80, 0xE0, 0x00, 0x00
	.byte 0xFD, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x09, 0x4A, 0x11, 0x68, 0x09, 0x48, 0x48, 0x43
	.byte 0x09, 0x49, 0x40, 0x18, 0x40, 0x00, 0x41, 0x08, 0x11, 0x60, 0x40, 0x0C, 0x01, 0x21, 0x08, 0x40
	.byte 0x00, 0x28, 0x0B, 0xD0, 0x8A, 0x20, 0x40, 0x00, 0xBD, 0xF7, 0x92, 0xFE, 0x09, 0xE0, 0x00, 0x00
	.byte 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00, 0x0B, 0x48, 0xBD, 0xF7
	.byte 0x87, 0xFE, 0x32, 0x1C, 0xC4, 0x32, 0x00, 0x20, 0x10, 0x80, 0x33, 0x1C, 0xC0, 0x33, 0xB0, 0x6D
	.byte 0x18, 0x60, 0xB0, 0x24, 0x24, 0x02, 0xF4, 0x65, 0x30, 0x1C, 0xC7, 0x30, 0x01, 0x78, 0x05, 0x1C
	.byte 0x00, 0x29, 0x07, 0xD1, 0x18, 0x68, 0x02, 0x49, 0x09, 0xE0, 0x00, 0x00, 0x15, 0x01, 0x00, 0x00
	.byte 0x00, 0xE8, 0xFF, 0xFF, 0x60, 0x42, 0xF0, 0x65, 0x18, 0x68, 0xC0, 0x21, 0x49, 0x01, 0x40, 0x18
	.byte 0x18, 0x60, 0xF0, 0x6D, 0x00, 0x28, 0x00, 0xDA, 0x7F, 0x30, 0xC0, 0x11, 0xF0, 0x65, 0xB0, 0x7B
	.byte 0x01, 0x30, 0xB0, 0x73, 0x70, 0x6D, 0xF1, 0x6D, 0x40, 0x18, 0x70, 0x65, 0x30, 0x1C, 0xC0, 0x30
	.byte 0x00, 0x68, 0xB0, 0x65, 0x10, 0x88, 0x04, 0x30, 0x10, 0x80, 0x00, 0x04, 0x0B, 0x49, 0x88, 0x42
	.byte 0x02, 0xD9, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x28, 0x78, 0x00, 0x28, 0x12, 0xD1, 0x08, 0x49
	.byte 0x10, 0x78, 0x40, 0x30, 0x00, 0x06, 0xC0, 0x0D, 0x40, 0x18, 0x00, 0x21, 0x40, 0x5E, 0x41, 0x00
	.byte 0x09, 0x18, 0xC9, 0x00, 0xB0, 0x6D, 0x40, 0x18, 0x11, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01
	.byte 0x74, 0xEA, 0x0F, 0x08, 0x0B, 0x49, 0x10, 0x78, 0x40, 0x30, 0x00, 0x06, 0xC0, 0x0D, 0x40, 0x18
	.byte 0x00, 0x21, 0x40, 0x5E, 0x41, 0x00, 0x09, 0x18, 0xC9, 0x00, 0xB0, 0x6D, 0x40, 0x1A, 0xB0, 0x65
	.byte 0x30, 0x1C, 0xC6, 0x30, 0x00, 0x78, 0xBD, 0xF7, 0x87, 0xFB, 0x30, 0x1C, 0xD0, 0xF7, 0x7E, 0xFE
	.byte 0x4F, 0xE0, 0x00, 0x00, 0x74, 0xEA, 0x0F, 0x08, 0x31, 0x1C, 0xBC, 0x31, 0x70, 0x6D, 0x08, 0x60
	.byte 0x33, 0x1C, 0xC0, 0x33, 0xB0, 0x6D, 0x18, 0x60, 0x32, 0x1C, 0xC7, 0x32, 0x10, 0x78, 0x01, 0x21
	.byte 0x48, 0x40, 0x10, 0x70, 0x15, 0x1C, 0x00, 0x28, 0x08, 0xD1, 0x18, 0x68, 0x80, 0x21, 0x89, 0x01
	.byte 0x40, 0x18, 0x18, 0x60, 0x31, 0x1C, 0xC4, 0x31, 0x80, 0x20, 0x06, 0xE0, 0x18, 0x68, 0x30, 0x49
	.byte 0x40, 0x18, 0x18, 0x60, 0x31, 0x1C, 0xC4, 0x31, 0x2E, 0x48, 0x08, 0x80, 0x0A, 0x1C, 0xB0, 0x7B
	.byte 0x01, 0x30, 0xB0, 0x73, 0x2B, 0x1C, 0x19, 0x78, 0x48, 0x00, 0x40, 0x18, 0x40, 0x00, 0x03, 0x38
	.byte 0x11, 0x88, 0x09, 0x1A, 0x11, 0x80, 0x09, 0x04, 0x09, 0x0C, 0x80, 0x20, 0x40, 0x00, 0x81, 0x42
	.byte 0x02, 0xD9, 0x18, 0x78, 0x00, 0x28, 0x05, 0xD0, 0x23, 0x48, 0x81, 0x42, 0x06, 0xD8, 0x28, 0x78
	.byte 0x01, 0x28, 0x03, 0xD1, 0x00, 0x21, 0x01, 0x20, 0x70, 0x73, 0xB1, 0x73, 0x30, 0x1C, 0xFF, 0xF7
	.byte 0x49, 0xF9, 0x30, 0x1C, 0xC6, 0x30, 0x00, 0x78, 0xBD, 0xF7, 0x36, 0xFB, 0x30, 0x1C, 0xD0, 0xF7
	.byte 0x2D, 0xFE
_08046A02:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046A58
	ldr r5, _08046A6C @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08046A70 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08046A74 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08046A78 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08046A58:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08046A60:
	.byte 0x00, 0xE0, 0xFF, 0xFF, 0x80, 0xFF, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00
_08046A6C: .4byte RNG_0202f388
_08046A70: .4byte 0x000343FD
_08046A74: .4byte 0x00269EC3
_08046A78: .4byte 0xFFFFFC00

	thumb_func_start babyelf_08046a7c
babyelf_08046a7c: @ 0x08046A7C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08046AFC
	cmp r5, #1
	bgt _08046A90
	cmp r5, #0
	beq _08046A9C
	b _08046CBE
_08046A90:
	cmp r5, #2
	beq _08046B58
	cmp r5, #3
	bne _08046A9A
	b _08046C3E
_08046A9A:
	b _08046CBE
_08046A9C:
	adds r6, r4, #0
	adds r6, #0xc6
	ldrb r0, [r6]
	cmp r0, #0
	beq _08046AAC
	bl ClearBlink
	strb r5, [r6]
_08046AAC:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08046AD0
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x15
	bl LoadBlink
	movs r0, #0x15
	b _08046AEC
_08046AD0:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x10
	bl LoadBlink
	movs r0, #0x10
_08046AEC:
	strb r0, [r6]
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08046AFC:
	adds r2, r4, #0
	adds r2, #0xc4
	adds r3, r4, #0
	adds r3, #0xc7
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08046B50 @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08046B54 @ =0x0000FF7F
	cmp r1, r0
	bhi _08046B26
	ldrb r0, [r3]
	cmp r0, #0
	beq _08046B30
_08046B26:
	cmp r1, #0x80
	bls _08046B36
	ldrb r0, [r3]
	cmp r0, #1
	bne _08046B36
_08046B30:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08046B36:
	adds r0, r4, #0
	bl babyelf_08045c84
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08046CBE
	.align 2, 0
_08046B50: .4byte 0x0000FFFD
_08046B54: .4byte 0x0000FF7F
_08046B58:
	movs r0, #0x8b
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xc8
	movs r6, #0
	strb r6, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bc5fc
	adds r5, r4, #0
	adds r5, #0xc6
	ldrb r0, [r5]
	cmp r0, #0
	beq _08046B80
	bl ClearBlink
	strb r6, [r5]
_08046B80:
	adds r0, r4, #0
	adds r0, #0x22
	strb r6, [r0]
	ldr r1, _08046BEC @ =0x00003301
	adds r0, r4, #0
	bl SetMotion
	ldrb r6, [r4, #0x10]
	cmp r6, #0
	bne _08046BC2
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x18
	bl LoadBlink
	movs r0, #0x18
	strb r0, [r5]
	bl UpdateBlinkMotionState
	ldrb r0, [r5]
	cmp r0, #0
	beq _08046BC2
	bl ClearBlink
	strb r6, [r5]
_08046BC2:
	adds r0, r4, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	cmp r0, #0
	bne _08046BF4
	ldr r2, _08046BF0 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0xa0
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08046BE2
	adds r0, #0xff
_08046BE2:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	b _08046C1A
	.align 2, 0
_08046BEC: .4byte 0x00003301
_08046BF0: .4byte gSineTable
_08046BF4:
	ldr r2, _08046CC4 @ =gSineTable
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08046C0C
	adds r0, #0xff
_08046C0C:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
_08046C1A:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08046C26
	adds r0, #0xff
_08046C26:
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0xa
	strb r0, [r4, #0x12]
	movs r0, #0x1a
	strb r0, [r4, #0x13]
	movs r0, #0x5a
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08046C3E:
	ldr r0, [r4, #0x64]
	subs r1, r0, #1
	str r1, [r4, #0x64]
	cmp r1, #0
	bne _08046C4E
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08046C4E:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08046CA8
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08046C78
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046C78
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	ldr r3, _08046CC8 @ =0xFFFFB000
	adds r1, r1, r3
	bl FUN_080bc660
_08046C78:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08046CA8
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046CA8
	movs r5, #0
	adds r7, r4, #0
	adds r7, #0xb4
	adds r6, r4, #0
	adds r6, #0xb8
_08046C92:
	ldr r0, [r7]
	ldr r1, [r6]
	ldr r2, _08046CC8 @ =0xFFFFB000
	adds r1, r1, r2
	lsls r2, r5, #0x1d
	lsrs r2, r2, #0x18
	bl FUN_0809f8fc
	adds r5, #1
	cmp r5, #7
	ble _08046C92
_08046CA8:
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
_08046CBE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046CC4: .4byte gSineTable
_08046CC8: .4byte 0xFFFFB000

	thumb_func_start FUN_08046ccc
FUN_08046ccc: @ 0x08046CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _08046D3E
	cmp r0, #1
	bgt _08046CE4
	cmp r0, #0
	beq _08046CF0
	b _08046E50
_08046CE4:
	cmp r0, #2
	beq _08046DC0
	cmp r0, #3
	bne _08046CEE
	b _08046E22
_08046CEE:
	b _08046E50
_08046CF0:
	movs r4, #0
	adds r2, r7, #0
	adds r2, #0xb4
	ldr r1, [r7, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	ble _08046D00
	movs r4, #1
_08046D00:
	adds r3, r7, #0
	adds r3, #0xc7
	strb r4, [r3]
	ldr r2, [r2]
	ldr r0, _08046DB8 @ =0xFFFF5000
	adds r2, r2, r0
	str r2, [r7, #0x54]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0xd
	adds r2, r2, r0
	str r2, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r1, [r0]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r7, #0x58]
	ldrb r0, [r3]
	lsls r0, r0, #0x10
	subs r1, r1, r0
	str r1, [r7, #0x58]
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08046D3E:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r6, [r7, #0x54]
	subs r0, r0, r6
	ldr r3, _08046DBC @ =0xFFFFA800
	adds r0, r0, r3
	adds r1, r7, #0
	adds r1, #0xc7
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r1, r1, #0xc
	adds r0, r0, r1
	adds r2, r7, #0
	adds r2, #0xb8
	ldr r5, [r7, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r1, r5, r3
	ldr r4, [r2]
	subs r4, r4, r1
	movs r1, #0xc
	bl __divsi3
	mov r8, r0
	adds r0, r4, #0
	movs r1, #0xc
	bl __divsi3
	add r6, r8
	str r6, [r7, #0x54]
	adds r5, r5, r0
	str r5, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046DAE
	adds r1, r7, #0
	adds r1, #0xc8
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08046DAE:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _08046E50
	.align 2, 0
_08046DB8: .4byte 0xFFFF5000
_08046DBC: .4byte 0xFFFFA800
_08046DC0:
	ldrb r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08046DFA
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x16
	bl LoadBlink
	adds r1, r7, #0
	adds r1, #0xc6
	movs r0, #0x16
	b _08046E1A
_08046DFA:
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x11
	bl LoadBlink
	adds r1, r7, #0
	adds r1, #0xc6
	movs r0, #0x11
_08046E1A:
	strb r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08046E22:
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08046E4A
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046E42
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_08046E42:
	movs r1, #0
	movs r0, #1
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_08046E4A:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_08046E50:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start babyelf_08046e5c
babyelf_08046e5c: @ 0x08046E5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r2, [r6, #0x2c]
	ldrb r0, [r6, #0xe]
	cmp r0, #7
	bls _08046E6C
	b _080470F8
_08046E6C:
	lsls r0, r0, #2
	ldr r1, _08046E7C @ =0x08046E80
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r6, #0
	adds r4, #0xc4
	mov pc, r0
	.align 2, 0
_08046E7C: .4byte 0x08046E80
_08046E80:
	.byte 0xA0, 0x6E, 0x04, 0x08, 0xB4, 0x6E, 0x04, 0x08, 0xF8, 0x6E, 0x04, 0x08, 0x0C, 0x6F, 0x04, 0x08
	.byte 0xE8, 0x6F, 0x04, 0x08, 0x02, 0x70, 0x04, 0x08, 0x50, 0x70, 0x04, 0x08, 0x7A, 0x70, 0x04, 0x08
	.byte 0x31, 0x1C, 0xC9, 0x31, 0x00, 0x20, 0x08, 0x70, 0x05, 0x39, 0x08, 0x80, 0xB0, 0x7B, 0x01, 0x30
	.byte 0xB0, 0x73, 0x0C, 0x1C, 0x32, 0x1C, 0xC7, 0x32, 0x10, 0x78, 0x41, 0x00, 0x09, 0x18, 0x49, 0x00
	.byte 0x0B, 0x48, 0x09, 0x18, 0x23, 0x88, 0xC9, 0x18, 0x21, 0x80, 0x09, 0x04, 0x09, 0x0C, 0x09, 0x48
	.byte 0x81, 0x42, 0x02, 0xD8, 0x10, 0x78, 0x00, 0x28, 0x06, 0xD0, 0x80, 0x29, 0x00, 0xD8, 0xAF, 0xE0
	.byte 0x10, 0x78, 0x01, 0x28, 0x00, 0xD0, 0xAB, 0xE0, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0xA7, 0xE0
	.byte 0xFD, 0xFF, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x32, 0x1C, 0xC4, 0x32, 0x00, 0x21, 0x00, 0x20
	.byte 0x10, 0x80, 0xF1, 0x74, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x14, 0x1C, 0xF0, 0x7C, 0x00, 0x28
	.byte 0x15, 0xD1, 0x1E, 0x4A, 0x11, 0x68, 0x1E, 0x48, 0x48, 0x43, 0x1E, 0x49, 0x40, 0x18, 0x40, 0x00
	.byte 0x41, 0x08, 0x11, 0x60, 0x40, 0x0C, 0x01, 0x21, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x1A, 0x48
	.byte 0xBD, 0xF7, 0x36, 0xFB, 0x70, 0x6D, 0xB1, 0x6D, 0x00, 0x22, 0x58, 0xF0, 0x19, 0xFD, 0xF0, 0x7C
	.byte 0x01, 0x30, 0xF0, 0x74, 0xF0, 0x7C, 0x1F, 0x21, 0x08, 0x40, 0xF0, 0x74, 0x20, 0x88, 0x01, 0x30
	.byte 0x20, 0x80, 0x00, 0x04, 0x80, 0x21, 0x49, 0x04, 0x88, 0x42, 0x02, 0xD9, 0xB0, 0x7B, 0x01, 0x30
	.byte 0xB0, 0x73, 0x30, 0x1C, 0xC7, 0x30, 0x00, 0x78, 0x00, 0x28, 0x19, 0xD1, 0x0B, 0x4A, 0x20, 0x78
	.byte 0x40, 0x00, 0x80, 0x18, 0x00, 0x23, 0xC1, 0x5E, 0xC8, 0x00, 0x40, 0x1A, 0x80, 0x01, 0x00, 0x28
	.byte 0x00, 0xDA, 0xFF, 0x30, 0x01, 0x12, 0x70, 0x6D, 0x40, 0x18, 0x18, 0xE0, 0x88, 0xF3, 0x02, 0x02
	.byte 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00, 0x15, 0x01, 0x00, 0x00, 0x74, 0xEA, 0x0F, 0x08
	.byte 0x10, 0x4A, 0x20, 0x78, 0x40, 0x00, 0x80, 0x18, 0x00, 0x23, 0xC1, 0x5E, 0xC8, 0x00, 0x40, 0x1A
	.byte 0x80, 0x01, 0x00, 0x28, 0x00, 0xDA, 0xFF, 0x30, 0x01, 0x12, 0x70, 0x6D, 0x40, 0x1A, 0x70, 0x65
	.byte 0x20, 0x78, 0x40, 0x30, 0x00, 0x06, 0xC0, 0x0D, 0x80, 0x18, 0x00, 0x22, 0x81, 0x5E, 0x2C, 0x20
	.byte 0x48, 0x43, 0x00, 0x28, 0x00, 0xDA, 0xFF, 0x30, 0x01, 0x12, 0xB0, 0x6D, 0x40, 0x18, 0xB0, 0x65
	.byte 0x8A, 0xE0, 0x00, 0x00, 0x74, 0xEA, 0x0F, 0x08, 0x02, 0x20, 0xF0, 0x74, 0x31, 0x1C, 0xC9, 0x31
	.byte 0x01, 0x20, 0x08, 0x70, 0x05, 0x39, 0x14, 0x48, 0x08, 0x80, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73
	.byte 0x0C, 0x1C, 0xF0, 0x7C, 0x00, 0x28, 0x08, 0xD0, 0x01, 0x38, 0xF0, 0x74, 0x00, 0x06, 0x00, 0x0E
	.byte 0x00, 0x28, 0x02, 0xD1, 0x31, 0x1C, 0xC9, 0x31, 0x08, 0x70, 0x10, 0x1C, 0xC9, 0x30, 0x00, 0x78
	.byte 0x00, 0x28, 0x02, 0xD0, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x30, 0x1C, 0xC7, 0x30, 0x01, 0x78
	.byte 0x48, 0x00, 0x40, 0x18, 0x40, 0x00, 0x05, 0x4B, 0xC0, 0x18, 0x21, 0x88, 0x40, 0x18, 0x20, 0x80
	.byte 0x30, 0x1C, 0xFE, 0xF7, 0x1F, 0xFE, 0x57, 0xE0, 0x80, 0xFE, 0x00, 0x00, 0xFD, 0xFF, 0x00, 0x00
	.byte 0x31, 0x1C, 0xC9, 0x31, 0x00, 0x20, 0x08, 0x70, 0x30, 0x1C, 0xC4, 0x30, 0x00, 0x22, 0x83, 0x5E
	.byte 0x19, 0x1C, 0x04, 0x1C, 0x00, 0x2B, 0x01, 0xDA, 0x3F, 0x48, 0x19, 0x18, 0x48, 0x12, 0x40, 0x02
	.byte 0x18, 0x1A, 0x20, 0x80, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x00, 0x27, 0x21, 0x88, 0x3B, 0x48
	.byte 0x33, 0x1C, 0xC7, 0x33, 0x81, 0x42, 0x02, 0xD8, 0x18, 0x78, 0x00, 0x28, 0x06, 0xD0, 0xC0, 0x20
	.byte 0x40, 0x00, 0x81, 0x42, 0x03, 0xD9, 0x18, 0x78, 0x01, 0x28, 0x00, 0xD1, 0x01, 0x27, 0x22, 0x1C
	.byte 0x1D, 0x1C, 0x29, 0x78, 0x48, 0x00, 0x40, 0x18, 0x40, 0x00, 0x31, 0x49, 0x40, 0x18, 0x11, 0x88
	.byte 0x40, 0x18, 0x10, 0x80, 0x00, 0x20, 0x11, 0x5E, 0x08, 0x1C, 0x00, 0x29, 0x01, 0xDA, 0x2A, 0x4A
	.byte 0x88, 0x18, 0x40, 0x12, 0x40, 0x02, 0x08, 0x1A, 0x20, 0x80, 0x00, 0x04, 0x01, 0x0C, 0x27, 0x48
	.byte 0x81, 0x42, 0x02, 0xD8, 0x28, 0x78, 0x00, 0x28, 0x06, 0xD0, 0xC0, 0x20, 0x40, 0x00, 0x81, 0x42
	.byte 0x07, 0xD9, 0x18, 0x78, 0x01, 0x28, 0x04, 0xD1, 0x00, 0x2F, 0x02, 0xD1, 0x01, 0x20, 0x70, 0x73
	.byte 0xB0, 0x73, 0x30, 0x1C, 0xFE, 0xF7, 0xC6, 0xFD
_080470F8:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804714E
	ldr r5, _08047174 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08047178 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _0804717C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08047180 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_0804714E:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047168:
	.byte 0xFF, 0x01, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00
	.byte 0xFD, 0xFF, 0x00, 0x00
_08047174: .4byte RNG_0202f388
_08047178: .4byte 0x000343FD
_0804717C: .4byte 0x00269EC3
_08047180: .4byte 0xFFFFFC00

	thumb_func_start babyelf_08047184
babyelf_08047184: @ 0x08047184
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r4, [r6, #0x28]
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _08047194
	b _080472BA
_08047194:
	lsls r0, r0, #2
	ldr r1, _080471A0 @ =_080471A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080471A0: .4byte _080471A4
_080471A4: @ jump table
	.4byte _080471BC @ case 0
	.4byte _080471F0 @ case 1
	.4byte _08047210 @ case 2
	.4byte _08047260 @ case 3
	.4byte _08047276 @ case 4
	.4byte _080472AE @ case 5
_080471BC:
	adds r1, r6, #0
	adds r1, #0xc9
	movs r0, #0
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0xc4
	adds r0, r6, #0
	adds r0, #0xc7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080471EC @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804724A
	b _08047244
	.align 2, 0
_080471EC: .4byte 0x0000FFFD
_080471F0:
	adds r2, r6, #0
	adds r2, #0xc4
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r1, #0
	cmp r1, #0
	bge _08047202
	ldr r3, _08047254 @ =0x000001FF
	adds r0, r1, r3
_08047202:
	asrs r0, r0, #9
	lsls r0, r0, #9
	subs r0, r1, r0
	strh r0, [r2]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047210:
	adds r2, r6, #0
	adds r2, #0xc4
	adds r3, r6, #0
	adds r3, #0xc7
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08047258 @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0804725C @ =0x0000FE7F
	cmp r1, r0
	bhi _0804723A
	ldrb r0, [r3]
	cmp r0, #0
	beq _08047244
_0804723A:
	cmp r1, #0x80
	bls _0804724A
	ldrb r0, [r3]
	cmp r0, #1
	bne _0804724A
_08047244:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804724A:
	adds r0, r6, #0
	bl babyelf_08045c84
	b _080472BA
	.align 2, 0
_08047254: .4byte 0x000001FF
_08047258: .4byte 0x0000FFFD
_0804725C: .4byte 0x0000FE7F
_08047260:
	movs r0, #0x8a
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0
	str r0, [r6, #0x64]
	movs r0, #8
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047276:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080472BA
	ldr r1, [r6, #0x54]
	ldr r2, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xc7
	ldrb r3, [r0]
	adds r0, r4, #0
	bl babyelf_0809f9f0
	movs r0, #8
	strb r0, [r6, #0x13]
	ldr r0, [r6, #0x64]
	adds r0, #1
	str r0, [r6, #0x64]
	cmp r0, #3
	ble _080472BA
	adds r1, r6, #0
	adds r1, #0xc9
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080472B8
_080472AE:
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _080472BA
	movs r0, #1
	strb r0, [r6, #0xd]
_080472B8:
	strb r0, [r6, #0xe]
_080472BA:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08047310
	ldr r5, _08047328 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _0804732C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08047330 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08047334 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08047310:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08047328: .4byte RNG_0202f388
_0804732C: .4byte 0x000343FD
_08047330: .4byte 0x00269EC3
_08047334: .4byte 0xFFFFFC00

	thumb_func_start babyelf_08047338
babyelf_08047338: @ 0x08047338
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #4
	bls _08047346
	b _08047518
_08047346:
	lsls r0, r0, #2
	ldr r1, _08047350 @ =_08047354
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08047350: .4byte _08047354
_08047354: @ jump table
	.4byte _08047368 @ case 0
	.4byte _08047376 @ case 1
	.4byte _080473C0 @ case 2
	.4byte _080473EE @ case 3
	.4byte _080474F4 @ case 4
_08047368:
	adds r1, r6, #0
	adds r1, #0xc4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047376:
	adds r2, r6, #0
	adds r2, #0xc4
	adds r3, r6, #0
	adds r3, #0xc7
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080473B8 @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r4, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080473BC @ =0x0000FF7F
	cmp r1, r0
	bhi _080473A0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080473AA
_080473A0:
	cmp r1, #0x80
	bls _080473B0
	ldrb r0, [r3]
	cmp r0, #1
	bne _080473B0
_080473AA:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080473B0:
	adds r0, r6, #0
	bl babyelf_08045c84
	b _08047518
	.align 2, 0
_080473B8: .4byte 0x0000FFFD
_080473BC: .4byte 0x0000FF7F
_080473C0:
	movs r0, #0
	strb r0, [r6, #0x13]
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080473EE:
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08047416
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0x13]
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r6, #0x13]
	cmp r0, #0xf
	bhi _0804740E
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	b _08047414
_0804740E:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x18
_08047414:
	strb r0, [r1]
_08047416:
	ldr r7, [r6, #0x5c]
	asrs r0, r7, #8
	lsls r0, r0, #0x18
	ldr r2, _080474DC @ =gSineTable
	lsrs r1, r0, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x17
	adds r0, r0, r3
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r4, #0
	ldrsh r5, [r0, r4]
	ldr r4, [r6, #0x64]
	adds r0, r5, #0
	muls r0, r4, r0
	cmp r0, #0
	bge _0804743A
	adds r0, #0xff
_0804743A:
	asrs r3, r0, #8
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, [r6, #0x68]
	adds r0, r1, #0
	muls r0, r2, r0
	cmp r0, #0
	bge _08047450
	adds r0, #0xff
_08047450:
	asrs r0, r0, #8
	adds r3, r3, r0
	adds r0, r1, #0
	muls r0, r4, r0
	cmp r0, #0
	bge _0804745E
	adds r0, #0xff
_0804745E:
	asrs r0, r0, #8
	rsbs r1, r0, #0
	adds r0, r5, #0
	muls r0, r2, r0
	cmp r0, #0
	bge _0804746C
	adds r0, #0xff
_0804746C:
	asrs r0, r0, #8
	adds r2, r1, r0
	adds r0, r7, #0
	adds r0, #0x14
	str r0, [r6, #0x5c]
	str r3, [r6, #0x64]
	str r2, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r0, r0, r3
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r4, _080474E0 @ =0xFFFFB000
	adds r1, r2, r4
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	lsls r0, r3, #5
	subs r0, r0, r3
	lsls r0, r0, #3
	cmp r0, #0
	bge _0804749E
	adds r0, #0xff
_0804749E:
	asrs r3, r0, #8
	str r3, [r6, #0x64]
	lsls r0, r2, #5
	subs r0, r0, r2
	lsls r0, r0, #3
	cmp r0, #0
	bge _080474AE
	adds r0, #0xff
_080474AE:
	asrs r1, r0, #8
	str r1, [r6, #0x68]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r2, _080474E4 @ =0x000003FF
	cmp r0, r2
	bhi _08047518
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r1, r3
	cmp r0, r2
	bhi _08047518
	ldrb r4, [r6, #0x10]
	cmp r4, #0
	bne _080474EC
	ldr r0, _080474E8 @ =0x00000117
	bl PlaySound
	movs r0, #8
	strb r0, [r6, #0xd]
	strb r4, [r6, #0xe]
	b _08047518
	.align 2, 0
_080474DC: .4byte gSineTable
_080474E0: .4byte 0xFFFFB000
_080474E4: .4byte 0x000003FF
_080474E8: .4byte 0x00000117
_080474EC:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _08047518
_080474F4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804758C @ =0x0836265C
	bl SetDDP
	adds r4, r6, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08047518
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_08047518:
	ldrb r0, [r6, #0xe]
	cmp r0, #4
	beq _08047584
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08047574
	ldr r5, _08047590 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08047594 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08047598 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _0804759C @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08047574:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08047584:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804758C: .4byte 0x0836265C
_08047590: .4byte RNG_0202f388
_08047594: .4byte 0x000343FD
_08047598: .4byte 0x00269EC3
_0804759C: .4byte 0xFFFFFC00

	thumb_func_start babyelf_080475a0
babyelf_080475a0: @ 0x080475A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _080475AE
	b _080477AE
_080475AE:
	lsls r0, r0, #2
	ldr r1, _080475BC @ =0x080475C0
	adds r0, r0, r1
	ldr r0, [r0]
	adds r6, r5, #0
	adds r6, #0xc6
	mov pc, r0
	.align 2, 0
_080475BC: .4byte 0x080475C0
_080475C0:
	.byte 0xE0, 0x75, 0x04, 0x08, 0x48, 0x76, 0x04, 0x08, 0x74, 0x76, 0x04, 0x08, 0xB8, 0x76, 0x04, 0x08
	.byte 0xCE, 0x76, 0x04, 0x08, 0x24, 0x77, 0x04, 0x08, 0x54, 0x77, 0x04, 0x08, 0x62, 0x77, 0x04, 0x08
	.byte 0x28, 0x1C, 0x74, 0x30, 0x20, 0x49, 0xBF, 0xF7, 0x15, 0xFE, 0x29, 0x1C, 0x25, 0x31, 0x18, 0x20
	.byte 0x08, 0x70, 0x28, 0x1C, 0xB4, 0x30, 0x00, 0x68, 0x68, 0x65, 0x28, 0x1C, 0xB8, 0x30, 0x00, 0x68
	.byte 0x1A, 0x49, 0x40, 0x18, 0xA8, 0x65, 0x1A, 0x49, 0x28, 0x1C, 0xCF, 0xF7, 0xAD, 0xFF, 0x28, 0x1C
	.byte 0xC6, 0x30, 0x01, 0x78, 0x06, 0x1C, 0x00, 0x29, 0x04, 0xD0, 0x30, 0x78, 0xBC, 0xF7, 0x4A, 0xFD
	.byte 0x00, 0x20, 0x30, 0x70, 0x28, 0x1C, 0xD0, 0xF7, 0xE5, 0xF9, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C
	.byte 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C, 0x01, 0x43, 0x1B, 0x20, 0xBC, 0xF7, 0x77, 0xFC, 0x1B, 0x20
	.byte 0x30, 0x70, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x30, 0x78, 0xBC, 0xF7, 0x0D, 0xFD, 0x28, 0x1C
	.byte 0xD0, 0xF7, 0x04, 0xF8, 0x28, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x00, 0xD0, 0xA6, 0xE0
	.byte 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0xA2, 0xE0, 0xA4, 0x26, 0x36, 0x08, 0x00, 0xB0, 0xFF, 0xFF
	.byte 0x09, 0x33, 0x00, 0x00, 0xD0, 0x21, 0x89, 0x01, 0x28, 0x1C, 0xCF, 0xF7, 0x75, 0xFF, 0x28, 0x1C
	.byte 0xC6, 0x30, 0x01, 0x78, 0x06, 0x1C, 0x00, 0x29, 0x04, 0xD0, 0x30, 0x78, 0xBC, 0xF7, 0x12, 0xFD
	.byte 0x00, 0x20, 0x30, 0x70, 0x28, 0x1C, 0xD0, 0xF7, 0xAD, 0xF9, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C
	.byte 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C, 0x01, 0x43, 0x1D, 0x20, 0xBC, 0xF7, 0x3F, 0xFC, 0x1D, 0x20
	.byte 0x30, 0x70, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x30, 0x78, 0xBC, 0xF7, 0xD5, 0xFC, 0x00, 0x06
	.byte 0x00, 0x0E, 0x03, 0x28, 0x42, 0xD1, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x3E, 0xE0, 0x10, 0x20
	.byte 0xE8, 0x74, 0x00, 0x24, 0x2E, 0x1C, 0xC6, 0x36, 0x69, 0x6D, 0xAA, 0x6D, 0x60, 0x07, 0x00, 0x0E
	.byte 0x00, 0x90, 0x28, 0x1C, 0xE0, 0x23, 0x5B, 0x00, 0x74, 0xF0, 0xE0, 0xFF, 0x01, 0x34, 0x07, 0x2C
	.byte 0xF2, 0xDD, 0x30, 0x78, 0x00, 0x28, 0x03, 0xD0, 0xBC, 0xF7, 0xDC, 0xFC, 0x00, 0x20, 0x30, 0x70
	.byte 0x28, 0x1C, 0xD0, 0xF7, 0x77, 0xF9, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00
	.byte 0x10, 0x1C, 0x01, 0x43, 0x1E, 0x20, 0xBC, 0xF7, 0x09, 0xFC, 0x1E, 0x20, 0x30, 0x70, 0xA8, 0x7B
	.byte 0x01, 0x30, 0xA8, 0x73, 0xE8, 0x7C, 0x01, 0x38, 0xE8, 0x74, 0x00, 0x06, 0x01, 0x0E, 0x00, 0x29
	.byte 0x09, 0xD1, 0x68, 0x7C, 0x01, 0x28, 0x03, 0xD1, 0x10, 0x20, 0x68, 0x73, 0xA9, 0x73, 0x02, 0xE0
	.byte 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x30, 0x78, 0xBC, 0xF7, 0x8E, 0xFC, 0x28, 0x1C, 0xCF, 0xF7
	.byte 0x85, 0xFF, 0x2C, 0xE0, 0x00, 0x21, 0x34, 0x20, 0xE8, 0x74, 0x29, 0x66, 0xA8, 0x7B, 0x01, 0x30
	.byte 0xA8, 0x73, 0x2C, 0x1C, 0xC6, 0x34, 0x20, 0x78, 0xBC, 0xF7, 0x7E, 0xFC, 0x28, 0x1C, 0xCF, 0xF7
	.byte 0x75, 0xFF, 0xE8, 0x7C, 0x26, 0x1C, 0x1A, 0x28, 0x02, 0xD9, 0x28, 0x6E, 0x0D, 0x38, 0x01, 0xE0
	.byte 0x28, 0x6E, 0x0D, 0x30, 0x28, 0x66, 0xE8, 0x7C, 0x01, 0x38, 0xE8, 0x74, 0x00, 0x06, 0x01, 0x0E
	.byte 0x00, 0x29, 0x02, 0xD1, 0x09, 0x20, 0x68, 0x73, 0xA9, 0x73, 0xA8, 0x6D, 0x29, 0x6E, 0x40, 0x18
	.byte 0xA8, 0x65, 0x30, 0x78, 0xBC, 0xF7, 0x60, 0xFC, 0x28, 0x1C, 0xCF, 0xF7, 0x57, 0xFF
_080477AE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start babyelf_080477b8
babyelf_080477b8: @ 0x080477B8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r3, [r6, #0xe]
	cmp r3, #0
	beq _080477C8
	cmp r3, #1
	beq _080477F0
	b _080478A8
_080477C8:
	adds r0, r6, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xca
	movs r2, #0
	strh r0, [r1]
	subs r1, #0xe
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc4
	strh r3, [r0]
	strb r2, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080477F0:
	adds r4, r6, #0
	adds r4, #0xc4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r2, [r0]
	str r2, [r6, #0x54]
	adds r0, #4
	ldr r3, [r0]
	str r3, [r6, #0x58]
	ldr r5, _080478B0 @ =gSineTable
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r2, r2, r0
	str r2, [r6, #0x54]
	ldrh r0, [r4]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	subs r3, r3, r0
	str r3, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #0x60
	bl __umodsi3
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0xca
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r6, #0
	adds r1, #0xa4
	movs r7, #0
	ldrsh r1, [r1, r7]
	subs r0, r0, r1
	cmp r0, #0xf
	bgt _08047876
	ldr r0, _080478B4 @ =pZero2
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08047876
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804787E
_08047876:
	movs r1, #0
	movs r0, #0xa
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_0804787E:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	bne _08047898
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, [r6, #0x54]
	ldr r2, [r6, #0x58]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0809fa44
_08047898:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080478A8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080478B0: .4byte gSineTable
_080478B4: .4byte pZero2

	thumb_func_start FUN_080478b8
FUN_080478b8: @ 0x080478B8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x2c]
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _0804790C
	cmp r4, #1
	bgt _080478CE
	cmp r4, #0
	beq _080478D8
	b _080479C4
_080478CE:
	cmp r4, #2
	beq _0804792C
	cmp r4, #3
	beq _08047984
	b _080479C4
_080478D8:
	adds r6, r5, #0
	adds r6, #0xc6
	ldrb r0, [r6]
	cmp r0, #0
	beq _080478E8
	bl ClearBlink
	strb r4, [r6]
_080478E8:
	adds r0, r5, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x1f
	bl LoadBlink
	movs r0, #0x1f
	strb r0, [r6]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804790C:
	adds r0, r5, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08047924
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08047924:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080479C4
_0804792C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080479CC @ =0x08362674
	bl SetDDP
	adds r0, r6, #0
	adds r0, #0x22
	movs r7, #0
	strb r7, [r0]
	ldr r4, _080479D0 @ =0x0000330A
	adds r0, r6, #0
	adds r1, r4, #0
	bl SetMotion
	adds r0, r5, #0
	adds r1, r4, #0
	bl SetMotion
	adds r4, r5, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08047960
	bl ClearBlink
	strb r7, [r4]
_08047960:
	adds r0, r5, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x1c
	bl LoadBlink
	movs r0, #0x1c
	strb r0, [r4]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08047984:
	adds r4, r5, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080479B8
	ldrb r0, [r4]
	cmp r0, #0
	beq _080479A4
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_080479A4:
	movs r2, #0
	movs r1, #0xb
	strb r1, [r6, #0xd]
	strb r2, [r6, #0xe]
	ldr r0, [r5, #0x54]
	str r0, [r6, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r6, #0x58]
	strb r1, [r5, #0xd]
	strb r2, [r5, #0xe]
_080479B8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080479C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080479CC: .4byte 0x08362674
_080479D0: .4byte 0x0000330A

	thumb_func_start babyelf_080479d4
babyelf_080479d4: @ 0x080479D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	beq _08047A90
	cmp r0, #1
	bgt _080479EE
	cmp r0, #0
	beq _080479FC
	b _08047BF6
_080479EE:
	cmp r0, #2
	bne _080479F4
	b _08047B08
_080479F4:
	cmp r0, #3
	bne _080479FA
	b _08047B6C
_080479FA:
	b _08047BF6
_080479FC:
	ldr r0, _08047A48 @ =0x00000117
	bl PlaySound
	mov r0, r8
	adds r0, #0x74
	ldr r1, _08047A4C @ =0x08362674
	bl SetDDP
	mov r1, r8
	ldrb r0, [r1, #0x10]
	adds r1, #0x22
	strb r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #6
	mov r0, r8
	bl SetMotion
	mov r2, r8
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	bne _08047A50
	mov r0, r8
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x16
	bl LoadBlink
	mov r1, r8
	adds r1, #0xc6
	movs r0, #0x16
	b _08047A70
	.align 2, 0
_08047A48: .4byte 0x00000117
_08047A4C: .4byte 0x08362674
_08047A50:
	mov r0, r8
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r6, #0
	orrs r1, r0
	movs r0, #0x11
	bl LoadBlink
	mov r1, r8
	adds r1, #0xc6
	movs r0, #0x11
_08047A70:
	strb r0, [r1]
	mov r0, r8
	ldrb r1, [r0, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	mov r1, r8
	strb r0, [r1, #0xa]
	ldrb r0, [r1, #0x10]
	adds r1, #0xc7
	strb r0, [r1]
	mov r3, r8
	strb r2, [r3, #0x12]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_08047A90:
	mov r0, r8
	adds r0, #0xb4
	ldr r0, [r0]
	mov r6, r8
	ldr r5, [r6, #0x54]
	subs r6, r0, r5
	ldr r0, _08047B04 @ =0xFFFFA800
	adds r6, r6, r0
	mov r0, r8
	adds r0, #0xc7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0xc
	adds r6, r6, r0
	mov r0, r8
	adds r0, #0xb8
	mov r1, r8
	ldr r4, [r1, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r1, r4, r2
	ldr r0, [r0]
	subs r7, r0, r1
	adds r0, r6, #0
	movs r1, #0xc
	bl __divsi3
	adds r6, r0, #0
	adds r0, r7, #0
	movs r1, #0xc
	bl __divsi3
	adds r7, r0, #0
	adds r5, r5, r6
	mov r3, r8
	str r5, [r3, #0x54]
	adds r4, r4, r7
	str r4, [r3, #0x58]
	mov r0, r8
	bl UpdateMotionGraphic
	mov r0, r8
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08047BF6
	mov r6, r8
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _08047BF4
	.align 2, 0
_08047B04: .4byte 0xFFFFA800
_08047B08:
	movs r0, #0x28
	mov r1, r8
	strb r0, [r1, #0x13]
	mov r4, r8
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08047B20
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_08047B20:
	mov r2, r8
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	bne _08047B46
	mov r0, r8
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x14
	bl LoadBlink
	movs r0, #0x14
	b _08047B62
_08047B46:
	mov r0, r8
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r6, #0
	orrs r1, r0
	movs r0, #0xf
	bl LoadBlink
	movs r0, #0xf
_08047B62:
	strb r0, [r4]
	mov r1, r8
	ldrb r0, [r1, #0xe]
	adds r0, #1
	strb r0, [r1, #0xe]
_08047B6C:
	mov r0, r8
	adds r0, #0xb4
	ldr r0, [r0]
	mov r2, r8
	ldr r5, [r2, #0x54]
	subs r6, r0, r5
	ldr r3, _08047C5C @ =0xFFFFA800
	adds r6, r6, r3
	mov r0, r8
	adds r0, #0xc7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0xc
	adds r6, r6, r0
	mov r0, r8
	adds r0, #0xb8
	ldr r4, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r1, r4, r2
	ldr r0, [r0]
	subs r7, r0, r1
	adds r0, r6, #0
	movs r1, #0xc
	bl __divsi3
	adds r6, r0, #0
	adds r0, r7, #0
	movs r1, #0xc
	bl __divsi3
	adds r7, r0, #0
	adds r5, r5, r6
	mov r3, r8
	str r5, [r3, #0x54]
	adds r4, r4, r7
	str r4, [r3, #0x58]
	mov r0, r8
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	mov r0, r8
	bl UpdateMotionGraphic
	mov r6, r8
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08047BF6
	mov r1, r8
	adds r1, #0xbc
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	mov r0, r8
	adds r0, #0xc4
	strh r2, [r0]
	movs r0, #1
	strb r0, [r6, #0xd]
_08047BF4:
	strb r0, [r6, #0xe]
_08047BF6:
	mov r1, r8
	ldrb r0, [r1, #0x12]
	adds r0, #1
	strb r0, [r1, #0x12]
	ldrb r0, [r1, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08047C50
	ldr r5, _08047C60 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08047C64 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08047C68 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r6, _08047C6C @ =0xFFFFFC00
	adds r1, r1, r6
	mov r6, r8
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08047C50:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047C5C: .4byte 0xFFFFA800
_08047C60: .4byte RNG_0202f388
_08047C64: .4byte 0x000343FD
_08047C68: .4byte 0x00269EC3
_08047C6C: .4byte 0xFFFFFC00

	thumb_func_start babyelf_08047c70
babyelf_08047c70: @ 0x08047C70
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08047C82
	cmp r0, #1
	beq _08047CEC
	b _08047E0C
_08047C82:
	ldr r2, _08047CA8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08047CAC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08047CB0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08047CB4
	movs r0, #0x8a
	lsls r0, r0, #1
	bl PlaySound
	b _08047CBA
	.align 2, 0
_08047CA8: .4byte RNG_0202f388
_08047CAC: .4byte 0x000343FD
_08047CB0: .4byte 0x00269EC3
_08047CB4:
	ldr r0, _08047E14 @ =0x00000115
	bl PlaySound
_08047CBA:
	adds r1, r6, #0
	adds r1, #0xbc
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r1]
	adds r1, #4
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _08047E18 @ =0xFFFFB000
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc7
	ldrb r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0xf
	str r0, [r6, #0x64]
	movs r0, #0
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047CEC:
	ldr r0, [r6, #0x68]
	adds r0, #8
	str r0, [r6, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08047CFC
	str r1, [r6, #0x68]
_08047CFC:
	ldr r2, [r6, #0x64]
	ldr r0, [r6, #0x68]
	subs r2, r2, r0
	str r2, [r6, #0x64]
	movs r3, #0xc7
	adds r3, r3, r6
	mov ip, r3
	ldrb r1, [r3]
	movs r3, #1
	subs r1, r3, r1
	lsls r1, r1, #7
	movs r0, #0xc0
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08047D28
	str r0, [r6, #0x64]
	movs r0, #0
	strb r3, [r6, #0xd]
	strb r0, [r6, #0xe]
_08047D28:
	movs r4, #0xb0
	lsls r4, r4, #7
	str r4, [r6, #0x5c]
	ldr r5, [r6, #0x64]
	asrs r1, r5, #8
	mov r2, ip
	ldrb r0, [r2]
	subs r0, r3, r0
	lsls r0, r0, #7
	ldr r7, _08047E1C @ =gSineTable
	subs r0, r0, r1
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r7
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r0, r4
	str r2, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r1, [r0]
	str r1, [r6, #0x54]
	asrs r5, r5, #8
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r7
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	bge _08047D78
	adds r0, #0xff
_08047D78:
	asrs r0, r0, #8
	adds r0, r1, r0
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r3, [r0]
	str r3, [r6, #0x58]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r7
	movs r4, #0
	ldrsh r1, [r0, r4]
	asrs r0, r2, #1
	muls r0, r1, r0
	cmp r0, #0
	bge _08047D9A
	adds r0, #0xff
_08047D9A:
	asrs r0, r0, #8
	adds r0, r3, r0
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08047DFC
	ldr r5, _08047E20 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08047E24 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08047E28 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08047E2C @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08047DFC:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08047E0C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047E14: .4byte 0x00000115
_08047E18: .4byte 0xFFFFB000
_08047E1C: .4byte gSineTable
_08047E20: .4byte RNG_0202f388
_08047E24: .4byte 0x000343FD
_08047E28: .4byte 0x00269EC3
_08047E2C: .4byte 0xFFFFFC00

	thumb_func_start babyelf_08047e30
babyelf_08047e30: @ 0x08047E30
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08047E98
	cmp r0, #1
	bgt _08047E46
	cmp r0, #0
	beq _08047E52
	b _08047F74
_08047E46:
	cmp r0, #2
	beq _08047F40
	cmp r0, #3
	bne _08047E50
	b _08047F60
_08047E50:
	b _08047F74
_08047E52:
	ldr r2, _08047E78 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08047E7C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08047E80 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08047E84
	movs r0, #0x8a
	lsls r0, r0, #1
	bl PlaySound
	b _08047E8A
	.align 2, 0
_08047E78: .4byte RNG_0202f388
_08047E7C: .4byte 0x000343FD
_08047E80: .4byte 0x00269EC3
_08047E84:
	ldr r0, _08047F2C @ =0x00000115
	bl PlaySound
_08047E8A:
	movs r1, #0
	movs r0, #0x30
	strb r0, [r6, #0x13]
	str r1, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047E98:
	ldr r1, [r6, #0x5c]
	subs r1, #0x10
	str r1, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	lsls r0, r0, #5
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08047EC2
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047EC2:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08047F18
	ldr r5, _08047F30 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08047F34 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08047F38 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08047F3C @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08047F18:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _08047F74
	.align 2, 0
_08047F2C: .4byte 0x00000115
_08047F30: .4byte RNG_0202f388
_08047F34: .4byte 0x000343FD
_08047F38: .4byte 0x00269EC3
_08047F3C: .4byte 0xFFFFFC00
_08047F40:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08047F7C @ =0x0836265C
	bl SetDDP
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, _08047F80 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #0x30
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08047F60:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08047F74
	movs r0, #0xe
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_08047F74:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08047F7C: .4byte 0x0836265C
_08047F80: .4byte 0xFFFFE000

	thumb_func_start FUN_08047f84
FUN_08047f84: @ 0x08047F84
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _08047F92
	b _0804810C
_08047F92:
	lsls r0, r0, #2
	ldr r1, _08047FA0 @ =0x08047FA4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r6, #0
	adds r4, #0xc7
	mov pc, r0
	.align 2, 0
_08047FA0: .4byte 0x08047FA4
_08047FA4:
	.byte 0xBC, 0x7F, 0x04, 0x08, 0xE2, 0x7F, 0x04, 0x08, 0x34, 0x80, 0x04, 0x08
	.byte 0x54, 0x80, 0x04, 0x08, 0xBC, 0x80, 0x04, 0x08, 0xC2, 0x80, 0x04, 0x08, 0xC0, 0x22, 0x92, 0x00
	.byte 0xF2, 0x65, 0x34, 0x1C, 0xC7, 0x34, 0x21, 0x78, 0x48, 0x00, 0x40, 0x18, 0x40, 0x02, 0x12, 0x1A
	.byte 0xF2, 0x65, 0x30, 0x1C, 0x74, 0x30, 0x15, 0x49, 0xBF, 0xF7, 0x1C, 0xF9, 0xB0, 0x7B, 0x01, 0x30
	.byte 0xB0, 0x73, 0x70, 0x6D, 0xF1, 0x6D, 0x41, 0x18, 0x71, 0x65, 0x20, 0x78, 0x00, 0x28, 0x0A, 0xD1
	.byte 0x30, 0x1C, 0xB4, 0x30, 0x00, 0x68, 0x0E, 0x4A, 0x80, 0x18, 0x81, 0x42, 0x03, 0xDD, 0x70, 0x65
	.byte 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x20, 0x78, 0x01, 0x28, 0x00, 0xD0, 0x7E, 0xE0, 0x30, 0x1C
	.byte 0xB4, 0x30, 0x00, 0x68, 0xA0, 0x23, 0xDB, 0x01, 0xC1, 0x18, 0x70, 0x6D, 0x88, 0x42, 0x75, 0xDA
	.byte 0x71, 0x65, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x70, 0xE0, 0x00, 0x00, 0x74, 0x26, 0x36, 0x08
	.byte 0x00, 0xB0, 0xFF, 0xFF, 0x40, 0x20, 0xF0, 0x74, 0x2A, 0x20, 0x70, 0x66, 0x31, 0x1C, 0xBC, 0x31
	.byte 0x70, 0x6D, 0x08, 0x60, 0x04, 0x31, 0xB0, 0x6D, 0x0A, 0x4A, 0x80, 0x18, 0x08, 0x60, 0xB0, 0x7B
	.byte 0x01, 0x30, 0xB0, 0x73, 0x70, 0x6E, 0x01, 0x38, 0x70, 0x66, 0x00, 0x28, 0x02, 0xD1, 0xB0, 0x7B
	.byte 0x01, 0x30, 0xB0, 0x73, 0x30, 0x1C, 0xC7, 0x30, 0x00, 0x78, 0x00, 0x28, 0x04, 0xD1, 0xF0, 0x7C
	.byte 0x06, 0x38, 0x03, 0xE0, 0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0x7C, 0x06, 0x30, 0xF0, 0x74, 0x30, 0x1C
	.byte 0xBC, 0x30, 0x01, 0x68, 0x71, 0x65, 0x0C, 0x4A, 0xF0, 0x7C, 0x40, 0x30, 0x00, 0x06, 0xC0, 0x0D
	.byte 0x80, 0x18, 0x00, 0x23, 0xC0, 0x5E, 0x00, 0x01, 0x09, 0x18, 0x71, 0x65, 0x30, 0x1C, 0xC0, 0x30
	.byte 0x01, 0x68, 0xB1, 0x65, 0xF0, 0x7C, 0x40, 0x00, 0x80, 0x18, 0x00, 0x22, 0x80, 0x5E, 0x00, 0x01
	.byte 0x09, 0x18, 0xB1, 0x65, 0x2A, 0xE0, 0x00, 0x00, 0x74, 0xEA, 0x0F, 0x08, 0xB0, 0x7B, 0x01, 0x30
	.byte 0xB0, 0x73, 0x70, 0x6D, 0xF1, 0x6D, 0x41, 0x18, 0x71, 0x65, 0x30, 0x1C, 0xC7, 0x30, 0x02, 0x78
	.byte 0x04, 0x1C, 0x00, 0x2A, 0x09, 0xD1, 0x13, 0x38, 0x00, 0x68, 0x28, 0x4B, 0xC0, 0x18, 0x81, 0x42
	.byte 0x03, 0xDD, 0x70, 0x65, 0x0F, 0x20, 0x70, 0x73, 0xB2, 0x73, 0x20, 0x78, 0x01, 0x28, 0x0D, 0xD1
	.byte 0x30, 0x1C, 0xB4, 0x30, 0x00, 0x68, 0x80, 0x22, 0x52, 0x01, 0x81, 0x18, 0x70, 0x6D, 0x88, 0x42
	.byte 0x04, 0xDA, 0x71, 0x65, 0x00, 0x21, 0x0F, 0x20, 0x70, 0x73, 0xB1, 0x73
_0804810C:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048162
	ldr r5, _08048180 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08048184 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048188 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _0804818C @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_08048162:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804817C:
	.byte 0x00, 0xF0, 0xFF, 0xFF
_08048180: .4byte RNG_0202f388
_08048184: .4byte 0x000343FD
_08048188: .4byte 0x00269EC3
_0804818C: .4byte 0xFFFFFC00

	thumb_func_start FUN_08048190
FUN_08048190: @ 0x08048190
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #4
	bls _0804819E
	b _08048314
_0804819E:
	lsls r0, r0, #2
	ldr r1, _080481A8 @ =_080481AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080481A8: .4byte _080481AC
_080481AC: @ jump table
	.4byte _080481C0 @ case 0
	.4byte _080481E0 @ case 1
	.4byte _08048248 @ case 2
	.4byte _08048270 @ case 3
	.4byte _080482A8 @ case 4
_080481C0:
	movs r0, #0x40
	strb r0, [r6, #0x13]
	movs r0, #0xa
	str r0, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	ldr r2, _08048200 @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080481E0:
	ldr r0, [r6, #0x64]
	subs r0, #1
	str r0, [r6, #0x64]
	cmp r0, #0
	bne _080481F0
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080481F0:
	adds r0, r6, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	cmp r0, #0
	bne _08048204
	ldrb r0, [r6, #0x13]
	subs r0, #6
	b _08048208
	.align 2, 0
_08048200: .4byte 0xFFFFF000
_08048204:
	ldrb r0, [r6, #0x13]
	adds r0, #6
_08048208:
	strb r0, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r1, [r0]
	str r1, [r6, #0x54]
	ldr r2, _08048244 @ =gSineTable
	ldrb r0, [r6, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #4
	adds r1, r1, r0
	str r1, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r1, [r0]
	str r1, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #4
	adds r1, r1, r0
	str r1, [r6, #0x58]
	b _08048314
	.align 2, 0
_08048244: .4byte gSineTable
_08048248:
	ldr r1, [r6, #0x58]
	ldr r0, _08048268 @ =0xFFFFFD00
	adds r1, r1, r0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _0804826C @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	bge _08048314
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _08048314
	.align 2, 0
_08048268: .4byte 0xFFFFFD00
_0804826C: .4byte 0xFFFFB000
_08048270:
	adds r1, r6, #0
	adds r1, #0xc7
	ldrb r0, [r1]
	lsls r0, r0, #7
	strb r0, [r6, #0x13]
	movs r0, #0x2a
	str r0, [r6, #0x64]
	adds r3, r6, #0
	adds r3, #0xbc
	ldr r2, [r6, #0x54]
	ldr r4, _080482C8 @ =0xFFFFD400
	adds r2, r2, r4
	str r2, [r3]
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0xb
	adds r2, r2, r0
	str r2, [r3]
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r6, #0x58]
	str r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080482A8:
	ldr r0, [r6, #0x64]
	subs r1, r0, #1
	str r1, [r6, #0x64]
	cmp r1, #0
	bne _080482B8
	movs r0, #1
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_080482B8:
	adds r0, r6, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	cmp r0, #0
	bne _080482CC
	ldrb r0, [r6, #0x13]
	subs r0, #3
	b _080482D0
	.align 2, 0
_080482C8: .4byte 0xFFFFD400
_080482CC:
	ldrb r0, [r6, #0x13]
	adds r0, #3
_080482D0:
	strb r0, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r2, [r0]
	str r2, [r6, #0x54]
	ldr r3, _08048384 @ =gSineTable
	ldrb r0, [r6, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r2, r2, r0
	str r2, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r2, [r0]
	str r2, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _08048388 @ =0x00001D55
	muls r0, r1, r0
	cmp r0, #0
	bge _0804830E
	adds r0, #0xff
_0804830E:
	asrs r0, r0, #8
	adds r0, r2, r0
	str r0, [r6, #0x58]
_08048314:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804836A
	ldr r5, _0804838C @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08048390 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048394 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08048398 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	movs r1, #0x80
	lsls r1, r1, #4
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	ldrb r2, [r6, #0x10]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_080bc594
_0804836A:
	adds r0, r6, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl UpdateMotionGraphic
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08048384: .4byte gSineTable
_08048388: .4byte 0x00001D55
_0804838C: .4byte RNG_0202f388
_08048390: .4byte 0x000343FD
_08048394: .4byte 0x00269EC3
_08048398: .4byte 0xFFFFFC00

	thumb_func_start FUN_0804839c
FUN_0804839c: @ 0x0804839C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	bls _080483A8
	b _08048540
_080483A8:
	lsls r0, r0, #2
	ldr r1, _080483B4 @ =_080483B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080483B4: .4byte _080483B8
_080483B8: @ jump table
	.4byte _080483E4 @ case 0
	.4byte _080483FC @ case 1
	.4byte _0804840C @ case 2
	.4byte _08048430 @ case 3
	.4byte _08048454 @ case 4
	.4byte _08048472 @ case 5
	.4byte _08048494 @ case 6
	.4byte _080484B8 @ case 7
	.4byte _080484DC @ case 8
	.4byte _08048514 @ case 9
	.4byte _08048520 @ case 10
_080483E4:
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0xce
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_0809f8ac
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080483FC:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804840A
	b _08048502
_0804840A:
	b _080484FC
_0804840C:
	ldr r0, [r4, #0x54]
	ldr r1, _08048428 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r1, [r1]
	ldr r2, _0804842C @ =0xFFFFB000
	adds r1, r1, r2
	cmp r0, r1
	bge _08048502
	str r1, [r4, #0x54]
	b _080484FC
	.align 2, 0
_08048428: .4byte 0xFFFFFE80
_0804842C: .4byte 0xFFFFB000
_08048430:
	ldr r0, [r4, #0x58]
	ldr r1, _0804844C @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	ldr r2, _08048450 @ =0xFFFF8800
	adds r1, r1, r2
	cmp r0, r1
	bge _08048502
	str r1, [r4, #0x58]
	b _080484FC
	.align 2, 0
_0804844C: .4byte 0xFFFFFE80
_08048450: .4byte 0xFFFF8800
_08048454:
	ldr r0, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r1, [r1]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r1, r1, r2
	cmp r0, r1
	ble _08048502
	str r1, [r4, #0x54]
	b _080484FC
_08048472:
	ldr r0, [r4, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	ldr r2, _08048490 @ =0xFFFFC900
	adds r1, r1, r2
	cmp r0, r1
	ble _08048502
	str r1, [r4, #0x58]
	b _080484FC
	.align 2, 0
_08048490: .4byte 0xFFFFC900
_08048494:
	ldr r0, [r4, #0x54]
	ldr r1, _080484B0 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r1, [r1]
	ldr r2, _080484B4 @ =0xFFFFB000
	adds r1, r1, r2
	cmp r0, r1
	bge _08048502
	str r1, [r4, #0x54]
	b _080484FC
	.align 2, 0
_080484B0: .4byte 0xFFFFFE80
_080484B4: .4byte 0xFFFFB000
_080484B8:
	ldr r0, [r4, #0x58]
	ldr r1, _080484D4 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	ldr r2, _080484D8 @ =0xFFFF8800
	adds r1, r1, r2
	cmp r0, r1
	bge _08048502
	str r1, [r4, #0x58]
	b _080484FC
	.align 2, 0
_080484D4: .4byte 0xFFFFFE80
_080484D8: .4byte 0xFFFF8800
_080484DC:
	ldr r0, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, [r2]
	cmp r0, r1
	ble _08048502
	adds r1, r4, #0
	adds r1, #0xce
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	str r0, [r4, #0x54]
_080484FC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08048502:
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08048540
_08048514:
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08048520:
	ldr r0, [r4, #0x64]
	subs r1, r0, #1
	str r1, [r4, #0x64]
	cmp r1, #0
	bne _08048530
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08048530:
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08048540:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08048548
FUN_08048548: @ 0x08048548
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	bne _080485A0
	mov r1, r8
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080485A0
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0804859C @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _08048740
	.align 2, 0
_0804859C: .4byte gBossFnTable
_080485A0:
	ldrb r1, [r6, #0xe]
	cmp r1, #1
	beq _080485FA
	cmp r1, #1
	bgt _080485B0
	cmp r1, #0
	beq _080485B8
	b _08048740
_080485B0:
	cmp r1, #2
	bne _080485B6
	b _08048738
_080485B6:
	b _08048740
_080485B8:
	movs r0, #0x78
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r0, r0, r2
	ldr r5, [r6, #0x54]
	subs r0, r0, r5
	str r0, [r6, #0x5c]
	movs r1, #0x3c
	bl __divsi3
	str r0, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldr r3, _080486A4 @ =0xFFFFD800
	adds r0, r0, r3
	ldr r4, [r6, #0x58]
	subs r0, r0, r4
	str r0, [r6, #0x60]
	movs r1, #0x32
	bl __divsi3
	str r0, [r6, #0x60]
	str r5, [r6, #0x64]
	str r4, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080485FA:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804860C
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804860C:
	ldrb r0, [r6, #0x10]
	adds r7, r0, #0
	ldr r4, [r6, #0x64]
	ldr r5, [r6, #0x68]
	cmp r7, #1
	bne _0804863C
	ldr r1, [r6, #0x28]
	ldr r0, [r1, #0x64]
	ldr r2, _080486A8 @ =0xFFFFF000
	adds r0, r0, r2
	subs r0, r0, r4
	str r0, [r6, #0x5c]
	cmp r0, #0
	bge _0804862A
	adds r0, #0xf
_0804862A:
	asrs r0, r0, #4
	str r0, [r6, #0x5c]
	ldr r0, [r1, #0x68]
	subs r0, r0, r5
	str r0, [r6, #0x60]
	movs r1, #0x1e
	bl __divsi3
	str r0, [r6, #0x60]
_0804863C:
	ldr r0, [r6, #0x5c]
	adds r0, r4, r0
	str r0, [r6, #0x64]
	ldr r1, [r6, #0x60]
	adds r1, #1
	str r1, [r6, #0x60]
	adds r1, r5, r1
	str r1, [r6, #0x68]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	lsls r0, r7, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08048664
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08048676
_08048664:
	cmp r2, #1
	bne _080486B0
	mov r3, r8
	ldr r0, [r3, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080486B0
_08048676:
	ldr r2, _080486AC @ =gSineTable
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #1
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #1
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	adds r0, #0x20
	b _080486B2
	.align 2, 0
_080486A4: .4byte 0xFFFFD800
_080486A8: .4byte 0xFFFFF000
_080486AC: .4byte gSineTable
_080486B0:
	movs r0, #0
_080486B2:
	strb r0, [r6, #0x13]
	adds r4, r6, #0
	adds r4, #0xc4
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #2
	subs r1, #2
	ldrh r0, [r4]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4]
	ldr r1, _08048724 @ =0x000001FF
	ands r0, r1
	strh r0, [r4]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrh r0, [r4]
	adds r1, r6, #0
	adds r1, #0xd1
	ldrb r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, #7
	bl __modsi3
	cmp r0, #0
	bne _08048740
	ldr r5, _08048728 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _0804872C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048730 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08048734 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0
	bl FUN_080bc540
	b _08048740
	.align 2, 0
_08048724: .4byte 0x000001FF
_08048728: .4byte RNG_0202f388
_0804872C: .4byte 0x000343FD
_08048730: .4byte 0x00269EC3
_08048734: .4byte 0xFFFFFC00
_08048738:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
_08048740:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804874c
FUN_0804874c: @ 0x0804874C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08048762
	cmp r0, #1
	bgt _08048780
	cmp r0, #0
	bne _08048780
	movs r0, #1
	strb r0, [r4, #0xe]
_08048762:
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r4, #0
	bl FUN_080d08d0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08048780
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08048780:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08048788
FUN_08048788: @ 0x08048788
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08048814
	cmp r5, #1
	bgt _0804879C
	cmp r5, #0
	beq _080487A8
	b _080488C4
_0804879C:
	cmp r5, #2
	beq _08048838
	cmp r5, #3
	bne _080487A6
	b _080488A4
_080487A6:
	b _080488C4
_080487A8:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _080487D2
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r4, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r4, #0x58]
_080487D2:
	adds r0, r4, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _08048834 @ =0x0000330A
	adds r0, r4, #0
	bl SetMotion
	adds r6, r4, #0
	adds r6, #0xc6
	ldrb r0, [r6]
	cmp r0, #0
	beq _080487F0
	bl ClearBlink
	strb r5, [r6]
_080487F0:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x1c
	bl LoadBlink
	movs r0, #0x1c
	strb r0, [r6]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08048814:
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0804882C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804882C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080488C4
	.align 2, 0
_08048834: .4byte 0x0000330A
_08048838:
	ldrb r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r5, r4, #0
	adds r5, #0xc6
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804885C
	bl ClearBlink
	movs r0, #0
	strb r0, [r5]
_0804885C:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08048880
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x16
	bl LoadBlink
	movs r0, #0x16
	b _0804889C
_08048880:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x11
	bl LoadBlink
	movs r0, #0x11
_0804889C:
	strb r0, [r5]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080488A4:
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080488BE
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080488BE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080488C4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080488cc
FUN_080488cc: @ 0x080488CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #8
	bls _080488DE
	b _08048D4A
_080488DE:
	lsls r0, r0, #2
	ldr r1, _080488E8 @ =_080488EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080488E8: .4byte _080488EC
_080488EC: @ jump table
	.4byte _08048910 @ case 0
	.4byte _0804899A @ case 1
	.4byte _080489B6 @ case 2
	.4byte _08048A08 @ case 3
	.4byte _08048AD4 @ case 4
	.4byte _08048AFE @ case 5
	.4byte _08048C14 @ case 6
	.4byte _08048C1E @ case 7
	.4byte _08048D4A @ case 8
_08048910:
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08048922
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_08048922:
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08048958
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x17
	bl LoadBlink
	movs r0, #0x17
	b _08048974
_08048958:
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x12
	bl LoadBlink
	movs r0, #0x12
_08048974:
	strb r0, [r4]
	adds r0, r7, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08048D4A
_0804899A:
	adds r0, r7, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080489AE
	b _08048BFC
_080489AE:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08048BFC
_080489B6:
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _080489C8
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_080489C8:
	adds r1, r7, #0
	adds r1, #0x22
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080489FE
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r6, #0
	orrs r1, r0
	movs r0, #0xd
	bl LoadBlink
	movs r0, #0xd
	strb r0, [r4]
_080489FE:
	movs r0, #0xa0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048A08:
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r3, [r0]
	movs r0, #0x9c
	lsls r0, r0, #7
	adds r3, r3, r0
	ldrb r1, [r7, #0x10]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xa
	adds r3, r3, r0
	ldr r4, [r7, #0x54]
	subs r3, r3, r4
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r2, [r0]
	ldr r6, _08048AC0 @ =0xFFFF9C00
	adds r2, r2, r6
	lsls r1, r1, #3
	movs r0, #0x28
	lsls r0, r1
	adds r2, r2, r0
	ldr r1, [r7, #0x58]
	subs r2, r2, r1
	adds r0, r3, #0
	cmp r3, #0
	bge _08048A40
	adds r0, #0x3f
_08048A40:
	asrs r3, r0, #6
	adds r0, r2, #0
	cmp r2, #0
	bge _08048A4A
	adds r0, #0x3f
_08048A4A:
	asrs r2, r0, #6
	adds r0, r4, r3
	str r0, [r7, #0x54]
	adds r0, r1, r2
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048A66
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048A66:
	ldrb r0, [r7, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048AAC
	ldr r5, _08048AC4 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08048AC8 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048ACC @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08048AD0 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	ldr r1, [r7, #0x58]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0
	bl FUN_080bc540
_08048AAC:
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	beq _08048AB4
	b _08048BFC
_08048AB4:
	adds r0, r7, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	b _08048BFC
	.align 2, 0
_08048AC0: .4byte 0xFFFF9C00
_08048AC4: .4byte RNG_0202f388
_08048AC8: .4byte 0x000343FD
_08048ACC: .4byte 0x00269EC3
_08048AD0: .4byte 0xFFFFFC00
_08048AD4:
	movs r5, #0
	strb r5, [r7, #0x13]
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r7, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r7, #0x58]
	str r0, [r1]
	str r5, [r7, #0x5c]
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08048AF8
	bl ClearBlink
	strb r5, [r4]
_08048AF8:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048AFE:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldr r0, [r7, #0x5c]
	adds r1, r0, #0
	adds r1, #0x60
	str r1, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0xbc
	ldr r4, [r0]
	str r4, [r7, #0x54]
	adds r0, #4
	ldr r5, [r0]
	str r5, [r7, #0x58]
	ldrb r0, [r7, #0x10]
	mov r8, r0
	mov r2, r8
	cmp r2, #0
	bne _08048B54
	ldr r3, _08048B50 @ =gSineTable
	asrs r1, r1, #8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r2, [r0, r6]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r4, r0
	str r0, [r7, #0x54]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r5, r0
	b _08048B7C
	.align 2, 0
_08048B50: .4byte gSineTable
_08048B54:
	ldr r3, _08048B94 @ =gSineTable
	asrs r1, r1, #8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r2, [r0, r6]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r0, r4, r0
	str r0, [r7, #0x54]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	subs r0, r5, r0
_08048B7C:
	str r0, [r7, #0x58]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08048B98
	ldr r1, [r7, #0x28]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	beq _08048BB0
	ldr r0, [r1, #0x18]
	b _08048BA0
	.align 2, 0
_08048B94: .4byte gSineTable
_08048B98:
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	beq _08048BB0
	ldr r0, [r7, #0x18]
_08048BA0:
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08048BB0
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048BB0:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048BFC
	ldr r5, _08048C04 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08048C08 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048C0C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r6, _08048C10 @ =0xFFFFFC00
	adds r1, r1, r6
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	ldr r1, [r7, #0x58]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0x40
	bl FUN_080bc540
_08048BFC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _08048D4A
	.align 2, 0
_08048C04: .4byte RNG_0202f388
_08048C08: .4byte 0x000343FD
_08048C0C: .4byte 0x00269EC3
_08048C10: .4byte 0xFFFFFC00
_08048C14:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048C1E:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldrb r4, [r7, #0x12]
	adds r0, r4, #0
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048CAA
	cmp r4, #0x4f
	bhi _08048CAA
	ldr r4, _08048D58 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _08048D5C @ =0x000343FD
	mov r8, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r3, _08048D60 @ =0x00269EC3
	mov sb, r3
	add r0, sb
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	adds r6, r0, #0
	mov r0, r8
	muls r0, r5, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x80
	ldr r5, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r4, _08048D64 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	bge _08048C8E
	adds r0, #0xff
_08048C8E:
	asrs r2, r0, #8
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	cmp r0, #0
	bge _08048CA2
	adds r0, #0xff
_08048CA2:
	asrs r3, r0, #8
	adds r0, r5, #0
	bl FUN_080bc540
_08048CAA:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x5a
	bne _08048CF2
	movs r0, #0x45
	bl PlaySound
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r4, #0
	ldr r5, _08048D64 @ =gSineTable
_08048CC2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	lsls r2, r4, #0x1d
	movs r6, #0x80
	lsls r6, r6, #0x17
	adds r2, r2, r6
	lsrs r2, r2, #0x17
	adds r2, r2, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	lsls r2, r2, #1
	lsls r3, r4, #0x1d
	lsrs r3, r3, #0x17
	adds r3, r3, r5
	movs r6, #0
	ldrsh r3, [r3, r6]
	lsls r3, r3, #1
	bl FUN_080bc540
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls _08048CC2
_08048CF2:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x5b
	bne _08048D2C
	movs r4, #1
	ldr r5, _08048D64 @ =gSineTable
_08048CFC:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	lsls r2, r4, #0x1d
	movs r3, #0x80
	lsls r3, r3, #0x17
	adds r2, r2, r3
	lsrs r2, r2, #0x17
	adds r2, r2, r5
	movs r6, #0
	ldrsh r2, [r2, r6]
	lsls r2, r2, #1
	lsls r3, r4, #0x1d
	lsrs r3, r3, #0x17
	adds r3, r3, r5
	movs r6, #0
	ldrsh r3, [r3, r6]
	lsls r3, r3, #1
	bl FUN_080bc540
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls _08048CFC
_08048D2C:
	movs r0, #0x12
	ldrsb r0, [r7, r0]
	cmp r0, #0
	bge _08048D44
	ldr r2, _08048D68 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048D44:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_08048D4A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08048D58: .4byte RNG_0202f388
_08048D5C: .4byte 0x000343FD
_08048D60: .4byte 0x00269EC3
_08048D64: .4byte gSineTable
_08048D68: .4byte gStageRun
