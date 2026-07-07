.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_125
gGraphicHeader_Sprite_weapon_unk_125:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_125_0-. @ src
	.4byte 608 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 152, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_125_1-. @ src
	.4byte 576 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_125_2-. @ src
	.4byte 384 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_125_3-. @ src
	.4byte 480 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 120, BPP4 	@ rowsize(unused), props

	@ Graphic 4
	.4byte gGraphicHeader_Sprite_weapon_unk_125_4-. @ src
	.4byte 544 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 136, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_125_0:
	.incbin "sprites/dynamic/weapon/unk_125/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_125_1:
	.incbin "sprites/dynamic/weapon/unk_125/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_125_2:
	.incbin "sprites/dynamic/weapon/unk_125/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_unk_125_3:
	.incbin "sprites/dynamic/weapon/unk_125/sheet/3.4bpp"

gGraphicHeader_Sprite_weapon_unk_125_4:
	.incbin "sprites/dynamic/weapon/unk_125/sheet/4.4bpp"
