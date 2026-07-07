  .include "asm/macros.inc"

.section .rodata
.balign 4, 0

@ カテゴリ分けが合ってるか怪しい
.global gBgMapOffsets
gBgMapOffsets: @ 0x085222A0
  .4byte Tilemap_Capcom-. @ 0
  .4byte Tilemap_Inti-. @ 1
  .4byte Tilemap_2-. @ 2
  .4byte Tilemap_TitleZero-., Tilemap_TitleCiel-. @ 3, 4
  .4byte Tilemap_5-. @ 5
  .4byte Tilemap_6-. @ 6
  .4byte Tilemap_7-. @ 7
  .4byte Tilemap_8-. @ 8
  .4byte dummy-., dummy-., dummy-., dummy-., dummy-., dummy-., dummy-., dummy-., dummy-. @ 9..17
  .4byte Tilemap_LogoDemo-. @ 18
  .4byte dummy-. @ 19
  .4byte Tilemap_20-. @ 20
  .4byte Tilemap_21-. @ 21
  .4byte Tilemap_22-. @ 22
  .4byte Tilemap_23-. @ 23
  .4byte Tilemap_Zero3DModelA-., Tilemap_Zero3DModelB-., dummy-., dummy-., dummy-., dummy-., dummy-., dummy-., dummy-. @ 24, 25, 26..32
  .4byte dummy-., dummy-., dummy-. @ 33..35
  .4byte dummy-., dummy-., dummy-., dummy-. @ 36..39
  .4byte Tilemap_40-., Tilemap_41-., Tilemap_42-. @ 40, 41, 42: Spacecraft
  .4byte Tilemap_43-., Tilemap_44-., Tilemap_45-., Tilemap_46-., Tilemap_47-., Tilemap_48-., Tilemap_49-., Tilemap_50-., Tilemap_51-., Tilemap_52-., Tilemap_53-., Tilemap_54-., Tilemap_55-., Tilemap_56-., Tilemap_57-. @ 43..57: Ocean Highway Ruins (後の方は違うかも)
  .4byte Tilemap_58-., Tilemap_59-., Tilemap_60-. @ 58..60: Resistance Base
  .4byte Tilemap_61-., Tilemap_62-. @ 61, 62: Twilight Desert
  .4byte Tilemap_63-., Tilemap_64-., Tilemap_65-. @ 63, 64, 65: Frostline Ice Base
  .4byte Tilemap_66-. @ 66: Area X2
  .4byte Tilemap_67-., Tilemap_68-., Tilemap_69-., Tilemap_70-., Tilemap_71-. @ 67..71: Sunken Library
  .4byte Tilemap_72-., Tilemap_73-., Tilemap_74-., Tilemap_75-., Tilemap_76-. @ 72..76: Weil Labo
  .4byte Tilemap_77-., Tilemap_78-. @ 77, 78: Snowy Plains
  .4byte Tilemap_79-., Tilemap_80-. @ 79, 80: Energy Facility
  .4byte 82084, 83624, 85164, 86448, 87732, 89016, 90300, 91584, 92868, 93368, 95420, 97472, 99524, 101576, 103628, 105680, 107732, 109784, 140, 111832, 113036, 114320, 116372, 120, 116, 117648, 117988, 118376, 100, 96, 92, 118656, 119940, 121864, 123148, 124432, 126484, 127768, 129052, 130336, 131620, 133672, 134956, 136240, 137524, 139576, 141628, 142912
  .4byte Tilemap_129-. @ 129
  .4byte Tilemap_130-., Tilemap_131-., Tilemap_132-. @ 130, 131, 132
  .4byte Tilemap_133-. @ 133

.global gTilemapData
gTilemapData:

dummy: @ タイルマップデータが存在しないグラフィックデータ(HPゲージなどの小道具) はここを指す

Tilemap_Capcom:
  .4byte 0x10001 @ 不明 (全てのタイルマップがこの値), .2byte 0x1, 0x1 で、何かの倍率とか？
  .2byte 32, 20  @ w8, h8
  .incbin "data/bgmaps/misc/000.bin"

Tilemap_Inti:
  .4byte 0x10001
  .2byte 32, 20  @ w8, h8
  .incbin "data/bgmaps/misc/001.bin"

Tilemap_2:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
  .incbin "data/bgmaps/misc/002.bin"

Tilemap_TitleZero:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
  .incbin "data/bgmaps/misc/003.bin"

Tilemap_TitleCiel:
	.4byte 0x10001
  .2byte 20, 20  @ w8, h8
  .incbin "data/bgmaps/misc/004.bin"

Tilemap_5:
	.4byte 0x10001
  .2byte 30, 2  @ w8, h8
  .incbin "data/bgmaps/misc/005.bin"

Tilemap_6:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
.incbin "data/bgmaps/misc/006.bin"

Tilemap_7:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
.incbin "data/bgmaps/misc/007.bin"

Tilemap_8:
	.4byte 0x10001
	.2byte	23, 5 @ w8, h8
  .incbin "data/bgmaps/misc/008.bin"

Tilemap_LogoDemo:
	.4byte 0x10001
	.2byte	11, 4 @ w8, h8
  .incbin "data/bgmaps/misc/018.bin"

Tilemap_20:
	.4byte 0x10001
  .2byte	32, 20 @ w8, h8
.incbin "data/bgmaps/menu/020.bin"

Tilemap_21:
	.4byte 0x10001
  .2byte	32, 20 @ w8, h8
  .incbin "data/bgmaps/menu/021.bin"

Tilemap_22:
	.4byte 0x10001
  .2byte	32, 20 @ w8, h8
  .incbin "data/bgmaps/menu/022.bin"

Tilemap_23:
	.4byte 0x10001
  .2byte	32, 20 @ w8, h8
  .incbin "data/bgmaps/menu/023.bin"

Tilemap_Zero3DModelA:
	.4byte 0x10001
	.2byte	6, 8 @ w8, h8
  .incbin "data/bgmaps/menu/024.bin"

Tilemap_Zero3DModelB:
	.4byte 0x10001
	.2byte	6, 8 @ w8, h8
  .incbin "data/bgmaps/menu/025.bin"

Tilemap_40:
	.4byte 0x10001
	.2byte	32, 32 @ w8, h8
  .incbin "data/bgmaps/spacecraft/040.bin"

Tilemap_41:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
  .incbin "data/bgmaps/spacecraft/041.bin"

Tilemap_42:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
  .incbin "data/bgmaps/spacecraft/042.bin"

Tilemap_43:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/043.bin"

Tilemap_44:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/044.bin"

Tilemap_45:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/045.bin"

Tilemap_46:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/046.bin"

Tilemap_47:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
  .incbin "data/bgmaps/ocean_highway_ruins/047.bin"

Tilemap_48:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/048.bin"

Tilemap_49:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/049.bin"

Tilemap_50:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/050.bin"

Tilemap_51:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
  .incbin "data/bgmaps/ocean_highway_ruins/051.bin"

Tilemap_52:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
  .incbin "data/bgmaps/ocean_highway_ruins/052.bin"

Tilemap_53:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
  .incbin "data/bgmaps/ocean_highway_ruins/053.bin"

Tilemap_54:
	.4byte 0x10001
	.2byte	16, 16 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/054.bin"

Tilemap_55:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/055.bin"

Tilemap_56:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/056.bin"

Tilemap_57:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/ocean_highway_ruins/057.bin"

Tilemap_58:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/resistance_base/058.bin"

Tilemap_59:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/resistance_base/059.bin"

Tilemap_60:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/resistance_base/060.bin"

Tilemap_61:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/twilight_desert/061.bin"

Tilemap_62:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/twilight_desert/062.bin"

Tilemap_63:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/frostline_ice_base/063.bin"

Tilemap_64:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/frostline_ice_base/064.bin"

Tilemap_65:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/frostline_ice_base/065.bin"

Tilemap_66:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/area_x2/066.bin"

Tilemap_67:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/sunken_library/067.bin"

Tilemap_68:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/sunken_library/068.bin"

Tilemap_69:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/sunken_library/069.bin"

Tilemap_70:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/sunken_library/070.bin"

Tilemap_71:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/sunken_library/071.bin"

Tilemap_72:
	.4byte 0x10001
	.2byte	32, 19
  .incbin "data/bgmaps/weil_labo/072.bin"

Tilemap_73:
	.4byte 0x10001
	.2byte	32, 19
  .incbin "data/bgmaps/weil_labo/073.bin"

Tilemap_74:
	.4byte 0x10001
	.2byte	20, 26
  .incbin "data/bgmaps/weil_labo/074.bin"

Tilemap_75:
	.4byte 0x10001
	.2byte	30, 24
  .incbin "data/bgmaps/weil_labo/075.bin"

Tilemap_76:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/weil_labo/076.bin"

Tilemap_77:
	.4byte 0x10001
	.2byte	32, 18
  .incbin "data/bgmaps/snowy_plains/077.bin"

Tilemap_78:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/snowy_plains/078.bin"

Tilemap_79:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/snowy_plains/079.bin"

Tilemap_80:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/snowy_plains/080.bin"

Tilemap_81:
	.4byte 0x10001
	.2byte	32, 24
  .incbin "data/bgmaps/todo/081.bin"

Tilemap_82:
	.4byte 0x10001
	.2byte	32, 24
  .incbin "data/bgmaps/todo/082.bin"

Tilemap_83:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/083.bin"

Tilemap_84:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/084.bin"

Tilemap_85:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/085.bin"

Tilemap_86:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/086.bin"

Tilemap_87:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/087.bin"

Tilemap_88:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/088.bin"

Tilemap_89:
	.4byte 0x10001
	.2byte	13, 19
.incbin "data/bgmaps/todo/089.bin"

Tilemap_90:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/090.bin"

Tilemap_91:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/091.bin"

Tilemap_92:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/092.bin"

Tilemap_93:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/093.bin"

Tilemap_94:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/094.bin"

Tilemap_95:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/095.bin"

Tilemap_96:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/096.bin"

Tilemap_97:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/097.bin"

Tilemap_98:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/098.bin"

Tilemap_100:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
.incbin "data/bgmaps/todo/100.bin"

Tilemap_101:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/101.bin"

Tilemap_102:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/102.bin"

Tilemap_103:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/103.bin"

Tilemap_106:
	.4byte 0x10001
	.2byte	12, 14
.incbin "data/bgmaps/todo/106.bin"

Tilemap_107:
	.4byte 0x10001
	.2byte	12, 16
.incbin "data/bgmaps/todo/107.bin"

Tilemap_108:
	.4byte 0x10001
	.2byte	12, 12
.incbin "data/bgmaps/todo/108.bin"

Tilemap_112:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/112.bin"

Tilemap_113:
	.4byte 0x10001
	.2byte	32, 30
.incbin "data/bgmaps/todo/113.bin"

Tilemap_114:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/114.bin"

Tilemap_115:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/115.bin"

Tilemap_116:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/116.bin"

Tilemap_117:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/117.bin"

Tilemap_118:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/118.bin"

Tilemap_119:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/119.bin"

Tilemap_120:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/120.bin"

Tilemap_121:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/121.bin"

Tilemap_122:
	.4byte 0x10001
  .2byte	32, 20
.incbin "data/bgmaps/todo/122.bin"

Tilemap_123:
	.4byte 0x10001
	.2byte	32, 20 @ w8, h8
.incbin "data/bgmaps/todo/123.bin"

Tilemap_124:
	.4byte 0x10001
	.2byte	32, 20 @ w8, h8
.incbin "data/bgmaps/todo/124.bin"

Tilemap_125:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
  .incbin "data/bgmaps/todo/125.bin"

Tilemap_126:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/126.bin"

Tilemap_127:
	.4byte 0x10001
	.2byte	32, 20
.incbin "data/bgmaps/todo/127.bin"

Tilemap_128:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
.incbin "data/bgmaps/todo/128.bin"

Tilemap_129:
	.4byte 0x10001
  .2byte	32, 32 @ w8, h8
.incbin "data/bgmaps/todo/129.bin"

Tilemap_130:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
.incbin "data/bgmaps/todo/130.bin"

Tilemap_131:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
  .incbin "data/bgmaps/todo/131.bin"

Tilemap_132:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
  .incbin "data/bgmaps/todo/132.bin"

Tilemap_133:
	.4byte 0x10001
  .2byte 30, 20  @ w8, h8
  .incbin "data/bgmaps/todo/133.bin"
