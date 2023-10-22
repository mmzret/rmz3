	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08060d60
FUN_08060d60: @ 0x08060D60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08060DBE
	cmp r0, #1
	bgt _08060D74
	cmp r0, #0
	beq _08060D7A
	b _08060E0C
_08060D74:
	cmp r0, #2
	beq _08060DF8
	b _08060E0C
_08060D7A:
	ldr r3, _08060DF0 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _08060D9C
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08060D9C
	ldr r0, _08060DF4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08060D9C:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08060DBE:
	movs r0, #0xa7
	bl UpdateBlinkMotionState
	movs r0, #0xa8
	bl UpdateBlinkMotionState
	movs r0, #0xa9
	bl UpdateBlinkMotionState
	movs r0, #0xaa
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08060E0C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060E0C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08060E0C
	.align 2, 0
_08060DF0: .4byte gStageRun
_08060DF4: .4byte 0x0000FFFE
_08060DF8:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08060E0C
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08060E0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08060e14
FUN_08060e14: @ 0x08060E14
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r1, [r7, #0xe]
	cmp r1, #1
	beq _08060E4A
	cmp r1, #1
	bgt _08060E30
	cmp r1, #0
	beq _08060E38
	b _08060F7C
_08060E30:
	cmp r1, #2
	bne _08060E36
	b _08060F48
_08060E36:
	b _08060F7C
_08060E38:
	strb r1, [r7, #0x13]
	movs r0, #0xb6
	strb r0, [r7, #0x12]
	str r1, [r7, #0x68]
	movs r0, #0xc
	strb r0, [r7, #0xf]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08060E4A:
	movs r0, #0xa7
	bl UpdateBlinkMotionState
	movs r0, #0xa8
	bl UpdateBlinkMotionState
	movs r0, #0xa9
	bl UpdateBlinkMotionState
	movs r0, #0xaa
	bl UpdateBlinkMotionState
	ldr r0, [r7, #0x68]
	adds r0, #8
	str r0, [r7, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08060E72
	str r1, [r7, #0x68]
_08060E72:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08060EEC
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r5, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #6
	adds r5, r5, r0
	str r5, [sp, #4]
	ldr r4, _08060F3C @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _08060F40 @ =0x000343FD
	mov sb, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _08060F44 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xaa
	bl __umodsi3
	subs r0, #0x55
	lsls r0, r0, #8
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	mov r0, sb
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x96
	bl __umodsi3
	subs r0, #0x5f
	lsls r0, r0, #8
	adds r0, r0, r5
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
_08060EEC:
	ldrb r0, [r7, #0x13]
	ldrb r1, [r7, #0xf]
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060F1E
	ldr r2, _08060F3C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08060F40 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08060F44 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r0, #8
	strb r0, [r7, #0xf]
	movs r0, #0x2a
	bl PlaySound
_08060F1E:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08060F34
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060F7C
_08060F34:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08060F7C
	.align 2, 0
_08060F3C: .4byte RNG_0202f388
_08060F40: .4byte 0x000343FD
_08060F44: .4byte 0x00269EC3
_08060F48:
	movs r0, #0xa7
	bl ClearBlink
	movs r0, #0xa8
	bl ClearBlink
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #0xaa
	bl ClearBlink
	ldr r2, _08060F8C @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	movs r3, #0
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _08060F90 @ =gOverworld
	ldr r1, _08060F94 @ =0x0002D025
	adds r0, r0, r1
	strb r3, [r0]
_08060F7C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060F8C: .4byte gStageRun
_08060F90: .4byte gOverworld
_08060F94: .4byte 0x0002D025

	thumb_func_start FUN_08060f98
FUN_08060f98: @ 0x08060F98
	movs r0, #1
	bx lr

	thumb_func_start FUN_08060f9c
FUN_08060f9c: @ 0x08060F9C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _08060FAC
	cmp r0, #1
	beq _08060FB0
	b _08060FCC
_08060FAC:
	movs r0, #1
	strb r0, [r2, #0xe]
_08060FB0:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08060FCC
	ldr r0, _08060FD0 @ =gOverworld
	ldr r1, _08060FD4 @ =0x0002D025
	adds r0, r0, r1
	movs r1, #0
	strb r3, [r0]
	strb r3, [r2, #0xd]
	strb r1, [r2, #0xe]
_08060FCC:
	pop {r0}
	bx r0
	.align 2, 0
_08060FD0: .4byte gOverworld
_08060FD4: .4byte 0x0002D025

	thumb_func_start FUN_08060fd8
FUN_08060fd8: @ 0x08060FD8
	movs r0, #1
	bx lr

	thumb_func_start FUN_08060fdc
FUN_08060fdc: @ 0x08060FDC
	push {lr}
	mov ip, r0
	ldrb r1, [r0, #0xe]
	cmp r1, #1
	beq _0806100A
	cmp r1, #1
	bgt _08060FF0
	cmp r1, #0
	beq _08060FF6
	b _08061060
_08060FF0:
	cmp r1, #2
	beq _08061058
	b _08061060
_08060FF6:
	movs r0, #1
	mov r1, ip
	strb r0, [r1, #0xe]
	adds r1, #0xd0
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r1]
	movs r0, #0xf0
	mov r2, ip
	strb r0, [r2, #0x12]
_0806100A:
	mov r3, ip
	adds r3, #0xd0
	ldr r2, [r3]
	movs r1, #0x98
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	mov r1, ip
	ldr r0, [r1, #0x58]
	subs r0, r0, r2
	str r0, [r1, #0x58]
	adds r1, #0xb8
	ldr r1, [r1]
	cmp r0, r1
	bge _08061034
	mov r2, ip
	str r1, [r2, #0x58]
_08061034:
	mov r2, ip
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r2, #0x5c]
	str r1, [r2, #0x60]
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _0806104E
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08061060
_0806104E:
	mov r1, ip
	ldrb r0, [r1, #0xe]
	adds r0, #1
	strb r0, [r1, #0xe]
	b _08061060
_08061058:
	movs r0, #0
	mov r2, ip
	strb r1, [r2, #0xd]
	strb r0, [r2, #0xe]
_08061060:
	pop {r0}
	bx r0

	thumb_func_start FUN_08061064
FUN_08061064: @ 0x08061064
	movs r0, #1
	bx lr

	thumb_func_start FUN_08061068
FUN_08061068: @ 0x08061068
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806107A
	cmp r0, #1
	beq _0806107E
	b _0806109C
_0806107A:
	movs r0, #1
	strb r0, [r4, #0xe]
_0806107E:
	ldr r0, _080610A4 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r5, #1
	ands r5, r0
	cmp r5, #0
	bne _0806109C
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_080c4e58
	str r0, [r4, #0x2c]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0806109C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080610A4: .4byte gStageRun

	thumb_func_start FUN_080610a8
FUN_080610a8: @ 0x080610A8
	movs r0, #1
	bx lr

	thumb_func_start Boss22Neutral
Boss22Neutral: @ 0x080610AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080610C0
	cmp r4, #1
	beq _080610E6
	b _08061216
_080610C0:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080610D8 @ =sCollisions+24
	bl SetDDP
	ldrb r0, [r5, #0xf]
	cmp r0, #0xff
	bne _080610DC
	movs r0, #1
	strb r0, [r5, #0x13]
	strb r4, [r5, #0xf]
	b _080610E0
	.align 2, 0
_080610D8: .4byte sCollisions+24
_080610DC:
	movs r0, #0x78
	strb r0, [r5, #0x13]
_080610E0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080610E6:
	adds r0, r5, #0
	bl FUN_080616fc
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _080610F4
	b _08061216
_080610F4:
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08061102
	b _08061216
_08061102:
	adds r0, r5, #0
	adds r0, #0xb5
	adds r1, r5, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r7, r0, #0
	mov r8, r1
	cmp r3, r2
	bne _080611B4
	subs r0, #0x11
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bgt _0806116C
	ldr r2, _0806115C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08061160 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08061164 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _08061168 @ =gOmegaZXMode2
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _0806120A
	adds r0, r5, #0
	bl FUN_08061648
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0806120A
	.align 2, 0
_0806115C: .4byte RNG_0202f388
_08061160: .4byte 0x000343FD
_08061164: .4byte 0x00269EC3
_08061168: .4byte gOmegaZXMode2
_0806116C:
	ldr r2, _080611A4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080611A8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080611AC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _080611B0 @ =gOmegaZXMode1
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _0806120A
	adds r0, r5, #0
	bl FUN_08061648
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0806120A
	.align 2, 0
_080611A4: .4byte RNG_0202f388
_080611A8: .4byte 0x000343FD
_080611AC: .4byte 0x00269EC3
_080611B0: .4byte gOmegaZXMode1
_080611B4:
	adds r0, r5, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x20
	bgt _080611E8
	ldr r2, _080611D8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080611DC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080611E0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _080611E4 @ =gOmegaZXMode2
	b _080611FE
	.align 2, 0
_080611D8: .4byte RNG_0202f388
_080611DC: .4byte 0x000343FD
_080611E0: .4byte 0x00269EC3
_080611E4: .4byte gOmegaZXMode2
_080611E8:
	ldr r2, _08061220 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08061224 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08061228 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _0806122C @ =gOmegaZXMode1
_080611FE:
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
_0806120A:
	strb r1, [r5, #0xd]
	strb r6, [r5, #0xe]
	ldrb r0, [r7]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r7]
_08061216:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061220: .4byte RNG_0202f388
_08061224: .4byte 0x000343FD
_08061228: .4byte 0x00269EC3
_0806122C: .4byte gOmegaZXMode1

	thumb_func_start FUN_08061230
FUN_08061230: @ 0x08061230
	movs r0, #1
	bx lr

	thumb_func_start FUN_08061234
FUN_08061234: @ 0x08061234
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _080612CC
	lsls r0, r0, #2
	ldr r1, _08061248 @ =_0806124C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08061248: .4byte _0806124C
_0806124C: @ jump table
	.4byte _08061260 @ case 0
	.4byte _08061294 @ case 1
	.4byte _0806128E @ case 2
	.4byte _08061294 @ case 3
	.4byte _080612B8 @ case 4
_08061260:
	movs r0, #0xa7
	bl ClearBlink
	movs r0, #0xa8
	bl ClearBlink
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #0xaa
	bl ClearBlink
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r0, #0xa7
	bl LoadBlink
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08061294
_0806128E:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	b _080612B0
_08061294:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa7
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080612CC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080612CC
_080612B0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080612CC
_080612B8:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa7
	bl ClearBlink
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080612CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080612d4
FUN_080612d4: @ 0x080612D4
	movs r0, #1
	bx lr

	thumb_func_start FUN_080612d8
FUN_080612d8: @ 0x080612D8
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _080613B0
	lsls r0, r0, #2
	ldr r1, _080612F0 @ =_080612F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080612F0: .4byte _080612F4
_080612F4: @ jump table
	.4byte _08061308 @ case 0
	.4byte _08061340 @ case 1
	.4byte _08061358 @ case 2
	.4byte _08061384 @ case 3
	.4byte _080613A2 @ case 4
_08061308:
	movs r0, #0xa7
	bl ClearBlink
	movs r0, #0xa8
	bl ClearBlink
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #0xaa
	bl ClearBlink
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r0, #0xaa
	bl LoadBlink
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080afedc
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061340:
	movs r0, #0xaa
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080613B0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080613B0
	b _0806139A
_08061358:
	ldr r0, _0806137C @ =0xFFFFDD00
	str r0, [sp]
	ldr r0, _08061380 @ =0xFFFFAA00
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	movs r2, #3
	bl FUN_080afedc
	adds r1, r4, #0
	adds r1, #0xc4
	str r0, [r1]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x13]
	b _0806139A
	.align 2, 0
_0806137C: .4byte 0xFFFFDD00
_08061380: .4byte 0xFFFFAA00
_08061384:
	movs r0, #0xaa
	bl UpdateBlinkMotionState
	adds r1, r4, #0
	adds r1, #0xc4
	ldr r0, [r1]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080613B0
	movs r0, #0
	str r0, [r1]
_0806139A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080613B0
_080613A2:
	movs r0, #0xaa
	bl ClearBlink
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080613B0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080613b8
FUN_080613b8: @ 0x080613B8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080613bc
FUN_080613bc: @ 0x080613BC
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _0806149C
	lsls r0, r0, #2
	ldr r1, _080613D4 @ =_080613D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080613D4: .4byte _080613D8
_080613D8: @ jump table
	.4byte _080613EC @ case 0
	.4byte _08061424 @ case 1
	.4byte _0806143C @ case 2
	.4byte _08061464 @ case 3
	.4byte _08061488 @ case 4
_080613EC:
	movs r0, #0xa7
	bl ClearBlink
	movs r0, #0xa8
	bl ClearBlink
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #0xaa
	bl ClearBlink
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0xa8
	bl LoadBlink
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080c4f04
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061424:
	adds r0, r4, #0
	bl FUN_080616fc
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806149C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806149C
	b _08061480
_0806143C:
	ldr r0, [r4, #0x54]
	ldr r1, _0806145C @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08061460 @ =0xFFFFDE00
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_080aff34
	adds r1, r4, #0
	adds r1, #0xc4
	b _0806147E
	.align 2, 0
_0806145C: .4byte 0xFFFFFC00
_08061460: .4byte 0xFFFFDE00
_08061464:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa8
	bl UpdateBlinkMotionState
	adds r1, r4, #0
	adds r1, #0xc4
	ldr r0, [r1]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0806149C
	movs r0, #0
_0806147E:
	str r0, [r1]
_08061480:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806149C
_08061488:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa8
	bl ClearBlink
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806149C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080614a4
FUN_080614a4: @ 0x080614A4
	movs r0, #1
	bx lr

	thumb_func_start FUN_080614a8
FUN_080614a8: @ 0x080614A8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080614B6
	b _080615D0
_080614B6:
	lsls r0, r0, #2
	ldr r1, _080614C0 @ =_080614C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080614C0: .4byte _080614C4
_080614C4: @ jump table
	.4byte _080614D8 @ case 0
	.4byte _08061524 @ case 1
	.4byte _08061560 @ case 2
	.4byte _080615A2 @ case 3
	.4byte _080615AC @ case 4
_080614D8:
	movs r0, #0xa7
	bl ClearBlink
	movs r0, #0xa8
	bl ClearBlink
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #0xaa
	bl ClearBlink
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0xa9
	bl LoadBlink
	movs r0, #3
	strb r0, [r4, #0x13]
	ldr r2, _0806158C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08061590 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08061594 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r1, r4, #0
	adds r1, #0xc8
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061524:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _08061598 @ =sOmegaZXProjectileTemplates
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #3
	ldrb r1, [r4, #0x13]
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r1, r3
	ldrh r2, [r0]
	adds r3, #4
	adds r1, r1, r3
	ldrb r3, [r1]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080affe4
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061560:
	movs r0, #0xa9
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080615D0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080615D0
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806159C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080615D0
	.align 2, 0
_0806158C: .4byte RNG_0202f388
_08061590: .4byte 0x000343FD
_08061594: .4byte 0x00269EC3
_08061598: .4byte sOmegaZXProjectileTemplates
_0806159C:
	movs r0, #1
	strb r0, [r4, #0xe]
	b _080615D0
_080615A2:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080615AC:
	movs r0, #0xa9
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080615D0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080615D0
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_080615D0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080615d8
FUN_080615d8: @ 0x080615D8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080615dc
FUN_080615dc: @ 0x080615DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080615EC
	cmp r0, #1
	beq _0806161C
	b _08061642
_080615EC:
	movs r0, #0xa7
	bl ClearBlink
	movs r0, #0xa8
	bl ClearBlink
	movs r0, #0xa9
	bl ClearBlink
	movs r0, #0xaa
	bl ClearBlink
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r0, #0xa7
	bl LoadBlink
	adds r0, r4, #0
	bl FUN_080616fc
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08061642
_0806161C:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa7
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r0, [r0]
	ldrb r0, [r0, #0xd]
	cmp r0, #7
	beq _08061642
	movs r0, #0xa7
	bl ClearBlink
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08061642:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08061648
FUN_08061648: @ 0x08061648
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r2, #0xa4
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #0x20
	bgt _0806167E
	movs r2, #0
	ldr r5, _08061670 @ =u16_ARRAY_080feffa
	adds r3, r5, #0
_0806165E:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08061674
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0806165E
	b _080616B0
	.align 2, 0
_08061670: .4byte u16_ARRAY_080feffa
_08061674:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _0806169A
_0806167E:
	movs r2, #0
	ldr r5, _080616A4 @ =u16_ARRAY_080feffa
	adds r3, r5, #0
_08061684:
	ldrh r1, [r3]
	cmp r1, r4
	bne _080616A8
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _08061694
	adds r0, r2, #4
_08061694:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_0806169A:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _080616B0
	.align 2, 0
_080616A4: .4byte u16_ARRAY_080feffa
_080616A8:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _08061684
_080616B0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080616b8
FUN_080616b8: @ 0x080616B8
	push {lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x2c]
	ldr r2, [r1, #0x2c]
	cmp r2, #0
	beq _080616D8
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bls _080616D0
	movs r0, #0
	str r0, [r1, #0x2c]
	b _080616D8
_080616D0:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
_080616D8:
	ldr r0, [r3, #0x2c]
	adds r1, r0, #0
	adds r1, #0xbc
	ldr r2, [r1]
	cmp r2, #0
	beq _080616F8
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bls _080616F0
	movs r0, #0
	str r0, [r1]
	b _080616F8
_080616F0:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
_080616F8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080616fc
FUN_080616fc: @ 0x080616FC
	push {r4, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	strh r0, [r1]
	ldr r1, _08061754 @ =gSineTable
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r3, r0, #2
	mov r4, ip
	ldr r0, [r4, #0x68]
	adds r0, r0, r3
	str r0, [r4, #0x58]
	mov r3, ip
	adds r3, #0xc2
	ldrh r0, [r3]
	adds r0, #2
	ands r0, r2
	strh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r3, r0, #3
	ldr r2, [r4, #0x64]
	adds r2, r2, r3
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	str r2, [r4, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061754: .4byte gSineTable
