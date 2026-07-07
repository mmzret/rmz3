.section .rodata
.balign 4, 0

.global gElevatorTilesetGraphics
gElevatorTilesetGraphics:

ElevatorTileset0: @ 0x087A2E2C
	.4byte ElevatorTileset0_Tiles-. @ data: 0x087A2E90 = .+100
	.4byte 9316 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087A2E38
		.4byte ElevatorTileset0_Pal-. @ data: 0x087A52F4 = .+9404
		.2byte 160 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

ElevatorTileset1: @ 0x087A2E40
	.4byte ElevatorTileset1_Tiles-. @ data: 0x087A5394 = .+9556
	.4byte 8800 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087A2E4C
		.4byte ElevatorTileset1_Pal-. @ data: 0x087A75F4 = .+18344
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

ElevatorTileset2: @ 0x087A2E54
	.4byte ElevatorTileset2_Tiles-. @ data: 0x087A7654 = .+18432
	.4byte 10928 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087A2E60
		.4byte ElevatorTileset2_Pal-. @ data: 0x087AA104 = .+29348
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

ElevatorTileset3: @ 0x087A2E68
	.4byte ElevatorTileset3_Tiles-. @ data: 0x087AA164 = .+29436
	.4byte 9036 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087A2E74
		.4byte ElevatorTileset3_Pal-. @ data: 0x087AC4B0 = .+38460
		.2byte 96 @ bytesize
		.byte 0, 9 @ lz77(bool8), dst = PaletteID

ElevatorTileset4: @ 0x087A2E7C
	.4byte ElevatorTileset4_Tiles-. @ data: 0x087AC510 = .+38548
	.4byte 11380 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 256, (LZ77 | BPP4) 	@ rowsize(unused), props
	@ Palette 0x087A2E88
		.4byte ElevatorTileset4_Pal-. @ data: 0x087AF184 = .+49916
		.2byte 96 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ElevatorTileset0_Tiles:
	.incbin "data/tilesets/giant_elevator/giant_elevator0.4bpp.lz"
ElevatorTileset0_Pal:
	.incbin "data/tilesets/giant_elevator/giant_elevator0.gbapal"

ElevatorTileset1_Tiles:
	.incbin "data/tilesets/giant_elevator/giant_elevator1.4bpp.lz"
ElevatorTileset1_Pal:
	.incbin "data/tilesets/giant_elevator/giant_elevator1.gbapal"

ElevatorTileset2_Tiles:
	.incbin "data/tilesets/giant_elevator/giant_elevator2.4bpp.lz"
ElevatorTileset2_Pal:
	.incbin "data/tilesets/giant_elevator/giant_elevator2.gbapal"

ElevatorTileset3_Tiles:
	.incbin "data/tilesets/giant_elevator/giant_elevator3.4bpp.lz"
ElevatorTileset3_Pal:
	.incbin "data/tilesets/giant_elevator/giant_elevator3.gbapal"

ElevatorTileset4_Tiles:
	.incbin "data/tilesets/giant_elevator/giant_elevator4.4bpp.lz"
ElevatorTileset4_Pal:
	.incbin "data/tilesets/giant_elevator/giant_elevator4.gbapal"

