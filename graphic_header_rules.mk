GFX_JSON_CONVERTER := ./tools/dev/graphic_header.ts

GFX_JSON := $(shell find data/tilesets -type f -name 'header.json') $(shell find sprites -type f -name 'header.json') $(shell find graphics/dialog -type f -name 'header.json')

# e.g. sprites/dynamic/zero/idle/sheet/header.s
GFX_ASM := $(subst .json,.s,$(GFX_JSON))

# オフセットの計算にグラフィックデータのサイズが必要なので、すべてのグラフィックデータを依存関係に含める
$(GFX_ASM): %.s: %.json $(ALL_GRAPHICS)
	$(GFX_JSON_CONVERTER) $< > $@

# e.g. sprites/dynamic/zero/idle/sheet/header.o
GFX_HDR := $(subst .json,.o,$(GFX_JSON))

.PHONY: graphic-headers
graphic-headers: $(GFX_HDR)

.PHONY: clean-graphic-headers
clean-graphic-headers:
	@rm -f $(GFX_HDR) $(subst .json,.s,$(GFX_JSON))
