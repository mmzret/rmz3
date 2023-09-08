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

// Story.elfFlags
#define PUTITE_ENABLED (1 << 0)     // 一撃死予防
#define ARMOR_ELF_ENABLED (1 << 1)  // キーナイト系
#define GIANT_ELF_ENABLED (1 << 2)  // ハンマーガ系
#define TIME_ELF_ENABLED (1 << 3)   // ストパーラ系
#define ELF_B4_ENABLED (1 << 4)
#define DYLPHINA_ENABLED (1 << 5)
#define METTAUR_ENABLED (1 << 6)
#define BYSE_ENABLED (1 << 7)

// Story.f0
#define STORY_HARD (1 << 0)
#define STORY_ULTIMATE (1 << 1)
#define STORY_F0_B2 (1 << 2)
#define STORY_F0_B3 (1 << 3)
#define STORY_CYBER (1 << 4)
#define STORY_CLEAR (1 << 5)
#define STORY_DEMO (1 << 6)

// Story.f1
#define STORY_F1_B3 (1 << 3)  // わかったわ...
#define STORY_F1_B4 (1 << 4)  // じゃあせめて
#define STORY_F1_B7 (1 << 7)

// Story.f2
#define NO_HARPUIA (1 << 0)
#define SUNKEN_ANALYZE (1 << 2)  // ディスク解析中
#define BRAIN_CONTROL (1 << 4)   // オメガによる洗脳
#define WEIL_LABO (1 << 5)       // バイル研究所突撃

#define ENEMY_KILLCOUNT(n) (gCurStory.s.flags[29 + n])

#define IS_MISSION (!(gCurStory.s.f0 & STORY_CLEAR))
#define IS_METTAUR (gCurStory.s.elfFlags & METTAUR_ENABLED)

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

  /*
    bit0: Hard mode
    bit1: Ultimate mode
    bit4: In Cyberspace
    bit5: Is current stage already cleared?
    bit6: Is Demo play?
  */
  u8 f0;

  /*
    シエルのチャットフラグ？
      0x02: シミュレーションの結果が出るまで...
      0x03: 待たせちゃったわねゼロ 準備はいい？
      0x07: 平常時
      0x08: わかったわ...
      0x10: じゃあせめて
  */
  u8 f1;

  /*
    bit0: ハルピュイアいない時
    bit2: ディスク解析中
    bit4: シエルに話すと、ヨウセイ戦争のファイル -> バイル洗脳 -> アンダーアルカディア
    bit5: バイル研究所突撃
  */
  u8 f2;

  u8 bossRush;  // ボスラッシュ撃破フラグ
  u8 elfFlags;

  /*
    .f5
    bit0:    Rank A elf (エワーネ系エルフが働いている)
    bit1..4: Ocean Button 0~3 is pressed (Bit1: Button 0, .. Bit 4: Button 3)
  */
  u8 unk_09;

  /*
    bit2: Buster only (今のところバスターのみ使用している)
    bit3: Buster only (今のところセイバーのみ使用している)
  */
  u8 unk_0a;
  u8 unk_0b;
  /*
    0..28: 会話の進行度
    29..69: 雑魚敵の種類ごとの撃破数
    70..71: 火山のリコイルで動かす棺桶みたいなコンテナの移動量
  */
  u8 flags[29 + 41 + 2];  // chatProgress[29] + zakoCounts[41] + volcanoCoffinX[2]
};                        // 84 bytes

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

static inline bool8 IsDemoplay() { return gCurStory.s.f0 & STORY_DEMO; }

#endif  // GUARD_RMZ3_STORY_H
