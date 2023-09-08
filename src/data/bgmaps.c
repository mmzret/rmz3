#include "global.h"

/*
  ゲーム中の背景マップのデータ
  0x085222a0..0854727F
*/

#define PATH(bin) "data/bgmaps/" bin

#define INC_BGMAP(n, w, h, bin)               \
  const struct BgMapHeader BgMapHeader##n = { \
      0x10001,                                \
      w,                                      \
      h,                                      \
  };                                          \
  INCBIN16(BgMap##n, PATH(bin));

/*
  0x085222a0
  BgMapHeader = &gBgMapOffsets[idx] + gBgMapOffsets[idx]
  e.g. 0x085229c0 = &gBgMapOffsets[1] + gBgMapOffsets[1] = 0x085222a4 + 0x71C
*/
const u32 gBgMapOffsets[134] = {
    536, 1820, 3104, 4308, 5512, 6316, 6440, 7644, 8848, 500, 496, 492, 488, 484, 480, 476, 472, 468, 9048, 460, 9136, 10420, 11704, 12988, 14272, 14372, 432, 428, 424, 420, 416, 412, 408, 404, 400, 396, 392, 388, 384, 380, 14416, 16468, 18520, 20572, 22624, 24676, 26728, 28780, 29296, 29812, 30328, 30844, 31360, 31876, 32392, 32908, 34960, 37012, 39064, 41116, 43168, 45220, 47272, 49324, 51376, 53428, 55480, 57532, 59584, 61636, 63688, 65740, 67792, 69012, 70232, 71276, 72720, 74772, 75928, 77980, 80032, 82084, 83624, 85164, 86448, 87732, 89016, 90300, 91584, 92868, 93368, 95420, 97472, 99524, 101576, 103628, 105680, 107732, 109784, 140, 111832, 113036, 114320, 116372, 120, 116, 117648, 117988, 118376, 100, 96, 92, 118656, 119940, 121864, 123148, 124432, 126484, 127768, 129052, 130336, 131620, 133672, 134956, 136240, 137524, 139576, 141628, 142912, 144116, 146168, 147372, 148576, 149780,
};

// Misc
INC_BGMAP(0, 32, 20, "misc/000.bin");  // 0x085224b8, "CAPCOM"
INC_BGMAP(1, 32, 20, "misc/001.bin");  // 0x085229c0, "インティ・クリエイツ"
INC_BGMAP(2, 30, 20, "misc/002.bin");  // 0x08522ec8, タイトル画面(BG2)
INC_BGMAP(3, 30, 20, "misc/003.bin");  // 0x08523380, タイトル画面(BG3)
INC_BGMAP(4, 20, 20, "misc/004.bin");  // 0x08523838, タイトル画面(BG3)
INC_BGMAP(5, 30, 2, "misc/005.bin");   // 0x08523b60, "スタートボタンをおしてください"(BG1)
INC_BGMAP(6, 30, 20, "misc/006.bin");  // 0x08523be0, ミニゲーム選択
INC_BGMAP(7, 30, 20, "misc/007.bin");  // 0x08524098
INC_BGMAP(8, 23, 5, "misc/008.bin");   // 0x08524550
INC_BGMAP(18, 11, 4, "misc/018.bin");  // 0x08524640

// Menu
INC_BGMAP(20, 32, 20, "menu/020.bin");  // 0x085246A0, MainMenuBgMap
INC_BGMAP(21, 32, 20, "menu/021.bin");  // 0x08524BA8, ExSkillMenuBgMap
INC_BGMAP(22, 32, 20, "menu/022.bin");  // 0x085250B0, KeyConfigMenuBgMap
INC_BGMAP(23, 32, 20, "menu/023.bin");  // 0x085255B8, ElfMenuBgMap
INC_BGMAP(24, 6, 8, "menu/024.bin");    // 0x08525AC0, Zero3DModelMap0
INC_BGMAP(25, 6, 8, "menu/025.bin");    // 0x08525B28, Zero3DModelMap1

// Spacecraft
INC_BGMAP(40, 32, 32, "spacecraft/040.bin");  // 0x08525B90, SpaceCraftBgMap
INC_BGMAP(41, 32, 32, "spacecraft/041.bin");  // 0x08526398, SpaceCraftSnowBgMap
INC_BGMAP(42, 32, 32, "spacecraft/042.bin");  // 0x08526BA0, OmegaWhiteBgMap

// Ocean Highway Ruins

// BG3, data/bgmaps/images/043.png
INC_BGMAP(43, 32, 32, "ocean_highway_ruins/043.bin");  // 0x085273A8, upper
INC_BGMAP(44, 32, 32, "ocean_highway_ruins/044.bin");  // 0x08527BB0, lower
// BG2 data/bgmaps/images/045.png
INC_BGMAP(45, 32, 32, "ocean_highway_ruins/045.bin");  // 0x085283B8, upper
INC_BGMAP(46, 32, 32, "ocean_highway_ruins/046.bin");  // 0x08528BC0, lower
// Todo
INC_BGMAP(47, 16, 16, "ocean_highway_ruins/047.bin");  // 0x085293C8
INC_BGMAP(48, 16, 16, "ocean_highway_ruins/048.bin");  // 0x085295D0
INC_BGMAP(49, 16, 16, "ocean_highway_ruins/049.bin");  // 0x085297D8
INC_BGMAP(50, 16, 16, "ocean_highway_ruins/050.bin");  // 0x085299E0
INC_BGMAP(51, 16, 16, "ocean_highway_ruins/051.bin");  // 0x08529BE8
INC_BGMAP(52, 16, 16, "ocean_highway_ruins/052.bin");  // 0x08529DF0
INC_BGMAP(53, 16, 16, "ocean_highway_ruins/053.bin");  // 0x08529FF8
INC_BGMAP(54, 16, 16, "ocean_highway_ruins/054.bin");  // 0x0852A200
INC_BGMAP(55, 32, 32, "ocean_highway_ruins/055.bin");  // 0x0852A408
INC_BGMAP(56, 32, 32, "ocean_highway_ruins/056.bin");  // 0x0852AC10
INC_BGMAP(57, 32, 32, "ocean_highway_ruins/057.bin");  // 0x0852B418

// Resistance Base
INC_BGMAP(58, 32, 32, "resistance_base/058.bin");  // 0x0852BC20, data/bgmaps/images/058.png
INC_BGMAP(59, 32, 32, "resistance_base/059.bin");  // 0x0852C428
INC_BGMAP(60, 32, 32, "resistance_base/060.bin");  // 0x0852CC30

// Twilight Desert
INC_BGMAP(61, 32, 32, "twilight_desert/061.bin");  // 0x0852D438
INC_BGMAP(62, 32, 32, "twilight_desert/062.bin");  // 0x0852DC40

// Frost Base Line
INC_BGMAP(63, 32, 32, "frostline_ice_base/063.bin");  // 0x0852E448
INC_BGMAP(64, 32, 32, "frostline_ice_base/064.bin");  // 0x0852EC50
INC_BGMAP(65, 32, 32, "frostline_ice_base/065.bin");  // 0x0852F458

// Area X2
INC_BGMAP(66, 32, 32, "area_x2/066.bin");  // 0x0852FC60

// Sunken Library
INC_BGMAP(67, 32, 32, "sunken_library/067.bin");  // 0x08530468
INC_BGMAP(68, 32, 32, "sunken_library/068.bin");  // 0x08530C70
INC_BGMAP(69, 32, 32, "sunken_library/069.bin");  // 0x08531478
INC_BGMAP(70, 32, 32, "sunken_library/070.bin");  // 0x08531C80
INC_BGMAP(71, 32, 32, "sunken_library/071.bin");  // 0x08532488

// Weil Labo
INC_BGMAP(72, 32, 19, "weil_labo/072.bin");  // 0x08532C90
INC_BGMAP(73, 32, 19, "weil_labo/073.bin");  // 0x08533158
INC_BGMAP(74, 20, 26, "weil_labo/074.bin");  // 0x08533620, Omega2CoreMap, ./images/074.png BG2
INC_BGMAP(75, 30, 24, "weil_labo/075.bin");  // 0x08533A38, Omega2ZeroMap, ./images/075.png BG3
INC_BGMAP(76, 32, 32, "weil_labo/076.bin");  // 0x08533FE0, Omega2BgMap, ./images/076.png BG1

// Snowy Plains
INC_BGMAP(77, 32, 18, "snowy_plains/077.bin");  // 0x085347E8
INC_BGMAP(78, 32, 32, "snowy_plains/078.bin");  // 0x08534C70
INC_BGMAP(79, 32, 32, "snowy_plains/079.bin");  // 0x08535478
INC_BGMAP(80, 32, 32, "snowy_plains/080.bin");  // 0x08535C80

// Todo(Uncategorize)
INC_BGMAP(81, 32, 24, "todo/081.bin");   // 0x08536488
INC_BGMAP(82, 32, 24, "todo/082.bin");   // 0x08536A90
INC_BGMAP(83, 32, 20, "todo/083.bin");   // 0x08537098
INC_BGMAP(84, 32, 20, "todo/084.bin");   // 0x085375A0
INC_BGMAP(85, 32, 20, "todo/085.bin");   // 0x08537AA8
INC_BGMAP(86, 32, 20, "todo/086.bin");   // 0x08537FB0
INC_BGMAP(87, 32, 20, "todo/087.bin");   // 0x085384B8
INC_BGMAP(88, 32, 20, "todo/088.bin");   // 0x085389C0
INC_BGMAP(89, 13, 19, "todo/089.bin");   // 0x08538EC8
INC_BGMAP(90, 32, 32, "todo/090.bin");   // 0x085390C0
INC_BGMAP(91, 32, 32, "todo/091.bin");   // 0x085398C8
INC_BGMAP(92, 32, 32, "todo/092.bin");   // 0x0853A0D0
INC_BGMAP(93, 32, 32, "todo/093.bin");   // 0x0853A8D8
INC_BGMAP(94, 32, 32, "todo/094.bin");   // 0x0853B0E0
INC_BGMAP(95, 32, 32, "todo/095.bin");   // 0x0853B8E8
INC_BGMAP(96, 32, 32, "todo/096.bin");   // 0x0853C0F0
INC_BGMAP(97, 32, 32, "todo/097.bin");   // 0x0853C8F8
INC_BGMAP(98, 32, 32, "todo/098.bin");   // 0x0853D100
INC_BGMAP(100, 30, 20, "todo/100.bin");  // 0x0853D908, ResultBgMap
INC_BGMAP(101, 32, 20, "todo/101.bin");  // 0x0853DDC0, DiskAnalysisBgMap
INC_BGMAP(102, 32, 32, "todo/102.bin");  // 0x0853E2C8
INC_BGMAP(103, 32, 20, "todo/103.bin");  // 0x0853EAD0
INC_BGMAP(106, 12, 14, "todo/106.bin");  // 0x0853EFD8
INC_BGMAP(107, 12, 16, "todo/107.bin");  // 0x0853F130
INC_BGMAP(108, 12, 12, "todo/108.bin");  // 0x0853F2B8
INC_BGMAP(112, 32, 20, "todo/112.bin");  // 0x0853F3E0
INC_BGMAP(113, 32, 30, "todo/113.bin");  // 0x0853F8E8
INC_BGMAP(114, 32, 20, "todo/114.bin");  // 0x08540070
INC_BGMAP(115, 32, 20, "todo/115.bin");  // 0x08540578
INC_BGMAP(116, 32, 32, "todo/116.bin");  // 0x08540A80
INC_BGMAP(117, 32, 20, "todo/117.bin");  // 0x08541288
INC_BGMAP(118, 32, 20, "todo/118.bin");  // 0x08541790
INC_BGMAP(119, 32, 20, "todo/119.bin");  // 0x08541C98
INC_BGMAP(120, 32, 20, "todo/120.bin");  // 0x085421A0
INC_BGMAP(121, 32, 32, "todo/121.bin");  // 0x085426A8
INC_BGMAP(122, 32, 20, "todo/122.bin");  // 0x08542EB0
INC_BGMAP(123, 32, 20, "todo/123.bin");  // 0x085433B8
INC_BGMAP(124, 32, 20, "todo/124.bin");  // 0x085438C0
INC_BGMAP(125, 32, 32, "todo/125.bin");  // 0x08543DC8
INC_BGMAP(126, 32, 32, "todo/126.bin");  // 0x085445D0
INC_BGMAP(127, 32, 20, "todo/127.bin");  // 0x08544DD8
INC_BGMAP(128, 30, 20, "todo/128.bin");  // 0x085452E0
INC_BGMAP(129, 32, 32, "todo/129.bin");  // 0x08545798
INC_BGMAP(130, 30, 20, "todo/130.bin");  // 0x08545FA0
INC_BGMAP(131, 30, 20, "todo/131.bin");  // 0x08546458
INC_BGMAP(132, 30, 20, "todo/132.bin");  // 0x08546910
INC_BGMAP(133, 30, 20, "todo/133.bin");  // 0x08546DC8
