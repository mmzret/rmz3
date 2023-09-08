	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r2, [r0, #0x10]
	movs r6, #0
	movs r7, #0
	ldr r0, _08022288 @ =0x080FECE4
	ldr r4, [r0]
	ldr r5, [r0, #4]
	cmp r2, #0
	beq _08022278
	ldr r1, _0802228C @ =gStageRun+232
	movs r0, #0x18
	ldrsb r0, [r1, r0]
	cmp r0, #3
	ble _0802221A
	ldr r6, [r1, #0x5c]
	ldr r7, [r1, #0x64]
	ldr r4, [r1, #0x60]
	ldr r5, [r1, #0x68]
_0802221A:
	ldr r1, _08022290 @ =gOverworld
	ldr r3, _08022294 @ =0x0002C014
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r6, r0
	bge _08022228
	adds r6, r0, #0
_08022228:
	ldr r3, _08022298 @ =0x0002C018
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r7, r0
	bge _08022234
	adds r7, r0, #0
_08022234:
	ldr r3, _0802229C @ =0x0002C01C
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r4, r0
	ble _08022240
	adds r4, r0, #0
_08022240:
	ldr r3, _080222A0 @ =0x0002C020
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r5, r0
	ble _0802224C
	adds r5, r0, #0
_0802224C:
	str r5, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r4, #0
	bl SetDisableArea
	mov r0, sb
	ldr r2, [r0, #0x20]
	cmp r2, #0
	beq _08022278
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08022278
	str r5, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r4, #0
	bl SetDisableArea
_08022278:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022288: .4byte s32_ARRAY_080fece4
_0802228C: .4byte gStageRun+232
_08022290: .4byte gOverworld
_08022294: .4byte 0x0002C014
_08022298: .4byte 0x0002C018
_0802229C: .4byte 0x0002C01C
_080222A0: .4byte 0x0002C020
