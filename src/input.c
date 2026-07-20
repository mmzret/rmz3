#include "input.h"

#include "gba/gba.h"

static void resetKeyStates(void);
static void readKeyInput(struct KeyState *j, s32 retry);
static void resetKeyState(struct KeyState *j);

void InitInput(void) {
  resetKeyStates();
  PollKeyInput();
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

void PollKeyInput(void) {
  s32 retry = 0;
  struct KeyState *j = gJoypad;

  for (retry = 0; retry < 2; retry++) {
    readKeyInput(j, retry);
    j = j + 1;
  }
}

static void readKeyInput(struct KeyState *j, s32 retry) {
  s16 i;
  s64 pressed;

  j->last = j->input;
  if (retry != 0) {
    j->firstRead = 0;
    return;
  }
  j->firstRead = 1;
  j->input = ~REG_KEYINPUT;
  j->pressed = j->input & ~j->last;
  j->field3_0x6 = 0;
  for (i = 0; i < 10; i++) {
    if ((j->input >> i) & 1) {
      if ((s8)j->unk_0a[i] == 0) {
        j->field3_0x6 |= 1 << i;
        pressed = j->pressed >> i;
        j->unk_0a[i] = (pressed & 1) ? j->field6_0x14 : j->field7_0x15;
      }
      j->unk_0a[i]--;
    } else {
      j->unk_0a[i] = 0;
    }
  }
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
