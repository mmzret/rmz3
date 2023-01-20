FONT_DIR := ./data/gfx/font

FONT_PNGS :=  $(wildcard $(FONT_DIR)/*.png)
FONT_4BPPS := $(subst .png,.4bpp,$(FONT_PNGS))

font: $(FONT_4BPPS)

clean-font:
	rm -f $(FONT_DIR)/*.4bpp
