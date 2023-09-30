#include "global.h"
#include "overworld.h"

NAKED s16 SpaceCraft_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	ldr r5, [r7, #0x20]\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	subs r0, #6\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bhi _0801AD8E\n\
	ldr r2, _0801ADD0 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _0801ADD4 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0801ADD8 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0x7f\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801AD8E\n\
	ldr r4, _0801ADDC @ =0x0000013F\n\
	adds r0, r4, #0\n\
	bl isSoundPlaying\n\
	cmp r0, #0\n\
	bne _0801AD84\n\
	adds r0, r4, #0\n\
	bl PlaySound\n\
_0801AD84:\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #4\n\
	bl AppendQuake\n\
_0801AD8E:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r7, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0801AD9C\n\
	b _0801AEF8\n\
_0801AD9C:\n\
	ldr r5, _0801ADE0 @ =gStageRun\n\
	ldrh r0, [r5, #8]\n\
	movs r1, #1\n\
	mov r8, r1\n\
	mov r1, r8\n\
	orrs r0, r1\n\
	strh r0, [r5, #8]\n\
	ldr r2, _0801ADE4 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r1, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801ADEC\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801ADE8 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #0x14\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801ADD0: .4byte RNG_0202f388\n\
_0801ADD4: .4byte 0x000343FD\n\
_0801ADD8: .4byte 0x00269EC3\n\
_0801ADDC: .4byte 0x0000013F\n\
_0801ADE0: .4byte gStageRun\n\
_0801ADE4: .4byte gCurStory\n\
_0801ADE8: .4byte gStageScriptList\n\
_0801ADEC:\n\
	ldrb r4, [r5, #2]\n\
	cmp r4, #0\n\
	bne _0801AE10\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AE0C @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	mov r0, r8\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AE0C: .4byte gStageScriptList\n\
_0801AE10:\n\
	cmp r4, #1\n\
	bne _0801AE1A\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	b _0801AEFE\n\
_0801AE1A:\n\
	cmp r4, #2\n\
	bne _0801AE24\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	b _0801AF22\n\
_0801AE24:\n\
	cmp r4, #3\n\
	bne _0801AE40\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AE3C @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	strb r4, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AE3C: .4byte gStageScriptList\n\
_0801AE40:\n\
	cmp r4, #4\n\
	bne _0801AE5C\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AE58 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #5\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AE58: .4byte gStageScriptList\n\
_0801AE5C:\n\
	cmp r4, #5\n\
	bne _0801AE78\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AE74 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #6\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AE74: .4byte gStageScriptList\n\
_0801AE78:\n\
	cmp r4, #6\n\
	bne _0801AE94\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AE90 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	movs r0, #8\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AE90: .4byte gStageScriptList\n\
_0801AE94:\n\
	cmp r4, #7\n\
	bne _0801AEC4\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AEC0 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x1c]\n\
	str r2, [sp]\n\
	bl SetScript\n\
	ldr r2, [sp]\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #9\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AEC0: .4byte gStageScriptList\n\
_0801AEC4:\n\
	cmp r4, #8\n\
	beq _0801AECA\n\
	b _0801B16C\n\
_0801AECA:\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801AEF0 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	ldrh r1, [r5, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801AEF4 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r5, #8]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xb\n\
	strb r0, [r1]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AEF0: .4byte gStageScriptList\n\
_0801AEF4: .4byte 0x0000FFFE\n\
_0801AEF8:\n\
	cmp r0, #1\n\
	bne _0801AF1C\n\
	ldr r0, _0801AF14 @ =gStageRun+16\n\
_0801AEFE:\n\
	ldr r1, _0801AF18 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AF14: .4byte gStageRun+16\n\
_0801AF18: .4byte gStageScriptList\n\
_0801AF1C:\n\
	cmp r0, #2\n\
	bne _0801AF40\n\
	ldr r0, _0801AF38 @ =gStageRun+16\n\
_0801AF22:\n\
	ldr r1, _0801AF3C @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AF38: .4byte gStageRun+16\n\
_0801AF3C: .4byte gStageScriptList\n\
_0801AF40:\n\
	cmp r0, #3\n\
	bne _0801AF6C\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801AF64 @ =0x000C6FFF\n\
	cmp r1, r0\n\
	ble _0801AF6C\n\
	ldr r1, _0801AF68 @ =gCollisionManager\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	movs r0, #4\n\
	strb r0, [r6]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AF64: .4byte 0x000C6FFF\n\
_0801AF68: .4byte gCollisionManager\n\
_0801AF6C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #4\n\
	bne _0801AFA4\n\
	ldr r1, _0801AF98 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801AF9C @ =gStageRun+16\n\
	ldr r1, _0801AFA0 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #5\n\
	strb r0, [r4]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AF98: .4byte gCollisionManager\n\
_0801AF9C: .4byte gStageRun+16\n\
_0801AFA0: .4byte gStageScriptList\n\
_0801AFA4:\n\
	cmp r0, #5\n\
	bne _0801AFC4\n\
	ldr r2, _0801AFC0 @ =gCollisionManager\n\
	ldrb r1, [r2]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	strb r0, [r4]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801AFC0: .4byte gCollisionManager\n\
_0801AFC4:\n\
	cmp r0, #6\n\
	bne _0801B054\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, _0801B040 @ =0x00013FFF\n\
	cmp r1, r0\n\
	bgt _0801B054\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801B044 @ =0x000DFFFF\n\
	cmp r1, r0\n\
	ble _0801AFF4\n\
	ldr r0, _0801B048 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r6, r0, r1\n\
	ldr r0, [r6]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801AFF4\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r6]\n\
_0801AFF4:\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801B04C @ =0x000E1FFF\n\
	cmp r1, r0\n\
	bgt _0801AFFE\n\
	b _0801B16C\n\
_0801AFFE:\n\
	ldr r2, _0801B050 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801B048 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801B032\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801B028\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801B028:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801B032:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801B040: .4byte 0x00013FFF\n\
_0801B044: .4byte 0x000DFFFF\n\
_0801B048: .4byte gStageRun\n\
_0801B04C: .4byte 0x000E1FFF\n\
_0801B050: .4byte gCollisionManager\n\
_0801B054:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #7\n\
	bne _0801B094\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801B084 @ =0x000EDFFF\n\
	cmp r1, r0\n\
	ble _0801B094\n\
	ldr r1, _0801B088 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801B08C @ =gStageRun+16\n\
	ldr r1, _0801B090 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	b _0801B0C4\n\
	.align 2, 0\n\
_0801B084: .4byte 0x000EDFFF\n\
_0801B088: .4byte gCollisionManager\n\
_0801B08C: .4byte gStageRun+16\n\
_0801B090: .4byte gStageScriptList\n\
_0801B094:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r7, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #8\n\
	bne _0801B0AC\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	b _0801B16C\n\
_0801B0AC:\n\
	cmp r0, #9\n\
	bne _0801B0D8\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801B0CC @ =0x000EFFFF\n\
	cmp r1, r0\n\
	ble _0801B0D8\n\
	ldr r0, _0801B0D0 @ =gStageRun+16\n\
	ldr r1, _0801B0D4 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
_0801B0C4:\n\
	movs r0, #8\n\
	strb r0, [r4]\n\
	b _0801B16C\n\
	.align 2, 0\n\
_0801B0CC: .4byte 0x000EFFFF\n\
_0801B0D0: .4byte gStageRun+16\n\
_0801B0D4: .4byte gStageScriptList\n\
_0801B0D8:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r7, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xa\n\
	bne _0801B140\n\
	ldr r4, _0801B130 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801B140\n\
	ldr r1, _0801B134 @ =gCollisionManager\n\
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
	ldr r1, _0801B138 @ =gStageScriptList\n\
	ldr r1, [r1, #4]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801B13C @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #8\n\
	bl setStageCheckpoint2\n\
	movs r0, #0xb\n\
	b _0801B16A\n\
	.align 2, 0\n\
_0801B130: .4byte gStageRun\n\
_0801B134: .4byte gCollisionManager\n\
_0801B138: .4byte gStageScriptList\n\
_0801B13C: .4byte 0x0000FFEF\n\
_0801B140:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x14\n\
	bne _0801B16C\n\
	ldr r4, _0801B17C @ =gStageRun+16\n\
	ldr r0, _0801B180 @ =gStageScriptList\n\
	ldr r0, [r0, #4]\n\
	ldr r1, [r0, #4]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801B184 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0x15\n\
_0801B16A:\n\
	strb r0, [r5]\n\
_0801B16C:\n\
	movs r0, #0\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801B17C: .4byte gStageRun+16\n\
_0801B180: .4byte gStageScriptList\n\
_0801B184: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}

s16 SpaceCraft_FreeUpdate(struct StageRun* p) {
  struct Zero* z = (struct Zero*)(p->vm).entities[0].entity;
  if (p->stageEventPhase == 0) {
    gStageRun.missionStatus |= MISSION_STAY;
    CLEAR_FLAG(gCurStory.s.gameflags, FLAG_2);

    if (gStageRun.checkpoint == 0) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SPACE_CRAFT][13]);
      setStageCheckpoint(1);
      p->stageEventPhase = 1;

    } else if (gStageRun.checkpoint == 1) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SPACE_CRAFT][3]);
      p->stageEventPhase = 1;

    } else if (gStageRun.checkpoint == 2) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SPACE_CRAFT][6]);
      p->stageEventPhase = 2;
    }

  } else if (p->stageEventPhase == 1 && (PIXEL(3480) <= (z->s).coord.x)) {
    *(&gStageRun.vm.camera.left) = PIXEL(3360);
    setStageCheckpoint(2);
    p->stageEventPhase = 2;

  } else if (p->stageEventPhase == 2 && ((z->s).coord.y < PIXEL(320))) {
    if ((z->s).coord.x >= PIXEL(3584)) {
      gCollisionManager.sweep |= (1 << FACTION_ENEMY);
    }
    if ((z->s).coord.x >= PIXEL(3616)) {
      gCollisionManager.sweep = 0;
      p->stageEventPhase = 3;
    }

  } else if (p->stageEventPhase == 3 && ((z->s).coord.x >= PIXEL(3840))) {
    SetScript(&gStageRun.vm, gStageScriptList[STAGE_SPACE_CRAFT][14]);
    gStageRun.missionStatus &= ~MISSION_STAY;
  }
  return 0;
}
