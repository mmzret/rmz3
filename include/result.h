#ifndef GUARD_RMZ3_RESULT_H
#define GUARD_RMZ3_RESULT_H

#include "entity.h"
#include "global.h"

struct ResultState {
  u8 unk_00[4];
  u16 frame;
  u16 unk_06;
  u16 unk_08;
  u16 unk_0a;
  u32 unk_0c;
  u32 rank;
  void* vfx;
  u8 codenamePrefix;
  u8 codenameSuffix;
  u16 unk_1a;
  u8 unk_1c[8];
  struct Widget* w;
  u8 unk_28[216];
};

// ------------------------------------------------------------------------------------------------------------------------------------

void PrepareResultScreen(struct ResultState* p);
bool32 result_0802400c(struct ResultState* p);

#endif  // GUARD_RMZ3_RESULT_H
