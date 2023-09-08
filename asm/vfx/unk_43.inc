	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX43
CreateVFX43: @ 0x080BE658
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r4, #0
	movs r5, #0
	ldr r0, _080BE6AC @ =0x0836D9AC
	mov r8, r0
_080BE66A:
	ldr r0, _080BE6B0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080BE69C
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #1
	strb r0, [r2]
	movs r0, #0x2b
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	strb r5, [r1, #0x10]
	strb r4, [r1, #0x11]
	str r7, [r1, #0x54]
	str r6, [r1, #0x58]
_080BE69C:
	adds r4, #1
	cmp r4, #3
	ble _080BE66A
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE6AC: .4byte 0x0836D9AC
_080BE6B0: .4byte gVFXHeaderPtr

	thumb_func_start VFX43_Init
VFX43_Init: @ 0x080BE6B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BE6F4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080BE6F8 @ =0x0836EFC0
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl VFX43_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE6F4: .4byte gVFXFnTable
_080BE6F8: .4byte 0x0836EFC0

	thumb_func_start VFX43_Update
VFX43_Update: @ 0x080BE6FC
	push {lr}
	ldr r2, _080BE710 @ =0x0836EFBC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BE710: .4byte 0x0836EFBC

	thumb_func_start VFX43_Die
VFX43_Die: @ 0x080BE714
	ldr r2, _080BE728 @ =gVFXFnTable
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
_080BE728: .4byte gVFXFnTable

	thumb_func_start FUN_080be72c
FUN_080be72c: @ 0x080BE72C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0x11]
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080BE73E
	cmp r0, #1
	beq _080BE796
	b _080BE80E
_080BE73E:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BE7AC @ =0x0836EFC2
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	subs r1, r4, #1
	lsls r1, r1, #8
	ldr r6, _080BE7B0 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080BE7B4 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080BE7B8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080BE7BC @ =0x000001FF
	ands r0, r4
	adds r1, r1, r0
	ldr r0, _080BE7C0 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, _080BE7C4 @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BE796:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE7C8
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BE7CE
	.align 2, 0
_080BE7AC: .4byte 0x0836EFC2
_080BE7B0: .4byte RNG_0202f388
_080BE7B4: .4byte 0x000343FD
_080BE7B8: .4byte 0x00269EC3
_080BE7BC: .4byte 0x000001FF
_080BE7C0: .4byte 0xFFFFFF00
_080BE7C4: .4byte 0xFFFFFE00
_080BE7C8:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BE7CE:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r1, #0x40
	str r1, [r7, #0x60]
	adds r0, r7, #0
	bl FUN_0801779c
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080BE80E
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BE814 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080BE80E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE814: .4byte gVFXFnTable
