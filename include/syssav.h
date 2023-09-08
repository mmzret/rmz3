#ifndef GUARD_RMZ3_SYSTEM_SAVE_H
#define GUARD_RMZ3_SYSTEM_SAVE_H

#include "constants/constants.h"
#include "gba/gba.h"
#include "types.h"

enum SramHealth {
  SRAM_NEUTRAL = 0,
  DATA_OK = 0,
  DATA_BROKEN = 0xFFFF,
};

struct SaveSlotInfo {
  bool8 ok[SAVE_SLOT + 1];                 // 0x0200_05f8
  u32 ALIGNED(4) playtime[SAVE_SLOT + 1];  // 0x0200_0600
  u32 ALIGNED(4) rank[SAVE_SLOT];          // 0x0200_0618
  u8 ALIGNED(4) lap[SAVE_SLOT + 1];        // 0x0200_062c 周回数
  u8 ALIGNED(4) gamemode[SAVE_SLOT + 1];   // 0x0200_0634
  u32 _;
};  // 72 bytes

struct SaveHeader {
  u8 INTI[4];  // マジックナンバ INTI
  u32 checksum;
  u32 size;
  u8 unk_c;  // 0x0B で固定
  u8 pad_d;
  u8 idx;  // セーブデータの番号(0..4)
  u8 _;
};  // 16 bytes

/**
 * @note ミニゲームの時はここにハイスコアなどのセーブデータが保存される
 * @note 0x020021b0 (En: 0x02002430)
 */
struct SystemSavedataManager {
  u8 flags[7];  // bitfield * 7 = 56 flags
  /*
    0: ???
    1:
      bit 0: ベースに鉢植えが置かれる
      bit 1: Saber atk +1
      bit 2: Pantheon Guardian HP +4
      bit 3: Pantheon Hunter HP +4
      bit 4: Nurse Elf looks
      bit 5: 52ECくれるレプリロイドがベースに出現
    2:
      bit 0: ???
      bit 1: Alouette dress
      bit 2: Archim atk +1
      bit 3: Zero damage 1/2
    3:
      bit 0: 152ECくれるレプリロイドがベースに出現
      bit 1: Rod atk +1
      bit 2: Orange cat
      bit 3: Shield atk +1
      bit 4: Bee elf atk +1
    4:
      bit 0: ???
      bit 1: Pnahtom cyberelf
      bit 2: Buster atk +1
      bit 3: Poster
      bit 4: Andrew room 1UP
      bit 5: Buster atk +2
      bit 6: 80ECくれるレプリロイドがベースに出現
    5:
      bit 0: ???
      bit 1: Flower
      bit 2: ???
      bit 3: Animal Elf looks
      bit 4: Andrew make younger
      bit 5: Archim atk +2
      bit 6: Seagulls
      bit 7: Tabby cat
    6:
      bit 0: Bee elf atk +2
      bit 1: ???
      bit 2: Shield atk +2
      bit 3: ???
      bit 4: Grafitti
      bit 5: ???
      bit 6: 100ECくれるレプリロイドがベースに出現
      bit 7: Rod atk +2
    7:
      bit 3: ベースの右の塔にいるキャラとの会話が変わる
      bit 4: 32EC(Room 2B)
      bit 6: 52EC(Room 2C)
      bit 7: 52EC(2F)
    8:
      bit 1: Elpizo cyberelf
      bit 3: Shield atk +3
      bit 4: ベースの左の塔にいるキャラとの会話が変わる
      bit 7: Bee elf atk +3
    9:
      bit 0: Archim atk +3
      bit 1: Hacker Elf looks
      bit 2: Crossbyne HP +4
      bit 3: Pantheon Base HP +4
      bit 4: Buster atk +3
    10:
      bit 0: Pantheon Aqua HP +4
      bit 2: Lilies
      bit 4: Fish
      bit 5: Rod atk +3
      bit 6: 32EC(Room 3A)
      bit 7: 52EC(Room 3B)
    11:
      bit 0: Archim atk +4
      bit 1: Saber atk +2
      bit 2: 40EC(Room 3C)
      bit 3: Pantheon Bomber HP +4
      bit 4: 32EC(3F)
      bit 5: 52EC(Room 3D)
      bit 6: Pantheon Aqua Mod HP +16
      bit 7: ???
    12:
      bit 1: Saber atk +3
      bit 3: Purple Nerple HP +4
      bit 4: Shell Crawler HP +4
      bit 5: Icebon HP +4
      bit 6: Generator Cannon HP +4
      bit 7: Claveker HP +4
    13:
      bit 0: Shotcounter HP +4
      bit 1: Grand Cannon HP +4
      bit 2: Shrimporin HP +4
      bit 3: Batring HP +4
      bit 4: PCannon HP +4
      bit 5: Volcaire HP +4
      bit 6: Snakecord HP +4
      bit 7: Lemmingles HP +4
    14:
      bit 0: Lamplort HP +4
      bit 1: Tile Cannon HP +4
      bit 2: Shelluno HP +4
      bit 3: Heavy Cannon HP +4
      bit 4: Mothjiro HP +4
      bit 5: CCannon HP +4
      bit 6: CalibeeG HP +16
      bit 7: Deathlock HP +4
    15:
      bit 0: Gyro Cannon HP +4
      bit 1: SharksealX HP +4
      bit 2: OlWormer HP +16
      bit 3: BranWormer HP +16
      bit 4: LocomoIF HP +16
      bit 5: BeeServer HP +16
      bit 6: Megamilpa HP +16
  */
  u8 mods[16];
  u8 unk_17;

  /*
    0x00: Locked
    0x31: Unlocked
  */
  u8 hardmodeLock;
  /*
    0x00: Locked
    0x38: Unlocked
  */
  u8 ultimateModeLock;
  u8 unlockedMinigames[7];
  u8 pad_21[3];
  u32 minigameHiscores[7];
  u32 mmbn4;  // ロックマンエグゼ4との通信で変化

  // 0: Default
  u8 msgbox;        // 1..8
  u8 title;         // 1..3: Zero, 4: Ciel
  u8 elevator;      // 1: Wood, 2: MMX
  u8 weather;       // 1: Night, 2: Snowy
  u8 cielComputer;  // 1..4
  u8 lifeEnergy;    // 1: Blue Orbs, 2: Flashing Square
  u8 crystal;       // 1: Orbs, 2: Green
  u8 disk;          // 1: Blue, 2: Red
  u8 extraLife;     // 1: Blue, 2: Green
  u8 bullet;        // 1: Black, 2: Realistic

  u16 _;
};  // 80 bytes

extern struct SystemSavedataManager gSystemSavedataManager;
extern struct SaveSlotInfo gSaveSlotInfo;

void LoadSystemData(void);
void SaveSystemData(void);
void ToggleMods(mod_t id);
void PrintSaveDataRow(s32 idx, u8 rank, u32 playTime, u8 playLaps, u32 mode, u8 y);

#endif  // GUARD_RMZ3_SYSTEM_SAVE_H
