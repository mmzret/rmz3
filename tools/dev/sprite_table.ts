#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { join } from 'https://deno.land/std/path/mod.ts';

type SpriteMetadata = { id: number; name: string; path: string };

type JsonData = {
  main: SpriteMetadata[];
};

type MetaspriteSymbol = `gMetaSprite_${string}`;
type SequenceSymbol = `gAnimationSequence_${string}`;

const HeaderPtrTable = new Map<number, [MetaspriteSymbol, SequenceSymbol]>();

const main = async () => {
  await new Command()
    .name('sprite_table.ts')
    .version('1.0.0')
    .description(
      'Create gDynamicMotionMetaspriteTable and gDynamicMotionCmdTable as Asm pointer table',
    )
    .parse(Deno.args);

  const infos = JSON.parse(Deno.readTextFileSync('sprites/sprite.json')) as JsonData;

  const metaspriteIncludes: `.include "${string}"`[] = [];
  const sequenceIncludes: `.include "${string}"`[] = [];

  let lastID = 0;
  for (const info of infos.main) {
    const symbol = info.path.split('/').join('_');
    HeaderPtrTable.set(info.id, [`gMetaSprite_${symbol}`, `gAnimationSequence_${symbol}`]);
    if (info.id > lastID) {
      lastID = info.id;
    }

    metaspriteIncludes.push(`.include "${join('sprites', info.path, 'metasprite.inc')}"`);
    sequenceIncludes.push(`.include "${join('sprites', info.path, 'sequence.inc')}"`);
  }

  console.log(`	.include "asm/macros.inc"`);
  console.log(`  .balign 4`);
  console.log(`  .section .rodata\n`);

  console.log(`.global gDynamicMotionMetaspriteTable`);
  console.log(`gDynamicMotionMetaspriteTable:`);
  for (let id = 0; id <= lastID; id++) {
    const label = HeaderPtrTable.get(id);
    if (label) {
      console.log(`  .word ${label[0]}`);
    } else if (id < 144) {
      console.log(`  .word ${HeaderPtrTable.get(0)![0]}`);
    } else {
      console.log(`  .word ${HeaderPtrTable.get(144)![0]}`);
    }
  }
  console.log('\n');
  console.log(metaspriteIncludes.join('\n'));

  console.log(`\n  .balign 4`);
  console.log(`.global gDynamicMotionCmdTable`);
  console.log(`gDynamicMotionCmdTable:`);
  for (let id = 0; id <= lastID; id++) {
    const label = HeaderPtrTable.get(id);
    if (label) {
      console.log(`  .word ${label[1]}`);
    } else if (id < 144) {
      console.log(`  .word ${HeaderPtrTable.get(0)![1]}`);
    } else {
      console.log(`  .word ${HeaderPtrTable.get(144)![1]}`);
    }
  }
  console.log('\n');
  console.log(sequenceIncludes.join('\n'));

  console.log(`  .balign 4`);
};

main();
