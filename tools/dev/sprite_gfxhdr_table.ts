#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

type SpriteMetadata = { id: number; name: string; path: string };

type JsonData = {
  data: SpriteMetadata[];
};

type HeaderSymbol = `gGraphicHeader_Sprite_${string}`;

const HeaderPtrTable = new Map<number, HeaderSymbol>();

const main = async () => {
  await new Command()
    .name('sprite_gfxhdr_table.ts')
    .version('1.0.0')
    .description(
      'Create gDynamicMotionGraphicOffsets as Asm pointer table',
    )
    .parse(Deno.args);

  const infos = JSON.parse(Deno.readTextFileSync('sprites/dynamic/sprite.json')) as JsonData;

  let lastID = 0;
  for (const info of infos.data) {
    const symbol = info.path.split('/').join('_');
    const label: HeaderSymbol = `gGraphicHeader_Sprite_${symbol}`;
    HeaderPtrTable.set(info.id, label);
    if (info.id > lastID) {
      lastID = info.id;
    }
  }

  console.log(`	.include "asm/macros.inc"`);
  console.log(`  .balign 4`);
  console.log(`  .section .rodata\n`);

  console.log(`.global gDynamicMotionGraphicOffsets`);
  console.log(`gDynamicMotionGraphicOffsets:`);
  for (let id = 0; id <= lastID; id++) {
    const label = HeaderPtrTable.get(id);
    if (label) {
      console.log(`  .word ${label}-.`);
    } else if (id < 144) {
      console.log(`  .word ${HeaderPtrTable.get(0)}-.`);
    } else {
      console.log(`  .word ${HeaderPtrTable.get(144)}-.`);
    }
  }
};

main();
