#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { Parser } from 'npm:binary-parser@2.2.1';
import { Coord } from '../../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 16;
const ROM = 'baserom.gba';

const ScriptEntityTemplate = new Parser().endianness('little')
  .uint8('kind')
  .uint8('variant')
  .uint8('unk_02')
  .uint8('unk_03')
  .nest('coord', { type: Coord })
  .uint32('flag');

const main = async () => {
  const { args } = await new Command()
    .name('script_entity.ts')
    .version('1.0.0')
    .description('Parser for ScriptEntityTemplate struct')
    .arguments('<start> <length:number>')
    .usage('0x08350b98 15')
    .parse(Deno.args);

  const rom = Deno.readFileSync(ROM);
  const [start, len] = [Number(args[0]), Number(args[1])];

  for (let i = 0; i < len; i++) {
    const addr = start + (i * SIZE) - BASE;
    const result = ScriptEntityTemplate.parse(rom.slice(addr, addr + SIZE));
    console.log(result);
  }
};

main();
