ELFTYPE_DIR := ./data/gfx/elf/type

ELFTYPE_PALS := $(wildcard $(ELFTYPE_DIR)/*/*.gbapal)
ELFTYPE_PNGS := $(subst .gbapal,.png,$(ELFTYPE_PALS))
ELFTYPE_4BPP := $(subst .gbapal,.4bpp,$(ELFTYPE_PALS))
ELFTYPE_LZ := $(subst .gbapal,.lz,$(ELFTYPE_PALS))
ELFTYPE_BIN := $(subst .gbapal,.bin,$(ELFTYPE_PALS))
$(warning $(ELFTYPE_LZ))

elftypeicon: $(ELFTYPE_BIN)

$(ELFTYPE_DIR)/%.bin: $(ELFTYPE_DIR)/%.lz
	@cat $< $(subst .lz,.gbapal,$<) > $@

$(ELFTYPE_DIR)/%.lz: $(ELFTYPE_DIR)/%.4bpp
	@$(GBAGFX) $< $@ $(GFX_OPTS)

$(ELFTYPE_DIR)/%.4bpp: $(ELFTYPE_DIR)/%.png
	@$(GBAGFX) $< $@ $(GFX_OPTS)

clean-elftypeicon:
	@rm -f $(ELFTYPE_DIR)/*/*.bin
	@rm -f $(ELFTYPE_DIR)/*/*.lz
	@rm -f $(ELFTYPE_DIR)/*/*.4bpp
