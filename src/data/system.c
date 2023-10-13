#include "gba/gba.h"
#include "global.h"
#include "sram.h"

void ReadSram_Core(const u8* src, u8* dest, u32 size);
void VerifySram_Core(const u8* src, u8* dest, u32 size);
void HBlankIntr1(void);
void HBlankIntr2(void);
void FUN_08002110(void);

const u8 SRAM_VERSION[] = "SRAM_V113";

const ALIGNED(4) sramFunc Jt_08338c80[4] = {
    ReadSram_Core,
    ReadSram,
    VerifySram_Core,
    (sramFunc)VerifySram,
};

const VoidFunc HBlankIntrs[4] = {
    NULL,
    HBlankIntr1,
    HBlankIntr2,
    FUN_08002110,
};

/*
  Process の sp
    0: 0x03001760 + 0x04e0 = 0x3001c40
    1: 0x03001760 + 0x0de0 = 0x3002540
    2: 0x03001760 + 0x12e0 = 0x3002a40
*/
const u16 gProcessStackPointerOffsets[3] = {
    0x3001c40 - 0x03001760,
    0x3002540 - 0x03001760,
    0x3002a40 - 0x03001760,
};

static const ALIGNED(4) u8 sBuildDateTime[] = "Mar 20 2004 01:33:22";

const saveFunc gSramRoutine[3] = {
    nop_080033d4,
    saveSram,
    loadSram,
};
