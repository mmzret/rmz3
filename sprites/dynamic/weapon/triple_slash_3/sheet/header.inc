.balign 4, 0

.global gGraphicHeader_Sprite_weapon_triple_slash_3
gGraphicHeader_Sprite_weapon_triple_slash_3:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_3_0-. @ src
	.4byte 384 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_3_1-. @ src
	.4byte 1472 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 368, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_3_2-. @ src
	.4byte 1472 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 368, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_3_3-. @ src
	.4byte 800 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 200, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_3_4-. @ src
	.4byte 480 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 120, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_triple_slash_3_0:
	.incbin "sprites/dynamic/weapon/triple_slash_3/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_triple_slash_3_1:
	.incbin "sprites/dynamic/weapon/triple_slash_3/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_triple_slash_3_2:
	.incbin "sprites/dynamic/weapon/triple_slash_3/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_triple_slash_3_3:
	.incbin "sprites/dynamic/weapon/triple_slash_3/sheet/3.4bpp"

gGraphicHeader_Sprite_weapon_triple_slash_3_4:
	.incbin "sprites/dynamic/weapon/triple_slash_3/sheet/4.4bpp"
