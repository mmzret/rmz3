.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_89
gGraphicHeader_Sprite_weapon_unk_89:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_89_0-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_89_1-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_89_2-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_89_3-. @ src
	.4byte 512 | (80 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_89_0:
	.incbin "sprites/dynamic/weapon/unk_89/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_89_1:
	.incbin "sprites/dynamic/weapon/unk_89/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_89_2:
	.incbin "sprites/dynamic/weapon/unk_89/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_unk_89_3:
	.incbin "sprites/dynamic/weapon/unk_89/sheet/3.4bpp"
