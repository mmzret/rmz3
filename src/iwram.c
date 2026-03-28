#include "gba/gba.h"

struct SoundInfo;

IWRAM_DATA u8 StackUsr[1200] = {};

// Reserved (0x03007F00..)

IWRAM_DATA u8 StackIrq[160] = {};
IWRAM_DATA u8 StackSvc[64] = {};
IWRAM_DATA u8 Unk_03007fe0[16] = {};
IWRAM_DATA struct SoundInfo* SOUND_INFO_PTR = NULL;
IWRAM_DATA u8 AllocatedArea_03007ff4[4] = {};
IWRAM_DATA u16 INTR_CHECK = 0;
IWRAM_DATA u16 unused_03007ffa = 0;
IWRAM_DATA void* INTR_VECTOR = NULL;
