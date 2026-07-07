.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_121
gGraphicHeader_Sprite_weapon_unk_121:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_121_0-. @ src
	.4byte 416 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 104, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_121_1-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 2
	.4byte gGraphicHeader_Sprite_weapon_unk_121_2-. @ src
	.4byte 256 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 64, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_121_0:
	.incbin "sprites/dynamic/weapon/unk_121/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_121_1:
	.incbin "sprites/dynamic/weapon/unk_121/sheet/1.4bpp"

gGraphicHeader_Sprite_weapon_unk_121_2:
	.incbin "sprites/dynamic/weapon/unk_121/sheet/2.4bpp"
