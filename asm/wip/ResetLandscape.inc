	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r3, r0, #0
	ldr r5, _08008B64 @ =0x020023C8
	ldr r0, [r1]
	str r0, [r5]
	ldr r0, [r1, #4]
	str r0, [r5, #4]
	ldr r1, _08008B68 @ =gStageLandscape
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r3, [r7]
	ldr r2, _08008B6C @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _08008B70 @ =0x0000C1FF
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	ldr r0, _08008B74 @ =0xFFFFFE38
	adds r4, r5, r0
	ldr r1, _08008B78 @ =TaskCB_UpdateOwGraphic
	adds r0, r4, #0
	str r3, [sp, #4]
	bl SetTaskCallback
	str r4, [r4, #8]
	ldr r1, _08008B7C @ =0x0002BE3A
	adds r0, r5, r1
	strh r6, [r0]
	movs r1, #0x80
	ldr r3, [sp, #4]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r5, #8]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r2, _08008B80 @ =gStageTerrains
	adds r0, r0, r2
	ldr r2, [r0]
	adds r2, r2, r0
	ldr r3, [r0, #8]
	adds r3, r3, r0
	ldr r1, [r0, #4]
	adds r1, r1, r0
	adds r0, r5, #0
	subs r0, #0x10
	ldr r4, [r7, #0xc]
	str r4, [sp]
	bl ResetTerrain
	ldr r3, _08008B84 @ =0x0000060C
	adds r1, r5, r3
	ldr r0, _08008B88 @ =0x0000FFFF
	strh r0, [r1]
	ldr r0, _08008B8C @ =0x0000060E
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	ldr r2, _08008B90 @ =0x0002BE3C
	adds r1, r5, r2
	ldr r0, [r7, #0x78]
	str r0, [r1]
	ldr r3, _08008B94 @ =0x0002BE40
	adds r5, r5, r3
	ldr r0, [r7, #0x7c]
	str r0, [r5]
	ldr r1, [r7, #0xc]
	adds r0, r7, #0
	bl loadStageLandscape
	movs r0, #0
_08008AE8:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	bl ResetStageLayer
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #2
	ble _08008AE8
	ldr r1, _08008B98 @ =gOverworld
	ldr r2, _08008B9C @ =0x0002C00C
	adds r0, r1, r2
	ldr r2, _08008BA0 @ =0x7FFFFFFF
	str r2, [r0]
	ldr r3, _08008BA4 @ =0x0002C010
	adds r0, r1, r3
	str r2, [r0]
	ldr r2, _08008BA8 @ =0x0002C014
	adds r0, r1, r2
	movs r3, #0
	str r3, [r0]
	adds r2, #4
	adds r0, r1, r2
	str r3, [r0]
	ldr r0, _08008BAC @ =0x0002C01C
	adds r2, r1, r0
	movs r0, #0xf0
	lsls r0, r0, #0xe
	str r0, [r2]
	ldr r0, _08008BB0 @ =0x0002C020
	adds r2, r1, r0
	movs r0, #0xa0
	lsls r0, r0, #0xe
	str r0, [r2]
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r3, [r0]
	movs r2, #0
	ldr r3, _08008BB4 @ =0x0002D024
	adds r4, r1, r3
	movs r3, #0
_08008B48:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r4
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08008B48
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008B64: .4byte 0x020023C8
_08008B68: .4byte gStageLandscape
_08008B6C: .4byte gVideoRegBuffer
_08008B70: .4byte 0x0000C1FF
_08008B74: .4byte 0xFFFFFE38
_08008B78: .4byte TaskCB_UpdateOwGraphic
_08008B7C: .4byte 0x0002BE3A
_08008B80: .4byte gStageTerrains
_08008B84: .4byte 0x0000060C
_08008B88: .4byte 0x0000FFFF
_08008B8C: .4byte 0x0000060E
_08008B90: .4byte 0x0002BE3C
_08008B94: .4byte 0x0002BE40
_08008B98: .4byte gOverworld
_08008B9C: .4byte 0x0002C00C
_08008BA0: .4byte 0x7FFFFFFF
_08008BA4: .4byte 0x0002C010
_08008BA8: .4byte 0x0002C014
_08008BAC: .4byte 0x0002C01C
_08008BB0: .4byte 0x0002C020
_08008BB4: .4byte 0x0002D024
