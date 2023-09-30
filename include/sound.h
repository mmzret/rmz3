#ifndef GUARD_RMZ3_SOUND_H
#define GUARD_RMZ3_SOUND_H

#include "gba/defines.h"
#include "gba/m4a.h"
#include "sound_wave.h"
#include "types.h"

extern SoundID SoundID1;
extern SoundID SoundID2;
extern u32 gSongCount;

extern struct MusicPlayerInfo gMPlayInfo_00;
extern struct MusicPlayerInfo gMPlayInfo_01;
extern struct MusicPlayerInfo gMPlayInfo_02;
extern struct MusicPlayerInfo gMPlayInfo_03;
extern struct MusicPlayerInfo gMPlayInfo_04;
extern struct MusicPlayerInfo gMPlayInfo_05;
extern struct MusicPlayerInfo gMPlayInfo_06;
extern struct MusicPlayerInfo gMPlayInfo_07;
extern struct MusicPlayerInfo gMPlayInfo_08;
extern struct MusicPlayerInfo gMPlayInfo_09;
extern struct MusicPlayerInfo gMPlayInfo_10;
extern struct MusicPlayerInfo gMPlayInfo_11;
extern struct MusicPlayerInfo gMPlayInfo_12;
extern struct MusicPlayerInfo gMPlayInfo_13;
extern struct MusicPlayerInfo gMPlayInfo_14;

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
