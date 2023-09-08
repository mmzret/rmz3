#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

const SUPRITE_SIZE: [number, number][] = [
  [8, 8],
  [16, 16],
  [32, 32],
  [64, 64],

  [16, 8],
  [32, 8],
  [32, 16],
  [64, 32],

  [8, 16],
  [8, 32],
  [16, 32],
  [32, 64],
];

type JsonData = {
  label?: string;
  data: Metasprite[];
};

type Metasprite = {
  sheetIdx: number;
  subsprites: Subsprite[];
};

type Subsprite = {
  tileNum: number;
  xflip: boolean;
  yflip: boolean;
  size: [number, number];
  x: number;
  y: number;
};

const main = async () => {
  const { args, options } = await new Command()
    .name('metasprite.ts')
    .version('1.0.0')
    .description(
      'Create a Asm file from a metasprite.json.',
    )
    .arguments('<json:string>')
    .option('--verbose', 'verbose')
    .option('-l, --label', 'label')
    .usage('sprites/zero/idle/metasprite.json')
    .parse(Deno.args);

  const json = JSON.parse(Deno.readTextFileSync(args[0])) as JsonData;
  const metasprites = json.data;
  if (options.verbose) {
    console.log(json);
  }

  const sizes = metasprites.map((
    metasprite,
    i,
  ) => (metasprite.subsprites.length * 4));

  const headers: string[] = [];
  for (let i = 0; i < metasprites.length; i++) {
    const metasprite = metasprites[i];
    let ofs = 4 * (metasprites.length - i) + (4 * i);
    if (i > 0) {
      ofs += sum(sizes.slice(0, i));
    }
    let header = `
  .2byte ${ofs}
  .byte ${metasprite.subsprites.length}
  .byte ${metasprite.sheetIdx}
`;

    headers.push(header);
  }

  console.log(`.section .rodata`);
  console.log(`.balign 4, 0`);

  if (options.label) {
    console.log(`.global ${options.label}`);
    console.log(`${options.label}:`);
  } else if (json.label != null) {
    console.log(`.global ${json.label}`);
    console.log(`${json.label}:`);
  }
  console.log(headers.join('\n'));

  metasprites.forEach((metasprite, i) => {
    metasprite.subsprites.forEach((subsprite, j) => {
      let u16 = subsprite.tileNum;
      u16 |= subsprite.xflip ? 0x400 : 0;
      u16 |= subsprite.yflip ? 0x800 : 0;
      u16 |= SUPRITE_SIZE.findIndex((size) => size[0] == subsprite.size[0] && size[1] == subsprite.size[1]) << 12;
      console.log(`.2byte 0x${u16.toString(16)}`);

      const x = subsprite.x >= 0 ? subsprite.x : 0x100 + subsprite.x;
      const y = subsprite.y >= 0 ? subsprite.y : 0x100 + subsprite.y;
      console.log(`.byte ${x}, ${y}`);
    });
  });
};

const sum = (numbers: number[]) => {
  return numbers.reduce((accumulator, current) => accumulator + current, 0);
};

main();
