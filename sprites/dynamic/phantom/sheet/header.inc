.balign 4, 0

.global gGraphicHeader_Sprite_phantom
gGraphicHeader_Sprite_phantom:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_phantom_0-. @ src
	.4byte 1248 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_0_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_phantom_1-. @ src
	.4byte 1376 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 344, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_1_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_phantom_2-. @ src
	.4byte 1152 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_2_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_phantom_3-. @ src
	.4byte 1856 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 464, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_3_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_phantom_4-. @ src
	.4byte 1472 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 368, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_4_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_phantom_5-. @ src
	.4byte 1856 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 464, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_5_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_phantom_6-. @ src
	.4byte 960 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_6_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 7
	.4byte gGraphicHeader_Sprite_phantom_7-. @ src
	.4byte 1184 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 296, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_7_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 8
	.4byte gGraphicHeader_Sprite_phantom_8-. @ src
	.4byte 1632 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_8_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 9
	.4byte gGraphicHeader_Sprite_phantom_9-. @ src
	.4byte 1920 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 480, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_9_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 10
	.4byte gGraphicHeader_Sprite_phantom_10-. @ src
	.4byte 1824 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 456, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_10_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 11
	.4byte gGraphicHeader_Sprite_phantom_11-. @ src
	.4byte 1440 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 360, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_11_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 12
	.4byte gGraphicHeader_Sprite_phantom_12-. @ src
	.4byte 1120 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 280, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_12_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 13
	.4byte gGraphicHeader_Sprite_phantom_13-. @ src
	.4byte 960 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 240, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_13_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 14
	.4byte gGraphicHeader_Sprite_phantom_14-. @ src
	.4byte 1312 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 328, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_14_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 15
	.4byte gGraphicHeader_Sprite_phantom_15-. @ src
	.4byte 2048 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_15_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 16
	.4byte gGraphicHeader_Sprite_phantom_16-. @ src
	.4byte 1760 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 440, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_16_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 17
	.4byte gGraphicHeader_Sprite_phantom_17-. @ src
	.4byte 1952 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 488, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_17_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 18
	.4byte gGraphicHeader_Sprite_phantom_18-. @ src
	.4byte 1216 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_18_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 19
	.4byte gGraphicHeader_Sprite_phantom_19-. @ src
	.4byte 1728 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 432, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_19_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 20
	.4byte gGraphicHeader_Sprite_phantom_20-. @ src
	.4byte 1632 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 408, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_20_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 21
	.4byte gGraphicHeader_Sprite_phantom_21-. @ src
	.4byte 1216 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_21_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

	@ Graphic 22
	.4byte gGraphicHeader_Sprite_phantom_22-. @ src
	.4byte 1248 | (512 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_phantom_22_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 4 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_phantom_0:
	.incbin "sprites/dynamic/phantom/sheet/0.4bpp"
	gGraphicHeader_Sprite_phantom_0_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/0.gbapal"

gGraphicHeader_Sprite_phantom_1:
	.incbin "sprites/dynamic/phantom/sheet/1.4bpp"
	gGraphicHeader_Sprite_phantom_1_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/1.gbapal"

gGraphicHeader_Sprite_phantom_2:
	.incbin "sprites/dynamic/phantom/sheet/2.4bpp"
	gGraphicHeader_Sprite_phantom_2_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/2.gbapal"

gGraphicHeader_Sprite_phantom_3:
	.incbin "sprites/dynamic/phantom/sheet/3.4bpp"
	gGraphicHeader_Sprite_phantom_3_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/3.gbapal"

gGraphicHeader_Sprite_phantom_4:
	.incbin "sprites/dynamic/phantom/sheet/4.4bpp"
	gGraphicHeader_Sprite_phantom_4_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/4.gbapal"

gGraphicHeader_Sprite_phantom_5:
	.incbin "sprites/dynamic/phantom/sheet/5.4bpp"
	gGraphicHeader_Sprite_phantom_5_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/5.gbapal"

gGraphicHeader_Sprite_phantom_6:
	.incbin "sprites/dynamic/phantom/sheet/6.4bpp"
	gGraphicHeader_Sprite_phantom_6_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/6.gbapal"

gGraphicHeader_Sprite_phantom_7:
	.incbin "sprites/dynamic/phantom/sheet/7.4bpp"
	gGraphicHeader_Sprite_phantom_7_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/7.gbapal"

gGraphicHeader_Sprite_phantom_8:
	.incbin "sprites/dynamic/phantom/sheet/8.4bpp"
	gGraphicHeader_Sprite_phantom_8_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/8.gbapal"

gGraphicHeader_Sprite_phantom_9:
	.incbin "sprites/dynamic/phantom/sheet/9.4bpp"
	gGraphicHeader_Sprite_phantom_9_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/9.gbapal"

gGraphicHeader_Sprite_phantom_10:
	.incbin "sprites/dynamic/phantom/sheet/10.4bpp"
	gGraphicHeader_Sprite_phantom_10_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/10.gbapal"

gGraphicHeader_Sprite_phantom_11:
	.incbin "sprites/dynamic/phantom/sheet/11.4bpp"
	gGraphicHeader_Sprite_phantom_11_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/11.gbapal"

gGraphicHeader_Sprite_phantom_12:
	.incbin "sprites/dynamic/phantom/sheet/12.4bpp"
	gGraphicHeader_Sprite_phantom_12_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/12.gbapal"

gGraphicHeader_Sprite_phantom_13:
	.incbin "sprites/dynamic/phantom/sheet/13.4bpp"
	gGraphicHeader_Sprite_phantom_13_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/13.gbapal"

gGraphicHeader_Sprite_phantom_14:
	.incbin "sprites/dynamic/phantom/sheet/14.4bpp"
	gGraphicHeader_Sprite_phantom_14_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/14.gbapal"

gGraphicHeader_Sprite_phantom_15:
	.incbin "sprites/dynamic/phantom/sheet/15.4bpp"
	gGraphicHeader_Sprite_phantom_15_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/15.gbapal"

gGraphicHeader_Sprite_phantom_16:
	.incbin "sprites/dynamic/phantom/sheet/16.4bpp"
	gGraphicHeader_Sprite_phantom_16_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/16.gbapal"

gGraphicHeader_Sprite_phantom_17:
	.incbin "sprites/dynamic/phantom/sheet/17.4bpp"
	gGraphicHeader_Sprite_phantom_17_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/17.gbapal"

gGraphicHeader_Sprite_phantom_18:
	.incbin "sprites/dynamic/phantom/sheet/18.4bpp"
	gGraphicHeader_Sprite_phantom_18_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/18.gbapal"

gGraphicHeader_Sprite_phantom_19:
	.incbin "sprites/dynamic/phantom/sheet/19.4bpp"
	gGraphicHeader_Sprite_phantom_19_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/19.gbapal"

gGraphicHeader_Sprite_phantom_20:
	.incbin "sprites/dynamic/phantom/sheet/20.4bpp"
	gGraphicHeader_Sprite_phantom_20_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/20.gbapal"

gGraphicHeader_Sprite_phantom_21:
	.incbin "sprites/dynamic/phantom/sheet/21.4bpp"
	gGraphicHeader_Sprite_phantom_21_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/21.gbapal"

gGraphicHeader_Sprite_phantom_22:
	.incbin "sprites/dynamic/phantom/sheet/22.4bpp"
	gGraphicHeader_Sprite_phantom_22_Palettes:
	.incbin "sprites/dynamic/phantom/sheet/22.gbapal"
