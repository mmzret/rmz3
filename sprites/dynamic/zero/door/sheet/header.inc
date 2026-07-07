.balign 4, 0

.global gGraphicHeader_Sprite_zero_door
gGraphicHeader_Sprite_zero_door:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_zero_door_0-. @ src
	.4byte 932 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 288, (LZ77 | BPP4) 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_zero_door_1-. @ src
	.4byte 528 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 168, (LZ77 | BPP4) 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_zero_door_2-. @ src
	.4byte 612 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 200, (LZ77 | BPP4) 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_zero_door_3-. @ src
	.4byte 940 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 304, (LZ77 | BPP4) 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_zero_door_4-. @ src
	.4byte 164 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, (LZ77 | BPP4) 	@ rowsize(unused), props

	@ Graphic 5
	.4byte gGraphicHeader_Sprite_zero_door_5-. @ src
	.4byte 204 | (0 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 248, (LZ77 | BPP4) 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_zero_door_0:
	.incbin "sprites/dynamic/zero/door/sheet/0.4bpp.lz"

gGraphicHeader_Sprite_zero_door_1:
	.incbin "sprites/dynamic/zero/door/sheet/1.4bpp.lz"

gGraphicHeader_Sprite_zero_door_2:
	.incbin "sprites/dynamic/zero/door/sheet/2.4bpp.lz"

gGraphicHeader_Sprite_zero_door_3:
	.incbin "sprites/dynamic/zero/door/sheet/3.4bpp.lz"

gGraphicHeader_Sprite_zero_door_4:
	.incbin "sprites/dynamic/zero/door/sheet/4.4bpp.lz"

gGraphicHeader_Sprite_zero_door_5:
	.incbin "sprites/dynamic/zero/door/sheet/5.4bpp.lz"
