	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08077110
FUN_08077110: @ 0x08077110
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	beq _0807716C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	bge _08077148
	ldr r1, _08077140 @ =0xFFFFFE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08077144 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _0807716C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #1
	b _0807716E
	.align 2, 0
_08077140: .4byte 0xFFFFFE00
_08077144: .4byte 0xFFFFF800
_08077148:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08077168 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _0807716C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #2
	b _0807716E
	.align 2, 0
_08077168: .4byte 0xFFFFF800
_0807716C:
	movs r0, #0
_0807716E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08077174
FUN_08077174: @ 0x08077174
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080771C4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080771BE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _080771C8 @ =gEnemyFnTable
	strb r0, [r3, #9]
	ldr r0, [r1, #0x60]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
_080771BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080771C4: .4byte gZakoHeaderPtr
_080771C8: .4byte gEnemyFnTable

	thumb_func_start FUN_080771cc
FUN_080771cc: @ 0x080771CC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldr r0, _08077228 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08077256
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807722C @ =gEnemyFnTable
	strb r0, [r3, #9]
	ldr r0, [r1, #0x60]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	cmp r7, #0
	bne _08077234
	ldr r1, _08077230 @ =0xFFFFFE00
	adds r0, r4, r1
	str r0, [r3, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	b _08077240
	.align 2, 0
_08077228: .4byte gZakoHeaderPtr
_0807722C: .4byte gEnemyFnTable
_08077230: .4byte 0xFFFFFE00
_08077234:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r3, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #3
_08077240:
	adds r0, r5, r1
	str r0, [r3, #0x58]
	strb r7, [r3, #0x12]
	cmp r6, #0
	beq _08077254
	adds r1, r6, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08077254:
	str r6, [r3, #0x28]
_08077256:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start nop_0807725c
nop_0807725c: @ 0x0807725C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08077260
FUN_08077260: @ 0x08077260
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080772F0
	ldrb r4, [r2, #0x10]
	cmp r4, #1
	bne _080772B0
	ldr r1, _080772A8 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r5, #2
	str r5, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _080772DC
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _080772AC
	strb r5, [r2, #0xd]
	b _080772E6
	.align 2, 0
_080772A8: .4byte gEnemyFnTable
_080772AC:
	strb r0, [r2, #0xd]
	b _080772E6
_080772B0:
	ldr r1, [r2, #0x28]
	cmp r1, #0
	beq _080772BE
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080772BE:
	ldr r1, _080772E0 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080772E4
_080772DC:
	strb r4, [r2, #0xd]
	b _080772E6
	.align 2, 0
_080772E0: .4byte gEnemyFnTable
_080772E4:
	strb r1, [r2, #0xd]
_080772E6:
	adds r0, r2, #0
	bl Volcaire_Die
	movs r0, #1
	b _080772F2
_080772F0:
	movs r0, #0
_080772F2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080772f8
FUN_080772f8: @ 0x080772F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _0807737E
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0807737E
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08077318
	cmp r0, #1
	beq _0807735C
	b _0807737E
_08077318:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0807737E
	ldr r1, _08077354 @ =0x0836726C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08077358 @ =0x0836728C
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
_0807734E:
	movs r0, #1
	b _08077380
	.align 2, 0
_08077354: .4byte 0x0836726C
_08077358: .4byte 0x0836728C
_0807735C:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0807737C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08077378 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807734E
	strb r5, [r4, #0xf]
	b _0807737E
	.align 2, 0
_08077378: .4byte 0x00020001
_0807737C:
	strb r0, [r4, #0xf]
_0807737E:
	movs r0, #0
_08077380:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08077388
FUN_08077388: @ 0x08077388
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080773D0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080773D0
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080773D0
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080773BC
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080773D0
_080773BC:
	ldr r2, _080773D8 @ =0x083673F0
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080773D0
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080773D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080773D8: .4byte 0x083673F0

	thumb_func_start Volcaire_Init
Volcaire_Init: @ 0x080773DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0807742C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08077430 @ =0x083673F8
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r2, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08077434
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _080774BC
	.align 2, 0
_0807742C: .4byte gEnemyFnTable
_08077430: .4byte 0x083673F8
_08077434:
	cmp r0, #0
	blt _080774BC
	cmp r0, #2
	bgt _080774BC
	adds r0, r6, #0
	adds r0, #0xb9
	strb r2, [r0]
	ldrb r0, [r6, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, _08077484 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x14]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08077490
	ldr r0, _08077488 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08077490
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807748C @ =0x083672B8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _080774A8
	.align 2, 0
_08077484: .4byte gSystemSavedataManager
_08077488: .4byte gCurStory
_0807748C: .4byte 0x083672B8
_08077490:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080774C8 @ =0x083672B8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_080774A8:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080774CC @ =nop_0807725c
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
_080774BC:
	adds r0, r6, #0
	bl Volcaire_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080774C8: .4byte 0x083672B8
_080774CC: .4byte nop_0807725c

	thumb_func_start Volcaire_Update
Volcaire_Update: @ 0x080774D0
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0807754C @ =gCurStory
	ldrb r1, [r2, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08077512
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08077554
	ldr r3, [r4, #0x28]
	cmp r3, #0
	beq _080774FA
	ldrb r0, [r3, #0xc]
	cmp r0, #1
	bls _080774FA
	str r1, [r4, #0x28]
	movs r3, #0
_080774FA:
	ldrb r1, [r2, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08077554
	cmp r3, #0
	beq _08077512
	adds r1, r3, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08077512:
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
	ldr r1, _08077550 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08077592
	.align 2, 0
_0807754C: .4byte gCurStory
_08077550: .4byte gEnemyFnTable
_08077554:
	adds r0, r4, #0
	bl FUN_08077260
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077592
	adds r0, r4, #0
	bl FUN_08077388
	adds r0, r4, #0
	bl FUN_080772f8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077592
	ldr r1, _08077598 @ =0x0836726C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807759C @ =0x0836728C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08077592:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08077598: .4byte 0x0836726C
_0807759C: .4byte 0x0836728C

	thumb_func_start Volcaire_Die
Volcaire_Die: @ 0x080775A0
	push {lr}
	adds r3, r0, #0
	ldr r0, _080775E8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080775F0
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
	ldr r1, _080775EC @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _08077600
	.align 2, 0
_080775E8: .4byte gCurStory
_080775EC: .4byte gEnemyFnTable
_080775F0:
	ldr r0, _08077604 @ =0x083672AC
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_08077600:
	pop {r0}
	bx r0
	.align 2, 0
_08077604: .4byte 0x083672AC

	thumb_func_start nop_08077608
nop_08077608: @ 0x08077608
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807760c
FUN_0807760c: @ 0x0807760C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08077628 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08077624
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08077624:
	pop {r0}
	bx r0
	.align 2, 0
_08077628: .4byte 0x00020001

	thumb_func_start FUN_0807762c
FUN_0807762c: @ 0x0807762C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08077642
	bl isKilled
	cmp r0, #0
	beq _0807768A
_08077642:
	movs r0, #0
	str r0, [r5]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0807765C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077658 @ =0x083672D0
	bl SetDDP
	b _08077666
	.align 2, 0
_08077658: .4byte 0x083672D0
_0807765C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077680 @ =0x08367360
	bl SetDDP
_08077666:
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0807768A
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08077684
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0807768A
	.align 2, 0
_08077680: .4byte 0x08367360
_08077684:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807768A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080776A8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080776A0
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080776A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080776A8: .4byte 0x00020001

	thumb_func_start FUN_080776ac
FUN_080776ac: @ 0x080776AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080776BC
	cmp r0, #1
	beq _080776FC
	b _080777BE
_080776BC:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _080776DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080776D8 @ =0x083672E8
	bl SetDDP
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080776F2
	.align 2, 0
_080776D8: .4byte 0x083672E8
_080776DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077750 @ =0x08367378
	bl SetDDP
	ldr r1, _08077754 @ =0x00002E05
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
_080776F2:
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080776FC:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _080777B8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08077716
	str r1, [r4, #0x60]
_08077716:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _080777B8
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	adds r6, r4, #0
	adds r6, #0xb9
	cmp r0, #0
	bne _08077758
	ldrb r0, [r6]
	cmp r0, #0
	bne _08077758
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	b _080777B8
	.align 2, 0
_08077750: .4byte 0x08367378
_08077754: .4byte 0x00002E05
_08077758:
	ldr r0, _080777C4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _080777B4
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	bne _0807777E
	ldr r1, [r4, #0x28]
	cmp r1, #0
	beq _0807777E
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0807777E:
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
	ldr r1, _080777C8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080777B4:
	movs r0, #1
	strb r0, [r6]
_080777B8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080777BE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080777C4: .4byte gStageRun+232
_080777C8: .4byte gEnemyFnTable

	thumb_func_start FUN_080777cc
FUN_080777cc: @ 0x080777CC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080777EE
	cmp r0, #1
	bgt _080777E0
	cmp r0, #0
	beq _080777E6
	b _0807782C
_080777E0:
	cmp r0, #2
	beq _08077806
	b _0807782C
_080777E6:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080777EE:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080777F8
	movs r0, #0xc0
	b _080777FE
_080777F8:
	movs r0, #1
	strb r0, [r4, #0x13]
	movs r0, #0x28
_080777FE:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077806:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077826
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #3
	bhi _08077822
	adds r0, r4, #0
	bl FUN_08077174
_08077822:
	movs r0, #1
	strb r0, [r4, #0xe]
_08077826:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807782C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08077834
FUN_08077834: @ 0x08077834
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08077870
	cmp r0, #1
	bgt _08077848
	cmp r0, #0
	beq _08077852
	b _08077902
_08077848:
	cmp r0, #2
	beq _08077898
	cmp r0, #3
	beq _080778A6
	b _08077902
_08077852:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077890 @ =0x083672D0
	bl SetDDP
	ldr r0, _08077894 @ =0xFFFFF800
	str r0, [r4, #0x60]
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077870:
	ldr r1, [r4, #0x60]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	cmp r1, #0
	ble _08077886
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077886:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08077902
	.align 2, 0
_08077890: .4byte 0x083672D0
_08077894: .4byte 0xFFFFF800
_08077898:
	ldr r1, _08077908 @ =0x00002E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080778A6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r5, [r0]
	cmp r5, #3
	bne _08077902
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r3, #0
	bl FUN_080771cc
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r3, #1
	bl FUN_080771cc
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
	ldr r1, _0807790C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08077902:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077908: .4byte 0x00002E01
_0807790C: .4byte gEnemyFnTable

	thumb_func_start FUN_08077910
FUN_08077910: @ 0x08077910
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0807791E
	b _08077A2C
_0807791E:
	lsls r0, r0, #2
	ldr r1, _08077928 @ =_0807792C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077928: .4byte _0807792C
_0807792C: @ jump table
	.4byte _08077944 @ case 0
	.4byte _080779FE @ case 1
	.4byte _080779A8 @ case 2
	.4byte _080779FE @ case 3
	.4byte _08077A18 @ case 4
	.4byte _08077A2C @ case 5
_08077944:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08077968
	ldr r1, _08077960 @ =0x00002E02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077964 @ =0x08367300
	bl SetDDP
	b _0807797A
	.align 2, 0
_08077960: .4byte 0x00002E02
_08077964: .4byte 0x08367300
_08077968:
	ldr r1, _0807799C @ =0x00002E03
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080779A0 @ =0x08367330
	bl SetDDP
_0807797A:
	movs r0, #8
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	lsls r1, r0, #0xf
	ldr r2, _080779A4 @ =0xFFFFC000
	adds r0, r1, r2
	str r0, [r4, #0x5c]
	cmp r0, #0
	bge _08077990
	adds r2, #0x1f
	adds r0, r1, r2
_08077990:
	asrs r0, r0, #5
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	b _080779F8
	.align 2, 0
_0807799C: .4byte 0x00002E03
_080779A0: .4byte 0x08367330
_080779A4: .4byte 0xFFFFC000
_080779A8:
	movs r0, #8
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080779CC @ =0x08367360
	bl SetDDP
	ldr r1, _080779D0 @ =0x00002E04
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080779D4
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080779DA
	.align 2, 0
_080779CC: .4byte 0x08367360
_080779D0: .4byte 0x00002E04
_080779D4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080779DA:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
_080779F8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080779FE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077A10
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077A10:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08077A2C
_08077A18:
	ldr r1, _08077A7C @ =0x00002E05
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077A2C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08077A3C
	str r1, [r4, #0x60]
_08077A3C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0xb9
	cmp r6, #0
	bge _08077A84
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08077A80
	ldrb r1, [r5]
	cmp r1, #0
	bne _08077A80
	ldr r0, [r4, #0x58]
	adds r0, r0, r6
	str r0, [r4, #0x58]
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08077A84
	.align 2, 0
_08077A7C: .4byte 0x00002E05
_08077A80:
	movs r0, #1
	strb r0, [r5]
_08077A84:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08077A92
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08077110
_08077A92:
	ldr r0, _08077AF0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08077AE8
	cmp r7, #0
	beq _08077AB2
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08077AB2:
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
	ldr r1, _08077AF4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08077AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077AF0: .4byte gStageRun+232
_08077AF4: .4byte gEnemyFnTable

	thumb_func_start FUN_08077af8
FUN_08077af8: @ 0x08077AF8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08077B08
	cmp r0, #1
	beq _08077B16
	b _08077B2E
_08077B08:
	ldr r1, _08077B34 @ =0x00002E05
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077B16:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08077B2E
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08077B2E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08077B34: .4byte 0x00002E05

	thumb_func_start FUN_08077b38
FUN_08077b38: @ 0x08077B38
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08077B4A
	cmp r0, #1
	beq _08077B78
	b _08077C96
_08077B4A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077BA0 @ =0x08367390
	bl SetDDP
	ldr r1, _08077BA4 @ =0x00002E06
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08077BA8 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08077B70
	movs r2, #0xc0
	lsls r2, r2, #1
_08077B70:
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077B78:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r2, r0
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	ble _08077BAC
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08077C3A
	.align 2, 0
_08077BA0: .4byte 0x08367390
_08077BA4: .4byte 0x00002E06
_08077BA8: .4byte 0xFFFFFE80
_08077BAC:
	str r2, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r5, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08077BEC
	ldr r0, [r4, #0x54]
	ldr r1, _08077BE4 @ =0xFFFFF600
	adds r0, r0, r1
	ldr r3, _08077BE8 @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToRight1
	cmp r0, #0
	ble _08077C3A
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08077C1C
	adds r0, r5, #0
	orrs r0, r2
	b _08077C20
	.align 2, 0
_08077BE4: .4byte 0xFFFFF600
_08077BE8: .4byte 0xFFFFF800
_08077BEC:
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r3, _08077C18 @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToLeft1
	cmp r0, #0
	bge _08077C3A
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08077C1C
	adds r0, r2, #0
	orrs r0, r5
	b _08077C20
	.align 2, 0
_08077C18: .4byte 0xFFFFF800
_08077C1C:
	movs r0, #0xef
	ands r0, r2
_08077C20:
	strb r0, [r4, #0xa]
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
_08077C3A:
	ldr r0, _08077C9C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08077C90
	cmp r6, #0
	beq _08077C5A
	adds r1, r6, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08077C5A:
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
	ldr r1, _08077CA0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08077C90:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08077C96:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08077C9C: .4byte gStageRun+232
_08077CA0: .4byte gEnemyFnTable

	thumb_func_start FUN_08077ca4
FUN_08077ca4: @ 0x08077CA4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08077CB6
	cmp r0, #1
	beq _08077CBE
	b _08077DC0
_08077CB6:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077CBE:
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08077D0C
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08077CF4
	ldr r1, [r4, #0x58]
	ldr r0, _08077CF0 @ =0xFFFFF800
	adds r1, r1, r0
	adds r0, r2, #0
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	ble _08077D0C
	b _08077D06
	.align 2, 0
_08077CF0: .4byte 0xFFFFF800
_08077CF4:
	ldr r1, [r4, #0x58]
	ldr r0, _08077D5C @ =0xFFFFF800
	adds r1, r1, r0
	adds r0, r2, #0
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	bge _08077D0C
_08077D06:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08077D0C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08077D1C
	str r1, [r4, #0x60]
_08077D1C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _08077D64
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08077D60
	ldrb r0, [r6]
	cmp r0, #0
	bne _08077D60
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	movs r0, #5
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	b _08077D64
	.align 2, 0
_08077D5C: .4byte 0xFFFFF800
_08077D60:
	movs r0, #1
	strb r0, [r6]
_08077D64:
	ldr r0, _08077DC8 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08077DBA
	cmp r7, #0
	beq _08077D84
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08077D84:
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
	ldr r1, _08077DCC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08077DBA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08077DC0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077DC8: .4byte gStageRun+232
_08077DCC: .4byte gEnemyFnTable

	thumb_func_start FUN_08077dd0
FUN_08077dd0: @ 0x08077DD0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08077DE0
	cmp r0, #1
	beq _08077E96
	b _08077F06
_08077DE0:
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08077E00
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08077DFC @ =0x083673C0
	bl SetDDP
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	b _08077E16
	.align 2, 0
_08077DFC: .4byte 0x083673C0
_08077E00:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08077E78 @ =0x083673D8
	bl SetDDP
	ldr r1, _08077E7C @ =0x00002E05
	adds r0, r5, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
_08077E16:
	ldr r0, _08077E80 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08077E84 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08077E88
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08077E90
	.align 2, 0
_08077E78: .4byte 0x083673D8
_08077E7C: .4byte 0x00002E05
_08077E80: .4byte pZero2
_08077E84: .4byte 0xFFFFE800
_08077E88:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08077E90:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08077E96:
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _08077EAA
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_08077EAA:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08077EBA
	str r1, [r5, #0x60]
_08077EBA:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _08077F00
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _08077F00
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08077EFC
	ldrb r0, [r4]
	cmp r0, #0
	bne _08077EFC
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl MaybeKillVolcaire
	b _08077F06
_08077EFC:
	movs r0, #1
	strb r0, [r4]
_08077F00:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08077F06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start MaybeKillVolcaire
MaybeKillVolcaire: @ 0x08077F0C
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
	ldr r1, _08077F90 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08077F94 @ =0x083673FC
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08077F98 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08077F9C @ =0x0000270E
	cmp r1, r0
	bhi _08077F6C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08077F6C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08077FA0 @ =gEnemyFnTable
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
_08077F90: .4byte 0xFFFFF000
_08077F94: .4byte 0x083673FC
_08077F98: .4byte gMission
_08077F9C: .4byte 0x0000270E
_08077FA0: .4byte gEnemyFnTable

	thumb_func_start FUN_08077fa4
FUN_08077fa4: @ 0x08077FA4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08077FB6
	cmp r0, #1
	beq _0807806E
	b _080780B4
_08077FB6:
	movs r3, #0
	ldr r0, _08077FD8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08077FC8
	movs r3, #1
_08077FC8:
	adds r7, r3, #0
	adds r2, r7, #0
	cmp r7, #0
	beq _08077FDC
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08077FE2
	.align 2, 0
_08077FD8: .4byte pZero2
_08077FDC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08077FE2:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r5, r7, #8
	ldr r0, [r6, #0x54]
	subs r0, r0, r5
	str r0, [r6, #0x54]
	ldr r1, _080780BC @ =0x00002E07
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r7, #0
	bl FUN_080b2b40
	movs r0, #0x80
	subs r0, r0, r5
	str r0, [sp, #8]
	movs r1, #0x60
	str r1, [sp, #0xc]
	movs r1, #3
	bl __divsi3
	str r0, [r6, #0x5c]
	str r4, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0x54
	ldr r0, _080780C0 @ =0x08367402
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r6, #0
	add r2, sp, #8
	movs r3, #0x20
	bl FUN_080b84f4
	strb r4, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807806E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x60]
	adds r0, #0x15
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08078086
	str r1, [r6, #0x60]
_08078086:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080780AE
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080780B4
_080780AE:
	adds r0, r6, #0
	bl MaybeKillVolcaire
_080780B4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080780BC: .4byte 0x00002E07
_080780C0: .4byte 0x08367402
