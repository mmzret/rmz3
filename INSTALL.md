# Installation

> [!NOTE]
> `rmz3` uses the same toolchain as [pret](https://github.com/pret), so follow [pret's INSTALL.md](https://github.com/pret/pokeemerald/blob/6eb688876d34d43096a276e690ae46b8853e03ac/INSTALL.md).

## Prerequisites

In addition to [pret's toolchain](https://github.com/pret/pokeemerald/blob/6eb688876d34d43096a276e690ae46b8853e03ac/INSTALL.md), `rmz3` requires the additional software.

- [Deno](https://deno.com/): Used as a build script.

## Installation

```sh
> git clone https://github.com/mmzret/rmz3

# install agbcc
> git clone https://github.com/pret/agbcc
> cd agbcc
> ./build.sh
> ./install.sh ../rmz3
> cd ../

# Build rmz3
> cd ./rmz3
> make
```

## Modern

There is a `modern` option to build using the latest C compiler instead of the original C compiler (agbcc), but currently **THIS OPTION DOESN'T WORK**.
This is because some addresses are still hardcoded, and relocation causes them to function incorrectly.

## Directory structure

```sh
rmz3/
  ├── asm                    # まだデコンパイルが完了していないARMアセンブリをここに置いています。ここのファイルは直接アセンブルしないで 別のディレクトリ(ほとんど `src/`) のファイルからインクルードして利用しています。
  ├── src                    # gcc (AGBCC or devkitARM) でコンパイル/アセンブルするC/ARMアセンブリのソースコードを置いています。
  ├── include                # ヘッダファイルを置いています。 また include/constants/ のヘッダファイルは、C/ARMアセンブリのソースコードからインクルードして利用することを想定しています。
  ├── data/graphics/sprites  # ゲームアセットが入っていますが、分類が不十分なので、整理する予定です。 
  ├── linker                 # リンカスクリプトを置いています。 vanilla と modern ビルドの共通部分をここに置いています。
  ├── sound                  # サウンド関連のファイルを置いています。(.s が入っていますが、個人的には後で .inc にして、 src からインクルードする形にしたいです)
  └── tools                  # ビルドツールやデータダンプツールを置いています。詳細は tools/README.md を参照してください。
```
