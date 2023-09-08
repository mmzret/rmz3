	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX54
CreateVFX54: @ 0x080C0F2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _080C0F74 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C0F6C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C0F78 @ =gVFXFnTable
	movs r1, #0x36
	strb r1, [r3, #9]
	adds r0, #0xd8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x60]
_080C0F6C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C0F74: .4byte gVFXHeaderPtr
_080C0F78: .4byte gVFXFnTable

	thumb_func_start VFX54_Init
VFX54_Init: @ 0x080C0F7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C0FBC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080C0FC0 @ =0x0836F1E4
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
	bl VFX54_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0FBC: .4byte gVFXFnTable
_080C0FC0: .4byte 0x0836F1E4

	thumb_func_start VFX54_Update
VFX54_Update: @ 0x080C0FC4
	push {lr}
	ldr r2, _080C0FD8 @ =0x0836F1E0
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C0FD8: .4byte 0x0836F1E0

	thumb_func_start VFX54_Die
VFX54_Die: @ 0x080C0FDC
	ldr r2, _080C0FF0 @ =gVFXFnTable
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
_080C0FF0: .4byte gVFXFnTable

	thumb_func_start FUN_080c0ff4
FUN_080c0ff4: @ 0x080C0FF4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	beq _080C1004
	cmp r6, #1
	beq _080C1062
	b _080C10F8
_080C1004:
	ldr r0, _080C1078 @ =RNG_0202f388
	mov ip, r0
	ldr r0, [r0]
	ldr r3, _080C107C @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080C1080 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	ldr r4, _080C1084 @ =0xFFFFFF00
	adds r0, r0, r4
	str r0, [r7, #0x5c]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	ldr r1, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r5, _080C1088 @ =0x0836F1E6
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C1062:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C108C
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C1092
	.align 2, 0
_080C1078: .4byte RNG_0202f388
_080C107C: .4byte 0x000343FD
_080C1080: .4byte 0x00269EC3
_080C1084: .4byte 0xFFFFFF00
_080C1088: .4byte 0x0836F1E6
_080C108C:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C1092:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C10AC
	str r1, [r7, #0x60]
_080C10AC:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080C10DA
	ldr r0, _080C1100 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080C10F8
_080C10DA:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080C1104 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080C10F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1100: .4byte gStageRun+232
_080C1104: .4byte gVFXFnTable
