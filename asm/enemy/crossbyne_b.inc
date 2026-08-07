	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Crossbyne_Init
Crossbyne_Init: @ 0x0807CE0C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0807CE68 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _0807CE6C @ =sInitModes
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	bls _0807CE74
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807CE70 @ =0x08367B9C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _0807CED4
	.align 2, 0
_0807CE68: .4byte gEnemyFnTable
_0807CE6C: .4byte sInitModes
_0807CE70: .4byte sCollisions
_0807CE74:
	ldr r0, _0807CEA8 @ =gSystemSavedata
	ldrb r1, [r0, #0x10]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0807CEB4
	ldr r0, _0807CEAC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0807CEB4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807CEB0 @ =0x08367B9C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	b _0807CECC
	.align 2, 0
_0807CEA8: .4byte gSystemSavedata
_0807CEAC: .4byte gCurStory
_0807CEB0: .4byte sCollisions
_0807CEB4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807CEF8 @ =0x08367B9C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
_0807CECC:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_0807CED4:
	ldr r0, _0807CEFC @ =onCollision
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	subs r1, #0x93
	movs r0, #0x14
	strb r0, [r1]
	adds r0, r6, #0
	bl Crossbyne_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807CEF8: .4byte sCollisions
_0807CEFC: .4byte onCollision

	thumb_func_start Crossbyne_Update
Crossbyne_Update: @ 0x0807CF00
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807cd74
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807CF34
	adds r0, r4, #0
	bl crossbyne_0807cdc4
	ldr r1, _0807CF3C @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807CF40 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807CF34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CF3C: .4byte sUpdates1
_0807CF40: .4byte sUpdates2

	thumb_func_start Crossbyne_Die
Crossbyne_Die: @ 0x0807CF44
	push {lr}
	ldr r2, _0807CF58 @ =sDeads
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0807CF58: .4byte sDeads

	thumb_func_start FUN_0807cf5c
FUN_0807cf5c: @ 0x0807CF5C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807cf60
FUN_0807cf60: @ 0x0807CF60
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0807CF76
	bl isKilled
	cmp r0, #0
	beq _0807CF80
_0807CF76:
	movs r1, #0
	str r1, [r5]
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807CF80:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807cf88
FUN_0807cf88: @ 0x0807CF88
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807CFA2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807CFA8 @ =0x08367BCC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807CFA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CFA8: .4byte sCollisions+(2*24)

	thumb_func_start FUN_0807cfac
FUN_0807cfac: @ 0x0807CFAC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807CFBC
	cmp r0, #1
	beq _0807CFD8
	b _0807CFF0
_0807CFBC:
	ldr r0, _0807CFF8 @ =0x0000012B
	bl PlaySound
	ldr r1, _0807CFFC @ =0x08367C40
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807CFD8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807CFF0
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807CFF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CFF8: .4byte 0x0000012B
_0807CFFC: .4byte sMotions

	thumb_func_start FUN_0807d000
FUN_0807d000: @ 0x0807D000
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0807D03E
	cmp r0, #1
	bgt _0807D014
	cmp r0, #0
	beq _0807D01A
	b _0807D078
_0807D014:
	cmp r0, #2
	beq _0807D060
	b _0807D078
_0807D01A:
	movs r0, #0x20
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807D058 @ =0x08367BB4
	bl SetDDP
	ldr r1, _0807D05C @ =0x08367C44
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807D03E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807D050
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807D050:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0807D078
	.align 2, 0
_0807D058: .4byte sCollisions+(1*24)
_0807D05C: .4byte sMotions+(2*2)
_0807D060:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #3
	bne _0807D078
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807D078:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start crossbyne_0807d080
crossbyne_0807d080: @ 0x0807D080
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807D090
	cmp r0, #1
	beq _0807D0CC
	b _0807D0E4
_0807D090:
	movs r0, #0x2c
	bl PlaySound
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0807D0A6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0807cc50
	b _0807D0AE
_0807D0A6:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0807cce0
_0807D0AE:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0807D0EC @ =0x08367C48
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807D0CC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807D0E4
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807D0E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D0EC: .4byte sMotions+(4*2)

	thumb_func_start FUN_0807d0f0
FUN_0807d0f0: @ 0x0807D0F0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807D100
	cmp r0, #1
	beq _0807D120
	b _0807D164
_0807D100:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807D16C @ =0x08367B9C
	bl SetDDP
	ldr r1, _0807D170 @ =0x08367C4C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807D120:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _0807D164
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
	ldr r1, _0807D174 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0807D164:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D16C: .4byte sCollisions
_0807D170: .4byte sMotions+(6*2)
_0807D174: .4byte gEnemyFnTable

	thumb_func_start FUN_0807d178
FUN_0807d178: @ 0x0807D178
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0807D188
	cmp r0, #1
	beq _0807D244
	b _0807D2A2
_0807D188:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0807D1B0 @ =0x08367BE4
	bl SetDDP
	ldrb r0, [r6, #0x11]
	cmp r0, #1
	bhi _0807D1F0
	ldr r1, _0807D1B4 @ =0x00004313
	adds r0, r6, #0
	bl SetMotion
	ldrb r2, [r6, #0x11]
	cmp r2, #0
	beq _0807D1B8
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0807D1BE
	.align 2, 0
_0807D1B0: .4byte sCollisions+(3*24)
_0807D1B4: .4byte 0x00004313
_0807D1B8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807D1BE:
	strb r0, [r6, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r6, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r6, #0x11]
	lsls r0, r0, #0xa
	ldr r1, _0807D1EC @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r6, #0x5c]
	str r3, [r6, #0x60]
	b _0807D23E
	.align 2, 0
_0807D1EC: .4byte 0xFFFFFE00
_0807D1F0:
	movs r2, #1
	ands r2, r0
	cmp r2, #0
	beq _0807D200
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	orrs r0, r1
	b _0807D206
_0807D200:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_0807D206:
	strb r0, [r6, #0xa]
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
	adds r0, r6, #0
	adds r0, #0x4d
	movs r5, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _0807D2A8 @ =0x00004312
	adds r0, r6, #0
	bl SetMotion
	str r5, [r6, #0x5c]
	ldrb r0, [r6, #0x11]
	ands r4, r0
	lsls r4, r4, #0xa
	ldr r0, _0807D2AC @ =0xFFFFFE00
	adds r4, r4, r0
	str r4, [r6, #0x60]
_0807D23E:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807D244:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, _0807D2B0 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _0807D2A2
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
	ldr r1, _0807D2B4 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_0807D2A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D2A8: .4byte 0x00004312
_0807D2AC: .4byte 0xFFFFFE00
_0807D2B0: .4byte gStageRun+232
_0807D2B4: .4byte gEnemyFnTable

	thumb_func_start FUN_0807d2b8
FUN_0807d2b8: @ 0x0807D2B8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807D2C8
	cmp r0, #1
	beq _0807D37A
	b _0807D3D8
_0807D2C8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807D314 @ =0x08367BE4
	bl SetDDP
	ldr r1, _0807D318 @ =0x00004314
	adds r0, r5, #0
	bl SetMotion
	ldr r4, _0807D31C @ =0xFFFFFEA0
	ldrb r1, [r5, #0x11]
	movs r3, #1
	movs r2, #1
	ands r2, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	subs r0, r0, r2
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r5, #0x5c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x19
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r5, #0x60]
	cmp r2, #0
	beq _0807D320
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0807D326
	.align 2, 0
_0807D314: .4byte sCollisions+(3*24)
_0807D318: .4byte 0x00004314
_0807D31C: .4byte 0xFFFFFEA0
_0807D320:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807D326:
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0x11]
	lsrs r2, r0, #1
	ands r2, r4
	cmp r2, #0
	beq _0807D356
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _0807D35C
_0807D356:
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
_0807D35C:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r2, r5, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807D37A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _0807D3E0 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _0807D3D8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807D3E4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0807D3D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D3E0: .4byte gStageRun+232
_0807D3E4: .4byte gEnemyFnTable

	thumb_func_start MaybeKillCrossbyne
MaybeKillCrossbyne: @ 0x0807D3E8
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
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0807D468 @ =0x08367C50
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #0
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0807D46C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807D470 @ =0x0000270E
	cmp r1, r0
	bhi _0807D444
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807D444:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0807D474 @ =gEnemyFnTable
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
_0807D468: .4byte sMotions+(8*2)
_0807D46C: .4byte gScore
_0807D470: .4byte 0x0000270E
_0807D474: .4byte gEnemyFnTable

	thumb_func_start FUN_0807d478
FUN_0807d478: @ 0x0807D478
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0807D48C
	cmp r0, #1
	bne _0807D48A
	b _0807D5A0
_0807D48A:
	b _0807D5B8
_0807D48C:
	movs r2, #0
	ldr r0, _0807D4AC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0807D49E
	movs r2, #1
_0807D49E:
	adds r7, r2, #0
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	bne _0807D4B0
	eors r0, r7
	b _0807D4B4
	.align 2, 0
_0807D4AC: .4byte pZero2
_0807D4B0:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
_0807D4B4:
	adds r7, r0, #0
	adds r2, r7, #0
	cmp r7, #0
	beq _0807D4C4
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0807D4CA
_0807D4C4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807D4CA:
	strb r0, [r6, #0xa]
	movs r1, #1
	ands r1, r2
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
	lsls r1, r7, #8
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _0807D53C @ =0x08367C56
	ldrb r0, [r6, #0x10]
	adds r5, r6, #0
	adds r5, #0xb8
	lsls r0, r0, #1
	ldrb r2, [r5]
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
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
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	bne _0807D540
	adds r3, r7, #0
	eors r3, r0
	movs r0, #0xff
	ands r3, r0
	b _0807D544
	.align 2, 0
_0807D53C: .4byte sMotions+(11*2)
_0807D540:
	movs r3, #0xff
	ands r3, r7
_0807D544:
	movs r0, #0
	add r1, sp, #8
	movs r2, #0x80
	lsls r2, r2, #2
	bl FUN_080b2b40
	movs r1, #0x60
	str r1, [sp, #8]
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	bne _0807D568
	eors r0, r7
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	movs r0, #0x60
	subs r0, r0, r1
	b _0807D570
_0807D568:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #6
	subs r0, r1, r0
_0807D570:
	str r0, [sp, #8]
	movs r0, #0x60
	str r0, [sp, #0xc]
	adds r1, r6, #0
	adds r1, #0x54
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	ldrb r5, [r5]
	adds r0, r0, r5
	lsls r0, r0, #1
	ldr r2, _0807D5C0 @ =0x08367C5E
	adds r0, r0, r2
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r6, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
	strb r4, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807D5A0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807D5B8
	adds r0, r6, #0
	bl MaybeKillCrossbyne
_0807D5B8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807D5C0: .4byte sMotions+(15*2)

	thumb_func_start FUN_0807d5c4
FUN_0807d5c4: @ 0x0807D5C4
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
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r1, _0807D60C @ =gEnemyFnTable
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
_0807D60C: .4byte gEnemyFnTable
