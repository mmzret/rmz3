	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initHeavyCannon
initHeavyCannon: @ 0x080CBEA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080CBFCC @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	mov r8, r1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080CBFD0 @ =u8_ARRAY_0836ff1c
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	bls _080CBEF2
	b _080CC07C
_080CBEF2:
	ldr r1, _080CBFD4 @ =0x00003801
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r5, r6, #0
	str r4, [r6, #0x28]
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	beq _080CBFDC
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0xb4
	str r4, [r0]
	ldrb r0, [r6, #0x10]
	adds r0, #1
	lsls r0, r0, #0xc
	subs r4, r4, r0
	str r4, [r6, #0x58]
	movs r3, #0
	ldrb r0, [r6, #0x10]
	adds r0, #1
	adds r7, r6, #0
	adds r7, #0x74
	movs r1, #0x54
	adds r1, r1, r6
	mov sl, r1
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
	cmp r3, r0
	bge _080CC022
	mov r8, r3
_080CBF5C:
	ldr r0, _080CBFD8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	str r3, [sp]
	bl AllocEntityLast
	adds r2, r0, #0
	ldr r3, [sp]
	cmp r2, #0
	beq _080CBFC0
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CBFCC @ =gSolidFnTable
	movs r0, #5
	strb r0, [r2, #9]
	ldr r0, [r1, #0x14]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	mov r1, r8
	strh r1, [r2, #0x20]
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
	movs r0, #4
	strb r0, [r2, #0x10]
	ldr r0, [r6, #0x54]
	str r0, [r2, #0x54]
	str r4, [r2, #0x58]
	adds r1, r2, #0
	adds r1, #0xb4
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r1]
	str r5, [r2, #0x28]
	str r2, [r5, #0x2c]
	mov r0, r8
	str r0, [r2, #0x2c]
	adds r5, r2, #0
_080CBFC0:
	adds r3, #1
	ldrb r0, [r6, #0x10]
	adds r0, #1
	cmp r3, r0
	blt _080CBF5C
	b _080CC022
	.align 2, 0
_080CBFCC: .4byte gSolidFnTable
_080CBFD0: .4byte u8_ARRAY_0836ff1c
_080CBFD4: .4byte 0x00003801
_080CBFD8: .4byte gSolidHeaderPtr
_080CBFDC:
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	mov r1, r8
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb4
	str r0, [r1]
	str r4, [r6, #0x2c]
	str r4, [r6, #0x28]
	adds r7, r6, #0
	adds r7, #0x74
	movs r0, #0x54
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
_080CC022:
	ldr r0, _080CC050 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CC05C
	ldr r0, _080CC054 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080CC05C
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	ldr r1, _080CC058 @ =sCollisions
	adds r0, r7, #0
	mov r2, sl
	movs r3, #0x14
	b _080CC06E
	.align 2, 0
_080CC050: .4byte gSystemSavedata
_080CC054: .4byte gCurStory
_080CC058: .4byte sCollisions
_080CC05C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080CC078 @ =sCollisions
	adds r0, r7, #0
	mov r2, sl
	movs r3, #0x10
_080CC06E:
	bl InitBody
	str r6, [r7, #0x2c]
	str r4, [r7, #0x24]
	b _080CC0F4
	.align 2, 0
_080CC078: .4byte sCollisions
_080CC07C:
	ldr r0, _080CC0C0 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CC0CC
	ldr r0, _080CC0C4 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080CC0CC
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080CC0C8 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r7, r4, #0
	movs r0, #0xb8
	adds r0, r0, r6
	mov sb, r0
	b _080CC0F4
	.align 2, 0
_080CC0C0: .4byte gSystemSavedata
_080CC0C4: .4byte gCurStory
_080CC0C8: .4byte sCollisions
_080CC0CC:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080CC118 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r7, r4, #0
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
_080CC0F4:
	ldr r0, _080CC11C @ =nop_080cbea4
	str r0, [r7, #0x24]
	movs r0, #0
	mov r1, sb
	str r0, [r1]
	str r0, [r6, #0x60]
	adds r0, r6, #0
	bl heavyCannonAI
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC118: .4byte sCollisions
_080CC11C: .4byte nop_080cbea4

	thumb_func_start heavyCannonAI
heavyCannonAI: @ 0x080CC120
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _080CC190
	ldr r0, _080CC144 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080CC148
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080CC15A
	.align 2, 0
_080CC144: .4byte gCurStory
_080CC148:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _080CC190
	ldrb r0, [r0, #0xc]
	cmp r0, #4
	bne _080CC190
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080CC15A:
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
	ldr r1, _080CC18C @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080CC1BC
	.align 2, 0
_080CC18C: .4byte gSolidFnTable
_080CC190:
	adds r0, r4, #0
	bl FUN_080cbdc0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CC1BC
	ldr r1, _080CC1C4 @ =gHeavyCannonUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CC1C8 @ =gHeavyCannonUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080CC1BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC1C4: .4byte gHeavyCannonUpdates1
_080CC1C8: .4byte gHeavyCannonUpdates2

	thumb_func_start killHeavyCannon
killHeavyCannon: @ 0x080CC1CC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r0, [r4, #0xa]
	movs r1, #0xfb
	ands r1, r0
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r3, [r4, #0x58]
	ldr r2, _080CC270 @ =0xFFFFF800
	adds r0, r3, r2
	str r0, [sp, #4]
	adds r2, r0, #0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CC212
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r3, r0
_080CC212:
	str r2, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080CC274 @ =gHeavyCannonMotions
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b82c0
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	beq _080CC256
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #0
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080CC278 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080CC27C @ =0x0000270E
	cmp r1, r0
	bhi _080CC24E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080CC24E:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
_080CC256:
	ldr r1, _080CC280 @ =gSolidFnTable
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
_080CC270: .4byte 0xFFFFF800
_080CC274: .4byte gHeavyCannonMotions
_080CC278: .4byte gScore
_080CC27C: .4byte 0x0000270E
_080CC280: .4byte gSolidFnTable

