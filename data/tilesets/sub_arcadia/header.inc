.section .rodata
.balign 4, 0

.global gSubArcadiaTilesetGraphics
gSubArcadiaTilesetGraphics:

SubArcadiaTileset0: @ 0x087AF1E4
	.4byte SubArcadiaTileset0_Tiles-. @ data: 0x087AF234 = .+80
	.4byte 8756 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087AF1F0
		.4byte SubArcadiaTileset0_Pal-. @ data: 0x087B1468 = .+8824
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

SubArcadiaTileset1: @ 0x087AF1F8
	.4byte SubArcadiaTileset1_Tiles-. @ data: 0x087B1548 = .+9040
	.4byte 8636 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087AF204
		.4byte SubArcadiaTileset1_Pal-. @ data: 0x087B3704 = .+17664
		.2byte 160 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

SubArcadiaTileset2: @ 0x087AF20C
	.4byte SubArcadiaTileset2_Tiles-. @ data: 0x087B37A4 = .+17816
	.4byte 5840 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087AF218
		.4byte SubArcadiaTileset2_Pal-. @ data: 0x087B4E74 = .+23644
		.2byte 128 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

SubArcadiaTileset3: @ 0x087AF220
	.4byte SubArcadiaTileset3_Tiles-. @ data: 0x087B4EF4 = .+23764
	.4byte 10056 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087AF22C
		.4byte SubArcadiaTileset3_Pal-. @ data: 0x087B763C = .+33808
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SubArcadiaTileset0_Tiles:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia0.4bpp.lz"
SubArcadiaTileset0_Pal:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia0.gbapal"

SubArcadiaTileset1_Tiles:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia1.4bpp.lz"
SubArcadiaTileset1_Pal:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia1.gbapal"

SubArcadiaTileset2_Tiles:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia2.4bpp.lz"
SubArcadiaTileset2_Pal:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia2.gbapal"

SubArcadiaTileset3_Tiles:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia3.4bpp.lz"
SubArcadiaTileset3_Pal:
	.incbin "data/tilesets/sub_arcadia/sub_arcadia3.gbapal"

