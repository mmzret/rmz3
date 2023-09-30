	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateGallisni
CreateGallisni: @ 0x08086F90
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08086FE8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08086FE0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08086FEC @ =gEnemyFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
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
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
_08086FE0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08086FE8: .4byte gZakoHeaderPtr
_08086FEC: .4byte gEnemyFnTable

	thumb_func_start FUN_08086ff0
FUN_08086ff0: @ 0x08086FF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x2c]
	ldr r1, [r2, #0x2c]
	mov r8, r1
	ldrh r1, [r0, #8]
	ldr r0, _080870A0 @ =0x00002E03
	cmp r1, r0
	beq _08087094
	mov r1, r8
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _08087094
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08087094
	mov r4, r8
	adds r4, #0xb8
	ldrb r0, [r4]
	mov sb, r0
	cmp r0, #0
	bne _08087094
	ldr r7, _080870A4 @ =gStageRun+232
	mov r1, r8
	adds r1, #0x54
	adds r0, r7, #0
	bl CalcFromCamera
	ldr r1, _080870A8 @ =0x000007FF
	cmp r0, r1
	bhi _08087094
	movs r0, #0xff
	strb r0, [r4]
	ldr r0, [r7, #0x38]
	ldr r6, _080870AC @ =0x00008BFF
	adds r0, r0, r6
	ldr r1, [r7, #0x3c]
	ldr r4, _080870B0 @ =0xFFFF9C00
	adds r1, r1, r4
	movs r2, #0
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	ldr r5, _080870B4 @ =0xFFFF7400
	adds r0, r0, r5
	ldr r1, [r7, #0x3c]
	adds r1, r1, r4
	movs r2, #1
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	adds r0, r0, r6
	ldr r1, [r7, #0x3c]
	ldr r4, _080870B8 @ =0x000063FF
	adds r1, r1, r4
	movs r2, #2
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	adds r0, r0, r5
	ldr r1, [r7, #0x3c]
	adds r1, r1, r4
	movs r2, #3
	bl CreateGallisni
	movs r0, #0xa3
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #0xd]
	mov r0, sb
	strb r0, [r1, #0xe]
	movs r0, #0x40
	strb r0, [r1, #0x12]
_08087094:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080870A0: .4byte 0x00002E03
_080870A4: .4byte gStageRun+232
_080870A8: .4byte 0x000007FF
_080870AC: .4byte 0x00008BFF
_080870B0: .4byte 0xFFFF9C00
_080870B4: .4byte 0xFFFF7400
_080870B8: .4byte 0x000063FF

	thumb_func_start gallisni_080870bc
gallisni_080870bc: @ 0x080870BC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808710E
	ldr r1, _080870FC @ =gEnemyFnTable
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
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08087100
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08087102
	strb r4, [r2, #0xd]
	b _08087104
	.align 2, 0
_080870FC: .4byte gEnemyFnTable
_08087100:
	movs r0, #1
_08087102:
	strb r0, [r2, #0xd]
_08087104:
	adds r0, r2, #0
	bl Gallisni_Die
	movs r0, #1
	b _08087110
_0808710E:
	movs r0, #0
_08087110:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start gallisni_08087118
gallisni_08087118: @ 0x08087118
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080871AA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080871AA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08087138
	cmp r0, #1
	beq _08087188
	b _080871AA
_08087138:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080871AA
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0808714E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808714E:
	ldr r1, _08087180 @ =0x0836868C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08087184 @ =0x083686AC
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
_0808717A:
	movs r0, #1
	b _080871AC
	.align 2, 0
_08087180: .4byte 0x0836868C
_08087184: .4byte 0x083686AC
_08087188:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080871A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080871A4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808717A
	strb r5, [r4, #0xf]
	b _080871AA
	.align 2, 0
_080871A4: .4byte 0x00020001
_080871A8:
	strb r0, [r4, #0xf]
_080871AA:
	movs r0, #0
_080871AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start gallisni_080871b4
gallisni_080871b4: @ 0x080871B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080871F4
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080871F4
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080871E0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080871F4
_080871E0:
	ldr r2, _080871FC @ =0x08368750
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080871F4
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080871F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080871FC: .4byte 0x08368750

	thumb_func_start Gallisni_Init
Gallisni_Init: @ 0x08087200
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808727C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08087280 @ =0x08368758
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087284 @ =0x083686D8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08087288 @ =FUN_08086ff0
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldrb r4, [r6, #0x10]
	cmp r4, #0
	bne _08087270
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r4, [r0]
_08087270:
	adds r0, r6, #0
	bl Gallisni_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808727C: .4byte gEnemyFnTable
_08087280: .4byte 0x08368758
_08087284: .4byte 0x083686D8
_08087288: .4byte FUN_08086ff0

	thumb_func_start Gallisni_Update
Gallisni_Update: @ 0x0808728C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08087318
	ldr r0, _080872C4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080872C8
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
	b _080872F4
	.align 2, 0
_080872C4: .4byte gCurStory
_080872C8:
	ldr r0, _08087310 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bls _08087318
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_080872F4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08087314 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08087356
	.align 2, 0
_08087310: .4byte gStageRun+232
_08087314: .4byte gEnemyFnTable
_08087318:
	adds r0, r4, #0
	bl gallisni_080870bc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08087356
	adds r0, r4, #0
	bl gallisni_080871b4
	adds r0, r4, #0
	bl gallisni_08087118
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08087356
	ldr r1, _0808735C @ =0x0836868C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08087360 @ =0x083686AC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08087356:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808735C: .4byte 0x0836868C
_08087360: .4byte 0x083686AC

	thumb_func_start Gallisni_Die
Gallisni_Die: @ 0x08087364
	push {lr}
	ldr r2, _08087378 @ =0x083686CC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08087378: .4byte 0x083686CC

	thumb_func_start nop_0808737c
nop_0808737c: @ 0x0808737C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08087380
FUN_08087380: @ 0x08087380
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808739C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08087398
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08087398:
	pop {r0}
	bx r0
	.align 2, 0
_0808739C: .4byte 0x00020001

	thumb_func_start FUN_080873a0
FUN_080873a0: @ 0x080873A0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _080873B6
	bl isKilled
	cmp r0, #0
	beq _080873D6
_080873B6:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080873F4 @ =0x08368708
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _080873D6
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080873D6:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080873F8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080873EC
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080873EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080873F4: .4byte 0x08368708
_080873F8: .4byte 0x00020001

	thumb_func_start FUN_080873fc
FUN_080873fc: @ 0x080873FC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08087424
	ldr r1, _0808742C @ =0x00006703
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08087430 @ =0x08368720
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08087424:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808742C: .4byte 0x00006703
_08087430: .4byte 0x08368720

	thumb_func_start FUN_08087434
FUN_08087434: @ 0x08087434
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08087444
	cmp r0, #1
	beq _08087468
	b _0808749A
_08087444:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080874A0 @ =0x083686D8
	bl SetDDP
	movs r0, #0x80
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldr r1, _080874A4 @ =0x00006701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08087468:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808747C
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808747C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _0808749A
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080874A8 @ =0x083686F0
	bl SetDDP
_0808749A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080874A0: .4byte 0x083686D8
_080874A4: .4byte 0x00006701
_080874A8: .4byte 0x083686F0

	thumb_func_start FUN_080874ac
FUN_080874ac: @ 0x080874AC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080874BC
	cmp r0, #1
	beq _080874D8
	b _08087508
_080874BC:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08087510 @ =0x083686D8
	bl SetDDP
	ldr r1, _08087514 @ =0x00006702
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080874D8:
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	cmp r0, #0
	beq _080874E6
	subs r0, #1
	strb r0, [r1]
_080874E6:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080874F6
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08087502
_080874F6:
	ldrb r1, [r1]
	cmp r1, #0
	bne _08087502
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08087502:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08087508:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087510: .4byte 0x083686D8
_08087514: .4byte 0x00006702

	thumb_func_start FUN_08087518
FUN_08087518: @ 0x08087518
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08087528
	cmp r0, #1
	beq _08087598
	b _080875BA
_08087528:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808754C @ =0x08368708
	bl SetDDP
	ldrb r0, [r4, #0x12]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	beq _08087550
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08087556
	.align 2, 0
_0808754C: .4byte 0x08368708
_08087550:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08087556:
	strb r0, [r4, #0xa]
	movs r1, #1
	adds r2, r1, #0
	ands r2, r3
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r2, #4
	ldrb r3, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	mov r2, ip
	strb r0, [r2]
	ldrb r0, [r4, #0x12]
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, _080875C0 @ =0xFFFFFC00
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r1, _080875C4 @ =0x00006703
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08087598:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080875BA
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080875BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080875C0: .4byte 0xFFFFFC00
_080875C4: .4byte 0x00006703

	thumb_func_start FUN_080875c8
FUN_080875c8: @ 0x080875C8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080875D8
	cmp r5, #1
	beq _08087608
	b _08087720
_080875D8:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldr r2, [r4, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r2, r2, r0
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #1
	movs r3, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	subs r2, r2, r0
	str r2, [r4, #0x68]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	eors r0, r3
	ands r0, r3
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08087608:
	ldr r5, [r4, #0x64]
	str r5, [r4, #0x54]
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	bne _08087638
	ldr r2, _08087634 @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
	b _08087650
	.align 2, 0
_08087634: .4byte gSineTable
_08087638:
	ldr r2, _0808767C @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
_08087650:
	str r0, [r4, #0x54]
	ldr r5, [r4, #0x68]
	str r5, [r4, #0x58]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08087680
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
	b _08087696
	.align 2, 0
_0808767C: .4byte gSineTable
_08087680:
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
_08087696:
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, _080876BC @ =0x00007FFF
	cmp r0, r1
	ble _080876B0
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080876B0:
	ldr r1, [r4, #0x5c]
	ldr r0, _080876C0 @ =0x000029FF
	cmp r1, r0
	bgt _080876C8
	ldr r1, _080876C4 @ =0x00006704
	b _080876D0
	.align 2, 0
_080876BC: .4byte 0x00007FFF
_080876C0: .4byte 0x000029FF
_080876C4: .4byte 0x00006704
_080876C8:
	ldr r0, _080876D8 @ =0x000053FF
	cmp r1, r0
	bgt _080876E0
	ldr r1, _080876DC @ =0x00006705
_080876D0:
	adds r0, r4, #0
	bl SetMotion
	b _0808771A
	.align 2, 0
_080876D8: .4byte 0x000053FF
_080876DC: .4byte 0x00006705
_080876E0:
	ldrb r2, [r4, #0x13]
	cmp r2, #0
	beq _080876EE
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080876F4
_080876EE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080876F4:
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
	ldr r1, _08087728 @ =0x00006704
	adds r0, r4, #0
	bl SetMotion
_0808771A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08087720:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08087728: .4byte 0x00006704

	thumb_func_start FUN_0808772c
FUN_0808772c: @ 0x0808772C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808773C
	cmp r0, #1
	beq _0808775E
	b _08087780
_0808773C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldrb r2, [r4, #0x12]
	movs r0, #1
	ands r0, r2
	lsls r0, r0, #0xb
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #4
	strb r0, [r4, #0x13]
	ldr r1, _08087788 @ =0x00006703
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808775E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08087780
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08087780:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087788: .4byte 0x00006703

	thumb_func_start FUN_0808778c
FUN_0808778c: @ 0x0808778C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808779C
	cmp r5, #1
	beq _080877CC
	b _080878E4
_0808779C:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldr r2, [r4, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r2, r2, r0
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #1
	movs r3, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	subs r2, r2, r0
	str r2, [r4, #0x68]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	eors r0, r3
	ands r0, r3
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080877CC:
	ldr r5, [r4, #0x64]
	str r5, [r4, #0x54]
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	bne _080877FC
	ldr r2, _080877F8 @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	b _08087814
	.align 2, 0
_080877F8: .4byte gSineTable
_080877FC:
	ldr r2, _08087840 @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
_08087814:
	str r0, [r4, #0x54]
	ldr r5, [r4, #0x68]
	str r5, [r4, #0x58]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08087844
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
	b _0808785A
	.align 2, 0
_08087840: .4byte gSineTable
_08087844:
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
_0808785A:
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, _08087880 @ =0x00007FFF
	cmp r0, r1
	ble _08087874
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08087874:
	ldr r1, [r4, #0x5c]
	ldr r0, _08087884 @ =0x000029FF
	cmp r1, r0
	bgt _0808788C
	ldr r1, _08087888 @ =0x00006704
	b _08087894
	.align 2, 0
_08087880: .4byte 0x00007FFF
_08087884: .4byte 0x000029FF
_08087888: .4byte 0x00006704
_0808788C:
	ldr r0, _0808789C @ =0x000053FF
	cmp r1, r0
	bgt _080878A4
	ldr r1, _080878A0 @ =0x00006705
_08087894:
	adds r0, r4, #0
	bl SetMotion
	b _080878DE
	.align 2, 0
_0808789C: .4byte 0x000053FF
_080878A0: .4byte 0x00006705
_080878A4:
	ldrb r2, [r4, #0x13]
	cmp r2, #0
	beq _080878B2
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080878B8
_080878B2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080878B8:
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
	ldr r1, _080878EC @ =0x00006704
	adds r0, r4, #0
	bl SetMotion
_080878DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080878E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080878EC: .4byte 0x00006704

	thumb_func_start FUN_080878f0
FUN_080878f0: @ 0x080878F0
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
	ldr r1, _08087974 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08087978 @ =0x0836875A
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0808797C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08087980 @ =0x0000270E
	cmp r1, r0
	bhi _08087950
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08087950:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08087984 @ =gEnemyFnTable
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
_08087974: .4byte 0xFFFFF000
_08087978: .4byte 0x0836875A
_0808797C: .4byte gMission
_08087980: .4byte 0x0000270E
_08087984: .4byte gEnemyFnTable

	thumb_func_start FUN_08087988
FUN_08087988: @ 0x08087988
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0808799A
	cmp r0, #1
	beq _08087A58
	b _08087A9E
_0808799A:
	movs r3, #0
	ldr r0, _080879BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080879AC
	movs r3, #1
_080879AC:
	adds r4, r3, #0
	adds r2, r4, #0
	cmp r4, #0
	beq _080879C0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080879C6
	.align 2, 0
_080879BC: .4byte pZero2
_080879C0:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080879C6:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	movs r5, #0
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
	lsls r1, r4, #8
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _08087AA8 @ =0x00006707
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
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
	adds r3, r4, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r6, #0
	adds r1, #0x54
	ldr r0, _08087AAC @ =0x08368760
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r6, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b857c
	ldr r0, [sp, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
	strb r4, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08087A58:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08087A70
	str r1, [r6, #0x60]
_08087A70:
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
	beq _08087A98
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08087A9E
_08087A98:
	adds r0, r6, #0
	bl FUN_080878f0
_08087A9E:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087AA8: .4byte 0x00006707
_08087AAC: .4byte 0x08368760

	thumb_func_start FUN_08087ab0
FUN_08087ab0: @ 0x08087AB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08087AC0
	cmp r0, #1
	beq _08087B56
	b _08087B96
_08087AC0:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08087B38 @ =0x08368738
	bl SetDDP
	ldr r1, _08087B3C @ =0x00006703
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _08087B40 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08087B44 @ =0xFFFFE800
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
	beq _08087B48
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
	b _08087B50
	.align 2, 0
_08087B38: .4byte 0x08368738
_08087B3C: .4byte 0x00006703
_08087B40: .4byte pZero2
_08087B44: .4byte 0xFFFFE800
_08087B48:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08087B50:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08087B56:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08087B6E
	str r1, [r5, #0x60]
_08087B6E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08087B90
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08087B96
_08087B90:
	adds r0, r5, #0
	bl FUN_080878f0
_08087B96:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
