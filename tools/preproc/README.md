# preproc

> [!WARNING]
> このREADMEはツールの作者 (YamaArashi) によって書かれたものではなく、ツールのユーザ (Akatsuki105) によって書かれたものです。

`pret/pokefirered` の `preproc` をカスタムしたものです (点字関連のコードを削除したりなど)

この時代のGCCでは、文字列リテラルをUTF8以外でエンコーディングできないっぽいので、preprocで処理する必要がある

## Usage

```sh
Usage:
  preproc [OPTIONS] SRC_FILE CHARMAP_FILE

Arguments:
  SRC_FILE      is the source file to preprocess. 
                It must have a .s, .c, or .i extension. (.s for assembly, .c or .i for C)
  CHARMAP_FILE  is the charmap file that defines the mapping from characters to byte sequences. e.g. rmz3/charmap.txt

Options:
  -i denotes if input is from stdin
  -e enables enum handling (only for assembly sources (.s))
```

## アセンブリに対する preproc

```assembly
; :: を グローバルラベルの定義とみなす
LABEL::
; ↓
LABEL: ; .global LABEL

; .string ディレクティブを見つけると 引数の CHARMAP_FILE を参照して、.byte 列に変換する
.string "あいうえお$"
; ↓
; rmz3/charmap.txt の場合
.byte 0x26, 0x28, 0x2A, 0x2C, 0x2E, 0xFF

; .include ディレクティブがあれば、そのファイルも preproc で処理して、処理結果を展開する (再帰的に処理する)
.include "data.inc"
; ↓
; data.inc の内容が
; DATA::
; .string "あいうえお$"
; だったなら
DATA: ; .global DATA
.byte 0x26, 0x28, 0x2A, 0x2C, 0x2E, 0xFF
```

## C言語に対する preproc

TODO
