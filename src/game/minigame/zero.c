#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/zero.inc");

void zeroMinigamePhase0(struct GameState* g);
void zeroMinigamePhase1(struct GameState* g);
void zeroMinigamePhase2(struct GameState* g);

const GameLoopFunc ZeroMinigameLoops[3] = {
    zeroMinigamePhase0,
    zeroMinigamePhase1,
    zeroMinigamePhase2,
};

// clang-format off
const struct Coord Coord_ARRAY_08386af8[6] = {
    {-0x2000, 0x1000}, {+0x2000, 0x1000},
    {-0x2000, 0x4800}, {+0x2000, 0x4800},
    {-0x2000, 0x8000}, {+0x2000, 0x8000},
};
// clang-format on

// clang-format off
const struct Coord Coord_ARRAY_08386b28[6] = {
    {+0x2800, 0x1000}, {-0x2800, 0x1000},
    {+0x1800, 0x4800}, {-0x1800, 0x4800},
    {+0x2800, 0x8000}, {-0x2800, 0x8000},
};
// clang-format on

NAKED bool32 exitZeroMinigame(struct GameState* g) {
  asm(".syntax unified\n\
	push {lr}\n\
	ldr r2, _080F9864 @ =0x00000DCC\n\
	adds r1, r0, r2\n\
	ldrh r2, [r1, #6]\n\
	movs r3, #6\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	bne _080F9868\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	strh r0, [r1, #6]\n\
	b _080F9898\n\
	.align 2, 0\n\
_080F9864: .4byte 0x00000DCC\n\
_080F9868:\n\
	cmp r0, #1\n\
	bne _080F9898\n\
	ldrh r2, [r1]\n\
	movs r3, #0\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	ble _080F9880\n\
	subs r0, r2, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bgt _080F9898\n\
_080F9880:\n\
	ldr r2, _080F9894 @ =gSystemSavedataManager\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r0, [r2, #0x24]\n\
	cmp r1, r0\n\
	bls _080F9890\n\
	str r1, [r2, #0x24]\n\
	bl SaveSystemData\n\
_080F9890:\n\
	movs r0, #0\n\
	b _080F989A\n\
	.align 2, 0\n\
_080F9894: .4byte gSystemSavedataManager\n\
_080F9898:\n\
	movs r0, #1\n\
_080F989A:\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
 .syntax divided\n");
}
