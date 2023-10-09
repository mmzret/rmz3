#### Metasprite Rules ####

METASPRITE_JSON := $(shell find sprites -type f -name 'metasprite.json')
METASPRITE := $(subst .json,.inc,$(METASPRITE_JSON))

$(METASPRITE): %.inc: %.json
	$(METASPRITE_JSON_CONVERTER) $< > $@

#### Sequence Rules ####

SEQUENCE_JSON := $(shell find sprites -type f -name 'sequence.json')
SEQUENCE := $(subst .json,.inc,$(SEQUENCE_JSON))

$(SEQUENCE): %.inc: %.json
	$(SEQUENCE_JSON_CONVERTER) $< > $@

#### Table Rules ####

sprites/%/anim.s: sprites/%/sprite.json
	./tools/dev/animation.ts $< > $@

sprites/dynamic/table.s: sprites/dynamic/sprite.json
	./tools/dev/sprite_gfxhdr_table.ts > $@

########################

sprite: $(METASPRITE) $(SEQUENCE)

clean-sprite:
	@rm -f $(METASPRITE) $(SEQUENCE) sprites/*/anim.s sprites/dynamic/table.s
