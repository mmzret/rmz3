	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateMegamilpaNode
CreateMegamilpaNode: @ 0x08065720
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08065770 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _08065768
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08065774 @ =gEnemyFnTable
	movs r0, #2
	strb r0, [r4, #9]
	ldr r0, [r1, #8]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r5, [r0]
_08065768:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08065770: .4byte gZakoHeaderPtr
_08065774: .4byte gEnemyFnTable

	thumb_func_start MegamilpaNode_Init
MegamilpaNode_Init: @ 0x08065778
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _08065814 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08065818 @ =0x08365CF0
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
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
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806581C @ =0x08365CD8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080657F6
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080657F6:
	ldrb r0, [r6, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	strb r0, [r6, #0x1d]
	adds r0, r6, #0
	bl MegamilpaNode_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065814: .4byte gEnemyFnTable
_08065818: .4byte 0x08365CF0
_0806581C: .4byte 0x08365CD8

	thumb_func_start MegamilpaNode_Update
MegamilpaNode_Update: @ 0x08065820
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0806584C
	ldr r1, _08065848 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl MegamilpaNode_Die
	b _0806586C
	.align 2, 0
_08065848: .4byte gEnemyFnTable
_0806584C:
	ldr r1, _08065874 @ =0x08365CA8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08065878 @ =0x08365CB4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0806586C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065874: .4byte 0x08365CA8
_08065878: .4byte 0x08365CB4

	thumb_func_start MegamilpaNode_Die
MegamilpaNode_Die: @ 0x0806587C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r2, [r5, #0xd]
	cmp r2, #0
	beq _0806588C
	cmp r2, #1
	beq _080658CC
	b _0806591C
_0806588C:
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r0, [r5, #0xa]
	movs r1, #0xfb
	ands r1, r0
	strb r1, [r5, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080658C4
	ldr r1, _080658C0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	b _0806591C
	.align 2, 0
_080658C0: .4byte gEnemyFnTable
_080658C4:
	str r2, [r5, #0x60]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080658CC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x20
	str r1, [r5, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _080658E2
	str r0, [r5, #0x60]
_080658E2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806591C
	ldr r1, _08065924 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateGhost19_2
_0806591C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065924: .4byte gEnemyFnTable

	thumb_func_start nop_08065928
nop_08065928: @ 0x08065928
	bx lr
	.align 2, 0

	thumb_func_start MegamilpaNode_0806592c
MegamilpaNode_0806592c: @ 0x0806592C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08065940
	cmp r0, #1
	beq _08065958
	b _0806597C
_08065940:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08065984 @ =0x08365CD8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065958:
	adds r1, r5, #0
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0806596C
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_0806596C:
	ldr r0, [r1]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806597C
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0806597C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065984: .4byte 0x08365CD8

	thumb_func_start MegamilpaNode_08065988
MegamilpaNode_08065988: @ 0x08065988
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080659DE
	cmp r0, #1
	bgt _080659AA
	cmp r0, #0
	beq _080659B6
	b _08065CA8
_080659AA:
	cmp r0, #2
	beq _08065A00
	cmp r0, #3
	bne _080659B4
	b _08065B0A
_080659B4:
	b _08065CA8
_080659B6:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080659F4 @ =0x08365CD8
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xba
	strh r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080659DE:
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _080659F8
	subs r0, r2, #1
	strh r0, [r1]
	b _08065CA8
	.align 2, 0
_080659F4: .4byte 0x08365CD8
_080659F8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08065CA8
_08065A00:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08065A34 @ =0x08365CC0
	bl SetDDP
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r7, #0
	adds r3, r1, #0
	orrs r3, r0
	strb r3, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065A7A
	adds r0, r6, #0
	adds r0, #0xbe
	ldrb r2, [r0]
	cmp r2, #0
	beq _08065A38
	movs r0, #0x10
	orrs r3, r0
	b _08065A3C
	.align 2, 0
_08065A34: .4byte 0x08365CC0
_08065A38:
	movs r0, #0xef
	ands r3, r0
_08065A3C:
	strb r3, [r5, #0xa]
	movs r1, #1
	ands r1, r2
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
	adds r0, r6, #0
	adds r0, #0xbf
	ldrb r2, [r0]
	cmp r2, #0
	beq _08065A6C
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _08065A72
_08065A6C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
_08065A72:
	strb r0, [r5, #0xa]
	movs r0, #1
	ands r0, r2
	b _08065AD6
_08065A7A:
	adds r0, r6, #0
	adds r0, #0xbe
	adds r2, r6, #0
	adds r2, #0xbf
	ldrb r1, [r0]
	ldrb r0, [r2]
	adds r4, r0, #0
	eors r4, r1
	mov r8, r2
	cmp r4, #0
	beq _08065A96
	movs r0, #0x10
	orrs r3, r0
	b _08065A9A
_08065A96:
	movs r0, #0xef
	ands r3, r0
_08065A9A:
	strb r3, [r5, #0xa]
	movs r1, #1
	ands r1, r4
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	mov r7, r8
	ldrb r4, [r7]
	adds r3, r2, #0
	cmp r4, #0
	beq _08065ACA
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _08065AD0
_08065ACA:
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
_08065AD0:
	strb r0, [r5, #0xa]
	movs r0, #1
	ands r0, r4
_08065AD6:
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	movs r2, #0xc0
	str r2, [r5, #0x5c]
	adds r3, r6, #0
	adds r3, #0xbe
	ldrb r1, [r3]
	lsls r1, r1, #1
	movs r0, #1
	subs r0, r0, r1
	muls r0, r2, r0
	str r0, [r5, #0x5c]
	ldrb r0, [r3]
	lsls r0, r0, #0xf
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08065B0A:
	ldr r3, _08065B84 @ =gSineTable
	ldr r4, [r5, #0x60]
	asrs r2, r4, #8
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r5, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	rsbs r1, r1, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r5, #0x58]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	movs r1, #0xb8
	adds r1, r1, r5
	mov sb, r1
	adds r7, r6, #0
	adds r7, #0xbe
	mov ip, r3
	cmp r0, #0
	bne _08065C1E
	ldr r1, _08065B88 @ =0x00000BA3
	mov r2, sb
	ldrb r0, [r2]
	muls r1, r0, r1
	ldr r3, _08065B8C @ =0x00000666
	adds r1, r1, r3
	ldrb r0, [r7]
	cmp r0, #0
	beq _08065B78
	movs r0, #0x80
	lsls r0, r0, #8
	subs r1, r0, r1
_08065B78:
	ldrb r0, [r7]
	cmp r4, r1
	ble _08065B90
	cmp r0, #1
	bne _08065B98
	b _08065B94
	.align 2, 0
_08065B84: .4byte gSineTable
_08065B88: .4byte 0x00000BA3
_08065B8C: .4byte 0x00000666
_08065B90:
	cmp r0, #0
	bne _08065B98
_08065B94:
	cmp r4, r1
	bne _08065C1E
_08065B98:
	movs r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x60]
	asrs r4, r0, #8
	movs r1, #0x80
	subs r4, r1, r4
	lsls r0, r4, #2
	adds r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _08065BB0
	adds r0, #0x7f
_08065BB0:
	asrs r4, r0, #7
	lsls r4, r4, #5
	subs r3, r1, r4
	movs r0, #0xbf
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08065BC4
	adds r3, #0x80
_08065BC4:
	ldr r1, [r5, #0x54]
	str r1, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r5, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, [r5, #0x58]
	str r2, [sp, #4]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	rsbs r1, r1, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	mov r1, r8
	ldrb r0, [r1]
	ldr r1, _08065C40 @ =0xFFFFFE00
	cmp r0, #0
	beq _08065C10
	movs r1, #0x80
	lsls r1, r1, #2
_08065C10:
	adds r2, r4, #0
	subs r2, #0x80
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	bl CreateLemon
_08065C1E:
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	adds r2, r0, r1
	str r2, [r5, #0x60]
	movs r1, #0xfe
	lsls r1, r1, #7
	ldrb r0, [r7]
	cmp r0, #0
	beq _08065C34
	movs r1, #0x80
	lsls r1, r1, #1
_08065C34:
	ldrb r0, [r7]
	cmp r2, r1
	ble _08065C44
	cmp r0, #1
	bne _08065C4E
	b _08065C48
	.align 2, 0
_08065C40: .4byte 0xFFFFFE00
_08065C44:
	cmp r0, #0
	bne _08065C4E
_08065C48:
	ldr r0, [r5, #0x60]
	cmp r0, r1
	bne _08065C56
_08065C4E:
	str r1, [r5, #0x60]
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_08065C56:
	ldr r0, [r5, #0x60]
	asrs r4, r0, #8
	ldrb r2, [r7]
	movs r0, #0
	mov r7, sb
	ldrb r3, [r7]
	cmp r3, #0
	bne _08065C72
	adds r0, r6, #0
	adds r0, #0xbf
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
_08065C72:
	cmp r2, r0
	beq _08065C7A
	movs r0, #0x80
	subs r4, r0, r4
_08065C7A:
	lsls r0, r4, #2
	adds r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _08065C86
	adds r0, #0x7f
_08065C86:
	asrs r4, r0, #7
	cmp r4, #4
	ble _08065C8E
	movs r4, #4
_08065C8E:
	cmp r3, #0
	bne _08065C94
	adds r4, #5
_08065C94:
	ldr r0, _08065CB8 @ =0x08365CF2
	lsls r1, r4, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl FUN_0801779c
_08065CA8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065CB8: .4byte 0x08365CF2

	thumb_func_start MegamilpaNode_08065cbc
MegamilpaNode_08065cbc: @ 0x08065CBC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r7, [r0]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _08065CCE
	b _08065F7C
_08065CCE:
	lsls r0, r0, #2
	ldr r1, _08065CD8 @ =_08065CDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08065CD8: .4byte _08065CDC
_08065CDC: @ jump table
	.4byte _08065CF4 @ case 0
	.4byte _08065D76 @ case 1
	.4byte _08065D98 @ case 2
	.4byte _08065E5C @ case 3
	.4byte _08065F38 @ case 4
	.4byte _08065F66 @ case 5
_08065CF4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08065D30 @ =0x08365CD8
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08065D38
	ldr r4, _08065D34 @ =0x0000A00B
	ldrb r0, [r6]
	lsls r0, r0, #2
	movs r1, #0xa
	bl __modsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #4
	bl GotoMotion
	b _08065D54
	.align 2, 0
_08065D30: .4byte 0x08365CD8
_08065D34: .4byte 0x0000A00B
_08065D38:
	ldr r4, _08065D8C @ =0x0000A005
	ldrb r0, [r6]
	lsls r0, r0, #2
	movs r1, #0xa
	bl __modsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #4
	bl GotoMotion
_08065D54:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r5, #0
	adds r1, #0xba
	strh r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08065D76:
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r0, [r1]
	movs r3, #0
	ldrsh r2, [r1, r3]
	cmp r2, #0
	beq _08065D90
	subs r0, #1
	strh r0, [r1]
	b _08065F7C
	.align 2, 0
_08065D8C: .4byte 0x0000A005
_08065D90:
	strb r2, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _08065F7A
_08065D98:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08065DC4 @ =0x08365CC0
	bl SetDDP
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r3, #0
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r0, r7, #0
	adds r0, #0xbe
	ldrb r2, [r0]
	adds r6, r0, #0
	cmp r2, #0
	beq _08065DC8
	movs r0, #0x10
	orrs r1, r0
	b _08065DCC
	.align 2, 0
_08065DC4: .4byte 0x08365CC0
_08065DC8:
	movs r0, #0xef
	ands r1, r0
_08065DCC:
	strb r1, [r5, #0xa]
	movs r4, #1
	movs r1, #1
	ands r1, r2
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
	ldrb r0, [r5, #0x13]
	eors r4, r0
	cmp r4, #0
	beq _08065DFC
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _08065E02
_08065DFC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
_08065E02:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r4
	adds r0, r5, #0
	adds r0, #0x4d
	strb r1, [r0]
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r0, #0xc0
	lsls r0, r0, #6
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldrb r0, [r6]
	ldrb r1, [r5, #0x13]
	eors r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r2, [r0]
	ldrb r1, [r5, #0x13]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r1, #0
	lsls r0, r0, #9
	ldr r1, _08065F18 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08065E5C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r4, r0, #0
	cmp r3, #0
	bne _08065E80
	adds r2, r5, #0
	adds r2, #0xb8
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _08065E94
_08065E80:
	cmp r3, #5
	bne _08065EF8
	adds r2, r5, #0
	adds r2, #0xb8
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _08065EF8
_08065E94:
	adds r0, r5, #0
	adds r0, #0x72
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #3
	bne _08065EF8
	adds r1, r5, #0
	adds r1, #0xb9
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r1]
	ldrb r1, [r6]
	adds r0, r0, r1
	ands r0, r2
	cmp r0, #0
	bne _08065EF8
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #5
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	adds r0, r7, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	eors r4, r0
	ldr r1, [r5, #0x54]
	ldr r2, _08065F1C @ =0xFFFFF400
	adds r1, r1, r2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #0xb
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #2
	lsls r4, r4, #0x1f
	lsrs r4, r4, #0x18
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_08065EF8:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r1, r0, r1
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08065F20
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r1, r0
	ble _08065F7C
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _08065F7A
	.align 2, 0
_08065F18: .4byte 0xFFFFFF00
_08065F1C: .4byte 0xFFFFF400
_08065F20:
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r3, _08065F34 @ =0xFFFF6000
	adds r0, r0, r3
	cmp r1, r0
	bge _08065F7C
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _08065F7A
	.align 2, 0
_08065F34: .4byte 0xFFFF6000
_08065F38:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08065F50 @ =0x08365CD8
	bl SetDDP
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08065F54
	movs r0, #0
	strb r0, [r5, #0xd]
	b _08065F7A
	.align 2, 0
_08065F50: .4byte 0x08365CD8
_08065F54:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08065F66:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08065F72
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08065F7C
_08065F72:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	movs r0, #2
_08065F7A:
	strb r0, [r5, #0xe]
_08065F7C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
