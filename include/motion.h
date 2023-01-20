#ifndef GUARD_RMZ3_MOTION_H
#define GUARD_RMZ3_MOTION_H

typedef u8 ActionID;

struct __attribute__((packed, aligned(2))) Action {
  u8 motion;
  ActionID id;
};  // 2bytes;

struct __attribute__((packed, aligned(2))) Koma {
  u8 idx;
  u8 frame;
};  // 2 bytes;

struct Shiori {
  u8 idx1;
  u8 idx2;
  u8 frame;
  u8 koma;  // 現在のKoma
};          // 4 bytes;

struct Motion {
  /*
    tbl[shiori.idx1][shiori.idx2];
    e.g. 0x085d3140
  */
  struct Koma **tbl;
  struct Shiori shiori;
};  // 8 bytes;

// e.g. 0x085ba244
struct MotionPltt {
  u8 len;
  u8 start;
  u8 end;
  u8 padding;

  // u16 pltt[len*n]; n = 次の MotionPltt構造体までの長さによって変動
};  // 4 bytes;

// 0x02002000
struct Film {
  struct MotionPltt *pal;
  struct Koma **tbl;
  struct Motion m;
  bool16 paused;
  u16 palIdx;
};  // 20 bytes;

/*
  0x02001fe0

  wBlinks[i]:
    0:   空エントリ
    N+1: BlinkID Nが設定 (BlinkID: 0x085be764 のidx)
*/
extern u16 wBlinks[16];

extern struct Film wFilms[16];  // 0x02002000

#endif  // GUARD_RMZ3_MOTION_H
