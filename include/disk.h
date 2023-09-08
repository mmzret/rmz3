#ifndef GUARD_RMZ3_DISK_H
#define GUARD_RMZ3_DISK_H

#include "game.h"
#include "gba/gba.h"

typedef void (*DiskLoopFunc)(struct GameState*);

void sd_analysis_080f85e0(struct GameState* p);
void sd_analysis_080f875c(struct GameState* p);
void sd_analysis_080f8984(struct GameState* p);

void DiskLoop_Run(struct GameState* p);
void DiskLoop_BlackOut(struct GameState* p);
void DiskLoop_Exit(struct GameState* p);

void clearSecretDiskData(u8* p);
void clearSecretDiskDataHard(u8* p);
void unlockAllSecretDisk(u8* p);

#endif  // GUARD_RMZ3_DISK_H
