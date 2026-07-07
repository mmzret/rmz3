.section .rodata
.balign 4, 0

.global gWeilLaboTilesetGraphics
gWeilLaboTilesetGraphics:

WeilLaboTileset0: @ 0x087B771C
	.4byte WeilLaboTileset0_Tiles-. @ data: 0x087B77A8 = .+140
	.4byte 8484 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B7728
		.4byte WeilLaboTileset0_Pal-. @ data: 0x087B98CC = .+8612
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WeilLaboTileset1: @ 0x087B7730
	.4byte WeilLaboTileset1_Tiles-. @ data: 0x087B99AC = .+8828
	.4byte 11160 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B773C
		.4byte WeilLaboTileset1_Pal-. @ data: 0x087BC544 = .+19976
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

WeilLaboTileset2: @ 0x087B7744
	.4byte WeilLaboTileset2_Tiles-. @ data: 0x087BC604 = .+20160
	.4byte 3900 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B7750
		.4byte WeilLaboTileset2_Pal-. @ data: 0x087BD540 = .+24048
		.2byte 160 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WeilLaboTileset3: @ 0x087B7758
	.4byte WeilLaboTileset3_Tiles-. @ data: 0x087BD5E0 = .+24200
	.4byte 10268 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B7764
		.4byte WeilLaboTileset3_Pal-. @ data: 0x087BFDFC = .+34456
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

WeilLaboTileset4: @ 0x087B776C
	.4byte WeilLaboTileset4_Tiles-. @ data: 0x087BFEDC = .+34672
	.4byte 7652 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B7778
		.4byte WeilLaboTileset4_Pal-. @ data: 0x087C1CC0 = .+42312
		.2byte 96 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WeilLaboTileset5: @ 0x087B7780
	.4byte WeilLaboTileset5_Tiles-. @ data: 0x087C1D20 = .+42400
	.4byte 7368 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B778C
		.4byte WeilLaboTileset5_Pal-. @ data: 0x087C39E8 = .+49756
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

WeilLaboTileset6: @ 0x087B7794
	.4byte WeilLaboTileset6_Tiles-. @ data: 0x087C3AA8 = .+49940
	.4byte 13224 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087B77A0
		.4byte WeilLaboTileset6_Pal-. @ data: 0x087C6E50 = .+63152
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

WeilLaboTileset0_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo0.4bpp.lz"
WeilLaboTileset0_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo0.gbapal"

WeilLaboTileset1_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo1.4bpp.lz"
WeilLaboTileset1_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo1.gbapal"

WeilLaboTileset2_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo2.4bpp.lz"
WeilLaboTileset2_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo2.gbapal"

WeilLaboTileset3_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo3.4bpp.lz"
WeilLaboTileset3_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo3.gbapal"

WeilLaboTileset4_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo4.4bpp.lz"
WeilLaboTileset4_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo4.gbapal"

WeilLaboTileset5_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo5.4bpp.lz"
WeilLaboTileset5_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo5.gbapal"

WeilLaboTileset6_Tiles:
	.incbin "data/tilesets/weil_labo/weil_labo6.4bpp.lz"
WeilLaboTileset6_Pal:
	.incbin "data/tilesets/weil_labo/weil_labo6.gbapal"
