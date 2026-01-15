#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from '@cliffy/command';

const BASE = 0x0800_0000;

const main = async () => {
  const { args } = await new Command()
    .name('bin.ts')
    .version('1.0.0')
    .description('開始アドレス(start) から 終端アドレス(end-1)だけ、 バイナリファイルとして ダンプします。')
    .arguments('<rom> <start> <end> <output>')
    .usage('rmz3.gba 0x0863c7a8 0x08644cb4 output.bin')
    .parse(Deno.args);

  const [start, end] = [
    Number(args[1]),
    Number(args[2]),
  ];
  const rom = Deno.readFileSync(args[0]);

  const length = end - start;
  const result = new Uint8Array(length);
  for (let i = 0; i < length; i++) {
    const addr = start + i - BASE;
    result[i] = rom[addr];
  }

  Deno.writeFileSync(args[3], result);
};

main();
