# `/tools`

To use the script, ROM file must be placed in the root as `rmz3/baserom.gba`.

Scripts require Deno runtime installation.

```sh
rmz3/tools
      ├── common        # Common subroutine for /dev, /dumper, /misc
      ├── dev           # This directory contains the build scripts used when building rmz3.gba.
      ├── dumper        # This directory contains data dumpers for decompilation work.
      ├── scaninc       # 後述
      ├── gbagfx        # 画像データをGBA用のフォーマットに変換するプログラム
      ├── mid2agb       # midi音源をGBA用のアセンブリコードに変換するプログラム
      └── misc          # Misc scripts useful for Decomp
```

## scaninc

agbcc (GBA時代のgcc) に 依存関係ファイル `.d` を出力する機能がないのでそれを行うプログラム

```sh
$ scaninc [-I INCLUDE_PATH] [-M DEPENDENCY_OUT_PATH] <filepath>

# e.g.
$ ./tools/scaninc/scaninc -I include -M test.d src/stage/ocean/landscape.c
```

```c
// src/stage/ocean/landscape.c
#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
// ...
#include "stage/ocean/layer.h"
// ...
#include "stage/ocean/landscape.h"
```

```makefile
# test.d
# scaninc がinclude先を見つけられなかった場合は無視される (-I で include を教えないと blink.h などは依存関係に入らない)
test.o: ... include/blink.h ...  stage/ocean/landscape.h stage/ocean/layer.h 
test.d: ... include/blink.h ...  stage/ocean/landscape.h stage/ocean/layer.h 
```
