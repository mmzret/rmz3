TOOL = $(DEVKITARM)/bin

AS = tools/binutils/bin/arm-none-eabi-as
LD = $(TOOL)/arm-none-eabi-ld
OBJCOPY = $(TOOL)/arm-none-eabi-objcopy
OBJDUMP := $(TOOL)/arm-none-eabi-objdump

TEXTCOMP := ./tools/rmz-text-compiler

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

ASFILE := $(wildcard asm/*.s) src/libs/m4a_1.s src/analysis/analysis.s \
	data/texts/texts.s data/string/string.s data/terrain/terrain.s data/data_085b5cd0/data_085b5cd0.s data/data_083856f8/data_083856f8.s data/data_08338de8/data_08338de8.s \
	data/gfx/cutscene/cutscene.s data/gfx/dialog/dialog.s data/gfx/elf/elf.s data/gfx/tileset/tileset.s data/gfx/gfx_083b8c8c/gfx_083b8c8c.s data/gfx/gfx_085d78f8/gfx_085d78f8.s data/gfx/font/font.s \
	data/sound/sound.s

CFILE := $(wildcard src/*.c) $(wildcard src/*/*.c)
ASOBJFILE := $(ASFILE:.s=.o)
COBJFILE := $(CFILE:.c=.o)

NAME := rmz3
ROM := $(NAME).gba

ELF := $(NAME).elf

ARCH = -mcpu=arm7tdmi -march=armv4t -mthumb -mthumb-interwork
ASFLAGS := $(ARCH) -g --agbasm-colon-defined-global-labels --agbasm-multiline-macros --agbasm-charmap --agbasm-no-gba-thumb-after-label-disasm-fix

CC1             := tools/agbcc/bin/agbcc$(EXE)
override CFLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm -fshort-enums

CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc

SHA1SUM := sha1sum -c

GBAGFX := tools/gbagfx/gbagfx$(EXE)

# Special configurations required for lib files
src/libs/agb_sram.o: CFLAGS := -O -mthumb-interwork
src/libs/m4a.o: CC1 := tools/agbcc/bin/old_agbcc$(EXE)

.PHONY: all check compare clean tools check

all: string texts mugshot elftypeicon elf-mugshot font $(ROM) clean compare
check: string texts mugshot elftypeicon elf-mugshot font $(ROM) compare

compare: $(ROM)
	$(SHA1SUM) $(NAME).sha1

clean: clean-string clean-texts clean-mugshot clean-elftypeicon clean-elf-mugshot clean-font clean-src
	@rm -f $(ELF) $(ASOBJFILE) $(COBJFILE)

decrypt:
	@./tools/encryption/decrypt.ts ./baserom.gba src/gfx.encrypted.bin src/gfx.c

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): %.elf: $(ASOBJFILE) $(COBJFILE) ld_script.ld
	$(LD) -T ld_script.ld -Map $*.map -o $@ $(ASOBJFILE) $(COBJFILE) -L tools/agbcc/lib -lgcc -lc

# If you want to debug asmfile,
# cc -E -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc src/TARGET | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm -o tmp.s
$(COBJFILE): %.o: %.c
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) -o $(subst .c,.s,$<)
	@echo ".text\n\t.align\t2, 0\n" >> $(subst .c,.s,$<)
	$(AS) $(ASFLAGS) $(subst .c,.s,$<) -o $@ 

$(ASOBJFILE): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.bin: %.txt
	$(TEXTCOMP) -f $< -o $@

%.bin: %.zc
	$(TEXTCOMP) -c --verbose -f $< -o $@

include data/string/string.mk
include data/texts/texts.mk
include src/src.mk

tools:
	@$(MAKE) -C tools/gbagfx

#### Graphics Rules ####

GFX_OPTS :=

%.1bpp:   %.png  ; $(GBAGFX) $< $@ $(GFX_OPTS)
%.4bpp:   %.png  ; $(GBAGFX) $< $@ $(GFX_OPTS)
%.8bpp:   %.png  ; $(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.pal  ; $(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.png  ; $(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %      ; $(GBAGFX) $< $@ $(GFX_OPTS)
%.rl:     %      ; $(GBAGFX) $< $@ $(GFX_OPTS)

include data/gfx/dialog/mugshot/mugshot.mk
include data/gfx/elf/type/type.mk
include data/gfx/elf/mugshot/mugshot.mk
include data/gfx/font/font.mk
