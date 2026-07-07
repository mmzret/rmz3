GBAGFX := tools/gbagfx/gbagfx$(EXE)

# gbagfx に追加でオプションを渡す場合は target-specific variables で個別に記述する
GFX_OPTS :=

include sprites/sprites.mk
include data/tilesets/tilesets.mk

# 汎用ルール, scaninc がソースファイルから依存関係を自動で生成するため、このルール定義だけでよい
%.1bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.4bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.8bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.pal              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %                  ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.rl:     %                  ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %.lz.4bpp          ; @$(GBAGFX) $< $@ $(GFX_OPTS)

.PHONY: clean-graphics clean-bg-gfx clean-cyberelf-gfx clean-dialog-gfx
clean-graphics: clean-bg-gfx clean-cyberelf-gfx clean-dialog-gfx clean-sprite-gfx clean-tileset
	rm -f ./graphics/font/*.4bpp

clean-bg-gfx:
	rm -f $(shell find ./graphics/bg -type f -name "*.gbapal" -o -name "*.lz" -o -name '*.4bpp' -o -name '*.8bpp')

clean-cyberelf-gfx:
	rm -f $(shell find ./graphics/cyberelf -type f -name "*.gbapal" -o -name "*.lz" -o -name '*.4bpp')

clean-dialog-gfx:
	rm -f $(shell find ./graphics/dialog -type f -name "*.gbapal" -o -name "*.lz" -o -name '*.4bpp')

RULES_NO_SCAN += clean-graphics clean-bg-gfx clean-cyberelf-gfx clean-dialog-gfx
