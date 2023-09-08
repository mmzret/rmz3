	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08073ea8
FUN_08073ea8: @ 0x08073EA8
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	beq _08073EE6
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	bge _08073ED0
	ldr r1, [r4, #0x58]
	bl PushoutToRight2
	adds r1, r0, #0
	cmp r1, #0
	ble _08073EE6
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #2
	b _08073EE8
_08073ED0:
	ldr r1, [r4, #0x58]
	bl PushoutToLeft2
	adds r1, r0, #0
	cmp r1, #0
	bge _08073EE6
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #1
	b _08073EE8
_08073EE6:
	movs r0, #0
_08073EE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08073ef0
FUN_08073ef0: @ 0x08073EF0
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	beq _08073F32
	ldr r0, [r4, #0x58]
	adds r2, r0, r1
	str r2, [r4, #0x58]
	cmp r1, #0
	bge _08073F1A
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl PushoutToDown2
	adds r1, r0, #0
	cmp r1, #0
	ble _08073F32
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #2
	b _08073F34
_08073F1A:
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bge _08073F32
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _08073F34
_08073F32:
	movs r0, #0
_08073F34:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08073f3c
FUN_08073f3c: @ 0x08073F3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov sb, r4
	cmp r4, #0
	beq _08073F8A
_08073F4E:
	ldr r0, [r4, #0x60]
	adds r2, r0, #0
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08073F84
	mov r1, sb
	ldrb r0, [r1, #0xd]
	cmp r0, #1
	bne _08073F74
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	b _08073F84
_08073F74:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
_08073F84:
	ldr r4, [r4, #0x28]
	cmp r4, #0
	bne _08073F4E
_08073F8A:
	mov r4, sb
	ldr r0, [r4, #0x28]
	mov r8, r0
	movs r1, #0
	mov sl, r1
	cmp r0, #0
	bne _08073F9A
	b _0807409C
_08073F9A:
	mov r0, r8
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r5, r1, r0
	mov r0, r8
	ldr r1, [r0, #0x58]
	ldr r0, [r4, #0x58]
	subs r7, r1, r0
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	mov r1, sl
	cmp r1, #0
	bne _08073FD2
	adds r1, r0, #0
	adds r1, #0xc0
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
_08073FD2:
	mov r0, r8
	adds r0, #0x24
	strb r2, [r0]
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r7, #0
	muls r1, r7, r1
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _08074084
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r0, r7, #8
	adds r1, r6, #0
	bl __divsi3
	adds r7, r0, #0
	ldr r0, _08074058 @ =0xFFFFF200
	adds r1, r6, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	bge _08074012
	adds r0, #0xff
_08074012:
	asrs r1, r0, #8
	adds r0, r5, #0
	muls r0, r1, r0
	cmp r0, #0
	bge _0807401E
	adds r0, #0xff
_0807401E:
	asrs r5, r0, #8
	adds r0, r7, #0
	muls r0, r1, r0
	cmp r0, #0
	bge _0807402A
	adds r0, #0xff
_0807402A:
	asrs r7, r0, #8
	mov r1, sb
	ldrb r0, [r1, #0xd]
	cmp r0, #1
	bne _0807405C
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r7
	str r0, [r4, #0x58]
	mov r1, r8
	ldrb r0, [r1, #0x12]
	cmp r0, #0
	beq _08074084
	ldr r0, [r1, #0x54]
	subs r0, r0, r5
	str r0, [r1, #0x54]
	ldr r0, [r1, #0x58]
	subs r0, r0, r7
	str r0, [r1, #0x58]
	b _08074084
	.align 2, 0
_08074058: .4byte 0xFFFFF200
_0807405C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08073ea8
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_08073ef0
	mov r1, r8
	ldrb r0, [r1, #0x12]
	cmp r0, #0
	beq _08074084
	rsbs r1, r5, #0
	mov r0, r8
	bl FUN_08073ea8
	rsbs r1, r7, #0
	mov r0, r8
	bl FUN_08073ef0
_08074084:
	mov r4, r8
	ldr r0, [r4, #0x28]
	mov r8, r0
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	mov r1, r8
	cmp r1, #0
	beq _0807409C
	b _08073F9A
_0807409C:
	mov r4, sb
	cmp r4, #0
	beq _080740D6
	movs r6, #0xfe
_080740A4:
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x64]
	subs r5, r2, r0
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x68]
	subs r7, r1, r0
	adds r0, r5, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _080740BA
	adds r0, #0xff
_080740BA:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	adds r0, r7, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _080740C8
	adds r0, #0xff
_080740C8:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	str r2, [r4, #0x64]
	str r1, [r4, #0x68]
	ldr r4, [r4, #0x28]
	cmp r4, #0
	bne _080740A4
_080740D6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080740e4
FUN_080740e4: @ 0x080740E4
	push {r4, lr}
	adds r2, r0, #0
	b _080740EC
_080740EA:
	ldr r2, [r2, #0x28]
_080740EC:
	ldr r0, [r2, #0x28]
	cmp r0, #0
	bne _080740EA
	cmp r2, #0
	beq _0807412A
	ldr r4, _08074130 @ =gEnemyFnTable
	movs r3, #0
_080740FA:
	ldrb r0, [r2, #0x12]
	cmp r0, #1
	bhi _08074118
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r4
	movs r0, #2
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #0xd]
	ldr r0, [r2, #0x2c]
	str r3, [r0, #0x28]
_08074118:
	ldrb r1, [r2, #0x10]
	cmp r1, #0
	bne _08074124
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08074124:
	ldr r2, [r2, #0x2c]
	cmp r2, #0
	bne _080740FA
_0807412A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074130: .4byte gEnemyFnTable

	thumb_func_start FUN_08074134
FUN_08074134: @ 0x08074134
	push {lr}
	ldr r2, [r0, #0x2c]
	ldr r1, [r0, #0x14]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08074158
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bne _08074158
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _08074158
	adds r0, r2, #0
	bl FUN_080740e4
_08074158:
	pop {r0}
	bx r0

	thumb_func_start FUN_0807415c
FUN_0807415c: @ 0x0807415C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	bne _080741FE
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	mov ip, r0
	cmp r1, #0
	beq _080741FE
	movs r2, #0
	ldr r1, [r3, #0x28]
	ldr r4, _080741D8 @ =gEnemyFnTable
	cmp r1, #0
	beq _080741A4
	adds r7, r4, #0
	movs r6, #2
	movs r5, #1
_08074188:
	ldrb r0, [r1, #9]
	lsls r0, r0, #2
	adds r0, r0, r7
	str r6, [r1, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r1, #0x14]
	strb r5, [r1, #0xd]
	ldr r1, [r1, #0x28]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r1, #0
	bne _08074188
_080741A4:
	ldrb r0, [r3, #0xd]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080741B4
	cmp r2, #2
	bne _080741E0
_080741B4:
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r2, #2
	str r2, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	mov r0, ip
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080741DC
	strb r2, [r3, #0xd]
	b _080741F4
	.align 2, 0
_080741D8: .4byte gEnemyFnTable
_080741DC:
	strb r1, [r3, #0xd]
	b _080741F4
_080741E0:
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	movs r0, #0
	strb r0, [r3, #0xd]
_080741F4:
	adds r0, r3, #0
	bl Snakecord_Die
	movs r0, #1
	b _08074200
_080741FE:
	movs r0, #0
_08074200:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08074208
FUN_08074208: @ 0x08074208
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	beq _080742E2
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _080742E2
	ldrb r5, [r4, #0xf]
	cmp r5, #0
	beq _08074228
	cmp r5, #1
	beq _080742B8
	b _080742E2
_08074228:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080742E2
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bne _0807427C
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	cmp r0, #0
	bge _08074250
	movs r0, #0xb
	b _08074252
_08074250:
	movs r0, #4
_08074252:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	ldr r2, [r4, #0x2c]
	cmp r2, #0
	beq _0807427C
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080742AC @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_0807427C:
	ldr r1, _080742B0 @ =0x08366E30
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080742B4 @ =0x08366E60
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080742A8:
	movs r0, #1
	b _080742E4
	.align 2, 0
_080742AC: .4byte gVFXFnTable
_080742B0: .4byte 0x08366E30
_080742B4: .4byte 0x08366E60
_080742B8:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080742E0
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bls _080742A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	ands r5, r1
	cmp r5, #0
	beq _080742A8
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	bne _080742E2
	b _080742A8
_080742E0:
	strb r0, [r4, #0xf]
_080742E2:
	movs r0, #0
_080742E4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080742ec
FUN_080742ec: @ 0x080742EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08074354
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _08074354
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	adds r5, r0, #0
	cmp r2, #0
	bne _08074354
	subs r0, #0x28
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08074354
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _08074326
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08074354
_08074326:
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _0807433C
	ldr r2, _08074338 @ =0x08367004
	b _0807433E
	.align 2, 0
_08074338: .4byte 0x08367004
_0807433C:
	ldr r2, _0807435C @ =0x08366FFC
_0807433E:
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	ldr r0, [r5]
	cmp r0, #0
	beq _08074354
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08074354:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807435C: .4byte 0x08366FFC

	thumb_func_start Snakecord_Init
Snakecord_Init: @ 0x08074360
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080743D4 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080743D8 @ =0x0836700C
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r4, #0
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, _080743DC @ =gSystemSavedataManager
	ldrb r1, [r0, #0x14]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080743E8
	ldr r0, _080743E0 @ =gCurStory
	ldrb r1, [r0, #4]
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080743E8
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080743E4 @ =0x08366E9C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _08074400
	.align 2, 0
_080743D4: .4byte gEnemyFnTable
_080743D8: .4byte 0x0836700C
_080743DC: .4byte gSystemSavedataManager
_080743E0: .4byte gCurStory
_080743E4: .4byte 0x08366E9C
_080743E8:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080744C4 @ =0x08366E9C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_08074400:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080744C8 @ =FUN_08074134
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _080744D8
	movs r7, #0
	ldr r4, [r6, #0x54]
	ldr r1, [r6, #0x58]
	adds r0, r4, #0
	bl FUN_0800a134
	adds r5, r0, #0
	movs r3, #0
	mov sb, r3
	ldr r0, _080744CC @ =gSineTable
	mov r8, r0
	movs r1, #0x64
	add r1, r8
	mov sl, r1
_08074436:
	ldr r0, _080744D0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	str r3, [sp]
	bl AllocEntityLast
	adds r2, r0, #0
	ldr r3, [sp]
	cmp r2, #0
	beq _080744AA
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _080744D4 @ =gEnemyFnTable
	movs r0, #0x14
	strb r0, [r2, #9]
	ldr r0, [r1, #0x50]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	mov r0, sb
	strh r0, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	mov r1, sb
	strb r1, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x10]
	strb r3, [r2, #0x12]
	str r4, [r2, #0x54]
	str r5, [r2, #0x58]
	str r4, [r2, #0x64]
	str r5, [r2, #0x68]
	str r7, [r2, #0x28]
	cmp r7, #0
	beq _0807448A
	str r2, [r7, #0x2c]
_0807448A:
	adds r7, r2, #0
	mov r0, r8
	adds r0, #0xe4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r4, r4, r0
	mov r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r5, r5, r0
_080744AA:
	adds r3, #1
	cmp r3, #3
	ble _08074436
	movs r0, #0
	strb r3, [r6, #0x12]
	str r7, [r6, #0x28]
	str r0, [r6, #0x2c]
	cmp r7, #0
	beq _080744BE
	str r6, [r7, #0x2c]
_080744BE:
	str r4, [r6, #0x54]
	str r5, [r6, #0x58]
	b _080744DE
	.align 2, 0
_080744C4: .4byte 0x08366E9C
_080744C8: .4byte FUN_08074134
_080744CC: .4byte gSineTable
_080744D0: .4byte gZakoHeaderPtr
_080744D4: .4byte gEnemyFnTable
_080744D8:
	adds r0, r6, #0
	bl Snakecord_Update
_080744DE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Snakecord_Update
Snakecord_Update: @ 0x080744F0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0x10]
	cmp r2, #1
	bne _08074564
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _08074564
	ldrb r0, [r0, #0xc]
	cmp r0, #2
	bls _08074544
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08074540 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080745A2
	.align 2, 0
_08074540: .4byte gEnemyFnTable
_08074544:
	cmp r0, #1
	bls _08074564
	ldr r1, _08074560 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	b _080745A2
	.align 2, 0
_08074560: .4byte gEnemyFnTable
_08074564:
	adds r0, r4, #0
	bl FUN_0807415c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080745A2
	adds r0, r4, #0
	bl FUN_080742ec
	adds r0, r4, #0
	bl FUN_08074208
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080745A2
	ldr r1, _080745A8 @ =0x08366E30
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080745AC @ =0x08366E60
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080745A2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080745A8: .4byte 0x08366E30
_080745AC: .4byte 0x08366E60

	thumb_func_start Snakecord_Die
Snakecord_Die: @ 0x080745B0
	push {lr}
	adds r3, r0, #0
	ldr r0, _080745F8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08074600
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
	ldr r1, _080745FC @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _08074610
	.align 2, 0
_080745F8: .4byte gCurStory
_080745FC: .4byte gEnemyFnTable
_08074600:
	ldr r0, _08074614 @ =0x08366E90
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_08074610:
	pop {r0}
	bx r0
	.align 2, 0
_08074614: .4byte 0x08366E90

	thumb_func_start FUN_08074618
FUN_08074618:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0807461c
FUN_0807461c: @ 0x0807461C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807463E
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0807463E
	movs r1, #0
	movs r0, #0xa
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807463E:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08074656
	movs r1, #0
	movs r0, #9
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08074656:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807465c
FUN_0807465c:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x8C, 0x30, 0x00, 0x68, 0x80, 0x21, 0x09, 0x01, 0x08, 0x40, 0x00, 0x28, 0x24, 0xD1, 0x21, 0x1C
	.byte 0x25, 0x31, 0x18, 0x20, 0x08, 0x70, 0xE2, 0x6A, 0x00, 0x2A, 0x0E, 0xD0, 0x91, 0x7A, 0xFE, 0x20
	.byte 0x08, 0x40, 0xFD, 0x21, 0x08, 0x40, 0x90, 0x72, 0x08, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18
	.byte 0x03, 0x21, 0xD1, 0x60, 0x00, 0x68, 0xC0, 0x68, 0x50, 0x61, 0x60, 0x6D, 0xA1, 0x6D, 0x95, 0xF7
	.byte 0xD5, 0xF9, 0x00, 0x28, 0x04, 0xDA, 0x0B, 0x20, 0x03, 0xE0, 0x00, 0x00, 0x00, 0xD9, 0x36, 0x08
	.byte 0x04, 0x20, 0x60, 0x73, 0x00, 0x20, 0xA0, 0x73, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_080746c0
FUN_080746c0:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x25, 0x1C, 0xB4, 0x35, 0x28, 0x68, 0x00, 0x28, 0x03, 0xD0, 0xB0, 0xF7
	.byte 0x9D, 0xFF, 0x00, 0x28, 0x1A, 0xD0, 0x00, 0x20, 0x28, 0x60, 0x20, 0x1C, 0x74, 0x30, 0x08, 0x49
	.byte 0x92, 0xF7, 0x98, 0xFD, 0x20, 0x1C, 0xEE, 0xF7, 0xB1, 0xFF, 0x00, 0x28, 0x0E, 0xD1, 0x60, 0x6D
	.byte 0xA1, 0x6D, 0x95, 0xF7, 0xAB, 0xF9, 0x00, 0x28, 0x04, 0xDA, 0x0B, 0x20, 0x03, 0xE0, 0x00, 0x00
	.byte 0xFC, 0x6E, 0x36, 0x08, 0x04, 0x20, 0x60, 0x73, 0x00, 0x20, 0xA0, 0x73, 0x20, 0x1C, 0x8C, 0x30
	.byte 0x00, 0x68, 0x05, 0x49, 0x08, 0x40, 0x88, 0x42, 0x03, 0xD1, 0x00, 0x21, 0x0A, 0x20, 0x60, 0x73
	.byte 0xA1, 0x73, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x01, 0x00, 0x02, 0x00

	thumb_func_start FUN_0807472c
FUN_0807472c: @ 0x0807472C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807474E
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0807474E
	movs r1, #0
	movs r0, #0xa
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807474E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start snakecord_08074754
snakecord_08074754: @ 0x08074754
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _08074768
	cmp r7, #1
	beq _08074806
	b _08074836
_08074768:
	ldr r0, [r6, #0x28]
	mov ip, r0
	cmp r0, #0
	beq _080747E0
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	movs r4, #0xfd
	ands r0, r4
	mov r2, ip
	strb r0, [r2, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r2, [r2, #0xa]
	movs r3, #0xfb
	adds r0, r3, #0
	ands r0, r2
	mov r5, ip
	strb r0, [r5, #0xa]
	ldr r0, _08074840 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r2, #3
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	ldr r5, [r5, #0x28]
	mov ip, r5
	ldrb r0, [r5, #0xa]
	ands r1, r0
	ands r1, r4
	strb r1, [r5, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	mov r1, ip
	ldrb r0, [r1, #0xa]
	ands r3, r0
	strb r3, [r1, #0xa]
	ldrb r0, [r1, #9]
	lsls r0, r0, #2
	add r0, r8
	str r2, [r1, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r1, #0x14]
	str r7, [r6, #0x28]
_080747E0:
	str r7, [r6, #0x60]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _08074844 @ =0x0000280C
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08074848 @ =0x08366F14
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08074806:
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	bne _08074836
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08074836
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807482E
	str r1, [r6, #0x60]
_0807482E:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
_08074836:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074840: .4byte gEnemyFnTable
_08074844: .4byte 0x0000280C
_08074848: .4byte 0x08366F14

	thumb_func_start FUN_0807484c
FUN_0807484c: @ 0x0807484C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807485C
	cmp r5, #1
	beq _08074896
	b _0807489C
_0807485C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080748A4 @ =0x08366EE4
	bl SetDDP
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	str r5, [r4, #0x5c]
	str r5, [r4, #0x60]
	adds r0, r4, #0
	bl InitRotatableMotion
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074896:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807489C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080748A4: .4byte 0x08366EE4

	thumb_func_start FUN_080748a8
FUN_080748a8: @ 0x080748A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807491E
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807491E
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08074910
	movs r0, #0x3b
	bl PlaySound
	ldr r1, _08074900 @ =0x00002803
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl FUN_080bb8c0
	ldr r2, _08074904 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08074908 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0807490C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	adds r0, #1
	strb r0, [r5, #0x13]
	b _0807491E
	.align 2, 0
_08074900: .4byte 0x00002803
_08074904: .4byte RNG_0202f388
_08074908: .4byte 0x000343FD
_0807490C: .4byte 0x00269EC3
_08074910:
	ldr r1, _08074934 @ =0x00002801
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl FUN_080bb878
_0807491E:
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _08074926
	b _08074AB6
_08074926:
	lsls r0, r0, #2
	ldr r1, _08074938 @ =0x0807493C
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0x24
	mov pc, r0
	.align 2, 0
_08074934: .4byte 0x00002801
_08074938: .4byte 0x0807493C
_0807493C:
	.byte 0x50, 0x49, 0x07, 0x08
	.byte 0x9C, 0x49, 0x07, 0x08, 0x00, 0x4A, 0x07, 0x08, 0x10, 0x4A, 0x07, 0x08, 0x80, 0x4A, 0x07, 0x08
	.byte 0xA9, 0x7A, 0x01, 0x20, 0x00, 0x24, 0x08, 0x43, 0xA8, 0x72, 0x28, 0x1C, 0x74, 0x30, 0x24, 0x49
	.byte 0x92, 0xF7, 0x58, 0xFC, 0x68, 0x6D, 0x68, 0x66, 0xA8, 0x6D, 0xA8, 0x66, 0xEC, 0x65, 0x2C, 0x66
	.byte 0x28, 0x1C, 0xA2, 0xF7, 0x0D, 0xFD, 0x1F, 0x49, 0x28, 0x1C, 0xA2, 0xF7, 0xF5, 0xFD, 0x28, 0x1C
	.byte 0x46, 0xF0, 0x7A, 0xFF, 0x06, 0x20, 0xE8, 0x74, 0x28, 0x1C, 0xB8, 0x30, 0x04, 0x70, 0x29, 0x1C
	.byte 0x24, 0x31, 0xC0, 0x20, 0x08, 0x70, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x0F, 0x78, 0x3E, 0x1C
	.byte 0xC0, 0x3E, 0x15, 0x48, 0x80, 0x46, 0x78, 0x00, 0x40, 0x44, 0x00, 0x21, 0x44, 0x5E, 0x30, 0x1C
	.byte 0x03, 0x21, 0x89, 0xF0, 0xB5, 0xFE, 0x02, 0x1C, 0x50, 0x32, 0x21, 0x1C, 0x51, 0x43, 0x00, 0x29
	.byte 0x00, 0xDA, 0xFF, 0x31, 0x09, 0x12, 0xE8, 0x6D, 0x40, 0x18, 0xE8, 0x65, 0x0B, 0x49, 0x78, 0x18
	.byte 0x00, 0x06, 0xC0, 0x0D, 0x40, 0x44, 0x00, 0x21, 0x40, 0x5E, 0x50, 0x43, 0x00, 0x28, 0x00, 0xDA
	.byte 0xFF, 0x30, 0x01, 0x12, 0x28, 0x6E, 0x40, 0x18, 0x28, 0x66, 0x28, 0x2E, 0x3F, 0xDD, 0x3B, 0xE0
	.byte 0xB4, 0x6E, 0x36, 0x08, 0x01, 0x28, 0x00, 0x00, 0x74, 0xEA, 0x0F, 0x08, 0xC0, 0xFE, 0xFF, 0xFF
	.byte 0x28, 0x1C, 0x24, 0x30, 0x00, 0x78, 0x06, 0x1C, 0xC0, 0x3E, 0x00, 0x2E, 0x2F, 0xDA, 0x2B, 0xE0
	.byte 0x28, 0x1C, 0x24, 0x30, 0x00, 0x78, 0x06, 0x1C, 0xC0, 0x3E, 0x18, 0x4F, 0x80, 0x38, 0x00, 0x06
	.byte 0xC0, 0x0D, 0xC0, 0x19, 0x00, 0x21, 0x44, 0x5E, 0x30, 0x1C, 0x03, 0x21, 0x89, 0xF0, 0x78, 0xFE
	.byte 0x50, 0x21, 0x0A, 0x1A, 0x21, 0x1C, 0x51, 0x43, 0x00, 0x29, 0x00, 0xDA, 0xFF, 0x31, 0x09, 0x12
	.byte 0xE8, 0x6D, 0x40, 0x18, 0xE8, 0x65, 0x30, 0x06, 0xC0, 0x0D, 0xC0, 0x19, 0x00, 0x21, 0x40, 0x5E
	.byte 0x50, 0x43, 0x00, 0x28, 0x00, 0xDA, 0xFF, 0x30, 0x00, 0x12, 0x29, 0x6E, 0x09, 0x18, 0x29, 0x66
	.byte 0x28, 0x20, 0x40, 0x42, 0x86, 0x42, 0x02, 0xDA, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x28, 0x1C
	.byte 0xFF, 0xF7, 0x64, 0xFA, 0x28, 0x1C, 0xA2, 0xF7, 0xF1, 0xFD, 0x1C, 0xE0, 0x74, 0xEA, 0x0F, 0x08
	.byte 0x28, 0x1C, 0x24, 0x30, 0x00, 0x78, 0x06, 0x1C, 0xC0, 0x3E, 0x00, 0x2E, 0x0D, 0xDD, 0x29, 0x1C
	.byte 0xB8, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x00, 0x06, 0x00, 0x0E, 0x03, 0x28, 0x02, 0xD9
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0x1F, 0xFB, 0x01, 0x20, 0xA8, 0x73, 0x28, 0x1C, 0xFF, 0xF7, 0x46, 0xFA
	.byte 0x28, 0x1C, 0xA2, 0xF7, 0xD3, 0xFD
_08074AB6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08074ac0
FUN_08074ac0: @ 0x08074AC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08074AD4
	cmp r0, #1
	beq _08074ADC
	b _08074B9A
_08074AD4:
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08074ADC:
	adds r0, r6, #0
	bl FUN_08073f3c
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08074B9A
	ldrb r0, [r6, #0x13]
	adds r0, #1
	movs r7, #0
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _08074B9A
	ldr r5, [r6, #0x28]
	mov ip, r5
	cmp r5, #0
	beq _08074B80
	ldrb r2, [r5, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	movs r4, #0xfd
	ands r0, r4
	strb r0, [r5, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	mov r0, ip
	ldrb r2, [r0, #0xa]
	movs r3, #0xfb
	adds r0, r3, #0
	ands r0, r2
	mov r2, ip
	strb r0, [r2, #0xa]
	ldr r5, _08074BA4 @ =gEnemyFnTable
	mov r8, r5
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r2, #3
	mov r5, ip
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	ldr r0, [r5, #0x28]
	mov ip, r0
	ldrb r0, [r0, #0xa]
	ands r1, r0
	ands r1, r4
	mov r5, ip
	strb r1, [r5, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r0, [r5, #0xa]
	ands r3, r0
	strb r3, [r5, #0xa]
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	str r7, [r6, #0x28]
_08074B80:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _08074BA8 @ =0x0000280C
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r7, [r6, #0xe]
_08074B9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074BA4: .4byte gEnemyFnTable
_08074BA8: .4byte 0x0000280C

	thumb_func_start FUN_08074bac
FUN_08074bac: @ 0x08074BAC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08074BBC
	cmp r0, #1
	beq _08074BD4
	b _08074CA4
_08074BBC:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r1, _08074C10 @ =0x0000280C
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074BD4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08074BDE
	subs r0, #1
	strb r0, [r4, #0x12]
_08074BDE:
	ldr r0, _08074C14 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r6, r1, r0
	movs r0, #0xc0
	lsls r0, r0, #6
	adds r1, r6, r0
	ldr r0, _08074C18 @ =0x00005FFF
	cmp r1, r0
	bhi _08074C00
	ldrb r1, [r4, #0x12]
	cmp r1, #0
	bne _08074C00
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08074C00:
	lsrs r5, r6, #0x1f
	adds r2, r5, #0
	cmp r5, #0
	beq _08074C1C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08074C22
	.align 2, 0
_08074C10: .4byte 0x0000280C
_08074C14: .4byte pZero2
_08074C18: .4byte 0x00005FFF
_08074C1C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08074C22:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r6, r0
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r1, r0
	bls _08074C7C
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #7
	subs r1, #0xc0
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r6, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r6, r0
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074C7A
	movs r0, #5
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _08074C7C
_08074C7A:
	str r6, [r4, #0x58]
_08074C7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08074CAC @ =0x08366FEC
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08074CB0 @ =0x08366E9C
	adds r1, r1, r2
	bl SetDDP
_08074CA4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08074CAC: .4byte 0x08366FEC
_08074CB0: .4byte 0x08366E9C

	thumb_func_start FUN_08074cb4
FUN_08074cb4: @ 0x08074CB4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08074CC4
	cmp r0, #1
	beq _08074CD4
	b _08074D0C
_08074CC4:
	str r0, [r4, #0x60]
	ldr r1, _08074D14 @ =0x00002809
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074CD4:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074CE4
	str r1, [r4, #0x60]
_08074CE4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bge _08074D06
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08074D06:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08074D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074D14: .4byte 0x00002809

	thumb_func_start FUN_08074d18
FUN_08074d18: @ 0x08074D18
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08074D44
	cmp r0, #1
	bgt _08074D2C
	cmp r0, #0
	beq _08074D36
	b _08074D86
_08074D2C:
	cmp r0, #2
	beq _08074D60
	cmp r0, #3
	beq _08074D6E
	b _08074D86
_08074D36:
	ldr r1, _08074D5C @ =0x00002805
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074D44:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _08074D86
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08074D86
	.align 2, 0
_08074D5C: .4byte 0x00002805
_08074D60:
	ldr r1, _08074D8C @ =0x00002806
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074D6E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _08074D86
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08074D86:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074D8C: .4byte 0x00002806

	thumb_func_start FUN_08074d90
FUN_08074d90: @ 0x08074D90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08074DE2
	cmp r0, #1
	bgt _08074DA4
	cmp r0, #0
	beq _08074DAE
	b _08074E82
_08074DA4:
	cmp r0, #2
	beq _08074E24
	cmp r0, #3
	beq _08074E36
	b _08074E82
_08074DAE:
	ldr r0, _08074E1C @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08074DC2
	movs r2, #0x80
	lsls r2, r2, #2
_08074DC2:
	str r2, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xa
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldr r1, _08074E20 @ =0x00002807
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074DE2:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074DFA
	str r1, [r4, #0x60]
_08074DFA:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _08074E82
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08074E82
	.align 2, 0
_08074E1C: .4byte 0xFFFFFE00
_08074E20: .4byte 0x00002807
_08074E24:
	movs r0, #0
	strb r0, [r4, #0x13]
	ldr r1, _08074E88 @ =0x00002808
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074E36:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08074E4E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08074E8C @ =0x08366F2C
	bl SetDDP
_08074E4E:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074E66
	str r1, [r4, #0x60]
_08074E66:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08074E7C
	movs r0, #8
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08074E7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08074E82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074E88: .4byte 0x00002808
_08074E8C: .4byte 0x08366F2C

	thumb_func_start FUN_08074e90
FUN_08074e90: @ 0x08074E90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08074EC6
	cmp r0, #1
	bgt _08074EA4
	cmp r0, #0
	beq _08074EAE
	b _08074F2A
_08074EA4:
	cmp r0, #2
	beq _08074F04
	cmp r0, #3
	beq _08074F12
	b _08074F2A
_08074EAE:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08074EFC @ =0x08366F2C
	bl SetDDP
	ldr r1, _08074F00 @ =0x00002809
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074EC6:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074EDE
	str r1, [r4, #0x60]
_08074EDE:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08074EF4
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074EF4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08074F2A
	.align 2, 0
_08074EFC: .4byte 0x08366F2C
_08074F00: .4byte 0x00002809
_08074F04:
	ldr r1, _08074F30 @ =0x0000280A
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074F12:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08074F2A
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08074F2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074F30: .4byte 0x0000280A

	thumb_func_start FUN_08074f34
FUN_08074f34: @ 0x08074F34
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08074F44
	cmp r5, #1
	beq _08074F6E
	b _08074FB6
_08074F44:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08074FBC @ =0x08366F5C
	bl SetDDP
	ldr r1, _08074FC0 @ =0x0000280B
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl FUN_080bb830
	str r0, [r4, #0x2c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074F6E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08074F7E
	movs r0, #0x18
	strb r0, [r4, #0x12]
	movs r0, #0x3b
	bl PlaySound
_08074F7E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, _08074FC4 @ =pZero2
	ldr r3, [r0]
	ldr r2, [r3, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r2, r1
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r5, #0xfe
	lsls r5, r5, #3
	adds r1, r2, r5
	cmp r0, #0
	beq _08074FA6
	ldr r0, _08074FC8 @ =0xFFFFF800
	adds r1, r2, r0
_08074FA6:
	str r1, [r4, #0x54]
	ldr r0, [r3, #0x58]
	ldr r1, _08074FC8 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08074FB6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08074FBC: .4byte 0x08366F5C
_08074FC0: .4byte 0x0000280B
_08074FC4: .4byte pZero2
_08074FC8: .4byte 0xFFFFF800

	thumb_func_start FUN_08074fcc
FUN_08074fcc: @ 0x08074FCC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08074FDC
	cmp r0, #1
	beq _08074FEC
	b _08075058
_08074FDC:
	strb r0, [r4, #0x12]
	ldr r1, _08075020 @ =0x0000280C
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074FEC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08075028
	ldr r2, _08075024 @ =0xFFFFFC00
	cmp r1, r2
	bge _0807500C
	ldrb r0, [r4, #0x12]
	muls r0, r2, r0
	cmp r0, #0
	bge _0807500A
	adds r0, #0xff
_0807500A:
	asrs r1, r0, #8
_0807500C:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #4
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4, #0x12]
	b _08075030
	.align 2, 0
_08075020: .4byte 0x0000280C
_08075024: .4byte 0xFFFFFC00
_08075028:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08075030:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08075060 @ =0x08366FEC
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08075064 @ =0x08366E9C
	adds r1, r1, r2
	bl SetDDP
_08075058:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08075060: .4byte 0x08366FEC
_08075064: .4byte 0x08366E9C

	thumb_func_start MaybeKillSnakecord
MaybeKillSnakecord: @ 0x08075068
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080750E8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080bb908
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #3
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080750EC @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080750F0 @ =0x0000270E
	cmp r1, r0
	bhi _080750C4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080750C4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _080750F4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080750E8: .4byte 0xFFFFF000
_080750EC: .4byte gMission
_080750F0: .4byte 0x0000270E
_080750F4: .4byte gEnemyFnTable

	thumb_func_start FUN_080750f8
FUN_080750f8: @ 0x080750F8
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _08075150 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08075150: .4byte gEnemyFnTable

	thumb_func_start FUN_08075154
FUN_08075154: @ 0x08075154
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _0807516A
	cmp r7, #1
	bne _08075168
	b _08075282
_08075168:
	b _080752C2
_0807516A:
	ldr r0, [r6, #0x28]
	mov ip, r0
	cmp r0, #0
	beq _080751E2
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	movs r4, #0xfd
	ands r0, r4
	mov r2, ip
	strb r0, [r2, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r2, [r2, #0xa]
	movs r3, #0xfb
	adds r0, r3, #0
	ands r0, r2
	mov r5, ip
	strb r0, [r5, #0xa]
	ldr r0, _08075260 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r2, #3
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	ldr r5, [r5, #0x28]
	mov ip, r5
	ldrb r0, [r5, #0xa]
	ands r1, r0
	ands r1, r4
	strb r1, [r5, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	mov r1, ip
	ldrb r0, [r1, #0xa]
	ands r3, r0
	strb r3, [r1, #0xa]
	ldrb r0, [r1, #9]
	lsls r0, r0, #2
	add r0, r8
	str r2, [r1, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r1, #0x14]
	str r7, [r6, #0x28]
_080751E2:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08075264 @ =0x08366FD4
	bl SetDDP
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _08075268 @ =0x0000280C
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _0807526C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r3, _08075270 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r6, #0x60]
	asrs r1, r1, #8
	adds r5, r1, #0
	muls r5, r1, r5
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r5, r5, r0
	adds r0, r5, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #8
	cmp r5, #0
	beq _08075274
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r6, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r6, #0x60]
	b _0807527C
	.align 2, 0
_08075260: .4byte gEnemyFnTable
_08075264: .4byte 0x08366FD4
_08075268: .4byte 0x0000280C
_0807526C: .4byte pZero2
_08075270: .4byte 0xFFFFE800
_08075274:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
_0807527C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08075282:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807529A
	str r1, [r6, #0x60]
_0807529A:
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080752BC
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080752C2
_080752BC:
	adds r0, r6, #0
	bl MaybeKillSnakecord
_080752C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
