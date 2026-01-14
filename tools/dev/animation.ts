#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from '@cliffy/command';
import { join } from 'https://deno.land/std/path/mod.ts';

/**
 * sprite.json から anim.s を生成するスクリプト
 * anim.s は 内部で metasprite.ts と sequence.ts の生成物をインクルードしているが
 * sprite.json に書いてあるパスに従ったインクルードパスを書いているだけであり、 anim.s の生成前に metasprite.ts や sequence.ts を実行する必要はない
 */

type SpriteMetadata = { id: number; name: string; path: string; noAnimation?: boolean };

type JsonData = {
  data: SpriteMetadata[];
};

type MetaspriteSymbol = `gMetaSprite_${string}` | `gStaticMetaSprite_${string}`;
type SequenceSymbol = `gAnimationSequence_${string}` | `gStaticAnimationSequence_${string}`;

const HeaderPtrTable = new Map<number, [MetaspriteSymbol, SequenceSymbol]>();

const main = async () => {
  const { args } = await new Command()
    .name('animation.ts')
    .version('1.0.0')
    .description(
      'Create gDynamicMotionMetaspriteTable and gDynamicMotionCmdTable as Asm pointer table',
    )
    .arguments('<json:string>')
    .parse(Deno.args);

  const jsonPath = args[0];
  const isDynamic = jsonPath.endsWith('dynamic/sprite.json');
  const dir = isDynamic ? 'dynamic' : 'static';

  const infos = JSON.parse(Deno.readTextFileSync(jsonPath)) as JsonData;

  const metaspriteIncludes: `.include "${string}"`[] = [];
  const sequenceIncludes: `.include "${string}"`[] = [];

  let lastID = 0;
  for (const info of infos.data) {
    let symbol = info.path.split('/').join('_');
    if (info.noAnimation) {
      symbol = infos.data[lastID].path.split('/').join('_');
    }
    if (isDynamic) {
      HeaderPtrTable.set(info.id, [`gMetaSprite_${symbol}`, `gAnimationSequence_${symbol}`]);
    } else {
      HeaderPtrTable.set(info.id, [`gStaticMetaSprite_${symbol}`, `gStaticAnimationSequence_${symbol}`]);
    }
    if (info.id > lastID) {
      lastID = info.id;
    }

    if (!info.noAnimation) {
      metaspriteIncludes.push(`.include "${join(`sprites/${dir}`, info.path, 'metasprite.inc')}"`);
      sequenceIncludes.push(`.include "${join(`sprites/${dir}`, info.path, 'sequence.inc')}"`);
    }
  }

  console.log(`	.include "asm/macros.inc"`);
  console.log(`  .balign 4`);
  console.log(`  .section .rodata\n`);

  {
    const ofsTblLabel = isDynamic ? 'gDynamicMotionMetaspriteTable' : 'gStaticMotionMetaspriteTable';
    console.log(`.global ${ofsTblLabel}`);
    console.log(`${ofsTblLabel}:`);
    for (let id = 0; id <= lastID; id++) {
      const label = HeaderPtrTable.get(id);
      if (label) {
        console.log(`  .word ${label[0]}`);
      } else {
        if (isDynamic) {
          if (id < 144) {
            console.log(`  .word ${HeaderPtrTable.get(0)![0]}`);
          } else {
            console.log(`  .word ${HeaderPtrTable.get(144)![0]}`);
          }
        } else {
          console.log(`  .word ${HeaderPtrTable.get(0)![0]}`);
        }
      }
    }
    console.log('\n');
    console.log(metaspriteIncludes.join('\n'));
  }

  console.log(`\n  .balign 4`);

  {
    const ofsTblLabel = isDynamic ? 'gDynamicMotionCmdTable' : 'gStaticMotionCmdTable';
    console.log(`.global ${ofsTblLabel}`);
    console.log(`${ofsTblLabel}:`);
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
  }

  console.log(`  .balign 4`);
};

main();
