#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from '@cliffy/command';
import { BASE, ROM_PATH } from '../common/index.ts';

// e.g. ./tools/dumper/bin.ts 0x0863c7a8 0x08644cb4 output.bin
const main = async () => {
  const { args } = await new Command()
    .name('bin.ts')
    .version('1.0.0')
    .description('開始アドレス(start) から 終端アドレス(end-1)だけ、 バイナリファイルとして ダンプします。')
    .arguments('<start> <end> <output>')
    .usage('0x0863c7a8 0x08644cb4 output.bin')
    .parse(Deno.args);

  const rom = Deno.readFileSync(ROM_PATH);
  const [start, end] = [Number(args[0]), Number(args[1])];
  if (isNaN(start) || isNaN(end)) {
    console.error('開始アドレスと終端アドレスは数値で指定してください。');
    Deno.exit(1);
  }
  if (start < BASE || end > BASE + rom.length) {
    console.error(`アドレスはROMの範囲内で指定してください。ROMの範囲: 0x${BASE.toString(16)} - 0x${(BASE + rom.length).toString(16)}`);
    Deno.exit(1);
  }
  if (start >= end) {
    console.error('開始アドレスは終端アドレスより小さく指定してください。');
    Deno.exit(1);
  }

  const length = end - start;
  const result = new Uint8Array(length);
  for (let i = 0; i < length; i++) {
    const addr = start + i - BASE;
    result[i] = rom[addr];
  }

  Deno.writeFileSync(args[2], result);
};

main();
