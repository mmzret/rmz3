#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { join } from 'https://deno.land/std/path/mod.ts';

type SpriteMetadata = { id: number; name: string; path: string; noAnimation?: boolean };

type JsonData = {
  data: SpriteMetadata[];
};

const main = async () => {
  await new Command()
    .name('sprite_label.ts')
    .version('1.0.0')
    .parse(Deno.args);

  const infos = JSON.parse(Deno.readTextFileSync('sprites/static/sprite.json')) as JsonData;
  for (const info of infos.data) {
    const p = join('sprites/static', info.path);
    const symbol = info.path.split('/').join('_');

    try {
      const metasprite = JSON.parse(Deno.readTextFileSync(join(p, 'metasprite.json'))) as { label: string };
      metasprite.label = `gStaticMetaSprite_${symbol}`;
      Deno.writeTextFileSync(join(p, 'metasprite.json'), JSON.stringify(metasprite, null, 2));
    } catch (e) {}
    try {
      const sequence = JSON.parse(Deno.readTextFileSync(join(p, 'sequence.json'))) as { label: string };
      sequence.label = `gStaticAnimationSequence_${symbol}`;
      Deno.writeTextFileSync(join(p, 'sequence.json'), JSON.stringify(sequence, null, 2));
    } catch (e) {}
  }
};

main();
