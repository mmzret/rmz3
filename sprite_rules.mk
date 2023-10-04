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

SPRITE_ANIM_TABLE := sprites/anim.s
SPRITE_GFXHDR_TABLE := sprites/table.s

$(SPRITE_ANIM_TABLE): sprites/sprite.json
	./tools/dev/animation.ts > $@

$(SPRITE_GFXHDR_TABLE): sprites/sprite.json
	./tools/dev/sprite_gfxhdr_table.ts > $@

########################

sprite: $(METASPRITE) $(SEQUENCE)

clean-sprite:
	@rm -f $(METASPRITE) $(SEQUENCE) $(SPRITE_ANIM_TABLE) $(SPRITE_GFXHDR_TABLE)
