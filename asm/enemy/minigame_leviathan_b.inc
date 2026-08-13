	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809ab28
FUN_0809ab28: @ 0x0809AB28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0809ABA6
	cmp r5, #1
	bgt _0809AB3C
	cmp r5, #0
	beq _0809AB46
	b _0809AC1E
_0809AB3C:
	cmp r5, #2
	beq _0809ABBC
	cmp r5, #3
	beq _0809ABC6
	b _0809AC1E
_0809AB46:
	ldr r1, [r4, #0x68]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0809AB6C
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809AB68 @ =FUN_0809aa10
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809AB9C
	.align 2, 0
_0809AB68: .4byte FUN_0809aa10
_0809AB6C:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809ABB8 @ =FUN_0809aa90
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	strb r5, [r4, #0x13]
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _0809AB9C
_0809AB88:
	adds r0, r1, #0
	movs r1, #0xa
	bl __divsi3
	adds r1, r0, #0
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	cmp r1, #0
	bne _0809AB88
_0809AB9C:
	movs r0, #0x1e
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABA6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _0809AC1E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809AC1E
	.align 2, 0
_0809ABB8: .4byte FUN_0809aa90
_0809ABBC:
	movs r0, #0x18
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABC6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809ABDC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0809ABE2
_0809ABDC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809ABE2:
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x64]
	cmp r2, #0
	bne _0809AC1E
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _0809AC24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809AC1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AC24: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ac28
FUN_0809ac28: @ 0x0809AC28
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AC7A
	ldr r0, [r4, #0x20]
	adds r0, #0x3c
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #1
	bl FUN_08099f54
	ldr r1, [r4, #0x1c]
	adds r1, #1
	cmp r1, #4
	ble _0809AC70
	movs r1, #4
_0809AC70:
	ldrb r0, [r6]
	muls r1, r0, r1
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AC7A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809ACD4 @ =0x0836A77E
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809ACD8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809ACD4: .4byte sMotions+(6*2)
_0809ACD8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809acdc
FUN_0809acdc: @ 0x0809ACDC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AD2A
	ldr r0, [r4, #0x20]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #5
	bl FUN_08099f54
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AD2A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809AD84 @ =0x0836A784
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809AD88 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AD84: .4byte sMotions+(9*2)
_0809AD88: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ad8c
FUN_0809ad8c: @ 0x0809AD8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AD9E
	cmp r5, #1
	beq _0809ADF0
	b _0809AE5C
_0809AD9E:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809ADCC
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AE04 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809ADCC:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ADF0:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AE08
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AE0E
	.align 2, 0
_0809AE04: .4byte 0xFFFFFED4
_0809AE08:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AE0E:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AE5C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AE38
	ldr r1, _0809AE64 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AE38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0809AE4C
	adds r0, #0xff
_0809AE4C:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x10
	str r1, [r4, #0x60]
_0809AE5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AE64: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ae68
FUN_0809ae68: @ 0x0809AE68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AE7A
	cmp r5, #1
	beq _0809AECA
	b _0809AF14
_0809AE7A:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AEA8
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AEE0 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809AEA8:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809AECA:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AEE4
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AEEA
	.align 2, 0
_0809AEE0: .4byte 0xFFFFFED4
_0809AEE4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AEEA:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AF14
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AF14
	ldr r1, _0809AF1C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AF14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AF1C: .4byte gEnemyFnTable
