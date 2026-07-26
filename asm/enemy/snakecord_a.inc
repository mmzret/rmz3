	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl IsFrozen
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
	bl UpdateEntityAnim
_080742A8:
	movs r0, #1
	b _080742E4
	.align 2, 0
_080742AC: .4byte gVFXFnTable
_080742B0: .4byte PTR_ARRAY_08366e30
_080742B4: .4byte PTR_ARRAY_08366e60
_080742B8:
	adds r0, r4, #0
	bl IsFrozen
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
_08074338: .4byte sElementCoords+(1*8)
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
_0807435C: .4byte sElementCoords

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
	ldr r1, _080743D8 @ =sInitModes
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
	ldr r0, _080743DC @ =gSystemSavedata
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
	ldr r1, _080743E4 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _08074400
	.align 2, 0
_080743D4: .4byte gEnemyFnTable
_080743D8: .4byte sInitModes
_080743DC: .4byte gSystemSavedata
_080743E0: .4byte gCurStory
_080743E4: .4byte sCollisions
_080743E8:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080744C4 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_08074400:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080744C8 @ =SnakeCord_onCollision
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
	ldr r0, _080744D0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	str r3, [sp]
	bl AllocEntityFirst
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
_080744C4: .4byte sCollisions
_080744C8: .4byte SnakeCord_onCollision
_080744CC: .4byte gSineTable
_080744D0: .4byte gEnemyHeaderPtr
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
_080745A8: .4byte PTR_ARRAY_08366e30
_080745AC: .4byte PTR_ARRAY_08366e60

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
_08074614: .4byte PTR_ARRAY_08366e90

	thumb_func_start FUN_08074618
FUN_08074618:
	bx lr
  .align 2, 0

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
