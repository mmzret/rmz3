.include "asm/macros.inc"

.balign 4
.section .rodata

.global gFont
gFont:  @ 0x080ff17c
  .incbin "graphics/font/font.4bpp"

.balign 4, 0
.global gFontBold
gFontBold:  @ 0x0810597c, リザルト画面などで使うフォント
  .incbin "graphics/font/font_bold.4bpp"

.balign 4, 0
.global gFontPalette
gFontPalette: @ 0x0810697c
  .incbin "graphics/font/font.rgb565"

.balign 4, 0
.global gFontBig
gFontBig: @ 0x08106a3c, タイトル画面の「つづきから」のようなフォント
  .incbin "graphics/font/font_big.4bpp"
