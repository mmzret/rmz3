# gbagfx

> [!WARNING]
> このREADMEはツールの作者 (YamaArashi) によって書かれたものではなく、ツールのユーザ (Akatsuki105) によって書かれたものです。
> コード自体は `pret/pokefirered` のそれと同じです。

GBAで扱うグラフィックデータを処理するツール

このレポジトリでは"rmz3.gba" をビルドする際に ".png" などのデータをGBAのタイルデータやパレットデータに変換するために使っている

## Usage

```sh
$ gbagfx INPUT_PATH OUTPUT_PATH [OPTIONS] # INPUT_PATH, OUTPUT_PATH の拡張子によって、変換の内容が決まる
```

### png から GBAのタイルデータ を生成

```sh
$ gbagfx input.png output.(1bpp|4bpp|8bpp) [OPTIONS]

Arguments:
  input.png:  画像の幅と高さは必ず8の倍数  
              以後、 tw は input.png 画像の 幅/8, th は input.png 画像の 高さ/8 とする (tw: Tile Width, th: Tile Height)  
              tw*th が num_tiles で指定するタイル数より多い場合、余ったタイルは (png画像の見栄えのための) パティングタイルとみなされ、
              生成される GBAのタイルデータ には含まれない  
              -Wnum_tiles オプション や -Werror=num_tiles オプション を有効にすると、パティングタイル に 0以外が含まれる際に、アラートやエラーを出す
  output.(1bpp|4bpp|8bpp): 出力するタイルデータ

Options:
  -num_tiles <N>    8x8px のタイル数を指定 (default tw*th)
  -Wnum_tiles       パティングタイルに 0 以外が含まれる際に、アラートを出して、 num_tiles の値を無視して、tw*th のタイル数で出力
  -Werror=num_tiles パティングタイルに 0 以外が含まれる際に、エラーを出して終了 ("num_tiles" は変数ではなく文字通り "-Werror=num_tiles" とコマンドに書く)
  -mwidth  <N>      メタタイルの幅, 後述 (default 1)
  -mheight <N>      メタタイルの高さ, 後述 (default 1)
  -plain            GBAのbitmap形式で出力するオプション 基本的に使わないと思うので未調査
  -data_width <N>   -plain 時に使用するオプションだが、-plain オプションがあまり使われないため、詳細は未調査
```

**メタタイル(metatile) について**

```
たとえば png のサイズ が tw=8, th=8 (つまり 64x64 px) のとき、

デフォルト(-mwidth 1 -mheight 1) の場合 では、pngのタイルを次の順番で処理する
  00 01 02 03 04 05 06 07
  08 09 0A 0B 0C 0D 0E 0F
  10 11 12 13 14 15 16 17
  18 19 1A 1B 1C 1D 1E 1F
  20 21 22 23 24 25 26 27
  28 29 2A 2B 2C 2D 2E 2F
  30 31 32 33 34 35 36 37
  38 39 3A 3B 3C 3D 3E 3F

-mwidth 2 -mheight 4 の場合 では、次の順番で処理される (つまり、pngが 16x32px のメタタイルが並んだものとみなされる)
  00 01 08 09 10 11 18 19
  02 03 0A 0B 12 13 1A 1B
  04 05 0C 0D 14 15 1C 1D
  06 07 0E 0F 16 17 1E 1F
  20 21 28 29 30 31 38 39
  22 23 2A 2B 32 33 3A 3B
  24 25 2C 2D 34 35 3C 3D
  26 27 2E 2F 36 37 3E 3F
```

### GBAのタイルデータ を png に変換

```sh
$ gbagfx input.(1bpp|4bpp|8bpp) output.png [OPTIONS]

Options:
  -width <N> pngのタイル幅を指定, mwidth, mheight　より優先 (default 1)
  -mwidth <N> pngのメタタイル幅を指定 (default 1)
  -mheight <N> pngのメタタイル高さを指定 (default 1)
  -palette <PATH>  パレットデータのパスを指定 (指定しないならば grayscale)
  -tilemap <PATH>  必要ならタイルマップデータのパスを指定
  -object スプライトのときに指定すると、色番号0を透過色として扱う
```

### パレットデータ関連

```
.gbapal:  GBAPAL, 単に RGB555 をそのまま並べたバイナリデータ (ヘッダとかなく本当に RGB555 が並んでいるだけ)
.pal:     JASC-PAL, Jasc社(現在はCorel社)のペイントソフト "Paint Shop Pro" のパレットデータ
```

```sh
$ gbagfx input.png    output.gbapal            # png から GBAPAL を生成
$ gbagfx input.png    output.pal               # png から JASC-PAL を生成
$ gbagfx input.gbapal output.pal               # GBAPAL を JASC-PAL に変換
$ gbagfx input.pal    output.gbapal [OPTIONS]  # JASC-PAL を GBAPAL に変換

Options:
  -num_colors <N>  (JASC-PAL(".pal")からGBAPAL(".gbapal")への変換のときにのみ有効)パレットの色数を指定 (指定しない場合は、ファイルから自動判定)
```

> [!NOTE]
> `.pal -> .gbapal` への変換では、bit15(ブレンド時の緑のLSB)は0になる

## データの圧縮,展開

どの圧縮形式も、GBAのBIOS関数で展開できる。

```
.huff: Huffman
.lz: LZ77
.rl: Run-Length
```

```sh
$ gbagfx input output.(huff|lz|rl)  # inputを 拡張子に対応する圧縮形式で圧縮
$ gbagfx input.(huff|lz|rl) output  # inputを 拡張子に対応する圧縮形式で展開
```

## フォント関連

このREADMEを書いたAkatsuki105は、フォント関連の機能は使っていないため、詳細は未調査

```
.latfont: ラテンフォント
.hwjpnfont: 半角日本語フォント
.fwjpnfont: 全角日本語フォント
```

```sh
$ gbagfx input.(latfont|hwjpnfont|fwjpnfont) output.png  # フォント を png に変換
$ gbagfx input.png output.(latfont|hwjpnfont|fwjpnfont)  # png から フォント を生成
```
