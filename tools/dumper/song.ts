#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadU32, toHex } from '../common/index.ts';
import { Parser } from 'npm:binary-parser@2.2.1';

type ParseResult = {
  trackCount: number;
  blockCount: number;
  priority: number;
  reverb: number;
  tone: number;
  mml: number[];
};
const SIZE = 8;

const SongHeader = new Parser().endianness('little')
  .uint8('trackCount')
  .uint8('blockCount')
  .uint8('priority')
  .uint8('reverb')
  .uint32('tone');

const voicegroups = [0x0810e5a4, 0x0810eba4, 0x0810f1a4];

const BASE = 0x0800_0000;
const gSongTable = 0x0810f810 - BASE;

const main = async () => {
  const { args } = await new Command()
    .name('song.ts')
    .version('1.0.0')
    .description('Song番号を指定すると、ロックマンゼロ3の対応するSongデータをasm形式でダンプします')
    .arguments('<n:number> <name:string>')
    .usage('270 se_rbase_typing')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const n = args[0];
  const name = args[1];
  const h = loadU32(rom, gSongTable + (8 * n)) - BASE; // e.g. 0x323ce8
  const result = SongHeader.parse(rom.slice(h, h + SIZE)) as ParseResult;
  const hdr: ParseResult = {
    ...result,
    mml: [],
  };

  let i = 0;
  let mml = loadU32(rom, h + 8 + (4 * i)); // 0x08323cf0
  while (mml > 0x8323ce8 && mml <= 0x8338c58) {
    hdr.mml.push(mml);
    i++;
    mml = loadU32(rom, h + 8 + (4 * i));
  }

  // mml
  const size = h - (hdr.mml[0] - BASE);
  const cmd = `./tools/dumper/byte.ts baserom.gba 0x${toHex(hdr.mml[0], 8)} ${size} -f=u8`;
  const p = await Deno.run({
    cmd: cmd.split(
      ' ',
    ),
    stdout: 'piped',
  });
  const mmlData = await (new TextDecoder().decode(await p.output())).trim();
  console.log(buildAsm(name, hdr, mmlData));
};

const buildAsm = (name: string, hdr: ParseResult, mml: string) => {
  const g = voicegroups.indexOf(hdr.tone);

  let result = `.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global ${name}

${name}_1:
  ${mml}

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

${name}:
  .byte	${hdr.trackCount}	@ NumTrks
  .byte	${hdr.blockCount}	@ NumBlks
  .byte 0x${toHex(hdr.priority, 2)}
  .byte ${hdr.reverb}
  .word voicegroup${toHex(g, 3)}
`;

  const base = hdr.mml[0];
  hdr.mml.forEach((addr) => {
    result += `  .4byte ${name}_1+${addr - base}\n`;
  });

  result += `\n.end\n`;
  return result;
};

main();
