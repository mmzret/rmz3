#ifndef GUARD_RMZ3_TRIG_H
#define GUARD_RMZ3_TRIG_H

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

#define SIN(index) (gSineTable[(u8)(index)])
#define COS(index) (gSineTable[(u8)(index + 64)])

#define SINX(index, amplitude) ((amplitude * gSineTable[index]))
#define COSX(index, amplitude) ((amplitude * gSineTable[(u8)(index + 64)]))

extern const s16 gSineTable[256];

static inline s32 Sin(u8 index, s32 amplitude) {
  s32 val = SINX(index, amplitude);
  if (val < 0) {
    val += 0xFF;
  }
  return (val >> 8);
}

static inline s32 Cos(u8 index, s32 amplitude) {
  s32 val = COSX(index, amplitude);
  if (val < 0) {
    val += 0xFF;
  }
  return (val >> 8);
}

#endif  // GUARD_RMZ3_TRIG_H
