	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808a0ec
FUN_0808a0ec: @ 0x0808A0EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808A138 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0808A130
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808A13C @ =gEnemyFnTable
	movs r1, #0x31
	strb r1, [r4, #9]
	adds r0, #0xc4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x28]
_0808A130:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808A138: .4byte gZakoHeaderPtr
_0808A13C: .4byte gEnemyFnTable

	thumb_func_start nop_0808a140
nop_0808a140: @ 0x0808A140
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808a144
FUN_0808a144: @ 0x0808A144
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808A18C
	ldr r1, _0808A17C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0808A180
	movs r0, #1
	strb r0, [r2, #0xd]
	b _0808A182
	.align 2, 0
_0808A17C: .4byte gEnemyFnTable
_0808A180:
	strb r1, [r2, #0xd]
_0808A182:
	adds r0, r2, #0
	bl PantheonBase_Die
	movs r0, #1
	b _0808A18E
_0808A18C:
	movs r0, #0
_0808A18E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start pBase_0808a194
pBase_0808a194: @ 0x0808A194
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _0808A208
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808A1AE
	cmp r0, #1
	beq _0808A1F0
	b _0808A208
_0808A1AE:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808A208
	ldr r1, _0808A1E8 @ =0x0836896C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808A1EC @ =0x08368974
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
	movs r0, #1
	b _0808A20A
	.align 2, 0
_0808A1E8: .4byte 0x0836896C
_0808A1EC: .4byte 0x08368974
_0808A1F0:
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808A206
	movs r0, #1
	b _0808A20A
_0808A206:
	strb r0, [r4, #0xf]
_0808A208:
	movs r0, #0
_0808A20A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start pBase_0808a210
pBase_0808a210: @ 0x0808A210
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r5, [r6]
	cmp r5, #0
	bne _0808A23E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808A23E
	ldr r2, _0808A244 @ =0x08368BDC
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808A23E
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808A23E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808A244: .4byte 0x08368BDC

	thumb_func_start PantheonBase_Init
PantheonBase_Init: @ 0x0808A248
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808A2B0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _0808A2B4 @ =0x08368BE4
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, _0808A2B8 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x10]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0808A2C4
	ldr r0, _0808A2BC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808A2C4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A2C0 @ =0x08368984
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _0808A2DC
	.align 2, 0
_0808A2B0: .4byte gEnemyFnTable
_0808A2B4: .4byte 0x08368BE4
_0808A2B8: .4byte gSystemSavedataManager
_0808A2BC: .4byte gCurStory
_0808A2C0: .4byte 0x08368984
_0808A2C4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A2FC @ =0x08368984
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
_0808A2DC:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808A300 @ =nop_0808a140
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r0, r6, #0
	bl PantheonBase_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808A2FC: .4byte 0x08368984
_0808A300: .4byte nop_0808a140

	thumb_func_start PantheonBase_Update
PantheonBase_Update: @ 0x0808A304
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0808A320 @ =gCurStory
	ldrb r0, [r0, #8]
	movs r2, #0x42
	ands r2, r0
	cmp r2, #0
	beq _0808A324
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _0808A332
	.align 2, 0
_0808A320: .4byte gCurStory
_0808A324:
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #2
	bls _0808A368
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808A332:
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
	ldr r1, _0808A364 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0808A3CE
	.align 2, 0
_0808A364: .4byte gEnemyFnTable
_0808A368:
	adds r0, r4, #0
	bl FUN_0808a144
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0808A3CE
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0808A39C
	ldr r1, _0808A398 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	adds r0, r4, #0
	bl PantheonBase_Die
	b _0808A3CE
	.align 2, 0
_0808A398: .4byte gEnemyFnTable
_0808A39C:
	adds r0, r4, #0
	bl pBase_0808a210
	adds r0, r4, #0
	bl pBase_0808a194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808A3CE
	ldr r1, _0808A3D4 @ =0x0836896C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808A3D8 @ =0x08368974
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808A3CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A3D4: .4byte 0x0836896C
_0808A3D8: .4byte 0x08368974

	thumb_func_start PantheonBase_Die
PantheonBase_Die: @ 0x0808A3DC
	push {lr}
	ldr r2, _0808A3F0 @ =0x0836897C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0808A3F0: .4byte 0x0836897C

	thumb_func_start nop_0808a3f4
nop_0808a3f4: @ 0x0808A3F4
	bx lr
	.align 2, 0

	thumb_func_start pBase_0808a3f8
pBase_0808a3f8: @ 0x0808A3F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808A40E
	bl isKilled
	cmp r0, #0
	beq _0808A42E
_0808A40E:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808A434 @ =0x08368984
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808A42E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808A42E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A434: .4byte 0x08368984

	thumb_func_start pBase_0808a438
pBase_0808a438: @ 0x0808A438
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808A44A
	cmp r0, #1
	beq _0808A46A
	b _0808A472
_0808A44A:
	movs r1, #0xda
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808A478 @ =0x083689CC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808A46A:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_0808A472:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A478: .4byte 0x083689CC

	thumb_func_start pBase_0808a47c
pBase_0808a47c: @ 0x0808A47C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808A48E
	cmp r0, #1
	beq _0808A49E
	b _0808A50C
_0808A48E:
	movs r1, #0xda
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808A49E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808A4D4 @ =0x08368BE5
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808A4D8 @ =0x08368984
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0808A4DC
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808A4E2
	.align 2, 0
_0808A4D4: .4byte 0x08368BE5
_0808A4D8: .4byte 0x08368984
_0808A4DC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808A4E2:
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
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808A50C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start pBase_0808a514
pBase_0808a514: @ 0x0808A514
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808A5B4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r4, _0808A5B8 @ =0x08368BEE
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r2, r4, #6
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r4, #0xc
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808A5BC @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808A5C0 @ =0x0000270E
	cmp r1, r0
	bhi _0808A590
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808A590:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _0808A5C4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A5B4: .4byte 0xFFFFF000
_0808A5B8: .4byte 0x08368BEE
_0808A5BC: .4byte gMission
_0808A5C0: .4byte 0x0000270E
_0808A5C4: .4byte gEnemyFnTable

	thumb_func_start FUN_0808a5c8
FUN_0808a5c8: @ 0x0808A5C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808A5DC
	cmp r6, #1
	beq _0808A65A
	b _0808A6A4
_0808A5DC:
	movs r4, #0
	ldr r0, _0808A6AC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808A5EE
	movs r4, #1
_0808A5EE:
	lsls r0, r4, #8
	subs r0, r1, r0
	str r0, [r5, #0x54]
	ldr r1, _0808A6B0 @ =0x00006D01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_080b2b40
	ldr r0, [r7, #0x5c]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [sp, #8]
	movs r0, #0x60
	str r0, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808A6B4 @ =0x08368C00
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldr r0, [r7, #0x5c]
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808A65A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808A672
	str r1, [r5, #0x60]
_0808A672:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808A69E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0808A6B8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808A6A4
_0808A69E:
	adds r0, r5, #0
	bl pBase_0808a514
_0808A6A4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808A6AC: .4byte pZero2
_0808A6B0: .4byte 0x00006D01
_0808A6B4: .4byte 0x08368C00
_0808A6B8: .4byte 0xFFFFF000
