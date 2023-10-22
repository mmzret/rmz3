#!/usr/bin/env -S deno run --allow-read --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { Parser as _Parser } from 'npm:binary-parser@2.2.1';
import { Coord, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 8;

type CommandArgs = {
  arg1: number;
  arg2: number;
  arg3: number;
};

const sequence: string[] = [];

const Parser = new _Parser().endianness('little');

const main = async () => {
  const { args } = await new Command()
    .name('script.ts')
    .version('1.0.0')
    .description(`Dump Zero3 command scripts`)
    .arguments('<start> <length:number>')
    .usage('0x08354908 17')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = args[1];

  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE) - BASE;
    const cmd = rom.subarray(addr, addr + SIZE);
    const args = cmd.subarray(1);
    const argments = Parser.uint8('arg1').uint16('arg2').uint32('arg3');
    const result: CommandArgs = argments.parse(args);
    switch (cmd[0]) {
      case 0x00: {
        console.log(`goto 0x${toHex(result.arg3, 8)}`);
        break;
      }

      case 0x01: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push('pause');
            break;
          }
          case 0x01: {
            sequence.push(`wait ${result.arg3}`);
            break;
          }
          case 0x02: {
            sequence.push(`waitabs ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x02: {
        sequence.push(`time ${result.arg3}`);
        break;
      }

      case 0x03: {
        sequence.push(`do_nothing`);
        break;
      }

      case 0x04: {
        sequence.push(`reset_camera Camera_${toHex(result.arg3, 8).toLowerCase()}`);
        break;
      }

      case 0x05: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`change_camera_mode ${result.arg3}`);
            break;
          }
          case 3:
          case 11:
          case 12:
          case 13:
          case 14:
          case 4: {
            sequence.push(`adjust_camera ${result.arg1}, 0 ${Coord(result.arg3)}`);
            break;
          }
          case 0x05: {
            sequence.push(`scroll_speed_x ${result.arg3}`);
            break;
          }
          case 0x06: {
            sequence.push(`scroll_speed_y ${result.arg3}`);
            break;
          }
          case 0x10: {
            sequence.push(`stop_camera`);
            break;
          }
          case 0x11: {
            sequence.push(`resume_camera`);
            break;
          }
          default: {
            sequence.push(`adjust_camera ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x06: {
        sequence.push(`cmd06 ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x07: {
        sequence.push(`resume ${result.arg1}`);
        break;
      }

      case 0x08: {
        sequence.push(`cmd08 ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x09: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`lock`);
            break;
          }
          case 0x01: {
            sequence.push(`release`);
            break;
          }
          case 0x02: {
            sequence.push(`forcekeyinput 0x${toHex(result.arg3, 8)}`);
            break;
          }
          default: {
            printUnkCommand(cmd[0], result);
            break;
          }
        }
        break;
      }

      case 0x0B: {
        sequence.push(`spawn ${result.arg1}, ${result.arg2}, Entity_${toHex(result.arg3, 8).toLowerCase()}`);
        break;
      }

      case 0x0C: {
        switch (true) {
          case (result.arg1 === 0x00 && result.arg2 === 0x00): {
            sequence.push(`entity 0, 0, Coord_${toHex(result.arg3, 8).toLowerCase()}`);
            break;
          }
          case (result.arg2 === 0x02 && result.arg3 === 0x00): {
            sequence.push(`turn_left ${result.arg1}`);
            break;
          }
          case (result.arg2 === 0x02 && result.arg3 === 0x01): {
            sequence.push(`turn_right ${result.arg1}`);
            break;
          }
          case (result.arg2 === 0x04 && result.arg3 === 0x00): {
            sequence.push(`visible ${result.arg1}, FALSE`);
            break;
          }
          case (result.arg2 === 0x05 && result.arg3 === 0x00): {
            sequence.push(`visible ${result.arg1}, TRUE`);
            break;
          }
          case (result.arg2 === 0x06 && result.arg3 === 0x00): {
            sequence.push(`destroy ${result.arg1}`);
            break;
          }
          default: {
            sequence.push(`entity ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x0D: {
        switch (result.arg3) {
          case 0x00: {
            const bit = Math.log2(result.arg2);
            sequence.push(`entityflag ${result.arg1}, ${bit}, FALSE`);
            break;
          }
          case 0x01: {
            const bit = Math.log2(result.arg2);
            sequence.push(`entityflag ${result.arg1}, ${bit}, TRUE`);
            break;
          }
          default: {
            sequence.push(`gameflag ${result.arg2}, ${result.arg3 - 2}`);
            break;
          }
        }
        break;
      }

      case 0x10: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`emergency_on`);
            break;
          }
          case 0x01: {
            sequence.push(`emergency_off`);
            break;
          }
          default: {
            printUnkCommand(cmd[0], result);
            break;
          }
        }
        break;
      }

      case 0x11: {
        switch (result.arg1) {
          case 0x01: {
            sequence.push(`stop_quake`);
            break;
          }
          default: {
            sequence.push(`quake ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x12: {
        const x = result.arg2 << 8;
        const c = result.arg3 & 0xFFFF;
        const y = ((result.arg3 >> 16) & 0xFFFF) << 8;
        sequence.push(`emotion ${result.arg1}, 0x${toHex(x, 4)}, 0x${toHex(y, 8)}, ${c}`);
        break;
      }

      case 0x13: {
        sequence.push(`scroll ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x14: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`wait_screeneffect`);
            break;
          }
          case 0x01: {
            sequence.push(`normal_screen`);
            break;
          }
          case 0x02: {
            sequence.push(`blackout_screen`);
            break;
          }
          case 0x04: {
            sequence.push(`whiteout_screen`);
            break;
          }
          default: {
            sequence.push(`screeneffect ${result.arg1}`);
            break;
          }
        }
        break;
      }

      case 0x16: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`wait_indicator_end`);
            break;
          }
          case 0x02: {
            sequence.push(`failed_or_gameover_indicator`);
            break;
          }
          case 0x04: {
            sequence.push(`warning_indicator`);
            break;
          }
          default: {
            sequence.push(`indicator ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x17: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`print_message ${result.arg2}, 0x${toHex(result.arg3, 4)}`);
            break;
          }
          case 0x01: {
            sequence.push(`message ${result.arg1}, ${result.arg2}, 0x${toHex(result.arg3, 4)}`);
            break;
          }
          case 0x02: {
            if (result.arg2 === 0x00) {
              sequence.push(`wait_msgbox_end`);
            } else {
              sequence.push(`message ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            }
            break;
          }
          case 0x03: {
            sequence.push(`message 3, ${result.arg2}, 0x${toHex(result.arg3, 4)}`);
            break;
          }
          default: {
            sequence.push(`message ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x18: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`play_bgm ${result.arg3}`);
            break;
          }
          case 0x01: {
            sequence.push(`stop_bgm`);
            break;
          }
          case 0x02: {
            sequence.push(`wait_bgm_end`);
            break;
          }
        }
        break;
      }

      case 0x19: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`play_se ${result.arg3}`);
            break;
          }
          case 0x01: {
            sequence.push(`stop_se ${result.arg3}`);
            break;
          }
          case 0x02: {
            sequence.push(`fadeout_se ${result.arg2}, ${result.arg3}`);
            break;
          }
          default: {
            printUnkCommand(cmd[0], result);
            break;
          }
        }
        break;
      }

      case 0x1a: {
        switch (result.arg1) {
          case 0x09: {
            sequence.push(`walkto ${Coord(result.arg3)}`);
            break;
          }
          default: {
            sequence.push(`force ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x1b: {
        sequence.push(`gimmick ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x1c: {
        switch (result.arg1) {
          case 0x02:
          case 0x03: {
            sequence.push(`cmd1c ${result.arg1}, ${result.arg2}, ${Coord(result.arg3)}`);
            break;
          }
          default: {
            sequence.push(`cmd1c ${result.arg1}, ${result.arg2}, ${result.arg3}`);
            break;
          }
        }
        break;
      }

      case 0x1d: {
        sequence.push(`sweep ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x1e: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`lockmenu`);
            break;
          }
          case 0x01: {
            sequence.push(`unlockmenu`);
            break;
          }
          default: {
            printUnkCommand(cmd[0], result);
            break;
          }
        }
        break;
      }

      case 0x1f: {
        sequence.push(`eventflag ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x20: {
        sequence.push(`cmd20 ${result.arg1}, ${result.arg2}, ${result.arg3}`);
        break;
      }

      case 0x22: {
        switch (result.arg1) {
          case 0x00: {
            sequence.push(`prepare_missionresult`);
            break;
          }
          case 0x01: {
            sequence.push(`missionresult`);
            break;
          }
          default: {
            printUnkCommand(cmd[0], result);
            break;
          }
        }
        break;
      }

      case 0x23: {
        sequence.push(`goodluck ${result.arg1}`);
        break;
      }

      case 0x25: {
        sequence.push(`cutscene ${result.arg1}`);
        break;
      }

      case 0xFF: {
        sequence.push(`end`);
        break;
      }

      default: {
        printUnkCommand(cmd[0], result);
        break;
      }
    }
  }

  console.log(`Script_${toHex(start, 8).toLowerCase()}:`);
  sequence.forEach((line) => console.log(`  ${line}`));
};

const printUnkCommand = (cmd: number, args: CommandArgs) => {
  console.error(`unknown command: 0x${toHex(cmd, 2)}`);
  sequence.push(`cmd${toHex(cmd, 2).toLowerCase()} ${args.arg1}, ${args.arg2}, ${args.arg3}`);
};

main();
