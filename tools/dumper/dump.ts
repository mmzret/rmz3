#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { Parser } from '@binary-parser';
import { BASE, Rect, ROM_PATH, toHex } from '../common/index.ts';

// ロックマンゼロ3で使われる様々なデータ構造を、ダンプするためのスクリプト
// ビルドでは使わない
// ちょっとしたデータのダンプはここにまとめる

const dumpMML = (view: DataView, start: number, length: number): string => {
  let result = '';
  let prefix = true;
  for (let i = 0; i < length; i++) {
    const offset = start + i - BASE;
    const val = view.getUint8(offset);
    let hex = toHex(Math.abs(val), 2, '0x');
    if (val < 0) {
      hex = '-' + hex;
    }

    switch (val) {
      case 0xB1: {
        result += `\n  .byte FINE`;
        prefix = true;
        break;
      }
      case 0xB2: {
        result += `\n  .byte GOTO`;
        const arg = view.getUint32(offset + 1, true);
        const delta = arg - (BASE + offset + 1);
        const dst = `.${delta > 0 ? '+' : '-'}${Math.abs(delta)}`;
        i += 4;
        result += `\n  .word ${dst}`;
        prefix = true;
        break;
      }
      case 0xB3: {
        result += `\n  .byte PATT`;
        const arg = view.getUint32(offset + 1, true);
        const delta = arg - (BASE + offset + 1);
        const dst = `.${delta > 0 ? '+' : '-'}${Math.abs(delta)}`;
        i += 4;
        result += `\n  .word ${dst}`;
        prefix = true;
        break;
      }
      default: {
        if (prefix) {
          result += `\n  .byte ${hex}`;
          prefix = false;
        } else {
          result += `, ${hex}`;
        }
        break;
      }
    }
  }
  return result;
};

const Subcommands = {
  // e.g. ./tools/dumper/dump.ts pixel 0x0833ecec 4 -w=16 > result.txt
  //       -> "PIXEL(0), PIXEL(0), -PIXEL(16), PIXEL(16),"
  'pixel': new Command().name('pixel')
    .description(`開始アドレス(start) から 長さNだけ、PIXEL(xx) としてダンプします。`)
    .argument('<start_addr:string>', '開始アドレス')
    .argument('<length:number>', 'エントリ数 (ビット幅が32なら エントリ数 x 4 バイトがダンプされる)')
    .option('-w, --width=[n:number]', 'エントリのビット幅 (s32 か s16)', { default: 32 })
    .option('--columns=[n:number]', '1行あたりのエントリ数', { default: 4 })
    .option('--coord32', 'Coord[エントリ数] としてダンプする (-w は無視される)')
    .action((options, start_addr: string, length: number) => {
      const isCoord32 = !!options.coord32; // {PIXEL(x1), PIXEL(y1)}, {PIXEL(x2), PIXEL(y2)}, ...}  の形式でダンプするかどうか
      const w = isCoord32 ? 32 : Number(options.width);
      const columns = Number(options.columns || 4);
      const rom = Deno.readFileSync(ROM_PATH);
      const view = new DataView(rom.buffer);
      const start = Number(start_addr);
      const SIZE = w / 8;

      const getI16 = (addr: number) => view.getInt16(addr - BASE, true);
      const getI32 = (addr: number) => view.getInt32(addr - BASE, true);

      if (isCoord32) {
        length *= 2; // Coord[エントリ数] としてダンプする場合、x と y のペアで1エントリとみなすため、実際のエントリ数は倍になる
      }

      const pixels: string[] = [];

      for (let i = 0; i < length; i++) {
        let result: string;
        const addr = start + (i * SIZE);
        const val = w == 32 ? getI32(addr) : getI16(addr);
        if ((val & 0xFF) === 0x00) {
          const pixel = val >> 8;
          result = (pixel >= 0) ? `PIXEL(${pixel})` : `-PIXEL(${-pixel})`;
        } else {
          result = toHex(val, w / 4, '0x');
        }
        pixels.push(result);
      }

      if (isCoord32) {
        let output = '';
        for (let i = 0; i < pixels.length; i += 2) {
          const x = pixels[i];
          const y = pixels[i + 1];
          output += `{${x}, ${y}}, `;
        }
        console.log(output);
        return;
      }

      let output = '';
      for (let i = 0; i < pixels.length; i++) {
        output += `${pixels[i]}, `;
        if ((i + 1) % columns === 0) {
          output += '\n';
        }
      }
      console.log(output);
    }),

  // e.g. ./tools/dumper/dump.ts collision 0x083705bc 3 > tmp.txt
  'collision': new Command().name('collision')
    .description(`En: Dump Collision C struct array from <start>\nJa: 開始アドレス(start) から 長さNだけ、 C言語のCollision構造体としてダンプします。`)
    .argument('<start_addr:string>', '開始アドレス')
    .argument('<length:number>', 'エントリ数')
    .option('-i, --index', "add index prefix as '[idx] = '", { default: true })
    .usage('0x08361c68 15')
    .action((options, start_addr: string, length: number) => {
      const rom = Deno.readFileSync(ROM_PATH);
      const start = Number(start_addr);
      const SIZE = 24; // sizeof(struct Collision)

      const KIND = ['DDP', 'DRP', 'DRP2'];
      const FACTION = ['FACTION_ALLY', 'FACTION_ENEMY', 'FACTION_NEUTRAL'];
      const SPECIAL = ['0', 'HALFABLE', 'CS_BOSS'];
      const HARDNESS: Record<number, string> = {
        1: 'METAL',
        2: 'NO_DAMAGE',
        8: 'HARDNESS_B3',
      };

      const Collision = new Parser().endianness('little')
        .uint8('kind')
        .uint8('faction')
        .uint8('special')
        .uint8('damage')
        .uint8('atkType')
        .uint8('element')
        .uint8('nature')
        .uint8('comboLv')
        .uint8('hitzone')
        .uint8('hardness')
        .uint8('unk_0a')
        .uint8('remaining')
        .uint32('layer')
        .nest('range', { type: Rect });

      type ParseResult = {
        kind: number;
        faction: number;
        special: number;
        damage: number;
        atkType: number;
        element: number;
        nature: number;
        comboLv: number;
        hitzone: number;
        hardness: number;
        unk_0a: number;
        remaining: number;
        layer: number;
        range: {
          w: number;
          h: number;
          x: number;
          y: number;
        };
      };

      console.log('// 0x' + toHex(start, 8));
      console.log(`static const struct Collision sCollisions[${length}] = {`);
      for (let i = 0; i < length; i++) {
        const addr = start + (i * SIZE) - BASE;
        const result = Collision.parse(rom.slice(addr, addr + SIZE)) as ParseResult;
        const collision = {
          atkType: `0x${toHex(result.atkType, 2)}`,
          element: `0x${toHex(result.element, 2)}`,
          nature: `0x${toHex(result.nature, 2)}`,
          hardness: HARDNESS[result.hardness] ?? String(result.hardness),
          unk_0a: `0x${toHex(result.unk_0a, 2)}`,
          layer: `0x${toHex(result.layer, 8)}`,
          rect_0: result.range.x >> 8,
          rect_1: result.range.y >> 8,
          rect_2: result.range.w >> 8,
          rect_3: result.range.h >> 8,
        };

        const layerName = result.kind === 1 ? `priorityLayer` : `layer`;
        console.log(`${options.index ? `[${i}] = ` : ''}{`);
        console.log(`    kind: ${KIND[result.kind]},`);
        console.log(`    faction: ${FACTION[result.faction]},`);
        if (result.special !== 0) console.log(`    special: ${SPECIAL[result.special] ?? result.special},`);
        if (result.damage !== 0) console.log(`    damage: ${result.damage},`);

        switch (KIND[result.kind]) {
          case 'DRP2':
          case 'DDP': {
            if (result.atkType !== 0) console.log(`    atkType: ${collision.atkType},`);
            if (result.element !== 0) console.log(`    element: ${collision.element},`);
            if (result.nature !== 0) console.log(`    nature: ${collision.nature},`);
            if (result.comboLv !== 0) console.log(`    comboLv: ${result.comboLv},`);
            break;
          }
          case 'DRP': {
            let layerLo = result.atkType;
            layerLo |= result.element << 8;
            let layerHi = result.nature;
            layerHi |= result.comboLv << 8;
            console.log(`    LAYER(0x${toHex(layerHi, 4)}${toHex(layerLo, 4)}),`);
            break;
          }
        }

        if ((KIND[result.kind] !== 'DDP') || (result.hitzone !== 0)) console.log(`    hitzone: ${result.hitzone},`);
        if (result.hardness !== 0) console.log(`    hardness: ${collision.hardness},`);
        if (result.unk_0a !== 0) console.log(`    unk_0a: ${collision.unk_0a},`);
        console.log(`    remaining: ${result.remaining},`);
        if (result.layer !== 0) console.log(`    ${layerName}: ${collision.layer},`);

        console.log(`    range: {${collision.rect_0 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_0)}), ${collision.rect_1 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_1)}), ${collision.rect_2 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_2)}), ${collision.rect_3 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_3)})},`);
        console.log(`},`);
      }
      console.log('};');
    }),

  // e.g. ./tools/dumper/dump.ts slashed_enemy 0x08366720 4 > result.txt
  'slashed_enemy': new Command().name('slashed_enemy')
    .description(`Dump "struct SlashedEnemy" C struct array from <start>`)
    .argument('<start_addr:string>', '開始アドレス')
    .argument('<length:number>', 'エントリ数')
    .option('-i, --index', "add index prefix as '[idx] = '")
    .usage('0x08366720 4')
    .action((options, start_addr: string, length: number) => {
      const rom = Deno.readFileSync(ROM_PATH);
      const view = new DataView(rom.buffer);
      const start = Number(start_addr);
      const SIZE = 28; // sizeof(struct SlashedEnemy)

      const getU8 = (addr: number) => view.getUint8(addr - BASE);
      const getU16 = (addr: number) => view.getUint16(addr - BASE, true);
      const getI16 = (addr: number) => view.getInt16(addr - BASE, true);

      console.log('// 0x' + toHex(start, 8));
      console.log(`static const struct SlashedEnemy sSlashedEnemies[${length}] = {`);
      for (let i = 0; i < length; i++) {
        const addr = start + (i * SIZE);
        const slashedEnemy = {
          m: toHex(getU16(addr), 4, '0x'),
          unk_02: [getU8(addr + 2), getU8(addr + 3)],
          c: [getI16(addr + 4), getI16(addr + 6)],
          d: [getI16(addr + 8), getI16(addr + 10)],
          unk_coord_0c: [getI16(addr + 12), getI16(addr + 14)],
          unk_10: [getI16(addr + 16), getI16(addr + 18)],
          unk_14: [getU16(addr + 20), getU16(addr + 22)],
          unk: [
            getU8(addr + 24),
            getU8(addr + 25),
            getU8(addr + 26),
            getU8(addr + 27),
          ],
        };
        console.log(`${options.index ? `[${i}] = ` : ''}{
    m: ${slashedEnemy.m},
    unk_02: {${slashedEnemy.unk_02[0]}, ${slashedEnemy.unk_02[1]}},
    c: {${toHex(slashedEnemy.c[0], 4, '0x')}, ${toHex(slashedEnemy.c[1], 4, '0x')}},
    d: {${toHex(slashedEnemy.d[0], 4, '0x')}, ${toHex(slashedEnemy.d[1], 4, '0x')}},
    unk_coord_0c: {${toHex(slashedEnemy.unk_coord_0c[0], 4, '0x')}, ${toHex(slashedEnemy.unk_coord_0c[1], 4, '0x')}},
    unk_10: {${toHex(slashedEnemy.unk_10[0], 4, '0x')}, ${toHex(slashedEnemy.unk_10[1], 4, '0x')}},
    unk_14: {${slashedEnemy.unk_14[0]}, ${slashedEnemy.unk_14[1]}},`);
        if (slashedEnemy.unk[0] !== 0 || slashedEnemy.unk[1] !== 0 || slashedEnemy.unk[2] !== 0 || slashedEnemy.unk[3] !== 0) {
          console.log(`    _: {${slashedEnemy.unk[0]}, ${slashedEnemy.unk[1]}, ${slashedEnemy.unk[2]}, ${slashedEnemy.unk[3]}},`);
        }
        console.log(`},`);
      }
      console.log('};');
    }),

  // e.g. ./tools/dumper/dump.ts mml 0x0833168b 181 > tmp/output.bin
  'mml': new Command().name('mml')
    .description(`Dump mml as asm byte data`)
    .argument('<start_addr:string>', '開始アドレス')
    .argument('<length:number>', 'エントリ数')
    .usage('0x0833168b 181 > output.bin')
    .action((_, start_addr: string, length: number) => {
      const view = new DataView(Deno.readFileSync(ROM_PATH).buffer);
      console.log(dumpMML(view, Number(start_addr), length));
    }),

  // e.g. ./tools/dumper/dump.ts song 331 bgm_mission_instruction > tmp/bgm_mission_instruction.s
  'song': new Command().name('song')
    .description('Song番号を指定すると、ロックマンゼロ3の対応するSongデータをasm形式でダンプします')
    .argument('<n:number>', 'Song ID')
    .argument('<name:string>', '出力するasmのシンボル名')
    .usage('270 se_rbase_typing')
    .action((_, n: number, name: string) => {
      const rom = Deno.readFileSync(ROM_PATH);
      const view = new DataView(rom.buffer);

      const gSongTable = 0x0810f810 - BASE;

      type ParseResult = {
        trackCount: number;
        blockCount: number;
        priority: number;
        reverb: number;
        tone: number;
        mml: number[];
      };
      const SIZE = 8;
      const h = view.getUint32(gSongTable + (8 * n), true) - BASE; // e.g. 0x323ce8

      const SongHeader = new Parser().endianness('little')
        .uint8('trackCount')
        .uint8('blockCount')
        .uint8('priority')
        .uint8('reverb')
        .uint32('tone');
      const result = SongHeader.parse(rom.slice(h, h + SIZE)) as ParseResult;
      const hdr: ParseResult = {
        ...result,
        mml: [],
      };

      let i = 0;
      let mml = view.getUint32(h + 8 + (4 * i), true); // e.g. 0x08323cf0
      while (mml > 0x8323ce8 && mml <= 0x8338c58) {
        hdr.mml.push(mml);
        i++;
        mml = view.getUint32(h + 8 + (4 * i), true);
      }

      // mml
      const size = h - (hdr.mml[0] - BASE);
      const mmlData = dumpMML(view, hdr.mml[0], size).trim();

      const voicegroups = [0x0810e5a4, 0x0810eba4, 0x0810f1a4];
      const buildAsm = (name: string, hdr: ParseResult, mml: string) => {
        const g = voicegroups.indexOf(hdr.tone);

        let result = `.include "MPlayDef.s"
      
.section .rodata
.balign 4, 0
.global ${name}
      
${name}_1:
\t${mml}
      
@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0

${name}:
  .byte	${hdr.trackCount}	@ NumTrks
  .byte	${hdr.blockCount}	@ NumBlks
  .byte ${hdr.priority}
  .byte ${hdr.reverb}
  .word voicegroup${toHex(g, 3)}
`;

        const base = hdr.mml[0];
        hdr.mml.forEach((addr) => {
          result += `\t.4byte ${name}_1+${addr - base}\n`;
        });

        result += `\n.end\n`;
        return result;
      };

      console.log(buildAsm(name, hdr, mmlData));
    }),
};

const main = async () => {
  const { args, cmd } = await new Command()
    .name('dump.ts')
    .version('1.0.0')
    .command('pixel', Subcommands['pixel'])
    .command('slashed_enemy', Subcommands['slashed_enemy'])
    .command('collision', Subcommands['collision'])
    .command('mml', Subcommands['mml'])
    .command('song', Subcommands['song'])
    .parse(Deno.args);
  if (cmd.getParent()) return;

  // default command
  console.log('default');
};

main();
