#ifndef GUARD_RMZ3_BLINK_H
#define GUARD_RMZ3_BLINK_H

#include "gba/gba.h"
#include "motion.h"

#define BLINK_LENGTH 16
#define BLINK_NUM 280

// 0x02002000
struct Blink {
  struct MotionPltt *pal;
  struct MotionCmd **cmds;
  struct Motion m;
  bool16 paused;
  u16 palIdx;
};  // 20 bytes;

struct BlinkManager {
  u16 ids[BLINK_LENGTH];  // wBlinks(02002000)のうち、点滅処理を行うもののBlinkID(=085be764のidx)
  struct Blink blinks[BLINK_LENGTH];
};

// --------------------------------------------

extern struct BlinkManager gBlinkManager;

// --------------------------------------------

void ClearBlink(u16 n);
void LoadBlink(u16 blinkID, u16 ofs);
u32 UpdateBlinkMotionState(u16 blinkID);
void ClearBlinkings(void);
void ExecBlink(void);
void PauseAllBlinks(void);
void ResumeAllBlinks(void);

#endif  // GUARD_RMZ3_BLINK_H
