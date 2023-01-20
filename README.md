# rmz3

```
This project is partially encrypted due to legal issues. You will need to decrypt it with your Mega Man Zero 3 ROM file in order to read the code and build.

For Japanese:
  このプロジェクトは法律の問題上、デコンパイルしたソースコードの一部を暗号化しています。
  暗号化されたコードを読んだり、このプロジェクトのビルドを行うためにはあなた自身のロックマンゼロ3のROMファイルで復号化を行う必要があります。
```

This is a disassembly of Mega Man Zero 3 Japanese version.

SHA1: `ff7a801776dc76e6d8c7ef73a6660ae732934a3f`

To set up the repository, see [INSTALL.md](INSTALL.md).

## Decrypt

For avoiding legal issues, a part of src file is encrypted by original ROM. So, if you want to build this repository, Original ROM is needed.

For decryption, 

1. Put your original ROM as `./baserom.gba`.
2. Run `make decrypt` (Deno runtime is needed)

## Disassemble 

1. Dump cfg file by `tools/cfg_dumper.py` from Ghidra.
2. Disassemble ROM file by [camthesaxman/gbadisasm](https://github.com/camthesaxman/gbadisasm).

