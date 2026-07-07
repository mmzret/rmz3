.section .rodata
.balign 4, 0

.global gSnowTilesetGraphics
gSnowTilesetGraphics:

Gfx0: @ 0x087044FC
	.4byte gSnowTilesetGraphic0-. @ data: 0x087045B0 = .+180
	.4byte 15424 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette0: @ 0x08704508
		.4byte gSnowTilesetGraphic0_Palettes-. @ data: 0x087081F0 = .+15592
		.2byte 96 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

Gfx1: @ 0x08704510
	.4byte gSnowTilesetGraphic1-. @ data: 0x08708250 = .+15680
	.4byte 11008 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette1: @ 0x0870451C
		.4byte gSnowTilesetGraphic1_Palettes-. @ data: 0x0870AD50 = .+26676
		.2byte 128 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

Gfx2: @ 0x08704524
	.4byte gSnowTilesetGraphic2-. @ data: 0x0870ADD0 = .+26796
	.4byte 14912 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette2: @ 0x08704530
		.4byte gSnowTilesetGraphic2_Palettes-. @ data: 0x0870E810 = .+41696
		.2byte 192 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

Gfx3: @ 0x08704538
	.4byte gSnowTilesetGraphic3-. @ data: 0x0870E8D0 = .+41880
	.4byte 10944 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette3: @ 0x08704544
		.4byte gSnowTilesetGraphic3_Palettes-. @ data: 0x08711390 = .+52812
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

Gfx4: @ 0x0870454C
	.4byte gSnowTilesetGraphic4-. @ data: 0x08711450 = .+52996
	.4byte 8404 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
Palette4: @ 0x08704558
		.4byte gSnowTilesetGraphic4_Palettes-. @ data: 0x08713524 = .+61388
		.2byte 128 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

Gfx5: @ 0x08704560
	.4byte gSnowTilesetGraphic5-. @ data: 0x087135A4 = .+61508
	.4byte 16320 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette5: @ 0x0870456C
		.4byte gSnowTilesetGraphic5_Palettes-. @ data: 0x08717564 = .+77816
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

Gfx6: @ 0x08704574
	.4byte gSnowTilesetGraphic6-. @ data: 0x087175C4 = .+77904
	.4byte 14464 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette6: @ 0x08704580
		.4byte gSnowTilesetGraphic6_Palettes-. @ data: 0x0871AE44 = .+92356
		.2byte 64 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

Gfx7: @ 0x08704588
	.4byte gSnowTilesetGraphic7-. @ data: 0x0871AE84 = .+92412
	.4byte 15360 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, BPP4 	@ rowsize(unused), props
Palette7: @ 0x08704594
		.4byte gSnowTilesetGraphic7_Palettes-. @ data: 0x0871EA84 = .+107760
		.2byte 160 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

Gfx8: @ 0x0870459C
	.4byte gSnowTilesetGraphic8-. @ data: 0x0871EB24 = .+107912
	.4byte 11268 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
Palette8: @ 0x087045A8
		.4byte gSnowTilesetGraphic8_Palettes-. @ data: 0x08721728 = .+119168
		.2byte 64 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@ GraphicData:
gSnowTilesetGraphic0:
	.incbin "data/tilesets/snow/snow0.4bpp"
gSnowTilesetGraphic0_Palettes:
	.incbin "data/tilesets/snow/snow0.gbapal"

gSnowTilesetGraphic1:
	.incbin "data/tilesets/snow/snow1.4bpp"
gSnowTilesetGraphic1_Palettes:
	.incbin "data/tilesets/snow/snow1.gbapal"

gSnowTilesetGraphic2:
	.incbin "data/tilesets/snow/snow2.4bpp"
gSnowTilesetGraphic2_Palettes:
	.incbin "data/tilesets/snow/snow2.gbapal"

gSnowTilesetGraphic3:
	.incbin "data/tilesets/snow/snow3.4bpp"
gSnowTilesetGraphic3_Palettes:
	.incbin "data/tilesets/snow/snow3.gbapal"

gSnowTilesetGraphic4:
	.incbin "data/tilesets/snow/snow4.4bpp.lz"
gSnowTilesetGraphic4_Palettes:
	.incbin "data/tilesets/snow/snow4.gbapal"

gSnowTilesetGraphic5:
	.incbin "data/tilesets/snow/snow5.4bpp"
gSnowTilesetGraphic5_Palettes:
	.incbin "data/tilesets/snow/snow5.gbapal"

gSnowTilesetGraphic6:
	.incbin "data/tilesets/snow/snow6.4bpp"
gSnowTilesetGraphic6_Palettes:
	.incbin "data/tilesets/snow/snow6.gbapal"

gSnowTilesetGraphic7:
	.incbin "data/tilesets/snow/snow7.4bpp"
gSnowTilesetGraphic7_Palettes:
	.incbin "data/tilesets/snow/snow7.gbapal"

gSnowTilesetGraphic8:
	.incbin "data/tilesets/snow/snow8.4bpp.lz"
gSnowTilesetGraphic8_Palettes:
	.incbin "data/tilesets/snow/snow8.gbapal"
