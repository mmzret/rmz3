.balign 4, 0
.section .rodata

@ TODO: src/bg0/text.c に移す (pret/bin2c か 新しめの pret/preproc で scaninc に対応した incbin ができる)

.global gFontTall
gFontTall:  @ 0x080ff17c, 8x16px, 会話で使うメインのフォント, charmap.txt の文字コードで描画される
  .incbin "graphics/font/tall.4bpp"

.global gFontJIS
gFontJIS:  @ 0x0810597c, 8x8px, JIS文字列用のフォント (ミニゲームのスコア表示で使っているが、本来はデバッグフォントかも?)
  .incbin "graphics/font/jis.4bpp"

.global gFontBigPal
gFontBigPal: @ 0x0810697c, gFontBig の色データ, パレット6個分 (=96色)
  @ gbagfx は bit15 が 1 のパレットを扱えないので、一旦バイナリのまま扱う
  .incbin "graphics/font/big.rgb565"

.global gFontBig
gFontBig: @ 0x08106a3c, 16x16px, タイトル画面の「つづきから」などで使うフォント, charmap.txt の BIG(文字コード 0xF7) を使うと描画される
  .incbin "graphics/font/big.4bpp"
