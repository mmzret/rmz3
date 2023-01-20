# Palette

Palette IWRAM buffer is `0x03002AC0..03002EBF`(`u16[512]`)

Basically, this buffer is flashed into Palette RAM (`0x05000000..050003FF`) every frame.

## Obj palette

`0x03002CC0..03002EBF` is Obj palette buffer.

Obj palette buffer has following 256 entries.

```
基本的にずっとこれ
  000..015: Zero body color
  016..032: Zsaber color
  048..064: Elf color
  192..208: Zero shadow color

状況によって変わる
  064..080:
    Ciel color
    Omega Zero color
  080..096:
    Omega Zero saber color
```

