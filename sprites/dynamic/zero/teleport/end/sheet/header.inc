.balign 4, 0

.global gGraphicHeader_Sprite_zero_teleport_end
gGraphicHeader_Sprite_zero_teleport_end:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_zero_teleport_end_0-. @ src
	.4byte 832 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 208, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_zero_teleport_end_1-. @ src
	.4byte 512 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_zero_teleport_end_2-. @ src
	.4byte 768 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 192, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_zero_teleport_end_3-. @ src
	.4byte 1344 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 336, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_zero_teleport_end_4-. @ src
	.4byte 1536 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 384, BPP4 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_zero_teleport_end_5-. @ src
	.4byte 928 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 232, BPP4 	@ rowsize(unused), props

	@ Graphic 6
	.4byte gGraphicHeader_Sprite_zero_teleport_end_6-. @ src
	.4byte 864 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 216, BPP4 	@ rowsize(unused), props

	@ Graphic 7
	.4byte gGraphicHeader_Sprite_zero_teleport_end_7-. @ src
	.4byte 1312 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 328, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_zero_teleport_end_0:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/0.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_1:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/1.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_2:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/2.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_3:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/3.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_4:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/4.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_5:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/5.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_6:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/6.4bpp"

gGraphicHeader_Sprite_zero_teleport_end_7:
	.incbin "sprites/dynamic/zero/teleport/end/sheet/7.4bpp"
