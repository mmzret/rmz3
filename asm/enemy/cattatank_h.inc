	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099a98
FUN_08099a98: @ 0x08099A98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08099B08
	cmp r0, #1
	bgt _08099AAC
	cmp r0, #0
	beq _08099AB8
	b _08099CDA
_08099AAC:
	cmp r0, #2
	beq _08099BA6
	cmp r0, #3
	bne _08099AB6
	b _08099BB4
_08099AB6:
	b _08099CDA
_08099AB8:
	ldr r1, _08099AE0 @ =0x0000D50A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099AE4 @ =0x0836A640
	bl SetDDP
	ldr r0, _08099AE8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099AF0
	ldr r0, _08099AEC @ =0xFFFFFA00
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _08099AF8
	.align 2, 0
_08099AE0: .4byte 0x0000D50A
_08099AE4: .4byte sCollisions+(16*24)
_08099AE8: .4byte pZero2
_08099AEC: .4byte 0xFFFFFA00
_08099AF0:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0xc0
_08099AF8:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B08:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099B30
	str r1, [r4, #0x60]
_08099B30:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099B52
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B52:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099B64
	ldr r0, [r4, #0x54]
	ldr r1, _08099B60 @ =0xFFFFF600
	adds r0, r0, r1
	b _08099B6C
	.align 2, 0
_08099B60: .4byte 0xFFFFF600
_08099B64:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
_08099B6C:
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099B8A
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_08099B8A:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	bne _08099B9A
	b _08099CDA
_08099B9A:
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
	b _08099CDA
_08099BA6:
	ldr r1, _08099BF0 @ =0x0000D50B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099BB4:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099BDC
	str r1, [r4, #0x60]
_08099BDC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099BF8
	ldr r0, [r4, #0x54]
	ldr r2, _08099BF4 @ =0xFFFFF600
	b _08099BFE
	.align 2, 0
_08099BF0: .4byte 0x0000D50B
_08099BF4: .4byte 0xFFFFF600
_08099BF8:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_08099BFE:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099C1E
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099C1E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099C36
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08099C36:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099CDA
	ldr r1, [r5]
	cmp r1, #0
	beq _08099CAC
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	cmp r2, #1
	bne _08099C6C
	subs r0, #0x1c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C66
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099C66:
	movs r1, #0
	movs r0, #7
	b _08099CD6
_08099C6C:
	cmp r2, #2
	bne _08099C96
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C90
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08099C8C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08099CC6
	.align 2, 0
_08099C8C: .4byte gEnemyFnTable
_08099C90:
	movs r1, #0
	movs r0, #9
	b _08099CD6
_08099C96:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CA8
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099CA8:
	movs r1, #0
	b _08099CD4
_08099CAC:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CD4
	strb r1, [r4, #0xf]
_08099CBA:
	ldr r1, _08099CD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08099CC6:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _08099CDA
	.align 2, 0
_08099CD0: .4byte gEnemyFnTable
_08099CD4:
	movs r0, #1
_08099CD6:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099CDA:
	pop {r4, r5}
	pop {r0}
	bx r0

