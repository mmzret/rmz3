.balign 4, 0

.global gGraphicHeader_Sprite_omega_zero
gGraphicHeader_Sprite_omega_zero:
	@ Graphic 0, 0x084054e8
	.4byte gGraphicHeader_Sprite_omega_zero_0-. @ src
	.4byte 992 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 248, BPP4 	@ rowsize(unused), props

	@ Graphic 1, 0x084054f4
	.4byte gGraphicHeader_Sprite_omega_zero_1-. @ src
	.4byte 704 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 176, BPP4 	@ rowsize(unused), props

	@ Graphic 2, 0x08405500
	.4byte gGraphicHeader_Sprite_omega_zero_2-. @ src
	.4byte 704 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 176, BPP4 	@ rowsize(unused), props

	@ Graphic 3, 0x0840550c
	.4byte gGraphicHeader_Sprite_omega_zero_3-. @ src
	.4byte 1184 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 296, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_omega_zero_4-. @ src
	.4byte 576 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_omega_zero_5-. @ src
	.4byte 1248 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_omega_zero_6-. @ src
	.4byte 1376 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 344, BPP4 	@ rowsize(unused), props

	@ Graphic 7
	.4byte gGraphicHeader_Sprite_omega_zero_7-. @ src
	.4byte 1248 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props

	@ Graphic 8
	.4byte gGraphicHeader_Sprite_omega_zero_8-. @ src
	.4byte 608 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 152, BPP4 	@ rowsize(unused), props

	@ Graphic 9
	.4byte gGraphicHeader_Sprite_omega_zero_9-. @ src
	.4byte 1248 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 312, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_omega_zero_0:
	.incbin "sprites/dynamic/omega_zero/sheet/0.4bpp"

gGraphicHeader_Sprite_omega_zero_1:
	.incbin "sprites/dynamic/omega_zero/sheet/1.4bpp"

gGraphicHeader_Sprite_omega_zero_2:
	.incbin "sprites/dynamic/omega_zero/sheet/2.4bpp"

gGraphicHeader_Sprite_omega_zero_3:
	.incbin "sprites/dynamic/omega_zero/sheet/3.4bpp"

gGraphicHeader_Sprite_omega_zero_4:
	.incbin "sprites/dynamic/omega_zero/sheet/4.4bpp"

gGraphicHeader_Sprite_omega_zero_5:
	.incbin "sprites/dynamic/omega_zero/sheet/5.4bpp"

gGraphicHeader_Sprite_omega_zero_6:
	.incbin "sprites/dynamic/omega_zero/sheet/6.4bpp"

gGraphicHeader_Sprite_omega_zero_7:
	.incbin "sprites/dynamic/omega_zero/sheet/7.4bpp"

gGraphicHeader_Sprite_omega_zero_8:
	.incbin "sprites/dynamic/omega_zero/sheet/8.4bpp"

gGraphicHeader_Sprite_omega_zero_9:
	.incbin "sprites/dynamic/omega_zero/sheet/9.4bpp"
