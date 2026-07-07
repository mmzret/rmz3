.balign 4, 0

.global gGraphicHeader_Sprite_boss_explosion
gGraphicHeader_Sprite_boss_explosion:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_boss_explosion_0-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_0_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_boss_explosion_1-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_1_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_boss_explosion_2-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_2_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_boss_explosion_3-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_3_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_boss_explosion_4-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_4_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_boss_explosion_5-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_5_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_boss_explosion_6-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_6_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 7
	.4byte gGraphicHeader_Sprite_boss_explosion_7-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_7_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 8
	.4byte gGraphicHeader_Sprite_boss_explosion_8-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_8_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 9
	.4byte gGraphicHeader_Sprite_boss_explosion_9-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_9_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 10
	.4byte gGraphicHeader_Sprite_boss_explosion_10-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_10_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

	@ Graphic 11
	.4byte gGraphicHeader_Sprite_boss_explosion_11-. @ src
	.4byte 2048 | (378 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 512, BPP4 	@ rowsize(unused), props
		@ Palette
		.4byte gGraphicHeader_Sprite_boss_explosion_11_Palettes-. @ src offset
		.2byte 32 @ bytesize
		.byte 0, 2 @ lz77(bool8), dst = PaletteID

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_boss_explosion_0:
	.incbin "sprites/dynamic/boss_explosion/sheet/0.4bpp"
	gGraphicHeader_Sprite_boss_explosion_0_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/0.gbapal"

gGraphicHeader_Sprite_boss_explosion_1:
	.incbin "sprites/dynamic/boss_explosion/sheet/1.4bpp"
	gGraphicHeader_Sprite_boss_explosion_1_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/1.gbapal"

gGraphicHeader_Sprite_boss_explosion_2:
	.incbin "sprites/dynamic/boss_explosion/sheet/2.4bpp"
	gGraphicHeader_Sprite_boss_explosion_2_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/2.gbapal"

gGraphicHeader_Sprite_boss_explosion_3:
	.incbin "sprites/dynamic/boss_explosion/sheet/3.4bpp"
	gGraphicHeader_Sprite_boss_explosion_3_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/3.gbapal"

gGraphicHeader_Sprite_boss_explosion_4:
	.incbin "sprites/dynamic/boss_explosion/sheet/4.4bpp"
	gGraphicHeader_Sprite_boss_explosion_4_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/4.gbapal"

gGraphicHeader_Sprite_boss_explosion_5:
	.incbin "sprites/dynamic/boss_explosion/sheet/5.4bpp"
	gGraphicHeader_Sprite_boss_explosion_5_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/5.gbapal"

gGraphicHeader_Sprite_boss_explosion_6:
	.incbin "sprites/dynamic/boss_explosion/sheet/6.4bpp"
	gGraphicHeader_Sprite_boss_explosion_6_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/6.gbapal"

gGraphicHeader_Sprite_boss_explosion_7:
	.incbin "sprites/dynamic/boss_explosion/sheet/7.4bpp"
	gGraphicHeader_Sprite_boss_explosion_7_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/7.gbapal"

gGraphicHeader_Sprite_boss_explosion_8:
	.incbin "sprites/dynamic/boss_explosion/sheet/8.4bpp"
	gGraphicHeader_Sprite_boss_explosion_8_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/8.gbapal"

gGraphicHeader_Sprite_boss_explosion_9:
	.incbin "sprites/dynamic/boss_explosion/sheet/9.4bpp"
	gGraphicHeader_Sprite_boss_explosion_9_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/9.gbapal"

gGraphicHeader_Sprite_boss_explosion_10:
	.incbin "sprites/dynamic/boss_explosion/sheet/10.4bpp"
	gGraphicHeader_Sprite_boss_explosion_10_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/10.gbapal"

gGraphicHeader_Sprite_boss_explosion_11:
	.incbin "sprites/dynamic/boss_explosion/sheet/11.4bpp"
	gGraphicHeader_Sprite_boss_explosion_11_Palettes:
	.incbin "sprites/dynamic/boss_explosion/sheet/11.gbapal"
