#include "global.h"
#include "incbin.h"

/*
  ゲーム中の背景マップのデータ
  0x085222a0..0854727F
*/

#define PATH(bin) "data/gfx/bgmaps/" bin

#define BgMap(n, w, h, bin)                   \
  const struct BgMapHeader BgMapHeader##n = { \
      0x10001,                                \
      w,                                      \
      h,                                      \
  };                                          \
  INCBIN16(BgMap##n, PATH(bin));

/*
  0x085222a0
  BgMapHeader = &BgMapOffsets[idx] + BgMapOffsets[idx]
  e.g. 0x085229c0 = &BgMapOffsets[1] + BgMapOffsets[1] = 0x085222a4 + 0x71C
*/
const u32 BgMapOffsets[134] = {
    0x00000218, 0x0000071C, 0x00000C20, 0x000010D4, 0x00001588, 0x000018AC, 0x00001928, 0x00001DDC, 0x00002290,
    0x000001F4, 0x000001F0, 0x000001EC, 0x000001E8, 0x000001E4, 0x000001E0, 0x000001DC, 0x000001D8, 0x000001D4,
    0x00002358, 0x000001CC, 0x000023B0, 0x000028B4, 0x00002DB8, 0x000032BC, 0x000037C0, 0x00003824, 0x000001B0,
    0x000001AC, 0x000001A8, 0x000001A4, 0x000001A0, 0x0000019C, 0x00000198, 0x00000194, 0x00000190, 0x0000018C,
    0x00000188, 0x00000184, 0x00000180, 0x0000017C, 0x00003850, 0x00004054, 0x00004858, 0x0000505C, 0x00005860,
    0x00006064, 0x00006868, 0x0000706C, 0x00007270, 0x00007474, 0x00007678, 0x0000787C, 0x00007A80, 0x00007C84,
    0x00007E88, 0x0000808C, 0x00008890, 0x00009094, 0x00009898, 0x0000A09C, 0x0000A8A0, 0x0000B0A4, 0x0000B8A8,
    0x0000C0AC, 0x0000C8B0, 0x0000D0B4, 0x0000D8B8, 0x0000E0BC, 0x0000E8C0, 0x0000F0C4, 0x0000F8C8, 0x000100CC,
    0x000108D0, 0x00010D94, 0x00011258, 0x0001166C, 0x00011C10, 0x00012414, 0x00012898, 0x0001309C, 0x000138A0,
    0x000140A4, 0x000146A8, 0x00014CAC, 0x000151B0, 0x000156B4, 0x00015BB8, 0x000160BC, 0x000165C0, 0x00016AC4,
    0x00016CB8, 0x000174BC, 0x00017CC0, 0x000184C4, 0x00018CC8, 0x000194CC, 0x00019CD0, 0x0001A4D4, 0x0001ACD8,
    0x0000008C, 0x0001B4D8, 0x0001B98C, 0x0001BE90, 0x0001C694, 0x00000078, 0x00000074, 0x0001CB90, 0x0001CCE4,
    0x0001CE68, 0x00000064, 0x00000060, 0x0000005C, 0x0001CF80, 0x0001D484, 0x0001DC08, 0x0001E10C, 0x0001E610,
    0x0001EE14, 0x0001F318, 0x0001F81C, 0x0001FD20, 0x00020224, 0x00020A28, 0x00020F2C, 0x00021430, 0x00021934,
    0x00022138, 0x0002293C, 0x00022E40, 0x000232F4, 0x00023AF8, 0x00023FAC, 0x00024460, 0x00024914,
};

// Misc
BgMap(0, 32, 20, "misc/000.bin");  // 0x085224b8, "CAPCOM"
BgMap(1, 32, 20, "misc/001.bin");  // 0x085229c0, "インティ・クリエイツ"
BgMap(2, 30, 20, "misc/002.bin");  // 0x08522ec8, タイトル画面(BG2)
BgMap(3, 30, 20, "misc/003.bin");  // 0x08523380, タイトル画面(BG3)
BgMap(4, 20, 20, "misc/004.bin");  // 0x08523838, タイトル画面(BG3)
BgMap(5, 30, 2, "misc/005.bin");   // 0x08523b60, "スタートボタンをおしてください"(BG1)
BgMap(6, 30, 20, "misc/006.bin");  // 0x08523be0, ミニゲーム選択
BgMap(7, 30, 20, "misc/007.bin");  // 0x08524098
BgMap(8, 23, 5, "misc/008.bin");   // 0x08524550
BgMap(18, 11, 4, "misc/018.bin");  // 0x08524640

// Menu
BgMap(20, 32, 20, "menu/020.bin");  // 0x085246A0, MainMenuBgMap
BgMap(21, 32, 20, "menu/021.bin");  // 0x08524BA8, ExSkillMenuBgMap
BgMap(22, 32, 20, "menu/022.bin");  // 0x085250B0, KeyConfigMenuBgMap
BgMap(23, 32, 20, "menu/023.bin");  // 0x085255B8, ElfMenuBgMap
BgMap(24, 6, 8, "menu/024.bin");    // 0x08525AC0, Zero3DModelMap0
BgMap(25, 6, 8, "menu/025.bin");    // 0x08525B28, Zero3DModelMap1

// Spacecraft
BgMap(40, 32, 32, "spacecraft/040.bin");  // 0x08525B90, SpaceCraftBgMap
BgMap(41, 32, 32, "spacecraft/041.bin");  // 0x08526398, SpaceCraftSnowBgMap
BgMap(42, 32, 32, "spacecraft/042.bin");  // 0x08526BA0, OmegaWhiteBgMap

// Ocean Highway Ruins

// BG3, data/gfx/bgmaps/images/043.png
BgMap(43, 32, 32, "ocean_highway_ruins/043.bin");  // 0x085273A8, upper
BgMap(44, 32, 32, "ocean_highway_ruins/044.bin");  // 0x08527BB0, lower
// BG2 data/gfx/bgmaps/images/045.png
BgMap(45, 32, 32, "ocean_highway_ruins/045.bin");  // 0x085283B8, upper
BgMap(46, 32, 32, "ocean_highway_ruins/046.bin");  // 0x08528BC0, lower
// Todo
BgMap(47, 16, 16, "ocean_highway_ruins/047.bin");  // 0x085293C8
BgMap(48, 16, 16, "ocean_highway_ruins/048.bin");  // 0x085295D0
BgMap(49, 16, 16, "ocean_highway_ruins/049.bin");  // 0x085297D8
BgMap(50, 16, 16, "ocean_highway_ruins/050.bin");  // 0x085299E0
BgMap(51, 16, 16, "ocean_highway_ruins/051.bin");  // 0x08529BE8
BgMap(52, 16, 16, "ocean_highway_ruins/052.bin");  // 0x08529DF0
BgMap(53, 16, 16, "ocean_highway_ruins/053.bin");  // 0x08529FF8
BgMap(54, 16, 16, "ocean_highway_ruins/054.bin");  // 0x0852A200
BgMap(55, 32, 32, "ocean_highway_ruins/055.bin");  // 0x0852A408
BgMap(56, 32, 32, "ocean_highway_ruins/056.bin");  // 0x0852AC10
BgMap(57, 32, 32, "ocean_highway_ruins/057.bin");  // 0x0852B418

// Resistance Base
BgMap(58, 32, 32, "resistance_base/058.bin");  // 0x0852BC20, data/gfx/bgmaps/images/058.png
BgMap(59, 32, 32, "resistance_base/059.bin");  // 0x0852C428
BgMap(60, 32, 32, "resistance_base/060.bin");  // 0x0852CC30

// Twilight Desert
BgMap(61, 32, 32, "twilight_desert/061.bin");  // 0x0852D438
BgMap(62, 32, 32, "twilight_desert/062.bin");  // 0x0852DC40

// Frost Base Line
BgMap(63, 32, 32, "frost_base_line/063.bin");  // 0x0852E448
BgMap(64, 32, 32, "frost_base_line/064.bin");  // 0x0852EC50
BgMap(65, 32, 32, "frost_base_line/065.bin");  // 0x0852F458

// Area X2
BgMap(66, 32, 32, "area_x2/066.bin");  // 0x0852FC60

// Sunken Library
BgMap(67, 32, 32, "sunken_library/067.bin");  // 0x08530468
BgMap(68, 32, 32, "sunken_library/068.bin");  // 0x08530C70
BgMap(69, 32, 32, "sunken_library/069.bin");  // 0x08531478
BgMap(70, 32, 32, "sunken_library/070.bin");  // 0x08531C80
BgMap(71, 32, 32, "sunken_library/071.bin");  // 0x08532488

// Weil Labo
BgMap(72, 32, 19, "weil_labo/072.bin");  // 0x08532C90
BgMap(73, 32, 19, "weil_labo/073.bin");  // 0x08533158
BgMap(74, 20, 26, "weil_labo/074.bin");  // 0x08533620, Omega2CoreMap, ./images/074.png BG2
BgMap(75, 30, 24, "weil_labo/075.bin");  // 0x08533A38, Omega2ZeroMap, ./images/075.png BG3
BgMap(76, 32, 32, "weil_labo/076.bin");  // 0x08533FE0, Omega2BgMap, ./images/076.png BG1

// Snowy Plains
BgMap(77, 32, 18, "snowy_plains/077.bin");  // 0x085347E8
BgMap(78, 32, 32, "snowy_plains/078.bin");  // 0x08534C70
BgMap(79, 32, 32, "snowy_plains/079.bin");  // 0x08535478
BgMap(80, 32, 32, "snowy_plains/080.bin");  // 0x08535C80

// Todo(Uncategorize)
BgMap(81, 32, 24, "todo/081.bin");   // 0x08536488
BgMap(82, 32, 24, "todo/082.bin");   // 0x08536A90
BgMap(83, 32, 20, "todo/083.bin");   // 0x08537098
BgMap(84, 32, 20, "todo/084.bin");   // 0x085375A0
BgMap(85, 32, 20, "todo/085.bin");   // 0x08537AA8
BgMap(86, 32, 20, "todo/086.bin");   // 0x08537FB0
BgMap(87, 32, 20, "todo/087.bin");   // 0x085384B8
BgMap(88, 32, 20, "todo/088.bin");   // 0x085389C0
BgMap(89, 13, 19, "todo/089.bin");   // 0x08538EC8
BgMap(90, 32, 32, "todo/090.bin");   // 0x085390C0
BgMap(91, 32, 32, "todo/091.bin");   // 0x085398C8
BgMap(92, 32, 32, "todo/092.bin");   // 0x0853A0D0
BgMap(93, 32, 32, "todo/093.bin");   // 0x0853A8D8
BgMap(94, 32, 32, "todo/094.bin");   // 0x0853B0E0
BgMap(95, 32, 32, "todo/095.bin");   // 0x0853B8E8
BgMap(96, 32, 32, "todo/096.bin");   // 0x0853C0F0
BgMap(97, 32, 32, "todo/097.bin");   // 0x0853C8F8
BgMap(98, 32, 32, "todo/098.bin");   // 0x0853D100
BgMap(100, 30, 20, "todo/100.bin");  // 0x0853D908, ResultBgMap
BgMap(101, 32, 20, "todo/101.bin");  // 0x0853DDC0, DiskAnalysisBgMap
BgMap(102, 32, 32, "todo/102.bin");  // 0x0853E2C8
BgMap(103, 32, 20, "todo/103.bin");  // 0x0853EAD0
BgMap(106, 12, 14, "todo/106.bin");  // 0x0853EFD8
BgMap(107, 12, 16, "todo/107.bin");  // 0x0853F130
BgMap(108, 12, 12, "todo/108.bin");  // 0x0853F2B8
BgMap(112, 32, 20, "todo/112.bin");  // 0x0853F3E0
BgMap(113, 32, 30, "todo/113.bin");  // 0x0853F8E8
BgMap(114, 32, 20, "todo/114.bin");  // 0x08540070
BgMap(115, 32, 20, "todo/115.bin");  // 0x08540578
BgMap(116, 32, 32, "todo/116.bin");  // 0x08540A80
BgMap(117, 32, 20, "todo/117.bin");  // 0x08541288
BgMap(118, 32, 20, "todo/118.bin");  // 0x08541790
BgMap(119, 32, 20, "todo/119.bin");  // 0x08541C98
BgMap(120, 32, 20, "todo/120.bin");  // 0x085421A0
BgMap(121, 32, 32, "todo/121.bin");  // 0x085426A8
BgMap(122, 32, 20, "todo/122.bin");  // 0x08542EB0
BgMap(123, 32, 20, "todo/123.bin");  // 0x085433B8
BgMap(124, 32, 20, "todo/124.bin");  // 0x085438C0
BgMap(125, 32, 32, "todo/125.bin");  // 0x08543DC8
BgMap(126, 32, 32, "todo/126.bin");  // 0x085445D0
BgMap(127, 32, 20, "todo/127.bin");  // 0x08544DD8
BgMap(128, 30, 20, "todo/128.bin");  // 0x085452E0
BgMap(129, 32, 32, "todo/129.bin");  // 0x08545798
BgMap(130, 30, 20, "todo/130.bin");  // 0x08545FA0
BgMap(131, 30, 20, "todo/131.bin");  // 0x08546458
BgMap(132, 30, 20, "todo/132.bin");  // 0x08546910
BgMap(133, 30, 20, "todo/133.bin");  // 0x08546DC8
