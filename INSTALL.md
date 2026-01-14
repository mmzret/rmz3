# Installation

Run the following commands (first, see [this](#macos) if you are on **macOS** or [this](#old-windows) if you are on **old Windows**):

## Prerequisites

You must install the devkitARM toolchain of devkitPro and add its environment variables.

```sh
export DEVKITPRO=/opt/devkitpro
echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
export DEVKITARM=$DEVKITPRO/devkitARM
echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc
```

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

## Old Windows

*For Windows 8.1 and earlier*

Download and run the [Cygwin](https://www.cygwin.com/install.html) setup, leaving the default settings intact. At "Select Packages", set the view to "Full" and choose to install the following:

- `make`
- `git`
- `gcc-core`
- `gcc-g++`
- `libpng-devel`

Additionally, there are extra optional tools which require installing the following packages, although they are not necessary to build:

- `python-3`

In the Cygwin command prompt, enter the commands.

If the command for building rmz3.gba does not work, run `nproc` and use that value instead of `$(nproc)` for `make`.


## Windows 10

Install the [Windows Subsystem for Linux](https://docs.microsoft.com/windows/wsl/install-win10), and run the commands.

