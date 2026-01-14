#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from '@cliffy/command';
import { dirname, extname, join } from 'https://deno.land/std/path/mod.ts';
import { existsSync } from 'https://deno.land/std/fs/mod.ts';
import { GraphicHeader } from '../common/index.ts';

/**
 * header.json から アセンブリファイル を生成するスクリプト (e.g. sprites/dynamic/anubis/sheet/header.json)
 * 実行すると次のようなファイルが生成されます (正確には標準出力に出力されるのでリダイレクトしてください)
 * グラフィックデータ(.incbinしてるやつら)のサイズからオフセットを計算する必要があるので、 このスクリプトの実行前に、グラフィックデータをビルドする必要があります。
 *
 * .section .rodata
 * .balign 4, 0
 * .global gGraphicHeader_XXX
 * gGraphicHeader_XXX:
 * @ ヘッダ列 (include/gfx.h の Graphic[])
 *   @ include/gfx.h の Graphic
 *     .4byte offset
 *     .4byte xxxxxxxx
 *     .2byte xxxx, xxxx
 *     @ パレットがあるなら
 *       .4byte xxxxxxxx
 *       .2byte xxxx
 *       .byte xx, xx
 *   @ header.json の data の要素数だけ繰り返し
 *     ...
 * @ グラフィックデータ
 *   .incbin "aaa/bbb.4bpp" (もしくは .lz)
 *   .incbin "aaa/bbb.gbapal" (もしあれば)
 *   ...
 */

type JsonData = {
  label?: string;
  data: GraphicHeader[];
};

type GraphicInfo = {
  name: string;
  size: number;
  color: number;
  files: string[];
  hdrOnly: boolean;
};

const main = async () => {
  const { args, options } = await new Command()
    .name('graphic_header.ts')
    .version('1.0.0')
    .description(
      'Create a C header file from a graphic json folder.',
    )
    .arguments('<json:string>')
    .option('--verbose', 'verbose')
    .option('-l, --label', 'label')
    .usage('sprites/dynamic/zero/idle/sheet/sheet.json')
    .parse(Deno.args);

  const base = dirname(args[0]);

  const json = JSON.parse(Deno.readTextFileSync(args[0])) as JsonData;
  const graphics = json.data;
  if (options.verbose) {
    console.log(json);
  }

  const infos: GraphicInfo[] = [];
  let headerSize = 12;

  for (let i = 0; i < graphics.length; i++) {
    const g = graphics[i];

    let name: string;
    const ext = extname(g.name);
    switch (ext) {
      case '.4bpp': {
        name = g.name;
        break;
      }
      case '.lz': {
        name = g.name;
        break;
      }
      case '.png': {
        if (g.name.endsWith('.lz.png')) {
          name = g.name.replaceAll('.lz.png', '.lz');
        } else {
          name = g.name.replaceAll('.png', '.4bpp');
        }
        break;
      }
      default: {
        name = g.name;
        break;
      }
    }

    const path = join(base, name);
    if (!existsSync(path)) {
      throw new Error('File not found: ' + path);
    }

    const size = Deno.statSync(path).size;

    let color = 0;
    if (g.palette != null) {
      headerSize = 20;
      color = g.palette.color;
    }

    let files: string[] = [];
    if (g.files != null && g.files.length > 0) {
      files = g.files.map((f) => join(base, f));
    } else {
      files.push(path);
      if (g.palette != null) {
        if (g.palette.color > 0) {
          let palettePath = name.replaceAll('.4bpp.lz', '.gbapal');
          palettePath = palettePath.replaceAll('.4bpp', '.gbapal');
          palettePath = palettePath.replaceAll('.lz', '.lz.gbapal');
          files.push(join(base, palettePath));
        }
      }
    }

    const hdrOnly = g.hdrOnly ?? false;
    infos.push({
      name,
      size: hdrOnly ? 0 : size,
      color,
      files,
      hdrOnly,
    });
  }

  const headers: string[] = [];
  for (let i = 0; i < graphics.length; i++) {
    const g = graphics[i];
    const info = infos[i];
    let ofs = headerSize * (graphics.length - i);
    if (i > 0) {
      ofs += sum(infos.slice(0, i).map((i) => i.size));
      ofs += sum(infos.slice(0, i).map((i) => i.color * 2));
    }
    let header = `
  .4byte ${ofs}
  .4byte ${BigInt(info.size) | (BigInt(g.ofs) << 22n)}
  .2byte ${g.chunkSize}
  .2byte ${getProps(g)}
`;

    if (g.palette != null) {
      ofs += info.size - 12;
      header += `
    .4byte ${ofs}
    .2byte ${info.color * 2}
    .byte 0
    .byte ${g.palette.id}
`;
    }

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
  infos.forEach((info) => {
    if (!info.hdrOnly) {
      info.files.forEach((file) => {
        console.log(`  .incbin "${file}"`);
      });
    }
  });
};

const getProps = (g: GraphicHeader): number => {
  let props = 0;
  if (g.props.includes('4bpp')) {
    props |= 0x20;
  }
  if (g.props.includes('8bpp')) {
    props |= 0x40;
  }
  if (g.props.includes('lz77')) {
    props |= 0x02;
  }
  if (g.props.includes('no_pal')) {
    props |= 0x04;
  }
  if (g.props.includes('chunked')) {
    props |= 0x01;
  }
  return props;
};

const sum = (numbers: number[]) => {
  return numbers.reduce((accumulator, current) => accumulator + current, 0);
};

main();
