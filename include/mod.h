#ifndef GUARD_RMZ3_MOD_H
#define GUARD_RMZ3_MOD_H

#include "gba/gba.h"

// 改造カード

#define MOD_FLAG_START ((7 << 3) + 7)

// SystemSavedata.flags の bit63 以降
enum ModID {
  MOD_0 = MOD_FLAG_START,  // flags[7] bit7
  MOD_PLANT,               // 8: ベースに鉢植えが置かれる
  MOD_09,                  // 9: ???
  MOD_SABER_ATK1,          // 10: Saber atk +1
  MOD_11,                  // 11: ???
  MOD_P_GUARDIAN_HP4,      // 12: Pantheon Guardian HP +4
  MOD_13,                  // 13: ???
  MOD_14,                  // 14: ???
  MOD_15,                  // 15: ???
  // 16..
  MOD_16,              // 16: ???
  MOD_ALOUETTE_DRESS,  // 17: Alouette dress
  MOD_ARCHIM_ATK1,     // 18: Archim atk +1
  MOD_DAMAGE_50P,      // 19: Zero damage 1/2
  MOD_20,
  MOD_21,
  MOD_22,
  MOD_23,
  // 24..
  MOD_152EC,       // 24: 152ECくれるレプリロイドがベースに出現
  MOD_ROD_ATK1,    // 25: Rod atk +1
  MOD_26,          // 26
  MOD_ORANGE_CAT,  // 27: Orange cat
  MOD_28,
  MOD_29,
  MOD_SHIELD_ATK1,  // 30: Shield atk +1
  MOD_BEE_ATK1,     // 31: Bee elf atk +1
  // 32..
  MOD_32,
  MOD_PHANTOM_ELF,  // 33
  MOD_BUSTER_ATK1,  // 34: Buster atk +1
  MOD_POSTER,       // 35
  MOD_ANDREW_1UP,   // 36: Andrew room 1UP
  MOD_BUSTER_ATK2,  // 37: Buster atk +2
  MOD_80EC,         // 38: 80ECくれるレプリロイドがベースに出現
  MOD_39,
  // 40..
  MOD_40,
  MOD_FLOWER,  // 41: ベースに花が咲く
  MOD_42,
  MOD_ANIMAL_ELF_LOOKS,  // 43:
  MOD_YOUNG_ANDREW,      // 44: Andrew looks younger
  MOD_ARCHIM_ATK2,       // 45: Archim atk +2
  MOD_SEAGULLS,          // 46: ベースにカモメが出現
  MOD_TABBY_CAT,         // 47: ベースにネコが出現
  // 48..
  MOD_BEE_ATK2,  // 48: Bee elf atk +2
  MOD_49,
  MOD_SHIELD_ATK2,  // 50: Shield atk +2
  MOD_51,
  MOD_GRAFFITI,  // 52
  MOD_53,
  MOD_100EC,     // 54: 100ECくれるレプリロイドがベースに出現
  MOD_ROD_ATK2,  // 55: Rod atk +2
  // 56..
  MOD_56,
  MOD_57,
  MOD_58,
  MOD_59,       // 59: ベースの右の塔にいるキャラとの会話が変わる
  MOD_32EC_2B,  // 60: 32EC(Room 2B)
  MOD_61,
  MOD_52EC_2C,  // 62: 52EC(Room 2C)
  MOD_52EC_2F,  // 63: 52EC(2F)
  // 64..
  MOD_64,
  MOD_ELPIZO_ELF,  // 65: Elpizo cyberelf
  MOD_66,
  MOD_SHIELD_ATK3,  // 67: Shield atk +3
  MOD_68,
  MOD_69,  // 69: ベースの左の塔にいるキャラとの会話が変わる
  MOD_70,
  MOD_BEE_ATK3,  // 71: Bee elf atk +3
  // 72..
  MOD_ARCHIM_ATK3,  // 72: Archim atk +3
  MOD_73,           // Hacker Elf looks
  MOD_74,           // Crossbyne HP +4
  MOD_75,           // Pantheon Base HP +4
  MOD_BUSTER_ATK3,  // 76: Buster atk +3
  MOD_77,
  MOD_78,
  MOD_79,
  // 80..
  MOD_80,  // Pantheon Aqua HP +4
  MOD_81,
  MOD_82,  // Lilies
  MOD_83,
  MOD_FLYING_FISH,  // 84: Fish
  MOD_ROD_ATK3,     // 85: Rod atk +3
  MOD_86,           // 32EC(Room 3A)
  MOD_87,           // 52EC(Room 3B)
  // 88..
  MOD_ARCHIM_ATK4,  // 88: Archim atk +4
  MOD_SABER_ATK2,   // 89: Saber atk +2
  MOD_90,           // bit 2: 40EC(Room 3C)
  MOD_P_BOMBER,     // bit 3: Pantheon Bomber HP +4
  MOD_92,           // bit 4: 32EC(3F)
  MOD_93,           // bit 5: 52EC(Room 3D)
  MOD_94,           // bit 6: Pantheon Aqua Mod HP +16
  MOD_95,           // bit 7: ???
  // 96..
  MOD_96,          // bit 0: ???
  MOD_SABER_ATK3,  // 97: Saber atk +3
  MOD_98,          // bit 2: ???
  MOD_99,          // bit 3: Purple Nerple HP +4
  MOD_100,         // bit 4: Shell Crawler HP +4
  MOD_101,         // bit 5: Icebon HP +4
  MOD_102,         // bit 6: Generator Cannon HP +4
  MOD_CLAVEKER,    // bit 7: Claveker HP +4
  // 104..
  MOD_104,            // bit 0: Shotcounter HP +4
  MOD_105,            // bit 1: Grand Cannon HP +4
  MOD_106,            // bit 2: Shrimporin HP +4
  MOD_107,            // bit 3: Batring HP +4
  MOD_PILLER_CANNON,  // bit 4: Piller Cannon HP +4
  MOD_109,            // bit 5: Volcaire HP +4
  MOD_110,            // bit 6: Snakecord HP +4
  MOD_111,            // bit 7: Lemmingles HP +4
  // 112..
  MOD_112,  // bit 0: Lamplort HP +4
  MOD_113,  // bit 1: Tile Cannon HP +4
  MOD_114,  // bit 2: Shelluno HP +4
  MOD_115,  // bit 3: Heavy Cannon HP +4
  MOD_116,  // bit 4: Mothjiro HP +4
  MOD_117,  // bit 5: CCannon HP +4
  MOD_118,  // bit 6: CalibeeG HP +16
  MOD_119,  // bit 7: Deathlock HP +4
  // 120..
  MOD_120,        //  bit 0: Gyro Cannon HP +4
  MOD_121,        //  bit 1: SharksealX HP +4
  MOD_122,        //  bit 2: OlWormer HP +16
  MOD_123,        //  bit 3: BranWormer HP +16
  MOD_124,        //  bit 4: LocomoIF HP +16
  MOD_125,        //  bit 5: BeeServer HP +16
  MOD_MEGAMILPA,  //  bit 6: Megamilpa HP +16
  MOD_127,
};

#endif  // GUARD_RMZ3_MOD_H
