GFX_OPTS :=

include graphics/elf/mugshot/mugshot.mk

%.1bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.4bpp:   %.png
	@$(GBAGFX) $< $@ $(GFX_OPTS)
	./tools/dev/trim.ts $@
%.8bpp:   %.8bpp.png         ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.pal              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %                  ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.rl:     %                  ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %.lz.4bpp          ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %.lz.8bpp          ; @$(GBAGFX) $< $@ $(GFX_OPTS)

FONT_DIR := ./graphics/font
font: $(subst .png,.4bpp,$(wildcard $(FONT_DIR)/*.png))

BG_DIR = ./graphics/bg
MSGBOX_DIR = ./graphics/dialog/*
ELFTYPEICON_DIR = ./graphics/elf/type
GFX_SM_DIR = ./graphics/sprite_prop
ANIM_DIR = ./sprites

GRAPHICS_ALL_PNGS := $(wildcard $(BG_DIR)/*.png $(BG_DIR)/*/*.png) $(wildcard $(MSGBOX_DIR)/*.png) $(wildcard $(ELFTYPEICON_DIR)/*.png) $(wildcard $(GFX_SM_DIR)/*.png) $(shell find $(ANIM_DIR) -type f -name '*.png')
GRAPHICS_PNGS := $(filter-out %.lz.8bpp.png, $(filter-out %.lz.png, $(GRAPHICS_ALL_PNGS)))
GRAPHICS_LZ_PNGS := $(filter %.lz.png, $(GRAPHICS_ALL_PNGS))
GRAPHICS_8BPP_PNGS := $(filter %.lz.8bpp.png, $(GRAPHICS_ALL_PNGS))

GRAPHICS_4BPP := $(subst .png,.4bpp,$(GRAPHICS_PNGS)) $(subst .png,.gbapal,$(GRAPHICS_PNGS))
GRAPHICS_LZ := $(subst .lz.png,.lz, $(GRAPHICS_LZ_PNGS)) $(subst .lz.png,.lz.gbapal,$(GRAPHICS_LZ_PNGS)) $(subst .lz.8bpp.png,.lz,$(GRAPHICS_8BPP_PNGS))

graphics: elf-mugshot $(GRAPHICS_4BPP) $(GRAPHICS_LZ)

asm/font.o: asm/font.s font

clean-graphics:
	@rm -f graphics/*/*.{gbapal,lz,4bpp} graphics/*/*/*.{gbapal,lz,4bpp}  graphics/*/*/*.{gbapal,lz,4bpp} graphics/*/*/*/*.{gbapal,lz,4bpp} ${FONT_DIR}/*.4bpp
