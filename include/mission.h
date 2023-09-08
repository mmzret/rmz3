#ifndef GUARD_RMZ3_MISSION_H
#define GUARD_RMZ3_MISSION_H

#include "game.h"

// 現在進行中のミッションの状況 0202fe20
struct Mission {
  struct PlayInfo* unk_00;
  u8 currentStageID;
  u8 currentStageScore;
  u8 unk_06;

  // Current mission evaluation
  u8 missionPoint;  // 0~20
  u32 clearTime;    // Frame
  u16 enemyCount;
  u16 totalDamage;
  u32 elfPenalty;  // エルフの使った数じゃなくて、エルフ使用による永続的な減点
  u16 retryCount;

  /*
    Current mission score (each is in 0..20)
      0: mission
      1: clear time
      2: enemy count
      3: total damage
      4: retry count
      5: elf
  */
  u8 resultScore[6];
  u16 weaponCount[4];  // Weapon use count (buster, saber, rod, shield)
  u8 _[12];
};  // 48 bytes

// 見たところ使われていなさそう
struct Unused_0202fe50 {
  u16 unk_00;
  u16 unk_02;
  u32 unk_04;
  u8 _[8];
};

typedef void (*Unk0834cc60Func)(struct Unused_0202fe50*);

extern struct Mission gMission;
extern struct Unused_0202fe50 gUnk_0202fe50;

void InitMissionInfo(u8 stageID, struct PlayInfo* p);
void AddMissionDamage(u16 damage);

#endif  // GUARD_RMZ3_MISSION_H
