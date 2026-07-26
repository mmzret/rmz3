	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ceb2c
FUN_080ceb2c: @ 0x080CEB2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CEB3E
	cmp r0, #1
	beq _080CEB72
	b _080CEC60
_080CEB3E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080CEB50
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x78
	b _080CEB6A
_080CEB50:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080CEBF4 @ =0x0837054E
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
_080CEB6A:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CEB72:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _080CEBF8 @ =0x08370544
	ldrb r1, [r4, #0x12]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080CEBFC @ =0x08370340
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080CEB98
	adds r0, r4, #0
	bl UpdateEntityAnim
_080CEB98:
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080CEC0C
	ldr r0, _080CEC00 @ =gStageRun
	ldrb r1, [r0, #0x12]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080CEBB2
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
_080CEBB2:
	ldrb r0, [r4, #0x12]
	cmp r0, #9
	bne _080CEC48
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080CEBD0
	adds r0, r4, #0
	adds r0, #0xbd
	strb r3, [r0]
	strb r3, [r4, #0xd]
	strb r2, [r4, #0xe]
_080CEBD0:
	ldr r0, _080CEC04 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, _080CEC08 @ =0x00002FFF
	cmp r0, r1
	bhi _080CEC48
	adds r0, r4, #0
	adds r0, #0xbd
	strb r2, [r0]
	strb r3, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080CEC48
	.align 2, 0
_080CEBF4: .4byte 0x0837054E
_080CEBF8: .4byte 0x08370544
_080CEBFC: .4byte 0x08370340
_080CEC00: .4byte gStageRun
_080CEC04: .4byte pZero2
_080CEC08: .4byte 0x00002FFF
_080CEC0C:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	movs r3, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	cmp r0, #9
	bne _080CEC48
	ldr r0, _080CEC68 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, _080CEC6C @ =0x00002FFF
	cmp r0, r1
	bhi _080CEC48
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _080CEC70 @ =0x00007FFF
	cmp r0, r1
	bhi _080CEC48
	adds r0, r4, #0
	adds r0, #0xbd
	strb r3, [r0]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
_080CEC48:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _080CEC60
	ldrb r1, [r4, #0x13]
	cmp r1, #0
	bne _080CEC60
	ldrb r0, [r4, #0x12]
	cmp r0, #9
	beq _080CEC60
	adds r0, #1
	strb r0, [r4, #0x12]
	strb r1, [r4, #0xe]
_080CEC60:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CEC68: .4byte pZero2
_080CEC6C: .4byte 0x00002FFF
_080CEC70: .4byte 0x00007FFF

	thumb_func_start FUN_080cec74
FUN_080cec74: @ 0x080CEC74
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080CEC80
	b _080CEDB2
_080CEC80:
	lsls r0, r0, #2
	ldr r1, _080CEC8C @ =_080CEC90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CEC8C: .4byte _080CEC90
_080CEC90: @ jump table
	.4byte _080CECA8 @ case 0
	.4byte _080CECE8 @ case 1
	.4byte _080CED00 @ case 2
	.4byte _080CED14 @ case 3
	.4byte _080CED44 @ case 4
	.4byte _080CED4E @ case 5
_080CECA8:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CECDE
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CECDE
	ldr r0, [r4, #0x28]
	adds r0, #0xc4
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r0, r1, r0
	str r0, [r4, #0x64]
	cmp r0, #0
	bge _080CECCC
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
_080CECCC:
	ldr r0, [r4, #0x64]
	lsls r0, r0, #3
	str r0, [r4, #0x64]
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __divsi3
	adds r0, #1
	b _080CECE0
_080CECDE:
	movs r0, #1
_080CECE0:
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CECE8:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _080CECF8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CECF8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080CEDB2
_080CED00:
	movs r0, #0x18
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CED14:
	ldr r0, [r4, #0x64]
	ldr r2, [r4, #0x68]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CED2A
	rsbs r0, r2, #0
	str r0, [r4, #0x68]
_080CED2A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CEDB2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080CEDB2
_080CED44:
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CED4E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CED5E
	str r1, [r4, #0x60]
_080CED5E:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CED92
	ldr r0, _080CEDB8 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080CEDB2
_080CED92:
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080CEDBC @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl GlacierleArm_Die
_080CEDB2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CEDB8: .4byte gStageRun+232
_080CEDBC: .4byte gSolidFnTable
