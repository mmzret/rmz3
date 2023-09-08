	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX57
CreateVFX57: @ 0x080C18EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, [sp, #0x18]
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080C195C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1950
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1960 @ =gVFXFnTable
	movs r1, #0x39
	strb r1, [r3, #9]
	adds r0, #0xe4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r7, [r3, #0x10]
	strb r5, [r3, #0x11]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	str r0, [r3, #0x5c]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [r3, #0x60]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080C1950:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C195C: .4byte gVFXHeaderPtr
_080C1960: .4byte gVFXFnTable

	thumb_func_start VFX57_Init
VFX57_Init: @ 0x080C1964
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _080C1976
	adds r0, r1, #0
	bl FUN_080c19b4
	b _080C197C
_080C1976:
	adds r0, r1, #0
	bl FUN_080c1a3c
_080C197C:
	pop {r0}
	bx r0

	thumb_func_start VFX57_Update
VFX57_Update: @ 0x080C1980
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _080C1992
	adds r0, r1, #0
	bl FUN_080c1aec
	b _080C1998
_080C1992:
	adds r0, r1, #0
	bl FUN_080c1b34
_080C1998:
	pop {r0}
	bx r0

	thumb_func_start VFX57_Die
VFX57_Die: @ 0x080C199C
	ldr r2, _080C19B0 @ =gVFXFnTable
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
_080C19B0: .4byte gVFXFnTable

	thumb_func_start FUN_080c19b4
FUN_080c19b4: @ 0x080C19B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080C1A08 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0x11]
	movs r2, #0xc6
	lsls r2, r2, #7
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080C19F8
	movs r1, #1
_080C19F8:
	adds r2, r1, #0
	cmp r2, #0
	beq _080C1A0C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C1A12
	.align 2, 0
_080C1A08: .4byte gVFXFnTable
_080C1A0C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C1A12:
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
	adds r0, r4, #0
	bl VFX57_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1a3c
FUN_080c1a3c: @ 0x080C1A3C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080C1A94 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080C1A98 @ =0x00006203
	adds r1, r0, #0
	ldrb r0, [r4, #0x11]
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	beq _080C1A9C
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080C1A84
	movs r1, #1
_080C1A84:
	adds r2, r1, #0
	cmp r2, #0
	beq _080C1AB4
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C1ABA
	.align 2, 0
_080C1A94: .4byte gVFXFnTable
_080C1A98: .4byte 0x00006203
_080C1A9C:
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bgt _080C1AA6
	movs r1, #1
_080C1AA6:
	adds r2, r1, #0
	cmp r2, #0
	beq _080C1AB4
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C1ABA
_080C1AB4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C1ABA:
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
	movs r0, #0
	strb r0, [r4, #0x12]
	movs r0, #0x3f
	bl PlaySound
	adds r0, r4, #0
	bl VFX57_Update
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1aec
FUN_080c1aec: @ 0x080C1AEC
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080C1B28
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C1B30 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C1B28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C1B30: .4byte gVFXFnTable

	thumb_func_start FUN_080c1b34
FUN_080c1b34: @ 0x080C1B34
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C1B66
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080C1B6C
_080C1B66:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080C1B6C:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C1B8E
	ldr r1, _080C1B94 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C1B8E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C1B94: .4byte gVFXFnTable
