# AnimScript のテーブル (sequence.json) を sequence.inc に変換するルール
# 正直、 palette.sx のように macroで sequence.inc を書けばいいと思うのでそのうち sequence.json とこのルールは消す予定

SEQUENCE_JSON_CONVERTER := ./tools/dev/sequence.ts

# e.g. sprites/dynamic/weil/sequence.json
SEQUENCE_JSON := $(shell find sprites -type f -name 'sequence.json')

# e.g. sprites/dynamic/weil/sequence.inc
SEQUENCE := $(subst .json,.inc,$(SEQUENCE_JSON))

$(SEQUENCE): %.inc: %.json
	$(SEQUENCE_JSON_CONVERTER) $< > $@

########################

SPRITE_ANIMS := $(SEQUENCE)

.PHONY: clean-sprite-animation
clean-sprite-animation:
	@rm -f $(SEQUENCE)

RULES_NO_SCAN += clean-sprite-animation
