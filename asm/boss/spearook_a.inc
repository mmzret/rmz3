	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08061b68
FUN_08061b68: @ 0x08061B68
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsrs r2, r0, #8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08061B84
	rsbs r4, r4, #0
_08061B84:
	ldr r1, _08061BF4 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r6, [r0, r3]
	adds r0, r4, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _08061B9E
	adds r0, #0xff
_08061B9E:
	asrs r3, r0, #8
	str r3, [sp]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	rsbs r0, r1, #0
	muls r0, r7, r0
	cmp r0, #0
	bge _08061BB4
	adds r0, #0xff
_08061BB4:
	asrs r0, r0, #8
	adds r3, r0, r3
	str r3, [sp]
	adds r0, r4, #0
	muls r0, r1, r0
	cmp r0, #0
	bge _08061BC4
	adds r0, #0xff
_08061BC4:
	asrs r1, r0, #8
	str r1, [sp, #4]
	adds r0, r7, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _08061BD2
	adds r0, #0xff
_08061BD2:
	asrs r0, r0, #8
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r1, r1, r3
	str r1, [sp]
	ldr r1, [r5, #0x58]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061BF4: .4byte gSineTable

	thumb_func_start FUN_08061bf8
FUN_08061bf8: @ 0x08061BF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, _08061C04 @ =RNG_0202f388
	ldr r7, _08061C08 @ =0x0836591C
	b _08061C14
	.align 2, 0
_08061C04: .4byte RNG_0202f388
_08061C08: .4byte 0x0836591C
_08061C0C:
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _08061C40
_08061C14:
	ldr r1, [r6]
	ldr r0, _08061C54 @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _08061C58 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r3, r0, #0x11
	movs r0, #0xf
	ands r3, r0
	adds r0, r5, #0
	adds r0, #0xc2
	adds r2, r3, r7
	ldrb r1, [r0]
	movs r4, #0xc3
	adds r4, r4, r5
	mov ip, r4
	adds r4, r0, #0
	ldrb r2, [r2]
	cmp r1, r2
	beq _08061C0C
_08061C40:
	adds r0, r3, r7
	ldrb r1, [r0]
	ldrb r0, [r4]
	cmp r0, r1
	bne _08061C5C
	mov r1, ip
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08061C64
	.align 2, 0
_08061C54: .4byte 0x000343FD
_08061C58: .4byte 0x00269EC3
_08061C5C:
	movs r0, #0
	strb r1, [r4]
	mov r4, ip
	strb r0, [r4]
_08061C64:
	adds r0, r3, r7
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08061c74
FUN_08061c74: @ 0x08061C74
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08061CC4 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08061CBA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08061CC8 @ =gBossFnTable
	strb r0, [r3, #9]
	ldr r0, [r1, #0x60]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r2, [r3, #0xb]
	movs r1, #0x10
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
	orrs r1, r2
	strb r1, [r3, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r3, #0x1d]
_08061CBA:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08061CC4: .4byte gBossHeaderPtr
_08061CC8: .4byte gBossFnTable

	thumb_func_start FUN_08061ccc
FUN_08061ccc: @ 0x08061CCC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08061D1C @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08061D16
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08061D20 @ =gBossFnTable
	strb r0, [r3, #9]
	ldr r0, [r1, #0x60]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r2, [r3, #0xb]
	movs r1, #0x10
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
	str r5, [r3, #0x2c]
	orrs r1, r2
	strb r1, [r3, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r3, #0x1d]
_08061D16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061D1C: .4byte gBossHeaderPtr
_08061D20: .4byte gBossFnTable

	thumb_func_start FUN_08061d24
FUN_08061d24: @ 0x08061D24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r2, [r0, #0x2c]
	ldrb r1, [r2, #0x10]
	cmp r1, #1
	bne _08061D5C
	ldr r0, [r0, #0x14]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08061DF8
	movs r3, #0
	ldr r0, _08061D58 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08061D50
	movs r3, #1
_08061D50:
	adds r0, r2, #0
	adds r0, #0xc0
	strb r3, [r0]
	b _08061DF8
	.align 2, 0
_08061D58: .4byte pZero2
_08061D5C:
	cmp r1, #0
	bne _08061DF8
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08061DF8
	movs r3, #0
	ldr r0, _08061E08 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08061D7A
	movs r3, #1
_08061D7A:
	adds r0, r2, #0
	adds r0, #0xc0
	strb r3, [r0]
	subs r0, #4
	ldr r1, [r0]
	movs r0, #2
	ands r1, r0
	adds r7, r2, #0
	adds r7, #0xa4
	movs r0, #0xc1
	adds r0, r0, r2
	mov sb, r0
	cmp r1, #0
	beq _08061DF2
	ldrh r0, [r7]
	lsls r0, r0, #1
	mov r3, sb
	ldrb r1, [r3]
	subs r0, r0, r1
	strh r0, [r7]
	ldr r1, [r2, #0x54]
	ldr r4, _08061E0C @ =0xFFFFF800
	adds r1, r1, r4
	ldr r3, _08061E10 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r4, _08061E14 @ =0x000343FD
	mov r8, r4
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	ldr r6, _08061E18 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r3]
	lsrs r0, r0, #0x11
	ldr r5, _08061E1C @ =0x000007FF
	ands r0, r5
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, [r2, #0x58]
	ldr r0, _08061E20 @ =0xFFFFEC00
	adds r2, r2, r0
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_08061DF2:
	ldrh r0, [r7]
	mov r1, sb
	strb r0, [r1]
_08061DF8:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061E08: .4byte pZero2
_08061E0C: .4byte 0xFFFFF800
_08061E10: .4byte RNG_0202f388
_08061E14: .4byte 0x000343FD
_08061E18: .4byte 0x00269EC3
_08061E1C: .4byte 0x000007FF
_08061E20: .4byte 0xFFFFEC00

	thumb_func_start FUN_08061e24
FUN_08061e24: @ 0x08061E24
	push {r4, lr}
	adds r2, r0, #0
	ldrb r4, [r2, #0x10]
	cmp r4, #1
	beq _08061E84
	cmp r4, #1
	bgt _08061E38
	cmp r4, #0
	beq _08061E3E
	b _08061EE8
_08061E38:
	cmp r4, #2
	beq _08061EBC
	b _08061EE8
_08061E3E:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08061E5A
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08061EE8
_08061E5A:
	ldr r0, _08061E7C @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08061EE8
	ldr r1, _08061E80 @ =gBossFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	strb r4, [r2, #0xd]
	b _08061ED8
	.align 2, 0
_08061E7C: .4byte gStageRun
_08061E80: .4byte gBossFnTable
_08061E84:
	ldr r3, [r2, #0x28]
	ldrb r0, [r3, #0xc]
	cmp r0, #1
	bls _08061EE8
	ldr r1, _08061EB4 @ =gBossFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r3, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08061EB8
	movs r0, #4
	b _08061ED6
	.align 2, 0
_08061EB4: .4byte gBossFnTable
_08061EB8:
	strb r4, [r2, #0xd]
	b _08061ED8
_08061EBC:
	ldr r3, [r2, #0x28]
	ldrb r0, [r3, #0xc]
	cmp r0, #1
	bls _08061EE8
	ldr r1, _08061EE4 @ =gBossFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	movs r0, #3
_08061ED6:
	strb r0, [r2, #0xd]
_08061ED8:
	adds r0, r2, #0
	bl Spearook_Die
	movs r0, #1
	b _08061EEA
	.align 2, 0
_08061EE4: .4byte gBossFnTable
_08061EE8:
	movs r0, #0
_08061EEA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08061ef0
FUN_08061ef0: @ 0x08061EF0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r6, [r5]
	cmp r6, #0
	bne _08061F2E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08061F2E
	ldr r2, _08061F34 @ =0x0836592C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _08061F2E
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0xf
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_08061F2E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08061F34: .4byte 0x0836592C

	thumb_func_start Spearook_Init
Spearook_Init: @ 0x08061F38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _08061F88 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08061F8C @ =0x08365934
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	bne _08061F90
	adds r0, r7, #0
	bl InitRotatableMotion
	adds r0, r7, #0
	adds r0, #0xb8
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	b _08061FA2
	.align 2, 0
_08061F88: .4byte gBossFnTable
_08061F8C: .4byte 0x08365934
_08061F90:
	cmp r0, #3
	bne _08061F9C
	adds r0, r7, #0
	bl InitRotatableMotion
	b _08061FA2
_08061F9C:
	adds r0, r7, #0
	bl InitNonAffineMotion
_08061FA2:
	ldr r1, _0806208C @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x60
	bl ResetBossBody
	ldr r1, _08062090 @ =FUN_08061d24
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	movs r1, #0
	str r1, [r0]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _0806205C
	adds r0, r7, #0
	bl FUN_08061c74
	adds r1, r0, #0
	adds r0, r7, #0
	bl FUN_08061ccc
	ldr r5, _08062094 @ =0x000010B8
	ldr r2, _08062098 @ =gStaticMotionGraphics
	mov sb, r2
	adds r0, r5, r2
	ldr r1, _0806209C @ =wStaticGraphicTilenums
	mov r8, r1
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080620A0 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	ldr r6, _080620A4 @ =wStaticMotionPalIDs
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _080620A8 @ =0x000010CC
	add sb, r4
	movs r5, #0xd7
	lsls r5, r5, #1
	add r8, r5
	mov r0, r8
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sb
	bl LoadGraphic
	ldr r1, _080620A0 @ =gStaticMotionGraphics+12
	adds r4, r4, r1
	adds r6, r6, r5
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	adds r0, #0xbc
	movs r2, #0
	str r2, [r0]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #0x60
	strb r0, [r1]
_0806205C:
	adds r0, r7, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xc2
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc3
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, r7, #0
	bl Spearook_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806208C: .4byte sCollisions
_08062090: .4byte FUN_08061d24
_08062094: .4byte 0x000010B8
_08062098: .4byte gStaticMotionGraphics
_0806209C: .4byte wStaticGraphicTilenums
_080620A0: .4byte gStaticMotionGraphics+12
_080620A4: .4byte wStaticMotionPalIDs
_080620A8: .4byte 0x000010CC

	thumb_func_start Spearook_Update
Spearook_Update: @ 0x080620AC
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08061e24
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080620BE
	b _08062246
_080620BE:
	adds r0, r4, #0
	bl FUN_08061ef0
	ldr r1, _08062158 @ =0x083656E8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806215C @ =0x0836572C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _080620EC
	b _08062246
_080620EC:
	ldr r3, [r4, #0x28]
	adds r2, r3, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x40
	ands r0, r1
	movs r1, #0xba
	adds r1, r1, r4
	mov ip, r1
	cmp r0, #0
	beq _08062170
	ldrb r0, [r4, #0xd]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0806211E
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	ldr r0, [r2]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_0806211E:
	ldr r0, [r2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r2, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r1, r1, r5
	mov r0, ip
	strh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xd
	subs r1, r1, r0
	mov r2, ip
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _08062160 @ =0xFFFFC000
	cmp r1, r0
	bge _08062164
	strh r0, [r2]
	b _08062170
	.align 2, 0
_08062158: .4byte 0x083656E8
_0806215C: .4byte 0x0836572C
_08062160: .4byte 0xFFFFC000
_08062164:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _08062170
	mov r5, ip
	strh r0, [r5]
_08062170:
	adds r2, r4, #0
	adds r2, #0xb8
	mov r0, ip
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r0, r1, r0
	cmp r0, #0
	bge _08062186
	adds r0, #0xf
_08062186:
	asrs r0, r0, #4
	ldrh r5, [r2]
	adds r1, r0, r5
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080621E2
	lsls r0, r1, #0x10
	cmp r0, #0
	ble _080621C0
	mov r1, ip
	ldrh r0, [r1]
	subs r0, #0x80
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080621AE
	strh r5, [r1]
_080621AE:
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r2]
	lsls r0, r0, #0x10
	adds r3, #0xbc
	cmp r0, #0
	bge _08062202
	strh r5, [r2]
	b _08062202
_080621C0:
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080621D0
	strh r5, [r1]
_080621D0:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r2]
	lsls r0, r0, #0x10
	adds r3, #0xbc
	cmp r0, #0
	ble _08062202
	strh r5, [r2]
	b _08062202
_080621E2:
	ldrb r0, [r4, #0xd]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, #0xbc
	cmp r0, #2
	bhi _08062202
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	ldr r0, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08062202:
	mov r5, ip
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r0, r5
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _0806221E
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	b _08062226
_0806221E:
	ldr r0, [r3]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
_08062226:
	str r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806223C
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	rsbs r0, r0, #0
	b _08062240
_0806223C:
	ldrh r0, [r2]
	lsrs r0, r0, #8
_08062240:
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
_08062246:
	pop {r4, r5}
	pop {r0}
	bx r0

