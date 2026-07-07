.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_119
gGraphicHeader_Sprite_weapon_unk_119:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_119_0-. @ src
	.4byte 640 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_119_1-. @ src
	.4byte 640 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 160, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_119_2-. @ src
	.4byte 576 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 144, BPP4 	@ rowsize(unused), props

	@ Graphic 3
	.4byte gGraphicHeader_Sprite_weapon_unk_119_3-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_119_0:
	.incbin "sprites/dynamic/weapon/unk_119/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_119_1:
	.incbin "sprites/dynamic/weapon/unk_119/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_119_2:
	.incbin "sprites/dynamic/weapon/unk_119/sheet/2.4bpp"

gGraphicHeader_Sprite_weapon_unk_119_3:
	.incbin "sprites/dynamic/weapon/unk_119/sheet/3.4bpp"
