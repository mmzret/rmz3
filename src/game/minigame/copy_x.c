#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/copy_x.inc");

void copyx_minigame_080fa560(struct GameState* g);
void copyx_minigame_080fa62c(struct GameState* g);
void copyx_minigame_080fa764(struct GameState* g);

const GameLoopFunc CopyXMinigameLoops[3] = {
    copyx_minigame_080fa560,
    copyx_minigame_080fa62c,
    copyx_minigame_080fa764,
};

NAKED bool32 exitCopyXMinigame(struct GameState* g) {
  asm(".syntax unified\n\
	push {lr}\n\
	ldr r2, _080FA878 @ =0x00000DCC\n\
	adds r1, r0, r2\n\
	ldrh r2, [r1, #6]\n\
	movs r3, #6\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	bne _080FA87C\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	strh r0, [r1, #6]\n\
	b _080FA8AC\n\
	.align 2, 0\n\
_080FA878: .4byte 0x00000DCC\n\
_080FA87C:\n\
	cmp r0, #1\n\
	bne _080FA8AC\n\
	ldrh r2, [r1]\n\
	movs r3, #0\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	ble _080FA894\n\
	subs r0, r2, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bgt _080FA8AC\n\
_080FA894:\n\
	ldr r2, _080FA8A8 @ =gSystemSavedataManager\n\
	ldr r1, [r1, #0x24]\n\
	ldr r0, [r2, #0x2c]\n\
	cmp r1, r0\n\
	bls _080FA8A4\n\
	str r1, [r2, #0x2c]\n\
	bl SaveSystemData\n\
_080FA8A4:\n\
	movs r0, #0\n\
	b _080FA8AE\n\
	.align 2, 0\n\
_080FA8A8: .4byte gSystemSavedataManager\n\
_080FA8AC:\n\
	movs r0, #1\n\
_080FA8AE:\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
 .syntax divided\n");
}
