.balign 4, 0

.global gGraphicHeader_Sprite_weapon_triple_slash_2
gGraphicHeader_Sprite_weapon_triple_slash_2:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_2_0-. @ src
	.4byte 1184 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 296, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_2_1-. @ src
	.4byte 1184 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 296, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_triple_slash_2_2-. @ src
	.4byte 1088 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 272, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_triple_slash_2_0:
	.incbin "sprites/dynamic/weapon/triple_slash_2/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_triple_slash_2_1:
	.incbin "sprites/dynamic/weapon/triple_slash_2/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_triple_slash_2_2:
	.incbin "sprites/dynamic/weapon/triple_slash_2/sheet/2.4bpp"
