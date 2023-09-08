#include "global.h"
#include "overworld.h"

/*
checkpoint (0202fe62):
  00: ステージ読み込み中
  01: ブリーフィング
  02: スタートポイント
  05: 中ボス戦
  06: 改造パンテオンアクア発生イベント
  07: 中ボス撃破後
  08: ボス戦
  09: ボス邂逅(リトライ時も)

StageEventPhase (0202ffdc):
  0: ??
  1: ??
  2: チルドレ邂逅前
  3: チルドレ邂逅イベント
  4: チルドレ出発開始
*/
NAKED s16 Ocean_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r7, r0, #0\n\
	ldr r5, [r7, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r7, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0801BAF0\n\
	b _0801BCA8\n\
_0801BAF0:\n\
	ldr r2, _0801BB30 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	movs r1, #1\n\
	mov r8, r1\n\
	mov r1, r8\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	ldr r5, _0801BB34 @ =gCurStory\n\
	ldrb r0, [r5, #4]\n\
	movs r3, #0xfb\n\
	adds r1, r3, #0\n\
	ands r1, r0\n\
	strb r1, [r5, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801BB3C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BB38 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x44]\n\
	bl SetScript\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #3\n\
	str r0, [r1]\n\
	movs r0, #0x14\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BB30: .4byte gStageRun\n\
_0801BB34: .4byte gCurStory\n\
_0801BB38: .4byte gStageScriptList\n\
_0801BB3C:\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801BB74\n\
	ldrb r1, [r5, #9]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	ands r0, r3\n\
	movs r1, #0xf7\n\
	ands r0, r1\n\
	movs r1, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #9]\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BB70 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	mov r1, r8\n\
	strb r1, [r6]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BB70: .4byte gStageScriptList\n\
_0801BB74:\n\
	cmp r4, #1\n\
	bne _0801BB94\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BB90 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BB90: .4byte gStageScriptList\n\
_0801BB94:\n\
	cmp r4, #2\n\
	bne _0801BBB4\n\
	ldrb r1, [r5, #9]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	ands r0, r3\n\
	strb r0, [r5, #9]\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BBB0 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #8]\n\
	b _0801BBEC\n\
	.align 2, 0\n\
_0801BBB0: .4byte gStageScriptList\n\
_0801BBB4:\n\
	cmp r4, #3\n\
	bne _0801BBD4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BBD0 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BBD0: .4byte gStageScriptList\n\
_0801BBD4:\n\
	cmp r4, #4\n\
	bne _0801BBF8\n\
	ldrb r1, [r5, #9]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	ands r0, r3\n\
	strb r0, [r5, #9]\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BBF4 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x14]\n\
_0801BBEC:\n\
	bl SetScript\n\
	strb r4, [r6]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BBF4: .4byte gStageScriptList\n\
_0801BBF8:\n\
	cmp r4, #5\n\
	bne _0801BC14\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BC10 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BC10: .4byte gStageScriptList\n\
_0801BC14:\n\
	cmp r4, #6\n\
	bne _0801BC38\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BC34 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	ldrb r0, [r5, #4]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #4]\n\
	movs r0, #7\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BC34: .4byte gStageScriptList\n\
_0801BC38:\n\
	cmp r4, #7\n\
	bne _0801BC60\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BC5C @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	ldrb r1, [r5, #9]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	movs r1, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #9]\n\
	movs r0, #0xb\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BC5C: .4byte gStageScriptList\n\
_0801BC60:\n\
	cmp r4, #8\n\
	bne _0801BC84\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BC80 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xd\n\
	strb r0, [r1]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BC80: .4byte gStageScriptList\n\
_0801BC84:\n\
	cmp r4, #9\n\
	beq _0801BC8A\n\
	b _0801C0F6\n\
_0801BC8A:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BCA4 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BCA4: .4byte gStageScriptList\n\
_0801BCA8:\n\
	cmp r0, #1\n\
	bne _0801BCB6\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801C0F4\n\
_0801BCB6:\n\
	cmp r0, #2\n\
	bne _0801BCE4\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BCD8 @ =0x0003BFFF\n\
	cmp r1, r0\n\
	ble _0801BCE4\n\
	ldr r0, _0801BCDC @ =gStageRun+16\n\
	ldr r1, _0801BCE0 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BCD8: .4byte 0x0003BFFF\n\
_0801BCDC: .4byte gStageRun+16\n\
_0801BCE0: .4byte gStageScriptList\n\
_0801BCE4:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #3\n\
	bne _0801BCFC\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	strb r0, [r4]\n\
	b _0801C0F6\n\
_0801BCFC:\n\
	cmp r0, #4\n\
	bne _0801BD48\n\
	ldr r0, _0801BD14 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801BD20\n\
	ldr r1, _0801BD18 @ =gStageRun+328\n\
	ldr r0, _0801BD1C @ =0x00188800\n\
	b _0801BD26\n\
	.align 2, 0\n\
_0801BD14: .4byte gCurStory\n\
_0801BD18: .4byte gStageRun+328\n\
_0801BD1C: .4byte 0x00188800\n\
_0801BD20:\n\
	ldr r1, _0801BD40 @ =gStageRun+328\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xe\n\
_0801BD26:\n\
	str r0, [r1]\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BD44 @ =0x00194FFF\n\
	cmp r1, r0\n\
	bgt _0801BD32\n\
	b _0801C0F6\n\
_0801BD32:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BD40: .4byte gStageRun+328\n\
_0801BD44: .4byte 0x00194FFF\n\
_0801BD48:\n\
	cmp r0, #5\n\
	bne _0801BD6C\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BD60 @ =0x001A4FFF\n\
	cmp r1, r0\n\
	ble _0801BD6C\n\
	ldr r0, _0801BD64 @ =gStageRun+16\n\
	ldr r1, _0801BD68 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x1c]\n\
	b _0801BD88\n\
	.align 2, 0\n\
_0801BD60: .4byte 0x001A4FFF\n\
_0801BD64: .4byte gStageRun+16\n\
_0801BD68: .4byte gStageScriptList\n\
_0801BD6C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #6\n\
	bne _0801BDB4\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BDA4 @ =0x001A4FFF\n\
	cmp r1, r0\n\
	ble _0801BDB4\n\
	ldr r0, _0801BDA8 @ =gStageRun+16\n\
	ldr r1, _0801BDAC @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x20]\n\
_0801BD88:\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801BDB0 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #7\n\
	strb r0, [r4]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BDA4: .4byte 0x001A4FFF\n\
_0801BDA8: .4byte gStageRun+16\n\
_0801BDAC: .4byte gStageScriptList\n\
_0801BDB0: .4byte gCurStory\n\
_0801BDB4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r7, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #7\n\
	bne _0801BDCA\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #8\n\
	b _0801C0F4\n\
_0801BDCA:\n\
	cmp r0, #8\n\
	bne _0801BE30\n\
	ldr r4, _0801BE1C @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801BE30\n\
	ldr r1, _0801BE20 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801BE24 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801BE28 @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801BE2C @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #9\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801BE1C: .4byte gStageRun\n\
_0801BE20: .4byte gCollisionManager\n\
_0801BE24: .4byte gStageScriptList\n\
_0801BE28: .4byte 0x0000FFEF\n\
_0801BE2C: .4byte gCurStory\n\
_0801BE30:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #9\n\
	bne _0801BE54\n\
	ldr r1, _0801BE50 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BE50: .4byte gCollisionManager\n\
_0801BE54:\n\
	cmp r0, #0xa\n\
	bne _0801BE80\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BE78 @ =0x001B3FFF\n\
	cmp r1, r0\n\
	ble _0801BE80\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801BE7C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #0xb\n\
	strb r0, [r4]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BE78: .4byte 0x001B3FFF\n\
_0801BE7C: .4byte gCurStory\n\
_0801BE80:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r7, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xb\n\
	bne _0801BF10\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BF00 @ =0x002B0FFF\n\
	cmp r1, r0\n\
	ble _0801BEB6\n\
	movs r0, #3\n\
	bl DeleteScriptEntity\n\
	ldr r0, _0801BF04 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r6, r0, r1\n\
	ldr r0, [r6]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801BEB6\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r6]\n\
_0801BEB6:\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BF08 @ =0x002B2FFF\n\
	cmp r1, r0\n\
	bgt _0801BEC0\n\
	b _0801C0F6\n\
_0801BEC0:\n\
	ldr r2, _0801BF0C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801BF04 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801BEF4\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801BEEA\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801BEEA:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801BEF4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xc\n\
	strb r0, [r1]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BF00: .4byte 0x002B0FFF\n\
_0801BF04: .4byte gStageRun\n\
_0801BF08: .4byte 0x002B2FFF\n\
_0801BF0C: .4byte gCollisionManager\n\
_0801BF10:\n\
	cmp r0, #0xc\n\
	bne _0801BF3C\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BF2C @ =0x002C0FFF\n\
	cmp r1, r0\n\
	ble _0801BF3C\n\
	ldr r1, _0801BF30 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801BF34 @ =gStageRun+16\n\
	ldr r1, _0801BF38 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x34]\n\
	b _0801BF5E\n\
	.align 2, 0\n\
_0801BF2C: .4byte 0x002C0FFF\n\
_0801BF30: .4byte gCollisionManager\n\
_0801BF34: .4byte gStageRun+16\n\
_0801BF38: .4byte gStageScriptList\n\
_0801BF3C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xd\n\
	bne _0801BF80\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801BF70 @ =0x002C0FFF\n\
	cmp r1, r0\n\
	ble _0801BF80\n\
	ldr r1, _0801BF74 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801BF78 @ =gStageRun+16\n\
	ldr r1, _0801BF7C @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x38]\n\
_0801BF5E:\n\
	bl SetScript\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r0, #0xe\n\
	strb r0, [r4]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801BF70: .4byte 0x002C0FFF\n\
_0801BF74: .4byte gCollisionManager\n\
_0801BF78: .4byte gStageRun+16\n\
_0801BF7C: .4byte gStageScriptList\n\
_0801BF80:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r7, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xe\n\
	bne _0801BF98\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	movs r0, #0xf\n\
	strb r0, [r4]\n\
	b _0801C0F6\n\
_0801BF98:\n\
	cmp r0, #0xf\n\
	bne _0801C088\n\
	ldr r0, _0801BFE4 @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #0x10\n\
	mov ip, r0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801C088\n\
	ldr r6, _0801BFE8 @ =gCurStory\n\
	ldrb r5, [r6, #9]\n\
	lsls r3, r5, #0x18\n\
	lsrs r0, r3, #0x19\n\
	movs r1, #1\n\
	adds r2, r1, #0\n\
	bics r2, r0\n\
	lsrs r4, r3, #0x1a\n\
	adds r0, r1, #0\n\
	bics r0, r4\n\
	adds r2, r2, r0\n\
	lsrs r3, r3, #0x1b\n\
	bics r1, r3\n\
	adds r2, r2, r1\n\
	ldr r1, _0801BFEC @ =gMission\n\
	movs r3, #7\n\
	ldrsb r3, [r1, r3]\n\
	mov r0, ip\n\
	ands r0, r5\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	bne _0801BFF0\n\
	adds r1, r2, #1\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	subs r0, r3, r0\n\
	cmp r0, #0\n\
	bgt _0801BFFA\n\
	b _0801C032\n\
	.align 2, 0\n\
_0801BFE4: .4byte gStageRun\n\
_0801BFE8: .4byte gCurStory\n\
_0801BFEC: .4byte gMission\n\
_0801BFF0:\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r2\n\
	subs r0, r3, r0\n\
	cmp r0, #0\n\
	ble _0801C032\n\
_0801BFFA:\n\
	mov ip, r4\n\
	ldrb r5, [r6, #9]\n\
	lsls r3, r5, #0x18\n\
	lsrs r0, r3, #0x19\n\
	movs r1, #1\n\
	adds r2, r1, #0\n\
	bics r2, r0\n\
	lsrs r4, r3, #0x1a\n\
	adds r0, r1, #0\n\
	bics r0, r4\n\
	adds r2, r2, r0\n\
	lsrs r3, r3, #0x1b\n\
	bics r1, r3\n\
	adds r1, r2, r1\n\
	mov r0, ip\n\
	movs r2, #7\n\
	ldrsb r2, [r0, r2]\n\
	movs r0, #0x10\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	bne _0801C026\n\
	adds r1, #1\n\
_0801C026:\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	subs r0, r2, r0\n\
	mov r1, ip\n\
	strb r0, [r1, #7]\n\
	b _0801C036\n\
_0801C032:\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
_0801C036:\n\
	ldr r1, _0801C078 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	ldr r4, _0801C07C @ =gStageRun+16\n\
	ldr r0, _0801C080 @ =gStageScriptList\n\
	ldr r0, [r0, #0xc]\n\
	ldr r1, [r0, #0x40]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801C084 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0x10\n\
	strb r0, [r1]\n\
	b _0801C0F6\n\
	.align 2, 0\n\
_0801C078: .4byte gCollisionManager\n\
_0801C07C: .4byte gStageRun+16\n\
_0801C080: .4byte gStageScriptList\n\
_0801C084: .4byte 0x0000FFEF\n\
_0801C088:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r6, r7, r1\n\
	ldrb r0, [r6]\n\
	cmp r0, #0x14\n\
	bne _0801C0D4\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801C0A6\n\
	subs r0, #1\n\
	str r0, [r1]\n\
	b _0801C0F6\n\
_0801C0A6:\n\
	ldr r4, _0801C0D0 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r7, r4, r1\n\
	ldr r0, [r7]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801C0C2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r7]\n\
_0801C0C2:\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	movs r0, #0x15\n\
	b _0801C0F4\n\
	.align 2, 0\n\
_0801C0D0: .4byte gStageRun\n\
_0801C0D4:\n\
	cmp r0, #0x15\n\
	bne _0801C0F6\n\
	ldr r2, _0801C104 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801C0F6\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801C108 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r2, #8]\n\
	movs r0, #0x16\n\
_0801C0F4:\n\
	strb r0, [r6]\n\
_0801C0F6:\n\
	movs r0, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801C104: .4byte gStageRun\n\
_0801C108: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}

NAKED s16 Ocean_FreeUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r2, r0, #0\n\
	ldr r3, [r2, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0801C1FC\n\
	ldr r2, _0801C164 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	movs r6, #1\n\
	orrs r0, r6\n\
	strh r0, [r2, #8]\n\
	ldr r4, _0801C168 @ =gCurStory\n\
	ldrb r1, [r4, #4]\n\
	movs r3, #0xfb\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	strb r0, [r4, #4]\n\
	ldrb r0, [r2, #2]\n\
	cmp r0, #0\n\
	bne _0801C170\n\
	ldrb r1, [r4, #9]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	ands r0, r3\n\
	movs r1, #0xf7\n\
	ands r0, r1\n\
	movs r1, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #9]\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C16C @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x48]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r6, [r5]\n\
	b _0801C3B6\n\
	.align 2, 0\n\
_0801C164: .4byte gStageRun\n\
_0801C168: .4byte gCurStory\n\
_0801C16C: .4byte gStageScriptList\n\
_0801C170:\n\
	cmp r0, #2\n\
	bne _0801C194\n\
	ldrb r1, [r4, #9]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	ands r0, r3\n\
	strb r0, [r4, #9]\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C190 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	movs r0, #4\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C190: .4byte gStageScriptList\n\
_0801C194:\n\
	cmp r0, #5\n\
	bne _0801C1B0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C1AC @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C1AC: .4byte gStageScriptList\n\
_0801C1B0:\n\
	cmp r0, #6\n\
	bne _0801C1D4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C1D0 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	ldrb r0, [r4, #4]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r4, #4]\n\
	movs r0, #7\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C1D0: .4byte gStageScriptList\n\
_0801C1D4:\n\
	cmp r0, #7\n\
	beq _0801C1DA\n\
	b _0801C3B6\n\
_0801C1DA:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C1F8 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	ldrb r1, [r4, #9]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	movs r1, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #9]\n\
	movs r0, #0xb\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C1F8: .4byte gStageScriptList\n\
_0801C1FC:\n\
	cmp r0, #1\n\
	bne _0801C20A\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	b _0801C3B4\n\
_0801C20A:\n\
	cmp r0, #4\n\
	bne _0801C254\n\
	ldr r0, _0801C220 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801C22C\n\
	ldr r1, _0801C224 @ =gStageRun+328\n\
	ldr r0, _0801C228 @ =0x00188800\n\
	b _0801C232\n\
	.align 2, 0\n\
_0801C220: .4byte gCurStory\n\
_0801C224: .4byte gStageRun+328\n\
_0801C228: .4byte 0x00188800\n\
_0801C22C:\n\
	ldr r1, _0801C24C @ =gStageRun+328\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xe\n\
_0801C232:\n\
	str r0, [r1]\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801C250 @ =0x00194FFF\n\
	cmp r1, r0\n\
	bgt _0801C23E\n\
	b _0801C3B6\n\
_0801C23E:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _0801C3B6\n\
	.align 2, 0\n\
_0801C24C: .4byte gStageRun+328\n\
_0801C250: .4byte 0x00194FFF\n\
_0801C254:\n\
	cmp r0, #6\n\
	bne _0801C290\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801C280 @ =0x001A4FFF\n\
	cmp r1, r0\n\
	ble _0801C290\n\
	ldr r0, _0801C284 @ =gStageRun+16\n\
	ldr r1, _0801C288 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801C28C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #7\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C280: .4byte 0x001A4FFF\n\
_0801C284: .4byte gStageRun+16\n\
_0801C288: .4byte gStageScriptList\n\
_0801C28C: .4byte gCurStory\n\
_0801C290:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #7\n\
	bne _0801C2A6\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #8\n\
	b _0801C3B4\n\
_0801C2A6:\n\
	cmp r0, #8\n\
	bne _0801C30C\n\
	ldr r4, _0801C2F8 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801C30C\n\
	ldr r1, _0801C2FC @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C300 @ =gStageScriptList\n\
	ldr r1, [r1, #0xc]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801C304 @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801C308 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #9\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C2F8: .4byte gStageRun\n\
_0801C2FC: .4byte gCollisionManager\n\
_0801C300: .4byte gStageScriptList\n\
_0801C304: .4byte 0x0000FFEF\n\
_0801C308: .4byte gCurStory\n\
_0801C30C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #9\n\
	bne _0801C330\n\
	ldr r1, _0801C32C @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	b _0801C3B6\n\
	.align 2, 0\n\
_0801C32C: .4byte gCollisionManager\n\
_0801C330:\n\
	cmp r0, #0xa\n\
	bne _0801C35C\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801C354 @ =0x001B3FFF\n\
	cmp r1, r0\n\
	ble _0801C35C\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801C358 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #0xb\n\
	strb r0, [r4]\n\
	b _0801C3B6\n\
	.align 2, 0\n\
_0801C354: .4byte 0x001B3FFF\n\
_0801C358: .4byte gCurStory\n\
_0801C35C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xb\n\
	bne _0801C388\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801C380 @ =0x002B0FFF\n\
	cmp r1, r0\n\
	ble _0801C3B6\n\
	ldr r2, _0801C384 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #0xc\n\
	b _0801C3B4\n\
	.align 2, 0\n\
_0801C380: .4byte 0x002B0FFF\n\
_0801C384: .4byte gCollisionManager\n\
_0801C388:\n\
	cmp r0, #0xc\n\
	bne _0801C3B6\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801C3C0 @ =0x002C0FFF\n\
	cmp r1, r0\n\
	ble _0801C3B6\n\
	ldr r1, _0801C3C4 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r4, _0801C3C8 @ =gStageRun+16\n\
	ldr r0, _0801C3CC @ =gStageScriptList\n\
	ldr r0, [r0, #0xc]\n\
	ldr r1, [r0, #0x4c]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801C3D0 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xd\n\
_0801C3B4:\n\
	strb r0, [r5]\n\
_0801C3B6:\n\
	movs r0, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801C3C0: .4byte 0x002C0FFF\n\
_0801C3C4: .4byte gCollisionManager\n\
_0801C3C8: .4byte gStageRun+16\n\
_0801C3CC: .4byte gStageScriptList\n\
_0801C3D0: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}
