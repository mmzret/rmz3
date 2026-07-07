include songs.mk
include metasprite_rules.mk
include sprite_animation_rules.mk
include graphics_file_rules.mk

# gbagfx を使うアセットは scaninc で依存関係を自動生成するので、ここに含める必要はない
ASSETS := $(SONG_ASMS) $(METASPRITE) $(SPRITE_ANIMS)

.PHONY: assets
assets: $(ASSETS)

.PHONY: clean-assets
clean-assets: clean-midi clean-metasprite clean-sprite-animation clean-graphics
