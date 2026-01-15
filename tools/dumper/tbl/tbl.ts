#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from '@cliffy/command';
import { Parser } from '@binary-parser';
import { toHex } from '../../common/index.ts';

/*
  Dump function pointer table (e.g. sUpdates2) is boring task, so I made helper script.
  Do not run this directly, but use a wrapper such as boss.ts or vfx.ts.
*/

const BASE = 0x0800_0000;
const SIZE = 4;
const ROM = 'baserom.gba';
const normat = ['// clang-format off\n', '// clang-format on'];

type ParseResult = {
  val: number;
};

const Func = new Parser().endianness('little')
  .uint32('val');

const main = async () => {
  const { args, options } = await new Command()
    .name('tbl.ts')
    .version('1.0.0')
    .description('Dump function pointer table')
    .arguments('<start> <length:number>')
    .usage("0x082523e8 4 -p='void PROTOTYPE(struct Entity* p)'")
    .option('-p, --prototype=[s:string]', 'Generate prototype declaration too')
    .option('-i, --index', "add index prefix as '[idx] = '")
    .option('--functype=[s:string]', 'function type for table type', {
      default: 'FUNCTYPE',
    })
    .parse(Deno.args);

  const rom = Deno.readFileSync(ROM);
  const [start, len] = [Number(args[0]), Number(args[1])];
  let declaration = '';

  // deno-fmt-ignore
  let table = `static const ${options.functype} PTR_ARRAY_${toHex(start, 8).toLowerCase()}[${len}] = {\n`;
  if (len > 4) {
    table = normat[0] + table;
  }

  for (let i = 0; i < len; i++) {
    const addr = start + (i * SIZE) - BASE;
    const result = Func.parse(rom.slice(addr, addr + SIZE)) as ParseResult;
    const fn = result.val & ~1;
    const symbol = fn === 0 ? `NULL` : `FUN_${toHex(fn, 8).toLowerCase()}`;
    table += `    ${options.index ? `[${i}] = ` : ''}${symbol},\n`;
    if (options.prototype && fn !== 0) {
      let prototype = options.prototype as string;
      if (prototype.includes('PROTOTYPE')) {
        prototype = prototype.replaceAll(';', '');
        declaration += `${prototype.replaceAll('PROTOTYPE', symbol)};\n`;
      }
    }
  }
  table += '};';
  if (len > 4) {
    table += `\n${normat[1]}`;
  }

  if (options.prototype) {
    console.log(declaration);
  }
  console.log(table);
};

main();
