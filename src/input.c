#include "input.h"

#include "gba/gba.h"

static void resetKeyStates(void);
static void readKeyInput(struct KeyState *j, s32 retry);
static void resetKeyState(struct KeyState *j);

void InitInput(void) {
  resetKeyStates();
  pollKeyInput();
}

static void resetKeyStates(void) {
  s32 i;
  for (i = 0; i < 2; i++) {
    struct KeyState *j = &gJoypad[i];
    resetKeyState(j);
    j->field6_0x14 = 24;
    j->field7_0x15 = 4;
  }
}

void pollKeyInput(void) {
  s32 retry = 0;
  struct KeyState *j = gJoypad;

  for (retry = 0; retry < 2; retry++) {
    readKeyInput(j, retry);
    j = j + 1;
  }
}

NAKED static void readKeyInput(struct KeyState *j, s32 retry) {
  asm(".syntax unified\n\
  push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldrh r2, [r4]\n\
	strh r2, [r4, #2]\n\
	cmp r1, #0\n\
	beq _0800315E\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	b _080031D2\n\
_0800315E:\n\
	movs r0, #1\n\
	strh r0, [r4, #8]\n\
	ldr r0, _080031AC @ =0x04000130\n\
	ldrh r0, [r0]\n\
	mvns r0, r0\n\
	strh r0, [r4]\n\
	bics r0, r2\n\
	strh r0, [r4, #4]\n\
	strh r1, [r4, #6]\n\
	movs r1, #0\n\
	movs r7, #1\n\
	adds r6, r4, #0\n\
	adds r6, #0xa\n\
_08003178:\n\
	ldrh r2, [r4]\n\
	lsls r0, r1, #0x10\n\
	asrs r3, r0, #0x10\n\
	asrs r2, r3\n\
	ands r2, r7\n\
	adds r5, r0, #0\n\
	cmp r2, #0\n\
	beq _080031C0\n\
	adds r2, r6, r3\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	cmp r0, #0\n\
	bne _080031B4\n\
	adds r0, r7, #0\n\
	lsls r0, r3\n\
	ldrh r1, [r4, #6]\n\
	orrs r0, r1\n\
	strh r0, [r4, #6]\n\
	ldrh r0, [r4, #4]\n\
	asrs r0, r3\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _080031B0\n\
	ldrb r0, [r4, #0x14]\n\
	b _080031B2\n\
	.align 2, 0\n\
_080031AC: .4byte 0x04000130\n\
_080031B0:\n\
	ldrb r0, [r4, #0x15]\n\
_080031B2:\n\
	strb r0, [r2]\n\
_080031B4:\n\
	asrs r1, r5, #0x10\n\
	adds r1, r6, r1\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	b _080031C4\n\
_080031C0:\n\
	adds r0, r6, r3\n\
	strb r2, [r0]\n\
_080031C4:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r5, r1\n\
	lsrs r1, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #9\n\
	ble _08003178\n\
_080031D2:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
              .syntax divided\n");
}

static void resetKeyState(struct KeyState *p) {
  p->firstRead = 0;
  p->field3_0x6 = 0;
  p->pressed = 0;
  p->last = 0;
  p->input = 0;
  *(u32 *)(&p->unk_0a[0]) = *(u32 *)(&p->unk_0a[4]) = 0;
  *(u16 *)(&p->unk_0a[8]) = 0;
}
