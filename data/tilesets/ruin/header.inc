.section .rodata
.balign 4, 0

.global gRuinTilesetGraphics
gRuinTilesetGraphics:

RuinTileset0: @ 0x08756C84
	.4byte RuinTileset0_Tiles-. @ data: 0x08756CD4 = .+80
	.4byte 11872 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette0 0x08756C90
		.4byte RuinTileset0_Pal-. @ data: 0x08759B34 = .+11940
		.2byte 160 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

RuinTileset1: @ 0x08756C98
	.4byte RuinTileset1_Tiles-. @ data: 0x08759BD4 = .+12092
	.4byte 10356 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette1 0x08756CA4
		.4byte RuinTileset1_Pal-. @ data: 0x0875C448 = .+22436
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

RuinTileset2: @ 0x08756CAC
	.4byte RuinTileset2_Tiles-. @ data: 0x0875C508 = .+22620
	.4byte 11388 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette2 0x08756CB8
		.4byte RuinTileset2_Pal-. @ data: 0x0875F184 = .+33996
		.2byte 160 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

RuinTileset3: @ 0x08756CC0
	.4byte RuinTileset3_Tiles-. @ data: 0x0875F224 = .+34148
	.4byte 9492 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette3 0x08756CCC
		.4byte RuinTileset3_Pal-. @ data: 0x08761738 = .+43628
		.2byte 96 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

RuinTileset0_Tiles:
	.incbin "data/tilesets/ruin/ruin0.4bpp.lz"
RuinTileset0_Pal:
	.incbin "data/tilesets/ruin/ruin0.gbapal"

RuinTileset1_Tiles:
	.incbin "data/tilesets/ruin/ruin1.4bpp.lz"
RuinTileset1_Pal:
	.incbin "data/tilesets/ruin/ruin1.gbapal"

RuinTileset2_Tiles:
	.incbin "data/tilesets/ruin/ruin2.4bpp.lz"
RuinTileset2_Pal:
	.incbin "data/tilesets/ruin/ruin2.gbapal"

RuinTileset3_Tiles:
	.incbin "data/tilesets/ruin/ruin3.4bpp.lz"
RuinTileset3_Pal:
	.incbin "data/tilesets/ruin/ruin3.gbapal"
