#include "overworld.h"
#include "zero.h"

void ClearInputHistory(struct Zero *z) {
  s32 i;
  for (i = 0; i < ARRAY_COUNT(z->inputHistory); i++) {
    z->inputHistory[i] = 0;
  }
}

WIP void handlePlayerInput(struct Zero *z) {
#if MODERN
  s32 i;
  KEY_INPUT input;
  for (i = ARRAY_COUNT(z->inputHistory) - 1; i != 0; i--) {
    z->inputHistory[i] = z->inputHistory[i - 1];
  }
  input = gStageRun.input;
  z->inputHistory[0] = input & 0x0FFF;
  z->pressed = (z->last ^ input) & input;
  z->last = input;
#else
  INCCODE("asm/wip/handlePlayerInput.inc");
#endif
}
