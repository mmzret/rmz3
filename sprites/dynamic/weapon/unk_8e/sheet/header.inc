.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_8e
gGraphicHeader_Sprite_weapon_unk_8e:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_8e_0-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_8e_1-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_8e_2-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_8e_3-. @ src
	.4byte 384 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 96, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_8e_0:
	.incbin "sprites/dynamic/weapon/unk_8e/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_8e_1:
	.incbin "sprites/dynamic/weapon/unk_8e/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_8e_2:
	.incbin "sprites/dynamic/weapon/unk_8e/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_unk_8e_3:
	.incbin "sprites/dynamic/weapon/unk_8e/sheet/3.4bpp"
