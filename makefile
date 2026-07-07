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

NAME := rmz3
# MODIFIERS はデバッグビルドなどで debug のように設定されることがあるので、 MODIFIERS を使う場合は := ではなく = で遅延評価すること
MODIFIERS := 

# The “modern” option is meant to build using the latest toolchain instead of agbcc (an older version of gcc used in rmz3), but because there are still hard-coded addresses in this project, 
# the rom built with “modern” won’t run all the way through, as the linking process won’t complete correctly.
ifneq ($(filter modern clean-code-modern,$(MAKECMDGOALS)),)
MODIFIERS := $(MODIFIERS)-modern
MODERN := 1
endif

MODERN ?= 0

# Build target
RONNAME = $(NAME)$(MODIFIERS)
BUILD_DIR := build/$(RONNAME)
ROM = $(RONNAME).gba
ELF = $(RONNAME).elf

all: $(ROM) compare

# Tools
TOOL = $(DEVKITARM)/bin
ifeq ($(MODERN),1)
  AGBCC := $(TOOL)/arm-none-eabi-gcc
else
  # agbcc は gcc 2.95.1 か gcc 2.95.2
  AGBCC := tools/agbcc/bin/agbcc$(EXE)
endif

AS := $(TOOL)/arm-none-eabi-as
LD = $(TOOL)/arm-none-eabi-ld
OBJCOPY = $(TOOL)/arm-none-eabi-objcopy

# macOS では arm-none-eabi-cpp を使用してください。macOS のデフォルトコンパイラ clang であり、clang のプリプロセッサは .s ファイルをプリプロセスする際に \u 文字を検出すると警告を表示します。これは Unicodeリテラルを期待しているためです。
# ただし、binutils-arm-none-eabi をインストールする環境では、このツールがデフォルトで付属していないため、無条件に arm-none-eabi-cpp を使用することはできません。
ifneq ($(MODERN),1)
# Vanilla
  ifeq ($(shell uname -s),Darwin)
# macOS
    CPP := $(TOOL)/arm-none-eabi-cpp
  else
    CPP := $(CC) -E
  endif
else
# Modern
  CPP := $(TOOL)/arm-none-eabi-cpp
endif

include make_tools.mk

# Flags
ARCH := -mcpu=arm7tdmi -march=armv4t -mthumb 
ASFLAGS := $(ARCH) -mthumb-interwork -g

CFLAGS := -mthumb-interwork  -Wimplicit -Wparentheses -Werror -O2 -fshort-enums
ifeq ($(MODERN),0)
# Vanilla
# undef: 組み込みマクロ無効, std は 指定しなくても gnu89 っぽい？
	CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -undef -std=gnu89 -DMODERN=$(MODERN)
	CFLAGS += -fhex-asm
	LIBPATH := -L ../../tools/agbcc/lib
else
# Modern
	CPPFLAGS := -I $(DEVKITARM)/arm-none-eabi/include -iquote include -DMODERN=$(MODERN)
	CFLAGS += $(ARCH) $(CPPFLAGS) -Wno-pointer-to-int-cast -fno-toplevel-reorder -fno-aggressive-loop-optimizations -Wno-address-of-packed-member
	LIBPATH := -L $(shell dirname $(shell $(AGBCC) --print-file-name=libgcc.a)) -L $(shell dirname $(shell $(AGBCC) --print-file-name=libc.a))
endif
LDFLAGS := $(LIBPATH) -lgcc -lc

include assets.mk

ASM_s := $(shell find src -type f -name '*.s') $(SONG_ASMS)
ASM_s_OBJS := $(addprefix $(BUILD_DIR)/, $(ASM_s:.s=.o))

# cppを通すアセンブリ
# 大文字のSだとファイル名の大文字小文字を区別しないapfsだとおかしくなるのでsx, ref: https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html
ASM_sx := $(shell find src -type f -name '*.sx')
ASM_sx_OBJS := $(addprefix $(BUILD_DIR)/, $(ASM_sx:.sx=.o))

ASM_OBJS := $(ASM_s_OBJS) $(ASM_sx_OBJS)
ASM_DEPS := $(ASM_s_OBJS:.o=.d)

# PRERPOC を使うので特別処理 (拡張子をユニークなものにすべき?)
ASM_USE_PREPROC := $(wildcard src/data/strings/*.s) $(wildcard src/data/texts/*.s) $(wildcard src/data/bg/*.s) $(wildcard src/data/graphic_table/*.s)
ASM_USE_PREPROC_OBJS := $(addprefix $(BUILD_DIR)/, $(ASM_USE_PREPROC:.s=.o))

C_SRCS := $(shell find src -type f -name '*.c')
C_OBJS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))
C_DEPS := $(C_OBJS:.o=.d)

OBJS := $(ASM_OBJS) $(C_OBJS)
OBJS_REL := $(patsubst $(BUILD_DIR)/%,%,$(OBJS))

SUBDIRS := $(sort $(dir $(OBJS)))
$(shell mkdir -p $(SUBDIRS))

ifneq ($(MODERN),1)
# Special configurations required for lib files
$(BUILD_DIR)/src/mmbn4.o: CFLAGS := -O -mno-thumb-interwork
$(BUILD_DIR)/src/libs/agb_sram.o: CFLAGS := -O -mthumb-interwork
# 外部ライブラリは old_agbcc (gcc 2.95) でビルドされているらしい
$(BUILD_DIR)/src/libs/m4a.o: AGBCC := tools/agbcc/bin/old_agbcc$(EXE)
endif

LDSCRIPT = ld_script$(MODIFIERS).ld
LD_INC := $(wildcard linker/*.txt)
LD_BUILD := $(addprefix $(BUILD_DIR)/, $(LD_INC))

######## ルール定義 #############

# RULES_NO_SCAN: ビルドを伴わないルールの一覧
RULES_NO_SCAN += assets clean clean-code clean-code-modern clean-assets
.PHONY: all modern compare compile $(RULES_NO_SCAN)

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

# SHELLSTATUS: 直前に実行したコマンドの終了ステータスを格納する特殊変数 (GNU Make 4.3 以降のみらしいので、未定義なら互換性のために 0 を設定しておく)
.SHELLSTATUS ?= 0

# ビルドを伴うルールの場合は tool と assets をビルドする
ifeq ($(DO_BUILD),1)
  # やっていることは単なる make -f make_tools.mk
  # あとの仰々しい部分は make -f make_tools.mk のコマンドをターミナルに出すのと、 エラーが起きたときに終了するためのもの
  $(foreach line, $(shell $(MAKE) -f make_tools.mk | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))
  ifneq ($(.SHELLSTATUS),0)
    $(error Errors occurred while building tools. See error messages above for more details)
  endif
  # Oh and also generate mapjson sources before we use `SCANINC`.
  $(foreach line, $(shell $(MAKE) -j8 assets | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))
  ifneq ($(.SHELLSTATUS),0)
    $(error Errors occurred while building assets. See error messages above for more details)
  endif
endif

modern: $(ROM)

compare: $(ROM)
	@sha1sum -c $(NAME).sha1

clean: clean-code clean-assets

clean-code:
	rm -rf ./$(BUILD_DIR)
	rm -f $(ELF)

clean-code-modern: clean-code

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

# Linker rule
$(LDSCRIPT): $(LD_BUILD)

$(LD_BUILD): $(BUILD_DIR)/linker/%.txt: linker/%.txt
	@mkdir -p $(dir $@)
	@cp $< $@

$(ELF): $(LDSCRIPT) $(OBJS)
	@cd $(BUILD_DIR) && $(LD) -T ../../$< -Map $(RONNAME).map -o ../../$@ $(OBJS_REL) $(LDFLAGS)

$(C_OBJS): $(BUILD_DIR)/%.o: %.c
ifeq ($(MODERN),1)
	@$(AGBCC) $(CFLAGS) $< -c -o $@
else
	$(CPP) $(CPPFLAGS) $< | $(AGBCC) $(CFLAGS) -o $(BUILD_DIR)/$(subst .c,.s,$<)
	@echo ".text\n\t.align\t2, 0\n" >> $(BUILD_DIR)/$(subst .c,.s,$<)
	$(AS) $(ASFLAGS) $(BUILD_DIR)/$(subst .c,.s,$<) -o $@ 
endif

# 依存関係ファイル (.d), agbcc には依存関係を生成する機能がないっぽいため、 scaninc ツールを使って生成する
SCANINC := tools/scaninc/scaninc$(EXE)
$(C_DEPS): $(BUILD_DIR)/%.d: %.c
	$(SCANINC) -M $@ -I include $<

# NODEP が 1 のときは依存関係ファイルを読み込まない、これをしないと make clean とかのときに不要な .dファイルを作ろうとしてしまう
ifneq ($(NODEP),1)
-include $(C_DEPS)
endif

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.sx
	$(TOOL)/arm-none-eabi-gcc -c $(CPPFLAGS) $(ASFLAGS) $< -o $@

$(ASM_s_OBJS:.o=.d): $(BUILD_DIR)/%.d: %.s
	$(SCANINC) -M $@ -I include $<

# $(ASM_sx_OBJS:.o=.d): $(BUILD_DIR)/%.d: %.sx
# $(SCANINC) -M $@ -I include $<

ifneq ($(NODEP),1)
-include $(ASM_DEPS)
endif

# PREPROC
PREPROC := tools/preproc/preproc$(EXE)
$(ASM_USE_PREPROC_OBJS): $(BUILD_DIR)/%.o: %.s
	$(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -
