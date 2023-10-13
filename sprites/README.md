# sprites

This directory contains the sprites used in the game.

There are two types of sprites, "Dynamic sprite" and "Static sprite".

```
Dynamic sprite:
  There are multiple graphics data, which are loaded into VRAM as needed for the Entity's movements.
  If the size of graphics data is large, Dynamic sprite should be used since Static sprite takes up a large amount of VRAM memory.
  Japanese translation:
    モーションに応じて、必要になったシートを逐次ロードする。
    グラフィックデータのサイズが大きい場合は、StaticだとVRAMメモリを圧迫するのでDynamicにすべきと思われる。

Static sprite:
  Only one graphic data, so load that graphics data into VRAM first.
  If the graphics data is small or if a lot of VRAM is available, sprite should be Static sprite.
  Japanese translation:
    シートは1つだけで逐次ロードは必要ない。
    グラフィックデータが小さかったり、VRAMに余裕がある場合はStaticにすべきと思われる。
```

Please use [mmzret/mmz3e](https://github.com/mmzret/mmz3e) for viewing the sprite animations.
