#include "game.h"
#include "gba/gba.h"

typedef void (*f)(struct GameState *);

extern f DiskAnalysisScripts[];
void sd_analysis_080f8408(struct GameState *);

void diskAnalysisScript(struct GameState *s) {
  DiskAnalysisScripts[s->mode](s);
  sd_analysis_080f8408(s);
  return;
}
