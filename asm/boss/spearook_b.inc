	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start Spearook_Die
Spearook_Die: @ 0x0806224C
	push {lr}
	ldr r2, _08062260 @ =0x08365770
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08062260: .4byte 0x08365770

	thumb_func_start FUN_08062264
FUN_08062264:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08062268
FUN_08062268: @ 0x08062268
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0806227E
	bl isKilled
	cmp r0, #0
	beq _08062286
_0806227E:
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08062286:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806228c
FUN_0806228c: @ 0x0806228C
	push {lr}
	adds r3, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080622FE
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080622C0
	adds r2, r3, #0
	adds r2, #0xba
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	lsls r0, r0, #0xf
	b _080622D8
_080622C0:
	adds r2, r3, #0
	adds r2, #0xba
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	lsls r0, r0, #0xc
_080622D8:
	subs r1, r1, r0
	strh r1, [r2]
	adds r3, r2, #0
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080622F0 @ =0xFFFFC000
	cmp r1, r0
	bge _080622F4
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r3]
	b _080622FE
	.align 2, 0
_080622F0: .4byte 0xFFFFC000
_080622F4:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _080622FE
	strh r0, [r2]
_080622FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08062304
FUN_08062304:
	.byte 0x00, 0xB5, 0x03, 0x1C, 0x8C, 0x30, 0x01, 0x68, 0x01, 0x20, 0x08, 0x40
	.byte 0x00, 0x28, 0x0F, 0xD0, 0x80, 0x20, 0x80, 0x02, 0x01, 0x40, 0x00, 0x29, 0x0A, 0xD0, 0x1A, 0x1C
	.byte 0xBC, 0x32, 0x10, 0x68, 0x05, 0x21, 0x49, 0x42, 0x08, 0x40, 0x10, 0x60, 0x00, 0x21, 0x0E, 0x20
	.byte 0x58, 0x73, 0x99, 0x73, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_08062338
FUN_08062338: @ 0x08062338
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08062348
	cmp r0, #1
	beq _0806236C
	b _080623B6
_08062348:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08062390 @ =0x0836579C
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	movs r1, #0xd6
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806236C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080623AC
	adds r0, r4, #0
	adds r0, #0xc4
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _08062394
	adds r0, r4, #0
	bl FUN_08061bf8
	b _0806239A
	.align 2, 0
_08062390: .4byte 0x0836579C
_08062394:
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_0806239A:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080623AC
	movs r0, #0
	strb r0, [r5]
_080623AC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080623B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080623bc
FUN_080623bc: @ 0x080623BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _080624A6
	lsls r0, r0, #2
	ldr r1, _080623D0 @ =_080623D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080623D0: .4byte _080623D4
_080623D4: @ jump table
	.4byte _080623EC @ case 0
	.4byte _08062404 @ case 1
	.4byte _08062420 @ case 2
	.4byte _08062446 @ case 3
	.4byte _08062490 @ case 4
	.4byte _08062496 @ case 5
_080623EC:
	ldr r0, _08062418 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _0806241C @ =0xFFFF7000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062404:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080624A6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080624A6
	.align 2, 0
_08062418: .4byte gStageRun+232
_0806241C: .4byte 0xFFFF7000
_08062420:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _08062488 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _0806248C @ =0xFFFF7000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r2, [r4, #0x60]
	movs r1, #0xd6
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062446:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08062456
	str r1, [r4, #0x60]
_08062456:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _08062480
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062480:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080624A6
	.align 2, 0
_08062488: .4byte gStageRun+232
_0806248C: .4byte 0xFFFF7000
_08062490:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062496:
	ldr r0, _080624AC @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080624A6
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
_080624A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080624AC: .4byte gStageRun

	thumb_func_start FUN_080624b0
FUN_080624b0: @ 0x080624B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080624C2
	cmp r0, #1
	beq _080624D2
	b _08062580
_080624C2:
	strb r0, [r4, #0x12]
	ldr r1, _0806253C @ =0x0000D601
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080624D2:
	ldrb r0, [r5, #0xd]
	cmp r0, #1
	beq _080624E2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08062540 @ =0x083657CC
	bl SetDDP
_080624E2:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #0xf
	bl __umodsi3
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08062504
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r2, _08062544 @ =0xFFFFCF00
	adds r0, r4, #0
	bl FUN_08061b68
_08062504:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r6, [r5, #0x54]
	str r6, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _08062548 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08062562
	ldrb r0, [r4, #0xa]
	lsrs r1, r0, #4
	movs r3, #1
	ands r1, r3
	ldr r0, _0806254C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r6, r0
	bge _08062550
	cmp r1, r3
	bne _08062554
	b _08062562
	.align 2, 0
_0806253C: .4byte 0x0000D601
_08062540: .4byte 0x083657CC
_08062544: .4byte 0xFFFFCF00
_08062548: .4byte 0xFFFFEE00
_0806254C: .4byte pZero2
_08062550:
	cmp r1, #0
	beq _08062562
_08062554:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #5
	b _0806257C
_08062562:
	ldr r2, [r2]
	movs r1, #4
	ands r1, r2
	cmp r1, #0
	beq _08062572
	movs r1, #0
	movs r0, #8
	b _0806257C
_08062572:
	movs r0, #0x20
	ands r2, r0
	cmp r2, #0
	beq _08062580
	movs r0, #0xa
_0806257C:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08062580:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08062588
FUN_08062588: @ 0x08062588
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldr r7, [r5, #0x2c]
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _0806259C
	cmp r4, #1
	beq _080625B0
	b _0806266E
_0806259C:
	ldr r1, _080625F0 @ =0x0000D60D
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	movs r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080625B0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080625F8
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _080625D2
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080625D2
	ldr r1, _080625F0 @ =0x0000D60D
	adds r0, r5, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r5, #0x13]
_080625D2:
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r1, [r0]
	movs r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08062614
	ldr r1, _080625F4 @ =0x0000D60E
	adds r0, r5, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r5, #0x12]
	b _08062614
	.align 2, 0
_080625F0: .4byte 0x0000D60D
_080625F4: .4byte 0x0000D60E
_080625F8:
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r4, [r1]
	movs r0, #2
	ands r4, r0
	adds r6, r1, #0
	cmp r4, #0
	bne _08062614
	ldr r1, _08062674 @ =0x0000D60F
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	strb r4, [r5, #0x13]
_08062614:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08062634
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	movs r1, #0
	movs r0, #6
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08062634:
	ldr r1, [r7, #0x54]
	str r1, [r5, #0x54]
	ldr r4, _08062678 @ =gSineTable
	adds r2, r7, #0
	adds r2, #0xb8
	ldrh r0, [r2]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #0xb
	muls r0, r3, r0
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r1, [r7, #0x58]
	str r1, [r5, #0x58]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	subs r1, r1, r0
	str r1, [r5, #0x58]
_0806266E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062674: .4byte 0x0000D60F
_08062678: .4byte gSineTable

	thumb_func_start FUN_0806267c
FUN_0806267c: @ 0x0806267C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080626AA
	cmp r0, #1
	bgt _08062690
	cmp r0, #0
	beq _08062696
	b _0806274C
_08062690:
	cmp r0, #2
	beq _080626B4
	b _0806274C
_08062696:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	bne _0806274C
	movs r0, #1
	strb r0, [r4, #0xe]
	b _0806274C
_080626AA:
	movs r0, #0x78
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080626B4:
	ldr r0, _080626D4 @ =pZero2
	ldr r0, [r0]
	ldr r3, [r0, #0x54]
	ldr r2, [r4, #0x54]
	subs r0, r3, r2
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, _080626D8 @ =0x0000BFFF
	cmp r0, r1
	bhi _080626DC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806274C
	.align 2, 0
_080626D4: .4byte pZero2
_080626D8: .4byte 0x0000BFFF
_080626DC:
	movs r5, #0
	cmp r2, r3
	ble _08062704
	ldr r1, _08062700 @ =0xFFFFEA00
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08062724
	ldr r0, [r4, #0x54]
	subs r0, #0x80
	str r0, [r4, #0x54]
	b _08062726
	.align 2, 0
_08062700: .4byte 0xFFFFEA00
_08062704:
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08062724
	ldr r0, [r4, #0x54]
	adds r0, #0x80
	str r0, [r4, #0x54]
	b _08062726
_08062724:
	movs r5, #1
_08062726:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08062738
	cmp r5, #0
	beq _0806273C
_08062738:
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806273C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_0806274C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08062754
FUN_08062754: @ 0x08062754
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _08062778 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08062794
	cmp r0, #1
	bgt _0806277C
	cmp r0, #0
	beq _08062786
	b _0806283C
	.align 2, 0
_08062778: .4byte 0xFFFFEE00
_0806277C:
	cmp r0, #2
	beq _080627B0
	cmp r0, #3
	beq _08062824
	b _0806283C
_08062786:
	ldr r1, _080627AC @ =0x0000D605
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062794:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806283C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806283C
	.align 2, 0
_080627AC: .4byte 0x0000D605
_080627B0:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r2, #0x4a
	adds r2, r2, r4
	mov ip, r2
	lsls r3, r1, #4
	ldrb r2, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _080627EA
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080627F0
_080627EA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080627F0:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062808
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r1, [r0]
	movs r2, #8
	orrs r1, r2
	b _08062814
_08062808:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r1, [r0]
	movs r2, #9
	rsbs r2, r2, #0
	ands r1, r2
_08062814:
	str r1, [r0]
	ldr r1, _08062844 @ =0x0000D606
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062824:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806283C
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806283C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08062844: .4byte 0x0000D606

	thumb_func_start FUN_08062848
FUN_08062848: @ 0x08062848
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r2, [r6, #0x2c]
	ldr r1, [r2, #0x54]
	str r1, [r6, #0x54]
	ldr r5, _08062898 @ =gSineTable
	adds r3, r2, #0
	adds r3, #0xb8
	ldrh r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r4, #0xb
	muls r0, r4, r0
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r1, [r2, #0x58]
	str r1, [r6, #0x58]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	subs r1, r1, r0
	str r1, [r6, #0x58]
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _080628B4
	cmp r0, #1
	bgt _0806289C
	cmp r0, #0
	beq _080628A6
	b _08062932
	.align 2, 0
_08062898: .4byte gSineTable
_0806289C:
	cmp r0, #2
	beq _080628D0
	cmp r0, #3
	beq _0806291C
	b _08062932
_080628A6:
	ldr r1, _080628CC @ =0x0000D60E
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080628B4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08062932
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _08062930
	.align 2, 0
_080628CC: .4byte 0x0000D60E
_080628D0:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08062906
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0806290C
_08062906:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806290C:
	strb r0, [r6, #0xa]
	ldr r1, _08062938 @ =0x0000D60F
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0806291C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08062932
	movs r0, #0
	strb r1, [r6, #0xd]
_08062930:
	strb r0, [r6, #0xe]
_08062932:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062938: .4byte 0x0000D60F

	thumb_func_start FUN_0806293c
FUN_0806293c: @ 0x0806293C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08062948
	b _08062A84
_08062948:
	lsls r0, r0, #2
	ldr r1, _08062954 @ =_08062958
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062954: .4byte _08062958
_08062958: @ jump table
	.4byte _08062970 @ case 0
	.4byte _08062986 @ case 1
	.4byte _0806299A @ case 2
	.4byte _080629BC @ case 3
	.4byte _08062A34 @ case 4
	.4byte _08062A52 @ case 5
_08062970:
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062986:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #0x12
	ands r0, r1
	cmp r0, #0
	bne _08062A84
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08062A82
_0806299A:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080629AC
	movs r0, #0x20
	b _080629B0
_080629AC:
	movs r0, #0x20
	rsbs r0, r0, #0
_080629B0:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080629BC:
	movs r5, #0
	ldr r2, [r4, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _080629F4 @ =0x000005FF
	cmp r1, r0
	bhi _080629D2
	ldr r0, [r4, #0x64]
	adds r0, r2, r0
	str r0, [r4, #0x5c]
_080629D2:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080629FC
	ldr r0, [r4, #0x54]
	ldr r1, _080629F8 @ =0xFFFFEA00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08062A26
	b _08062A16
	.align 2, 0
_080629F4: .4byte 0x000005FF
_080629F8: .4byte 0xFFFFEA00
_080629FC:
	ldr r0, [r4, #0x54]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08062A20
_08062A16:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	b _08062A22
_08062A20:
	movs r5, #1
_08062A22:
	cmp r5, #0
	beq _08062A2C
_08062A26:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062A2C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08062A84
_08062A34:
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	str r1, [r4, #0x5c]
	movs r0, #0xc
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	cmp r1, #0
	bge _08062A46
	movs r0, #0xc
_08062A46:
	str r0, [r4, #0x64]
	lsrs r0, r1, #0x1f
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062A52:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r1, #0
	bge _08062A6C
	cmp r0, #1
	bne _08062A70
	b _08062A84
_08062A6C:
	cmp r0, #0
	beq _08062A84
_08062A70:
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r4, #0xd]
_08062A82:
	strb r0, [r4, #0xe]
_08062A84:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08062a94
FUN_08062a94: @ 0x08062A94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _08062AB8 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08062AD8
	cmp r0, #1
	bgt _08062ABC
	cmp r0, #0
	beq _08062AC6
	b _08062B60
	.align 2, 0
_08062AB8: .4byte 0xFFFFEE00
_08062ABC:
	cmp r0, #2
	beq _08062B10
	cmp r0, #3
	beq _08062B2C
	b _08062B60
_08062AC6:
	ldr r1, _08062B08 @ =0x0000D602
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062AD8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08062AF2
	movs r1, #0xf0
	lsls r1, r1, #4
	ldr r2, _08062B0C @ =0xFFFFCF00
	adds r0, r4, #0
	bl FUN_08061b68
_08062AF2:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08062AFE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062AFE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08062B60
	.align 2, 0
_08062B08: .4byte 0x0000D602
_08062B0C: .4byte 0xFFFFCF00
_08062B10:
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08062B68 @ =0x0000D601
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062B2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08062B46
	movs r1, #0xf0
	lsls r1, r1, #4
	ldr r2, _08062B6C @ =0xFFFFCF00
	adds r0, r4, #0
	bl FUN_08061b68
_08062B46:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _08062B5A
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08062B5A:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08062B60:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08062B68: .4byte 0x0000D601
_08062B6C: .4byte 0xFFFFCF00
