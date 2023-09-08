	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bdd74
FUN_080bdd74: @ 0x080BDD74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080BDDC4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BDDBC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BDDC8 @ =gVFXFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080BDDBC:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BDDC4: .4byte gVFXHeaderPtr
_080BDDC8: .4byte gVFXFnTable

	thumb_func_start FUN_080bddcc
FUN_080bddcc: @ 0x080BDDCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080BDE30 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BDE22
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080BDE34 @ =gVFXFnTable
	movs r1, #0x29
	strb r1, [r4, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x78]
_080BDE22:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BDE30: .4byte gVFXHeaderPtr
_080BDE34: .4byte gVFXFnTable

	thumb_func_start createHellbatElectricBeam
createHellbatElectricBeam: @ 0x080BDE38
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080BDE94 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BDE8C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BDE98 @ =gVFXFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x7c
	strb r6, [r0]
	movs r0, #2
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080BDE8C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BDE94: .4byte gVFXHeaderPtr
_080BDE98: .4byte gVFXFnTable

	thumb_func_start FUN_080bde9c
FUN_080bde9c: @ 0x080BDE9C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080BDEF8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BDEF0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BDEFC @ =gVFXFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x7c
	strb r6, [r0]
	movs r0, #3
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080BDEF0:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BDEF8: .4byte gVFXHeaderPtr
_080BDEFC: .4byte gVFXFnTable

	thumb_func_start VFX41_Init
VFX41_Init: @ 0x080BDF00
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080BDF42
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _080BDF68
_080BDF42:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x80
	rsbs r0, r0, #0
_080BDF68:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r2, [r4, #0x11]
	cmp r2, #0
	bne _080BDF94
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BDF90 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080BDFD4
	.align 2, 0
_080BDF90: .4byte gVFXFnTable
_080BDF94:
	cmp r2, #1
	bne _080BDFB4
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BDFB0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r3, [r4, #0xd]
	b _080BDFD4
	.align 2, 0
_080BDFB0: .4byte gVFXFnTable
_080BDFB4:
	cmp r2, #2
	beq _080BDFBC
	cmp r2, #3
	bne _080BDFD8
_080BDFBC:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BDFE4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_080BDFD4:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
_080BDFD8:
	adds r0, r4, #0
	bl VFX41_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BDFE4: .4byte gVFXFnTable

	thumb_func_start VFX41_Update
VFX41_Update: @ 0x080BDFE8
	push {lr}
	ldr r2, _080BDFFC @ =0x0836EEF8
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BDFFC: .4byte 0x0836EEF8

	thumb_func_start VFX41_Die
VFX41_Die: @ 0x080BE000
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BE01C @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080BE01C: .4byte gVFXFnTable

	thumb_func_start FUN_080be020
FUN_080be020: @ 0x080BE020
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080BE056
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BE078
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BE078
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BE078
_080BE056:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080BE074 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BE146
	.align 2, 0
_080BE074: .4byte gVFXFnTable
_080BE078:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080BE086
	cmp r0, #1
	beq _080BE0F0
	b _080BE146
_080BE086:
	ldr r4, _080BE108 @ =0x0836EF68
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080BE10C @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080BE110 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080BE114 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BE0F0:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE118
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BE11E
	.align 2, 0
_080BE108: .4byte 0x0836EF68
_080BE10C: .4byte RNG_0202f388
_080BE110: .4byte 0x000343FD
_080BE114: .4byte 0x00269EC3
_080BE118:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BE11E:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BE130
	str r1, [r7, #0x60]
_080BE130:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BE146:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080be154
FUN_080be154: @ 0x080BE154
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080BE1AE
	cmp r5, #1
	bgt _080BE168
	cmp r5, #0
	beq _080BE16E
	b _080BE224
_080BE168:
	cmp r5, #2
	beq _080BE1F6
	b _080BE224
_080BE16E:
	ldr r1, _080BE18C @ =0x0000A80D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080BE190
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080BE196
	.align 2, 0
_080BE18C: .4byte 0x0000A80D
_080BE190:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080BE1E8 @ =0xFFFFF400
_080BE196:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE1AE:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE1EC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	b _080BE224
	.align 2, 0
_080BE1E8: .4byte 0xFFFFF400
_080BE1EC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080BE224
_080BE1F6:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080BE224
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080BE22C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BE224:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE22C: .4byte gVFXFnTable

	thumb_func_start FUN_080be230
FUN_080be230: @ 0x080BE230
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BE2C0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080BE310
	ldrb r0, [r1, #0xd]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080BE310
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BE25C
	cmp r0, #1
	beq _080BE28C
	b _080BE2C0
_080BE25C:
	ldr r1, _080BE2D8 @ =0x0000A901
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE28C:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080BE2DC @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _080BE2C0
	ldr r1, _080BE2E0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BE2C0:
	adds r0, r4, #0
	adds r0, #0x7c
	ldrb r1, [r0]
	cmp r1, #1
	bne _080BE322
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BE2E4
	cmp r0, #1
	beq _080BE2FE
	b _080BE322
	.align 2, 0
_080BE2D8: .4byte 0x0000A901
_080BE2DC: .4byte 0xFFFFFF00
_080BE2E0: .4byte gVFXFnTable
_080BE2E4:
	strb r1, [r4, #0x12]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080BE328 @ =0x0000A904
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE2FE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BE322
_080BE310:
	ldr r1, _080BE32C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BE322:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE328: .4byte 0x0000A904
_080BE32C: .4byte gVFXFnTable

	thumb_func_start FUN_080be330
FUN_080be330: @ 0x080BE330
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BE340
	cmp r0, #1
	beq _080BE3E0
	b _080BE454
_080BE340:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080BE350
	ldr r1, _080BE34C @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE34C: .4byte 0x0000A907
_080BE350:
	cmp r0, #1
	bne _080BE35C
	ldr r1, _080BE358 @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE358: .4byte 0x0000A907
_080BE35C:
	cmp r0, #2
	bne _080BE368
	ldr r1, _080BE364 @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE364: .4byte 0x0000A907
_080BE368:
	cmp r0, #3
	bne _080BE374
	ldr r1, _080BE370 @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE370: .4byte 0x0000A907
_080BE374:
	cmp r0, #4
	bne _080BE388
	ldr r1, _080BE384 @ =0x0000A90B
_080BE37A:
	adds r0, r4, #0
	bl SetMotion
	b _080BE394
	.align 2, 0
_080BE384: .4byte 0x0000A90B
_080BE388:
	cmp r0, #5
	bne _080BE394
	ldr r1, _080BE3AC @ =0x0000A90B
	adds r0, r4, #0
	bl SetMotion
_080BE394:
	adds r0, r4, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	movs r2, #1
	ands r2, r0
	cmp r2, #0
	beq _080BE3B0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080BE3B6
	.align 2, 0
_080BE3AC: .4byte 0x0000A90B
_080BE3B0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080BE3B6:
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
	movs r0, #3
	strb r0, [r4, #0x13]
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE3E0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BE3F0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BE44E
_080BE3F0:
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080BE404
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BE41C
_080BE404:
	ldr r1, _080BE418 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BE44E
	.align 2, 0
_080BE418: .4byte gVFXFnTable
_080BE41C:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bhi _080BE43C
	ldr r0, _080BE438 @ =0x0836EF74
	ldrb r1, [r4, #0x13]
	subs r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
	b _080BE44E
	.align 2, 0
_080BE438: .4byte 0x0836EF74
_080BE43C:
	ldr r0, _080BE45C @ =0x0836EF7A
	ldrb r1, [r4, #0x13]
	subs r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
_080BE44E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BE454:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE45C: .4byte 0x0836EF7A
