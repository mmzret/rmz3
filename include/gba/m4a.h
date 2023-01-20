#ifndef GUARD_GBA_M4A_H
#define GUARD_GBA_M4A_H

#include "gba/m4a_internal.h"

void m4aSoundInit(void);
void m4aMPlayAllStop(void);
void m4aSoundMain(void);
void m4aSongNumStart(u16);
void m4aSoundVSync(void);
void m4aMPlayFadeOut(struct MusicPlayerInfo *, u16);
void m4aSongNumStop(u16);

#endif  // GUARD_GBA_M4A_H
