#include "global.h"
#include "overworld.h"

NAKED s16 MissileFactory_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r4, [r6, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	beq _0801CEC0\n\
	b _0801CFD4\n\
_0801CEC0:\n\
	ldr r1, _0801CEEC @ =gStageRun\n\
	ldrh r0, [r1, #8]\n\
	movs r6, #1\n\
	adds r2, r6, #0\n\
	orrs r2, r0\n\
	strh r2, [r1, #8]\n\
	ldrb r4, [r1, #2]\n\
	cmp r4, #0\n\
	bne _0801CEF4\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CEF0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r6, [r5]\n\
	b _0801D448\n\
	.align 2, 0\n\
_0801CEEC: .4byte gStageRun\n\
_0801CEF0: .4byte gStageScriptList\n\
_0801CEF4:\n\
	cmp r4, #1\n\
	bne _0801CF14\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CF10 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801CF10: .4byte gStageScriptList\n\
_0801CF14:\n\
	cmp r4, #2\n\
	bne _0801CF30\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CF2C @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801D448\n\
	.align 2, 0\n\
_0801CF2C: .4byte gStageScriptList\n\
_0801CF30:\n\
	cmp r4, #3\n\
	bne _0801CF50\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CF4C @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #5\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801CF4C: .4byte gStageScriptList\n\
_0801CF50:\n\
	cmp r4, #4\n\
	bne _0801CF6C\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CF68 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #5\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801CF68: .4byte gStageScriptList\n\
_0801CF6C:\n\
	cmp r4, #5\n\
	bne _0801CF88\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CF84 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	movs r0, #0x11\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801CF84: .4byte gStageScriptList\n\
_0801CF88:\n\
	cmp r4, #6\n\
	bne _0801CFA4\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CFA0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	movs r0, #0x12\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801CFA0: .4byte gStageScriptList\n\
_0801CFA4:\n\
	cmp r4, #7\n\
	bne _0801CFC0\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CFBC @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	movs r0, #0x14\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801CFBC: .4byte gStageScriptList\n\
_0801CFC0:\n\
	cmp r4, #8\n\
	beq _0801CFC6\n\
	b _0801D448\n\
_0801CFC6:\n\
	ldr r0, _0801CFD0 @ =0x0000FFFE\n\
	ands r2, r0\n\
	strh r2, [r1, #8]\n\
	b _0801D444\n\
	.align 2, 0\n\
_0801CFD0: .4byte 0x0000FFFE\n\
_0801CFD4:\n\
	cmp r0, #1\n\
	bne _0801CFE2\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801D446\n\
_0801CFE2:\n\
	cmp r0, #2\n\
	bne _0801D010\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D004 @ =0x0007C7FF\n\
	cmp r1, r0\n\
	ble _0801D010\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, _0801D008 @ =0x00012FFF\n\
	cmp r1, r0\n\
	bgt _0801D010\n\
	ldr r2, _0801D00C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #3\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D004: .4byte 0x0007C7FF\n\
_0801D008: .4byte 0x00012FFF\n\
_0801D00C: .4byte gCollisionManager\n\
_0801D010:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801D044\n\
	ldr r1, _0801D038 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D03C @ =gStageRun+16\n\
	ldr r1, _0801D040 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D038: .4byte gCollisionManager\n\
_0801D03C: .4byte gStageRun+16\n\
_0801D040: .4byte gStageScriptList\n\
_0801D044:\n\
	cmp r0, #4\n\
	bne _0801D052\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #5\n\
	b _0801D446\n\
_0801D052:\n\
	cmp r0, #5\n\
	bne _0801D074\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D06C @ =0x00101000\n\
	cmp r1, r0\n\
	bgt _0801D074\n\
	ldr r2, _0801D070 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #6\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D06C: .4byte 0x00101000\n\
_0801D070: .4byte gCollisionManager\n\
_0801D074:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #6\n\
	bne _0801D0A4\n\
	ldr r1, _0801D098 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D09C @ =gStageRun+16\n\
	ldr r1, _0801D0A0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #7\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D098: .4byte gCollisionManager\n\
_0801D09C: .4byte gStageRun+16\n\
_0801D0A0: .4byte gStageScriptList\n\
_0801D0A4:\n\
	cmp r0, #7\n\
	bne _0801D0D8\n\
	ldr r1, [r4, #0x58]\n\
	movs r0, #0xcc\n\
	lsls r0, r0, #0xb\n\
	cmp r1, r0\n\
	ble _0801D0D8\n\
	ldr r4, _0801D0D4 @ =gStageRun+232\n\
	adds r0, r4, #0\n\
	movs r1, #6\n\
	bl SetCameraMode\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r4, #0x19]\n\
	strh r1, [r4, #0x22]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xe\n\
	str r0, [r4, #0x60]\n\
	movs r0, #0xc4\n\
	lsls r0, r0, #0xb\n\
	str r0, [r4, #0x64]\n\
	movs r0, #8\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D0D4: .4byte gStageRun+232\n\
_0801D0D8:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #8\n\
	bne _0801D114\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D104 @ =0x001067FF\n\
	cmp r1, r0\n\
	bgt _0801D0EE\n\
	b _0801D448\n\
_0801D0EE:\n\
	ldr r1, _0801D108 @ =gStageRun+324\n\
	movs r0, #0xff\n\
	lsls r0, r0, #0xc\n\
	str r0, [r1]\n\
	ldr r0, _0801D10C @ =gOverworld\n\
	ldr r1, _0801D110 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #9\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D104: .4byte 0x001067FF\n\
_0801D108: .4byte gStageRun+324\n\
_0801D10C: .4byte gOverworld\n\
_0801D110: .4byte 0x0002D025\n\
_0801D114:\n\
	cmp r0, #9\n\
	bne _0801D158\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D140 @ =0x00124FFF\n\
	cmp r1, r0\n\
	bgt _0801D122\n\
	b _0801D448\n\
_0801D122:\n\
	ldr r1, _0801D144 @ =gStageRun+324\n\
	ldr r0, _0801D148 @ =0x0011D800\n\
	str r0, [r1]\n\
	ldr r2, _0801D14C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801D150 @ =gOverworld\n\
	ldr r1, _0801D154 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	movs r0, #0xa\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D140: .4byte 0x00124FFF\n\
_0801D144: .4byte gStageRun+324\n\
_0801D148: .4byte 0x0011D800\n\
_0801D14C: .4byte gCollisionManager\n\
_0801D150: .4byte gOverworld\n\
_0801D154: .4byte 0x0002D025\n\
_0801D158:\n\
	cmp r0, #0xa\n\
	bne _0801D194\n\
	ldr r0, _0801D180 @ =gCollisionManager\n\
	movs r2, #0\n\
	strb r2, [r0, #1]\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D184 @ =0x001337FF\n\
	cmp r1, r0\n\
	bgt _0801D16C\n\
	b _0801D448\n\
_0801D16C:\n\
	ldr r1, _0801D188 @ =gStageRun+324\n\
	movs r0, #0x96\n\
	lsls r0, r0, #0xd\n\
	str r0, [r1]\n\
	ldr r0, _0801D18C @ =gOverworld\n\
	ldr r1, _0801D190 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	strb r2, [r0]\n\
	movs r0, #0xb\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D180: .4byte gCollisionManager\n\
_0801D184: .4byte 0x001337FF\n\
_0801D188: .4byte gStageRun+324\n\
_0801D18C: .4byte gOverworld\n\
_0801D190: .4byte 0x0002D025\n\
_0801D194:\n\
	cmp r0, #0xb\n\
	bne _0801D1D8\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D1C0 @ =0x00151FFF\n\
	cmp r1, r0\n\
	bgt _0801D1A2\n\
	b _0801D448\n\
_0801D1A2:\n\
	ldr r1, _0801D1C4 @ =gStageRun+324\n\
	ldr r0, _0801D1C8 @ =0x0014A800\n\
	str r0, [r1]\n\
	ldr r2, _0801D1CC @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801D1D0 @ =gOverworld\n\
	ldr r1, _0801D1D4 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	strb r1, [r0]\n\
	movs r0, #0xc\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D1C0: .4byte 0x00151FFF\n\
_0801D1C4: .4byte gStageRun+324\n\
_0801D1C8: .4byte 0x0014A800\n\
_0801D1CC: .4byte gCollisionManager\n\
_0801D1D0: .4byte gOverworld\n\
_0801D1D4: .4byte 0x0002D025\n\
_0801D1D8:\n\
	cmp r0, #0xc\n\
	bne _0801D218\n\
	ldr r0, _0801D200 @ =gCollisionManager\n\
	movs r2, #0\n\
	strb r2, [r0, #1]\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D204 @ =0x001607FF\n\
	cmp r1, r0\n\
	bgt _0801D1EC\n\
	b _0801D448\n\
_0801D1EC:\n\
	ldr r1, _0801D208 @ =gStageRun+324\n\
	ldr r0, _0801D20C @ =0x00159000\n\
	str r0, [r1]\n\
	ldr r0, _0801D210 @ =gOverworld\n\
	ldr r1, _0801D214 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	strb r2, [r0]\n\
	movs r0, #0xd\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D200: .4byte gCollisionManager\n\
_0801D204: .4byte 0x001607FF\n\
_0801D208: .4byte gStageRun+324\n\
_0801D20C: .4byte 0x00159000\n\
_0801D210: .4byte gOverworld\n\
_0801D214: .4byte 0x0002D025\n\
_0801D218:\n\
	cmp r0, #0xd\n\
	bne _0801D25C\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D244 @ =0x0017EFFF\n\
	cmp r1, r0\n\
	bgt _0801D226\n\
	b _0801D448\n\
_0801D226:\n\
	ldr r1, _0801D248 @ =gStageRun+324\n\
	ldr r0, _0801D24C @ =0x00177800\n\
	str r0, [r1]\n\
	ldr r2, _0801D250 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801D254 @ =gOverworld\n\
	ldr r1, _0801D258 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	movs r0, #0xe\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D244: .4byte 0x0017EFFF\n\
_0801D248: .4byte gStageRun+324\n\
_0801D24C: .4byte 0x00177800\n\
_0801D250: .4byte gCollisionManager\n\
_0801D254: .4byte gOverworld\n\
_0801D258: .4byte 0x0002D025\n\
_0801D25C:\n\
	cmp r0, #0xe\n\
	bne _0801D298\n\
	ldr r0, _0801D284 @ =gCollisionManager\n\
	movs r2, #0\n\
	strb r2, [r0, #1]\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D288 @ =0x0018D7FF\n\
	cmp r1, r0\n\
	bgt _0801D270\n\
	b _0801D448\n\
_0801D270:\n\
	ldr r1, _0801D28C @ =gStageRun+324\n\
	movs r0, #0xc3\n\
	lsls r0, r0, #0xd\n\
	str r0, [r1]\n\
	ldr r0, _0801D290 @ =gOverworld\n\
	ldr r1, _0801D294 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	strb r2, [r0]\n\
	movs r0, #0xf\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D284: .4byte gCollisionManager\n\
_0801D288: .4byte 0x0018D7FF\n\
_0801D28C: .4byte gStageRun+324\n\
_0801D290: .4byte gOverworld\n\
_0801D294: .4byte 0x0002D025\n\
_0801D298:\n\
	cmp r0, #0xf\n\
	bne _0801D31C\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D30C @ =0x00193FFF\n\
	cmp r1, r0\n\
	ble _0801D2C0\n\
	ldr r0, _0801D310 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r7, r0, r1\n\
	ldr r0, [r7]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801D2C0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r7]\n\
_0801D2C0:\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D314 @ =0x00195FFF\n\
	cmp r1, r0\n\
	bgt _0801D2CA\n\
	b _0801D448\n\
_0801D2CA:\n\
	ldr r2, _0801D318 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801D310 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801D2FE\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801D2F4\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801D2F4:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801D2FE:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r6, r0\n\
	movs r0, #0x10\n\
	strb r0, [r1]\n\
	b _0801D448\n\
	.align 2, 0\n\
_0801D30C: .4byte 0x00193FFF\n\
_0801D310: .4byte gStageRun\n\
_0801D314: .4byte 0x00195FFF\n\
_0801D318: .4byte gCollisionManager\n\
_0801D31C:\n\
	cmp r0, #0x10\n\
	bne _0801D354\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D344 @ =0x001A3FFF\n\
	cmp r1, r0\n\
	ble _0801D354\n\
	ldr r1, _0801D348 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D34C @ =gStageRun+16\n\
	ldr r1, _0801D350 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #0x12\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D344: .4byte 0x001A3FFF\n\
_0801D348: .4byte gCollisionManager\n\
_0801D34C: .4byte gStageRun+16\n\
_0801D350: .4byte gStageScriptList\n\
_0801D354:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x11\n\
	bne _0801D394\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D384 @ =0x001A3FFF\n\
	cmp r1, r0\n\
	ble _0801D394\n\
	ldr r1, _0801D388 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D38C @ =gStageRun+16\n\
	ldr r1, _0801D390 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #0x12\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D384: .4byte 0x001A3FFF\n\
_0801D388: .4byte gCollisionManager\n\
_0801D38C: .4byte gStageRun+16\n\
_0801D390: .4byte gStageScriptList\n\
_0801D394:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x12\n\
	bne _0801D3AA\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #0x13\n\
	b _0801D446\n\
_0801D3AA:\n\
	cmp r0, #0x13\n\
	bne _0801D40C\n\
	ldr r4, _0801D3FC @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801D40C\n\
	ldr r1, _0801D400 @ =gCollisionManager\n\
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
	ldr r1, _0801D404 @ =gStageScriptList\n\
	ldr r1, [r1, #0x18]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801D408 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #7\n\
	bl setStageCheckpoint2\n\
	movs r0, #0x14\n\
	b _0801D446\n\
	.align 2, 0\n\
_0801D3FC: .4byte gStageRun\n\
_0801D400: .4byte gCollisionManager\n\
_0801D404: .4byte gStageScriptList\n\
_0801D408: .4byte 0x0000FFEF\n\
_0801D40C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x14\n\
	bne _0801D448\n\
	ldr r1, _0801D450 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	ldr r4, _0801D454 @ =gStageRun+16\n\
	ldr r0, _0801D458 @ =gStageScriptList\n\
	ldr r0, [r0, #0x18]\n\
	ldr r1, [r0, #0x34]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801D45C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0801D444:\n\
	movs r0, #0x15\n\
_0801D446:\n\
	strb r0, [r5]\n\
_0801D448:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801D450: .4byte gCollisionManager\n\
_0801D454: .4byte gStageRun+16\n\
_0801D458: .4byte gStageScriptList\n\
_0801D45C: .4byte 0x0000FFFE\n\
	 .syntax divided\n");
}

s16 MissileFactory_FreeUpdate(struct StageRun* p) {
  struct Entity* z = (p->vm).entities[0].entity;
  if (p->stageEventPhase == 0) {
    gStageRun.missionStatus |= MISSION_STAY;
    if (gStageRun.checkpoint == 0) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_MISSILE_FACTORY][14]);
      setStageCheckpoint(1);
      p->stageEventPhase = 1;
    } else if (gStageRun.checkpoint == 2) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_MISSILE_FACTORY][2]);
      p->stageEventPhase = 2;
    }

  } else if (p->stageEventPhase == 1) {
    setStageCheckpoint(2);
    p->stageEventPhase = 2;

  } else if (p->stageEventPhase == 2) {
    if ((z->coord).x >= 0x78000) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_MISSILE_FACTORY][15]);
      gStageRun.missionStatus &= ~MISSION_STAY;
      p->stageEventPhase = 3;
    }
  }
  return 0;
}
