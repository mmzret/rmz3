	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ac700
FUN_080ac700: @ 0x080AC700
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080AC736
	movs r1, #0
	str r1, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _080AC7E2
_080AC736:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080AC742
	cmp r0, #1
	beq _080AC79C
	b _080AC7F4
_080AC742:
	ldr r2, _080AC7FC @ =0x0836C6F4
	ldrb r0, [r7, #0x11]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _080AC800 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080AC804 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080AC808 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldr r2, [r2]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, _080AC80C @ =0x00000C01
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080AC79C:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x32
	bne _080AC7AC
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080AC810 @ =0x0836C644
	bl SetDDP
_080AC7AC:
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AC7BC
	str r1, [r7, #0x60]
_080AC7BC:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080AC7E2
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AC7F4
_080AC7E2:
	ldr r1, _080AC814 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080AC7F4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC7FC: .4byte 0x0836C6F4
_080AC800: .4byte RNG_0202f388
_080AC804: .4byte 0x000343FD
_080AC808: .4byte 0x00269EC3
_080AC80C: .4byte 0x00000C01
_080AC810: .4byte 0x0836C644
_080AC814: .4byte gProjectileFnTable

