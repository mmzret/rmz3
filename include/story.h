#ifndef GUARD_RMZ3_STORY_H
#define GUARD_RMZ3_STORY_H

#include "common.h"
#include "gba/gba.h"
#include "types.h"

// Story.id
#define STAGE_DONE (1 << 5)

// PlayInfo.missionDones
#define SPACE_CRAFT (1 << 1)
#define FIRST4 0x3C  // First 4 missions
#define MISSILE_FACTORY (1 << 6)
#define MEDIUM3 0x380  // Medium 3 missions
#define AREA_X2 0x400
#define LATER4 0x7800
#define SUB_ARCADIA 0x8000

#define ENEMY_KILLCOUNT(n) (gCurStory.s.counts[29 + n])

#define FLAG(gameflags, n) (gameflags[n >> 3] & (1 << (n & 7)))
#define SET_FLAG(gameflags, n) (gameflags[n >> 3] |= (1 << (n & 7)))
#define CLEAR_FLAG(gameflags, n) (gameflags[n >> 3] &= ~(1 << (n & 7)))

#define IS_MISSION (!FLAG(gCurStory.s.gameflags, IS_FREERUN))
#define IS_METTAUR (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED))

// --------------------------------------------

struct PlayInfo {
  u8 extraLife;
  u8 rank;
  u8 codenameSuffix;
  u8 pad_03;
  u8 codenamePrefix;
  u8 pad_05;
  bool8 allElfCompleted;  // エルフを全種類捕まえているか(育てているかは無関係)

  /*
    bit0: 全部のエルフを育てきってるか(称号エルフブリーダーの条件を満たしているか)
    bit4: 全てのシークレットディスクを取得している(解析の有無は問わない)
  */
  u8 collectFlag;

  u8 clearCodenameSuffix;  // ストーリークリア時に適用される
  u8 clearCodenamePrefix;  // ストーリークリア時に適用される

  u16 scoreSum;         // 今までクリアしたステージのスコアの合計
  u32 playTime;         // フレーム単位のプレイ時間
  u8 clearCount;        // 今までクリアしたステージの数
  u8 unusedClearCount;  // clearCountと全く同じ内容
  u8 unk_12;
  u8 lastStage;            // 最後にクリアしたステージ 根拠: 08019794
  u32 missionDones;        // クリア済みミッション を表すbitfield
  u32 unusedMissionDones;  // missionDonesと全く同じ内容
  u32 unk_1c;
  u8 unk_20[20];
  u8 suffixIdx[8];  // 0834c9e0 の2つ目のidx(0..7)
  u8 unk_3a[16];
  u8 fusionCount;  // フュージョンエルフを使った回数 リザルトのエルフ使用回数に反映されるが、減点には反映せず
  u8 _[3];
};  // 80 bytes

struct Story {
  u16 id;  // stage ID
  u16 pad_02;
  u8 gameflags[8];
  /*
    0..28: 会話の進行度
    29..69: 雑魚敵の種類ごとの撃破数
    70..71: 火山のリコイルで動かす棺桶みたいなコンテナの移動量
  */
  u8 counts[29 + 41 + 2];  // chatProgress[29] + zakoCounts[41] + volcanoCoffinX[2]
};                         // 84 bytes

// 0202fdc0
struct Story96 {
  struct Story s;
  u8 unk_54;
  u8 ALIGNED(1) _[11];
};  // 96 bytes

// --------------------------------------------

extern struct Story96 gCurStory;

// --------------------------------------------

void saveCurStory(struct Story* dst);
void resetCurStory(u8 stageID, struct Story* src);
void FUN_08019678(struct Story* p);
void ClearPlayInfo(struct PlayInfo* p);

#endif  // GUARD_RMZ3_STORY_H
