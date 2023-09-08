#ifndef GUARD_RMZ3_MMBN4_H
#define GUARD_RMZ3_MMBN4_H

#include "constants/constants.h"
#include "types.h"

// 0x02030b54
struct UnkMmbn4 {
  u32 unk_00;
  u8 _[8];
};

struct Unk_02000d50 {
  u8 unk_00;
  u8 unk_01;
  u8 unk_02;
  u8 unk_03;
  u8 unk_04[6];
  u16 unk_0a;
  u16 unk_0c;
  u16 unk_0e;
  u16 unk_10[6];
  u32 unk_1c;
  u32 unk_20;
  u32 unk_24;
  u32 unk_28;
  u32 unk_2c;
  u32 unk_30;
  u32 unk_34;
  u32 unk_38;
  u32 unk_3c;
  u32 unk_40;
  u32 unk_44;
  u32 unk_48;
  u32 unk_4c;
  u32 unk_50;
  u32 unk_54;
};

struct Unk_080006c8 {
  void* a;
  void* b;
  void* c;
  u8 d;
  u8 _[3];
};

extern struct UnkMmbn4 gUnkMmbn4;
extern struct Unk_02000d50 gUnk02000d50;

void sio_0800100c(void);
void sio_0800133c(void);
u8 sio_080013a8(void);
u8 sio_080013d0(void);
u8 sio_080013f0(void);
u8 sio_08001410(void);
void sio_080014ec(void);
u16 sio_08001514(void);
void sio_08001538(void);
u8 sio_08001570(void);
u8 sio_080015e8(void);
void sio_08001778(void);
void FUN_08000eac(u32 r0, u32 r1, u32 r2);

#endif  // GUARD_RMZ3_MMBN4_H
