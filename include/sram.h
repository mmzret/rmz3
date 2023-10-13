#ifndef GUARD_RMZ3_SRAM_H
#define GUARD_RMZ3_SRAM_H

#include "types.h"

struct SramState {
  u8 unk_00;
  u8 slot;
  u8 status;
  u8 busStatus;
  s16 retryCount;
  u16 useBackup;  // +0x3ffc 版を使う 080033d8 でセットされる
  u8* start;      // 例: 0x02036dbc ここからメインのセーブデータ
  u8* wramAddr;   // wramStartから始まって処理と共に増える
  u8* sramAddr;   // セーブデータのある場所
  s32 length;     // SRAMの全体サイズ
  u32 remaining;  // lengthから始まってセーブが進むにつれて減っていく
  s16 unk_1c;
  u16 health;
};  // 32 bytes

typedef void (*sramFunc)(const u8* src, u8* dest, u32 size);
typedef void (*saveFunc)(struct SramState* s);

extern struct SramState gSramState;
extern const saveFunc gSramRoutine[3];

void UpdateSram(void);
bool32 CheckSavedataCorrect(u8 saveIdx, s32 length);
s32 WriteSramINTI(u8 saveIdx);
s32 sram_08003330(u8 saveIdx, u8* dst, u32 length);
s32 sram_08003378(u8 saveIdx, u8* dst, u32 length);

void nop_080033d4(struct SramState* _);
void saveSram(struct SramState* s);
void loadSram(struct SramState* s);

#endif  // GUARD_RMZ3_SRAM_H
