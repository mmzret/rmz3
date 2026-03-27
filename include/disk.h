#ifndef GUARD_RMZ3_DISK_H
#define GUARD_RMZ3_DISK_H

#include "gba/gba.h"

void clearSecretDiskData(u8* flagbits);
void clearSecretDiskDataHard(u8* flagbits);
void unlockAllSecretDisk(u8* flagbits);

#endif  // GUARD_RMZ3_DISK_H
