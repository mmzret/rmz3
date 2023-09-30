STAGE_JSON := $(shell find data/stage -type f -name 'stage.json')
STAGE := $(subst stage.json,landscape.h,$(STAGE_JSON))

$(STAGE): %/landscape.h: %/stage.json
	$(STAGE_JSON_CONVERTER) $<

stage: $(STAGE)

clean-stage:
	@rm -f $(STAGE)