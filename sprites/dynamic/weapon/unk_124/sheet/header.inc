.balign 4, 0

.global gGraphicHeader_Sprite_weapon_unk_124
gGraphicHeader_Sprite_weapon_unk_124:
	@ Graphic 0
	.4byte gGraphicHeader_Sprite_weapon_unk_124_0-. @ src
	.4byte 512 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 128, BPP4 	@ rowsize(unused), props

	@ Graphic 1
	.4byte gGraphicHeader_Sprite_weapon_unk_124_1-. @ src
	.4byte 192 | (48 << 22) 	@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
	.2byte 48, BPP4 	@ rowsize(unused), props

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gGraphicHeader_Sprite_weapon_unk_124_0:
	.incbin "sprites/dynamic/weapon/unk_124/sheet/0.4bpp"

gGraphicHeader_Sprite_weapon_unk_124_1:
	.incbin "sprites/dynamic/weapon/unk_124/sheet/1.4bpp"
