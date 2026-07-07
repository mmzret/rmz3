.section .rodata
.balign 4, 0

.global gAreaX2TilesetGraphics
gAreaX2TilesetGraphics:

AreaX2Tileset0: @ 0x087895A8
	.4byte AreaX2Tileset0_Tiles-. @ data: 0x087895F8 = .+80
	.4byte 8916 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087895B4
		.4byte AreaX2Tileset0_Pal-. @ data: 0x0878B8CC = .+8984
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

AreaX2Tileset1: @ 0x087895BC
	.4byte AreaX2Tileset1_Tiles-. @ data: 0x0878B98C = .+9168
	.4byte 7392 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087895C8
		.4byte AreaX2Tileset1_Pal-. @ data: 0x0878D66C = .+16548
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

AreaX2Tileset2: @ 0x087895D0
	.4byte AreaX2Tileset2_Tiles-. @ data: 0x0878D74C = .+16764
	.4byte 8456 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087895DC
		.4byte AreaX2Tileset2_Pal-. @ data: 0x0878F854 = .+25208
		.2byte 160 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

AreaX2Tileset3: @ 0x087895E4
	.4byte AreaX2Tileset3_Tiles-. @ data: 0x0878F8F4 = .+25360
	.4byte 6932 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087895F0
		.4byte AreaX2Tileset3_Pal-. @ data: 0x08791408 = .+32280
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

AreaX2Tileset0_Tiles:
	.incbin "data/tilesets/area_x2/area_x2_0.4bpp.lz"
AreaX2Tileset0_Pal:
	.incbin "data/tilesets/area_x2/area_x2_0.gbapal"

AreaX2Tileset1_Tiles:
	.incbin "data/tilesets/area_x2/area_x2_1.4bpp.lz"
AreaX2Tileset1_Pal:
	.incbin "data/tilesets/area_x2/area_x2_1.gbapal"

AreaX2Tileset2_Tiles:
	.incbin "data/tilesets/area_x2/area_x2_2.4bpp.lz"
AreaX2Tileset2_Pal:
	.incbin "data/tilesets/area_x2/area_x2_2.gbapal"

AreaX2Tileset3_Tiles:
	.incbin "data/tilesets/area_x2/area_x2_3.4bpp.lz"
AreaX2Tileset3_Pal:
	.incbin "data/tilesets/area_x2/area_x2_3.gbapal"

