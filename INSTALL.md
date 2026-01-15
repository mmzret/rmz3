# Installation

> [!NOTE]
> `rmz3` uses the same toolchain as [pret](https://github.com/pret), so follow [pret's INSTALL.md](https://github.com/pret/pokeemerald/blob/6eb688876d34d43096a276e690ae46b8853e03ac/INSTALL.md).

## Prerequisites

In addition to [pret's toolchain](https://github.com/pret/pokeemerald/blob/6eb688876d34d43096a276e690ae46b8853e03ac/INSTALL.md), `rmz3` requires the additional software.

- [Deno](https://deno.com/): Used as a build script.
- [Rust](https://rust-lang.org/): Used for text build, I'll remove it in the future.

## Installation

```sh
> git clone https://github.com/mmzret/rmz3

# install agbcc
> git clone https://github.com/pret/agbcc
> cd agbcc
> ./build.sh
> ./install.sh ../rmz3
> cd ../

# install agbasm(custom arm-none-eabi-as)
> git clone https://github.com/luckytyphlosion/agbcc -b new_layout_with_libs agbasm
> cd agbasm
> make binutils
> cp ./gas/as-new ../rmz3/tools/agbasm # if windows, add .exe

# install mmzret/rmz-text-compiler
> cd ../
> git clone https://github.com/mmzret/rmz-text-compiler
> cd ./rmz-text-compiler
> cargo build --release
> cp ./target/release/rmz-text-compiler ../rmz3/tools/rmz-text-compiler

# Build rmz3
> cd ../rmz3
> make
```

## Modern

There is a `modern` option to build using the latest C compiler instead of the original C compiler (agbcc), but ROMs built this way are currently unplayable.  
This is because some addresses are still hardcoded, and relocation causes them to function incorrectly.
