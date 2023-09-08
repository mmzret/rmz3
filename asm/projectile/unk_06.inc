	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile6_Update
Projectile6_Update: @ 0x0809DC74
	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x28]
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bhi _0809DCAC
	ldr r0, _0809DCC8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0809DCD0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
_0809DCAC:
	ldr r1, _0809DCCC @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	adds r0, r3, #0
	bl Projectile6_Die
	b _0809DD1A
	.align 2, 0
_0809DCC8: .4byte gCurStory
_0809DCCC: .4byte gProjectileFnTable
_0809DCD0:
	ldrb r0, [r2, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809DCE4
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809DCEA
_0809DCE4:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809DCEA:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r1, _0809DD20 @ =sUpdates
	ldrb r0, [r3, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
_0809DD1A:
	pop {r0}
	bx r0
	.align 2, 0
_0809DD20: .4byte sUpdates

	thumb_func_start Projectile6_Die
Projectile6_Die: @ 0x0809DD24
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0809DD5C @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_0809DD5C: .4byte gProjectileFnTable

	thumb_func_start FUN_0809dd60
FUN_0809dd60: @ 0x0809DD60
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0809DD8C
	ldr r1, _0809DD88 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile6_Die
	b _0809DDFA
	.align 2, 0
_0809DD88: .4byte gProjectileFnTable
_0809DD8C:
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809DDA0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809DDA6
_0809DDA0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809DDA6:
	strb r0, [r4, #0xa]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r6, #0
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
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ands r0, r5
	cmp r0, #0
	beq _0809DDDC
	str r6, [r1]
	strb r5, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _0809DDFA
_0809DDDC:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0809DDFA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809DE00 @ =0x0836ABF8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809DDFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809DE00: .4byte 0x0836ABF8

	thumb_func_start FUN_0809de04
FUN_0809de04: @ 0x0809DE04
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0809DE30
	ldr r1, _0809DE2C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile6_Die
	b _0809DF0C
	.align 2, 0
_0809DE2C: .4byte gProjectileFnTable
_0809DE30:
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809DE44
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809DE4A
_0809DE44:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809DE4A:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r5, #0
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
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r6, [r1]
	movs r0, #2
	ands r6, r0
	cmp r6, #0
	beq _0809DE7E
	str r5, [r1]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _0809DF0C
_0809DE7E:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0809DEB4
	cmp r5, #1
	bgt _0809DE8E
	cmp r5, #0
	beq _0809DE94
	b _0809DF0C
_0809DE8E:
	cmp r5, #2
	beq _0809DEF8
	b _0809DF0C
_0809DE94:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809DEEC @ =0x00001905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809DEF0 @ =0x0836AC10
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809DEB4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0809DED8
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809DEF4 @ =0x0836AC28
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809DED8:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809DF0C
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0809DF0C
	.align 2, 0
_0809DEEC: .4byte 0x00001905
_0809DEF0: .4byte 0x0836AC10
_0809DEF4: .4byte 0x0836AC28
_0809DEF8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809DF0C
	strb r5, [r4, #0xd]
	strb r6, [r4, #0xe]
_0809DF0C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809df14
FUN_0809df14:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0xA1, 0x6A, 0x08, 0x7B, 0x01, 0x28, 0x07, 0xD9
	.byte 0x20, 0x1C, 0xB4, 0x30, 0x00, 0x21, 0x01, 0x60, 0x03, 0x20, 0x60, 0x73, 0xA1, 0x73, 0x3C, 0xE0
	.byte 0x88, 0x7A, 0x02, 0x09, 0x01, 0x20, 0x02, 0x40, 0x00, 0x2A, 0x03, 0xD0, 0xA1, 0x7A, 0x10, 0x20
	.byte 0x08, 0x43, 0x02, 0xE0, 0xA1, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x11, 0x1C, 0x20, 0x1C
	.byte 0x4C, 0x30, 0x00, 0x25, 0x01, 0x70, 0x23, 0x1C, 0x4A, 0x33, 0x09, 0x01, 0x1A, 0x78, 0x11, 0x20
	.byte 0x40, 0x42, 0x10, 0x40, 0x08, 0x43, 0x18, 0x70, 0x22, 0x1C, 0xB4, 0x32, 0x10, 0x68, 0x02, 0x21
	.byte 0x08, 0x40, 0x00, 0x28, 0x04, 0xD0, 0x15, 0x60, 0x03, 0x20, 0x60, 0x73, 0xA5, 0x73, 0x14, 0xE0
	.byte 0xA0, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28, 0x0C, 0xD0, 0x0E, 0xE0, 0x08, 0x49, 0x20, 0x1C
	.byte 0x79, 0xF7, 0xEA, 0xFA, 0x20, 0x1C, 0x74, 0x30, 0x06, 0x49, 0x69, 0xF7, 0x3B, 0xF9, 0xA0, 0x7B
	.byte 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0x79, 0xF7, 0x59, 0xFB, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x07, 0x19, 0x00, 0x00, 0x40, 0xAC, 0x36, 0x08

	thumb_func_start FUN_0809dfb8
FUN_0809dfb8: @ 0x0809DFB8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0809DFE4
	ldr r1, _0809DFE0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile6_Die
	b _0809E054
	.align 2, 0
_0809DFE0: .4byte gProjectileFnTable
_0809DFE4:
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809DFF8
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809DFFE
_0809DFF8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809DFFE:
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
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809E026
	cmp r0, #1
	beq _0809E03E
	b _0809E054
_0809E026:
	ldr r1, _0809E05C @ =0x00001909
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809E060 @ =0x0836AC70
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809E03E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809E054
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0809E054:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809E05C: .4byte 0x00001909
_0809E060: .4byte 0x0836AC70
