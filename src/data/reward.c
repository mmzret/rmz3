#include "reward.h"

#include "global.h"

// 0x0835dba8

#define STAGE_CHIP_NONE 0
#define STAGE_CHIP_BODY 2
#define STAGE_CHIP_FOOT 3

// clang-format off

// ステージクリアしたときの報酬としてもらえるチップ
const u8 StageChipTypes[STAGE_COUNT] = {
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_BODY,
    STAGE_CHIP_BODY,
    STAGE_CHIP_BODY,
    STAGE_CHIP_BODY,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_BODY,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
};

// clang-format on

// StageChipTypes[i] が BODY, StageChipIDs[i] が4 ならBODYの4 つまり フレイムチップ
const u8 StageChipIDs[STAGE_COUNT] = {
    0, 0, 4, 5, 3, 1, 0, 0, 0, 0, 4, 2, 5, 3, 2, 0, 0, 0,
};

const TextID UnlockEquipTextIDs[STAGE_COUNT] = {
    0x0000, 0x0000, 0x0118, 0x0117, 0x0119, 0x0116, 0x0000, 0x0000, 0x0000, 0x0000, 0x011E, 0x011C, 0x011D, 0x011B, 0x011A, 0x0000, 0x0000, 0x0000,
};

// clang-format off
const u32 StageRewardExSkills[STAGE_COUNT] = {
    EXSKILL_ID_NONE,
    EXSKILL_ID_NONE,
    EXSKILL_ID_BURST,
    EXSKILL_ID_THROW,
    EXSKILL_ID_SMASH,
    EXSKILL_ID_THOUSAND,
    EXSKILL_ID_NONE,
    EXSKILL_ID_SWEEP,
    EXSKILL_ID_SPLIT,
    EXSKILL_ID_BLIZZ,
    EXSKILL_ID_LASER,
    EXSKILL_ID_SOUL,
    EXSKILL_ID_ORBIT,
    EXSKILL_ID_VSHOT,
    EXSKILL_ID_GALE,
    EXSKILL_ID_NONE,
    EXSKILL_ID_NONE,
    EXSKILL_ID_NONE,
};
// clang-format on

const TextID UnlockExSkillTextIDs[STAGE_COUNT] = {
    0x0000, 0x0000, 0x010C, 0x010B, 0x010D, 0x010A, 0x0000, 0x0113, 0x010F, 0x010E, 0x0111, 0x0114, 0x0110, 0x0115, 0x0112, 0x0000, 0x0000, 0x0000,
};

// clang-format off

// MapItemDropRates[確率テーブル][itemID]
const u16 MapItemDropRates[9][7] = {
    { 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x00A0, 0x00E0, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x0080, 0x0000, 0x0000, 0x0000, 0x00E0, 0x0100, 0x0000 },
    { 0x0060, 0x00A0, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000 },
    { 0x006B, 0x009F, 0x00AF, 0x0000, 0x00EF, 0x00FF, 0x0100 },
    { 0x0000, 0x0060, 0x007F, 0x0000, 0x00DF, 0x00FF, 0x0100 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100 },
    { 0x0000, 0x00E0, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000 },
};
// clang-format on

const u8 MiddleBossDiskNo[8] = {
    DISK_ELF_ILETHAS, DISK_ELF_HANMARBO, DISK_ELF_ARCHIL, DISK_ELF_ANATER, DISK_ELF_KYNITE, DISK_TOP_GABYOALL, DISK_ULTIMA_FOOT, DISK_ELF_HANMARJI,
};

const ALIGNED(2) struct DiskDrop EnemyDiskDrops[42] = {
    // Space Craft
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 29,
      type : ENTITY_ENEMY,
      id : ZAKO_GRAND_CANNON,
      unk_0a : 0xFFFF,
      count : 5,
      diskNo : DISK_GRAND_CANNON,
    },
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 30,
      type : ENTITY_ENEMY,
      id : ZAKO_SHRIMPORIN,
      unk_0a : 0xFFFF,
      count : 3,
      diskNo : DISK_SHRIMPOLIN,
    },
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 31,
      type : ENTITY_ENEMY,
      id : ZAKO_BATRING,
      unk_0a : 0xFFFF,
      count : 4,
      diskNo : DISK_BATRING,
    },
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 32,
      type : ENTITY_ENEMY,
      id : ZAKO_SHOTCOUNTER,
      unk_0a : 0xFFFF,
      count : 4,
      diskNo : DISK_SHOTCOUNTER,
    },

    // Volcano
    {
      stageID : STAGE_VOLCANO,
      stageID2 : STAGE_VOLCANO,
      zakoOfs : 33,
      type : ENTITY_ENEMY,
      id : ZAKO_VOLCAIRE,
      unk_0a : 0xFFFF,
      count : 3,
      diskNo : DISK_VOLCAIRE,
    },
    {
      stageID : STAGE_VOLCANO,
      stageID2 : STAGE_VOLCANO,
      zakoOfs : 34,
      type : ENTITY_ENEMY,
      id : ZAKO_LAMPLORT,
      unk_0a : 0xFFFF,
      count : 4,
      diskNo : DISK_LAMPLORT,
    },
    {
      stageID : STAGE_VOLCANO,
      stageID2 : STAGE_VOLCANO,
      zakoOfs : 35,
      type : ENTITY_ENEMY,
      id : 33,
      unk_0a : 0xFFFF,
      count : 10,
      diskNo : DISK_CROSSBYNE,
    },

    // Ocean
    {
      stageID : STAGE_OCEAN,
      stageID2 : STAGE_OCEAN,
      zakoOfs : 36,
      type : ENTITY_ENEMY,
      id : ZAKO_SHELLUNO,
      unk_0a : 0xFFFF,
      count : 4,
      diskNo : DISK_SHELLUNO,
    },
    {
      stageID : STAGE_OCEAN,
      stageID2 : STAGE_OCEAN,
      zakoOfs : 37,
      type : ENTITY_SOLID,
      id : SOLID_ICEBON,
      unk_0a : 0xFFFF,
      count : 3,
      diskNo : DISK_ICEBON,
    },
    {
      stageID : STAGE_OCEAN,
      stageID2 : STAGE_OCEAN,
      zakoOfs : 38,
      type : ENTITY_ENEMY,
      id : ZAKO_SHARKSEAL_X,
      unk_0a : 0xFFFF,
      count : 4,
      diskNo : DISK_SHARKSEAL_X,
    },

    // Repair Factory
    {
      stageID : STAGE_REPAIR_FACTORY,
      stageID2 : STAGE_REPAIR_FACTORY,
      zakoOfs : 39,
      type : ENTITY_ENEMY,
      id : ZAKO_LEMMINGLES_NEST,
      unk_0a : 0xFFFF,
      count : 3,
      diskNo : DISK_ELF_GAMBUL,
    },
    {
      stageID : STAGE_REPAIR_FACTORY,
      stageID2 : STAGE_REPAIR_FACTORY,
      zakoOfs : 40,
      type : ENTITY_ENEMY,
      id : 55,
      unk_0a : 0xFFFF,
      count : 5,
      diskNo : DISK_DEATHLOCK,
    },
    {
      stageID : STAGE_REPAIR_FACTORY,
      stageID2 : STAGE_REPAIR_FACTORY,
      zakoOfs : 41,
      type : ENTITY_ENEMY,
      id : ZAKO_LEMMINGLES,
      unk_0a : 0xFFFF,
      count : 5,
      diskNo : DISK_LEMMINGLES,
    },
    {0x0005, 0x0005, 0x002A, 0x0003, 0x0005, 0xFFFF, 0x0003, 0x0087},
    {0x0005, 0x0005, 0x002B, 0x0003, 0x0039, 0x0000, 0x0005, 0x0091},
    {0x0006, 0x0006, 0x002C, 0x0003, 0x0036, 0x0001, 0x0006, 0x0062},
    {0x0006, 0x0006, 0x002D, 0x0003, 0x0000, 0xFFFF, 0x0004, 0x007F},
    {0x0006, 0x0006, 0x002E, 0x0003, 0x0036, 0x0000, 0x0003, 0x008A},
    {0x0006, 0x0006, 0x002F, 0x0003, 0x0029, 0xFFFF, 0x0004, 0x008B},
    {0x0007, 0x0007, 0x0030, 0x0003, 0x0033, 0xFFFF, 0x0002, 0x0041},
    {0x0007, 0x0007, 0x0031, 0x0003, 0x0007, 0xFFFF, 0x0005, 0x005B},
    {0x0007, 0x0007, 0x0032, 0x0003, 0x0009, 0xFFFF, 0x0005, 0x0099},
    {0x0007, 0x0007, 0x0033, 0x0003, 0x0016, 0xFFFF, 0x0005, 0x009A},
    {0x0008, 0x0008, 0x0034, 0x0003, 0x0019, 0xFFFF, 0x0007, 0x0086},
    {0x0008, 0x0008, 0x0035, 0x0003, 0x0023, 0xFFFF, 0x0005, 0x009D},
    {0x0009, 0x0009, 0x0036, 0x0003, 0x0012, 0xFFFF, 0x0003, 0x0080},
    {0x0009, 0x0009, 0x0037, 0x0003, 0x000B, 0xFFFF, 0x0003, 0x0084},
    {0x0009, 0x0009, 0x0038, 0x0006, 0x0005, 0xFFFF, 0x0004, 0x0088},
    {0x000A, 0x000A, 0x0039, 0x0003, 0x002B, 0xFFFF, 0x0004, 0x0089},
    {0x000B, 0x000B, 0x003A, 0x0003, 0x0014, 0xFFFF, 0x0004, 0x0096},
    {0x000B, 0x000B, 0x003B, 0x0003, 0x002F, 0xFFFF, 0x0009, 0x009B},
    {0x000C, 0x000C, 0x003C, 0x0003, 0x001D, 0xFFFF, 0x0005, 0x002E},
    {0x000C, 0x000C, 0x003D, 0x0003, 0x0031, 0xFFFF, 0x0004, 0x0082},
    {0x000C, 0x000C, 0x003E, 0x0003, 0x0041, 0xFFFF, 0x0004, 0x00A2},
    {0x000E, 0x000E, 0x003F, 0x0003, 0x0040, 0xFFFF, 0x0005, 0x0081},
    {0x000E, 0x000E, 0x0040, 0x0003, 0x003E, 0xFFFF, 0x0006, 0x0090},
    {0x000E, 0x000E, 0x0041, 0x0003, 0x0043, 0xFFFF, 0x0005, 0x0094},
    {0x000F, 0x000F, 0x0042, 0x0003, 0x0038, 0xFFFF, 0x0005, 0x008E},
    {0x000F, 0x000F, 0x0043, 0x0003, 0x003A, 0xFFFF, 0x0003, 0x008F},
    {0x000F, 0x000F, 0x0044, 0x0003, 0x0042, 0xFFFF, 0x0005, 0x00A3},
    {0x0010, 0x0010, 0x0045, 0x0003, 0x0001, 0xFFFF, 0x0005, 0x007E},
    {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000},
};

const u8 StageEnemyDiskDrops[STAGE_COUNT] = {
    0, 0, 4, 7, 10, 13, 15, 19, 23, 25, 28, 29, 31, 34, 34, 37, 40, 0,
};
