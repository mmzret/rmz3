#include "overworld.h"
#include "zero.h"

void ClearInputHistory(struct Zero *z) {
  s32 i;
  for (i = 0; i < ARRAY_COUNT(z->inputHistory); i++) {
    z->inputHistory[i] = 0;
  }
}

void handlePlayerInput(struct Zero *z) {
  s32 i = ARRAY_COUNT(z->inputHistory) - 1;
  struct StageRun *s = &gStageRun;
  KEY_INPUT *history = &z->inputHistory[0];

  /*
    history[63] = history[62];
    history[62] = history[61];
    ...
    history[2] = history[1];
    history[1] = history[0];
  */
  for (; i != 0; i--) {
    history[i] = history[i - 1];
  }

  history[0] = s->input & 0x0FFF;
  z->pressed = (z->last ^ s->input) & s->input;
  z->last = s->input;
}
