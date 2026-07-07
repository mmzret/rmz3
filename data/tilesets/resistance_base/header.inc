.section .rodata
.balign 4, 0

.global gResistanceBaseTilesetGraphics
gResistanceBaseTilesetGraphics:

ResistanceBaseTileset0: @ 0x087C6F30
	.4byte ResistanceBaseTileset0_Tiles-. @ data: 0x087C6FA8 = .+120
	.4byte 6148 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087C6F3C
		.4byte ResistanceBaseTileset0_Pal-. @ data: 0x087C87AC = .+6256
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

ResistanceBaseTileset1: @ 0x087C6F44
	.4byte ResistanceBaseTileset1_Tiles-. @ data: 0x087C888C = .+6472
	.4byte 6892 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087C6F50
		.4byte ResistanceBaseTileset1_Pal-. @ data: 0x087CA378 = .+13352
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

ResistanceBaseTileset2: @ 0x087C6F58
	.4byte ResistanceBaseTileset2_Tiles-. @ data: 0x087CA458 = .+13568
	.4byte 16384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x087C6F64
		.4byte ResistanceBaseTileset2_Pal-. @ data: 0x087CE458 = .+29940
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

ResistanceBaseTileset3: @ 0x087C6F6C
	.4byte ResistanceBaseTileset3_Tiles-. @ data: 0x087CE538 = .+30156
	.4byte 16384 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
	@ Palette 0x087C6F78
		.4byte ResistanceBaseTileset3_Pal-. @ data: 0x087D2538 = .+46528
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

ResistanceBaseTileset4: @ 0x087C6F80
	.4byte ResistanceBaseTileset4_Tiles-. @ data: 0x087D2618 = .+46744
	.4byte 8160 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087C6F8C
		.4byte ResistanceBaseTileset4_Pal-. @ data: 0x087D45F8 = .+54892
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

ResistanceBaseTileset5: @ 0x087C6F94
	.4byte ResistanceBaseTileset5_Tiles-. @ data: 0x087D46D8 = .+55108
	.4byte 4788 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087C6FA0
		.4byte ResistanceBaseTileset5_Pal-. @ data: 0x087D598C = .+59884
		.2byte 160 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ResistanceBaseTileset0_Tiles:
	.incbin "data/tilesets/resistance_base/resistance_base0.4bpp.lz"
ResistanceBaseTileset0_Pal:
	.incbin "data/tilesets/resistance_base/resistance_base0.gbapal"

ResistanceBaseTileset1_Tiles:
	.incbin "data/tilesets/resistance_base/resistance_base1.4bpp.lz"
ResistanceBaseTileset1_Pal:
	.incbin "data/tilesets/resistance_base/resistance_base1.gbapal"

ResistanceBaseTileset2_Tiles:
	.incbin "data/tilesets/resistance_base/resistance_base2.4bpp"
ResistanceBaseTileset2_Pal:
	.incbin "data/tilesets/resistance_base/resistance_base2.gbapal"

ResistanceBaseTileset3_Tiles:
	.incbin "data/tilesets/resistance_base/resistance_base3.4bpp"
ResistanceBaseTileset3_Pal:
	.incbin "data/tilesets/resistance_base/resistance_base3.gbapal"

ResistanceBaseTileset4_Tiles:
	.incbin "data/tilesets/resistance_base/resistance_base4.4bpp.lz"
ResistanceBaseTileset4_Pal:
	.incbin "data/tilesets/resistance_base/resistance_base4.gbapal"

ResistanceBaseTileset5_Tiles:
	.incbin "data/tilesets/resistance_base/resistance_base5.4bpp.lz"
ResistanceBaseTileset5_Pal:
	.incbin "data/tilesets/resistance_base/resistance_base5.gbapal"
