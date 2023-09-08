#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { join } from 'https://deno.land/std/path/mod.ts';

type SpriteMetadata = { id: number; name: string; path: string };

type JsonData = {
  main: SpriteMetadata[];
};

const main = async () => {
  await new Command()
    .name('sprite_label.ts')
    .version('1.0.0')
    .parse(Deno.args);

  const infos = JSON.parse(Deno.readTextFileSync('sprites/sprite.json')) as JsonData;
  for (const info of infos.main) {
    const p = join('sprites', info.path);
    const symbol = info.path.split('/').join('_');

    {
      const metasprite = JSON.parse(Deno.readTextFileSync(join(p, 'metasprite.json'))) as { label: string };
      metasprite.label = `gMetaSprite_${symbol}`;
      Deno.writeTextFileSync(join(p, 'metasprite.json'), JSON.stringify(metasprite, null, 2));
    }
    {
      const sequence = JSON.parse(Deno.readTextFileSync(join(p, 'sequence.json'))) as { label: string };
      sequence.label = `gAnimationSequence_${symbol}`;
      Deno.writeTextFileSync(join(p, 'sequence.json'), JSON.stringify(sequence, null, 2));
    }
  }
};

main();
