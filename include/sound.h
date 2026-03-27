#ifndef GUARD_RMZ3_SOUND_H
#define GUARD_RMZ3_SOUND_H

#include "gba/defines.h"
#include "gba/m4a.h"
#include "sound_wave.h"
#include "types.h"

extern SoundID SoundID1;
extern SoundID SoundID2;
extern u32 gSongCount;

extern struct MusicPlayerTrack gMPlayTracks[21];

extern const struct Song gSongTable[336];

extern const struct ToneData voicegroup000[128];
extern const struct ToneData voicegroup001[128];
extern const struct ToneData voicegroup002[122];

void InitSound(void);
void StopAllMusics(void);
void TurnDownBGM(void);
void TurnUpBGM(void);
void playBGM(SoundID n);
void fadeoutBGM(SoundID n);
bool32 _isSoundPlaying(SoundID n);
s16 PlaySound(SoundID id);
void stopSound(s16 n);
void fadeoutSound(s16 r0, u16 r1);
bool32 isSoundPlaying(SoundID n);
void SetStageNoiseVolume(SoundID n);

#endif  // GUARD_RMZ3_SOUND_H
