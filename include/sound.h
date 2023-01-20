#ifndef GUARD_RMZ3_SOUND_H
#define GUARD_RMZ3_SOUND_H

#include "gba/gba.h"
#include "gba/m4a.h"

typedef u16 SoundID;
typedef u32 SoundID32;

bool32 _isSoundPlaying(SoundID32);

#endif  // GUARD_RMZ3_SOUND_H
