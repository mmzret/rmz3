STAGE_JSON := $(shell find data/stage -type f -name 'stage.json')
STAGE := $(subst .json,.h,$(STAGE_JSON))

$(STAGE): %.h: %.json
	$(STAGE_JSON_CONVERTER) $< > $@

stage: $(STAGE)

clean-stage:
	@rm -f $(STAGE)
