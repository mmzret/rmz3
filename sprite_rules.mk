#### Metasprite Rules ####

METASPRITE_JSON_CONVERTER := ./tools/dev/metasprite.ts

# e.g. sprites/dynamic/weil/metasprite.json
METASPRITE_JSON := $(shell find sprites -type f -name 'metasprite.json')

# e.g. sprites/dynamic/weil/metasprite.inc
METASPRITE := $(subst .json,.inc,$(METASPRITE_JSON))

$(METASPRITE): %/metasprite.inc: %/metasprite.json
	$(METASPRITE_JSON_CONVERTER) $< > $@

#### Sequence Rules ####

SEQUENCE_JSON_CONVERTER := ./tools/dev/sequence.ts

# e.g. sprites/dynamic/weil/sequence.json
SEQUENCE_JSON := $(shell find sprites -type f -name 'sequence.json')

# e.g. sprites/dynamic/weil/sequence.inc
SEQUENCE := $(subst .json,.inc,$(SEQUENCE_JSON))

$(SEQUENCE): %.inc: %.json
	$(SEQUENCE_JSON_CONVERTER) $< > $@

#### Sprite Table Rules ####

SPRITE_TABLES := sprites/dynamic/table.s sprites/dynamic/anim.s sprites/static/anim.s

sprites/dynamic/anim.s: sprites/dynamic/sprite.json
	./tools/dev/animation.ts $< > $@
sprites/static/anim.s: sprites/static/sprite.json
	./tools/dev/animation.ts $< > $@
sprites/dynamic/table.s: sprites/dynamic/sprite.json
	./tools/dev/sprite_gfxhdr_table.ts > $@

########################

SPRITES := $(METASPRITE) $(SEQUENCE) $(SPRITE_TABLES)

.PHONY: clean-sprite
clean-sprite:
	@rm -f $(METASPRITE) $(SEQUENCE) $(SPRITE_TABLES)
