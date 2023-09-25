# TODO: Refactor rule dependencies.

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

# Enabled by `make modern`
MODERN ?= 0

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
AS = tools/binutils/bin/arm-none-eabi-as
LD = $(TOOL)/arm-none-eabi-ld
OBJCOPY = $(TOOL)/arm-none-eabi-objcopy
OBJDUMP := $(TOOL)/arm-none-eabi-objdump

# Flags
ARCH := -mcpu=arm7tdmi -march=armv4t -mthumb 
CFLAGS := -mthumb-interwork  -Wimplicit -Wparentheses -Werror -O2 -fshort-enums
ASFLAGS := $(ARCH) -mthumb-interwork  -g --agbasm-colon-defined-global-labels --agbasm-multiline-macros --agbasm-charmap --agbasm-no-gba-thumb-after-label-disasm-fix
ifeq ($(MODERN),1)
	CPPFLAGS := -I $(DEVKITARM)/arm-none-eabi/include -iquote include -DMODERN=$(MODERN)
	CFLAGS += $(ARCH) $(CPPFLAGS) -Wno-pointer-to-int-cast -fno-toplevel-reorder -fno-aggressive-loop-optimizations
	LIBPATH := -L $(shell dirname $(shell $(AGBCC) --print-file-name=libgcc.a)) -L $(shell dirname $(shell $(AGBCC) --print-file-name=libc.a))
else
	CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -DMODERN=$(MODERN)
	CFLAGS += -fhex-asm
	LIBPATH := -L tools/agbcc/lib
endif
LDFLAGS := $(LIBPATH) -lgcc -lc

ASFILE := $(wildcard asm/*.s) $(wildcard asm/*/*.s) $(shell find sound/songs -type f -name '*.s') src/libs/m4a_1.s data/tilesets/offsets.s sprites/table.s sprites/anim.s
ASOBJFILE := $(ASFILE:.s=.o)

CFILE := $(shell find src -type f -name '*.c')
COBJFILE := $(CFILE:.c=.o)

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

.PHONY: all check compare clean clean-code

all: $(ROM) compare
check: $(ROM) compare

# This is a build method for romhacks and builds with gcc specified by the user.
modern: ; @$(MAKE) $(ROM) -j8 MODERN=1

compare: $(ROM)
	@sha1sum -c $(NAME).sha1

clean: clean-src clean-graphics
	@rm -f $(ELF) $(ASOBJFILE) $(COBJFILE)

clean-code: clean-src
	@rm -f $(ELF) $(ASOBJFILE) $(COBJFILE) $(shell find asm -type f -name '*.o') $(shell find src -type f -name '*.o') $(shell find sound/songs -type f -name '*.o')

$(ROM): $(ELF)
	@$(OBJCOPY) -O binary $< $@

$(ELF): %.elf: $(ASOBJFILE) $(COBJFILE) midi ld_script.ld $(GFX_HDR)
	@$(LD) -T $(LDSCRIPT) -Map $*.map -o $@ $(ASOBJFILE) $(COBJFILE) $(GFX_HDR) $(LDFLAGS)

$(COBJFILE): %.o: %.c graphics stage
ifeq ($(MODERN),1)
	@$(AGBCC) $(CFLAGS) $< -c -o $@
else
	@$(CPP) $(CPPFLAGS) $< | $(AGBCC) $(CFLAGS) -o $(subst .c,.s,$<)
	@echo ".text\n\t.align\t2, 0\n" >> $(subst .c,.s,$<)
	@$(AS) $(ASFLAGS) $(subst .c,.s,$<) -o $@ 
endif

$(ASOBJFILE): %.o: %.s string graphics sprite
	$(CPP) $(CPPFLAGS) $< | $(AS) $(ASFLAGS) -o $@ -

include data/string/string.mk
include data/texts/texts.mk
include src/src.mk

#### Graphics Rules ####

GBAGFX := tools/gbagfx/gbagfx$(EXE)
include graphics_file_rules.mk

#### Graphic Headers Rules ####

GFX_JSON_CONVERTER := ./tools/dev/graphic_header.ts
include graphic_header_rules.mk

#### Audio Rules ####

MID := tools/mid2agb/mid2agb$(EXE)
include songs.mk

#### Text Rules ####

TEXTCOMP := tools/rmz-text-compiler$(EXE)

%.bin: %.txt ; @$(TEXTCOMP) -f $< -o $@
%.bin: %.zc ;@$(TEXTCOMP) -c --verbose -f $< -o $@

#### Sprite Rules ####

METASPRITE_JSON_CONVERTER := ./tools/dev/metasprite.ts
SEQUENCE_JSON_CONVERTER := ./tools/dev/sequence.ts
include sprite_rules.mk

#### Stage Rules ####

STAGE_JSON_CONVERTER := ./tools/dev/stage.ts
include stage_rules.mk
