#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/harpuia.inc");

void harpuia_minigame_080fab10(struct GameState* g);
void harpuia_minigame_080fabe8(struct GameState* g);
void harpuia_minigame_080faebc(struct GameState* g);

const GameLoopFunc HarpuiaMinigameLoops[3] = {
    harpuia_minigame_080fab10,
    harpuia_minigame_080fabe8,
    harpuia_minigame_080faebc,
};

// 0x080FAFC0
NAKED bool32 exitHarpuiaMinigame(struct GameState* g) {
  asm(".syntax unified\n\
	push {lr}\n\
	ldr r2, _080FAFDC @ =0x00000DCC\n\
	adds r1, r0, r2\n\
	ldrh r2, [r1, #6]\n\
	movs r3, #6\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	bne _080FAFE0\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	strh r0, [r1, #6]\n\
	b _080FB010\n\
	.align 2, 0\n\
_080FAFDC: .4byte 0x00000DCC\n\
_080FAFE0:\n\
	cmp r0, #1\n\
	bne _080FB010\n\
	ldrh r2, [r1]\n\
	movs r3, #0\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	ble _080FAFF8\n\
	subs r0, r2, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bgt _080FB010\n\
_080FAFF8:\n\
	ldr r2, _080FB00C @ =gSystemSavedataManager\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r0, [r2, #0x30]\n\
	cmp r1, r0\n\
	bls _080FB008\n\
	str r1, [r2, #0x30]\n\
	bl SaveSystemData\n\
_080FB008:\n\
	movs r0, #0\n\
	b _080FB012\n\
	.align 2, 0\n\
_080FB00C: .4byte gSystemSavedataManager\n\
_080FB010:\n\
	movs r0, #1\n\
_080FB012:\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
 .syntax divided\n");
}
