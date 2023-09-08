	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806e590
FUN_0806e590: @ 0x0806E590
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0806E5F8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0806E5F2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0806E5FC @ =gEnemyFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	strb r7, [r3, #0x12]
	adds r1, r3, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x54]
	str r0, [r1]
_0806E5F2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E5F8: .4byte gZakoHeaderPtr
_0806E5FC: .4byte gEnemyFnTable

	thumb_func_start nop_0806e600
nop_0806e600: @ 0x0806E600
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806e604
FUN_0806e604: @ 0x0806E604
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806E66A
	ldr r2, [r3, #0x28]
	cmp r2, #0
	beq _0806E62C
	adds r2, #0xb4
	movs r1, #1
	ldrb r0, [r3, #0x11]
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0806E62C:
	ldr r1, _0806E658 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #2
	str r2, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _0806E65C
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0806E65E
	strb r2, [r3, #0xd]
	b _0806E660
	.align 2, 0
_0806E658: .4byte gEnemyFnTable
_0806E65C:
	movs r0, #1
_0806E65E:
	strb r0, [r3, #0xd]
_0806E660:
	adds r0, r3, #0
	bl Lemmingles_Die
	movs r0, #1
	b _0806E66C
_0806E66A:
	movs r0, #0
_0806E66C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806e674
FUN_0806e674: @ 0x0806E674
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _0806E6FA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0806E6FA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0806E694
	cmp r0, #1
	beq _0806E6D8
	b _0806E6FA
_0806E694:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0806E6FA
	ldr r1, _0806E6D0 @ =0x08366828
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806E6D4 @ =0x08366844
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
_0806E6CA:
	movs r0, #1
	b _0806E6FC
	.align 2, 0
_0806E6D0: .4byte 0x08366828
_0806E6D4: .4byte 0x08366844
_0806E6D8:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0806E6F8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0806E6F4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0806E6CA
	strb r5, [r4, #0xf]
	b _0806E6FA
	.align 2, 0
_0806E6F4: .4byte 0x00020001
_0806E6F8:
	strb r0, [r4, #0xf]
_0806E6FA:
	movs r0, #0
_0806E6FC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806e704
FUN_0806e704: @ 0x0806E704
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0806E744
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806E744
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0806E730
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0806E744
_0806E730:
	ldr r2, _0806E74C @ =0x08366914
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0806E744
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0806E744:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E74C: .4byte 0x08366914

	thumb_func_start Lemmingles_Init
Lemmingles_Init: @ 0x0806E750
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0806E7C8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0806E7CC @ =0x0836691C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r0, _0806E7D0 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x14]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0806E7DC
	ldr r0, _0806E7D4 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _0806E7DC
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0806E7D8 @ =0x0836686C
	adds r2, r5, #0
	adds r2, #0x54
	ldrb r0, [r5, #0x10]
	movs r3, #0xc
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #1
	bhi _0806E7BC
	movs r3, #8
_0806E7BC:
	adds r0, r4, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _0806E804
	.align 2, 0
_0806E7C8: .4byte gEnemyFnTable
_0806E7CC: .4byte 0x0836691C
_0806E7D0: .4byte gSystemSavedataManager
_0806E7D4: .4byte gCurStory
_0806E7D8: .4byte 0x0836686C
_0806E7DC:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r1, _0806E824 @ =0x0836686C
	adds r2, r5, #0
	adds r2, #0x54
	ldrb r0, [r5, #0x10]
	movs r3, #8
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #1
	bhi _0806E7F8
	movs r3, #4
_0806E7F8:
	adds r0, r4, #0
	bl InitBody
	str r5, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
_0806E804:
	ldr r0, _0806E828 @ =nop_0806e600
	str r0, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r1, #8
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl Lemmingles_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E824: .4byte 0x0836686C
_0806E828: .4byte nop_0806e600

	thumb_func_start Lemmingles_Update
Lemmingles_Update: @ 0x0806E82C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	cmp r5, #0
	beq _0806E840
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0806E840
	movs r0, #0
	str r0, [r4, #0x28]
_0806E840:
	ldr r0, _0806E8AC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bhi _0806E85E
	ldr r0, _0806E8B0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x42
	ands r0, r1
	cmp r0, #0
	beq _0806E8B8
_0806E85E:
	cmp r5, #0
	beq _0806E872
	adds r2, r5, #0
	adds r2, #0xb4
	movs r1, #1
	ldrb r0, [r4, #0x11]
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0806E872:
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
	ldr r1, _0806E8B4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0806E8F6
	.align 2, 0
_0806E8AC: .4byte gStageRun+232
_0806E8B0: .4byte gCurStory
_0806E8B4: .4byte gEnemyFnTable
_0806E8B8:
	adds r0, r4, #0
	bl FUN_0806e604
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E8F6
	adds r0, r4, #0
	bl FUN_0806e704
	adds r0, r4, #0
	bl FUN_0806e674
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E8F6
	ldr r1, _0806E8FC @ =0x08366828
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806E900 @ =0x08366844
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0806E8F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E8FC: .4byte 0x08366828
_0806E900: .4byte 0x08366844

	thumb_func_start Lemmingles_Die
Lemmingles_Die: @ 0x0806E904
	push {lr}
	adds r3, r0, #0
	ldr r0, _0806E94C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0806E954
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
	ldr r1, _0806E950 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _0806E964
	.align 2, 0
_0806E94C: .4byte gCurStory
_0806E950: .4byte gEnemyFnTable
_0806E954:
	ldr r0, _0806E968 @ =0x08366860
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_0806E964:
	pop {r0}
	bx r0
	.align 2, 0
_0806E968: .4byte 0x08366860

	thumb_func_start nop_0806e96c
nop_0806e96c: @ 0x0806E96C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806e970
FUN_0806e970: @ 0x0806E970
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0806E98C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0806E988
	movs r1, #0
	movs r0, #6
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0806E988:
	pop {r0}
	bx r0
	.align 2, 0
_0806E98C: .4byte 0x00020001

	thumb_func_start FUN_0806e990
FUN_0806e990: @ 0x0806E990
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0806E9A6
	bl isKilled
	cmp r0, #0
	beq _0806E9D6
_0806E9A6:
	movs r0, #0
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x74
	ldrb r0, [r4, #0x10]
	ldr r1, _0806E9F4 @ =0x08366884
	cmp r0, #1
	bls _0806E9B8
	adds r1, #0x30
_0806E9B8:
	adds r0, r2, #0
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0806E9D6
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xbd
	strb r1, [r0]
_0806E9D6:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0806E9F8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0806E9EC
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806E9EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E9F4: .4byte 0x08366884
_0806E9F8: .4byte 0x00020001

	thumb_func_start FUN_0806e9fc
FUN_0806e9fc: @ 0x0806E9FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806EA0C
	cmp r0, #1
	beq _0806EA20
	b _0806EA58
_0806EA0C:
	str r0, [r4, #0x60]
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806EA60 @ =0x0836689C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EA20:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _0806EA58
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806EA3C
	str r1, [r4, #0x60]
_0806EA3C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0806EA58
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0806EA58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806EA60: .4byte 0x0836689C

	thumb_func_start FUN_0806ea64
FUN_0806ea64: @ 0x0806EA64
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0806EAC0
	cmp r0, #1
	bgt _0806EA7A
	cmp r0, #0
	beq _0806EA80
	b _0806EC44
_0806EA7A:
	cmp r0, #2
	beq _0806EB00
	b _0806EC44
_0806EA80:
	adds r1, r4, #0
	adds r1, #0xbd
	movs r0, #8
	strb r0, [r1]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0806EA96
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0806EA9C
_0806EA96:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806EA9C:
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
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EAC0:
	adds r2, r4, #0
	adds r2, #0x74
	ldrb r0, [r4, #0x10]
	ldr r1, _0806EB40 @ =0x08366884
	cmp r0, #1
	bls _0806EACE
	adds r1, #0x30
_0806EACE:
	adds r0, r2, #0
	bl SetDDP
	ldr r0, _0806EB44 @ =0xFFFFFDC0
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806EAE8
	movs r2, #0x90
	lsls r2, r2, #2
_0806EAE8:
	str r2, [r4, #0x5c]
	ldr r1, _0806EB48 @ =0x08366920
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EB00:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r5, r0, #0
	movs r7, #0
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r2, r1, r0
	movs r0, #0xf0
	lsls r0, r0, #8
	adds r1, r2, r0
	movs r0, #0xf0
	lsls r0, r0, #9
	cmp r1, r0
	bls _0806EB50
	movs r1, #0
	cmp r2, #0
	ble _0806EB32
	movs r1, #1
_0806EB32:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0806EB4C
	cmp r1, #0
	beq _0806EB7E
	b _0806EB50
	.align 2, 0
_0806EB40: .4byte 0x08366884
_0806EB44: .4byte 0xFFFFFDC0
_0806EB48: .4byte 0x08366920
_0806EB4C:
	cmp r1, #0
	bne _0806EB7E
_0806EB50:
	ldr r2, [r4, #0x54]
	ldr r1, _0806EB98 @ =0xFFFFF600
	adds r3, r2, r1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806EB66
	movs r0, #0xa0
	lsls r0, r0, #4
	adds r3, r2, r0
_0806EB66:
	ldr r1, [r4, #0x58]
	ldr r2, _0806EB9C @ =0xFFFFF800
	adds r1, r1, r2
	adds r0, r3, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806EB7A
	movs r7, #1
_0806EB7A:
	cmp r7, #0
	beq _0806EBBE
_0806EB7E:
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0806EBA0
	movs r0, #0x10
	orrs r0, r2
	b _0806EBA4
	.align 2, 0
_0806EB98: .4byte 0xFFFFF600
_0806EB9C: .4byte 0xFFFFF800
_0806EBA0:
	movs r0, #0xef
	ands r0, r2
_0806EBA4:
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
_0806EBBE:
	ldr r0, _0806EBE8 @ =pZero2
	ldr r0, [r0]
	ldr r3, [r0, #0x54]
	ldr r2, [r4, #0x54]
	subs r0, r3, r2
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, _0806EBEC @ =0x00005FFF
	cmp r0, r1
	bhi _0806EC0A
	movs r1, #0
	cmp r2, r3
	bge _0806EBDC
	movs r1, #1
_0806EBDC:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0806EBF0
	cmp r1, #0
	beq _0806EBF4
	b _0806EC0A
	.align 2, 0
_0806EBE8: .4byte pZero2
_0806EBEC: .4byte 0x00005FFF
_0806EBF0:
	cmp r1, #0
	beq _0806EC0A
_0806EBF4:
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r0, [r2]
	cmp r0, #0
	beq _0806EC12
	movs r1, #0
	strb r1, [r2]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0806EC12
_0806EC0A:
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_0806EC12:
	ldr r0, [r4, #0x58]
	subs r0, r5, r0
	ldr r1, _0806EC28 @ =0x000009FF
	cmp r0, r1
	ble _0806EC2C
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0806EC3E
	.align 2, 0
_0806EC28: .4byte 0x000009FF
_0806EC2C:
	adds r1, r4, #0
	adds r1, #0xbd
	ldrb r0, [r1]
	cmp r0, #0
	bne _0806EC3A
	str r5, [r4, #0x58]
	b _0806EC3E
_0806EC3A:
	subs r0, #1
	strb r0, [r1]
_0806EC3E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806EC44:
	cmp r6, #0
	beq _0806ECF6
	ldr r1, [r6, #0x54]
	ldr r0, [r4, #0x54]
	subs r5, r1, r0
	movs r2, #0
	cmp r5, #0
	ble _0806EC56
	movs r2, #1
_0806EC56:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806EC66
	cmp r2, #0
	beq _0806EC6A
	b _0806ECF6
_0806EC66:
	cmp r2, #0
	beq _0806ECF6
_0806EC6A:
	movs r2, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806EC74
	movs r2, #1
_0806EC74:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806EC82
	cmp r2, #0
	beq _0806EC86
	b _0806ECF6
_0806EC82:
	cmp r2, #0
	beq _0806ECF6
_0806EC86:
	ldr r1, [r4, #0x58]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	bgt _0806ECF6
	ldr r2, _0806ECFC @ =0xFFFFE800
	adds r0, r0, r2
	cmp r1, r0
	ble _0806ECF6
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _0806ED00 @ =0x0000057F
	cmp r1, r0
	bhi _0806ECF6
	adds r3, r6, #0
	adds r3, #0xb4
	ldrb r1, [r4, #0x11]
	adds r1, #4
	movs r2, #1
	adds r0, r2, #0
	lsls r0, r1
	ldr r1, [r3]
	orrs r1, r0
	str r1, [r3]
	ldrb r0, [r4, #0x11]
	adds r0, #8
	lsls r2, r0
	orrs r1, r2
	str r1, [r3]
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
	ldr r1, _0806ED04 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0806ECF6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806ECFC: .4byte 0xFFFFE800
_0806ED00: .4byte 0x0000057F
_0806ED04: .4byte gEnemyFnTable

	thumb_func_start FUN_0806ed08
FUN_0806ed08: @ 0x0806ED08
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806ED18
	cmp r5, #1
	beq _0806ED3C
	b _0806EE04
_0806ED18:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806ED26
	ldr r1, _0806ED7C @ =0x00001D07
	adds r0, r4, #0
	bl SetMotion
_0806ED26:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _0806ED34
	ldr r1, _0806ED80 @ =0x00001D0D
	adds r0, r4, #0
	bl SetMotion
_0806ED34:
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806ED3C:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _0806ED46
	cmp r0, #3
	bne _0806ED4C
_0806ED46:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806ED4C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806ED5C
	str r1, [r4, #0x60]
_0806ED5C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0806ED84
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	bge _0806ED9A
	b _0806ED94
	.align 2, 0
_0806ED7C: .4byte 0x00001D07
_0806ED80: .4byte 0x00001D0D
_0806ED84:
	ldr r1, _0806EDF0 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	ble _0806ED9A
_0806ED94:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0806ED9A:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _0806EE04
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl GetMetatileAttr
	movs r1, #0x10
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0
	beq _0806EDF8
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0806EDD6
	adds r2, #0xb4
	movs r1, #1
	ldrb r0, [r4, #0x11]
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0806EDD6:
	ldr r1, _0806EDF4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	b _0806EE04
	.align 2, 0
_0806EDF0: .4byte 0xFFFFFC00
_0806EDF4: .4byte gEnemyFnTable
_0806EDF8:
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806EE04:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806ee0c
FUN_0806ee0c: @ 0x0806EE0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806EE1C
	cmp r0, #1
	beq _0806EE4C
	b _0806EE8E
_0806EE1C:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806EE2A
	ldr r1, _0806EE74 @ =0x00001D04
	adds r0, r4, #0
	bl SetMotion
_0806EE2A:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _0806EE38
	ldr r1, _0806EE78 @ =0x00001D0A
	adds r0, r4, #0
	bl SetMotion
_0806EE38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	strb r0, [r4, #0x13]
	movs r0, #0x12
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EE4C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0806EE8E
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _0806EE6A
	cmp r0, #3
	bne _0806EE7C
_0806EE6A:
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0806EE8E
	.align 2, 0
_0806EE74: .4byte 0x00001D04
_0806EE78: .4byte 0x00001D0A
_0806EE7C:
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0x13]
	cmp r1, #0
	bne _0806EE8E
	adds r0, r4, #0
	adds r0, #0xbd
	strb r1, [r0]
_0806EE8E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806ee94
FUN_0806ee94: @ 0x0806EE94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806EEA4
	cmp r0, #1
	beq _0806EEDE
	b _0806EF9E
_0806EEA4:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806EEB8
	ldr r1, _0806EEB4 @ =0x00001D05
	adds r0, r4, #0
	bl SetMotion
	b _0806EEC0
	.align 2, 0
_0806EEB4: .4byte 0x00001D05
_0806EEB8:
	ldr r1, _0806EEFC @ =0x00001D0B
	adds r0, r4, #0
	bl SetMotion
_0806EEC0:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldr r0, _0806EF00 @ =0xFFFFFA64
	str r0, [r4, #0x60]
	ldr r1, [r4, #0x5c]
	movs r0, #0xd0
	muls r0, r1, r0
	cmp r0, #0
	bge _0806EED4
	adds r0, #0xff
_0806EED4:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EEDE:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x12
	bne _0806EF10
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806EF08
	ldr r1, _0806EF04 @ =0x00001D06
	adds r0, r4, #0
	bl SetMotion
	b _0806EF10
	.align 2, 0
_0806EEFC: .4byte 0x00001D0B
_0806EF00: .4byte 0xFFFFFA64
_0806EF04: .4byte 0x00001D06
_0806EF08:
	ldr r1, _0806EF68 @ =0x00001D0C
	adds r0, r4, #0
	bl SetMotion
_0806EF10:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806EF26
	str r1, [r4, #0x60]
_0806EF26:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0806EF46
	ldr r0, [r4, #0x54]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	ble _0806EF46
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0806EF46:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0806EF80
	cmp r1, #0
	ble _0806EF6C
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _0806EF80
	b _0806EF7A
	.align 2, 0
_0806EF68: .4byte 0x00001D0C
_0806EF6C:
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _0806EF80
_0806EF7A:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0806EF80:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0806EF8E
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806EF8E:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0806EF9E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	strb r0, [r4, #0x13]
_0806EF9E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806efa4
FUN_0806efa4: @ 0x0806EFA4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0806EFE8
	cmp r0, #1
	bgt _0806EFB8
	cmp r0, #0
	beq _0806EFC2
	b _0806F06C
_0806EFB8:
	cmp r0, #2
	beq _0806F014
	cmp r0, #3
	beq _0806F042
	b _0806F06C
_0806EFC2:
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806EFD4
	ldr r1, _0806F00C @ =0x00001D08
	adds r0, r4, #0
	bl SetMotion
_0806EFD4:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _0806EFE2
	ldr r1, _0806F010 @ =0x00001D0E
	adds r0, r4, #0
	bl SetMotion
_0806EFE2:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EFE8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806EFFA
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806EFFA:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _0806F004
	cmp r0, #3
	bne _0806F06C
_0806F004:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0806F06C
	.align 2, 0
_0806F00C: .4byte 0x00001D08
_0806F010: .4byte 0x00001D0E
_0806F014:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806F02A
	ldr r1, _0806F074 @ =0x00001D09
	adds r0, r4, #0
	movs r2, #1
	movs r3, #8
	bl GotoMotion
_0806F02A:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _0806F03C
	ldr r1, _0806F078 @ =0x00001D0F
	adds r0, r4, #0
	movs r2, #1
	movs r3, #8
	bl GotoMotion
_0806F03C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806F042:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _0806F04C
	cmp r0, #3
	bne _0806F052
_0806F04C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806F052:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0806F06C
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xbd
	strb r1, [r0]
_0806F06C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806F074: .4byte 0x00001D09
_0806F078: .4byte 0x00001D0F

	thumb_func_start FUN_0806f07c
FUN_0806f07c: @ 0x0806F07C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0806F08C
	cmp r0, #1
	beq _0806F142
	b _0806F1D6
_0806F08C:
	ldr r2, [r6, #0x28]
	cmp r2, #0
	beq _0806F0A0
	adds r2, #0xb4
	movs r1, #1
	ldrb r0, [r6, #0x11]
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0806F0A0:
	adds r2, r6, #0
	adds r2, #0x74
	ldrb r0, [r6, #0x10]
	ldr r1, _0806F124 @ =0x083668E4
	cmp r0, #1
	bls _0806F0AE
	adds r1, #0x18
_0806F0AE:
	adds r0, r2, #0
	bl SetDDP
	ldr r1, _0806F128 @ =0x08366928
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _0806F12C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r3, _0806F130 @ =0xFFFFE800
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
	beq _0806F134
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
	b _0806F13C
	.align 2, 0
_0806F124: .4byte 0x083668E4
_0806F128: .4byte 0x08366928
_0806F12C: .4byte pZero2
_0806F130: .4byte 0xFFFFE800
_0806F134:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
_0806F13C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0806F142:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #0
	ble _0806F168
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	bge _0806F17C
	ldr r0, [r6, #0x54]
	adds r0, r0, r5
	str r0, [r6, #0x54]
	b _0806F1BA
_0806F168:
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	ble _0806F17C
	ldr r0, [r6, #0x54]
	adds r0, r0, r5
	str r0, [r6, #0x54]
	b _0806F1BA
_0806F17C:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0806F1BA
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806F19A
	str r1, [r6, #0x60]
_0806F19A:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r2, r0, r1
	str r2, [r6, #0x58]
	cmp r1, #0
	ble _0806F1C2
	ldr r0, [r6, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _0806F1D6
	ldr r0, [r6, #0x58]
	adds r0, r0, r5
	str r0, [r6, #0x58]
_0806F1BA:
	adds r0, r6, #0
	bl FUN_0806f1dc
	b _0806F1D6
_0806F1C2:
	ldr r0, [r6, #0x54]
	adds r1, r2, #0
	bl PushoutToDown1
	adds r5, r0, #0
	cmp r5, #0
	ble _0806F1D6
	ldr r0, [r6, #0x58]
	adds r0, r0, r5
	str r0, [r6, #0x58]
_0806F1D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806f1dc
FUN_0806f1dc: @ 0x0806F1DC
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
	ldr r1, _0806F260 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0806F264 @ =0x08366930
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #3
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0806F268 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0806F26C @ =0x0000270E
	cmp r1, r0
	bhi _0806F23C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806F23C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0806F270 @ =gEnemyFnTable
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
_0806F260: .4byte 0xFFFFF000
_0806F264: .4byte 0x08366930
_0806F268: .4byte gMission
_0806F26C: .4byte 0x0000270E
_0806F270: .4byte gEnemyFnTable

	thumb_func_start FUN_0806f274
FUN_0806f274: @ 0x0806F274
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806F286
	cmp r0, #1
	beq _0806F36C
	b _0806F3BC
_0806F286:
	movs r3, #0
	ldr r0, _0806F328 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0806F298
	movs r3, #1
_0806F298:
	adds r7, r3, #0
	movs r6, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _0806F2A6
	cmp r0, #3
	bne _0806F2A8
_0806F2A6:
	movs r6, #1
_0806F2A8:
	ldr r1, _0806F32C @ =0x00001D12
	cmp r6, #0
	beq _0806F2B0
	subs r1, #2
_0806F2B0:
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r5, #0
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r7, #0
	bl FUN_080b2b40
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0806F2EC
	adds r0, #3
_0806F2EC:
	asrs r0, r0, #2
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r1, r0
	ldr r1, _0806F330 @ =0x000003FF
	cmp r0, r1
	ble _0806F338
	movs r0, #0x20
	str r0, [r4, #0x68]
	adds r1, r4, #0
	adds r1, #0x54
	lsls r0, r6, #1
	ldr r2, _0806F334 @ =0x08366936
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b84f4
	b _0806F354
	.align 2, 0
_0806F328: .4byte pZero2
_0806F32C: .4byte 0x00001D12
_0806F330: .4byte 0x000003FF
_0806F334: .4byte 0x08366936
_0806F338:
	str r5, [r4, #0x68]
	adds r1, r4, #0
	adds r1, #0x54
	lsls r0, r6, #1
	ldr r2, _0806F3C4 @ =0x08366936
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
_0806F354:
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806F36C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _0806F3A2
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806F388
	str r1, [r4, #0x60]
_0806F388:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0806F3A2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0806F3A2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806F3BC
	adds r0, r4, #0
	bl FUN_0806f1dc
_0806F3BC:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F3C4: .4byte 0x08366936
