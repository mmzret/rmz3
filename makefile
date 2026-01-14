# TODO: Refactor rule dependencies.
# あまり美しくないけど、Makefileの書き方毎回忘れるのでコメントで色々 GNU Make の文法のメモを残す。
# オプション
#   make -C: カレントディレクトリを変更して実行する
#   make -f: ファイル名 を指定して make を実行する (ファイル名が Makefile でないときに使う)
# 自動変数 (Automatic Variables)
#   $@: ルールのターゲット
#   $<: 依存関係の一番最初
#   $^: すべての依存関係
#   例えば
#   aaa: bbb ccc
#     @echo $@     # => aaa
#     @echo $<     # => bbb
#     @echo $^     # => bbb ccc
#   のとなる
# 
# 変数の代入
#   "=":  遅延評価(変数が使われるときに評価する)
#   ":=": 即時評価(変数が定義されたときに評価する), 基本的にこれを使う
#   "?=": 未定義の場合にのみ = と同じ動作をする
# 
# パターンルール
#   %.o: %.c
#     レシピ
#   のようなルールは パターンルール(Pattern Rules) と呼ばれ、この例では、 任意の .o ファイルをビルドするために 対応する .c ファイルを使用することを指定している。
#   % はワイルドカードで、任意の文字列にマッチする。(bash の * とは違う)
#   例えば、 ビルドするものが、 foo.o と bar.o なら、
#     foo.o: foo.c
#       レシピ
#     bar.o: bar.c
#       レシピ
#   と同じ意味になる。
#
# 静的パターンルール
#   $(objects): %.o: %.c
#    $(CC) -c $(CFLAGS) $< -o $@
#   のようなルールは 静的パターンルール(Static Pattern Rules) と呼ばれ、 $(objects) の *.o ファイルをビルドするときだけ適用されるパターンルールを定義するためのもの
#
# シングルクォートとダブルクォート(レシピ内)
#   VAR = hoge
#   all:
#    @echo '$$VAR'   # => $VAR
#    @echo "$$VAR"   # => hoge
#
# デバッグ
#  nオプション
#    "-n"オプションをつけて make を実行すると、実際にはコマンドを実行せずに、実行されるコマンドを表示する。
#  変数表示
#    $(warning MAKE = $(MAKE)) # => MAKE = /usr/xxx/bin/make
# 

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

# Enabled by `make modern`
MODERN ?= 0

all: $(ROM) compare

# Build target
NAME := rmz3
ROM := $(NAME).gba
ELF := $(NAME).elf

# Tools
TOOL = $(DEVKITARM)/bin
ifeq ($(MODERN),1)
  AGBCC := $(TOOL)/arm-none-eabi-gcc
else
  AGBCC := tools/agbcc/bin/agbcc$(EXE)
endif

# arm-none-eabi-as を GBA用にカスタムしたもので charmap機能が便利なので使っている
# ...が、正直全部 arm-none-eabi-as (AS) でビルドした方が楽な気がしてきた。
AGBASM := tools/agbasm$(EXE)

AS := $(TOOL)/arm-none-eabi-as
LD = $(TOOL)/arm-none-eabi-ld
OBJCOPY = $(TOOL)/arm-none-eabi-objcopy

include make_tools.mk

# Flags
ARCH := -mcpu=arm7tdmi -march=armv4t -mthumb 
ASFLAGS := $(ARCH) -mthumb-interwork -g
AGBASM_FLAGS := $(ASFLAGS) --agbasm-colon-defined-global-labels --agbasm-multiline-macros --agbasm-charmap --agbasm-no-gba-thumb-after-label-disasm-fix

CFLAGS := -mthumb-interwork  -Wimplicit -Wparentheses -Werror -O2 -fshort-enums
ifeq ($(MODERN),1)
	CPPFLAGS := -I $(DEVKITARM)/arm-none-eabi/include -iquote include -DMODERN=$(MODERN)
	CFLAGS += $(ARCH) $(CPPFLAGS) -Wno-pointer-to-int-cast -fno-toplevel-reorder -fno-aggressive-loop-optimizations -Wno-address-of-packed-member
	LIBPATH := -L $(shell dirname $(shell $(AGBCC) --print-file-name=libgcc.a)) -L $(shell dirname $(shell $(AGBCC) --print-file-name=libc.a))
else
	CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -DMODERN=$(MODERN)
	CFLAGS += -fhex-asm
	LIBPATH := -L tools/agbcc/lib
endif
LDFLAGS := $(LIBPATH) -lgcc -lc

include assets.mk

# アセンブラに agbasm を使うので特別処理
ASM_STRING := asm/string.s

ASM_DATAS := $(SONG_ASMS) $(SPRITE_TABLES) data/tilesets/offsets.s
ASM_CODES := $(wildcard asm/*.s) $(wildcard asm/*/*.s) src/libs/m4a_1.s
ASM_SRCS := $(ASM_CODES) $(ASM_DATAS)
ASM_OBJS := $(ASM_SRCS:.s=.o)

# *.s から *.o を作るが、 ファイルによっては別アセンブラを使う必要があったり、 プリプロセッサを通す必要があったりするため、 いくつかの変数に分けて管理している。
# gccプリプロセッサで処理するもの
ASM_SCRIPTS := $(wildcard asm/scripts/*.s)
# ASM_SCRIPTS, ASM_STRING を除いたもの (普通にアセンブリできるもの)
GCCASFILE := $(filter-out $(ASM_STRING) $(ASM_SCRIPTS), $(ASM_SRCS))

C_SRCS := $(shell find src -type f -name '*.c')
C_OBJS := $(C_SRCS:.c=.o)
C_DEPS := $(C_SRCS:.c=.d)

ifneq ($(MODERN),1)
# Special configurations required for lib files
src/mmbn4.o: CFLAGS += -mno-thumb-interwork
src/libs/agb_sram.o: CFLAGS := -O -mthumb-interwork
src/libs/m4a.o: AGBCC := tools/agbcc/bin/old_agbcc$(EXE)
endif

ifeq ($(MODERN),1)
	LDSCRIPT := ld_script_modern.ld
else
	LDSCRIPT := ld_script.ld
endif

######## ルール定義 #############

# RULES_NO_SCAN: ビルドを伴わないルールの一覧
RULES_NO_SCAN := assets clean clean-code clean-assets
.PHONY: all check compare compile $(RULES_NO_SCAN)

# ビルドを伴うルールの場合は、アセットの生成 と 依存関係ファイル　の読み込み が必要になる。
# 現在、アセットが .h　ファイルを生成したり、　agbcc に依存関係ファイルを生成させる機能がなかったりと、　アセットの生成に依存するコードの依存関係を正しくMakeに伝えるのが難しいため、　ビルドを伴うルールの場合は必ず make assets を実行してからビルドするようにしている。
NODEP ?= 0
DO_BUILD ?= 1
ifneq (,$(MAKECMDGOALS))
	ifeq (,$(filter-out $(RULES_NO_SCAN),$(MAKECMDGOALS)))
		NODEP := 1
		DO_BUILD := 0
	endif
endif

# ビルドを伴うルールの場合は tool と assets をビルドする
ifeq ($(DO_BUILD),1)
EXIT_CODE = $(shell $(MAKE) -f make_tools.mk > /dev/null 2>&1; echo $$?)
ifneq ($(EXIT_CODE),0)
  $(error make_tools.mkが終了コード $(EXIT_CODE) で失敗しました)
endif

EXIT_CODE = $(shell $(MAKE) -j8 assets > /dev/null 2>&1; echo $$?)
ifneq ($(EXIT_CODE),0)
  $(error make assets が終了コード $(EXIT_CODE) で失敗しました)
endif
endif

check: $(ROM) compare

# This is a build method for romhacks and builds with gcc specified by the user.
modern: ; @$(MAKE) $(ROM) -j8 MODERN=1
compare: $(ROM)
	@sha1sum -c $(NAME).sha1

clean: clean-code clean-assets
	rm -f $(ELF)

# Cファイルは、AGBCCの都合で一旦アセンブリに変換してからオブジェクトファイルにする必要があるので .s も中間生成される
clean-code:
	@rm -f $(C_SRCS:.c=.s) $(C_OBJS) $(C_DEPS)
	@rm -f $(ASM_OBJS)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

# Linker rule
$(ELF): $(ASM_OBJS) $(C_OBJS) $(GFX_HDR) ld_script.ld
	$(LD) -T $(LDSCRIPT) -Map $(NAME).map -o $@ $(ASM_OBJS) $(C_OBJS) $(GFX_HDR) $(LDFLAGS)

$(C_OBJS): %.o: %.c
ifeq ($(MODERN),1)
	@$(AGBCC) $(CFLAGS) $< -c -o $@
else
	$(CPP) $(CPPFLAGS) $< | $(AGBCC) $(CFLAGS) -o $(subst .c,.s,$<)
	@echo ".text\n\t.align\t2, 0\n" >> $(subst .c,.s,$<)
	$(AS) $(ASFLAGS) $(subst .c,.s,$<) -o $@ 
endif

# 依存関係ファイル (.d), agbcc には依存関係を生成する機能がないっぽいため、 scaninc ツールを使って生成する
SCANINC := tools/scaninc/scaninc$(EXE)
$(C_DEPS): %.d: %.c
	$(SCANINC) -M $@ -I include $<

# NODEP が 1 のときは依存関係ファイルを読み込まない、これをしないと make clean とかのときに不要な .dファイルを作ろうとしてしまう
ifneq ($(NODEP),1)
-include $(C_DEPS)
endif

# AGBASM を使うための特別ルール
asm/string.o: asm/string.s $(STR_BINS)
	$(AGBASM) $(AGBASM_FLAGS) -o $@ $<

$(ASM_SCRIPTS:.s=.o): %.o: %.s
	$(CPP) $(CPPFLAGS) $< | $(AS) $(ASFLAGS) -o $@ -
