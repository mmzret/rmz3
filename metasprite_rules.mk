# metasprite.json -> metasprite.inc
# metasprite.json は OAMスプライトとテクスチャ(sheet/*.png)をどう組み合わせてメタスプライトを作るかを記述したファイル

METASPRITE_JSON_CONVERTER := ./tools/dev/metasprite.ts

# e.g. sprites/dynamic/weil/metasprite.json
METASPRITE_JSON := $(shell find sprites -type f -name 'metasprite.json')

# e.g. sprites/dynamic/weil/metasprite.inc
METASPRITE := $(subst .json,.inc,$(METASPRITE_JSON))

$(METASPRITE): %/metasprite.inc: %/metasprite.json
	$(METASPRITE_JSON_CONVERTER) $< > $@

.PHONY: clean-metasprite
clean-metasprite:
	@rm -f $(METASPRITE)

RULES_NO_SCAN += clean-metasprite
