.section .rodata
.balign 4, 0

.global gWatersideTilesetGraphics
gWatersideTilesetGraphics:

WatersideTileset0: @ 0x08736538
	.4byte WatersideTileset0_Tiles-. @ data: 0x087365C4 = .+140
	.4byte 11952 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette0 0x08736544
		.4byte WatersideTileset0_Pal-. @ data: 0x08739474 = .+12080
		.2byte 192 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WatersideTileset1: @ 0x0873654C
	.4byte WatersideTileset1_Tiles-. @ data: 0x08739534 = .+12264
	.4byte 8032 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette1 0x08736558
		.4byte WatersideTileset1_Pal-. @ data: 0x0873B494 = .+20284
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

WatersideTileset2: @ 0x08736560
	.4byte WatersideTileset2_Tiles-. @ data: 0x0873B574 = .+20500
	.4byte 10172 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette2 0x0873656C
		.4byte WatersideTileset2_Pal-. @ data: 0x0873DD30 = .+30660
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WatersideTileset3: @ 0x08736574
	.4byte WatersideTileset3_Tiles-. @ data: 0x0873DE10 = .+30876
	.4byte 6664 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette3 0x08736580
		.4byte WatersideTileset3_Pal-. @ data: 0x0873F818 = .+37528
		.2byte 160 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WatersideTileset4: @ 0x08736588
	.4byte WatersideTileset4_Tiles-. @ data: 0x0873F8B8 = .+37680
	.4byte 6940 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette4 0x08736594
		.4byte WatersideTileset4_Pal-. @ data: 0x087413D4 = .+44608
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

WatersideTileset5: @ 0x0873659C
	.4byte WatersideTileset5_Tiles-. @ data: 0x087414B4 = .+44824
	.4byte 6456 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette5 0x087365A8
		.4byte WatersideTileset5_Pal-. @ data: 0x08742DEC = .+51268
		.2byte 224 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

WatersideTileset6: @ 0x087365B0
	.4byte WatersideTileset6_Tiles-. @ data: 0x08742ECC = .+51484
	.4byte 7304 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette6 0x087365BC
		.4byte WatersideTileset6_Pal-. @ data: 0x08744B54 = .+58776
		.2byte 224 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

WatersideTileset0_Tiles:
	.incbin "data/tilesets/waterside/waterside0.4bpp.lz"
WatersideTileset0_Pal:
	.incbin "data/tilesets/waterside/waterside0.gbapal"

WatersideTileset1_Tiles:
	.incbin "data/tilesets/waterside/waterside1.4bpp.lz"
WatersideTileset1_Pal:
	.incbin "data/tilesets/waterside/waterside1.gbapal"

WatersideTileset2_Tiles:
	.incbin "data/tilesets/waterside/waterside2.4bpp.lz"
WatersideTileset2_Pal:
	.incbin "data/tilesets/waterside/waterside2.gbapal"

WatersideTileset3_Tiles:
	.incbin "data/tilesets/waterside/waterside3.4bpp.lz"
WatersideTileset3_Pal:
	.incbin "data/tilesets/waterside/waterside3.gbapal"

WatersideTileset4_Tiles:
	.incbin "data/tilesets/waterside/waterside4.4bpp.lz"
WatersideTileset4_Pal:
	.incbin "data/tilesets/waterside/waterside4.gbapal"

WatersideTileset5_Tiles:
	.incbin "data/tilesets/waterside/waterside5.4bpp.lz"
WatersideTileset5_Pal:
	.incbin "data/tilesets/waterside/waterside5.gbapal"

WatersideTileset6_Tiles:
	.incbin "data/tilesets/waterside/waterside6.4bpp.lz"
WatersideTileset6_Pal:
	.incbin "data/tilesets/waterside/waterside6.gbapal"
