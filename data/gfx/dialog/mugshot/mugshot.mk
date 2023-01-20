MUGSHOT_DIR := ./data/gfx/dialog/mugshot

MUGSHOT_PALS := $(wildcard $(MUGSHOT_DIR)/*/*.gbapal)
MUGSHOT_PNGS := $(subst .gbapal,.png,$(MUGSHOT_PALS))
MUGSHOT_4BPP := $(subst .gbapal,.4bpp,$(MUGSHOT_PALS))
MUGSHOT_LZ := $(subst .gbapal,.lz,$(MUGSHOT_PALS))
MUGSHOT_BIN := $(subst .gbapal,.bin,$(MUGSHOT_PALS))
$(warning $(MUGSHOT_LZ))

mugshot: $(MUGSHOT_BIN)

$(MUGSHOT_DIR)/%.bin: $(MUGSHOT_DIR)/%.lz
	cat $< $(subst .lz,.gbapal,$<) > $@

$(MUGSHOT_DIR)/%.lz: $(MUGSHOT_DIR)/%.4bpp
	$(GBAGFX) $< $@ $(GFX_OPTS)

$(MUGSHOT_DIR)/%.4bpp: $(MUGSHOT_DIR)/%.png
	$(GBAGFX) $< $@ $(GFX_OPTS)

clean-mugshot:
	@rm -f $(MUGSHOT_DIR)/*/*.bin
	@rm -f $(MUGSHOT_DIR)/*/*.lz
	@rm -f $(MUGSHOT_DIR)/*/*.4bpp
